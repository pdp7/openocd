/***************************************************************************//**
* \file cy_target.h
* \version 1.0
*
* \brief
*  Provides an memory declarations for MXS40 platform.
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TARGET_H)
#define CY_TARGET_H

#include "../cy_common/build.h"

/* extern "C" */
#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
* Base addresses
*******************************************************************************/
//- MXS40 Top Level Device Address Map -------------------------------------------------------
// Offset	 | Size		  | Qty | Width |	Name	| Description
//--------------------------------------------------------------------------------------------
// 0x00000000 | 0x00020000 | 1	 | 32    | ROM		| 128kB ROM (Boot, Test,SmartWrite)
// 0x08000000 | 0x00040000 | 1   | 32    | SRAM0	| 256kB System RAM
// 0x10000000 | 0x00100000 | 1   | 32    | FLASH	| 1024kB FLASH Main Region
// 0x14000000 | 0x00008000 | 1   | 32    | WFLASH	| 32kB FLASH Work Region
// 0x16000000 | 0x00008000 | 1   |       | SFLASH	| FLASH Supervisory Region
// 0x18000000 | 0x08000000 | 1   | 32    | XIP		| External memory execute-in-place region
// 0x40000000 | 0x01000000 | 1   |       | MMIO		| Peripheral Interconnect
// 0xE0000000 | 0x20000000 | 1   |       | SYSTEM	| ARM System Space (CPU & Debug Registers)
//--------------------------------------------------------------------------------------------

#define TARGET_ROM_ADDR          (0x00000000UL) /* 128kB ROM (Boot, Test,SmartWrite) */
#define TARGET_SRAM0_ADDR        (0x08000000UL) /* 256kB System RAM */
#define TARGET_FLASH_ADDR        (0x10000000UL) /* 1024kB FLASH Main Region */
#define TARGET_WFLASH_ADDR       (0x14000000UL) /* 32kB FLASH Work Region */
#define TARGET_SFLASH_ADDR       (0x16000000UL) /* FLASH Supervisory Region */
#define TARGET_XIP_ADDR          (0x18000000UL) /* External memory execute-in-place region */
#define TARGET_XIP_SIZE          (0x08000000UL) /* Size of execute-in-place region */
#define TARGET_MMIO_ADDR         (0x40000000UL) /* Peripheral Interconnect */
#define TARGET_MMIO2_ADDR        (TARGET_MMIO_ADDR + 0x200000UL) /* 0x40200000: Core platform peripherals */
#define TARGET_SYSTEM_ADDR       (0xE0000000UL) /* ARM System Space (CPU & Debug Registers) */

#define TARGET_FLASH_ROW_SIZE    (0x200u)    /* Internal Flash row size: 512 bytes */
#define TARGET_FLASH_SECTOR_SIZE (0x40000UL) /* Internal Flash sector size: 256 kB. */
                                             /* Sectors: 0x1000_0000, 0x1004_0000, 0x1008_0000 and 0x100C_0000 */
#define TARGET_FLASH_ERASE_VAL   (0x00u)     /* Initial content of erased memory*/
#define TARGET_TOC_ROW					 (62u)
#define TARGET_TOC_OFFSET        (TARGET_TOC_ROW * TARGET_FLASH_ROW_SIZE)

/*******************************************************************************
* Target - specific configuration
*******************************************************************************/

#if defined BUILD_TARGET_CY8C6x6_M0
#define TARGET_FAMILY_NAME "CY8C6x6"
#define TARGET_FLASH_SIZE  (0x00080000UL) /** 512kB */

#elif defined BUILD_TARGET_CY8C6x6_M4
#define TARGET_FAMILY_NAME "CY8C6x6"
#define TARGET_FLASH_SIZE (0x00080000UL) /** 512kB */

#elif defined BUILD_TARGET_CY8C6x7_M0
#define TARGET_FAMILY_NAME "CY8C6x7"
#define TARGET_FLASH_SIZE (0x00100000UL) /** 1024kB */

