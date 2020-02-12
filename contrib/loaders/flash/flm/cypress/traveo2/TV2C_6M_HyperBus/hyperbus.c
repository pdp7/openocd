//#include "cmsis_compiler.h"
//#include "cy_gpio.h"
//#include "cy_smif_hb_flash.h"
//#include "cy_sysclk.h"
//#include "cy_syswdt.h"
//#include "bb_bsp_tviic2d6m.h"

// clang-format off
#include "cy_smif_hb_flash.c"
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

#if defined(HYPER_FLASH) && defined(HYPER_RAM)
#error "Both, HYPER_FLASH and HYPER_RAM defined"
#endif

#if !defined(HYPER_FLASH) && !defined(HYPER_RAM)
#error "None of HYPER_FLASH / HYPER_RAM defined"
#endif

#if !defined(SMIF_CH_0) && !defined(SMIF_CH_1)
#error "None of SMIF_CH_0 / SMIF_CH_0 defined"
#endif

// Switch for SMIF instance to be used
//#define SMIF_CH_TO_BE_USED  0
#if defined (SMIF_CH_0)
  #define SMIF_USED               SMIF0
  #define SMIF_DEVICE0            SMIF0_DEVICE0
  #define SMIF_DEVICE1            SMIF0_DEVICE1

  #define CY_SMIF_CLK_PORT        CY_SMIF0_CLK_PORT
  #define CY_SMIF_CLK_PIN         CY_SMIF0_CLK_PIN
  #define CY_SMIF_CLK_PIN_MUX     CY_SMIF0_CLK_PIN_MUX

  #define CY_SMIF_RWDS_PORT       CY_SMIF0_RWDS_PORT
  #define CY_SMIF_RWDS_PIN        CY_SMIF0_RWDS_PIN
  #define CY_SMIF_RWDS_PIN_MUX    CY_SMIF0_RWDS_PIN_MUX

  #define CY_SMIF_SELECT0_PORT    CY_SMIF0_SELECT0_PORT
  #define CY_SMIF_SELECT0_PIN     CY_SMIF0_SELECT0_PIN
  #define CY_SMIF_SELECT0_PIN_MUX CY_SMIF0_SELECT0_PIN_MUX

  #define CY_SMIF_SELECT1_PORT    CY_SMIF0_SELECT1_PORT
  #define CY_SMIF_SELECT1_PIN     CY_SMIF0_SELECT1_PIN
  #define CY_SMIF_SELECT1_PIN_MUX CY_SMIF0_SELECT1_PIN_MUX

  #define CY_SMIF_DATA0_PORT      CY_SMIF0_DATA0_PORT
  #define CY_SMIF_DATA0_PIN       CY_SMIF0_DATA0_PIN
  #define CY_SMIF_DATA0_PIN_MUX   CY_SMIF0_DATA0_PIN_MUX

  #define CY_SMIF_DATA1_PORT      CY_SMIF0_DATA1_PORT
  #define CY_SMIF_DATA1_PIN       CY_SMIF0_DATA1_PIN
  #define CY_SMIF_DATA1_PIN_MUX   CY_SMIF0_DATA1_PIN_MUX

  #define CY_SMIF_DATA2_PORT      CY_SMIF0_DATA2_PORT
  #define CY_SMIF_DATA2_PIN       CY_SMIF0_DATA2_PIN
  #define CY_SMIF_DATA2_PIN_MUX   CY_SMIF0_DATA2_PIN_MUX

  #define CY_SMIF_DATA3_PORT      CY_SMIF0_DATA3_PORT
  #define CY_SMIF_DATA3_PIN       CY_SMIF0_DATA3_PIN
  #define CY_SMIF_DATA3_PIN_MUX   CY_SMIF0_DATA3_PIN_MUX

  #define CY_SMIF_DATA4_PORT      CY_SMIF0_DATA4_PORT
  #define CY_SMIF_DATA4_PIN       CY_SMIF0_DATA4_PIN
  #define CY_SMIF_DATA4_PIN_MUX   CY_SMIF0_DATA4_PIN_MUX

  #define CY_SMIF_DATA5_PORT      CY_SMIF0_DATA5_PORT
  #define CY_SMIF_DATA5_PIN       CY_SMIF0_DATA5_PIN
  #define CY_SMIF_DATA5_PIN_MUX   CY_SMIF0_DATA5_PIN_MUX

  #define CY_SMIF_DATA6_PORT      CY_SMIF0_DATA6_PORT
  #define CY_SMIF_DATA6_PIN       CY_SMIF0_DATA6_PIN
  #define CY_SMIF_DATA6_PIN_MUX   CY_SMIF0_DATA6_PIN_MUX

  #define CY_SMIF_DATA7_PORT      CY_SMIF0_DATA7_PORT
  #define CY_SMIF_DATA7_PIN       CY_SMIF0_DATA7_PIN
  #define CY_SMIF_DATA7_PIN_MUX   CY_SMIF0_DATA7_PIN_MUX

  /* !! YOTS: Possibly, the number of HF clock for SMFI will be changed. */
  #define SMIF_HF_CLOCK           CY_SYSCLK_HFCLK_9

  #define SMIF_IRQ_NO             smif_0_interrupt_IRQn
