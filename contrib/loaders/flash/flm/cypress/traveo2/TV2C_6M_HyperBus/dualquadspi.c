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

// clang-format off
//#include "cy_smif_hb_flash.c"
#include "system_tviic2d6m_cm0plus.c"
#include "cy_syslib.c"
#include "cy_smif_s25fl.c"
#include "cy_smif_s28h.c"
#include "cy_smif_memslot.c"
#include "cy_smif.c"
#include "cy_gpio.c"
#include "cy_syswdt.c"
#include "cy_smif_device_common.c"
// clang-format on

#include "stdint.h"
#include "string.h"

#if !defined(SMIF_CH_0) && !defined(SMIF_CH_1)
#error "None of SMIF_CH_0 / SMIF_CH_0 defined"
#endif

// Switch for SMIF instance to be used

#if defined(SMIF_CH_0)
#define SMIF_USED SMIF0
#define SMIF_DEVICE0 SMIF0_DEVICE0
#define SMIF_DEVICE1 SMIF0_DEVICE1

#define CY_SMIF_CLK_PORT CY_SMIF0_CLK_PORT
#define CY_SMIF_CLK_PIN CY_SMIF0_CLK_PIN
#define CY_SMIF_CLK_PIN_MUX CY_SMIF0_CLK_PIN_MUX

#define CY_SMIF_RWDS_PORT CY_SMIF0_RWDS_PORT
#define CY_SMIF_RWDS_PIN CY_SMIF0_RWDS_PIN
#define CY_SMIF_RWDS_PIN_MUX CY_SMIF0_RWDS_PIN_MUX

#define CY_SMIF_SELECT0_PORT CY_SMIF0_SELECT0_PORT
#define CY_SMIF_SELECT0_PIN CY_SMIF0_SELECT0_PIN
#define CY_SMIF_SELECT0_PIN_MUX CY_SMIF0_SELECT0_PIN_MUX

#define CY_SMIF_SELECT1_PORT CY_SMIF0_SELECT1_PORT
#define CY_SMIF_SELECT1_PIN CY_SMIF0_SELECT1_PIN
#define CY_SMIF_SELECT1_PIN_MUX CY_SMIF0_SELECT1_PIN_MUX

#define CY_SMIF_DATA0_PORT CY_SMIF0_DATA0_PORT
#define CY_SMIF_DATA0_PIN CY_SMIF0_DATA0_PIN
#define CY_SMIF_DATA0_PIN_MUX CY_SMIF0_DATA0_PIN_MUX

#define CY_SMIF_DATA1_PORT CY_SMIF0_DATA1_PORT
#define CY_SMIF_DATA1_PIN CY_SMIF0_DATA1_PIN
#define CY_SMIF_DATA1_PIN_MUX CY_SMIF0_DATA1_PIN_MUX

#define CY_SMIF_DATA2_PORT CY_SMIF0_DATA2_PORT
#define CY_SMIF_DATA2_PIN CY_SMIF0_DATA2_PIN
#define CY_SMIF_DATA2_PIN_MUX CY_SMIF0_DATA2_PIN_MUX

#define CY_SMIF_DATA3_PORT CY_SMIF0_DATA3_PORT
#define CY_SMIF_DATA3_PIN CY_SMIF0_DATA3_PIN
#define CY_SMIF_DATA3_PIN_MUX CY_SMIF0_DATA3_PIN_MUX

#define CY_SMIF_DATA4_PORT CY_SMIF0_DATA4_PORT
#define CY_SMIF_DATA4_PIN CY_SMIF0_DATA4_PIN
#define CY_SMIF_DATA4_PIN_MUX CY_SMIF0_DATA4_PIN_MUX

#define CY_SMIF_DATA5_PORT CY_SMIF0_DATA5_PORT
#define CY_SMIF_DATA5_PIN CY_SMIF0_DATA5_PIN
#define CY_SMIF_DATA5_PIN_MUX CY_SMIF0_DATA5_PIN_MUX

#define CY_SMIF_DATA6_PORT CY_SMIF0_DATA6_PORT
#define CY_SMIF_DATA6_PIN CY_SMIF0_DATA6_PIN
#define CY_SMIF_DATA6_PIN_MUX CY_SMIF0_DATA6_PIN_MUX

#define CY_SMIF_DATA7_PORT CY_SMIF0_DATA7_PORT
#define CY_SMIF_DATA7_PIN CY_SMIF0_DATA7_PIN
#define CY_SMIF_DATA7_PIN_MUX CY_SMIF0_DATA7_PIN_MUX

#define XIP_ADDR 0x60000000

/* !! YOTS: Possibly, the number of HF clock for SMFI will be changed. */
#define SMIF_HF_CLOCK CY_SYSCLK_HFCLK_8

