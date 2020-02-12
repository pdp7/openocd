/**************************************************************************//**
 * @file     system_tviibh8m.h
 * @brief    CMSIS Cortex-M# Device Peripheral Access Layer Header File for
 *           Device <Device>
 * @version  V5.00
 * @date     02. March 2016
 ******************************************************************************/
/*
 * Copyright (c) 2009-2016 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SYSTEM_TVIIBH8M_H
#define SYSTEM_TVIIBH8M_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**  Start address of the Cortex-M7_0 application */
#ifndef CY_CORTEX_M7_0_APPL_ADDR
    // This symbol is defined in the linker script
    extern char *  __cm7_0_vector_base_linker_symbol;
    #define CY_CORTEX_M7_0_APPL_ADDR      ((uint32_t) &__cm7_0_vector_base_linker_symbol)
#endif

/**  Start address of the Cortex-M7_1 application */
#ifndef CY_CORTEX_M7_1_APPL_ADDR
    // This symbol is defined in the linker script
    extern char *  __cm7_1_vector_base_linker_symbol;
    #define CY_CORTEX_M7_1_APPL_ADDR      ((uint32_t) &__cm7_1_vector_base_linker_symbol)
#endif
    

// Macro to provide a delay option
#define DELAY(loop_till)     do { for( volatile uint32_t loop_cnt = 0; loop_cnt < loop_till; loop_cnt++); } while(0)
// This cycle value should be less than 16777216 (0x01000000, 24bits)
#define DELAY_CORE_CYCLE(cycle) {\
    SysTick->CTRL = 0;\
    SysTick->LOAD = cycle;\
    SysTick->VAL  = 0;\
    SysTick->CTRL = 5;\
    while((SysTick->CTRL & 0x00010000) == 0);\
    SysTick->CTRL = 0;\
}\

/**
* \addtogroup group_system_config_cm_status_macro
* \{
*/
#define CY_SYS_CM_STATUS_OFF                    (0u)    /**< The Cortex-M core is off. */
#define CY_SYS_CM_STATUS_RESET                  (1u)    /**< The Cortex-M core is in reset. */
#define CY_SYS_CM_STATUS_RETAINED               (2u)    /**< The Cortex-M core is retained. */
#define CY_SYS_CM_STATUS_ENABLED                (3u)    /**< The Cortex-M core is enabled */
/** \} group_system_config_cm_status_macro */

/*******************************************************************************
* VCCD selection
*******************************************************************************/
#define CY_SYS_VCCD_PMIC                        (0u)
#define CY_SYS_VCCD_PASS_TR                     (1u)
#define CY_SYS_VCCD_INTERNAL                    (2u)
#define CY_SYS_VCCD_SOURCE                      CY_SYS_VCCD_PASS_TR

/*******************************************************************************
* PLL400#0 leading to CM7 cores output frequency selection
*******************************************************************************/
#define CY_SYS_PLL400M_0_160MHz                 (0u)
#define CY_SYS_PLL400M_0_250MHz                 (1u)
#define CY_SYS_PLL400M_0_320MHz                 (2u)
#define CY_SYS_PLL400M_0_350MHz                 (3u)
#define CY_SYS_PLL400M_0_FREQ                   CY_SYS_PLL400M_0_350MHz

#if (CY_SYS_VCCD_SOURCE == CY_SYS_VCCD_INTERNAL) && (CY_SYS_PLL400M_0_FREQ != CY_SYS_PLL400M_0_160MHz)
  #error "The Core 7 frequency is too high to fulfill spec for internal VCCD."
#endif

/*******************************************************************************
* System Clock Initialization
*******************************************************************************/
#if (CY_USE_PSVP == 1)
    #define CY_INITIAL_TARGET_FAST0_FREQ        ( 24000000UL)

    #define CY_INITIAL_TARGET_FAST1_FREQ        ( 24000000UL)

    #define CY_INITIAL_TARGET_PERI_FREQ         ( 24000000UL)

    #define CY_INITIAL_TARGET_SLOW_FREQ         ( 24000000UL)

    #define CY_CLK_ECO_FREQ_HZ                  ( 10000000UL)

    #define CY_CLK_IMO_FREQ_HZ                  ( 24000000UL)

    /** WCO frequency in Hz */
    #define CY_CLK_WCO_FREQ_HZ                  (    32900UL)

