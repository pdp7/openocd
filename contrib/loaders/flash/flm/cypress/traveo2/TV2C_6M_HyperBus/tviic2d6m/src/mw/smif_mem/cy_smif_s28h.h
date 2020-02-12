/***************************************************************************//**
* \file cy_smif_s28h.h
* \version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
*
* Provides an API declaration of the Cypress 28HL HSSPI series driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2018, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_SMIF_S28H_H)
#define CY_SMIF_S28H_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "cy_device_headers.h"
#include "smif/cy_smif.h"
#include "cy_project.h"
#include "cy_smif_device_common.h"

typedef enum
{
	/*****************************/
	/*       SPI (1S-1S-1S)      */
	/*****************************/
	/* Read Device ID */
	CY_28HL_CMD_SPI_RDIDN_0_0   = 0x009F, // Read manufacturer and device identification
	CY_28HL_CMD_SPI_RSFDP_3_0   = 0x005A, // Read JEDEC Serial Flash Discoverable Parameters
	CY_28HL_CMD_SPI_RDUID_0_0   = 0x004C, // Read Unique ID
	/* Register Access */
	CY_28HL_CMD_SPI_RDSR1_0_0   = 0x0005, // Read Status Register 1
	CY_28HL_CMD_SPI_RDSR2_0_0   = 0x0007, // Read Status Register-2
	CY_28HL_CMD_SPI_RDARG_C_0   = 0x0065, // Read Any Register
	CY_28HL_CMD_SPI_WRENB_0_0   = 0x0006, // Write Enable
	CY_28HL_CMD_SPI_WRDIS_0_0   = 0x0004, // Write Disable
	CY_28HL_CMD_SPI_WRARG_C_1   = 0x0071, // Write Any Register
	CY_28HL_CMD_SPI_CLPEF_0_0   = 0x0082, // Clear Program and Erase Failure Flags
	/* ECC */
	CY_28HL_CMD_SPI_RDECC_4_0   = 0x0019, // Read ECC Status
	CY_28HL_CMD_SPI_CLECC_0_0   = 0x001B, // Clear ECC Status Register
	/* CRC */
	CY_28HL_CMD_SPI_DICHK_4_1   = 0x005B, // Data Integrity Check
	/* Read Flash Array */
	CY_28HL_CMD_SPI_RDAY1_C_0   = 0x0003, // Read
	CY_28HL_CMD_SPI_RDAY1_4_0   = 0x0013, // Read
	CY_28HL_CMD_SPI_RDAY2_C_0   = 0x000B, // Read Fast
	/* Program Flash Array */
	CY_28HL_CMD_SPI_PRPGE_4_1   = 0x0012, // Program Page
	/* Erase Flash Array */
	CY_28HL_CMD_SPI_ER004_4_0   = 0x0021, // Erase 4-KB Sector
	CY_28HL_CMD_SPI_ER256_4_0   = 0x00DC, // Erase 256-KB Sector
	CY_28HL_CMD_SPI_ERCHP_0_0   = 0x0060, // Erase Chip (or 0x00C7)
	CY_28HL_CMD_SPI_EVERS_4_0   = 0x00D0, // Evaluate Erase Status
	CY_28HL_CMD_SPI_SEERC_4_0   = 0x005D, // Sector Erase Count
	/* Suspend / Resume */
	CY_28HL_CMD_SPI_SPEPD_0_0   = 0x00B0, // Suspend Erase / Program / Data Integrity Check
	CY_28HL_CMD_SPI_RSEPD_0_0   = 0x0030, // Resume Erase / Program / Data Integrity Check
	/* Secure Silicon Region */
	CY_28HL_CMD_SPI_PRSSR_4_1   = 0x0042, // Program Secure Silicon Region
	CY_28HL_CMD_SPI_RDSSR_4_0   = 0x004B, // Read Secure Silicon Region
	/* Advanced Sector Protection */
	CY_28HL_CMD_SPI_RDDYB_4_0   = 0x00E0, // Read Dynamic Protection Bit
	CY_28HL_CMD_SPI_WRDYB_4_1   = 0x00E1, // Write Dynamic Protection Bit
	CY_28HL_CMD_SPI_RDPPB_4_0   = 0x00E2, // Read Persistent Protection Bit
	CY_28HL_CMD_SPI_PRPPB_4_0   = 0x00E3, // Program Persistent Protection Bit
	CY_28HL_CMD_SPI_ERPPB_0_0   = 0x00E4, // Erase Persistent Protection Bit
	CY_28HL_CMD_SPI_WRPLB_0_0   = 0x00A6, // Write PPB Protection Lock Bit
	CY_28HL_CMD_SPI_RDPLB_0_0   = 0x00A7, // Read Password Protection Mode Lock Bit
	CY_28HL_CMD_SPI_PWDUL_0_1   = 0x00E9, // Password Unlock
	/* Reset */
	CY_28HL_CMD_SPI_SRSTE_0_0   = 0x0066, // Software Reset Enable
	CY_28HL_CMD_SPI_SFRST_0_0   = 0x0099, // Software Reset
	/* Deep Power Down */
	CY_28HL_CMD_SPI_ENDPD_0_0   = 0x00B9, // Enter Deep Power Down Mode
	/******************************/
	/* Octal (8S-8S-8S, 8D-8D-8D) */
	/******************************/
	/* Read Device ID */
	CY_28HL_CMD_OCTAL_RDIDN_4_0 = 0x9F9F, // Read manufacturer and device identification
	CY_28HL_CMD_OCTAL_RSFDP_4_0 = 0x5A5A, // Read JEDEC Serial Flash Discoverable Parameters
	CY_28HL_CMD_OCTAL_RDUID_4_0 = 0x4C4C, // Read Unique ID
	/* Register Access */
	CY_28HL_CMD_OCTAL_RDSR1_4_0 = 0x0505, // Read Status Register 1
	CY_28HL_CMD_OCTAL_RDSR2_4_0 = 0x0707, // Read Status Register 2
	CY_28HL_CMD_OCTAL_RDARG_4_0 = 0x6565, // Read Any Register
	CY_28HL_CMD_OCTAL_WRENB_0_0 = 0x0606, // Write Enable
	CY_28HL_CMD_OCTAL_WRDIS_0_0 = 0x0404, // Write Disable
	CY_28HL_CMD_OCTAL_WRARG_4_1 = 0x7171, // Write Any Register
	CY_28HL_CMD_OCTAL_CLPEF_0_0 = 0x8282, // Clear Program and Erase Failure Flags
	/* ECC */
	CY_28HL_CMD_OCTAL_RDECC_4_0 = 0x1919, // Read ECC Status
	CY_28HL_CMD_OCTAL_CLECC_0_0 = 0x1B1B, // Clear ECC Status Register
	/* CRC */
	CY_28HL_CMD_OCTAL_RDCRC_4_0 = 0x6464, // Read Interface CRC Register
	CY_28HL_CMD_OCTAL_DICHK_4_1 = 0x5B5B, // Data Integrity Check
	/* Read Flash Array */
	CY_28HL_CMD_OCTAL_RDAY1_4_0 = 0xECEC, // Read Octal SDR
	CY_28HL_CMD_OCTAL_RDAY2_4_0 = 0xEEEE, // Read Octal DDR
	/* Program Flash Array */
	CY_28HL_CMD_OCTAL_PRPGE_4_1 = 0x1212, // Program Page
	/* Erase Flash Array */
	CY_28HL_CMD_OCTAL_ER004_4_0 = 0x2121, // Erase 4-KB Sector
	CY_28HL_CMD_OCTAL_ER256_4_0 = 0xDCDC, // Erase 256-KB Sector
	CY_28HL_CMD_OCTAL_ERCHP_0_0 = 0x6060, // Erase Chip (or 0xC7C7)
	CY_28HL_CMD_OCTAL_EVERS_4_0 = 0xD0D0, // Evaluate Erase Status
	CY_28HL_CMD_OCTAL_SEERC_4_0 = 0x5D5D, // Sector Erase Count
	/* Suspend / Resume */
	CY_28HL_CMD_OCTAL_SPEPD_0_0 = 0xB0B0, // Suspend Erase / Program / Data Integrity Check
	CY_28HL_CMD_OCTAL_RSEPD_0_0 = 0x3030, // Resume Erase / Program / Data Integrity Check
	/* Secure Silicon Region */
	CY_28HL_CMD_OCTAL_PRSSR_4_1 = 0x4242, // Program Secure Silicon Region
	CY_28HL_CMD_OCTAL_RDSSR_4_0 = 0x4B4B, // Read Secure Silicon Region
	/* Advanced Sector Protection */
	CY_28HL_CMD_OCTAL_RDDYB_4_0 = 0xE0E0, // Read Dynamic Protection Bit
	CY_28HL_CMD_OCTAL_WRDYB_4_1 = 0xE1E1, // Write Dynamic Protection Bit
	CY_28HL_CMD_OCTAL_RDPPB_4_0 = 0xE2E2, // Read Persistent Protection Bit
	CY_28HL_CMD_OCTAL_PRPPB_4_0 = 0xE3E3, // Program Persistent Protection Bit
	CY_28HL_CMD_OCTAL_ERPPB_0_0 = 0xE4E4, // Erase Persistent Protection Bit
	CY_28HL_CMD_OCTAL_WRPLB_0_0 = 0x2C2C, // Write PPB Protection Lock Bit
	CY_28HL_CMD_OCTAL_RDPLB_4_0 = 0x2D2D, // Read  Password Protection Mode Lock Bit
	CY_28HL_CMD_OCTAL_PWDUL_4_1 = 0xE9E9, // Password Unlock
	/* Reset */
	CY_28HL_CMD_OCTAL_SRSTE_0_0 = 0x6666, // Software Reset Enable
	CY_28HL_CMD_OCTAL_SFRST_0_0 = 0x9999, // Software Reset
	/* Deep Power Down */
	CY_28HL_CMD_OCTAL_ENDPD_0_0 = 0xB9B9, // Enter Deep Power Down Mode
} en_cy_smif_28hl_cmd_t;

