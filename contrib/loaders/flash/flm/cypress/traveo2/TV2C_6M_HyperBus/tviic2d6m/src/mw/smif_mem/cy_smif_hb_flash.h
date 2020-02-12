/* cy_smif_hb_flash.h - Source Code for Cypress's Low Level Driver */

#ifndef CY_SMIF_HB_FLASH_H
#define CY_SMIF_HB_FLASH_H

#include "cy_device_headers.h"
#include "smif/cy_smif.h"

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/**************************************************** 
* Define how to access your hardware.         *
* Describe to the LLD the flash chip configuration  *
* un-comment the one that matches your system       *
****************************************************/
#define CY_SMIF_HB_FLASH_CONFIGURATION_X16_AS_X16    /* no-interleaving, a single x16 device in x16 mode  */
 

/* LLD System Specific Typedefs */
typedef uint8_t                     CY_SMIF_BYTE;             /* 8 bits wide */
typedef uint8_t                     CY_SMIF_HB_FLASH_CHAR;    /* 8 bit wids */
typedef uint16_t                    CY_SMIF_HB_FLASH_UINT16;  /* 16 bits wide */
typedef uint32_t                    CY_SMIF_HB_FLASH_UINT32;  /* 32 bits wide */
typedef uint64_t                    CY_SMIF_HB_FLASH_UINT64;  /* 64 bits wide */
typedef CY_SMIF_HB_FLASH_UINT32     CY_SMIF_ADDRESS;          /* Used for system level addressing */
typedef uint32_t                    CY_SMIF_WORDCOUNT;        /* used for multi-byte operations */

/* boolean macros */
#ifndef TRUE  // CY_SMIF_HB_FLASH_KEEP
 #define TRUE  (1)
#endif      // CY_SMIF_HB_FLASH_KEEP
#ifndef FALSE // CY_SMIF_HB_FLASH_KEEP
 #define FALSE (0)
#endif      // CY_SMIF_HB_FLASH_KEEP

#define CY_SMIF_SA_OFFSET_MASK	0xFFFE0000   /* mask off the offset */

/* LLD Command Definition */
#define CY_SMIF_NOR_CFI_QUERY_CMD                ((0x98)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_CHIP_ERASE_CMD               ((0x10)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_ERASE_SETUP_CMD              ((0x80)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_RESET_CMD                    ((0xF0)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_SECSI_SECTOR_ENTRY_CMD       ((0x88)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_SECTOR_ERASE_CMD             ((0x30)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_WRITE_BUFFER_LOAD_CMD        ((0x25)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_WRITE_BUFFER_PGM_CONFIRM_CMD ((0x29)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER) 
#define CY_SMIF_NOR_SET_CONFIG_CMD           ((0xD0)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_BIT_FIELD_CMD        ((0xBF)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)

#define CY_SMIF_NOR_ERASE_SUSPEND_CMD      ((0xB0)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_ERASE_RESUME_CMD       ((0x30)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_PROGRAM_SUSPEND_CMD      ((0x51)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_PROGRAM_RESUME_CMD       ((0x50)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_STATUS_REG_READ_CMD      ((0x70)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_STATUS_REG_CLEAR_CMD     ((0x71)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_BLANK_CHECK_CMD        ((0x33)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)

/* Command code definition */
#define CY_SMIF_NOR_AUTOSELECT_CMD               ((0x90)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_PROGRAM_CMD                  ((0xA0)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_SECSI_SECTOR_EXIT_SETUP_CMD  ((0x90)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_SECSI_SECTOR_EXIT_CMD        ((0x00)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_UNLOCK_BYPASS_ENTRY_CMD      ((0x20)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_UNLOCK_BYPASS_PROGRAM_CMD    ((0xA0)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_UNLOCK_BYPASS_RESET_CMD1     ((0x90)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_UNLOCK_BYPASS_RESET_CMD2     ((0x00)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_UNLOCK_DATA1                 ((0xAA)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_UNLOCK_DATA2                 ((0x55)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_SUSPEND_CMD                  ((0xB0)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_RESUME_CMD                   ((0x30)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_READ_CONFIG_CMD          ((0xC6)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_WRITE_BUFFER_ABORT_RESET_CMD ((0xF0)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)

/* Sector protection command definition */
#define CY_SMIF_PPB_PROTECTED                           (0*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_PPB_UNPROTECTED                         (1*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)

#define CY_SMIF_WSXXX_LOCK_REG_ENTRY      (0x40*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_WSXXX_LOCK_REG2_ENTRY     (0x41*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)  // for GL-R
#define CY_SMIF_WSXXX_PSWD_PROT_CMD_ENTRY (0x60*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_WSXXX_PSWD_UNLOCK_1       (0x25*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_WSXXX_PSWD_UNLOCK_2       (0x03*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_WSXXX_PSWD_UNLOCK_3       (0x29*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_WSXXX_PPB_ENTRY           (0xC0*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_WSXXX_PPB_ERASE_CONFIRM   (0x30*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_WSXXX_PPB_LOCK_ENTRY      (0x50*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_WSXXX_DYB_ENTRY           (0xE0*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_WSXXX_DYB_CLEAR           (0x01*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)

#define CY_SMIF_NOR_LOCK_REG_ENTRY        (0x40*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_SECTOR_LOCK_CMD     (0x60*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_LOAD_SECTOR_ADR     (0x61*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_SECTOR_UNLOCK_ADR6    (0x40*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_SECTOR_LOCK_ADR6    ((~CY_SMIF_NOR_SECTOR_UNLOCK_ADR6)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)

