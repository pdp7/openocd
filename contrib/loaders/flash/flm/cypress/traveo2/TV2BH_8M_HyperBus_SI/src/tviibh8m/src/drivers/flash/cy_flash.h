/***************************************************************************//**
* \file cy_flash.h
* \version 1.0
*
* Provides the API declarations of the Flash driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_FLASH_H)
#define CY_FLASH_H

/**
* \defgroup group_flash Flash System Routine (Flash)
* \{
* Internal flash memory programming
*
* Flash memory in PSoC devices provides non-volatile storage for user firmware,
* user configuration data, and bulk data storage.
*
* Flash operations are implemented as system calls. System calls are executed
* out of SROM in the privileged mode of operation. Users have no access to read
* or modify the SROM code. The driver API requests the system call by acquiring
* the Inter-processor communication (IPC) and writing the SROM function opcode
* and parameters to its input registers. As a result, an NMI interrupt is invoked
* and the requested SROM API is executed. The operation status is returned to the
* driver context and a release interrupt is triggered.
*
* Writing to flash can take up to 20 milliseconds. During this time,
* the device should not be reset (including XRES pin, software  reset, and
* watchdog) or unexpected changes may be made to portions of the flash.
* Also, the low-voltage detect circuits should be configured to generate an
* interrupt instead of a reset.
*
* The Read while Write violation occurs when the flash Read operation is initiated
* in the same flash sector where the flash Write operation is performing. The
* violation leads to the exception generation. To avoid the Read while Write
* violation, the user has to carefully split the Read and Write operation from the
* same flash sector considering both cores in the multi-processor device.
* Use different flash sectors for code and data storage. The flash is divided
* into four equal sectors.
*
* \section group_flash_configuration Configuration Considerations
*
* Note that to be able to perform FLASH writes, the VCCD should be more than 0.99 V.
* For more information see the technical reference manual (TRM).
*
* \section group_flash_more_information More Information
*
* See the technical reference manual (TRM) for more information about the Flash architecture.
*
*
* \section group_flash_changelog Changelog
*
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_flash_macro Macro
* \defgroup group_flash_functions Functions
* \defgroup group_flash_data_structure Data Structures
*/

#include <cy_device_headers.h>
#include <stddef.h>
#include <ipc/cy_ipc_drv.h>
#include <syslib/cy_syslib.h>

/***************************************
* Macro definitions
***************************************/
/**
* \addtogroup group_flash_macro
* \{
*/

/** Driver major version */
#define CY_FLASH_DRV_VERSION_MAJOR       1

/** Driver minor version */
#define CY_FLASH_DRV_VERSION_MINOR       0


/**
* \defgroup group_flash_returns  Flash return values
* \{
* Specifies return values meaning
*/
#define CY_FLASH_ID                        (CY_PDL_DRV_ID(0x14u))  /**< FLASH PDL ID */

#define CY_FLASH_ID_INFO    (uint32_t)( CY_FLASH_ID | CY_PDL_STATUS_INFO )   /**< Return prefix for FLASH driver function status codes */
#define CY_FLASH_ID_WARNING (uint32_t)( CY_FLASH_ID | CY_PDL_STATUS_WARNING) /**< Return prefix for FLASH driver function warning return values */
#define CY_FLASH_ID_ERROR   (uint32_t)( CY_FLASH_ID | CY_PDL_STATUS_ERROR)   /**< Return prefix for FLASH driver function error return values */

typedef enum
{
    CY_FLASH_IN_BOUNDS,
    CY_FLASH_OUT_OF_BOUNDS,
} en_flash_bounds_t;

#define CY_WFLASH_LG_SBM_TOP  CY_WFLASH_LG_SBM_BASE
#define CY_WFLASH_LG_SBM_END  (CY_WFLASH_LG_SBM_BASE + CY_WFLASH_LG_SBM_SIZE)

#define CY_WFLASH_SM_SBM_TOP  CY_WFLASH_SM_SBM_BASE
#define CY_WFLASH_SM_SBM_END  (CY_WFLASH_SM_SBM_BASE + CY_WFLASH_SM_SBM_SIZE)

#define CY_WFLASH_LG_DBM0_TOP CY_WFLASH_LG_DBM0_BASE
#define CY_WFLASH_LG_DBM0_END (CY_WFLASH_LG_DBM0_BASE + CY_WFLASH_LG_DBM0_SIZE)

#define CY_WFLASH_SM_DBM0_TOP CY_WFLASH_SM_DBM0_BASE
#define CY_WFLASH_SM_DBM0_END (CY_WFLASH_SM_DBM0_BASE + CY_WFLASH_SM_DBM0_SIZE)

#define CY_WFLASH_LG_DBM1_TOP CY_WFLASH_LG_DBM1_BASE
#define CY_WFLASH_LG_DBM1_END (CY_WFLASH_LG_DBM1_BASE + CY_WFLASH_LG_DBM1_SIZE)

#define CY_WFLASH_SM_DBM1_TOP CY_WFLASH_SM_DBM1_BASE
#define CY_WFLASH_SM_DBM1_END (CY_WFLASH_SM_DBM1_BASE + CY_WFLASH_SM_DBM1_SIZE)

#define CY_FLASH_LG_SBM_TOP  CY_FLASH_LG_SBM_BASE
#define CY_FLASH_LG_SBM_END  (CY_FLASH_LG_SBM_BASE + CY_FLASH_LG_SBM_SIZE)

#define CY_FLASH_SM_SBM_TOP  CY_FLASH_SM_SBM_BASE
#define CY_FLASH_SM_SBM_END  (CY_FLASH_SM_SBM_BASE + CY_FLASH_SM_SBM_SIZE)

#define CY_FLASH_LG_DBM0_TOP CY_FLASH_LG_DBM0_BASE
#define CY_FLASH_LG_DBM0_END (CY_FLASH_LG_DBM0_BASE + CY_FLASH_LG_DBM0_SIZE)

