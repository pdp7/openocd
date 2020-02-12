/**************************************************************************//**
 * @file     system_tviibh8m_cm0plus.c
 * @brief    CMSIS Cortex-M# Device Peripheral Access Layer Source File for
 *           Device <Device>
 * @version  V5.00
 * @date     28. September 2016
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

#include <stdint.h>
#include <stdbool.h>
#include "cy_device_headers.h"
#include "cy_project.h"

#if CY_SYSTEM_USE_CLOCK == CY_SYSTEM_USE_ECO
	#define CY_SYSTEM_PLL_INPUT_SOURCE       CY_SYSCLK_CLKPATH_IN_ECO

  #if (CY_SYS_PLL400M_0_FREQ == CY_SYS_PLL400M_0_350MHz)
	// PLL_OUT = 16,000,000(Feco) / 4 * 175 / 2 = 350,000,000Hz
	// Restriction: 400,000,000 <= Fvco <= 800,000,000
	// This time, Fvco = 16,000,000 * 175 / 4 = 700,000,000.
	#define CY_SYSTEM_PLL0_CONFIG_REFDIV      (4UL)
	#define CY_SYSTEM_PLL0_CONFIG_FEEDBACKDIV (175UL)
	#define CY_SYSTEM_PLL0_CONFIG_OUTDIV      (2UL)
  #elif (CY_SYS_PLL400M_0_FREQ == CY_SYS_PLL400M_0_320MHz)
	// PLL_OUT = 16,000,000(Feco) / 2 * 80 / 2 = 320,000,000Hz
	// Restriction: 400,000,000 <= Fvco <= 800,000,000
	// This time, Fvco = 16,000,000 * 80 / 2 = 640,000,000.
	#define CY_SYSTEM_PLL0_CONFIG_REFDIV      (2UL)
	#define CY_SYSTEM_PLL0_CONFIG_FEEDBACKDIV (80UL)
	#define CY_SYSTEM_PLL0_CONFIG_OUTDIV      (2UL)
  #elif (CY_SYS_PLL400M_0_FREQ == CY_SYS_PLL400M_0_250MHz)
	// PLL_OUT = 16,000,000(Feco) / 4 * 125 / 2 = 250,000,000Hz
	// Restriction: 400,000,000 <= Fvco <= 800,000,000
	// This time, Fvco = 16,000,000 * 125 / 4 = 500,000,000.
	#define CY_SYSTEM_PLL0_CONFIG_REFDIV      (4UL)
	#define CY_SYSTEM_PLL0_CONFIG_FEEDBACKDIV (125UL)
	#define CY_SYSTEM_PLL0_CONFIG_OUTDIV      (2UL)
  #else
	// PLL_OUT = 16,000,000(Feco) / 1 * 30 / 3 = 160,000,000Hz
	// Restriction: 400,000,000 <= Fvco <= 800,000,000
	// This time, Fvco = 16,000,000 * 30 / 1 = 480,000,000.
	#define CY_SYSTEM_PLL0_CONFIG_REFDIV      (1UL)
	#define CY_SYSTEM_PLL0_CONFIG_FEEDBACKDIV (30UL)
	#define CY_SYSTEM_PLL0_CONFIG_OUTDIV      (3UL)
  #endif

	// PLL_OUT = 16,000,000(Feco) / 2 * 73.72799985 / 3 = 196607999.6Hz
	// Restriction: 400,000,000 <= Fvco <= 800,000,000
	// This time, Fvco = 16,000,000 * 73.72799985 / 2 = 589824000.
	#define CY_SYSTEM_PLL1_CONFIG_REFDIV      (2UL)
	#define CY_SYSTEM_PLL1_CONFIG_FB_INT      (73UL)
	#define CY_SYSTEM_PLL1_CONFIG_FB_FRAC     (12213813UL)
	#define CY_SYSTEM_PLL1_CONFIG_OUTDIV      (3UL)

	// PLL_OUT = 16,000,000(Feco) / 2 * 40 / 2 = 160,000,000Hz
	// Restriction: 170,000,000 <= Fvco <= 400,000,000
	// This time, Fvco = 16,000,000 * 40 / 2 = 320,000,000.
	#define CY_SYSTEM_PLL2_CONFIG_REFDIV      (2UL)
	#define CY_SYSTEM_PLL2_CONFIG_FEEDBACKDIV (40UL)
	#define CY_SYSTEM_PLL2_CONFIG_OUTDIV      (2UL)

	// PLL_OUT = 16,000,000(Feco) / 2 * 30 / 3 = 80,000,000Hz
	// Restriction: 170,000,000 <= Fvco <= 400,000,000
	// This time, Fvco = 16,000,000 * 30 / 2 = 240,000,000.
	#define CY_SYSTEM_PLL3_CONFIG_REFDIV      (2UL)
	#define CY_SYSTEM_PLL3_CONFIG_FEEDBACKDIV (30UL)
	#define CY_SYSTEM_PLL3_CONFIG_OUTDIV      (3UL)

#elif CY_SYSTEM_USE_CLOCK == CY_SYSTEM_USE_IMO
	#define CY_SYSTEM_PLL_INPUT_SOURCE CY_SYSCLK_CLKPATH_IN_IMO

  #if (CY_SYS_PLL400M_0_FREQ == CY_SYS_PLL400M_0_350MHz)
	// PLL_OUT = 8,000,000(Fimo) / 2 * 175 / 2 = 350,000,000Hz
	// Restriction: 400,000,000 < Fvco < 800,000,000
	// This time, Fvco = 8,000,000 * 175 / 2 = 700,000,000.
	#define CY_SYSTEM_PLL0_CONFIG_REFDIV      (2UL)
	#define CY_SYSTEM_PLL0_CONFIG_FEEDBACKDIV (175UL)
	#define CY_SYSTEM_PLL0_CONFIG_OUTDIV      (2UL)
  #elif (CY_SYS_PLL400M_0_FREQ == CY_SYS_PLL400M_0_320MHz)
	// PLL_OUT = 8,000,000(Fimo) / 1 * 80 / 2 = 320,000,000Hz
	// Restriction: 400,000,000 < Fvco < 800,000,000
	// This time, Fvco = 8,000,000 * 80 / 1 = 640,000,000.
	#define CY_SYSTEM_PLL0_CONFIG_REFDIV      (1UL)
	#define CY_SYSTEM_PLL0_CONFIG_FEEDBACKDIV (80UL)
	#define CY_SYSTEM_PLL0_CONFIG_OUTDIV      (2UL)
  #elif (CY_SYS_PLL400M_0_FREQ == CY_SYS_PLL400M_0_250MHz)
	// PLL_OUT = 8,000,000(Fimo) / 2 * 125 / 2 = 250,000,000Hz
	// Restriction: 400,000,000 < Fvco < 800,000,000
	// This time, Fvco = 8,000,000 * 80 / 2 = 500,000,000.
	#define CY_SYSTEM_PLL0_CONFIG_REFDIV      (2UL)
	#define CY_SYSTEM_PLL0_CONFIG_FEEDBACKDIV (125UL)
	#define CY_SYSTEM_PLL0_CONFIG_OUTDIV      (2UL)
  #else
	// PLL_OUT = 8,000,000(Fimo) / 1 * 60 / 3 = 160,000,000Hz
	// Restriction: 400,000,000 < Fvco < 800,000,000
	// This time, Fvco = 8,000,000 * 60 / 1 = 480,000,000.
	#define CY_SYSTEM_PLL0_CONFIG_REFDIV      (1UL)
	#define CY_SYSTEM_PLL0_CONFIG_FEEDBACKDIV (60UL)
	#define CY_SYSTEM_PLL0_CONFIG_OUTDIV      (3UL)
  #endif

	// PLL_OUT = 8,000,000(Fimo) / 1 * 73.72799985 / 3 = 196607999.6Hz
	// Restriction: 400,000,000 <= Fvco <= 800,000,000
	// This time, Fvco = 8,000,000 * 73.72799985 / 1 = 589824000.
	#define CY_SYSTEM_PLL1_CONFIG_REFDIV      (1UL)
	#define CY_SYSTEM_PLL1_CONFIG_FB_INT      (73UL)
	#define CY_SYSTEM_PLL1_CONFIG_FB_FRAC     (12213813UL)
	#define CY_SYSTEM_PLL1_CONFIG_OUTDIV      (3UL)

	// PLL_OUT = 8,000,000(Fimo) / 1 * 40 / 2 = 160,000,000Hz
	// Restriction: 170,000,000 <= Fvco <= 400,000,000
	// This time, Fvco = 8,000,000 * 40 / 1 = 320,000,000.
	#define CY_SYSTEM_PLL2_CONFIG_REFDIV      (1UL)
	#define CY_SYSTEM_PLL2_CONFIG_FEEDBACKDIV (40UL)
	#define CY_SYSTEM_PLL2_CONFIG_OUTDIV      (2UL)

	// PLL_OUT = 8,000,000(Fimo) / 1 * 30 / 3 = 80,000,000Hz
	// Restriction: 170,000,000 <= Fvco <= 400,000,000
	// This time, Fvco = 8,000,000 * 30 / 1 = 240,000,000.
	#define CY_SYSTEM_PLL3_CONFIG_REFDIV      (1UL)
	#define CY_SYSTEM_PLL3_CONFIG_FEEDBACKDIV (30UL)
	#define CY_SYSTEM_PLL3_CONFIG_OUTDIV      (3UL)

#elif CY_SYSTEM_USE_CLOCK == CY_SYSTEM_USE_EXT

	#warning "Not implemented yet!!"

#endif


/** Holds the SlowClk system core clock, which is the system clock frequency supplied to the SysTick timer and the
* processor core clock. This variable can be used by debuggers to query the frequency of the debug timer or to configure
* the trace clock speed.
*
* \attention Compilers must be configured to avoid removing this variable in case the application program is not using
* it. Debugging systems require the variable to be physically present in memory so that it can be examined to configure
* the debugger. */
uint32_t SystemCoreClock  = 0UL;

