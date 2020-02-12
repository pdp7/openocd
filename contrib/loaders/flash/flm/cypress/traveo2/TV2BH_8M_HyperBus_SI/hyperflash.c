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

#define FLASH_BURST_LENGTH_32_BYTES 3
#define FLASH_RDS_WILL_STALL 0
#define FLASH_UN_SECT_INTO_LOWEST_ADDR 2
#define FLASH_SECURE_SILICON_REGION_UNLOCKED 1
#define FLASH_VCR_AND_NVCR_UNLOCKED 1
#define FLASH_DRIVE_STRENGTH_34_OHMS 0
#define XIP_ADDR 0x60000000

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

static const cy_stc_device_hb_config_t smifDevHBFlashCfg = {
	.xipReadCmd = CY_SMIF_HB_READ_WRAPPED_BURST,
	.xipWriteCmd = CY_SMIF_HB_WRITE_WRAPPED_BURST,
	.mergeTimeoutEnable = true,
	.mergeTimeout = CY_SMIF_MER_TIMEOUT_1_CYCLE,
	.totalTimeoutEnable = true,
	.totalTimeout = 1000u,
	.addr = XIP_ADDR,
	.size = CY_SMIF_DEVICE_64M_BYTE,
	.lc_hb = CY_SMIF_HB_LC5,
	.hbDevType = CY_SMIF_HB_FLASH,
};

typedef struct {
	volatile stc_GPIO_PRT_t *port;
	uint8_t pin;
	en_hsiom_sel_t hsiom;
	uint32_t driveMode;
} cy_stc_smif_port_t;

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

int Init(unsigned long adr, unsigned long clk, unsigned long fnc) {
	SystemInit();

	Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_6);
	configure_pll(64000000);

	SmifPortInit();

	/* 1. Setting for SMIF 0 */
	Cy_SMIF_Init(SMIF0, &smifConfig, 1000, &smifContext);
	Cy_SMIF_Set_DelayTapSel(SMIF0, (CY_SMIF_GetDelayTapsNumber(SMIF0) - 1));
	Cy_SMIF_Enable(SMIF0, &smifContext);
	Cy_SMIF_InitDeviceHyperBus(CY_SMIF0_DEVICE0, &smifDevHBFlashCfg);

	Cy_SMIF_CacheDisable(SMIF0, CY_SMIF_CACHE_BOTH);

	/* 2. Setting for SMIF 0 Device 0 for hyper FLASH */
	un_HyperFlashVCR_t flashVCR = {.u16 = 0xFFFF};
	flashVCR.fld.burstLength = FLASH_BURST_LENGTH_32_BYTES;
	flashVCR.fld.RDS_stallControll = FLASH_RDS_WILL_STALL;
	flashVCR.fld.readLatency = smifDevHBFlashCfg.lc_hb;
	flashVCR.fld.sectorMapping = FLASH_UN_SECT_INTO_LOWEST_ADDR;
	flashVCR.fld.SSR_freeze = FLASH_SECURE_SILICON_REGION_UNLOCKED;
	flashVCR.fld.VCR_freeze = FLASH_VCR_AND_NVCR_UNLOCKED;
	flashVCR.fld.driveStrength = FLASH_DRIVE_STRENGTH_34_OHMS;
	CY_SMIF_HbFlash_LoadVolatileConfigReg((CY_SMIF_FLASHDATA *)XIP_ADDR, flashVCR.u16);
	uint16_t readConfigRegVal = CY_SMIF_HbFlash_ReadVolatileConfigReg((CY_SMIF_FLASHDATA *)XIP_ADDR);
	if (readConfigRegVal != flashVCR.u16) return __LINE__;

	return 0;
}

int EraseSector(unsigned long adr) {
	if (adr < XIP_ADDR) return __LINE__;
	if (adr >= (XIP_ADDR + 0x8000000)) return __LINE__;
	int hr = CY_SMIF_HbFlash_SectorEraseOp((CY_SMIF_FLASHDATA *)XIP_ADDR, (adr - XIP_ADDR) >> 1);
	if (hr != CY_SMIF_DEV_NOT_BUSY) return __LINE__;
	return 0;
}

int EraseChip(void) {
	int hr = CY_SMIF_HbFlash_ChipEraseOp((CY_SMIF_FLASHDATA *)XIP_ADDR);
	if (hr != CY_SMIF_DEV_NOT_BUSY) return __LINE__;
	return 0;
}

int ProgramPage(unsigned long adr, unsigned long sz, unsigned char *buf) {
	if (adr < XIP_ADDR) return __LINE__;
	if (adr >= (XIP_ADDR + 0x8000000)) return __LINE__;
	int hr = CY_SMIF_HbFlash_WriteBufferProgramOp((CY_SMIF_FLASHDATA *)XIP_ADDR, (adr - XIP_ADDR) >> 1, sz >> 1,
												  (CY_SMIF_FLASHDATA *)buf);
	if (hr != CY_SMIF_DEV_NOT_BUSY) return __LINE__;
	return 0;
}

int UnInit(unsigned long fnc) { return 0; }

/* [] END OF FILE */
