/***************************************************************************//**
* \file cyreg_smartio.h
*
* \brief
* SMARTIO register definition header
*
* \note
* Generator version: 1.4.0.1252
* Database revision: TVIIC2D6M_CFR
*
********************************************************************************
* \copyright
* Copyright 2016-2019, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef _CYREG_SMARTIO_H_
#define _CYREG_SMARTIO_H_

#include "cyip_smartio_v4.h"

/**
  * \brief Programmable IO port registers (SMARTIO_PRT7)
  */
#define CYREG_SMARTIO_PRT7_CTL          ((volatile un_SMARTIO_PRT_CTL_t*) 0x40320700UL)
#define CYREG_SMARTIO_PRT7_SYNC_CTL     ((volatile un_SMARTIO_PRT_SYNC_CTL_t*) 0x40320710UL)
#define CYREG_SMARTIO_PRT7_LUT_SEL0     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x40320720UL)
#define CYREG_SMARTIO_PRT7_LUT_SEL1     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x40320724UL)
#define CYREG_SMARTIO_PRT7_LUT_SEL2     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x40320728UL)
#define CYREG_SMARTIO_PRT7_LUT_SEL3     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x4032072CUL)
#define CYREG_SMARTIO_PRT7_LUT_SEL4     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x40320730UL)
#define CYREG_SMARTIO_PRT7_LUT_SEL5     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x40320734UL)
#define CYREG_SMARTIO_PRT7_LUT_SEL6     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x40320738UL)
#define CYREG_SMARTIO_PRT7_LUT_SEL7     ((volatile un_SMARTIO_PRT_LUT_SEL_t*) 0x4032073CUL)
#define CYREG_SMARTIO_PRT7_LUT_CTL0     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x40320740UL)
#define CYREG_SMARTIO_PRT7_LUT_CTL1     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x40320744UL)
#define CYREG_SMARTIO_PRT7_LUT_CTL2     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x40320748UL)
#define CYREG_SMARTIO_PRT7_LUT_CTL3     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x4032074CUL)
#define CYREG_SMARTIO_PRT7_LUT_CTL4     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x40320750UL)
#define CYREG_SMARTIO_PRT7_LUT_CTL5     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x40320754UL)
#define CYREG_SMARTIO_PRT7_LUT_CTL6     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x40320758UL)
#define CYREG_SMARTIO_PRT7_LUT_CTL7     ((volatile un_SMARTIO_PRT_LUT_CTL_t*) 0x4032075CUL)
#define CYREG_SMARTIO_PRT7_DU_SEL       ((volatile un_SMARTIO_PRT_DU_SEL_t*) 0x403207C0UL)
#define CYREG_SMARTIO_PRT7_DU_CTL       ((volatile un_SMARTIO_PRT_DU_CTL_t*) 0x403207C4UL)
#define CYREG_SMARTIO_PRT7_DATA         ((volatile un_SMARTIO_PRT_DATA_t*) 0x403207F0UL)

#endif /* _CYREG_SMARTIO_H_ */


/* [] END OF FILE */
