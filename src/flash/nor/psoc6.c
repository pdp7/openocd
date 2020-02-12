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

#if(0)

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <time.h>

#include "imp.h"
#include "target/target.h"
#include "target/cortex_m.h"
#include "target/breakpoints.h"
#include "target/target_type.h"
#include "time_support.h"
#include "target/algorithm.h"
#include "target/image.h"
#include "flash/progress.h"

/**************************************************************************************************
 * PSoC6 device definitions
 *************************************************************************************************/
#define MFLASH_SECTOR_SIZE             (256u * 1024u)
#define WFLASH_SECTOR_SIZE             (32u * 1024u)

#define MEM_BASE_MFLASH                0x10000000u
#define MEM_BASE_WFLASH                0x14000000u
#define MEM_WFLASH_SIZE                32768u
#define MEM_SFLASH_SIZE                32768u
#define MEM_BASE_SFLASH_P6             0x16000000u
#define MEM_BASE_SFLASH_TV2            0x17000000u

#define RAM_STACK_WA_SIZE              2048u

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

#define MEM_SPCIF2_GEOMETRY            0x4024F010u
#define MEM_SPCIF3_GEOMETRY            0x4024F00Cu
#define MEM_BASE_IPC2                  0x40220060u
#define MEM_IPC2_INTR_MASK             0x40221008u
#define MEM_VTBASE2_CM0                0x40201120u
#define MEM_VTBASE2_CM4                0x40200200u
#define MEM_IPC2_ACQUIRE               (MEM_BASE_IPC2 + 0x00u)
#define MEM_IPC2_RELEASE               (MEM_BASE_IPC2 + 0x04u)
#define MEM_IPC2_NOTIFY                (MEM_BASE_IPC2 + 0x08u)
#define MEM_IPC2_DATA                  (MEM_BASE_IPC2 + 0x0Cu)
#define MEM_IPC2_LOCK_STATUS           (MEM_BASE_IPC2 + 0x1Cu)

#define IPC_ACQUIRE_SUCCESS_MSK        0x80000000u
#define IPC_LOCK_ACQUIRED_MSK          0x80000000u

#define SROMAPI_SIID_REQ                    0x00000001u
#define SROMAPI_SIID_REQ_FAMILY_REVISION    (SROMAPI_SIID_REQ | 0x000u)
#define SROMAPI_SIID_REQ_SIID_PROTECTION    (SROMAPI_SIID_REQ | 0x100u)
#define SROMAPI_WRITEROW_REQ                0x05000100u
#define SROMAPI_PROGRAMROW_REQ              0x06000100u
#define SROMAPI_ERASESECTOR_REQ             0x14000100u
#define SROMAPI_ERASEALL_REQ                0x0A000100u
#define SROMAPI_ERASEROW_REQ                0x1C000100u

#define SROMAPI_READ_FUSE_BYTE              0x03000001u
#define SROMAPI_CHECK_FACTORY_HASH          0x27000001u
#define SROMAPI_GENERATE_HASH_CODE          0x1E000000u

#define SROMAPI_STATUS_MSK                  0xF0000000u
#define SROMAPI_STAT_SUCCESS                0xA0000000u
#define SROMAPI_DATA_LOCATION_MSK           0x00000001u
#define IPC_TIMEOUT_MS                      1500

#define MXS40_VARIANT_PSOC6A1M              1
#define MXS40_VARIANT_PSOC6A2M              2
#define MXS40_VARIANT_TRAVEO_II             3

#define MXS40_EFUSE_IGNORE                           0xFF
#define MXS40_EFUSE_NOT_BLOWN                        0x00
#define MXS40_EFUSE_BLOWN                            0x01

#define MXS40_EFUSE_FLASH_BOOT_HASH_SIZE             16u
#define MXS40_EFUSE_FLASH_BOOT_HASH_RESPONSE_SIZE    24u
#define MXS40_EFUSE_FLASH_BOOT_HASH_ZEROS_OFSET      0x14u

#define MXS40_EFUSE_FLASH_BOOT_HASH_OFFSET           0x14
#define MXS40_EFUSE_FLASH_BOOT_HASH_ZEROS_OFFSET     0x26
#define MXS40_EFUSE_LIFECYCLE_STAGE_OFFSET           0x2B

#define MXS40_EFUSE_LIFE_CYCLE_NORMAL_BIT_ADDR       0
#define MXS40_EFUSE_LIFE_CYCLE_SECURE_DEBUG_BIT_ADDR 1
#define MXS40_EFUSE_LIFE_CYCLE_SECURE_BIT_ADDR       2
#define MXS40_EFUSE_LIFE_CYCLE_RMA_BIT_ADDR          3


#define MXS40_LIFE_CYCLE_NORMAL          (1 << MXS40_EFUSE_LIFE_CYCLE_NORMAL_BIT_ADDR)
#define MXS40_LIFE_CYCLE_SECURE_DEBUG    (1 << MXS40_EFUSE_LIFE_CYCLE_SECURE_DEBUG_BIT_ADDR)
#define MXS40_LIFE_CYCLE_SECURE          (1 << MXS40_EFUSE_LIFE_CYCLE_SECURE_BIT_ADDR)
#define MXS40_LIFE_CYCLE_RMA             (1 << MXS40_EFUSE_LIFE_CYCLE_RMA_BIT_ADDR)

#define SROMAPI_BLOW_FUSE_MACROPERADDR               32

#define SROMAPI_BLOW_FUSE_CODE_ROL                   24
#define SROMAPI_BLOW_FUSE_CODE                       1
#define SROMAPI_BLOW_FUSE_ADDR_ROL                   16
#define SROMAPI_BLOW_FUSE_ADDR_MASK                  0x00FF0000
#define SROMAPI_BLOW_FUSE_MACRO_ROL                  12
#define SROMAPI_BLOW_FUSE_MACRO_MASK                 0x0000F000
#define SROMAPI_BLOW_FUSE_BIT_ROL                    8
#define SROMAPI_BLOW_FUSE_BIT_MASK                   0x00000700

#define MXS40_CHIP_PROT_UNKNOWN                      0x00u
#define MXS40_CHIP_PROT_VIRGIN                       0x01u
#define MXS40_CHIP_PROT_NORMAL                       0x02u
#define MXS40_CHIP_PROT_SECURE                       0x03u
#define MXS40_CHIP_PROT_DEAD                         0x04u
#define MXS40_CHIP_PROT_MASK                         0x0Fu

#define BYTE_BITS                                    8
#define NVIC_VTOR                                    0xE000ED08

static const uint8_t p6_program_algo[] = {
#include "../../../contrib/loaders/flash/psoc6/psoc6_write.inc"
};

static const uint8_t p62m_program_algo[] = {
#include "../../../contrib/loaders/flash/psoc6/psoc62m_write.inc"
};

static const uint8_t tv2_program_algo[] = {
#include "../../../contrib/loaders/flash/psoc6/tv2_write.inc"
};

enum reset_halt_mode {
	mode_default,
	mode_sysresetreq,
	mode_vectreset
};

struct mxs40_bank_info {
	uint32_t page_size;
	bool is_probed;
	const struct psoc6_regs *regs;
};

struct timeout {
	int64_t start_time;
	long timeout_ms;
};

struct row_region {
	char *target_name;
	target_addr_t addr;
	uint32_t size;
};

struct psoc6_regs {
	uint32_t variant;
	uint32_t spcif_geometry;
	uint32_t ipc_acquire;
	uint32_t ipc_release;
	uint32_t ipc_notify;
	uint32_t ipc_data;
	uint32_t ipc_lock_stat;
	uint32_t ipc_intr;
	uint32_t vtbase_cm0;
	uint32_t vtbase_cm4;
	uint32_t mem_base_main[4];
	uint32_t mem_base_work[4];
	uint32_t mem_base_sflash[4];
	uint32_t mem_base_efuses[4];
};

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

/* PSOC6A1M registers */
static const struct psoc6_regs psoc6_regs = {
	.variant = MXS40_VARIANT_PSOC6A1M,
	.spcif_geometry = MEM_SPCIF1_GEOMETRY,
	.ipc_acquire = MEM_IPC1_ACQUIRE,
	.ipc_release = MEM_IPC1_RELEASE,
	.ipc_notify = MEM_IPC1_NOTIFY,
	.ipc_data = MEM_IPC1_DATA,
	.ipc_lock_stat = MEM_IPC1_LOCK_STATUS,
	.ipc_intr = MEM_IPC1_INTR_MASK,
	.vtbase_cm0 = MEM_VTBASE1_CM0,
	.vtbase_cm4 = MEM_VTBASE1_CM4,
	.mem_base_main = {0x10000000, 0, },
	.mem_base_work = {0x14000000, 0, },
	.mem_base_sflash = {0x16000000, 0, },
	.mem_base_efuses = {0x90700000, 0, },
};

/* PSoC6A2M registers */
static const struct psoc6_regs psoc62m_regs = {
	.variant = MXS40_VARIANT_PSOC6A2M,
	.spcif_geometry = MEM_SPCIF2_GEOMETRY,
	.ipc_acquire = MEM_IPC2_ACQUIRE,
	.ipc_release = MEM_IPC2_RELEASE,
	.ipc_notify = MEM_IPC2_NOTIFY,
	.ipc_data = MEM_IPC2_DATA,
	.ipc_lock_stat = MEM_IPC2_LOCK_STATUS,
	.ipc_intr = MEM_IPC2_INTR_MASK,
	.vtbase_cm0 = MEM_VTBASE2_CM0,
	.vtbase_cm4 = MEM_VTBASE2_CM4,
	.mem_base_main = {0x10000000, 0,},
	.mem_base_work = {0x14000000, 0,},
	.mem_base_sflash = {0x16000000, 0,},
	.mem_base_efuses = {0x90700000, 0,},
};

/* Traveo-II registers */
static const struct psoc6_regs traveo2_regs = {
	.variant = MXS40_VARIANT_TRAVEO_II,
	.spcif_geometry = MEM_SPCIF3_GEOMETRY,
	.ipc_acquire = MEM_IPC2_ACQUIRE,
	.ipc_release = MEM_IPC2_RELEASE,
	.ipc_notify = MEM_IPC2_NOTIFY,
	.ipc_data = MEM_IPC2_DATA,
	.ipc_lock_stat = MEM_IPC2_LOCK_STATUS,
	.ipc_intr = MEM_IPC2_INTR_MASK,
	.vtbase_cm0 = MEM_VTBASE2_CM0,
	.vtbase_cm4 = MEM_VTBASE2_CM4,
	.mem_base_main = {0x10000000, 0,},
	.mem_base_work = {0x14000000, 0,},
	.mem_base_sflash = {0x17000000, 0,},
	.mem_base_efuses = {0, 0,},
};