uint32_t cy_delayFreqHz   = 0UL;

uint32_t cy_delayFreqKhz  = 0UL;

uint8_t cy_delayFreqMhz   = 0UL;

uint32_t cy_delay32kMs    = 0UL;

/*******************************************************************************
* Cy_SysEnableCM7(), Cy_SysRetainCM7(), and Cy_SysResetCM7()
*******************************************************************************/
#define CY_SYS_PWR_CTL_KEY_OPEN  (0x05FAUL)
#define CY_SYS_PWR_CTL_KEY_CLOSE (0xFA05UL)

/*******************************************************************************
* Function Name: WaitCoreCycle
****************************************************************************//**
*
* Used for distribution clock gladually.
*
*******************************************************************************/
#if ((CY_USE_PSVP == 0u) && (CY_SYS_VCCD_SOURCE == CY_SYS_VCCD_PMIC))
#define TIMING_MONZA_PMIC_ENABLE            (4)  // 0: Enable fastest timing, 8:Enable latest timing
#define WAIT_CYCLE_WHILE_DISTRIBUTING_CLOCK (50)
static void WaitCoreCycle(uint32_t cycle)
{
	SysTick->CTRL = 0;
	SysTick->LOAD = cycle;
	SysTick->VAL  = 0;
	SysTick->CTRL = 5;
	while((SysTick->CTRL & 0x00010000) == 0);
	SysTick->CTRL = 0;
}
#endif

