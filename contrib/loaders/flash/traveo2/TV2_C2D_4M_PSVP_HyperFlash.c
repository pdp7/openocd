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
#include "cy_device_headers.h"
#include "cy_project.h"
#include "tvii_series_smif_ex_adopter.h"

#include <string.h>
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

/************ Modifiable definitions **********/
#define TEST_SECTOR_NO (0)  // modifiable 0 ~ 255
// !!!!!!! Note the sector defined by below will be erased during delay line calibration !!!!!!!!!
#define SECTOR_NO_USED_BY_CALIB (255)  // modifiable 0 ~ 255
/**********************************************/

#define HB_WRITE_BUF_SIZE_WORD (256)   // 256 word = 512 byte
#define HB_SECTOR_SIZE (0x00040000UL)  // 256KB
#define TEST_SECTOR_ADDRESS (HB_SECTOR_SIZE * TEST_SECTOR_NO)
#define SECTOR_ADDR_USED_BY_CALIB (HB_SECTOR_SIZE * SECTOR_NO_USED_BY_CALIB)

cy_stc_smif_config_t const smifConfig = {
	.txClk = CY_SMIF_INV_FOR_DDR,
	.rxClk = CY_SMIF_INV_RWDS,
	.dlpAuto = CY_SMIF_DLP_UPDATE_MANUAL,
	.capDelay = CY_SMIF_CAPTURE_DELAY_0_CYCLE,
	.delaySel = CY_SMIF_1_SEN_SEL_PER_TAP,
	.deselectDelay = CY_SMIF_MIN_DESELECT_1_CLK,
	.setupDelay = CY_SMIF_SETUP_2_CLK_PULUS_MIN,
	.holdDelay = CY_SMIF_HOLD_0_CLK_PULUS_MIN,
	.mode = CY_SMIF_MEMORY,  // XIP mode
	.blockEvent = CY_SMIF_BUS_ERROR,
};
cy_stc_smif_context_t smifContext;

#define HB_FLASH_TARGET_LC CY_SMIF_HB_LC10

static cy_stc_device_hb_config_t smifDevHBFlashCfg = {
	.xipReadCmd = CY_SMIF_HB_READ_CONTINUOUS_BURST,
	.xipWriteCmd = CY_SMIF_HB_WRITE_CONTINUOUS_BURST,
	.mergeEnable = false,  // will be updated in the application
	.mergeTimeout = CY_SMIF_MER_TIMEOUT_1_CYCLE,
	.totalTimeoutEnable = false,
	.totalTimeout = 50,
	.addr = 0,  // will be updated in the application
	.size = CY_SMIF_DEVICE_64M_BYTE,
	.lc_hb = HB_FLASH_TARGET_LC,
	.hbDevType = CY_SMIF_HB_FLASH,
};

typedef struct {
  volatile stc_GPIO_PRT_t* port;
  uint8_t pin;
  en_hsiom_sel_t hsiom;
  uint32_t driveMode;
} cy_stc_smif_port_t;