static struct working_area *g_stack_area;
static struct armv7m_algorithm g_armv7m_info;
static bool g_allow_unsafe_sflash_writes;
static bool g_allow_efuse_programming;
static bool g_ecc_enabled;
static bool g_sflash_skipped_silent;

/* Safe SFLASH regions */
static size_t g_num_sflash_regions;
static struct row_region *g_sflash_regions;

/** ***********************************************************************************************
 * @brief Initializes `struct timeout` structure with given timeout value
 * @param to pointer to `struct timeout` structure
 * @param timeout_ms timeout, in milliseconds
 *************************************************************************************************/
static void timeout_init(struct timeout *to, long timeout_ms)
{
	to->start_time = timeval_ms();
	to->timeout_ms = timeout_ms;
}

/** ***********************************************************************************************
 * @brief Returns true if given timeout has expired
 * @param to pointer to `struct timeout` structure
 * @return true if timeout expired
 *************************************************************************************************/
static bool timeout_expired(struct timeout *to)
{
	return (timeval_ms() - to->start_time) > to->timeout_ms;
}

/** ***********************************************************************************************
 * @brief Starts pseudo flash algorithm and leaves it running. Function allocates working area for
 * algorithm code and CPU stack, adjusts stack pointer, uploads and starts the algorithm.
 * Algorithm (a basic infinite loop) runs asynchronously while driver performs Flash operations.
 *
 * @param bank current flash bank
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int sromalgo_prepare(struct flash_bank *bank)
{
	struct target *target = bank->target;
	struct mxs40_bank_info *info = bank->driver_priv;

	if (target->state != TARGET_HALTED) {
		LOG_WARNING("Target not halted");
		return ERROR_TARGET_NOT_HALTED;
	}

	/* Initialize Vector Table Offset register (in case FW modified it) */
	int hr = target_write_u32(target, NVIC_VTOR, 0x00000000);
	if (hr != ERROR_OK)
		return hr;

	/* Restore THUMB bit in xPSR register */
	const struct armv7m_common *cm = target_to_armv7m(target);
	hr = cm->store_core_reg_u32(target, ARMV7M_xPSR, 0x01000000);
	if (hr != ERROR_OK)
		return hr;

	/* Allocate Working Area for Stack and Flash algorithm */
	hr = target_alloc_working_area(target, RAM_STACK_WA_SIZE, &g_stack_area);
	if (hr != ERROR_OK)
		return hr;

	g_armv7m_info.common_magic = ARMV7M_COMMON_MAGIC;
	g_armv7m_info.core_mode = ARM_MODE_THREAD;

	struct reg_param reg_params;
	init_reg_param(&reg_params, "sp", 32, PARAM_OUT);
	buf_set_u32(reg_params.value, 0, 32, g_stack_area->address + g_stack_area->size);

	/* Write 'cpsie	i' + basic infinite loop algorithm to target RAM */
	hr = target_write_u32(target, g_stack_area->address, 0xE7FEB662);
	if (hr != ERROR_OK)
		goto destroy_rp_free_wa;

	hr = target_start_algorithm(target, 0, NULL, 1, &reg_params, g_stack_area->address,
			0, &g_armv7m_info);
	if (hr != ERROR_OK)
		goto destroy_rp_free_wa;

	if (info->regs->variant == MXS40_VARIANT_TRAVEO_II) {
		hr = target_write_u32(bank->target, 0x4024F400, 0x01);
		if (hr != ERROR_OK)
			goto destroy_rp_free_wa;

		hr = target_write_u32(bank->target, 0x4024F500, 0x01);
		if (hr != ERROR_OK)
			goto destroy_rp_free_wa;
	}

	destroy_reg_param(&reg_params);
	return hr;

destroy_rp_free_wa:
	/* Something went wrong, do some cleanup */
	destroy_reg_param(&reg_params);

	if (g_stack_area) {
		target_free_working_area(target, g_stack_area);
		g_stack_area = NULL;
	}

	return hr;
}

/** ***********************************************************************************************
 * @brief Stops running flash algorithm and releases associated resources.
 * This function is also used for cleanup in case of errors so g_stack_area may be NULL.
 * These cases have to be handled gracefully.
 *
 * @param bank current flash bank
 *************************************************************************************************/
static void sromalgo_release(struct target *target)
{
	int hr = ERROR_OK;

	if (g_stack_area) {
		/* Stop flash algorithm if it is running */
		if (target->running_alg) {
			hr = target_halt(target);
			if (hr != ERROR_OK)
				goto exit_free_wa;

			hr = target_wait_algorithm(target, 0, NULL, 0, NULL, 0,
					IPC_TIMEOUT_MS, &g_armv7m_info);
			if (hr != ERROR_OK)
				goto exit_free_wa;
		}

exit_free_wa:
		/* Free Stack/Flash algorithm working area */
		target_free_working_area(target, g_stack_area);
		g_stack_area = NULL;
	}
}

/** ***********************************************************************************************
 * @brief Waits for expected IPC lock status. PSoC6 uses IPC structures for inter-core
 * communication. Same IPCs are used to invoke SROM API. IPC structure must be locked prior to
 * invoking any SROM API. This ensures nothing else in the system will use same IPC thus corrupting
 * our data. Locking is performed by ipc_acquire(), this function ensures that IPC is actually
 * in expected state
 *
 * @param bank current flash bank
 * @param lock_expected expected lock status
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int ipc_poll_lock_stat(struct flash_bank *bank, bool lock_expected)
{
	uint32_t reg_val;
	struct timeout to;
	struct target *target = bank->target;
	struct mxs40_bank_info *info = bank->driver_priv;
	timeout_init(&to, IPC_TIMEOUT_MS);

	while (!timeout_expired(&to)) {
		/* Process any server requests */
		keep_alive();

		/* Read IPC Lock status */
		int hr = target_read_u32(target, info->regs->ipc_lock_stat, &reg_val);
		if (hr != ERROR_OK) {
			LOG_ERROR("Unable to read IPC Lock Status register");
			return hr;
		}

		bool is_locked = (reg_val & IPC_LOCK_ACQUIRED_MSK) != 0;

		if (lock_expected == is_locked)
			return ERROR_OK;
	}

	if (target->coreid) {
		LOG_WARNING("SROM API calls via CM4 target are supported on single-core PSoC6 devices only. "
			"Please perform all Flash-related operations via CM0+ target on dual-core devices.");
	}

	LOG_ERROR("Timeout polling IPC Lock Status");
	return ERROR_TARGET_TIMEOUT;
}

/** ***********************************************************************************************
 * @brief Acquires IPC structure. PSoC6 uses IPC structures for inter-core communication.
 * Same IPCs are used to invoke SROM API. IPC structure must be locked prior to invoking any SROM API.
 * This ensures nothing else in the system will use same IPC thus corrupting our data.
 * This function locks the IPC.
 *
 * @param bank current flash bank
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int ipc_acquire(struct flash_bank *bank)
{
	int hr = ERROR_OK;
	bool is_acquired = false;
	uint32_t reg_val = 0;
	struct timeout to;
	struct target *target = bank->target;
	struct mxs40_bank_info *info = bank->driver_priv;

	timeout_init(&to, IPC_TIMEOUT_MS);

	while (!timeout_expired(&to)) {
		keep_alive();

		hr = target_write_u32(target,
				info->regs->ipc_acquire,
				IPC_ACQUIRE_SUCCESS_MSK);
		if (hr != ERROR_OK) {
			LOG_ERROR("Unable to write to IPC Acquire register");
			return hr;
		}

		/* Check if data is written on first step */
		hr = target_read_u32(target, info->regs->ipc_acquire, &reg_val);
		if (hr != ERROR_OK) {
			LOG_ERROR("Unable to read IPC Acquire register");
			return hr;
		}

		is_acquired = (reg_val & IPC_ACQUIRE_SUCCESS_MSK) != 0;
		if (is_acquired) {
			/* If IPC structure is acquired, the lock status should be set */
			hr = ipc_poll_lock_stat(bank, true);
			break;
		}
	}

	if (!is_acquired)
		LOG_ERROR("Timeout acquiring IPC structure");

	return hr;
}

/** ***********************************************************************************************
 * @brief Invokes SROM API functions which are responsible for Flash operations
 *
 * @param bank current flash bank
 * @param req_and_params requect id of the function to invoke
 * @param working_area address of memory buffer in target's memory space for SROM API parameters
 * @param data_out pointer to variable which will be populated with execution status
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int mxs40_call_sromapi(struct flash_bank *bank,
	uint32_t req_and_params,
	uint32_t working_area,
	uint32_t *data_out)
{
	int hr;
	struct target *target = bank->target;
	struct mxs40_bank_info *info = bank->driver_priv;
	bool is_data_in_ram = (req_and_params & SROMAPI_DATA_LOCATION_MSK) == 0;

	hr = ipc_acquire(bank);
	if (hr != ERROR_OK)
		return hr;

	if (is_data_in_ram)
		hr = target_write_u32(target, info->regs->ipc_data, working_area);
	else
		hr = target_write_u32(target, info->regs->ipc_data, req_and_params);

	if (hr != ERROR_OK)
		return hr;

	/* Enable notification interrupt of IPC_INTR_STRUCT0(CM0+) for IPC_STRUCT2 */
	hr = target_write_u32(target, info->regs->ipc_intr, 0x0Fu << 16);
	if (hr != ERROR_OK)
		return hr;

	hr = target_write_u32(target, info->regs->ipc_notify, 1);
	if (hr != ERROR_OK)
		return hr;

	/* Poll lock status */
	hr = ipc_poll_lock_stat(bank, false);
	if (hr != ERROR_OK)
		return hr;

	/* Poll Data byte */
	if (is_data_in_ram)
		hr = target_read_u32(target, working_area, data_out);
	else
		hr = target_read_u32(target, info->regs->ipc_data, data_out);

	if (hr != ERROR_OK) {
		LOG_ERROR("Error reading SROM API Status location");
		return hr;
	}

	bool is_success = (*data_out & SROMAPI_STATUS_MSK) == SROMAPI_STAT_SUCCESS;
	if (!is_success) {
		LOG_ERROR("SROM API execution failed. Status: 0x%08X", (uint32_t)*data_out);
		return ERROR_TARGET_FAILURE;
	}

	return ERROR_OK;
}