#elif defined (SMIF_CH_1)
#define SMIF_USED SMIF1
#define SMIF_DEVICE0 SMIF1_DEVICE0
#define SMIF_DEVICE1 SMIF1_DEVICE1

#define CY_SMIF_CLK_PORT CY_SMIF1_CLK_PORT
#define CY_SMIF_CLK_PIN CY_SMIF1_CLK_PIN
#define CY_SMIF_CLK_PIN_MUX CY_SMIF1_CLK_PIN_MUX

#define CY_SMIF_RWDS_PORT CY_SMIF1_RWDS_PORT
#define CY_SMIF_RWDS_PIN CY_SMIF1_RWDS_PIN
#define CY_SMIF_RWDS_PIN_MUX CY_SMIF1_RWDS_PIN_MUX

#define CY_SMIF_SELECT0_PORT CY_SMIF1_SELECT0_PORT
#define CY_SMIF_SELECT0_PIN CY_SMIF1_SELECT0_PIN
#define CY_SMIF_SELECT0_PIN_MUX CY_SMIF1_SELECT0_PIN_MUX

#define CY_SMIF_SELECT1_PORT CY_SMIF1_SELECT1_PORT
#define CY_SMIF_SELECT1_PIN CY_SMIF1_SELECT1_PIN
#define CY_SMIF_SELECT1_PIN_MUX CY_SMIF1_SELECT1_PIN_MUX

#define CY_SMIF_DATA0_PORT CY_SMIF1_DATA0_PORT
#define CY_SMIF_DATA0_PIN CY_SMIF1_DATA0_PIN
#define CY_SMIF_DATA0_PIN_MUX CY_SMIF1_DATA0_PIN_MUX

#define CY_SMIF_DATA1_PORT CY_SMIF1_DATA1_PORT
#define CY_SMIF_DATA1_PIN CY_SMIF1_DATA1_PIN
#define CY_SMIF_DATA1_PIN_MUX CY_SMIF1_DATA1_PIN_MUX

#define CY_SMIF_DATA2_PORT CY_SMIF1_DATA2_PORT
#define CY_SMIF_DATA2_PIN CY_SMIF1_DATA2_PIN
#define CY_SMIF_DATA2_PIN_MUX CY_SMIF1_DATA2_PIN_MUX

#define CY_SMIF_DATA3_PORT CY_SMIF1_DATA3_PORT
#define CY_SMIF_DATA3_PIN CY_SMIF1_DATA3_PIN
#define CY_SMIF_DATA3_PIN_MUX CY_SMIF1_DATA3_PIN_MUX

#define CY_SMIF_DATA4_PORT CY_SMIF1_DATA4_PORT
#define CY_SMIF_DATA4_PIN CY_SMIF1_DATA4_PIN
#define CY_SMIF_DATA4_PIN_MUX CY_SMIF1_DATA4_PIN_MUX

#define CY_SMIF_DATA5_PORT CY_SMIF1_DATA5_PORT
#define CY_SMIF_DATA5_PIN CY_SMIF1_DATA5_PIN
#define CY_SMIF_DATA5_PIN_MUX CY_SMIF1_DATA5_PIN_MUX

#define CY_SMIF_DATA6_PORT CY_SMIF1_DATA6_PORT
#define CY_SMIF_DATA6_PIN CY_SMIF1_DATA6_PIN
#define CY_SMIF_DATA6_PIN_MUX CY_SMIF1_DATA6_PIN_MUX

#define CY_SMIF_DATA7_PORT CY_SMIF1_DATA7_PORT
#define CY_SMIF_DATA7_PIN CY_SMIF1_DATA7_PIN
#define CY_SMIF_DATA7_PIN_MUX CY_SMIF1_DATA7_PIN_MUX

#define XIP_ADDR 0x80000000

/* !! YOTS: Possibly, the number of HF clock for SMFI will be changed. */
#define SMIF_HF_CLOCK CY_SYSCLK_HFCLK_9

#else
#error "not existing smif channel selected."
#endif

#define DLP_VALUE (0x34u)
#if (CY_SMIF0_QUAD_MEMORY == CY_SMIF_S25FXXXS)
#define TEST_SPI_READ_LC CY_SMIF_S25FL_RD_LATENCY2
#elif (CY_SMIF0_QUAD_MEMORY == CY_SMIF_S25FXXXL)
#define TEST_SPI_READ_LC CY_SMIF_S25FL_RD_LATENCY8
#endif

#define TEST_SPI_WRITE_LC CY_SMIF_S25FL_WT_LATENCY0

//#define TEST_PROGRAM_SECTOR (0x01240000ul)
#define TEST_PROGRAM_SECTOR (0ul)

