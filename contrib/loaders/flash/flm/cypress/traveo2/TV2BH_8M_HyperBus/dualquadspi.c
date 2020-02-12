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
#include "cy_gpio.h"
#include "cy_smif_hb_flash.h"
#include "cy_sysclk.h"
#include "cy_syswdt.h"
#include "cy_smif_s25fl.h"

/*#define QUAD_BASE_ADDR_SLV0 (SMIF_SMIF_XIP_ADDR)		/ * 0x6000_0000 * /
 *#define QUAD_BASE_ADDR_SLV1 (SMIF_SMIF_XIP_ADDR + 0x02000000UL)	/ * 0x6200_0000 * / */

#define DLP_VALUE (0x34u)
#define TEST_SPI_LC CY_SMIF_SPI_LATENCY2
#define TEST_PROGRAM_SECTOR (0x01240000ul)

/*#define TEST_DQUAD_XIP_PROGRAM_ADDR (TEST_PROGRAM_SECTOR * 2ul) */
#define D_QUAD_SLAVES (cy_en_smif_slave_select_t)((uint8_t) CY_SMIF_SLAVE_SELECT_0 | \
	(uint8_t)CY_SMIF_SLAVE_SELECT_1)

/* #define DLP_SETTING_UPDATE_AUTO */

#ifdef DLP_SETTING_UPDATE_AUTO
  #define SETTING_DELAY_SEL CY_SMIF_1_NEW_SEL_PER_TAP
  #define SETTING_DLP_AUTO  CY_SMIF_DLP_UPDATE_AUTO
#else
  #define SETTING_DELAY_SEL CY_SMIF_NO_DELAY_SEL
  #define SETTING_DLP_AUTO  CY_SMIF_DLP_UPDATE_MANUAL
#endif

#define USE_QUAD_MODE 1	/* 0: not quad, 1: quad */

typedef struct {
	volatile stc_GPIO_PRT_t *port;
	uint8_t pin;
	en_hsiom_sel_t hsiom;
	uint32_t driveMode;
} cy_stc_smif_port_t;

cy_stc_smif_port_t smifPortCfg[] = {
    {GPIO_PRT24, 1u, P24_1_SMIF0_SPIHB_CLK,     CY_GPIO_DM_STRONG},
    {GPIO_PRT24, 2u, P24_2_SMIF0_SPIHB_RWDS,    CY_GPIO_DM_STRONG},
    {GPIO_PRT24, 3u, P24_3_SMIF0_SPIHB_SELECT0, CY_GPIO_DM_STRONG},
    {GPIO_PRT7,  3u, P7_3_SMIF0_SPIHB_SELECT1,  CY_GPIO_DM_STRONG},
    {GPIO_PRT25, 0u, P25_0_SMIF0_SPIHB_DATA0,   CY_GPIO_DM_STRONG},
    {GPIO_PRT25, 1u, P25_1_SMIF0_SPIHB_DATA1,   CY_GPIO_DM_STRONG},
    {GPIO_PRT25, 2u, P25_2_SMIF0_SPIHB_DATA2,   CY_GPIO_DM_STRONG},
    {GPIO_PRT25, 3u, P25_3_SMIF0_SPIHB_DATA3,   CY_GPIO_DM_STRONG},
    {GPIO_PRT8,  2u, P8_2_SMIF0_SPIHB_DATA4,    CY_GPIO_DM_STRONG},
    {GPIO_PRT11, 0u, P11_0_SMIF0_SPIHB_DATA5,   CY_GPIO_DM_STRONG},
    {GPIO_PRT11, 1u, P11_1_SMIF0_SPIHB_DATA6,   CY_GPIO_DM_STRONG},
    {GPIO_PRT11, 2u, P11_2_SMIF0_SPIHB_DATA7,   CY_GPIO_DM_STRONG},
};
#define SIZE_OF_PORT (sizeof(smifPortCfg)/sizeof(cy_stc_smif_port_t))

static void SmifPortInit(cy_stc_smif_port_t cfg[], uint8_t size)
{
	cy_stc_gpio_pin_config_t pinCfg = {0};
	for (uint32_t i = 0; i < size; i++) {
		pinCfg.driveMode = cfg[i].driveMode;
		pinCfg.hsiom     = cfg[i].hsiom;
		Cy_GPIO_Pin_Init(cfg[i].port, cfg[i].pin, &pinCfg);
	}
}

/* any valid address */
#define TEST_ADDRESS (0x01240000ul)

