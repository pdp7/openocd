/***************************************************************************//**
* \file cy_reghc.h
* \version 1.0
*
* \brief
* Provides an API declaration of the PMIC middleware driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
* \defgroup group_pmic
* \{
* Offers control and switch from internal to external LDO transistion and vice versa.
*
* 
*/

#if !defined(CY_REGHC_H)
#define CY_REGHC_H

#include <stddef.h>
#include <stdbool.h>
#include "cy_device_headers.h"
#include "sysreg/cy_sysreg.h"


#if defined(__cplusplus)
extern "C" {
#endif


/**
 *****************************************************************************
 ** \brief PMIC states used
 *****************************************************************************/
////////////////////////////////////////////////////////////////////////////////

#define CY_SROM_ID                      (CY_PDL_DRV_ID(0xFFu))  /**< Dummy PDL ID */

#define CY_SROM_ID_INFO                 (uint32_t)( CY_SROM_ID | CY_PDL_STATUS_INFO )   /**< Return prefix for FLASH driver function status codes */
#define CY_SROM_ID_WARNING              (uint32_t)( CY_SROM_ID | CY_PDL_STATUS_WARNING) /**< Return prefix for FLASH driver function warning return values */
#define CY_SROM_ID_ERROR                (uint32_t)( CY_SROM_ID | CY_PDL_STATUS_ERROR)   /**< Return prefix for FLASH driver function error return values */

#define CY_SROM_RESULT_MASK             (0x0FFFFFFFUL)
#define CY_SROM_ERROR_SHIFT             (28UL)
#define CY_SROM_ERROR_NO_ERROR          (0xAUL)

/** SROM API opcode change over regulator operation */
#define CY_SROM_MODE_EXT_TRANSISTOR     (0x00UL)
#define CY_SROM_MODE_EXT_PMIC           (0x01UL)
#define CY_SROM_SWITCH_TO_PMIC          (0x00UL)
#define CY_SROM_SWITCH_TO_LIN_REGULATOR (0x01UL)
#define CY_SROM_NOBLOCK_CM0             (0x00UL)
#define CY_SROM_BLOCK_CM0               (0x01UL)
#define CY_SROM_OPCODE_PROGRAM_ROW      (0x11UL)

#define CY_SROM_IPC_NOTIFY_STRUCT       (0x01u)

#define CY_SROM_IPC_STRUCT              ((volatile stc_IPC_STRUCT_t*) &IPC->STRUCT[CY_IPC_CHAN_SYSCALL])

/** This enum has the return values of the Flash driver */
typedef enum 
{
    CY_SROM_SUCCESS                  =   0x00ul,  /**< Success */
    CY_SROM_INV_PROT                 =   ( CY_SROM_ID_ERROR + 0x00ul),  /**< Invalid device protection state (SROM STATUS CODE: 0xF0000001) */
    CY_SROM_INVALID_OPCODE           =   ( CY_SROM_ID_ERROR + 0x01ul),  /**< Invalid opcode (SROM STATUS CODE: 0xF0000004) */
    CY_SROM_INVALID_INPUT_PARAMETERS =   ( CY_SROM_ID_ERROR + 0x02ul),  
    CY_SROM_IPC_BUSY                 =   ( CY_SROM_ID_ERROR + 0x03ul),  /**< IPC structure is already locked by another process  (SROM STATUS CODE: 0xF0000006) */
    CY_SROM_ERR_UNC                  =   ( CY_SROM_ID_ERROR + 0xFFul),  /**< Unknown error */
    CY_SROM_PROGRESS_NO_ERROR        =   ( CY_SROM_ID_INFO  + 0ul),     /**< Command in progress; no error */
    CY_SROM_OPERATION_STARTED        =   ( CY_SROM_ID_INFO  + 1ul),     /**< Operation is successfully initiated */
    CY_SROM_OPCODE_BUSY              =   ( CY_SROM_ID_INFO  + 2ul)      /**< Opcode busy */
} cy_en_srom_status_t;

/** Flash driver context */
typedef struct
{
    uint32_t arg_ind       : 1;
    uint32_t mode          : 1;
    uint32_t reserved      : 6;
    uint32_t regulator     : 8;
    uint32_t blocking      : 8;
    uint32_t opcode        : 8;
}cy_stc_switchOverRegulator_context_t;

typedef union
{
    uint32_t arg;
    cy_stc_switchOverRegulator_context_t config;
}cy_un_srom_context_t;

typedef enum
{
    CY_REGHC_PMIC_STS_ABNORMAL_LOW  = 0,
    CY_REGHC_PMIC_STS_ABNORMAL_HIGH = 1,
} cy_en_reghc_status_polarity_t;

typedef enum
{
    CY_REGHC_PMIC_CTL_ENABLE_LOW  = 0,
    CY_REGHC_PMIC_CTL_ENABLE_HIGH = 1,
} cy_en_reghc_control_polarity_t;

////////////////////////////////////////////////////////////////////////////////
cy_en_srom_status_t Cy_Srom_SwitchOverRegulator(const cy_stc_switchOverRegulator_context_t *config);


/*******************************************************************************
* Function Name: Cy_PMIC_Switch_ExtToInt
****************************************************************************//**
*
* \brief        : Power transistion from external to internal LDO.
*
* \param        : none
*
* \return       : ret status of api
*
*******************************************************************************/
void Cy_PMIC_Switch_ExtToInt(void);
   

/*******************************************************************************
* Function Name: Cy_PMIC_Switch_IntToPMIC
****************************************************************************//**
*
* \brief        : Power transition from internal to external PMIC.
*
* \param 
* pmicTrim : Trim setting to provide 50mV offset, default is 1.1V
*             vadj=(1.020V + REGHC_VADJ*0.005V)
* ctrPolarity : 0 - Output Low  when PMIC enabled.
*               1 - Output High when PMIC enabled.
* statusPolarity : 0 - TVII detect abnormal status when received Low  from PMIC.
*                  0 - TVII detect abnormal status when received High from PMIC.
*
* \return
* none
*
*******************************************************************************/
void Cy_PMIC_Switch_IntToPMIC(cy_en_sysreg_reghc_vadj_t pmicTrim, 
                              cy_en_reghc_control_polarity_t ctrPolarity, 
                              cy_en_reghc_status_polarity_t statusPolarity,
                              uint16_t waitTime);

/*******************************************************************************
* Function Name: Cy_PMIC_Switch_IntToPassTR
****************************************************************************//**
*
* \brief        : Power transition from internal to external PMIC.
*
* \param 
* pmicTrim : Trim setting to provide 50mV offset, default is 1.1V
*             vadj=(1.020V + REGHC_VADJ*0.005V)
*
* \return
* none
*
*******************************************************************************/
void Cy_PMIC_Switch_IntToPassTR(void);

/*******************************************************************************
* Function Name: Cy_PassTR_ManuallyEnable
****************************************************************************//**
*
* \brief        : Enable pass transistor manually.
*
* \param        : vadj between 0x11 to 0x16 for VCCD around 1.1 [V]
*
* \return       : None
*
*******************************************************************************/
void Cy_PassTR_ManuallyEnable(cy_en_sysreg_reghc_vadj_t vadj);

/*******************************************************************************
* Function Name: Cy_PassTR_IsReady
****************************************************************************//**
*
* \brief        : returns the pass TR is ready or not
*
* \param        : None
*
* \return       : true: ready, false: not ready
*
*******************************************************************************/
bool Cy_PassTR_IsReady(void);



/** \} group_button_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_REGHC_H */

/** \} group_pmic */

/* [] END OF FILE */
