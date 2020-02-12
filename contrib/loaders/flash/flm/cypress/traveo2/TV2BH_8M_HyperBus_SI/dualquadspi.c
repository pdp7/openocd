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

#define D_QUAD_SLAVES (cy_en_smif_slave_select_t)((uint8_t)CY_SMIF_SLAVE_SELECT_0 | (uint8_t)CY_SMIF_SLAVE_SELECT_1)
#define SETTING_DELAY_SEL CY_SMIF_NO_DELAY_SEL
#define SETTING_DLP_AUTO CY_SMIF_DLP_UPDATE_MANUAL
#define XIP_ADDR 0x60000000

static const struct cy_stc_smif_port {
	volatile stc_GPIO_PRT_t *port;
	uint8_t pin;
	en_hsiom_sel_t hsiom;
	uint32_t driveMode;
} cy_stc_smif_port[] = {
	{CY_SMIF0_CLK_PORT, CY_SMIF0_CLK_PIN, CY_SMIF0_CLK_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF0_RWDS_PORT, CY_SMIF0_RWDS_PIN, CY_SMIF0_RWDS_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF0_SELECT0_PORT, CY_SMIF0_SELECT0_PIN, CY_SMIF0_SELECT0_PIN_MUX, CY_GPIO_DM_PULLUP},
	{CY_SMIF0_SELECT1_PORT, CY_SMIF0_SELECT1_PIN, CY_SMIF0_SELECT1_PIN_MUX, CY_GPIO_DM_PULLUP},
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

static cy_stc_smif_context_t smifContext;

static const cy_stc_smif_config_t const smifConfig = {
	.txClk = CY_SMIF_INV_FOR_DDR,
	.rxClk = CY_SMIF_INV_FEEDBACK_CLK,
	.delaySel = SETTING_DELAY_SEL,
	.dlpAuto = SETTING_DLP_AUTO,
	.capDelay = CY_SMIF_CAPTURE_DELAY_0_CYCLE,
	.deselectDelay = CY_SMIF_MIN_DESELECT_1_CLK,
	.setupDelay = CY_SMIF_SETUP_0_CLK_PULUS_MIN,
	.holdDelay = CY_SMIF_HOLD_0_CLK_PULUS_MIN,
	.mode = CY_SMIF_NORMAL,  // MMIO mode
	.blockEvent = CY_SMIF_BUS_ERROR,
};

static const cy_stc_device_s25fl_config_t smifDevDualQuadCfg = {
	.xipReadCmd = CY_SMIF_4QOR,
	.xipReadMode = CY_SMIF_XIP_RW_NON_CONTINUOUS,
	.xipWriteCmd = CY_SMIF_4QPP,
	.mergeTimeoutEnable = true,
	.mergeTimeout = CY_SMIF_MER_TIMEOUT_1_CYCLE,
	.totalTimeoutEnable = true,
	.totalTimeout = 1000u,
	.addr = XIP_ADDR,
	.size = CY_SMIF_DEVICE_64M_BYTE,  // 32Mbyte * 2(device)
	.lc_spi = CY_SMIF_SPI_LATENCY8,
};

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

static int wait_ready(cy_en_smif_slave_select_t slave) {
	for (uint8_t i_slaveNum = 0; i_slaveNum < CY_SMIF_GetDeviceNumber(SMIF0); i_slaveNum++) {
		cy_en_smif_slave_select_t slaveToBeChecked = (cy_en_smif_slave_select_t)((uint8_t)slave & (0x01 << i_slaveNum));
		if ((uint8_t)slaveToBeChecked == 0u) continue;

		// only selected slave will reach hare.
		while (1) {
			volatile un_cy_smif_s25fl128_SR1_t sr1 = {.u8 = 0u};
			Cy_SMIF_S25FL_ReadStatusRegister1(SMIF0, slaveToBeChecked, (uint8_t *)&sr1, &smifContext);
			if (sr1.field.u1WIP == 0u) break;

			volatile un_cy_smif_s25fl128_SR2_t sr2 = {.u8 = 0u};
			Cy_SMIF_S25FL_ReadStatusRegister2(SMIF0, slaveToBeChecked, (uint8_t *)&sr2, &smifContext);
			if ((sr2.field.u1E_ERR == 1u) || (sr2.field.u1P_ERR == 1u)) {
				Cy_SMIF_S25FL_ClearStatusRegister(SMIF0, slaveToBeChecked, &smifContext);
				return 1;
			}
		}
	}

	return 0;
}

static int set_mode(volatile stc_SMIF_t *base, cy_en_smif_mode_t mode) {
	cy_en_smif_status_t status;
	for (int i = 0; i < 100000; i++) {
		status = Cy_SMIF_SetMode(base, mode);
		if (status == CY_SMIF_SUCCESS) return 0;
	}

	return 1;
}

int Init(unsigned long adr, unsigned long clk, unsigned long fnc) {
	SystemInit();

	Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_6);
	configure_pll(64000000);

	SmifPortInit();

	Cy_SMIF_DeInit(SMIF0);
	Cy_SMIF_Init(SMIF0, &smifConfig, 1000, &smifContext);

	Cy_SMIF_DeviceSetDataSelect(SMIF0_DEVICE0, CY_SMIF_DATA_SEL0);
	Cy_SMIF_DeviceWriteEnable(SMIF0_DEVICE0);
	Cy_SMIF_DeviceSetDataSelect(SMIF0_DEVICE1, CY_SMIF_DATA_SEL2);
	Cy_SMIF_DeviceWriteEnable(SMIF0_DEVICE1);
	Cy_SMIF_Enable(SMIF0, &smifContext);

	Cy_SMIF_S25FL_SoftwareReset(SMIF0, D_QUAD_SLAVES, &smifContext);
	CY_ASSERT_L1(wait_ready(D_QUAD_SLAVES) == 0u);

	un_cy_smif_s25fl128_CR1_t cr1 = {.u8 = 0u};
	un_cy_smif_s25fl128_CR2_t cr2 = {.u8 = 0u};
	un_cy_smif_s25fl128_CR3_t cr3 = {.u8 = 0u};

	cr1.field.u1QUAD = 1u;
	cr1.field.u1CMP = 0u;
	cr2.field.u1QPI = 0u;                   // Quad instruction disabled
	cr3.field.u4RL = CY_SMIF_SPI_LATENCY8;  // Latency code
	cr3.field.u1WE = 1u;                    // Wrap Disabled

	stc_cy_smif_s25f_write_reg_t writeRegValue_0;
	writeRegValue_0.stsReg1 = 0x00;
	writeRegValue_0.confgReg1 = cr1.u8;
	writeRegValue_0.confgReg2 = cr2.u8;
	writeRegValue_0.confgReg3 = cr3.u8;

	// Send Write Enable command
	Cy_SMIF_S25FL_WriteEnable(SMIF0, D_QUAD_SLAVES, &smifContext);

	// Write Registers
	Cy_SMIF_S25FL_WriteStatusAndConfigRegister(SMIF0, CY_SMIF_SLAVE_SELECT_0, &writeRegValue_0, 4, &smifContext);
	Cy_SMIF_S25FL_WriteStatusAndConfigRegister(SMIF0, CY_SMIF_SLAVE_SELECT_1, &writeRegValue_0, 4, &smifContext);

	// Wait writing registers complete
	wait_ready(D_QUAD_SLAVES);

	Cy_SMIF_S25FL_SoftwareReset(SMIF0, D_QUAD_SLAVES, &smifContext);
	wait_ready(D_QUAD_SLAVES);

	// 4.4 Set DLP
	uint8_t dlp = 0x34u;
	Cy_SMIF_S25FL_WriteVDLR(SMIF0, D_QUAD_SLAVES, dlp, &smifContext);

	Cy_SMIF_InitDeviceForS25FL(SMIF0_DEVICE0, CY_SMIF_DEV_D_QUAD_BIT_0To3, &smifDevDualQuadCfg);
	Cy_SMIF_InitDeviceForS25FL(SMIF0_DEVICE1, CY_SMIF_DEV_D_QUAD_BIT_4To7, &smifDevDualQuadCfg);

	set_mode(SMIF0, CY_SMIF_MEMORY);
	return 0;
}

