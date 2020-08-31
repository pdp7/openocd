/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2018 by Bohdan Tymkiv                                   *
 *   bohdan.tymkiv@cypress.com bohdan200@gmail.com                         *
 *                                                                         *
 *   Copyright (C) <2019-2020> < Cypress Semiconductor Corporation >       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <transport/transport.h>
#include <jtag/swd.h>
#include <jtag/interface.h>
#include <jtag/commands.h>
#include <jtag/tcl.h>

#include <jtag/drivers/cmsis_dap_usb.h>
#include <helper/time_support.h>

#define KP3_TARGET_VOLTAGE_MAX_ERROR_PC   5
#define KP3_USB_TIMEOUT                   1000u
#define KP3_REQUEST_VERSION               0x80
#define KP3_REQUEST_ACQUIRE               0x85
#define KP3_REQUEST_ACQUIRE_PARAM         0x91
#define KP3_REQUEST_POWER                 0x84
#define KP3_REQUEST_POWER_SET             0x10
#define KP3_REQUEST_POWER_GET             0x11
#define KP3_REQUEST_LED_CONTROL           0x83

#define KP3_LED_STATE_READY               0x00u
#define KP3_LED_STATE_PROGRAMMING         0x01u
#define KP3_LED_STATE_SUCCESS             0x02u
#define KP3_LED_STATE_ERROR               0x03u

#define KP3_REQUEST_SET_ACQUIRE_PARAMS    0x91
#define KP3_ACQUIRE_PARAM_TIMEOUT         0x00
// Not implemented yet
#define KP3_ACQUIRE_PARAM_SEQ_TYPE        0x01
#define KP3_ACQUIRE_PARAM_AP_NUM          0x02

#define INVOKE_CMSIS_DAP(name, ...)       cmsis_dap_adapter_driver.name(__VA_ARGS__)

extern struct adapter_driver kitprog3_adapter_driver;
extern struct jtag_interface kitprog3_dap_interface ;

struct acquire_config {
	bool configured;
	uint8_t target_type;
	uint8_t acquire_mode;
	uint8_t attempts;
	uint8_t acquire_timeout;
	uint8_t acquire_ap;
};

struct power_config {
	bool configured;
	bool enabled;
	uint16_t voltage;
};

struct kp3_version {
	char *fw_loader_dir;
	size_t major;
	size_t minor;
	size_t build;
};

static struct kp3_version g_kp3_latest_ver;
static struct acquire_config acquire_config;
static struct power_config power_config;
static bool voltage_changed;
static uint16_t initial_voltage;

/** ***********************************************************************************************
 * @brief Compares KitProg3 versions represented by kp3_version structure
 * @return -1 (a < b), 0 (a == b) or +1 (a > b)
 *************************************************************************************************/
static int kitprog3_compare_versions(struct kp3_version *a, struct kp3_version *b) {
	if (a->major < b->major) return -1;
	if (a->major > b->major) return 1;
	if (a->minor < b->minor) return -1;
	if (a->minor > b->minor) return 1;
	if (a->build < b->build) return -1;
	if (a->build > b->build) return 1;
	return 0;
}

/** ***********************************************************************************************
 * @brief Performs USB transaction in HID mode.
 * Data to be sent must be stored in dap->packet_buffer.
 * @param timeout timeout value, in milliseconds
 * @param has_cmd_stat true if response to the current request contains status sield in second byte
 * @return ERROR_OK in case of success, ERROR_FAIL otherwise.
 *************************************************************************************************/
static int kitprog3_request_hid(int timeout, bool has_cmd_stat)
{
	struct cmsis_dap *dap = cmsis_dap_handle;
	uint8_t *packet_buffer = dap->packet_buffer;
	size_t packet_size = dap->packet_size;
	int hr;

	hr = hid_write(dap->hid_handle, packet_buffer, packet_size);
	if (hr == -1)
		return ERROR_FAIL;

	do {
		/* Avoid warning during PSoC64 acquisition */
		keep_alive();

		hr = hid_read_timeout(dap->hid_handle, packet_buffer, packet_size, timeout);
		if (hr == -1 || hr == 0)
			return ERROR_FAIL;
	} while (packet_buffer[1] == 1);

	if(has_cmd_stat)
		return packet_buffer[1] == 0 ? ERROR_OK : ERROR_FAIL;

	return ERROR_OK;
}