/* RPC2 command code definition */
#define CY_SMIF_NOR_ENTER_DEEP_POWER_DOWN_CMD                 ((0xB9)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_MEASURE_TEMPERATURE_CMD                   ((0xA9)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_READ_TEMPERATURE_REG_CMD                    ((0xA8)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_PROGRAM_POR_TIMER_CMD                           ((0x34)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_READ_POR_TIMER_CMD                                  ((0x3C)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_LOAD_INTERRUPT_CFG_REG_CMD                 ((0x36)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_READ_INTERRUPT_CFG_REG_CMD                 ((0xC4)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_LOAD_INTERRUPT_STATUS_REG_CMD           ((0x37)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_READ_INTERRUPT_STATUS_REG_CMD           ((0xC5)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_LOAD_VOLATILE_CFG_REG_CMD                   ((0x38)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_READ_VOLATILE_CFG_REG_CMD                   ((0xC7)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_PROGRAM_NON_VOLATILE_CFG_REG_CMD    ((0x39)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_ERASE_NON_VOLATILE_CFG_REG_CMD          ((0xC8)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_READ_NON_VOLATILE_CFG_REG_CMD           ((0xC6)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_EVALUATE_ERASE_STATUS_CMD                   ((0xD0)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_ECC_STATUS_ENTER_CMD                              ((0x75)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_ECC_CLEAR_ERROR_DETECTION_COUNTER_CMD    ((0x50)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_ECC_EXIT_CMD                                               ((0xF0)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER) 
#define CY_SMIF_NOR_ECC_READ_ERROR_CMD                                  ((0x60)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER) 
#define CY_SMIF_NOR_CRC_ENTRY_CMD                                             ((0x78)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER) 
#define CY_SMIF_NOR_LOAD_CRC_START_ADDR_CMD                       ((0xC3)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER) 
#define CY_SMIF_NOR_LOAD_CRC_END_ADDR_CMD                           ((0x3C)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_CRC_SUSPEND_CMD                                        ((0xC0)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_CRC_RESUME_CMD                                          ((0xC1)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_CRC_READ_CHECKVALUE_RESLUT_REG_CMD  ((0x60)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)
#define CY_SMIF_NOR_CRC_EXIT_CMD                                               ((0xF0)*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)  

/* polling routine options */
typedef enum
{
CY_SMIF_HB_FLASH_P_POLL_NONE = 0,      /* pull program status */
CY_SMIF_HB_FLASH_P_POLL_PGM,           /* pull program status */
CY_SMIF_HB_FLASH_P_POLL_WRT_BUF_PGM,     /* Poll write buffer   */
CY_SMIF_HB_FLASH_P_POLL_SEC_ERS,         /* Poll sector erase   */
CY_SMIF_HB_FLASH_P_POLL_CHIP_ERS,      /* Poll chip erase     */
CY_SMIF_HB_FLASH_P_POLL_RESUME,
CY_SMIF_HB_FLASH_P_POLL_BLANK          /* Poll device sector blank check */
}CY_SMIF_POLLING_TYPE;

/* polling return status */
typedef enum {
 CY_SMIF_DEV_STATUS_UNKNOWN = 0,
 CY_SMIF_DEV_NOT_BUSY,
 CY_SMIF_DEV_BUSY,
 CY_SMIF_DEV_EXCEEDED_TIME_LIMITS,
 CY_SMIF_DEV_SUSPEND,
 CY_SMIF_DEV_WRITE_BUFFER_ABORT,
 CY_SMIF_DEV_STATUS_GET_PROBLEM,
 CY_SMIF_DEV_VERIFY_ERROR,
 CY_SMIF_DEV_BYTES_PER_OP_WRONG,
 CY_SMIF_DEV_ERASE_ERROR,       
 CY_SMIF_DEV_PROGRAM_ERROR,       
 CY_SMIF_DEV_SECTOR_LOCK,
 CY_SMIF_DEV_PROGRAM_SUSPEND,     /* Device is in program suspend mode */
 CY_SMIF_DEV_PROGRAM_SUSPEND_ERROR,   /* Device program suspend error */
 CY_SMIF_DEV_ERASE_SUSPEND,       /* Device is in erase suspend mode */
 CY_SMIF_DEV_ERASE_SUSPEND_ERROR,   /* Device erase suspend error */
 CY_SMIF_DEV_BUSY_IN_OTHER_BANK     /* Busy operation in other bank */
} CY_SMIF_DEVSTATUS;


typedef enum 
{
  CY_SMIF_FLSTATE_NOT_BUSY = 0,
  CY_SMIF_FLSTATE_ERASE = 1,
  CY_SMIF_FLSTATE_WRITEBUFFER = 2
} CY_SMIF_FLSTATE;

#define CY_SMIF_FLRESUME 0
#define CY_SMIF_FLSUSPEND 1

#define CY_SMIF_DEV_RDY_MASK      (0x80*CY_SMIF_HB_FLASH_DEV_MULTIPLIER) /* Device Ready Bit */
#define CY_SMIF_DEV_ERASE_SUSP_MASK   (0x40*CY_SMIF_HB_FLASH_DEV_MULTIPLIER) /* Erase Suspend Bit */
#define CY_SMIF_DEV_ERASE_MASK      (0x20*CY_SMIF_HB_FLASH_DEV_MULTIPLIER) /* Erase Status Bit */
#define CY_SMIF_DEV_PROGRAM_MASK    (0x10*CY_SMIF_HB_FLASH_DEV_MULTIPLIER) /* Program Status Bit */
#define CY_SMIF_DEV_RFU_MASK      (0x08*CY_SMIF_HB_FLASH_DEV_MULTIPLIER) /* Reserved */
#define CY_SMIF_DEV_PROGRAM_SUSP_MASK (0x04*CY_SMIF_HB_FLASH_DEV_MULTIPLIER) /* Program Suspend Bit */
#define CY_SMIF_DEV_SEC_LOCK_MASK   (0x02*CY_SMIF_HB_FLASH_DEV_MULTIPLIER) /* Sector lock Bit */
#define CY_SMIF_DEV_BANK_MASK     (0x01*CY_SMIF_HB_FLASH_DEV_MULTIPLIER) /* Operation in current bank */