static void SetModeWithBusyCheck(volatile stc_SMIF_t *base, cy_en_smif_mode_t mode)
{
	cy_en_smif_status_t status;
	do
	{
		status = Cy_SMIF_SetMode(base, mode);
	} while (status != CY_SMIF_SUCCESS);
}

cy_stc_smif_context_t smifContext;

cy_stc_smif_config_t const smifConfig = {
	.txClk         = CY_SMIF_INV_FOR_DDR,
	.rxClk         = CY_SMIF_INV_OUTPUT_CLK,/* Note */
	.delaySel      = SETTING_DELAY_SEL,
	.dlpAuto       = SETTING_DLP_AUTO,
	.capDelay      = CY_SMIF_CAPTURE_DELAY_0_CYCLE,
	.deselectDelay = CY_SMIF_MIN_DESELECT_1_CLK,
	.setupDelay    = CY_SMIF_SETUP_0_CLK_PULUS_MIN,
	.holdDelay     = CY_SMIF_HOLD_0_CLK_PULUS_MIN,
	.mode          = CY_SMIF_NORMAL,/* MMIO mode */
	.blockEvent    = CY_SMIF_BUS_ERROR,
};

cy_stc_device_s25fl_config_t smifDevDualQuadCfg = {
	.xipReadCmd         = CY_SMIF_4QOR,
	.xipReadMode        = CY_SMIF_XIP_RW_NON_CONTINUOUS,
	.xipWriteCmd        = CY_SMIF_4QPP,
	.mergeTimeoutEnable = true,
	.mergeTimeout       = CY_SMIF_MER_TIMEOUT_1_CYCLE,
	.totalTimeoutEnable = true,
	.totalTimeout       = 1000u,
	.addr               = SMIF_SMIF_XIP_ADDR,/* 0x6000_0000 */
	.size               = CY_SMIF_DEVICE_64M_BYTE,	/* 32Mbyte * 2(device) */
	.lc_spi             = TEST_SPI_LC,
};

static void WaitDeviceBecomesReady(cy_en_smif_slave_select_t slave)
{
	volatile un_cy_smif_s25fl128_SR1_t sr1 = { .u8 = 0u };
	for (uint8_t i_slaveNum = 0; i_slaveNum < SMIF_DEVICE_NR; i_slaveNum++) {
		cy_en_smif_slave_select_t slaveToBeChecked =
			(cy_en_smif_slave_select_t)((uint8_t)slave & (0x01 << i_slaveNum));
		if ((uint8_t)slaveToBeChecked == 0u) {
			/* not selected slave */
			continue;
		}

		/* only selected slave will reach hare. */
		while (1) {
			Cy_SMIF_S25FL_ReadStatusRegister1(SMIF0, slaveToBeChecked, (uint8_t *)&sr1,
				&smifContext);
			if (sr1.field.u1WIP == 0u)
				break;
		}
	}
}

static int SetMMIO_mode()
{
	SetModeWithBusyCheck(SMIF0, CY_SMIF_NORMAL);
	/* Dummy Read to get device non continuous mode */
	uint32_t dummyRead = 0ul;
	Cy_SMIF_S25FL_Read(SMIF0, D_QUAD_SLAVES, CY_SMIF_4QIOR, TEST_ADDRESS, 4u,
		(uint8_t *)&dummyRead, TEST_SPI_LC, CY_SMIF_XIP_RW_NON_CONTINUOUS, CY_SMIF_BLOCKING,
		&smifContext);

	return 0;
}

static int SetXIP_mode()
{
	/* Dummy Read to get device continuous mode */
	uint32_t dummyRead = 0ul;
	Cy_SMIF_S25FL_Read(SMIF0, D_QUAD_SLAVES, CY_SMIF_4QIOR, TEST_ADDRESS, 4u,
		(uint8_t *)&dummyRead, TEST_SPI_LC, CY_SMIF_XIP_RW_CONTINUOUS, CY_SMIF_BLOCKING,
		&smifContext);

	SetModeWithBusyCheck(SMIF0, CY_SMIF_MEMORY);
	return 0;
}