/** ***********************************************************************************************
 * @brief Retrieves SiliconID and Protection status of the target device
 * @param bank current flash bank
 * @param si_id pointer to variable, will be populated with SiliconID
 * @param protection pointer to variable, will be populated with protection status
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int mxs40_get_silicon_id(struct flash_bank *bank, uint32_t *si_id, uint8_t *protection)
{
	int hr;
	uint32_t family_rev, siid_prot;
	struct target *target = bank->target;

	hr = sromalgo_prepare(bank);
	if (hr != ERROR_OK)
		goto exit;

	/* Read FamilyID and Revision */
	hr = mxs40_call_sromapi(bank, SROMAPI_SIID_REQ_FAMILY_REVISION, 0, &family_rev);
	if (hr != ERROR_OK)
		goto exit;

	/* Read SiliconID and Protection */
	hr = mxs40_call_sromapi(bank, SROMAPI_SIID_REQ_SIID_PROTECTION, 0, &siid_prot);
	if (hr != ERROR_OK)
		goto exit;

	*si_id  = (siid_prot & 0x0000FFFF) << 16;
	*si_id |= (family_rev & 0x00FF0000) >> 8;
	*si_id |= (family_rev & 0x000000FF) >> 0;

	*protection = (siid_prot & 0x000F0000) >> 0x10;

exit:
	sromalgo_release(target);
	return hr;
}

/** ***********************************************************************************************
 * @brief Translates Protection status to openocd-friendly boolean value
 * @param bank current flash bank
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int mxs40_protect_check(struct flash_bank *bank)
{
	int is_protected;
	uint32_t silicon_id;
	uint8_t protection;

	int hr = mxs40_get_silicon_id(bank, &silicon_id, &protection);
	if (hr != ERROR_OK)
		return hr;

	switch (protection) {
		case MXS40_CHIP_PROT_VIRGIN:
		case MXS40_CHIP_PROT_NORMAL:
			is_protected = 0;
			break;

		case MXS40_CHIP_PROT_UNKNOWN:
		case MXS40_CHIP_PROT_SECURE:
		case MXS40_CHIP_PROT_DEAD:
		default:
			is_protected = 1;
			break;
	}

	for (int i = 0; i < bank->num_sectors; i++)
		bank->sectors[i].is_protected = is_protected;

	return ERROR_OK;
}

/** ***********************************************************************************************
 * @brief Translates Protection status to string
 * @param protection protection value
 * @return pointer to const string describintg protection status
 *************************************************************************************************/
static const char *protection_to_str(uint8_t protection)
{
	static const char *prot_states[] = {"UNKNOWN", "VIRGIN", "NORMAL", "SECURE", "DEAD"};
	if (protection > 4)
		protection = 0;
	return prot_states[protection];
}

/** ***********************************************************************************************
 * @brief psoc6_get_info Displays human-readable information about acquired device
 * @param bank current flash bank
 * @param buf pointer to buffer for human-readable text
 * @param buf_size size of the buffer
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int psoc6_get_info(struct flash_bank *bank, char *buf, int buf_size)
{
	struct mxs40_bank_info *info = bank->driver_priv;

	if (info->is_probed == false)
		return ERROR_FAIL;

	uint32_t silicon_id;
	uint8_t protection;

	int hr = mxs40_get_silicon_id(bank, &silicon_id, &protection);
	if (hr != ERROR_OK)
		return hr;

	snprintf(buf, buf_size,
		"PSoC6 Silicon ID: 0x%08X\n"
		"Protection: %s\n",
		silicon_id,
		protection_to_str(protection));

	return ERROR_OK;
}

/** ***********************************************************************************************
 * @brief Checks if given flash row belongs to Safe Supervisory Flash region
 * @param bank current flash bank
 * @param addr row start address to check
 * @return true if flash bank belongs to Safe Supervisory Flash region
 *************************************************************************************************/
static bool is_safe_sflash_page(struct flash_bank *bank, uint32_t addr)
{
	assert(addr % 512 == 0);

	if (g_allow_unsafe_sflash_writes)
		return true;

	for (size_t i = 0; i < g_num_sflash_regions; i++) {
		if (strcmp(bank->target->cmd_name, g_sflash_regions[i].target_name) != 0)
			continue;

		uint32_t region_start = g_sflash_regions[i].addr;
		uint32_t region_size = g_sflash_regions[i].size;

		if (addr >= region_start && addr < region_start + region_size)
			return true;
	}

	return false;
}

/** ***********************************************************************************************
 * @brief Checks if given flash bank base address is one in the addr_array array
 * @param bank current flash bank
 * @param addr_array array with base addresses
 * @return true if flash bank matches
 *************************************************************************************************/
static bool flash_bank_matches(struct flash_bank *bank, const uint32_t *addr_array)
{
	while (*addr_array) {
		if (bank->base == *addr_array)
			return true;
		addr_array++;
	}

	return false;
}

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

#if (0)
static int add_sectors(struct flash_bank *bank, uint32_t size, uint32_t count, uint8_t empty_val)
{
	const int ns = bank->num_sectors;
	uint32_t sec_offset = ns ? bank->sectors[ns - 1].offset + bank->sectors[ns - 1].size : 0;

	struct flash_sector *new_sectors;
	new_sectors = realloc(bank->sectors, (ns + count) * sizeof(struct flash_sector));
	if (new_sectors == NULL)
		return ERROR_FAIL;

	for (uint32_t i = 0; i < count; i++) {
		new_sectors[i + ns].size = size;
		new_sectors[i + ns].offset = sec_offset;
		new_sectors[i + ns].is_erased = -1;
		new_sectors[i + ns].is_protected = -1;
		sec_offset += size;
	}

	bank->sectors = new_sectors;
	bank->num_sectors = ns + count;
	bank->erased_value = bank->default_padded_value = empty_val;

	bank->size = 0;
	for (int i = 0; i < bank->num_sectors; i++)
		bank->size += bank->sectors[i].size;

	return ERROR_OK;
}
#endif

/** ***********************************************************************************************
 * @brief Probes the device and populates related data structures with target flash geometry data.
 * This is done in non-intrusive way, no SROM API calls are involved so GDB can safely attach to a
 * running target. This is for Traveo-II devices only.
 *
 * @param bank current flash bank
 * @param geometry value in FLASHC.GEONETRY register
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int traveo2_probe(struct flash_bank *bank, uint32_t geometry)
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

	if (flash_bank_matches(bank, info->regs->mem_base_main)) {
		const uint32_t main_large_sec_num_tbl[8] = {14, 30, 62, 126, 190, 254, 0, 0};
		const uint32_t main_small_sec_num_tbl[8] = {16, 16, 16, 16, 32, 32, 0, 0};
		large_sec_num = main_large_sec_num_tbl[geometry & 0x07];
		small_sec_num = main_small_sec_num_tbl[geometry & 0x07];

		if (bank->size == 0x100000) {
			LOG_INFO("Using TVII-8M PSVP MainFlash layout");
			large_sec_num = 30;
			small_sec_num = 8;
		}

		large_sec_size = 32768;
		small_sec_size = 8192;
		info->page_size = 512;
	} else if (flash_bank_matches(bank, info->regs->mem_base_work)) {
		const uint32_t work_large_sec_num_tbl[8] = {0, 24,  36, 48, 96, 192, 0, 0};
		const uint32_t work_small_sec_num_tbl[8] = {0, 128, 192, 256, 512, 1024, 0, 0};
		large_sec_num = work_large_sec_num_tbl[(geometry >> 3) & 0x07];
		small_sec_num = work_small_sec_num_tbl[(geometry >> 3) & 0x07];
		large_sec_size = 2048;
		small_sec_size = 128;
		info->page_size = 4;
	} else if (flash_bank_matches(bank, info->regs->mem_base_sflash)) {
		info->page_size = 512;
		bank->size = MEM_SFLASH_SIZE;
		bank->num_sectors = bank->size / info->page_size;
		bank->sectors = calloc(bank->num_sectors,
				sizeof(struct flash_sector));

		bank->chip_width = 4;
		bank->bus_width = 4;
		bank->erased_value = 0x00;
		bank->default_padded_value = 0x00;

		for (int j = 0; j < bank->num_sectors; j++) {
			bank->sectors[j].size = 512;
			bank->sectors[j].offset = 512 * j;
			bank->sectors[j].is_erased = -1;
			bank->sectors[j].is_protected = -1;
		}

		bank->write_start_alignment = info->page_size;
		bank->write_end_alignment = info->page_size;
		bank->minimal_write_gap = info->page_size;

		info->is_probed = true;
		return ERROR_OK;
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

/** ***********************************************************************************************
 * @brief Probes the device and populates related data structures with target flash geometry data.
 * This is done in non-intrusive way, no SROM API calls are involved so GDB can safely attach to a
 * running target. Function assumes that size of Work Flash is 32kB (true for all current part numbers)
 *
 * @param bank current flash bank
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_probe(struct flash_bank *bank)
{
	assert(bank->size != 0);

	struct mxs40_bank_info *info = bank->driver_priv;

	bank->chip_width = 1;
	bank->bus_width = 1;
	bank->erased_value = 0;
	bank->default_padded_value = 0xFF;

	bank->num_sectors = 1;
	bank->sectors = calloc(1, sizeof(struct flash_sector));
	bank->sectors[0].size = bank->size;
	bank->sectors[0].is_erased = -1;
	bank->sectors[0].is_protected = -1;

	bank->write_start_alignment = bank->size;
	bank->write_end_alignment = bank->size;
	bank->minimal_write_gap = bank->size;

	info->page_size = bank->size;
	info->is_probed = true;

	return ERROR_OK;
}

static int efuse_auto_probe(struct flash_bank *bank)
{
	struct mxs40_bank_info *info = bank->driver_priv;
	return info->is_probed ? ERROR_OK : efuse_probe(bank);
}

static int mxs40_probe(struct flash_bank *bank)
{
	struct target *target = bank->target;
	struct mxs40_bank_info *info = bank->driver_priv;
	int hr;
	uint32_t val;

	if (bank->sectors) {
		free(bank->sectors);
		bank->sectors = NULL;
		bank->num_sectors = 0;
	}

	/* Autodetect PSoC6 type (1M/2M) */
