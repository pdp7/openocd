/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
 */

#include <string.h>
#include "cy_device_headers.h"
#include "cy_project.h"
#include "tvii_series_smif_ex_adopter.h"

#include "glue_functions.c"
#include "sdl/common/src/drivers/gpio/cy_gpio.c"
#include "sdl/common/src/drivers/syslib/cy_syslib.c"
#include "sdl/common/src/drivers/syspm/cy_syspm.c"
#include "sdl/common/src/drivers/syswdt/cy_syswdt.c"
#include "sdl/tviic2d4m/src/drivers/smif/cy_smif.c"
#include "sdl/tviic2d4m/src/drivers/smif/cy_smif_memslot.c"
#include "sdl/tviic2d4m/src/drivers/sysclk/cy_sysclk.c"
#include "sdl/tviic2d4m/src/drivers/syspmic/cy_syspmic.c"
//#include "sdl/tviic2d4m/src/mw/pmic/cy_pmic.c"
#include "sdl/tviic2d4m/src/mw/smif_mem/cy_smif_device_common.c"
#include "sdl/tviic2d4m/src/mw/smif_mem/cy_smif_hb_flash.c"
#include "sdl/tviic2d4m/src/system/rev_a/system_tviic2d4m_cm0plus.c"

cy_stc_smif_config_t const smifConfig =
{
	.txClk         = CY_SMIF_INV_FOR_DDR,
	.rxClk         = CY_SMIF_INV_RWDS,
	.dlpAuto       = CY_SMIF_DLP_UPDATE_MANUAL,
	.capDelay      = CY_SMIF_CAPTURE_DELAY_0_CYCLE,
	.delaySel      = CY_SMIF_1_SEN_SEL_PER_TAP,
	.deselectDelay = CY_SMIF_MIN_DESELECT_1_CLK,
	.setupDelay    = CY_SMIF_SETUP_3_CLK_PULUS_MIN,
	.holdDelay     = CY_SMIF_HOLD_1_CLK_PULUS_MIN,
	.mode          = CY_SMIF_MEMORY, // XIP mode
	.blockEvent    = CY_SMIF_BUS_ERROR,
};
cy_stc_smif_context_t smifContext;

#define HB_INITIAL_LC CY_SMIF_HB_LC4

cy_stc_device_hb_config_t smifDevHBSramCfg =
{
	.xipReadCmd         = CY_SMIF_HB_READ_CONTINUOUS_BURST,
	.xipWriteCmd        = CY_SMIF_HB_WRITE_CONTINUOUS_BURST,
	.mergeEnable        = false,
	.mergeTimeout       = CY_SMIF_MER_TIMEOUT_1_CYCLE,
	.totalTimeoutEnable = false,
	.totalTimeout       = 1000u,
	.addr               = 0,                       // will be updated in the application
	.size               = CY_SMIF_DEVICE_8M_BYTE,
	.lc_hb              = HB_INITIAL_LC,
	.hbDevType          = CY_SMIF_HB_SRAM,
};

typedef struct
{
	volatile stc_GPIO_PRT_t*  port;
	uint8_t                   pin;
	en_hsiom_sel_t            hsiom;
	uint32_t                  driveMode;
} cy_stc_smif_port_t;

cy_stc_smif_port_t smifPortCfg[] =
{
	{CY_SMIF_CLK_PORT,         CY_SMIF_CLK_PIN,       CY_SMIF_CLK_PIN_MUX,           CY_GPIO_DM_STRONG},
#if defined(CY_SMIF_OLD_VERSION)
	{CY_SMIF_CLK_INV_PORT,     CY_SMIF_CLK_INV_PIN,   CY_SMIF_CLK_INV_PIN_MUX,       CY_GPIO_DM_STRONG},
#endif
	{CY_SMIF_RWDS_PORT,        CY_SMIF_RWDS_PIN,      CY_SMIF_RWDS_PIN_MUX,          CY_GPIO_DM_STRONG},
	{CY_SMIF_SELECT0_PORT,     CY_SMIF_SELECT0_PIN,   CY_SMIF_SELECT0_PIN_MUX,       CY_GPIO_DM_STRONG},
	{CY_SMIF_SELECT1_PORT,     CY_SMIF_SELECT1_PIN,   CY_SMIF_SELECT1_PIN_MUX,       CY_GPIO_DM_STRONG},
	{CY_SMIF_DATA0_PORT,       CY_SMIF_DATA0_PIN,     CY_SMIF_DATA0_PIN_MUX,         CY_GPIO_DM_STRONG},
	{CY_SMIF_DATA1_PORT,       CY_SMIF_DATA1_PIN,     CY_SMIF_DATA1_PIN_MUX,         CY_GPIO_DM_STRONG},
	{CY_SMIF_DATA2_PORT,       CY_SMIF_DATA2_PIN,     CY_SMIF_DATA2_PIN_MUX,         CY_GPIO_DM_STRONG},
	{CY_SMIF_DATA3_PORT,       CY_SMIF_DATA3_PIN,     CY_SMIF_DATA3_PIN_MUX,         CY_GPIO_DM_STRONG},
	{CY_SMIF_DATA4_PORT,       CY_SMIF_DATA4_PIN,     CY_SMIF_DATA4_PIN_MUX,         CY_GPIO_DM_STRONG},
	{CY_SMIF_DATA5_PORT,       CY_SMIF_DATA5_PIN,     CY_SMIF_DATA5_PIN_MUX,         CY_GPIO_DM_STRONG},
	{CY_SMIF_DATA6_PORT,       CY_SMIF_DATA6_PIN,     CY_SMIF_DATA6_PIN_MUX,         CY_GPIO_DM_STRONG},
	{CY_SMIF_DATA7_PORT,       CY_SMIF_DATA7_PIN,     CY_SMIF_DATA7_PIN_MUX,         CY_GPIO_DM_STRONG},
};
#define SIZE_OF_PORT (sizeof(smifPortCfg)/sizeof(cy_stc_smif_port_t))

