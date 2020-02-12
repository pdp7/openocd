/***************************************************************************//**
* \file cy_systick.c
* \version 1.0
*
* Provides the API definitions of the SisTick driver.
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include "systick/cy_systick.h"
#include "syslib/cy_syslib.h"
#include "cy_device_headers.h"


static Cy_SysTick_Callback Cy_SysTick_Callbacks[CY_SYS_SYST_NUM_OF_CALLBACKS];
static void Cy_SysTick_ServiceCallbacks(void);


/*******************************************************************************
* Function Name: Cy_SysTick_Init
****************************************************************************//**
*
* \brief  Initializes the callback addresses with pointers to NULL, associates the
* 	  SysTick system vector with the function responsible for calling
* 	  registered callback functions, configures the SysTick timer to generate an
* 	  interrupt periodically.
*
* \param  clockSource : The SysTick clock source \ref en_systick_clock_source_t
* \param  interval    : The SysTick reload value.
*
* \return None
* 
* \note   Clears the SysTick count flag if it was set.
*
*******************************************************************************/
void Cy_SysTick_Init(cy_en_systick_clock_source_t clockSource, uint32_t interval)
{
    uint32_t i;

    for (i = 0u; i<CY_SYS_SYST_NUM_OF_CALLBACKS; i++)
    {
        Cy_SysTick_Callbacks[i] = (void *) 0;
    }

    __ramVectors[CY_SYSTICK_IRQ_NUM] = &Cy_SysTick_ServiceCallbacks;
    Cy_SysTick_ServiceCallbacks();
    Cy_SysTick_SetClockSource(clockSource);

    Cy_SysTick_SetReload(interval);
    Cy_SysTick_Clear();
    Cy_SysTick_Enable();
}

