/***************************************************************************//**
* \file cyreg_lin.h
*
* \brief
* LIN register definition header
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

#ifndef _CYREG_LIN_H_
#define _CYREG_LIN_H_

#include "cyip_lin.h"

/**
  * \brief LIN channel structure (LIN_CH0)
  */
#define CYREG_LIN0_CH0_CTL0             ((volatile un_LIN_CH_CTL0_t*) 0x40508000UL)
#define CYREG_LIN0_CH0_CTL1             ((volatile un_LIN_CH_CTL1_t*) 0x40508004UL)
#define CYREG_LIN0_CH0_STATUS           ((volatile un_LIN_CH_STATUS_t*) 0x40508008UL)
#define CYREG_LIN0_CH0_CMD              ((volatile un_LIN_CH_CMD_t*) 0x40508010UL)
#define CYREG_LIN0_CH0_TX_RX_STATUS     ((volatile un_LIN_CH_TX_RX_STATUS_t*) 0x40508060UL)
#define CYREG_LIN0_CH0_PID_CHECKSUM     ((volatile un_LIN_CH_PID_CHECKSUM_t*) 0x40508080UL)
#define CYREG_LIN0_CH0_DATA0            ((volatile un_LIN_CH_DATA0_t*) 0x40508084UL)
#define CYREG_LIN0_CH0_DATA1            ((volatile un_LIN_CH_DATA1_t*) 0x40508088UL)
#define CYREG_LIN0_CH0_INTR             ((volatile un_LIN_CH_INTR_t*) 0x405080C0UL)
#define CYREG_LIN0_CH0_INTR_SET         ((volatile un_LIN_CH_INTR_SET_t*) 0x405080C4UL)
#define CYREG_LIN0_CH0_INTR_MASK        ((volatile un_LIN_CH_INTR_MASK_t*) 0x405080C8UL)
#define CYREG_LIN0_CH0_INTR_MASKED      ((volatile un_LIN_CH_INTR_MASKED_t*) 0x405080CCUL)

/**
  * \brief LIN channel structure (LIN_CH1)
  */
#define CYREG_LIN0_CH1_CTL0             ((volatile un_LIN_CH_CTL0_t*) 0x40508100UL)
#define CYREG_LIN0_CH1_CTL1             ((volatile un_LIN_CH_CTL1_t*) 0x40508104UL)
#define CYREG_LIN0_CH1_STATUS           ((volatile un_LIN_CH_STATUS_t*) 0x40508108UL)
#define CYREG_LIN0_CH1_CMD              ((volatile un_LIN_CH_CMD_t*) 0x40508110UL)
#define CYREG_LIN0_CH1_TX_RX_STATUS     ((volatile un_LIN_CH_TX_RX_STATUS_t*) 0x40508160UL)
#define CYREG_LIN0_CH1_PID_CHECKSUM     ((volatile un_LIN_CH_PID_CHECKSUM_t*) 0x40508180UL)
#define CYREG_LIN0_CH1_DATA0            ((volatile un_LIN_CH_DATA0_t*) 0x40508184UL)
#define CYREG_LIN0_CH1_DATA1            ((volatile un_LIN_CH_DATA1_t*) 0x40508188UL)
#define CYREG_LIN0_CH1_INTR             ((volatile un_LIN_CH_INTR_t*) 0x405081C0UL)
#define CYREG_LIN0_CH1_INTR_SET         ((volatile un_LIN_CH_INTR_SET_t*) 0x405081C4UL)
#define CYREG_LIN0_CH1_INTR_MASK        ((volatile un_LIN_CH_INTR_MASK_t*) 0x405081C8UL)
#define CYREG_LIN0_CH1_INTR_MASKED      ((volatile un_LIN_CH_INTR_MASKED_t*) 0x405081CCUL)

/**
  * \brief LIN (LIN0)
  */
#define CYREG_LIN0_ERROR_CTL            ((volatile un_LIN_ERROR_CTL_t*) 0x40500000UL)
#define CYREG_LIN0_TEST_CTL             ((volatile un_LIN_TEST_CTL_t*) 0x40500004UL)

#endif /* _CYREG_LIN_H_ */


/* [] END OF FILE */
