///************************************************************************/
///*                                                                      */
///*  DefineMSX40.h                                                    */
///*  Defines for PSOC 6 series            																*/
///*  Version V0.1                                                        */
///*  Date    2016-10-10                                                  */
///*                                                                      */
///************************************************************************/

///*******************************************************************************
//* Copyright (C) 2016, Cypress Semiconductor Corporation or a                   *
//* subsidiary of Cypress Semiconductor Corporation.  All rights reserved.       *
//*                                                                              *
//* This software, including source code, documentation and related              *
//* materials ("Software"), is owned by Cypress Semiconductor Corporation or     *
//* one of its subsidiaries ("Cypress") and is protected by and subject to       *
//* worldwide patent protection (United States and foreign), United States       *
//* copyright laws and international treaty provisions. Therefore, you may use   *
//* this Software only as provided in the license agreement accompanying the     *
//* software package from which you obtained this Software ("EULA").             *
//*                                                                              *
//* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,     *
//* non-transferable license to copy, modify, and compile the                    *
//* Software source code solely for use in connection with Cypress's             *
//* integrated circuit products.  Any reproduction, modification, translation,   *
//* compilation, or representation of this Software except as specified          *
//* above is prohibited without the express written permission of Cypress.       *
//*                                                                              *
//* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO                         *
//* WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING,                         *
//* BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED                                 *
//* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A                              *
//* PARTICULAR PURPOSE. Cypress reserves the right to make                       *
//* changes to the Software without notice. Cypress does not assume any          *
//* liability arising out of the application or use of the Software or any       *
//* product or circuit described in the Software. Cypress does not               *
//* authorize its products for use in any products where a malfunction or        *
//* failure of the Cypress product may reasonably be expected to result in       *
//* significant property damage, injury or death ("High Risk Product"). By       *
//* including Cypress's product in a High Risk Product, the manufacturer         *
//* of such system or application assumes all risk of such use and in doing      *
//* so agrees to indemnify Cypress against all liability.                        *
//*******************************************************************************/
//#ifndef _DEFINE_MSX40_H_
//#define _DEFINE_MSX40_H_

///*------------------------------------------------------------------------------
//Base addresses
//-------------------------------------------------------------------------------*/
///* 288kB System RAM*/
//#define MEM_BASE_SRAM0	 												0x08000000
///* 32kB Work Flash */
//#define MEM_BASE_WFLASH	 												0x14000000
///* Peripheral Interconnect*/
//#define MEM_BASE_MMIO	 													0x40000000
///* 0x40200000: Core platform peripherals */
//#define MEM_BASE_MMIO2													MEM_BASE_MMIO + 0x200000
///* 0x40230000: Base address for IPC structs*/
//#define MEM_BASE_IPC	 													MEM_BASE_MMIO2 + 0x30000
///* 0x40231000: Base address for IPC_INTR struct*/
//#define MEM_BASE_IPCINTR 												MEM_BASE_MMIO2 + 0x31000

//#define MEM_SIZE_WFLASH	 												0x8000 /* 32kB of Work Flash Region */

///*------------------------------------------------------------------------------
//IPC and Structures definitions
//------------------------------------------------------------------------------
//Addresses for IPC_STRUCT and IPC_INTR_STRUCT*/
//#define IPC_STRUCT_SIZE		      								0x20
///*0x40230000: CM0+ IPC_STRUCT absolute address*/
//#define IPC_STRUCT0		        									MEM_BASE_IPC
///* 0x40230020: CM4 IPC_STRUCT absolute address*/
//#define IPC_STRUCT1		        									IPC_STRUCT0 + IPC_STRUCT_SIZE
///*0x40231000: IPC_INTR struct absolute address*/
//#define IPC_INTR_STRUCT               					MEM_BASE_IPCINTR

///* Registers offsets in IPC_STRUCT[x]
//This register is used to acquire a lock. This register is NOT SW writable.*/
//#define IPC_STRUCT_ACQUIRE_OFFSET								0x00

///* This field allows for the generation of notification events to the IPC
//interrupt structures.*/
//#define IPC_STRUCT_NOTIFY_OFFSET								0x08
///*This field holds a 32-bit data element that is associated with the IPC structure.*/
//#define IPC_STRUCT_DATA_OFFSET									0x0C
///* IPC lock status*/
//#define IPC_STRUCT_LOCK_STATUS_OFFSET						0x10

///* Registers offsets in IPC_INTR_STRUCT
//IPC interrupt mask*/
//#define IPC_INTR_STRUCT_INTR_IPC_MASK_OFFSET		0x08

///*Masks for IPC_STRUCT[x] registers
//Specifies if the lock is successfully acquired or not: '0': Not successfully
//acquired, '1': Successfully acquired.*/
//#define IPC_STRUCT_ACQUIRE_SUCCESS_MSK	        0x80000000
///*Specifies if the lock is acquired.*/
//#define IPC_STRUCT_LOCK_STATUS_ACQUIRED_MSK     0x80000000

///* Misc
//Timeout attempts of IPC_STRUCT acuire
//Timeout attempts of IPC_STRUCT data*/
//#define IPC_STRUCT_ACQUIRE_TIMEOUT_ATTEMPTS			250
//#define IPC_STRUCT_DATA_TIMEOUT_ATTEMPTS        250

