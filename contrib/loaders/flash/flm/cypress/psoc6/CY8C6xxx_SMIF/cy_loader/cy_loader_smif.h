/***************************************************************************//**
* \file cy_loader_smif.c
* \version 1.0
*
* \brief
*  Provides an API declaration for SMIF loader.
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_LOADER_SMIF_H)
#define CY_LOADER_SMIF_H

#include "../cy_common/build.h"

#if defined (BUILD_ENABLE_LOADER_SMIF)

#include "../cy_common/cy_common.h"
#include "../cy_common/cy_target.h"
#include "../cy_debug/cy_debug.h"
#include "../cy_smif/cy_smif.h"
#include "../cy_smif/cy_smif_memslot.h"
#include "../device_header.h"

/* extern "C" */
#ifdef __cplusplus
extern "C" {
#endif

#define SMIF0_BASE                  0x40420000UL /* Base address of SMIF IP block#0 */
#define SILICON_REV                 (1)          /* 0 for ** and 1 for *A */

/* For P6** */
#if (SILICON_REV == 0)
    #define SMIF_CONF_TABLE_OFFS_IN_TOC (0x38u)     /* Offset in TOC for SMIF Configuration Table pointer */
#else
/* For P6*A */
    #define SMIF_CONF_TABLE_OFFS_IN_TOC (0x0Cu)     /* Offset in TOC for SMIF Configuration Table pointer */
#endif

#define SMIF_MAX_SLOT_NUMBER        (4u)        /* Maximum supported slots per SMIF block */
#define SMIF_INT_MAP                (NvicMux10) /* Mapping the SMIF M4 core interrupt to
                                                 * the 10th M0+ core interrupt */
#define SMIF_INT_PRIORITY           (1u)        /* SMIF interrupt priority */
#define SMIF_DESELECT_DELAY         (7u)        /* Minimum duration of SPI de-selection */
#define SMIF_RX_CLOCK_SELECT        (1u)        /* Clock source for the receiver clock */
#define SMIF_AHB_BUS_ERROR          (0u)        /* Error that happens when there is a read
                                                 * from an empty RX FIFO or write to a full TX FIFO
                                                 */

#define SMIF_ERASE_VALUE            (0xFFu)      /* Default value after erase (all '1's for NOR & NAND flash) */
#define SMIF_EnableInt()            NVIC_EnableIRQ((uint32_t)smif_interrupt_IRQn)
#define SMIF_FIFO_THRESHOLD         (0x04u)


/*******************************************************************************
* Function Prototypes
*******************************************************************************/
result_t Loader_SMIF_LoadStructFromFlash(bool forceUpdate);
result_t Loader_SMIF_Erase(uint32_t block_addr, uint32_t block_size);
result_t Loader_SMIF_Program(uint32_t blockAddr, uint32_t offsetInBlock, uint8_t *buffer, uint32_t size);
result_t Loader_SMIF_Verify(uint32_t blockAddr, uint32_t blockSize, uint8_t *buffer, uint32_t *lastVerifiedAddr);
result_t Loader_SMIF_IsMemoryFilled(uint32_t blockAddr, uint32_t blockSize, uint8_t value);
result_t Loader_SMIF_Init_XIP(uint32_t blockAddr);
result_t Loader_SMIF_Deinit(void);
result_t Loader_SMIF_FindSecondDevice(cy_stc_smif_mem_config_t **smifMemConfig, uint32_t dualChMask);


/******************************************************************************
 * Functions results processing
 ******************************************************************************/
typedef uint32_t result_smif_t;


/******************************************************************************
 * Timeouts
 ******************************************************************************/
                                        /* Absolute maximum values
                                         * value = SMIF_POLLING_DELAY * *_timeout
                                         * SMIF_POLLING_DELAY is in uS             */
#define SMIF_DRIVER_TIMEOUT    (1000ul) /* Timeout for all blocking SMIF functions */
#define SMIF_ERASE_TIMEOUT     (50000u) /* Timeout for SMIF Erase operation        */
#define SMIF_PROGRAM_TIMEOUT   (50000u) /* Timeout for SMIF Program operation      */
#define SMIF_POLLING_DELAY     (100u)   /* SMIF IP block status polling delay      */

/* extern "C" */
#ifdef __cplusplus
}
#endif

#endif /* BUILD_ENABLE_LOADER_SMIF */

#endif /* CY_LOADER_SMIF_H */

/* [] END OF FILE */
