#include "cy_device_headers.h"
#include "cy_project.h"
#include "tvii_series_smif_ex_adopter.h"

#include "glue_functions.c"
#include "sdl/common/src/drivers/gpio/cy_gpio.c"
#include "sdl/common/src/drivers/syslib/cy_syslib.c"
#include "sdl/common/src/drivers/syspm/cy_syspm.c"
#include "sdl/common/src/drivers/syswdt/cy_syswdt.c"
#include "sdl/tviic2d6m/src/drivers/smif/cy_smif.c"
#include "sdl/tviic2d6m/src/drivers/smif/cy_smif_memslot.c"
#include "sdl/tviic2d6m/src/drivers/sysclk/cy_sysclk.c"
#include "sdl/tviic2d6m/src/drivers/syspmic/cy_syspmic.c"
#include "sdl/tviic2d6m/src/mw/pmic/cy_pmic.c"
#include "sdl/tviic2d6m/src/mw/smif_mem/cy_smif_device_common.c"
#include "sdl/tviic2d6m/src/mw/smif_mem/cy_smif_hb_flash.c"
#include "sdl/tviic2d6m/src/mw/smif_mem/cy_smif_semp.c"
#include "sdl/tviic2d6m/src/system/rev_a/system_tviic2d6m_cm0plus.c"

#define TEST_WRITE_LC CY_SMIF_SEMP_WT_LATENCY0
#define TEST_READ_LC \
  CY_SMIF_SEMP_RD_LATENCY2  // SDR SPI: up to 81MHz, SDR OCTAL: up to 92MHz, DDR OCTAL: up to 85MHz
#define TEST_READ_REG_LC \
  CY_SMIF_SEMP_REG_LATENCY1  // SDR SPI: up to 133MHz, SDR OCTAL: up to 133MHz, DDR OCTAL: up to
                             // 66MHz
#define TEST_ADDR_LEN CY_TRX_ADDR_4BYTE

/******************************************************/

#define TEST_PROGRAM_SECTOR (0x00123400ul)

#define DEVICE_PROGRAM_BUFFER_SIZE (0x100)     // 256B
#define DEVICE_SECTOR_ERASE_SIZE (0x00040000)  // 256KB

typedef struct {
  volatile stc_GPIO_PRT_t* port;
  uint8_t pin;
  en_hsiom_sel_t hsiom;
  uint32_t driveMode;
} cy_stc_smif_port_t;