#endif

#if defined (SMIF_CH_1)

  #define SMIF_USED               SMIF1
  #define SMIF_DEVICE0            SMIF1_DEVICE0
  #define SMIF_DEVICE1            SMIF1_DEVICE1

  #define CY_SMIF_CLK_PORT        CY_SMIF1_CLK_PORT
  #define CY_SMIF_CLK_PIN         CY_SMIF1_CLK_PIN
  #define CY_SMIF_CLK_PIN_MUX     CY_SMIF1_CLK_PIN_MUX

  #define CY_SMIF_RWDS_PORT       CY_SMIF1_RWDS_PORT
  #define CY_SMIF_RWDS_PIN        CY_SMIF1_RWDS_PIN
  #define CY_SMIF_RWDS_PIN_MUX    CY_SMIF1_RWDS_PIN_MUX

  #define CY_SMIF_SELECT0_PORT    CY_SMIF1_SELECT0_PORT
  #define CY_SMIF_SELECT0_PIN     CY_SMIF1_SELECT0_PIN
  #define CY_SMIF_SELECT0_PIN_MUX CY_SMIF1_SELECT0_PIN_MUX

  #define CY_SMIF_SELECT1_PORT    CY_SMIF1_SELECT1_PORT
  #define CY_SMIF_SELECT1_PIN     CY_SMIF1_SELECT1_PIN
  #define CY_SMIF_SELECT1_PIN_MUX CY_SMIF1_SELECT1_PIN_MUX

  #define CY_SMIF_DATA0_PORT      CY_SMIF1_DATA0_PORT
  #define CY_SMIF_DATA0_PIN       CY_SMIF1_DATA0_PIN
  #define CY_SMIF_DATA0_PIN_MUX   CY_SMIF1_DATA0_PIN_MUX

  #define CY_SMIF_DATA1_PORT      CY_SMIF1_DATA1_PORT
  #define CY_SMIF_DATA1_PIN       CY_SMIF1_DATA1_PIN
  #define CY_SMIF_DATA1_PIN_MUX   CY_SMIF1_DATA1_PIN_MUX

  #define CY_SMIF_DATA2_PORT      CY_SMIF1_DATA2_PORT
  #define CY_SMIF_DATA2_PIN       CY_SMIF1_DATA2_PIN
  #define CY_SMIF_DATA2_PIN_MUX   CY_SMIF1_DATA2_PIN_MUX

  #define CY_SMIF_DATA3_PORT      CY_SMIF1_DATA3_PORT
  #define CY_SMIF_DATA3_PIN       CY_SMIF1_DATA3_PIN
  #define CY_SMIF_DATA3_PIN_MUX   CY_SMIF1_DATA3_PIN_MUX

  #define CY_SMIF_DATA4_PORT      CY_SMIF1_DATA4_PORT
  #define CY_SMIF_DATA4_PIN       CY_SMIF1_DATA4_PIN
  #define CY_SMIF_DATA4_PIN_MUX   CY_SMIF1_DATA4_PIN_MUX

  #define CY_SMIF_DATA5_PORT      CY_SMIF1_DATA5_PORT
  #define CY_SMIF_DATA5_PIN       CY_SMIF1_DATA5_PIN
  #define CY_SMIF_DATA5_PIN_MUX   CY_SMIF1_DATA5_PIN_MUX

  #define CY_SMIF_DATA6_PORT      CY_SMIF1_DATA6_PORT
  #define CY_SMIF_DATA6_PIN       CY_SMIF1_DATA6_PIN
  #define CY_SMIF_DATA6_PIN_MUX   CY_SMIF1_DATA6_PIN_MUX

  #define CY_SMIF_DATA7_PORT      CY_SMIF1_DATA7_PORT
  #define CY_SMIF_DATA7_PIN       CY_SMIF1_DATA7_PIN
  #define CY_SMIF_DATA7_PIN_MUX   CY_SMIF1_DATA7_PIN_MUX

  /* !! YOTS: Possibly, the number of HF clock for SMFI will be changed. */
  #define SMIF_HF_CLOCK           CY_SYSCLK_HFCLK_10

  #define SMIF_IRQ_NO             smif_1_interrupt_IRQn