#define CY_FLASH_SM_DBM0_TOP CY_FLASH_SM_DBM0_BASE
#define CY_FLASH_SM_DBM0_END (CY_FLASH_SM_DBM0_BASE + CY_FLASH_SM_DBM0_SIZE)

#define CY_FLASH_LG_DBM1_TOP CY_FLASH_LG_DBM1_BASE
#define CY_FLASH_LG_DBM1_END (CY_FLASH_LG_DBM1_BASE + CY_FLASH_LG_DBM1_SIZE)

#define CY_FLASH_SM_DBM1_TOP CY_FLASH_SM_DBM1_BASE
#define CY_FLASH_SM_DBM1_END (CY_FLASH_SM_DBM1_BASE + CY_FLASH_SM_DBM1_SIZE)

#define CY_SFLASH_TOP  CY_SFLASH_BASE
#define CY_SFLASH_END  (CY_SFLASH_BASE + CY_SFLASH_SIZE)

#define CY_SFLASH1_TOP CY_SFLASH1_BASE
#define CY_SFLASH1_END (CY_SFLASH1_BASE + CY_SFLASH1_SIZE)


/** This enum has the return values of the Flash driver */
typedef enum 
{
    CY_FLASH_DRV_SUCCESS                  =   0x00ul,  /**< Success */
    CY_FLASH_DRV_INV_PROT                 =   ( CY_FLASH_ID_ERROR + 0x00ul),  /**< Invalid device protection state (SROM STATUS CODE: 0xF0000001) */
    CY_FLASH_DRV_INVALID_FM_PL            =   ( CY_FLASH_ID_ERROR + 0x01ul),  /**< Invalid flash page latch address (SROM STATUS CODE: 0xF0000003) */
    CY_FLASH_DRV_INVALID_FLASH_ADDR       =   ( CY_FLASH_ID_ERROR + 0x02ul),  /**< Invalid flash address (SROM STATUS CODE: 0xF0000004) */
    CY_FLASH_DRV_ROW_PROTECTED            =   ( CY_FLASH_ID_ERROR + 0x03ul),  /**< Row is write protected (SROM STATUS CODE: 0xF0000005) */
    CY_FLASH_DRV_IPC_BUSY                 =   ( CY_FLASH_ID_ERROR + 0x04ul),  /**< IPC structure is already locked by another process  (SROM STATUS CODE: 0xF0000006) */
    CY_FLASH_DRV_CHECKSUM_NON_ZERO        =   ( CY_FLASH_ID_ERROR + 0x05ul),  /**< Checksum of FLASH resulted in non-zero (SROM STATUS CODE: 0xF000000A) */
    CY_FLASH_DRV_SECTOR_SUSPEND           =   ( CY_FLASH_ID_ERROR + 0x06ul),  /**< Returned when Program operation is called on sector which is suspended from erase (SROM STATUS CODE: 0xF0000091) */
    CY_FLASH_DRV_NO_ERASE_SUSPEND         =   ( CY_FLASH_ID_ERROR + 0x07ul),  /**< Returned when EraseResume is called when no sector is suspended from erase (SROM STATUS CODE: 0xF0000092) */
    CY_FLASH_DRV_FLASH_NOT_ERASED         =   ( CY_FLASH_ID_ERROR + 0x08ul),  /**< Returned when ProgramRow is invoked on unerased cells or blank check fails (SROM STATUS CODE: 0xF00000A4) */
    CY_FLASH_DRV_NO_ERASE_ONGOING         =   ( CY_FLASH_ID_ERROR + 0x09ul),  /**< Returned by EraseSuspend when called with no ongoing erase operation (SROM STATUS CODE: 0xF00000A5) */
    CY_FLASH_DRV_ACTIVE_ERASE             =   ( CY_FLASH_ID_ERROR + 0x0Aul),  /**< Returned by ProgramRow when active erase operation is going on (SROM STATUS CODE: 0xF00000A6) */
    CY_FLASH_DRV_INVALID_DATA_WIDTH       =   ( CY_FLASH_ID_ERROR + 0x0Bul),  /**< Returned by ProgramRow API if invalid program width option is provided (SROM STATUS CODE: 0xF00000A8) */
    CY_FLASH_DRV_FLASH_SAFTEY_ENABLED     =   ( CY_FLASH_ID_ERROR + 0x0Cul),  /**< Returned by FLASH program/erase APIs when writes are disabled in safety register (SROM STATUS CODE: 0xF00000AA) */
    CY_FLASH_DRV_INVALID_SFLASH_ADDR      =   ( CY_FLASH_ID_ERROR + 0x0Dul),  /**< Returned when WriteRow is called on invalid SFLASH rows in NORMAL state (SROM STATUS CODE: 0xF00000B2) */
    CY_FLASH_DRV_SFLASH_BACKUP_ERASED     =   ( CY_FLASH_ID_ERROR + 0x0Eul),  /**< Returned by Sflash programming APIs when backup sector is in erased state (SROM STATUS CODE: 0xF00000BB) */
    CY_FLASH_DRV_INVALID_INPUT_PARAMETERS =   ( CY_FLASH_ID_ERROR + 0x0Ful),  /**< Input parameters passed to Flash API are not valid */
    CY_FLASH_DRV_ERR_UNC                  =   ( CY_FLASH_ID_ERROR + 0xFFul),/**< Unknown error */
    CY_FLASH_DRV_PROGRESS_NO_ERROR        =   ( CY_FLASH_ID_INFO  + 0ul),  /**< Command in progress; no error */
    CY_FLASH_DRV_OPERATION_STARTED        =   ( CY_FLASH_ID_INFO  + 1ul),  /**< Flash operation is successfully initiated */
    CY_FLASH_DRV_OPCODE_BUSY              =   ( CY_FLASH_ID_INFO  + 2ul)  /**< Flash is under operation */
} cy_en_flashdrv_status_t;

/** \} group_flash_returns */

/** \cond INTERNAL */

#define SROM_RESPONSE_IPC_INTR_STRUCT IPC_INTR_STRUCT2