/*******************************************************************************
* Function Name: SystemInit
****************************************************************************//**
*
* Initializes the system:
* - Unlocks and disables WDT.
*
*******************************************************************************/
void SystemInit (void)
{
#if defined(CY_SYSTEM_WDT_DISABLE)
	/* disable WDT */
	Cy_WDT_Disable();
#endif /* CY_SYSTEM_WDT_DISABLE */

#if (CY_USE_PSVP == 0u)

	// Needed for SROM API system calls, CDT#323531
	NVIC_SetPriority(CPUIntIdx0_IRQn, 1);
	NVIC_EnableIRQ(CPUIntIdx0_IRQn);
	NVIC_EnableIRQ(CPUIntIdx1_IRQn);

	// temporary VCCD trim fix in SFLASH.
	{
		// PWR_TRIM_HT_PWRSYS_CTL = 0x08600f17;
        //CY_SET_REG32(0x4026321C, 0x08600f00);
	}

#if (CY_SYS_VCCD_SOURCE == CY_SYS_VCCD_PASS_TR)
	Cy_PMIC_Switch_IntToPassTR();
#endif

	/*********** Setting wait state for ROM **********/
	CPUSS->unROM_CTL.stcField.u2SLOW_WS = 1u;
	CPUSS->unROM_CTL.stcField.u2FAST_WS = 0u;

	/*********** Setting wait state for RAM **********/
	CPUSS->unRAM0_CTL0.stcField.u2SLOW_WS = 1u;
	CPUSS->unRAM0_CTL0.stcField.u2FAST_WS = 0u;

	#if defined (CPUSS_RAMC1_PRESENT) && (CPUSS_RAMC1_PRESENT == 1UL)
	CPUSS->unRAM1_CTL0.stcField.u2SLOW_WS = 1u;
	CPUSS->unRAM1_CTL0.stcField.u2FAST_WS = 0u;
	#endif /* defined (CPUSS_RAMC1_PRESENT) && (CPUSS_RAMC1_PRESENT == 1UL) */

	#if defined (CPUSS_RAMC2_PRESENT) && (CPUSS_RAMC2_PRESENT == 1UL)
	CPUSS->unRAM2_CTL0.stcField.u2SLOW_WS = 1u;
	CPUSS->unRAM2_CTL0.stcField.u2FAST_WS = 0u;
	#endif /* defined (CPUSS_RAMC2_PRESENT) && (CPUSS_RAMC2_PRESENT == 1UL) */

	/*********** Setting wait state for FLASH **********/
	FLASHC->unFLASH_CTL.stcField.u4WS = 1u;

	/***    Set clock LF source        ***/
	SRSS->unCLK_SELECT.stcField.u3LFCLK_SEL = CY_SYSCLK_LFCLK_IN_ILO0; // CY_SYSCLK_LFCLK_IN_WCO;

#if CY_SYSTEM_USE_CLOCK == CY_SYSTEM_USE_ECO
	/***    ECO port settings        ***/
	/* P20_2: ECO_IN, P20_3: ECO_OUT */
	/* Default settings should be OK. */

	/***    ECO setting and enabling        ***/
	/* These values need to be confirmed */
	SRSS->unCLK_ECO_CONFIG2.stcField.u3WDTRIM = 4u;
	SRSS->unCLK_ECO_CONFIG2.stcField.u4ATRIM  = 12u;
	SRSS->unCLK_ECO_CONFIG2.stcField.u2FTRIM  = 3u;
	SRSS->unCLK_ECO_CONFIG2.stcField.u2RTRIM  = 3u;
	SRSS->unCLK_ECO_CONFIG2.stcField.u3GTRIM  = 1u;

	SRSS->unCLK_ECO_CONFIG.stcField.u1ECO_EN = 1ul;
	while(SRSS->unCLK_ECO_STATUS.stcField.u1ECO_OK == 0ul);
	while(SRSS->unCLK_ECO_STATUS.stcField.u1ECO_READY == 0ul);
#endif

	/***  Set CPUSS dividers as required        ***/
	/* CLK_MEM */
	CPUSS->unMEM_CLOCK_CTL.stcField.u8INT_DIV     = 0u; /* no division */

	/* CLK_SLOW */
	CPUSS->unSLOW_CLOCK_CTL.stcField.u8INT_DIV    = 1u; /* divided by 2 */

	/* CLK_PERI */
	CPUSS->unPERI_CLOCK_CTL.stcField.u8INT_DIV    = 1u; /* divided by 2 */

	/* CLK_TRC_DBG */
	CPUSS->unTRC_DBG_CLOCK_CTL.stcField.u8INT_DIV = 1u; /* divided by 2 */

	// No setting for CLK_GRx requred. Initial values (no division) should be ok.

	/***     PLL setting and enabling        ***/

	/* Settings for PLL2 */
	SRSS->unCLK_PATH_SELECT[3/*PLL2*/].stcField.u3PATH_MUX = CY_SYSTEM_PLL_INPUT_SOURCE;

	/***     PLL setting and enabling        ***/
	/* Settings for PLL0 */
	SRSS->unCLK_PATH_SELECT[1/*PLL0*/].stcField.u3PATH_MUX = CY_SYSTEM_PLL_INPUT_SOURCE;

	SRSS->CLK_PLL400M[0].unCONFIG2.stcField.u1FRAC_EN      = 0ul;     /* Disabled */

	SRSS->CLK_PLL400M[0].unCONFIG3.stcField.u10SSCG_DEPTH  = 0x029ul; /* -0.5% (down-spread) */
	SRSS->CLK_PLL400M[0].unCONFIG3.stcField.u3SSCG_RATE    = 0ul;     /* Modulation rate = fPFD/4096 */
	SRSS->CLK_PLL400M[0].unCONFIG3.stcField.u1SSCG_DITHER_EN = 1ul;   /* Enabled */
	SRSS->CLK_PLL400M[0].unCONFIG3.stcField.u1SSCG_MODE    = 0ul;     /* Write "0" always */
	SRSS->CLK_PLL400M[0].unCONFIG3.stcField.u1SSCG_EN      = 1ul;

	SRSS->CLK_PLL400M[0].unCONFIG.stcField.u5REFERENCE_DIV = CY_SYSTEM_PLL0_CONFIG_REFDIV;
	SRSS->CLK_PLL400M[0].unCONFIG.stcField.u8FEEDBACK_DIV  = CY_SYSTEM_PLL0_CONFIG_FEEDBACKDIV;
	SRSS->CLK_PLL400M[0].unCONFIG.stcField.u5OUTPUT_DIV    = CY_SYSTEM_PLL0_CONFIG_OUTDIV;
	SRSS->CLK_PLL400M[0].unCONFIG.stcField.u2LOCK_DELAY    = 1ul;     /* Fractional division or spreading */
	SRSS->CLK_PLL400M[0].unCONFIG.stcField.u2BYPASS_SEL    = 0ul;     /* Auto */
	SRSS->CLK_PLL400M[0].unCONFIG.stcField.u1ENABLE        = 1ul;

	/* Settings for PLL1 */
	SRSS->unCLK_PATH_SELECT[2/*PLL1*/].stcField.u3PATH_MUX = CY_SYSTEM_PLL_INPUT_SOURCE;

	SRSS->CLK_PLL400M[1].unCONFIG2.stcField.u24FRAC_DIV    = CY_SYSTEM_PLL1_CONFIG_FB_FRAC;
	SRSS->CLK_PLL400M[1].unCONFIG2.stcField.u3FRAC_DITHER_EN  = 1ul; /* Enabled */
	SRSS->CLK_PLL400M[1].unCONFIG2.stcField.u1FRAC_EN      = 1ul;    /* Enabled */

	SRSS->CLK_PLL400M[1].unCONFIG3.stcField.u1SSCG_EN      = 0ul;    /* Disabled */

	SRSS->CLK_PLL400M[1].unCONFIG.stcField.u5REFERENCE_DIV = CY_SYSTEM_PLL1_CONFIG_REFDIV;
	SRSS->CLK_PLL400M[1].unCONFIG.stcField.u8FEEDBACK_DIV  = CY_SYSTEM_PLL1_CONFIG_FB_INT;
	SRSS->CLK_PLL400M[1].unCONFIG.stcField.u5OUTPUT_DIV    = CY_SYSTEM_PLL1_CONFIG_OUTDIV;
	SRSS->CLK_PLL400M[1].unCONFIG.stcField.u2LOCK_DELAY    = 1ul;    /* Fractional division or spreading */
	SRSS->CLK_PLL400M[1].unCONFIG.stcField.u2BYPASS_SEL    = 0ul;    /* Auto */
	SRSS->CLK_PLL400M[1].unCONFIG.stcField.u1ENABLE        = 1ul;

	/* Settings for PLL2 */
	SRSS->unCLK_PATH_SELECT[3/*PLL2*/].stcField.u3PATH_MUX = CY_SYSTEM_PLL_INPUT_SOURCE;

	SRSS->unCLK_PLL_CONFIG[0].stcField.u7FEEDBACK_DIV      = CY_SYSTEM_PLL2_CONFIG_FEEDBACKDIV;
	SRSS->unCLK_PLL_CONFIG[0].stcField.u5REFERENCE_DIV     = CY_SYSTEM_PLL2_CONFIG_REFDIV;
	SRSS->unCLK_PLL_CONFIG[0].stcField.u5OUTPUT_DIV        = CY_SYSTEM_PLL2_CONFIG_OUTDIV;
	SRSS->unCLK_PLL_CONFIG[0].stcField.u2LOCK_DELAY        = 0ul;    /* Normal operation */
	SRSS->unCLK_PLL_CONFIG[0].stcField.u1PLL_LF_MODE       = 0ul;    /* VCO frequency is [200MHz, 400MHz] Fvco = 400,000,000[Hz] */
	SRSS->unCLK_PLL_CONFIG[0].stcField.u2BYPASS_SEL        = 0ul;    /* Auto */
	SRSS->unCLK_PLL_CONFIG[0].stcField.u1ENABLE            = 1ul;

	/* Settings for PLL3 */
	SRSS->unCLK_PATH_SELECT[4/*PLL4*/].stcField.u3PATH_MUX = CY_SYSTEM_PLL_INPUT_SOURCE;

	SRSS->unCLK_PLL_CONFIG[1].stcField.u7FEEDBACK_DIV      = CY_SYSTEM_PLL3_CONFIG_FEEDBACKDIV;
	SRSS->unCLK_PLL_CONFIG[1].stcField.u5REFERENCE_DIV     = CY_SYSTEM_PLL3_CONFIG_REFDIV;
	SRSS->unCLK_PLL_CONFIG[1].stcField.u5OUTPUT_DIV        = CY_SYSTEM_PLL3_CONFIG_OUTDIV;
	SRSS->unCLK_PLL_CONFIG[1].stcField.u2LOCK_DELAY        = 0ul;    /* Normal operation */
	SRSS->unCLK_PLL_CONFIG[1].stcField.u1PLL_LF_MODE       = 0ul;    /* VCO frequency is [200MHz, 400MHz] Fvco = 240,000,000[Hz] */
	SRSS->unCLK_PLL_CONFIG[1].stcField.u2BYPASS_SEL        = 0ul;    /* Auto */
	SRSS->unCLK_PLL_CONFIG[1].stcField.u1ENABLE            = 1ul;

	/* Waiting for all PLLs being locked */
	while(SRSS->CLK_PLL400M[0].unSTATUS.stcField.u1LOCKED == 0ul);
	while(SRSS->CLK_PLL400M[1].unSTATUS.stcField.u1LOCKED == 0ul);
	while(SRSS->unCLK_PLL_STATUS[0].stcField.u1LOCKED == 0ul);
	while(SRSS->unCLK_PLL_STATUS[1].stcField.u1LOCKED == 0ul);

	/***   Setting  PATH5  source        ***/
	SRSS->unCLK_PATH_SELECT[5].stcField.u3PATH_MUX = CY_SYSCLK_CLKPATH_IN_IMO;

	/***  Setting for each clk_hf        ***/
	struct {uint8_t targetDivRegVal; cy_en_hf_clk_sources_t source;} clkHfSetting[8] =
	{
		{ .targetDivRegVal = 0, .source = CY_SYSCLK_HFCLK_IN_CLKPATH3 /* PLL2: PLL200#0 */ }, // setting for clk_hf0
		{ .targetDivRegVal = 0, .source = CY_SYSCLK_HFCLK_IN_CLKPATH1 /* PLL0: PLL400#0 */ }, // setting for clk_hf1
		{ .targetDivRegVal = 0, .source = CY_SYSCLK_HFCLK_IN_CLKPATH4 /* PLL3: PLL200#1 */ }, // setting for clk_hf2
		{ .targetDivRegVal = 0, .source = CY_SYSCLK_HFCLK_IN_CLKPATH1 /* PLL0: PLL400#0 */ }, // setting for clk_hf3
		{ .targetDivRegVal = 2, .source = CY_SYSCLK_HFCLK_IN_CLKPATH3 /* PLL2: PLL200#0 */ }, // setting for clk_hf4
		{ .targetDivRegVal = 0, .source = CY_SYSCLK_HFCLK_IN_CLKPATH2 /* PLL1: PLL400#1 */ }, // setting for clk_hf5
		{ .targetDivRegVal = 0, .source = CY_SYSCLK_HFCLK_IN_CLKPATH3 /* PLL2: PLL200#0 */ }, // setting for clk_hf6
		{ .targetDivRegVal = 0, .source = CY_SYSCLK_HFCLK_IN_CLKPATH5 /* No PLL/FLL */     }, // setting for clk_hf7
	};

#if (CY_SYS_VCCD_SOURCE == CY_SYS_VCCD_PMIC)
	// Restriction 1. Enabling MONZA PMIC when the current comsumption is from 20 [mA] to 300 [mA]
	//                Please adjust "TIMING_MONZA_PMIC_ENABLE" defined above.
	// Restriction 2. The current rising time has to be more than 10 [us]
	//                Please adjust "WAIT_CYCLE_WHILE_DISTRIBUTING_CLOCK" defined above.
	for(int8_t i_clkHfNo = 0ul; i_clkHfNo < 8; i_clkHfNo++)
	{
		if(i_clkHfNo == TIMING_MONZA_PMIC_ENABLE)
		{
			/***   Enabling MONZA PMIC     ***/
			Cy_PMIC_Switch_IntToPMIC(CY_SYSREG_REGHC_VADJ_16, CY_REGHC_PMIC_CTL_ENABLE_HIGH, CY_REGHC_PMIC_STS_ABNORMAL_LOW, 0ul);
		}
		SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u4ROOT_MUX   = clkHfSetting[i_clkHfNo].source;
		SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u2ROOT_DIV   = 3u; /* divide by 8 */
		SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u1DIRECT_MUX = 1u; /* Select ROOT_MUX */
		SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u1ENABLE     = 1u; /* 1 = enable */
		for(int8_t i_divRegValue = 2; i_divRegValue >= clkHfSetting[i_clkHfNo].targetDivRegVal; i_divRegValue--)
		{
			WaitCoreCycle(WAIT_CYCLE_WHILE_DISTRIBUTING_CLOCK);
			SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u2ROOT_DIV = i_divRegValue;
		}
		WaitCoreCycle(WAIT_CYCLE_WHILE_DISTRIBUTING_CLOCK);
	}
#else
	for(int8_t i_clkHfNo = 0ul; i_clkHfNo < 8; i_clkHfNo++)
	{
		SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u4ROOT_MUX   = clkHfSetting[i_clkHfNo].source;
		SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u2ROOT_DIV   = clkHfSetting[i_clkHfNo].targetDivRegVal; /* divide by 8 */
		SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u1DIRECT_MUX = 1u; /* Select ROOT_MUX */
		SRSS->unCLK_ROOT_SELECT[i_clkHfNo].stcField.u1ENABLE     = 1u; /* 1 = enable */
	}
#endif

	/* CLK_FAST_0 */
	CPUSS->unFAST_0_CLOCK_CTL.stcField.u8INT_DIV  = 0u; /* no division */
	CPUSS->unFAST_0_CLOCK_CTL.stcField.u5FRAC_DIV = 0u; /* no division */

	/* CLK_FAST_1 */
	CPUSS->unFAST_1_CLOCK_CTL.stcField.u8INT_DIV  = 0u; /* no division */
	CPUSS->unFAST_1_CLOCK_CTL.stcField.u5FRAC_DIV = 0u; /* no division */

	/***     FLL  disabling        ***/
	/* Disable Fll */
	SRSS->unCLK_FLL_CONFIG.stcField.u1FLL_ENABLE = 0;     /* 0 = disable */
	SRSS->unCLK_FLL_CONFIG4.stcField.u1CCO_ENABLE = 0;    /* 0 = disable */

	/***     Enabling ILO0        ***/
	Cy_WDT_Unlock();
	SRSS->unCLK_ILO0_CONFIG.stcField.u1ENABLE = 1;        /* 1 = enable */
	SRSS->unCLK_ILO0_CONFIG.stcField.u1ILO0_BACKUP = 1ul; /* Ilo HibernateOn */
	Cy_WDT_Lock();
#endif

	SystemCoreClockUpdate();
	/* Sets clock frequency for Delay API */
}