/** ***********************************************************************************************
 * @brief Performs USB transaction in BULK mode
 * Data to be sent must be stored in dap->packet_buffer.
 * @param timeout timeout value, in milliseconds
 * @param has_cmd_stat true if response to the current request contains status sield in second byte
 * @return ERROR_OK in case of success, ERROR_FAIL otherwise.
 * Received data is stored in dap->packet_buffer.
 *************************************************************************************************/
static int kitprog3_request_bulk(int timeout, bool has_cmd_stat)
{
	struct cmsis_dap *dap = cmsis_dap_handle;
	uint8_t *packet_buffer = dap->packet_buffer;
	int packet_size = dap->packet_size;
	int transferred = 0;
	int hr;

	hr = libusb_bulk_transfer(dap->bulk_handle, (1 | LIBUSB_ENDPOINT_OUT),
			packet_buffer + 1, packet_size - 1, &transferred, KP3_USB_TIMEOUT);
	if (hr != 0)
		return ERROR_FAIL;

	do {
		/* Avoid warning during PSoC64 acquisition */
		keep_alive();

		hr = libusb_bulk_transfer(dap->bulk_handle, (2 | LIBUSB_ENDPOINT_IN),
				packet_buffer, packet_size - 1, &transferred,
				(unsigned)timeout);

		if (hr != 0)
			return ERROR_FAIL;
	} while (packet_buffer[1] == 1);

	if(has_cmd_stat)
		return packet_buffer[1] == 0 ? ERROR_OK : ERROR_FAIL;

	return ERROR_OK;
}

/** ***********************************************************************************************
 * @brief Performs USB transaction. Data to be sent must be stored in dap->packet_buffer.
 * @param timeout timeout value, in milliseconds
 * @param has_cmd_stat true if response to the current request contains status sield in second byte
 * @return ERROR_OK in case of success, ERROR_FAIL otherwise.
 * Received data is stored in dap->packet_buffer.
 *************************************************************************************************/
static int kitprog3_usb_request(int timeout, bool has_cmd_stat)
{
	struct cmsis_dap *dap = cmsis_dap_handle;
	int hr;

	if (dap->is_hid)
		hr = kitprog3_request_hid(timeout, has_cmd_stat);
	else
		hr = kitprog3_request_bulk(timeout, has_cmd_stat);

	return hr;
}

/** ***********************************************************************************************
 * @brief Shows "Please update the firmware message"
 *************************************************************************************************/
static void kitprog3_show_update_fw_message(bool is_fatal)
{
	const char * const message = {
		"\n*******************************************************************************************"
		"\n* KitProg firmware is out of date, please update to the latest version (%zu.%zu.%zu)"
		"\n* using fw-loader tool which can be found in the following folder"
		"\n* %s"
		"\n*******************************************************************************************"
	};

	const struct kp3_version *v = &g_kp3_latest_ver;
	if(is_fatal)
		LOG_ERROR(message, v->major, v->minor, v->build, v->fw_loader_dir);
	else
		LOG_WARNING(message, v->major, v->minor, v->build, v->fw_loader_dir);
}

/** ***********************************************************************************************
 * @brief Controls LED status
 * @param status Type of LED indication. Possible values:
 * - KP3_LED_STATE_READY
 * - KP3_LED_STATE_PROGRAMMING
 * - KP3_LED_STATE_SUCCESS
 * - KP3_LED_STATE_ERROR
 * @return ERROR_OK in case of success, ERROR_FAIL otherwise.
 *************************************************************************************************/