typedef struct
{
	uint8_t u1RDYBSY : 1;
	uint8_t u1WRPGEN : 1;
	uint8_t u3LBPROT : 3;
	uint8_t u1ERSERR : 1;
	uint8_t u1PRGERR : 1;
	uint8_t u1RESRVD : 1;
} stc_cy_smif_28hl_STR1_t;

typedef struct
{
	uint8_t u1PROGMS : 1;
	uint8_t u1ERASES : 1;
	uint8_t u1SESTAT : 1;
	uint8_t u1DICRCA : 1;
	uint8_t u1DICRCS : 1;
	uint8_t u3RESRVD : 3;
} stc_cy_smif_28hl_STR2_t;

typedef struct
{
	uint8_t u1TLPROT  : 1;
	uint8_t u1RESRVD0 : 1;
	uint8_t u1TB4KBS  : 1;
	uint8_t u1RESRVD1 : 1;
	uint8_t u1PLPROT  : 1;
	uint8_t u1TBPROT  : 1;
	uint8_t u1SP4KBS  : 1;
	uint8_t u1RESRVD2 : 1;
} stc_cy_smif_28hl_CFR1_t;

typedef struct
{
	uint8_t u4MEMLAT : 4;
	uint8_t u3RESRVD : 3;
	uint8_t u1ADRBYT : 1;
} stc_cy_smif_28hl_CFR2_t;