#define CY_SMIF_DEV_CRCSSB_MASK			(0x0100*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)	/* CRC Suspend Bit, 1: suspend, 0: no suspend*/
#define CY_SMIF_DEV_ESTAT_MASK        (0x01*CY_SMIF_HB_FLASH_DEV_MULTIPLIER)	/* Sector Erase Status Bit (for Evaluate Erase Status)*/
                                                                                              /*0=previous erase did not complete successfully*/
                                                                                              /*1=previous erase completed successfully*/
/*****************************************************
* Define Flash read/write macro to be used by LLD    *
*****************************************************/
#define CY_SMIF_FLASH_OFFSET(b,o)       (*(( (volatile CY_SMIF_FLASHDATA*)(b) ) + (o)))

#if (CY_CPU_CORTEX_M7)
  #define CY_SMIF_FLASH_WR(b,o,d)   {\
                                        __DMB();\
                                        CY_SMIF_FLASH_OFFSET((b),(o)) = (d);\
                                     }
#else
  #define CY_SMIF_FLASH_WR(b,o,d) CY_SMIF_FLASH_OFFSET((b),(o)) = (d)
#endif
#define CY_SMIF_FLASH_RD(b,o)   CY_SMIF_FLASH_OFFSET((b),(o))          



#ifdef  CY_SMIF_HB_FLASH_CONFIGURATION_X16_AS_X16           // CY_SMIF_HB_FLASH_KEEP
#define CY_SMIF_HB_FLASH_DEV_MULTIPLIER 0x00000001
#define CY_SMIF_HB_FLASH_DB_READ_MASK   0x0000FFFF
#define CY_SMIF_HB_FLASH_DEV_READ_MASK  0x0000FFFF
#define CY_SMIF_HB_FLASH_UNLOCK_ADDR1   0x00000555
#define CY_SMIF_HB_FLASH_UNLOCK_ADDR2   0x000002AA
#define CY_SMIF_HB_FLASH_BYTES_PER_OP   0x00000002
#define CY_SMIF_HB_FLASH_CFI_UNLOCK_ADDR1 0x00000055
typedef CY_SMIF_HB_FLASH_UINT16 CY_SMIF_FLASHDATA;
#define CY_SMIF_HB_FLASH_BUF_SIZE_MULTIPLIER 1

#elif defined  CY_SMIF_HB_FLASH_CONFIGURATION_X32_AS_X32           
#define CY_SMIF_HB_FLASH_DEV_MULTIPLIER 0x00000001
#define CY_SMIF_HB_FLASH_DB_READ_MASK   0xFFFFFFFF 
#define CY_SMIF_HB_FLASH_DEV_READ_MASK  0xFFFFFFFF
#define CY_SMIF_HB_FLASH_UNLOCK_ADDR1   0x00000555
#define CY_SMIF_HB_FLASH_UNLOCK_ADDR2   0x000002AA
#define CY_SMIF_HB_FLASH_BYTES_PER_OP   0x00000004
#define CY_SMIF_HB_FLASH_CFI_UNLOCK_ADDR1 0x00000055
typedef CY_SMIF_HB_FLASH_UINT32 CY_SMIF_FLASHDATA;
#define CY_SMIF_HB_FLASH_BUF_SIZE_MULTIPLIER 1

#elif defined CY_SMIF_HB_FLASH_CONFIGURATION_X8X16_AS_X8    // CY_SMIF_HB_FLASH_KEEP
#define CY_SMIF_HB_FLASH_DEV_MULTIPLIER 0x00000001
#define CY_SMIF_HB_FLASH_DB_READ_MASK   0x000000FF
#define CY_SMIF_HB_FLASH_DEV_READ_MASK  0x000000FF
#define CY_SMIF_HB_FLASH_UNLOCK_ADDR1   0x00000AAA
#define CY_SMIF_HB_FLASH_UNLOCK_ADDR2   0x00000555
#define CY_SMIF_HB_FLASH_BYTES_PER_OP   0x00000001
#define CY_SMIF_HB_FLASH_CFI_UNLOCK_ADDR1 0x000000AA
typedef CY_SMIF_BYTE CY_SMIF_CY_SMIF_FLASHDATA;
#define CY_SMIF_HB_FLASH_BUF_SIZE_MULTIPLIER 2

#elif defined CY_SMIF_HB_FLASH_CONFIGURATION_X8X16_AS_X16   // CY_SMIF_HB_FLASH_KEEP
#define CY_SMIF_HB_FLASH_DEV_MULTIPLIER 0x00000001
#define CY_SMIF_HB_FLASH_DB_READ_MASK   0x0000FFFF
#define CY_SMIF_HB_FLASH_DEV_READ_MASK  0x0000FFFF
#define CY_SMIF_HB_FLASH_UNLOCK_ADDR1   0x00000555
#define CY_SMIF_HB_FLASH_UNLOCK_ADDR2   0x000002AA
#define CY_SMIF_HB_FLASH_BYTES_PER_OP   0x00000002
#define CY_SMIF_HB_FLASH_CFI_UNLOCK_ADDR1 0x00000055
typedef CY_SMIF_HB_FLASH_UINT16 CY_SMIF_FLASHDATA;
#define CY_SMIF_HB_FLASH_BUF_SIZE_MULTIPLIER 1

#elif defined CY_SMIF_HB_FLASH_CONFIGURATION_X16_AS_X32     // CY_SMIF_HB_FLASH_KEEP
#define CY_SMIF_HB_FLASH_DEV_MULTIPLIER 0x00010001
#define CY_SMIF_HB_FLASH_DB_READ_MASK   0xFFFFFFFF
#define CY_SMIF_HB_FLASH_DEV_READ_MASK  0x0000FFFF
#define CY_SMIF_HB_FLASH_UNLOCK_ADDR1   0x00000555
#define CY_SMIF_HB_FLASH_UNLOCK_ADDR2   0x000002AA
#define CY_SMIF_HB_FLASH_BYTES_PER_OP   0x00000004
#define CY_SMIF_HB_FLASH_CFI_UNLOCK_ADDR1 0x00000055
typedef CY_SMIF_HB_FLASH_UINT32 CY_SMIF_FLASHDATA;
#define CY_SMIF_HB_FLASH_BUF_SIZE_MULTIPLIER 1

