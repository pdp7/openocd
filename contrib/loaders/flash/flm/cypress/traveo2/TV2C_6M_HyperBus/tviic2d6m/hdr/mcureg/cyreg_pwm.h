/***************************************************************************//**
* \file cyreg_pwm.h
*
* \brief
* PWM register definition header
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

#ifndef _CYREG_PWM_H_
#define _CYREG_PWM_H_

#include "cyip_pwm.h"

/**
  * \brief PWM structure (PWM_TX0)
  */
#define CYREG_PWM0_TX0_CTL              ((volatile un_PWM_TX_CTL_t*) 0x40838000UL)
#define CYREG_PWM0_TX0_IF_CTL           ((volatile un_PWM_TX_IF_CTL_t*) 0x40838010UL)
#define CYREG_PWM0_TX0_DOUBLE_CTL       ((volatile un_PWM_TX_DOUBLE_CTL_t*) 0x40838014UL)
#define CYREG_PWM0_TX0_GAIN_CTL         ((volatile un_PWM_TX_GAIN_CTL_t*) 0x40838018UL)
#define CYREG_PWM0_TX0_PWM_CTL0         ((volatile un_PWM_TX_PWM_CTL0_t*) 0x40838020UL)
#define CYREG_PWM0_TX0_PWM_CTL1         ((volatile un_PWM_TX_PWM_CTL1_t*) 0x40838024UL)
#define CYREG_PWM0_TX0_PWM_CTL2         ((volatile un_PWM_TX_PWM_CTL2_t*) 0x40838028UL)
#define CYREG_PWM0_TX0_PWM_CTL3         ((volatile un_PWM_TX_PWM_CTL3_t*) 0x4083802CUL)
#define CYREG_PWM0_TX0_TX_FIFO_CTL      ((volatile un_PWM_TX_TX_FIFO_CTL_t*) 0x40838080UL)
#define CYREG_PWM0_TX0_TX_FIFO_STATUS   ((volatile un_PWM_TX_TX_FIFO_STATUS_t*) 0x40838084UL)
#define CYREG_PWM0_TX0_TX_FIFO_WR       ((volatile un_PWM_TX_TX_FIFO_WR_t*) 0x40838088UL)
#define CYREG_PWM0_TX0_INTR_TX          ((volatile un_PWM_TX_INTR_TX_t*) 0x408380C0UL)
#define CYREG_PWM0_TX0_INTR_TX_SET      ((volatile un_PWM_TX_INTR_TX_SET_t*) 0x408380C4UL)
#define CYREG_PWM0_TX0_INTR_TX_MASK     ((volatile un_PWM_TX_INTR_TX_MASK_t*) 0x408380C8UL)
#define CYREG_PWM0_TX0_INTR_TX_MASKED   ((volatile un_PWM_TX_INTR_TX_MASKED_t*) 0x408380CCUL)

/**
  * \brief PWM structure (PWM_TX1)
  */
#define CYREG_PWM0_TX1_CTL              ((volatile un_PWM_TX_CTL_t*) 0x40838100UL)
#define CYREG_PWM0_TX1_IF_CTL           ((volatile un_PWM_TX_IF_CTL_t*) 0x40838110UL)
#define CYREG_PWM0_TX1_DOUBLE_CTL       ((volatile un_PWM_TX_DOUBLE_CTL_t*) 0x40838114UL)
#define CYREG_PWM0_TX1_GAIN_CTL         ((volatile un_PWM_TX_GAIN_CTL_t*) 0x40838118UL)
#define CYREG_PWM0_TX1_PWM_CTL0         ((volatile un_PWM_TX_PWM_CTL0_t*) 0x40838120UL)
#define CYREG_PWM0_TX1_PWM_CTL1         ((volatile un_PWM_TX_PWM_CTL1_t*) 0x40838124UL)
#define CYREG_PWM0_TX1_PWM_CTL2         ((volatile un_PWM_TX_PWM_CTL2_t*) 0x40838128UL)
#define CYREG_PWM0_TX1_PWM_CTL3         ((volatile un_PWM_TX_PWM_CTL3_t*) 0x4083812CUL)
#define CYREG_PWM0_TX1_TX_FIFO_CTL      ((volatile un_PWM_TX_TX_FIFO_CTL_t*) 0x40838180UL)
#define CYREG_PWM0_TX1_TX_FIFO_STATUS   ((volatile un_PWM_TX_TX_FIFO_STATUS_t*) 0x40838184UL)
#define CYREG_PWM0_TX1_TX_FIFO_WR       ((volatile un_PWM_TX_TX_FIFO_WR_t*) 0x40838188UL)
#define CYREG_PWM0_TX1_INTR_TX          ((volatile un_PWM_TX_INTR_TX_t*) 0x408381C0UL)
#define CYREG_PWM0_TX1_INTR_TX_SET      ((volatile un_PWM_TX_INTR_TX_SET_t*) 0x408381C4UL)
#define CYREG_PWM0_TX1_INTR_TX_MASK     ((volatile un_PWM_TX_INTR_TX_MASK_t*) 0x408381C8UL)
#define CYREG_PWM0_TX1_INTR_TX_MASKED   ((volatile un_PWM_TX_INTR_TX_MASKED_t*) 0x408381CCUL)

/**
  * \brief PWM (PWM0)
  */
#define CYREG_PWM0_CTL                  ((volatile un_PWM_CTL_t*) 0x40830000UL)
#define CYREG_PWM0_CTL_CLR              ((volatile un_PWM_CTL_CLR_t*) 0x40830004UL)
#define CYREG_PWM0_CTL_SET              ((volatile un_PWM_CTL_SET_t*) 0x40830008UL)

#endif /* _CYREG_PWM_H_ */


/* [] END OF FILE */
