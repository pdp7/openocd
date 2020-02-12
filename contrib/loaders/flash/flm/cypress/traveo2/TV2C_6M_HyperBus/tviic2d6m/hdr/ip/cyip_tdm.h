/***************************************************************************//**
* \file cyip_tdm.h
*
* \brief
* TDM IP definitions
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

#ifndef _CYIP_TDM_H_
#define _CYIP_TDM_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     TDM
*******************************************************************************/

#define TDM_TDM_STRUCT_TDM_TX_STRUCT_SECTION_SIZE 0x00000100UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_SECTION_SIZE 0x00000100UL
#define TDM_TDM_STRUCT_SECTION_SIZE             0x00000200UL
#define TDM_SECTION_SIZE                        0x00010000UL

/**
  * \brief TX control (TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL_field {
  uint32_t                         u4WORD_SIZE:4;
  uint32_t                         :8;
  uint32_t                         u2FORMAT:2;
  uint32_t                         :2;
  uint32_t                         u1MS:1;
  uint32_t                         :14;
  uint32_t                         u1ENABLED:1;
} stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL_t;

/**
  * \brief TX interface control (TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_field {
  uint32_t                         u8CLOCK_DIV:8;
  uint32_t                         u3CLOCK_SEL:3;
  uint32_t                         :1;
  uint32_t                         u1SCK_POLARITY:1;
  uint32_t                         u1FSYNC_POLARITY:1;
  uint32_t                         :1;
  uint32_t                         u1FSYNC_FORMAT:1;
  uint32_t                         u5CH_NR:5;
  uint32_t                         :3;
  uint32_t                         u5CH_SIZE:5;
  uint32_t                         :3;
} stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_t;

/**
  * \brief TX channel control (TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CH_CTL)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CH_CTL_field {
  uint32_t                         u32CH_EN:32;
} stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CH_CTL_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CH_CTL {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CH_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CH_CTL_t;

/**
  * \brief TX test control (TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_TEST_CTL)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_TEST_CTL_field {
  uint32_t                         :31;
  uint32_t                         u1ENABLED:1;
} stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_TEST_CTL_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_TEST_CTL {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_TEST_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_TEST_CTL_t;

/**
  * \brief TX FIFO control (TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_field {
  uint32_t                         u7TRIGGER_LEVEL:7;
  uint32_t                         :9;
  uint32_t                         u1MUTE:1;
  uint32_t                         u1FREEZE:1;
  uint32_t                         u1ACTIVE:1;
  uint32_t                         u1REPLAY:1;
  uint32_t                         :12;
} stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_t;

/**
  * \brief TX FIFO status (TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_STATUS)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_STATUS_field {
  uint32_t                         u8USED:8;
  uint32_t                         :8;
  uint32_t                         u7RD_PTR:7;
  uint32_t                         :1;
  uint32_t                         u7WR_PTR:7;
} stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_STATUS_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_STATUS {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_STATUS_t;

/**
  * \brief TX FIFO write (TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_WR)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_WR_field {
  uint32_t                         u32DATA:32;
} stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_WR_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_WR {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_WR_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_WR_t;

/**
  * \brief Interrupt (TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_t;

/**
  * \brief Interrupt set (TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_SET)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_SET_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_SET_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_SET {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_SET_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_SET_t;

/**
  * \brief Interrupt mask (TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASK)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASK_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASK_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASK {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASK_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASK_t;

/**
  * \brief Interrupt masked (TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASKED)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASKED_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASKED_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASKED {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASKED_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASKED_t;



/**
  * \brief RX control (TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_field {
  uint32_t                         u4WORD_SIZE:4;
  uint32_t                         :4;
  uint32_t                         u1WORD_SIGN_EXTEND:1;
  uint32_t                         :3;
  uint32_t                         u2FORMAT:2;
  uint32_t                         :2;
  uint32_t                         u1MS:1;
  uint32_t                         :14;
  uint32_t                         u1ENABLED:1;
} stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_t;

/**
  * \brief RX interface control (TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_field {
  uint32_t                         u8CLOCK_DIV:8;
  uint32_t                         u3CLOCK_SEL:3;
  uint32_t                         :1;
  uint32_t                         u1SCK_POLARITY:1;
  uint32_t                         u1FSYNC_POLARITY:1;
  uint32_t                         u1LATE_SAMPLE:1;
  uint32_t                         u1FSYNC_FORMAT:1;
  uint32_t                         u5CH_NR:5;
  uint32_t                         :3;
  uint32_t                         u5CH_SIZE:5;
  uint32_t                         :3;
} stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_t;

/**
  * \brief RX channel control (TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CH_CTL)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CH_CTL_field {
  uint32_t                         u32CH_EN:32;
} stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CH_CTL_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CH_CTL {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CH_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CH_CTL_t;

/**
  * \brief RX test control (TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_TEST_CTL)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_TEST_CTL_field {
  uint32_t                         :31;
  uint32_t                         u1ENABLED:1;
} stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_TEST_CTL_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_TEST_CTL {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_TEST_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_TEST_CTL_t;

/**
  * \brief RX FIFO control (TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_CTL)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_CTL_field {
  uint32_t                         u7TRIGGER_LEVEL:7;
  uint32_t                         :10;
  uint32_t                         u1FREEZE:1;
  uint32_t                         u1ACTIVE:1;
  uint32_t                         :13;
} stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_CTL_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_CTL {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_CTL_t;

/**
  * \brief RX FIFO status (TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_STATUS)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_STATUS_field {
  uint32_t                         u8USED:8;
  uint32_t                         :8;
  uint32_t                         u7RD_PTR:7;
  uint32_t                         :1;
  uint32_t                         u7WR_PTR:7;
} stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_STATUS_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_STATUS {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_STATUS_t;

/**
  * \brief RX FIFO read (TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_RD)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_RD_field {
  uint32_t                         u32DATA:32;
} stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_RD_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_RD {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_RD_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_RD_t;

/**
  * \brief RX FIFO silent read (TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_RD_SILENT)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_RD_SILENT_field {
  uint32_t                         u32DATA:32;
} stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_RD_SILENT_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_RD_SILENT {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_RD_SILENT_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_RD_SILENT_t;

/**
  * \brief Interrupt (TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_OVERFLOW:1;
  uint32_t                         :23;
} stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_t;

/**
  * \brief Interrupt set (TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_SET)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_SET_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_OVERFLOW:1;
  uint32_t                         :23;
} stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_SET_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_SET {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_SET_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_SET_t;

/**
  * \brief Interrupt mask (TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASK)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASK_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_OVERFLOW:1;
  uint32_t                         :23;
} stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASK_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASK {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASK_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASK_t;

/**
  * \brief Interrupt masked (TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASKED)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASKED_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_OVERFLOW:1;
  uint32_t                         :23;
} stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASKED_field_t;

typedef union un_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASKED {
  uint32_t                         u32Register;
  stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASKED_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASKED_t;



/**
  * \brief TDM TX structure (TDM_TDM_STRUCT_TDM_TX_STRUCT)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_TX_STRUCT {
  un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL_t unTX_CTL;   /*!< 0x00000000 TX control */
  uint32_t                         au32Reserved[3];
  un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_t unTX_IF_CTL; /*!< 0x00000010 TX interface control */
  un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CH_CTL_t unTX_CH_CTL; /*!< 0x00000014 TX channel control */
  uint32_t                         au32Reserved1[2];
  un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_TEST_CTL_t unTX_TEST_CTL; /*!< 0x00000020 TX test control */
  uint32_t                         au32Reserved2[23];
  un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_t unTX_FIFO_CTL; /*!< 0x00000080 TX FIFO control */
  un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_STATUS_t unTX_FIFO_STATUS; /*!< 0x00000084 TX FIFO status */
  un_TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_WR_t unTX_FIFO_WR; /*!< 0x00000088 TX FIFO write */
  uint32_t                         au32Reserved3[13];
  un_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_t unINTR_TX; /*!< 0x000000C0 Interrupt */
  un_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_SET_t unINTR_TX_SET; /*!< 0x000000C4 Interrupt set */
  un_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASK_t unINTR_TX_MASK; /*!< 0x000000C8 Interrupt mask */
  un_TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASKED_t unINTR_TX_MASKED; /*!< 0x000000CC Interrupt masked */
  uint32_t                         au32Reserved4[12];
} stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t;                  /*!< Size = 256 (0x100) */

