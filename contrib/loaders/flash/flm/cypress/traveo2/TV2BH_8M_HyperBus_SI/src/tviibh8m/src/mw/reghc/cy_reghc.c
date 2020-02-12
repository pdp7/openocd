/***************************************************************************//**
* \file cy_reghc.c
* \version 1.0
*
* \brief
* Provides an API implementation of the Button middleware driver
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


/*****************************************************************************
* Include files
*****************************************************************************/
#include "cy_project.h"
#include "cy_device_headers.h"
#include "cy_reghc.h"


#if defined(__cplusplus)
extern "C" {
#endif

/*****************************************************************************
* Local pre-processor symbols/macros ('define')
*****************************************************************************/

/*****************************************************************************
* Global variable definitions (declared in header file with 'extern')
*****************************************************************************/

/*****************************************************************************
* Local type definitions ('typedef')
*****************************************************************************/
  
/*****************************************************************************
* Local variable definitions ('static')
*****************************************************************************/

/*****************************************************************************
* Local function prototypes ('static')                                                                            
*****************************************************************************/
static cy_en_srom_status_t Cy_Srom_ProcessOpcode(uint32_t opcode);
static cy_en_srom_status_t Cy_Srom_SendMsgWaitComplete(cy_un_srom_context_t *context, uint32_t *returnData);
  
/*****************************************************************************
* Function implementation - global ('extern') and local ('static')
*****************************************************************************/


/**
 *****************************************************************************
 ** Switch the power source from internal to external regulator.
 **
 ** \param 
 ** pmicTrim : Trim setting to provide 50mV offset, default is 1.1V
 **             vadj=(1.020V + REGHC_VADJ*0.005V)
 ** ctrPolarity : 0 - Output Low  when PMIC enabled.
 **               1 - Output High when PMIC enabled.
 ** statusPolarity : 0 - TVII detect abnormal status when received Low  from PMIC.
 **                  0 - TVII detect abnormal status when received High from PMIC.
 **
 ** waitTime : giving additional settling time after PMIC status input is 
 **            initially OK in [us]
 ** 
 ** \return  
 ** none
 *****************************************************************************/
void Cy_PMIC_Switch_IntToPMIC(cy_en_sysreg_reghc_vadj_t pmicTrim, 
                              cy_en_reghc_control_polarity_t ctrPolarity, 
                              cy_en_reghc_status_polarity_t statusPolarity,
                              uint16_t waitTime)
{
    bool retStatus = false;

    // Check if RegHC is already configured
    retStatus = Cy_SysReg_IsRegHCConfigured();
    if(retStatus == true)
    {
        return;
    }

    // Select external regulator mode 
    Cy_SysReg_SelectRegHCMode(CY_SYSREG_REGHC_EXT_PMIC);

    // Enable the s40ereghc or external PMIC
    Cy_SysReg_RegHCEnableStatusInput((bool)statusPolarity);
    Cy_SysReg_RegHCEnablePmic((bool)ctrPolarity);
    Cy_SysReg_SetRegHCConfigured();

    // Program the s40ereghc configuration registers
    Cy_SysReg_RegHCAdjustOutputVoltage(pmicTrim);

    // Set wait time until the PMIC output settle.
    Cy_SysReg_RegHCSetPmicStatusWaitTime(waitTime);

    Cy_SysReg_EnableRegHC();

    // Wait for the s40ereghc or external PMIC power ok signal
    while((Cy_SysReg_IsRegHCSequencerBusy() == 1) ||
       (Cy_SysReg_IsRegHCEnabled() == 0) );
}

/**
 *****************************************************************************
 ** Switch the power source from internal to external regulator.
 **
 ** \param 
 ** trim : Trim setting to provide 50mV offset, default is 1.1V
 **             vadj=(1.020V + REGHC_VADJ*0.005V)
 ** 
 ** \return  
 ** none
 *****************************************************************************/
void Cy_PMIC_Switch_IntToPassTR(void)
{
    bool retStatus = false;

    // Check if RegHC is already configured
    retStatus = Cy_SysReg_IsRegHCConfigured();
    if(retStatus == true)
    {
        return;
    }

    // Set external pass transistor mode
    Cy_SysReg_SelectRegHCMode(CY_SYSREG_REGHC_EXT_TR);

    // Enable the s40ereghc or external PMIC
    Cy_SysReg_SetRegHCConfigured();

    Cy_SysReg_EnableRegHC();

    while((Cy_SysReg_IsRegHCSequencerBusy() == 1) ||
       (Cy_SysReg_IsRegHCEnabled() == 0) );
}


/**
 *****************************************************************************
 ** Switch the power source from external to internal regulator.
 **
 ** \param 
 ** none
 **
 ** \return 
 ** none
 *****************************************************************************/
void Cy_PMIC_Switch_ExtToInt(void)
{
    bool retStatus = false;
    
    // Program htreg configuration registers (trim, voltage, etc)
    
    // Enable the htreg
    Cy_SysReg_EnableLinearRegulator();
    
    // Wait for the htreg act_reg_ready_ok signal
    do {
        retStatus = Cy_SysReg_LinearRegulatorStatus();
    } while(retStatus == false);
    
    // Mask s40ereg or PMIC supply monitoring signals (overcurrent detect, power ok)
    
    // Disable the s40ereghc or external PMIC
    Cy_SysReg_DisableRegHC();
    Cy_SysReg_RegHCDisablePmic();
}


////////////////////////////////////////////////////////////////////////////////
cy_en_srom_status_t Cy_Srom_SwitchOverRegulator(const cy_stc_switchOverRegulator_context_t *config)
{
    cy_en_srom_status_t result;

    /* Checks if input pointers are not NULL */
    if (config == NULL)
    {
        return CY_SROM_INVALID_INPUT_PARAMETERS;
    }

    /* Prepares arguments to be passed to SROM API */
    cy_un_srom_context_t context;
    context.arg = 0UL;
    context.config.arg_ind = 0u;
    context.config.mode = config->mode;
    context.config.regulator = config->regulator;
    context.config.blocking = config->blocking;
    context.config.opcode = CY_SROM_OPCODE_PROGRAM_ROW;
    
    /* Tries to acquire the IPC structure and pass the arguments to SROM API */
    if(context.config.blocking == CY_SROM_BLOCK_CM0)
    {
        result = Cy_Srom_SendMsgWaitComplete(&context, NULL);
        if(result != CY_SROM_SUCCESS)
        {
            return result;
        }

        return CY_SROM_SUCCESS;
    }
    else
    {
        /* Send message by IPC */
        if (Cy_IPC_Drv_SendMsgPtr(CY_SROM_IPC_STRUCT, CY_SROM_IPC_NOTIFY_STRUCT, (void*)&context) != CY_IPC_DRV_SUCCESS)
        {
            /* The IPC structure is already locked by another process */
            return CY_SROM_IPC_BUSY;
        }
        return CY_SROM_SUCCESS;
    }
}

////////////////////////////////////////////////////////////////////////////////
static cy_en_srom_status_t Cy_Srom_SendMsgWaitComplete(cy_un_srom_context_t *context, uint32_t *returnData)
{
    cy_en_srom_status_t result = CY_SROM_OPCODE_BUSY;

    /* Send message by IPC */
    if (Cy_IPC_Drv_SendMsgPtr(CY_SROM_IPC_STRUCT, CY_SROM_IPC_NOTIFY_STRUCT, (void*)context) != CY_IPC_DRV_SUCCESS)
    {
        /* The IPC structure is already locked by another process */
        return CY_SROM_IPC_BUSY;
    }

    /* Wait until the IPC is released */
    do
    {
        /* Checks if the IPC structure is not locked */
        if (Cy_IPC_Drv_IsLockAcquired(CY_SROM_IPC_STRUCT) == false)
        {
            /* The result of SROM API calling is returned to the driver context */
            result = Cy_Srom_ProcessOpcode(context->arg);
        }
    }
    while (result == CY_SROM_OPCODE_BUSY);

    /* Check result */
    if(result != CY_SROM_SUCCESS)
    {
        return result;
    }

    /* Get received data from IPC if needed */
    if(returnData != NULL)
    {
        *returnData = context->arg;
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////
static cy_en_srom_status_t Cy_Srom_ProcessOpcode(uint32_t opcode)
{
    cy_en_srom_status_t retVal;

    if((opcode >> CY_SROM_ERROR_SHIFT) == CY_SROM_ERROR_NO_ERROR)
    {
        return CY_SROM_SUCCESS;
    }

    // Process error code
    switch (opcode)
    {
        case CY_FLASH_ROMCODE_INV_PROT:
            retVal = CY_SROM_INV_PROT;
            break;
        case CY_FLASH_ROMCODE_IPC_BUSY:
            retVal = CY_SROM_IPC_BUSY;
            break;
        case CY_FLASH_ROMCODE_IN_PROGRESS_NO_ERROR:
            retVal = CY_SROM_PROGRESS_NO_ERROR;
            break;
        case (uint32_t)CY_FLASH_DRV_INVALID_INPUT_PARAMETERS:
            retVal = CY_SROM_INVALID_INPUT_PARAMETERS;
            break;
        default:
            retVal = CY_SROM_ERR_UNC;
            break;
    }

    return (retVal);
}

////////////////////////////////////////////////////////////////////////////////
void Cy_PassTR_ManuallyEnable(cy_en_sysreg_reghc_vadj_t vadj)
{
    // Set external pass transistor mode
    Cy_SysReg_SelectRegHCMode(CY_SYSREG_REGHC_EXT_TR);

    // Set VCCD around 1.1 [V] using REGHC_VADJ
    Cy_SysReg_RegHCAdjustOutputVoltage(vadj);

    // Enable the pass transistor sequencer manually
    Cy_SysReg_PassTransistorManualEnable();

    // TODO: Should wait for pass TR becoming OK here (YOTS)

    // Disable internal active regulator
    Cy_SysReg_DisableLinearRegulator();
}

////////////////////////////////////////////////////////////////////////////////
bool Cy_PassTR_IsReady(void)
{
    // Check if the REGHC pass transistor enabled and operating
    if((Cy_SysReg_IsRegHCCktEnabledAndOperating() == 1) &&
       (Cy_SysReg_IsRegHCOcdWithinLimits() == 1) )
    {
        return true;
    }
    else
    {
        return false;
    }
}



////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
}
#endif


/* [] END OF FILE */