#define TEST_DQUAD_XIP_PROGRAM_ADDR (TEST_PROGRAM_SECTOR * 2ul)
#define D_QUAD_SLAVES (cy_en_smif_slave_select_t)((uint8_t)CY_SMIF_SLAVE_SELECT_0 | (uint8_t)CY_SMIF_SLAVE_SELECT_1)

#if (CY_SMIF0_QUAD_MEMORY == CY_SMIF_S25FXXXS)
#define DEVICE_PROGRAM_BUFFER_SIZE (0x200)  // 512B
#define DEVICE_SECTOR_ERASE (0x00040000)    // 256KB
#elif (CY_SMIF0_QUAD_MEMORY == CY_SMIF_S25FXXXL)
#define DEVICE_PROGRAM_BUFFER_SIZE (0x100)  // 256B
#define DEVICE_SECTOR_ERASE (0x00001000)    // 4KB
#endif

/**
																TEST_PROGRAM_SECTOR is the address recognized by
External Quad Devices. TEST_DQUAD_XIP_PROGRAM_ADDR is the address recognized by TVII in XIP, Dual Quad mode.
**/

// #define DLP_SETTING_UPDATE_AUTO

#ifdef DLP_SETTING_UPDATE_AUTO
#define SETTING_DELAY_SEL CY_SMIF_1_NEW_SEL_PER_TAP
#define SETTING_DLP_AUTO CY_SMIF_DLP_UPDATE_AUTO
#else
#define SETTING_DELAY_SEL CY_SMIF_NO_DELAY_SEL
#define SETTING_DLP_AUTO CY_SMIF_DLP_UPDATE_MANUAL
#endif

#define USE_QUAD_MODE 1  // 0: not quad, 1: quad

typedef struct {
  volatile stc_GPIO_PRT_t *port;
  uint8_t pin;
  en_hsiom_sel_t hsiom;
  uint32_t driveMode;
} cy_stc_smif_port_t;

static const cy_stc_smif_port_t smifPortCfg[] = {
	{CY_SMIF_CLK_PORT, CY_SMIF_CLK_PIN, CY_SMIF_CLK_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF_RWDS_PORT, CY_SMIF_RWDS_PIN, CY_SMIF_RWDS_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF_SELECT0_PORT, CY_SMIF_SELECT0_PIN, CY_SMIF_SELECT0_PIN_MUX, CY_GPIO_DM_PULLUP},
	{CY_SMIF_SELECT1_PORT, CY_SMIF_SELECT1_PIN, CY_SMIF_SELECT1_PIN_MUX, CY_GPIO_DM_PULLUP},
	{CY_SMIF_DATA0_PORT, CY_SMIF_DATA0_PIN, CY_SMIF_DATA0_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF_DATA1_PORT, CY_SMIF_DATA1_PIN, CY_SMIF_DATA1_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF_DATA2_PORT, CY_SMIF_DATA2_PIN, CY_SMIF_DATA2_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF_DATA3_PORT, CY_SMIF_DATA3_PIN, CY_SMIF_DATA3_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF_DATA4_PORT, CY_SMIF_DATA4_PIN, CY_SMIF_DATA4_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF_DATA5_PORT, CY_SMIF_DATA5_PIN, CY_SMIF_DATA5_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF_DATA6_PORT, CY_SMIF_DATA6_PIN, CY_SMIF_DATA6_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF_DATA7_PORT, CY_SMIF_DATA7_PIN, CY_SMIF_DATA7_PIN_MUX, CY_GPIO_DM_STRONG},
};
#define SIZE_OF_PORT (sizeof(smifPortCfg) / sizeof(cy_stc_smif_port_t))

static void SmifPortInit(const cy_stc_smif_port_t cfg[], uint8_t size) {
  cy_stc_gpio_pin_config_t pinCfg = {0};
  for (uint32_t i = 0; i < size; i++) {
	pinCfg.driveMode = cfg[i].driveMode;
	pinCfg.hsiom = cfg[i].hsiom;
	Cy_GPIO_Pin_Init(cfg[i].port, cfg[i].pin, &pinCfg);
  }
}

cy_stc_smif_context_t smifContext;

static const cy_stc_smif_config_t smifConfig = {
	.txClk = CY_SMIF_INV_FOR_DDR,
	.rxClk = CY_SMIF_OUTPUT_CLK,  // Note
	.delaySel = SETTING_DELAY_SEL,
	.dlpAuto = SETTING_DLP_AUTO,
	.capDelay = CY_SMIF_CAPTURE_DELAY_0_CYCLE,
	.deselectDelay = CY_SMIF_MIN_DESELECT_1_CLK,
	.setupDelay = CY_SMIF_SETUP_0_CLK_PULUS_MIN,
	.holdDelay = CY_SMIF_HOLD_0_CLK_PULUS_MIN,
	.mode = CY_SMIF_NORMAL,  // MMIO mode
	.blockEvent = CY_SMIF_BUS_ERROR,
};