/* addr - offset from QSPI start address */
int EraseSector (unsigned long adr)
{
	SetMMIO_mode();

	/*  Erase sector
	 * Write enable */
	Cy_SMIF_S25FL_WriteEnable(SMIF0, D_QUAD_SLAVES, &smifContext);

	/* Sector erase */
	Cy_SMIF_S25FL_SectorErase(SMIF0, D_QUAD_SLAVES, (uint32_t)(adr / 2), &smifContext);

	/* Wait for completion */
	WaitDeviceBecomesReady(D_QUAD_SLAVES);

	/* Check there is no error */
	volatile un_cy_smif_s25fl128_SR1_t sr1 = { .u8 = 0u };
	Cy_SMIF_S25FL_ReadStatusRegister1(SMIF0, D_QUAD_SLAVES, (uint8_t *)&sr1, &smifContext);

	SetXIP_mode();

	return !(sr1.field.u1E_ERR == 0u);
}

int EraseChip (void)
{
	SetMMIO_mode();

	/*  Erase sector
	 * Write enable */
	Cy_SMIF_S25FL_WriteEnable(SMIF0, D_QUAD_SLAVES, &smifContext);

	/* Sector erase */
	Cy_SMIF_S25FL_BulkErase(SMIF0, D_QUAD_SLAVES, &smifContext);

	/* Wait for completion */
	WaitDeviceBecomesReady(D_QUAD_SLAVES);

	/* Check there is no error */
	volatile un_cy_smif_s25fl128_SR1_t sr1 = { .u8 = 0u };
	Cy_SMIF_S25FL_ReadStatusRegister1(SMIF0, D_QUAD_SLAVES, (uint8_t *)&sr1, &smifContext);

	SetXIP_mode();

	return  !(sr1.field.u1E_ERR == 0u);
}

#define SECTOR_SIZE     0x10000
#define PROGRAM_ROW_SIZE    0x200

/* program by 256/512 bytes
 * addr - offset from QSPI start address */
int ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf)
{
	SetMMIO_mode();

	/* Write enable */
	Cy_SMIF_S25FL_WriteEnable(SMIF0, D_QUAD_SLAVES, &smifContext);

	/* Issue program */
	cy_en_smif_status_t status =
		Cy_SMIF_S25FL_Program(SMIF0, D_QUAD_SLAVES, CY_SMIF_4QPP, (uint32_t)(adr / 2),
			(uint32_t)(sz) /* 512B * 2 */, buf, CY_SMIF_BLOCKING, &smifContext);

	/* Wait for completion */
	WaitDeviceBecomesReady(D_QUAD_SLAVES);

	SetXIP_mode();

	return !(status == CY_SMIF_SUCCESS);
}

int UnInit(unsigned long fnc)
{
	(void)fnc;
	return 0;
}