cy_stc_smif_port_t smifPortCfg[] = {
    {CY_SMIF_CLK_PORT, CY_SMIF_CLK_PIN, CY_SMIF_CLK_PIN_MUX, CY_GPIO_DM_STRONG},
    {CY_SMIF_CLK_INV_PORT, CY_SMIF_CLK_INV_PIN, CY_SMIF_CLK_INV_PIN_MUX, CY_GPIO_DM_STRONG},
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

static void SmifPortInit(cy_stc_smif_port_t cfg[], uint8_t size) {
  cy_stc_gpio_pin_config_t pinCfg = {0};
  for (uint32_t i = 0; i < size; i++) {
    pinCfg.driveMode = cfg[i].driveMode;
    pinCfg.hsiom = cfg[i].hsiom;
    Cy_GPIO_Pin_Init(cfg[i].port, cfg[i].pin, &pinCfg);
  }
}

cy_stc_smif_context_t smifContext;

cy_stc_smif_config_t smifConfig = {
    .txClk = CY_SMIF_INV_FOR_DDR,
    .rxClk = CY_SMIF_INV_OUTPUT_CLK,  // Note
    .dlpAuto = CY_SMIF_DLP_UPDATE_MANUAL,
    .capDelay = CY_SMIF_CAPTURE_DELAY_0_CYCLE,
    .delaySel = CY_SMIF_1_SEN_SEL_PER_TAP,
    .deselectDelay = CY_SMIF_MIN_DESELECT_1_CLK,
    .setupDelay = CY_SMIF_SETUP_0_CLK_PULUS_MIN,
    .holdDelay = CY_SMIF_HOLD_0_CLK_PULUS_MIN,
    .mode = CY_SMIF_NORMAL,  // MMIO mode
    .blockEvent = CY_SMIF_BUS_ERROR,
};

cy_stc_device_config_t smifDev0Cfg = {
    .xipReadCmdId = CY_SMIF_SEMP_RDID_1S1S1S_4ADR,
    .xipReadMode = 0x00,  // Do not care
    .writeEn = false,
    .xipWriteCmdId = CY_SMIF_SEMP_WTID_1S1S1S_4ADR,
    .xipWriteMode = 0u,  // Do not care
    .mergeEnable = true,
    .mergeTimeout = CY_SMIF_MER_TIMEOUT_1_CYCLE,
    .totalTimeoutEnable = true,
    .totalTimeout = 1000u,
    .addr = 0,  // will be updated in the application
    .size = CY_SMIF_DEVICE_64M_BYTE,
    .rdLatencyCode = TEST_READ_LC,
    .wtLatencyCode = TEST_WRITE_LC,
};

static bool WaitDeviceBecomesReady(cy_en_smif_slave_select_t slave,
                                   cy_en_smif_semp_reg_latency_code_t regLc,
                                   cy_en_smif_trx_type_t transMode);
static void SetModeWithBusyCheck(volatile stc_SMIF_t* base, cy_en_smif_mode_t mode);
static void WriteRegisterSequence(cy_en_smif_slave_select_t slave, cy_en_smif_semp_reg_addr_t addr,
                                  uint8_t value, cy_en_smif_trx_addr_len_t addrLen,
                                  cy_en_smif_semp_reg_latency_code_t regLc,
                                  cy_en_smif_trx_type_t transMode);
static void DetectVolatileRegLantency(cy_en_smif_slave_select_t slave,
                                      cy_en_smif_semp_reg_latency_code_t* detectRegLatency);
static void EnterSPIMode(volatile stc_SMIF_DEVICE_t* device);

cy_stc_ex_dev_context_t smifDevice0Context;

static void SetModeWithBusyCheck(volatile stc_SMIF_t* base, cy_en_smif_mode_t mode) {
  cy_en_smif_status_t status;
  do {
    status = Cy_SMIF_SetMode(base, mode);
  } while (status != CY_SMIF_SUCCESS);
}

// return 1, when one of selected device return error during erasing.
// return 0, when erasing completed without error.
static bool WaitDeviceBecomesReady(cy_en_smif_slave_select_t slave,
                                   cy_en_smif_semp_reg_latency_code_t regLc,
                                   cy_en_smif_trx_type_t transMode) {
  while (1) {
    un_cy_smif_semp_STR1_t status1;
#if 0
		Cy_SMIF_SEMP_ReadAnyVolatileRegister(SMIF_USED,
								 slave,
								 &status1.u8,
								 CY_TRX_ADDR_StatusRegister1_V,
								 regLc,
								 TEST_ADDR_LEN,
								 transMode,
								 &smifContext);
#else
    Cy_SMIF_SEMP_ReadStatusRegister1(SMIF_USED, slave, &status1.u8, regLc, transMode, &smifContext);
#endif
    // After transfer from Regacy SPI to OCTAL(SDR/DDR). RDYBSY may be also "0".
    if (status1.field.u1ERSERR == 1) {
      return 1;
    }

    if (status1.field.u1PRGERR == 1) {
      return 1;
    }

    if (status1.field.u1RDYBSY == 0) {
      break;
    }
  }

  return 0;
}

static void WriteRegisterSequence(cy_en_smif_slave_select_t slave, cy_en_smif_semp_reg_addr_t addr,
                                  uint8_t value, cy_en_smif_trx_addr_len_t addrLen,
                                  cy_en_smif_semp_reg_latency_code_t regLc,
                                  cy_en_smif_trx_type_t transMode) {
  Cy_SMIF_SEMP_WriteEnable(SMIF_USED, slave, transMode, &smifContext);
  Cy_SMIF_SEMP_WriteAnyRegister(SMIF_USED, slave, value, addr, addrLen, transMode, &smifContext);
  WaitDeviceBecomesReady(slave, regLc, transMode);
}

// This function has a side effect that this function will set address length to 4 byte anyway.
static void DetectVolatileRegLantency(cy_en_smif_slave_select_t slave,
                                      cy_en_smif_semp_reg_latency_code_t* detectRegLatency) {
  cy_stc_smif_semp_id_t readId;
  Cy_SMIF_SEMP_ReadId(SMIF_USED, slave, &readId, CY_SMIF_SEMP_REG_LATENCY0,
                      CY_SPI_TRANSACTION_1S1S1S, &smifContext);
  if (readId.manufacturerId == 0x34) {
    *detectRegLatency =
        CY_SMIF_SEMP_REG_LATENCY0;  // or CY_SMIF_SEMP_REG_LATENCY1 (will decide later)
  } else if (readId.manufacturerId == 0x1A) {
    *detectRegLatency = CY_SMIF_SEMP_REG_LATENCY2;
  } else if (readId.manufacturerId == 0x0D) {
    *detectRegLatency = CY_SMIF_SEMP_REG_LATENCY3;
  } else {
    CY_ASSERT(false);
  }

  // At here, we don't know the device setting of address length
  // then try both 4 byte address and 3 byte address anyway!!
  un_cy_smif_semp_CFR2_t presetConfigReg2_0 = {0};

  presetConfigReg2_0.field.u4MEMLAT = CY_SMIF_SEMP_RD_LATENCY0;
  presetConfigReg2_0.field.u1ADRBYT = CY_TRX_ADDR_4BYTE;

  WriteRegisterSequence(CY_SMIF_SLAVE_SELECT_0, CY_SEMP_REG_ADDR_CFR2_V, presetConfigReg2_0.u8,
                        CY_TRX_ADDR_4BYTE, *detectRegLatency, CY_SPI_TRANSACTION_1S1S1S);

  WriteRegisterSequence(CY_SMIF_SLAVE_SELECT_0, CY_SEMP_REG_ADDR_CFR2_V, presetConfigReg2_0.u8,
                        CY_TRX_ADDR_3BYTE, *detectRegLatency, CY_SPI_TRANSACTION_1S1S1S);

  // Read back configuration register 2
  if (*detectRegLatency == CY_SMIF_SEMP_REG_LATENCY0) {
    un_cy_smif_semp_CFR2_t monitorConfigReg2_0 = {0};
    Cy_SMIF_SEMP_ReadAnyVolatileRegister(
        SMIF_USED, slave, &monitorConfigReg2_0.u8, CY_SEMP_REG_ADDR_CFR2_V,
        CY_SMIF_SEMP_REG_LATENCY0, CY_TRX_ADDR_4BYTE, CY_SPI_TRANSACTION_1S1S1S, &smifContext);
    if (monitorConfigReg2_0.u8 == presetConfigReg2_0.u8) {
      *detectRegLatency = CY_SMIF_SEMP_REG_LATENCY0;
      return;
    }

    Cy_SMIF_SEMP_ReadAnyVolatileRegister(
        SMIF_USED, slave, &monitorConfigReg2_0.u8, CY_SEMP_REG_ADDR_CFR2_V,
        CY_SMIF_SEMP_REG_LATENCY1, CY_TRX_ADDR_4BYTE, CY_SPI_TRANSACTION_1S1S1S, &smifContext);
    if (monitorConfigReg2_0.u8 == presetConfigReg2_0.u8) {
      *detectRegLatency = CY_SMIF_SEMP_REG_LATENCY1;
    } else {
      CY_ASSERT(false);
    }
  }
}

cy_stc_smif_config_t const smifConfigHb = {
    .txClk = CY_SMIF_INV_FOR_DDR,
    .rxClk = CY_SMIF_INV_RWDS,
    .dlpAuto = CY_SMIF_DLP_UPDATE_MANUAL,
    .capDelay = CY_SMIF_CAPTURE_DELAY_0_CYCLE,
    .delaySel = CY_SMIF_1_SEN_SEL_PER_TAP,
    .deselectDelay = CY_SMIF_MIN_DESELECT_1_CLK,
    .setupDelay = CY_SMIF_SETUP_0_CLK_PULUS_MIN,
    .holdDelay = CY_SMIF_HOLD_0_CLK_PULUS_MIN,
    .mode = CY_SMIF_MEMORY,  // XIP mode
    .blockEvent = CY_SMIF_BUS_ERROR,
};

cy_stc_device_hb_config_t smifDevHBFlashCfg = {
    .xipReadCmd = CY_SMIF_HB_READ_CONTINUOUS_BURST,
    .xipWriteCmd = CY_SMIF_HB_WRITE_CONTINUOUS_BURST,
    .mergeEnable = true,
    .mergeTimeout = CY_SMIF_MER_TIMEOUT_1_CYCLE,
    .totalTimeoutEnable = true,
    .totalTimeout = 1000u,
    .addr = 0,  // will be updated in the application
    .size = CY_SMIF_DEVICE_64M_BYTE,
    .lc_hb = CY_SMIF_HB_LC5,
    .hbDevType = CY_SMIF_HB_FLASH,
};

static void EnterSPIMode(volatile stc_SMIF_DEVICE_t* device) {
  CY_SMIF_FLASHDATA* pHyperFlashBaseAddr = (CY_SMIF_FLASHDATA*)(CY_SMIF_GetXIP_Address(SMIF_USED));

  /* 1. Setting for SMIF 0 */
  Cy_SMIF_Init(SMIF_USED, &smifConfigHb, 1000, &smifContext);
  Cy_SMIF_Set_DelayTapSel(SMIF_USED, (CY_SMIF_GetDelayTapsNumber(SMIF_USED) - 1));
  Cy_SMIF_Enable(SMIF_USED, &smifContext);
  smifDevHBFlashCfg.addr = CY_SMIF_GetXIP_Address(SMIF_USED);

  /* 1. Setting for SMIF_USED Device 0 */
  Cy_SMIF_InitDeviceHyperBus(device, &smifDevHBFlashCfg);

  Cy_SMIF_CacheDisable(
      SMIF_USED,
      CY_SMIF_CACHE_BOTH);  // this is required when checking status register of external device

  CY_SMIF_HbFlash_EnterSPIModeCmd(pHyperFlashBaseAddr);
}

#include <string.h>

__attribute__((used)) int Init(unsigned long adr, unsigned long clk, unsigned long fnc) {
  SystemInit();

  memset(g_sempReadLatencyCodeToDummyCycle, 0, sizeof(g_sempReadLatencyCodeToDummyCycle));
  g_sempReadLatencyCodeToDummyCycle[0] = g_sempLatTblOtherThanOctalRead;
  g_sempReadLatencyCodeToDummyCycle[1] = g_sempLatTblOctalRead;

  memset(g_sempWriteLatencyCodeToDummyCycle, 0, sizeof(g_sempWriteLatencyCodeToDummyCycle));
  g_sempWriteLatencyCodeToDummyCycle[0] = g_latancyTableOfWrite;

  memset(cmdLatTbls, 0, sizeof(cmdLatTbls));
  cmdLatTbls[0] = NULL;
  cmdLatTbls[1] = g_sempLatTblRegType1;
  cmdLatTbls[2] = g_sempLatTblRegType2;
  cmdLatTbls[3] = g_sempLatTblRegType3;
  cmdLatTbls[4] = g_sempLatTblOtherThanOctalRead;
  cmdLatTbls[5] = g_sempLatTblOctalRead;

  Cy_SysClk_HfClkEnable(SMIF_HF_CLOCK);
  Cy_SysClk_HfClockSetDivider(SMIF_HF_CLOCK, CY_SYSCLK_HFCLK_DIVIDE_BY_4);

  // Please modify according to your HW condition.
  ChangePLLFrequency(64000000);  // SMIF out clock will be 32,000,000 //YOTS: for initial test

  SmifPortInit(smifPortCfg, SIZE_OF_PORT);

#if 0  // If your device is hyper bus mode by default, please enable this code.
       // Assumed the device is in Hyper bus mode by default
	EnterSPIMode(SMIF_DEVICE0);
#endif

  CY_ASSERT(Cy_SMIF_InitExMemContext(CY_SMIF_SEMP, &smifDevice0Context) == CY_SMIF_SUCCESS);

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
  Cy_SMIF_DeviceSetDataSelect(SMIF_DEVICE1, CY_SMIF_DATA_SEL0);
  Cy_SMIF_DeviceWriteEnable(SMIF_DEVICE1);

  /********************/
  /* 3. Enable SMIF 0 */
  /********************/
  Cy_SMIF_Enable(SMIF_USED, &smifContext);

  /*********************************************************/
  /********* Read Status and Configuration registers *******/
  /*********************************************************/

  cy_en_smif_semp_reg_latency_code_t initialRegLatency;
  DetectVolatileRegLantency(CY_SMIF_SLAVE_SELECT_0, &initialRegLatency);

  // Setting Configuration Register 2
  un_cy_smif_semp_CFR2_t writeConfigReg2_0 = {0};
  writeConfigReg2_0.field.u4MEMLAT = TEST_READ_LC;
  writeConfigReg2_0.field.u1ADRBYT = TEST_ADDR_LEN;
  WriteRegisterSequence(CY_SMIF_SLAVE_SELECT_0, CY_SEMP_REG_ADDR_CFR2_V, writeConfigReg2_0.u8,
                        CY_TRX_ADDR_4BYTE, initialRegLatency, CY_SPI_TRANSACTION_1S1S1S);

  un_cy_smif_semp_CFR2_t readConfigReg2_0 = {0};
  Cy_SMIF_SEMP_ReadAnyVolatileRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, &readConfigReg2_0.u8,
                                       CY_SEMP_REG_ADDR_CFR2_V, initialRegLatency, TEST_ADDR_LEN,
                                       CY_SPI_TRANSACTION_1S1S1S, &smifContext);
  CY_ASSERT(writeConfigReg2_0.field.u4MEMLAT == readConfigReg2_0.field.u4MEMLAT);
  CY_ASSERT(writeConfigReg2_0.field.u1ADRBYT == readConfigReg2_0.field.u1ADRBYT);

  // Setting Configuration Register 3
  un_cy_smif_semp_CFR3_t writeConfigReg3_0 = {0};
  writeConfigReg3_0.field.u2VRGLAT = TEST_READ_REG_LC;
  WriteRegisterSequence(CY_SMIF_SLAVE_SELECT_0, CY_SEMP_REG_ADDR_CFR3_V, writeConfigReg3_0.u8,
                        TEST_ADDR_LEN, initialRegLatency, CY_SPI_TRANSACTION_1S1S1S);

  un_cy_smif_semp_CFR3_t readConfigReg3_0 = {0};
  Cy_SMIF_SEMP_ReadAnyVolatileRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, &readConfigReg3_0.u8,
                                       CY_SEMP_REG_ADDR_CFR3_V, TEST_READ_REG_LC, TEST_ADDR_LEN,
                                       CY_SPI_TRANSACTION_1S1S1S, &smifContext);
  CY_ASSERT(writeConfigReg3_0.field.u2VRGLAT == readConfigReg3_0.field.u2VRGLAT);

  // Setting Configuration Register 4
  un_cy_smif_semp_CFR4_t previousConfigReg4_0 = {0};
  Cy_SMIF_SEMP_ReadAnyVolatileRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, &previousConfigReg4_0.u8,
                                       CY_SEMP_REG_ADDR_CFR4_V, TEST_READ_REG_LC, TEST_ADDR_LEN,
                                       CY_SPI_TRANSACTION_1S1S1S, &smifContext);

  un_cy_smif_semp_CFR4_t writeConfigReg4_0 = previousConfigReg4_0;
  writeConfigReg4_0.field.u1RBSTWP = 0;  // Read Wrapped Burst disable
  WriteRegisterSequence(CY_SMIF_SLAVE_SELECT_0, CY_SEMP_REG_ADDR_CFR4_V, writeConfigReg4_0.u8,
                        TEST_ADDR_LEN, TEST_READ_REG_LC, CY_SPI_TRANSACTION_1S1S1S);

  un_cy_smif_semp_CFR4_t readConfigReg4_0 = {0};
  Cy_SMIF_SEMP_ReadAnyVolatileRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, &readConfigReg4_0.u8,
                                       CY_SEMP_REG_ADDR_CFR4_V, TEST_READ_REG_LC, TEST_ADDR_LEN,
                                       CY_SPI_TRANSACTION_1S1S1S, &smifContext);
  CY_ASSERT(writeConfigReg4_0.field.u1RBSTWP == readConfigReg4_0.field.u1RBSTWP);

  uint16_t readSPICommand;
  uint16_t readFastSPICommand;
  if (TEST_ADDR_LEN == CY_TRX_ADDR_4BYTE) {
    readSPICommand = CY_SMIF_SEMP_RDID_1S1S1S_4ADR;
    readFastSPICommand = CY_SMIF_SEMP_RDID_1S1S1S_FAST_4ADR;
    smifDev0Cfg.size = CY_SMIF_DEVICE_64M_BYTE;
  } else {
    readSPICommand = CY_SMIF_SEMP_RDID_1S1S1S_3ADR;
    readFastSPICommand = CY_SMIF_SEMP_RDID_1S1S1S_FAST_4ADR;
    smifDev0Cfg.size = CY_SMIF_DEVICE_8M_BYTE;
  }

  smifDev0Cfg.addr = CY_SMIF_GetXIP_Address(SMIF_USED);
  smifDev0Cfg.xipReadCmdId = readSPICommand;
  CY_ASSERT(Cy_SMIF_InitXIPModeForExMem(SMIF_DEVICE0, CY_SMIF_DEV_SINGLE_BIT_0To1, &smifDev0Cfg,
                                        &smifDevice0Context) == CY_SMIF_SUCCESS);
  SetModeWithBusyCheck(SMIF_USED, CY_SMIF_MEMORY);

  return 0;
}