static const cy_stc_device_config_t smifDevDualQuadCfg = {
	.xipReadCmdId = CY_SMIF_S25FL_ID_4QIOR,
	.xipReadMode = CY_SMIF_S25FL_RW_NON_CONTINUOUS,
	.writeEn = true,
	.xipWriteCmdId = CY_SMIF_S25FL_ID_4QPP,
	.xipWriteMode = 0u,  // Do not care
	.mergeTimeoutEnable = true,
	.mergeTimeout = CY_SMIF_MER_TIMEOUT_1_CYCLE,
	.totalTimeoutEnable = true,
	.totalTimeout = 1000u,
	.addr = XIP_ADDR,                        // will be updated in the application
	.size = CY_SMIF_DEVICE_64M_BYTE,  // 32Mbyte * 2(device)
	.rdLatencyCode = TEST_SPI_READ_LC,
	.wtLatencyCode = 0,  // Do not care
};

static int TestFor_DQUAD_MMIO_WRITE_Then_MMIO_READ(uint16_t rd_cmdId);

static cy_en_smif_status_t SetModeWithBusyCheck(volatile stc_SMIF_t *base, cy_en_smif_mode_t mode) {
  cy_en_smif_status_t status;
  for (uint32_t i = 0; i < 1000000; i++) {
	status = Cy_SMIF_SetMode(base, mode);
	if (status == CY_SMIF_SUCCESS) return status;
  }
  return status;
}

// return 1, when one of selected device return error during erasing.
// return 0, when erasing completed without error.
static bool WaitDeviceBecomesReady(cy_en_smif_slave_select_t slave) {
  for (uint8_t i_slaveNum = 0; i_slaveNum < CY_SMIF_GetDeviceNumber(SMIF_USED); i_slaveNum++) {
	cy_en_smif_slave_select_t slaveToBeChecked = (cy_en_smif_slave_select_t)((uint8_t)slave & (0x01 << i_slaveNum));
	if ((uint8_t)slaveToBeChecked == 0u) continue;

	// only selected slave will reach hare.
	while (1) {
	  volatile un_cy_smif_s25fl128_SR1_t sr1 = {.u8 = 0u};
	  Cy_SMIF_S25FL_ReadStatusRegister1(SMIF_USED, slaveToBeChecked, (uint8_t *)&sr1, &smifContext);
	  if (sr1.field.u1WIP == 0u) break;

#if (CY_SMIF0_QUAD_MEMORY == CY_SMIF_S25FXXXS)
	  if ((sr1.field.u1E_ERR == 1u) || (sr1.field.u1P_ERR == 1u)) return 1;

#elif (CY_SMIF0_QUAD_MEMORY == CY_SMIF_S25FXXXL)
	  volatile un_cy_smif_s25fl128_SR2_t sr2 = {.u8 = 0u};
	  Cy_SMIF_S25FL_ReadStatusRegister2(SMIF_USED, slaveToBeChecked, (uint8_t *)&sr2, &smifContext);
	  if ((sr2.field.u1E_ERR == 1u) || (sr2.field.u1P_ERR == 1u)) {
		Cy_SMIF_S25FL_ClearStatusRegister(SMIF_USED, slaveToBeChecked, &smifContext);

		return 1;  // error
	  }
#endif
	}
  }
  return 0;
}

#define PLL_200M_0_PATH_NO (3u)
#define PLL200M_0_SOURCE_CLK CY_SYSCLK_CLKPATH_IN_ECO
#define PLL200M_0_SOURCE_FREQ (16000000ul)
#define WAIT_FOR_STABILIZATION (10000ul)
static void ChangeFrequency_PLL200M_0(uint32_t outputFreq) {
#if (CY_USE_PSVP == 0u)
  cy_stc_pll_config_t pll200_0_Config = {
	  .inputFreq = PLL200M_0_SOURCE_FREQ,
	  .outputFreq = outputFreq,  // target PLL output
	  .lfMode = 0u,              // VCO frequency is [200MHz, 400MHz]
	  .outputMode = CY_SYSCLK_FLLPLL_OUTPUT_AUTO,
  };

  CY_ASSERT(Cy_SysClk_HfClockSetSource(CY_SYSCLK_HFCLK_0, CY_SYSCLK_HFCLK_IN_CLKPATH5) == CY_SYSCLK_SUCCESS);
  CY_ASSERT(Cy_SysClk_PllDisable(PLL_200M_0_PATH_NO) == CY_SYSCLK_SUCCESS);
  CY_ASSERT(Cy_SysClk_ClkPathSetSource(PLL_200M_0_PATH_NO, PLL200M_0_SOURCE_CLK) == CY_SYSCLK_SUCCESS);
  CY_ASSERT(Cy_SysClk_PllConfigure(PLL_200M_0_PATH_NO, &pll200_0_Config) == CY_SYSCLK_SUCCESS);
  CY_ASSERT(Cy_SysClk_PllEnable(PLL_200M_0_PATH_NO, WAIT_FOR_STABILIZATION) == CY_SYSCLK_SUCCESS);
  CY_ASSERT(Cy_SysClk_HfClockSetSource(CY_SYSCLK_HFCLK_0, CY_SYSCLK_HFCLK_IN_CLKPATH3) == CY_SYSCLK_SUCCESS);
  return;
#else
  return;
#endif
}

