/***************************************************************************//**
* \file cyip_i2s.h
*
* \brief
* I2S IP definitions
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

#ifndef _CYIP_I2S_H_
#define _CYIP_I2S_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     I2S
*******************************************************************************/

#define I2S_I2S_STRUCT_I2S_TX_STRUCT_SECTION_SIZE 0x00000100UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_SECTION_SIZE 0x00000100UL
#define I2S_I2S_STRUCT_SECTION_SIZE             0x00000200UL
#define I2S_SECTION_SIZE                        0x00010000UL

/**
  * \brief TX control (I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_CTL)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_CTL_field {
  uint32_t                         u4WORD_SIZE:4;
  uint32_t                         :8;
  uint32_t                         u2FORMAT:2;
  uint32_t                         :2;
  uint32_t                         u1MS:1;
  uint32_t                         :14;
  uint32_t                         u1ENABLED:1;
} stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_CTL_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_CTL {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_CTL_t;

/**
  * \brief TX interface control (I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_field {
  uint32_t                         u8CLOCK_DIV:8;
  uint32_t                         u3CLOCK_SEL:3;
  uint32_t                         :1;
  uint32_t                         u1SCK_POLARITY:1;
  uint32_t                         u1WS_POLARITY:1;
  uint32_t                         :2;
  uint32_t                         u1CH0_EN:1;
  uint32_t                         u1CH1_EN:1;
  uint32_t                         :6;
  uint32_t                         u5CH_SIZE:5;
  uint32_t                         :3;
} stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_t;

/**
  * \brief TX test control (I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_TEST_CTL)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_TEST_CTL_field {
  uint32_t                         :31;
  uint32_t                         u1ENABLED:1;
} stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_TEST_CTL_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_TEST_CTL {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_TEST_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_TEST_CTL_t;

/**
  * \brief TX FIFO control (I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_CTL)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_CTL_field {
  uint32_t                         u6TRIGGER_LEVEL:6;
  uint32_t                         :10;
  uint32_t                         u1MUTE:1;
  uint32_t                         u1FREEZE:1;
  uint32_t                         u1ACTIVE:1;
  uint32_t                         u1REPLAY:1;
  uint32_t                         :12;
} stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_CTL_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_CTL {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_CTL_t;

/**
  * \brief TX FIFO status (I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_STATUS)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_STATUS_field {
  uint32_t                         u7USED:7;
  uint32_t                         :9;
  uint32_t                         u6RD_PTR:6;
  uint32_t                         :2;
  uint32_t                         u6WR_PTR:6;
  uint32_t                         :2;
} stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_STATUS_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_STATUS {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_STATUS_t;

/**
  * \brief TX FIFO write (I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_WR)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_WR_field {
  uint32_t                         u32DATA:32;
} stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_WR_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_WR {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_WR_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_WR_t;

/**
  * \brief Interrupt (I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_t;

/**
  * \brief Interrupt set (I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_SET)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_SET_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_SET_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_SET {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_SET_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_SET_t;

/**
  * \brief Interrupt mask (I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASK)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASK_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASK_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASK {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASK_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASK_t;

/**
  * \brief Interrupt masked (I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASKED)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASKED_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASKED_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASKED {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASKED_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASKED_t;



/**
  * \brief RX control (I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL_field {
  uint32_t                         u4WORD_SIZE:4;
  uint32_t                         :4;
  uint32_t                         u1WORD_SIGN_EXTEND:1;
  uint32_t                         :3;
  uint32_t                         u2FORMAT:2;
  uint32_t                         :2;
  uint32_t                         u1MS:1;
  uint32_t                         :14;
  uint32_t                         u1ENABLED:1;
} stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL_t;

/**
  * \brief RX interface control (I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_field {
  uint32_t                         u8CLOCK_DIV:8;
  uint32_t                         u3CLOCK_SEL:3;
  uint32_t                         :1;
  uint32_t                         u1SCK_POLARITY:1;
  uint32_t                         u1WS_POLARITY:1;
  uint32_t                         u1LATE_SAMPLE:1;
  uint32_t                         :1;
  uint32_t                         u1CH0_EN:1;
  uint32_t                         u1CH1_EN:1;
  uint32_t                         :6;
  uint32_t                         u5CH_SIZE:5;
  uint32_t                         :3;
} stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_t;

/**
  * \brief RX test control (I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_TEST_CTL)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_TEST_CTL_field {
  uint32_t                         :31;
  uint32_t                         u1ENABLED:1;
} stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_TEST_CTL_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_TEST_CTL {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_TEST_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_TEST_CTL_t;

/**
  * \brief RX FIFO control (I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_CTL)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_CTL_field {
  uint32_t                         u6TRIGGER_LEVEL:6;
  uint32_t                         :11;
  uint32_t                         u1FREEZE:1;
  uint32_t                         u1ACTIVE:1;
  uint32_t                         :13;
} stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_CTL_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_CTL {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_CTL_t;

/**
  * \brief RX FIFO status (I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_STATUS)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_STATUS_field {
  uint32_t                         u7USED:7;
  uint32_t                         :9;
  uint32_t                         u6RD_PTR:6;
  uint32_t                         :2;
  uint32_t                         u6WR_PTR:6;
  uint32_t                         :2;
} stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_STATUS_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_STATUS {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_STATUS_t;

/**
  * \brief RX FIFO read (I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_RD)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_RD_field {
  uint32_t                         u32DATA:32;
} stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_RD_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_RD {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_RD_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_RD_t;

/**
  * \brief RX FIFO silent read (I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_RD_SILENT)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_RD_SILENT_field {
  uint32_t                         u32DATA:32;
} stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_RD_SILENT_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_RD_SILENT {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_RD_SILENT_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_RD_SILENT_t;

/**
  * \brief Interrupt (I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_OVERFLOW:1;
  uint32_t                         :23;
} stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_t;

/**
  * \brief Interrupt set (I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_SET)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_SET_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_OVERFLOW:1;
  uint32_t                         :23;
} stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_SET_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_SET {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_SET_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_SET_t;

/**
  * \brief Interrupt mask (I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASK)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASK_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_OVERFLOW:1;
  uint32_t                         :23;
} stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASK_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASK {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASK_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASK_t;

/**
  * \brief Interrupt masked (I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASKED)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASKED_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_OVERFLOW:1;
  uint32_t                         :23;
} stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASKED_field_t;

typedef union un_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASKED {
  uint32_t                         u32Register;
  stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASKED_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASKED_t;



/**
  * \brief I2S TX structure (I2S_I2S_STRUCT_I2S_TX_STRUCT)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_TX_STRUCT {
  un_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_CTL_t unTX_CTL;   /*!< 0x00000000 TX control */
  uint32_t                         au32Reserved[3];
  un_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_t unTX_IF_CTL; /*!< 0x00000010 TX interface control */
  uint32_t                         au32Reserved1[3];
  un_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_TEST_CTL_t unTX_TEST_CTL; /*!< 0x00000020 TX test control */
  uint32_t                         au32Reserved2[23];
  un_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_CTL_t unTX_FIFO_CTL; /*!< 0x00000080 TX FIFO control */
  un_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_STATUS_t unTX_FIFO_STATUS; /*!< 0x00000084 TX FIFO status */
  un_I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_WR_t unTX_FIFO_WR; /*!< 0x00000088 TX FIFO write */
  uint32_t                         au32Reserved3[13];
  un_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_t unINTR_TX; /*!< 0x000000C0 Interrupt */
  un_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_SET_t unINTR_TX_SET; /*!< 0x000000C4 Interrupt set */
  un_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASK_t unINTR_TX_MASK; /*!< 0x000000C8 Interrupt mask */
  un_I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASKED_t unINTR_TX_MASKED; /*!< 0x000000CC Interrupt masked */
  uint32_t                         au32Reserved4[12];
} stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t;                  /*!< Size = 256 (0x100) */