static int kitprog3_led_control(uint8_t status)
{
	struct cmsis_dap *dap = cmsis_dap_handle;
	dap->packet_buffer[0] = 0;
	dap->packet_buffer[1] = KP3_REQUEST_LED_CONTROL;
	dap->packet_buffer[2] = status;

	int hr = kitprog3_usb_request(KP3_USB_TIMEOUT, true);
	if (hr != ERROR_OK)
		LOG_ERROR("kitprog3: led_control command failed");

	return hr;
}

/** ***********************************************************************************************
 * @brief Measures target voltage
 * @param voltage is populated with the target voltage value in millivolts
 * @return ERROR_OK in case of success, ERROR_FAIL otherwise.
 *************************************************************************************************/
static int kitprog3_get_power(uint16_t *voltage)
{
	struct cmsis_dap *dap = cmsis_dap_handle;
	dap->packet_buffer[0] = 0;
	dap->packet_buffer[1] = KP3_REQUEST_POWER;
	dap->packet_buffer[2] = KP3_REQUEST_POWER_GET;

	int hr = kitprog3_usb_request(KP3_USB_TIMEOUT, true);
	if (hr != ERROR_OK) {
		LOG_ERROR("kitprog3: get_power command failed");
		return hr;
	}

	*voltage = (uint16_t)(dap->packet_buffer[3] + (dap->packet_buffer[4] << 8));
	return ERROR_OK;
}

/** ***********************************************************************************************
 * @brief Controls power sypply of the target device. Target voltage must be configured using
 * 'power_config' before calling this function.
 * @return ERROR_OK in case of success, error code otherwise.
 *************************************************************************************************/
static int kitprog3_power_control(void)
{
	if (!power_config.configured) {
		LOG_ERROR("kitprog3: target voltage not configured, (use 'kitprog3 power_config')");
		return ERROR_FAIL;
	}

	uint16_t target_voltage = 0;

	if (power_config.enabled) {
		/* Get current voltage, used for dropout detection */
		int hr = kitprog3_get_power(&target_voltage);
		if(hr != ERROR_OK)
			return hr;
	}

	struct cmsis_dap *dap = cmsis_dap_handle;
	dap->packet_buffer[0] = 0;
	dap->packet_buffer[1] = KP3_REQUEST_POWER;
	dap->packet_buffer[2] = KP3_REQUEST_POWER_SET;
	if (power_config.enabled) {
		/* Report dropout if voltage has changed by more than 5% */
		const int max_error  = KP3_TARGET_VOLTAGE_MAX_ERROR_PC * power_config.voltage / 100;
		if(abs(target_voltage - power_config.voltage) > max_error)
			voltage_changed = true;

		LOG_INFO("kitprog3: powering up target device using KitProg3 (VTarg = %d mV)",
			power_config.voltage);
		dap->packet_buffer[3] = power_config.voltage ? 0x02 : 0x00;
		dap->packet_buffer[4] = power_config.voltage & 0xFF;
		dap->packet_buffer[5] = power_config.voltage >> 8;
	} else {
		LOG_INFO("kitprog3: powering down target device using KitProg3");
		dap->packet_buffer[3] = 0x00;
		dap->packet_buffer[4] = 0x00;
		dap->packet_buffer[5] = 0x00;
	}

	int hr = kitprog3_usb_request(KP3_USB_TIMEOUT, true);
	if (hr != ERROR_OK)
		LOG_ERROR("kitprog3: power_control command failed (target already powered?)");

	if(power_config.enabled && power_config.voltage) {
		/* Wait up to KP3_USB_TIMEOUT for target voltage to stabilise */
		int64_t start = timeval_ms();
		const int max_error  = KP3_TARGET_VOLTAGE_MAX_ERROR_PC * power_config.voltage / 100;

		while(timeval_ms() - start <= KP3_USB_TIMEOUT) {
			alive_sleep(10);

			hr = kitprog3_get_power(&target_voltage);
			if(hr != ERROR_OK)
				return hr;

			if(abs(target_voltage - power_config.voltage) <= max_error)
				break;
		}

		if(timeval_ms() - start > KP3_USB_TIMEOUT)
			LOG_WARNING("Target voltage (%u.%03u V) is not within %d%% of requested %u.%03u V",
						target_voltage / 1000, target_voltage % 1000,
						KP3_TARGET_VOLTAGE_MAX_ERROR_PC,
						power_config.voltage / 1000, power_config.voltage % 1000);
	}

	return hr;
}

