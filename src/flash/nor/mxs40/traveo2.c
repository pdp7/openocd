/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2019 by Bohdan Tymkiv, Mykola Tuzyak                    *
 *   bohdan.tymkiv@cypress.com bohdan200@gmail.com                         *
 *   mykola.tyzyak@cypress.com                                             *
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

#include "flash/nor/mxs40/mxs40.h"

#include "flash/nor/imp.h"
#include "target/target.h"
#include "target/cortex_m.h"
#include "target/breakpoints.h"
#include "target/target_type.h"
#include "time_support.h"
#include "target/algorithm.h"
#include "target/image.h"
#include "flash/progress.h"

#define MEM_SFLASH_SIZE                32768u

#define FLASHC_BASE                 0x40240000
#define FLASHC_FLASH_CTL            (FLASHC_BASE + 0x00)
#define FLASH_CTL_MAIN_ECC_EN       (0x01 << 16)
#define FLASH_CTL_WORK_ECC_EN       (0x01 << 20)
#define FLASH_CTL_MAIN_ERR_SILENT   (0x01 << 18)
#define FLASH_CTL_WORK_ERR_SILENT   (0x01 << 22)
#define FLASH_CTL_MAIN_ECC_INJ_EN   (0x01 << 17)
#define FLASH_CTL_WORK_ECC_INJ_EN   (0x01 << 21)

#define FAULT_STRUCT_SIZE        0x00000100
#define FAULT_STATUS_VALID_MASK  0x80000000
#define FAULT_BASE(n)     (0x40210000 + (n) * FAULT_STRUCT_SIZE)

#define FAULT_CTL(n)      (FAULT_BASE((n)) + 0x00)
#define FAULT_STATUS(n)   (FAULT_BASE((n)) + 0x0C)
#define FAULT_DATA0(n)    (FAULT_BASE((n)) + 0x10)
#define FAULT_DATA1(n)    (FAULT_BASE((n)) + 0x14)
#define FAULT_DATA2(n)    (FAULT_BASE((n)) + 0x18)
#define FAULT_DATA3(n)    (FAULT_BASE((n)) + 0x1C)
#define FAULT_MASK0(n)    (FAULT_BASE((n)) + 0x50)
#define FAULT_MASK1(n)    (FAULT_BASE((n)) + 0x54)
#define FAULT_MASK2(n)    (FAULT_BASE((n)) + 0x58)

#define FAULT_MASK1_MAIN_C_ECC  (0x01 << 17)
#define FAULT_MASK1_MAIN_NC_ECC (0x01 << 18)
#define FAULT_MASK1_WORK_C_ECC  (0x01 << 20)
#define FAULT_MASK1_WORK_NC_ECC (0x01 << 21)
#define FAULT_MASK1_ENABLE_ECC_MASK (FAULT_MASK1_MAIN_C_ECC | FAULT_MASK1_MAIN_NC_ECC | \
	FAULT_MASK1_WORK_C_ECC | FAULT_MASK1_WORK_NC_ECC)

#define MEM_SPCIF3_GEOMETRY            0x4024F00Cu
#define MEM_BASE_IPC2                  0x40220040u
#define MEM_IPC2_INTR_MASK             0x40221008u
#define MEM_VTBASE2_CM0                0x40201120u
#define MEM_VTBASE2_CM4                0x40200200u
#define MEM_IPC2_ACQUIRE               (MEM_BASE_IPC2 + 0x00u)
#define MEM_IPC2_RELEASE               (MEM_BASE_IPC2 + 0x04u)
#define MEM_IPC2_NOTIFY                (MEM_BASE_IPC2 + 0x08u)
#define MEM_IPC2_DATA                  (MEM_BASE_IPC2 + 0x0Cu)
#define MEM_IPC2_LOCK_STATUS           (MEM_BASE_IPC2 + 0x1Cu)

/* Traveo-II registers */
const struct mxs40_regs traveo2_regs = {
	.variant = MXS40_VARIANT_TRAVEO_II,
	.spcif_geometry = MEM_SPCIF3_GEOMETRY,
	.ipc_acquire = MEM_IPC2_ACQUIRE,
	.ipc_release = MEM_IPC2_RELEASE,
	.ipc_notify = MEM_IPC2_NOTIFY,
	.ipc_data = MEM_IPC2_DATA,
	.ipc_lock_stat = MEM_IPC2_LOCK_STATUS,
	.ipc_intr = MEM_IPC2_INTR_MASK,
	.vtbase = {MEM_VTBASE2_CM0, MEM_VTBASE2_CM4, 0, },
	.mem_base_main = {0x10000000, 0,},
	.mem_base_work = {0x14000000, 0,},
	.mem_base_sflash = {0x17000000, 0,},
	.mem_base_efuses = {0, 0,},
};

