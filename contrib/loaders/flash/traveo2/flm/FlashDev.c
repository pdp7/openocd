/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright (c) 2010 Keil - An ARM Company. All rights reserved.     */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for New Device Flash               */
/*                                                                     */
/***********************************************************************/

#include "FlashOS.h"        /* FlashOS Structures*/

#if defined (tviic2d6m) && defined (DUAL_QUAD_SPI)
__attribute__((used))
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             /* Driver Version, do not modify! */
   "TraveoII DualQuadSPI",     /* Device Name */
   ONCHIP,                     /* Device Type */
   0x60000000,                 /* Device Start Address */
   0x04000000,                 /* Device Size in Bytes (512kB) */
   512,                        /* Programming Page Size */
   0,                          /* Reserved, must be 0 */
   0xFF,                       /* Initial Content of Erased Memory */
   1000,                       /* Program Page Timeout 1000 mSec */
   120000,                     /* Erase Sector Timeout 4000 mSec */
   {{ 0x00080000, 0x000000, }, /* Set Sector size */
   { SECTOR_END }}
};
#elif defined (tviic2d6m) && defined (HYPER_FLASH)
__attribute__((used))
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             /* Driver Version, do not modify! */
   "TraveoII HyperBus",        /* Device Name */
   ONCHIP,                     /* Device Type */
   0x60000000,                 /* Device Start Address */
   0x04000000,                 /* Device Size in Bytes (512kB) */
   512,                        /* Programming Page Size */
   0,                          /* Reserved, must be 0 */
   0xFF,                       /* Initial Content of Erased Memory */
   1000,                       /* Program Page Timeout 1000 mSec */
   120000,                     /* Erase Sector Timeout 4000 mSec */
   {{ 0x00040000, 0x000000, }, /* Set Sector size */
   { SECTOR_END }}
};
#elif defined (tviic2d6m) &&  defined (SEMPER_FLASH)
__attribute__((used))
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             /* Driver Version, do not modify! */
   "TraveoII SemperFlash",     /* Device Name */
   ONCHIP,                     /* Device Type */
   0x60000000,                 /* Device Start Address */
   0x04000000,                 /* Device Size in Bytes (512kB) */
   256,                        /* Programming Page Size */
   0,                          /* Reserved, must be 0 */
   0xFF,                       /* Initial Content of Erased Memory */
   1000,                       /* Program Page Timeout 1000 mSec */
   120000,                     /* Erase Sector Timeout 4000 mSec */
   {{ 0x00040000, 0x000000, }, /* Set Sector size */
   { SECTOR_END }}
};
#elif (defined (tviibh8m) || defined (tviibh4m) ) && defined (DUAL_QUAD_SPI)
__attribute__((used))
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             /* Driver Version, do not modify! */
   "TraveoII DualQuadSPI",     /* Device Name */
   ONCHIP,                     /* Device Type */
   0x60000000,                 /* Device Start Address */
   0x04000000,                 /* Device Size in Bytes (512kB) */
   512,                        /* Programming Page Size */
   0,                          /* Reserved, must be 0 */
   0xFF,                       /* Initial Content of Erased Memory */
   1000,                       /* Program Page Timeout 1000 mSec */
   120000,                     /* Erase Sector Timeout 4000 mSec */
   {{ 0x00020000, 0x000000, }, /* Set Sector size */
   { SECTOR_END }}
};
#elif defined (tviibh8m) && defined (HYPER_FLASH)
__attribute__((used))
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             /* Driver Version, do not modify! */
   "TraveoII HyperBus",        /* Device Name */
   ONCHIP,                     /* Device Type */
   0x60000000,                 /* Device Start Address */
   0x04000000,                 /* Device Size in Bytes (512kB) */
   512,                        /* Programming Page Size */
   0,                          /* Reserved, must be 0 */
   0xFF,                       /* Initial Content of Erased Memory */
   1000,                       /* Program Page Timeout 1000 mSec */
   120000,                     /* Erase Sector Timeout 4000 mSec */
   {{ 0x00040000, 0x000000, }, /* Set Sector size */
   { SECTOR_END }}
};
#elif defined (HYPER_RAM)
// Nothing to include
#else
  #error "FlashDevice structure not known"
#endif