__attribute__((used)) int UnInit(unsigned long fnc) {
  (void)fnc;
  return (0);
}

__attribute__((used)) int EraseSector(unsigned long adr) {
  if (adr < CY_SMIF_GetXIP_Address(SMIF_USED)) return __LINE__;
  adr -= CY_SMIF_GetXIP_Address(SMIF_USED);

  SetModeWithBusyCheck(SMIF_USED, CY_SMIF_NORMAL);
  Cy_SMIF_SEMP_WriteEnable(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, CY_SPI_TRANSACTION_1S1S1S,
                           &smifContext);
  Cy_SMIF_SEMP_Erase_256KB_Sector(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, adr, CY_SPI_TRANSACTION_1S1S1S,
                                  &smifContext);
  CY_ASSERT(WaitDeviceBecomesReady(CY_SMIF_SLAVE_SELECT_0, TEST_READ_REG_LC,
                                   CY_SPI_TRANSACTION_1S1S1S) == 0);
  SetModeWithBusyCheck(SMIF_USED, CY_SMIF_MEMORY);

  return (0);
}

__attribute__((used)) int EraseChip(void) {
  SetModeWithBusyCheck(SMIF_USED, CY_SMIF_NORMAL);
  Cy_SMIF_SEMP_WriteEnable(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, CY_SPI_TRANSACTION_1S1S1S,
                           &smifContext);
  Cy_SMIF_SEMP_EraseChip(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, CY_SPI_TRANSACTION_1S1S1S,
                         &smifContext);
  CY_ASSERT(WaitDeviceBecomesReady(CY_SMIF_SLAVE_SELECT_0, TEST_READ_REG_LC,
                                   CY_SPI_TRANSACTION_1S1S1S) == 0);
  SetModeWithBusyCheck(SMIF_USED, CY_SMIF_MEMORY);

  return (0);
}