/*******************************************************************************
* Function Name: Cy_SysTick_Enable
****************************************************************************//**
*
* \brief  Enables the SysTick timer and its interrupt.
*
* \param  None
*
* \return None
*
* \note   Clears the SysTick count flag if it was set
*
*******************************************************************************/
void Cy_SysTick_Enable(void)
{
    Cy_SysTick_EnableInterrupt();
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

/*******************************************************************************
* Function Name: Cy_SysTick_Disable
****************************************************************************//**
*
* \brief  Disables the SysTick timer and its interrupt.
*
* \param  None
*
* \return None
*
* \note   Clears the SysTick count flag if it was set
*
*******************************************************************************/
void Cy_SysTick_Disable(void)
{
    Cy_SysTick_DisableInterrupt();
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}	

/*******************************************************************************
* Function Name: Cy_SysTick_EnableInterrupt
****************************************************************************//**
*
* \brief  Enables the SysTick interrupt.
*
* \param  None
*
* \return None
*
* \note   Clears the SysTick count flag if it was set
*
*******************************************************************************/
void Cy_SysTick_EnableInterrupt(void)
{
    SysTick->CTRL = SysTick->CTRL | SysTick_CTRL_TICKINT_Msk;
}

/*******************************************************************************
* Function Name: Cy_SysTick_DisableInterrupt
****************************************************************************//**
*
* \brief  Cy_Disables the SysTick interrupt.
*
* \param  None
*
* \return None
*
* \note   Cy_Clears the SysTick count flag if it was set
*
*******************************************************************************/
void Cy_SysTick_DisableInterrupt(void)
{
    SysTick->CTRL = SysTick->CTRL & ~SysTick_CTRL_TICKINT_Msk;
}

/*******************************************************************************
* Function Name: Cy_SysTick_SetReload
****************************************************************************//**
*
* \brief  Sets the value the counter is set to on a startup and after it reaches zero.
* 	  This function does not change or reset the current sysTick counter value, so
* 	  it should be cleared using the SysTick_Clear() API.
*
* \param  value: The valid range is [0x0-0x00FFFFFF]. The counter reset value.
*
*
* \return None
*******************************************************************************/
void Cy_SysTick_SetReload(uint32_t value)
{
    SysTick->LOAD = (value & SysTick_LOAD_RELOAD_Msk);
}

/*******************************************************************************
* Function Name: Cy_SysTick_Set10msClockCycles
****************************************************************************//**
*
* \brief  Sets the value that Specifies the number of clock source cycles 
*         (minus 1) that make up 10 ms for the selected clock source.
* 	  It is SW’s responsibility to provide the correct value to get 10ms
*         timeout for the selected clock source.
*
* \param  value: The valid range is [0x0-0x00FFFFFF].
*
*
* \return None
*******************************************************************************/
void Cy_SysTick_Set10msCalibration(uint32_t value)
{
    CPUSS->unSYSTICK_CTL.stcField.u24TENMS = (value-1);
}

/*******************************************************************************
* Function Name: Cy_SysTick_Get10msClockCycles
****************************************************************************//**
*
* \brief  Sets the value that Specifies the number of clock source cycles 
*         (plus 1) that make up 10 ms for the selected clock source.
*
* \param  None
*
* \return The clock source cycles to make up 10ms value.
*
*******************************************************************************/
uint32_t Cy_SysTick_Get10msCalibration(void)
{
//    return (CPUSS->unSYSTICK_CTL.stcField.u24TENMS + 1);
  return ((SysTick->CALIB & SysTick_CALIB_TENMS_Msk) + 1);
}

/*******************************************************************************
* Function Name: Cy_SysTick_GetReload
****************************************************************************//**
*
* \brief  Gets the value the counter is set to on a startup and after it reaches zero.
*
* \param  None
*
* \return The counter reset value.
*
*******************************************************************************/
uint32_t Cy_SysTick_GetReload(void)
{
    return (SysTick->LOAD);
}

/*******************************************************************************
* Function Name: Cy_SysTick_GetValue
****************************************************************************//**
*
* \brief  Gets the current SysTick counter value.
*
* \param  None
*
* \return The current SysTick counter value.
*
*******************************************************************************/
uint32_t Cy_SysTick_GetValue(void)
{
    return (SysTick->VAL);
}

/*******************************************************************************
* Function Name: Cy_SysTick_SetCallback
****************************************************************************//**
*
* \brief  This function allows up to five user-defined interrupt service routine
* 	  functions to be associated with the SysTick interrupt. These are specified
* 	  through the use of pointers to the function.
*
* \param  number : The number of the callback function addresses to be set.
* 	           The valid range is from 0 to 4.
*
* \param  function: The pointer to the function that will be associated with the
* 	 	   SysTick ISR for the specified number.
*
* \return Returns the address of the previous callback function.
* 	  The NULL is returned if the specified address in not set.
*
* \note  The registered callback functions will be executed in the interrupt.
*
*******************************************************************************/
Cy_SysTick_Callback Cy_SysTick_SetCallback(uint32_t number, Cy_SysTick_Callback function)
{
    Cy_SysTick_Callback retVal;

    retVal = Cy_SysTick_Callbacks[number];
    Cy_SysTick_Callbacks[number] = function;
    return (retVal);
}

/*******************************************************************************
* Function Name: Cy_SysTick_GetCallback
****************************************************************************//**
*
* \brief  The function gets the specified callback pointer.
*
* \param  number : The number of the callback function address to get. The valid
* 		  range is from 0 to 4.
*
* \return Returns the address of the specified callback function.
* 	  The NULL is returned if the specified address in not initialized.
*
*******************************************************************************/
Cy_SysTick_Callback Cy_SysTick_GetCallback(uint32_t number)
{
    return ((Cy_SysTick_Callback) Cy_SysTick_Callbacks[number]);
}


/*******************************************************************************
* Function Name: Cy_SysTick_SetClockSource
****************************************************************************//**
*
* \brief  Sets the clock source for the SysTick counter.
*
* Clears the SysTick count flag if it was set. If the clock source is not ready
* this function call will have no effect. After changing the clock source to the
* low frequency clock, the counter and reload register values will remain
* unchanged so the time to the interrupt will be significantly longer and vice
* versa.
*
* Changing the SysTick clock source and/or its frequency will change
* the interrupt interval and that SysTick_SetReload() should be
* called to compensate this change.
*
* \param clockSource : \ref en_systick_clock_source_t Clock source.
*
*******************************************************************************/
void Cy_SysTick_SetClockSource(cy_en_systick_clock_source_t clockSource)
{
    if (clockSource == CY_SYSTICK_CLOCK_SOURCE_CLK_CPU)
    {
        SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
        CPUSS->unSYSTICK_CTL.stcField.u1NOREF = 1;
    }
    else
    {
        CPUSS->unSYSTICK_CTL.stcField.u2CLOCK_SOURCE = (uint32_t) clockSource;
        CPUSS->unSYSTICK_CTL.stcField.u1NOREF = 0;
        SysTick->CTRL &= ~SysTick_CTRL_CLKSOURCE_Msk;
    }
}

/*******************************************************************************
* Function Name: Cy_SysTick_GetClockSource
****************************************************************************//**
*
* \brief   Gets the clock source for the SysTick counter.
*
* \param   None
*
* \returns \ref en_systick_clock_source_t Clock source
*
*******************************************************************************/
cy_en_systick_clock_source_t Cy_SysTick_GetClockSource(void)
{
    cy_en_systick_clock_source_t returnValue;

    if ((SysTick->CTRL & SysTick_CTRL_CLKSOURCE_Msk) != 0u)
    {
        returnValue = CY_SYSTICK_CLOCK_SOURCE_CLK_CPU;
    }
    else
    {
        returnValue =  (cy_en_systick_clock_source_t)CPUSS->unSYSTICK_CTL.stcField.u2CLOCK_SOURCE;
    }

    return(returnValue);
}

/*******************************************************************************
* Function Name: Cy_SysTick_GetCountFlag
****************************************************************************//**
*
* \brief  The count flag is set, once the SysTick counter reaches zero.
* 	  The flag is cleared on read.
*
* \param  None
*
* \return Returns a non-zero value if a flag is set, otherwise a zero is
* 	  returned.
*
* \note   Clears the SysTick count flag if it was set.
*
*******************************************************************************/
uint32_t Cy_SysTick_GetCountFlag(void)
{
    return (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk);
}

/*******************************************************************************
* Function Name: Cy_SysTick_Clear
****************************************************************************//**
*
* \brief  Clears the SysTick counter for a well-defined startup.
*
* \param  None
*
* \return None
*
*******************************************************************************/
void Cy_SysTick_Clear(void)
{
  SysTick->VAL = 0u;
}

/*******************************************************************************
* Function Name: Cy_SysTick_ServiceCallbacks
****************************************************************************//**
*
* The system Tick timer interrupt routine.
*
*******************************************************************************/
static void Cy_SysTick_ServiceCallbacks(void)
{
    uint32_t i;

    /* Verify that tick timer flag was set */
    if (0u != Cy_SysTick_GetCountFlag())
    {
        for (i=0u; i < CY_SYS_SYST_NUM_OF_CALLBACKS; i++)
        {
            if (Cy_SysTick_Callbacks[i] != (void *) 0)
            {
                (void)(Cy_SysTick_Callbacks[i])();
            }
        }
    }
}


/* [] END OF FILE */
