/***************************************************************************//**
* \file cyip_pwm.h
*
* \brief
* PWM IP definitions
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

#ifndef _CYIP_PWM_H_
#define _CYIP_PWM_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     PWM
*******************************************************************************/

#define PWM_TX_SECTION_SIZE                     0x00000100UL
#define PWM_SECTION_SIZE                        0x00010000UL

/**
  * \brief Control (PWM_TX_CTL)
  */
typedef struct stc_PWM_TX_CTL_field {
  uint32_t                         u4WORD_SIZE:4;
  uint32_t                         :27;
  uint32_t                         u1ENABLED:1;
} stc_PWM_TX_CTL_field_t;

typedef union un_PWM_TX_CTL {
  uint32_t                         u32Register;
  stc_PWM_TX_CTL_field_t           stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PWM_TX_CTL_t;

/**
  * \brief Interface control (PWM_TX_IF_CTL)
  */
typedef struct stc_PWM_TX_IF_CTL_field {
  uint32_t                         u8CLOCK_DIV:8;
  uint32_t                         u3CLOCK_SEL:3;
  uint32_t                         :1;
  uint32_t                         u4LINE_POLARITY:4;
  uint32_t                         :16;
} stc_PWM_TX_IF_CTL_field_t;

typedef union un_PWM_TX_IF_CTL {
  uint32_t                         u32Register;
  stc_PWM_TX_IF_CTL_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PWM_TX_IF_CTL_t;

/**
  * \brief Double control (PWM_TX_DOUBLE_CTL)
  */
typedef struct stc_PWM_TX_DOUBLE_CTL_field {
  uint32_t                         u1MODE:1;
  uint32_t                         :30;
  uint32_t                         u1ENABLED:1;
} stc_PWM_TX_DOUBLE_CTL_field_t;

typedef union un_PWM_TX_DOUBLE_CTL {
  uint32_t                         u32Register;
  stc_PWM_TX_DOUBLE_CTL_field_t    stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PWM_TX_DOUBLE_CTL_t;

/**
  * \brief Gain control (PWM_TX_GAIN_CTL)
  */
typedef struct stc_PWM_TX_GAIN_CTL_field {
  uint32_t                         u7CODE:7;
  uint32_t                         :25;
} stc_PWM_TX_GAIN_CTL_field_t;

typedef union un_PWM_TX_GAIN_CTL {
  uint32_t                         u32Register;
  stc_PWM_TX_GAIN_CTL_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PWM_TX_GAIN_CTL_t;

/**
  * \brief PWM control 0 (PWM_TX_PWM_CTL0)
  */
typedef struct stc_PWM_TX_PWM_CTL0_field {
  uint32_t                         u2FORMAT:2;
  uint32_t                         :14;
  uint32_t                         u4SCALE:4;
  uint32_t                         :12;
} stc_PWM_TX_PWM_CTL0_field_t;

typedef union un_PWM_TX_PWM_CTL0 {
  uint32_t                         u32Register;
  stc_PWM_TX_PWM_CTL0_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PWM_TX_PWM_CTL0_t;

/**
  * \brief PWM control 1 (PWM_TX_PWM_CTL1)
  */
typedef struct stc_PWM_TX_PWM_CTL1_field {
  uint32_t                         u16MIN:16;
  uint32_t                         u16MAX:16;
} stc_PWM_TX_PWM_CTL1_field_t;

typedef union un_PWM_TX_PWM_CTL1 {
  uint32_t                         u32Register;
  stc_PWM_TX_PWM_CTL1_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PWM_TX_PWM_CTL1_t;

/**
  * \brief PWM control 2 (PWM_TX_PWM_CTL2)
  */
typedef struct stc_PWM_TX_PWM_CTL2_field {
  uint32_t                         u16PERIOD:16;
  uint32_t                         u16OFFSET:16;
} stc_PWM_TX_PWM_CTL2_field_t;

typedef union un_PWM_TX_PWM_CTL2 {
  uint32_t                         u32Register;
  stc_PWM_TX_PWM_CTL2_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PWM_TX_PWM_CTL2_t;

/**
  * \brief PWM control 3 (PWM_TX_PWM_CTL3)
  */
typedef struct stc_PWM_TX_PWM_CTL3_field {
  uint32_t                         u16DT:16;
  uint32_t                         :16;
} stc_PWM_TX_PWM_CTL3_field_t;

typedef union un_PWM_TX_PWM_CTL3 {
  uint32_t                         u32Register;
  stc_PWM_TX_PWM_CTL3_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PWM_TX_PWM_CTL3_t;

/**
  * \brief TX FIFO control (PWM_TX_TX_FIFO_CTL)
  */
typedef struct stc_PWM_TX_TX_FIFO_CTL_field {
  uint32_t                         u6TRIGGER_LEVEL:6;
  uint32_t                         :10;
  uint32_t                         u1MUTE:1;
  uint32_t                         u1FREEZE:1;
  uint32_t                         :14;
} stc_PWM_TX_TX_FIFO_CTL_field_t;

typedef union un_PWM_TX_TX_FIFO_CTL {
  uint32_t                         u32Register;
  stc_PWM_TX_TX_FIFO_CTL_field_t   stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PWM_TX_TX_FIFO_CTL_t;

/**
  * \brief TX FIFO status (PWM_TX_TX_FIFO_STATUS)
  */
typedef struct stc_PWM_TX_TX_FIFO_STATUS_field {
  uint32_t                         u7USED:7;
  uint32_t                         :9;
  uint32_t                         u6RD_PTR:6;
  uint32_t                         :2;
  uint32_t                         u6WR_PTR:6;
  uint32_t                         :2;
} stc_PWM_TX_TX_FIFO_STATUS_field_t;

typedef union un_PWM_TX_TX_FIFO_STATUS {
  uint32_t                         u32Register;
  stc_PWM_TX_TX_FIFO_STATUS_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PWM_TX_TX_FIFO_STATUS_t;

/**
  * \brief TX FIFO write (PWM_TX_TX_FIFO_WR)
  */
typedef struct stc_PWM_TX_TX_FIFO_WR_field {
  uint32_t                         u32DATA:32;
} stc_PWM_TX_TX_FIFO_WR_field_t;

typedef union un_PWM_TX_TX_FIFO_WR {
  uint32_t                         u32Register;
  stc_PWM_TX_TX_FIFO_WR_field_t    stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PWM_TX_TX_FIFO_WR_t;

/**
  * \brief Interrupt (PWM_TX_INTR_TX)
  */
typedef struct stc_PWM_TX_INTR_TX_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_PWM_TX_INTR_TX_field_t;

typedef union un_PWM_TX_INTR_TX {
  uint32_t                         u32Register;
  stc_PWM_TX_INTR_TX_field_t       stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PWM_TX_INTR_TX_t;

/**
  * \brief Interrupt set (PWM_TX_INTR_TX_SET)
  */
typedef struct stc_PWM_TX_INTR_TX_SET_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_PWM_TX_INTR_TX_SET_field_t;

typedef union un_PWM_TX_INTR_TX_SET {
  uint32_t                         u32Register;
  stc_PWM_TX_INTR_TX_SET_field_t   stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PWM_TX_INTR_TX_SET_t;

/**
  * \brief Interrupt mask (PWM_TX_INTR_TX_MASK)
  */
typedef struct stc_PWM_TX_INTR_TX_MASK_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_PWM_TX_INTR_TX_MASK_field_t;

typedef union un_PWM_TX_INTR_TX_MASK {
  uint32_t                         u32Register;
  stc_PWM_TX_INTR_TX_MASK_field_t  stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PWM_TX_INTR_TX_MASK_t;

/**
  * \brief Interrupt masked (PWM_TX_INTR_TX_MASKED)
  */
typedef struct stc_PWM_TX_INTR_TX_MASKED_field {
  uint32_t                         u1FIFO_TRIGGER:1;
  uint32_t                         u1FIFO_OVERFLOW:1;
  uint32_t                         u1FIFO_UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_PWM_TX_INTR_TX_MASKED_field_t;

typedef union un_PWM_TX_INTR_TX_MASKED {
  uint32_t                         u32Register;
  stc_PWM_TX_INTR_TX_MASKED_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PWM_TX_INTR_TX_MASKED_t;



/**
  * \brief Control (PWM_CTL)
  */
typedef struct stc_PWM_CTL_field {
  uint32_t                         u8ACTIVE:8;
  uint32_t                         :24;
} stc_PWM_CTL_field_t;

typedef union un_PWM_CTL {
  uint32_t                         u32Register;
  stc_PWM_CTL_field_t              stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PWM_CTL_t;

/**
  * \brief Control clear (PWM_CTL_CLR)
  */
typedef struct stc_PWM_CTL_CLR_field {
  uint32_t                         u8ACTIVE:8;
  uint32_t                         :24;
} stc_PWM_CTL_CLR_field_t;

typedef union un_PWM_CTL_CLR {
  uint32_t                         u32Register;
  stc_PWM_CTL_CLR_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PWM_CTL_CLR_t;

/**
  * \brief Control set (PWM_CTL_SET)
  */
typedef struct stc_PWM_CTL_SET_field {
  uint32_t                         u8ACTIVE:8;
  uint32_t                         :24;
} stc_PWM_CTL_SET_field_t;

typedef union un_PWM_CTL_SET {
  uint32_t                         u32Register;
  stc_PWM_CTL_SET_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_PWM_CTL_SET_t;



/**
  * \brief PWM structure (PWM_TX)
  */
typedef struct stc_PWM_TX {
  un_PWM_TX_CTL_t                  unCTL;              /*!< 0x00000000 Control */
  uint32_t                         au32Reserved[3];
  un_PWM_TX_IF_CTL_t               unIF_CTL;           /*!< 0x00000010 Interface control */
  un_PWM_TX_DOUBLE_CTL_t           unDOUBLE_CTL;       /*!< 0x00000014 Double control */
  un_PWM_TX_GAIN_CTL_t             unGAIN_CTL;         /*!< 0x00000018 Gain control */
  uint32_t                         u32Reserved1;
  un_PWM_TX_PWM_CTL0_t             unPWM_CTL0;         /*!< 0x00000020 PWM control 0 */
  un_PWM_TX_PWM_CTL1_t             unPWM_CTL1;         /*!< 0x00000024 PWM control 1 */
  un_PWM_TX_PWM_CTL2_t             unPWM_CTL2;         /*!< 0x00000028 PWM control 2 */
  un_PWM_TX_PWM_CTL3_t             unPWM_CTL3;         /*!< 0x0000002C PWM control 3 */
  uint32_t                         au32Reserved2[20];
  un_PWM_TX_TX_FIFO_CTL_t          unTX_FIFO_CTL;      /*!< 0x00000080 TX FIFO control */
  un_PWM_TX_TX_FIFO_STATUS_t       unTX_FIFO_STATUS;   /*!< 0x00000084 TX FIFO status */
  un_PWM_TX_TX_FIFO_WR_t           unTX_FIFO_WR;       /*!< 0x00000088 TX FIFO write */
  uint32_t                         au32Reserved3[13];
  un_PWM_TX_INTR_TX_t              unINTR_TX;          /*!< 0x000000C0 Interrupt */
  un_PWM_TX_INTR_TX_SET_t          unINTR_TX_SET;      /*!< 0x000000C4 Interrupt set */
  un_PWM_TX_INTR_TX_MASK_t         unINTR_TX_MASK;     /*!< 0x000000C8 Interrupt mask */
  un_PWM_TX_INTR_TX_MASKED_t       unINTR_TX_MASKED;   /*!< 0x000000CC Interrupt masked */
  uint32_t                         au32Reserved4[12];
} stc_PWM_TX_t;                                        /*!< Size = 256 (0x100) */

/**
  * \brief PWM (PWM)
  */
typedef struct stc_PWM {
  un_PWM_CTL_t                     unCTL;              /*!< 0x00000000 Control */
  un_PWM_CTL_CLR_t                 unCTL_CLR;          /*!< 0x00000004 Control clear */
  un_PWM_CTL_SET_t                 unCTL_SET;          /*!< 0x00000008 Control set */
  uint32_t                         au32Reserved[8189];
  stc_PWM_TX_t                     TX[8];              /*!< 0x00008000 PWM structure */
} stc_PWM_t;                                           /*!< Size = 34816 (0x8800) */


/* PWM_TX.CTL */
#define PWM_TX_CTL_WORD_SIZE_Pos                0UL
#define PWM_TX_CTL_WORD_SIZE_Msk                0xFUL
#define PWM_TX_CTL_ENABLED_Pos                  31UL
#define PWM_TX_CTL_ENABLED_Msk                  0x80000000UL
/* PWM_TX.IF_CTL */
#define PWM_TX_IF_CTL_CLOCK_DIV_Pos             0UL
#define PWM_TX_IF_CTL_CLOCK_DIV_Msk             0xFFUL
#define PWM_TX_IF_CTL_CLOCK_SEL_Pos             8UL
#define PWM_TX_IF_CTL_CLOCK_SEL_Msk             0x700UL
#define PWM_TX_IF_CTL_LINE_POLARITY_Pos         12UL
#define PWM_TX_IF_CTL_LINE_POLARITY_Msk         0xF000UL
/* PWM_TX.DOUBLE_CTL */
#define PWM_TX_DOUBLE_CTL_MODE_Pos              0UL
#define PWM_TX_DOUBLE_CTL_MODE_Msk              0x1UL
#define PWM_TX_DOUBLE_CTL_ENABLED_Pos           31UL
#define PWM_TX_DOUBLE_CTL_ENABLED_Msk           0x80000000UL
/* PWM_TX.GAIN_CTL */
#define PWM_TX_GAIN_CTL_CODE_Pos                0UL
#define PWM_TX_GAIN_CTL_CODE_Msk                0x7FUL
/* PWM_TX.PWM_CTL0 */
#define PWM_TX_PWM_CTL0_FORMAT_Pos              0UL
#define PWM_TX_PWM_CTL0_FORMAT_Msk              0x3UL
#define PWM_TX_PWM_CTL0_SCALE_Pos               16UL
#define PWM_TX_PWM_CTL0_SCALE_Msk               0xF0000UL
/* PWM_TX.PWM_CTL1 */
#define PWM_TX_PWM_CTL1_MIN_Pos                 0UL
#define PWM_TX_PWM_CTL1_MIN_Msk                 0xFFFFUL
#define PWM_TX_PWM_CTL1_MAX_Pos                 16UL
#define PWM_TX_PWM_CTL1_MAX_Msk                 0xFFFF0000UL
/* PWM_TX.PWM_CTL2 */
#define PWM_TX_PWM_CTL2_PERIOD_Pos              0UL
#define PWM_TX_PWM_CTL2_PERIOD_Msk              0xFFFFUL
#define PWM_TX_PWM_CTL2_OFFSET_Pos              16UL
#define PWM_TX_PWM_CTL2_OFFSET_Msk              0xFFFF0000UL
/* PWM_TX.PWM_CTL3 */
#define PWM_TX_PWM_CTL3_DT_Pos                  0UL
#define PWM_TX_PWM_CTL3_DT_Msk                  0xFFFFUL
/* PWM_TX.TX_FIFO_CTL */
#define PWM_TX_TX_FIFO_CTL_TRIGGER_LEVEL_Pos    0UL
#define PWM_TX_TX_FIFO_CTL_TRIGGER_LEVEL_Msk    0x3FUL
#define PWM_TX_TX_FIFO_CTL_MUTE_Pos             16UL
#define PWM_TX_TX_FIFO_CTL_MUTE_Msk             0x10000UL
#define PWM_TX_TX_FIFO_CTL_FREEZE_Pos           17UL
#define PWM_TX_TX_FIFO_CTL_FREEZE_Msk           0x20000UL
/* PWM_TX.TX_FIFO_STATUS */
#define PWM_TX_TX_FIFO_STATUS_USED_Pos          0UL
#define PWM_TX_TX_FIFO_STATUS_USED_Msk          0x7FUL
#define PWM_TX_TX_FIFO_STATUS_RD_PTR_Pos        16UL
#define PWM_TX_TX_FIFO_STATUS_RD_PTR_Msk        0x3F0000UL
#define PWM_TX_TX_FIFO_STATUS_WR_PTR_Pos        24UL
#define PWM_TX_TX_FIFO_STATUS_WR_PTR_Msk        0x3F000000UL
/* PWM_TX.TX_FIFO_WR */
#define PWM_TX_TX_FIFO_WR_DATA_Pos              0UL
#define PWM_TX_TX_FIFO_WR_DATA_Msk              0xFFFFFFFFUL
/* PWM_TX.INTR_TX */
#define PWM_TX_INTR_TX_FIFO_TRIGGER_Pos         0UL
#define PWM_TX_INTR_TX_FIFO_TRIGGER_Msk         0x1UL
#define PWM_TX_INTR_TX_FIFO_OVERFLOW_Pos        1UL
#define PWM_TX_INTR_TX_FIFO_OVERFLOW_Msk        0x2UL
#define PWM_TX_INTR_TX_FIFO_UNDERFLOW_Pos       2UL
#define PWM_TX_INTR_TX_FIFO_UNDERFLOW_Msk       0x4UL
#define PWM_TX_INTR_TX_IF_UNDERFLOW_Pos         8UL
#define PWM_TX_INTR_TX_IF_UNDERFLOW_Msk         0x100UL
/* PWM_TX.INTR_TX_SET */
#define PWM_TX_INTR_TX_SET_FIFO_TRIGGER_Pos     0UL
#define PWM_TX_INTR_TX_SET_FIFO_TRIGGER_Msk     0x1UL
#define PWM_TX_INTR_TX_SET_FIFO_OVERFLOW_Pos    1UL
#define PWM_TX_INTR_TX_SET_FIFO_OVERFLOW_Msk    0x2UL
#define PWM_TX_INTR_TX_SET_FIFO_UNDERFLOW_Pos   2UL
#define PWM_TX_INTR_TX_SET_FIFO_UNDERFLOW_Msk   0x4UL
#define PWM_TX_INTR_TX_SET_IF_UNDERFLOW_Pos     8UL
#define PWM_TX_INTR_TX_SET_IF_UNDERFLOW_Msk     0x100UL
/* PWM_TX.INTR_TX_MASK */
#define PWM_TX_INTR_TX_MASK_FIFO_TRIGGER_Pos    0UL
#define PWM_TX_INTR_TX_MASK_FIFO_TRIGGER_Msk    0x1UL
#define PWM_TX_INTR_TX_MASK_FIFO_OVERFLOW_Pos   1UL
#define PWM_TX_INTR_TX_MASK_FIFO_OVERFLOW_Msk   0x2UL
#define PWM_TX_INTR_TX_MASK_FIFO_UNDERFLOW_Pos  2UL
#define PWM_TX_INTR_TX_MASK_FIFO_UNDERFLOW_Msk  0x4UL
#define PWM_TX_INTR_TX_MASK_IF_UNDERFLOW_Pos    8UL
#define PWM_TX_INTR_TX_MASK_IF_UNDERFLOW_Msk    0x100UL
/* PWM_TX.INTR_TX_MASKED */
#define PWM_TX_INTR_TX_MASKED_FIFO_TRIGGER_Pos  0UL
#define PWM_TX_INTR_TX_MASKED_FIFO_TRIGGER_Msk  0x1UL
#define PWM_TX_INTR_TX_MASKED_FIFO_OVERFLOW_Pos 1UL
#define PWM_TX_INTR_TX_MASKED_FIFO_OVERFLOW_Msk 0x2UL
#define PWM_TX_INTR_TX_MASKED_FIFO_UNDERFLOW_Pos 2UL
#define PWM_TX_INTR_TX_MASKED_FIFO_UNDERFLOW_Msk 0x4UL
#define PWM_TX_INTR_TX_MASKED_IF_UNDERFLOW_Pos  8UL
#define PWM_TX_INTR_TX_MASKED_IF_UNDERFLOW_Msk  0x100UL


/* PWM.CTL */
#define PWM_CTL_ACTIVE_Pos                      0UL
#define PWM_CTL_ACTIVE_Msk                      0xFFUL
/* PWM.CTL_CLR */
#define PWM_CTL_CLR_ACTIVE_Pos                  0UL
#define PWM_CTL_CLR_ACTIVE_Msk                  0xFFUL
/* PWM.CTL_SET */
#define PWM_CTL_SET_ACTIVE_Pos                  0UL
#define PWM_CTL_SET_ACTIVE_Msk                  0xFFUL


#endif /* _CYIP_PWM_H_ */


/* [] END OF FILE */
