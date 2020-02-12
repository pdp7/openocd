/***************************************************************************//**
* \file cy_sysreg.c
* \version 1.0
*
* Provides an API implementation of the system regulator driver.
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_sysreg.h"
#include "syslib/cy_syslib.h"

#include <stdlib.h>

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
* Function Name: Cy_SysReg_DisableLinearRegulator
********************************************************************************
* \brief 
* Disables internal linear regulator.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysReg_DisableLinearRegulator(void)
{
    SRSS->unPWR_CTL2.stcField.u1LINREG_DIS = 1u;
}

/*******************************************************************************
* Function Name: Cy_SysReg_EnableLinearRegulator
********************************************************************************
* \brief 
* Enables internal linear regulator.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysReg_EnableLinearRegulator(void)
{
    SRSS->unPWR_CTL2.stcField.u1LINREG_DIS = 0u;
}


bool Cy_SysReg_LinearRegulatorStatus(void)
{
    return(SRSS->unPWR_CTL2.stcField.u1LINREG_OK);
}

/*******************************************************************************
* Function Name: Cy_SysReg_DisableLinearRegulator
********************************************************************************
* \brief 
* Disables internal linear regulator.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysReg_DisableDeepSleepRegulator(void)
{
    SRSS->unPWR_CTL2.stcField.u1DPSLP_REG_DIS = 1u;
}

/*******************************************************************************
* Function Name: Cy_SysReg_EnableLinearRegulator
********************************************************************************
* \brief 
* Enables internal linear regulator.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysReg_EnableDeepSleepRegulator(void)
{
    SRSS->unPWR_CTL2.stcField.u1DPSLP_REG_DIS = 0u;
}

/*******************************************************************************
* Function Name: Cy_SysReg_SelectRegHCMode
********************************************************************************
* \brief 
* Selects one of the supported REGHC mode.
*
* \param
* cy_en_sysreg_reghc_mode_t.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysReg_SelectRegHCMode(cy_en_sysreg_reghc_mode_t mode)
{
    SRSS->unPWR_REGHC_CTL.stcField.u1REGHC_MODE = mode;
}

/*******************************************************************************
* Function Name: Cy_SysReg_SelectRegHCPmicDriveOut
********************************************************************************
* \brief 
* Selects DRV_OUT setting.
*
* \param
* 0b00 - vccd*0.9/vadj, 0b01 - vccd*0.8/vadj, 0b10 - vccd*0.6/vadj, 0b11 - vccd.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysReg_SelectRegHCPmicDriveOut(cy_en_sysreg_reghc_drive_out_t drvOut)
{
    SRSS->unPWR_REGHC_CTL.stcField.u2REGHC_PMIC_DRV_VOUT = drvOut;
}

/*******************************************************************************
* Function Name: Cy_SysReg_RegHCAdjustOutputVoltage
********************************************************************************
* \brief 
* Selects regulator output voltage adjustment.
*
* \param
* trim - Regulator output trim according to the formula vadj=(1.020V + REGHC_VADJ*0.005V).   
* The step is nominally 5mV/LSB.
*
* \return 
* None.
*******************************************************************************/
void Cy_SysReg_RegHCAdjustOutputVoltage(cy_en_sysreg_reghc_vadj_t trim)
{
    SRSS->unPWR_REGHC_CTL.stcField.u5REGHC_VADJ = trim;
}

/*******************************************************************************
* Function Name: Cy_SysReg_DisableLinearRegulator
********************************************************************************
* \brief 
* Disables PMIC.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysReg_RegHCDisablePmic(void)
{
    SRSS->unPWR_REGHC_CTL.stcField.u1REGHC_PMIC_CTL_OUTEN = 0u;
    SRSS->unPWR_REGHC_CTL.stcField.u1REGHC_PMIC_CTL_POLARITY = 0u;
}

/*******************************************************************************
* Function Name: Cy_SysReg_RegHCEnablePmic
********************************************************************************
* \brief 
* Enables PMIC.
*
* \param
* 1 - output high, 0 - output low.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysReg_RegHCEnablePmic(bool polarity)
{
    SRSS->unPWR_REGHC_CTL.stcField.u1REGHC_PMIC_CTL_OUTEN = 1u;
    SRSS->unPWR_REGHC_CTL.stcField.u1REGHC_PMIC_CTL_POLARITY = polarity;
}

/*******************************************************************************
* Function Name: Cy_SysReg_RegHCEnableStatusInput
********************************************************************************
* \brief 
* Enables receiving status from PMIC.
*
* \param
* 1 - receiving High means abnormal status.
  0 - receiving Low  means abnormal status.
*
* \return 
* None.
*******************************************************************************/
void Cy_SysReg_RegHCEnableStatusInput(bool polarity)
{
    SRSS->unPWR_REGHC_CTL.stcField.u1REGHC_PMIC_STATUS_INEN = 1u;
    SRSS->unPWR_REGHC_CTL.stcField.u1REGHC_PMIC_STATUS_POLARITY = polarity;
}

/*******************************************************************************
* Function Name: Cy_SysReg_RegHCSetPmicStatusWaitTime
********************************************************************************
* \brief 
* Wait count in 1us steps after PMIC status ok.  This is used by the hardware 
* sequencer to allow additional settling time before disabling the internal regulator.  
* The LSB is eight IMO periods which results in a nominal LSB step of 1us.
*
* \param
* waitValue = 0 to 10 -> 1us to 11us Delay
*
* \return 
* None.
*******************************************************************************/
void Cy_SysReg_RegHCSetPmicStatusWaitTime(uint16_t waitTime)
{
    SRSS->unPWR_REGHC_CTL.stcField.u10REGHC_PMIC_STATUS_WAIT = waitTime;
}