#define MEM_BASE_IPC3                  0x40220060u
#define MEM_IPC3_ACQUIRE               (MEM_BASE_IPC3 + 0x00u)
#define MEM_IPC3_RELEASE               (MEM_BASE_IPC3 + 0x04u)
#define MEM_IPC3_NOTIFY                (MEM_BASE_IPC3 + 0x08u)
#define MEM_IPC3_DATA                  (MEM_BASE_IPC3 + 0x0Cu)
#define MEM_IPC3_LOCK_STATUS           (MEM_BASE_IPC3 + 0x1Cu)

/* Traveo-II 8M registers */
const struct mxs40_regs traveo2_8m_regs = {
	.variant = MXS40_VARIANT_TRAVEO_II_8M,
	.spcif_geometry = MEM_SPCIF3_GEOMETRY,
	.ipc_acquire = MEM_IPC3_ACQUIRE,
	.ipc_release = MEM_IPC3_RELEASE,
	.ipc_notify = MEM_IPC3_NOTIFY,
	.ipc_data = MEM_IPC3_DATA,
	.ipc_lock_stat = MEM_IPC3_LOCK_STATUS,
	.ipc_intr = MEM_IPC2_INTR_MASK,
	.vtbase = {MEM_VTBASE2_CM0, MEM_VTBASE2_CM4, 0, },
	.mem_base_main = {0x10000000, // present on Si and PSVP
					  0x102f8000, 0x105F0000, 0x10610000, // 6M PSVP
					  0x10400000, // 8M PSVP
					  0 // MARKER
					  },
	.mem_base_work = {0x14000000, 0,},
	.mem_base_sflash = {0x17000000, 0,},
	.mem_base_efuses = {0, 0,},
};

static bool g_ecc_enabled;

/** ***********************************************************************************************
 * @brief Configures ECC error reporting on Traveo-II devices
 * @param target current target
 * @param enabled true if ECC error reporting should be enabled
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int traveo2_configure_ecc(struct target *target, bool enabled)
{
	int hr;

	for (size_t idx = 1; idx <= 3; idx++) {
		/* Disable FAULT[1] */
		hr = target_write_u32(target, FAULT_CTL(idx), 0);
		if (hr != ERROR_OK)
			return hr;

		hr = target_write_u32(target, FAULT_MASK0(idx), 0);
		if (hr != ERROR_OK)
			return hr;

		hr = target_write_u32(target, FAULT_MASK1(idx), 0);
		if (hr != ERROR_OK)
			return hr;

		hr = target_write_u32(target, FAULT_MASK2(idx), 0);
		if (hr != ERROR_OK)
			return hr;
	}

	/* Common config for FAULT[0] */
	hr = target_write_u32(target, FAULT_CTL(0), 0);
	if (hr != ERROR_OK)
		return hr;

	hr = target_write_u32(target, FAULT_MASK0(0), 0);
	if (hr != ERROR_OK)
		return hr;

	hr = target_write_u32(target, FAULT_MASK2(0), 0);
	if (hr != ERROR_OK)
		return hr;

	uint32_t flashc_ctl_val = 0;
	hr = target_read_u32(target, FLASHC_FLASH_CTL, &flashc_ctl_val);
	if (hr != ERROR_OK)
		return hr;

	if (enabled) {
		flashc_ctl_val |=
			(FLASH_CTL_MAIN_ECC_EN | FLASH_CTL_WORK_ECC_EN | FLASH_CTL_MAIN_ERR_SILENT |
			FLASH_CTL_WORK_ERR_SILENT);
		hr = target_write_u32(target, FLASHC_FLASH_CTL, flashc_ctl_val);
		if (hr != ERROR_OK)
			return hr;

		hr = target_write_u32(target, FAULT_MASK1(0), FAULT_MASK1_ENABLE_ECC_MASK);
		if (hr != ERROR_OK)
			return hr;
	} else {
		flashc_ctl_val &= ~(FLASH_CTL_MAIN_ECC_EN | FLASH_CTL_WORK_ECC_EN);
		hr = target_write_u32(target, FLASHC_FLASH_CTL, flashc_ctl_val);
		if (hr != ERROR_OK)
			return hr;
		hr = target_write_u32(target, FAULT_MASK1(0), 0);
		if (hr != ERROR_OK)
			return hr;
	}

	return ERROR_OK;
}