cy_stc_ex_dev_context_t smifDeviceContext;

int Init(unsigned long adr, unsigned long clk, unsigned long fnc) {
  SystemInit();
  Cy_SysClk_HfClkEnable(SMIF_HF_CLOCK);
  ChangeFrequency_PLL200M_0(100000000);  // SMIF out clock will be 50,000,000
  SmifPortInit(smifPortCfg, SIZE_OF_PORT);

  CY_ASSERT(Cy_SMIF_InitExMemContext(CY_SMIF_S25FL, &smifDeviceContext) == CY_SMIF_SUCCESS);

  /*************************/
  /* 1. Setting for SMIF 0 */
  /*************************/
  Cy_SMIF_DeInit(SMIF_USED);
  Cy_SMIF_Init(SMIF_USED, &smifConfig, 1000, &smifContext);

  /************************************/
  /* 2. Setting for SMIF 0 Device 0/1 */
  /************************************/
  Cy_SMIF_DeviceSetDataSelect(SMIF_DEVICE0, CY_SMIF_DATA_SEL0);
  Cy_SMIF_DeviceWriteEnable(SMIF_DEVICE0);
  Cy_SMIF_DeviceSetDataSelect(SMIF_DEVICE1, CY_SMIF_DATA_SEL2);
  Cy_SMIF_DeviceWriteEnable(SMIF_DEVICE1);

  /********************/
  /* 3. Enable SMIF 0 */
  /********************/
  Cy_SMIF_Enable(SMIF_USED, &smifContext);
  Cy_SMIF_CacheDisable(SMIF_USED, CY_SMIF_CACHE_BOTH);

#if (CY_SMIF0_QUAD_MEMORY == CY_SMIF_S25FXXXS)
  /***********************************/
  /* 4. Setting for external devices */
  /***********************************/
  // 4.1 Send Rest command
  Cy_SMIF_S25FL_WriteEnable(SMIF_USED, D_QUAD_SLAVES, &smifContext);
  Cy_SMIF_S25FL_SoftwareReset(SMIF_USED, D_QUAD_SLAVES, &smifContext);

  /*********************************************************/
  /********* Read Status and Configuration registers *******/
  /*********************************************************/
  // 4.2 Read Configulation register 1 and status register 1
  // Read current configuration register 1 and status register 1
  volatile un_cy_smif_s25fl128_CR1_t prevConfigReg0 = {.u8 = 0u};
  volatile un_cy_smif_s25fl128_CR1_t prevConfigReg1 = {.u8 = 0u};
  volatile un_cy_smif_s25fl128_SR1_t prevStatusReg0 = {.u8 = 0u};
  volatile un_cy_smif_s25fl128_SR1_t prevStatusReg1 = {.u8 = 0u};

  Cy_SMIF_S25FL_ReadConfigurationRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, (uint8_t *)&prevConfigReg0, &smifContext);
  Cy_SMIF_S25FL_ReadConfigurationRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_1, (uint8_t *)&prevConfigReg1, &smifContext);
  Cy_SMIF_S25FL_ReadStatusRegister1(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, (uint8_t *)&prevStatusReg0, &smifContext);
  Cy_SMIF_S25FL_ReadStatusRegister1(SMIF_USED, CY_SMIF_SLAVE_SELECT_1, (uint8_t *)&prevStatusReg1, &smifContext);

  /*********************************************************/
  /******* Modify Status and Configuration registers *******/
  /*********************************************************/
  // Modify QUAD and LC field to be set
  prevConfigReg0.field.u1QUAD = USE_QUAD_MODE;
  prevConfigReg0.field.u2LC = TEST_SPI_READ_LC;
  prevConfigReg1.field.u1QUAD = USE_QUAD_MODE;
  prevConfigReg1.field.u2LC = TEST_SPI_READ_LC;
  prevStatusReg0.field.u3BP = 0u;  // no protection
  prevStatusReg1.field.u3BP = 0u;  // no protection

  /*********************************************************/
  /******* Write Status and Configuration registers ********/
  /*********************************************************/
  // Send Write Enable command
  Cy_SMIF_S25FL_WriteEnable(SMIF_USED, D_QUAD_SLAVES, &smifContext);

  // Write Registers
  stc_cy_smif_s25f_write_reg_t writeRegValue_0;
  writeRegValue_0.stsReg1 = prevStatusReg0.u8;
  writeRegValue_0.confgReg1 = prevConfigReg0.u8;

  stc_cy_smif_s25f_write_reg_t writeRegValue_1;
  writeRegValue_1.stsReg1 = prevStatusReg1.u8;
  writeRegValue_1.confgReg1 = prevConfigReg1.u8;

  // Write Registers
  Cy_SMIF_S25FL_WriteStatusAndConfigRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, &writeRegValue_0, 2, &smifContext);
  Cy_SMIF_S25FL_WriteStatusAndConfigRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_1, &writeRegValue_1, 2, &smifContext);

  // Wait writing registers complete
  CY_ASSERT_L1(WaitDeviceBecomesReady(D_QUAD_SLAVES) == 0u);

  /*********************************************************/
  /******* Verify Status and Configuration registers *******/
  /*********************************************************/
  // Check the config register have been writen properly
  volatile un_cy_smif_s25fl128_CR1_t readConfigReg0 = {.u8 = 0u};
  volatile un_cy_smif_s25fl128_CR1_t readConfigReg1 = {.u8 = 0u};
  Cy_SMIF_S25FL_ReadConfigurationRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, (uint8_t *)&readConfigReg0, &smifContext);
  Cy_SMIF_S25FL_ReadConfigurationRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_1, (uint8_t *)&readConfigReg1, &smifContext);
  CY_ASSERT_L1(readConfigReg0.field.u1QUAD == USE_QUAD_MODE);
  CY_ASSERT_L1(readConfigReg0.field.u2LC == TEST_SPI_READ_LC);
  CY_ASSERT_L1(readConfigReg1.field.u1QUAD == USE_QUAD_MODE);
  CY_ASSERT_L1(readConfigReg1.field.u2LC == TEST_SPI_READ_LC);