/** ***********************************************************************************************
 * @brief Acquires target device. Acquisition mode and parameters must be configured with
 * 'acquire_config' before calling this function
 * @return ERROR_OK in case of success, error code otherwise.
 *************************************************************************************************/
static int kitprog3_acquire_psoc(void)
{
	if (!acquire_config.configured) {
		LOG_ERROR("kitprog3: acquire procedure not configured, (use 'kitprog3 acquire_config')");
		goto error;
	}

	LOG_INFO("kitprog3: acquiring the device...");

	struct cmsis_dap *dap = cmsis_dap_handle;
	int hr = kitprog3_led_control(KP3_LED_STATE_PROGRAMMING);
	if (hr != ERROR_OK)
		goto error;

	if(acquire_config.acquire_timeout) {
		dap->packet_buffer[0] = 0;
		dap->packet_buffer[1] = KP3_REQUEST_ACQUIRE_PARAM;
		dap->packet_buffer[2] = KP3_ACQUIRE_PARAM_TIMEOUT;
		dap->packet_buffer[3] = acquire_config.acquire_timeout;

		hr = kitprog3_usb_request(KP3_USB_TIMEOUT, true);
		if (hr != ERROR_OK) {
			LOG_WARNING("KitProg3: Acquire timeout not configurable, please update the firmware");
		}

		dap->packet_buffer[0] = 0;
		dap->packet_buffer[1] = KP3_REQUEST_ACQUIRE_PARAM;
		dap->packet_buffer[2] = KP3_ACQUIRE_PARAM_AP_NUM;
		dap->packet_buffer[3] = acquire_config.acquire_ap;

		hr = kitprog3_usb_request(KP3_USB_TIMEOUT, true);
		if (hr != ERROR_OK) {
			LOG_WARNING("KitProg3: Acquire AP not configurable, please update the firmware");
		}
	}

	dap->packet_buffer[0] = 0;
	dap->packet_buffer[1] = KP3_REQUEST_ACQUIRE;
	dap->packet_buffer[2] = acquire_config.target_type;
	dap->packet_buffer[3] = acquire_config.acquire_mode;
	dap->packet_buffer[4] = acquire_config.attempts;

	hr = kitprog3_usb_request(acquire_config.attempts * KP3_USB_TIMEOUT, true);
	if (hr != ERROR_OK) {
		LOG_ERROR("kitprog3: acquire_psoc request failed");
		goto error;
	}

	if (dap->packet_buffer[2] == 0) {
		LOG_ERROR("kitprog3: failed to acquire the device");
		goto error;
	}

	kitprog3_led_control(KP3_LED_STATE_SUCCESS);
	return ERROR_OK;

error:
	kitprog3_led_control(KP3_LED_STATE_ERROR);
	return ERROR_FAIL;
}

/** ***********************************************************************************************
 * @brief Compares KitProg version with the latest version available (if set) and warns the user
 * in case firmware update is needed
 * @return ERROR_OK in case of success, error code otherwise.
 *************************************************************************************************/