#elif defined CY_SMIF_HB_FLASH_CONFIGURATION_X8X16_AS_X32   // CY_SMIF_HB_FLASH_KEEP
#define CY_SMIF_HB_FLASH_DEV_MULTIPLIER 0x00010001
#define CY_SMIF_HB_FLASH_DB_READ_MASK   0xFFFFFFFF
#define CY_SMIF_HB_FLASH_DEV_READ_MASK  0x0000FFFF
#define CY_SMIF_HB_FLASH_UNLOCK_ADDR1   0x00000555
#define CY_SMIF_HB_FLASH_UNLOCK_ADDR2   0x000002AA
#define CY_SMIF_HB_FLASH_BYTES_PER_OP   0x00000004
#define CY_SMIF_HB_FLASH_CFI_UNLOCK_ADDR1 0x00000055
typedef CY_SMIF_HB_FLASH_UINT32 CY_SMIF_FLASHDATA;
#define CY_SMIF_HB_FLASH_BUF_SIZE_MULTIPLIER 1

#elif defined CY_SMIF_HB_FLASH_CONFIGURATION_X8_AS_X8       // CY_SMIF_HB_FLASH_KEEP
#define CY_SMIF_HB_FLASH_DEV_MULTIPLIER 0x00000001
#define CY_SMIF_HB_FLASH_DB_READ_MASK   0x000000FF
#define CY_SMIF_HB_FLASH_DEV_READ_MASK  0x000000FF
#define CY_SMIF_HB_FLASH_UNLOCK_ADDR1   0x00000555
#define CY_SMIF_HB_FLASH_UNLOCK_ADDR2   0x000002AA
#define CY_SMIF_HB_FLASH_BYTES_PER_OP   0x00000001
#define CY_SMIF_HB_FLASH_CFI_UNLOCK_ADDR1 0x00000055
typedef CY_SMIF_BYTE CY_SMIF_FLASHDATA;
#define CY_SMIF_HB_FLASH_BUF_SIZE_MULTIPLIER 1

#elif defined CY_SMIF_HB_FLASH_CONFIGURATION_X8_AS_X16     // CY_SMIF_HB_FLASH_KEEP
#define CY_SMIF_HB_FLASH_DEV_MULTIPLIER 0x00000101
#define CY_SMIF_HB_FLASH_DB_READ_MASK   0x0000FFFF
#define CY_SMIF_HB_FLASH_DEV_READ_MASK  0x0000FFFF
#define CY_SMIF_HB_FLASH_UNLOCK_ADDR1   0x00000555
#define CY_SMIF_HB_FLASH_UNLOCK_ADDR2   0x000002AA
#define CY_SMIF_HB_FLASH_BYTES_PER_OP   0x00000002
#define CY_SMIF_HB_FLASH_CFI_UNLOCK_ADDR1 0x00000055
typedef CY_SMIF_HB_FLASH_UINT16 CY_SMIF_FLASHDATA;
#define CY_SMIF_HB_FLASH_BUF_SIZE_MULTIPLIER 2

#elif defined CY_SMIF_HB_FLASH_CONFIGURATION_X8_AS_X32     // CY_SMIF_HB_FLASH_KEEP
#define CY_SMIF_HB_FLASH_DEV_MULTIPLIER 0x01010101
#define CY_SMIF_HB_FLASH_DB_READ_MASK   0xFFFFFFFF
#define CY_SMIF_HB_FLASH_DEV_READ_MASK  0xFFFFFFFF
#define CY_SMIF_HB_FLASH_UNLOCK_ADDR1   0x00000555
#define CY_SMIF_HB_FLASH_UNLOCK_ADDR2   0x000002AA
#define CY_SMIF_HB_FLASH_BYTES_PER_OP   0x00000004
#define CY_SMIF_HB_FLASH_CFI_UNLOCK_ADDR1 0x00000055
typedef CY_SMIF_HB_FLASH_UINT32 CY_SMIF_FLASHDATA;
#define CY_SMIF_HB_FLASH_BUF_SIZE_MULTIPLIER 2
#endif     // CY_SMIF_HB_FLASH_KEEP              

typedef enum
{
    CY_SMIF_HB_LC5 = 0u,
    CY_SMIF_HB_LC6 = 1u,
    CY_SMIF_HB_LC7 = 2u,
    CY_SMIF_HB_LC8 = 3u,
    CY_SMIF_HB_LC9 = 4u,
    CY_SMIF_HB_LC10 = 5u,
    CY_SMIF_HB_LC11 = 6u,
    CY_SMIF_HB_LC12 = 7u,
    CY_SMIF_HB_LC13 = 8u,
    CY_SMIF_HB_LC14 = 9u,
    CY_SMIF_HB_LC15 = 10u,
    CY_SMIF_HB_LC16 = 11u,
    CY_SMIF_HB_LC3  = 14u,
    CY_SMIF_HB_LC4  = 15u,
} cy_en_smif_hb_latency_code_t;

typedef enum
{
    CY_SMIF_HB_READ_WRAPPED_BURST    = 0x80,
    CY_SMIF_HB_READ_CONTINUOUS_BURST = 0xA0,
} cy_en_smif_hb_rd_cmd_t;

typedef enum
{
    CY_SMIF_HB_WRITE_WRAPPED_BURST    = 0x00,
    CY_SMIF_HB_WRITE_CONTINUOUS_BURST = 0x20,
} cy_en_smif_hb_wt_cmd_t;

typedef enum
{
    CY_SMIF_HB_FLASH = 0,
    CY_SMIF_HB_SRAM  = 1,
} cy_en_smif_hb_dev_type_t;