#endif

#define FLASH_DRIVE_STRENGTH_34_OHMS 0
#define FLASH_DRIVE_STRENGTH_115_OHMS 1
#define FLASH_DRIVE_STRENGTH_67_OHMS 2
#define FLASH_DRIVE_STRENGTH_46_OHMS 3
#define FLASH_DRIVE_STRENGTH_27_OHMS 5
#define FLASH_DRIVE_STRENGTH_22_OHMS 6
#define FLASH_DRIVE_STRENGTH_19_OHMS 7

#define FLASH_VCR_OR_NVCR_LOCKED 0
#define FLASH_VCR_AND_NVCR_UNLOCKED 1

#define FLASH_SECURE_SILICON_REGION_LOCKED 0
#define FLASH_SECURE_SILICON_REGION_UNLOCKED 1

#define FLASH_MAPPED_INTO_LOWEST_ADDRESSES 0
#define FLASH_MAPPED_INTO_HIGHEST_ADDRESSES 1
#define FLASH_UN_SECT_INTO_LOWEST_ADDR 2
#define FLASH_UN_SECT_INTO_HIGHTEST_ADDR 3

#define FLASH_RDS_WILL_STALL 0
#define FLASH_RDS_WILL_NOT_STALL 1

#define FLASH_BURST_LENGTH_64_BYTES 1
#define FLASH_BURST_LENGTH_16_BYTES 2
#define FLASH_BURST_LENGTH_32_BYTES 3


/* HyperRAM Register CY_SMIF_WORD Offset Address */
/* Macro to be used for reg_addr argument of API */
#define CY_SMIF_HYPERRAM_ID_REG_0               (0x00000000)
#define CY_SMIF_HYPERRAM_ID_REG_1               (0x00000001)
#define CY_SMIF_HYPERRAM_CONFIG_REG_0           (0x00000800)
#define CY_SMIF_HYPERRAM_CONFIG_REG_1           (0x00000801)
#define CY_SMIF_HYPERRAM_DIE_MANUF_INFO_REG_0   (0x00010000)
#define CY_SMIF_HYPERRAM_DIE_MANUF_INFO_REG_1   (0x00010001)
#define CY_SMIF_HYPERRAM_DIE_MANUF_INFO_REG_2   (0x00010002)

#define ENTER_DEEP_POWER_DOWN 0
#define NORMAL_OPERATION 1

#define OFFSET_STROBE_ENABLED 0
#define OFFSET_STROBE_DISABLED 1

#define RAM_VARIABLE_INITIAL_LATENCY 0
#define RAM_FIXED_INITIAL_LATENCY 1

#define RAM_FOLLOW_HYBRID_BURST_SEQUENCING 0
#define RAM_LEGACY_WRAPPED_BURST_MANNER 1

#define RAM_BURST_LENGTH_128_BYTES 0
#define RAM_BURST_LENGTH_64_BYTES 1
#define RAM_BURST_LENGTH_16_BYTES 2
#define RAM_BURST_LENGTH_32_BYTES 3