/**
  * \brief TDM RX structure (TDM_TDM_STRUCT_TDM_RX_STRUCT)
  */
typedef struct stc_TDM_TDM_STRUCT_TDM_RX_STRUCT {
  un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_t unRX_CTL;   /*!< 0x00000000 RX control */
  uint32_t                         au32Reserved[3];
  un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_t unRX_IF_CTL; /*!< 0x00000010 RX interface control */
  un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CH_CTL_t unRX_CH_CTL; /*!< 0x00000014 RX channel control */
  uint32_t                         au32Reserved1[2];
  un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_TEST_CTL_t unRX_TEST_CTL; /*!< 0x00000020 RX test control */
  uint32_t                         au32Reserved2[23];
  un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_CTL_t unRX_FIFO_CTL; /*!< 0x00000080 RX FIFO control */
  un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_STATUS_t unRX_FIFO_STATUS; /*!< 0x00000084 RX FIFO status */
  un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_RD_t unRX_FIFO_RD; /*!< 0x00000088 RX FIFO read */
  un_TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_RD_SILENT_t unRX_FIFO_RD_SILENT; /*!< 0x0000008C RX FIFO silent read */
  uint32_t                         au32Reserved3[12];
  un_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_t unINTR_RX; /*!< 0x000000C0 Interrupt */
  un_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_SET_t unINTR_RX_SET; /*!< 0x000000C4 Interrupt set */
  un_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASK_t unINTR_RX_MASK; /*!< 0x000000C8 Interrupt mask */
  un_TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASKED_t unINTR_RX_MASKED; /*!< 0x000000CC Interrupt masked */
  uint32_t                         au32Reserved4[12];
} stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t;                  /*!< Size = 256 (0x100) */