#elif (CY_SMIF0_QUAD_MEMORY == CY_SMIF_S25FXXXL)
  // 4.1 Send Rest command
  // YOTS: Not implemented yet.

  /*********************************************************/
  /********* Read Status and Configuration registers *******/
  /*********************************************************/
  // 4.2 Read Configulation register 1 and status register 1
  // Read current configuration register 1 and status register 1
  volatile un_cy_smif_s25fl128_SR1_t prevStatusReg1_0 = {.u8 = 0u};
  volatile un_cy_smif_s25fl128_CR1_t prevConfigReg1_0 = {.u8 = 0u};
  volatile un_cy_smif_s25fl128_CR2_t prevConfigReg2_0 = {.u8 = 0u};
  volatile un_cy_smif_s25fl128_CR3_t prevConfigReg3_0 = {.u8 = 0u};

  volatile un_cy_smif_s25fl128_SR1_t prevStatusReg1_1 = {.u8 = 0u};
  volatile un_cy_smif_s25fl128_CR1_t prevConfigReg1_1 = {.u8 = 0u};
  volatile un_cy_smif_s25fl128_CR2_t prevConfigReg2_1 = {.u8 = 0u};
  volatile un_cy_smif_s25fl128_CR3_t prevConfigReg3_1 = {.u8 = 0u};

  Cy_SMIF_S25FL_ReadStatusRegister1(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, (uint8_t *)&prevStatusReg1_0, &smifContext);
  Cy_SMIF_S25FL_ReadConfigurationRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, (uint8_t *)&prevConfigReg1_0,
										  &smifContext);
  Cy_SMIF_S25FL_ReadConfigurationRegister2(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, (uint8_t *)&prevConfigReg2_0,
										   &smifContext);
  Cy_SMIF_S25FL_ReadConfigurationRegister3(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, (uint8_t *)&prevConfigReg3_0,
										   &smifContext);

  Cy_SMIF_S25FL_ReadStatusRegister1(SMIF_USED, CY_SMIF_SLAVE_SELECT_1, (uint8_t *)&prevStatusReg1_1, &smifContext);
  Cy_SMIF_S25FL_ReadConfigurationRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_1, (uint8_t *)&prevConfigReg1_1,
										  &smifContext);
  Cy_SMIF_S25FL_ReadConfigurationRegister2(SMIF_USED, CY_SMIF_SLAVE_SELECT_1, (uint8_t *)&prevConfigReg2_1,
										   &smifContext);
  Cy_SMIF_S25FL_ReadConfigurationRegister3(SMIF_USED, CY_SMIF_SLAVE_SELECT_1, (uint8_t *)&prevConfigReg3_1,
										   &smifContext);

  /*********************************************************/
  /******* Modify Status and Configuration registers *******/
  /*********************************************************/
  prevConfigReg1_0.field.u1QUAD = USE_QUAD_MODE;
  prevConfigReg1_0.field.u1CMP = 0u;
  prevConfigReg2_0.field.u1QPI = 0u;               // Quad instruction disabled
  prevConfigReg3_0.field.u4RL = TEST_SPI_READ_LC;  // Latency code
  prevConfigReg3_0.field.u1WE = 1u;                // Wrap Disabled

  prevConfigReg1_1.field.u1QUAD = USE_QUAD_MODE;
  prevConfigReg1_0.field.u1CMP = 0u;
  prevConfigReg2_1.field.u1QPI = 0u;               // Quad instruction disabled
  prevConfigReg3_1.field.u4RL = TEST_SPI_READ_LC;  // Latency code
  prevConfigReg3_1.field.u1WE = 1u;                // Wrap Disabled

  /*********************************************************/
  /******* Write Status and Configuration registers ********/
  /*********************************************************/
  // Send Write Enable command
  Cy_SMIF_S25FL_WriteEnable(SMIF_USED, D_QUAD_SLAVES, &smifContext);

  stc_cy_smif_s25f_write_reg_t writeRegValue_0;
  writeRegValue_0.stsReg1 = prevStatusReg1_0.u8;
  writeRegValue_0.confgReg1 = prevConfigReg1_0.u8;
  writeRegValue_0.confgReg2 = prevConfigReg2_0.u8;
  writeRegValue_0.confgReg3 = prevConfigReg3_0.u8;

  stc_cy_smif_s25f_write_reg_t writeRegValue_1;
  writeRegValue_1.stsReg1 = prevStatusReg1_1.u8;
  writeRegValue_1.confgReg1 = prevConfigReg1_1.u8;
  writeRegValue_1.confgReg2 = prevConfigReg2_1.u8;
  writeRegValue_1.confgReg3 = prevConfigReg3_1.u8;

  // Write Registers
  Cy_SMIF_S25FL_WriteStatusAndConfigRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, &writeRegValue_0, 4, &smifContext);
  Cy_SMIF_S25FL_WriteStatusAndConfigRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_1, &writeRegValue_1, 4, &smifContext);

  // Wait writing registers complete
  CY_ASSERT_L1(WaitDeviceBecomesReady(D_QUAD_SLAVES) == 0u);

  /*********************************************************/
  /******* Verify Status and Configuration registers *******/
  /*********************************************************/
  // Check the config register have been writen properly
  volatile un_cy_smif_s25fl128_CR1_t readConfigReg1_0 = {.u8 = 0u};
  volatile un_cy_smif_s25fl128_CR2_t readConfigReg2_0 = {.u8 = 0u};
  volatile un_cy_smif_s25fl128_CR3_t readConfigReg3_0 = {.u8 = 0u};
  Cy_SMIF_S25FL_ReadConfigurationRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, (uint8_t *)&readConfigReg1_0,
										  &smifContext);
  Cy_SMIF_S25FL_ReadConfigurationRegister2(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, (uint8_t *)&readConfigReg2_0,
										   &smifContext);
  Cy_SMIF_S25FL_ReadConfigurationRegister3(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, (uint8_t *)&readConfigReg3_0,
										   &smifContext);

  CY_ASSERT_L1(readConfigReg1_0.field.u1QUAD == USE_QUAD_MODE);
  CY_ASSERT_L1(readConfigReg1_0.field.u1CMP == 0u);
  CY_ASSERT_L1(readConfigReg2_0.field.u1QPI == 0u);
  CY_ASSERT_L1(readConfigReg3_0.field.u4RL == TEST_SPI_READ_LC);
  CY_ASSERT_L1(readConfigReg3_0.field.u1WE == 1u);

  volatile un_cy_smif_s25fl128_CR1_t readConfigReg1_1 = {.u8 = 0u};
  volatile un_cy_smif_s25fl128_CR2_t readConfigReg2_1 = {.u8 = 0u};
  volatile un_cy_smif_s25fl128_CR3_t readConfigReg3_1 = {.u8 = 0u};
  Cy_SMIF_S25FL_ReadConfigurationRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_1, (uint8_t *)&readConfigReg1_1,
										  &smifContext);
  Cy_SMIF_S25FL_ReadConfigurationRegister2(SMIF_USED, CY_SMIF_SLAVE_SELECT_1, (uint8_t *)&readConfigReg2_1,
										   &smifContext);
  Cy_SMIF_S25FL_ReadConfigurationRegister3(SMIF_USED, CY_SMIF_SLAVE_SELECT_1, (uint8_t *)&readConfigReg3_1,
										   &smifContext);

  CY_ASSERT_L1(readConfigReg1_1.field.u1QUAD == USE_QUAD_MODE);
  CY_ASSERT_L1(readConfigReg1_1.field.u1CMP == 0u);
  CY_ASSERT_L1(readConfigReg2_1.field.u1QPI == 0u);
  CY_ASSERT_L1(readConfigReg3_1.field.u4RL == TEST_SPI_READ_LC);
  CY_ASSERT_L1(readConfigReg3_1.field.u1WE == 1u);