/*----------------------------------------------------------------------------
  Clock functions
 *----------------------------------------------------------------------------*/

void SystemCoreClockUpdate (void)            /* Get Core Clock Frequency      */
{
	SystemCoreClock  = CY_INITIAL_TARGET_SLOW_FREQ;
	cy_delayFreqHz   = CY_INITIAL_TARGET_SLOW_FREQ; // SystemCoreClock;
	cy_delayFreqMhz  = (uint8_t)((cy_delayFreqHz + CY_DELAY_1M_MINUS_1_THRESHOLD) / CY_DELAY_1M_THRESHOLD);
	cy_delayFreqKhz  = (cy_delayFreqHz + CY_DELAY_1K_MINUS_1_THRESHOLD) / CY_DELAY_1K_THRESHOLD;
	cy_delay32kMs    = CY_DELAY_MS_OVERFLOW_THRESHOLD * cy_delayFreqKhz;
}

/*******************************************************************************
* Function Name: Cy_SysGetApplCoreStatus
****************************************************************************//**
*
* Gets the Cortex-M4/M7 core power mode.
*
* \return \ref group_system_config_cm_status_macro
*
*******************************************************************************/
uint32_t Cy_SysGetApplCoreStatus(uint8_t core)
{
    uint32_t regValue;

	CY_ASSERT(core < CORE_MAX);

	if(core == CORE_CM7_0)
	{
		/* Get current power mode */
		regValue = CPUSS->unCM7_0_PWR_CTL.u32Register;
		regValue = (regValue >> CPUSS_CM7_0_PWR_CTL_PWR_MODE_Pos) & CPUSS_CM7_0_PWR_CTL_PWR_MODE_Msk;
	}
	else if(core == CORE_CM7_1)
	{
		/* Get current power mode */
		regValue = CPUSS->unCM7_1_PWR_CTL.u32Register;
		regValue = (regValue >> CPUSS_CM7_1_PWR_CTL_PWR_MODE_Pos) & CPUSS_CM7_1_PWR_CTL_PWR_MODE_Msk;
	}

	return (regValue);
}