typedef struct
{
	uint16_t burstLength        : 2;
	uint16_t hybridBurstEnable  : 1;
	uint16_t fixedLatencyEnable : 1;
	uint16_t initialLatency     : 4;
	uint16_t offsetStrobeEnable : 1;
	uint16_t Reserved0          : 3;
	uint16_t driveStrength      : 3;
	uint16_t deepPowerDownEnable: 1;
} stc_hyperram_vcr_t;

typedef union
{
	uint16_t           u16;
	stc_hyperram_vcr_t fld;
} un_HyperRamVCR_t;

static void SmifPortInit()
{
	const struct {
		volatile stc_GPIO_PRT_t *port;
		uint8_t pin;
		en_hsiom_sel_t hsiom;
		uint32_t driveMode;
	}  smifPortCfg[] =
	{
		{CY_SMIF_CLK_PORT,         CY_SMIF_CLK_PIN,          CY_SMIF_CLK_PIN_MUX,          CY_GPIO_DM_STRONG},
		{CY_SMIF_RWDS_PORT,        CY_SMIF_RWDS_PIN,         CY_SMIF_RWDS_PIN_MUX,         CY_GPIO_DM_STRONG},
		{CY_SMIF_SELECT0_PORT,     CY_SMIF_SELECT0_PIN,      CY_SMIF_SELECT0_PIN_MUX,      CY_GPIO_DM_STRONG},
		{CY_SMIF_SELECT1_PORT,     CY_SMIF_SELECT1_PIN,      CY_SMIF_SELECT1_PIN_MUX,      CY_GPIO_DM_STRONG},
		{CY_SMIF_DATA0_PORT,       CY_SMIF_DATA0_PIN,        CY_SMIF_DATA0_PIN_MUX,        CY_GPIO_DM_STRONG},
		{CY_SMIF_DATA1_PORT,       CY_SMIF_DATA1_PIN,        CY_SMIF_DATA1_PIN_MUX,        CY_GPIO_DM_STRONG},
		{CY_SMIF_DATA2_PORT,       CY_SMIF_DATA2_PIN,        CY_SMIF_DATA2_PIN_MUX,        CY_GPIO_DM_STRONG},
		{CY_SMIF_DATA3_PORT,       CY_SMIF_DATA3_PIN,        CY_SMIF_DATA3_PIN_MUX,        CY_GPIO_DM_STRONG},
		{CY_SMIF_DATA4_PORT,       CY_SMIF_DATA4_PIN,        CY_SMIF_DATA4_PIN_MUX,        CY_GPIO_DM_STRONG},
		{CY_SMIF_DATA5_PORT,       CY_SMIF_DATA5_PIN,        CY_SMIF_DATA5_PIN_MUX,        CY_GPIO_DM_STRONG},
		{CY_SMIF_DATA6_PORT,       CY_SMIF_DATA6_PIN,        CY_SMIF_DATA6_PIN_MUX,        CY_GPIO_DM_STRONG},
		{CY_SMIF_DATA7_PORT,       CY_SMIF_DATA7_PIN,        CY_SMIF_DATA7_PIN_MUX,        CY_GPIO_DM_STRONG},
	};
	#define SIZE_OF_PORT (sizeof(smifPortCfg) / sizeof(smifPortCfg[0]))

	cy_stc_gpio_pin_config_t pinCfg = {0};
	for(uint32_t i = 0; i < SIZE_OF_PORT; i++)
	{
		pinCfg.driveMode = smifPortCfg[i].driveMode;
		pinCfg.hsiom     = smifPortCfg[i].hsiom;
		Cy_GPIO_Pin_Init(smifPortCfg[i].port, smifPortCfg[i].pin, &pinCfg);
	}
}

static CY_SMIF_FLASHDATA *g_base_addr;