typedef struct
{
	uint8_t u3RESRVD : 3;
	uint8_t u1UNHYSA : 1;
	uint8_t u1PGMBUF : 1;
	uint8_t u1BLKCHK : 1;
	uint8_t u2VRGLAT : 2;
} stc_cy_smif_28hl_CFR3_t;

typedef struct
{
	uint8_t u2RBSTWL : 2;
	uint8_t u1DPDPOR : 1;
	uint8_t u1ECC12S : 1;
	uint8_t u1RBSTWP : 1;
	uint8_t u3IOIMPD : 3;
} stc_cy_smif_28hl_CFR4_t;

typedef struct
{
	uint8_t u1OPI_IT : 1;
	uint8_t u1SDRDDR : 1;
	uint8_t u4RESRVD : 5;
	uint8_t u1DSOSDR : 1;
} stc_cy_smif_28hl_CFR5_t;

typedef struct
{
	uint8_t u1ITCRCE : 1;
	uint8_t u7RESVRD : 7;
} stc_cy_smif_28hl_ICEV_t;

typedef struct
{
	uint32_t u32ITCRCV : 32;
} stc_cy_smif_28hl_ICRV_t;

typedef struct
{
	uint32_t u32DTCRCV : 32;
} stc_cy_smif_28hl_DCRV_t;

typedef struct
{
	uint8_t u3RESRVD0 : 3;
	uint8_t u1ECC1BT  : 1;
	uint8_t u1ECC2BT  : 1;
	uint8_t u3RESRVD1 : 3;
} stc_cy_smif_28hl_ESCV_t;

