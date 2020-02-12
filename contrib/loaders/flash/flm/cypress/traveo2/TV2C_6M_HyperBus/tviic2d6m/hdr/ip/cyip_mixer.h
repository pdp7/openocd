/***************************************************************************//**
* \file cyip_mixer.h
*
* \brief
* MIXER IP definitions
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

#ifndef _CYIP_MIXER_H_
#define _CYIP_MIXER_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    MIXER
*******************************************************************************/

#define MIXER_MIXER_SRC_STRUCT_SECTION_SIZE     0x00000100UL
#define MIXER_MIXER_DST_STRUCT_SECTION_SIZE     0x00000100UL
#define MIXER_MIXER_TX_STRUCT_SECTION_SIZE      0x00000100UL
#define MIXER_SECTION_SIZE                      0x00010000UL

/**
  * \brief Source control (MIXER_MIXER_SRC_STRUCT_SRC_CTL)
  */
typedef struct stc_MIXER_MIXER_SRC_STRUCT_SRC_CTL_field {
  uint32_t                         :12;
  uint32_t                         u3FS_RATIO:3;
  uint32_t                         :1;
  uint32_t                         u2CH0_SEL:2;
  uint32_t                         u2CH1_SEL:2;
  uint32_t                         :11;
  uint32_t                         u1ENABLED:1;
} stc_MIXER_MIXER_SRC_STRUCT_SRC_CTL_field_t;