typedef struct
{
    cy_en_smif_hb_rd_cmd_t         xipReadCmd;
    cy_en_smif_hb_wt_cmd_t         xipWriteCmd;
    bool                           mergeTimeoutEnable;
    cy_en_smif_dev_merge_timeout_t mergeTimeout;
    bool                           totalTimeoutEnable;
    uint16_t                       totalTimeout;
    uint32_t                       addr;
    cy_en_device_size_t            size;
    cy_en_smif_hb_latency_code_t   lc_hb;
    cy_en_smif_hb_dev_type_t       hbDevType;
} cy_stc_device_hb_config_t;

typedef struct
{
    uint64_t ColumnAddress     : 3;
    uint64_t Reserved0         : 10;
    uint64_t ByteEnableForRAM  : 2;
    uint64_t Reserved1         : 1;
    uint64_t PageAddress       : 24;
    uint64_t Reserved2         : 5;
    uint64_t BurstType         : 1;
    uint64_t Target            : 1;
    uint64_t ReadWrite         : 1;
    uint64_t Reserved3         : 16;
} stc_hb_com_addr_bitfield_t;

typedef union
{
    uint64_t       u64;
    uint16_t       u16[4];
    uint32_t       u32[2];
    stc_hb_com_addr_bitfield_t fld;
} un_Hyper_Com_Addr_t;

typedef enum
{
    CY_SMIF_HB_WRAPPED_BURST    = 0,
    CY_SMIF_HB_COUTINUOUS_BURST = 1,
} en_hb_bust_type_t;

typedef enum
{
    CY_SMIF_HB_TARGET_MEMORY   = 0,
    CY_SMIF_HB_TARGET_REGISTER = 1,
} en_hb_target_t;

typedef enum
{
    CY_SMIF_HB_WRITE   = 0,
    CY_SMIF_HB_READ = 1,
} en_hb_read_write_t;

/* public function prototypes */
cy_en_smif_status_t Cy_SMIF_InitDeviceHyperBus(volatile stc_SMIF_DEVICE_t *device, const cy_stc_device_hb_config_t *config);
cy_en_smif_status_t Cy_SMIF_HB_MMIO_Read(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        en_hb_bust_type_t burstType,
                                        uint32_t readAddress,
                                        uint32_t sizeInHalfWord,
                                        uint16_t buf[],
                                        cy_en_smif_hb_latency_code_t lcCode,
                                        bool isblockingMode,
                                        cy_stc_smif_context_t *context);

cy_en_smif_status_t Cy_SMIF_HB_MMIO_Write(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        en_hb_bust_type_t burstType,
                                        uint32_t writeAddress,
                                        uint32_t sizeInHalfWord,
                                        uint16_t buf[],
                                        bool isblockingMode,
                                        cy_stc_smif_context_t *context);
static uint32_t Cy_SMIF_HB_LatencyCodeToCycle(cy_en_smif_hb_latency_code_t code);

cy_en_smif_status_t CY_SMIF_ReadHYPERRAM_REG(volatile stc_SMIF_DEVICE_t *device, uint32_t reg_addr, uint16_t* reg_value);
cy_en_smif_status_t CY_SMIF_WriteHYPERRAM_REG(volatile stc_SMIF_DEVICE_t *device, uint32_t reg_addr, uint16_t reg_value);

/* Operation Functions */
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadOp
(
CY_SMIF_FLASHDATA * base_addr,      /* device base address is system */
CY_SMIF_ADDRESS offset          /* address offset from base address */
);

extern CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_WriteBufferProgramOp
(
CY_SMIF_FLASHDATA * base_addr,      /* device base address is system */
CY_SMIF_ADDRESS offset,         /* address offset from base address */
CY_SMIF_WORDCOUNT word_cnt,       /* number of words to program */
CY_SMIF_FLASHDATA *data_buf       /* buffer containing data to program */
);

extern CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_ProgramOp
(
CY_SMIF_FLASHDATA * base_addr,      /* device base address is system */
CY_SMIF_ADDRESS offset,         /* address offset from base address */
CY_SMIF_FLASHDATA write_data      /* variable containing data to program */
);

extern CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_SectorEraseOp
(
CY_SMIF_FLASHDATA * base_addr,      /* device base address is system */
CY_SMIF_ADDRESS offset          /* address offset from base address */
);

extern CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_ChipEraseOp
(
CY_SMIF_FLASHDATA * base_addr     /* device base address is system */
);

extern void CY_SMIF_HbFlash_InitCmd
(
CY_SMIF_FLASHDATA * base_addr     /* device base address in system */
);

extern void CY_SMIF_HbFlash_ResetCmd
(
CY_SMIF_FLASHDATA * base_addr     /* device base address in system */
);

extern void CY_SMIF_HbFlash_SectorEraseCmd
(
CY_SMIF_FLASHDATA * base_addr,      /* device base address in system */
CY_SMIF_ADDRESS offset          /* address offset from base address */
);

extern void CY_SMIF_HbFlash_ChipEraseCmd
(
CY_SMIF_FLASHDATA * base_addr     /* device base address in system */
);

extern void CY_SMIF_HbFlash_ProgramCmd
(
CY_SMIF_FLASHDATA * base_addr,      /* device base address in system */
CY_SMIF_ADDRESS offset,         /* address offset from base address */
CY_SMIF_FLASHDATA *pgm_data_ptr     /* variable containing data to program */
);

extern void CY_SMIF_HbFlash_SecSiSectorExitCmd
(
CY_SMIF_FLASHDATA * base_addr     /* device base address in system */
);
extern void CY_SMIF_HbFlash_SecSiSectorEntryCmd
(
CY_SMIF_FLASHDATA * base_addr,      /* device base address in system */
CY_SMIF_ADDRESS offset          /* address offset from base address */
);

extern void CY_SMIF_HbFlash_WriteToBufferCmd
(
CY_SMIF_FLASHDATA * base_addr,      /* device base address in system */
CY_SMIF_ADDRESS offset          /* address offset from base address */
);