#else
    #define CY_INITIAL_TARGET_FAST0_FREQ        (320000000UL)

    #define CY_INITIAL_TARGET_FAST1_FREQ        (320000000UL)

    #define CY_INITIAL_TARGET_PERI_FREQ         ( 80000000UL)

    #define CY_INITIAL_TARGET_SLOW_FREQ         ( 80000000UL)

    #define CY_CLK_ECO_FREQ_HZ                  ( 16000000UL)

    #define CY_CLK_IMO_FREQ_HZ                  (  8000000UL)

    /** WCO frequency in Hz */
    #define CY_CLK_WCO_FREQ_HZ                  (    32768UL)
#endif

/** HVILO0 frequency in Hz */
#define CY_CLK_HVILO0_FREQ_HZ                   (    32768UL)

/** HVILO1 frequency in Hz */
#define CY_CLK_HVILO1_FREQ_HZ                   (    32768UL)

#define CY_CLK_EXT_FREQ_HZ                      (        0UL) //TODO

/* Do not use these definitions directly in your application */
#define CY_DELAY_MS_OVERFLOW_THRESHOLD          (0x8000u)
#define CY_DELAY_1K_THRESHOLD                   (1000u)
#define CY_DELAY_1K_MINUS_1_THRESHOLD           (CY_DELAY_1K_THRESHOLD - 1u)
#define CY_DELAY_1M_THRESHOLD                   (1000000u)
#define CY_DELAY_1M_MINUS_1_THRESHOLD           (CY_DELAY_1M_THRESHOLD - 1u)

#define CORE_CM7_0			        0 // Cortex-M7 core 0
#define CORE_CM7_1			        1 // Cortex-M7 core 1 
#define CORE_MAX			        2 // Error Selection
    
/************************User Configurable Macro Definitions*******************/

// Macro to select the Clock Source
#define CY_SYSTEM_USE_IMO                       0
#define CY_SYSTEM_USE_EXT                       1
#define CY_SYSTEM_USE_ECO                       2
#define CY_SYSTEM_USE_CLOCK                     CY_SYSTEM_USE_ECO

// Definition of this macro disables the WDT (Enabled in SROM)
#define CY_SYSTEM_WDT_DISABLE

/**************************Definition of global variables**********************/

/** \addtogroup group_system_config_globals
* \{
*/
  
extern uint32_t SystemCoreClock;
extern uint32_t cy_Hfclk0FreqHz;
extern uint32_t cy_PeriClkFreqHz;
extern uint32_t cy_delayFreqHz;
extern uint32_t cy_delayFreqKhz;
extern uint8_t  cy_delayFreqMhz;
extern uint32_t cy_delay32kMs;

/** \} group_system_config_globals */

/******************************Definition of global functions******************/

/**
  \brief Setup the microcontroller system.

   Initialize the System and update the SystemCoreClock variable.
 */
extern void     SystemInit (void);

extern uint32_t Cy_SaveIRQ(void);
extern void     Cy_RestoreIRQ(uint32_t saved);

/**
  \brief  Update SystemCoreClock variable.

   Updates the SystemCoreClock with current core Clock retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate (void);

extern void Cy_SystemInitFpuEnable(void);

extern uint32_t Cy_SysGetApplCoreStatus(uint8_t core);
extern void     Cy_SysEnableApplCore(uint8_t core, uint32_t vectorTableOffset);
extern void     Cy_SysDisableApplCore(uint8_t core);
extern void     Cy_SysRetainApplCore(uint8_t core);
extern void     Cy_SysResetApplCore(uint8_t core);



#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_TVIIBH8M_H */