/*******************************************************************************
* Function Name: Cy_SysEnableApplCore
****************************************************************************//**
*
* Enables the Cortex-M4/M7 core. The CPU is enabled once if it was in the disabled
* or retained mode.
*
* \param vectorTableOffset The offset of the vector table base address from
* memory address 0x00000000. The offset should be multiple to 1024 bytes.
*
*******************************************************************************/
void Cy_SysEnableApplCore(uint8_t core, uint32_t vectorTableOffset)
{
	uint32_t cmStatus;
	uint32_t interruptState;
	un_CPUSS_CM7_0_PWR_CTL_t tPwrCtl0;
	un_CPUSS_CM7_1_PWR_CTL_t tPwrCtl1;

	CY_ASSERT(core < CORE_MAX);

//    interruptState = Cy_SaveIRQ();

	cmStatus = Cy_SysGetApplCoreStatus(core);
	if(cmStatus == CY_SYS_CM_STATUS_ENABLED)
	{
		// Set core into reset first, so that new settings can get effective
		// This branch is e.g. entered if a debugger is connected that would power-up the CM7,
		// but let it run in ROM boot or pause its execution by keeping CPU_WAIT bit set.
		Cy_SysResetApplCore(core);
	}

	// CLK_HF1, by default is disabled for use by CM7_0/1, hence enable
	SRSS->unCLK_ROOT_SELECT[1].stcField.u1ENABLE = 1;

	if(core == CORE_CM7_0)
	{
		// Adjust the vector address
		CPUSS->unCM7_0_VECTOR_TABLE_BASE.u32Register = vectorTableOffset;

		// Enable the Power Control Key
		tPwrCtl0.stcField.u16VECTKEYSTAT = CY_SYS_PWR_CTL_KEY_OPEN;
		tPwrCtl0.stcField.u2PWR_MODE = CY_SYS_CM_STATUS_ENABLED;
		CPUSS->unCM7_0_PWR_CTL.u32Register = tPwrCtl0.u32Register;

		CPUSS->unCM7_0_CTL.stcField.u1CPU_WAIT = 0;
	}
	else if(core == CORE_CM7_1)
	{
		// Adjust the vector address
		CPUSS->unCM7_1_VECTOR_TABLE_BASE.u32Register = vectorTableOffset;

		// Enable the Power Control Key
		tPwrCtl1.stcField.u16VECTKEYSTAT = CY_SYS_PWR_CTL_KEY_OPEN;
		tPwrCtl1.stcField.u2PWR_MODE = CY_SYS_CM_STATUS_ENABLED;
		CPUSS->unCM7_1_PWR_CTL.u32Register = tPwrCtl1.u32Register;

		CPUSS->unCM7_1_CTL.stcField.u1CPU_WAIT = 0;
	}

//	Cy_RestoreIRQ(interruptState);
}