extern void CY_SMIF_HbFlash_ProgramBufferToFlashCmd
(
CY_SMIF_FLASHDATA * base_addr,      /* device base address in system */
CY_SMIF_ADDRESS offset          /* address offset from base address */
);
extern void CY_SMIF_HbFlash_WriteBufferAbortResetCmd
(
CY_SMIF_FLASHDATA * base_addr     /* device base address in system */
);



CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadCfiWord
(
CY_SMIF_FLASHDATA * base_addr,      /* device base address is system */
CY_SMIF_ADDRESS offset          /* address offset from base address */
);
extern void CY_SMIF_HbFlash_CfiExitCmd
(
CY_SMIF_FLASHDATA * base_addr     /* device base address in system */
);
extern void CY_SMIF_HbFlash_CfiEntryCmd
(
CY_SMIF_FLASHDATA * base_addr,      /* device base address in system */
CY_SMIF_ADDRESS     offset        /* address offset from base address */
);

void CY_SMIF_HbFlash_StatusClear
(
CY_SMIF_FLASHDATA *  base_addr      /* device base address in system */
);

CY_SMIF_FLASHDATA CY_SMIF_HbFlash_StatusGetReg
(
CY_SMIF_FLASHDATA *  base_addr,      /* device base address in system */
CY_SMIF_ADDRESS      offset          /* address offset from base address */
);


CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_memcpy
(
CY_SMIF_FLASHDATA * base_addr,      /* device base address is system */
CY_SMIF_ADDRESS offset,         /* address offset from base address */
CY_SMIF_WORDCOUNT words_cnt,      /* number of words to program */
CY_SMIF_FLASHDATA *data_buf       /* buffer containing data to program */
);

extern void CY_SMIF_HbFlash_StatusRegClearCmd
(
CY_SMIF_FLASHDATA * base_addr     /* device base address in system */
);

extern void CY_SMIF_HbFlash_StatusRegReadCmd
(
CY_SMIF_FLASHDATA * base_addr     /* device base address in system */
);



void CY_SMIF_HbFlash_AutoselectEntryCmd
(
CY_SMIF_FLASHDATA * base_addr,      /* device base address in system */
CY_SMIF_ADDRESS offset          /* address offset from base address */
);

void CY_SMIF_HbFlash_AutoselectExitCmd
(
CY_SMIF_FLASHDATA * base_addr     /* device base address in system */
);

extern void CY_SMIF_HbFlash_ProgramSuspendCmd
(
CY_SMIF_FLASHDATA * base_addr     /* device base address in system */
);

extern void CY_SMIF_HbFlash_EraseSuspendCmd
(
CY_SMIF_FLASHDATA * base_addr     /* device base address in system */
);

extern void CY_SMIF_HbFlash_EraseResumeCmd
(
CY_SMIF_FLASHDATA * base_addr     /* device base address in system */
);

extern void CY_SMIF_HbFlash_ProgramResumeCmd
(
CY_SMIF_FLASHDATA * base_addr     /* device base address in system */
);
extern CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_EraseSuspendOp
(
CY_SMIF_FLASHDATA * base_addr     /* device base address is system */
);
extern CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_ProgramSuspendOp
(
CY_SMIF_FLASHDATA * base_addr     /* Device base address is system */
);

extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_Poll
(
CY_SMIF_FLASHDATA * base_addr,      /* device base address in system */
CY_SMIF_ADDRESS offset          /* address offset from base address */
);

extern uint32_t CY_SMIF_HbFlash_GetDeviceId
(
CY_SMIF_FLASHDATA * base_addr,   /* device base address in system */
CY_SMIF_ADDRESS offset
);

extern void CY_SMIF_HbFlash_BlankCheckCmd
(
CY_SMIF_FLASHDATA * base_addr,    /* device base address in system */
CY_SMIF_ADDRESS offset        /* address offset from base address */
);

extern CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_BlankCheckOp
(
CY_SMIF_FLASHDATA * base_addr,    /* device base address in system */
CY_SMIF_ADDRESS offset        /* address offset from base address */
);

#ifdef CY_SMIF_TRACE
extern void FlashWrite(CY_SMIF_FLASHDATA * addr, CY_SMIF_ADDRESS offset, CY_SMIF_FLASHDATA data);
extern CY_SMIF_FLASHDATA FlashRead(CY_SMIF_FLASHDATA * addr, CY_SMIF_ADDRESS offset);
#endif

#ifdef CY_SMIF_EXTEND_ADDR
extern void FlashWrite_Extend(CY_SMIF_FLASHDATA *base_addr, CY_SMIF_ADDRESS offset, CY_SMIF_FLASHDATA data);
extern CY_SMIF_FLASHDATA FlashRead_Extend(CY_SMIF_FLASHDATA *base_addr, CY_SMIF_ADDRESS offset);
#endif

#ifdef CY_SMIF_USER_SPECIFIC_CMD
extern void FlashWriteUserCmd(CY_SMIF_ADDRESS address, CY_SMIF_FLASHDATA data);
extern CY_SMIF_FLASHDATA FlashReadUserCmd(CY_SMIF_ADDRESS address);
#endif

/**********************************************************
* Sector protection functions prototype.
**********************************************************/

extern void CY_SMIF_HbFlash_LockRegEntryCmd     
( 
 CY_SMIF_FLASHDATA *   base_addr    /* device base address in system */ 
);
extern void CY_SMIF_HbFlash_LockRegBitsProgramCmd 
( 
 CY_SMIF_FLASHDATA *   base_addr,   /* device base address in system */
 CY_SMIF_FLASHDATA value
);
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_LockRegBitsReadCmd 
( 
 CY_SMIF_FLASHDATA *   base_addr    /* device base address in system */
);
extern void CY_SMIF_HbFlash_LockRegExitCmd      
( 
 CY_SMIF_FLASHDATA *   base_addr    /* device base address in system */
);


