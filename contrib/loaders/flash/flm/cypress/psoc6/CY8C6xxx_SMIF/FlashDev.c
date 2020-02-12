/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright (c) 2010 Keil - An ARM Company. All rights reserved.     */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.C:  Device Description for New Device Flash               */
/*                                                                     */
/***********************************************************************/

#include "FlashOS.h"        /* FlashOS Structures*/
#include "DefineMXS40.h"
#include "cy_common/cy_target.h"

#if defined(CY8C6x6_CM0p)
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             /* Driver Version, do not modify!*/
   "CY8C6x6_CM0p",       			 /* Device Name */
   ONCHIP,                     /* Device Type*/
   0x10000000,                 /* Device Start Address*/
   0x00080000,                 /* Device Size in Bytes (512kB)*/
   TARGET_FLASH_ROW_SIZE,                   /* Programming Page Size*/
   0,                          /* Reserved, must be 0*/
   0x00,                       /* Initial Content of Erased Memory*/
   10000,                      /* Program Page Timeout 10000 mSec*/
   40000,                      /* Erase Sector Timeout 40000 mSec*/

   /* Specify Size and Address of Sectors*/
   //0x00040000, 0x000000,         /* Sector Size  256kB (4 Sectors)*/
	{{ TARGET_FLASH_ROW_SIZE, 0x000000, },        /* Set Sector size = row size*/
   { SECTOR_END }}
};
#elif defined(CY8C6x6_CM4)
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             /* Driver Version, do not modify!*/
   "CY8C6x6_CM4",       			 /* Device Name */
   ONCHIP,                     /* Device Type*/
   0x10000000,                 /* Device Start Address*/
   0x08000000,                 /* Device Size in Bytes (512kB)*/
   TARGET_FLASH_ROW_SIZE,                   /* Programming Page Size*/
   0,                          /* Reserved, must be 0*/
   0x00,                       /* Initial Content of Erased Memory*/
   10000,                      /* Program Page Timeout 10000 mSec*/
   40000,                      /* Erase Sector Timeout 40000 mSec*/

   /* Specify Size and Address of Sectors*/
   //0x00040000, 0x000000,         /* Sector Size  256kB (4 Sectors)*/
	 TARGET_FLASH_ROW_SIZE, 0x000000,         /* Set Sector size = row size*/
   SECTOR_END
};
#elif defined(CY8C6xxx_SMIF)
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             /* Driver Version, do not modify!*/
   "CY8C6xxx_SMIF",       		 /* Device Name */
   EXTSPI,                     /* Device Type*/
   0x18000000,                 /* Device Start Address*/
   0x00400000,                 /* Device Size in Bytes*/
   0x1000,                      /* Programming Page Size*/
   0,                          /* Reserved, must be 0*/
   0xff,                       /* Initial Content of Erased Memory*/
   1000,                       /* Program Page Timeout 10000 mSec*/
   4000,                       /* Erase Sector Timeout 40000 mSec*/

   /* Specify Size and Address of Sectors*/
   //0x00040000, 0x000000,         /* Sector Size  256kB (4 Sectors)*/
	 SMIF_ERASE_BLOCK, 0x000000,         /* Set Sector size = row size*/
   SECTOR_END
};
#elif defined(CY8C6x7_CM4)
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             /* Driver Version, do not modify!*/
   "CY8C6x7_CM4",    					 /* Device Name */
   ONCHIP,                     /* Device Type*/
   0x10000000,                 /* Device Start Address*/
   0x00100000,                 /* Device Size in Bytes (1024kB)*/
   0x100,                      /* Programming Page Size*/
   0,                          /* Reserved, must be 0*/
   0x00,                       /* Initial Content of Erased Memory*/
   10000,                      /* Program Page Timeout 10000 mSec*/
   40000,                     	/* Erase Sector Timeout 40000 mSec*/

   /* Specify Size and Address of Sectors*/
   //0x00040000, 0x000000,         /* Sector Size  256kB (4 Sectors)*/
	 TARGET_FLASH_ROW_SIZE, 0x000000,         /* Set Sector size = row size*/
   SECTOR_END
};

#else
#error "Flash Device is not defined."
#endif