/*******************************************************************************
* Function Name: Cy_SysDisableApplCore
****************************************************************************//**
*
* Disables the Cortex-M4/M7 core.
*
* \warning Do not call the function while the Cortex-M4 is executing because
* such a call may corrupt/abort a pending bus-transaction by the CPU and cause
* unexpected behavior in the system including a deadlock. Call the function
* while the Cortex-M4 core is in the Sleep or Deep Sleep low-power mode. Use
* the \ref group_syspm Power Management (syspm) API to put the CPU into the
* low-power modes. Use the \ref Cy_SysPm_ReadStatus() to get a status of the
* CPU.
*
*******************************************************************************/
void Cy_SysDisableApplCore(uint8_t core)
{
	un_CPUSS_CM7_0_PWR_CTL_t tPwrCtl0;
	un_CPUSS_CM7_1_PWR_CTL_t tPwrCtl1;

	CY_ASSERT(core < CORE_MAX);

	if(core == CORE_CM7_0)
	{
		tPwrCtl0.stcField.u16VECTKEYSTAT = CY_SYS_PWR_CTL_KEY_OPEN;
		tPwrCtl0.stcField.u2PWR_MODE = CY_SYS_CM_STATUS_OFF;
		CPUSS->unCM7_0_PWR_CTL.u32Register = tPwrCtl0.u32Register;
	}
	else if(core == CORE_CM7_1)
	{
		tPwrCtl1.stcField.u16VECTKEYSTAT = CY_SYS_PWR_CTL_KEY_OPEN;
		tPwrCtl1.stcField.u2PWR_MODE = CY_SYS_CM_STATUS_OFF;
		CPUSS->unCM7_1_PWR_CTL.u32Register = tPwrCtl1.u32Register;
	}
}