extern void CY_SMIF_HbFlash_PasswordProtectionEntryCmd
( 
 CY_SMIF_FLASHDATA *   base_addr    /* device base address in system */
);
extern void CY_SMIF_HbFlash_PasswordProtectionProgramCmd
( 
 CY_SMIF_FLASHDATA * base_addr,     /* device base address in system */
 CY_SMIF_ADDRESS offset,        /* address offset from base address */
 CY_SMIF_FLASHDATA pwd 
);
extern void CY_SMIF_HbFlash_PasswordProtectionReadCmd
( 
 CY_SMIF_FLASHDATA *    base_addr,    /* device base address in system */
 CY_SMIF_FLASHDATA *pwd0,       /* Password 0 */
 CY_SMIF_FLASHDATA *pwd1,       /* Password 1 */
 CY_SMIF_FLASHDATA *pwd2,       /* Password 2 */
 CY_SMIF_FLASHDATA *pwd3        /* Password 3 */
);
extern void CY_SMIF_HbFlash_PasswordProtectionUnlockCmd
( 
 CY_SMIF_FLASHDATA *  base_addr,    /* device base address in system */
 CY_SMIF_FLASHDATA pwd0,        /* Password 0 */
 CY_SMIF_FLASHDATA pwd1,        /* Password 1 */
 CY_SMIF_FLASHDATA pwd2,        /* Password 2 */
 CY_SMIF_FLASHDATA pwd3         /* Password 3 */
);
extern void CY_SMIF_HbFlash_PasswordProtectionExitCmd
( 
 CY_SMIF_FLASHDATA *  base_addr     /* device base address in system */
);

extern void CY_SMIF_HbFlash_PpbEntryCmd       
( 
 CY_SMIF_FLASHDATA *   base_addr,   /* device base address in system */
 CY_SMIF_ADDRESS offset 
);
extern void CY_SMIF_HbFlash_PpbProgramCmd     
( 
 CY_SMIF_FLASHDATA *   base_addr,   /* device base address in system */
 CY_SMIF_ADDRESS   offset       /* address offset from base address */
);
extern void CY_SMIF_HbFlash_PpbAllEraseCmd      
( 
 CY_SMIF_FLASHDATA *   base_addr    /* device base address in system */
);
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_PpbStatusReadCmd 
( 
 CY_SMIF_FLASHDATA *   base_addr,   /* device base address in system */
 CY_SMIF_ADDRESS   offset       /* address offset from base address */
);
extern void CY_SMIF_HbFlash_PpbExitCmd        
( 
 CY_SMIF_FLASHDATA *   base_addr    /* device base address in system */
);
extern void CY_SMIF_HbFlash_PpbLockBitEntryCmd    
( 
 CY_SMIF_FLASHDATA *   base_addr    /* device base address in system */
);
extern void CY_SMIF_HbFlash_PpbLockBitSetCmd    
( 
 CY_SMIF_FLASHDATA *   base_addr    /* device base address in system */
);
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_PpbLockBitReadCmd  
( 
 CY_SMIF_FLASHDATA *   base_addr    /* device base address in system */
);
extern void CY_SMIF_HbFlash_PpbLockBitExitCmd   
(
 CY_SMIF_FLASHDATA *   base_addr    /* device base address in system */
);
extern void CY_SMIF_HbFlash_DybEntryCmd       
( 
 CY_SMIF_FLASHDATA *   base_addr    /* device base address in system */
);
extern void CY_SMIF_HbFlash_DybSetCmd       
( 
 CY_SMIF_FLASHDATA *   base_addr,   /* device base address in system */
 CY_SMIF_ADDRESS   offset       /* address offset from base address */
);
extern void CY_SMIF_HbFlash_DybClrCmd       
( 
 CY_SMIF_FLASHDATA *   base_addr,   /* device base address in system */
 CY_SMIF_ADDRESS   offset       /* address offset from base address */
);
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_DybReadCmd     
( CY_SMIF_FLASHDATA *   base_addr,    /* device base address in system */
 CY_SMIF_ADDRESS   offset       /* address offset from base address */
);
extern void CY_SMIF_HbFlash_DybExitCmd        
( 
 CY_SMIF_FLASHDATA *   base_addr    /* device base address in system */
);
extern CY_SMIF_FLASHDATA  CY_SMIF_HbFlash_PpbLockBitReadOp  
( 
 CY_SMIF_FLASHDATA *  base_addr   /* device base address in system */
);
extern int CY_SMIF_HbFlash_PpbAllEraseOp      
( 
 CY_SMIF_FLASHDATA *   base_addr    /* device base address in system */
);
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_PpbStatusReadOp  
( 
 CY_SMIF_FLASHDATA *  base_addr,    /* device base address in system */
 CY_SMIF_ADDRESS offset
);
extern int CY_SMIF_HbFlash_PpbProgramOp       
( 
 CY_SMIF_FLASHDATA *  base_addr,    /* device base address in system */
 CY_SMIF_ADDRESS offset         /* address offset from base address */
);
extern int CY_SMIF_HbFlash_PpbLockBitSetOp      
( 
 CY_SMIF_FLASHDATA *   base_addr    /* device base address in system */
);

extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_LockRegBitsReadOp  
( 
 CY_SMIF_FLASHDATA *  base_addr   /* device base address in system */
);

extern int CY_SMIF_HbFlash_LockRegBitsProgramOp   
( 
 CY_SMIF_FLASHDATA *  base_addr,    /* device base address in system */
 CY_SMIF_FLASHDATA value
);


extern void CY_SMIF_HbFlash_EnterDeepPowerDown
(
 CY_SMIF_FLASHDATA *base_addr
);

extern void CY_SMIF_HbFlash_MeasureTemperature
(
 CY_SMIF_FLASHDATA *base_addr
);

extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadTemperatureReg 
(
 CY_SMIF_FLASHDATA *base_addr
);

