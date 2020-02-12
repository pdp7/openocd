/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright (c) 2010 Keil - An ARM Company. All rights reserved.     */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Flash Programming Functions adapted                   */
/*               for New Device 256kB Flash                            */
/*                                                                     */
/***********************************************************************/

#include "DefineMXS40.h"
#include "FlashOS.h" /* FlashOS Structures*/
#include "cy_debug/cy_debug.h"
#include "cy_loader/cy_loader_base.h"
#include "cy_loader/cy_loader_smif.h"
#include "device_header.h"
#include "loader.h"

#define CY_GET_REG32(addr) (*((const volatile uint32_t *)(addr)))

int Init(unsigned long adr, unsigned long clk, unsigned long fnc) {
	backRestoreCnfg(false);
	initHWSMIF();
	Loader_SMIF_Init_XIP(adr);
	return (0);
}

int UnInit(unsigned long fnc) {
	//	return (0);

	Loader_SMIF_Deinit();
	backRestoreCnfg(true);
	return (0);
}

int EraseSector(unsigned long adr) {
	//	return (0);
	return Loader_Erase(adr, SMIF_ERASE_BLOCK);
}

int ProgramPage(unsigned long adr, unsigned long sz, unsigned char *buf) {
	//	return (0);
	return Loader_Program(adr, 0, (uint8_t *)buf, sz);  // Finished without Errors
}