/**
  * \brief I2S RX structure (I2S_I2S_STRUCT_I2S_RX_STRUCT)
  */
typedef struct stc_I2S_I2S_STRUCT_I2S_RX_STRUCT {
  un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL_t unRX_CTL;   /*!< 0x00000000 RX control */
  uint32_t                         au32Reserved[3];
  un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_t unRX_IF_CTL; /*!< 0x00000010 RX interface control */
  uint32_t                         au32Reserved1[3];
  un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_TEST_CTL_t unRX_TEST_CTL; /*!< 0x00000020 RX test control */
  uint32_t                         au32Reserved2[23];
  un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_CTL_t unRX_FIFO_CTL; /*!< 0x00000080 RX FIFO control */
  un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_STATUS_t unRX_FIFO_STATUS; /*!< 0x00000084 RX FIFO status */
  un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_RD_t unRX_FIFO_RD; /*!< 0x00000088 RX FIFO read */
  un_I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_RD_SILENT_t unRX_FIFO_RD_SILENT; /*!< 0x0000008C RX FIFO silent read */
  uint32_t                         au32Reserved3[12];
  un_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_t unINTR_RX; /*!< 0x000000C0 Interrupt */
  un_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_SET_t unINTR_RX_SET; /*!< 0x000000C4 Interrupt set */
  un_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASK_t unINTR_RX_MASK; /*!< 0x000000C8 Interrupt mask */
  un_I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASKED_t unINTR_RX_MASKED; /*!< 0x000000CC Interrupt masked */
  uint32_t                         au32Reserved4[12];
} stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t;                  /*!< Size = 256 (0x100) */

