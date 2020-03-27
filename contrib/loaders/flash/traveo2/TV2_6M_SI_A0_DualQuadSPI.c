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
#include "sdl/tviic2d6m/src/mw/smif_mem/cy_smif_s25fs.c"
#include "sdl/tviic2d6m/src/system/rev_a/system_tviic2d6m_cm0plus.c"

/***** User Modifiable definitions *****/
#define TEST_WRITE_LC CY_SMIF_S25FS_WT_LATENCY0
#define TEST_READ_LC CY_SMIF_S25FS_RD_LATENCY2
#define TEST_ADDR_LEN CY_TRX_ADDR_4BYTE
/**************************************/

#define DATA_WIDTH_1_OR_2_BITS (0)
#define DATA_WIDTH_4_BITS (1)
#define TRX_DATA_WIDTH (CY_SPI_TRANSACTION_4S4S4S)
#define TEST_SLAVE (cy_en_smif_slave_select_t)(CY_SMIF_SLAVE_SELECT_0 | CY_SMIF_SLAVE_SELECT_1)

typedef struct {
  volatile stc_GPIO_PRT_t* port;
  uint8_t pin;
  en_hsiom_sel_t hsiom;
  uint32_t driveMode;
} cy_stc_smif_port_t;

static const cy_stc_smif_port_t smifPortCfg[] = {
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

static void SmifPortInit(const cy_stc_smif_port_t cfg[], uint8_t size) {
  cy_stc_gpio_pin_config_t pinCfg = {0};
  for (uint32_t i = 0; i < size; i++) {
    pinCfg.driveMode = cfg[i].driveMode;
    pinCfg.hsiom = cfg[i].hsiom;
    Cy_GPIO_Pin_Init(cfg[i].port, cfg[i].pin, &pinCfg);
  }
}

static cy_stc_smif_context_t smifContext;

static const cy_stc_smif_config_t smifConfig = {
    .txClk = CY_SMIF_INV_FOR_DDR,
    .rxClk = CY_SMIF_INV_OUTPUT_CLK,  // Note
    .dlpAuto = CY_SMIF_DLP_UPDATE_MANUAL,
    .capDelay = CY_SMIF_CAPTURE_DELAY_0_CYCLE,
    .delaySel = CY_SMIF_1_SEN_SEL_PER_TAP,
    .deselectDelay = CY_SMIF_MIN_DESELECT_1_CLK,
    .setupDelay = CY_SMIF_SETUP_3_CLK_PULUS_MIN,
    .holdDelay = CY_SMIF_HOLD_3_CLK_PULUS_MIN,
    .mode = CY_SMIF_NORMAL,  // MMIO mode
    .blockEvent = CY_SMIF_BUS_ERROR,
};

// will be updated in the application
static cy_stc_device_config_t smifDev0Cfg = {
    .xipReadCmdId = CY_SMIF_S25FS_RDID_1S1S1S_4ADR,
    .xipReadMode = 0x00,
    .writeEn = false,
    .xipWriteCmdId = CY_SMIF_S25FS_WTID_1S1S1S_4ADR,
    .xipWriteMode = 0u,
    .mergeEnable = true,
    .mergeTimeout = CY_SMIF_MER_TIMEOUT_256_CYCLE,
    .totalTimeoutEnable = false,
    .totalTimeout = 1000u,
    .addr = 0,
    .size = CY_SMIF_DEVICE_64M_BYTE,
    .rdLatencyCode = TEST_READ_LC,
    .wtLatencyCode = TEST_WRITE_LC,
};

static bool WaitDeviceBecomesReady(cy_en_smif_slave_select_t slave,
                                   cy_en_smif_trx_type_t transMode);
static void SetModeWithBusyCheck(volatile stc_SMIF_t* base, cy_en_smif_mode_t mode);
static void WriteRegisterSequence(cy_en_smif_slave_select_t slave, cy_en_smif_s25fs_reg_addr_t addr,
                                  uint8_t value, cy_en_smif_trx_addr_len_t addrLen,
                                  cy_en_smif_trx_type_t transMode);
static void ReadbackMMIO(uint16_t rdCmdId, uint32_t size);
static void ReadbackXIP(uint16_t rdCmdId, uint32_t size);

static cy_stc_ex_dev_context_t smifDevice0Context;

static void ReadbackContinuousMode(uint16_t rdDummyCmdId, uint16_t rdCmdId, uint32_t size);

static bool WaitDeviceBecomesReady(cy_en_smif_slave_select_t slave,
                                   cy_en_smif_trx_type_t transMode) {
  for (uint8_t i_slaveNum = 0; i_slaveNum < CY_SMIF_GetDeviceNumber(SMIF_USED); i_slaveNum++) {
    cy_en_smif_slave_select_t slaveToBeChecked =
        (cy_en_smif_slave_select_t)((uint8_t)slave & (0x01 << i_slaveNum));
    if ((uint8_t)slaveToBeChecked == 0u) {
      // not selected slave
      continue;
    }

    // only selected slave will reach hare.
    while (1) {
      un_cy_smif_s25fs_STR1_t status1;
      Cy_SMIF_S25FS_ReadStatusRegister1(SMIF_USED, slaveToBeChecked, &status1.u8,
                                        CY_SMIF_S25FS_REG_LATENCY0,  // fixed 0 latency for S25SL
                                        transMode, &smifContext);
      // After transfer from Regacy SPI to OCTAL(SDR/DDR). RDYBSY may be also "0".
      if (status1.field.u1E_ERR == 1) {
        return 1;
      }
      if (status1.field.u1P_ERR == 1) {
        return 1;
      }
      if (status1.field.u1WIP == 0) {
        break;
      }
    }
  }

  return 0;
}

static void WriteRegisterSequence(cy_en_smif_slave_select_t slave, cy_en_smif_s25fs_reg_addr_t addr,
                                  uint8_t value, cy_en_smif_trx_addr_len_t addrLen,
                                  cy_en_smif_trx_type_t transMode) {
  Cy_SMIF_S25FS_WriteEnable(SMIF_USED, slave, transMode, &smifContext);
  Cy_SMIF_S25FS_WriteAnyRegister(SMIF_USED, slave, value, addr, addrLen, transMode, &smifContext);
  CY_ASSERT(WaitDeviceBecomesReady(slave, transMode) == 0);
}

static uint16_t sdrQuadCommand0;
static uint16_t ddrQuadCommand0;
static uint16_t sdrQuadCmdCont;
static uint16_t ddrQuadCmdCont;
static uint16_t writeQuadCommand;

#include <string.h>

__attribute__((used)) int Init(unsigned long adr, unsigned long clk, unsigned long fnc) {
  SystemInit();

  g_cmdLatTbls_s25fs[0] = 0;
  g_cmdLatTbls_s25fs[1] = g_s25fsLatTblOtherThanOctalRead;

  memset(g_s25fsReadLatencyCodeToDummyCycle, 0, sizeof(g_s25fsReadLatencyCodeToDummyCycle));
  g_s25fsReadLatencyCodeToDummyCycle[0] = g_s25fsLatTblOtherThanOctalRead;

  memset(g_s25fsWriteLatencyCodeToDummyCycle, 0, sizeof(g_s25fsWriteLatencyCodeToDummyCycle));
  g_s25fsWriteLatencyCodeToDummyCycle[0] = g_latancyTableOfWrite_s25fs;

  Cy_SysClk_HfClkEnable(SMIF_HF_CLOCK);
  Cy_SysClk_HfClockSetDivider(SMIF_HF_CLOCK, CY_SYSCLK_HFCLK_DIVIDE_BY_4);

  // Please modify according to your HW condition.
  ChangePLLFrequency(64000000);  // SMIF out clock will be 32,000,000 //YOTS: for initial test

  SmifPortInit(smifPortCfg, SIZE_OF_PORT);

  CY_ASSERT(Cy_SMIF_InitExMemContext(CY_SMIF_S25FS, &smifDevice0Context) == CY_SMIF_SUCCESS);

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

  /********* Issue Software Reset In legacy SPI mode ******/
  Cy_SMIF_S25FS_SoftwareResetEnable(SMIF_USED, TEST_SLAVE, CY_SPI_TRANSACTION_1S1S1S, &smifContext);
  Cy_SMIF_S25FS_SoftwareReset(SMIF_USED, TEST_SLAVE, CY_SPI_TRANSACTION_1S1S1S, &smifContext);
  WaitDeviceBecomesReady(TEST_SLAVE, CY_SPI_TRANSACTION_1S1S1S);

  /********* Issue Software Reset In legacy Quad mode ******/
  Cy_SMIF_S25FS_SoftwareResetEnable(SMIF_USED, TEST_SLAVE, CY_SPI_TRANSACTION_4S4S4S, &smifContext);
  Cy_SMIF_S25FS_SoftwareReset(SMIF_USED, TEST_SLAVE, CY_SPI_TRANSACTION_4S4S4S, &smifContext);
  WaitDeviceBecomesReady(TEST_SLAVE, CY_SPI_TRANSACTION_4S4S4S);

  /*********************************************************/
  /********* Write Status and Configuration registers ******/
  /*********************************************************/

  // Write Configuration register 1
  un_cy_smif_s25fs_CFR1_t writeConfigReg1 = {0};
  writeConfigReg1.field.u1QUAD = DATA_WIDTH_1_OR_2_BITS;

  WriteRegisterSequence(TEST_SLAVE, CY_S25FS_REG_ADDR_CFR1_V, writeConfigReg1.u8, CY_TRX_ADDR_3BYTE,
                        CY_SPI_TRANSACTION_1S1S1S);

  un_cy_smif_s25fs_CFR1_t readConfigReg1_0 = {0};
  Cy_SMIF_S25FS_ReadAnyRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, &readConfigReg1_0.u8,
                                CY_S25FS_REG_ADDR_CFR1_V, CY_SMIF_S25FS_RD_LATENCY0,
                                CY_TRX_ADDR_3BYTE, CY_SPI_TRANSACTION_1S1S1S, &smifContext);
  CY_ASSERT(writeConfigReg1.field.u1QUAD == readConfigReg1_0.field.u1QUAD);

  un_cy_smif_s25fs_CFR1_t readConfigReg1_1 = {0};
  Cy_SMIF_S25FS_ReadAnyRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_1, &readConfigReg1_1.u8,
                                CY_S25FS_REG_ADDR_CFR1_V, CY_SMIF_S25FS_RD_LATENCY0,
                                CY_TRX_ADDR_3BYTE, CY_SPI_TRANSACTION_1S1S1S, &smifContext);
  CY_ASSERT(writeConfigReg1.field.u1QUAD == readConfigReg1_1.field.u1QUAD);

  // Write Configuration register 2
  un_cy_smif_s25fs_CFR2_t writeConfigReg2 = {0};
  writeConfigReg2.field.u4RL = TEST_READ_LC;
  writeConfigReg2.field.u1QA = DATA_WIDTH_4_BITS;
  writeConfigReg2.field.u1AL = TEST_ADDR_LEN;

  WriteRegisterSequence(TEST_SLAVE, CY_S25FS_REG_ADDR_CFR2_V, writeConfigReg2.u8, CY_TRX_ADDR_3BYTE,
                        CY_SPI_TRANSACTION_1S1S1S);

  un_cy_smif_s25fs_CFR2_t readConfigReg2_0 = {0};
  Cy_SMIF_S25FS_ReadAnyRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, &readConfigReg2_0.u8,
                                CY_S25FS_REG_ADDR_CFR2_V, TEST_READ_LC, TEST_ADDR_LEN,
                                TRX_DATA_WIDTH, &smifContext);
  CY_ASSERT(writeConfigReg2.field.u4RL == readConfigReg2_0.field.u4RL);
  CY_ASSERT(writeConfigReg2.field.u1QA == readConfigReg2_0.field.u1QA);
  CY_ASSERT(writeConfigReg2.field.u1AL == readConfigReg2_0.field.u1AL);

  un_cy_smif_s25fs_CFR2_t readConfigReg2_1 = {0};
  Cy_SMIF_S25FS_ReadAnyRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_1, &readConfigReg2_1.u8,
                                CY_S25FS_REG_ADDR_CFR2_V, TEST_READ_LC, TEST_ADDR_LEN,
                                TRX_DATA_WIDTH, &smifContext);
  CY_ASSERT(writeConfigReg2.field.u4RL == readConfigReg2_1.field.u4RL);
  CY_ASSERT(writeConfigReg2.field.u1QA == readConfigReg2_1.field.u1QA);
  CY_ASSERT(writeConfigReg2.field.u1AL == readConfigReg2_1.field.u1AL);

  // Write Configuration register 3
  un_cy_smif_s25fs_CFR3_t writeConfigReg3 = {0};
  writeConfigReg3.field.u1D8h = 1;  // 256Kbyte uniformed sector
  writeConfigReg3.field.u120h = 1;
  WriteRegisterSequence(TEST_SLAVE, CY_S25FS_REG_ADDR_CFR3_V, writeConfigReg3.u8, TEST_ADDR_LEN,
                        TRX_DATA_WIDTH);

  un_cy_smif_s25fs_CFR3_t readConfigReg3_0 = {0};
  Cy_SMIF_S25FS_ReadAnyRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, &readConfigReg3_0.u8,
                                CY_S25FS_REG_ADDR_CFR3_V, TEST_READ_LC, TEST_ADDR_LEN,
                                TRX_DATA_WIDTH, &smifContext);
  CY_ASSERT(writeConfigReg3.field.u1D8h == readConfigReg3_0.field.u1D8h);

  un_cy_smif_s25fs_CFR3_t readConfigReg3_1 = {0};
  Cy_SMIF_S25FS_ReadAnyRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_1, &readConfigReg3_1.u8,
                                CY_S25FS_REG_ADDR_CFR3_V, TEST_READ_LC, TEST_ADDR_LEN,
                                TRX_DATA_WIDTH, &smifContext);
  CY_ASSERT(writeConfigReg3.field.u1D8h == readConfigReg3_1.field.u1D8h);

  // Write Configuration register 4
  un_cy_smif_s25fs_CFR4_t writeConfigReg4 = {0};
  writeConfigReg4.field.u1WE = 1;  // Read Wrapped Burst disable

  WriteRegisterSequence(TEST_SLAVE, CY_S25FS_REG_ADDR_CFR4_V, writeConfigReg4.u8, TEST_ADDR_LEN,
                        TRX_DATA_WIDTH);

  un_cy_smif_s25fs_CFR4_t readConfigReg4_0 = {0};
  Cy_SMIF_S25FS_ReadAnyRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, &readConfigReg4_0.u8,
                                CY_S25FS_REG_ADDR_CFR4_V, TEST_READ_LC, TEST_ADDR_LEN,
                                TRX_DATA_WIDTH, &smifContext);
  CY_ASSERT(writeConfigReg4.field.u1WE == readConfigReg4_0.field.u1WE);

  un_cy_smif_s25fs_CFR4_t readConfigReg4_1 = {0};
  Cy_SMIF_S25FS_ReadAnyRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_1, &readConfigReg4_1.u8,
                                CY_S25FS_REG_ADDR_CFR4_V, TEST_READ_LC, TEST_ADDR_LEN,
                                TRX_DATA_WIDTH, &smifContext);
  CY_ASSERT(writeConfigReg4.field.u1WE == readConfigReg4_1.field.u1WE);

  /*********************************************************/
  /*******          Write/Read DLP register           ******/
  /*********************************************************/
  // just for read/write test for now
  WriteRegisterSequence(TEST_SLAVE, CY_S25FS_REG_ADDR_DLP_V, 0xAA, TEST_ADDR_LEN, TRX_DATA_WIDTH);
  uint8_t readbackDLP = 0u;
  Cy_SMIF_S25FS_ReadAnyRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_0, &readbackDLP,
                                CY_S25FS_REG_ADDR_DLP_V, TEST_READ_LC, TEST_ADDR_LEN,
                                TRX_DATA_WIDTH, &smifContext);
  CY_ASSERT(readbackDLP == 0xAA);

  readbackDLP = 0u;
  Cy_SMIF_S25FS_ReadAnyRegister(SMIF_USED, CY_SMIF_SLAVE_SELECT_1, &readbackDLP,
                                CY_S25FS_REG_ADDR_DLP_V, TEST_READ_LC, TEST_ADDR_LEN,
                                TRX_DATA_WIDTH, &smifContext);
  CY_ASSERT(readbackDLP == 0xAA);

  if (TEST_ADDR_LEN == CY_TRX_ADDR_4BYTE) {
    sdrQuadCommand0 = CY_SMIF_S25FS_RDID_4S4S4S_4ADR;
    ddrQuadCommand0 = CY_SMIF_S25FS_RDID_4D4D4D_4ADR;
    sdrQuadCmdCont = CY_SMIF_S25FS_RDID_4S4S_4ADR;
    ddrQuadCmdCont = CY_SMIF_S25FS_RDID_4D4D_4ADR;
    writeQuadCommand = CY_SMIF_S25FS_WTID_4S4S4S_4ADR;
    smifDev0Cfg.size = CY_SMIF_DEVICE_64M_BYTE;
  } else {
    sdrQuadCommand0 = CY_SMIF_S25FS_RDID_4S4S4S_3ADR;
    ddrQuadCommand0 = CY_SMIF_S25FS_RDID_4D4D4D_3ADR;
    sdrQuadCmdCont = CY_SMIF_S25FS_RDID_4S4S_3ADR;
    ddrQuadCmdCont = CY_SMIF_S25FS_RDID_4D4D_3ADR;
    writeQuadCommand = CY_SMIF_S25FS_WTID_4S4S4S_3ADR;
    smifDev0Cfg.size = CY_SMIF_DEVICE_8M_BYTE;
  }

  // Set up for XIP mode
  smifDev0Cfg.addr = CY_SMIF_GetXIP_Address(SMIF_USED);
  smifDev0Cfg.xipReadCmdId = sdrQuadCommand0;
  smifDev0Cfg.xipReadMode = Cy_SMIF_S25FS_MODE_NOT_CONTINUOUS;
  CY_ASSERT(Cy_SMIF_InitXIPModeForExMem(SMIF_DEVICE0, CY_SMIF_DEV_D_QUAD_BIT_0To3, &smifDev0Cfg,
                                        &smifDevice0Context) == CY_SMIF_SUCCESS);
  CY_ASSERT(Cy_SMIF_InitXIPModeForExMem(SMIF_DEVICE1, CY_SMIF_DEV_D_QUAD_BIT_4To7, &smifDev0Cfg,
                                        &smifDevice0Context) == CY_SMIF_SUCCESS);
  SetModeWithBusyCheck(SMIF_USED, CY_SMIF_MEMORY);

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
  if (adr < CY_SMIF_GetXIP_Address(SMIF_USED)) return __LINE__;
  adr -= CY_SMIF_GetXIP_Address(SMIF_USED);

  SetModeWithBusyCheck(SMIF_USED, CY_SMIF_NORMAL);

  if (Cy_SMIF_S25FS_WriteEnable(SMIF_USED, TEST_SLAVE, TRX_DATA_WIDTH, &smifContext))
    return __LINE__;
  if (Cy_SMIF_S25FS_Erase_256KB_Sector(SMIF_USED, TEST_SLAVE, adr >> 1, TRX_DATA_WIDTH,
                                       &smifContext))
    return __LINE__;
  if (WaitDeviceBecomesReady(TEST_SLAVE, TRX_DATA_WIDTH)) return __LINE__;
  SetModeWithBusyCheck(SMIF_USED, CY_SMIF_MEMORY);
  return (0);
}