static void SmifPortInit(cy_stc_smif_port_t cfg[], uint8_t size) {
  cy_stc_gpio_pin_config_t pinCfg = {0};
  for (uint32_t i = 0; i < size; i++) {
	pinCfg.driveMode = cfg[i].driveMode;
	pinCfg.hsiom = cfg[i].hsiom;
	Cy_GPIO_Pin_Init(cfg[i].port, cfg[i].pin, &pinCfg);
  }
}

static void SetModeWithBusyCheck(volatile stc_SMIF_t* base, cy_en_smif_mode_t mode);

__attribute__((used, __section__(".start"))) int Init(unsigned long adr, unsigned long clk,
													  unsigned long fnc) {
  SystemInit();

  Cy_SysClk_HfClkEnable(SMIF_HF_CLOCK);
  ChangePLLFrequency(64000000);  // SMIF out clock will be 32,000,000

  SmifPortInit(smifPortCfg, SIZE_OF_PORT);

  /*************************************/
  /*       SMIF Initialization         */
  /*************************************/
  Cy_SMIF_Init(SMIF_USED, &smifConfig, 1000, &smifContext);
  Cy_SMIF_Set_DelayTapSel(SMIF_USED, (CY_SMIF_GetDelayTapsNumber(SMIF_USED) - 1));
  Cy_SMIF_Enable(SMIF_USED, &smifContext);
  Cy_SMIF_CacheInvalidate(SMIF_USED, CY_SMIF_CACHE_BOTH);
  Cy_SMIF_CacheDisable(SMIF_USED, CY_SMIF_CACHE_BOTH);

  volatile uint32_t* pHyperRamBaseAddr =
	  (uint32_t*)(CY_SMIF_GetXIP_Address(SMIF_USED) + 0x04000000ul);

  /*************************************/
  /*     SMIF DEVICE Initialization    */
  /*************************************/
  smifDevHBSramCfg.addr = (uint32_t)pHyperRamBaseAddr;
  Cy_SMIF_InitDeviceHyperBus(SMIF_DEVICE1, &smifDevHBSramCfg);

  /*************************************/
  /*      Hyper Bus Initialization     */
  /*************************************/
  /***** Set Configuration register 0 *****/
  // Load Configuration register 0
  cy_un_h_ram_cfg0_reg_t ramVCR = {.u16 = CY_SMIF_CFG_REG0_DEFAULT_S27KXXXX1}; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  ramVCR.fld.readLatency = smifDevHBSramCfg.lc_hb;
  CY_SMIF_WriteHYPERRAM_REG(SMIF_DEVICE1, CY_SMIF_CFG_REG0_ADDR_S27K, ramVCR.u16);
  __BKPT(0);

  // Read Configuration register 0
  uint16_t readVCRValue0 = 0;
  CY_SMIF_ReadHYPERRAM_REG(SMIF_DEVICE1, CY_SMIF_CFG_REG0_ADDR_S27K, &readVCRValue0);

  // Verify Configuration register 0
  CY_ASSERT(readVCRValue0 == ramVCR.u16);

  SetModeWithBusyCheck(SMIF_USED, CY_SMIF_MEMORY);

  //	Cy_SMIF_CacheEnable(SMIF_USED, CY_SMIF_CACHE_BOTH);
  //	Cy_SMIF_CachePrefetchingEnable(SMIF_USED, CY_SMIF_CACHE_BOTH);

  __BKPT(0);
  return 0;
}

static void SetModeWithBusyCheck(volatile stc_SMIF_t* base, cy_en_smif_mode_t mode) {
  cy_en_smif_status_t status;
  do {
	status = Cy_SMIF_SetMode(base, mode);
  } while (status != CY_SMIF_SUCCESS);
}
