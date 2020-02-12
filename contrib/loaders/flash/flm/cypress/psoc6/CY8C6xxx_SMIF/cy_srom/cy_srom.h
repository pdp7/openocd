/*******************************************************************************
* \file cy_srom.h
* \version 1.0
*
* \brief
*  Defines MXS40 SROM APIs
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SROM_H)
#define CY_SROM_H

#include "../cy_common/build.h"

#if defined(BUILD_ENABLE_LOADER_FLASH)

#include "../cy_common/cy_common.h"
#include "../cy_common/cy_target.h"
#include "../cy_debug/cy_debug.h"
#include "../device_header.h"

/* extern "C" */
#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
* SROM APIs
*******************************************************************************/
/** [0]: 1 - arguments are passed in IPC.DATA. 0 - arguments are passed in SRAM */
#define SROMAPI_DATA_LOCATION_MSK     (0x00000001UL)
/**  Status Code: 4 bits [31:28] of the data register */
#define SROMAPI_STATUS_MSK            (0xF0000000UL)
/** Status Code = 0xA */
#define SROMAPI_STAT_SUCCESS          (0xA0000000UL)
#define SROMAPI_WRITEROW_CODE         (0x05000100UL)
#define SROMAPI_PROGRAMROW_CODE       (0x06000100UL)
#define SROMAPI_ERASESECTOR_CODE      (0x14000100UL)
#define SROMAPI_ERASEROW_CODE         (0x1C000100UL)
 /**  Test vectors can keep SRAM variables before 0x08001000 address */
#define SROMAPI_SRAM_SCRATCH_ADDR     (TARGET_SRAM0_ADDR + 0x1000UL)

/*******************************************************************************
* Functions
*******************************************************************************/

result_t Ipc_PollLockStatus(char ipcId, bool lockExpected, int timeoutAttempts);
result_t Ipc_Acquire(char ipcId, int timeoutAttempts);
result_t PollSromApiStatus(uint32_t address, int timeoutAttempts, uint32_t *dataOut);
result_t CallSromApi(uint32_t callIdAndParams, uint32_t *dataOut);
result_t SromApiEraseRow(uint32_t addr);
result_t SromApiEraseSector(uint32_t addr);
result_t SromApiProgramRow(uint32_t addr, char const *data);
result_t SromApiWriteRow(uint32_t addr, char const *data);


/* extern "C" */
#ifdef __cplusplus
}
#endif

#endif /* BUILD_ENABLE_LOADER_FLASH */

#endif /*CY_SROM_H*/
