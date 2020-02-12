/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2018 by Bohdan Tymkiv                                   *
 *   bohdan.tymkiv@cypress.com bohdan200@gmail.com                         *
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
#define KP3_REQUEST_POWER                 0x84
#define KP3_REQUEST_POWER_SET             0x10
#define KP3_REQUEST_POWER_GET             0x11
#define KP3_REQUEST_LED_CONTROL           0x83

#define KP3_LED_STATE_READY               0x00u
#define KP3_LED_STATE_PROGRAMMING         0x01u
#define KP3_LED_STATE_SUCCESS             0x02u
#define KP3_LED_STATE_ERROR               0x03u

#define INVOKE_CMSIS_DAP(name, ...)       cmsis_dap_interface.name(__VA_ARGS__)

extern struct jtag_interface kitprog3_interface;
static bool power_dropout_detected;

struct acquire_config {
	bool configured;
	uint8_t target_type;
	uint8_t acquire_mode;
	uint8_t attempts;
};

struct power_config {
	bool configured;
	bool enabled;
	uint16_t voltage;
};

static struct acquire_config acquire_config;
static struct power_config power_config;

static uint16_t g_kit_fw_major;
static uint16_t g_kit_fw_minor;
static uint16_t g_fw_build_number;

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
			power_dropout_detected = true;

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

	LOG_INFO("kitprog3: acquiring PSoC device...");

	struct cmsis_dap *dap = cmsis_dap_handle;
	int hr = kitprog3_led_control(KP3_LED_STATE_PROGRAMMING);
	if (hr != ERROR_OK)
		goto error;

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
		LOG_ERROR("kitprog3: failed to acquire PSoC device");
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
		LOG_ERROR("*******************************************************************************************");
		LOG_ERROR("* KitProg firmware is out of date, please update to the latest version using fw-loader at *");
		LOG_ERROR("* ModusToolbox/tools/fw-loader                                                            *");
		LOG_ERROR("*******************************************************************************************");
		return ERROR_FAIL;
	}

	dap->packet_buffer[0] = 0;
	dap->packet_buffer[1] = KP3_REQUEST_VERSION;

	hr = kitprog3_usb_request(KP3_USB_TIMEOUT, true);
	if (hr != ERROR_OK) {
		LOG_ERROR("kitprog3: get_version command failed");
		return hr;
	}

	uint16_t kit_fw_major = dap->packet_buffer[2] + (dap->packet_buffer[3] << 8);
	uint16_t kit_fw_minor = dap->packet_buffer[4] + (dap->packet_buffer[5] << 8);
	uint16_t fw_build_number = dap->packet_buffer[10] + (dap->packet_buffer[11] << 8);

	if(!g_kit_fw_major)
		return ERROR_OK;

	if(kit_fw_major < g_kit_fw_major)
		goto warn_user;

	if(kit_fw_minor < g_kit_fw_minor)
		goto warn_user;

	if(fw_build_number < g_fw_build_number)
		goto warn_user;

	return ERROR_OK;

warn_user:
	LOG_WARNING("*******************************************************************************************");
	LOG_WARNING("* KitProg firmware is out of date, please update to the latest version using fw-loader at *");
	LOG_WARNING("* ModusToolbox/tools/fw-loader                                                            *");
	LOG_WARNING("*******************************************************************************************");
	return ERROR_OK;
}

/** ***********************************************************************************************
 * @brief Initializes KitProg3 driver and underlying CMSIS-DAP subsystem. Function optionnally
 * powers up and acquires target device.
 * @return ERROR_OK in case of success, error code otherwise.
 *************************************************************************************************/
static int kitprog3_init(void)
{
	kitprog3_interface.execute_queue   = cmsis_dap_interface.execute_queue;
	kitprog3_interface.speed = cmsis_dap_interface.speed;
	kitprog3_interface.speed_div = cmsis_dap_interface.speed_div;
	kitprog3_interface.khz = cmsis_dap_interface.khz;

	int hr = INVOKE_CMSIS_DAP(init);
	if (hr != ERROR_OK)
		return hr;

	hr = kitprog3_check_version();
	if (hr != ERROR_OK)
		return hr;

	if (power_config.configured) {
		hr = kitprog3_power_control();
		if (hr != ERROR_OK)
			return hr;
	}

	uint16_t voltage;
	hr = kitprog3_get_power(&voltage);
	if (hr == ERROR_OK)
		LOG_INFO("VTarget = %u.%03u V", voltage / 1000, voltage % 1000);

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
	return INVOKE_CMSIS_DAP(quit);
}