/** Command completed with no errors */
#define CY_FLASH_ROMCODE_SUCCESS                  (0xA0000000UL)
/** Invalid device protection state */
#define CY_FLASH_ROMCODE_INV_PROT                 (0xF0000001UL)
/** Invalid flash page latch address */
#define CY_FLASH_ROMCODE_INVALID_FM_PL            (0xF0000003UL)
/** Invalid flash address */
#define CY_FLASH_ROMCODE_INVALID_FLASH_ADDR       (0xF0000004UL)
/** Row is write protected */
#define CY_FLASH_ROMCODE_ROW_PROTECTED            (0xF0000005UL)

/** IPC structure is already locked by another process */
#define CY_FLASH_ROMCODE_IPC_BUSY                 (0xF0000006UL)
/** Checksum of FLASH resulted in non-zero */
#define CY_FLASH_ROMCODE_CHECKSUM_NON_ZERO        (0xF000000AUL)
/** Returned when Program operation is called on sector which is suspended from erase */
#define CY_FLASH_ROMCODE_SECTOR_SUSPEND           (0xF0000091UL)
/** Returned when ProgramRow is invoked on unerased cells or blank check fails */
#define CY_FLASH_ROMCODE_NO_ERASE_SUSPEND         (0xF0000092UL)
/** Returned by EraseSuspend when called with no ongoing erase operation */
#define CY_FLASH_ROMCODE_FLASH_NOT_ERASED         (0xF00000A4UL)
/** Row is write protected */
#define CY_FLASH_ROMCODE_NO_ERASE_ONGOING         (0xF00000A5UL)
/** Row is write protected */
#define CY_FLASH_ROMCODE_ACTIVE_ERASE             (0xF00000A6UL)
/** Row is write protected */
#define CY_FLASH_ROMCODE_INVALID_DATA_WIDTH       (0xF00000A8UL)
/** Row is write protected */
#define CY_FLASH_ROMCODE_FLASH_SAFTEY_ENABLED     (0xF00000AAUL)
/** Row is write protected */
#define CY_FLASH_ROMCODE_INVALID_SFLASH_ADDR      (0xF00000B2UL)
/** Row is write protected */
#define CY_FLASH_ROMCODE_SFLASH_BACKUP_ERASED     (0xF00000BBUL)
/** Command in progress; no error */
#define CY_FLASH_ROMCODE_IN_PROGRESS_NO_ERROR      (0xA0000009UL)
/** Flash operation is successfully initiated */
#define CY_FLASH_IS_OPERATION_STARTED              (0x00000010UL)
/** Flash is under operation */
#define CY_FLASH_IS_BUSY                           (0x00000040UL)
/** IPC structure is already locked by another process */
#define CY_FLASH_IS_IPC_BUSY                       (0x00000080UL)
/** Input parameters passed to Flash API are not valid */
#define CY_FLASH_IS_INVALID_INPUT_PARAMETERS       (0x00000100UL)
/** Result mask */
#define CY_FLASH_RESULT_MASK               (0x0FFFFFFFUL)
/** Error shift */
#define CY_FLASH_ERROR_SHIFT               (28UL)
/** No error */
#define CY_FLASH_ERROR_NO_ERROR            (0xAUL)
/** CODE ECC injection mask */
#define CY_FLASH_CODE_ECC_INJECT_MASK (0x00FFFFFFUL)
/** WORK ECC injection mask */
#define CY_FLASH_WORK_ECC_INJECT_MASK (0x007FFFFFUL)
/** CACHE ECC injection mask */
#define CY_FLASH_CACHE_ECC_INJECT_MASK (0x00FFFFFFUL)
/** CODE ECC injection position shift */
#define CY_FLASH_CODE_ECC_INJECT_POS (0x03u)
/** WORK ECC injection position shift */
#define CY_FLASH_WORK_ECC_INJECT_POS (0x02u)
/** CACHE ECC injection position shift */
#define CY_FLASH_CACHE_ECC_INJECT_POS (0x02u)
/** CODE ECC injection parity mask */
#define CY_FLASH_CODE_ECC_INJECT_PARITY_MASK (0x7Fu)
/** WORK ECC injection parity mask */
#define CY_FLASH_WORK_ECC_INJECT_PARITY_MASK (0x3Fu)
/** CACHE ECC injection parity mask */
#define CY_FLASH_CACHE_ECC_INJECT_PARITY_MASK (0x3Fu)

typedef enum
{
    CY_FLASH_PROGRAMROW_DATA_SIZE_8BIT    = (0x00ul),
    CY_FLASH_PROGRAMROW_DATA_SIZE_16BIT   = (0x01ul),
    CY_FLASH_PROGRAMROW_DATA_SIZE_32BIT   = (0x02ul),
    CY_FLASH_PROGRAMROW_DATA_SIZE_64BIT   = (0x03ul),
    CY_FLASH_PROGRAMROW_DATA_SIZE_128BIT  = (0x04ul),
    CY_FLASH_PROGRAMROW_DATA_SIZE_256BIT  = (0x05ul),
    CY_FLASH_PROGRAMROW_DATA_SIZE_512BIT  = (0x06ul),
    CY_FLASH_PROGRAMROW_DATA_SIZE_1024BIT = (0x07ul),
    CY_FLASH_PROGRAMROW_DATA_SIZE_2048BIT = (0x08ul),
    CY_FLASH_PROGRAMROW_DATA_SIZE_4096BIT = (0x09ul)
} cy_en_flash_programrow_datasize_t;

typedef enum
{
    CY_FLASH_PROGRAMROW_NON_BLOCKING = (0x00ul),
    CY_FLASH_PROGRAMROW_BLOCKING     = (0x01ul)
} cy_en_flash_programrow_blocking_t;

typedef enum
{
    CY_FLASH_PROGRAMROW_BLANK_CHECK      =  (0x00ul),
    CY_FLASH_PROGRAMROW_SKIP_BLANK_CHECK =  (0x01ul)
} cy_en_flash_programrow_skipblankcheck_t;

