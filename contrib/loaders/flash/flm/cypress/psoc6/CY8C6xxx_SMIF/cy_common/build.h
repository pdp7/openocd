/***************************************************************************//**
* \file build.h
* \version 1.0
*
* \brief
*  Project setup
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#ifndef BUILD_H
#define BUILD_H

/******************************************************************************
 * Preprocessor symbols/definitions
 ******************************************************************************/
/*
* BUILD_IDE_CREATOR or BUILD_IDE_uVISION or BUILD_IDE_IAR - unique for each IDE
* BUILD_ENABLE_LOADER_FLASH  - Enable Flash Loader
* BUILD_ENABLE_LOADER_SMIF   - Euild SMIF Loader
* MPN (e.g. CY8C637BZI_MD76) - Target device, used in cy_device_headers.h
*  to include propper device header. Already predefined for Creator.
* DEBUG_TEST - defines whether or not to include test application
* DEBUG_LOG - defines whether or not to include UART logging
* CY_TOC_PRESENT - needs to be defined to put TOC structure into Flash.
*  This is for user application only or for SMIF loader testing
*/


/******************************************************************************
 * Target device. Define only one.
 ******************************************************************************/
//#define BUILD_TARGET_CY8C6x6_M0
//#define BUILD_TARGET_CY8C6x6_M4
#define BUILD_TARGET_CY8C6x7_M0
//#define BUILD_TARGET_CY8C6x7_M4
//#define BUILD_TARGET_CY8C622PSVP_M0
//#define BUILD_TARGET_CY8C622PSVP_M4
#define BUILD_TARGET_SMIF
#define BUILD_ENABLE_LOADER_SMIF
//#define BUILD_ENABLE_LOADER_FLASH

/******************************************************************************
 * Project include directories
 ******************************************************************************/
/*
* Creator: "../../"
* uVision: "../../"
* IAR:
$TOOLKIT_DIR$/src/flashloader/framework2/
$PROJ_DIR$
$PROJ_DIR$/../../
$PROJ_DIR$/../../pdl/3.0.0/drivers/peripheral/
$PROJ_DIR$/../../pdl/3.0.0/devices/psoc6/psoc6ble/include/
$PROJ_DIR$/../../pdl/3.0.0/cmsis/include/
*/

/******************************************************************************
 * Project linker files
 ******************************************************************************/
/* Creator: default from pdl for both cores
*
* uVision:
* a) "..\..\cy_test\linker_uVision_loader.scat": Flash loader only without
*    test application
* b) "..\..\cy_test\linker_uVision_test_(cy8c6x7_cm0plus).scat": Test application,
*    but flash loader will not work due to absence of PrgCode, PrgData and DevDscr sections
*
* IAR:
* "$PROJ_DIR$\PSoC6FlashLoader.icf"
*/

#endif /*BUILD_H*/

/* [] END OF FILE */