cy_stc_smif_port_t smifPortCfg[] = {
	{CY_SMIF_CLK_PORT, CY_SMIF_CLK_PIN, CY_SMIF_CLK_PIN_MUX, CY_GPIO_DM_STRONG},
#if defined(CY_SMIF_OLD_VERSION)
	{CY_SMIF_CLK_INV_PORT, CY_SMIF_CLK_INV_PIN, CY_SMIF_CLK_INV_PIN_MUX, CY_GPIO_DM_STRONG},
#endif
	{CY_SMIF_RWDS_PORT, CY_SMIF_RWDS_PIN, CY_SMIF_RWDS_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF_SELECT0_PORT, CY_SMIF_SELECT0_PIN, CY_SMIF_SELECT0_PIN_MUX, CY_GPIO_DM_STRONG},
	{CY_SMIF_SELECT1_PORT, CY_SMIF_SELECT1_PIN, CY_SMIF_SELECT1_PIN_MUX, CY_GPIO_DM_STRONG},
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

static void SmifPortInit(cy_stc_smif_port_t cfg[], uint8_t size) {
  cy_stc_gpio_pin_config_t pinCfg = {0};
  for (uint32_t i = 0; i < size; i++) {
	pinCfg.driveMode = cfg[i].driveMode;
	pinCfg.hsiom = cfg[i].hsiom;
	Cy_GPIO_Pin_Init(cfg[i].port, cfg[i].pin, &pinCfg);
  }
}

static void SetModeWithBusyCheck(volatile stc_SMIF_t* base, cy_en_smif_mode_t mode);
uint16_t HyperFlashReadStatusOpInMMIO(void);
void HyperFlashEraseOpInMMIO(uint32_t address);
void HyperFlashWordProgramOpInMMIO(uint32_t address, uint16_t* writeData, uint16_t halfWordCount);

static CY_SMIF_FLASHDATA* g_base_addr;

__attribute__((used)) int Init(unsigned long adr, unsigned long clk, unsigned long fnc) {
  g_base_addr = (CY_SMIF_FLASHDATA*)adr;
  smifDevHBFlashCfg.addr = (uint32_t)g_base_addr;

  SystemInit();
  Cy_SysClk_HfClkEnable(SMIF_HF_CLOCK);
  ChangePLLFrequency(64000000);  // SMIF out clock will be 80,000,000
  SmifPortInit(smifPortCfg, SIZE_OF_PORT);

  /*************************************/
  /*       SMIF Initialization         */
  /*************************************/
  Cy_SMIF_Init(SMIF_USED, &smifConfig, 1000, &smifContext);
  Cy_SMIF_Set_DelayTapSel(SMIF_USED, (CY_SMIF_GetDelayTapsNumber(SMIF_USED) - 1));
  Cy_SMIF_Enable(SMIF_USED, &smifContext);
  Cy_SMIF_CacheInvalidate(SMIF_USED, CY_SMIF_CACHE_BOTH);
  Cy_SMIF_CacheDisable(SMIF_USED, CY_SMIF_CACHE_BOTH);

  /*************************************/
  /*     SMIF DEVICE Initialization    */
  /*************************************/
  // smifDevHBFlashCfg.addr = (uint32_t)pHyperFlashBaseAddr;
  Cy_SMIF_InitDeviceHyperBus(SMIF_DEVICE0, &smifDevHBFlashCfg);

  /*************************************/
  /*      Hyper Bus Initialization     */
  /*************************************/
  /***** Set Configuration register 1 *****/
  // Load Configuration register 1
  cy_un_h_flash_cfg1_reg_t flashVCR1 = {.u16 = CFG_REG1_DEFAULT_S26K};
  flashVCR1.fld.readLatency = smifDevHBFlashCfg.lc_hb;
  flashVCR1.fld.driveStrength = CY_SMIF_HB_S26K_DRV_34_20_OHMS;
  CY_SMIF_HbFlash_LoadVolatileConfigReg(g_base_addr, flashVCR1.u16);

  // Read Configuration register 1
  uint16_t readConfig1RegVal = CY_SMIF_HbFlash_ReadVolatileConfigReg(g_base_addr);

  // Verify Configuration register 1
  CY_ASSERT(readConfig1RegVal == flashVCR1.u16);
  // CY_SMIF_HbFlash_SectorEraseOp(pHyperFlashBaseAddr, TEST_SECTOR_ADDRESS);

  return 0;
}

static void SetModeWithBusyCheck(volatile stc_SMIF_t* base, cy_en_smif_mode_t mode) {
  cy_en_smif_status_t status;
  do {
	status = Cy_SMIF_SetMode(base, mode);
  } while (status != CY_SMIF_SUCCESS);
}
__attribute__((used)) int UnInit(unsigned long fnc) {
  (void)fnc;
  return (0);
}

__attribute__((used)) int EraseSector(unsigned long adr) {
  CY_SMIF_HB_DEVSTATUS hr;

  if (adr < (unsigned long)g_base_addr) return 1;

  adr -= (unsigned long)g_base_addr;
  hr = CY_SMIF_HbFlash_SectorEraseOp(g_base_addr, (CY_SMIF_ADDRESS)(adr / 2));
  return !(hr == CY_SMIF_DEV_NOT_BUSY);
}

__attribute__((used)) int EraseChip() {
  CY_SMIF_HB_DEVSTATUS hr = CY_SMIF_HbFlash_ChipEraseOp(g_base_addr);
  return !(hr == CY_SMIF_DEV_NOT_BUSY);
}

__attribute__((used)) int ProgramPage(unsigned long adr, unsigned long sz,
									  const unsigned char* buf) {
  if (adr < (unsigned long)g_base_addr) return 1;

  adr -= (unsigned long)g_base_addr;

  CY_SMIF_HB_DEVSTATUS hr;
  CY_SMIF_ADDRESS offset = (adr / 2);
  CY_SMIF_FLASHDATA* data = (CY_SMIF_FLASHDATA*)buf;
  hr = CY_SMIF_HbFlash_WriteBufferProgramOp(g_base_addr, offset, sz >> 1, data);
  return !(hr == CY_SMIF_DEV_NOT_BUSY);
}

/* [] END OF FILE */