/*	hr = psoc6_detect_mem_layout(target, &info->regs);
 *	if (hr != ERROR_OK)
 *		return hr; */

	info->regs = &psoc6_regs;
	if (!info->regs) {
		LOG_ERROR("Unknown PSoC6 device, giving up...");
		return ERROR_TARGET_INVALID;
	}

	/* Retrieve data from SPCIF_GEOMETRY */
	hr = target_read_u32(target, info->regs->spcif_geometry, &val);

	uint32_t row_sz_lg2;
	uint32_t row_sz;
	uint32_t row_cnt;
	uint32_t bank_cnt;

	if (info->regs->variant == MXS40_VARIANT_PSOC6A1M) {
		row_sz_lg2 = (val & 0xF0) >> 4;
		row_sz = (0x01 << row_sz_lg2);
		row_cnt = 1 + ((val & 0x00FFFF00) >> 8);
		bank_cnt = 1 + ((val & 0xFF000000) >> 24);
	} else if (info->regs->variant == MXS40_VARIANT_PSOC6A2M) {
		row_cnt = 1 + (val & 0x0000FFFF);
		row_sz_lg2 = (val & 0xF0000000) >> 28;
		row_sz = (0x01 << row_sz_lg2);
		bank_cnt = 1 + ((val & 0x00FF0000) >> 16);
	} else {
		hr = traveo2_probe(bank, val);
		return hr;
	}

	/* Calculate size of Main Flash */
	uint32_t flash_sz_bytes = bank_cnt * row_cnt * row_sz;
	if (hr != ERROR_OK) {
		if (flash_bank_matches(bank, info->regs->mem_base_main))
			LOG_WARNING(
				"FLASHC.GEOMETRY is not accessible, assuming Flash Size is %d kB",
				bank->size / 1024);

		flash_sz_bytes = bank->size;
		row_sz = 512;
		hr = ERROR_OK;
	}

	if (bank->sectors) {
		free(bank->sectors);
		bank->sectors = NULL;
	}

	size_t bank_size = 0;
	if (flash_bank_matches(bank, info->regs->mem_base_main))
		bank_size = flash_sz_bytes;
	else if (flash_bank_matches(bank, info->regs->mem_base_work))
		bank_size = MEM_WFLASH_SIZE;
	else if (flash_bank_matches(bank, info->regs->mem_base_sflash))
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
 * @brief Probes target device only if it hasn't been probed yet
 * @param bank current flash bank
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int mxs40_auto_probe(struct flash_bank *bank)
{
	struct mxs40_bank_info *info = bank->driver_priv;
	return info->is_probed ? ERROR_OK : mxs40_probe(bank);
}

/** ***********************************************************************************************
 * @brief Erases single sector (256k) on target device
 * @param bank current flash bank
 * @param wa working area for SROM API parameters
 * @param addr starting address of the sector
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int psoc6_erase_sector(struct flash_bank *bank, struct working_area *wa, uint32_t addr)
{
	struct target *target = bank->target;
	int hr;

	LOG_DEBUG("psoc6: eraseing sector @%08X", addr);

	hr = target_write_u32(target, wa->address, SROMAPI_ERASESECTOR_REQ);
	if (hr != ERROR_OK)
		return hr;

	hr = target_write_u32(target, wa->address + 0x04, addr);
	if (hr != ERROR_OK)
		return hr;

	uint32_t data_out;
	hr = mxs40_call_sromapi(bank, SROMAPI_ERASESECTOR_REQ, wa->address, &data_out);

	if (hr != ERROR_OK)
		LOG_ERROR("SECTOR @%08X not erased!", addr);

	return hr;
}

/** ***********************************************************************************************
 * @brief Erases single row (512b) on target device
 * @param bank current flash bank
 * @param wa working area for SROM API parameters
 * @param addr starting address of the flash row
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int psoc6_erase_row(struct flash_bank *bank, struct working_area *wa, uint32_t addr)
{
	struct target *target = bank->target;

	LOG_DEBUG("psoc6: eraseing row @%08X", addr);

	int hr = target_write_u32(target, wa->address, SROMAPI_ERASEROW_REQ);
	if (hr != ERROR_OK)
		return hr;

	hr = target_write_u32(target, wa->address + 0x04, addr);
	if (hr != ERROR_OK)
		return hr;

	uint32_t data_out;
	hr = mxs40_call_sromapi(bank, SROMAPI_ERASEROW_REQ, wa->address, &data_out);
	if (hr != ERROR_OK)
		LOG_ERROR("ROW @%08X not erased!", addr);

	return hr;
}

static int psoc6_program(struct flash_bank *bank, const uint8_t *buffer, uint32_t offset,
	uint32_t count);

/** ***********************************************************************************************
 * @brief Erases Supervisory Flash by programming it with zeros
 *
 * @param bank current flash bank
 * @param first first sector to erase
 * @param last last sector to erase
 * @return ERROR_OK, all errors are ignored (but reported)
 *************************************************************************************************/
static int psoc6_erase_sflash(struct flash_bank *bank, int first, int last)
{
	uint32_t offset = bank->sectors[first].offset;
	uint32_t size = bank->sectors[last].offset + bank->sectors[last].size - offset;
	uint8_t *buffer = calloc(1, size);

	g_sflash_skipped_silent = true;
	bool g_allow_unsafe_sflash_writes_tmp = g_allow_unsafe_sflash_writes;
	g_allow_unsafe_sflash_writes = false;
	int hr = psoc6_program(bank, buffer, offset, size);
	g_allow_unsafe_sflash_writes = g_allow_unsafe_sflash_writes_tmp;
	g_sflash_skipped_silent = false;

	free(buffer);
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
static int efuse_erase(struct flash_bank *bank, int first, int last)
{
	(void) bank; (void) first; (void) last;
	LOG_INFO("Erase operation for EFuse bank is not supported, skipping");
	return ERROR_OK;

}

static int psoc6_erase(struct flash_bank *bank, int first, int last)
{
	struct target *target = bank->target;
	struct mxs40_bank_info *info = bank->driver_priv;
	struct working_area *wa;
	int hr;

	if (flash_bank_matches(bank, info->regs->mem_base_sflash)) {
		psoc6_erase_sflash(bank, first, last);
		return ERROR_OK;
	}

	hr = sromalgo_prepare(bank);
	if (hr != ERROR_OK)
		goto exit;

	hr = target_alloc_working_area(target, info->page_size + 32, &wa);
	if (hr != ERROR_OK)
		goto exit;

	if (info->regs->variant == MXS40_VARIANT_TRAVEO_II) {
		progress_init(last - first + 1, ERASING);
		for (int i = first; i <= last; i++) {
			hr = psoc6_erase_sector(bank, wa, bank->base + bank->sectors[i].offset);
			if (hr != ERROR_OK)
				goto exit_free_wa;
			progress_sofar(i - first + 1);
		}
	} else {
		const uint32_t sector_size = flash_bank_matches(bank, info->regs->mem_base_work) ?
			WFLASH_SECTOR_SIZE : MFLASH_SECTOR_SIZE;

		/* Number of rows in single sector */
		const int rows_in_sector = sector_size / info->page_size;

		progress_init(last - first + 1, ERASING);
		while (last >= first) {
			/* Erase Sector if we are on sector boundary and erase size covers whole
			 * sector */
			if ((first % rows_in_sector) == 0 &&
				(last - first + 1) >= rows_in_sector) {
				hr = psoc6_erase_sector(bank, wa, bank->base + first * info->page_size);
				if (hr != ERROR_OK)
					goto exit_free_wa;

				for (int i = first; i < first + rows_in_sector; i++)
					bank->sectors[i].is_erased = 1;

				first += rows_in_sector;
			} else {
				/* Perform Row Erase otherwise */
				hr = psoc6_erase_row(bank, wa, bank->base + first * info->page_size);
				if (hr != ERROR_OK)
					goto exit_free_wa;

				bank->sectors[first].is_erased = 1;
				first += 1;
			}

			progress_left(last - first + 1);
		}
	}

exit_free_wa:
	target_free_working_area(target, wa);
exit:
	sromalgo_release(target);
	progress_done(hr);
	return hr;
}

/** ***********************************************************************************************
 * @brief Reads single Efuse byte
 *
 * @param bank The bank to read
 * @param addr The address of efuse byte to read
 * @param efuse_byte_value The read value of efuse byte
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_read_byte(struct flash_bank *bank, uint16_t addr, uint8_t *efuse_byte_value)
{
	uint32_t data_out = 0;

	int hr = mxs40_call_sromapi(bank, SROMAPI_READ_FUSE_BYTE + (addr << 8), 0, &data_out);
	if (hr != ERROR_OK)
		return hr;

	*efuse_byte_value = (uint8_t)data_out;

	return hr;
}

/** ***********************************************************************************************
 * @brief Performs Read operation of EFuse region.
 *
 * @param bank The bank to read
 * @param buffer The data bytes read
 * @param offset The offset into the chip to read
 * @param count The number of bits to read. Note: single efuse bit is represented by bye in a
 * programming file
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_read_bank(struct flash_bank *bank, uint8_t *buffer,
	uint32_t offset, uint32_t count)
{

	memset(buffer, 0, count);

	uint32_t cur_addr = offset;
	uint32_t end_addr = offset + count;
	uint32_t start_byte_addr = cur_addr / BYTE_BITS * BYTE_BITS;

	uint8_t byte_addr = 0;
	uint8_t efuse = 0;
	uint8_t bit_counter = 0;

	int hr = sromalgo_prepare(bank);
	if (hr != ERROR_OK)
		goto exit;

	/* calculate number of bits to read */
	size_t num_bits_to_read = 0;
	/* check if need to read from middle of efuse byte */
	if (cur_addr > start_byte_addr) {
		byte_addr = (uint8_t)(cur_addr / BYTE_BITS);
		hr = efuse_read_byte(bank, byte_addr, &efuse);
		if (hr != ERROR_OK)
			goto exit;
		size_t skip_bits_start = (uint8_t)(cur_addr - start_byte_addr);

		if ((BYTE_BITS - skip_bits_start) > count)
			num_bits_to_read = (size_t)count;
		else
			num_bits_to_read = BYTE_BITS - skip_bits_start;

		bit_counter = 0;
		for (size_t bit_addr = skip_bits_start;
			bit_addr < skip_bits_start + num_bits_to_read; bit_addr++) {
			if (efuse & (1 << bit_addr))
				buffer[bit_counter] = 1;
			bit_counter++;
		}
		cur_addr += num_bits_to_read;
	}

	num_bits_to_read = BYTE_BITS;

	while (cur_addr < end_addr) {
		if (cur_addr + BYTE_BITS > end_addr) {
			/* last efuse byte to read */
			num_bits_to_read = (size_t)(end_addr - cur_addr);
		}

		byte_addr = (uint8_t)(cur_addr / BYTE_BITS);
		hr = efuse_read_byte(bank, byte_addr, &efuse);
		if (hr != ERROR_OK)
			goto exit;
		bit_counter = 0;
		for (uint8_t bit_addr = 0; bit_addr < num_bits_to_read; bit_addr++) {
			if (efuse & (1 << bit_addr))
				buffer[cur_addr + bit_counter - offset] = 1;
			bit_counter++;
		}
		cur_addr += num_bits_to_read;
	}

exit:
	sromalgo_release(bank->target);
	return hr;
}