/** ***********************************************************************************************
 * @brief Performs Flash Read operation with ECC error reporting. This function is used in Traveo-II
 * devices only since PSoC6 does not support ECC.
 * @param bank The bank to read
 * @param buffer The data bytes read
 * @param offset The offset into the chip to read
 * @param count The number of bytes to read
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int traveo2_flash_read(struct flash_bank *bank, uint8_t *buffer, uint32_t offset,
	uint32_t count)
{
	if (!g_ecc_enabled)
		return default_flash_read(bank, buffer, offset, count);

	assert(offset % 4 == 0);
	assert(count % 4 == 0);
	int hr = target_write_u32(bank->target, FAULT_STATUS(0), 0x00);
	if (hr != ERROR_OK)
		return hr;

	uint32_t address = bank->base + offset;

	while (count) {
		hr = target_read_buffer(bank->target, address, 4, buffer);
		if (hr != ERROR_OK)
			return hr;

		uint32_t status = 0;
		do {
			hr = target_read_u32(bank->target, FAULT_STATUS(0), &status);
			if (hr != ERROR_OK)
				return hr;

			if (status & FAULT_STATUS_VALID_MASK) {
				uint32_t er_addr;
				hr = target_read_u32(bank->target, FAULT_DATA0(0), &er_addr);
				if (hr != ERROR_OK)
					return hr;

				er_addr |= (address & 0xF8000000);
				LOG_WARNING("ECC Error at address 0x%08X", er_addr);

				hr = target_write_u32(bank->target, FAULT_STATUS(0), 0x00);
				if (hr != ERROR_OK)
					return hr;
			}
		} while (status & FAULT_STATUS_VALID_MASK);

		count -= 4;
		buffer += 4;
		address += 4;
	}

	return ERROR_OK;
}

/** ***********************************************************************************************
 * @brief Performs Erase operation. Function will try to use biggest erase block possible to
 * speedup the operation.
 *
 * @param bank current flash bank
 * @param first first sector to erase
 * @param last last sector to erase
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int traveo2_erase(struct flash_bank *bank, int first, int last)
{
	struct target *target = bank->target;
	struct mxs40_bank_info *info = bank->driver_priv;
	int hr;

	hr = mxs40_traveo_setup(bank);
	if (hr != ERROR_OK)
		return hr;

	if (mxs40_flash_bank_matches(bank, info->regs->mem_base_sflash, NULL)) {
		mxs40_erase_sflash(bank, first, last);
		return ERROR_OK;
	}

	hr = mxs40_sromalgo_prepare(bank);
	if (hr != ERROR_OK)
		goto exit;

	progress_init(last - first + 1, ERASING);
	for (int i = first; i <= last; i++) {
		hr = mxs40_erase_row(bank, bank->base + bank->sectors[i].offset, true);
		if (hr != ERROR_OK)
			goto exit;
		progress_sofar(i - first + 1);
	}

exit:
	mxs40_sromalgo_release(target);
	progress_done(hr);
	return hr;
}

/** ***********************************************************************************************
 * @brief Performs Program operation
 * @param bank current flash bank
 * @param buffer pointer to the buffer with data
 * @param offset starting offset in falsh bank
 * @param count number of bytes in buffer
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int traveo2_program(struct flash_bank *bank, const uint8_t *buffer, uint32_t offset,
	uint32_t count)
{
	int hr = mxs40_traveo_setup(bank);
	if (hr != ERROR_OK)
		return hr;

	return mxs40_program(bank, buffer, offset, count);
}

/** *************************************************************************************
 * @brief Returns largest possible Work Flash programming page size
 ***************************************************************************************/
