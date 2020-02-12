/***************************************************************************//**
* \file cyreg_dac.h
*
* \brief
* DAC register definition header
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

#ifndef _CYREG_DAC_H_
#define _CYREG_DAC_H_

#include "cyip_dac.h"

/**
  * \brief DAC (DAC)
  */
#define CYREG_DAC0_CTL                  ((volatile un_DAC_CTL_t*) 0x40840000UL)
#define CYREG_DAC0_IF_CTL               ((volatile un_DAC_IF_CTL_t*) 0x40840004UL)
#define CYREG_DAC0_COUNT                ((volatile un_DAC_COUNT_t*) 0x40840008UL)
#define CYREG_DAC0_STATUS               ((volatile un_DAC_STATUS_t*) 0x40840010UL)
#define CYREG_DAC0_TX_FIFO_CTL          ((volatile un_DAC_TX_FIFO_CTL_t*) 0x40840080UL)
#define CYREG_DAC0_TX_FIFO_STATUS       ((volatile un_DAC_TX_FIFO_STATUS_t*) 0x40840084UL)
#define CYREG_DAC0_TX_FIFO_WR           ((volatile un_DAC_TX_FIFO_WR_t*) 0x40840088UL)
#define CYREG_DAC0_INTR_TX              ((volatile un_DAC_INTR_TX_t*) 0x408400C0UL)
#define CYREG_DAC0_INTR_TX_SET          ((volatile un_DAC_INTR_TX_SET_t*) 0x408400C4UL)
#define CYREG_DAC0_INTR_TX_MASK         ((volatile un_DAC_INTR_TX_MASK_t*) 0x408400C8UL)
#define CYREG_DAC0_INTR_TX_MASKED       ((volatile un_DAC_INTR_TX_MASKED_t*) 0x408400CCUL)
#define CYREG_DAC0_TEST_CTL             ((volatile un_DAC_TEST_CTL_t*) 0x408400F0UL)
#define CYREG_DAC0_TEST_ANALOG_DATA     ((volatile un_DAC_TEST_ANALOG_DATA_t*) 0x408400F4UL)

#endif /* _CYREG_DAC_H_ */


/* [] END OF FILE */
