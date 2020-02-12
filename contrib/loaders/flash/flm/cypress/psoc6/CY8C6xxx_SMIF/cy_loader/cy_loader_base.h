/*******************************************************************************
* \file cy_loader_base.h
* \version 1.0
*
* \brief
*  Provides base flash loaders API declaration.
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_LOADER_BASE_H)
#define CY_LOADER_BASE_H

#include "../cy_common/build.h"
#include "../cy_common/cy_common.h"
#include "../cy_common/cy_target.h"
#include "../cy_debug/cy_debug.h"
#include "cy_loader_flash.h"
#include "cy_loader_smif.h"

/* extern "C" */
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {MEM_TYPE_FLASH, MEM_TYPE_SMIF, MEM_TYPE_UNKNOWN} mem_type_t;

mem_type_t Loader_GetMemType(uint32_t addr);
result_t Loader_Erase(uint32_t block_addr, uint32_t block_size);
result_t Loader_Program(uint32_t block_addr, uint32_t offset_in_block, uint8_t *buffer, uint32_t size);
result_t Loader_Verify(uint32_t addr, uint32_t size, uint8_t *buffer, uint32_t *lastVerifiedAddr);
result_t Loader_IsMemoryFilled(uint32_t blockAddr, uint32_t blockSize, uint8_t value);
result_t Loader_Init(uint32_t blockAddr);
result_t Loader_UnInit(uint32_t func);
uint32_t Loader_Checksum(uint32_t address, uint32_t size, uint32_t *checksum);

/* extern "C" */
#ifdef __cplusplus
}
#endif

#endif /*CY_LOADER_BASE_H1*/

/* [] END OF FILE */
