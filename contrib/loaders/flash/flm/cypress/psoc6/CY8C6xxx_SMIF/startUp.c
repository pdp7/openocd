/*******************************************************************************
 * \file StartUp.c
 * \version 1.0
 *
 * \brief
 *  Implements basic APIs for silicon startup.
 *
 ********************************************************************************
 * \copyright
 * Copyright 2017, Cypress Semiconductor Corporation.  All rights reserved.
 * You may use this file only in accordance with the license, terms, conditions,
 * disclaimers, and limitations in the end user license agreement accompanying
 * the software package with which this file was provided.
 *******************************************************************************/
#include "device_header.h"

/* SMIF_1_SMIF_IRQ */
#define SMIF_1_SMIF_IRQ__INTC_CORTEXM0P_ASSIGNED 1
#define SMIF_1_SMIF_IRQ__INTC_CORTEXM0P_MUX 0u
#define SMIF_1_SMIF_IRQ__INTC_CORTEXM0P_PRIORITY 3u
#define SMIF_1_SMIF_IRQ__INTC_NUMBER 134u

#define SRSS_CLK_PATH_SELECT_PATH_MUX_Pos 0UL
#define SRSS_CLK_PATH_SELECT_PATH_MUX_Msk 0x7UL

static volatile uint32_t clkReg1;
static volatile uint32_t clkReg2;
static volatile uint32_t clkReg3;
static volatile uint32_t clkReg4;

static cy_stc_gpio_prt_config_t port1_cfg_b = {.out = 1,
											   .intrMask = 1,
											   .intrCfg = 1,
											   .cfg = 1,
											   .cfgIn = 1,
											   .cfgOut = 1,
											   .cfgSIO = 1,
											   .sel0Active = 1,
											   .sel1Active = 1};

static cy_stc_gpio_prt_config_t port8_cfg_b = {.out = 1,
											   .intrMask = 1,
											   .intrCfg = 1,
											   .cfg = 1,
											   .cfgIn = 1,
											   .cfgOut = 1,
											   .cfgSIO = 1,
											   .sel0Active = 1,
											   .sel1Active = 1};

static cy_stc_gpio_prt_config_t port11_cfg_b = {.out = 1,
												.intrMask = 1,
												.intrCfg = 1,
												.cfg = 1,
												.cfgIn = 1,
												.cfgOut = 1,
												.cfgSIO = 1,
												.sel0Active = 1,
												.sel1Active = 1};

static cy_stc_gpio_prt_config_t port12_cfg_b = {.out = 1,
												.intrMask = 1,
												.intrCfg = 1,
												.cfg = 1,
												.cfgIn = 1,
												.cfgOut = 1,
												.cfgSIO = 1,
												.sel0Active = 1,
												.sel1Active = 1};

/*******************************************************************************
 * Function Name: initHWSMIF
 ********************************************************************************
 *
 * Initializes clock, pins used by SMIF and debug uart.
 *
 *
 *******************************************************************************/
void initHWSMIF(void) {
	/* Cy_SysClk_HfClockSetSource(2u, CY_SYSCLK_HFCLK_IN_CLKPATH0); */
	CY_SYSCLK_CLR_SET(SRSS->CLK_ROOT_SELECT[2u], SRSS_CLK_ROOT_SELECT_ROOT_MUX, CY_SYSCLK_HFCLK_IN_CLKPATH0);

	/* Cy_SysClk_ClkPathSetSource(2, CY_SYSCLK_CLKPATH_IN_IMO); */
	SRSS->CLK_PATH_SELECT[2] = _VAL2FLD(SRSS_CLK_PATH_SELECT_PATH_MUX, (uint32_t)0);

	/* Cy_SysClk_ClkHfEnable(2u); */
	SRSS->CLK_ROOT_SELECT[0u] |= _VAL2FLD(SRSS_CLK_ROOT_SELECT_ENABLE, 1ul); /* 1 = enable */
	SRSS->CLK_ROOT_SELECT[1u] |= _VAL2FLD(SRSS_CLK_ROOT_SELECT_ENABLE, 1ul); /* 1 = enable */
	SRSS->CLK_ROOT_SELECT[2u] |= _VAL2FLD(SRSS_CLK_ROOT_SELECT_ENABLE, 1ul); /* 1 = enable */

	/* Port1 configuration */
	const cy_stc_gpio_prt_config_t port1_cfg = {
		.out = 0x00000001,
		.intrMask = 0x00000000,
		.intrCfg = 0x00000000,
		.cfg = 0x0000000B,
		.cfgIn = 0x00000000,
		.cfgOut = 0x00000000,
		.cfgSIO = 0x00000000,
		.sel0Active = 0x00000000,
		.sel1Active = 0x00000000,
	};
	Cy_GPIO_Port_Init(GPIO_PRT1, &port1_cfg);

	/* Port8 configuration */
	const cy_stc_gpio_prt_config_t port8_cfg = {
		.out = 0x00000003,
		.intrMask = 0x00000000,
		.intrCfg = 0x00000000,
		.cfg = 0x00000068,
		.cfgIn = 0x00000000,
		.cfgOut = 0x00000000,
		.cfgSIO = 0x00000000,
		.sel0Active = 0x00001212,
		.sel1Active = 0x00000000,
	};
	Cy_GPIO_Port_Init(GPIO_PRT8, &port8_cfg);

	/* Port11 configuration */
	const cy_stc_gpio_prt_config_t port11_cfg = {
		.out = 0x000000FF,
		.intrMask = 0x00000000,
		.intrCfg = 0x00000000,
		.cfg = 0x6EEEE666,
		.cfgIn = 0x00000000,
		.cfgOut = 0x00000000,
		.cfgSIO = 0x00000000,
		.sel0Active = 0x11111111,
		.sel1Active = 0x11111111,
	};
	Cy_GPIO_Port_Init(GPIO_PRT11, &port11_cfg);

	/* Port12 configuration */
	const cy_stc_gpio_prt_config_t port12_cfg = {
		.out = 0x0000001F,
		.intrMask = 0x00000000,
		.intrCfg = 0x00000000,
		.cfg = 0x0006EEEE,
		.cfgIn = 0x00000000,
		.cfgOut = 0x00000000,
		.cfgSIO = 0x00000000,
		.sel0Active = 0x11111111,
		.sel1Active = 0x00000011,
	};
	Cy_GPIO_Port_Init(GPIO_PRT12, &port12_cfg);
}