extern void CY_SMIF_HbFlash_ProgramPORTimerReg
(
 CY_SMIF_FLASHDATA *base_addr,
 CY_SMIF_FLASHDATA portime      /* Power On Reset Time */
);

extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadPORTimerReg
(
 CY_SMIF_FLASHDATA *base_addr
);

extern void CY_SMIF_HbFlash_LoadInterruptConfigReg 
(
 CY_SMIF_FLASHDATA *base_addr,
 CY_SMIF_FLASHDATA icr        /* Interrupt Configuration Register */
);

extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadInterruptConfigReg
(
 CY_SMIF_FLASHDATA *base_addr
);

extern void CY_SMIF_HbFlash_LoadInterruptStatusReg
(
 CY_SMIF_FLASHDATA *base_addr, 
 CY_SMIF_FLASHDATA isr
);

extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadInterruptStatusReg
(
 CY_SMIF_FLASHDATA *base_addr
);

extern void CY_SMIF_HbFlash_LoadVolatileConfigReg
(
 CY_SMIF_FLASHDATA *base_addr,
 CY_SMIF_FLASHDATA vcr
);

extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadVolatileConfigReg
(
 CY_SMIF_FLASHDATA *base_addr
);

CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_ProgramVolatileConfigRegOp
(
 CY_SMIF_FLASHDATA *base_addr,
 CY_SMIF_FLASHDATA vcr
);

extern void CY_SMIF_HbFlash_ProgramNonVolatileConfigReg
(
 CY_SMIF_FLASHDATA *base_addr, 
 CY_SMIF_FLASHDATA nvcr
);

extern void CY_SMIF_HbFlash_EraseNonVolatileConfigReg
(
 CY_SMIF_FLASHDATA *base_addr
);

extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadNonVolatileConfigReg
(
 CY_SMIF_FLASHDATA *base_addr
);

CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_ProgramNonVolatileConfigRegOp
(
 CY_SMIF_FLASHDATA *base_addr,
 CY_SMIF_FLASHDATA nvcr
);

extern void CY_SMIF_HbFlash_EvaluateEraseStatus
(
 CY_SMIF_FLASHDATA *base_addr, 
 CY_SMIF_ADDRESS   offset
);

extern void CY_SMIF_HbFlash_ECCStatusEnterCmd
(
 CY_SMIF_FLASHDATA *base_addr
);

extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ECCStatusReadCmd
(
 CY_SMIF_FLASHDATA *base_addr, 
 CY_SMIF_ADDRESS   offset
);

extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ECCErrorLowerAddrRegReadCmd
(
 CY_SMIF_FLASHDATA *base_addr
);

extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ECCErrorUpperAddrRegReadCmd
(
 CY_SMIF_FLASHDATA *base_addr
);

extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ECCReadErrorDetectionCounterCmd
(
 CY_SMIF_FLASHDATA *base_addr
);

extern void CY_SMIF_HbFlash_ECCClearErrorDetectionCounterCmd
(
 CY_SMIF_FLASHDATA *base_addr
);

extern void CY_SMIF_HbFlash_ECCExitCmd
(
 CY_SMIF_FLASHDATA *base_addr
);

extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ECCStatusReadOp
(
 CY_SMIF_FLASHDATA *base_addr, 
 CY_SMIF_ADDRESS   offset
);

extern void CY_SMIF_HbFlash_CRCEnterCmd
(
 CY_SMIF_FLASHDATA *base_addr
);

extern void CY_SMIF_HbFlash_LoadCRCStartAddrCmd
(
 CY_SMIF_FLASHDATA *base_addr, 
 CY_SMIF_ADDRESS   offset
);

extern void CY_SMIF_HbFlash_LoadCRCEndAddrCmd
(
 CY_SMIF_FLASHDATA *base_addr, 
 CY_SMIF_ADDRESS   offset
);

extern void CY_SMIF_HbFlash_CRCSuspendCmd
(
 CY_SMIF_FLASHDATA *base_addr
);

extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_CRCArrayReadCmd
(
 CY_SMIF_FLASHDATA *base_addr, 
 CY_SMIF_ADDRESS   offset
);

extern void CY_SMIF_HbFlash_CRCResumeCmd
(
 CY_SMIF_FLASHDATA *base_addr
);

extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadCheckvalueLowResultRegCmd
(
 CY_SMIF_FLASHDATA *base_addr
);

extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadCheckvalueHighResultRegCmd
(
 CY_SMIF_FLASHDATA *base_addr
);

extern void CY_SMIF_HbFlash_CRCExitCmd
(
 CY_SMIF_FLASHDATA *base_addr
);

typedef struct
{
    uint16_t SectorEraseSts     : 1;
    uint16_t SectorLockSts      : 1;
    uint16_t ProgramSuspendSts  : 1;
    uint16_t WriteBufAbortSts   : 1;
    uint16_t ProgramSts         : 1;
    uint16_t EraseSts           : 1;
    uint16_t EraseSuspendSts    : 1;
    uint16_t DeviceReady        : 1;
    uint16_t CRC_SuspendSts     : 1;
    uint16_t Reserved           : 7;
} stc_StatusField_t;

typedef union
{
    uint16_t       u16;
    stc_StatusField_t fld;
} un_HyperFlashStatusReg_t;

typedef struct
{
    uint16_t burstLength       : 2;
    uint16_t RDS_stallControll : 1;
    uint16_t Reserved0         : 1;
    uint16_t readLatency       : 4;
    uint16_t sectorMapping     : 2;
    uint16_t SSR_freeze        : 1;
    uint16_t VCR_freeze        : 1;
    uint16_t driveStrength     : 3;
    uint16_t Reserved1         : 1;
} stc_vcrField_t;

typedef union
{
    uint16_t       u16;
    stc_vcrField_t fld;
} un_HyperFlashVCR_t;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CY_SMIF_HB_FLASH_H  */