/** ***********************************************************************************************
 * @brief returns lifycycle included into programming file
 * @param pgmFileLifeCycleByte lifecycle byte read from programming file
 * @return lifycycle included into programming file
 *************************************************************************************************/
static uint8_t efuse_get_life_cycle_from_file(uint8_t life_cycle_byte)
{
	uint8_t ret_life_cycle = 0;

	/* if RMA bit is set all other bits are ignored */
	if ((life_cycle_byte & MXS40_LIFE_CYCLE_RMA) == MXS40_LIFE_CYCLE_RMA)
		ret_life_cycle = MXS40_LIFE_CYCLE_RMA;
	/* if SECURE bit is set all other bits are ignored */
	else if ((life_cycle_byte & MXS40_LIFE_CYCLE_SECURE) == MXS40_LIFE_CYCLE_SECURE)
		ret_life_cycle = MXS40_LIFE_CYCLE_SECURE;
	/* if SECURE_WITH_DEBUG bit is set all other bits are ignored */
	else if ((life_cycle_byte & MXS40_LIFE_CYCLE_SECURE_DEBUG) == MXS40_LIFE_CYCLE_SECURE_DEBUG)
		ret_life_cycle = MXS40_LIFE_CYCLE_SECURE_DEBUG;
	/* if NORMAL bit is set all other bits are ignored */
	else if ((life_cycle_byte & MXS40_LIFE_CYCLE_NORMAL) == MXS40_LIFE_CYCLE_NORMAL)
		ret_life_cycle = MXS40_LIFE_CYCLE_NORMAL;

	return ret_life_cycle;
}

/** ***********************************************************************************************
 * @brief returns efuse byte with specific offset from programming file
 * @param buffer contains whole efuse region
 * @param offset address of efuse byte to be checked
 * @return efuse byte with specific offset from programming file
 *************************************************************************************************/
static uint8_t efuse_get_byte_from_file(const uint8_t *buffer, uint16_t offset)
{
	size_t pos_start = (size_t)(offset * BYTE_BITS);
	size_t pos_end = (size_t)(offset * BYTE_BITS + BYTE_BITS);

	uint8_t bitPos = 0;
	uint8_t read_efuse_byte = 0;
	for (size_t i = pos_start; i < pos_end; i++) {
		if (buffer[i] == MXS40_EFUSE_BLOWN)
			read_efuse_byte |= 1 << bitPos;

		bitPos++;
	}
	return read_efuse_byte;
}

/** ***********************************************************************************************
 * @brief Checks if Efuse byte with specific offset is present in programming file
 * @param buffer contains whole efuse region
 * @param offset address of efuse byte to be checked
 * @return true if requesed efuse byte is present
 *************************************************************************************************/
static uint8_t efuse_is_byte_in_file(const uint8_t *buffer, uint16_t offset)
{
	/* buffer contains list of eFuse bits, one bit is represented as byte:
	 * 0x00 - not blown
	 * 0x01 - blown
	 * 0xFF - ignored */

	size_t pos_start = (size_t)(offset * BYTE_BITS);
	size_t pos_end = pos_start + BYTE_BITS;

	for (size_t i = pos_start; i < pos_end; i++) {
		if (buffer[i] != MXS40_EFUSE_IGNORE)
			return true;
	}
	return false;
}

/** ***********************************************************************************************
 * @brief Returns specific bit of efuse byte
 * @param bank current flash bank
 * @param addr address of efuse byte
 * @param bitAddr bit address of efuse bit inside of the efuse byte
 * @param bitValue returns 1 if read efuse bit with specific address is not empty
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_get_bit(struct flash_bank *bank, uint8_t addr, uint8_t bit_addr,
	uint8_t *bit_value)
{

	uint8_t readByte = 0;
	int hr = efuse_read_byte(bank, addr, &readByte);
	if (hr == ERROR_OK)
		*bit_value = (readByte & (1 << bit_addr)) != 0;
	return hr;
}

/** ***********************************************************************************************
 * @brief Blows the addressed eFuse bit and checks if efuse was blown correctly
 * @param bank current flash bank
 * @param addr address of efuse byte
 * @param bit_addr bit address of efuse bit inside of the efuse byte
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_blow_bit(struct flash_bank *bank, uint8_t addr, uint8_t bit_addr)
{
	uint8_t bitValue = 0;
	int hr = efuse_get_bit(bank, addr, bit_addr, &bitValue);
	if (hr != ERROR_OK)
		return hr;

	if (bitValue == 1) {
		LOG_WARNING("The efuse bit at address 0x%X[%X] has already been blown",
			addr, bit_addr);
		return ERROR_OK;
	}

	uint8_t macro_addr = 0;
	uint8_t byte_addr = addr;

	while (byte_addr >= SROMAPI_BLOW_FUSE_MACROPERADDR) {
		byte_addr -= SROMAPI_BLOW_FUSE_MACROPERADDR;
		macro_addr++;
	}
	uint32_t params = (SROMAPI_BLOW_FUSE_CODE << SROMAPI_BLOW_FUSE_CODE_ROL) +
		(SROMAPI_BLOW_FUSE_ADDR_MASK & (byte_addr << SROMAPI_BLOW_FUSE_ADDR_ROL)) +
		(SROMAPI_BLOW_FUSE_MACRO_MASK & (macro_addr << SROMAPI_BLOW_FUSE_MACRO_ROL)) +
		(SROMAPI_BLOW_FUSE_BIT_MASK & (bit_addr << SROMAPI_BLOW_FUSE_BIT_ROL)) + 1;

	uint32_t data = 0;
	hr = mxs40_call_sromapi(bank, params, 0, &data);

	if (hr != ERROR_OK) {
		LOG_ERROR("Error of BlowFuseBit Addr = %X[%X]", addr, bit_addr);
		return hr;
	}

	hr = efuse_get_bit(bank, addr, bit_addr, &bitValue);
	if (hr != ERROR_OK)
		return hr;

	const char EFUSE_MSG1[] =
		"2.5 Volts +/-5 % is required to blow efuse bits. Check the supplied voltage is within";
	const char EFUSE_MSG2[] =
		"the required range and pay attend to the precision of power supply and power meter";

	if (bitValue == 0) {
		LOG_ERROR("The efuse bit at address 0x%X[%X] was not blown. %s %s",
			addr,
			bit_addr,
			EFUSE_MSG1,
			EFUSE_MSG2);
		return ERROR_FLASH_OPERATION_FAILED;
	}
	return ERROR_OK;
}

/** ***********************************************************************************************
 * @brief Displays information why lifecycle transition is not allowed
 * @param chip_prot current chip protection returned by SROM API
 * @param file_lc lifecycle read from programming file
 *************************************************************************************************/
static void efuse_transition_forbidden(uint8_t chip_prot, uint8_t file_lc)
{
	char *chip_prot_str;
	char *file_lc_str;

	file_lc_str =
		(file_lc == MXS40_LIFE_CYCLE_NORMAL) ? "Normal" :
		(file_lc == MXS40_LIFE_CYCLE_SECURE_DEBUG) ? "Secure with Debug" :
		(file_lc == MXS40_LIFE_CYCLE_SECURE) ? "Secure" :
		NULL;

	if (file_lc_str == NULL) {
		LOG_ERROR("The programming file contains an invalid Life Cycle stage");
		return;
	}

	chip_prot_str =
		(chip_prot == MXS40_CHIP_PROT_UNKNOWN) ? "Unknown" :
		(chip_prot == MXS40_CHIP_PROT_VIRGIN) ? "Virgin" :
		(chip_prot == MXS40_CHIP_PROT_NORMAL) ? "Normal" :
		(chip_prot == MXS40_CHIP_PROT_SECURE) ? "Secure" :
		(chip_prot == MXS40_CHIP_PROT_DEAD) ? "Dead" :
		NULL;

	if (chip_prot_str == NULL) {
		LOG_ERROR("The target is in unknown protection state");
		return;
	}

	if (strcmp(chip_prot_str, file_lc_str) == 0)
		LOG_WARNING("The '%s' eFuse bit is already blown", chip_prot_str);
	else {
		LOG_ERROR("Transaction to '%s' Life Cycle in '%s' Protection State is not allowed",
			file_lc_str, chip_prot_str);
	}
}