typedef struct
{
	uint32_t u32ECCATP : 32;
} stc_cy_smif_28hl_EATV_t;

typedef struct
{
	uint16_t u16ECCCNT : 16;
} stc_cy_smif_28hl_ECTV_t;

typedef struct
{
	uint16_t u1ASPPRM  : 1;
	uint16_t u1ASPPER  : 1;
	uint16_t u1ASPPWD  : 1;
	uint16_t u1ASPPPB  : 1;
	uint16_t u1ASPDYB  : 1;
	uint16_t u1ASPRDP  : 1;
	uint16_t u10RESRVD : 10;
} stc_cy_smif_28hl_ASPO_t;

typedef struct
{
	uint64_t u64ASPPRM  : 64;
} stc_cy_smif_28hl_PWDO_t;

typedef struct
{
	uint8_t u1PPBLCK  : 1;
	uint8_t u7RESVRD  : 7;
} stc_cy_smif_28hl_PPLV_t;

typedef struct
{
	uint8_t u8PPBACS  : 8;
} stc_cy_smif_28hl_PPAV_t;

typedef struct
{
	uint8_t u8DYBACS  : 8;
} stc_cy_smif_28hl_DYAV_t;

typedef struct
{
	uint32_t u1ATBTEN : 1;
	uint32_t u8STDLY  : 8;
	uint32_t u23STADR : 23;
} stc_cy_smif_28hl_ATBN_t;

typedef struct
{
	uint32_t u23SECVAL : 23;
	uint32_t u1SECCPT  : 1;
	uint32_t u8RESVRD  : 8;
} stc_cy_smif_28hl_SECV_t;

typedef struct
{
	uint8_t u1ECC1BT  : 1;
	uint8_t u1ECC2BT  : 1;
	uint8_t u2RESRVD0 : 2;
	uint8_t u1REYBSY  : 1;
	uint8_t u2RESRVD1 : 2;
	uint8_t u1INTBEN  : 1;
} stc_cy_smif_28hl_INCV_t;

typedef struct
{
	uint8_t u1ECC1BT  : 1;
	uint8_t u1ECC2BT  : 1;
	uint8_t u2RESRVD0 : 2;
	uint8_t u1REYBSY  : 1;
	uint8_t u3RESRVD1 : 3;
} stc_cy_smif_28hl_INSV_t;

typedef struct
{
	uint16_t u1EPTEBx  : 1;
	uint16_t u1ERGNTx  : 1;
	uint16_t u8EPTADx  : 8;
	uint16_t u6RESRVD  : 6;
} stc_cy_smif_28hl_EFX1TO4_t;

typedef struct
{
	uint16_t u1WRLVEN  : 1;
	uint16_t u1GBLSEL  : 1;
	uint16_t u14RESRVD : 14;
} stc_cy_smif_28hl_EFX0_t;



typedef union
{
	uint8_t                 u8;
	stc_cy_smif_28hl_STR1_t field;
} un_cy_smif_28hl_STR1_t;

typedef union
{
	uint8_t                 u8;
	stc_cy_smif_28hl_STR2_t field;
} un_cy_smif_28hl_STR2_t;

typedef union
{
	uint8_t                 u8;
	stc_cy_smif_28hl_CFR1_t field;
} un_cy_smif_28hl_CFR1_t;

typedef union
{
	uint8_t                 u8;
	stc_cy_smif_28hl_CFR2_t field;
} un_cy_smif_28hl_CFR2_t;

typedef union
{
	uint8_t                 u8;
	stc_cy_smif_28hl_CFR3_t field;
} un_cy_smif_28hl_CFR3_t;

typedef union
{
	uint8_t                 u8;
	stc_cy_smif_28hl_CFR4_t field;
} un_cy_smif_28hl_CFR4_t;

typedef union
{
	uint8_t                 u8;
	stc_cy_smif_28hl_CFR5_t field;
} un_cy_smif_28hl_CFR5_t;

typedef union
{
	uint8_t                 u8;
	stc_cy_smif_28hl_ICEV_t field;
} un_cy_smif_28hl_ICEV_t;

typedef union
{
	uint32_t                u32;
	stc_cy_smif_28hl_ICRV_t field;
} un_cy_smif_28hl_ICRV_t;