static int kitprog3_check_version(void)
{
	struct cmsis_dap *dap = cmsis_dap_handle;

	dap->packet_buffer[0] = 0;
	dap->packet_buffer[1] = 0;
	dap->packet_buffer[2] = 4;

	int hr = kitprog3_usb_request(KP3_USB_TIMEOUT, false);
	if (hr != ERROR_OK) {
		LOG_ERROR("kitprog3: get_version command failed");
		return hr;
	}

	int is_kp3 = strcmp("1.10", (char *)&dap->packet_buffer[2]);

	if(!is_kp3) {
		kitprog3_show_update_fw_message(true);
		return ERROR_FAIL;
	}

	dap->packet_buffer[0] = 0;
	dap->packet_buffer[1] = KP3_REQUEST_VERSION;

	hr = kitprog3_usb_request(KP3_USB_TIMEOUT, true);
	if (hr != ERROR_OK) {
		LOG_ERROR("kitprog3: get_version command failed");
		return hr;
	}

	struct kp3_version kp3_ver;
	kp3_ver.major = dap->packet_buffer[2] + (dap->packet_buffer[3] << 8);
	kp3_ver.minor = dap->packet_buffer[4] + (dap->packet_buffer[5] << 8);
	kp3_ver.build = dap->packet_buffer[10] + (dap->packet_buffer[11] << 8);

	LOG_INFO("KitProg3: FW version: %zu.%zu.%zu", kp3_ver.major, kp3_ver.minor, kp3_ver.build);
	if(kitprog3_compare_versions(&kp3_ver, &g_kp3_latest_ver) < 0)
		kitprog3_show_update_fw_message(false);

	/* Workaround for KP3 FW < 1.20.591 in BULK mode */
	if(kitprog3_compare_versions(&kp3_ver, &(struct kp3_version){NULL, 1, 20, 591}) < 0 \
			&& !cmsis_dap_handle->is_hid)
	{
		cmsis_dap_handle->packet_count = 1;
		LOG_INFO("KitProg3: Pipelined transfers disabled, please update the firmware");
	} else {
		LOG_INFO("KitProg3: Pipelined transfers enabled");
	}

	return ERROR_OK;
}

/** ***********************************************************************************************
 * @brief Resets Acquisition parameters to their default values
 *************************************************************************************************/
static void kitprog3_reset_acquire_params(void)
{
	struct cmsis_dap *dap = cmsis_dap_handle;

	/* Reset all possibly overridden KitProg3 parameters :
	 * Parameter = 0: Set Acquire Timeout to zero
	 * set to zero - reset to default */
	dap->packet_buffer[0] = 0;
	dap->packet_buffer[1] = KP3_REQUEST_SET_ACQUIRE_PARAMS;
	dap->packet_buffer[2] = KP3_ACQUIRE_PARAM_TIMEOUT;
	dap->packet_buffer[3] = 0;
	kitprog3_usb_request(KP3_USB_TIMEOUT, true);

#if defined(KP3_ACQUIRE_PARAM_SEQ_TYPE)
	/* Parameter = 1: Set type of DAP handshake
	 * set to zero - swd line reset for PSoC4, jtag-to-swd for others */
	dap->packet_buffer[0] = 0;
	dap->packet_buffer[1] = KP3_REQUEST_SET_ACQUIRE_PARAMS;
	dap->packet_buffer[2] = KP3_ACQUIRE_PARAM_SEQ_TYPE;
	dap->packet_buffer[3] = 0;
	kitprog3_usb_request(KP3_USB_TIMEOUT, true);
#endif

	/* Parameter = 2:  Set DAP AP through which the test mode bit will be set
	 * set to zero - SysAP */
	dap->packet_buffer[0] = 0;
	dap->packet_buffer[1] = KP3_REQUEST_SET_ACQUIRE_PARAMS;
	dap->packet_buffer[2] = KP3_ACQUIRE_PARAM_AP_NUM;
	dap->packet_buffer[3] = 0;
	kitprog3_usb_request(KP3_USB_TIMEOUT, true);
}

/** ***********************************************************************************************
 * @brief Initializes KitProg3 driver and underlying CMSIS-DAP subsystem. Function optionnally
 * powers up and acquires target device.
 * @return ERROR_OK in case of success, error code otherwise.
 *************************************************************************************************/
static int kitprog3_init(void)
{
	kitprog3_adapter_driver.speed = cmsis_dap_adapter_driver.speed;
	kitprog3_adapter_driver.speed_div = cmsis_dap_adapter_driver.speed_div;
	kitprog3_adapter_driver.khz = cmsis_dap_adapter_driver.khz;
	kitprog3_adapter_driver.reset = cmsis_dap_adapter_driver.reset;

	int hr = INVOKE_CMSIS_DAP(init);
	if (hr != ERROR_OK)
		return hr;

	kitprog3_reset_acquire_params();

	hr = kitprog3_check_version();
	if (hr != ERROR_OK)
		return hr;

	if (power_config.configured) {
		hr = kitprog3_power_control();
		if (hr != ERROR_OK)
			return hr;
	}

	hr = kitprog3_get_power(&initial_voltage);
	if (hr == ERROR_OK)
		LOG_INFO("VTarget = %u.%03u V", initial_voltage / 1000, initial_voltage % 1000);

	if (acquire_config.configured)
		kitprog3_acquire_psoc();

	kitprog3_led_control(KP3_LED_STATE_READY);

	return ERROR_OK;
}