static uint32_t traveo2_get_wflash_page_size(struct target *target)
{
	#include "../../../../contrib/loaders/flash/psoc6/flashboot.h"

	uint32_t val;
	int hr = target_read_u32(target, FLASHBOOT_VER_HI_ADDR, &val);
	if(hr != ERROR_OK)
		goto error;

	val = val >> 28u;
	if(val < 2)
		return 4;

	hr = target_read_u32(target, FLASHBOOT_VER_LO_ADDR, &val);
	if(hr != ERROR_OK)
		goto error;

	val = val & 0xFFFFu;
	uint32_t wf_page = (val < FLASHBOOT_BUILD_BULK_SUPPORTED) ? 4 : 512;
	return wf_page;

error:
	LOG_WARNING("Failed to determine WorkFlash page saze, assuming 4 bytes");
	return 4;
}

/** ***********************************************************************************************
 * @brief Probes the device and populates related data structures with target flash geometry data.
 * This is done in non-intrusive way, no SROM API calls are involved so GDB can safely attach to a
 * running target. This is for Traveo-II devices only.
 *
 * @param bank current flash bank
 * @param geometry value in FLASHC.GEONETRY register
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int traveo2_probe(struct flash_bank *bank)
{
	struct mxs40_bank_info *info = bank->driver_priv;
	uint32_t large_sec_num = 0;
	uint32_t small_sec_num = 0;
	uint32_t large_sec_size = 0;
	uint32_t small_sec_size = 0;
	int hr;

	hr = traveo2_configure_ecc(bank->target, g_ecc_enabled);
	if (hr != ERROR_OK)
		return hr;

	if (bank->sectors) {
		free(bank->sectors);
		bank->sectors = NULL;
		bank->num_sectors = 0;
	}

	if (mxs40_flash_bank_matches(bank, info->regs->mem_base_main, NULL)) {

		if (!info->size_override) {
			LOG_ERROR("Unknown Main Flash geometry");
			return ERROR_FLASH_OPERATION_FAILED;
		}

		large_sec_num = info->size_override >> 16;
		small_sec_num = info->size_override & 0xFFFF;

		LOG_DEBUG("MainFlash geometry:"
			" %d large sectors + %d small sectors",
			large_sec_num, small_sec_num);

		large_sec_size = 32768;
		small_sec_size = 8192;
		info->page_size = 512;

	} else if (mxs40_flash_bank_matches(bank, info->regs->mem_base_work, NULL)) {

		if (!info->size_override) {
			LOG_ERROR("Unknown Work Flash geometry");
			return ERROR_FLASH_OPERATION_FAILED;
		}

		large_sec_num = info->size_override >> 16;
		small_sec_num = info->size_override & 0xFFFF;

		LOG_DEBUG("WorkFlash geometry:"
			" %d large sectors + %d small sectors",
			large_sec_num, small_sec_num);

		large_sec_size = 2048;
		small_sec_size = 128;
		info->page_size = traveo2_get_wflash_page_size(bank->target);
	} else if (mxs40_flash_bank_matches(bank, info->regs->mem_base_sflash, NULL)) {
		info->page_size = 512;
		bank->size = MEM_SFLASH_SIZE;
		bank->num_sectors = bank->size / info->page_size;

		large_sec_num = bank->num_sectors;
		large_sec_size = info->page_size;
		small_sec_num = 0;
		small_sec_size = 0;
	} else
		return ERROR_FLASH_BANK_INVALID;

	bank->size = large_sec_num * large_sec_size + small_sec_num * small_sec_size;
	bank->chip_width = 4;
	bank->bus_width = 4;
	bank->erased_value = 0xFF;
	bank->default_padded_value = 0xFF;

	bank->write_start_alignment = info->page_size;
	bank->write_end_alignment = info->page_size;
	bank->minimal_write_gap = info->page_size;

	bank->num_sectors = large_sec_num + small_sec_num;
	bank->sectors = calloc(bank->num_sectors, sizeof(struct flash_sector));
	uint32_t sec_offset = 0;
	uint32_t sec_size;
	for (size_t i = 0; i < large_sec_num + small_sec_num; i++) {
		if (i < large_sec_num)
			sec_size = large_sec_size;
		else
			sec_size = small_sec_size;

		bank->sectors[i].size = sec_size;
		bank->sectors[i].offset = sec_offset;
		bank->sectors[i].is_erased = -1;
		bank->sectors[i].is_protected = -1;
		sec_offset += sec_size;
	}

	info->is_probed = true;

	return 0;
}

FLASH_BANK_COMMAND_HANDLER(traveo2_flash_bank_command)
{
	if (CMD_ARGC < 6)
		return ERROR_COMMAND_SYNTAX_ERROR;

	static const uint8_t traveo2_program_algo[] = {
		#include "../../../../contrib/loaders/flash/psoc6/tv2_write.inc"
	};

	struct mxs40_bank_info *info = calloc(1, sizeof(struct mxs40_bank_info));
	info->is_probed = false;
	info->program_algo_p = traveo2_program_algo;
	info->program_algo_size = sizeof(traveo2_program_algo);
	info->regs = &traveo2_regs;
	info->size_override = bank->size;

	/* Bank Size has special encoding in TVII (number of large and small sectors)
	 * nullify value in bank->size to not confuse the user. Size will be populated
	 * during first probing */
	bank->size = 0;
	bank->driver_priv = info;

	return ERROR_OK;
}