typedef enum
{
    CY_FLASH_PROGRAMROW_DATA_LOCATION_PAGE_LATCH = (0x00ul),
    CY_FLASH_PROGRAMROW_DATA_LOCATION_SRAM       = (0x01ul)
} cy_en_flash_programrow_location_t;

typedef enum
{
    CY_FLASH_PROGRAMROW_NOT_SET_INTR_MASK = (0x00ul),
    CY_FLASH_PROGRAMROW_SET_INTR_MASK     = (0x01ul)
} cy_en_flash_programrow_intrmask_t;

typedef enum
{
    CY_FLASH_ERASESECTOR_NON_BLOCKING      = (0x00ul),
    CY_FLASH_ERASESECTOR_BLOCKING          = (0x01ul)
} cy_en_flash_erasesector_blocking_t;

typedef enum
{
    CY_FLASH_ERASESECTOR_NOT_SET_INTR_MASK = (0x00ul),
    CY_FLASH_ERASESECTOR_SET_INTR_MASK     = (0x01ul)
} cy_en_flash_erasesector_intrmask_t;

typedef enum
{
    CY_FLASH_CHECKSUM_BANK0     = (0x00ul),
    CY_FLASH_CHECKSUM_BANK1     = (0x01ul)
} cy_en_flash_checksum_bank_t;

typedef enum
{
    CY_FLASH_CHECKSUM_PAGE     = (0x00ul),
    CY_FLASH_CHECKSUM_WHOLE    = (0x01ul)
} cy_en_flash_checksum_scope_t;

typedef enum
{
    CY_FLASH_CHECKSUM_MAIN        = (0x00ul),
    CY_FLASH_CHECKSUM_WOEK        = (0x01ul),
    CY_FLASH_CHECKSUM_SUPERVISORY = (0x02ul)
} cy_en_flash_checksum_region_t;

typedef enum
{
    CY_FLASH_COMPUTEHASH_BASIC  = (0x00ul),
    CY_FLASH_COMPUTEHASH_CRC8   = (0x01ul)
} cy_en_flash_computehash_type_t;

typedef enum
{
    CY_FLASH_ERASERESUME_NOT_SET_INTR_MASK  = (0x00ul),
    CY_FLASH_ERASERESUME_SET_INTR_MASK      = (0x01ul)
} cy_en_flash_eraseresume_setintr_t;

typedef enum
{
    CY_FLASH_ERASERESUME_NON_BLOCKING  = (0x00ul),
    CY_FLASH_ERASERESUME_BLOCKING      = (0x01ul)
} cy_en_flash_eraseresume_blocking_t;

typedef enum
{
    CY_FLASH_DRIVER_NON_BLOCKING  = (0x00ul),
    CY_FLASH_DRIVER_BLOCKING      = (0x01ul)
} cy_en_flash_driver_blocking_t;


/** \endcond */

/**
* \addtogroup group_flash_config_macro Flash configuration
* \{
* Specifies the parameter values passed to SROM API
*/

/** SROM API opcode for flash write operation */
#define CY_FLASH_OPCODE_PROGRAM_ROW        (0x06UL)
/** SROM API opcode for flash checksum operation */
#define CY_FLASH_OPCODE_CHECKSUM           (0x0BUL)
/** SROM API opcode for flash hash operation */
#define CY_FLASH_OPCODE_HASH               (0x0DUL)
/** SROM API opcode for flash erase all operation */
#define CY_FLASH_OPCODE_ERASEALL           (0x0AUL)
/** SROM API opcode for flash erase sector operation */
#define CY_FLASH_OPCODE_ERASE_SECTOR       (0x14UL)
/** SROM API opcode for check flash macro status */
#define CY_FLASH_OPCODE_CHECK_FM_STATUS    (0x07UL)
/** SROM API opcode for check flash macro status */
#define CY_FLASH_OPCODE_CONFIG_FM_INTR     (0x08UL)
/** SROM API opcode for erase suspend operation */
#define CY_FLASH_OPCODE_ERASE_SUSPEND      (0x22UL)
/** SROM API opcode for erase resume operation */
#define CY_FLASH_OPCODE_ERASE_RESUME       (0x23UL)
/** SROM API opcode for blank check operation */
#define CY_FLASH_OPCODE_BLANK_CHECK        (0x2AUL)
/** SROM API flash row shift for flash checksum operation */
#define CY_FLASH_OPCODE_CHECKSUM_ROW_SHIFT (8u)
/** SROM API flash data size parameter for flash write operation */
#define CY_FLASH_CONFIG_DATASIZE           (0x06UL)
/** SROM API flash verification option for flash write operation */
#define CY_FLASH_CONFIG_VERIFICATION_EN    (0x01UL)

/** \} group_flash_config_macro */


/**
* \addtogroup group_flash_general_macro Flash general parameters
* \{
* Provides general information about flash and IPC
*/

/** Flash row size */
#define CY_FLASH_SIZEOF_ROW                (CPUSS_FLASHC_PA_SIZE * 4u)
/** Number of flash rows */
#define CY_FLASH_NUMBER_ROWS               (CPUSS_FLASH_SIZE / CY_FLASH_SIZEOF_ROW)
/** Long words flash row size */
#define CY_FLASH_SIZEOF_ROW_LONG_UNITS     (CY_FLASH_SIZEOF_ROW / sizeof(uint32_t))
/** IPC channel to be used */
#define CY_FLASH_IPC_STRUCT ((volatile stc_IPC_STRUCT_t*) &IPC->STRUCT[CY_IPC_CHAN_SYSCALL])
/** IPC notify bit for IPC_STRUCT0 (dedicated to flash operation) */
#define CY_FLASH_IPC_NOTIFY_STRUCT         (0x1UL) // Setting Bit0 signifies ipc interrupt Struct0
/** \cond INTERNAL */
#define CY_FLASH_CM4_FLASH_PROXY_ADDR      (0x16001101UL)
/** \endcond */