typedef union
{
	uint32_t                u32;
	stc_cy_smif_28hl_DCRV_t field;
} un_cy_smif_28hl_DCRV_t;

typedef union
{
	uint8_t                 u8;
	stc_cy_smif_28hl_ESCV_t field;
} un_cy_smif_28hl_ESCV_t;

typedef union
{
	uint32_t                u32 ;
	stc_cy_smif_28hl_EATV_t field;
} un_cy_smif_28hl_EATV_t;

typedef union
{
	uint16_t                u16;
	stc_cy_smif_28hl_ECTV_t field;
} un_cy_smif_28hl_ECTV_t;

typedef union
{
	uint16_t                u16;
	stc_cy_smif_28hl_ASPO_t field;
} un_cy_smif_28hl_ASPO_t;

typedef union
{
	uint64_t                u64;
	stc_cy_smif_28hl_PWDO_t field;
} un_cy_smif_28hl_PWDO_t;

typedef union
{
	uint8_t                 u8;
	stc_cy_smif_28hl_PPLV_t field;
} un_cy_smif_28hl_PPLV_t;

typedef union
{
	uint8_t                 u8;
	stc_cy_smif_28hl_PPAV_t field;
} un_cy_smif_28hl_PPAV_t;

typedef union
{
	uint8_t                 u8;
	stc_cy_smif_28hl_DYAV_t field;
} un_cy_smif_28hl_DYAV_t;

typedef union
{
	uint8_t                 u8;
	stc_cy_smif_28hl_ATBN_t field;
} un_cy_smif_28hl_ATBN_t;

typedef union
{
	uint32_t                u32;
	stc_cy_smif_28hl_SECV_t field;
} un_cy_smif_28hl_SECV_t;

typedef union
{
	uint8_t                 u8;
	stc_cy_smif_28hl_INCV_t field;
} un_cy_smif_28hl_INCV_t;

typedef union
{
	uint8_t                 u8;
	stc_cy_smif_28hl_INSV_t field;
} un_cy_smif_28hl_INSV_t;

typedef union
{
	uint16_t                   u16;
	stc_cy_smif_28hl_EFX1TO4_t field;
} un_cy_smif_28hl_EFX1TO4_t;

typedef union
{
	uint16_t                  u16;
	stc_cy_smif_28hl_EFX0_t field;
} un_cy_smif_28hl_EFX0_t;

typedef enum
{
	CY_SMIF_S28H_ID_3ADDR_READ           = 0u, // Read (3-byte address)
	CY_SMIF_S28H_ID_4ADDR_READ0          = 1u, // Read (4-byte address)
	CY_SMIF_S28H_ID_4ADDR_READ1          = 2u, // Read (4-byte address)
	CY_SMIF_S28H_ID_3ADDR_FAST_READ      = 3u, // Fast Read (3-byte address)
	CY_SMIF_S28H_ID_4ADDR_FAST_READ      = 4u, // Fast Read (4-byte address)
	CY_SMIF_S28H_ID_OCTAL_4ADDR_SDR_READ = 5u, // Octal Read (4-byte address)
	CY_SMIF_S28H_ID_OCTAL_4ADDR_DDR_READ = 6u, // Octal Read (4-byte address)
	CY_SMIF_S28H_READ_ID_NUM,
} cy_en_smif_s28h_rd_cmdid_t;

typedef enum
{
	CY_SMIF_S28H_ID_PP           = 0u, // Page Program (4-byte address)
	CY_SMIF_S28H_ID_OCTAL_SDR_PP = 1u, // Page Program (4-byte address)
	CY_SMIF_S28H_ID_OCTAL_DDR_PP = 2u, // Page Program (4-byte address)
	CY_SMIF_S28H_WRITE_ID_NUM,
} cy_en_smif_s28h_wt_cmdid_t;