__attribute__((used)) int ProgramPage(unsigned long adr, unsigned long sz,
                                      const unsigned char* buf) {
  if (sz != 0x100) return __LINE__;
  if (adr < CY_SMIF_GetXIP_Address(SMIF_USED)) return __LINE__;
  adr -= CY_SMIF_GetXIP_Address(SMIF_USED);

  SetModeWithBusyCheck(SMIF_USED, CY_SMIF_NORMAL);

  // Write Enable
  Cy_SMIF_SEMP_WriteEnable(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, CY_SPI_TRANSACTION_1S1S1S,
                           &smifContext);
  // Write test data
  Cy_SMIF_MMIO_Program_ExMem(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, CY_SMIF_SEMP_WTID_1S1S1S_4ADR, adr,
                             sz, buf, CY_SMIF_BLOCKING, TEST_WRITE_LC, 0, /* mode value */
                             &smifDevice0Context, &smifContext);
  CY_ASSERT(WaitDeviceBecomesReady(CY_SMIF_SLAVE_SELECT_0, TEST_READ_REG_LC,
                                   CY_SPI_TRANSACTION_1S1S1S) == 0);

  SetModeWithBusyCheck(SMIF_USED, CY_SMIF_MEMORY);

  return (0);
}

/* [] END OF FILE */
