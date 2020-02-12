/***************************************************************************//**
* \file cyip_sg.h
*
* \brief
* SG IP definitions
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

#ifndef _CYIP_SG_H_
#define _CYIP_SG_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                      SG
*******************************************************************************/

#define SG_SG_STRUCT_SECTION_SIZE               0x00000100UL
#define SG_SECTION_SIZE                         0x00010000UL

/**
  * \brief Source control (SG_SG_STRUCT_CTL)
  */
typedef struct stc_SG_SG_STRUCT_CTL_field {
  uint32_t                         u1FORMAT:1;
  uint32_t                         :17;
  uint32_t                         u1ACTIVE:1;
  uint32_t                         :12;
  uint32_t                         u1ENABLED:1;
} stc_SG_SG_STRUCT_CTL_field_t;

typedef union un_SG_SG_STRUCT_CTL {
  uint32_t                         u32Register;
  stc_SG_SG_STRUCT_CTL_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SG_SG_STRUCT_CTL_t;

/**
  * \brief Interface control (SG_SG_STRUCT_IF_CTL)
  */
typedef struct stc_SG_SG_STRUCT_IF_CTL_field {
  uint32_t                         u8CLOCK_DIV:8;
  uint32_t                         u3CLOCK_SEL:3;
  uint32_t                         :21;
} stc_SG_SG_STRUCT_IF_CTL_field_t;

typedef union un_SG_SG_STRUCT_IF_CTL {
  uint32_t                         u32Register;
  stc_SG_SG_STRUCT_IF_CTL_field_t  stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SG_SG_STRUCT_IF_CTL_t;

/**
  * \brief Time control (SG_SG_STRUCT_TIME_CTL)
  */
typedef struct stc_SG_SG_STRUCT_TIME_CTL_field {
  uint32_t                         u8PERIOD8:8;
  uint32_t                         :8;
  uint32_t                         u8NR:8;
  uint32_t                         :8;
} stc_SG_SG_STRUCT_TIME_CTL_field_t;

typedef union un_SG_SG_STRUCT_TIME_CTL {
  uint32_t                         u32Register;
  stc_SG_SG_STRUCT_TIME_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SG_SG_STRUCT_TIME_CTL_t;

/**
  * \brief Tone control (SG_SG_STRUCT_TONE_CTL)
  */
typedef struct stc_SG_SG_STRUCT_TONE_CTL_field {
  uint32_t                         u8PERIOD8:8;
  uint32_t                         :8;
  uint32_t                         u8HIGH8:8;
  uint32_t                         :8;
} stc_SG_SG_STRUCT_TONE_CTL_field_t;

typedef union un_SG_SG_STRUCT_TONE_CTL {
  uint32_t                         u32Register;
  stc_SG_SG_STRUCT_TONE_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SG_SG_STRUCT_TONE_CTL_t;

/**
  * \brief Amplitude control (SG_SG_STRUCT_AMPL_CTL)
  */
typedef struct stc_SG_SG_STRUCT_AMPL_CTL_field {
  uint32_t                         u16PERIOD16:16;
  uint32_t                         u16HIGH16:16;
} stc_SG_SG_STRUCT_AMPL_CTL_field_t;

typedef union un_SG_SG_STRUCT_AMPL_CTL {
  uint32_t                         u32Register;
  stc_SG_SG_STRUCT_AMPL_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SG_SG_STRUCT_AMPL_CTL_t;

/**
  * \brief Step control (SG_SG_STRUCT_STEP_CTL)
  */
typedef struct stc_SG_SG_STRUCT_STEP_CTL_field {
  uint32_t                         u16STEP:16;
  uint32_t                         :15;
  uint32_t                         u1VALID:1;
} stc_SG_SG_STRUCT_STEP_CTL_field_t;

typedef union un_SG_SG_STRUCT_STEP_CTL {
  uint32_t                         u32Register;
  stc_SG_SG_STRUCT_STEP_CTL_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SG_SG_STRUCT_STEP_CTL_t;

/**
  * \brief Buffered time control (SG_SG_STRUCT_TIME_CTL_BUFF)
  */
typedef struct stc_SG_SG_STRUCT_TIME_CTL_BUFF_field {
  uint32_t                         u8PERIOD8:8;
  uint32_t                         :8;
  uint32_t                         u8NR:8;
  uint32_t                         :8;
} stc_SG_SG_STRUCT_TIME_CTL_BUFF_field_t;

typedef union un_SG_SG_STRUCT_TIME_CTL_BUFF {
  uint32_t                         u32Register;
  stc_SG_SG_STRUCT_TIME_CTL_BUFF_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SG_SG_STRUCT_TIME_CTL_BUFF_t;

/**
  * \brief Buffered tone control (SG_SG_STRUCT_TONE_CTL_BUFF)
  */
typedef struct stc_SG_SG_STRUCT_TONE_CTL_BUFF_field {
  uint32_t                         u8PERIOD8:8;
  uint32_t                         :8;
  uint32_t                         u8HIGH8:8;
  uint32_t                         :8;
} stc_SG_SG_STRUCT_TONE_CTL_BUFF_field_t;

typedef union un_SG_SG_STRUCT_TONE_CTL_BUFF {
  uint32_t                         u32Register;
  stc_SG_SG_STRUCT_TONE_CTL_BUFF_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SG_SG_STRUCT_TONE_CTL_BUFF_t;

/**
  * \brief Buffered amplitude control (SG_SG_STRUCT_AMPL_CTL_BUFF)
  */
typedef struct stc_SG_SG_STRUCT_AMPL_CTL_BUFF_field {
  uint32_t                         u16PERIOD16:16;
  uint32_t                         u16HIGH16:16;
} stc_SG_SG_STRUCT_AMPL_CTL_BUFF_field_t;

typedef union un_SG_SG_STRUCT_AMPL_CTL_BUFF {
  uint32_t                         u32Register;
  stc_SG_SG_STRUCT_AMPL_CTL_BUFF_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SG_SG_STRUCT_AMPL_CTL_BUFF_t;

/**
  * \brief Buffered step control (SG_SG_STRUCT_STEP_CTL_BUFF)
  */
typedef struct stc_SG_SG_STRUCT_STEP_CTL_BUFF_field {
  uint32_t                         u16STEP:16;
  uint32_t                         :15;
  uint32_t                         u1VALID:1;
} stc_SG_SG_STRUCT_STEP_CTL_BUFF_field_t;

typedef union un_SG_SG_STRUCT_STEP_CTL_BUFF {
  uint32_t                         u32Register;
  stc_SG_SG_STRUCT_STEP_CTL_BUFF_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SG_SG_STRUCT_STEP_CTL_BUFF_t;

/**
  * \brief Interrupt (SG_SG_STRUCT_INTR_TX)
  */
typedef struct stc_SG_SG_STRUCT_INTR_TX_field {
  uint32_t                         u1COMPLETE:1;
  uint32_t                         :1;
  uint32_t                         u1UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_SG_SG_STRUCT_INTR_TX_field_t;

typedef union un_SG_SG_STRUCT_INTR_TX {
  uint32_t                         u32Register;
  stc_SG_SG_STRUCT_INTR_TX_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SG_SG_STRUCT_INTR_TX_t;

/**
  * \brief Interrupt set (SG_SG_STRUCT_INTR_TX_SET)
  */
typedef struct stc_SG_SG_STRUCT_INTR_TX_SET_field {
  uint32_t                         u1COMPLETE:1;
  uint32_t                         :1;
  uint32_t                         u1UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_SG_SG_STRUCT_INTR_TX_SET_field_t;

typedef union un_SG_SG_STRUCT_INTR_TX_SET {
  uint32_t                         u32Register;
  stc_SG_SG_STRUCT_INTR_TX_SET_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SG_SG_STRUCT_INTR_TX_SET_t;

/**
  * \brief Interrupt mask (SG_SG_STRUCT_INTR_TX_MASK)
  */
typedef struct stc_SG_SG_STRUCT_INTR_TX_MASK_field {
  uint32_t                         u1COMPLETE:1;
  uint32_t                         :1;
  uint32_t                         u1UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_SG_SG_STRUCT_INTR_TX_MASK_field_t;

typedef union un_SG_SG_STRUCT_INTR_TX_MASK {
  uint32_t                         u32Register;
  stc_SG_SG_STRUCT_INTR_TX_MASK_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SG_SG_STRUCT_INTR_TX_MASK_t;

/**
  * \brief Interrupt masked (SG_SG_STRUCT_INTR_TX_MASKED)
  */
typedef struct stc_SG_SG_STRUCT_INTR_TX_MASKED_field {
  uint32_t                         u1COMPLETE:1;
  uint32_t                         :1;
  uint32_t                         u1UNDERFLOW:1;
  uint32_t                         :5;
  uint32_t                         u1IF_UNDERFLOW:1;
  uint32_t                         :23;
} stc_SG_SG_STRUCT_INTR_TX_MASKED_field_t;

typedef union un_SG_SG_STRUCT_INTR_TX_MASKED {
  uint32_t                         u32Register;
  stc_SG_SG_STRUCT_INTR_TX_MASKED_field_t stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_SG_SG_STRUCT_INTR_TX_MASKED_t;



/**
  * \brief Sound generator structure (SG_SG_STRUCT)
  */
typedef struct stc_SG_SG_STRUCT {
  un_SG_SG_STRUCT_CTL_t            unCTL;              /*!< 0x00000000 Source control */
  uint32_t                         au32Reserved[3];
  un_SG_SG_STRUCT_IF_CTL_t         unIF_CTL;           /*!< 0x00000010 Interface control */
  uint32_t                         au32Reserved1[3];
  un_SG_SG_STRUCT_TIME_CTL_t       unTIME_CTL;         /*!< 0x00000020 Time control */
  un_SG_SG_STRUCT_TONE_CTL_t       unTONE_CTL;         /*!< 0x00000024 Tone control */
  un_SG_SG_STRUCT_AMPL_CTL_t       unAMPL_CTL;         /*!< 0x00000028 Amplitude control */
  un_SG_SG_STRUCT_STEP_CTL_t       unSTEP_CTL;         /*!< 0x0000002C Step control */
  un_SG_SG_STRUCT_TIME_CTL_BUFF_t  unTIME_CTL_BUFF;    /*!< 0x00000030 Buffered time control */
  un_SG_SG_STRUCT_TONE_CTL_BUFF_t  unTONE_CTL_BUFF;    /*!< 0x00000034 Buffered tone control */
  un_SG_SG_STRUCT_AMPL_CTL_BUFF_t  unAMPL_CTL_BUFF;    /*!< 0x00000038 Buffered amplitude control */
  un_SG_SG_STRUCT_STEP_CTL_BUFF_t  unSTEP_CTL_BUFF;    /*!< 0x0000003C Buffered step control */
  uint32_t                         au32Reserved2[32];
  un_SG_SG_STRUCT_INTR_TX_t        unINTR_TX;          /*!< 0x000000C0 Interrupt */
  un_SG_SG_STRUCT_INTR_TX_SET_t    unINTR_TX_SET;      /*!< 0x000000C4 Interrupt set */
  un_SG_SG_STRUCT_INTR_TX_MASK_t   unINTR_TX_MASK;     /*!< 0x000000C8 Interrupt mask */
  un_SG_SG_STRUCT_INTR_TX_MASKED_t unINTR_TX_MASKED;   /*!< 0x000000CC Interrupt masked */
  uint32_t                         au32Reserved3[12];
} stc_SG_SG_STRUCT_t;                                  /*!< Size = 256 (0x100) */

/**
  * \brief SG (SG)
  */
typedef struct stc_SG {
  uint32_t                         au32Reserved[8192];
  stc_SG_SG_STRUCT_t               SG_STRUCT[8];       /*!< 0x00008000 Sound generator structure */
} stc_SG_t;                                            /*!< Size = 34816 (0x8800) */


/* SG_SG_STRUCT.CTL */
#define SG_SG_STRUCT_CTL_FORMAT_Pos             0UL
#define SG_SG_STRUCT_CTL_FORMAT_Msk             0x1UL
#define SG_SG_STRUCT_CTL_ACTIVE_Pos             18UL
#define SG_SG_STRUCT_CTL_ACTIVE_Msk             0x40000UL
#define SG_SG_STRUCT_CTL_ENABLED_Pos            31UL
#define SG_SG_STRUCT_CTL_ENABLED_Msk            0x80000000UL
/* SG_SG_STRUCT.IF_CTL */
#define SG_SG_STRUCT_IF_CTL_CLOCK_DIV_Pos       0UL
#define SG_SG_STRUCT_IF_CTL_CLOCK_DIV_Msk       0xFFUL
#define SG_SG_STRUCT_IF_CTL_CLOCK_SEL_Pos       8UL
#define SG_SG_STRUCT_IF_CTL_CLOCK_SEL_Msk       0x700UL
/* SG_SG_STRUCT.TIME_CTL */
#define SG_SG_STRUCT_TIME_CTL_PERIOD8_Pos       0UL
#define SG_SG_STRUCT_TIME_CTL_PERIOD8_Msk       0xFFUL
#define SG_SG_STRUCT_TIME_CTL_NR_Pos            16UL
#define SG_SG_STRUCT_TIME_CTL_NR_Msk            0xFF0000UL
/* SG_SG_STRUCT.TONE_CTL */
#define SG_SG_STRUCT_TONE_CTL_PERIOD8_Pos       0UL
#define SG_SG_STRUCT_TONE_CTL_PERIOD8_Msk       0xFFUL
#define SG_SG_STRUCT_TONE_CTL_HIGH8_Pos         16UL
#define SG_SG_STRUCT_TONE_CTL_HIGH8_Msk         0xFF0000UL
/* SG_SG_STRUCT.AMPL_CTL */
#define SG_SG_STRUCT_AMPL_CTL_PERIOD16_Pos      0UL
#define SG_SG_STRUCT_AMPL_CTL_PERIOD16_Msk      0xFFFFUL
#define SG_SG_STRUCT_AMPL_CTL_HIGH16_Pos        16UL
#define SG_SG_STRUCT_AMPL_CTL_HIGH16_Msk        0xFFFF0000UL
/* SG_SG_STRUCT.STEP_CTL */
#define SG_SG_STRUCT_STEP_CTL_STEP_Pos          0UL
#define SG_SG_STRUCT_STEP_CTL_STEP_Msk          0xFFFFUL
#define SG_SG_STRUCT_STEP_CTL_VALID_Pos         31UL
#define SG_SG_STRUCT_STEP_CTL_VALID_Msk         0x80000000UL
/* SG_SG_STRUCT.TIME_CTL_BUFF */
#define SG_SG_STRUCT_TIME_CTL_BUFF_PERIOD8_Pos  0UL
#define SG_SG_STRUCT_TIME_CTL_BUFF_PERIOD8_Msk  0xFFUL
#define SG_SG_STRUCT_TIME_CTL_BUFF_NR_Pos       16UL
#define SG_SG_STRUCT_TIME_CTL_BUFF_NR_Msk       0xFF0000UL
/* SG_SG_STRUCT.TONE_CTL_BUFF */
#define SG_SG_STRUCT_TONE_CTL_BUFF_PERIOD8_Pos  0UL
#define SG_SG_STRUCT_TONE_CTL_BUFF_PERIOD8_Msk  0xFFUL
#define SG_SG_STRUCT_TONE_CTL_BUFF_HIGH8_Pos    16UL
#define SG_SG_STRUCT_TONE_CTL_BUFF_HIGH8_Msk    0xFF0000UL
/* SG_SG_STRUCT.AMPL_CTL_BUFF */
#define SG_SG_STRUCT_AMPL_CTL_BUFF_PERIOD16_Pos 0UL
#define SG_SG_STRUCT_AMPL_CTL_BUFF_PERIOD16_Msk 0xFFFFUL
#define SG_SG_STRUCT_AMPL_CTL_BUFF_HIGH16_Pos   16UL
#define SG_SG_STRUCT_AMPL_CTL_BUFF_HIGH16_Msk   0xFFFF0000UL
/* SG_SG_STRUCT.STEP_CTL_BUFF */
#define SG_SG_STRUCT_STEP_CTL_BUFF_STEP_Pos     0UL
#define SG_SG_STRUCT_STEP_CTL_BUFF_STEP_Msk     0xFFFFUL
#define SG_SG_STRUCT_STEP_CTL_BUFF_VALID_Pos    31UL
#define SG_SG_STRUCT_STEP_CTL_BUFF_VALID_Msk    0x80000000UL
/* SG_SG_STRUCT.INTR_TX */
#define SG_SG_STRUCT_INTR_TX_COMPLETE_Pos       0UL
#define SG_SG_STRUCT_INTR_TX_COMPLETE_Msk       0x1UL
#define SG_SG_STRUCT_INTR_TX_UNDERFLOW_Pos      2UL
#define SG_SG_STRUCT_INTR_TX_UNDERFLOW_Msk      0x4UL
#define SG_SG_STRUCT_INTR_TX_IF_UNDERFLOW_Pos   8UL
#define SG_SG_STRUCT_INTR_TX_IF_UNDERFLOW_Msk   0x100UL
/* SG_SG_STRUCT.INTR_TX_SET */
#define SG_SG_STRUCT_INTR_TX_SET_COMPLETE_Pos   0UL
#define SG_SG_STRUCT_INTR_TX_SET_COMPLETE_Msk   0x1UL
#define SG_SG_STRUCT_INTR_TX_SET_UNDERFLOW_Pos  2UL
#define SG_SG_STRUCT_INTR_TX_SET_UNDERFLOW_Msk  0x4UL
#define SG_SG_STRUCT_INTR_TX_SET_IF_UNDERFLOW_Pos 8UL
#define SG_SG_STRUCT_INTR_TX_SET_IF_UNDERFLOW_Msk 0x100UL
/* SG_SG_STRUCT.INTR_TX_MASK */
#define SG_SG_STRUCT_INTR_TX_MASK_COMPLETE_Pos  0UL
#define SG_SG_STRUCT_INTR_TX_MASK_COMPLETE_Msk  0x1UL
#define SG_SG_STRUCT_INTR_TX_MASK_UNDERFLOW_Pos 2UL
#define SG_SG_STRUCT_INTR_TX_MASK_UNDERFLOW_Msk 0x4UL
#define SG_SG_STRUCT_INTR_TX_MASK_IF_UNDERFLOW_Pos 8UL
#define SG_SG_STRUCT_INTR_TX_MASK_IF_UNDERFLOW_Msk 0x100UL
/* SG_SG_STRUCT.INTR_TX_MASKED */
#define SG_SG_STRUCT_INTR_TX_MASKED_COMPLETE_Pos 0UL
#define SG_SG_STRUCT_INTR_TX_MASKED_COMPLETE_Msk 0x1UL
#define SG_SG_STRUCT_INTR_TX_MASKED_UNDERFLOW_Pos 2UL
#define SG_SG_STRUCT_INTR_TX_MASKED_UNDERFLOW_Msk 0x4UL
#define SG_SG_STRUCT_INTR_TX_MASKED_IF_UNDERFLOW_Pos 8UL
#define SG_SG_STRUCT_INTR_TX_MASKED_IF_UNDERFLOW_Msk 0x100UL


#endif /* _CYIP_SG_H_ */


/* [] END OF FILE */
