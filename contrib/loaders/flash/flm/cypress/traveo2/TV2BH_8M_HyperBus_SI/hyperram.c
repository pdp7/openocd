/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2019 by Bohdan Tymkiv                                   *
 *   bohdan.tymkiv@cypress.com bohdan200@gmail.com                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/

/* NOTE
 * This driver is designed to work on CYTVII-B-H-8M-176-CPU board
 * configured in PMIC mode (J46 in PMIC position, J41 and J42 shorted)
 * 'Internal' and 'Pass TR' modes are not guaranteed to work correctly
 */

#include "cy_device_headers.h"
#include "cy_project.h"

#define RAM_BURST_LENGTH_128_BYTES 0
#define RAM_LEGACY_WRAPPED_BURST_MANNER 1
#define RAM_FIXED_INITIAL_LATENCY 1
#define OFFSET_STROBE_DISABLED 1
#define NORMAL_OPERATION 1
#define CY_SMIF_HYPERRAM_CONFIG_REG_0 (0x00000800)
#define CY_SMIF_HYPERRAM_CONFIG_REG_1 (0x00000801)
#define XIP_ADDR 0x64000000

static const cy_stc_smif_config_t smifConfig = {
	.txClk = CY_SMIF_INV_FOR_DDR,
	.rxClk = CY_SMIF_INV_RWDS,
	.capDelay = CY_SMIF_CAPTURE_DELAY_0_CYCLE,
	.delaySel = CY_SMIF_1_SEN_SEL_PER_TAP,
	.deselectDelay = CY_SMIF_MIN_DESELECT_1_CLK,
	.setupDelay = CY_SMIF_SETUP_0_CLK_PULUS_MIN,
	.holdDelay = CY_SMIF_HOLD_0_CLK_PULUS_MIN,
	.mode = CY_SMIF_MEMORY,
	.blockEvent = CY_SMIF_BUS_ERROR,
};

static cy_stc_smif_context_t smifContext;

cy_stc_device_hb_config_t smifDevHBSramCfg = {
	.xipReadCmd = CY_SMIF_HB_READ_WRAPPED_BURST,
	.xipWriteCmd = CY_SMIF_HB_WRITE_WRAPPED_BURST,
	.mergeTimeoutEnable = true,
	.mergeTimeout = CY_SMIF_MER_TIMEOUT_1_CYCLE,
	.totalTimeoutEnable = true,
	.totalTimeout = 1000u,
	.addr = XIP_ADDR,
	.size = CY_SMIF_DEVICE_8M_BYTE,
	.lc_hb = CY_SMIF_HB_LC5,
	.hbDevType = CY_SMIF_HB_SRAM,
};
typedef struct {
	uint16_t burstLength : 2;
	uint16_t hybridBurstEnable : 1;
	uint16_t fixedLatencyEnable : 1;
	uint16_t initialLatency : 4;
	uint16_t offsetStrobeEnable : 1;
	uint16_t Reserved0 : 3;
	uint16_t driveStrength : 3;
	uint16_t deepPowerDownEnable : 1;
} stc_hyperram_vcr_t;

typedef union {
	uint16_t u16;
	stc_hyperram_vcr_t fld;
} un_HyperRamVCR_t;

static const struct cy_stc_smif_port {
	volatile stc_GPIO_PRT_t *port;
	uint8_t pin;
	en_hsiom_sel_t hsiom;
	uint32_t driveMode;
} cy_stc_smif_port[] = {
	{CY_SMIF0_CLK_PORT, CY_SMIF0_CLK_PIN, CY_SMIF0_CLK_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF0_RWDS_PORT, CY_SMIF0_RWDS_PIN, CY_SMIF0_RWDS_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF0_SELECT0_PORT, CY_SMIF0_SELECT0_PIN, CY_SMIF0_SELECT0_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF0_SELECT1_PORT, CY_SMIF0_SELECT1_PIN, CY_SMIF0_SELECT1_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF0_DATA0_PORT, CY_SMIF0_DATA0_PIN, CY_SMIF0_DATA0_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF0_DATA1_PORT, CY_SMIF0_DATA1_PIN, CY_SMIF0_DATA1_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF0_DATA2_PORT, CY_SMIF0_DATA2_PIN, CY_SMIF0_DATA2_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF0_DATA3_PORT, CY_SMIF0_DATA3_PIN, CY_SMIF0_DATA3_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF0_DATA4_PORT, CY_SMIF0_DATA4_PIN, CY_SMIF0_DATA4_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF0_DATA5_PORT, CY_SMIF0_DATA5_PIN, CY_SMIF0_DATA5_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF0_DATA6_PORT, CY_SMIF0_DATA6_PIN, CY_SMIF0_DATA6_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF0_DATA7_PORT, CY_SMIF0_DATA7_PIN, CY_SMIF0_DATA7_PIN_MUX, CY_GPIO_DM_STRONG},
};
#define SIZE_OF_PORT (sizeof(cy_stc_smif_port) / sizeof(cy_stc_smif_port[0]))