__attribute__((used)) int EraseChip() {
  SetModeWithBusyCheck(SMIF_USED, CY_SMIF_NORMAL);
  if (Cy_SMIF_S25FS_WriteEnable(SMIF_USED, TEST_SLAVE, TRX_DATA_WIDTH, &smifContext))
    return __LINE__;
  if (Cy_SMIF_S25FS_EraseChip(SMIF_USED, TEST_SLAVE, TRX_DATA_WIDTH, &smifContext)) return __LINE__;
  if (WaitDeviceBecomesReady(TEST_SLAVE, TRX_DATA_WIDTH)) return __LINE__;
  SetModeWithBusyCheck(SMIF_USED, CY_SMIF_MEMORY);
  return (0);
}

__attribute__((used)) int ProgramPage(unsigned long adr, unsigned long sz,
                                      const unsigned char* buf) {
  if (TEST_ADDR_LEN == CY_TRX_ADDR_4BYTE) {
    sdrQuadCommand0 = CY_SMIF_S25FS_RDID_4S4S4S_4ADR;
    ddrQuadCommand0 = CY_SMIF_S25FS_RDID_4D4D4D_4ADR;
    sdrQuadCmdCont = CY_SMIF_S25FS_RDID_4S4S_4ADR;
    ddrQuadCmdCont = CY_SMIF_S25FS_RDID_4D4D_4ADR;
    writeQuadCommand = CY_SMIF_S25FS_WTID_4S4S4S_4ADR;
    smifDev0Cfg.size = CY_SMIF_DEVICE_64M_BYTE;
  } else {
    sdrQuadCommand0 = CY_SMIF_S25FS_RDID_4S4S4S_3ADR;
    ddrQuadCommand0 = CY_SMIF_S25FS_RDID_4D4D4D_3ADR;
    sdrQuadCmdCont = CY_SMIF_S25FS_RDID_4S4S_3ADR;
    ddrQuadCmdCont = CY_SMIF_S25FS_RDID_4D4D_3ADR;
    writeQuadCommand = CY_SMIF_S25FS_WTID_4S4S4S_3ADR;
    smifDev0Cfg.size = CY_SMIF_DEVICE_8M_BYTE;
  }

  if (adr < CY_SMIF_GetXIP_Address(SMIF_USED)) return __LINE__;
  adr -= CY_SMIF_GetXIP_Address(SMIF_USED);

  SetModeWithBusyCheck(SMIF_USED, CY_SMIF_NORMAL);

  Cy_SMIF_S25FS_WriteEnable(SMIF_USED, TEST_SLAVE, TRX_DATA_WIDTH, &smifContext);
  // Write test data
  Cy_SMIF_MMIO_Program_ExMem(SMIF_USED, TEST_SLAVE, writeQuadCommand, adr >> 1, sz, buf,
                             CY_SMIF_BLOCKING, TEST_WRITE_LC, Cy_SMIF_S25FS_MODE_NOT_CONTINUOUS,
                             &smifDevice0Context, &smifContext);
  CY_ASSERT(WaitDeviceBecomesReady(TEST_SLAVE, TRX_DATA_WIDTH) == 0);

  SetModeWithBusyCheck(SMIF_USED, CY_SMIF_MEMORY);
  return 0;
}

/* [] END OF FILE */
