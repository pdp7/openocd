/***************************************************************************//**
* \file cy_loader_flash.h
* \version 1.0
*
* \brief
*  Provides an API declaration for flash loader.
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_LOADER_FLASH_H)
#define CY_LOADER_FLASH_H

#include "../cy_common/build.h"

#if defined (BUILD_ENABLE_LOADER_FLASH)

#include "../cy_common/cy_common.h"
#include "../cy_common/cy_target.h"
#include "../cy_srom/cy_srom.h"

/* extern "C" */
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {PRG_API_PROGRAM_ROW, PRG_API_WRITE_ROW} prg_api_t;

result_t Loader_Flash_Erase(uint32_t block_addr, uint32_t block_size);
result_t Loader_Flash_Program(uint32_t block_addr, uint32_t offset_in_block, uint8_t *buffer, uint32_t size, prg_api_t prg_api);
result_t Loader_Flash_Verify(uint32_t addr, uint32_t size, uint8_t *buffer, uint32_t *lastVerifiedAddr);
result_t Loader_Flash_IsMemoryFilled(uint32_t blockAddr, uint32_t blockSize, uint8_t value);

/* extern "C" */
#ifdef __cplusplus
}
#endif

#endif /* BUILD_ENABLE_LOADER_FLASH */

#endif /* CY_LOADER_FLASH_H */

/* [] END OF FILE */
