/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright (c) 2010 Keil - An ARM Company. All rights reserved.     */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for New Device Flash               */
/*                                                                     */
/***********************************************************************/

#include "FlashOS.h"        /* FlashOS Structures*/

#if defined (DUAL_QUAD_SPI)
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             /* Driver Version, do not modify! */
   "TraveoII DualQuadSPI",     /* Device Name */
   ONCHIP,                     /* Device Type */
   0x60000000,                 /* Device Start Address */
   0x04000000,                 /* Device Size in Bytes */
   512,                        /* Programming Page Size */
   0,                          /* Reserved, must be 0 */
   0xFF,                       /* Initial Content of Erased Memory */
   1000,                       /* Program Page Timeout 1000 mSec */
   1000,                       /* Erase Sector Timeout 3500 mSec */
   {{ 0x00002000, 0x000000, }, /* Set Sector size */
   { SECTOR_END }}
};
#elif defined (HYPER_FLASH)
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             /* Driver Version, do not modify! */
   "TraveoII HyperBus",        /* Device Name */
   ONCHIP,                     /* Device Type */
   0x60000000,                 /* Device Start Address */
   0x04000000,                 /* Device Size in Bytes */
   512,                        /* Programming Page Size */
   0,                          /* Reserved, must be 0 */
   0xFF,                       /* Initial Content of Erased Memory */
   1000,                       /* Program Page Timeout 1000 mSec */
   3500,                       /* Erase Sector Timeout 3500 mSec */
   {{ 0x00040000, 0x000000, }, /* Set Sector size */
   { SECTOR_END }}
};
#else
  #error "FlashDevice structure not known"
#endif