/** ***********************************************************************************************
 * @brief Deinitialezes KitProg3 driver and underlying CMSIS-DAP subsystem
 * @return ERROR_OK in case of success, error code otherwise.
 *************************************************************************************************/
static int kitprog3_quit(void)
{
	kitprog3_led_control(KP3_LED_STATE_READY);
	kitprog3_reset_acquire_params();
	free(g_kp3_latest_ver.fw_loader_dir); /* free(NULL) is OK */

	return INVOKE_CMSIS_DAP(quit);
}

/**************************************************************************************************
 * Configuration command handlers
 *************************************************************************************************/
COMMAND_HANDLER(cmsis_dap_handle_acquire_config_command)
{
	if (CMD_ARGC != 1 && CMD_ARGC != 4 && CMD_ARGC != 6)
		return ERROR_COMMAND_ARGUMENT_INVALID;

	bool enabled = false;
	uint8_t target = 0;
	uint8_t mode = 0;
	uint8_t attempts = 0;
	uint8_t timeout_sec = 0;
	uint8_t ap_num = 255;

	COMMAND_PARSE_ON_OFF(CMD_ARGV[0], enabled);

	if (enabled) {
		if (CMD_ARGC != 4 && CMD_ARGC != 6)
			return ERROR_COMMAND_ARGUMENT_INVALID;

		COMMAND_PARSE_NUMBER(u8, CMD_ARGV[1], target);
		COMMAND_PARSE_NUMBER(u8, CMD_ARGV[2], mode);
		COMMAND_PARSE_NUMBER(u8, CMD_ARGV[3], attempts);

		if(CMD_ARGC == 6) {
			COMMAND_PARSE_NUMBER(u8, CMD_ARGV[4], timeout_sec);
			COMMAND_PARSE_NUMBER(u8, CMD_ARGV[5], ap_num);
		}
	}

	acquire_config.configured = enabled;
	acquire_config.target_type = target;
	acquire_config.acquire_mode = mode;
	acquire_config.attempts = attempts;
	acquire_config.acquire_timeout = timeout_sec;
	acquire_config.acquire_ap = ap_num;

	return ERROR_OK;
}

COMMAND_HANDLER(cmsis_dap_handle_power_config_command)
{
	if (CMD_ARGC  == 0)
		return ERROR_COMMAND_ARGUMENT_INVALID;

	bool enabled = false;
	uint16_t voltage = 0;

	COMMAND_PARSE_ON_OFF(CMD_ARGV[0], enabled);

	if (enabled) {
		if (CMD_ARGC != 2)
			return ERROR_COMMAND_ARGUMENT_INVALID;
		COMMAND_PARSE_NUMBER(u16, CMD_ARGV[1], voltage);
	}

	power_config.configured = true;
	power_config.enabled = enabled;
	power_config.voltage = voltage;

	return ERROR_OK;
}

/**************************************************************************************************
 * Other command handlers
 *************************************************************************************************/
COMMAND_HANDLER(cmsis_dap_handle_acquire_psoc_command)
{
	if (CMD_ARGC != 0)
		return ERROR_COMMAND_ARGUMENT_INVALID;

	return kitprog3_acquire_psoc();
}

COMMAND_HANDLER(cmsis_dap_handle_power_control_command)
{
	if (CMD_ARGC != 1)
		return ERROR_COMMAND_ARGUMENT_INVALID;

	bool enabled = false;
	COMMAND_PARSE_ON_OFF(CMD_ARGV[0], enabled);
	power_config.enabled = enabled;

	return kitprog3_power_control();
}