/*******************************************************************************
 * Function Name: Cy_GPIO_Port_Init
 ****************************************************************************//**
*
* \brief Initialize a complete port of pins from a single init structure.
*
* \param base
* Pointer to the pin's port register base address
*
* \param config
* Pointer to the pin config structure base address
*
* \return
* void
*
*******************************************************************************/
uint32_t Cy_GPIO_Port_Init(GPIO_PRT_Type* base, const cy_stc_gpio_prt_config_t* config) {
	uint32_t portNum;
	HSIOM_PRT_Type* baseHSIOM;

	/* This error check was pointless in a flash loader */
	portNum = ((uint32_t)(base)-GPIO_BASE) / GPIO_PRT_SECTION_SIZE;
	baseHSIOM = (HSIOM_PRT_Type*)(HSIOM_BASE + (HSIOM_PRT_SECTION_SIZE * portNum));

	base->OUT = config->out;
	base->CFG = config->cfg;
	base->CFG_IN = config->cfgIn;
	base->CFG_OUT = config->cfgOut;
	base->INTR_CFG = config->intrCfg;
	base->INTR_MASK = config->intrMask;
	base->CFG_SIO = config->cfgSIO;
	baseHSIOM->PORT_SEL0 = config->sel0Active;
	baseHSIOM->PORT_SEL1 = config->sel1Active;

	return 0;
}

/*******************************************************************************
 * Function Name: Cy_SysLib_DelayCycles
 ****************************************************************************//**
*
* \brief Creates a blocking delay.
*
* \param cycles
* Number of cycles.
*
* \return
* void
*
*******************************************************************************/
#ifdef __GNUC__
void Cy_SysLib_DelayCycles(uint32_t cycles) {
	for (volatile uint32_t i = (cycles >> 4); i; i--)
		;
}
#else
__asm void Cy_SysLib_DelayCycles(uint32_t cycles) {
	EXPORT Cy_SysLib_DelayCycles ADDS r0, r0, #2 LSRS r0, r0, #2 BEQ Cy_DelayCycles_done Cy_DelayCycles_loop ADDS r0,
		r0, #1 SUBS r0, r0, #2 BNE Cy_DelayCycles_loop NOP Cy_DelayCycles_done BX lr
}
#endif

/*******************************************************************************
 * Function Name: Cy_SysLib_DelayUs
 ****************************************************************************//**
*
* The function delays by the specified number of microseconds.
* By default, the number of cycles to delay is calculated based on the
* SystemCoreClock. Assumption is that core is running at 4Mhz.
*
*  \param microseconds  The number of microseconds to delay.
*
*******************************************************************************/
void Cy_SysLib_DelayUs(uint16_t microseconds) { Cy_SysLib_DelayCycles((uint32_t)microseconds * 5); }