/**************************************************************************************************
 * Configuration command handlers
 *************************************************************************************************/
COMMAND_HANDLER(cmsis_dap_handle_acquire_config_command)
{
	if (CMD_ARGC  == 0)
		return ERROR_COMMAND_ARGUMENT_INVALID;

	bool enabled = false;
	uint8_t target = 0;
	uint8_t mode = 0;
	uint8_t attempts = 0;

	COMMAND_PARSE_ON_OFF(CMD_ARGV[0], enabled);

	if (enabled) {
		if (CMD_ARGC != 4)
			return ERROR_COMMAND_ARGUMENT_INVALID;
		COMMAND_PARSE_NUMBER(u8, CMD_ARGV[1], target);
		COMMAND_PARSE_NUMBER(u8, CMD_ARGV[2], mode);
		COMMAND_PARSE_NUMBER(u8, CMD_ARGV[3], attempts);
	}

	acquire_config.configured = enabled;
	acquire_config.target_type = target;
	acquire_config.acquire_mode = mode;
	acquire_config.attempts = attempts;

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

	command_print(CMD_CTX, "VTarget = %u.%03u V", voltage / 1000, voltage % 1000);
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

	uint16_t kit_fw_major = dap->packet_buffer[2] + (dap->packet_buffer[3] << 8);
	uint16_t kit_fw_minor = dap->packet_buffer[4] + (dap->packet_buffer[5] << 8);

	uint16_t kit_hw_id = dap->packet_buffer[6] + (dap->packet_buffer[7] << 8);

	uint8_t kit_prot_major = dap->packet_buffer[8];
	uint8_t kit_prot_minor = dap->packet_buffer[9];

	uint16_t fw_build_number = dap->packet_buffer[10] + (dap->packet_buffer[11] << 8);

	command_print(CMD_CTX, "KitProg3 FW Ver = %u.%u.%u, HW ID = %u, KHPI Ver = %u.%u",
				 kit_fw_major, kit_fw_minor, fw_build_number, kit_hw_id, kit_prot_major, kit_prot_minor);

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
	int hr = ERROR_FAIL;

	if (CMD_ARGC != 1)
		return ERROR_COMMAND_ARGUMENT_INVALID;

	char *copy = strdup(CMD_ARGV[0]);
	if(!copy)
		return ERROR_FAIL;

	char *tok = strtok(copy, ".");
	if(!tok)
		goto exit;

	g_kit_fw_major = atoi(tok);

	tok = strtok(NULL, ".");
	if(!tok)
		goto exit;

	g_kit_fw_minor = atoi(tok);

	tok = strtok(NULL, ".");
	if(!tok)
		goto exit;

	g_fw_build_number = atoi(tok);

	hr = ERROR_OK;

exit:
	free(copy);
	return hr;
}

static const struct command_registration kitprog3_subcommand_handlers[] = {
	{
		.name = "acquire_config",
		.handler = &cmsis_dap_handle_acquire_config_command,
		.mode = COMMAND_CONFIG,
		.usage = "<enabled on|off> [target_type (0:PSoC4, 1:PSoC5-LP, 2:PSoC6...)] "
			"[mode (0: Reset, 1: Power Cycle)] [attempts]",
		.help = "Controls PSoC acquisition during init phase",
	},
	{
		.name = "acquire_psoc",
		.handler = &cmsis_dap_handle_acquire_psoc_command,
		.mode = COMMAND_EXEC,
		.usage = "",
		.help = "Acquire PSoC device",
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

static int kitprog3_power_dropout(int *power_dropout)
{
	*power_dropout = (int)power_dropout_detected;
	power_dropout_detected = false;

	return ERROR_OK;
}

static const char *const kitprog3_transport[] = { "swd", "jtag", NULL };
struct jtag_interface kitprog3_interface = {
	.name = "kitprog3",
	.commands = kitprog3_command_handlers,
	.swd = &cmsis_dap_swd_driver,
	.transports = kitprog3_transport,
	.execute_queue = NULL,
	.speed = NULL,
	.speed_div = NULL,
	.khz = NULL,
	.init = kitprog3_init,
	.quit = kitprog3_quit,
	.power_dropout = kitprog3_power_dropout,
};