#if defined(HYPER_RAM)
__attribute__((__section__(".start")))
#endif
int Init(unsigned long adr, unsigned long clk, unsigned long fnc)
{
	(void)clk; (void)fnc;

	SystemInit();

	const cy_stc_smif_config_t smifConfig = {
		.txClk         = CY_SMIF_INV_FOR_DDR,
		.rxClk         = CY_SMIF_INV_RWDS,
		.capDelay      = CY_SMIF_CAPTURE_DELAY_0_CYCLE,
		.delaySel      = CY_SMIF_1_SEN_SEL_PER_TAP,
		.deselectDelay = CY_SMIF_MIN_DESELECT_1_CLK,
		.setupDelay    = CY_SMIF_SETUP_0_CLK_PULUS_MIN,
		.holdDelay     = CY_SMIF_HOLD_0_CLK_PULUS_MIN,
		.mode          = CY_SMIF_MEMORY, // XIP mode
		.blockEvent    = CY_SMIF_BUS_ERROR,
	};

	#define HB_INITIAL_LC CY_SMIF_HB_LC5

	cy_stc_smif_context_t smifContext;

	g_base_addr = (CY_SMIF_FLASHDATA *)adr;

	Cy_WDT_Disable();
	Cy_SysClk_HfClkEnable(SMIF_HF_CLOCK);
	Cy_SysClk_HfClockSetDivider(SMIF_HF_CLOCK, CY_SYSCLK_HFCLK_DIVIDE_BY_8);

	SmifPortInit();

	/* 1. Setting for SMIF 0 */
	Cy_SMIF_Init(SMIF_USED, &smifConfig, 1000, &smifContext);
	Cy_SMIF_Set_DelayTapSel(SMIF_USED, (CY_SMIF_GetDelayTapsNumber(SMIF_USED) - 1));
	Cy_SMIF_CacheDisable(SMIF_USED, CY_SMIF_CACHE_BOTH);
	Cy_SMIF_Enable(SMIF_USED, &smifContext);

#if defined(HYPER_FLASH)
	const cy_stc_device_hb_config_t smifDevHBFlashCfg = {
		.xipReadCmd         = CY_SMIF_HB_READ_WRAPPED_BURST,
		.xipWriteCmd        = CY_SMIF_HB_WRITE_WRAPPED_BURST,
		.mergeTimeoutEnable = true,
		.mergeTimeout       = CY_SMIF_MER_TIMEOUT_1_CYCLE,
		.totalTimeoutEnable = true,
		.totalTimeout       = 1000u,
		.addr = adr,	/* 0x6000_0000 */
		.size               = CY_SMIF_DEVICE_16M_BYTE,
		.lc_hb              = HB_INITIAL_LC,
		.hbDevType          = CY_SMIF_HB_FLASH,
	};

	/* 2. Setting for SMIF 0 Device 0 for hyper FLASH */
	Cy_SMIF_InitDeviceHyperBus(SMIF_DEVICE0, &smifDevHBFlashCfg);
	un_HyperFlashVCR_t flashVCR    = { .u16 = 0xFFFF };
	flashVCR.fld.burstLength       = FLASH_BURST_LENGTH_32_BYTES;          // Burst length set to 32 byte.
	flashVCR.fld.RDS_stallControll = FLASH_RDS_WILL_STALL;                 // RDS will stall (remain LOW) upon Dual Error Detect.
	flashVCR.fld.readLatency       = smifDevHBFlashCfg.lc_hb;              // Maximum operation frequency is 104 MHz.
	flashVCR.fld.sectorMapping     = FLASH_UN_SECT_INTO_LOWEST_ADDR;       // Uniform Sectors with Read Password Sector mapped into lowest addresses.
	flashVCR.fld.SSR_freeze        = FLASH_SECURE_SILICON_REGION_UNLOCKED; // Secure silicon region unlocked.
	flashVCR.fld.VCR_freeze        = FLASH_VCR_AND_NVCR_UNLOCKED;          // VCR and NVCR unlocked.
	flashVCR.fld.driveStrength     = FLASH_DRIVE_STRENGTH_34_OHMS;         // Burst length set to 32 byte.
	CY_SMIF_HbFlash_LoadVolatileConfigReg((CY_SMIF_FLASHDATA *)adr, flashVCR.u16);
	/* Return value should match flashVCR.u16
	 * Ignored for now
	 * uint16_t readConfigRegVal = CY_SMIF_HbFlash_ReadVolatileConfigReg(pHyperFlashBaseAddr);
	 * CY_ASSERT(readConfigRegVal == flashVCR.u16);	 */
#endif

#if defined(HYPER_RAM)
	cy_stc_device_hb_config_t smifDevHBSramCfg = {
		.xipReadCmd         = CY_SMIF_HB_READ_WRAPPED_BURST,
		.xipWriteCmd        = CY_SMIF_HB_WRITE_WRAPPED_BURST,
		.mergeTimeoutEnable = true,
		.mergeTimeout       = CY_SMIF_MER_TIMEOUT_1_CYCLE,
		.totalTimeoutEnable = true,
		.totalTimeout       = 1000u,
		.addr               = adr, /* 0x6400_0000 */
		.size               = CY_SMIF_DEVICE_8M_BYTE,
		.lc_hb              = HB_INITIAL_LC,
		.hbDevType          = CY_SMIF_HB_SRAM,
	};

	/* 3. Setting for SMIF 0 Device 1 for hyper RAM */
	Cy_SMIF_InitDeviceHyperBus(SMIF_DEVICE1, &smifDevHBSramCfg);
	un_HyperRamVCR_t ramVCR        = { .u16 = 0xFFFF };
	ramVCR.fld.burstLength         = RAM_BURST_LENGTH_128_BYTES;      // Burst length set to 128 byte.
	ramVCR.fld.hybridBurstEnable   = RAM_LEGACY_WRAPPED_BURST_MANNER; //
	ramVCR.fld.fixedLatencyEnable  = RAM_FIXED_INITIAL_LATENCY;       // Fixed latency
	ramVCR.fld.initialLatency      = smifDevHBSramCfg.lc_hb;          // 4 clocks
	ramVCR.fld.offsetStrobeEnable  = OFFSET_STROBE_DISABLED;          //
	ramVCR.fld.driveStrength       = 7;                               // Device dependent impedance
	ramVCR.fld.deepPowerDownEnable = NORMAL_OPERATION;                // Normal operation

	uint16_t v0 = 0;
	uint16_t v1 = 0;

	CY_SMIF_WriteHYPERRAM_REG(SMIF_DEVICE1, CY_SMIF_HYPERRAM_CONFIG_REG_0, ramVCR.u16);
	CY_SMIF_WriteHYPERRAM_REG(SMIF_DEVICE1, CY_SMIF_HYPERRAM_CONFIG_REG_1, 0x0001);
	CY_SMIF_ReadHYPERRAM_REG(SMIF_DEVICE1, CY_SMIF_HYPERRAM_CONFIG_REG_0, &v0);
	CY_SMIF_ReadHYPERRAM_REG(SMIF_DEVICE1, CY_SMIF_HYPERRAM_CONFIG_REG_1, &v1);
	/* Errors ignored for now
	 * CY_ASSERT(v0 == ramVCR.u16);
	 * CY_ASSERT(v1 == 0x0001); */


	__BKPT(0);
#endif
	return 0;
}

