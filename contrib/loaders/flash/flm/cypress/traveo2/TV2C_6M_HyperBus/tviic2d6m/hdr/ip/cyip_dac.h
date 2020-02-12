/***************************************************************************//**
* \file cyip_dac.h
*
* \brief
* DAC IP definitions
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

#ifndef _CYIP_DAC_H_
#define _CYIP_DAC_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     DAC
*******************************************************************************/

#define DAC_SECTION_SIZE                        0x00000100UL

/**
  * \brief Control (DAC_CTL)
  */
typedef struct stc_DAC_CTL_field {
  uint32_t                         :31;
  uint32_t                         u1ENABLED:1;
} stc_DAC_CTL_field_t;

typedef union un_DAC_CTL {
  uint32_t                         u32Register;
  stc_DAC_CTL_field_t              stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_DAC_CTL_t;

/**
  * \brief Interface Control (DAC_IF_CTL)
  */
typedef struct stc_DAC_IF_CTL_field {
  uint32_t                         u8CLOCK_DIV:8;
  uint32_t                         u3CLOCK_SEL:3;
  uint32_t                         :5;
  uint32_t                         u2FS_SEL:2;
  uint32_t                         :6;
  uint32_t                         u1LDATA_POLARITY:1;
  uint32_t                         u1RDATA_POLARITY:1;
  uint32_t                         u1LDATA_SEL:1;
  uint32_t                         u1RDATA_SEL:1;
  uint32_t                         :2;
  uint32_t                         u1SW_OVERRIDE_FAST_RAMP_EN:1;
  uint32_t                         u1DAC_EN:1;
} stc_DAC_IF_CTL_field_t;

typedef union un_DAC_IF_CTL {
  uint32_t                         u32Register;
  stc_DAC_IF_CTL_field_t           stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_DAC_IF_CTL_t;

/**
  * \brief Count (DAC_COUNT)
  */
typedef struct stc_DAC_COUNT_field {
  uint32_t                         u16COUNT_1MS:16;
  uint32_t                         u8FAST_RAMP_COUNT_IN_MS:8;
  uint32_t                         u8COMP_RAMP_COUNT_IN_MS:8;
} stc_DAC_COUNT_field_t;

typedef union un_DAC_COUNT {
  uint32_t                         u32Register;
  stc_DAC_COUNT_field_t            stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_DAC_COUNT_t;

/**
  * \brief Status (DAC_STATUS)
  */
typedef struct stc_DAC_STATUS_field {
  uint32_t                         u1DAC_BUSY:1;
  uint32_t                         :15;
  uint32_t                         u1FAST_RAMP_DONE:1;
  uint32_t                         u1COMP_RAMP_DONE:1;
  uint32_t                         :14;
} stc_DAC_STATUS_field_t;

typedef union un_DAC_STATUS {
  uint32_t                         u32Register;
  stc_DAC_STATUS_field_t           stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_DAC_STATUS_t;

/**
  * \brief TX FIFO control (DAC_TX_FIFO_CTL)
  */
typedef struct stc_DAC_TX_FIFO_CTL_field {
  uint32_t                         u6TRIGGER_LEVEL:6;
  uint32_t                         :10;
  uint32_t                         u1MUTE:1;
  uint32_t                         u1FREEZE:1;
  uint32_t                         u1ACTIVE:1;
  uint32_t                         :13;
} stc_DAC_TX_FIFO_CTL_field_t;

typedef union un_DAC_TX_FIFO_CTL {
  uint32_t                         u32Register;
  stc_DAC_TX_FIFO_CTL_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_DAC_TX_FIFO_CTL_t;

/**
  * \brief TX FIFO status (DAC_TX_FIFO_STATUS)
  */
typedef struct stc_DAC_TX_FIFO_STATUS_field {
  uint32_t                         u7USED:7;
  uint32_t                         :9;
  uint32_t                         u6RD_PTR:6;
  uint32_t                         :2;
  uint32_t                         u6WR_PTR:6;
  uint32_t                         :2;
} stc_DAC_TX_FIFO_STATUS_field_t;

typedef union un_DAC_TX_FIFO_STATUS {
  uint32_t                         u32Register;
  stc_DAC_TX_FIFO_STATUS_field_t   stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_DAC_TX_FIFO_STATUS_t;

/**
  * \brief TX FIFO write (DAC_TX_FIFO_WR)
  */
typedef struct stc_DAC_TX_FIFO_WR_field {
  uint32_t                         u32DATA:32;
} stc_DAC_TX_FIFO_WR_field_t;

typedef union un_DAC_TX_FIFO_WR {
  uint32_t                         u32Register;
  stc_DAC_TX_FIFO_WR_field_t       stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_DAC_TX_FIFO_WR_t;

/**
  * \brief Interrupt (DAC_INTR_TX)
  */
typedef struct stc_DAC_INTR_TX_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :13;
  uint32_t                         u1FAST_RAMP_COMPLETE:1;
  uint32_t                         u1RAMP_COMPLETE:1;
  uint32_t                         :14;
} stc_DAC_INTR_TX_field_t;

typedef union un_DAC_INTR_TX {
  uint32_t                         u32Register;
  stc_DAC_INTR_TX_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_DAC_INTR_TX_t;

/**
  * \brief Interrupt set (DAC_INTR_TX_SET)
  */
typedef struct stc_DAC_INTR_TX_SET_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :13;
  uint32_t                         u1FAST_RAMP_COMPLETE:1;
  uint32_t                         u1RAMP_COMPLETE:1;
  uint32_t                         :14;
} stc_DAC_INTR_TX_SET_field_t;

typedef union un_DAC_INTR_TX_SET {
  uint32_t                         u32Register;
  stc_DAC_INTR_TX_SET_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_DAC_INTR_TX_SET_t;

/**
  * \brief Interrupt mask (DAC_INTR_TX_MASK)
  */
typedef struct stc_DAC_INTR_TX_MASK_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :13;
  uint32_t                         u1FAST_RAMP_COMPLETE:1;
  uint32_t                         u1RAMP_COMPLETE:1;
  uint32_t                         :14;
} stc_DAC_INTR_TX_MASK_field_t;

typedef union un_DAC_INTR_TX_MASK {
  uint32_t                         u32Register;
  stc_DAC_INTR_TX_MASK_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_DAC_INTR_TX_MASK_t;

/**
  * \brief Interrupt masked (DAC_INTR_TX_MASKED)
  */
typedef struct stc_DAC_INTR_TX_MASKED_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :13;
  uint32_t                         u1FAST_RAMP_COMPLETE:1;
  uint32_t                         u1RAMP_COMPLETE:1;
  uint32_t                         :14;
} stc_DAC_INTR_TX_MASKED_field_t;

typedef union un_DAC_INTR_TX_MASKED {
  uint32_t                         u32Register;
  stc_DAC_INTR_TX_MASKED_field_t   stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_DAC_INTR_TX_MASKED_t;

/**
  * \brief TEST control (DAC_TEST_CTL)
  */
typedef struct stc_DAC_TEST_CTL_field {
  uint32_t                         u1TEST_MODE_EN:1;
  uint32_t                         :7;
  uint32_t                         u2DFT_AMUX_SEL_IN_L:2;
  uint32_t                         u2DFT_AMUX_SEL_IN_R:2;
  uint32_t                         u1DFT_AMUX_SEL_OUT:1;
  uint32_t                         :19;
} stc_DAC_TEST_CTL_field_t;

typedef union un_DAC_TEST_CTL {
  uint32_t                         u32Register;
  stc_DAC_TEST_CTL_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_DAC_TEST_CTL_t;

/**
  * \brief TEST Analog Data (DAC_TEST_ANALOG_DATA)
  */
typedef struct stc_DAC_TEST_ANALOG_DATA_field {
  uint32_t                         u10TEST_ANALOG_DATAIN:10;
  uint32_t                         :22;
} stc_DAC_TEST_ANALOG_DATA_field_t;

typedef union un_DAC_TEST_ANALOG_DATA {
  uint32_t                         u32Register;
  stc_DAC_TEST_ANALOG_DATA_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_DAC_TEST_ANALOG_DATA_t;



/**
  * \brief DAC (DAC)
  */
typedef struct stc_DAC {
  un_DAC_CTL_t                     unCTL;              /*!< 0x00000000 Control */
  un_DAC_IF_CTL_t                  unIF_CTL;           /*!< 0x00000004 Interface Control */
  un_DAC_COUNT_t                   unCOUNT;            /*!< 0x00000008 Count */
  uint32_t                         u32Reserved;
  un_DAC_STATUS_t                  unSTATUS;           /*!< 0x00000010 Status */
  uint32_t                         au32Reserved1[27];
  un_DAC_TX_FIFO_CTL_t             unTX_FIFO_CTL;      /*!< 0x00000080 TX FIFO control */
  un_DAC_TX_FIFO_STATUS_t          unTX_FIFO_STATUS;   /*!< 0x00000084 TX FIFO status */
  un_DAC_TX_FIFO_WR_t              unTX_FIFO_WR;       /*!< 0x00000088 TX FIFO write */
  uint32_t                         au32Reserved2[13];
  un_DAC_INTR_TX_t                 unINTR_TX;          /*!< 0x000000C0 Interrupt */
  un_DAC_INTR_TX_SET_t             unINTR_TX_SET;      /*!< 0x000000C4 Interrupt set */
  un_DAC_INTR_TX_MASK_t            unINTR_TX_MASK;     /*!< 0x000000C8 Interrupt mask */
  un_DAC_INTR_TX_MASKED_t          unINTR_TX_MASKED;   /*!< 0x000000CC Interrupt masked */
  uint32_t                         au32Reserved3[8];
  un_DAC_TEST_CTL_t                unTEST_CTL;         /*!< 0x000000F0 TEST control */
  un_DAC_TEST_ANALOG_DATA_t        unTEST_ANALOG_DATA; /*!< 0x000000F4 TEST Analog Data */
} stc_DAC_t;                                           /*!< Size = 248 (0xF8) */


/* DAC.CTL */
#define DAC_CTL_ENABLED_Pos                     31UL
#define DAC_CTL_ENABLED_Msk                     0x80000000UL
/* DAC.IF_CTL */
#define DAC_IF_CTL_CLOCK_DIV_Pos                0UL
#define DAC_IF_CTL_CLOCK_DIV_Msk                0xFFUL
#define DAC_IF_CTL_CLOCK_SEL_Pos                8UL
#define DAC_IF_CTL_CLOCK_SEL_Msk                0x700UL
#define DAC_IF_CTL_FS_SEL_Pos                   16UL
#define DAC_IF_CTL_FS_SEL_Msk                   0x30000UL
#define DAC_IF_CTL_LDATA_POLARITY_Pos           24UL
#define DAC_IF_CTL_LDATA_POLARITY_Msk           0x1000000UL
#define DAC_IF_CTL_RDATA_POLARITY_Pos           25UL
#define DAC_IF_CTL_RDATA_POLARITY_Msk           0x2000000UL
#define DAC_IF_CTL_LDATA_SEL_Pos                26UL
#define DAC_IF_CTL_LDATA_SEL_Msk                0x4000000UL
#define DAC_IF_CTL_RDATA_SEL_Pos                27UL
#define DAC_IF_CTL_RDATA_SEL_Msk                0x8000000UL
#define DAC_IF_CTL_SW_OVERRIDE_FAST_RAMP_EN_Pos 30UL
#define DAC_IF_CTL_SW_OVERRIDE_FAST_RAMP_EN_Msk 0x40000000UL
#define DAC_IF_CTL_DAC_EN_Pos                   31UL
#define DAC_IF_CTL_DAC_EN_Msk                   0x80000000UL
/* DAC.COUNT */
#define DAC_COUNT_COUNT_1MS_Pos                 0UL
#define DAC_COUNT_COUNT_1MS_Msk                 0xFFFFUL
#define DAC_COUNT_FAST_RAMP_COUNT_IN_MS_Pos     16UL
#define DAC_COUNT_FAST_RAMP_COUNT_IN_MS_Msk     0xFF0000UL
#define DAC_COUNT_COMP_RAMP_COUNT_IN_MS_Pos     24UL
#define DAC_COUNT_COMP_RAMP_COUNT_IN_MS_Msk     0xFF000000UL
/* DAC.STATUS */
#define DAC_STATUS_DAC_BUSY_Pos                 0UL
#define DAC_STATUS_DAC_BUSY_Msk                 0x1UL
#define DAC_STATUS_FAST_RAMP_DONE_Pos           16UL
#define DAC_STATUS_FAST_RAMP_DONE_Msk           0x10000UL
#define DAC_STATUS_COMP_RAMP_DONE_Pos           17UL
#define DAC_STATUS_COMP_RAMP_DONE_Msk           0x20000UL
/* DAC.TX_FIFO_CTL */
#define DAC_TX_FIFO_CTL_TRIGGER_LEVEL_Pos       0UL
#define DAC_TX_FIFO_CTL_TRIGGER_LEVEL_Msk       0x3FUL
#define DAC_TX_FIFO_CTL_MUTE_Pos                16UL
#define DAC_TX_FIFO_CTL_MUTE_Msk                0x10000UL
#define DAC_TX_FIFO_CTL_FREEZE_Pos              17UL
#define DAC_TX_FIFO_CTL_FREEZE_Msk              0x20000UL
#define DAC_TX_FIFO_CTL_ACTIVE_Pos              18UL
#define DAC_TX_FIFO_CTL_ACTIVE_Msk              0x40000UL
/* DAC.TX_FIFO_STATUS */
#define DAC_TX_FIFO_STATUS_USED_Pos             0UL
#define DAC_TX_FIFO_STATUS_USED_Msk             0x7FUL
#define DAC_TX_FIFO_STATUS_RD_PTR_Pos           16UL
#define DAC_TX_FIFO_STATUS_RD_PTR_Msk           0x3F0000UL
#define DAC_TX_FIFO_STATUS_WR_PTR_Pos           24UL
#define DAC_TX_FIFO_STATUS_WR_PTR_Msk           0x3F000000UL
/* DAC.TX_FIFO_WR */
#define DAC_TX_FIFO_WR_DATA_Pos                 0UL
#define DAC_TX_FIFO_WR_DATA_Msk                 0xFFFFFFFFUL
/* DAC.INTR_TX */
#define DAC_INTR_TX_FIFO_TRIGGER_Pos            0UL
#define DAC_INTR_TX_FIFO_TRIGGER_Msk            0x1UL
#define DAC_INTR_TX_FIFO_OVERFLOW_Pos           1UL
#define DAC_INTR_TX_FIFO_OVERFLOW_Msk           0x2UL
#define DAC_INTR_TX_FIFO_UNDERFLOW_Pos          2UL
#define DAC_INTR_TX_FIFO_UNDERFLOW_Msk          0x4UL
#define DAC_INTR_TX_FAST_RAMP_COMPLETE_Pos      16UL
#define DAC_INTR_TX_FAST_RAMP_COMPLETE_Msk      0x10000UL
#define DAC_INTR_TX_RAMP_COMPLETE_Pos           17UL
#define DAC_INTR_TX_RAMP_COMPLETE_Msk           0x20000UL
/* DAC.INTR_TX_SET */
#define DAC_INTR_TX_SET_FIFO_TRIGGER_Pos        0UL
#define DAC_INTR_TX_SET_FIFO_TRIGGER_Msk        0x1UL
#define DAC_INTR_TX_SET_FIFO_OVERFLOW_Pos       1UL
#define DAC_INTR_TX_SET_FIFO_OVERFLOW_Msk       0x2UL
#define DAC_INTR_TX_SET_FIFO_UNDERFLOW_Pos      2UL
#define DAC_INTR_TX_SET_FIFO_UNDERFLOW_Msk      0x4UL
#define DAC_INTR_TX_SET_FAST_RAMP_COMPLETE_Pos  16UL
#define DAC_INTR_TX_SET_FAST_RAMP_COMPLETE_Msk  0x10000UL
#define DAC_INTR_TX_SET_RAMP_COMPLETE_Pos       17UL
#define DAC_INTR_TX_SET_RAMP_COMPLETE_Msk       0x20000UL
/* DAC.INTR_TX_MASK */
#define DAC_INTR_TX_MASK_FIFO_TRIGGER_Pos       0UL
#define DAC_INTR_TX_MASK_FIFO_TRIGGER_Msk       0x1UL
#define DAC_INTR_TX_MASK_FIFO_OVERFLOW_Pos      1UL
#define DAC_INTR_TX_MASK_FIFO_OVERFLOW_Msk      0x2UL
#define DAC_INTR_TX_MASK_FIFO_UNDERFLOW_Pos     2UL
#define DAC_INTR_TX_MASK_FIFO_UNDERFLOW_Msk     0x4UL
#define DAC_INTR_TX_MASK_FAST_RAMP_COMPLETE_Pos 16UL
#define DAC_INTR_TX_MASK_FAST_RAMP_COMPLETE_Msk 0x10000UL
#define DAC_INTR_TX_MASK_RAMP_COMPLETE_Pos      17UL
#define DAC_INTR_TX_MASK_RAMP_COMPLETE_Msk      0x20000UL
/* DAC.INTR_TX_MASKED */
#define DAC_INTR_TX_MASKED_FIFO_TRIGGER_Pos     0UL
#define DAC_INTR_TX_MASKED_FIFO_TRIGGER_Msk     0x1UL
#define DAC_INTR_TX_MASKED_FIFO_OVERFLOW_Pos    1UL
#define DAC_INTR_TX_MASKED_FIFO_OVERFLOW_Msk    0x2UL
#define DAC_INTR_TX_MASKED_FIFO_UNDERFLOW_Pos   2UL
#define DAC_INTR_TX_MASKED_FIFO_UNDERFLOW_Msk   0x4UL
#define DAC_INTR_TX_MASKED_FAST_RAMP_COMPLETE_Pos 16UL
#define DAC_INTR_TX_MASKED_FAST_RAMP_COMPLETE_Msk 0x10000UL
#define DAC_INTR_TX_MASKED_RAMP_COMPLETE_Pos    17UL
#define DAC_INTR_TX_MASKED_RAMP_COMPLETE_Msk    0x20000UL
/* DAC.TEST_CTL */
#define DAC_TEST_CTL_TEST_MODE_EN_Pos           0UL
#define DAC_TEST_CTL_TEST_MODE_EN_Msk           0x1UL
#define DAC_TEST_CTL_DFT_AMUX_SEL_IN_L_Pos      8UL
#define DAC_TEST_CTL_DFT_AMUX_SEL_IN_L_Msk      0x300UL
#define DAC_TEST_CTL_DFT_AMUX_SEL_IN_R_Pos      10UL
#define DAC_TEST_CTL_DFT_AMUX_SEL_IN_R_Msk      0xC00UL
#define DAC_TEST_CTL_DFT_AMUX_SEL_OUT_Pos       12UL
#define DAC_TEST_CTL_DFT_AMUX_SEL_OUT_Msk       0x1000UL
/* DAC.TEST_ANALOG_DATA */
#define DAC_TEST_ANALOG_DATA_TEST_ANALOG_DATAIN_Pos 0UL
#define DAC_TEST_ANALOG_DATA_TEST_ANALOG_DATAIN_Msk 0x3FFUL


#endif /* _CYIP_DAC_H_ */


/* [] END OF FILE */