/** ***********************************************************************************************
 * @brief Checks the Factory HASH of the FLASH boot programmed in SFLASH
 * @param bank current flash bank
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_check_factory_hash(struct flash_bank *bank)
{

	LOG_DEBUG("psoc6: checkFactoryHASH");
	struct target *target = bank->target;

	struct working_area *wa;

	int hr = target_alloc_working_area(target, sizeof(uint32_t), &wa);
	if (hr != ERROR_OK)
		goto exit;

	uint32_t sromapi_req = SROMAPI_CHECK_FACTORY_HASH;

	hr = target_write_u32(target, wa->address, sromapi_req);
	if (hr != ERROR_OK)
		goto exit_free_wa;

	uint32_t data_out;
	hr = mxs40_call_sromapi(bank, sromapi_req, wa->address, &data_out);

exit_free_wa:
	target_free_working_area(target, wa);

exit:
	return hr;
}

/** ***********************************************************************************************
 * @brief Generates hash and hash zero
 * @param bank current flash bank
 * @param hash_arr address of array for generated hash value
 * @param hash_arr_size size of hash_arr
 * @param hashZeros generated hash zero value
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_generate_hash(struct flash_bank *bank,
	uint8_t *hash_arr, size_t hash_arr_size, uint8_t *hash_zeros)
{

	LOG_DEBUG("psoc6: generateHASH");

	/* todo : correct response code, e.g. invalid argument */
	if (hash_arr_size <  MXS40_EFUSE_FLASH_BOOT_HASH_SIZE)
		return ERROR_FLASH_OPERATION_FAILED;

	struct target *target = bank->target;

	struct working_area *wa;

	int hr = target_alloc_working_area(target,
			sizeof(uint32_t) * MXS40_EFUSE_FLASH_BOOT_HASH_RESPONSE_SIZE,
			&wa);
	if (hr != ERROR_OK)
		goto exit;

	uint32_t sromapi_req = SROMAPI_GENERATE_HASH_CODE;

	hr = target_write_u32(target, wa->address, sromapi_req);
	if (hr != ERROR_OK)
		goto exit_free_wa;

	uint32_t data_out;
	hr = mxs40_call_sromapi(bank, sromapi_req, wa->address, &data_out);
	if (hr != ERROR_OK)
		goto exit_free_wa;

	for (size_t i = 0; i < MXS40_EFUSE_FLASH_BOOT_HASH_SIZE / sizeof(uint32_t); i++) {
		hr = target_read_u32(target, wa->address + 4 * (i + 1), &data_out);
		if (hr != ERROR_OK)
			goto exit_free_wa;

		hash_arr[4 * i + 0] = (data_out >> 0) & 0xFF;
		hash_arr[4 * i + 1] = (data_out >> 8) & 0xFF;
		hash_arr[4 * i + 2] = (data_out >> 16) & 0xFF;
		hash_arr[4 * i + 3] = (data_out >> 24) & 0xFF;
	}

	hr = target_read_u32(target,
			wa->address + MXS40_EFUSE_FLASH_BOOT_HASH_ZEROS_OFSET,
			&data_out);
	if (hr != ERROR_OK)
		goto exit_free_wa;

	*hash_zeros = data_out;

exit_free_wa:
	target_free_working_area(target, wa);

exit:
	return hr;
}

/** ***********************************************************************************************
 * @brief Blows whole efuse byte and checks if the efuses were blown correctly
 * @param bank current flash bank
 * @param addr the address of efuse byte
 * @param data the value to be blown
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_blow_byte(struct flash_bank *bank, uint8_t addr, uint8_t data)
{

	int hr = ERROR_OK;

	for (uint8_t bitAddr = 0; bitAddr < 8; bitAddr++) {
		if (((data >> bitAddr) & 0x01) == 0x01) {
			hr = efuse_blow_bit(bank, addr, bitAddr);
			if (hr != ERROR_OK)
				break;
		}
	}
	return hr;
}

/** ***********************************************************************************************
 * @brief Programs EFuse region
 * @param bank current flash bank
 * @param addr address of the flash row
 * @param buffer pointer to the buffer with data
 * @param count number of bytes in buffer
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_program_bank(struct flash_bank *bank,
	const uint8_t *buffer, uint32_t offset,
	uint32_t count)
{
	if (!g_allow_efuse_programming) {
		LOG_WARNING("Programming of eFuse bank is skipped. Use 'psoc6 allow_efuse_program on|off'"
			" command to enable|disable programming of efuse bank");
		return ERROR_OK;
	}

	/* Verify if efuse data in programming file is correct */
	for (size_t i = 0; i < count; i++) {
		if (buffer[i] != MXS40_EFUSE_NOT_BLOWN &&
			buffer[i] != MXS40_EFUSE_BLOWN &&
			buffer[i] != MXS40_EFUSE_IGNORE) {
			LOG_ERROR("The eFuse bit value is out of the range. Allowed values are:"
				"0x00, 0x01 and 0xFF, but found 0x%X", buffer[i]);
			return ERROR_COMMAND_SYNTAX_ERROR;
		}
	}

	/* Get lifecycle efuse if present */
	uint8_t pgm_file_life_cycle = 0;
	if (efuse_is_byte_in_file(buffer, MXS40_EFUSE_LIFECYCLE_STAGE_OFFSET)) {
		/* Read LifeCycle from programming file */
		pgm_file_life_cycle = efuse_get_byte_from_file(buffer,
				MXS40_EFUSE_LIFECYCLE_STAGE_OFFSET);
		pgm_file_life_cycle = efuse_get_life_cycle_from_file(pgm_file_life_cycle);
	}

	int hr = sromalgo_prepare(bank);
	if (hr != ERROR_OK)
		goto exit;

	size_t lifecycle_offset = MXS40_EFUSE_LIFECYCLE_STAGE_OFFSET * BYTE_BITS;
	/* Program all efuses from programming file except lifecycle */
	for (size_t i = 0; i <= count; i++) {
		if (i >= lifecycle_offset && i < lifecycle_offset + BYTE_BITS - 1)
			continue;
		if (buffer[i] != MXS40_EFUSE_IGNORE) {

			uint8_t byte_addr = (uint8_t)(i / BYTE_BITS);
			uint8_t bit_addr = (uint8_t)(i % BYTE_BITS);

			/*check if efuse is not blown if has to be */
			if (buffer[i] == MXS40_EFUSE_NOT_BLOWN) {
				uint8_t efuse_bit_value = 0;
				hr = efuse_get_bit(bank, byte_addr, bit_addr, &efuse_bit_value);
				if (hr != ERROR_OK) {
					LOG_ERROR("Cannot read Efuse byte at Addr = 0x%X",
						byte_addr);
					goto exit_release;
				}
				if (efuse_bit_value == 1) {
					LOG_ERROR(
						"EFuse bit at address 0x%X[%d] is blown but has to be not blown",
						byte_addr,
						bit_addr);
					goto exit_release;
				}
			} else if (buffer[i] == MXS40_EFUSE_BLOWN) {
				hr = efuse_blow_bit(bank, byte_addr, bit_addr);
				if (hr != ERROR_OK)
					goto exit_release;
			}
		}
	}

	/* Program lifecycle efuses if present */
	if (pgm_file_life_cycle) {

		/* Get chip protection */
		uint32_t silicon_id;
		uint8_t protection;


		/* get_silicon_id contains sromalgo_prepare, so release it here */
		sromalgo_release(bank->target);

		hr = mxs40_get_silicon_id(bank, &silicon_id, &protection);
		if (hr != ERROR_OK)
			goto exit;

		hr = sromalgo_prepare(bank);
		if (hr != ERROR_OK)
			goto exit;

		/* Check that the transaction meets the flow: NORMAL->SECURE/SECURE_WITH_DEBUG and
		 * program eFuse */

		bool is_secure_programming = false;	/* is SECURE or SECURE_WITH_DEBUG
							 * transaction? */
		uint8_t secure_bit_addr = 0;				/* Bit addr of SECURE or
									 * SECURE_WITH_DEBUG */

		if (protection == MXS40_CHIP_PROT_NORMAL &&
			pgm_file_life_cycle == MXS40_LIFE_CYCLE_SECURE_DEBUG) {
			is_secure_programming = true;
			secure_bit_addr = MXS40_EFUSE_LIFE_CYCLE_SECURE_DEBUG_BIT_ADDR;
		} else if (protection == MXS40_CHIP_PROT_NORMAL &&
			pgm_file_life_cycle == MXS40_LIFE_CYCLE_SECURE) {
			is_secure_programming = true;
			secure_bit_addr = MXS40_EFUSE_LIFE_CYCLE_SECURE_BIT_ADDR;
		}

		if (!is_secure_programming)
			efuse_transition_forbidden(protection, pgm_file_life_cycle);
		else {	/* NORMAL to SECURE or SECURE_WITH_DEBUG */
			hr = efuse_check_factory_hash(bank);
			if (hr != ERROR_OK)
				goto exit_release;

			uint8_t hash[MXS40_EFUSE_FLASH_BOOT_HASH_SIZE];
			uint8_t hash_zeros = 0;
			hr = efuse_generate_hash(bank,
					hash,
					MXS40_EFUSE_FLASH_BOOT_HASH_SIZE,
					&hash_zeros);
			if (hr != ERROR_OK)
				goto exit_release;

			/* Program FLASH_BOOT_HASH */

			for (uint8_t byte_num = 0; byte_num < MXS40_EFUSE_FLASH_BOOT_HASH_SIZE;
				byte_num++) {
				hr = efuse_blow_byte(bank,
						MXS40_EFUSE_FLASH_BOOT_HASH_OFFSET + byte_num,
						hash[byte_num]);
				if (hr != ERROR_OK)
					goto exit_release;
			}

			/* Program FLASH_BOOT_HASH_ZEROS */
			hr = efuse_blow_byte(bank,
					MXS40_EFUSE_FLASH_BOOT_HASH_ZEROS_OFFSET,
					hash_zeros);
			if (hr != ERROR_OK)
				goto exit_release;

			hr = efuse_blow_bit(bank,
					MXS40_EFUSE_LIFECYCLE_STAGE_OFFSET,
					secure_bit_addr);
			if (hr != ERROR_OK)
				goto exit_release;
		}

	}	/* program chip protection */
	else
		LOG_INFO("The Life Cycle stage is not present in the programming file");
exit_release:
	sromalgo_release(bank->target);
exit:
	return hr;
}