int EraseSector(unsigned long adr) {
	if (adr < XIP_ADDR) return __LINE__;
	if (adr >= (XIP_ADDR + 0x8000000)) return __LINE__;
	if (set_mode(SMIF0, CY_SMIF_NORMAL)) return __LINE__;
	if (Cy_SMIF_S25FL_WriteEnable(SMIF0, D_QUAD_SLAVES, &smifContext)) return __LINE__;
	if (Cy_SMIF_S25FL_SectorErase(SMIF0, D_QUAD_SLAVES, (adr - XIP_ADDR) >> 1, &smifContext)) return __LINE__;
	if (wait_ready(D_QUAD_SLAVES)) return __LINE__;
	if (set_mode(SMIF0, CY_SMIF_MEMORY)) return __LINE__;

	return 0;
}

int EraseChip(void) {
	if (set_mode(SMIF0, CY_SMIF_NORMAL)) return __LINE__;
	if (Cy_SMIF_S25FL_WriteEnable(SMIF0, D_QUAD_SLAVES, &smifContext)) return __LINE__;
	if (Cy_SMIF_S25FL_ChipErase(SMIF0, D_QUAD_SLAVES, &smifContext)) return __LINE__;
	if (wait_ready(D_QUAD_SLAVES)) return __LINE__;
	if (set_mode(SMIF0, CY_SMIF_MEMORY)) return __LINE__;

	return 0;
}

int ProgramPage(unsigned long adr, unsigned long sz, unsigned char *buf) {
	if (adr < XIP_ADDR) return __LINE__;
	if (adr >= (XIP_ADDR + 0x8000000)) return __LINE__;
	if (sz != 512) return __LINE__;
	adr = (adr - XIP_ADDR) >> 1;

	if (set_mode(SMIF0, CY_SMIF_NORMAL)) return __LINE__;
	if (Cy_SMIF_S25FL_WriteEnable(SMIF0, D_QUAD_SLAVES, &smifContext)) return __LINE__;
	if (Cy_SMIF_S25FL_Program(SMIF0, D_QUAD_SLAVES, CY_SMIF_4QPP, adr, sz, buf, CY_SMIF_BLOCKING, &smifContext))
		return __LINE__;
	if (wait_ready(D_QUAD_SLAVES)) return __LINE__;
	if (set_mode(SMIF0, CY_SMIF_MEMORY)) return __LINE__;

	return 0;
}

int UnInit(unsigned long fnc) { return 0; }

/* [] END OF FILE */