/**
  * \brief TDM structure (TDM_TDM_STRUCT)
  */
typedef struct stc_TDM_TDM_STRUCT {
  stc_TDM_TDM_STRUCT_TDM_TX_STRUCT_t TDM_TX_STRUCT;    /*!< 0x00000000 TDM TX structure */
  stc_TDM_TDM_STRUCT_TDM_RX_STRUCT_t TDM_RX_STRUCT;    /*!< 0x00000100 TDM RX structure */
} stc_TDM_TDM_STRUCT_t;                                /*!< Size = 512 (0x200) */

/**
  * \brief TDM (TDM)
  */
typedef struct stc_TDM {
  uint32_t                         au32Reserved[8192];
  stc_TDM_TDM_STRUCT_t             TDM_STRUCT[4];      /*!< 0x00008000 TDM structure */
} stc_TDM_t;                                           /*!< Size = 34816 (0x8800) */


/* TDM_TDM_STRUCT_TDM_TX_STRUCT.TX_CTL */
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL_WORD_SIZE_Pos 0UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL_WORD_SIZE_Msk 0xFUL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL_FORMAT_Pos 12UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL_FORMAT_Msk 0x3000UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL_MS_Pos 16UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL_MS_Msk 0x10000UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL_ENABLED_Pos 31UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CTL_ENABLED_Msk 0x80000000UL
/* TDM_TDM_STRUCT_TDM_TX_STRUCT.TX_IF_CTL */
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_CLOCK_DIV_Pos 0UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_CLOCK_DIV_Msk 0xFFUL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_CLOCK_SEL_Pos 8UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_CLOCK_SEL_Msk 0x700UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_SCK_POLARITY_Pos 12UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_SCK_POLARITY_Msk 0x1000UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_FSYNC_POLARITY_Pos 13UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_FSYNC_POLARITY_Msk 0x2000UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_FSYNC_FORMAT_Pos 15UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_FSYNC_FORMAT_Msk 0x8000UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_CH_NR_Pos 16UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_CH_NR_Msk 0x1F0000UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_CH_SIZE_Pos 24UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_IF_CTL_CH_SIZE_Msk 0x1F000000UL
/* TDM_TDM_STRUCT_TDM_TX_STRUCT.TX_CH_CTL */
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CH_CTL_CH_EN_Pos 0UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_CH_CTL_CH_EN_Msk 0xFFFFFFFFUL
/* TDM_TDM_STRUCT_TDM_TX_STRUCT.TX_TEST_CTL */
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_TEST_CTL_ENABLED_Pos 31UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_TEST_CTL_ENABLED_Msk 0x80000000UL
/* TDM_TDM_STRUCT_TDM_TX_STRUCT.TX_FIFO_CTL */
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_TRIGGER_LEVEL_Pos 0UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_TRIGGER_LEVEL_Msk 0x7FUL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_MUTE_Pos 16UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_MUTE_Msk 0x10000UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_FREEZE_Pos 17UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_FREEZE_Msk 0x20000UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_ACTIVE_Pos 18UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_ACTIVE_Msk 0x40000UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_REPLAY_Pos 19UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_REPLAY_Msk 0x80000UL
/* TDM_TDM_STRUCT_TDM_TX_STRUCT.TX_FIFO_STATUS */
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_STATUS_USED_Pos 0UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_STATUS_USED_Msk 0xFFUL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_STATUS_RD_PTR_Pos 16UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_STATUS_RD_PTR_Msk 0x7F0000UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_STATUS_WR_PTR_Pos 24UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_STATUS_WR_PTR_Msk 0x7F000000UL
/* TDM_TDM_STRUCT_TDM_TX_STRUCT.TX_FIFO_WR */
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_WR_DATA_Pos 0UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_WR_DATA_Msk 0xFFFFFFFFUL
/* TDM_TDM_STRUCT_TDM_TX_STRUCT.INTR_TX */
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_FIFO_TRIGGER_Pos 0UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_FIFO_TRIGGER_Msk 0x1UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_FIFO_OVERFLOW_Pos 1UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_FIFO_OVERFLOW_Msk 0x2UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_FIFO_UNDERFLOW_Pos 2UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_FIFO_UNDERFLOW_Msk 0x4UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_IF_UNDERFLOW_Pos 8UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_IF_UNDERFLOW_Msk 0x100UL
/* TDM_TDM_STRUCT_TDM_TX_STRUCT.INTR_TX_SET */
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_SET_FIFO_TRIGGER_Pos 0UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_SET_FIFO_TRIGGER_Msk 0x1UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_SET_FIFO_OVERFLOW_Pos 1UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_SET_FIFO_OVERFLOW_Msk 0x2UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_SET_FIFO_UNDERFLOW_Pos 2UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_SET_FIFO_UNDERFLOW_Msk 0x4UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_SET_IF_UNDERFLOW_Pos 8UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_SET_IF_UNDERFLOW_Msk 0x100UL
/* TDM_TDM_STRUCT_TDM_TX_STRUCT.INTR_TX_MASK */
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASK_FIFO_TRIGGER_Pos 0UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASK_FIFO_TRIGGER_Msk 0x1UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASK_FIFO_OVERFLOW_Pos 1UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASK_FIFO_OVERFLOW_Msk 0x2UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASK_FIFO_UNDERFLOW_Pos 2UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASK_FIFO_UNDERFLOW_Msk 0x4UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASK_IF_UNDERFLOW_Pos 8UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASK_IF_UNDERFLOW_Msk 0x100UL
/* TDM_TDM_STRUCT_TDM_TX_STRUCT.INTR_TX_MASKED */
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASKED_FIFO_TRIGGER_Pos 0UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASKED_FIFO_TRIGGER_Msk 0x1UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASKED_FIFO_OVERFLOW_Pos 1UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASKED_FIFO_OVERFLOW_Msk 0x2UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASKED_FIFO_UNDERFLOW_Pos 2UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASKED_FIFO_UNDERFLOW_Msk 0x4UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASKED_IF_UNDERFLOW_Pos 8UL
#define TDM_TDM_STRUCT_TDM_TX_STRUCT_INTR_TX_MASKED_IF_UNDERFLOW_Msk 0x100UL