/** ***********************************************************************************************
 * @brief Programs single Flash Row
 * @param bank current flash bank
 * @param addr address of the flash row
 * @param buffer pointer to the buffer with data
 * @param is_sflash true if current flash bank belongs to Supervisory Flash
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int psoc6_program_row(struct flash_bank *bank,
	uint32_t addr,
	const uint8_t *buffer,
	bool is_sflash)
{
	struct target *target = bank->target;
	struct mxs40_bank_info *info = bank->driver_priv;
	struct working_area *wa;
	const uint32_t sromapi_req = is_sflash ? SROMAPI_WRITEROW_REQ : SROMAPI_PROGRAMROW_REQ;
	uint32_t data_out;
	int hr = ERROR_OK;

	LOG_DEBUG("psoc6: programming row @%08X", addr);

	hr = target_alloc_working_area(target, info->page_size + 32, &wa);
	if (hr != ERROR_OK)
		goto exit;

	hr = target_write_u32(target, wa->address, sromapi_req);
	if (hr != ERROR_OK)
		goto exit_free_wa;

	hr = target_write_u32(target, wa->address + 0x04, 0x109);
	if (hr != ERROR_OK)
		goto exit_free_wa;

	hr = target_write_u32(target, wa->address + 0x08, addr);
	if (hr != ERROR_OK)
		goto exit_free_wa;

	hr = target_write_u32(target, wa->address + 0x0C, wa->address + 0x10);
	if (hr != ERROR_OK)
		goto exit_free_wa;

	hr = target_write_buffer(target, wa->address + 0x10, info->page_size, buffer);
	if (hr != ERROR_OK)
		goto exit_free_wa;

	hr = mxs40_call_sromapi(bank, sromapi_req, wa->address, &data_out);

exit_free_wa:
	target_free_working_area(target, wa);

exit:
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
static int psoc6_program_fast(struct flash_bank *bank, const uint8_t *buffer,
	uint32_t offset, uint32_t count)
{
	struct target *target = bank->target;
	struct mxs40_bank_info *info = bank->driver_priv;
	int hr;

	struct working_area *wa_algorithm;
	struct working_area *wa_stack;
	struct working_area *wa_buffer;

	const uint8_t *algo_p = NULL;	/* Silence the compile error on MinGW */
	size_t algo_size = 0;
	if (info->regs->variant == MXS40_VARIANT_PSOC6A1M) {
		algo_p = p6_program_algo;
		algo_size = sizeof(p6_program_algo);
	} else if (info->regs->variant == MXS40_VARIANT_PSOC6A2M) {
		algo_p = p62m_program_algo;
		algo_size = sizeof(p62m_program_algo);
	} else if (info->regs->variant == MXS40_VARIANT_TRAVEO_II) {
		algo_p = tv2_program_algo;
		algo_size = sizeof(tv2_program_algo);

		hr = target_write_u32(bank->target, 0x4024F400, 0x01);
		if (hr != ERROR_OK)
			return hr;

		hr = target_write_u32(bank->target, 0x4024F500, 0x01);
		if (hr != ERROR_OK)
			return hr;
	} else
		assert(0);

	/* Allocate buffer for the algorithm */
	hr = target_alloc_working_area(target, algo_size, &wa_algorithm);
	if (hr != ERROR_OK)
		return hr;

	/* Write the algorithm code */
	hr = target_write_buffer(target,
			wa_algorithm->address,
			algo_size,
			algo_p);
	if (hr != ERROR_OK)
		goto err_free_wa_algo;

	/* Allocate buffer for the stack */
	hr = target_alloc_working_area(target, RAM_STACK_WA_SIZE, &wa_stack);
	if (hr != ERROR_OK)
		goto err_free_wa_algo;

	/* Try to allocate as large RAM Buffer as possible starting form 16 Page Buffers*/
	uint32_t buffer_size = 16 * info->page_size;

	while (target_alloc_working_area_try(target, buffer_size + 8, &wa_buffer) != ERROR_OK) {
		buffer_size -= info->page_size;
		if (buffer_size <= 4 * info->page_size) {
			LOG_WARNING("Failed to allocate Circular Buffer");
			hr = ERROR_TARGET_RESOURCE_NOT_AVAILABLE;
			goto err_free_wa_stack;
		}
	}

	LOG_DEBUG("Allocated %u bytes for circular buffer", buffer_size);

	struct armv7m_algorithm armv7m_algo;
	armv7m_algo.common_magic = ARMV7M_COMMON_MAGIC;
	armv7m_algo.core_mode = ARM_MODE_THREAD;

	struct reg_param reg_params[5];
	init_reg_param(&reg_params[0], "r0", 32, PARAM_IN_OUT);
	init_reg_param(&reg_params[1], "r1", 32, PARAM_OUT);
	init_reg_param(&reg_params[2], "r2", 32, PARAM_OUT);
	init_reg_param(&reg_params[3], "r3", 32, PARAM_OUT);
	init_reg_param(&reg_params[4], "sp", 32, PARAM_OUT);

	buf_set_u32(reg_params[0].value, 0, 32, wa_buffer->address);
	buf_set_u32(reg_params[1].value, 0, 32, wa_buffer->address + wa_buffer->size);
	buf_set_u32(reg_params[2].value, 0, 32, bank->base + offset);
	buf_set_u32(reg_params[3].value, 0, 32, count / info->page_size);
	buf_set_u32(reg_params[4].value, 0, 32, wa_stack->address + wa_stack->size);

	hr = target_run_flash_async_algorithm(target, buffer, count / info->page_size,
			info->page_size, 0, NULL, 5, reg_params,
			wa_buffer->address, wa_buffer->size,
			wa_algorithm->address, 0, &armv7m_algo);

	if (hr != ERROR_OK) {
		uint32_t srom_result = buf_get_u32(reg_params[0].value, 0, 32);
		if ((srom_result & SROMAPI_STATUS_MSK) != SROMAPI_STAT_SUCCESS) {
			LOG_ERROR("SROM API execution failed. Status: 0x%08X", srom_result);
			hr = ERROR_FAIL;
		}
	}

	destroy_reg_param(&reg_params[0]);
	destroy_reg_param(&reg_params[1]);
	destroy_reg_param(&reg_params[2]);
	destroy_reg_param(&reg_params[3]);
	destroy_reg_param(&reg_params[4]);

	target_free_working_area(target, wa_buffer);

err_free_wa_stack:
	target_free_working_area(target, wa_stack);

err_free_wa_algo:
	target_free_working_area(target, wa_algorithm);

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
static int psoc6_program(struct flash_bank *bank, const uint8_t *buffer, uint32_t offset,
	uint32_t count)
{
	struct target *target = bank->target;
	struct mxs40_bank_info *info = bank->driver_priv;
	int hr = ERROR_OK;

	assert(offset % info->page_size == 0);
	assert(count % info->page_size == 0);

	const bool is_sflash = flash_bank_matches(bank, info->regs->mem_base_sflash);

	if (!is_sflash)
		return psoc6_program_fast(bank, buffer, offset, count);

	hr = sromalgo_prepare(bank);
	if (hr != ERROR_OK)
		goto exit;


	progress_init(count / info->page_size, PROGRAMMING);
	for (size_t i = 0; i < count / info->page_size; i++) {
		const uint32_t page_addr = bank->base + offset + i * info->page_size;
		if (!is_sflash || is_safe_sflash_page(bank, page_addr)) {
			hr = psoc6_program_row(bank, page_addr, buffer, is_sflash);
			if (hr != ERROR_OK) {
				LOG_ERROR("Failed to program Flash at address 0x%08X", page_addr);

				/* Ignore possigle errors in case we are dealing with SFlash */
				if (!is_sflash)
					goto exit;
			}
		} else {
			if (!g_sflash_skipped_silent)
				LOG_WARNING("Unsafe Supervisory Row @0x%08X skipped, use "
					"'psoc6 allow_unsafe_sflash on' to enable programming "
					"of unsafe Rows", page_addr);
		}

		progress_sofar(i + 1);
		buffer += info->page_size;
	}

exit:
	sromalgo_release(target);
	progress_done(hr);
	return hr;
}

/** ***********************************************************************************************
 * @brief Simulates broken Vector Catch
 * Function will try to determine entry point of user application. If it succeeds it will set HW
 * breakpoint at that address, issue SW Reset and remove the breakpoint afterwards.
 * In case of CM0, SYSRESETREQ is used. This allows to reset all peripherals. Boot code will
 * reset CM4 anyway, so using SYSRESETREQ is safe here.
 * In case of CM4, VECTRESET is used instead of SYSRESETREQ to not disturb CM0 core.
 *
 * @param target current target
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int handle_reset_halt(struct target *target, enum reset_halt_mode mode,
	const struct psoc6_regs *regs)
{
	int hr;
	uint32_t reset_addr;
	const bool is_cm0 = (target->coreid == 0);

	/* Read Vector Offset register */
	uint32_t vt_base;
	const uint32_t vt_offset_reg = is_cm0 ? regs->vtbase_cm0 : regs->vtbase_cm4;
	hr = target_read_u32(target, vt_offset_reg, &vt_base);
	if (hr != ERROR_OK)
		return ERROR_OK;

	/* Invalid value means flash is empty */
	vt_base &= 0xFFFFFF00;
	if ((vt_base == 0) || ((vt_base & 0xFFFF0000) == 0xFFFF0000)) {
		LOG_INFO("Vector Table address invalid (0x%08X), reset_halt skipped ", vt_base);
		return ERROR_OK;
	}

	/* Read Reset Vector value */
	hr = target_read_u32(target, vt_base + 4, &reset_addr);
	if (hr != ERROR_OK)
		return hr;

	/* Invalid value means flash is empty */
	if ((reset_addr < MEM_BASE_MFLASH) || (reset_addr > MEM_BASE_MFLASH + 8 * 1024 * 1024)) {
		LOG_INFO("Entry Point address invalid (0x%08X), reset_halt skipped", reset_addr);
		return ERROR_OK;
	}

	/* Set breakpoint at User Application entry point */
	hr = breakpoint_add(target, reset_addr, 2, BKPT_HARD);
	if (hr != ERROR_OK)
		return hr;

	const struct armv7m_common *cm = target_to_armv7m(target);

	/* PSoC6 reboots immediatelly after issuing SYSRESETREQ / VECTRESET
	 * this disables SWD/JTAG pins momentarily and may break communication
	 * Ignoring return value of mem_ap_write_atomic_u32 seems to be ok here */

	char *mode_str = "SYSRESETREQ";
	uint32_t rst_mask = AIRCR_SYSRESETREQ;

	if (mode == mode_default) {
		if (!is_cm0) {
			mode_str = "VECTRESET";
			rst_mask = AIRCR_VECTRESET;
		}
	} else if (mode == mode_vectreset) {
		mode_str = "VECTRESET";
		rst_mask = AIRCR_VECTRESET;
	}

	/* Reset the CM0 by asserting SYSRESETREQ. This will also reset CM4 */
	LOG_INFO("%s: bkpt @0x%08X, issuing %s", target->cmd_name, reset_addr, mode_str);
	mem_ap_write_atomic_u32(cm->debug_ap, NVIC_AIRCR,
		AIRCR_VECTKEY | rst_mask);

	struct cortex_m_common *cortex_m = target_to_cm(target);
	const int dl_old = debug_level;
	debug_level = -1;
	usleep(200000);
	dap_invalidate_cache(cm->debug_ap->dap);
	mem_ap_read_atomic_u32(cm->debug_ap, DCB_DHCSR, &cortex_m->dcb_dhcsr);
	dap_dp_init(cm->debug_ap->dap);
	debug_level = dl_old;

	target_wait_state(target, TARGET_HALTED, IPC_TIMEOUT_MS);

	/* Remove the break point */
	breakpoint_remove(target, reset_addr);

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

	while (count) {
		hr =
			target_read_buffer(bank->target, bank->base + offset, 4, buffer);
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

				er_addr |= ((bank->base + offset) & 0xF8000000);
				LOG_WARNING("ECC Error at address 0x%08X", er_addr);

				hr = target_write_u32(bank->target, FAULT_STATUS(0), 0x00);
				if (hr != ERROR_OK)
					return hr;
			}
		} while (status & FAULT_STATUS_VALID_MASK);

		count -= 4;
		buffer += 4;
		offset += 4;
	}

	return ERROR_OK;
}

