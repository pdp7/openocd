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

#define KiB(x)   ((x) << 10)
#define MiB(x)   ((x) << 20)

#define MFLASH_SECTOR_SIZE             (256u * 1024u)
#define WFLASH_SECTOR_SIZE             (32u * 1024u)

#define MEM_WFLASH_SIZE                32768u
#define MEM_SFLASH_SIZE                32768u

#define MEM_SPCIF1_GEOMETRY            0x4025F00Cu
#define MEM_BASE_IPC1                  0x40230040u
#define MEM_IPC1_INTR_MASK             0x40231008u
#define MEM_VTBASE1_CM0                0x402102B0u
#define MEM_VTBASE1_CM4                0x402102C0u
#define MEM_IPC1_ACQUIRE               (MEM_BASE_IPC1 + 0x00u)
#define MEM_IPC1_RELEASE               (MEM_BASE_IPC1 + 0x04u)
#define MEM_IPC1_NOTIFY                (MEM_BASE_IPC1 + 0x08u)
#define MEM_IPC1_DATA                  (MEM_BASE_IPC1 + 0x0Cu)
#define MEM_IPC1_LOCK_STATUS           (MEM_BASE_IPC1 + 0x10u)

/* PSOC6A1M registers */
const struct mxs40_regs psoc6_ble2_regs = {
	.variant = MXS40_VARIANT_PSOC6_BLE2,
	.spcif_geometry = MEM_SPCIF1_GEOMETRY,
	.ipc_acquire = MEM_IPC1_ACQUIRE,
	.ipc_release = MEM_IPC1_RELEASE,
	.ipc_notify = MEM_IPC1_NOTIFY,
	.ipc_data = MEM_IPC1_DATA,
	.ipc_lock_stat = MEM_IPC1_LOCK_STATUS,
	.ipc_intr = MEM_IPC1_INTR_MASK,
	.vtbase = { MEM_VTBASE1_CM0, MEM_VTBASE1_CM4, 0, },
	.mem_base_main = {0x10000000, 0, },
	.mem_base_work = {0x14000000, 0, },
	.mem_base_sflash = {0x16000000, 0, },
	.mem_base_efuses = {0x90700000, 0, },
};

#define MEM_SPCIF2_GEOMETRY            0x4024F010u
#define MEM_BASE_IPC2                  0x40220040u
#define MEM_IPC2_INTR_MASK             0x40221008u
#define MEM_VTBASE2_CM0                0x40201120u
#define MEM_VTBASE2_CM4                0x40200200u
#define MEM_IPC2_ACQUIRE               (MEM_BASE_IPC2 + 0x00u)
#define MEM_IPC2_RELEASE               (MEM_BASE_IPC2 + 0x04u)
#define MEM_IPC2_NOTIFY                (MEM_BASE_IPC2 + 0x08u)
#define MEM_IPC2_DATA                  (MEM_BASE_IPC2 + 0x0Cu)
#define MEM_IPC2_LOCK_STATUS           (MEM_BASE_IPC2 + 0x1Cu)

/* PSoC6A2M registers */
const struct mxs40_regs psoc6_2m_regs = {
	.variant = MXS40_VARIANT_PSOC6A_2M,
	.spcif_geometry = MEM_SPCIF2_GEOMETRY,
	.ipc_acquire = MEM_IPC2_ACQUIRE,
	.ipc_release = MEM_IPC2_RELEASE,
	.ipc_notify = MEM_IPC2_NOTIFY,
	.ipc_data = MEM_IPC2_DATA,
	.ipc_lock_stat = MEM_IPC2_LOCK_STATUS,
	.ipc_intr = MEM_IPC2_INTR_MASK,
	.vtbase = { MEM_VTBASE2_CM0, MEM_VTBASE2_CM4, 0, },
	.mem_base_main = {0x10000000, 0,},
	.mem_base_work = {0x14000000, 0,},
	.mem_base_sflash = {0x16000000, 0,},
	.mem_base_efuses = {0x90700000, 0,},
};