/*******************************************************************************
 * Function Name: backRestoreCnfg
 ****************************************************************************//**
*
* The function backs up or restores registers affected by the flash loader.
*
*  \param restore  The type of the operation
*		true  - restore
*		false - back up
*
*******************************************************************************/
void backRestoreCnfg(bool restore) {
	HSIOM_PRT_Type* baseHSIOM = NULL;
	uint32_t portNum = 0;

	/* Restore previously saved congig */
	if (restore == true) {
		SRSS->CLK_PATH_SELECT[2u] = clkReg1;
		SRSS->CLK_ROOT_SELECT[0u] = clkReg2;
		SRSS->CLK_ROOT_SELECT[1u] = clkReg3;
		SRSS->CLK_ROOT_SELECT[2u] = clkReg4;

		Cy_GPIO_Port_Init(GPIO_PRT1, &port1_cfg_b);
		Cy_GPIO_Port_Init(GPIO_PRT8, &port8_cfg_b);
		Cy_GPIO_Port_Init(GPIO_PRT11, &port11_cfg_b);
		Cy_GPIO_Port_Init(GPIO_PRT12, &port12_cfg_b);

	} else {
		/* Port1 */
		portNum = ((uint32_t)(GPIO_PRT1)-GPIO_BASE) / GPIO_PRT_SECTION_SIZE;
		baseHSIOM = (HSIOM_PRT_Type*)(HSIOM_BASE + (HSIOM_PRT_SECTION_SIZE * portNum));

		port1_cfg_b.out = GPIO_PRT1->OUT;
		port1_cfg_b.cfg = GPIO_PRT1->CFG;
		port1_cfg_b.cfgIn = GPIO_PRT1->CFG_IN;
		port1_cfg_b.cfgOut = GPIO_PRT1->CFG_OUT;
		port1_cfg_b.intrCfg = GPIO_PRT1->INTR_CFG;
		port1_cfg_b.intrMask = GPIO_PRT1->INTR_MASK;
		port1_cfg_b.cfgSIO = GPIO_PRT1->CFG_SIO;

		port1_cfg_b.sel0Active = baseHSIOM->PORT_SEL0;
		port1_cfg_b.sel1Active = baseHSIOM->PORT_SEL1;

		/* Port8 */
		portNum = ((uint32_t)(GPIO_PRT8)-GPIO_BASE) / GPIO_PRT_SECTION_SIZE;
		baseHSIOM = (HSIOM_PRT_Type*)(HSIOM_BASE + (HSIOM_PRT_SECTION_SIZE * portNum));

		port8_cfg_b.out = GPIO_PRT8->OUT;
		port8_cfg_b.cfg = GPIO_PRT8->CFG;
		port8_cfg_b.cfgIn = GPIO_PRT8->CFG_IN;
		port8_cfg_b.cfgOut = GPIO_PRT8->CFG_OUT;
		port8_cfg_b.intrCfg = GPIO_PRT8->INTR_CFG;
		port8_cfg_b.intrMask = GPIO_PRT8->INTR_MASK;
		port8_cfg_b.cfgSIO = GPIO_PRT8->CFG_SIO;

		port8_cfg_b.sel0Active = baseHSIOM->PORT_SEL0;
		port8_cfg_b.sel1Active = baseHSIOM->PORT_SEL1;

		/* Port 11 */
		portNum = ((uint32_t)(GPIO_PRT11)-GPIO_BASE) / GPIO_PRT_SECTION_SIZE;
		baseHSIOM = (HSIOM_PRT_Type*)(HSIOM_BASE + (HSIOM_PRT_SECTION_SIZE * portNum));

		port11_cfg_b.out = GPIO_PRT11->OUT;
		port11_cfg_b.cfg = GPIO_PRT11->CFG;
		port11_cfg_b.cfgIn = GPIO_PRT11->CFG_IN;
		port11_cfg_b.cfgOut = GPIO_PRT11->CFG_OUT;
		port11_cfg_b.intrCfg = GPIO_PRT11->INTR_CFG;
		port11_cfg_b.intrMask = GPIO_PRT11->INTR_MASK;
		port11_cfg_b.cfgSIO = GPIO_PRT11->CFG_SIO;

		port11_cfg_b.sel0Active = baseHSIOM->PORT_SEL0;
		port11_cfg_b.sel1Active = baseHSIOM->PORT_SEL1;

		/* Port 12 */
		portNum = ((uint32_t)(GPIO_PRT12)-GPIO_BASE) / GPIO_PRT_SECTION_SIZE;
		baseHSIOM = (HSIOM_PRT_Type*)(HSIOM_BASE + (HSIOM_PRT_SECTION_SIZE * portNum));

		port12_cfg_b.out = GPIO_PRT1->OUT;
		port12_cfg_b.cfg = GPIO_PRT1->CFG;
		port12_cfg_b.cfgIn = GPIO_PRT1->CFG_IN;
		port12_cfg_b.cfgOut = GPIO_PRT1->CFG_OUT;
		port12_cfg_b.intrCfg = GPIO_PRT1->INTR_CFG;
		port12_cfg_b.intrMask = GPIO_PRT1->INTR_MASK;
		port12_cfg_b.cfgSIO = GPIO_PRT1->CFG_SIO;

		port12_cfg_b.sel0Active = baseHSIOM->PORT_SEL0;
		port12_cfg_b.sel1Active = baseHSIOM->PORT_SEL1;

		/* Clock registers */
		clkReg1 = SRSS->CLK_PATH_SELECT[2u];
		clkReg2 = SRSS->CLK_ROOT_SELECT[0u];
		clkReg3 = SRSS->CLK_ROOT_SELECT[1u];
		clkReg4 = SRSS->CLK_ROOT_SELECT[2u];
	}
}

/* [] END OF FILE */