/**
  * \brief I2S structure (I2S_I2S_STRUCT)
  */
typedef struct stc_I2S_I2S_STRUCT {
  stc_I2S_I2S_STRUCT_I2S_TX_STRUCT_t I2S_TX_STRUCT;    /*!< 0x00000000 I2S TX structure */
  stc_I2S_I2S_STRUCT_I2S_RX_STRUCT_t I2S_RX_STRUCT;    /*!< 0x00000100 I2S RX structure */
} stc_I2S_I2S_STRUCT_t;                                /*!< Size = 512 (0x200) */

/**
  * \brief I2S (I2S)
  */
typedef struct stc_I2S {
  uint32_t                         au32Reserved[8192];
  stc_I2S_I2S_STRUCT_t             I2S_STRUCT[4];      /*!< 0x00008000 I2S structure */
} stc_I2S_t;                                           /*!< Size = 34816 (0x8800) */


/* I2S_I2S_STRUCT_I2S_TX_STRUCT.TX_CTL */
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_CTL_WORD_SIZE_Pos 0UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_CTL_WORD_SIZE_Msk 0xFUL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_CTL_FORMAT_Pos 12UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_CTL_FORMAT_Msk 0x3000UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_CTL_MS_Pos 16UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_CTL_MS_Msk 0x10000UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_CTL_ENABLED_Pos 31UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_CTL_ENABLED_Msk 0x80000000UL
/* I2S_I2S_STRUCT_I2S_TX_STRUCT.TX_IF_CTL */
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CLOCK_DIV_Pos 0UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CLOCK_DIV_Msk 0xFFUL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CLOCK_SEL_Pos 8UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CLOCK_SEL_Msk 0x700UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_SCK_POLARITY_Pos 12UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_SCK_POLARITY_Msk 0x1000UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_WS_POLARITY_Pos 13UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_WS_POLARITY_Msk 0x2000UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CH0_EN_Pos 16UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CH0_EN_Msk 0x10000UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CH1_EN_Pos 17UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CH1_EN_Msk 0x20000UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CH_SIZE_Pos 24UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_IF_CTL_CH_SIZE_Msk 0x1F000000UL
/* I2S_I2S_STRUCT_I2S_TX_STRUCT.TX_TEST_CTL */
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_TEST_CTL_ENABLED_Pos 31UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_TEST_CTL_ENABLED_Msk 0x80000000UL
/* I2S_I2S_STRUCT_I2S_TX_STRUCT.TX_FIFO_CTL */
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_CTL_TRIGGER_LEVEL_Pos 0UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_CTL_TRIGGER_LEVEL_Msk 0x3FUL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_CTL_MUTE_Pos 16UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_CTL_MUTE_Msk 0x10000UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_CTL_FREEZE_Pos 17UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_CTL_FREEZE_Msk 0x20000UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_CTL_ACTIVE_Pos 18UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_CTL_ACTIVE_Msk 0x40000UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_CTL_REPLAY_Pos 19UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_CTL_REPLAY_Msk 0x80000UL
/* I2S_I2S_STRUCT_I2S_TX_STRUCT.TX_FIFO_STATUS */
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_STATUS_USED_Pos 0UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_STATUS_USED_Msk 0x7FUL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_STATUS_RD_PTR_Pos 16UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_STATUS_RD_PTR_Msk 0x3F0000UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_STATUS_WR_PTR_Pos 24UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_STATUS_WR_PTR_Msk 0x3F000000UL
/* I2S_I2S_STRUCT_I2S_TX_STRUCT.TX_FIFO_WR */
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_WR_DATA_Pos 0UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_TX_FIFO_WR_DATA_Msk 0xFFFFFFFFUL
/* I2S_I2S_STRUCT_I2S_TX_STRUCT.INTR_TX */
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_FIFO_TRIGGER_Pos 0UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_FIFO_TRIGGER_Msk 0x1UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_FIFO_OVERFLOW_Pos 1UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_FIFO_OVERFLOW_Msk 0x2UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_FIFO_UNDERFLOW_Pos 2UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_FIFO_UNDERFLOW_Msk 0x4UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_IF_UNDERFLOW_Pos 8UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_IF_UNDERFLOW_Msk 0x100UL
/* I2S_I2S_STRUCT_I2S_TX_STRUCT.INTR_TX_SET */
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_SET_FIFO_TRIGGER_Pos 0UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_SET_FIFO_TRIGGER_Msk 0x1UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_SET_FIFO_OVERFLOW_Pos 1UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_SET_FIFO_OVERFLOW_Msk 0x2UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_SET_FIFO_UNDERFLOW_Pos 2UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_SET_FIFO_UNDERFLOW_Msk 0x4UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_SET_IF_UNDERFLOW_Pos 8UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_SET_IF_UNDERFLOW_Msk 0x100UL
/* I2S_I2S_STRUCT_I2S_TX_STRUCT.INTR_TX_MASK */
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASK_FIFO_TRIGGER_Pos 0UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASK_FIFO_TRIGGER_Msk 0x1UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASK_FIFO_OVERFLOW_Pos 1UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASK_FIFO_OVERFLOW_Msk 0x2UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASK_FIFO_UNDERFLOW_Pos 2UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASK_FIFO_UNDERFLOW_Msk 0x4UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASK_IF_UNDERFLOW_Pos 8UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASK_IF_UNDERFLOW_Msk 0x100UL
/* I2S_I2S_STRUCT_I2S_TX_STRUCT.INTR_TX_MASKED */
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASKED_FIFO_TRIGGER_Pos 0UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASKED_FIFO_TRIGGER_Msk 0x1UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASKED_FIFO_OVERFLOW_Pos 1UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASKED_FIFO_OVERFLOW_Msk 0x2UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASKED_FIFO_UNDERFLOW_Pos 2UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASKED_FIFO_UNDERFLOW_Msk 0x4UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASKED_IF_UNDERFLOW_Pos 8UL
#define I2S_I2S_STRUCT_I2S_TX_STRUCT_INTR_TX_MASKED_IF_UNDERFLOW_Msk 0x100UL