/*******************************************************************************
* Function Name: Cy_SysRetainApplCore
****************************************************************************//**
*
* Retains the Cortex-M4/M7 core.
*
* \warning Do not call the function while the Cortex-M4 is executing because
* such a call may corrupt/abort a pending bus-transaction by the CPU and cause
* unexpected behavior in the system including a deadlock. Call the function
* while the Cortex-M4 core is in the Sleep or Deep Sleep low-power mode. Use
* the \ref group_syspm Power Management (syspm) API to put the CPU into the
* low-power modes. Use the \ref Cy_SysPm_ReadStatus() to get a status of the CPU.
*
*******************************************************************************/
void Cy_SysRetainApplCore(uint8_t core)
{
	uint32_t cmStatus;
	uint32_t  interruptState;
	un_CPUSS_CM7_0_PWR_CTL_t tPwrCtl0;
	un_CPUSS_CM7_1_PWR_CTL_t tPwrCtl1;

	interruptState = Cy_SaveIRQ();

	cmStatus = Cy_SysGetApplCoreStatus(core);
	if(cmStatus == CY_SYS_CM_STATUS_ENABLED)
	{
		if(core == CORE_CM7_0)
		{
			tPwrCtl0.stcField.u16VECTKEYSTAT = CY_SYS_PWR_CTL_KEY_OPEN;
			tPwrCtl0.stcField.u2PWR_MODE = CY_SYS_CM_STATUS_RETAINED;
			CPUSS->unCM7_0_PWR_CTL.u32Register = tPwrCtl0.u32Register;
		}
		else if(core == CORE_CM7_1)
		{
			tPwrCtl1.stcField.u16VECTKEYSTAT = CY_SYS_PWR_CTL_KEY_OPEN;
			tPwrCtl1.stcField.u2PWR_MODE = CY_SYS_CM_STATUS_RETAINED;
			CPUSS->unCM7_1_PWR_CTL.u32Register = tPwrCtl1.u32Register;
		}
	}

	Cy_RestoreIRQ(interruptState);
}