static void SmifPortInit(void) {
	cy_stc_gpio_pin_config_t pinCfg = {0};
	for (uint32_t i = 0; i < SIZE_OF_PORT; i++) {
		pinCfg.driveMode = cy_stc_smif_port[i].driveMode;
		pinCfg.hsiom = cy_stc_smif_port[i].hsiom;
		Cy_GPIO_Pin_Init(cy_stc_smif_port[i].port, cy_stc_smif_port[i].pin, &pinCfg);
	}
}

#define PLL_200M_0_PATH_NO (3u)
#define PLL200M_0_SOURCE_CLK CY_SYSCLK_CLKPATH_IN_ECO
#define PLL200M_0_SOURCE_FREQ (16000000ul)
#define WAIT_FOR_STABILIZATION (10000ul)

static void configure_pll(uint32_t outputFreq) {
	cy_stc_pll_config_t pll200_0_Config = {
		.inputFreq = PLL200M_0_SOURCE_FREQ,
		.outputFreq = outputFreq,  // target PLL output
		.lfMode = 0u,              // VCO frequency is [200MHz, 400MHz]
		.outputMode = CY_SYSCLK_FLLPLL_OUTPUT_AUTO,
	};

	Cy_SysClk_HfClockSetSource(CY_SYSCLK_HFCLK_0, CY_SYSCLK_HFCLK_IN_CLKPATH5);
	Cy_SysClk_PllDisable(PLL_200M_0_PATH_NO);
	Cy_SysClk_ClkPathSetSource(PLL_200M_0_PATH_NO, PLL200M_0_SOURCE_CLK);
	Cy_SysClk_PllConfigure(PLL_200M_0_PATH_NO, &pll200_0_Config);
	Cy_SysClk_PllEnable(PLL_200M_0_PATH_NO, WAIT_FOR_STABILIZATION);
	Cy_SysClk_HfClockSetSource(CY_SYSCLK_HFCLK_0, CY_SYSCLK_HFCLK_IN_CLKPATH3);
}

__attribute__((__section__(".start"))) int Init(unsigned long adr, unsigned long clk, unsigned long fnc) {
	SystemInit();
	Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_6);
	configure_pll(64000000);
	SmifPortInit();

	/* 1. Setting for SMIF 0 */
	Cy_SMIF_Init(SMIF0, &smifConfig, 1000, &smifContext);
	Cy_SMIF_Set_DelayTapSel(SMIF0, (CY_SMIF_GetDelayTapsNumber(SMIF0) - 1));
	Cy_SMIF_Enable(SMIF0, &smifContext);
	Cy_SMIF_InitDeviceHyperBus(CY_SMIF0_DEVICE1, &smifDevHBSramCfg);

	Cy_SMIF_CacheDisable(SMIF0, CY_SMIF_CACHE_BOTH);

	uint16_t readVCRValue0 = 0;
	uint16_t readVCRValue1 = 0;

	/* 3. Setting for SMIF 0 Device 1 for hyper RAM */
	Cy_SMIF_InitDeviceHyperBus(CY_SMIF0_DEVICE1, &smifDevHBSramCfg);
	un_HyperRamVCR_t ramVCR = {.u16 = 0xFFFF};
	ramVCR.fld.burstLength = RAM_BURST_LENGTH_128_BYTES;
	ramVCR.fld.hybridBurstEnable = RAM_LEGACY_WRAPPED_BURST_MANNER;
	ramVCR.fld.fixedLatencyEnable = RAM_FIXED_INITIAL_LATENCY;
	ramVCR.fld.initialLatency = smifDevHBSramCfg.lc_hb;
	ramVCR.fld.offsetStrobeEnable = OFFSET_STROBE_DISABLED;
	ramVCR.fld.driveStrength = 7;
	ramVCR.fld.deepPowerDownEnable = NORMAL_OPERATION;
	CY_SMIF_WriteHYPERRAM_REG(CY_SMIF0_DEVICE1, CY_SMIF_HYPERRAM_CONFIG_REG_0, ramVCR.u16);
	CY_SMIF_WriteHYPERRAM_REG(CY_SMIF0_DEVICE1, CY_SMIF_HYPERRAM_CONFIG_REG_1, 0x0001);
	CY_SMIF_ReadHYPERRAM_REG(CY_SMIF0_DEVICE1, CY_SMIF_HYPERRAM_CONFIG_REG_0, &readVCRValue0);
	CY_SMIF_ReadHYPERRAM_REG(CY_SMIF0_DEVICE1, CY_SMIF_HYPERRAM_CONFIG_REG_1, &readVCRValue1);

	/* This image is loaded and executed from TCL script which
	 * expects that execution stops on breakpoint upon completion
	 */
	__BKPT(0);

	return 0;
}

/* [] END OF FILE */