int UnInit (unsigned long fnc)
{
	(void)fnc;
	return (0);
}

int EraseSector(unsigned long adr)
{
	CY_SMIF_DEVSTATUS hr;

	if (adr < (unsigned long)g_base_addr)
		return 1;

	adr -= (unsigned long)g_base_addr;
	hr = CY_SMIF_HbFlash_SectorEraseOp(g_base_addr, (CY_SMIF_ADDRESS)(adr / 2));
	return !(hr == CY_SMIF_DEV_NOT_BUSY);
}

int EraseChip()
{
	CY_SMIF_DEVSTATUS hr = CY_SMIF_HbFlash_ChipEraseOp(g_base_addr);
	return !(hr == CY_SMIF_DEV_NOT_BUSY);
}

int ProgramPage(unsigned long adr, unsigned long sz, const unsigned char *buf)
{
	if (adr < (unsigned long)g_base_addr)
		return 1;

	adr -= (unsigned long)g_base_addr;

	CY_SMIF_DEVSTATUS hr;
	CY_SMIF_ADDRESS offset = (adr / 2);
	CY_SMIF_FLASHDATA *data = (CY_SMIF_FLASHDATA *)buf;
	hr = CY_SMIF_HbFlash_WriteBufferProgramOp(g_base_addr, offset, sz >> 1, data);
	return !(hr == CY_SMIF_DEV_NOT_BUSY);
}

/* [] END OF FILE */