/** ***********************************************************************************************
 * @brief Dummy function, device does not support flash bank protection
 * @return ERROR_OK always
 *************************************************************************************************/
static int dummy_protect(struct flash_bank *bank, int set, int first, int last)
{
	(void)bank; (void)set; (void)first; (void)last;

	LOG_WARNING("Device does not support flash bank protection");
	return ERROR_OK;
}

/** ***********************************************************************************************
 * @brief Simulates broken Vector Catch
 * Function will try to determine entry point of user application. If it succeeds it will set HW
 * breakpoint at that address, issue SW Reset and remove the breakpoint afterwards.
 * In case of CM0, SYSRESETREQ is used. This allows to reset all peripherals. Boot code will
 * reset CM4 anyway, so using SYSRESETREQ is safe here.
 * In case of CM4, VECTRESET is used instead of SYSRESETREQ to not disturb CM0 core.
 *
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
COMMAND_HANDLER(psoc6_handle_reset_halt)
{
	enum reset_halt_mode mode;

	if (CMD_ARGC == 0)
		mode = mode_default;
	else if (CMD_ARGC == 1) {
		if (strcmp(CMD_ARGV[0], "sysresetreq") == 0)
			mode = mode_sysresetreq;
		else if (strcmp(CMD_ARGV[0], "vectreset") == 0)
			mode = mode_vectreset;
		else if (strcmp(CMD_ARGV[0], "default") == 0)
			mode = mode_default;
		else
			return ERROR_COMMAND_SYNTAX_ERROR;
	} else
		return ERROR_COMMAND_SYNTAX_ERROR;

	struct target *target = get_current_target(CMD_CTX);


	const struct psoc6_regs *regs = NULL;
	const char *target_name = CMD_CURRENT->parent->name;
	if (strcmp(target_name, "psoc6") == 0)
		regs = &psoc6_regs;
	else if (strcmp(target_name, "psoc62m") == 0)
		regs = &psoc62m_regs;
	else if (strcmp(target_name, "traveo2") == 0)
		regs = &traveo2_regs;

	assert(regs != NULL);

	return handle_reset_halt(target, mode, regs);
}

FLASH_BANK_COMMAND_HANDLER(psoc6_flash_bank_command)
{
	struct mxs40_bank_info *info;
	int hr = ERROR_OK;

	if (CMD_ARGC < 6)
		hr = ERROR_COMMAND_SYNTAX_ERROR;
	else {
		info = calloc(1, sizeof(struct mxs40_bank_info));
		info->is_probed = false;
		bank->driver_priv = info;
	}
	return hr;
}

COMMAND_HANDLER(psoc6_handle_allow_unsafe_sflash)
{
	if (CMD_ARGC != 1)
		return ERROR_COMMAND_SYNTAX_ERROR;

	COMMAND_PARSE_ON_OFF(CMD_ARGV[0], g_allow_unsafe_sflash_writes);

	if (g_allow_unsafe_sflash_writes)
		LOG_WARNING("Writes to 'unsafe' Supervisory Flash rows is now ALLOWED");

	return ERROR_OK;
}

COMMAND_HANDLER(psoc6_handle_allow_efuse_program)
{
	if (CMD_ARGC != 1)
		return ERROR_COMMAND_SYNTAX_ERROR;

	COMMAND_PARSE_ON_OFF(CMD_ARGV[0], g_allow_efuse_programming);

	if (g_allow_efuse_programming)
		LOG_WARNING("Programming of efuses now ALLOWED");

	return ERROR_OK;
}

COMMAND_HANDLER(psoc6_handle_ecc_error_reporting_command)
{
	if (CMD_ARGC != 1)
		return ERROR_COMMAND_SYNTAX_ERROR;

	COMMAND_PARSE_ON_OFF(CMD_ARGV[0], g_ecc_enabled);

	struct target *target = get_current_target(CMD_CTX);

	traveo2_configure_ecc(target, g_ecc_enabled);
	LOG_INFO("ECC error reporting is now %s", g_ecc_enabled ? "Enabled" : "Disabled");

	return ERROR_OK;
}

COMMAND_HANDLER(psoc6_handle_add_safe_sflash_region)
{
	if (CMD_ARGC != 3)
		return ERROR_COMMAND_SYNTAX_ERROR;

	target_addr_t addr;
	uint32_t size;

	COMMAND_PARSE_ADDRESS(CMD_ARGV[1], addr);
	COMMAND_PARSE_NUMBER(u32, CMD_ARGV[2], size);

	struct row_region *tmp;
	tmp = realloc(g_sflash_regions, (g_num_sflash_regions + 1)*sizeof(struct row_region));
	if (tmp == NULL)
		return ERROR_FAIL;

	g_sflash_regions = tmp;
	g_sflash_regions[g_num_sflash_regions].target_name = strdup(CMD_ARGV[0]);
	g_sflash_regions[g_num_sflash_regions].addr = addr;
	g_sflash_regions[g_num_sflash_regions].size = size;

	g_num_sflash_regions++;
	return ERROR_OK;
}

static const struct command_registration mxs40_exec_command_handlers[] = {
	{
		.name = "reset_halt",
		.handler = psoc6_handle_reset_halt,
		.mode = COMMAND_EXEC,
		.usage = "[mode (sysresetreq, vectreset), by default core-dependent reset is used]",
		.help = "Tries to simulate broken Vector Catch",
	},
	{
		.name = "allow_unsafe_sflash",
		.handler = psoc6_handle_allow_unsafe_sflash,
		.mode = COMMAND_ANY,
		.usage = "on|off",
		.help = "Enables writes to 'unsafe' SFlash regions",
	},
	{
		.name = "add_safe_sflash_region",
		.handler = psoc6_handle_add_safe_sflash_region,
		.mode = COMMAND_ANY,
		.usage = "<target> <address> <size>",
		.help = "Enables writes to 'unsafe' SFlash regions",
	},
	COMMAND_REGISTRATION_DONE
};

static const struct command_registration psoc6_exec_command_handlers[] = {
	{
		.name = "allow_efuse_program",
		.handler = psoc6_handle_allow_efuse_program,
		.mode = COMMAND_ANY,
		.usage = "on|off",
		.help = "Enables programming of efuse region",
	},
	{
		.chain = mxs40_exec_command_handlers,
	},
	COMMAND_REGISTRATION_DONE
};

static const struct command_registration tv2_exec_command_handlers[] = {
	{
		.name = "ecc_error_reporting",
		.handler = psoc6_handle_ecc_error_reporting_command,
		.mode = COMMAND_EXEC,
		.usage = "on|off",
		.help = "Controls ECC error reporting",
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
	{
		.name = "traveo2",
		.mode = COMMAND_ANY,
		.help = "Traveo-II flash command group",
		.usage = "",
		.chain = tv2_exec_command_handlers,
	},
	COMMAND_REGISTRATION_DONE
};

struct flash_driver psoc611_flash = {
	.name = "psoc6",
	.commands = psoc6_command_handlers,
	.flash_bank_command = psoc6_flash_bank_command,
	.erase = psoc6_erase,
	.protect = dummy_protect,
	.write = psoc6_program,
	.read = default_flash_read,
	.probe = mxs40_probe,
	.auto_probe = mxs40_auto_probe,
	.erase_check = default_flash_blank_check,
	.protect_check = mxs40_protect_check,
	.info = psoc6_get_info,
	.free_driver_priv = default_flash_free_driver_priv,
};

struct flash_driver psoc6112m_flash = {
	.name = "psoc62m",
	.commands = psoc6_command_handlers,
	.flash_bank_command = psoc6_flash_bank_command,
	.erase = psoc6_erase,
	.protect = dummy_protect,
	.write = psoc6_program,
	.read = default_flash_read,
	.probe = mxs40_probe,
	.auto_probe = mxs40_auto_probe,
	.erase_check = default_flash_blank_check,
	.protect_check = mxs40_protect_check,
	.info = psoc6_get_info,
	.free_driver_priv = default_flash_free_driver_priv,
};

struct flash_driver psoc6_efuse111 = {
	.name = "psoc6_efuse",
	.commands = psoc6_command_handlers,
	.flash_bank_command = psoc6_flash_bank_command,
	.erase = efuse_erase,
	.protect = dummy_protect,
	.write = efuse_program_bank,
	.read = efuse_read_bank,
	.probe = efuse_probe,
	.auto_probe = efuse_auto_probe,
	.erase_check = default_flash_blank_check,
	.protect_check = mxs40_protect_check,
	.info = psoc6_get_info,
	.free_driver_priv = default_flash_free_driver_priv,
};

struct flash_driver traveo2_flash = {
	.name = "traveo2",
	.commands = psoc6_command_handlers,
	.flash_bank_command = psoc6_flash_bank_command,
	.erase = psoc6_erase,
	.protect = dummy_protect,
	.write = psoc6_program,
	.read = traveo2_flash_read,
	.probe = mxs40_probe,
	.auto_probe = mxs40_auto_probe,
	.erase_check = default_flash_blank_check,
	.protect_check = mxs40_protect_check,
	.info = psoc6_get_info,
	.free_driver_priv = default_flash_free_driver_priv,
};
#endif