/** \} group_flash_general_macro */

typedef enum
{
    CY_FLASH_MAIN_REGION = 0u,
    CY_FLASH_WORK_REGION = 1u,
    CY_FLASH_CA_CM0P_REGION = 2u
} cy_en_region_t;

typedef enum
{
    CY_FLASH_SINGLE_BANK_MODE = 0u,
    CY_FLASH_DUAL_BANK_MODE = 1u
} cy_en_bankmode_t;

typedef enum
{
    CY_FLASH_MAPPING_A = 0u,
    CY_FLASH_MAPPING_B = 1u
} cy_en_maptype_t;

/** \} group_flash_macro */

#if defined(__cplusplus)
extern "C" {
#endif

/***************************************
* Data Structure definitions
***************************************/

/**
* \addtogroup group_flash_srom_config_structure
* \{
*/

typedef struct
{
    const uint32_t *destAddr;                    /**< Specifies the configuration of flash operation */
    const uint32_t *dataAddr;                    /**< Specifies the configuration of flash operation */
    cy_en_flash_programrow_blocking_t blocking;  /**< Specifies the code of flash operation */
    cy_en_flash_programrow_skipblankcheck_t skipBC; /**< Specifies the code of flash operation */
    cy_en_flash_programrow_datasize_t dataSize;  /**< Specifies the configuration of flash operation */
    cy_en_flash_programrow_location_t dataLoc;   /**< Specifies the configuration of flash operation */
    cy_en_flash_programrow_intrmask_t intrMask;  /**< Specifies the configuration of flash operation */
}cy_stc_flash_programrow_config_t;

typedef struct
{
    const uint32_t *Addr;                              /**< Specifies the configuration of flash operation */
    cy_en_flash_erasesector_blocking_t blocking; /**< Specifies the code of flash operation */
    cy_en_flash_erasesector_intrmask_t intrMask; /**< Specifies the configuration of flash operation */
}cy_stc_flash_erasesector_config_t;

typedef struct
{
    uint8_t rowId;                               /**< Specifies the configuration of flash operation */
    cy_en_flash_checksum_bank_t bank;            /**< Specifies the code of flash operation */
    cy_en_flash_checksum_scope_t whole;          /**< Specifies the configuration of flash operation */
    cy_en_flash_checksum_region_t region;        /**< Specifies the configuration of flash operation */
} cy_stc_flash_checksum_config_t;

typedef struct
{
    const uint32_t *startAddr;                   /**< Specifies the configuration of flash operation */
    uint32_t numOfByte;                          /**< Specifies the configuration of flash operation */
    cy_en_flash_computehash_type_t type;         /**< Specifies the code of flash operation */
} cy_stc_flash_computehash_config_t;

typedef struct
{
    cy_en_flash_eraseresume_setintr_t intrMask;  /**< Specifies the code of flash operation */
    cy_en_flash_eraseresume_blocking_t blocking; /**< Specifies the code of flash operation */
} cy_stc_flash_eraseresume_config_t;

typedef struct
{
    const uint32_t *addrToBeChecked;
    uint32_t        numOfWordsToBeChecked;
} cy_stc_flash_blankcheck_config_t;

typedef union
{
    struct
    {
        uint16_t prm_code         : 8; // Indicates if active PGM operation to the Code flash is taking place
        uint16_t pgm_work         : 8; // Indicates if active PGM operation to the Work flash is taking place
        uint16_t erase_code       : 8; // Indicates if active Erase operation to the Code flash is taking place
        uint16_t erase_work       : 8; // Indicates if active Erase operation to the Work flash is taking place
        uint16_t ers_suspend      : 8; // Indicates if Erase operation (Code/Work) is currently being suspended
        uint16_t blank_check_work : 8; // Indicates if Blank Check mode is currently running on the work flash
        uint16_t blank_check_pass : 8; // Indicates  the Blank check command result is Blank
        uint16_t hang             : 8; // After embedded operation (pgm/erase) this flag will tell if it was successful or failed
        uint16_t busy             : 8; // Whenever the device is in embedded mode the RDY goes
    } status_bits;
    uint16_t u16;
} cy_un_fm_status_t;

typedef enum
{
    CY_FLASH_CLEAR_INTERRUPT_MASK = 0u,
    CY_FLASH_SET_INTERRUPT_MASK = 1u,
    CY_FLASH_CLEAR_INTERRUPT = 2u
} cy_en_config_fm_intr_t;

/** \cond INTERNAL */
typedef struct
{
    struct
    {
        uint32_t rev0               : 8;
        uint32_t blocking           : 8;
        uint32_t skipBlankCheck     : 8;
        uint32_t opcode             : 8;
    } arg0;
    struct
    {
        uint32_t dataSize          : 8;
        uint32_t dataLoc           : 8;
        uint32_t rev0              : 8;
        uint32_t interruptMask     : 8;
    } arg1;
    struct
    {
        uint32_t addrProg : 32;
    } arg2;
    struct
    {
        uint32_t addrData : 32;
    } arg3;
} cy_stc_progrow_util_t;

typedef struct
{
    struct
    {
        uint32_t rev0          : 8;
        uint32_t blocking      : 8;
        uint32_t interruptMask : 8;
        uint32_t opcode        : 8;
    } arg0;
    struct
    {
        uint32_t address  : 32;
    } arg1;
    uint32_t arg2;
    uint32_t arg3;
} cy_stc_erasesector_util_t;

typedef struct
{
    struct
    {
        uint32_t rev0   : 24;
        uint32_t opcode : 8;
    } arg0;
    uint32_t arg1;
    uint32_t arg2;
    uint32_t arg3;
} cy_stc_eraseall_util_t;

typedef struct
{
    struct
    {
        uint32_t rev0   : 24;
        uint32_t opcode : 8;
    } arg0;
    uint32_t arg1;
    uint32_t arg2;
    uint32_t arg3;
} cy_stc_checkfmstate_util_t;

typedef struct
{
    struct
    {
        uint32_t option : 24;
        uint32_t opcode : 8;
    } arg0;
    uint32_t arg1;
    uint32_t arg2;
    uint32_t arg3;
} cy_stc_configurfminterrupt_util_t;

typedef struct
{
    struct
    {
        uint32_t passindata   : 1;
        uint32_t rev0   : 6;
        uint32_t bank   : 1;
        uint32_t row_id : 13;
        uint32_t whole  : 1;
        uint32_t region : 2;
        uint32_t opcode : 8;
    } arg0;
    uint32_t arg1;
    uint32_t arg2;
    uint32_t arg3;
} cy_stc_checksum_util_t;

typedef struct
{
    struct
    {
        uint32_t rev0   : 8;
        uint32_t type   : 8;
        uint32_t rev1   : 8;
        uint32_t opcode : 8;
    } arg0;
    struct
    {
        uint32_t start_addr: 32;
    } arg1;
    struct
    {
        uint32_t number_byte: 32;
    } arg2;
    uint32_t arg3;
} cy_stc_computehash_util_t;

typedef struct
{
    struct
    {
        uint32_t rev0   : 24;
        uint32_t opcode : 8;
    } arg0;
    uint32_t arg1;
    uint32_t arg2;
    uint32_t arg3;
} cy_stc_erasesuspend_util_t;

typedef struct
{
    struct
    {
        uint32_t rev0     : 8;
        uint32_t blocking : 8;
        uint32_t intrmask : 8;
        uint32_t opcode   : 8;
    } arg0;
    uint32_t arg1;
    uint32_t arg2;
    uint32_t arg3;
} cy_stc_eraseresume_util_t;

typedef struct
{
    struct
    {
        uint32_t rev0   : 24;
        uint32_t opcode : 8;
    } arg0;
    struct
    {
        uint32_t addrToBeChecked : 32;
    } arg1;
    struct
    {
        uint32_t numOfWordsToBeChecked   : 16;
        uint32_t rev0   : 16;
    } arg2;
    uint32_t arg3;
} cy_stc_blankcheck_util_t;
/** \endcond */

/** Flash driver context */
typedef union
{
    uint32_t                          arg[4];
    cy_stc_progrow_util_t             progRowUtil;
    cy_stc_erasesector_util_t         eraseSectUtil;
    cy_stc_eraseall_util_t            eraseAllUtil;
    cy_stc_checkfmstate_util_t        checkFmStateUtil;
    cy_stc_configurfminterrupt_util_t cfgFmIntUtil;
    cy_stc_checksum_util_t            checkSumUtil;
    cy_stc_computehash_util_t         compHashUtil;
    cy_stc_erasesuspend_util_t        ersSuspUtil;
    cy_stc_eraseresume_util_t         ersResumUtil;
    cy_stc_blankcheck_util_t          blankCheckUtil;
}cy_un_flash_context_t;



/** \} group_flash_srom_config_structure */

/*******************************************************************************
* Function Name: Cy_Flashc_SetMainWaitState
****************************************************************************//**
*
* \brief Sets main wait state
*
* \param waitState wait state to be set.
*
* \return flash status
*
*******************************************************************************/
__STATIC_INLINE cy_en_flashdrv_status_t Cy_Flashc_SetMainWaitState(uint8_t waitState)
{
    if(waitState <= 16ul)
    {
        FLASHC->unFLASH_CTL.stcField.u4WS = waitState;
        return CY_FLASH_DRV_SUCCESS;
    }
    else
    {
        return CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;
    }
}

/*******************************************************************************
* Function Name: Cy_Flashc_CM0_CacheEnable
****************************************************************************//**
*
* \brief Enables CM0 cache.
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_CM0_CacheEnable(void)
{
    FLASHC->unCM0_CA_CTL0.stcField.u1CA_EN = 1u;
}

/*******************************************************************************
* Function Name: Cy_Flashc_CM0_CacheDisable
****************************************************************************//**
*
* \brief Disables CM0 cache
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_CM0_CacheDisable(void)
{
    FLASHC->unCM0_CA_CTL0.stcField.u1CA_EN = 0u;
}

/*******************************************************************************
* Function Name: Cy_Flashc_CM0_PrefetchEnable
****************************************************************************//**
*
* \brief Enables CM0 prefetch
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_CM0_PrefetchEnable(void)
{
    FLASHC->unCM0_CA_CTL0.stcField.u1PREF_EN = 1u;
}

/*******************************************************************************
* Function Name: Cy_Flashc_CM0_PrefetchDisable
****************************************************************************//**
*
* \brief Disables CM0 prefetch
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_CM0_PrefetchDisable(void)
{
    FLASHC->unCM0_CA_CTL0.stcField.u1PREF_EN = 0u;
}

/*******************************************************************************
* Function Name: Cy_Flashc_WorkECCEnabled
****************************************************************************//**
*
* \brief Enables ECC for work flash
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_WorkECCEnabled(void)
{
   FLASHC->unFLASH_CTL.stcField.u1WORK_ECC_EN = 1u;
}

/*******************************************************************************
* Function Name: Cy_Flashc_WorkECCDisable
****************************************************************************//**
*
* \brief Disables ECC for work flash
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_WorkECCDisable(void)
{
   FLASHC->unFLASH_CTL.stcField.u1WORK_ECC_EN = 0u;
}

/*******************************************************************************
* Function Name: Cy_Flashc_MainECCEnable
****************************************************************************//**
*
* \brief Enables ECC for main flash
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_MainECCEnable(void)
{
   FLASHC->unFLASH_CTL.stcField.u1MAIN_ECC_EN = 1u;
}

/*******************************************************************************
* Function Name: Cy_Flashc_MainECCDisable
****************************************************************************//**
*
* \brief Disables ECC for main flash
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_MainECCDisable(void)
{
   FLASHC->unFLASH_CTL.stcField.u1MAIN_ECC_EN = 0u;
}

/*******************************************************************************
* Function Name: Cy_Flashc_CM0_CAECCEnable
****************************************************************************//**
*
* \brief Enables ECC for cache in CM0
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_CM0_CAECCEnable(void)
{
   FLASHC->unCM0_CA_CTL0.stcField.u1RAM_ECC_EN = 1u;
}

/*******************************************************************************
* Function Name: Cy_Flashc_CM0_CAECCDisable
****************************************************************************//**
*
* \brief Disables ECC for cache in CM0
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_CM0_CAECCDisable(void)
{
   FLASHC->unCM0_CA_CTL0.stcField.u1RAM_ECC_EN = 0u;
}

/*******************************************************************************
* Function Name: Cy_Flashc_WorkECCInjectionEnable
****************************************************************************//**
*
* \brief Enables ECC injection for work flash
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_WorkECCInjectionEnable(void)
{
   FLASHC->unFLASH_CTL.stcField.u1WORK_ECC_INJ_EN = 1u;
}

/*******************************************************************************
* Function Name: Cy_Flashc_WorkECCInjectionDisable
****************************************************************************//**
*
* \brief Disables ECC injection for work flash
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_WorkECCInjectionDisable(void)
{
   FLASHC->unFLASH_CTL.stcField.u1WORK_ECC_INJ_EN = 0u;
}


/*******************************************************************************
* Function Name: Cy_Flashc_MainECCInjectionEnable
****************************************************************************//**
*
* \brief Enables ECC injection for main flash
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_MainECCInjectionEnable(void)
{
   FLASHC->unFLASH_CTL.stcField.u1MAIN_ECC_INJ_EN = 1u;
}

/*******************************************************************************
* Function Name: Cy_Flashc_MAINECCInjectionDisable
****************************************************************************//**
*
* \brief Disables ECC injection for main flash
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_MAINECCInjectionDisable(void)
{
   FLASHC->unFLASH_CTL.stcField.u1MAIN_ECC_INJ_EN = 0u;
}

/*******************************************************************************
* Function Name: Cy_Flashc_WorkSeqReadEnable
****************************************************************************//**
*
* \brief Enables sequential read operation from work flash
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_WorkSeqReadEnable(void)
{
   FLASHC->unFLASH_CTL.stcField.u1WORK_SEQ_RD_EN = 1u;
}

/*******************************************************************************
* Function Name: Cy_Flashc_WorkSeqReadDisable
****************************************************************************//**
*
* \brief Disables sequential read operation from work flash
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_WorkSeqReadDisable(void)
{
   FLASHC->unFLASH_CTL.stcField.u1WORK_SEQ_RD_EN = 0u;
}

/*******************************************************************************
* Function Name: Cy_Flashc_CM0_CAECCInjectionEnable
****************************************************************************//**
*
* \brief Enables ECC injection for cache in CM0
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_CM0_CAECCInjectionEnable(void)
{
   FLASHC->unCM0_CA_CTL0.stcField.u1RAM_ECC_INJ_EN = 1u;
}

/*******************************************************************************
* Function Name: Cy_Flashc_CM0_CAECCInjectionDisable
****************************************************************************//**
*
* \brief Disables ECC injection for cache in CM0
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_CM0_CAECCInjectionDisable(void)
{
   FLASHC->unCM0_CA_CTL0.stcField.u1RAM_ECC_INJ_EN = 0u;
}

/*******************************************************************************
* Function Name: Cy_Flashc_SetWorkBankMode
****************************************************************************//**
*
* \brief Sets bank mode for work flash
*
* \param mode bank mode to be set
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_SetWorkBankMode(cy_en_bankmode_t mode)
{
   FLASHC->unFLASH_CTL.stcField.u1WORK_BANK_MODE = mode;
   FLASHC->unFLASH_CTL.u32Register;
}

/*******************************************************************************
* Function Name: Cy_Flashc_GetWorkBankMode
****************************************************************************//**
*
* \brief Gets current bank mode for work flash
*
* \return Current bank mode
*
*******************************************************************************/
__STATIC_INLINE cy_en_bankmode_t Cy_Flashc_GetWorkBankMode(void)
{
   return (cy_en_bankmode_t)FLASHC->unFLASH_CTL.stcField.u1WORK_BANK_MODE;
}

/*******************************************************************************
* Function Name: Cy_Flashc_SetMainBankMode
****************************************************************************//**
*
* \brief Sets bank mode for main flash
*
* \param mode bank mode to be set
*
* \return
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_SetMainBankMode(cy_en_bankmode_t mode)
{
   FLASHC->unFLASH_CTL.stcField.u1MAIN_BANK_MODE = mode;
   FLASHC->unFLASH_CTL.u32Register;
}

/*******************************************************************************
* Function Name: Cy_Flashc_GetMainBankMode
****************************************************************************//**
*
* \brief Gets current bank mode for main flash
*
* \return Current bank mode
*
*******************************************************************************/
__STATIC_INLINE cy_en_bankmode_t Cy_Flashc_GetMainBankMode(void)
{
   return (cy_en_bankmode_t)FLASHC->unFLASH_CTL.stcField.u1MAIN_BANK_MODE;
}

/*******************************************************************************
* Function Name: Cy_Flashc_SetWorkMap
****************************************************************************//**
*
* \brief Sets bank map for work flash
*
* \param type Bank map type to be set
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_SetWorkMap(cy_en_maptype_t type)
{
   FLASHC->unFLASH_CTL.stcField.u1WORK_MAP = type;
   FLASHC->unFLASH_CTL.u32Register;
}

/*******************************************************************************
* Function Name: Cy_Flashc_GetWorkMap
****************************************************************************//**
*
* \brief Gets bank map for work flash
*
* \return type Bank map type
*
*******************************************************************************/
__STATIC_INLINE cy_en_maptype_t Cy_Flashc_GetWorkMap(void)
{
   return (cy_en_maptype_t)FLASHC->unFLASH_CTL.stcField.u1WORK_MAP;
}

/*******************************************************************************
* Function Name: Cy_Flashc_SetMainMap
****************************************************************************//**
*
* \brief Sets bank map for main flash
*
* \param type Bank map type to be set
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_SetMainMap(cy_en_maptype_t type)
{
   FLASHC->unFLASH_CTL.stcField.u1MAIN_MAP = type;
   FLASHC->unFLASH_CTL.u32Register;
}

/*******************************************************************************
* Function Name: Cy_Flashc_GetMainMap
****************************************************************************//**
*
* \brief Gets bank map for main flash
*
* \return type Bank map type
*
*******************************************************************************/
__STATIC_INLINE cy_en_maptype_t Cy_Flashc_GetMainMap(void)
{
   return (cy_en_maptype_t)FLASHC->unFLASH_CTL.stcField.u1MAIN_MAP;
}

/*******************************************************************************
* Function Name: Cy_Flashc_InvalidateFlashCacheBuffer
****************************************************************************//**
*
* \brief Invalidates the flash cache and buffer
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_InvalidateFlashCacheBuffer(void)
{
    FLASHC->unFLASH_CMD.stcField.u1INV = 0x1u;
}

/*******************************************************************************
* Function Name: Cy_Flashc_InvalidateFlashBuffer
****************************************************************************//**
*
* \brief Invalidates the flash buffer
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_InvalidateFlashBuffer(void)
{
    FLASHC->unFLASH_CMD.stcField.u1BUFF_INV = 0x1u;
}

// Needs to be removed once boot supports enabling by default
/*******************************************************************************
* Function Name: Cy_Flashc_MainWriteEnable
****************************************************************************//**
*
* \brief Enable writting main flash
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_MainWriteEnable(void)
{
    FLASHC_FM_CTL_ECT->unMAIN_FLASH_SAFETY.stcField.u1MAINFLASHWRITEENABLE = 1u;
}

// Needs to be removed once boot supports enabling by default
/*******************************************************************************
* Function Name: Cy_Flashc_WorkWriteEnable
****************************************************************************//**
*
* \brief Enable writting work flash
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_WorkWriteEnable(void)
{
    FLASHC_FM_CTL_ECT->unWORK_FLASH_SAFETY.stcField.u1WORKFLASHWRITEENABLE = 1u;
}

// Needs to be removed once boot supports enabling by default
/*******************************************************************************
* Function Name: Cy_Flashc_MainWriteDisable
****************************************************************************//**
*
* \brief Disable writting main flash
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_MainWriteDisable(void)
{
    FLASHC_FM_CTL_ECT->unMAIN_FLASH_SAFETY.stcField.u1MAINFLASHWRITEENABLE = 0u;
}

// Needs to be removed once boot supports enabling by default
/*******************************************************************************
* Function Name: Cy_Flashc_WorkWriteDisable
****************************************************************************//**
*
* \brief Disable writting work flash
*
* \return none
*
*******************************************************************************/
__STATIC_INLINE void Cy_Flashc_WorkWriteDisable(void)
{
    FLASHC_FM_CTL_ECT->unWORK_FLASH_SAFETY.stcField.u1WORKFLASHWRITEENABLE = 0u;
}


/***************************************
* Function Prototypes
***************************************/

/**
* \addtogroup group_flash_functions
* \{
*/
cy_en_flashdrv_status_t Cy_Flash_ProgramRow(cy_un_flash_context_t* context, const cy_stc_flash_programrow_config_t* config, cy_en_flash_driver_blocking_t block);
cy_en_flashdrv_status_t Cy_Flash_Checksum (cy_un_flash_context_t* context, const cy_stc_flash_checksum_config_t *config, uint32_t* cheksumPtr);
cy_en_flashdrv_status_t Cy_Flash_CalculateHash(cy_un_flash_context_t* context, const cy_stc_flash_computehash_config_t *config,  uint32_t* hashPtr);
cy_en_flashdrv_status_t Cy_Flash_EraseAll(cy_un_flash_context_t* context, cy_en_flash_driver_blocking_t block);
cy_en_flashdrv_status_t Cy_Flash_EraseSector(cy_un_flash_context_t* context, const cy_stc_flash_erasesector_config_t *config, cy_en_flash_driver_blocking_t block);
cy_en_flashdrv_status_t Cy_Flash_CheckFMStatus(cy_un_flash_context_t* context, cy_un_fm_status_t *status);
cy_en_flashdrv_status_t Cy_Flash_ConfigureFMIntr(cy_un_flash_context_t* context, cy_en_config_fm_intr_t option);
cy_en_flashdrv_status_t Cy_Flash_EraseSuspend(cy_un_flash_context_t* context);
cy_en_flashdrv_status_t Cy_Flash_EraseResume(cy_un_flash_context_t* context ,const cy_stc_flash_eraseresume_config_t *config);
cy_en_flashdrv_status_t Cy_Flash_BlankCheck(cy_un_flash_context_t* context ,const cy_stc_flash_blankcheck_config_t *config, cy_en_flash_driver_blocking_t block);
cy_en_flashdrv_status_t Cy_Flash_GetDrvStatus(cy_un_flash_context_t *context);

/** \cond INTERNAL */
en_flash_bounds_t Cy_Flash_WorkBoundsCheck(uint32_t address);
en_flash_bounds_t Cy_Flash_MainBoundsCheck(uint32_t address);
en_flash_bounds_t Cy_Flash_SupervisoryBoundsCheck(uint32_t address);
en_flash_bounds_t Cy_Flash_BoundsCheck(uint32_t flashAddr);
cy_en_flashdrv_status_t Cy_Flash_ProcessOpcode(uint32_t opcode);
static cy_en_flashdrv_status_t Cy_Flash_SendMsgWaitComplete(cy_un_flash_context_t *context, uint32_t *returnData);

/** \endcond */

/** \} group_flash_functions */

#if defined(__cplusplus)
}
#endif


#endif /* #if !defined(CY_FLASH_H) */
/** \endcond */


/** \} group_flash */


/* [] END OF FILE */