typedef enum
{
	CY_SMIF_S28H_RD_LATENCY0 = 0u,
	CY_SMIF_S28H_RD_LATENCY1 = 1u,
	CY_SMIF_S28H_RD_LATENCY2 = 2u,
	CY_SMIF_S28H_RD_LATENCY3 = 3u,
	CY_SMIF_S28H_RD_LATENCY4 = 4u,
	CY_SMIF_S28H_RD_LATENCY5 = 5u,
	CY_SMIF_S28H_RD_LATENCY6 = 6u,
	CY_SMIF_S28H_RD_LATENCY7 = 7u,
	CY_SMIF_S28H_RD_LATENCY8 = 8u,
	CY_SMIF_S28H_RD_LATENCY9 = 9u,
	CY_SMIF_S28H_RD_LATENCY10 = 10u,
	CY_SMIF_S28H_RD_LATENCY11 = 11u,
	CY_SMIF_S28H_RD_LATENCY12 = 12u,
	CY_SMIF_S28H_RD_LATENCY13 = 13u,
	CY_SMIF_S28H_RD_LATENCY14 = 14u,
	CY_SMIF_S28H_RD_LATENCY15 = 15u,
} cy_en_smif_s28hl_read_latency_code_t;
#define CY_SMIF_S28H_READ_LATENCY_CODE_MAX (16u)
#define CY_SMIF_S28H_READ_LC_DC_TABLE_MAX  (2u)

typedef enum
{
	CY_SMIF_S28H_WT_LATENCY0 = 0u,
} cy_en_smif_s28hl_write_latency_code_t;
#define CY_SMIF_S28H_WRITE_LATENCY_CODE_MAX (1u)
#define CY_SMIF_S28H_WRITE_LC_DC_TABLE_MAX  (1u)

typedef enum
{
	CY_SMIF_S28H_REG_LATENCY0 = 0u,
	CY_SMIF_S28H_REG_LATENCY1 = 1u,
	CY_SMIF_S28H_REG_LATENCY2 = 2u,
	CY_SMIF_S28H_REG_LATENCY3 = 3u,
} cy_en_smif_s28hl_reg_latency_code_t;
#define CY_SMIF_S28H_REG_LATENCY_CODE_MAX (4u)

// YOTS: should be moved to .c file
static const uint8_t g_s28hLatancyTableOfRegType1[CY_SMIF_S28H_REG_LATENCY_CODE_MAX] = {0u, 1u, 1u, 2u};
static const uint8_t g_s28hLatancyTableOfRegType2[CY_SMIF_S28H_REG_LATENCY_CODE_MAX] = {0u, 0u, 1u, 2u};
static const uint8_t g_s28hLatancyTableOfRegType3[CY_SMIF_S28H_REG_LATENCY_CODE_MAX] = {3u, 4u, 5u, 6u};


