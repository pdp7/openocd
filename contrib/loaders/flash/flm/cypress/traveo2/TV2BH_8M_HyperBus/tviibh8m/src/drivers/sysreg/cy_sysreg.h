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


/** This enumeration is used to set the clock source for the RTC block */
typedef enum
{
    CY_SYSREG_EXT_TR = 0u,     /**< External Transistor Mode */
    CY_SYSREG_EXT_PMIC = 1u,     /**< External PMIC Mode */
} cy_en_sysreg_reghc_mode_t;

void Cy_SysReg_DisableLinearRegulator(void);
void Cy_SysReg_EnableLinearRegulator(void);
void Cy_SysReg_DisableDeepSleepRegulator(void);

bool Cy_SysReg_LinearRegulatorStatus(void);

void Cy_SysReg_EnableDeepSleepRegulator(void);
void Cy_SysReg_SelectRegHCMode(cy_en_sysreg_reghc_mode_t mode);
void Cy_SysReg_SelectRegHCPmicDriveOut(uint8_t drvOut);
void Cy_SysReg_RegHCAdjustOutputVoltage(uint8_t trim);
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