/* TDM_TDM_STRUCT_TDM_RX_STRUCT.RX_CTL */
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_WORD_SIZE_Pos 0UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_WORD_SIZE_Msk 0xFUL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_WORD_SIGN_EXTEND_Pos 8UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_WORD_SIGN_EXTEND_Msk 0x100UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_FORMAT_Pos 12UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_FORMAT_Msk 0x3000UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_MS_Pos 16UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_MS_Msk 0x10000UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_ENABLED_Pos 31UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CTL_ENABLED_Msk 0x80000000UL
/* TDM_TDM_STRUCT_TDM_RX_STRUCT.RX_IF_CTL */
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_CLOCK_DIV_Pos 0UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_CLOCK_DIV_Msk 0xFFUL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_CLOCK_SEL_Pos 8UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_CLOCK_SEL_Msk 0x700UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_SCK_POLARITY_Pos 12UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_SCK_POLARITY_Msk 0x1000UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_FSYNC_POLARITY_Pos 13UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_FSYNC_POLARITY_Msk 0x2000UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_LATE_SAMPLE_Pos 14UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_LATE_SAMPLE_Msk 0x4000UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_FSYNC_FORMAT_Pos 15UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_FSYNC_FORMAT_Msk 0x8000UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_CH_NR_Pos 16UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_CH_NR_Msk 0x1F0000UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_CH_SIZE_Pos 24UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_IF_CTL_CH_SIZE_Msk 0x1F000000UL
/* TDM_TDM_STRUCT_TDM_RX_STRUCT.RX_CH_CTL */
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CH_CTL_CH_EN_Pos 0UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_CH_CTL_CH_EN_Msk 0xFFFFFFFFUL
/* TDM_TDM_STRUCT_TDM_RX_STRUCT.RX_TEST_CTL */
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_TEST_CTL_ENABLED_Pos 31UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_TEST_CTL_ENABLED_Msk 0x80000000UL
/* TDM_TDM_STRUCT_TDM_RX_STRUCT.RX_FIFO_CTL */
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_CTL_TRIGGER_LEVEL_Pos 0UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_CTL_TRIGGER_LEVEL_Msk 0x7FUL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_CTL_FREEZE_Pos 17UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_CTL_FREEZE_Msk 0x20000UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_CTL_ACTIVE_Pos 18UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_CTL_ACTIVE_Msk 0x40000UL
/* TDM_TDM_STRUCT_TDM_RX_STRUCT.RX_FIFO_STATUS */
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_STATUS_USED_Pos 0UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_STATUS_USED_Msk 0xFFUL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_STATUS_RD_PTR_Pos 16UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_STATUS_RD_PTR_Msk 0x7F0000UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_STATUS_WR_PTR_Pos 24UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_STATUS_WR_PTR_Msk 0x7F000000UL
/* TDM_TDM_STRUCT_TDM_RX_STRUCT.RX_FIFO_RD */
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_RD_DATA_Pos 0UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_RD_DATA_Msk 0xFFFFFFFFUL
/* TDM_TDM_STRUCT_TDM_RX_STRUCT.RX_FIFO_RD_SILENT */
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_RD_SILENT_DATA_Pos 0UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_RD_SILENT_DATA_Msk 0xFFFFFFFFUL
/* TDM_TDM_STRUCT_TDM_RX_STRUCT.INTR_RX */
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_FIFO_TRIGGER_Pos 0UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_FIFO_TRIGGER_Msk 0x1UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_FIFO_OVERFLOW_Pos 1UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_FIFO_OVERFLOW_Msk 0x2UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_FIFO_UNDERFLOW_Pos 2UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_FIFO_UNDERFLOW_Msk 0x4UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_IF_OVERFLOW_Pos 8UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_IF_OVERFLOW_Msk 0x100UL
/* TDM_TDM_STRUCT_TDM_RX_STRUCT.INTR_RX_SET */
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_SET_FIFO_TRIGGER_Pos 0UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_SET_FIFO_TRIGGER_Msk 0x1UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_SET_FIFO_OVERFLOW_Pos 1UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_SET_FIFO_OVERFLOW_Msk 0x2UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_SET_FIFO_UNDERFLOW_Pos 2UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_SET_FIFO_UNDERFLOW_Msk 0x4UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_SET_IF_OVERFLOW_Pos 8UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_SET_IF_OVERFLOW_Msk 0x100UL
/* TDM_TDM_STRUCT_TDM_RX_STRUCT.INTR_RX_MASK */
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASK_FIFO_TRIGGER_Pos 0UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASK_FIFO_TRIGGER_Msk 0x1UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASK_FIFO_OVERFLOW_Pos 1UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASK_FIFO_OVERFLOW_Msk 0x2UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASK_FIFO_UNDERFLOW_Pos 2UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASK_FIFO_UNDERFLOW_Msk 0x4UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASK_IF_OVERFLOW_Pos 8UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASK_IF_OVERFLOW_Msk 0x100UL
/* TDM_TDM_STRUCT_TDM_RX_STRUCT.INTR_RX_MASKED */
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASKED_FIFO_TRIGGER_Pos 0UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASKED_FIFO_TRIGGER_Msk 0x1UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASKED_FIFO_OVERFLOW_Pos 1UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASKED_FIFO_OVERFLOW_Msk 0x2UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASKED_FIFO_UNDERFLOW_Pos 2UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASKED_FIFO_UNDERFLOW_Msk 0x4UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASKED_IF_OVERFLOW_Pos 8UL
#define TDM_TDM_STRUCT_TDM_RX_STRUCT_INTR_RX_MASKED_IF_OVERFLOW_Msk 0x100UL


#endif /* _CYIP_TDM_H_ */


/* [] END OF FILE */