/** ***********************************************************************************************
 * @brief Probes the device and populates related data structures with target flash geometry data.
 * This is done in non-intrusive way, no SROM API calls are involved so GDB can safely attach to a
 * running target. Function assumes that size of Work Flash is 32kB (true for all current part numbers)
 *
 * @param bank current flash bank
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int psoc6_probe(struct flash_bank *bank)
{
	struct mxs40_bank_info *info = bank->driver_priv;
	struct target *target = bank->target;

	int hr = ERROR_OK;

	if (bank->sectors) {
		free(bank->sectors);
		bank->sectors = NULL;
		bank->num_sectors = 0;
	}

	uint32_t row_sz = 512;
	size_t bank_size = 0;
	uint32_t idx;

	if (mxs40_flash_bank_matches(bank, info->regs->mem_base_main, &idx)) {
		if (!info->size_override)
			info->size_override = mxs40_probe_mem_area(target, info->regs->mem_base_main[idx],
													   KiB(128), KiB(1));

		if (!info->size_override) {
			LOG_ERROR("MainFlash size is unknown");
			return ERROR_FLASH_BANK_INVALID;
		}
		bank_size = info->size_override;
	} else if (mxs40_flash_bank_matches(bank, info->regs->mem_base_work,&idx))
		bank_size = MEM_WFLASH_SIZE;
	else if (mxs40_flash_bank_matches(bank, info->regs->mem_base_sflash, NULL))
		bank_size = MEM_SFLASH_SIZE;

	if (bank_size == 0) {
		LOG_ERROR("Invalid Flash Bank base address in config file");
		return ERROR_FLASH_BANK_INVALID;
	}

	size_t num_sectors = bank_size / row_sz;
	bank->size = bank_size;
	bank->num_sectors = num_sectors;

	bank->chip_width = 4;
	bank->bus_width = 4;
	bank->erased_value = 0;
	bank->default_padded_value = 0;

	bank->sectors = calloc(num_sectors, sizeof(struct flash_sector));
	for (size_t i = 0; i < num_sectors; i++) {
		bank->sectors[i].size = row_sz;
		bank->sectors[i].offset = i * row_sz;
		bank->sectors[i].is_erased = -1;
		bank->sectors[i].is_protected = -1;
	}

	bank->write_start_alignment = row_sz;
	bank->write_end_alignment = row_sz;
	bank->minimal_write_gap = row_sz;

	info->page_size = row_sz;
	info->is_probed = true;

	return hr;
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
static int psoc6_erase(struct flash_bank *bank, int first, int last)
{
	struct target *target = bank->target;
	struct mxs40_bank_info *info = bank->driver_priv;
	int hr;

	if (mxs40_flash_bank_matches(bank, info->regs->mem_base_sflash, NULL))
		return mxs40_erase_sflash(bank, first, last);

	hr = mxs40_sromalgo_prepare(bank);
	if (hr != ERROR_OK)
		goto exit;

	const uint32_t sector_size = mxs40_flash_bank_matches(bank, info->regs->mem_base_work, NULL) ?
		WFLASH_SECTOR_SIZE : MFLASH_SECTOR_SIZE;

	/* Number of rows in single sector */
	const int rows_in_sector = sector_size / info->page_size;

	progress_init(last - first + 1, ERASING);
	while (last >= first) {
		const uint32_t address = bank->base + first * info->page_size;
		/* Erase Sector if we are on sector boundary and erase size covers whole sector */
		if ((first % rows_in_sector) == 0 && (last - first + 1) >= rows_in_sector) {
			hr = mxs40_erase_row(bank, address, true);
			if (hr != ERROR_OK)
				goto exit;

			for (int i = first; i < first + rows_in_sector; i++)
				bank->sectors[i].is_erased = 1;

			first += rows_in_sector;
		} else {
			/* Perform Row Erase otherwise */
			hr = mxs40_erase_row(bank, address, false);
			if (hr != ERROR_OK)
				goto exit;

			bank->sectors[first].is_erased = 1;
			first += 1;
		}
		progress_left(last - first + 1);
	}