typedef union un_MIXER_MIXER_SRC_STRUCT_SRC_CTL {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_SRC_STRUCT_SRC_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_SRC_STRUCT_SRC_CTL_t;

/**
  * \brief Source status (MIXER_MIXER_SRC_STRUCT_SRC_STATUS)
  */
typedef struct stc_MIXER_MIXER_SRC_STRUCT_SRC_STATUS_field {
  uint32_t                         u4PHASE:4;
  uint32_t                         :28;
} stc_MIXER_MIXER_SRC_STRUCT_SRC_STATUS_field_t;

typedef union un_MIXER_MIXER_SRC_STRUCT_SRC_STATUS {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_SRC_STRUCT_SRC_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_SRC_STRUCT_SRC_STATUS_t;

/**
  * \brief Source fade control (MIXER_MIXER_SRC_STRUCT_SRC_FADE_CTL)
  */
typedef struct stc_MIXER_MIXER_SRC_STRUCT_SRC_FADE_CTL_field {
  uint32_t                         u7CODE:7;
  uint32_t                         :25;
} stc_MIXER_MIXER_SRC_STRUCT_SRC_FADE_CTL_field_t;

typedef union un_MIXER_MIXER_SRC_STRUCT_SRC_FADE_CTL {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_SRC_STRUCT_SRC_FADE_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_SRC_STRUCT_SRC_FADE_CTL_t;

/**
  * \brief Source fade status (MIXER_MIXER_SRC_STRUCT_SRC_FADE_STATUS)
  */
typedef struct stc_MIXER_MIXER_SRC_STRUCT_SRC_FADE_STATUS_field {
  uint32_t                         :16;
  uint32_t                         u10PACE:10;
  uint32_t                         :6;
} stc_MIXER_MIXER_SRC_STRUCT_SRC_FADE_STATUS_field_t;

typedef union un_MIXER_MIXER_SRC_STRUCT_SRC_FADE_STATUS {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_SRC_STRUCT_SRC_FADE_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_SRC_STRUCT_SRC_FADE_STATUS_t;

/**
  * \brief Source fade command (MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD)
  */
typedef struct stc_MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_field {
  uint32_t                         u1FADE_IN:1;
  uint32_t                         u1FADE_OUT:1;
  uint32_t                         :6;
  uint32_t                         u1AUTO_DEACTIVATE:1;
  uint32_t                         :7;
  uint32_t                         u10PACE:10;
  uint32_t                         :6;
} stc_MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_field_t;

typedef union un_MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_t;

/**
  * \brief Source gain control (MIXER_MIXER_SRC_STRUCT_SRC_GAIN_CTL)
  */
typedef struct stc_MIXER_MIXER_SRC_STRUCT_SRC_GAIN_CTL_field {
  uint32_t                         u7CODE:7;
  uint32_t                         :25;
} stc_MIXER_MIXER_SRC_STRUCT_SRC_GAIN_CTL_field_t;

typedef union un_MIXER_MIXER_SRC_STRUCT_SRC_GAIN_CTL {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_SRC_STRUCT_SRC_GAIN_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_SRC_STRUCT_SRC_GAIN_CTL_t;

/**
  * \brief Source FIFO control (MIXER_MIXER_SRC_STRUCT_SRC_FIFO_CTL)
  */
typedef struct stc_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_CTL_field {
  uint32_t                         u7TRIGGER_LEVEL:7;
  uint32_t                         :9;
  uint32_t                         u1MUTE:1;
  uint32_t                         :1;
  uint32_t                         u1ACTIVE:1;
  uint32_t                         :13;
} stc_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_CTL_field_t;

typedef union un_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_CTL {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_CTL_t;

/**
  * \brief Source FIFO status (MIXER_MIXER_SRC_STRUCT_SRC_FIFO_STATUS)
  */
typedef struct stc_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_STATUS_field {
  uint32_t                         u8USED:8;
  uint32_t                         :8;
  uint32_t                         u7RD_PTR:7;
  uint32_t                         :1;
  uint32_t                         u7WR_PTR:7;
} stc_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_STATUS_field_t;

typedef union un_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_STATUS {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_STATUS_t;

/**
  * \brief Source FIFO write (MIXER_MIXER_SRC_STRUCT_SRC_FIFO_WR)
  */
typedef struct stc_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_WR_field {
  uint32_t                         u32DATA:32;
} stc_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_WR_field_t;

typedef union un_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_WR {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_WR_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_WR_t;

/**
  * \brief Interrupt (MIXER_MIXER_SRC_STRUCT_INTR_SRC)
  */
typedef struct stc_MIXER_MIXER_SRC_STRUCT_INTR_SRC_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         :6;
  uint32_t                         u1FADED_OUT:1;
  uint32_t                         :23;
} stc_MIXER_MIXER_SRC_STRUCT_INTR_SRC_field_t;

typedef union un_MIXER_MIXER_SRC_STRUCT_INTR_SRC {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_SRC_STRUCT_INTR_SRC_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_SRC_STRUCT_INTR_SRC_t;

/**
  * \brief Interrupt set (MIXER_MIXER_SRC_STRUCT_INTR_SRC_SET)
  */
typedef struct stc_MIXER_MIXER_SRC_STRUCT_INTR_SRC_SET_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         :6;
  uint32_t                         u1FADED_OUT:1;
  uint32_t                         :23;
} stc_MIXER_MIXER_SRC_STRUCT_INTR_SRC_SET_field_t;

typedef union un_MIXER_MIXER_SRC_STRUCT_INTR_SRC_SET {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_SRC_STRUCT_INTR_SRC_SET_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_SRC_STRUCT_INTR_SRC_SET_t;

/**
  * \brief Interrupt mask (MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASK)
  */
typedef struct stc_MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASK_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         :6;
  uint32_t                         u1FADED_OUT:1;
  uint32_t                         :23;
} stc_MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASK_field_t;

typedef union un_MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASK {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASK_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASK_t;

/**
  * \brief Interrupt masked (MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASKED)
  */
typedef struct stc_MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASKED_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         :6;
  uint32_t                         u1FADED_OUT:1;
  uint32_t                         :23;
} stc_MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASKED_field_t;

typedef union un_MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASKED {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASKED_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASKED_t;



/**
  * \brief Destination control (MIXER_MIXER_DST_STRUCT_DST_CTL)
  */
typedef struct stc_MIXER_MIXER_DST_STRUCT_DST_CTL_field {
  uint32_t                         :31;
  uint32_t                         u1ENABLED:1;
} stc_MIXER_MIXER_DST_STRUCT_DST_CTL_field_t;

typedef union un_MIXER_MIXER_DST_STRUCT_DST_CTL {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_DST_STRUCT_DST_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_DST_STRUCT_DST_CTL_t;

/**
  * \brief Destination fade control (MIXER_MIXER_DST_STRUCT_DST_FADE_CTL)
  */
typedef struct stc_MIXER_MIXER_DST_STRUCT_DST_FADE_CTL_field {
  uint32_t                         u7CODE:7;
  uint32_t                         :25;
} stc_MIXER_MIXER_DST_STRUCT_DST_FADE_CTL_field_t;

typedef union un_MIXER_MIXER_DST_STRUCT_DST_FADE_CTL {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_DST_STRUCT_DST_FADE_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_DST_STRUCT_DST_FADE_CTL_t;

/**
  * \brief Destination fade status (MIXER_MIXER_DST_STRUCT_DST_FADE_STATUS)
  */
typedef struct stc_MIXER_MIXER_DST_STRUCT_DST_FADE_STATUS_field {
  uint32_t                         :16;
  uint32_t                         u10PACE:10;
  uint32_t                         :6;
} stc_MIXER_MIXER_DST_STRUCT_DST_FADE_STATUS_field_t;

typedef union un_MIXER_MIXER_DST_STRUCT_DST_FADE_STATUS {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_DST_STRUCT_DST_FADE_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_DST_STRUCT_DST_FADE_STATUS_t;

/**
  * \brief Destination fade command (MIXER_MIXER_DST_STRUCT_DST_FADE_CMD)
  */
typedef struct stc_MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_field {
  uint32_t                         u1FADE_IN:1;
  uint32_t                         u1FADE_OUT:1;
  uint32_t                         :6;
  uint32_t                         u1AUTO_DEACTIVATE:1;
  uint32_t                         :7;
  uint32_t                         u10PACE:10;
  uint32_t                         :6;
} stc_MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_field_t;

typedef union un_MIXER_MIXER_DST_STRUCT_DST_FADE_CMD {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_t;

/**
  * \brief Destination gain control (MIXER_MIXER_DST_STRUCT_DST_GAIN_CTL)
  */
typedef struct stc_MIXER_MIXER_DST_STRUCT_DST_GAIN_CTL_field {
  uint32_t                         u7CODE:7;
  uint32_t                         :25;
} stc_MIXER_MIXER_DST_STRUCT_DST_GAIN_CTL_field_t;

typedef union un_MIXER_MIXER_DST_STRUCT_DST_GAIN_CTL {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_DST_STRUCT_DST_GAIN_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_DST_STRUCT_DST_GAIN_CTL_t;

/**
  * \brief Destination FIFO control (MIXER_MIXER_DST_STRUCT_DST_FIFO_CTL)
  */
typedef struct stc_MIXER_MIXER_DST_STRUCT_DST_FIFO_CTL_field {
  uint32_t                         u6TRIGGER_LEVEL:6;
  uint32_t                         :10;
  uint32_t                         u1MUTE:1;
  uint32_t                         :1;
  uint32_t                         u1ACTIVE:1;
  uint32_t                         :13;
} stc_MIXER_MIXER_DST_STRUCT_DST_FIFO_CTL_field_t;

typedef union un_MIXER_MIXER_DST_STRUCT_DST_FIFO_CTL {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_DST_STRUCT_DST_FIFO_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_DST_STRUCT_DST_FIFO_CTL_t;

/**
  * \brief Destination FIFO status (MIXER_MIXER_DST_STRUCT_DST_FIFO_STATUS)
  */
typedef struct stc_MIXER_MIXER_DST_STRUCT_DST_FIFO_STATUS_field {
  uint32_t                         u7USED:7;
  uint32_t                         :9;
  uint32_t                         u6RD_PTR:6;
  uint32_t                         :2;
  uint32_t                         u6WR_PTR:6;
  uint32_t                         :2;
} stc_MIXER_MIXER_DST_STRUCT_DST_FIFO_STATUS_field_t;

typedef union un_MIXER_MIXER_DST_STRUCT_DST_FIFO_STATUS {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_DST_STRUCT_DST_FIFO_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_DST_STRUCT_DST_FIFO_STATUS_t;

/**
  * \brief Destination FIFO read (MIXER_MIXER_DST_STRUCT_DST_FIFO_RD)
  */
typedef struct stc_MIXER_MIXER_DST_STRUCT_DST_FIFO_RD_field {
  uint32_t                         u32DATA:32;
} stc_MIXER_MIXER_DST_STRUCT_DST_FIFO_RD_field_t;

typedef union un_MIXER_MIXER_DST_STRUCT_DST_FIFO_RD {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_DST_STRUCT_DST_FIFO_RD_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_DST_STRUCT_DST_FIFO_RD_t;

/**
  * \brief Destination FIFO silent read (MIXER_MIXER_DST_STRUCT_DST_FIFO_RD_SILENT)
  */
typedef struct stc_MIXER_MIXER_DST_STRUCT_DST_FIFO_RD_SILENT_field {
  uint32_t                         u32DATA:32;
} stc_MIXER_MIXER_DST_STRUCT_DST_FIFO_RD_SILENT_field_t;

typedef union un_MIXER_MIXER_DST_STRUCT_DST_FIFO_RD_SILENT {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_DST_STRUCT_DST_FIFO_RD_SILENT_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_DST_STRUCT_DST_FIFO_RD_SILENT_t;

/**
  * \brief Interrupt (MIXER_MIXER_DST_STRUCT_INTR_DST)
  */
typedef struct stc_MIXER_MIXER_DST_STRUCT_INTR_DST_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         :1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1FADED_OUT:1;
  uint32_t                         :23;
} stc_MIXER_MIXER_DST_STRUCT_INTR_DST_field_t;

typedef union un_MIXER_MIXER_DST_STRUCT_INTR_DST {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_DST_STRUCT_INTR_DST_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_DST_STRUCT_INTR_DST_t;

/**
  * \brief Interrupt set (MIXER_MIXER_DST_STRUCT_INTR_DST_SET)
  */
typedef struct stc_MIXER_MIXER_DST_STRUCT_INTR_DST_SET_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         :1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1FADED_OUT:1;
  uint32_t                         :23;
} stc_MIXER_MIXER_DST_STRUCT_INTR_DST_SET_field_t;

typedef union un_MIXER_MIXER_DST_STRUCT_INTR_DST_SET {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_DST_STRUCT_INTR_DST_SET_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_DST_STRUCT_INTR_DST_SET_t;

/**
  * \brief Interrupt mask (MIXER_MIXER_DST_STRUCT_INTR_DST_MASK)
  */
typedef struct stc_MIXER_MIXER_DST_STRUCT_INTR_DST_MASK_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         :1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1FADED_OUT:1;
  uint32_t                         :23;
} stc_MIXER_MIXER_DST_STRUCT_INTR_DST_MASK_field_t;

typedef union un_MIXER_MIXER_DST_STRUCT_INTR_DST_MASK {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_DST_STRUCT_INTR_DST_MASK_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_DST_STRUCT_INTR_DST_MASK_t;

/**
  * \brief Interrupt masked (MIXER_MIXER_DST_STRUCT_INTR_DST_MASKED)
  */
typedef struct stc_MIXER_MIXER_DST_STRUCT_INTR_DST_MASKED_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         :1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1FADED_OUT:1;
  uint32_t                         :23;
} stc_MIXER_MIXER_DST_STRUCT_INTR_DST_MASKED_field_t;

typedef union un_MIXER_MIXER_DST_STRUCT_INTR_DST_MASKED {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_DST_STRUCT_INTR_DST_MASKED_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_DST_STRUCT_INTR_DST_MASKED_t;



/**
  * \brief TX control (MIXER_MIXER_TX_STRUCT_TX_CTL)
  */
typedef struct stc_MIXER_MIXER_TX_STRUCT_TX_CTL_field {
  uint32_t                         u4WORD_SIZE:4;
  uint32_t                         :8;
  uint32_t                         u2FORMAT:2;
  uint32_t                         :2;
  uint32_t                         u1MS:1;
  uint32_t                         :14;
  uint32_t                         u1ENABLED:1;
} stc_MIXER_MIXER_TX_STRUCT_TX_CTL_field_t;

typedef union un_MIXER_MIXER_TX_STRUCT_TX_CTL {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_TX_STRUCT_TX_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_TX_STRUCT_TX_CTL_t;

/**
  * \brief TX interface control (MIXER_MIXER_TX_STRUCT_TX_IF_CTL)
  */
typedef struct stc_MIXER_MIXER_TX_STRUCT_TX_IF_CTL_field {
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
} stc_MIXER_MIXER_TX_STRUCT_TX_IF_CTL_field_t;

typedef union un_MIXER_MIXER_TX_STRUCT_TX_IF_CTL {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_TX_STRUCT_TX_IF_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_TX_STRUCT_TX_IF_CTL_t;

/**
  * \brief TX FIFO control (MIXER_MIXER_TX_STRUCT_TX_FIFO_CTL)
  */
typedef struct stc_MIXER_MIXER_TX_STRUCT_TX_FIFO_CTL_field {
  uint32_t                         :16;
  uint32_t                         u1MUTE:1;
  uint32_t                         u1FREEZE:1;
  uint32_t                         u1ACTIVE:1;
  uint32_t                         u1REPLAY:1;
  uint32_t                         :12;
} stc_MIXER_MIXER_TX_STRUCT_TX_FIFO_CTL_field_t;

typedef union un_MIXER_MIXER_TX_STRUCT_TX_FIFO_CTL {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_TX_STRUCT_TX_FIFO_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_TX_STRUCT_TX_FIFO_CTL_t;

/**
  * \brief Interrupt (MIXER_MIXER_TX_STRUCT_INTR_TX)
  */
typedef struct stc_MIXER_MIXER_TX_STRUCT_INTR_TX_field {
  uint32_t                         :2;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_MIXER_MIXER_TX_STRUCT_INTR_TX_field_t;

typedef union un_MIXER_MIXER_TX_STRUCT_INTR_TX {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_TX_STRUCT_INTR_TX_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_TX_STRUCT_INTR_TX_t;

/**
  * \brief Interrupt set (MIXER_MIXER_TX_STRUCT_INTR_TX_SET)
  */
typedef struct stc_MIXER_MIXER_TX_STRUCT_INTR_TX_SET_field {
  uint32_t                         :2;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_MIXER_MIXER_TX_STRUCT_INTR_TX_SET_field_t;

typedef union un_MIXER_MIXER_TX_STRUCT_INTR_TX_SET {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_TX_STRUCT_INTR_TX_SET_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_TX_STRUCT_INTR_TX_SET_t;

/**
  * \brief Interrupt mask (MIXER_MIXER_TX_STRUCT_INTR_TX_MASK)
  */
typedef struct stc_MIXER_MIXER_TX_STRUCT_INTR_TX_MASK_field {
  uint32_t                         :2;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_MIXER_MIXER_TX_STRUCT_INTR_TX_MASK_field_t;

typedef union un_MIXER_MIXER_TX_STRUCT_INTR_TX_MASK {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_TX_STRUCT_INTR_TX_MASK_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_TX_STRUCT_INTR_TX_MASK_t;

/**
  * \brief Interrupt masked (MIXER_MIXER_TX_STRUCT_INTR_TX_MASKED)
  */
typedef struct stc_MIXER_MIXER_TX_STRUCT_INTR_TX_MASKED_field {
  uint32_t                         :2;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_MIXER_MIXER_TX_STRUCT_INTR_TX_MASKED_field_t;

typedef union un_MIXER_MIXER_TX_STRUCT_INTR_TX_MASKED {
  uint32_t                         u32Register;
  stc_MIXER_MIXER_TX_STRUCT_INTR_TX_MASKED_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_MIXER_MIXER_TX_STRUCT_INTR_TX_MASKED_t;



/**
  * \brief Mixer source structure (MIXER_MIXER_SRC_STRUCT)
  */
typedef struct stc_MIXER_MIXER_SRC_STRUCT {
  un_MIXER_MIXER_SRC_STRUCT_SRC_CTL_t unSRC_CTL;       /*!< 0x00000000 Source control */
  un_MIXER_MIXER_SRC_STRUCT_SRC_STATUS_t unSRC_STATUS; /*!< 0x00000004 Source status */
  uint32_t                         au32Reserved[3];
  un_MIXER_MIXER_SRC_STRUCT_SRC_FADE_CTL_t unSRC_FADE_CTL; /*!< 0x00000014 Source fade control */
  un_MIXER_MIXER_SRC_STRUCT_SRC_FADE_STATUS_t unSRC_FADE_STATUS; /*!< 0x00000018 Source fade status */
  un_MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_t unSRC_FADE_CMD; /*!< 0x0000001C Source fade command */
  un_MIXER_MIXER_SRC_STRUCT_SRC_GAIN_CTL_t unSRC_GAIN_CTL; /*!< 0x00000020 Source gain control */
  uint32_t                         au32Reserved1[23];
  un_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_CTL_t unSRC_FIFO_CTL; /*!< 0x00000080 Source FIFO control */
  un_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_STATUS_t unSRC_FIFO_STATUS; /*!< 0x00000084 Source FIFO status */
  un_MIXER_MIXER_SRC_STRUCT_SRC_FIFO_WR_t unSRC_FIFO_WR; /*!< 0x00000088 Source FIFO write */
  uint32_t                         au32Reserved2[13];
  un_MIXER_MIXER_SRC_STRUCT_INTR_SRC_t unINTR_SRC;     /*!< 0x000000C0 Interrupt */
  un_MIXER_MIXER_SRC_STRUCT_INTR_SRC_SET_t unINTR_SRC_SET; /*!< 0x000000C4 Interrupt set */
  un_MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASK_t unINTR_SRC_MASK; /*!< 0x000000C8 Interrupt mask */
  un_MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASKED_t unINTR_SRC_MASKED; /*!< 0x000000CC Interrupt masked */
  uint32_t                         au32Reserved3[12];
} stc_MIXER_MIXER_SRC_STRUCT_t;                        /*!< Size = 256 (0x100) */

/**
  * \brief Mixer destination structure (MIXER_MIXER_DST_STRUCT)
  */
typedef struct stc_MIXER_MIXER_DST_STRUCT {
  un_MIXER_MIXER_DST_STRUCT_DST_CTL_t unDST_CTL;       /*!< 0x00000000 Destination control */
  uint32_t                         au32Reserved[4];
  un_MIXER_MIXER_DST_STRUCT_DST_FADE_CTL_t unDST_FADE_CTL; /*!< 0x00000014 Destination fade control */
  un_MIXER_MIXER_DST_STRUCT_DST_FADE_STATUS_t unDST_FADE_STATUS; /*!< 0x00000018 Destination fade status */
  un_MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_t unDST_FADE_CMD; /*!< 0x0000001C Destination fade command */
  un_MIXER_MIXER_DST_STRUCT_DST_GAIN_CTL_t unDST_GAIN_CTL; /*!< 0x00000020 Destination gain control */
  uint32_t                         au32Reserved1[23];
  un_MIXER_MIXER_DST_STRUCT_DST_FIFO_CTL_t unDST_FIFO_CTL; /*!< 0x00000080 Destination FIFO control */
  un_MIXER_MIXER_DST_STRUCT_DST_FIFO_STATUS_t unDST_FIFO_STATUS; /*!< 0x00000084 Destination FIFO status */
  un_MIXER_MIXER_DST_STRUCT_DST_FIFO_RD_t unDST_FIFO_RD; /*!< 0x00000088 Destination FIFO read */
  un_MIXER_MIXER_DST_STRUCT_DST_FIFO_RD_SILENT_t unDST_FIFO_RD_SILENT; /*!< 0x0000008C Destination FIFO silent read */
  uint32_t                         au32Reserved2[12];
  un_MIXER_MIXER_DST_STRUCT_INTR_DST_t unINTR_DST;     /*!< 0x000000C0 Interrupt */
  un_MIXER_MIXER_DST_STRUCT_INTR_DST_SET_t unINTR_DST_SET; /*!< 0x000000C4 Interrupt set */
  un_MIXER_MIXER_DST_STRUCT_INTR_DST_MASK_t unINTR_DST_MASK; /*!< 0x000000C8 Interrupt mask */
  un_MIXER_MIXER_DST_STRUCT_INTR_DST_MASKED_t unINTR_DST_MASKED; /*!< 0x000000CC Interrupt masked */
  uint32_t                         au32Reserved3[12];
} stc_MIXER_MIXER_DST_STRUCT_t;                        /*!< Size = 256 (0x100) */

/**
  * \brief Mixer TX structure (MIXER_MIXER_TX_STRUCT)
  */
typedef struct stc_MIXER_MIXER_TX_STRUCT {
  un_MIXER_MIXER_TX_STRUCT_TX_CTL_t unTX_CTL;          /*!< 0x00000000 TX control */
  uint32_t                         au32Reserved[3];
  un_MIXER_MIXER_TX_STRUCT_TX_IF_CTL_t unTX_IF_CTL;    /*!< 0x00000010 TX interface control */
  uint32_t                         au32Reserved1[27];
  un_MIXER_MIXER_TX_STRUCT_TX_FIFO_CTL_t unTX_FIFO_CTL; /*!< 0x00000080 TX FIFO control */
  uint32_t                         au32Reserved2[15];
  un_MIXER_MIXER_TX_STRUCT_INTR_TX_t unINTR_TX;        /*!< 0x000000C0 Interrupt */
  un_MIXER_MIXER_TX_STRUCT_INTR_TX_SET_t unINTR_TX_SET; /*!< 0x000000C4 Interrupt set */
  un_MIXER_MIXER_TX_STRUCT_INTR_TX_MASK_t unINTR_TX_MASK; /*!< 0x000000C8 Interrupt mask */
  un_MIXER_MIXER_TX_STRUCT_INTR_TX_MASKED_t unINTR_TX_MASKED; /*!< 0x000000CC Interrupt masked */
  uint32_t                         au32Reserved3[12];
} stc_MIXER_MIXER_TX_STRUCT_t;                         /*!< Size = 256 (0x100) */

/**
  * \brief MIXER (MIXER)
  */
typedef struct stc_MIXER {
  uint32_t                         au32Reserved[8192];
  stc_MIXER_MIXER_SRC_STRUCT_t     MIXER_SRC_STRUCT[8]; /*!< 0x00008000 Mixer source structure */
  uint32_t                         au32Reserved1[3584];
  stc_MIXER_MIXER_DST_STRUCT_t     MIXER_DST_STRUCT;   /*!< 0x0000C000 Mixer destination structure */
  uint32_t                         au32Reserved2[960];
  stc_MIXER_MIXER_TX_STRUCT_t      MIXER_TX_STRUCT;    /*!< 0x0000D000 Mixer TX structure */
} stc_MIXER_t;                                         /*!< Size = 53504 (0xD100) */


/* MIXER_MIXER_SRC_STRUCT.SRC_CTL */
#define MIXER_MIXER_SRC_STRUCT_SRC_CTL_FS_RATIO_Pos 12UL
#define MIXER_MIXER_SRC_STRUCT_SRC_CTL_FS_RATIO_Msk 0x7000UL
#define MIXER_MIXER_SRC_STRUCT_SRC_CTL_CH0_SEL_Pos 16UL
#define MIXER_MIXER_SRC_STRUCT_SRC_CTL_CH0_SEL_Msk 0x30000UL
#define MIXER_MIXER_SRC_STRUCT_SRC_CTL_CH1_SEL_Pos 18UL
#define MIXER_MIXER_SRC_STRUCT_SRC_CTL_CH1_SEL_Msk 0xC0000UL
#define MIXER_MIXER_SRC_STRUCT_SRC_CTL_ENABLED_Pos 31UL
#define MIXER_MIXER_SRC_STRUCT_SRC_CTL_ENABLED_Msk 0x80000000UL
/* MIXER_MIXER_SRC_STRUCT.SRC_STATUS */
#define MIXER_MIXER_SRC_STRUCT_SRC_STATUS_PHASE_Pos 0UL
#define MIXER_MIXER_SRC_STRUCT_SRC_STATUS_PHASE_Msk 0xFUL
/* MIXER_MIXER_SRC_STRUCT.SRC_FADE_CTL */
#define MIXER_MIXER_SRC_STRUCT_SRC_FADE_CTL_CODE_Pos 0UL
#define MIXER_MIXER_SRC_STRUCT_SRC_FADE_CTL_CODE_Msk 0x7FUL
/* MIXER_MIXER_SRC_STRUCT.SRC_FADE_STATUS */
#define MIXER_MIXER_SRC_STRUCT_SRC_FADE_STATUS_PACE_Pos 16UL
#define MIXER_MIXER_SRC_STRUCT_SRC_FADE_STATUS_PACE_Msk 0x3FF0000UL
/* MIXER_MIXER_SRC_STRUCT.SRC_FADE_CMD */
#define MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_FADE_IN_Pos 0UL
#define MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_FADE_IN_Msk 0x1UL
#define MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_FADE_OUT_Pos 1UL
#define MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_FADE_OUT_Msk 0x2UL
#define MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_AUTO_DEACTIVATE_Pos 8UL
#define MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_AUTO_DEACTIVATE_Msk 0x100UL
#define MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_PACE_Pos 16UL
#define MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_PACE_Msk 0x3FF0000UL
/* MIXER_MIXER_SRC_STRUCT.SRC_GAIN_CTL */
#define MIXER_MIXER_SRC_STRUCT_SRC_GAIN_CTL_CODE_Pos 0UL
#define MIXER_MIXER_SRC_STRUCT_SRC_GAIN_CTL_CODE_Msk 0x7FUL
/* MIXER_MIXER_SRC_STRUCT.SRC_FIFO_CTL */
#define MIXER_MIXER_SRC_STRUCT_SRC_FIFO_CTL_TRIGGER_LEVEL_Pos 0UL
#define MIXER_MIXER_SRC_STRUCT_SRC_FIFO_CTL_TRIGGER_LEVEL_Msk 0x7FUL
#define MIXER_MIXER_SRC_STRUCT_SRC_FIFO_CTL_MUTE_Pos 16UL
#define MIXER_MIXER_SRC_STRUCT_SRC_FIFO_CTL_MUTE_Msk 0x10000UL
#define MIXER_MIXER_SRC_STRUCT_SRC_FIFO_CTL_ACTIVE_Pos 18UL
#define MIXER_MIXER_SRC_STRUCT_SRC_FIFO_CTL_ACTIVE_Msk 0x40000UL
/* MIXER_MIXER_SRC_STRUCT.SRC_FIFO_STATUS */
#define MIXER_MIXER_SRC_STRUCT_SRC_FIFO_STATUS_USED_Pos 0UL
#define MIXER_MIXER_SRC_STRUCT_SRC_FIFO_STATUS_USED_Msk 0xFFUL
#define MIXER_MIXER_SRC_STRUCT_SRC_FIFO_STATUS_RD_PTR_Pos 16UL
#define MIXER_MIXER_SRC_STRUCT_SRC_FIFO_STATUS_RD_PTR_Msk 0x7F0000UL
#define MIXER_MIXER_SRC_STRUCT_SRC_FIFO_STATUS_WR_PTR_Pos 24UL
#define MIXER_MIXER_SRC_STRUCT_SRC_FIFO_STATUS_WR_PTR_Msk 0x7F000000UL
/* MIXER_MIXER_SRC_STRUCT.SRC_FIFO_WR */
#define MIXER_MIXER_SRC_STRUCT_SRC_FIFO_WR_DATA_Pos 0UL
#define MIXER_MIXER_SRC_STRUCT_SRC_FIFO_WR_DATA_Msk 0xFFFFFFFFUL
/* MIXER_MIXER_SRC_STRUCT.INTR_SRC */
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_FIFO_TRIGGER_Pos 0UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_FIFO_TRIGGER_Msk 0x1UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_FIFO_OVERFLOW_Pos 1UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_FIFO_OVERFLOW_Msk 0x2UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_FADED_OUT_Pos 8UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_FADED_OUT_Msk 0x100UL
/* MIXER_MIXER_SRC_STRUCT.INTR_SRC_SET */
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_SET_FIFO_TRIGGER_Pos 0UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_SET_FIFO_TRIGGER_Msk 0x1UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_SET_FIFO_OVERFLOW_Pos 1UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_SET_FIFO_OVERFLOW_Msk 0x2UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_SET_FADED_OUT_Pos 8UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_SET_FADED_OUT_Msk 0x100UL
/* MIXER_MIXER_SRC_STRUCT.INTR_SRC_MASK */
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASK_FIFO_TRIGGER_Pos 0UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASK_FIFO_TRIGGER_Msk 0x1UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASK_FIFO_OVERFLOW_Pos 1UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASK_FIFO_OVERFLOW_Msk 0x2UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASK_FADED_OUT_Pos 8UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASK_FADED_OUT_Msk 0x100UL
/* MIXER_MIXER_SRC_STRUCT.INTR_SRC_MASKED */
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASKED_FIFO_TRIGGER_Pos 0UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASKED_FIFO_TRIGGER_Msk 0x1UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASKED_FIFO_OVERFLOW_Pos 1UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASKED_FIFO_OVERFLOW_Msk 0x2UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASKED_FADED_OUT_Pos 8UL
#define MIXER_MIXER_SRC_STRUCT_INTR_SRC_MASKED_FADED_OUT_Msk 0x100UL


/* MIXER_MIXER_DST_STRUCT.DST_CTL */
#define MIXER_MIXER_DST_STRUCT_DST_CTL_ENABLED_Pos 31UL
#define MIXER_MIXER_DST_STRUCT_DST_CTL_ENABLED_Msk 0x80000000UL
/* MIXER_MIXER_DST_STRUCT.DST_FADE_CTL */
#define MIXER_MIXER_DST_STRUCT_DST_FADE_CTL_CODE_Pos 0UL
#define MIXER_MIXER_DST_STRUCT_DST_FADE_CTL_CODE_Msk 0x7FUL
/* MIXER_MIXER_DST_STRUCT.DST_FADE_STATUS */
#define MIXER_MIXER_DST_STRUCT_DST_FADE_STATUS_PACE_Pos 16UL
#define MIXER_MIXER_DST_STRUCT_DST_FADE_STATUS_PACE_Msk 0x3FF0000UL
/* MIXER_MIXER_DST_STRUCT.DST_FADE_CMD */
#define MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_FADE_IN_Pos 0UL
#define MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_FADE_IN_Msk 0x1UL
#define MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_FADE_OUT_Pos 1UL
#define MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_FADE_OUT_Msk 0x2UL
#define MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_AUTO_DEACTIVATE_Pos 8UL
#define MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_AUTO_DEACTIVATE_Msk 0x100UL
#define MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_PACE_Pos 16UL
#define MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_PACE_Msk 0x3FF0000UL
/* MIXER_MIXER_DST_STRUCT.DST_GAIN_CTL */
#define MIXER_MIXER_DST_STRUCT_DST_GAIN_CTL_CODE_Pos 0UL
#define MIXER_MIXER_DST_STRUCT_DST_GAIN_CTL_CODE_Msk 0x7FUL
/* MIXER_MIXER_DST_STRUCT.DST_FIFO_CTL */
#define MIXER_MIXER_DST_STRUCT_DST_FIFO_CTL_TRIGGER_LEVEL_Pos 0UL
#define MIXER_MIXER_DST_STRUCT_DST_FIFO_CTL_TRIGGER_LEVEL_Msk 0x3FUL
#define MIXER_MIXER_DST_STRUCT_DST_FIFO_CTL_MUTE_Pos 16UL
#define MIXER_MIXER_DST_STRUCT_DST_FIFO_CTL_MUTE_Msk 0x10000UL
#define MIXER_MIXER_DST_STRUCT_DST_FIFO_CTL_ACTIVE_Pos 18UL
#define MIXER_MIXER_DST_STRUCT_DST_FIFO_CTL_ACTIVE_Msk 0x40000UL
/* MIXER_MIXER_DST_STRUCT.DST_FIFO_STATUS */
#define MIXER_MIXER_DST_STRUCT_DST_FIFO_STATUS_USED_Pos 0UL
#define MIXER_MIXER_DST_STRUCT_DST_FIFO_STATUS_USED_Msk 0x7FUL
#define MIXER_MIXER_DST_STRUCT_DST_FIFO_STATUS_RD_PTR_Pos 16UL
#define MIXER_MIXER_DST_STRUCT_DST_FIFO_STATUS_RD_PTR_Msk 0x3F0000UL
#define MIXER_MIXER_DST_STRUCT_DST_FIFO_STATUS_WR_PTR_Pos 24UL
#define MIXER_MIXER_DST_STRUCT_DST_FIFO_STATUS_WR_PTR_Msk 0x3F000000UL
/* MIXER_MIXER_DST_STRUCT.DST_FIFO_RD */
#define MIXER_MIXER_DST_STRUCT_DST_FIFO_RD_DATA_Pos 0UL
#define MIXER_MIXER_DST_STRUCT_DST_FIFO_RD_DATA_Msk 0xFFFFFFFFUL
/* MIXER_MIXER_DST_STRUCT.DST_FIFO_RD_SILENT */
#define MIXER_MIXER_DST_STRUCT_DST_FIFO_RD_SILENT_DATA_Pos 0UL
#define MIXER_MIXER_DST_STRUCT_DST_FIFO_RD_SILENT_DATA_Msk 0xFFFFFFFFUL
/* MIXER_MIXER_DST_STRUCT.INTR_DST */
#define MIXER_MIXER_DST_STRUCT_INTR_DST_FIFO_TRIGGER_Pos 0UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_FIFO_TRIGGER_Msk 0x1UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_FIFO_UNDERFLOW_Pos 2UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_FIFO_UNDERFLOW_Msk 0x4UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_FADED_OUT_Pos 8UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_FADED_OUT_Msk 0x100UL
/* MIXER_MIXER_DST_STRUCT.INTR_DST_SET */
#define MIXER_MIXER_DST_STRUCT_INTR_DST_SET_FIFO_TRIGGER_Pos 0UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_SET_FIFO_TRIGGER_Msk 0x1UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_SET_FIFO_UNDERFLOW_Pos 2UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_SET_FIFO_UNDERFLOW_Msk 0x4UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_SET_FADED_OUT_Pos 8UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_SET_FADED_OUT_Msk 0x100UL
/* MIXER_MIXER_DST_STRUCT.INTR_DST_MASK */
#define MIXER_MIXER_DST_STRUCT_INTR_DST_MASK_FIFO_TRIGGER_Pos 0UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_MASK_FIFO_TRIGGER_Msk 0x1UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_MASK_FIFO_UNDERFLOW_Pos 2UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_MASK_FIFO_UNDERFLOW_Msk 0x4UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_MASK_FADED_OUT_Pos 8UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_MASK_FADED_OUT_Msk 0x100UL
/* MIXER_MIXER_DST_STRUCT.INTR_DST_MASKED */
#define MIXER_MIXER_DST_STRUCT_INTR_DST_MASKED_FIFO_TRIGGER_Pos 0UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_MASKED_FIFO_TRIGGER_Msk 0x1UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_MASKED_FIFO_UNDERFLOW_Pos 2UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_MASKED_FIFO_UNDERFLOW_Msk 0x4UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_MASKED_FADED_OUT_Pos 8UL
#define MIXER_MIXER_DST_STRUCT_INTR_DST_MASKED_FADED_OUT_Msk 0x100UL


/* MIXER_MIXER_TX_STRUCT.TX_CTL */
#define MIXER_MIXER_TX_STRUCT_TX_CTL_WORD_SIZE_Pos 0UL
#define MIXER_MIXER_TX_STRUCT_TX_CTL_WORD_SIZE_Msk 0xFUL
#define MIXER_MIXER_TX_STRUCT_TX_CTL_FORMAT_Pos 12UL
#define MIXER_MIXER_TX_STRUCT_TX_CTL_FORMAT_Msk 0x3000UL
#define MIXER_MIXER_TX_STRUCT_TX_CTL_MS_Pos     16UL
#define MIXER_MIXER_TX_STRUCT_TX_CTL_MS_Msk     0x10000UL
#define MIXER_MIXER_TX_STRUCT_TX_CTL_ENABLED_Pos 31UL
#define MIXER_MIXER_TX_STRUCT_TX_CTL_ENABLED_Msk 0x80000000UL
/* MIXER_MIXER_TX_STRUCT.TX_IF_CTL */
#define MIXER_MIXER_TX_STRUCT_TX_IF_CTL_CLOCK_DIV_Pos 0UL
#define MIXER_MIXER_TX_STRUCT_TX_IF_CTL_CLOCK_DIV_Msk 0xFFUL
#define MIXER_MIXER_TX_STRUCT_TX_IF_CTL_CLOCK_SEL_Pos 8UL
#define MIXER_MIXER_TX_STRUCT_TX_IF_CTL_CLOCK_SEL_Msk 0x700UL
#define MIXER_MIXER_TX_STRUCT_TX_IF_CTL_SCK_POLARITY_Pos 12UL
#define MIXER_MIXER_TX_STRUCT_TX_IF_CTL_SCK_POLARITY_Msk 0x1000UL
#define MIXER_MIXER_TX_STRUCT_TX_IF_CTL_WS_POLARITY_Pos 13UL
#define MIXER_MIXER_TX_STRUCT_TX_IF_CTL_WS_POLARITY_Msk 0x2000UL
#define MIXER_MIXER_TX_STRUCT_TX_IF_CTL_CH0_EN_Pos 16UL
#define MIXER_MIXER_TX_STRUCT_TX_IF_CTL_CH0_EN_Msk 0x10000UL
#define MIXER_MIXER_TX_STRUCT_TX_IF_CTL_CH1_EN_Pos 17UL
#define MIXER_MIXER_TX_STRUCT_TX_IF_CTL_CH1_EN_Msk 0x20000UL
#define MIXER_MIXER_TX_STRUCT_TX_IF_CTL_CH_SIZE_Pos 24UL
#define MIXER_MIXER_TX_STRUCT_TX_IF_CTL_CH_SIZE_Msk 0x1F000000UL
/* MIXER_MIXER_TX_STRUCT.TX_FIFO_CTL */
#define MIXER_MIXER_TX_STRUCT_TX_FIFO_CTL_MUTE_Pos 16UL
#define MIXER_MIXER_TX_STRUCT_TX_FIFO_CTL_MUTE_Msk 0x10000UL
#define MIXER_MIXER_TX_STRUCT_TX_FIFO_CTL_FREEZE_Pos 17UL
#define MIXER_MIXER_TX_STRUCT_TX_FIFO_CTL_FREEZE_Msk 0x20000UL
#define MIXER_MIXER_TX_STRUCT_TX_FIFO_CTL_ACTIVE_Pos 18UL
#define MIXER_MIXER_TX_STRUCT_TX_FIFO_CTL_ACTIVE_Msk 0x40000UL
#define MIXER_MIXER_TX_STRUCT_TX_FIFO_CTL_REPLAY_Pos 19UL
#define MIXER_MIXER_TX_STRUCT_TX_FIFO_CTL_REPLAY_Msk 0x80000UL
/* MIXER_MIXER_TX_STRUCT.INTR_TX */
#define MIXER_MIXER_TX_STRUCT_INTR_TX_FIFO_UNDERFLOW_Pos 2UL
#define MIXER_MIXER_TX_STRUCT_INTR_TX_FIFO_UNDERFLOW_Msk 0x4UL
#define MIXER_MIXER_TX_STRUCT_INTR_TX_IF_UNDERFLOW_Pos 8UL
#define MIXER_MIXER_TX_STRUCT_INTR_TX_IF_UNDERFLOW_Msk 0x100UL
/* MIXER_MIXER_TX_STRUCT.INTR_TX_SET */
#define MIXER_MIXER_TX_STRUCT_INTR_TX_SET_FIFO_UNDERFLOW_Pos 2UL
#define MIXER_MIXER_TX_STRUCT_INTR_TX_SET_FIFO_UNDERFLOW_Msk 0x4UL
#define MIXER_MIXER_TX_STRUCT_INTR_TX_SET_IF_UNDERFLOW_Pos 8UL
#define MIXER_MIXER_TX_STRUCT_INTR_TX_SET_IF_UNDERFLOW_Msk 0x100UL
/* MIXER_MIXER_TX_STRUCT.INTR_TX_MASK */
#define MIXER_MIXER_TX_STRUCT_INTR_TX_MASK_FIFO_UNDERFLOW_Pos 2UL
#define MIXER_MIXER_TX_STRUCT_INTR_TX_MASK_FIFO_UNDERFLOW_Msk 0x4UL
#define MIXER_MIXER_TX_STRUCT_INTR_TX_MASK_IF_UNDERFLOW_Pos 8UL
#define MIXER_MIXER_TX_STRUCT_INTR_TX_MASK_IF_UNDERFLOW_Msk 0x100UL
/* MIXER_MIXER_TX_STRUCT.INTR_TX_MASKED */
#define MIXER_MIXER_TX_STRUCT_INTR_TX_MASKED_FIFO_UNDERFLOW_Pos 2UL
#define MIXER_MIXER_TX_STRUCT_INTR_TX_MASKED_FIFO_UNDERFLOW_Msk 0x4UL
#define MIXER_MIXER_TX_STRUCT_INTR_TX_MASKED_IF_UNDERFLOW_Pos 8UL
#define MIXER_MIXER_TX_STRUCT_INTR_TX_MASKED_IF_UNDERFLOW_Msk 0x100UL


#endif /* _CYIP_MIXER_H_ */


/* [] END OF FILE */