/*******************************************************************************
* Function Name: Cy_SysResetApplCore
****************************************************************************//**
*
* Resets the Cortex-M4/M7 core.
*
* \warning Do not call the function while the Cortex-M4 is executing because
* such a call may corrupt/abort a pending bus-transaction by the CPU and cause
* unexpected behavior in the system including a deadlock. Call the function
* while the Cortex-M4 core is in the Sleep or Deep Sleep low-power mode. Use
* the \ref group_syspm Power Management (syspm) API to put the CPU into the
* low-power modes. Use the \ref Cy_SysPm_ReadStatus() to get a status of the CPU.
*
*******************************************************************************/
void Cy_SysResetApplCore(uint8_t core)
{
	un_CPUSS_CM7_0_PWR_CTL_t tPwrCtl0;
	un_CPUSS_CM7_1_PWR_CTL_t tPwrCtl1;

	CY_ASSERT(core < CORE_MAX);

	if(core == CORE_CM7_0)
	{
		tPwrCtl0.stcField.u16VECTKEYSTAT = CY_SYS_PWR_CTL_KEY_OPEN;
		tPwrCtl0.stcField.u2PWR_MODE = CY_SYS_CM_STATUS_RESET;
		CPUSS->unCM7_0_PWR_CTL.u32Register = tPwrCtl0.u32Register;
	}
	else if(core == CORE_CM7_1)
	{
		tPwrCtl1.stcField.u16VECTKEYSTAT = CY_SYS_PWR_CTL_KEY_OPEN;
		tPwrCtl1.stcField.u2PWR_MODE = CY_SYS_CM_STATUS_RESET;
		CPUSS->unCM7_1_PWR_CTL.u32Register = tPwrCtl1.u32Register;
	}
}