#endif

  // 4.4 Set DLP
  uint8_t dlp = DLP_VALUE;
  Cy_SMIF_S25FL_WriteVDLR(SMIF_USED, D_QUAD_SLAVES, dlp, &smifContext);

  Cy_SMIF_InitXIPModeForExMem(SMIF_DEVICE0, CY_SMIF_DEV_D_QUAD_BIT_0To3, &smifDevDualQuadCfg, &smifDeviceContext);
  Cy_SMIF_InitXIPModeForExMem(SMIF_DEVICE1, CY_SMIF_DEV_D_QUAD_BIT_4To7, &smifDevDualQuadCfg, &smifDeviceContext);

  SetModeWithBusyCheck(SMIF_USED, CY_SMIF_MEMORY);
  return 0;
}

static void SectorEraseProcedure(cy_en_smif_slave_select_t slave, uint32_t address) {
  Cy_SMIF_S25FL_WriteEnable(SMIF_USED, slave, &smifContext);
  Cy_SMIF_S25FL_SectorErase(SMIF_USED, slave, address, &smifContext);
  CY_ASSERT_L1(WaitDeviceBecomesReady(D_QUAD_SLAVES) == 0);
}

int EraseSector(unsigned long adr) {
  if (adr < XIP_ADDR) return __LINE__;
  if (adr >= (XIP_ADDR + 0x8000000)) return __LINE__;

  if (SetModeWithBusyCheck(SMIF_USED, CY_SMIF_NORMAL)) return __LINE__;
  Cy_SMIF_S25FL_WriteEnable(SMIF_USED, D_QUAD_SLAVES, &smifContext);
  Cy_SMIF_S25FL_SectorErase(SMIF_USED, D_QUAD_SLAVES, (adr - XIP_ADDR) >> 1, &smifContext);
  if (WaitDeviceBecomesReady(D_QUAD_SLAVES)) return __LINE__;
  if (SetModeWithBusyCheck(SMIF_USED, CY_SMIF_MEMORY)) return __LINE__;

  return 0;
}