exit:
	mxs40_sromalgo_release(target);
	progress_done(hr);
	return hr;
}

FLASH_BANK_COMMAND_HANDLER(psoc6_ble2_flash_bank_command)
{
	if (CMD_ARGC < 6)
		return ERROR_COMMAND_SYNTAX_ERROR;

	static const uint8_t p6_program_algo[] = {
		#include "../../../../contrib/loaders/flash/psoc6/psoc6_write.inc"
	};

	struct mxs40_bank_info *info = calloc(1, sizeof(struct mxs40_bank_info));
	info->is_probed = false;
	info->program_algo_p = p6_program_algo;
	info->program_algo_size = sizeof(p6_program_algo);
	info->regs = &psoc6_ble2_regs;
	info->size_override = bank->size;
	bank->driver_priv = info;

	return ERROR_OK;
}

FLASH_BANK_COMMAND_HANDLER(psoc6_2m_flash_bank_command)
{
	if (CMD_ARGC < 6)
		return ERROR_COMMAND_SYNTAX_ERROR;

	static const uint8_t p6_2m_program_algo[] = {
		#include "../../../../contrib/loaders/flash/psoc6/psoc62m_write.inc"
	};

	struct mxs40_bank_info *info = calloc(1, sizeof(struct mxs40_bank_info));
	info->is_probed = false;
	info->program_algo_p = p6_2m_program_algo;
	info->program_algo_size = sizeof(p6_2m_program_algo);
	info->regs = &psoc6_2m_regs;
	info->size_override = bank->size;
	bank->driver_priv = info;

	return ERROR_OK;
}

COMMAND_HANDLER(psoc6_handle_secure_acquire)
{
	int hr;
	struct timeout to;
	struct target *target = get_current_target(CMD_CTX);
	struct cortex_m_common *cm = target_to_cm(target);
	uint32_t ap = cm->common_magic == CORTEX_M_COMMON_MAGIC ? cm->apsel : 0;
	bool acquire_mode_halt;

	if(CMD_ARGC != 3)
		return ERROR_COMMAND_SYNTAX_ERROR;

	uint32_t ipc_data_addr;
	if(strcmp(CMD_ARGV[0], "psoc6") == 0) {
		ipc_data_addr = MEM_IPC1_DATA;
	} else if(strcmp(CMD_ARGV[0], "psoc6_2m") == 0) {
		ipc_data_addr = MEM_IPC2_DATA;
	} else {
		LOG_ERROR("Invalid target for secure_acquire: '%s'. "
				  "Only 'psoc6' and 'psoc6_2m' are currently supported.", CMD_ARGV[0]);
		return ERROR_COMMAND_SYNTAX_ERROR;
	}

	if(strcmp(CMD_ARGV[1], "run") == 0) {
		acquire_mode_halt = false;
	} else if(strcmp(CMD_ARGV[1], "halt") == 0) {
		acquire_mode_halt = true;
	} else {
		LOG_ERROR("Invalid mode for secure_acquire: '%s'. "
				  "Only 'run' and 'halt' are currently supported.", CMD_ARGV[1]);
		return ERROR_COMMAND_SYNTAX_ERROR;
	}

	uint32_t timeout;
	COMMAND_PARSE_NUMBER(u32, CMD_ARGV[2], timeout);

	LOG_INFO("Waiting up to %d.%d sec for the bootloader to open AP #%d...",
			 timeout / 1000u, timeout % 1000u, ap);

	enum log_levels old_level = change_debug_level(LOG_LVL_USER);
	mxs40_timeout_init(&to, timeout);

	const char *error_msg = "";

	/* Wait for boot code to open corresponding AP */
	while(!mxs40_timeout_expired(&to)) {
		keep_alive();

		error_msg = "Failed to access debug sybsystem";
		target->examined = false;
		if(target_examine_one(target) == ERROR_OK)
			break;
	};

	/* Set TEST_MODE bit (only if we are going to halt) */
	while(acquire_mode_halt && !mxs40_timeout_expired(&to)) {
		keep_alive();

		error_msg = "failed to write IPC[2].DATA register";
		if(target_write_u32(target, ipc_data_addr, 0) != ERROR_OK)
			continue;

		error_msg = "failed to write SRSS.TST_MODE register";
		if(target_write_u32(target, 0x40260100, 0x80000000) != ERROR_OK)
			continue;

		error_msg = "";
		break;
	};
	change_debug_level(old_level);

	if(mxs40_timeout_expired(&to)) {
		LOG_ERROR("AP #%d is still not opened: %s, giving up", ap, error_msg);
		return ERROR_TARGET_FAILURE;
	}

	/* Wait for handshake (only if we are going to halt) */
	if(acquire_mode_halt) {
		LOG_INFO("Waiting up to %d.%d sec for the handshake from the target...",
				 timeout / 1000u, timeout % 1000u);

		mxs40_timeout_init(&to, timeout);
		while(!mxs40_timeout_expired(&to)) {
			keep_alive();

			uint32_t ipc_data;
			if(target_read_u32(target, ipc_data_addr, &ipc_data) != ERROR_OK)
				continue;

			if(ipc_data == 0x12344321)
				break;
		};

		if(mxs40_timeout_expired(&to))
			LOG_WARNING("No handshake from the target, continuing anyway");
	}

	target->examined = false;
	hr = target_examine_one(target);
	if(hr != ERROR_OK)
		return hr;

	hr = target_poll(target);
	if(hr != ERROR_OK)
		return hr;

	hr = target_poll(target);
	if(hr != ERROR_OK)
		return hr;

	/* Halt the target, if requested */
	if(acquire_mode_halt) {
		hr = target_halt(target);
		if(hr != ERROR_OK)
			return hr;

		hr = target_wait_state(target, TARGET_HALTED, 1000);
		if(hr != ERROR_OK)
			return hr;
	}

	return ERROR_OK;
}