#elif defined BUILD_TARGET_CY8C6x7_M4
#define TARGET_FAMILY_NAME "CY8C6x7"
#define TARGET_FLASH_SIZE (0x00100000UL) /** 1024kB */

#elif defined BUILD_TARGET_CY8C622PSVP_M0
#define TARGET_FAMILY_NAME "CY8C622PSVP"
#define TARGET_FLASH_SIZE (0x00100000UL) /** 1024kB */

#elif defined BUILD_TARGET_CY8C622PSVP_M4
#define TARGET_FAMILY_NAME "CY8C622PSVP"
#define TARGET_FLASH_SIZE (0x00100000UL) /** 1024kB */

#elif defined BUILD_TARGET_SMIF
#define TARGET_FAMILY_NAME "CY8C6_SMIF"
//#define TARGET_FLASH_SIZE (0x08000000UL) /** 128MB */
#define TARGET_FLASH_SIZE (0x00100000UL) /** 1024kB */ /* Need for TOC Addr calculation */

#else
#error "Flash Device is not defined."
#endif

/* TOC (Table Of Contents): Last row in internal Flash */
/* for P6**
#define TARGET_TOC_ADDR (TARGET_FLASH_ADDR + TARGET_FLASH_SIZE - TARGET_FLASH_ROW_SIZE)*/
/* for P6*A */
#define TARGET_TOC_ADDR (TARGET_SFLASH_ADDR + TARGET_TOC_OFFSET)

/*******************************************************************************
* IPC definitions
*******************************************************************************/
#define MXS40_IPC_SIZE             (0x20u)
#define MXS40_IPC_ADDR             (TARGET_MMIO2_ADDR + 0x30000UL) /* 0x40230000: Base address for IPC structs */
#define MXS40_IPC0_ADDR            (MXS40_IPC_ADDR) /* 0x40230000: CM0+ IPC_STRUCT absolute address */
#define MXS40_IPC_CM0_ADDR         (MXS40_IPC0_ADDR)
#define MXS40_IPC1_ADDR            (MXS40_IPC0_ADDR + MXS40_IPC_SIZE) /* 0x40230020: CM4 IPC_STRUCT absolute address */
#define MXS40_IPC_CM4_ADDR         (MXS40_IPC1_ADDR)
#define MXS40_IPC2_ADDR            (MXS40_IPC1_ADDR + MXS40_IPC_SIZE) /* 0x40230040: DAP IPC_STRUCT absolute address */
#define MXS40_IPC_DAP_ADDR         (TARGET_ADDR_IPC2)
#define MXS40_IPC_INTR_ADDR        (TARGET_MMIO2_ADDR + 0x31000UL) /* 0x40231000: Base address for IPC_INTR struct */

/** This register is used to acquire a lock. This register is NOT SW writable. */
#define MXS40_IPC_ACQUIRE_OFFS     (0x00u)
/** This field allows for the generation of notification events to the IPC interrupt structures */
#define MXS40_IPC_NOTIFY_OFFS      (0x08u)
/** This field holds a 32-bit data element that is associated with the IPC structure. */
#define MXS40_IPC_DATA_OFFS        (0x0Cu)
/** IPC lock status */
#define MXS40_IPC_LOCK_STATUS_OFFS (0x10u)
/** IPC interrupt mask */
#define MXS40_IPC_INTR_IPC_MASK_OFFS  (0x08u)
/** Specifies if the lock is successfully acquired or not: '0': Not successfully acquired, '1': Successfully acquired.*/
#define MXS40_IPC_ACQUIRE_SUCCESS_MSK      (0x80000000UL)
/** Specifies if the lock is acquired */
#define MXS40_IPC_LOCK_STATUS_ACQUIRED_MSK (0x80000000UL)

/*******************************************************************************
* Timeouts
*******************************************************************************/
#define TIMEOUT_IPC_ACQUIRE (250u)
#define TIMEOUT_IPC_DATA    (250u)

/* extern "C" */
#ifdef __cplusplus
}
#endif

#endif /*CY_TARGET_H*/

/* [] END OF FILE */