int EraseChip(void) {
  if (SetModeWithBusyCheck(SMIF_USED, CY_SMIF_NORMAL)) return __LINE__;
  Cy_SMIF_S25FL_WriteEnable(SMIF_USED, D_QUAD_SLAVES, &smifContext);
  if (Cy_SMIF_S25FL_ChipErase(SMIF_USED, D_QUAD_SLAVES, &smifContext)) return __LINE__;
  if (WaitDeviceBecomesReady(D_QUAD_SLAVES)) return __LINE__;
  if (SetModeWithBusyCheck(SMIF_USED, CY_SMIF_MEMORY)) return __LINE__;

  return 0;
}

int ProgramPage(unsigned long adr, unsigned long sz, unsigned char *buf) {
  if (adr < XIP_ADDR) return __LINE__;
  if (adr >= (XIP_ADDR + 0x8000000)) return __LINE__;
  // if (sz != 512) return __LINE__;
  adr = (adr - XIP_ADDR) >> 1;
  if (SetModeWithBusyCheck(SMIF_USED, CY_SMIF_NORMAL)) return __LINE__;
  if (Cy_SMIF_S25FL_WriteEnable(SMIF_USED, D_QUAD_SLAVES, &smifContext)) return __LINE__;
  if (Cy_SMIF_MMIO_Program_ExMem(SMIF_USED, D_QUAD_SLAVES, CY_SMIF_S25FL_ID_4QPP, adr, sz, buf, CY_SMIF_BLOCKING,
								 TEST_SPI_WRITE_LC, 0, &smifDeviceContext, &smifContext))
	return __LINE__;
  if (WaitDeviceBecomesReady(D_QUAD_SLAVES)) return __LINE__;
  if (SetModeWithBusyCheck(SMIF_USED, CY_SMIF_MEMORY)) return __LINE__;
  return 0;
}

int UnInit(unsigned long fnc) { return 0; }

/* [] END OF FILE */