int Init(unsigned long adr, unsigned long clk, unsigned long fnc)
{
	(void)clk; (void)fnc;

	SystemInit();
	
	Cy_SysClk_HfClkEnable(CY_SYSCLK_HFCLK_6);

	smifDevDualQuadCfg.addr = adr;

	SmifPortInit(smifPortCfg, SIZE_OF_PORT);

	/************************
	 * 1. Setting for SMIF 0
	 *************************/
	Cy_SMIF_DeInit(SMIF0);
	Cy_SMIF_Init(SMIF0, &smifConfig, 1000, &smifContext);

	/***********************************
	 * 2. Setting for SMIF 0 Device 0/1
	 ************************************/
	Cy_SMIF_DeviceSetDataSelect(SMIF0_DEVICE0, CY_SMIF_DATA_SEL0);
	Cy_SMIF_DeviceWriteEnable(SMIF0_DEVICE0);
	Cy_SMIF_DeviceSetDataSelect(SMIF0_DEVICE1, CY_SMIF_DATA_SEL2);
	Cy_SMIF_DeviceWriteEnable(SMIF0_DEVICE1);

	/*******************
	 * 3. Enable SMIF 0
	 ********************/
	Cy_SMIF_Enable(SMIF0, &smifContext);

	Cy_SMIF_CacheDisable(SMIF0, CY_SMIF_CACHE_BOTH);

	/**********************************
	 * 4. Setting for external devices
	 ***********************************/
	/* 4.1 Send Rest command */
	Cy_SMIF_S25FL_WriteEnable(SMIF0, D_QUAD_SLAVES, &smifContext);
	Cy_SMIF_S25FL_SoftwareReset(SMIF0, D_QUAD_SLAVES, &smifContext);

	/* 4.2 Read Configulation register 1 and status register 1 */

	/* Read current configuration register 1 and status register 1 */
	volatile un_cy_smif_s25fl128_CR1_t prevConfigReg0 = { .u8 = 0u };
	volatile un_cy_smif_s25fl128_CR1_t prevConfigReg1 = { .u8 = 0u };
	volatile un_cy_smif_s25fl128_SR1_t prevStatusReg0 = { .u8 = 0u };
	volatile un_cy_smif_s25fl128_SR1_t prevStatusReg1 = { .u8 = 0u };

	Cy_SMIF_S25FL_ReadConfigurationRegister(SMIF0, CY_SMIF_SLAVE_SELECT_0,
		(uint8_t *)&prevConfigReg0, &smifContext);

	Cy_SMIF_S25FL_ReadConfigurationRegister(SMIF0, CY_SMIF_SLAVE_SELECT_1,
		(uint8_t *)&prevConfigReg1, &smifContext);

	Cy_SMIF_S25FL_ReadStatusRegister1(SMIF0, CY_SMIF_SLAVE_SELECT_0,
		(uint8_t *)&prevStatusReg0, &smifContext);

	Cy_SMIF_S25FL_ReadStatusRegister1(SMIF0, CY_SMIF_SLAVE_SELECT_1,
		(uint8_t *)&prevStatusReg1, &smifContext);

	/* 4.3 Modify the registers and set them */

	/* Modify QUAD and LC field to be set */
	prevConfigReg0.field.u1QUAD = USE_QUAD_MODE;
	prevConfigReg0.field.u2LC   = TEST_SPI_LC;
	prevConfigReg1.field.u1QUAD = USE_QUAD_MODE;
	prevConfigReg1.field.u2LC   = TEST_SPI_LC;
	prevStatusReg0.field.u3BP   = 0u;/* no protection */
	prevStatusReg1.field.u3BP   = 0u;/* no protection */

	/* Send Write Enable command */
	Cy_SMIF_S25FL_WriteEnable(SMIF0, D_QUAD_SLAVES, &smifContext);

	/* Write Registers */
	Cy_SMIF_S25FL_WriteStatusAndConfigRegister(SMIF0, CY_SMIF_SLAVE_SELECT_0, prevStatusReg0.u8,
		prevConfigReg0.u8, &smifContext);

	Cy_SMIF_S25FL_WriteStatusAndConfigRegister(SMIF0, CY_SMIF_SLAVE_SELECT_1, prevStatusReg1.u8,
		prevConfigReg1.u8, &smifContext);

	/* Wait writing registers complete */
	WaitDeviceBecomesReady(D_QUAD_SLAVES);

	/* Check the config register have been writen properly */
	volatile un_cy_smif_s25fl128_CR1_t readConfigReg0 = { .u8 = 0u };
	volatile un_cy_smif_s25fl128_CR1_t readConfigReg1 = { .u8 = 0u };

	Cy_SMIF_S25FL_ReadConfigurationRegister(SMIF0, CY_SMIF_SLAVE_SELECT_0,
		(uint8_t *)&readConfigReg0, &smifContext);

	Cy_SMIF_S25FL_ReadConfigurationRegister(SMIF0, CY_SMIF_SLAVE_SELECT_1,
		(uint8_t *)&readConfigReg1, &smifContext);

	CY_ASSERT_L1(readConfigReg0.field.u1QUAD == USE_QUAD_MODE);
	CY_ASSERT_L1(readConfigReg0.field.u2LC == TEST_SPI_LC);
	CY_ASSERT_L1(readConfigReg1.field.u1QUAD == USE_QUAD_MODE);
	CY_ASSERT_L1(readConfigReg1.field.u2LC == TEST_SPI_LC);

	/* 4.4 Set DLP */
	uint8_t dlp = DLP_VALUE;
	Cy_SMIF_S25FL_WriteVDLR(SMIF0, D_QUAD_SLAVES, dlp, &smifContext);

	smifDevDualQuadCfg.xipReadCmd = CY_SMIF_4QIOR;
	smifDevDualQuadCfg.xipReadMode = CY_SMIF_XIP_RW_CONTINUOUS;
	Cy_SMIF_InitDeviceForS25FL(SMIF0_DEVICE0, CY_SMIF_DEV_D_QUAD_BIT_0To3, &smifDevDualQuadCfg);
	Cy_SMIF_InitDeviceForS25FL(SMIF0_DEVICE1, CY_SMIF_DEV_D_QUAD_BIT_4To7, &smifDevDualQuadCfg);

	SetXIP_mode();

	return 0;
}

/* [] END OF FILE */