COMMAND_HANDLER(cmsis_dap_handle_get_power_command)
{
	if (CMD_ARGC != 0)
		return ERROR_COMMAND_ARGUMENT_INVALID;

	uint16_t voltage = 0;
	int hr = kitprog3_get_power(&voltage);
	if (hr != ERROR_OK)
		return hr;

	command_print(CMD, "VTarget = %u.%03u V", voltage / 1000, voltage % 1000);
	return ERROR_OK;
}

COMMAND_HANDLER(cmsis_dap_handle_get_version_command)
{
	if (CMD_ARGC != 0)
		return ERROR_COMMAND_ARGUMENT_INVALID;

	struct cmsis_dap *dap = cmsis_dap_handle;
	dap->packet_buffer[0] = 0;
	dap->packet_buffer[1] = KP3_REQUEST_VERSION;

	int hr = kitprog3_usb_request(KP3_USB_TIMEOUT, true);
	if (hr != ERROR_OK) {
		LOG_ERROR("kitprog3: get_version command failed");
		return hr;
	}

	struct kp3_version kp3_ver;
	kp3_ver.major = dap->packet_buffer[2] + (dap->packet_buffer[3] << 8);
	kp3_ver.minor = dap->packet_buffer[4] + (dap->packet_buffer[5] << 8);
	kp3_ver.build = dap->packet_buffer[10] + (dap->packet_buffer[11] << 8);

	uint16_t kit_hw_id = dap->packet_buffer[6] + (dap->packet_buffer[7] << 8);
	uint8_t kit_prot_major = dap->packet_buffer[8];
	uint8_t kit_prot_minor = dap->packet_buffer[9];

	command_print(CMD, "KitProg3 FW Ver = %zu.%zu.%zu, HW ID = %u, KHPI Ver = %u.%u",
				kp3_ver.major, kp3_ver.minor, kp3_ver.build,
				kit_hw_id, kit_prot_major, kit_prot_minor);

	return ERROR_OK;
}

COMMAND_HANDLER(cmsis_dap_handle_led_command)
{
	if (CMD_ARGC != 1)
		return ERROR_COMMAND_ARGUMENT_INVALID;

	uint8_t status = KP3_LED_STATE_ERROR;
	COMMAND_PARSE_NUMBER(u8, CMD_ARGV[0], status);

	return kitprog3_led_control(status);
}

COMMAND_HANDLER(cmsis_dap_handle_set_latest_version_command)
{
	if (CMD_ARGC != 2)
		return ERROR_COMMAND_ARGUMENT_INVALID;

	struct kp3_version kp3_ver;

	if(sscanf(CMD_ARGV[1], "%zu.%zu.%zu", &kp3_ver.major, &kp3_ver.minor, &kp3_ver.build) != 3) {
		LOG_ERROR("KitProg3: Invalid version format, should match %%zu.%%zu.%%zu pattern");
		return ERROR_COMMAND_ARGUMENT_INVALID;
	}

	/* Remember only the latest version found */
	if(kitprog3_compare_versions(&kp3_ver, &g_kp3_latest_ver) > 0) {
		free(g_kp3_latest_ver.fw_loader_dir); /* free(NULL) is OK */
		g_kp3_latest_ver.fw_loader_dir = strdup(CMD_ARGV[0]);
		g_kp3_latest_ver.major = kp3_ver.major;
		g_kp3_latest_ver.minor = kp3_ver.minor;
		g_kp3_latest_ver.build = kp3_ver.build;
	}

	return ERROR_OK;
}

