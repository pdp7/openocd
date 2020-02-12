/*******************************************************************************
* \file cy_sysreg.h
* \version 1.0
*
* Provides an API declaration of the system regulator driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(__CY_SYSREG_H__)
#define __CY_SYSREG_H__

#include "cy_device_headers.h"
#include "syslib/cy_syslib.h"
#include "syspm/cy_syspm.h"
#include "systick/cy_systick.h"
#include <stdbool.h>

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/**
* \addtogroup group_sysreg_macros
* \{
*/
/** Driver major version */
#define  CY_SYSREG_DRV_VERSION_MAJOR   1
/** Driver minor version */
#define  CY_SYSREG_DRV_VERSION_MINOR   0
/** \} group_sysreg_macros */


/** This enumeration is used to select the REGHC mode */
typedef enum
{
    CY_SYSREG_REGHC_EXT_TR = 0u,              /**< External Transistor Mode */
    CY_SYSREG_REGHC_EXT_PMIC = 1u,            /**< External PMIC Mode */
} cy_en_sysreg_reghc_mode_t;

/** This enumeration is used to set the voltage trims */

//  VADJ = 0  -> b00000 1.020 V   ||   VADJ = 16 -> b10000 1.100 V
//  VADJ = 1  -> b00001 1.025 V   ||   VADJ = 17 -> b10001 1.105 V
//  VADJ = 2  -> b00010 1.030 V   ||   VADJ = 18 -> b10010 1.110 V
//  VADJ = 3  -> b00011 1.035 V   ||   VADJ = 19 -> b10011 1.115 V
//  VADJ = 4  -> b00100 1.040 V   ||   VADJ = 20 -> b10100 1.120 V
//  VADJ = 5  -> b00101 1.045 V   ||   VADJ = 21 -> b10101 1.125 V
//  VADJ = 6  -> b00110 1.050 V   ||   VADJ = 22 -> b10110 1.130 V
//  VADJ = 7  -> b00111 1.055 V   ||   VADJ = 23 -> b10111 1.135 V
//  VADJ = 8  -> b01000 1.060 V   ||   VADJ = 24 -> b11000 1.140 V
//  VADJ = 9  -> b01001 1.065 V   ||   VADJ = 25 -> b11001 1.145 V
//  VADJ = 10 -> b01010 1.070 V   ||   VADJ = 26 -> b11010 1.150 V
//  VADJ = 11 -> b01011 1.075 V   ||   VADJ = 27 -> b11011 1.155 V
//  VADJ = 12 -> b01100 1.080 V   ||   VADJ = 28 -> b11100 1.160 V
//  VADJ = 13 -> b00101 1.085 V   ||   VADJ = 29 -> b10101 1.165 V
//  VADJ = 14 -> b01110 1.090 V   ||   VADJ = 30 -> b11110 1.170 V
//  VADJ = 15 -> b01111 1.095 V   ||   VADJ = 31 -> b11111 1.175 V

typedef enum
{
    CY_SYSREG_REGHC_VADJ_0      = 0u,
    CY_SYSREG_REGHC_VADJ_1      = 1u,
    CY_SYSREG_REGHC_VADJ_2      = 2u,
    CY_SYSREG_REGHC_VADJ_3      = 3u,
    CY_SYSREG_REGHC_VADJ_4      = 4u,
    CY_SYSREG_REGHC_VADJ_5      = 5u,
    CY_SYSREG_REGHC_VADJ_6      = 6u,
    CY_SYSREG_REGHC_VADJ_7      = 7u,
    CY_SYSREG_REGHC_VADJ_8      = 8u,
    CY_SYSREG_REGHC_VADJ_9      = 9u,
    CY_SYSREG_REGHC_VADJ_10     = 10u,
    CY_SYSREG_REGHC_VADJ_11     = 11u,
    CY_SYSREG_REGHC_VADJ_12     = 12u,
    CY_SYSREG_REGHC_VADJ_13     = 13u,
    CY_SYSREG_REGHC_VADJ_14     = 14u,
    CY_SYSREG_REGHC_VADJ_15     = 15u,
    CY_SYSREG_REGHC_VADJ_16     = 16u,
    CY_SYSREG_REGHC_VADJ_17     = 17u,
    CY_SYSREG_REGHC_VADJ_18     = 18u,
    CY_SYSREG_REGHC_VADJ_19     = 19u,
    CY_SYSREG_REGHC_VADJ_20     = 20u,
    CY_SYSREG_REGHC_VADJ_21     = 21u,
    CY_SYSREG_REGHC_VADJ_22     = 22u,
    CY_SYSREG_REGHC_VADJ_23     = 23u,
    CY_SYSREG_REGHC_VADJ_24     = 24u,
    CY_SYSREG_REGHC_VADJ_25     = 25u,
    CY_SYSREG_REGHC_VADJ_26     = 26u,
    CY_SYSREG_REGHC_VADJ_27     = 27u,
    CY_SYSREG_REGHC_VADJ_28     = 28u,
    CY_SYSREG_REGHC_VADJ_29     = 29u,
    CY_SYSREG_REGHC_VADJ_30     = 30u,
    CY_SYSREG_REGHC_VADJ_31     = 31u
} cy_en_sysreg_reghc_vadj_t;

// Drive out configuration
typedef enum 
{
    CY_SYSREG_REGHC_DRIVE_OUT_0        = 0u,
    CY_SYSREG_REGHC_DRIVE_OUT_1        = 1u,
    CY_SYSREG_REGHC_DRIVE_OUT_2        = 2u,
    CY_SYSREG_REGHC_DRIVE_OUT_3        = 3u
} cy_en_sysreg_reghc_drive_out_t;

// Internal regulator APIs
void Cy_SysReg_DisableLinearRegulator(void);
void Cy_SysReg_EnableLinearRegulator(void);
void Cy_SysReg_DisableDeepSleepRegulator(void);
bool Cy_SysReg_LinearRegulatorStatus(void);
void Cy_SysReg_EnableDeepSleepRegulator(void);

// REGHC APIs
void Cy_SysReg_SelectRegHCMode(cy_en_sysreg_reghc_mode_t mode);
void Cy_SysReg_SelectRegHCPmicDriveOut(cy_en_sysreg_reghc_drive_out_t drvOut);
void Cy_SysReg_RegHCAdjustOutputVoltage(cy_en_sysreg_reghc_vadj_t trim);
void Cy_SysReg_RegHCDisablePmic(void);
void Cy_SysReg_RegHCEnablePmic(bool polarity);
void Cy_SysReg_RegHCEnableStatusInput(bool polarity);
void Cy_SysReg_RegHCSetPmicStatusWaitTime(uint16_t waitTime);
void Cy_SysReg_IsRegHCDisablePmicStatusInputBuffer(void);
bool Cy_SysReg_IsRegHCConfigured(void);
void Cy_SysReg_SetRegHCConfigured(void);
void Cy_SysReg_DisableRegHC(void);
void Cy_SysReg_EnableRegHC(void);
bool Cy_SysReg_IsRegHCEnabled(void);
bool Cy_SysReg_IsRegHCOcdWithinLimits(void);
bool Cy_SysReg_IsRegHCCktEnabledAndOperating(void);
bool Cy_SysReg_RegHCPmicStatus(void);
bool Cy_SysReg_IsRegHCSequencerBusy(void);
void Cy_SysReg_PassTransistorManualEnable(void);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* __CY_SYSREG_H__ */

/** \} group_sysclk */


/******************************************************************************/
/* [] END OF FILE */
/******************************************************************************/