static const struct command_registration psoc6_exec_command_handlers[] = {
	{
		.name = "secure_acquire",
		.handler = psoc6_handle_secure_acquire,
		.mode = COMMAND_EXEC,
		.usage = "<psoc6|psoc6_2m> <run|halt> <timeout>",
		.help = "",
	},
	{
		.chain = mxs40_exec_command_handlers,
	},
	COMMAND_REGISTRATION_DONE
};

static const struct command_registration psoc6_command_handlers[] = {
	{
		.name = "psoc6",
		.mode = COMMAND_ANY,
		.help = "PSoC 6 flash command group",
		.usage = "",
		.chain = psoc6_exec_command_handlers,
	},
	COMMAND_REGISTRATION_DONE
};

/* Flash driver for PSoC6 BLE2 */
struct flash_driver psoc6_flash = {
	.name = "psoc6",
	.commands = psoc6_command_handlers,
	.flash_bank_command = psoc6_ble2_flash_bank_command,
	.erase = psoc6_erase,
	.protect = mxs40_protect,
	.write = mxs40_program,
	.read = default_flash_read,
	.probe = psoc6_probe,
	.auto_probe = mxs40_auto_probe,
	.erase_check = default_flash_blank_check,
	.protect_check = mxs40_protect_check,
	.info = mxs40_get_info,
	.free_driver_priv = mxs40_free_driver_priv,
};

/* Flash driver for PSoC6 BLE2 */
struct flash_driver psoc6_2m_flash = {
	.name = "psoc6_2m",
	.commands = psoc6_command_handlers,
	.flash_bank_command = psoc6_2m_flash_bank_command,
	.erase = psoc6_erase,
	.protect = mxs40_protect,
	.write = mxs40_program,
	.read = default_flash_read,
	.probe = psoc6_probe,
	.auto_probe = mxs40_auto_probe,
	.erase_check = default_flash_blank_check,
	.protect_check = mxs40_protect_check,
	.info = mxs40_get_info,
	.free_driver_priv = mxs40_free_driver_priv,
};