/* I2S_I2S_STRUCT_I2S_RX_STRUCT.RX_CTL */
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL_WORD_SIZE_Pos 0UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL_WORD_SIZE_Msk 0xFUL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL_WORD_SIGN_EXTEND_Pos 8UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL_WORD_SIGN_EXTEND_Msk 0x100UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL_FORMAT_Pos 12UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL_FORMAT_Msk 0x3000UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL_MS_Pos 16UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL_MS_Msk 0x10000UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL_ENABLED_Pos 31UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_CTL_ENABLED_Msk 0x80000000UL
/* I2S_I2S_STRUCT_I2S_RX_STRUCT.RX_IF_CTL */
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CLOCK_DIV_Pos 0UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CLOCK_DIV_Msk 0xFFUL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CLOCK_SEL_Pos 8UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CLOCK_SEL_Msk 0x700UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_SCK_POLARITY_Pos 12UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_SCK_POLARITY_Msk 0x1000UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_WS_POLARITY_Pos 13UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_WS_POLARITY_Msk 0x2000UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_LATE_SAMPLE_Pos 14UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_LATE_SAMPLE_Msk 0x4000UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CH0_EN_Pos 16UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CH0_EN_Msk 0x10000UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CH1_EN_Pos 17UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CH1_EN_Msk 0x20000UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CH_SIZE_Pos 24UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_IF_CTL_CH_SIZE_Msk 0x1F000000UL
/* I2S_I2S_STRUCT_I2S_RX_STRUCT.RX_TEST_CTL */
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_TEST_CTL_ENABLED_Pos 31UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_TEST_CTL_ENABLED_Msk 0x80000000UL
/* I2S_I2S_STRUCT_I2S_RX_STRUCT.RX_FIFO_CTL */
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_CTL_TRIGGER_LEVEL_Pos 0UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_CTL_TRIGGER_LEVEL_Msk 0x3FUL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_CTL_FREEZE_Pos 17UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_CTL_FREEZE_Msk 0x20000UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_CTL_ACTIVE_Pos 18UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_CTL_ACTIVE_Msk 0x40000UL
/* I2S_I2S_STRUCT_I2S_RX_STRUCT.RX_FIFO_STATUS */
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_STATUS_USED_Pos 0UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_STATUS_USED_Msk 0x7FUL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_STATUS_RD_PTR_Pos 16UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_STATUS_RD_PTR_Msk 0x3F0000UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_STATUS_WR_PTR_Pos 24UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_STATUS_WR_PTR_Msk 0x3F000000UL
/* I2S_I2S_STRUCT_I2S_RX_STRUCT.RX_FIFO_RD */
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_RD_DATA_Pos 0UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_RD_DATA_Msk 0xFFFFFFFFUL
/* I2S_I2S_STRUCT_I2S_RX_STRUCT.RX_FIFO_RD_SILENT */
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_RD_SILENT_DATA_Pos 0UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_RX_FIFO_RD_SILENT_DATA_Msk 0xFFFFFFFFUL
/* I2S_I2S_STRUCT_I2S_RX_STRUCT.INTR_RX */
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_FIFO_TRIGGER_Pos 0UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_FIFO_TRIGGER_Msk 0x1UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_FIFO_OVERFLOW_Pos 1UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_FIFO_OVERFLOW_Msk 0x2UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_FIFO_UNDERFLOW_Pos 2UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_FIFO_UNDERFLOW_Msk 0x4UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_IF_OVERFLOW_Pos 8UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_IF_OVERFLOW_Msk 0x100UL
/* I2S_I2S_STRUCT_I2S_RX_STRUCT.INTR_RX_SET */
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_SET_FIFO_TRIGGER_Pos 0UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_SET_FIFO_TRIGGER_Msk 0x1UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_SET_FIFO_OVERFLOW_Pos 1UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_SET_FIFO_OVERFLOW_Msk 0x2UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_SET_FIFO_UNDERFLOW_Pos 2UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_SET_FIFO_UNDERFLOW_Msk 0x4UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_SET_IF_OVERFLOW_Pos 8UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_SET_IF_OVERFLOW_Msk 0x100UL
/* I2S_I2S_STRUCT_I2S_RX_STRUCT.INTR_RX_MASK */
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASK_FIFO_TRIGGER_Pos 0UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASK_FIFO_TRIGGER_Msk 0x1UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASK_FIFO_OVERFLOW_Pos 1UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASK_FIFO_OVERFLOW_Msk 0x2UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASK_FIFO_UNDERFLOW_Pos 2UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASK_FIFO_UNDERFLOW_Msk 0x4UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASK_IF_OVERFLOW_Pos 8UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASK_IF_OVERFLOW_Msk 0x100UL
/* I2S_I2S_STRUCT_I2S_RX_STRUCT.INTR_RX_MASKED */
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASKED_FIFO_TRIGGER_Pos 0UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASKED_FIFO_TRIGGER_Msk 0x1UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASKED_FIFO_OVERFLOW_Pos 1UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASKED_FIFO_OVERFLOW_Msk 0x2UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASKED_FIFO_UNDERFLOW_Pos 2UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASKED_FIFO_UNDERFLOW_Msk 0x4UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASKED_IF_OVERFLOW_Pos 8UL
#define I2S_I2S_STRUCT_I2S_RX_STRUCT_INTR_RX_MASKED_IF_OVERFLOW_Msk 0x100UL


#endif /* _CYIP_I2S_H_ */


/* [] END OF FILE */
