/***************************************************************************//**
* \file cyreg_cxpi.h
*
* \brief
* CXPI register definition header
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

#ifndef _CYREG_CXPI_H_
#define _CYREG_CXPI_H_

#include "cyip_cxpi.h"

/**
  * \brief CXPI channel structure (CXPI_CH0)
  */
#define CYREG_CXPI0_CH0_CTL0            ((volatile un_CXPI_CH_CTL0_t*) 0x40518000UL)
#define CYREG_CXPI0_CH0_CTL1            ((volatile un_CXPI_CH_CTL1_t*) 0x40518004UL)
#define CYREG_CXPI0_CH0_CTL2            ((volatile un_CXPI_CH_CTL2_t*) 0x40518008UL)
#define CYREG_CXPI0_CH0_STATUS          ((volatile un_CXPI_CH_STATUS_t*) 0x4051800CUL)
#define CYREG_CXPI0_CH0_CMD             ((volatile un_CXPI_CH_CMD_t*) 0x40518010UL)
#define CYREG_CXPI0_CH0_TX_RX_STATUS    ((volatile un_CXPI_CH_TX_RX_STATUS_t*) 0x40518040UL)
#define CYREG_CXPI0_CH0_TXPID_FI        ((volatile un_CXPI_CH_TXPID_FI_t*) 0x40518050UL)
#define CYREG_CXPI0_CH0_RXPID_FI        ((volatile un_CXPI_CH_RXPID_FI_t*) 0x40518054UL)
#define CYREG_CXPI0_CH0_CRC             ((volatile un_CXPI_CH_CRC_t*) 0x40518058UL)
#define CYREG_CXPI0_CH0_TX_FIFO_CTL     ((volatile un_CXPI_CH_TX_FIFO_CTL_t*) 0x40518080UL)
#define CYREG_CXPI0_CH0_TX_FIFO_STATUS  ((volatile un_CXPI_CH_TX_FIFO_STATUS_t*) 0x40518084UL)
#define CYREG_CXPI0_CH0_TX_FIFO_WR      ((volatile un_CXPI_CH_TX_FIFO_WR_t*) 0x40518088UL)
#define CYREG_CXPI0_CH0_RX_FIFO_CTL     ((volatile un_CXPI_CH_RX_FIFO_CTL_t*) 0x405180A0UL)
#define CYREG_CXPI0_CH0_RX_FIFO_STATUS  ((volatile un_CXPI_CH_RX_FIFO_STATUS_t*) 0x405180A4UL)
#define CYREG_CXPI0_CH0_RX_FIFO_RD      ((volatile un_CXPI_CH_RX_FIFO_RD_t*) 0x405180A8UL)
#define CYREG_CXPI0_CH0_RX_FIFO_RD_SILENT ((volatile un_CXPI_CH_RX_FIFO_RD_SILENT_t*) 0x405180ACUL)
#define CYREG_CXPI0_CH0_INTR            ((volatile un_CXPI_CH_INTR_t*) 0x405180C0UL)
#define CYREG_CXPI0_CH0_INTR_SET        ((volatile un_CXPI_CH_INTR_SET_t*) 0x405180C4UL)
#define CYREG_CXPI0_CH0_INTR_MASK       ((volatile un_CXPI_CH_INTR_MASK_t*) 0x405180C8UL)
#define CYREG_CXPI0_CH0_INTR_MASKED     ((volatile un_CXPI_CH_INTR_MASKED_t*) 0x405180CCUL)

/**
  * \brief CXPI channel structure (CXPI_CH1)
  */
#define CYREG_CXPI0_CH1_CTL0            ((volatile un_CXPI_CH_CTL0_t*) 0x40518100UL)
#define CYREG_CXPI0_CH1_CTL1            ((volatile un_CXPI_CH_CTL1_t*) 0x40518104UL)
#define CYREG_CXPI0_CH1_CTL2            ((volatile un_CXPI_CH_CTL2_t*) 0x40518108UL)
#define CYREG_CXPI0_CH1_STATUS          ((volatile un_CXPI_CH_STATUS_t*) 0x4051810CUL)
#define CYREG_CXPI0_CH1_CMD             ((volatile un_CXPI_CH_CMD_t*) 0x40518110UL)
#define CYREG_CXPI0_CH1_TX_RX_STATUS    ((volatile un_CXPI_CH_TX_RX_STATUS_t*) 0x40518140UL)
#define CYREG_CXPI0_CH1_TXPID_FI        ((volatile un_CXPI_CH_TXPID_FI_t*) 0x40518150UL)
#define CYREG_CXPI0_CH1_RXPID_FI        ((volatile un_CXPI_CH_RXPID_FI_t*) 0x40518154UL)
#define CYREG_CXPI0_CH1_CRC             ((volatile un_CXPI_CH_CRC_t*) 0x40518158UL)
#define CYREG_CXPI0_CH1_TX_FIFO_CTL     ((volatile un_CXPI_CH_TX_FIFO_CTL_t*) 0x40518180UL)
#define CYREG_CXPI0_CH1_TX_FIFO_STATUS  ((volatile un_CXPI_CH_TX_FIFO_STATUS_t*) 0x40518184UL)
#define CYREG_CXPI0_CH1_TX_FIFO_WR      ((volatile un_CXPI_CH_TX_FIFO_WR_t*) 0x40518188UL)
#define CYREG_CXPI0_CH1_RX_FIFO_CTL     ((volatile un_CXPI_CH_RX_FIFO_CTL_t*) 0x405181A0UL)
#define CYREG_CXPI0_CH1_RX_FIFO_STATUS  ((volatile un_CXPI_CH_RX_FIFO_STATUS_t*) 0x405181A4UL)
#define CYREG_CXPI0_CH1_RX_FIFO_RD      ((volatile un_CXPI_CH_RX_FIFO_RD_t*) 0x405181A8UL)
#define CYREG_CXPI0_CH1_RX_FIFO_RD_SILENT ((volatile un_CXPI_CH_RX_FIFO_RD_SILENT_t*) 0x405181ACUL)
#define CYREG_CXPI0_CH1_INTR            ((volatile un_CXPI_CH_INTR_t*) 0x405181C0UL)
#define CYREG_CXPI0_CH1_INTR_SET        ((volatile un_CXPI_CH_INTR_SET_t*) 0x405181C4UL)
#define CYREG_CXPI0_CH1_INTR_MASK       ((volatile un_CXPI_CH_INTR_MASK_t*) 0x405181C8UL)
#define CYREG_CXPI0_CH1_INTR_MASKED     ((volatile un_CXPI_CH_INTR_MASKED_t*) 0x405181CCUL)

/**
  * \brief CXPI (CXPI0)
  */
#define CYREG_CXPI0_ERROR_CTL           ((volatile un_CXPI_ERROR_CTL_t*) 0x40510000UL)
#define CYREG_CXPI0_TEST_CTL            ((volatile un_CXPI_TEST_CTL_t*) 0x40510004UL)

#endif /* _CYREG_CXPI_H_ */


/* [] END OF FILE */