/*******************************************************************************
* Function Name: Cy_SysReg_IsRegHCDisablePmicStatusInputBuffer
********************************************************************************
* \brief 
* Disables PMIC status input buffer  
*
* \param
* None.   
*
* \return 
* None
*******************************************************************************/
void Cy_SysReg_IsRegHCDisablePmicStatusInputBuffer(void)
{
    SRSS->unPWR_REGHC_CTL.stcField.u1REGHC_PMIC_STATUS_INEN = 0u;
}

/*******************************************************************************
* Function Name: Cy_SysReg_IsRegHCConfigured
********************************************************************************
* \brief 
* Disables REGHC. This is used to know if REGHC should be enabled in response to 
* a debug power up request.  Do not change REGHC settings after this bit is high.  
*
* \param
* None.   
*
* \return 
* 1 - Configured, 0 - Not configured
*******************************************************************************/
bool Cy_SysReg_IsRegHCConfigured(void)
{
    return (SRSS->unPWR_REGHC_CTL.stcField.u1REGHC_CONFIGURED);
}

/*******************************************************************************
* Function Name: Cy_SysReg_SetRegHCConfigured
********************************************************************************
* \brief 
* Set REGHC. This is required to apply setting before enable PMIC.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysReg_SetRegHCConfigured(void)
{
    SRSS->unPWR_REGHC_CTL.stcField.u1REGHC_CONFIGURED = 1u;
}

/*******************************************************************************
* Function Name: Cy_SysReg_DisableLinearRegulator
********************************************************************************
* \brief 
* Disables REGHC.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysReg_DisableRegHC(void)
{
    SRSS->unPWR_REGHC_CTL2.stcField.u1REGHC_EN = 0u;
}

/*******************************************************************************
* Function Name: Cy_SysReg_EnableLinearRegulator
********************************************************************************
* \brief 
* Enables REGHC.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysReg_EnableRegHC(void)
{
    SRSS->unPWR_REGHC_CTL2.stcField.u1REGHC_EN = 1u;
}

/*******************************************************************************
* Function Name: Cy_SysReg_IsRegHCEnabled
********************************************************************************
* \brief 
* Indicates the state of the REGHC enable/disable sequencer.  This bit is only 
* valid when REGHC_SEQ_BUSY==0 (Cy_SysReg_IsRegHCSequencerBusy).  
*
* \param
* None.   
*
* \return 
* 1 - Enabled, 0 - Disabled
*******************************************************************************/
bool Cy_SysReg_IsRegHCEnabled(void)
{
    return (SRSS->unPWR_REGHC_STATUS.stcField.u1REGHC_ENABLED);
}

/*******************************************************************************
* Function Name: Cy_SysReg_IsRegHCOcdWithinLimits
********************************************************************************
* \brief 
* Indicates the over-current detector is operating and the current drawn from 
* REGHC is within limits.  OCD is only a choice for transistor mode, and it is 
* disabled for PMIC mode.  
*
* \param
* None.   
*
* \return 
* 0: Current measurement exceeds limit or detector is OFF,
* 1: Current measurement within limit
*******************************************************************************/
bool Cy_SysReg_IsRegHCOcdWithinLimits(void)
{
    return (SRSS->unPWR_REGHC_STATUS.stcField.u1REGHC_OCD_OK);
}

/*******************************************************************************
* Function Name: Cy_SysReg_IsRegHCCktEnabledAndOperating
********************************************************************************
* \brief 
* Indicates the REGHC circuit is enabled and operating. 
*
* \param
* None.   
*
* \return 
* 0: REGHC Disabled
* 1: REGHC Enabled and Operating
*******************************************************************************/
bool Cy_SysReg_IsRegHCCktEnabledAndOperating(void)
{
    return (SRSS->unPWR_REGHC_STATUS.stcField.u1REGHC_CKT_OK);
}

/*******************************************************************************
* Function Name: Cy_SysReg_RegHCPmicStatus
********************************************************************************
* \brief 
* Indicates the PMIC status is ok.  This includes polarity adjustment according 
* to REGHC_PMIC_STATUS_POLARITY.
*
* \param
* None.   
*
* \return 
* 0: PMIC status is not ok or PMIC input buffer is disabled (REGHC_PMIC_STATUS_INEN == 0)
* 1: PMIC status input buffer is enabled and indicates ok
*******************************************************************************/
bool Cy_SysReg_RegHCPmicStatus(void)
{
    return (SRSS->unPWR_REGHC_STATUS.stcField.u1REGHC_PMIC_STATUS_OK);
}

/*******************************************************************************
* Function Name: Cy_SysReg_IsRegHCSequencerBusy
********************************************************************************
* \brief 
* Indicates whether the REGHC circuit is busy. Indicates the REGHC enable/disable 
* sequencer is busy transitioning to/from REGHC.
*
* \param
* None.   
*
* \return 
* 0: REGHC busy
* 1: REGHC not busy
*******************************************************************************/
bool Cy_SysReg_IsRegHCSequencerBusy(void)
{
    return (SRSS->unPWR_REGHC_STATUS.stcField.u1REGHC_SEQ_BUSY);
}

/*******************************************************************************
* Function Name: Cy_SysReg_PassTransistorManualEnable
********************************************************************************
* \brief 
* This API manually enables REGHC sequencer.
*
* \param
* None.   
*
* \return 
* None.
*******************************************************************************/
void Cy_SysReg_PassTransistorManualEnable(void)
{
    // PWR_REGHC_CTL3.REGHC_SEQ_MANUAL=1
    // PWR_REGHC_CTL3.REGHC_CKT_EN=1
    *(volatile uint32_t*)(0x40261034UL) = 0xC0000000UL;
}

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/******************************************************************************/
/* [] END OF FILE */
/******************************************************************************/