FLASH_BANK_COMMAND_HANDLER(traveo2_8m_flash_bank_command)
{
	if (CMD_ARGC < 6)
		return ERROR_COMMAND_SYNTAX_ERROR;

	static const uint8_t traveo2_program_algo[] = {
		#include "../../../../contrib/loaders/flash/psoc6/tv2_write.inc"
	};

	struct mxs40_bank_info *info = calloc(1, sizeof(struct mxs40_bank_info));
	info->is_probed = false;
	info->program_algo_p = traveo2_program_algo;
	info->program_algo_size = sizeof(traveo2_program_algo);
	info->regs = &traveo2_8m_regs;
	info->size_override = bank->size;

	/* Bank Size has special encoding in TVII (number of large and small sectors)
	 * nullify value in bank->size to not confuse the user. Size will be populated
	 * during first probing */
	bank->size = 0;
	bank->driver_priv = info;

	return ERROR_OK;
}

COMMAND_HANDLER(traveo2_handle_ecc_error_reporting_command)
{
	if (CMD_ARGC != 1)
		return ERROR_COMMAND_SYNTAX_ERROR;

	COMMAND_PARSE_ON_OFF(CMD_ARGV[0], g_ecc_enabled);

	struct target *target = get_current_target(CMD_CTX);

	int hr = traveo2_configure_ecc(target, g_ecc_enabled);
	LOG_INFO("ECC error reporting is now %s", g_ecc_enabled ? "Enabled" : "Disabled");

	return hr;
}

static const struct command_registration tv2_exec_command_handlers[] = {
	{
		.name = "ecc_error_reporting",
		.handler = traveo2_handle_ecc_error_reporting_command,
		.mode = COMMAND_EXEC,
		.usage = "on|off",
		.help = "Controls ECC error reporting",
	},
	{
		.chain = mxs40_exec_command_handlers,
	},
	COMMAND_REGISTRATION_DONE
};

static const struct command_registration traveo2_command_handlers[] = {
	{
		.name = "traveo2",
		.mode = COMMAND_ANY,
		.help = "Traveo-II flash command group",
		.usage = "",
		.chain = tv2_exec_command_handlers,
	},
	COMMAND_REGISTRATION_DONE
};

struct flash_driver traveo21_flash = {
	.name = "traveo21",
	.commands = traveo2_command_handlers,
	.flash_bank_command = traveo2_flash_bank_command,
	.erase = traveo2_erase,
	.protect = mxs40_protect,
	.write = traveo2_program,
	.read = traveo2_flash_read,
	.probe = traveo2_probe,
	.auto_probe = mxs40_auto_probe,
	.erase_check = default_flash_blank_check,
	.protect_check = mxs40_protect_check,
	.info = mxs40_get_info,
	.free_driver_priv = mxs40_free_driver_priv,
};

struct flash_driver traveo22_flash = {
	.name = "traveo22",
	.commands = traveo2_command_handlers,
	.flash_bank_command = traveo2_8m_flash_bank_command,
	.erase = traveo2_erase,
	.protect = mxs40_protect,
	.write = traveo2_program,
	.read = traveo2_flash_read,
	.probe = traveo2_probe,
	.auto_probe = mxs40_auto_probe,
	.erase_check = default_flash_blank_check,
	.protect_check = mxs40_protect_check,
	.info = mxs40_get_info,
	.free_driver_priv = mxs40_free_driver_priv,
};