static const struct command_registration kitprog3_subcommand_handlers[] = {
	{
		.name = "acquire_config",
		.handler = &cmsis_dap_handle_acquire_config_command,
		.mode = COMMAND_CONFIG,
		.usage = "<enabled on|off> <target_type (0:PSoC4, 1:PSoC5-LP, 2:PSoC6...)>"
			"<mode (0: Reset, 1: Power Cycle)> <attempts> [<timeout_sec> <ap_num>]",
		.help = "Controls PSoC acquisition during init phase",
	},
	{
		.name = "acquire_psoc",
		.handler = &cmsis_dap_handle_acquire_psoc_command,
		.mode = COMMAND_EXEC,
		.usage = "",
		.help = "Acquire the device",
	},
	{
		.name = "power_config",
		.handler = &cmsis_dap_handle_power_config_command,
		.mode = COMMAND_CONFIG,
		.usage = "<enabled on|off> [voltage (mV)]",
		.help = "Controls the target's power supply during init phase",
	},
	{
		.name = "power_control",
		.handler = &cmsis_dap_handle_power_control_command,
		.mode = COMMAND_EXEC,
		.usage = "[on|off]",
		.help = "Controls the target's power supply",
	},
	{
		.name = "led_control",
		.handler = &cmsis_dap_handle_led_command,
		.mode = COMMAND_EXEC,
		.usage = "<type (0:READY, 1:PROGRAMMING, 2:SUCCESS, 3:ERROR)>",
		.help = "Controls LED state of the kp3",
	},
	{
		.name = "get_power",
		.handler = &cmsis_dap_handle_get_power_command,
		.mode = COMMAND_EXEC,
		.usage = "",
		.help = "Reports the target's power supply voltage",
	},
	{
		.name = "get_version",
		.handler = &cmsis_dap_handle_get_version_command,
		.mode = COMMAND_EXEC,
		.usage = "",
		.help = "Reports the target's firmware and hardware versions",
	},
	{
		.name = "set_latest_version",
		.handler = &cmsis_dap_handle_set_latest_version_command,
		.mode = COMMAND_CONFIG,
		.usage = "",
		.help = "Sets expexted KitProg version. OpenOCD will warn the user if FW version is out of date.",
	},
	COMMAND_REGISTRATION_DONE
};

static const struct command_registration kitprog3_command_handlers[] = {
	{
		.name = "kitprog3",
		.mode = COMMAND_ANY,
		.help = "perform KitProg3 management",
		.usage = "<cmd>",
		.chain = kitprog3_subcommand_handlers,
	},
	{
		.chain = cmsis_dap_command_handlers,
	},
	COMMAND_REGISTRATION_DONE
};

#define POWER_STABLE_TIMEOUT_MS 5000l
static int kitprog3_power_dropout(int *power_dropout)
{
	const int max_error  = KP3_TARGET_VOLTAGE_MAX_ERROR_PC * initial_voltage / 100;
	static int64_t last_mv_change_time;

	uint16_t now_mv;
	int hr = kitprog3_get_power(&now_mv);
	if (hr != ERROR_OK)
		return hr;

	bool dropout = false;
	static uint16_t prev_mv;

	const bool mv_wrong = abs(initial_voltage - now_mv) > max_error;
	const bool mv_now_changed = abs(prev_mv - now_mv) > max_error;
	prev_mv = now_mv;

	if(mv_now_changed)
		last_mv_change_time = timeval_ms();

	if (mv_wrong)
		dropout = true;

	if (dropout && timeval_ms() - last_mv_change_time > POWER_STABLE_TIMEOUT_MS) {
		LOG_INFO("Voltage is stable for more than %lu sec, assuming power is good",
				 POWER_STABLE_TIMEOUT_MS / 1000);
		initial_voltage = now_mv;
		dropout = false;
	}

	*power_dropout = (int)(voltage_changed | dropout);
	voltage_changed = false;

	return ERROR_OK;
}

static const char *const kitprog3_transport[] = { "swd", "jtag", NULL };

struct adapter_driver kitprog3_adapter_driver = {
	.name = "kitprog3",
	.commands = kitprog3_command_handlers,
	.transports = kitprog3_transport,
	.speed = NULL,
	.speed_div = NULL,
	.khz = NULL,
	.reset = NULL,
	.init = kitprog3_init,
	.quit = kitprog3_quit,
	.power_dropout = kitprog3_power_dropout,

	.jtag_ops = &cmsis_dap_interface,
	.swd_ops = &cmsis_dap_swd_driver,
};