///*
//--------------------------------------------------------------------------------------------
// SROM APIs
//--------------------------------------------------------------------------------------------
// SROM APIs masks
// [0]: 1 - arguments are passed in IPC.DATA. 0 - arguments are passed in SRAM*/
//#define MXS40_SROMAPI_DATA_LOCATION_MSK	        0x00000001
///* Status Code: 4 bits [31:28] of the data register*/
//#define MXS40_SROMAPI_STATUS_MSK	        			0xF0000000
///* Status Code = 0xA*/
//#define MXS40_SROMAPI_STAT_SUCCESS	        		0xA0000000
///* [31:24]: Opcode = 0x06; [0]: 0 - arguments are passed in SRAM*/
//#define MXS40_SROMAPI_PROGRAMROW_CODE	      		0x06000100
///* [31:24]: Opcode = 0x0A; [0]: 0 - arguments are passed in SRAM*/
//#define MXS40_SROMAPI_ERASEALL_CODE             0x0A000100
///* [31:24]: Opcode = 0x14; [0]: 0 - arguments are passed in SRAM*/
//#define MXS40_SROMAPI_ERASESECTOR_CODE	        0x14000100
///* [31:24]: Opcode = 0x1D; [0]: 0 - arguments are passed in SRAM*/
//#define MXS40_SROMAPI_ERASESUBSECTOR_CODE	        0x14000100
///* [31:24]: Opcode = 0x1C; [0]: 0 - arguments are passed in SRAM*/
//#define MXS40_SROMAPI_ERASEROW_CODE							0x1C000100

///* Offset for data location/size and Integrity check*/
//#define DATA_LOCATION_OFFSET		        				0x04

///* Property for data location/size and Integrity check*/
//#define DATA_LOCATION_PROPERTY		        			0x106

///* Offset for flash address which will be programed*/
//#define FLASH_ADDRESS_OFFSET		        				0x08

///* Offset for first data byte in SRAM*/
//#define DATA_OFFSET		                					0x10

///* Offset for set pointer to the first data byte location*/
//#define POINTER_ON_FIRST_BYTE_LOCATION_OFFSET   0x0C

///* Buffer for SRAM APIs parameters */
//#define BUFFER_SIZE_SRAM_SCRATCH							DATA_OFFSET + ROW_SIZE + 4
///* Required for J-Link to not overlap with stack.
// * This is because J-Link sets SP close to loader's code,
// * but, except stack usage by loader itself, SROM APIs also requires up to 900 Bytes of steck */
//#define BUFFER_SIZE_EXTRA_STACK 							1024

///* Misc  */
//#define ROW_SIZE 																512
//#define TARGET_FLASH_SIZE 											0x00100000

//#define RESULT_OK 															0
//#define RESULT_ERROR 														1

///*Delay = 1ms, measured by scope*/
//#define DELAY_1MS_PSOC6													3333

///*******************************************************************************
//* Base addresses
//*******************************************************************************/
////- MXS40 Top Level Device Address Map -------------------------------------------------------
//// Offset	 | Size		  | Qty | Width |	Name	| Description
////--------------------------------------------------------------------------------------------
//// 0x00000000 | 0x00020000 | 1	 | 32    | ROM		| 128kB ROM (Boot, Test,SmartWrite)
//// 0x08000000 | 0x00040000 | 1   | 32    | SRAM0	| 256kB System RAM
//// 0x10000000 | 0x00100000 | 1   | 32    | FLASH	| 1024kB FLASH Main Region
//// 0x14000000 | 0x00008000 | 1   | 32    | WFLASH	| 32kB FLASH Work Region
//// 0x16000000 | 0x00008000 | 1   |       | SFLASH	| FLASH Supervisory Region
//// 0x18000000 | 0x08000000 | 1   | 32    | XIP		| External memory execute-in-place region
//// 0x40000000 | 0x01000000 | 1   |       | MMIO		| Peripheral Interconnect
//// 0xE0000000 | 0x20000000 | 1   |       | SYSTEM	| ARM System Space (CPU & Debug Registers)
////--------------------------------------------------------------------------------------------

//#define TARGET_ROM_ADDR          (0x00000000UL) /* 128kB ROM (Boot, Test,SmartWrite) */
//#define TARGET_SRAM0_ADDR        (0x08000000UL) /* 256kB System RAM */
//#define TARGET_FLASH_ADDR        (0x10000000UL) /* 1024kB FLASH Main Region */
//#define TARGET_WFLASH_ADDR       (0x14000000UL) /* 32kB FLASH Work Region */
//#define TARGET_SFLASH_ADDR       (0x16000000UL) /* FLASH Supervisory Region */
//#define TARGET_XIP_ADDR          (0x18000000UL) /* External memory execute-in-place region */
//#define TARGET_XIP_SIZE          (0x08000000UL) /* Size of execute-in-place region */
//#define TARGET_MMIO_ADDR         (0x40000000UL) /* Peripheral Interconnect */
//#define TARGET_MMIO2_ADDR        (TARGET_MMIO_ADDR + 0x200000UL) /* 0x40200000: Core platform peripherals */
//#define TARGET_SYSTEM_ADDR       (0xE0000000UL) /* ARM System Space (CPU & Debug Registers) */

//                                             /* Sectors: 0x1000_0000, 0x1004_0000, 0x1008_0000 and 0x100C_0000 */
//#define TARGET_FLASH_ERASE_VAL   (0x00u)     /* Initial content of erased memory*/

//#define SUCCEEDED(result) ((result) == (RESULT_OK))

///******************************************************************************
// * Attributes
// ******************************************************************************/
//#define CY_USED __attribute__((used))
//#if defined(__ARMCC_VERSION) || defined(__GNUC__) || defined(__ARMCC_VERSION)
//    #define CY_SECTION(name)    __attribute__ ((section(name)))
//#elif defined (__ICCARM__)
//    #define CY_SECTION(name)    CY_PRAGMA(section = name)
//#else
//    #error Unsupported toolchain
//#endif  /* (__ARMCC_VERSION) */

//#endif /* _DEFINE_MSX40_H_ */