typedef enum
{
	/* Non-Volatile registers */
	CY_S28H_ADDR_StatusRegister1_NV                    = 0x00000000UL,
	CY_S28H_ADDR_ConfigurationRegister1_NV             = 0x00000002UL,
	CY_S28H_ADDR_ConfigurationRegister2_NV             = 0x00000003UL,
	CY_S28H_ADDR_ConfigurationRegister3_NV             = 0x00000004UL,
	CY_S28H_ADDR_ConfigurationRegister4_NV             = 0x00000005UL,
	CY_S28H_ADDR_ConfigurationRegister5_NV             = 0x00000006UL,
	CY_S28H_ADDR_EnduraFlexArchSelReg0_NV              = 0x00000050UL,
	CY_S28H_ADDR_EnduraFlexArchSelReg1Byte0_NV         = 0x00000052UL,
	CY_S28H_ADDR_EnduraFlexArchSelReg1Byte1_NV         = 0x00000053UL,
	CY_S28H_ADDR_EnduraFlexArchSelReg2Byte0_NV         = 0x00000054UL,
	CY_S28H_ADDR_EnduraFlexArchSelReg2Byte1_NV         = 0x00000055UL,
	CY_S28H_ADDR_EnduraFlexArchSelReg3Byte0_NV         = 0x00000056UL,
	CY_S28H_ADDR_EnduraFlexArchSelReg3Byte1_NV         = 0x00000057UL,
	CY_S28H_ADDR_EnduraFlexArchSelReg4Byte0_NV         = 0x00000058UL,
	CY_S28H_ADDR_EnduraFlexArchSelReg4Byte1_NV         = 0x00000059UL,
	CY_S28H_ADDR_AutoBootRegisterByte0_NV              = 0x00000042UL,
	CY_S28H_ADDR_AutoBootRegisterByte1_NV              = 0x00000043UL,
	CY_S28H_ADDR_AutoBootRegisterByte2_NV              = 0x00000044UL,
	CY_S28H_ADDR_AutoBootRegisterByte3_NV              = 0x00000045UL,
	CY_S28H_ADDR_ASP_RegisterByte0_NV                  = 0x00000030UL,
	CY_S28H_ADDR_ASP_RegisterByte1_NV                  = 0x00000031UL,
	CY_S28H_ADDR_ASP_PasswordRegisterByte0_NV          = 0x00000020UL,
	CY_S28H_ADDR_ASP_PasswordRegisterByte1_NV          = 0x00000021UL,
	CY_S28H_ADDR_ASP_PasswordRegisterByte2_NV          = 0x00000022UL,
	CY_S28H_ADDR_ASP_PasswordRegisterByte3_NV          = 0x00000023UL,
	CY_S28H_ADDR_ASP_PasswordRegisterByte4_NV          = 0x00000024UL,
	CY_S28H_ADDR_ASP_PasswordRegisterByte5_NV          = 0x00000025UL,
	CY_S28H_ADDR_ASP_PasswordRegisterByte6_NV          = 0x00000026UL,
	CY_S28H_ADDR_ASP_PasswordRegisterByte7_NV          = 0x00000027UL,

	/* Volatile registers */
	CY_S28H_ADDR_StatusRegister1_V                     = 0x00800000UL,
	CY_S28H_ADDR_StatusRegister2_V                     = 0x00800001UL,
	CY_S28H_ADDR_ConfigurationRegister1_V              = 0x00800002UL,
	CY_S28H_ADDR_ConfigurationRegister2_V              = 0x00800003UL,
	CY_S28H_ADDR_ConfigurationRegister3_V              = 0x00800004UL,
	CY_S28H_ADDR_ConfigurationRegister4_V              = 0x00800005UL,
	CY_S28H_ADDR_ConfigurationRegister5_V              = 0x00800006UL,
	CY_S28H_ADDR_CRCEnableRegister_V                   = 0x00800008UL,
	CY_S28H_ADDR_InterruptConfigurationRegister_V      = 0x00800068UL,
	CY_S28H_ADDR_InterruptStatusRegister_V             = 0x00800067UL,
	CY_S28H_ADDR_ECCStatusRegister_V                   = 0x00800089UL,
	CY_S28H_ADDR_ECCErrorDetectionCountRegisterByte0_V = 0x0080008AUL,
	CY_S28H_ADDR_ECCErrorDetectionCountRegisterByte1_V = 0x0080008BUL,
	CY_S28H_ADDR_ECCAddressTrapRegisterByte0_V         = 0x0080008EUL,
	CY_S28H_ADDR_ECCAddressTrapRegisterByte1_V         = 0x0080008FUL,
	CY_S28H_ADDR_ECCAddressTrapRegisterByte2_V         = 0x00800040UL,
	CY_S28H_ADDR_ECCAddressTrapRegisterByte3_V         = 0x00800041UL,
	CY_S28H_ADDR_SectorEraseCountRegisterByte0_V       = 0x00800091UL,
	CY_S28H_ADDR_SectorEraseCountRegisterByte1_V       = 0x00800092UL,
	CY_S28H_ADDR_SectorEraseCountRegisterByte2_V       = 0x00800093UL,
	CY_S28H_ADDR_DataIntegrityCheckCRCRegisterByte0_V  = 0x00800095UL,
	CY_S28H_ADDR_DataIntegrityCheckCRCRegisterByte1_V  = 0x00800096UL,
	CY_S28H_ADDR_DataIntegrityCheckCRCRegisterByte2_V  = 0x00800097UL,
	CY_S28H_ADDR_DataIntegrityCheckCRCRegisterByte3_V  = 0x00800098UL,
	CY_S28H_ADDR_ASP_PPB_LockRegister_V                = 0x0080009BUL,
} cy_en_smif_s28hl_reg_addr_t;


typedef struct
{
	uint8_t manufacturerId;
	uint8_t DeviceId_MSB;
	uint8_t DeviceId_LSB;
	uint8_t idLength;
	uint8_t physicalSecotorArch;
	uint8_t familyId;
} cy_stc_smif_s28hl_id_t;

typedef enum
{
	CY_S28H_ADDR_3BYTE = 0,
	CY_S28H_ADDR_4BYTE = 1,
} cy_en_smif_s28hl_addr_len_t;

typedef enum
{
	CY_S28H_TRANSACTION_1S1S1S = 0,
	CY_S28H_TRANSACTION_8S8S8S = 1,
	CY_S28H_TRANSACTION_8D8D8D = 2,
} cy_en_smif_s28hl_transaction_t;

cy_en_smif_status_t Cy_SMIF_S28H_ReadId(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_stc_smif_s28hl_id_t* readID,
										cy_en_smif_s28hl_reg_latency_code_t lc,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_ReadJedecId(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint64_t* readData[],
										uint32_t readAddress,
										uint32_t readSize,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_ReadUniqueId(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint64_t* uniqueId,
										cy_en_smif_s28hl_reg_latency_code_t lc,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_ReadStatusRegister1(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint8_t* readData,
										cy_en_smif_s28hl_reg_latency_code_t regLc,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_ReadStatusRegister2(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint8_t* readData,
										cy_en_smif_s28hl_reg_latency_code_t regLc,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_ReadAnyNonVolatileRegister(volatile stc_SMIF_t *base,
												cy_en_smif_slave_select_t slave,
												uint8_t* readData,
												cy_en_smif_s28hl_reg_addr_t regAddr,
												cy_en_smif_s28hl_read_latency_code_t latencyCode,
												cy_en_smif_s28hl_addr_len_t addrLen,
												cy_en_smif_s28hl_transaction_t transaction,
												cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_ReadAnyVolatileRegister(volatile stc_SMIF_t *base,
												cy_en_smif_slave_select_t slave,
												uint8_t* readData,
												cy_en_smif_s28hl_reg_addr_t regAddr,
												cy_en_smif_s28hl_reg_latency_code_t latencyCode,
												cy_en_smif_s28hl_addr_len_t addrLen,
												cy_en_smif_s28hl_transaction_t transaction,
												cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_WriteEnable(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_WriteDisable(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_WriteAnyRegister(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint8_t writeData,
										cy_en_smif_s28hl_reg_addr_t regAddr,
										cy_en_smif_s28hl_addr_len_t addrLen,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_ClearProgramAndEraseFailureFlags(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_ReadECC_DataUnitStatus(volatile stc_SMIF_t *base,
												cy_en_smif_slave_select_t slave,
												uint8_t* readStatus,
												uint32_t unitAdder,
												uint8_t latencyCode,
												cy_en_smif_s28hl_transaction_t transaction,
												cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_ClearECC_StatusRegister(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_DataIntegrityCheck(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint32_t startAddress,
										uint32_t endAddress,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_Erase_4KB_Sector(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint32_t erasedAddress,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_Erase_256KB_Sector(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint32_t erasedAddress,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_EraseChip(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_EvaluateEraseStatus(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint32_t erasedAddress,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_SectorEraseCount(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint32_t erasedAddress,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_SuspendEraseProgram(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_ResumeEraseProgram(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_SoftwareResetEnable(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_SoftwareReset(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);
cy_en_smif_status_t Cy_SMIF_S28H_EnterDeepPowerDownMode(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context);


//extern const cy_stc_cmd_sq_t         g_s28hReadCmdTypes[];
//extern const cy_stc_addr_sq_t        g_s28hReadAddrTypes[];
//extern const cy_stc_mode_sq_t        g_s28hReadModeTypes[];
//extern const cy_stc_dummy_sq_t       g_s28hReadDummyTypes[];
//extern const uint8_t*                g_s28hReadLatencyCodeToDummyCycle[CY_SMIF_S28H_READ_LC_DC_TABLE_MAX];
//extern const cy_stc_data_sq_t        g_s28hReadDataTypes[];
//extern const cy_stc_read_info_t      g_s28hReadCmdInfo[];
//extern const cy_stc_cmd_sq_t         g_s28hWriteCmdTypes[];
//extern const cy_stc_addr_sq_t        g_s28hWriteAddrTypes[];
//extern const cy_stc_mode_sq_t        g_s28hWriteModeTypes[];
//extern const cy_stc_dummy_sq_t       g_s28hWriteDummyTypes[];
//extern const uint8_t*                g_s28hWriteLatencyCodeToDummyCycle[CY_SMIF_S28H_WRITE_LC_DC_TABLE_MAX];
//extern const cy_stc_data_sq_t        g_s28hWriteDataTypes[];
//extern const cy_stc_write_info_t     g_s28hWriteCmdInfo[];


#if defined(__cplusplus)
}
#endif

#endif /* (CY_SMIF_S28H_H) */

