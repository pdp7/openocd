/***************************************************************************//**
* \file cyip_flexray.h
*
* \brief
* FLEXRAY IP definitions
*
* \note
* Generator version: 1.4.0.1226
* Database revision: TVIIBH8M_CFR_METALTO
*
********************************************************************************
* \copyright
* Copyright 2016-2018, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef _CYIP_FLEXRAY_H_
#define _CYIP_FLEXRAY_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                   FLEXRAY
*******************************************************************************/

#define FLEXRAY_SECTION_SIZE                    0x00001000UL

/**
  * \brief Control Register (FLEXRAY_CTL)
  */
typedef struct stc_FLEXRAY_CTL_field {
  uint32_t                         :31;
  uint32_t                         u1ENABLED:1;
} stc_FLEXRAY_CTL_field_t;

typedef union un_FLEXRAY_CTL {
  uint32_t                         u32Register;
  stc_FLEXRAY_CTL_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_CTL_t;

/**
  * \brief DMA Control Register (FLEXRAY_DMA_CTL)
  */
typedef struct stc_FLEXRAY_DMA_CTL_field {
  uint32_t                         u1IDMATOE:1;
  uint32_t                         u1ODMATOE:1;
  uint32_t                         u1ODMAFFE:1;
  uint32_t                         :29;
} stc_FLEXRAY_DMA_CTL_field_t;

typedef union un_FLEXRAY_DMA_CTL {
  uint32_t                         u32Register;
  stc_FLEXRAY_DMA_CTL_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_DMA_CTL_t;

/**
  * \brief Test Register 1 (FLEXRAY_TEST1)
  */
typedef struct stc_FLEXRAY_TEST1_field {
  uint32_t                         u1WRTEN:1;
  uint32_t                         u1ELBE:1;
  uint32_t                         :2;
  uint32_t                         u2TMC:2;
  uint32_t                         :2;
  uint32_t                         u1AOA:1;
  uint32_t                         u1AOB:1;
  uint32_t                         :6;
  uint32_t                         u1RXA:1;
  uint32_t                         u1RXB:1;
  uint32_t                         u1TXA:1;
  uint32_t                         u1TXB:1;
  uint32_t                         u1TXENA:1;
  uint32_t                         u1TXENB:1;
  uint32_t                         :2;
  uint32_t                         u4CERA:4;
  uint32_t                         u4CERB:4;
} stc_FLEXRAY_TEST1_field_t;

typedef union un_FLEXRAY_TEST1 {
  uint32_t                         u32Register;
  stc_FLEXRAY_TEST1_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_TEST1_t;

/**
  * \brief Test Register 2 (FLEXRAY_TEST2)
  */
typedef struct stc_FLEXRAY_TEST2_field {
  uint32_t                         u3RS:3;
  uint32_t                         :1;
  uint32_t                         u3SSEL:3;
  uint32_t                         :7;
  uint32_t                         u1WRPB:1;
  uint32_t                         u1RDPB:1;
  uint32_t                         :16;
} stc_FLEXRAY_TEST2_field_t;

typedef union un_FLEXRAY_TEST2 {
  uint32_t                         u32Register;
  stc_FLEXRAY_TEST2_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_TEST2_t;

/**
  * \brief Lock Register (FLEXRAY_LCK)
  */
typedef struct stc_FLEXRAY_LCK_field {
  uint32_t                         u8CLK:8;
  uint32_t                         u8TMK:8;
  uint32_t                         :16;
} stc_FLEXRAY_LCK_field_t;

typedef union un_FLEXRAY_LCK {
  uint32_t                         u32Register;
  stc_FLEXRAY_LCK_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_LCK_t;

/**
  * \brief Error Interrupt Register (FLEXRAY_EIR)
  */
typedef struct stc_FLEXRAY_EIR_field {
  uint32_t                         u1PEMC:1;
  uint32_t                         u1CNA:1;
  uint32_t                         u1SFBM:1;
  uint32_t                         u1SFO:1;
  uint32_t                         u1CCF:1;
  uint32_t                         u1CCL:1;
  uint32_t                         u1PERR:1;
  uint32_t                         u1RFO:1;
  uint32_t                         u1EFA:1;
  uint32_t                         u1IIBA:1;
  uint32_t                         u1IOBA:1;
  uint32_t                         u1MHF:1;
  uint32_t                         :4;
  uint32_t                         u1EDA:1;
  uint32_t                         u1LTVA:1;
  uint32_t                         u1TABA:1;
  uint32_t                         :5;
  uint32_t                         u1EDB:1;
  uint32_t                         u1LTVB:1;
  uint32_t                         u1TABB:1;
  uint32_t                         :5;
} stc_FLEXRAY_EIR_field_t;

typedef union un_FLEXRAY_EIR {
  uint32_t                         u32Register;
  stc_FLEXRAY_EIR_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_EIR_t;

/**
  * \brief Status Interrupt Register (FLEXRAY_SIR)
  */
typedef struct stc_FLEXRAY_SIR_field {
  uint32_t                         u1WST:1;
  uint32_t                         u1CAS:1;
  uint32_t                         u1CYCS:1;
  uint32_t                         u1TXI:1;
  uint32_t                         u1RXI:1;
  uint32_t                         u1RFNE:1;
  uint32_t                         u1RFCL:1;
  uint32_t                         u1NMVC:1;
  uint32_t                         u1TI0:1;
  uint32_t                         u1TI1:1;
  uint32_t                         u1TIBC:1;
  uint32_t                         u1TOBC:1;
  uint32_t                         u1SWE:1;
  uint32_t                         u1SUCS:1;
  uint32_t                         u1MBSI:1;
  uint32_t                         u1SDS:1;
  uint32_t                         u1WUPA:1;
  uint32_t                         u1MTSA:1;
  uint32_t                         :6;
  uint32_t                         u1WUPB:1;
  uint32_t                         u1MTSB:1;
  uint32_t                         :6;
} stc_FLEXRAY_SIR_field_t;

typedef union un_FLEXRAY_SIR {
  uint32_t                         u32Register;
  stc_FLEXRAY_SIR_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_SIR_t;

/**
  * \brief Error Interrupt Line Select (FLEXRAY_EILS)
  */
typedef struct stc_FLEXRAY_EILS_field {
  uint32_t                         u1PEMCL:1;
  uint32_t                         u1CNAL:1;
  uint32_t                         u1SFBML:1;
  uint32_t                         u1SFOL:1;
  uint32_t                         u1CCFL:1;
  uint32_t                         u1CCLL:1;
  uint32_t                         u1PERRL:1;
  uint32_t                         u1RFOL:1;
  uint32_t                         u1EFAL:1;
  uint32_t                         u1IIBAL:1;
  uint32_t                         u1IOBAL:1;
  uint32_t                         u1MHFL:1;
  uint32_t                         :4;
  uint32_t                         u1EDAL:1;
  uint32_t                         u1LTVAL:1;
  uint32_t                         u1TABAL:1;
  uint32_t                         :5;
  uint32_t                         u1EDBL:1;
  uint32_t                         u1LTVBL:1;
  uint32_t                         u1TABBL:1;
  uint32_t                         :5;
} stc_FLEXRAY_EILS_field_t;

typedef union un_FLEXRAY_EILS {
  uint32_t                         u32Register;
  stc_FLEXRAY_EILS_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_EILS_t;

/**
  * \brief Status Interrupt Line Select (FLEXRAY_SILS)
  */
typedef struct stc_FLEXRAY_SILS_field {
  uint32_t                         u1WSTL:1;
  uint32_t                         u1CASL:1;
  uint32_t                         u1CYCSL:1;
  uint32_t                         u1TXIL:1;
  uint32_t                         u1RXIL:1;
  uint32_t                         u1RFNEL:1;
  uint32_t                         u1RFCLL:1;
  uint32_t                         u1NMVCL:1;
  uint32_t                         u1TI0L:1;
  uint32_t                         u1TI1L:1;
  uint32_t                         u1TIBCL:1;
  uint32_t                         u1TOBCL:1;
  uint32_t                         u1SWEL:1;
  uint32_t                         u1SUCSL:1;
  uint32_t                         u1MBSIL:1;
  uint32_t                         u1SDSL:1;
  uint32_t                         u1WUPAL:1;
  uint32_t                         u1MTSAL:1;
  uint32_t                         :6;
  uint32_t                         u1WUPBL:1;
  uint32_t                         u1MTSBL:1;
  uint32_t                         :6;
} stc_FLEXRAY_SILS_field_t;

typedef union un_FLEXRAY_SILS {
  uint32_t                         u32Register;
  stc_FLEXRAY_SILS_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_SILS_t;

/**
  * \brief Error Interrupt Enable Set (FLEXRAY_EIES)
  */
typedef struct stc_FLEXRAY_EIES_field {
  uint32_t                         u1PEMCE:1;
  uint32_t                         u1CNAE:1;
  uint32_t                         u1SFBME:1;
  uint32_t                         u1SFOE:1;
  uint32_t                         u1CCFE:1;
  uint32_t                         u1CCLE:1;
  uint32_t                         u1PERRE:1;
  uint32_t                         u1RFOE:1;
  uint32_t                         u1EFAE:1;
  uint32_t                         u1IIBAE:1;
  uint32_t                         u1IOBAE:1;
  uint32_t                         u1MHFE:1;
  uint32_t                         :4;
  uint32_t                         u1EDAE:1;
  uint32_t                         u1LTVAE:1;
  uint32_t                         u1TABAE:1;
  uint32_t                         :5;
  uint32_t                         u1EDBE:1;
  uint32_t                         u1LTVBE:1;
  uint32_t                         u1TABBE:1;
  uint32_t                         :5;
} stc_FLEXRAY_EIES_field_t;

typedef union un_FLEXRAY_EIES {
  uint32_t                         u32Register;
  stc_FLEXRAY_EIES_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_EIES_t;

/**
  * \brief Error Interrupt Enable Reset (FLEXRAY_EIER)
  */
typedef struct stc_FLEXRAY_EIER_field {
  uint32_t                         u1PEMCE:1;
  uint32_t                         u1CNAE:1;
  uint32_t                         u1SFBME:1;
  uint32_t                         u1SFOE:1;
  uint32_t                         u1CCFE:1;
  uint32_t                         u1CCLE:1;
  uint32_t                         u1PERRE:1;
  uint32_t                         u1RFOE:1;
  uint32_t                         u1EFAE:1;
  uint32_t                         u1IIBAE:1;
  uint32_t                         u1IOBAE:1;
  uint32_t                         u1MHFE:1;
  uint32_t                         :4;
  uint32_t                         u1EDAE:1;
  uint32_t                         u1LTVAE:1;
  uint32_t                         u1TABAE:1;
  uint32_t                         :5;
  uint32_t                         u1EDBE:1;
  uint32_t                         u1LTVBE:1;
  uint32_t                         u1TABBE:1;
  uint32_t                         :5;
} stc_FLEXRAY_EIER_field_t;

typedef union un_FLEXRAY_EIER {
  uint32_t                         u32Register;
  stc_FLEXRAY_EIER_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_EIER_t;

/**
  * \brief Status Interrupt Enable Set (FLEXRAY_SIES)
  */
typedef struct stc_FLEXRAY_SIES_field {
  uint32_t                         u1WSTE:1;
  uint32_t                         u1CASE:1;
  uint32_t                         u1CYCSE:1;
  uint32_t                         u1TXIE:1;
  uint32_t                         u1RXIE:1;
  uint32_t                         u1RFNEE:1;
  uint32_t                         u1RFCLE:1;
  uint32_t                         u1NMVCE:1;
  uint32_t                         u1TI0E:1;
  uint32_t                         u1TI1E:1;
  uint32_t                         u1TIBCE:1;
  uint32_t                         u1TOBCE:1;
  uint32_t                         u1SWEE:1;
  uint32_t                         u1SUCSE:1;
  uint32_t                         u1MBSIE:1;
  uint32_t                         u1SDSE:1;
  uint32_t                         u1WUPAE:1;
  uint32_t                         u1MTSAE:1;
  uint32_t                         :6;
  uint32_t                         u1WUPBE:1;
  uint32_t                         u1MTSBE:1;
  uint32_t                         :6;
} stc_FLEXRAY_SIES_field_t;

typedef union un_FLEXRAY_SIES {
  uint32_t                         u32Register;
  stc_FLEXRAY_SIES_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_SIES_t;

/**
  * \brief Status Interrupt Enable Reset (FLEXRAY_SIER)
  */
typedef struct stc_FLEXRAY_SIER_field {
  uint32_t                         u1WSTE:1;
  uint32_t                         u1CASE:1;
  uint32_t                         u1CYCSE:1;
  uint32_t                         u1TXIE:1;
  uint32_t                         u1RXIE:1;
  uint32_t                         u1RFNEE:1;
  uint32_t                         u1RFCLE:1;
  uint32_t                         u1NMVCE:1;
  uint32_t                         u1TI0E:1;
  uint32_t                         u1TI1E:1;
  uint32_t                         u1TIBCE:1;
  uint32_t                         u1TOBCE:1;
  uint32_t                         u1SWEE:1;
  uint32_t                         u1SUCSE:1;
  uint32_t                         u1MBSIE:1;
  uint32_t                         u1SDSE:1;
  uint32_t                         u1WUPAE:1;
  uint32_t                         u1MTSAE:1;
  uint32_t                         :6;
  uint32_t                         u1WUPBE:1;
  uint32_t                         u1MTSBE:1;
  uint32_t                         :6;
} stc_FLEXRAY_SIER_field_t;

typedef union un_FLEXRAY_SIER {
  uint32_t                         u32Register;
  stc_FLEXRAY_SIER_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_SIER_t;

/**
  * \brief Interrupt Line Enable (FLEXRAY_ILE)
  */
typedef struct stc_FLEXRAY_ILE_field {
  uint32_t                         u1EINT0_:1;
  uint32_t                         u1EINT1_:1;
  uint32_t                         :30;
} stc_FLEXRAY_ILE_field_t;

typedef union un_FLEXRAY_ILE {
  uint32_t                         u32Register;
  stc_FLEXRAY_ILE_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_ILE_t;

/**
  * \brief Timer 0 Configuration (FLEXRAY_T0C)
  */
typedef struct stc_FLEXRAY_T0C_field {
  uint32_t                         u1T0RC:1;
  uint32_t                         u1T0MS:1;
  uint32_t                         :6;
  uint32_t                         u7T0CC:7;
  uint32_t                         :1;
  uint32_t                         u14T0MO:14;
  uint32_t                         :2;
} stc_FLEXRAY_T0C_field_t;

typedef union un_FLEXRAY_T0C {
  uint32_t                         u32Register;
  stc_FLEXRAY_T0C_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_T0C_t;

/**
  * \brief Timer 1 Configuration (FLEXRAY_T1C)
  */
typedef struct stc_FLEXRAY_T1C_field {
  uint32_t                         u1T1RC:1;
  uint32_t                         u1T1MS:1;
  uint32_t                         :14;
  uint32_t                         u14T1MC:14;
  uint32_t                         :2;
} stc_FLEXRAY_T1C_field_t;

typedef union un_FLEXRAY_T1C {
  uint32_t                         u32Register;
  stc_FLEXRAY_T1C_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_T1C_t;

/**
  * \brief Stop Watch Register 1 (FLEXRAY_STPW1)
  */
typedef struct stc_FLEXRAY_STPW1_field {
  uint32_t                         u1ESWT:1;
  uint32_t                         u1SWMS:1;
  uint32_t                         u1EDGE:1;
  uint32_t                         u1SSWT:1;
  uint32_t                         u1EETP:1;
  uint32_t                         u1EINT0:1;
  uint32_t                         u1EINT1:1;
  uint32_t                         :1;
  uint32_t                         u6SCCV:6;
  uint32_t                         :2;
  uint32_t                         u14SMTV:14;
  uint32_t                         :2;
} stc_FLEXRAY_STPW1_field_t;

typedef union un_FLEXRAY_STPW1 {
  uint32_t                         u32Register;
  stc_FLEXRAY_STPW1_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_STPW1_t;

/**
  * \brief Stop Watch Register 2 (FLEXRAY_STPW2)
  */
typedef struct stc_FLEXRAY_STPW2_field {
  uint32_t                         u11SSCVA:11;
  uint32_t                         :5;
  uint32_t                         u11SSCVB:11;
  uint32_t                         :5;
} stc_FLEXRAY_STPW2_field_t;

typedef union un_FLEXRAY_STPW2 {
  uint32_t                         u32Register;
  stc_FLEXRAY_STPW2_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_STPW2_t;

/**
  * \brief SUC Configuration Register 1 (FLEXRAY_SUCC1)
  */
typedef struct stc_FLEXRAY_SUCC1_field {
  uint32_t                         u4CMD:4;
  uint32_t                         :3;
  uint32_t                         u1PBSY:1;
  uint32_t                         u1TXST:1;
  uint32_t                         u1TXSY:1;
  uint32_t                         :1;
  uint32_t                         u5CSA:5;
  uint32_t                         u5PTA:5;
  uint32_t                         u1WUCS:1;
  uint32_t                         u1TSM:1;
  uint32_t                         u1HCSE:1;
  uint32_t                         u1MTSA_:1;
  uint32_t                         u1MTSB_:1;
  uint32_t                         u1CCHA:1;
  uint32_t                         u1CCHB:1;
  uint32_t                         :4;
} stc_FLEXRAY_SUCC1_field_t;

typedef union un_FLEXRAY_SUCC1 {
  uint32_t                         u32Register;
  stc_FLEXRAY_SUCC1_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_SUCC1_t;

/**
  * \brief SUC Configuration Register 2 (FLEXRAY_SUCC2)
  */
typedef struct stc_FLEXRAY_SUCC2_field {
  uint32_t                         u21LT:21;
  uint32_t                         :3;
  uint32_t                         u4LTN:4;
  uint32_t                         :4;
} stc_FLEXRAY_SUCC2_field_t;

typedef union un_FLEXRAY_SUCC2 {
  uint32_t                         u32Register;
  stc_FLEXRAY_SUCC2_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_SUCC2_t;

/**
  * \brief SUC Configuration Register 3 (FLEXRAY_SUCC3)
  */
typedef struct stc_FLEXRAY_SUCC3_field {
  uint32_t                         u4WCP:4;
  uint32_t                         u4WCF:4;
  uint32_t                         :24;
} stc_FLEXRAY_SUCC3_field_t;

typedef union un_FLEXRAY_SUCC3 {
  uint32_t                         u32Register;
  stc_FLEXRAY_SUCC3_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_SUCC3_t;

/**
  * \brief NEM Configuration Register (FLEXRAY_NEMC)
  */
typedef struct stc_FLEXRAY_NEMC_field {
  uint32_t                         u4NML:4;
  uint32_t                         :28;
} stc_FLEXRAY_NEMC_field_t;

typedef union un_FLEXRAY_NEMC {
  uint32_t                         u32Register;
  stc_FLEXRAY_NEMC_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_NEMC_t;

/**
  * \brief PRT Configuration Register 1 (FLEXRAY_PRTC1)
  */
typedef struct stc_FLEXRAY_PRTC1_field {
  uint32_t                         u4TSST:4;
  uint32_t                         u6CASM:6;
  uint32_t                         u1CASM6:1;
  uint32_t                         :1;
  uint32_t                         u2SPP:2;
  uint32_t                         u2BRP:2;
  uint32_t                         u9RXW:9;
  uint32_t                         :1;
  uint32_t                         u6RWP:6;
} stc_FLEXRAY_PRTC1_field_t;

typedef union un_FLEXRAY_PRTC1 {
  uint32_t                         u32Register;
  stc_FLEXRAY_PRTC1_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_PRTC1_t;

/**
  * \brief PRT Configuration Register 2 (FLEXRAY_PRTC2)
  */
typedef struct stc_FLEXRAY_PRTC2_field {
  uint32_t                         u6RXI_:6;
  uint32_t                         :2;
  uint32_t                         u6RXL:6;
  uint32_t                         :2;
  uint32_t                         u8TXI_:8;
  uint32_t                         u6TXL:6;
  uint32_t                         :2;
} stc_FLEXRAY_PRTC2_field_t;

typedef union un_FLEXRAY_PRTC2 {
  uint32_t                         u32Register;
  stc_FLEXRAY_PRTC2_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_PRTC2_t;

/**
  * \brief MHD Configuration Register (FLEXRAY_MHDC)
  */
typedef struct stc_FLEXRAY_MHDC_field {
  uint32_t                         u7SFDL:7;
  uint32_t                         :9;
  uint32_t                         u13SLT:13;
  uint32_t                         :3;
} stc_FLEXRAY_MHDC_field_t;

typedef union un_FLEXRAY_MHDC {
  uint32_t                         u32Register;
  stc_FLEXRAY_MHDC_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_MHDC_t;

/**
  * \brief GTU Configuration Register 1 (FLEXRAY_GTUC1)
  */
typedef struct stc_FLEXRAY_GTUC1_field {
  uint32_t                         u20UT:20;
  uint32_t                         :12;
} stc_FLEXRAY_GTUC1_field_t;

typedef union un_FLEXRAY_GTUC1 {
  uint32_t                         u32Register;
  stc_FLEXRAY_GTUC1_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_GTUC1_t;

/**
  * \brief GTU Configuration Register 2 (FLEXRAY_GTUC2)
  */
typedef struct stc_FLEXRAY_GTUC2_field {
  uint32_t                         u14MPC:14;
  uint32_t                         :2;
  uint32_t                         u4SNM:4;
  uint32_t                         :12;
} stc_FLEXRAY_GTUC2_field_t;

typedef union un_FLEXRAY_GTUC2 {
  uint32_t                         u32Register;
  stc_FLEXRAY_GTUC2_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_GTUC2_t;

/**
  * \brief GTU Configuration Register 3 (FLEXRAY_GTUC3)
  */
typedef struct stc_FLEXRAY_GTUC3_field {
  uint32_t                         u8UIOA:8;
  uint32_t                         u8UIOB:8;
  uint32_t                         u7MIOA:7;
  uint32_t                         :1;
  uint32_t                         u7MIOB:7;
} stc_FLEXRAY_GTUC3_field_t;

typedef union un_FLEXRAY_GTUC3 {
  uint32_t                         u32Register;
  stc_FLEXRAY_GTUC3_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_GTUC3_t;

/**
  * \brief GTU Configuration Register 4 (FLEXRAY_GTUC4)
  */
typedef struct stc_FLEXRAY_GTUC4_field {
  uint32_t                         u14NIT:14;
  uint32_t                         :2;
  uint32_t                         u14OCS:14;
  uint32_t                         :2;
} stc_FLEXRAY_GTUC4_field_t;

typedef union un_FLEXRAY_GTUC4 {
  uint32_t                         u32Register;
  stc_FLEXRAY_GTUC4_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_GTUC4_t;

/**
  * \brief GTU Configuration Register 5 (FLEXRAY_GTUC5)
  */
typedef struct stc_FLEXRAY_GTUC5_field {
  uint32_t                         u8DCA:8;
  uint32_t                         u8DCB:8;
  uint32_t                         u5CDD:5;
  uint32_t                         :3;
  uint32_t                         u8DEC:8;
} stc_FLEXRAY_GTUC5_field_t;

typedef union un_FLEXRAY_GTUC5 {
  uint32_t                         u32Register;
  stc_FLEXRAY_GTUC5_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_GTUC5_t;

/**
  * \brief GTU Configuration Register 6 (FLEXRAY_GTUC6)
  */
typedef struct stc_FLEXRAY_GTUC6_field {
  uint32_t                         u11ASR:11;
  uint32_t                         :5;
  uint32_t                         u11MOD:11;
  uint32_t                         :5;
} stc_FLEXRAY_GTUC6_field_t;

typedef union un_FLEXRAY_GTUC6 {
  uint32_t                         u32Register;
  stc_FLEXRAY_GTUC6_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_GTUC6_t;

/**
  * \brief GTU Configuration Register 7 (FLEXRAY_GTUC7)
  */
typedef struct stc_FLEXRAY_GTUC7_field {
  uint32_t                         u10SSL:10;
  uint32_t                         :6;
  uint32_t                         u10NSS:10;
  uint32_t                         :6;
} stc_FLEXRAY_GTUC7_field_t;

typedef union un_FLEXRAY_GTUC7 {
  uint32_t                         u32Register;
  stc_FLEXRAY_GTUC7_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_GTUC7_t;

/**
  * \brief GTU Configuration Register 8 (FLEXRAY_GTUC8)
  */
typedef struct stc_FLEXRAY_GTUC8_field {
  uint32_t                         u6MSL:6;
  uint32_t                         :10;
  uint32_t                         u13NMS:13;
  uint32_t                         :3;
} stc_FLEXRAY_GTUC8_field_t;

typedef union un_FLEXRAY_GTUC8 {
  uint32_t                         u32Register;
  stc_FLEXRAY_GTUC8_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_GTUC8_t;

/**
  * \brief GTU Configuration Register 9 (FLEXRAY_GTUC9)
  */
typedef struct stc_FLEXRAY_GTUC9_field {
  uint32_t                         u6APO:6;
  uint32_t                         :2;
  uint32_t                         u5MAPO:5;
  uint32_t                         :3;
  uint32_t                         u2DSI:2;
  uint32_t                         :14;
} stc_FLEXRAY_GTUC9_field_t;

typedef union un_FLEXRAY_GTUC9 {
  uint32_t                         u32Register;
  stc_FLEXRAY_GTUC9_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_GTUC9_t;

/**
  * \brief GTU Configuration Register 10 (FLEXRAY_GTUC10)
  */
typedef struct stc_FLEXRAY_GTUC10_field {
  uint32_t                         u14MOC:14;
  uint32_t                         :2;
  uint32_t                         u11MRC:11;
  uint32_t                         :5;
} stc_FLEXRAY_GTUC10_field_t;

typedef union un_FLEXRAY_GTUC10 {
  uint32_t                         u32Register;
  stc_FLEXRAY_GTUC10_field_t       stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_GTUC10_t;

/**
  * \brief GTU Configuration Register 11 (FLEXRAY_GTUC11)
  */
typedef struct stc_FLEXRAY_GTUC11_field {
  uint32_t                         u2EOCC:2;
  uint32_t                         :6;
  uint32_t                         u2ERCC:2;
  uint32_t                         :6;
  uint32_t                         u3EOC:3;
  uint32_t                         :5;
  uint32_t                         u3ERC:3;
  uint32_t                         :5;
} stc_FLEXRAY_GTUC11_field_t;

typedef union un_FLEXRAY_GTUC11 {
  uint32_t                         u32Register;
  stc_FLEXRAY_GTUC11_field_t       stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_GTUC11_t;

/**
  * \brief CC Status Vector (FLEXRAY_CCSV)
  */
typedef struct stc_FLEXRAY_CCSV_field {
  uint32_t                         u6POCS:6;
  uint32_t                         u1FSI:1;
  uint32_t                         u1HRQ:1;
  uint32_t                         u2SLM:2;
  uint32_t                         :2;
  uint32_t                         u1CSNI:1;
  uint32_t                         u1CSAI:1;
  uint32_t                         u1CSI:1;
  uint32_t                         :1;
  uint32_t                         u3WSV:3;
  uint32_t                         u5RCA:5;
  uint32_t                         u6PSL:6;
  uint32_t                         :2;
} stc_FLEXRAY_CCSV_field_t;

typedef union un_FLEXRAY_CCSV {
  uint32_t                         u32Register;
  stc_FLEXRAY_CCSV_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_CCSV_t;

/**
  * \brief CC Error Vector (FLEXRAY_CCEV)
  */
typedef struct stc_FLEXRAY_CCEV_field {
  uint32_t                         u4CCFC:4;
  uint32_t                         :2;
  uint32_t                         u2ERRM:2;
  uint32_t                         u5PTAC:5;
  uint32_t                         :19;
} stc_FLEXRAY_CCEV_field_t;

typedef union un_FLEXRAY_CCEV {
  uint32_t                         u32Register;
  stc_FLEXRAY_CCEV_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_CCEV_t;

/**
  * \brief Slot Counter Value (FLEXRAY_SCV)
  */
typedef struct stc_FLEXRAY_SCV_field {
  uint32_t                         u11SCCA:11;
  uint32_t                         :5;
  uint32_t                         u11SCCB:11;
  uint32_t                         :5;
} stc_FLEXRAY_SCV_field_t;

typedef union un_FLEXRAY_SCV {
  uint32_t                         u32Register;
  stc_FLEXRAY_SCV_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_SCV_t;

/**
  * \brief Macrotick and Cycle Counter Value (FLEXRAY_MTCCV)
  */
typedef struct stc_FLEXRAY_MTCCV_field {
  uint32_t                         u14MTV:14;
  uint32_t                         :2;
  uint32_t                         u6CCV:6;
  uint32_t                         :10;
} stc_FLEXRAY_MTCCV_field_t;

typedef union un_FLEXRAY_MTCCV {
  uint32_t                         u32Register;
  stc_FLEXRAY_MTCCV_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_MTCCV_t;

/**
  * \brief Rate Correction Value (FLEXRAY_RCV)
  */
typedef struct stc_FLEXRAY_RCV_field {
  uint32_t                         u12RCV:12;
  uint32_t                         :20;
} stc_FLEXRAY_RCV_field_t;

typedef union un_FLEXRAY_RCV {
  uint32_t                         u32Register;
  stc_FLEXRAY_RCV_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_RCV_t;

/**
  * \brief Offset Correction Value (FLEXRAY_OCV)
  */
typedef struct stc_FLEXRAY_OCV_field {
  uint32_t                         u19OCV:19;
  uint32_t                         :13;
} stc_FLEXRAY_OCV_field_t;

typedef union un_FLEXRAY_OCV {
  uint32_t                         u32Register;
  stc_FLEXRAY_OCV_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_OCV_t;

/**
  * \brief Sync Frame Status (FLEXRAY_SFS)
  */
typedef struct stc_FLEXRAY_SFS_field {
  uint32_t                         u4VSAE:4;
  uint32_t                         u4VSAO:4;
  uint32_t                         u4VSBE:4;
  uint32_t                         u4VSBO:4;
  uint32_t                         u1MOCS:1;
  uint32_t                         u1OCLR:1;
  uint32_t                         u1MRCS:1;
  uint32_t                         u1RCLR:1;
  uint32_t                         :12;
} stc_FLEXRAY_SFS_field_t;

typedef union un_FLEXRAY_SFS {
  uint32_t                         u32Register;
  stc_FLEXRAY_SFS_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_SFS_t;

/**
  * \brief Symbol Window and NIT Status (FLEXRAY_SWNIT)
  */
typedef struct stc_FLEXRAY_SWNIT_field {
  uint32_t                         u1SESA:1;
  uint32_t                         u1SBSA:1;
  uint32_t                         u1TCSA:1;
  uint32_t                         u1SESB:1;
  uint32_t                         u1SBSB:1;
  uint32_t                         u1TCSB:1;
  uint32_t                         u1MTSA__:1;
  uint32_t                         u1MTSB__:1;
  uint32_t                         u1SENA:1;
  uint32_t                         u1SBNA:1;
  uint32_t                         u1SENB:1;
  uint32_t                         u1SBNB:1;
  uint32_t                         :20;
} stc_FLEXRAY_SWNIT_field_t;

typedef union un_FLEXRAY_SWNIT {
  uint32_t                         u32Register;
  stc_FLEXRAY_SWNIT_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_SWNIT_t;

/**
  * \brief Aggregated Channel Status (FLEXRAY_ACS)
  */
typedef struct stc_FLEXRAY_ACS_field {
  uint32_t                         u1VFRA_:1;
  uint32_t                         u1SEDA:1;
  uint32_t                         u1CEDA:1;
  uint32_t                         u1CIA:1;
  uint32_t                         u1SBVA:1;
  uint32_t                         :3;
  uint32_t                         u1VFRB_:1;
  uint32_t                         u1SEDB:1;
  uint32_t                         u1CEDB:1;
  uint32_t                         u1CIB:1;
  uint32_t                         u1SBVB:1;
  uint32_t                         :19;
} stc_FLEXRAY_ACS_field_t;

typedef union un_FLEXRAY_ACS {
  uint32_t                         u32Register;
  stc_FLEXRAY_ACS_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_ACS_t;

/**
  * \brief Even Sync ID [1...15] (FLEXRAY_ESID)
  */
typedef struct stc_FLEXRAY_ESID_field {
  uint32_t                         u10EID:10;
  uint32_t                         :4;
  uint32_t                         u1RXEA:1;
  uint32_t                         u1RXEB:1;
  uint32_t                         :16;
} stc_FLEXRAY_ESID_field_t;

typedef union un_FLEXRAY_ESID {
  uint32_t                         u32Register;
  stc_FLEXRAY_ESID_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_ESID_t;

/**
  * \brief Odd Sync ID [1...15] (FLEXRAY_OSID)
  */
typedef struct stc_FLEXRAY_OSID_field {
  uint32_t                         u10OID:10;
  uint32_t                         :4;
  uint32_t                         u1RXOA:1;
  uint32_t                         u1RXOB:1;
  uint32_t                         :16;
} stc_FLEXRAY_OSID_field_t;

typedef union un_FLEXRAY_OSID {
  uint32_t                         u32Register;
  stc_FLEXRAY_OSID_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_OSID_t;

/**
  * \brief Network Management Vector 1 (FLEXRAY_NMV1)
  */
typedef struct stc_FLEXRAY_NMV1_field {
  uint32_t                         u8DATA0:8;
  uint32_t                         u8DATA1:8;
  uint32_t                         u8DATA2:8;
  uint32_t                         u8DATA3:8;
} stc_FLEXRAY_NMV1_field_t;

typedef union un_FLEXRAY_NMV1 {
  uint32_t                         u32Register;
  stc_FLEXRAY_NMV1_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_NMV1_t;

/**
  * \brief Network Management Vector 2 (FLEXRAY_NMV2)
  */
typedef struct stc_FLEXRAY_NMV2_field {
  uint32_t                         u8DATA4:8;
  uint32_t                         u8DATA5:8;
  uint32_t                         u8DATA6:8;
  uint32_t                         u8DATA7:8;
} stc_FLEXRAY_NMV2_field_t;

typedef union un_FLEXRAY_NMV2 {
  uint32_t                         u32Register;
  stc_FLEXRAY_NMV2_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_NMV2_t;

/**
  * \brief Network Management Vector 3 (FLEXRAY_NMV3)
  */
typedef struct stc_FLEXRAY_NMV3_field {
  uint32_t                         u8DATA8:8;
  uint32_t                         u8DATA9:8;
  uint32_t                         u8DATA10:8;
  uint32_t                         u8DATA11:8;
} stc_FLEXRAY_NMV3_field_t;

typedef union un_FLEXRAY_NMV3 {
  uint32_t                         u32Register;
  stc_FLEXRAY_NMV3_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_NMV3_t;

/**
  * \brief Message RAM Configuration (FLEXRAY_MRC)
  */
typedef struct stc_FLEXRAY_MRC_field {
  uint32_t                         u8FDB:8;
  uint32_t                         u8FFB:8;
  uint32_t                         u8LCB:8;
  uint32_t                         u2SEC:2;
  uint32_t                         u1SPLM:1;
  uint32_t                         :5;
} stc_FLEXRAY_MRC_field_t;

typedef union un_FLEXRAY_MRC {
  uint32_t                         u32Register;
  stc_FLEXRAY_MRC_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_MRC_t;

/**
  * \brief FIFO Rejection Filter (FLEXRAY_FRF)
  */
typedef struct stc_FLEXRAY_FRF_field {
  uint32_t                         u2CH:2;
  uint32_t                         u11FID_:11;
  uint32_t                         :3;
  uint32_t                         u7CYF:7;
  uint32_t                         u1RSS:1;
  uint32_t                         u1RNF:1;
  uint32_t                         :7;
} stc_FLEXRAY_FRF_field_t;

typedef union un_FLEXRAY_FRF {
  uint32_t                         u32Register;
  stc_FLEXRAY_FRF_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_FRF_t;

/**
  * \brief FIFO Rejection Filter Mask (FLEXRAY_FRFM)
  */
typedef struct stc_FLEXRAY_FRFM_field {
  uint32_t                         :2;
  uint32_t                         u11MFID:11;
  uint32_t                         :19;
} stc_FLEXRAY_FRFM_field_t;

typedef union un_FLEXRAY_FRFM {
  uint32_t                         u32Register;
  stc_FLEXRAY_FRFM_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_FRFM_t;

/**
  * \brief FIFO Critical Level (FLEXRAY_FCL)
  */
typedef struct stc_FLEXRAY_FCL_field {
  uint32_t                         u8CL:8;
  uint32_t                         :24;
} stc_FLEXRAY_FCL_field_t;

typedef union un_FLEXRAY_FCL {
  uint32_t                         u32Register;
  stc_FLEXRAY_FCL_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_FCL_t;

/**
  * \brief Message Handler Status (FLEXRAY_MHDS)
  */
typedef struct stc_FLEXRAY_MHDS_field {
  uint32_t                         u1PIBF:1;
  uint32_t                         u1POBF:1;
  uint32_t                         u1PMR:1;
  uint32_t                         u1PTBF1:1;
  uint32_t                         u1PTBF2:1;
  uint32_t                         u1FMBD:1;
  uint32_t                         u1MFMB:1;
  uint32_t                         u1CRAM:1;
  uint32_t                         u7FMB:7;
  uint32_t                         :1;
  uint32_t                         u7MBT:7;
  uint32_t                         :1;
  uint32_t                         u7MBU:7;
} stc_FLEXRAY_MHDS_field_t;

typedef union un_FLEXRAY_MHDS {
  uint32_t                         u32Register;
  stc_FLEXRAY_MHDS_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_MHDS_t;

/**
  * \brief Last Dynamic Transmit Slot (FLEXRAY_LDTS)
  */
typedef struct stc_FLEXRAY_LDTS_field {
  uint32_t                         u11LDTA:11;
  uint32_t                         :5;
  uint32_t                         u11LDTB:11;
  uint32_t                         :5;
} stc_FLEXRAY_LDTS_field_t;

typedef union un_FLEXRAY_LDTS {
  uint32_t                         u32Register;
  stc_FLEXRAY_LDTS_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_LDTS_t;

/**
  * \brief FIFO Status Register (FLEXRAY_FSR)
  */
typedef struct stc_FLEXRAY_FSR_field {
  uint32_t                         u1RFNE_:1;
  uint32_t                         u1RFCL_:1;
  uint32_t                         u1RFO_:1;
  uint32_t                         :5;
  uint32_t                         u8RFFL:8;
  uint32_t                         :16;
} stc_FLEXRAY_FSR_field_t;

typedef union un_FLEXRAY_FSR {
  uint32_t                         u32Register;
  stc_FLEXRAY_FSR_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_FSR_t;

/**
  * \brief Message Handler Constraints Flags (FLEXRAY_MHDF)
  */
typedef struct stc_FLEXRAY_MHDF_field {
  uint32_t                         u1SNUA:1;
  uint32_t                         u1SNUB:1;
  uint32_t                         u1FNFA:1;
  uint32_t                         u1FNFB:1;
  uint32_t                         u1TBFA:1;
  uint32_t                         u1TBFB:1;
  uint32_t                         u1TNSA:1;
  uint32_t                         u1TNSB:1;
  uint32_t                         u1WAHP:1;
  uint32_t                         :23;
} stc_FLEXRAY_MHDF_field_t;

typedef union un_FLEXRAY_MHDF {
  uint32_t                         u32Register;
  stc_FLEXRAY_MHDF_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_MHDF_t;

/**
  * \brief Transmission Request 1 (FLEXRAY_TXRQ1)
  */
typedef struct stc_FLEXRAY_TXRQ1_field {
  uint32_t                         u32TXR:32;
} stc_FLEXRAY_TXRQ1_field_t;

typedef union un_FLEXRAY_TXRQ1 {
  uint32_t                         u32Register;
  stc_FLEXRAY_TXRQ1_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_TXRQ1_t;

/**
  * \brief Transmission Request 2 (FLEXRAY_TXRQ2)
  */
typedef struct stc_FLEXRAY_TXRQ2_field {
  uint32_t                         u32TXR:32;
} stc_FLEXRAY_TXRQ2_field_t;

typedef union un_FLEXRAY_TXRQ2 {
  uint32_t                         u32Register;
  stc_FLEXRAY_TXRQ2_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_TXRQ2_t;

/**
  * \brief Transmission Request 3 (FLEXRAY_TXRQ3)
  */
typedef struct stc_FLEXRAY_TXRQ3_field {
  uint32_t                         u32TXR:32;
} stc_FLEXRAY_TXRQ3_field_t;

typedef union un_FLEXRAY_TXRQ3 {
  uint32_t                         u32Register;
  stc_FLEXRAY_TXRQ3_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_TXRQ3_t;

/**
  * \brief Transmission Request 4 (FLEXRAY_TXRQ4)
  */
typedef struct stc_FLEXRAY_TXRQ4_field {
  uint32_t                         u32TXR:32;
} stc_FLEXRAY_TXRQ4_field_t;

typedef union un_FLEXRAY_TXRQ4 {
  uint32_t                         u32Register;
  stc_FLEXRAY_TXRQ4_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_TXRQ4_t;

/**
  * \brief New Data 1 (FLEXRAY_NDAT1)
  */
typedef struct stc_FLEXRAY_NDAT1_field {
  uint32_t                         u32ND:32;
} stc_FLEXRAY_NDAT1_field_t;

typedef union un_FLEXRAY_NDAT1 {
  uint32_t                         u32Register;
  stc_FLEXRAY_NDAT1_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_NDAT1_t;

/**
  * \brief New Data 2 (FLEXRAY_NDAT2)
  */
typedef struct stc_FLEXRAY_NDAT2_field {
  uint32_t                         u32ND:32;
} stc_FLEXRAY_NDAT2_field_t;

typedef union un_FLEXRAY_NDAT2 {
  uint32_t                         u32Register;
  stc_FLEXRAY_NDAT2_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_NDAT2_t;

/**
  * \brief New Data 3 (FLEXRAY_NDAT3)
  */
typedef struct stc_FLEXRAY_NDAT3_field {
  uint32_t                         u32ND:32;
} stc_FLEXRAY_NDAT3_field_t;

typedef union un_FLEXRAY_NDAT3 {
  uint32_t                         u32Register;
  stc_FLEXRAY_NDAT3_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_NDAT3_t;

/**
  * \brief New Data 4 (FLEXRAY_NDAT4)
  */
typedef struct stc_FLEXRAY_NDAT4_field {
  uint32_t                         u32ND:32;
} stc_FLEXRAY_NDAT4_field_t;

typedef union un_FLEXRAY_NDAT4 {
  uint32_t                         u32Register;
  stc_FLEXRAY_NDAT4_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_NDAT4_t;

/**
  * \brief Message Buffer Status Changed 1 (FLEXRAY_MBSC1)
  */
typedef struct stc_FLEXRAY_MBSC1_field {
  uint32_t                         u32MBC:32;
} stc_FLEXRAY_MBSC1_field_t;

typedef union un_FLEXRAY_MBSC1 {
  uint32_t                         u32Register;
  stc_FLEXRAY_MBSC1_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_MBSC1_t;

/**
  * \brief Message Buffer Status Changed 2 (FLEXRAY_MBSC2)
  */
typedef struct stc_FLEXRAY_MBSC2_field {
  uint32_t                         u32MBC:32;
} stc_FLEXRAY_MBSC2_field_t;

typedef union un_FLEXRAY_MBSC2 {
  uint32_t                         u32Register;
  stc_FLEXRAY_MBSC2_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_MBSC2_t;

/**
  * \brief Message Buffer Status Changed 3 (FLEXRAY_MBSC3)
  */
typedef struct stc_FLEXRAY_MBSC3_field {
  uint32_t                         u32MBC:32;
} stc_FLEXRAY_MBSC3_field_t;

typedef union un_FLEXRAY_MBSC3 {
  uint32_t                         u32Register;
  stc_FLEXRAY_MBSC3_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_MBSC3_t;

/**
  * \brief Message Buffer Status Changed 4 (FLEXRAY_MBSC4)
  */
typedef struct stc_FLEXRAY_MBSC4_field {
  uint32_t                         u32MBC:32;
} stc_FLEXRAY_MBSC4_field_t;

typedef union un_FLEXRAY_MBSC4 {
  uint32_t                         u32Register;
  stc_FLEXRAY_MBSC4_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_MBSC4_t;

/**
  * \brief Core Release Register (FLEXRAY_CREL)
  */
typedef struct stc_FLEXRAY_CREL_field {
  uint32_t                         u8DAY:8;
  uint32_t                         u8MON:8;
  uint32_t                         u4YEAR:4;
  uint32_t                         u8STEP:8;
  uint32_t                         u4REL:4;
} stc_FLEXRAY_CREL_field_t;

typedef union un_FLEXRAY_CREL {
  uint32_t                         u32Register;
  stc_FLEXRAY_CREL_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_CREL_t;

/**
  * \brief Endian Register (FLEXRAY_ENDN)
  */
typedef struct stc_FLEXRAY_ENDN_field {
  uint32_t                         u32ETV:32;
} stc_FLEXRAY_ENDN_field_t;

typedef union un_FLEXRAY_ENDN {
  uint32_t                         u32Register;
  stc_FLEXRAY_ENDN_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_ENDN_t;

/**
  * \brief Write Data Section [1...64] (FLEXRAY_WRDS)
  */
typedef struct stc_FLEXRAY_WRDS_field {
  uint32_t                         u32MD:32;
} stc_FLEXRAY_WRDS_field_t;

typedef union un_FLEXRAY_WRDS {
  uint32_t                         u32Register;
  stc_FLEXRAY_WRDS_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_WRDS_t;

/**
  * \brief Write Header Section 1 (FLEXRAY_WRHS1)
  */
typedef struct stc_FLEXRAY_WRHS1_field {
  uint32_t                         u11FID:11;
  uint32_t                         :5;
  uint32_t                         u7CYC:7;
  uint32_t                         :1;
  uint32_t                         u1CHA:1;
  uint32_t                         u1CHB:1;
  uint32_t                         u1CFG:1;
  uint32_t                         u1PPIT:1;
  uint32_t                         u1TXM:1;
  uint32_t                         u1MBI:1;
  uint32_t                         :2;
} stc_FLEXRAY_WRHS1_field_t;

typedef union un_FLEXRAY_WRHS1 {
  uint32_t                         u32Register;
  stc_FLEXRAY_WRHS1_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_WRHS1_t;

/**
  * \brief Write Header Section 2 (FLEXRAY_WRHS2)
  */
typedef struct stc_FLEXRAY_WRHS2_field {
  uint32_t                         u11CRC:11;
  uint32_t                         :5;
  uint32_t                         u7PLC:7;
  uint32_t                         :9;
} stc_FLEXRAY_WRHS2_field_t;

typedef union un_FLEXRAY_WRHS2 {
  uint32_t                         u32Register;
  stc_FLEXRAY_WRHS2_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_WRHS2_t;

/**
  * \brief Write Header Section 3 (FLEXRAY_WRHS3)
  */
typedef struct stc_FLEXRAY_WRHS3_field {
  uint32_t                         u11DP:11;
  uint32_t                         :21;
} stc_FLEXRAY_WRHS3_field_t;

typedef union un_FLEXRAY_WRHS3 {
  uint32_t                         u32Register;
  stc_FLEXRAY_WRHS3_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_WRHS3_t;

/**
  * \brief Input Buffer Command Mask (FLEXRAY_IBCM)
  */
typedef struct stc_FLEXRAY_IBCM_field {
  uint32_t                         u1LHSH:1;
  uint32_t                         u1LDSH:1;
  uint32_t                         u1STXRH:1;
  uint32_t                         :13;
  uint32_t                         u1LHSS:1;
  uint32_t                         u1LDSS:1;
  uint32_t                         u1STXRS:1;
  uint32_t                         :13;
} stc_FLEXRAY_IBCM_field_t;

typedef union un_FLEXRAY_IBCM {
  uint32_t                         u32Register;
  stc_FLEXRAY_IBCM_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_IBCM_t;

/**
  * \brief Input Buffer Command Request (FLEXRAY_IBCR)
  */
typedef struct stc_FLEXRAY_IBCR_field {
  uint32_t                         u7IBRH:7;
  uint32_t                         :8;
  uint32_t                         u1IBSYH:1;
  uint32_t                         u7IBRS:7;
  uint32_t                         :8;
  uint32_t                         u1IBSYS:1;
} stc_FLEXRAY_IBCR_field_t;

typedef union un_FLEXRAY_IBCR {
  uint32_t                         u32Register;
  stc_FLEXRAY_IBCR_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_IBCR_t;

/**
  * \brief Read Data Section [1...64] (FLEXRAY_RDDS)
  */
typedef struct stc_FLEXRAY_RDDS_field {
  uint32_t                         u32MD:32;
} stc_FLEXRAY_RDDS_field_t;

typedef union un_FLEXRAY_RDDS {
  uint32_t                         u32Register;
  stc_FLEXRAY_RDDS_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_RDDS_t;

/**
  * \brief Read Header Section 1 (FLEXRAY_RDHS1)
  */
typedef struct stc_FLEXRAY_RDHS1_field {
  uint32_t                         u11FID:11;
  uint32_t                         :5;
  uint32_t                         u7CYC:7;
  uint32_t                         :1;
  uint32_t                         u1CHA:1;
  uint32_t                         u1CHB:1;
  uint32_t                         u1CFG:1;
  uint32_t                         u1PPIT:1;
  uint32_t                         u1TXM:1;
  uint32_t                         u1MBI:1;
  uint32_t                         :2;
} stc_FLEXRAY_RDHS1_field_t;

typedef union un_FLEXRAY_RDHS1 {
  uint32_t                         u32Register;
  stc_FLEXRAY_RDHS1_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_RDHS1_t;

/**
  * \brief Read Header Section 2 (FLEXRAY_RDHS2)
  */
typedef struct stc_FLEXRAY_RDHS2_field {
  uint32_t                         u11CRC:11;
  uint32_t                         :5;
  uint32_t                         u7PLC:7;
  uint32_t                         :1;
  uint32_t                         u7PLR:7;
} stc_FLEXRAY_RDHS2_field_t;

typedef union un_FLEXRAY_RDHS2 {
  uint32_t                         u32Register;
  stc_FLEXRAY_RDHS2_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_RDHS2_t;

/**
  * \brief Read Header Section 3 (FLEXRAY_RDHS3)
  */
typedef struct stc_FLEXRAY_RDHS3_field {
  uint32_t                         u11DP:11;
  uint32_t                         :5;
  uint32_t                         u6RCC:6;
  uint32_t                         :2;
  uint32_t                         u1RCI:1;
  uint32_t                         u1SFI:1;
  uint32_t                         u1SYN:1;
  uint32_t                         u1NFI:1;
  uint32_t                         u1PPI:1;
  uint32_t                         u1RES:1;
  uint32_t                         :2;
} stc_FLEXRAY_RDHS3_field_t;

typedef union un_FLEXRAY_RDHS3 {
  uint32_t                         u32Register;
  stc_FLEXRAY_RDHS3_field_t        stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_RDHS3_t;

/**
  * \brief Message Buffer Status (FLEXRAY_MBS)
  */
typedef struct stc_FLEXRAY_MBS_field {
  uint32_t                         u1VFRA:1;
  uint32_t                         u1VFRB:1;
  uint32_t                         u1SEOA:1;
  uint32_t                         u1SEOB:1;
  uint32_t                         u1CEOA:1;
  uint32_t                         u1CEOB:1;
  uint32_t                         u1SVOA:1;
  uint32_t                         u1SVOB:1;
  uint32_t                         u1TCIA:1;
  uint32_t                         u1TCIB:1;
  uint32_t                         u1ESA:1;
  uint32_t                         u1ESB:1;
  uint32_t                         u1MLST:1;
  uint32_t                         :1;
  uint32_t                         u1FTA:1;
  uint32_t                         u1FTB:1;
  uint32_t                         u6CCS:6;
  uint32_t                         :2;
  uint32_t                         u1RCIS:1;
  uint32_t                         u1SFIS:1;
  uint32_t                         u1SYNS:1;
  uint32_t                         u1NFIS:1;
  uint32_t                         u1PPIS:1;
  uint32_t                         u1RESS:1;
  uint32_t                         :2;
} stc_FLEXRAY_MBS_field_t;

typedef union un_FLEXRAY_MBS {
  uint32_t                         u32Register;
  stc_FLEXRAY_MBS_field_t          stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_MBS_t;

/**
  * \brief Output Buffer Command Mask (FLEXRAY_OBCM)
  */
typedef struct stc_FLEXRAY_OBCM_field {
  uint32_t                         u1RHSS:1;
  uint32_t                         u1RDSS:1;
  uint32_t                         :14;
  uint32_t                         u1RHSH:1;
  uint32_t                         u1RDSH:1;
  uint32_t                         :14;
} stc_FLEXRAY_OBCM_field_t;

typedef union un_FLEXRAY_OBCM {
  uint32_t                         u32Register;
  stc_FLEXRAY_OBCM_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_OBCM_t;

/**
  * \brief Output Buffer Command Request (FLEXRAY_OBCR)
  */
typedef struct stc_FLEXRAY_OBCR_field {
  uint32_t                         u7OBRS:7;
  uint32_t                         :1;
  uint32_t                         u1VIEW:1;
  uint32_t                         u1REQ:1;
  uint32_t                         :5;
  uint32_t                         u1OBSYS:1;
  uint32_t                         u7OBRH:7;
  uint32_t                         :9;
} stc_FLEXRAY_OBCR_field_t;

typedef union un_FLEXRAY_OBCR {
  uint32_t                         u32Register;
  stc_FLEXRAY_OBCR_field_t         stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_OBCR_t;

/**
  * \brief Write Header Section 1 (2nd mirror) (FLEXRAY_WRHS1_MIR2)
  */
typedef struct stc_FLEXRAY_WRHS1_MIR2_field {
  uint32_t                         u11FID:11;
  uint32_t                         :5;
  uint32_t                         u7CYC:7;
  uint32_t                         :1;
  uint32_t                         u1CHA:1;
  uint32_t                         u1CHB:1;
  uint32_t                         u1CFG:1;
  uint32_t                         u1PPIT:1;
  uint32_t                         u1TXM:1;
  uint32_t                         u1MBI:1;
  uint32_t                         :2;
} stc_FLEXRAY_WRHS1_MIR2_field_t;

typedef union un_FLEXRAY_WRHS1_MIR2 {
  uint32_t                         u32Register;
  stc_FLEXRAY_WRHS1_MIR2_field_t   stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_WRHS1_MIR2_t;

/**
  * \brief Write Header Section 2 (2nd mirror) (FLEXRAY_WRHS2_MIR2)
  */
typedef struct stc_FLEXRAY_WRHS2_MIR2_field {
  uint32_t                         u11CRC:11;
  uint32_t                         :5;
  uint32_t                         u7PLC:7;
  uint32_t                         :9;
} stc_FLEXRAY_WRHS2_MIR2_field_t;

typedef union un_FLEXRAY_WRHS2_MIR2 {
  uint32_t                         u32Register;
  stc_FLEXRAY_WRHS2_MIR2_field_t   stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_WRHS2_MIR2_t;

/**
  * \brief Write Header Section 3 (2nd mirror) (FLEXRAY_WRHS3_MIR2)
  */
typedef struct stc_FLEXRAY_WRHS3_MIR2_field {
  uint32_t                         u11DP:11;
  uint32_t                         :21;
} stc_FLEXRAY_WRHS3_MIR2_field_t;

typedef union un_FLEXRAY_WRHS3_MIR2 {
  uint32_t                         u32Register;
  stc_FLEXRAY_WRHS3_MIR2_field_t   stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_WRHS3_MIR2_t;

/**
  * \brief Write Data Section [1...64] (mirror) (FLEXRAY_WRDS_MIR)
  */
typedef struct stc_FLEXRAY_WRDS_MIR_field {
  uint32_t                         u32MD:32;
} stc_FLEXRAY_WRDS_MIR_field_t;

typedef union un_FLEXRAY_WRDS_MIR {
  uint32_t                         u32Register;
  stc_FLEXRAY_WRDS_MIR_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_WRDS_MIR_t;

/**
  * \brief Write Header Section 1 (mirror) (FLEXRAY_WRHS1_MIR)
  */
typedef struct stc_FLEXRAY_WRHS1_MIR_field {
  uint32_t                         u11FID:11;
  uint32_t                         :5;
  uint32_t                         u7CYC:7;
  uint32_t                         :1;
  uint32_t                         u1CHA:1;
  uint32_t                         u1CHB:1;
  uint32_t                         u1CFG:1;
  uint32_t                         u1PPIT:1;
  uint32_t                         u1TXM:1;
  uint32_t                         u1MBI:1;
  uint32_t                         :2;
} stc_FLEXRAY_WRHS1_MIR_field_t;

typedef union un_FLEXRAY_WRHS1_MIR {
  uint32_t                         u32Register;
  stc_FLEXRAY_WRHS1_MIR_field_t    stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_WRHS1_MIR_t;

/**
  * \brief Write Header Section 2 (mirror) (FLEXRAY_WRHS2_MIR)
  */
typedef struct stc_FLEXRAY_WRHS2_MIR_field {
  uint32_t                         u11CRC:11;
  uint32_t                         :5;
  uint32_t                         u7PLC:7;
  uint32_t                         :9;
} stc_FLEXRAY_WRHS2_MIR_field_t;

typedef union un_FLEXRAY_WRHS2_MIR {
  uint32_t                         u32Register;
  stc_FLEXRAY_WRHS2_MIR_field_t    stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_WRHS2_MIR_t;

/**
  * \brief Write Header Section 3 (mirror) (FLEXRAY_WRHS3_MIR)
  */
typedef struct stc_FLEXRAY_WRHS3_MIR_field {
  uint32_t                         u11DP:11;
  uint32_t                         :21;
} stc_FLEXRAY_WRHS3_MIR_field_t;

typedef union un_FLEXRAY_WRHS3_MIR {
  uint32_t                         u32Register;
  stc_FLEXRAY_WRHS3_MIR_field_t    stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_WRHS3_MIR_t;

/**
  * \brief Input Buffer Command Mask (mirror) (FLEXRAY_IBCM_MIR)
  */
typedef struct stc_FLEXRAY_IBCM_MIR_field {
  uint32_t                         u1LHSH:1;
  uint32_t                         u1LDSH:1;
  uint32_t                         u1STXRH:1;
  uint32_t                         :13;
  uint32_t                         u1LHSS:1;
  uint32_t                         u1LDSS:1;
  uint32_t                         u1STXRS:1;
  uint32_t                         :13;
} stc_FLEXRAY_IBCM_MIR_field_t;

typedef union un_FLEXRAY_IBCM_MIR {
  uint32_t                         u32Register;
  stc_FLEXRAY_IBCM_MIR_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_IBCM_MIR_t;

/**
  * \brief Input Buffer Command Request (mirror) (FLEXRAY_IBCR_MIR)
  */
typedef struct stc_FLEXRAY_IBCR_MIR_field {
  uint32_t                         u7IBRH:7;
  uint32_t                         :8;
  uint32_t                         u1IBSYH:1;
  uint32_t                         u7IBRS:7;
  uint32_t                         :8;
  uint32_t                         u1IBSYS:1;
} stc_FLEXRAY_IBCR_MIR_field_t;

typedef union un_FLEXRAY_IBCR_MIR {
  uint32_t                         u32Register;
  stc_FLEXRAY_IBCR_MIR_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_IBCR_MIR_t;

/**
  * \brief Read Header Section 1 (2nd mirror) (FLEXRAY_RDHS1_MIR2)
  */
typedef struct stc_FLEXRAY_RDHS1_MIR2_field {
  uint32_t                         u11FID:11;
  uint32_t                         :5;
  uint32_t                         u7CYC:7;
  uint32_t                         :1;
  uint32_t                         u1CHA:1;
  uint32_t                         u1CHB:1;
  uint32_t                         u1CFG:1;
  uint32_t                         u1PPIT:1;
  uint32_t                         u1TXM:1;
  uint32_t                         u1MBI:1;
  uint32_t                         :2;
} stc_FLEXRAY_RDHS1_MIR2_field_t;

typedef union un_FLEXRAY_RDHS1_MIR2 {
  uint32_t                         u32Register;
  stc_FLEXRAY_RDHS1_MIR2_field_t   stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_RDHS1_MIR2_t;

/**
  * \brief Read Header Section 2 (2nd mirror) (FLEXRAY_RDHS2_MIR2)
  */
typedef struct stc_FLEXRAY_RDHS2_MIR2_field {
  uint32_t                         u11CRC:11;
  uint32_t                         :5;
  uint32_t                         u7PLC:7;
  uint32_t                         :1;
  uint32_t                         u7PLR:7;
} stc_FLEXRAY_RDHS2_MIR2_field_t;

typedef union un_FLEXRAY_RDHS2_MIR2 {
  uint32_t                         u32Register;
  stc_FLEXRAY_RDHS2_MIR2_field_t   stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_RDHS2_MIR2_t;

/**
  * \brief Read Header Section 3 (2nd mirror) (FLEXRAY_RDHS3_MIR2)
  */
typedef struct stc_FLEXRAY_RDHS3_MIR2_field {
  uint32_t                         u11DP:11;
  uint32_t                         :5;
  uint32_t                         u6RCC:6;
  uint32_t                         :2;
  uint32_t                         u1RCI:1;
  uint32_t                         u1SFI:1;
  uint32_t                         u1SYN:1;
  uint32_t                         u1NFI:1;
  uint32_t                         u1PPI:1;
  uint32_t                         u1RES:1;
  uint32_t                         :2;
} stc_FLEXRAY_RDHS3_MIR2_field_t;

typedef union un_FLEXRAY_RDHS3_MIR2 {
  uint32_t                         u32Register;
  stc_FLEXRAY_RDHS3_MIR2_field_t   stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_RDHS3_MIR2_t;

/**
  * \brief Message Buffer Status  (2nd mirror) (FLEXRAY_MBS_MIR2)
  */
typedef struct stc_FLEXRAY_MBS_MIR2_field {
  uint32_t                         u1VFRA:1;
  uint32_t                         u1VFRB:1;
  uint32_t                         u1SEOA:1;
  uint32_t                         u1SEOB:1;
  uint32_t                         u1CEOA:1;
  uint32_t                         u1CEOB:1;
  uint32_t                         u1SVOA:1;
  uint32_t                         u1SVOB:1;
  uint32_t                         u1TCIA:1;
  uint32_t                         u1TCIB:1;
  uint32_t                         u1ESA:1;
  uint32_t                         u1ESB:1;
  uint32_t                         u1MLST:1;
  uint32_t                         :1;
  uint32_t                         u1FTA:1;
  uint32_t                         u1FTB:1;
  uint32_t                         u6CCS:6;
  uint32_t                         :2;
  uint32_t                         u1RCIS:1;
  uint32_t                         u1SFIS:1;
  uint32_t                         u1SYNS:1;
  uint32_t                         u1NFIS:1;
  uint32_t                         u1PPIS:1;
  uint32_t                         u1RESS:1;
  uint32_t                         :2;
} stc_FLEXRAY_MBS_MIR2_field_t;

typedef union un_FLEXRAY_MBS_MIR2 {
  uint32_t                         u32Register;
  stc_FLEXRAY_MBS_MIR2_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_MBS_MIR2_t;

/**
  * \brief Read Data Section [1...64] (mirror) (FLEXRAY_RDDS_MIR)
  */
typedef struct stc_FLEXRAY_RDDS_MIR_field {
  uint32_t                         u32MD:32;
} stc_FLEXRAY_RDDS_MIR_field_t;

typedef union un_FLEXRAY_RDDS_MIR {
  uint32_t                         u32Register;
  stc_FLEXRAY_RDDS_MIR_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_RDDS_MIR_t;

/**
  * \brief Read Header Section 1 (mirror) (FLEXRAY_RDHS1_MIR)
  */
typedef struct stc_FLEXRAY_RDHS1_MIR_field {
  uint32_t                         u11FID:11;
  uint32_t                         :5;
  uint32_t                         u7CYC:7;
  uint32_t                         :1;
  uint32_t                         u1CHA:1;
  uint32_t                         u1CHB:1;
  uint32_t                         u1CFG:1;
  uint32_t                         u1PPIT:1;
  uint32_t                         u1TXM:1;
  uint32_t                         u1MBI:1;
  uint32_t                         :2;
} stc_FLEXRAY_RDHS1_MIR_field_t;

typedef union un_FLEXRAY_RDHS1_MIR {
  uint32_t                         u32Register;
  stc_FLEXRAY_RDHS1_MIR_field_t    stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_RDHS1_MIR_t;

/**
  * \brief Read Header Section 2 (mirror) (FLEXRAY_RDHS2_MIR)
  */
typedef struct stc_FLEXRAY_RDHS2_MIR_field {
  uint32_t                         u11CRC:11;
  uint32_t                         :5;
  uint32_t                         u7PLC:7;
  uint32_t                         :1;
  uint32_t                         u7PLR:7;
} stc_FLEXRAY_RDHS2_MIR_field_t;

typedef union un_FLEXRAY_RDHS2_MIR {
  uint32_t                         u32Register;
  stc_FLEXRAY_RDHS2_MIR_field_t    stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_RDHS2_MIR_t;

/**
  * \brief Read Header Section 3 (mirror) (FLEXRAY_RDHS3_MIR)
  */
typedef struct stc_FLEXRAY_RDHS3_MIR_field {
  uint32_t                         u11DP:11;
  uint32_t                         :5;
  uint32_t                         u6RCC:6;
  uint32_t                         :2;
  uint32_t                         u1RCI:1;
  uint32_t                         u1SFI:1;
  uint32_t                         u1SYN:1;
  uint32_t                         u1NFI:1;
  uint32_t                         u1PPI:1;
  uint32_t                         u1RES:1;
  uint32_t                         :2;
} stc_FLEXRAY_RDHS3_MIR_field_t;

typedef union un_FLEXRAY_RDHS3_MIR {
  uint32_t                         u32Register;
  stc_FLEXRAY_RDHS3_MIR_field_t    stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_RDHS3_MIR_t;

/**
  * \brief Message Buffer Status (mirror) (FLEXRAY_MBS_MIR)
  */
typedef struct stc_FLEXRAY_MBS_MIR_field {
  uint32_t                         u1VFRA:1;
  uint32_t                         u1VFRB:1;
  uint32_t                         u1SEOA:1;
  uint32_t                         u1SEOB:1;
  uint32_t                         u1CEOA:1;
  uint32_t                         u1CEOB:1;
  uint32_t                         u1SVOA:1;
  uint32_t                         u1SVOB:1;
  uint32_t                         u1TCIA:1;
  uint32_t                         u1TCIB:1;
  uint32_t                         u1ESA:1;
  uint32_t                         u1ESB:1;
  uint32_t                         u1MLST:1;
  uint32_t                         :1;
  uint32_t                         u1FTA:1;
  uint32_t                         u1FTB:1;
  uint32_t                         u6CCS:6;
  uint32_t                         :2;
  uint32_t                         u1RCIS:1;
  uint32_t                         u1SFIS:1;
  uint32_t                         u1SYNS:1;
  uint32_t                         u1NFIS:1;
  uint32_t                         u1PPIS:1;
  uint32_t                         u1RESS:1;
  uint32_t                         :2;
} stc_FLEXRAY_MBS_MIR_field_t;

typedef union un_FLEXRAY_MBS_MIR {
  uint32_t                         u32Register;
  stc_FLEXRAY_MBS_MIR_field_t      stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_MBS_MIR_t;

/**
  * \brief Output Buffer Command Mask (mirror) (FLEXRAY_OBCM_MIR)
  */
typedef struct stc_FLEXRAY_OBCM_MIR_field {
  uint32_t                         u1RHSS:1;
  uint32_t                         u1RDSS:1;
  uint32_t                         :14;
  uint32_t                         u1RHSH:1;
  uint32_t                         u1RDSH:1;
  uint32_t                         :14;
} stc_FLEXRAY_OBCM_MIR_field_t;

typedef union un_FLEXRAY_OBCM_MIR {
  uint32_t                         u32Register;
  stc_FLEXRAY_OBCM_MIR_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_OBCM_MIR_t;

/**
  * \brief Output Buffer Command Request (mirror) (FLEXRAY_OBCR_MIR)
  */
typedef struct stc_FLEXRAY_OBCR_MIR_field {
  uint32_t                         u7OBRS:7;
  uint32_t                         :1;
  uint32_t                         u1VIEW:1;
  uint32_t                         u1REQ:1;
  uint32_t                         :5;
  uint32_t                         u1OBSYS:1;
  uint32_t                         u7OBRH:7;
  uint32_t                         :9;
} stc_FLEXRAY_OBCR_MIR_field_t;

typedef union un_FLEXRAY_OBCR_MIR {
  uint32_t                         u32Register;
  stc_FLEXRAY_OBCR_MIR_field_t     stcField;
  uint8_t                          au8Byte[4];
  uint16_t                         au16Halfword[2];
} un_FLEXRAY_OBCR_MIR_t;



/**
  * \brief FlexRay Bus Interface (FLEXRAY)
  */
typedef struct stc_FLEXRAY {
  un_FLEXRAY_CTL_t                 unCTL;              /*!< 0x00000000 Control Register */
  un_FLEXRAY_DMA_CTL_t             unDMA_CTL;          /*!< 0x00000004 DMA Control Register */
  uint32_t                         au32Reserved[2];
  un_FLEXRAY_TEST1_t               unTEST1;            /*!< 0x00000010 Test Register 1 */
  un_FLEXRAY_TEST2_t               unTEST2;            /*!< 0x00000014 Test Register 2 */
  uint32_t                         u32Reserved1;
  un_FLEXRAY_LCK_t                 unLCK;              /*!< 0x0000001C Lock Register */
  un_FLEXRAY_EIR_t                 unEIR;              /*!< 0x00000020 Error Interrupt Register */
  un_FLEXRAY_SIR_t                 unSIR;              /*!< 0x00000024 Status Interrupt Register */
  un_FLEXRAY_EILS_t                unEILS;             /*!< 0x00000028 Error Interrupt Line Select */
  un_FLEXRAY_SILS_t                unSILS;             /*!< 0x0000002C Status Interrupt Line Select */
  un_FLEXRAY_EIES_t                unEIES;             /*!< 0x00000030 Error Interrupt Enable Set */
  un_FLEXRAY_EIER_t                unEIER;             /*!< 0x00000034 Error Interrupt Enable Reset */
  un_FLEXRAY_SIES_t                unSIES;             /*!< 0x00000038 Status Interrupt Enable Set */
  un_FLEXRAY_SIER_t                unSIER;             /*!< 0x0000003C Status Interrupt Enable Reset */
  un_FLEXRAY_ILE_t                 unILE;              /*!< 0x00000040 Interrupt Line Enable */
  un_FLEXRAY_T0C_t                 unT0C;              /*!< 0x00000044 Timer 0 Configuration */
  un_FLEXRAY_T1C_t                 unT1C;              /*!< 0x00000048 Timer 1 Configuration */
  un_FLEXRAY_STPW1_t               unSTPW1;            /*!< 0x0000004C Stop Watch Register 1 */
  un_FLEXRAY_STPW2_t               unSTPW2;            /*!< 0x00000050 Stop Watch Register 2 */
  uint32_t                         au32Reserved2[11];
  un_FLEXRAY_SUCC1_t               unSUCC1;            /*!< 0x00000080 SUC Configuration Register 1 */
  un_FLEXRAY_SUCC2_t               unSUCC2;            /*!< 0x00000084 SUC Configuration Register 2 */
  un_FLEXRAY_SUCC3_t               unSUCC3;            /*!< 0x00000088 SUC Configuration Register 3 */
  un_FLEXRAY_NEMC_t                unNEMC;             /*!< 0x0000008C NEM Configuration Register */
  un_FLEXRAY_PRTC1_t               unPRTC1;            /*!< 0x00000090 PRT Configuration Register 1 */
  un_FLEXRAY_PRTC2_t               unPRTC2;            /*!< 0x00000094 PRT Configuration Register 2 */
  un_FLEXRAY_MHDC_t                unMHDC;             /*!< 0x00000098 MHD Configuration Register */
  uint32_t                         u32Reserved3;
  un_FLEXRAY_GTUC1_t               unGTUC1;            /*!< 0x000000A0 GTU Configuration Register 1 */
  un_FLEXRAY_GTUC2_t               unGTUC2;            /*!< 0x000000A4 GTU Configuration Register 2 */
  un_FLEXRAY_GTUC3_t               unGTUC3;            /*!< 0x000000A8 GTU Configuration Register 3 */
  un_FLEXRAY_GTUC4_t               unGTUC4;            /*!< 0x000000AC GTU Configuration Register 4 */
  un_FLEXRAY_GTUC5_t               unGTUC5;            /*!< 0x000000B0 GTU Configuration Register 5 */
  un_FLEXRAY_GTUC6_t               unGTUC6;            /*!< 0x000000B4 GTU Configuration Register 6 */
  un_FLEXRAY_GTUC7_t               unGTUC7;            /*!< 0x000000B8 GTU Configuration Register 7 */
  un_FLEXRAY_GTUC8_t               unGTUC8;            /*!< 0x000000BC GTU Configuration Register 8 */
  un_FLEXRAY_GTUC9_t               unGTUC9;            /*!< 0x000000C0 GTU Configuration Register 9 */
  un_FLEXRAY_GTUC10_t              unGTUC10;           /*!< 0x000000C4 GTU Configuration Register 10 */
  un_FLEXRAY_GTUC11_t              unGTUC11;           /*!< 0x000000C8 GTU Configuration Register 11 */
  uint32_t                         au32Reserved4[13];
  un_FLEXRAY_CCSV_t                unCCSV;             /*!< 0x00000100 CC Status Vector */
  un_FLEXRAY_CCEV_t                unCCEV;             /*!< 0x00000104 CC Error Vector */
  uint32_t                         au32Reserved5[2];
  un_FLEXRAY_SCV_t                 unSCV;              /*!< 0x00000110 Slot Counter Value */
  un_FLEXRAY_MTCCV_t               unMTCCV;            /*!< 0x00000114 Macrotick and Cycle Counter Value */
  un_FLEXRAY_RCV_t                 unRCV;              /*!< 0x00000118 Rate Correction Value */
  un_FLEXRAY_OCV_t                 unOCV;              /*!< 0x0000011C Offset Correction Value */
  un_FLEXRAY_SFS_t                 unSFS;              /*!< 0x00000120 Sync Frame Status */
  un_FLEXRAY_SWNIT_t               unSWNIT;            /*!< 0x00000124 Symbol Window and NIT Status */
  un_FLEXRAY_ACS_t                 unACS;              /*!< 0x00000128 Aggregated Channel Status */
  uint32_t                         u32Reserved6;
  un_FLEXRAY_ESID_t                unESID[15];         /*!< 0x00000130 Even Sync ID [1...15] */
  uint32_t                         u32Reserved7;
  un_FLEXRAY_OSID_t                unOSID[15];         /*!< 0x00000170 Odd Sync ID [1...15] */
  uint32_t                         u32Reserved8;
  un_FLEXRAY_NMV1_t                unNMV1;             /*!< 0x000001B0 Network Management Vector 1 */
  un_FLEXRAY_NMV2_t                unNMV2;             /*!< 0x000001B4 Network Management Vector 2 */
  un_FLEXRAY_NMV3_t                unNMV3;             /*!< 0x000001B8 Network Management Vector 3 */
  uint32_t                         au32Reserved9[81];
  un_FLEXRAY_MRC_t                 unMRC;              /*!< 0x00000300 Message RAM Configuration */
  un_FLEXRAY_FRF_t                 unFRF;              /*!< 0x00000304 FIFO Rejection Filter */
  un_FLEXRAY_FRFM_t                unFRFM;             /*!< 0x00000308 FIFO Rejection Filter Mask */
  un_FLEXRAY_FCL_t                 unFCL;              /*!< 0x0000030C FIFO Critical Level */
  un_FLEXRAY_MHDS_t                unMHDS;             /*!< 0x00000310 Message Handler Status */
  un_FLEXRAY_LDTS_t                unLDTS;             /*!< 0x00000314 Last Dynamic Transmit Slot */
  un_FLEXRAY_FSR_t                 unFSR;              /*!< 0x00000318 FIFO Status Register */
  un_FLEXRAY_MHDF_t                unMHDF;             /*!< 0x0000031C Message Handler Constraints Flags */
  un_FLEXRAY_TXRQ1_t               unTXRQ1;            /*!< 0x00000320 Transmission Request 1 */
  un_FLEXRAY_TXRQ2_t               unTXRQ2;            /*!< 0x00000324 Transmission Request 2 */
  un_FLEXRAY_TXRQ3_t               unTXRQ3;            /*!< 0x00000328 Transmission Request 3 */
  un_FLEXRAY_TXRQ4_t               unTXRQ4;            /*!< 0x0000032C Transmission Request 4 */
  un_FLEXRAY_NDAT1_t               unNDAT1;            /*!< 0x00000330 New Data 1 */
  un_FLEXRAY_NDAT2_t               unNDAT2;            /*!< 0x00000334 New Data 2 */
  un_FLEXRAY_NDAT3_t               unNDAT3;            /*!< 0x00000338 New Data 3 */
  un_FLEXRAY_NDAT4_t               unNDAT4;            /*!< 0x0000033C New Data 4 */
  un_FLEXRAY_MBSC1_t               unMBSC1;            /*!< 0x00000340 Message Buffer Status Changed 1 */
  un_FLEXRAY_MBSC2_t               unMBSC2;            /*!< 0x00000344 Message Buffer Status Changed 2 */
  un_FLEXRAY_MBSC3_t               unMBSC3;            /*!< 0x00000348 Message Buffer Status Changed 3 */
  un_FLEXRAY_MBSC4_t               unMBSC4;            /*!< 0x0000034C Message Buffer Status Changed 4 */
  uint32_t                         au32Reserved10[40];
  un_FLEXRAY_CREL_t                unCREL;             /*!< 0x000003F0 Core Release Register */
  un_FLEXRAY_ENDN_t                unENDN;             /*!< 0x000003F4 Endian Register */
  uint32_t                         au32Reserved11[2];
  un_FLEXRAY_WRDS_t                unWRDS[64];         /*!< 0x00000400 Write Data Section [1...64] */
  un_FLEXRAY_WRHS1_t               unWRHS1;            /*!< 0x00000500 Write Header Section 1 */
  un_FLEXRAY_WRHS2_t               unWRHS2;            /*!< 0x00000504 Write Header Section 2 */
  un_FLEXRAY_WRHS3_t               unWRHS3;            /*!< 0x00000508 Write Header Section 3 */
  uint32_t                         u32Reserved12;
  un_FLEXRAY_IBCM_t                unIBCM;             /*!< 0x00000510 Input Buffer Command Mask */
  un_FLEXRAY_IBCR_t                unIBCR;             /*!< 0x00000514 Input Buffer Command Request */
  uint32_t                         au32Reserved13[58];
  un_FLEXRAY_RDDS_t                unRDDS[64];         /*!< 0x00000600 Read Data Section [1...64] */
  un_FLEXRAY_RDHS1_t               unRDHS1;            /*!< 0x00000700 Read Header Section 1 */
  un_FLEXRAY_RDHS2_t               unRDHS2;            /*!< 0x00000704 Read Header Section 2 */
  un_FLEXRAY_RDHS3_t               unRDHS3;            /*!< 0x00000708 Read Header Section 3 */
  un_FLEXRAY_MBS_t                 unMBS;              /*!< 0x0000070C Message Buffer Status */
  un_FLEXRAY_OBCM_t                unOBCM;             /*!< 0x00000710 Output Buffer Command Mask */
  un_FLEXRAY_OBCR_t                unOBCR;             /*!< 0x00000714 Output Buffer Command Request */
  uint32_t                         au32Reserved14[310];
  un_FLEXRAY_WRHS1_MIR2_t          unWRHS1_MIR2;       /*!< 0x00000BF0 Write Header Section 1 (2nd mirror) */
  un_FLEXRAY_WRHS2_MIR2_t          unWRHS2_MIR2;       /*!< 0x00000BF4 Write Header Section 2 (2nd mirror) */
  un_FLEXRAY_WRHS3_MIR2_t          unWRHS3_MIR2;       /*!< 0x00000BF8 Write Header Section 3 (2nd mirror) */
  uint32_t                         u32Reserved15;
  un_FLEXRAY_WRDS_MIR_t            unWRDS_MIR[64];     /*!< 0x00000C00 Write Data Section [1...64] (mirror) */
  un_FLEXRAY_WRHS1_MIR_t           unWRHS1_MIR;        /*!< 0x00000D00 Write Header Section 1 (mirror) */
  un_FLEXRAY_WRHS2_MIR_t           unWRHS2_MIR;        /*!< 0x00000D04 Write Header Section 2 (mirror) */
  un_FLEXRAY_WRHS3_MIR_t           unWRHS3_MIR;        /*!< 0x00000D08 Write Header Section 3 (mirror) */
  uint32_t                         u32Reserved16;
  un_FLEXRAY_IBCM_MIR_t            unIBCM_MIR;         /*!< 0x00000D10 Input Buffer Command Mask (mirror) */
  un_FLEXRAY_IBCR_MIR_t            unIBCR_MIR;         /*!< 0x00000D14 Input Buffer Command Request (mirror) */
  uint32_t                         au32Reserved17[54];
  un_FLEXRAY_RDHS1_MIR2_t          unRDHS1_MIR2;       /*!< 0x00000DF0 Read Header Section 1 (2nd mirror) */
  un_FLEXRAY_RDHS2_MIR2_t          unRDHS2_MIR2;       /*!< 0x00000DF4 Read Header Section 2 (2nd mirror) */
  un_FLEXRAY_RDHS3_MIR2_t          unRDHS3_MIR2;       /*!< 0x00000DF8 Read Header Section 3 (2nd mirror) */
  un_FLEXRAY_MBS_MIR2_t            unMBS_MIR2;         /*!< 0x00000DFC Message Buffer Status  (2nd mirror) */
  un_FLEXRAY_RDDS_MIR_t            unRDDS_MIR[64];     /*!< 0x00000E00 Read Data Section [1...64] (mirror) */
  un_FLEXRAY_RDHS1_MIR_t           unRDHS1_MIR;        /*!< 0x00000F00 Read Header Section 1 (mirror) */
  un_FLEXRAY_RDHS2_MIR_t           unRDHS2_MIR;        /*!< 0x00000F04 Read Header Section 2 (mirror) */
  un_FLEXRAY_RDHS3_MIR_t           unRDHS3_MIR;        /*!< 0x00000F08 Read Header Section 3 (mirror) */
  un_FLEXRAY_MBS_MIR_t             unMBS_MIR;          /*!< 0x00000F0C Message Buffer Status (mirror) */
  un_FLEXRAY_OBCM_MIR_t            unOBCM_MIR;         /*!< 0x00000F10 Output Buffer Command Mask (mirror) */
  un_FLEXRAY_OBCR_MIR_t            unOBCR_MIR;         /*!< 0x00000F14 Output Buffer Command Request (mirror) */
} stc_FLEXRAY_t;                                       /*!< Size = 3864 (0xF18) */


/* FLEXRAY.CTL */
#define FLEXRAY_CTL_ENABLED_Pos                 31UL
#define FLEXRAY_CTL_ENABLED_Msk                 0x80000000UL
/* FLEXRAY.DMA_CTL */
#define FLEXRAY_DMA_CTL_IDMATOE_Pos             0UL
#define FLEXRAY_DMA_CTL_IDMATOE_Msk             0x1UL
#define FLEXRAY_DMA_CTL_ODMATOE_Pos             1UL
#define FLEXRAY_DMA_CTL_ODMATOE_Msk             0x2UL
#define FLEXRAY_DMA_CTL_ODMAFFE_Pos             2UL
#define FLEXRAY_DMA_CTL_ODMAFFE_Msk             0x4UL
/* FLEXRAY.TEST1 */
#define FLEXRAY_TEST1_WRTEN_Pos                 0UL
#define FLEXRAY_TEST1_WRTEN_Msk                 0x1UL
#define FLEXRAY_TEST1_ELBE_Pos                  1UL
#define FLEXRAY_TEST1_ELBE_Msk                  0x2UL
#define FLEXRAY_TEST1_TMC_Pos                   4UL
#define FLEXRAY_TEST1_TMC_Msk                   0x30UL
#define FLEXRAY_TEST1_AOA_Pos                   8UL
#define FLEXRAY_TEST1_AOA_Msk                   0x100UL
#define FLEXRAY_TEST1_AOB_Pos                   9UL
#define FLEXRAY_TEST1_AOB_Msk                   0x200UL
#define FLEXRAY_TEST1_RXA_Pos                   16UL
#define FLEXRAY_TEST1_RXA_Msk                   0x10000UL
#define FLEXRAY_TEST1_RXB_Pos                   17UL
#define FLEXRAY_TEST1_RXB_Msk                   0x20000UL
#define FLEXRAY_TEST1_TXA_Pos                   18UL
#define FLEXRAY_TEST1_TXA_Msk                   0x40000UL
#define FLEXRAY_TEST1_TXB_Pos                   19UL
#define FLEXRAY_TEST1_TXB_Msk                   0x80000UL
#define FLEXRAY_TEST1_TXENA_Pos                 20UL
#define FLEXRAY_TEST1_TXENA_Msk                 0x100000UL
#define FLEXRAY_TEST1_TXENB_Pos                 21UL
#define FLEXRAY_TEST1_TXENB_Msk                 0x200000UL
#define FLEXRAY_TEST1_CERA_Pos                  24UL
#define FLEXRAY_TEST1_CERA_Msk                  0xF000000UL
#define FLEXRAY_TEST1_CERB_Pos                  28UL
#define FLEXRAY_TEST1_CERB_Msk                  0xF0000000UL
/* FLEXRAY.TEST2 */
#define FLEXRAY_TEST2_RS_Pos                    0UL
#define FLEXRAY_TEST2_RS_Msk                    0x7UL
#define FLEXRAY_TEST2_SSEL_Pos                  4UL
#define FLEXRAY_TEST2_SSEL_Msk                  0x70UL
#define FLEXRAY_TEST2_WRPB_Pos                  14UL
#define FLEXRAY_TEST2_WRPB_Msk                  0x4000UL
#define FLEXRAY_TEST2_RDPB_Pos                  15UL
#define FLEXRAY_TEST2_RDPB_Msk                  0x8000UL
/* FLEXRAY.LCK */
#define FLEXRAY_LCK_CLK_Pos                     0UL
#define FLEXRAY_LCK_CLK_Msk                     0xFFUL
#define FLEXRAY_LCK_TMK_Pos                     8UL
#define FLEXRAY_LCK_TMK_Msk                     0xFF00UL
/* FLEXRAY.EIR */
#define FLEXRAY_EIR_PEMC_Pos                    0UL
#define FLEXRAY_EIR_PEMC_Msk                    0x1UL
#define FLEXRAY_EIR_CNA_Pos                     1UL
#define FLEXRAY_EIR_CNA_Msk                     0x2UL
#define FLEXRAY_EIR_SFBM_Pos                    2UL
#define FLEXRAY_EIR_SFBM_Msk                    0x4UL
#define FLEXRAY_EIR_SFO_Pos                     3UL
#define FLEXRAY_EIR_SFO_Msk                     0x8UL
#define FLEXRAY_EIR_CCF_Pos                     4UL
#define FLEXRAY_EIR_CCF_Msk                     0x10UL
#define FLEXRAY_EIR_CCL_Pos                     5UL
#define FLEXRAY_EIR_CCL_Msk                     0x20UL
#define FLEXRAY_EIR_PERR_Pos                    6UL
#define FLEXRAY_EIR_PERR_Msk                    0x40UL
#define FLEXRAY_EIR_RFO_Pos                     7UL
#define FLEXRAY_EIR_RFO_Msk                     0x80UL
#define FLEXRAY_EIR_EFA_Pos                     8UL
#define FLEXRAY_EIR_EFA_Msk                     0x100UL
#define FLEXRAY_EIR_IIBA_Pos                    9UL
#define FLEXRAY_EIR_IIBA_Msk                    0x200UL
#define FLEXRAY_EIR_IOBA_Pos                    10UL
#define FLEXRAY_EIR_IOBA_Msk                    0x400UL
#define FLEXRAY_EIR_MHF_Pos                     11UL
#define FLEXRAY_EIR_MHF_Msk                     0x800UL
#define FLEXRAY_EIR_EDA_Pos                     16UL
#define FLEXRAY_EIR_EDA_Msk                     0x10000UL
#define FLEXRAY_EIR_LTVA_Pos                    17UL
#define FLEXRAY_EIR_LTVA_Msk                    0x20000UL
#define FLEXRAY_EIR_TABA_Pos                    18UL
#define FLEXRAY_EIR_TABA_Msk                    0x40000UL
#define FLEXRAY_EIR_EDB_Pos                     24UL
#define FLEXRAY_EIR_EDB_Msk                     0x1000000UL
#define FLEXRAY_EIR_LTVB_Pos                    25UL
#define FLEXRAY_EIR_LTVB_Msk                    0x2000000UL
#define FLEXRAY_EIR_TABB_Pos                    26UL
#define FLEXRAY_EIR_TABB_Msk                    0x4000000UL
/* FLEXRAY.SIR */
#define FLEXRAY_SIR_WST_Pos                     0UL
#define FLEXRAY_SIR_WST_Msk                     0x1UL
#define FLEXRAY_SIR_CAS_Pos                     1UL
#define FLEXRAY_SIR_CAS_Msk                     0x2UL
#define FLEXRAY_SIR_CYCS_Pos                    2UL
#define FLEXRAY_SIR_CYCS_Msk                    0x4UL
#define FLEXRAY_SIR_TXI_Pos                     3UL
#define FLEXRAY_SIR_TXI_Msk                     0x8UL
#define FLEXRAY_SIR_RXI_Pos                     4UL
#define FLEXRAY_SIR_RXI_Msk                     0x10UL
#define FLEXRAY_SIR_RFNE_Pos                    5UL
#define FLEXRAY_SIR_RFNE_Msk                    0x20UL
#define FLEXRAY_SIR_RFCL_Pos                    6UL
#define FLEXRAY_SIR_RFCL_Msk                    0x40UL
#define FLEXRAY_SIR_NMVC_Pos                    7UL
#define FLEXRAY_SIR_NMVC_Msk                    0x80UL
#define FLEXRAY_SIR_TI0_Pos                     8UL
#define FLEXRAY_SIR_TI0_Msk                     0x100UL
#define FLEXRAY_SIR_TI1_Pos                     9UL
#define FLEXRAY_SIR_TI1_Msk                     0x200UL
#define FLEXRAY_SIR_TIBC_Pos                    10UL
#define FLEXRAY_SIR_TIBC_Msk                    0x400UL
#define FLEXRAY_SIR_TOBC_Pos                    11UL
#define FLEXRAY_SIR_TOBC_Msk                    0x800UL
#define FLEXRAY_SIR_SWE_Pos                     12UL
#define FLEXRAY_SIR_SWE_Msk                     0x1000UL
#define FLEXRAY_SIR_SUCS_Pos                    13UL
#define FLEXRAY_SIR_SUCS_Msk                    0x2000UL
#define FLEXRAY_SIR_MBSI_Pos                    14UL
#define FLEXRAY_SIR_MBSI_Msk                    0x4000UL
#define FLEXRAY_SIR_SDS_Pos                     15UL
#define FLEXRAY_SIR_SDS_Msk                     0x8000UL
#define FLEXRAY_SIR_WUPA_Pos                    16UL
#define FLEXRAY_SIR_WUPA_Msk                    0x10000UL
#define FLEXRAY_SIR_MTSA_Pos                    17UL
#define FLEXRAY_SIR_MTSA_Msk                    0x20000UL
#define FLEXRAY_SIR_WUPB_Pos                    24UL
#define FLEXRAY_SIR_WUPB_Msk                    0x1000000UL
#define FLEXRAY_SIR_MTSB_Pos                    25UL
#define FLEXRAY_SIR_MTSB_Msk                    0x2000000UL
/* FLEXRAY.EILS */
#define FLEXRAY_EILS_PEMCL_Pos                  0UL
#define FLEXRAY_EILS_PEMCL_Msk                  0x1UL
#define FLEXRAY_EILS_CNAL_Pos                   1UL
#define FLEXRAY_EILS_CNAL_Msk                   0x2UL
#define FLEXRAY_EILS_SFBML_Pos                  2UL
#define FLEXRAY_EILS_SFBML_Msk                  0x4UL
#define FLEXRAY_EILS_SFOL_Pos                   3UL
#define FLEXRAY_EILS_SFOL_Msk                   0x8UL
#define FLEXRAY_EILS_CCFL_Pos                   4UL
#define FLEXRAY_EILS_CCFL_Msk                   0x10UL
#define FLEXRAY_EILS_CCLL_Pos                   5UL
#define FLEXRAY_EILS_CCLL_Msk                   0x20UL
#define FLEXRAY_EILS_PERRL_Pos                  6UL
#define FLEXRAY_EILS_PERRL_Msk                  0x40UL
#define FLEXRAY_EILS_RFOL_Pos                   7UL
#define FLEXRAY_EILS_RFOL_Msk                   0x80UL
#define FLEXRAY_EILS_EFAL_Pos                   8UL
#define FLEXRAY_EILS_EFAL_Msk                   0x100UL
#define FLEXRAY_EILS_IIBAL_Pos                  9UL
#define FLEXRAY_EILS_IIBAL_Msk                  0x200UL
#define FLEXRAY_EILS_IOBAL_Pos                  10UL
#define FLEXRAY_EILS_IOBAL_Msk                  0x400UL
#define FLEXRAY_EILS_MHFL_Pos                   11UL
#define FLEXRAY_EILS_MHFL_Msk                   0x800UL
#define FLEXRAY_EILS_EDAL_Pos                   16UL
#define FLEXRAY_EILS_EDAL_Msk                   0x10000UL
#define FLEXRAY_EILS_LTVAL_Pos                  17UL
#define FLEXRAY_EILS_LTVAL_Msk                  0x20000UL
#define FLEXRAY_EILS_TABAL_Pos                  18UL
#define FLEXRAY_EILS_TABAL_Msk                  0x40000UL
#define FLEXRAY_EILS_EDBL_Pos                   24UL
#define FLEXRAY_EILS_EDBL_Msk                   0x1000000UL
#define FLEXRAY_EILS_LTVBL_Pos                  25UL
#define FLEXRAY_EILS_LTVBL_Msk                  0x2000000UL
#define FLEXRAY_EILS_TABBL_Pos                  26UL
#define FLEXRAY_EILS_TABBL_Msk                  0x4000000UL
/* FLEXRAY.SILS */
#define FLEXRAY_SILS_WSTL_Pos                   0UL
#define FLEXRAY_SILS_WSTL_Msk                   0x1UL
#define FLEXRAY_SILS_CASL_Pos                   1UL
#define FLEXRAY_SILS_CASL_Msk                   0x2UL
#define FLEXRAY_SILS_CYCSL_Pos                  2UL
#define FLEXRAY_SILS_CYCSL_Msk                  0x4UL
#define FLEXRAY_SILS_TXIL_Pos                   3UL
#define FLEXRAY_SILS_TXIL_Msk                   0x8UL
#define FLEXRAY_SILS_RXIL_Pos                   4UL
#define FLEXRAY_SILS_RXIL_Msk                   0x10UL
#define FLEXRAY_SILS_RFNEL_Pos                  5UL
#define FLEXRAY_SILS_RFNEL_Msk                  0x20UL
#define FLEXRAY_SILS_RFCLL_Pos                  6UL
#define FLEXRAY_SILS_RFCLL_Msk                  0x40UL
#define FLEXRAY_SILS_NMVCL_Pos                  7UL
#define FLEXRAY_SILS_NMVCL_Msk                  0x80UL
#define FLEXRAY_SILS_TI0L_Pos                   8UL
#define FLEXRAY_SILS_TI0L_Msk                   0x100UL
#define FLEXRAY_SILS_TI1L_Pos                   9UL
#define FLEXRAY_SILS_TI1L_Msk                   0x200UL
#define FLEXRAY_SILS_TIBCL_Pos                  10UL
#define FLEXRAY_SILS_TIBCL_Msk                  0x400UL
#define FLEXRAY_SILS_TOBCL_Pos                  11UL
#define FLEXRAY_SILS_TOBCL_Msk                  0x800UL
#define FLEXRAY_SILS_SWEL_Pos                   12UL
#define FLEXRAY_SILS_SWEL_Msk                   0x1000UL
#define FLEXRAY_SILS_SUCSL_Pos                  13UL
#define FLEXRAY_SILS_SUCSL_Msk                  0x2000UL
#define FLEXRAY_SILS_MBSIL_Pos                  14UL
#define FLEXRAY_SILS_MBSIL_Msk                  0x4000UL
#define FLEXRAY_SILS_SDSL_Pos                   15UL
#define FLEXRAY_SILS_SDSL_Msk                   0x8000UL
#define FLEXRAY_SILS_WUPAL_Pos                  16UL
#define FLEXRAY_SILS_WUPAL_Msk                  0x10000UL
#define FLEXRAY_SILS_MTSAL_Pos                  17UL
#define FLEXRAY_SILS_MTSAL_Msk                  0x20000UL
#define FLEXRAY_SILS_WUPBL_Pos                  24UL
#define FLEXRAY_SILS_WUPBL_Msk                  0x1000000UL
#define FLEXRAY_SILS_MTSBL_Pos                  25UL
#define FLEXRAY_SILS_MTSBL_Msk                  0x2000000UL
/* FLEXRAY.EIES */
#define FLEXRAY_EIES_PEMCE_Pos                  0UL
#define FLEXRAY_EIES_PEMCE_Msk                  0x1UL
#define FLEXRAY_EIES_CNAE_Pos                   1UL
#define FLEXRAY_EIES_CNAE_Msk                   0x2UL
#define FLEXRAY_EIES_SFBME_Pos                  2UL
#define FLEXRAY_EIES_SFBME_Msk                  0x4UL
#define FLEXRAY_EIES_SFOE_Pos                   3UL
#define FLEXRAY_EIES_SFOE_Msk                   0x8UL
#define FLEXRAY_EIES_CCFE_Pos                   4UL
#define FLEXRAY_EIES_CCFE_Msk                   0x10UL
#define FLEXRAY_EIES_CCLE_Pos                   5UL
#define FLEXRAY_EIES_CCLE_Msk                   0x20UL
#define FLEXRAY_EIES_PERRE_Pos                  6UL
#define FLEXRAY_EIES_PERRE_Msk                  0x40UL
#define FLEXRAY_EIES_RFOE_Pos                   7UL
#define FLEXRAY_EIES_RFOE_Msk                   0x80UL
#define FLEXRAY_EIES_EFAE_Pos                   8UL
#define FLEXRAY_EIES_EFAE_Msk                   0x100UL
#define FLEXRAY_EIES_IIBAE_Pos                  9UL
#define FLEXRAY_EIES_IIBAE_Msk                  0x200UL
#define FLEXRAY_EIES_IOBAE_Pos                  10UL
#define FLEXRAY_EIES_IOBAE_Msk                  0x400UL
#define FLEXRAY_EIES_MHFE_Pos                   11UL
#define FLEXRAY_EIES_MHFE_Msk                   0x800UL
#define FLEXRAY_EIES_EDAE_Pos                   16UL
#define FLEXRAY_EIES_EDAE_Msk                   0x10000UL
#define FLEXRAY_EIES_LTVAE_Pos                  17UL
#define FLEXRAY_EIES_LTVAE_Msk                  0x20000UL
#define FLEXRAY_EIES_TABAE_Pos                  18UL
#define FLEXRAY_EIES_TABAE_Msk                  0x40000UL
#define FLEXRAY_EIES_EDBE_Pos                   24UL
#define FLEXRAY_EIES_EDBE_Msk                   0x1000000UL
#define FLEXRAY_EIES_LTVBE_Pos                  25UL
#define FLEXRAY_EIES_LTVBE_Msk                  0x2000000UL
#define FLEXRAY_EIES_TABBE_Pos                  26UL
#define FLEXRAY_EIES_TABBE_Msk                  0x4000000UL
/* FLEXRAY.EIER */
#define FLEXRAY_EIER_PEMCE_Pos                  0UL
#define FLEXRAY_EIER_PEMCE_Msk                  0x1UL
#define FLEXRAY_EIER_CNAE_Pos                   1UL
#define FLEXRAY_EIER_CNAE_Msk                   0x2UL
#define FLEXRAY_EIER_SFBME_Pos                  2UL
#define FLEXRAY_EIER_SFBME_Msk                  0x4UL
#define FLEXRAY_EIER_SFOE_Pos                   3UL
#define FLEXRAY_EIER_SFOE_Msk                   0x8UL
#define FLEXRAY_EIER_CCFE_Pos                   4UL
#define FLEXRAY_EIER_CCFE_Msk                   0x10UL
#define FLEXRAY_EIER_CCLE_Pos                   5UL
#define FLEXRAY_EIER_CCLE_Msk                   0x20UL
#define FLEXRAY_EIER_PERRE_Pos                  6UL
#define FLEXRAY_EIER_PERRE_Msk                  0x40UL
#define FLEXRAY_EIER_RFOE_Pos                   7UL
#define FLEXRAY_EIER_RFOE_Msk                   0x80UL
#define FLEXRAY_EIER_EFAE_Pos                   8UL
#define FLEXRAY_EIER_EFAE_Msk                   0x100UL
#define FLEXRAY_EIER_IIBAE_Pos                  9UL
#define FLEXRAY_EIER_IIBAE_Msk                  0x200UL
#define FLEXRAY_EIER_IOBAE_Pos                  10UL
#define FLEXRAY_EIER_IOBAE_Msk                  0x400UL
#define FLEXRAY_EIER_MHFE_Pos                   11UL
#define FLEXRAY_EIER_MHFE_Msk                   0x800UL
#define FLEXRAY_EIER_EDAE_Pos                   16UL
#define FLEXRAY_EIER_EDAE_Msk                   0x10000UL
#define FLEXRAY_EIER_LTVAE_Pos                  17UL
#define FLEXRAY_EIER_LTVAE_Msk                  0x20000UL
#define FLEXRAY_EIER_TABAE_Pos                  18UL
#define FLEXRAY_EIER_TABAE_Msk                  0x40000UL
#define FLEXRAY_EIER_EDBE_Pos                   24UL
#define FLEXRAY_EIER_EDBE_Msk                   0x1000000UL
#define FLEXRAY_EIER_LTVBE_Pos                  25UL
#define FLEXRAY_EIER_LTVBE_Msk                  0x2000000UL
#define FLEXRAY_EIER_TABBE_Pos                  26UL
#define FLEXRAY_EIER_TABBE_Msk                  0x4000000UL
/* FLEXRAY.SIES */
#define FLEXRAY_SIES_WSTE_Pos                   0UL
#define FLEXRAY_SIES_WSTE_Msk                   0x1UL
#define FLEXRAY_SIES_CASE_Pos                   1UL
#define FLEXRAY_SIES_CASE_Msk                   0x2UL
#define FLEXRAY_SIES_CYCSE_Pos                  2UL
#define FLEXRAY_SIES_CYCSE_Msk                  0x4UL
#define FLEXRAY_SIES_TXIE_Pos                   3UL
#define FLEXRAY_SIES_TXIE_Msk                   0x8UL
#define FLEXRAY_SIES_RXIE_Pos                   4UL
#define FLEXRAY_SIES_RXIE_Msk                   0x10UL
#define FLEXRAY_SIES_RFNEE_Pos                  5UL
#define FLEXRAY_SIES_RFNEE_Msk                  0x20UL
#define FLEXRAY_SIES_RFCLE_Pos                  6UL
#define FLEXRAY_SIES_RFCLE_Msk                  0x40UL
#define FLEXRAY_SIES_NMVCE_Pos                  7UL
#define FLEXRAY_SIES_NMVCE_Msk                  0x80UL
#define FLEXRAY_SIES_TI0E_Pos                   8UL
#define FLEXRAY_SIES_TI0E_Msk                   0x100UL
#define FLEXRAY_SIES_TI1E_Pos                   9UL
#define FLEXRAY_SIES_TI1E_Msk                   0x200UL
#define FLEXRAY_SIES_TIBCE_Pos                  10UL
#define FLEXRAY_SIES_TIBCE_Msk                  0x400UL
#define FLEXRAY_SIES_TOBCE_Pos                  11UL
#define FLEXRAY_SIES_TOBCE_Msk                  0x800UL
#define FLEXRAY_SIES_SWEE_Pos                   12UL
#define FLEXRAY_SIES_SWEE_Msk                   0x1000UL
#define FLEXRAY_SIES_SUCSE_Pos                  13UL
#define FLEXRAY_SIES_SUCSE_Msk                  0x2000UL
#define FLEXRAY_SIES_MBSIE_Pos                  14UL
#define FLEXRAY_SIES_MBSIE_Msk                  0x4000UL
#define FLEXRAY_SIES_SDSE_Pos                   15UL
#define FLEXRAY_SIES_SDSE_Msk                   0x8000UL
#define FLEXRAY_SIES_WUPAE_Pos                  16UL
#define FLEXRAY_SIES_WUPAE_Msk                  0x10000UL
#define FLEXRAY_SIES_MTSAE_Pos                  17UL
#define FLEXRAY_SIES_MTSAE_Msk                  0x20000UL
#define FLEXRAY_SIES_WUPBE_Pos                  24UL
#define FLEXRAY_SIES_WUPBE_Msk                  0x1000000UL
#define FLEXRAY_SIES_MTSBE_Pos                  25UL
#define FLEXRAY_SIES_MTSBE_Msk                  0x2000000UL
/* FLEXRAY.SIER */
#define FLEXRAY_SIER_WSTE_Pos                   0UL
#define FLEXRAY_SIER_WSTE_Msk                   0x1UL
#define FLEXRAY_SIER_CASE_Pos                   1UL
#define FLEXRAY_SIER_CASE_Msk                   0x2UL
#define FLEXRAY_SIER_CYCSE_Pos                  2UL
#define FLEXRAY_SIER_CYCSE_Msk                  0x4UL
#define FLEXRAY_SIER_TXIE_Pos                   3UL
#define FLEXRAY_SIER_TXIE_Msk                   0x8UL
#define FLEXRAY_SIER_RXIE_Pos                   4UL
#define FLEXRAY_SIER_RXIE_Msk                   0x10UL
#define FLEXRAY_SIER_RFNEE_Pos                  5UL
#define FLEXRAY_SIER_RFNEE_Msk                  0x20UL
#define FLEXRAY_SIER_RFCLE_Pos                  6UL
#define FLEXRAY_SIER_RFCLE_Msk                  0x40UL
#define FLEXRAY_SIER_NMVCE_Pos                  7UL
#define FLEXRAY_SIER_NMVCE_Msk                  0x80UL
#define FLEXRAY_SIER_TI0E_Pos                   8UL
#define FLEXRAY_SIER_TI0E_Msk                   0x100UL
#define FLEXRAY_SIER_TI1E_Pos                   9UL
#define FLEXRAY_SIER_TI1E_Msk                   0x200UL
#define FLEXRAY_SIER_TIBCE_Pos                  10UL
#define FLEXRAY_SIER_TIBCE_Msk                  0x400UL
#define FLEXRAY_SIER_TOBCE_Pos                  11UL
#define FLEXRAY_SIER_TOBCE_Msk                  0x800UL
#define FLEXRAY_SIER_SWEE_Pos                   12UL
#define FLEXRAY_SIER_SWEE_Msk                   0x1000UL
#define FLEXRAY_SIER_SUCSE_Pos                  13UL
#define FLEXRAY_SIER_SUCSE_Msk                  0x2000UL
#define FLEXRAY_SIER_MBSIE_Pos                  14UL
#define FLEXRAY_SIER_MBSIE_Msk                  0x4000UL
#define FLEXRAY_SIER_SDSE_Pos                   15UL
#define FLEXRAY_SIER_SDSE_Msk                   0x8000UL
#define FLEXRAY_SIER_WUPAE_Pos                  16UL
#define FLEXRAY_SIER_WUPAE_Msk                  0x10000UL
#define FLEXRAY_SIER_MTSAE_Pos                  17UL
#define FLEXRAY_SIER_MTSAE_Msk                  0x20000UL
#define FLEXRAY_SIER_WUPBE_Pos                  24UL
#define FLEXRAY_SIER_WUPBE_Msk                  0x1000000UL
#define FLEXRAY_SIER_MTSBE_Pos                  25UL
#define FLEXRAY_SIER_MTSBE_Msk                  0x2000000UL
/* FLEXRAY.ILE */
#define FLEXRAY_ILE_EINT0__Pos                  0UL
#define FLEXRAY_ILE_EINT0__Msk                  0x1UL
#define FLEXRAY_ILE_EINT1__Pos                  1UL
#define FLEXRAY_ILE_EINT1__Msk                  0x2UL
/* FLEXRAY.T0C */
#define FLEXRAY_T0C_T0RC_Pos                    0UL
#define FLEXRAY_T0C_T0RC_Msk                    0x1UL
#define FLEXRAY_T0C_T0MS_Pos                    1UL
#define FLEXRAY_T0C_T0MS_Msk                    0x2UL
#define FLEXRAY_T0C_T0CC_Pos                    8UL
#define FLEXRAY_T0C_T0CC_Msk                    0x7F00UL
#define FLEXRAY_T0C_T0MO_Pos                    16UL
#define FLEXRAY_T0C_T0MO_Msk                    0x3FFF0000UL
/* FLEXRAY.T1C */
#define FLEXRAY_T1C_T1RC_Pos                    0UL
#define FLEXRAY_T1C_T1RC_Msk                    0x1UL
#define FLEXRAY_T1C_T1MS_Pos                    1UL
#define FLEXRAY_T1C_T1MS_Msk                    0x2UL
#define FLEXRAY_T1C_T1MC_Pos                    16UL
#define FLEXRAY_T1C_T1MC_Msk                    0x3FFF0000UL
/* FLEXRAY.STPW1 */
#define FLEXRAY_STPW1_ESWT_Pos                  0UL
#define FLEXRAY_STPW1_ESWT_Msk                  0x1UL
#define FLEXRAY_STPW1_SWMS_Pos                  1UL
#define FLEXRAY_STPW1_SWMS_Msk                  0x2UL
#define FLEXRAY_STPW1_EDGE_Pos                  2UL
#define FLEXRAY_STPW1_EDGE_Msk                  0x4UL
#define FLEXRAY_STPW1_SSWT_Pos                  3UL
#define FLEXRAY_STPW1_SSWT_Msk                  0x8UL
#define FLEXRAY_STPW1_EETP_Pos                  4UL
#define FLEXRAY_STPW1_EETP_Msk                  0x10UL
#define FLEXRAY_STPW1_EINT0_Pos                 5UL
#define FLEXRAY_STPW1_EINT0_Msk                 0x20UL
#define FLEXRAY_STPW1_EINT1_Pos                 6UL
#define FLEXRAY_STPW1_EINT1_Msk                 0x40UL
#define FLEXRAY_STPW1_SCCV_Pos                  8UL
#define FLEXRAY_STPW1_SCCV_Msk                  0x3F00UL
#define FLEXRAY_STPW1_SMTV_Pos                  16UL
#define FLEXRAY_STPW1_SMTV_Msk                  0x3FFF0000UL
/* FLEXRAY.STPW2 */
#define FLEXRAY_STPW2_SSCVA_Pos                 0UL
#define FLEXRAY_STPW2_SSCVA_Msk                 0x7FFUL
#define FLEXRAY_STPW2_SSCVB_Pos                 16UL
#define FLEXRAY_STPW2_SSCVB_Msk                 0x7FF0000UL
/* FLEXRAY.SUCC1 */
#define FLEXRAY_SUCC1_CMD_Pos                   0UL
#define FLEXRAY_SUCC1_CMD_Msk                   0xFUL
#define FLEXRAY_SUCC1_PBSY_Pos                  7UL
#define FLEXRAY_SUCC1_PBSY_Msk                  0x80UL
#define FLEXRAY_SUCC1_TXST_Pos                  8UL
#define FLEXRAY_SUCC1_TXST_Msk                  0x100UL
#define FLEXRAY_SUCC1_TXSY_Pos                  9UL
#define FLEXRAY_SUCC1_TXSY_Msk                  0x200UL
#define FLEXRAY_SUCC1_CSA_Pos                   11UL
#define FLEXRAY_SUCC1_CSA_Msk                   0xF800UL
#define FLEXRAY_SUCC1_PTA_Pos                   16UL
#define FLEXRAY_SUCC1_PTA_Msk                   0x1F0000UL
#define FLEXRAY_SUCC1_WUCS_Pos                  21UL
#define FLEXRAY_SUCC1_WUCS_Msk                  0x200000UL
#define FLEXRAY_SUCC1_TSM_Pos                   22UL
#define FLEXRAY_SUCC1_TSM_Msk                   0x400000UL
#define FLEXRAY_SUCC1_HCSE_Pos                  23UL
#define FLEXRAY_SUCC1_HCSE_Msk                  0x800000UL
#define FLEXRAY_SUCC1_MTSA__Pos                 24UL
#define FLEXRAY_SUCC1_MTSA__Msk                 0x1000000UL
#define FLEXRAY_SUCC1_MTSB__Pos                 25UL
#define FLEXRAY_SUCC1_MTSB__Msk                 0x2000000UL
#define FLEXRAY_SUCC1_CCHA_Pos                  26UL
#define FLEXRAY_SUCC1_CCHA_Msk                  0x4000000UL
#define FLEXRAY_SUCC1_CCHB_Pos                  27UL
#define FLEXRAY_SUCC1_CCHB_Msk                  0x8000000UL
/* FLEXRAY.SUCC2 */
#define FLEXRAY_SUCC2_LT_Pos                    0UL
#define FLEXRAY_SUCC2_LT_Msk                    0x1FFFFFUL
#define FLEXRAY_SUCC2_LTN_Pos                   24UL
#define FLEXRAY_SUCC2_LTN_Msk                   0xF000000UL
/* FLEXRAY.SUCC3 */
#define FLEXRAY_SUCC3_WCP_Pos                   0UL
#define FLEXRAY_SUCC3_WCP_Msk                   0xFUL
#define FLEXRAY_SUCC3_WCF_Pos                   4UL
#define FLEXRAY_SUCC3_WCF_Msk                   0xF0UL
/* FLEXRAY.NEMC */
#define FLEXRAY_NEMC_NML_Pos                    0UL
#define FLEXRAY_NEMC_NML_Msk                    0xFUL
/* FLEXRAY.PRTC1 */
#define FLEXRAY_PRTC1_TSST_Pos                  0UL
#define FLEXRAY_PRTC1_TSST_Msk                  0xFUL
#define FLEXRAY_PRTC1_CASM_Pos                  4UL
#define FLEXRAY_PRTC1_CASM_Msk                  0x3F0UL
#define FLEXRAY_PRTC1_CASM6_Pos                 10UL
#define FLEXRAY_PRTC1_CASM6_Msk                 0x400UL
#define FLEXRAY_PRTC1_SPP_Pos                   12UL
#define FLEXRAY_PRTC1_SPP_Msk                   0x3000UL
#define FLEXRAY_PRTC1_BRP_Pos                   14UL
#define FLEXRAY_PRTC1_BRP_Msk                   0xC000UL
#define FLEXRAY_PRTC1_RXW_Pos                   16UL
#define FLEXRAY_PRTC1_RXW_Msk                   0x1FF0000UL
#define FLEXRAY_PRTC1_RWP_Pos                   26UL
#define FLEXRAY_PRTC1_RWP_Msk                   0xFC000000UL
/* FLEXRAY.PRTC2 */
#define FLEXRAY_PRTC2_RXI__Pos                  0UL
#define FLEXRAY_PRTC2_RXI__Msk                  0x3FUL
#define FLEXRAY_PRTC2_RXL_Pos                   8UL
#define FLEXRAY_PRTC2_RXL_Msk                   0x3F00UL
#define FLEXRAY_PRTC2_TXI__Pos                  16UL
#define FLEXRAY_PRTC2_TXI__Msk                  0xFF0000UL
#define FLEXRAY_PRTC2_TXL_Pos                   24UL
#define FLEXRAY_PRTC2_TXL_Msk                   0x3F000000UL
/* FLEXRAY.MHDC */
#define FLEXRAY_MHDC_SFDL_Pos                   0UL
#define FLEXRAY_MHDC_SFDL_Msk                   0x7FUL
#define FLEXRAY_MHDC_SLT_Pos                    16UL
#define FLEXRAY_MHDC_SLT_Msk                    0x1FFF0000UL
/* FLEXRAY.GTUC1 */
#define FLEXRAY_GTUC1_UT_Pos                    0UL
#define FLEXRAY_GTUC1_UT_Msk                    0xFFFFFUL
/* FLEXRAY.GTUC2 */
#define FLEXRAY_GTUC2_MPC_Pos                   0UL
#define FLEXRAY_GTUC2_MPC_Msk                   0x3FFFUL
#define FLEXRAY_GTUC2_SNM_Pos                   16UL
#define FLEXRAY_GTUC2_SNM_Msk                   0xF0000UL
/* FLEXRAY.GTUC3 */
#define FLEXRAY_GTUC3_UIOA_Pos                  0UL
#define FLEXRAY_GTUC3_UIOA_Msk                  0xFFUL
#define FLEXRAY_GTUC3_UIOB_Pos                  8UL
#define FLEXRAY_GTUC3_UIOB_Msk                  0xFF00UL
#define FLEXRAY_GTUC3_MIOA_Pos                  16UL
#define FLEXRAY_GTUC3_MIOA_Msk                  0x7F0000UL
#define FLEXRAY_GTUC3_MIOB_Pos                  24UL
#define FLEXRAY_GTUC3_MIOB_Msk                  0x7F000000UL
/* FLEXRAY.GTUC4 */
#define FLEXRAY_GTUC4_NIT_Pos                   0UL
#define FLEXRAY_GTUC4_NIT_Msk                   0x3FFFUL
#define FLEXRAY_GTUC4_OCS_Pos                   16UL
#define FLEXRAY_GTUC4_OCS_Msk                   0x3FFF0000UL
/* FLEXRAY.GTUC5 */
#define FLEXRAY_GTUC5_DCA_Pos                   0UL
#define FLEXRAY_GTUC5_DCA_Msk                   0xFFUL
#define FLEXRAY_GTUC5_DCB_Pos                   8UL
#define FLEXRAY_GTUC5_DCB_Msk                   0xFF00UL
#define FLEXRAY_GTUC5_CDD_Pos                   16UL
#define FLEXRAY_GTUC5_CDD_Msk                   0x1F0000UL
#define FLEXRAY_GTUC5_DEC_Pos                   24UL
#define FLEXRAY_GTUC5_DEC_Msk                   0xFF000000UL
/* FLEXRAY.GTUC6 */
#define FLEXRAY_GTUC6_ASR_Pos                   0UL
#define FLEXRAY_GTUC6_ASR_Msk                   0x7FFUL
#define FLEXRAY_GTUC6_MOD_Pos                   16UL
#define FLEXRAY_GTUC6_MOD_Msk                   0x7FF0000UL
/* FLEXRAY.GTUC7 */
#define FLEXRAY_GTUC7_SSL_Pos                   0UL
#define FLEXRAY_GTUC7_SSL_Msk                   0x3FFUL
#define FLEXRAY_GTUC7_NSS_Pos                   16UL
#define FLEXRAY_GTUC7_NSS_Msk                   0x3FF0000UL
/* FLEXRAY.GTUC8 */
#define FLEXRAY_GTUC8_MSL_Pos                   0UL
#define FLEXRAY_GTUC8_MSL_Msk                   0x3FUL
#define FLEXRAY_GTUC8_NMS_Pos                   16UL
#define FLEXRAY_GTUC8_NMS_Msk                   0x1FFF0000UL
/* FLEXRAY.GTUC9 */
#define FLEXRAY_GTUC9_APO_Pos                   0UL
#define FLEXRAY_GTUC9_APO_Msk                   0x3FUL
#define FLEXRAY_GTUC9_MAPO_Pos                  8UL
#define FLEXRAY_GTUC9_MAPO_Msk                  0x1F00UL
#define FLEXRAY_GTUC9_DSI_Pos                   16UL
#define FLEXRAY_GTUC9_DSI_Msk                   0x30000UL
/* FLEXRAY.GTUC10 */
#define FLEXRAY_GTUC10_MOC_Pos                  0UL
#define FLEXRAY_GTUC10_MOC_Msk                  0x3FFFUL
#define FLEXRAY_GTUC10_MRC_Pos                  16UL
#define FLEXRAY_GTUC10_MRC_Msk                  0x7FF0000UL
/* FLEXRAY.GTUC11 */
#define FLEXRAY_GTUC11_EOCC_Pos                 0UL
#define FLEXRAY_GTUC11_EOCC_Msk                 0x3UL
#define FLEXRAY_GTUC11_ERCC_Pos                 8UL
#define FLEXRAY_GTUC11_ERCC_Msk                 0x300UL
#define FLEXRAY_GTUC11_EOC_Pos                  16UL
#define FLEXRAY_GTUC11_EOC_Msk                  0x70000UL
#define FLEXRAY_GTUC11_ERC_Pos                  24UL
#define FLEXRAY_GTUC11_ERC_Msk                  0x7000000UL
/* FLEXRAY.CCSV */
#define FLEXRAY_CCSV_POCS_Pos                   0UL
#define FLEXRAY_CCSV_POCS_Msk                   0x3FUL
#define FLEXRAY_CCSV_FSI_Pos                    6UL
#define FLEXRAY_CCSV_FSI_Msk                    0x40UL
#define FLEXRAY_CCSV_HRQ_Pos                    7UL
#define FLEXRAY_CCSV_HRQ_Msk                    0x80UL
#define FLEXRAY_CCSV_SLM_Pos                    8UL
#define FLEXRAY_CCSV_SLM_Msk                    0x300UL
#define FLEXRAY_CCSV_CSNI_Pos                   12UL
#define FLEXRAY_CCSV_CSNI_Msk                   0x1000UL
#define FLEXRAY_CCSV_CSAI_Pos                   13UL
#define FLEXRAY_CCSV_CSAI_Msk                   0x2000UL
#define FLEXRAY_CCSV_CSI_Pos                    14UL
#define FLEXRAY_CCSV_CSI_Msk                    0x4000UL
#define FLEXRAY_CCSV_WSV_Pos                    16UL
#define FLEXRAY_CCSV_WSV_Msk                    0x70000UL
#define FLEXRAY_CCSV_RCA_Pos                    19UL
#define FLEXRAY_CCSV_RCA_Msk                    0xF80000UL
#define FLEXRAY_CCSV_PSL_Pos                    24UL
#define FLEXRAY_CCSV_PSL_Msk                    0x3F000000UL
/* FLEXRAY.CCEV */
#define FLEXRAY_CCEV_CCFC_Pos                   0UL
#define FLEXRAY_CCEV_CCFC_Msk                   0xFUL
#define FLEXRAY_CCEV_ERRM_Pos                   6UL
#define FLEXRAY_CCEV_ERRM_Msk                   0xC0UL
#define FLEXRAY_CCEV_PTAC_Pos                   8UL
#define FLEXRAY_CCEV_PTAC_Msk                   0x1F00UL
/* FLEXRAY.SCV */
#define FLEXRAY_SCV_SCCA_Pos                    0UL
#define FLEXRAY_SCV_SCCA_Msk                    0x7FFUL
#define FLEXRAY_SCV_SCCB_Pos                    16UL
#define FLEXRAY_SCV_SCCB_Msk                    0x7FF0000UL
/* FLEXRAY.MTCCV */
#define FLEXRAY_MTCCV_MTV_Pos                   0UL
#define FLEXRAY_MTCCV_MTV_Msk                   0x3FFFUL
#define FLEXRAY_MTCCV_CCV_Pos                   16UL
#define FLEXRAY_MTCCV_CCV_Msk                   0x3F0000UL
/* FLEXRAY.RCV */
#define FLEXRAY_RCV_RCV_Pos                     0UL
#define FLEXRAY_RCV_RCV_Msk                     0xFFFUL
/* FLEXRAY.OCV */
#define FLEXRAY_OCV_OCV_Pos                     0UL
#define FLEXRAY_OCV_OCV_Msk                     0x7FFFFUL
/* FLEXRAY.SFS */
#define FLEXRAY_SFS_VSAE_Pos                    0UL
#define FLEXRAY_SFS_VSAE_Msk                    0xFUL
#define FLEXRAY_SFS_VSAO_Pos                    4UL
#define FLEXRAY_SFS_VSAO_Msk                    0xF0UL
#define FLEXRAY_SFS_VSBE_Pos                    8UL
#define FLEXRAY_SFS_VSBE_Msk                    0xF00UL
#define FLEXRAY_SFS_VSBO_Pos                    12UL
#define FLEXRAY_SFS_VSBO_Msk                    0xF000UL
#define FLEXRAY_SFS_MOCS_Pos                    16UL
#define FLEXRAY_SFS_MOCS_Msk                    0x10000UL
#define FLEXRAY_SFS_OCLR_Pos                    17UL
#define FLEXRAY_SFS_OCLR_Msk                    0x20000UL
#define FLEXRAY_SFS_MRCS_Pos                    18UL
#define FLEXRAY_SFS_MRCS_Msk                    0x40000UL
#define FLEXRAY_SFS_RCLR_Pos                    19UL
#define FLEXRAY_SFS_RCLR_Msk                    0x80000UL
/* FLEXRAY.SWNIT */
#define FLEXRAY_SWNIT_SESA_Pos                  0UL
#define FLEXRAY_SWNIT_SESA_Msk                  0x1UL
#define FLEXRAY_SWNIT_SBSA_Pos                  1UL
#define FLEXRAY_SWNIT_SBSA_Msk                  0x2UL
#define FLEXRAY_SWNIT_TCSA_Pos                  2UL
#define FLEXRAY_SWNIT_TCSA_Msk                  0x4UL
#define FLEXRAY_SWNIT_SESB_Pos                  3UL
#define FLEXRAY_SWNIT_SESB_Msk                  0x8UL
#define FLEXRAY_SWNIT_SBSB_Pos                  4UL
#define FLEXRAY_SWNIT_SBSB_Msk                  0x10UL
#define FLEXRAY_SWNIT_TCSB_Pos                  5UL
#define FLEXRAY_SWNIT_TCSB_Msk                  0x20UL
#define FLEXRAY_SWNIT_MTSA___Pos                6UL
#define FLEXRAY_SWNIT_MTSA___Msk                0x40UL
#define FLEXRAY_SWNIT_MTSB___Pos                7UL
#define FLEXRAY_SWNIT_MTSB___Msk                0x80UL
#define FLEXRAY_SWNIT_SENA_Pos                  8UL
#define FLEXRAY_SWNIT_SENA_Msk                  0x100UL
#define FLEXRAY_SWNIT_SBNA_Pos                  9UL
#define FLEXRAY_SWNIT_SBNA_Msk                  0x200UL
#define FLEXRAY_SWNIT_SENB_Pos                  10UL
#define FLEXRAY_SWNIT_SENB_Msk                  0x400UL
#define FLEXRAY_SWNIT_SBNB_Pos                  11UL
#define FLEXRAY_SWNIT_SBNB_Msk                  0x800UL
/* FLEXRAY.ACS */
#define FLEXRAY_ACS_VFRA__Pos                   0UL
#define FLEXRAY_ACS_VFRA__Msk                   0x1UL
#define FLEXRAY_ACS_SEDA_Pos                    1UL
#define FLEXRAY_ACS_SEDA_Msk                    0x2UL
#define FLEXRAY_ACS_CEDA_Pos                    2UL
#define FLEXRAY_ACS_CEDA_Msk                    0x4UL
#define FLEXRAY_ACS_CIA_Pos                     3UL
#define FLEXRAY_ACS_CIA_Msk                     0x8UL
#define FLEXRAY_ACS_SBVA_Pos                    4UL
#define FLEXRAY_ACS_SBVA_Msk                    0x10UL
#define FLEXRAY_ACS_VFRB__Pos                   8UL
#define FLEXRAY_ACS_VFRB__Msk                   0x100UL
#define FLEXRAY_ACS_SEDB_Pos                    9UL
#define FLEXRAY_ACS_SEDB_Msk                    0x200UL
#define FLEXRAY_ACS_CEDB_Pos                    10UL
#define FLEXRAY_ACS_CEDB_Msk                    0x400UL
#define FLEXRAY_ACS_CIB_Pos                     11UL
#define FLEXRAY_ACS_CIB_Msk                     0x800UL
#define FLEXRAY_ACS_SBVB_Pos                    12UL
#define FLEXRAY_ACS_SBVB_Msk                    0x1000UL
/* FLEXRAY.ESID */
#define FLEXRAY_ESID_EID_Pos                    0UL
#define FLEXRAY_ESID_EID_Msk                    0x3FFUL
#define FLEXRAY_ESID_RXEA_Pos                   14UL
#define FLEXRAY_ESID_RXEA_Msk                   0x4000UL
#define FLEXRAY_ESID_RXEB_Pos                   15UL
#define FLEXRAY_ESID_RXEB_Msk                   0x8000UL
/* FLEXRAY.OSID */
#define FLEXRAY_OSID_OID_Pos                    0UL
#define FLEXRAY_OSID_OID_Msk                    0x3FFUL
#define FLEXRAY_OSID_RXOA_Pos                   14UL
#define FLEXRAY_OSID_RXOA_Msk                   0x4000UL
#define FLEXRAY_OSID_RXOB_Pos                   15UL
#define FLEXRAY_OSID_RXOB_Msk                   0x8000UL
/* FLEXRAY.NMV1 */
#define FLEXRAY_NMV1_DATA0_Pos                  0UL
#define FLEXRAY_NMV1_DATA0_Msk                  0xFFUL
#define FLEXRAY_NMV1_DATA1_Pos                  8UL
#define FLEXRAY_NMV1_DATA1_Msk                  0xFF00UL
#define FLEXRAY_NMV1_DATA2_Pos                  16UL
#define FLEXRAY_NMV1_DATA2_Msk                  0xFF0000UL
#define FLEXRAY_NMV1_DATA3_Pos                  24UL
#define FLEXRAY_NMV1_DATA3_Msk                  0xFF000000UL
/* FLEXRAY.NMV2 */
#define FLEXRAY_NMV2_DATA4_Pos                  0UL
#define FLEXRAY_NMV2_DATA4_Msk                  0xFFUL
#define FLEXRAY_NMV2_DATA5_Pos                  8UL
#define FLEXRAY_NMV2_DATA5_Msk                  0xFF00UL
#define FLEXRAY_NMV2_DATA6_Pos                  16UL
#define FLEXRAY_NMV2_DATA6_Msk                  0xFF0000UL
#define FLEXRAY_NMV2_DATA7_Pos                  24UL
#define FLEXRAY_NMV2_DATA7_Msk                  0xFF000000UL
/* FLEXRAY.NMV3 */
#define FLEXRAY_NMV3_DATA8_Pos                  0UL
#define FLEXRAY_NMV3_DATA8_Msk                  0xFFUL
#define FLEXRAY_NMV3_DATA9_Pos                  8UL
#define FLEXRAY_NMV3_DATA9_Msk                  0xFF00UL
#define FLEXRAY_NMV3_DATA10_Pos                 16UL
#define FLEXRAY_NMV3_DATA10_Msk                 0xFF0000UL
#define FLEXRAY_NMV3_DATA11_Pos                 24UL
#define FLEXRAY_NMV3_DATA11_Msk                 0xFF000000UL
/* FLEXRAY.MRC */
#define FLEXRAY_MRC_FDB_Pos                     0UL
#define FLEXRAY_MRC_FDB_Msk                     0xFFUL
#define FLEXRAY_MRC_FFB_Pos                     8UL
#define FLEXRAY_MRC_FFB_Msk                     0xFF00UL
#define FLEXRAY_MRC_LCB_Pos                     16UL
#define FLEXRAY_MRC_LCB_Msk                     0xFF0000UL
#define FLEXRAY_MRC_SEC_Pos                     24UL
#define FLEXRAY_MRC_SEC_Msk                     0x3000000UL
#define FLEXRAY_MRC_SPLM_Pos                    26UL
#define FLEXRAY_MRC_SPLM_Msk                    0x4000000UL
/* FLEXRAY.FRF */
#define FLEXRAY_FRF_CH_Pos                      0UL
#define FLEXRAY_FRF_CH_Msk                      0x3UL
#define FLEXRAY_FRF_FID__Pos                    2UL
#define FLEXRAY_FRF_FID__Msk                    0x1FFCUL
#define FLEXRAY_FRF_CYF_Pos                     16UL
#define FLEXRAY_FRF_CYF_Msk                     0x7F0000UL
#define FLEXRAY_FRF_RSS_Pos                     23UL
#define FLEXRAY_FRF_RSS_Msk                     0x800000UL
#define FLEXRAY_FRF_RNF_Pos                     24UL
#define FLEXRAY_FRF_RNF_Msk                     0x1000000UL
/* FLEXRAY.FRFM */
#define FLEXRAY_FRFM_MFID_Pos                   2UL
#define FLEXRAY_FRFM_MFID_Msk                   0x1FFCUL
/* FLEXRAY.FCL */
#define FLEXRAY_FCL_CL_Pos                      0UL
#define FLEXRAY_FCL_CL_Msk                      0xFFUL
/* FLEXRAY.MHDS */
#define FLEXRAY_MHDS_PIBF_Pos                   0UL
#define FLEXRAY_MHDS_PIBF_Msk                   0x1UL
#define FLEXRAY_MHDS_POBF_Pos                   1UL
#define FLEXRAY_MHDS_POBF_Msk                   0x2UL
#define FLEXRAY_MHDS_PMR_Pos                    2UL
#define FLEXRAY_MHDS_PMR_Msk                    0x4UL
#define FLEXRAY_MHDS_PTBF1_Pos                  3UL
#define FLEXRAY_MHDS_PTBF1_Msk                  0x8UL
#define FLEXRAY_MHDS_PTBF2_Pos                  4UL
#define FLEXRAY_MHDS_PTBF2_Msk                  0x10UL
#define FLEXRAY_MHDS_FMBD_Pos                   5UL
#define FLEXRAY_MHDS_FMBD_Msk                   0x20UL
#define FLEXRAY_MHDS_MFMB_Pos                   6UL
#define FLEXRAY_MHDS_MFMB_Msk                   0x40UL
#define FLEXRAY_MHDS_CRAM_Pos                   7UL
#define FLEXRAY_MHDS_CRAM_Msk                   0x80UL
#define FLEXRAY_MHDS_FMB_Pos                    8UL
#define FLEXRAY_MHDS_FMB_Msk                    0x7F00UL
#define FLEXRAY_MHDS_MBT_Pos                    16UL
#define FLEXRAY_MHDS_MBT_Msk                    0x7F0000UL
#define FLEXRAY_MHDS_MBU_Pos                    24UL
#define FLEXRAY_MHDS_MBU_Msk                    0x7F000000UL
/* FLEXRAY.LDTS */
#define FLEXRAY_LDTS_LDTA_Pos                   0UL
#define FLEXRAY_LDTS_LDTA_Msk                   0x7FFUL
#define FLEXRAY_LDTS_LDTB_Pos                   16UL
#define FLEXRAY_LDTS_LDTB_Msk                   0x7FF0000UL
/* FLEXRAY.FSR */
#define FLEXRAY_FSR_RFNE__Pos                   0UL
#define FLEXRAY_FSR_RFNE__Msk                   0x1UL
#define FLEXRAY_FSR_RFCL__Pos                   1UL
#define FLEXRAY_FSR_RFCL__Msk                   0x2UL
#define FLEXRAY_FSR_RFO__Pos                    2UL
#define FLEXRAY_FSR_RFO__Msk                    0x4UL
#define FLEXRAY_FSR_RFFL_Pos                    8UL
#define FLEXRAY_FSR_RFFL_Msk                    0xFF00UL
/* FLEXRAY.MHDF */
#define FLEXRAY_MHDF_SNUA_Pos                   0UL
#define FLEXRAY_MHDF_SNUA_Msk                   0x1UL
#define FLEXRAY_MHDF_SNUB_Pos                   1UL
#define FLEXRAY_MHDF_SNUB_Msk                   0x2UL
#define FLEXRAY_MHDF_FNFA_Pos                   2UL
#define FLEXRAY_MHDF_FNFA_Msk                   0x4UL
#define FLEXRAY_MHDF_FNFB_Pos                   3UL
#define FLEXRAY_MHDF_FNFB_Msk                   0x8UL
#define FLEXRAY_MHDF_TBFA_Pos                   4UL
#define FLEXRAY_MHDF_TBFA_Msk                   0x10UL
#define FLEXRAY_MHDF_TBFB_Pos                   5UL
#define FLEXRAY_MHDF_TBFB_Msk                   0x20UL
#define FLEXRAY_MHDF_TNSA_Pos                   6UL
#define FLEXRAY_MHDF_TNSA_Msk                   0x40UL
#define FLEXRAY_MHDF_TNSB_Pos                   7UL
#define FLEXRAY_MHDF_TNSB_Msk                   0x80UL
#define FLEXRAY_MHDF_WAHP_Pos                   8UL
#define FLEXRAY_MHDF_WAHP_Msk                   0x100UL
/* FLEXRAY.TXRQ1 */
#define FLEXRAY_TXRQ1_TXR_Pos                   0UL
#define FLEXRAY_TXRQ1_TXR_Msk                   0xFFFFFFFFUL
/* FLEXRAY.TXRQ2 */
#define FLEXRAY_TXRQ2_TXR_Pos                   0UL
#define FLEXRAY_TXRQ2_TXR_Msk                   0xFFFFFFFFUL
/* FLEXRAY.TXRQ3 */
#define FLEXRAY_TXRQ3_TXR_Pos                   0UL
#define FLEXRAY_TXRQ3_TXR_Msk                   0xFFFFFFFFUL
/* FLEXRAY.TXRQ4 */
#define FLEXRAY_TXRQ4_TXR_Pos                   0UL
#define FLEXRAY_TXRQ4_TXR_Msk                   0xFFFFFFFFUL
/* FLEXRAY.NDAT1 */
#define FLEXRAY_NDAT1_ND_Pos                    0UL
#define FLEXRAY_NDAT1_ND_Msk                    0xFFFFFFFFUL
/* FLEXRAY.NDAT2 */
#define FLEXRAY_NDAT2_ND_Pos                    0UL
#define FLEXRAY_NDAT2_ND_Msk                    0xFFFFFFFFUL
/* FLEXRAY.NDAT3 */
#define FLEXRAY_NDAT3_ND_Pos                    0UL
#define FLEXRAY_NDAT3_ND_Msk                    0xFFFFFFFFUL
/* FLEXRAY.NDAT4 */
#define FLEXRAY_NDAT4_ND_Pos                    0UL
#define FLEXRAY_NDAT4_ND_Msk                    0xFFFFFFFFUL
/* FLEXRAY.MBSC1 */
#define FLEXRAY_MBSC1_MBC_Pos                   0UL
#define FLEXRAY_MBSC1_MBC_Msk                   0xFFFFFFFFUL
/* FLEXRAY.MBSC2 */
#define FLEXRAY_MBSC2_MBC_Pos                   0UL
#define FLEXRAY_MBSC2_MBC_Msk                   0xFFFFFFFFUL
/* FLEXRAY.MBSC3 */
#define FLEXRAY_MBSC3_MBC_Pos                   0UL
#define FLEXRAY_MBSC3_MBC_Msk                   0xFFFFFFFFUL
/* FLEXRAY.MBSC4 */
#define FLEXRAY_MBSC4_MBC_Pos                   0UL
#define FLEXRAY_MBSC4_MBC_Msk                   0xFFFFFFFFUL
/* FLEXRAY.CREL */
#define FLEXRAY_CREL_DAY_Pos                    0UL
#define FLEXRAY_CREL_DAY_Msk                    0xFFUL
#define FLEXRAY_CREL_MON_Pos                    8UL
#define FLEXRAY_CREL_MON_Msk                    0xFF00UL
#define FLEXRAY_CREL_YEAR_Pos                   16UL
#define FLEXRAY_CREL_YEAR_Msk                   0xF0000UL
#define FLEXRAY_CREL_STEP_Pos                   20UL
#define FLEXRAY_CREL_STEP_Msk                   0xFF00000UL
#define FLEXRAY_CREL_REL_Pos                    28UL
#define FLEXRAY_CREL_REL_Msk                    0xF0000000UL
/* FLEXRAY.ENDN */
#define FLEXRAY_ENDN_ETV_Pos                    0UL
#define FLEXRAY_ENDN_ETV_Msk                    0xFFFFFFFFUL
/* FLEXRAY.WRDS */
#define FLEXRAY_WRDS_MD_Pos                     0UL
#define FLEXRAY_WRDS_MD_Msk                     0xFFFFFFFFUL
/* FLEXRAY.WRHS1 */
#define FLEXRAY_WRHS1_FID_Pos                   0UL
#define FLEXRAY_WRHS1_FID_Msk                   0x7FFUL
#define FLEXRAY_WRHS1_CYC_Pos                   16UL
#define FLEXRAY_WRHS1_CYC_Msk                   0x7F0000UL
#define FLEXRAY_WRHS1_CHA_Pos                   24UL
#define FLEXRAY_WRHS1_CHA_Msk                   0x1000000UL
#define FLEXRAY_WRHS1_CHB_Pos                   25UL
#define FLEXRAY_WRHS1_CHB_Msk                   0x2000000UL
#define FLEXRAY_WRHS1_CFG_Pos                   26UL
#define FLEXRAY_WRHS1_CFG_Msk                   0x4000000UL
#define FLEXRAY_WRHS1_PPIT_Pos                  27UL
#define FLEXRAY_WRHS1_PPIT_Msk                  0x8000000UL
#define FLEXRAY_WRHS1_TXM_Pos                   28UL
#define FLEXRAY_WRHS1_TXM_Msk                   0x10000000UL
#define FLEXRAY_WRHS1_MBI_Pos                   29UL
#define FLEXRAY_WRHS1_MBI_Msk                   0x20000000UL
/* FLEXRAY.WRHS2 */
#define FLEXRAY_WRHS2_CRC_Pos                   0UL
#define FLEXRAY_WRHS2_CRC_Msk                   0x7FFUL
#define FLEXRAY_WRHS2_PLC_Pos                   16UL
#define FLEXRAY_WRHS2_PLC_Msk                   0x7F0000UL
/* FLEXRAY.WRHS3 */
#define FLEXRAY_WRHS3_DP_Pos                    0UL
#define FLEXRAY_WRHS3_DP_Msk                    0x7FFUL
/* FLEXRAY.IBCM */
#define FLEXRAY_IBCM_LHSH_Pos                   0UL
#define FLEXRAY_IBCM_LHSH_Msk                   0x1UL
#define FLEXRAY_IBCM_LDSH_Pos                   1UL
#define FLEXRAY_IBCM_LDSH_Msk                   0x2UL
#define FLEXRAY_IBCM_STXRH_Pos                  2UL
#define FLEXRAY_IBCM_STXRH_Msk                  0x4UL
#define FLEXRAY_IBCM_LHSS_Pos                   16UL
#define FLEXRAY_IBCM_LHSS_Msk                   0x10000UL
#define FLEXRAY_IBCM_LDSS_Pos                   17UL
#define FLEXRAY_IBCM_LDSS_Msk                   0x20000UL
#define FLEXRAY_IBCM_STXRS_Pos                  18UL
#define FLEXRAY_IBCM_STXRS_Msk                  0x40000UL
/* FLEXRAY.IBCR */
#define FLEXRAY_IBCR_IBRH_Pos                   0UL
#define FLEXRAY_IBCR_IBRH_Msk                   0x7FUL
#define FLEXRAY_IBCR_IBSYH_Pos                  15UL
#define FLEXRAY_IBCR_IBSYH_Msk                  0x8000UL
#define FLEXRAY_IBCR_IBRS_Pos                   16UL
#define FLEXRAY_IBCR_IBRS_Msk                   0x7F0000UL
#define FLEXRAY_IBCR_IBSYS_Pos                  31UL
#define FLEXRAY_IBCR_IBSYS_Msk                  0x80000000UL
/* FLEXRAY.RDDS */
#define FLEXRAY_RDDS_MD_Pos                     0UL
#define FLEXRAY_RDDS_MD_Msk                     0xFFFFFFFFUL
/* FLEXRAY.RDHS1 */
#define FLEXRAY_RDHS1_FID_Pos                   0UL
#define FLEXRAY_RDHS1_FID_Msk                   0x7FFUL
#define FLEXRAY_RDHS1_CYC_Pos                   16UL
#define FLEXRAY_RDHS1_CYC_Msk                   0x7F0000UL
#define FLEXRAY_RDHS1_CHA_Pos                   24UL
#define FLEXRAY_RDHS1_CHA_Msk                   0x1000000UL
#define FLEXRAY_RDHS1_CHB_Pos                   25UL
#define FLEXRAY_RDHS1_CHB_Msk                   0x2000000UL
#define FLEXRAY_RDHS1_CFG_Pos                   26UL
#define FLEXRAY_RDHS1_CFG_Msk                   0x4000000UL
#define FLEXRAY_RDHS1_PPIT_Pos                  27UL
#define FLEXRAY_RDHS1_PPIT_Msk                  0x8000000UL
#define FLEXRAY_RDHS1_TXM_Pos                   28UL
#define FLEXRAY_RDHS1_TXM_Msk                   0x10000000UL
#define FLEXRAY_RDHS1_MBI_Pos                   29UL
#define FLEXRAY_RDHS1_MBI_Msk                   0x20000000UL
/* FLEXRAY.RDHS2 */
#define FLEXRAY_RDHS2_CRC_Pos                   0UL
#define FLEXRAY_RDHS2_CRC_Msk                   0x7FFUL
#define FLEXRAY_RDHS2_PLC_Pos                   16UL
#define FLEXRAY_RDHS2_PLC_Msk                   0x7F0000UL
#define FLEXRAY_RDHS2_PLR_Pos                   24UL
#define FLEXRAY_RDHS2_PLR_Msk                   0x7F000000UL
/* FLEXRAY.RDHS3 */
#define FLEXRAY_RDHS3_DP_Pos                    0UL
#define FLEXRAY_RDHS3_DP_Msk                    0x7FFUL
#define FLEXRAY_RDHS3_RCC_Pos                   16UL
#define FLEXRAY_RDHS3_RCC_Msk                   0x3F0000UL
#define FLEXRAY_RDHS3_RCI_Pos                   24UL
#define FLEXRAY_RDHS3_RCI_Msk                   0x1000000UL
#define FLEXRAY_RDHS3_SFI_Pos                   25UL
#define FLEXRAY_RDHS3_SFI_Msk                   0x2000000UL
#define FLEXRAY_RDHS3_SYN_Pos                   26UL
#define FLEXRAY_RDHS3_SYN_Msk                   0x4000000UL
#define FLEXRAY_RDHS3_NFI_Pos                   27UL
#define FLEXRAY_RDHS3_NFI_Msk                   0x8000000UL
#define FLEXRAY_RDHS3_PPI_Pos                   28UL
#define FLEXRAY_RDHS3_PPI_Msk                   0x10000000UL
#define FLEXRAY_RDHS3_RES_Pos                   29UL
#define FLEXRAY_RDHS3_RES_Msk                   0x20000000UL
/* FLEXRAY.MBS */
#define FLEXRAY_MBS_VFRA_Pos                    0UL
#define FLEXRAY_MBS_VFRA_Msk                    0x1UL
#define FLEXRAY_MBS_VFRB_Pos                    1UL
#define FLEXRAY_MBS_VFRB_Msk                    0x2UL
#define FLEXRAY_MBS_SEOA_Pos                    2UL
#define FLEXRAY_MBS_SEOA_Msk                    0x4UL
#define FLEXRAY_MBS_SEOB_Pos                    3UL
#define FLEXRAY_MBS_SEOB_Msk                    0x8UL
#define FLEXRAY_MBS_CEOA_Pos                    4UL
#define FLEXRAY_MBS_CEOA_Msk                    0x10UL
#define FLEXRAY_MBS_CEOB_Pos                    5UL
#define FLEXRAY_MBS_CEOB_Msk                    0x20UL
#define FLEXRAY_MBS_SVOA_Pos                    6UL
#define FLEXRAY_MBS_SVOA_Msk                    0x40UL
#define FLEXRAY_MBS_SVOB_Pos                    7UL
#define FLEXRAY_MBS_SVOB_Msk                    0x80UL
#define FLEXRAY_MBS_TCIA_Pos                    8UL
#define FLEXRAY_MBS_TCIA_Msk                    0x100UL
#define FLEXRAY_MBS_TCIB_Pos                    9UL
#define FLEXRAY_MBS_TCIB_Msk                    0x200UL
#define FLEXRAY_MBS_ESA_Pos                     10UL
#define FLEXRAY_MBS_ESA_Msk                     0x400UL
#define FLEXRAY_MBS_ESB_Pos                     11UL
#define FLEXRAY_MBS_ESB_Msk                     0x800UL
#define FLEXRAY_MBS_MLST_Pos                    12UL
#define FLEXRAY_MBS_MLST_Msk                    0x1000UL
#define FLEXRAY_MBS_FTA_Pos                     14UL
#define FLEXRAY_MBS_FTA_Msk                     0x4000UL
#define FLEXRAY_MBS_FTB_Pos                     15UL
#define FLEXRAY_MBS_FTB_Msk                     0x8000UL
#define FLEXRAY_MBS_CCS_Pos                     16UL
#define FLEXRAY_MBS_CCS_Msk                     0x3F0000UL
#define FLEXRAY_MBS_RCIS_Pos                    24UL
#define FLEXRAY_MBS_RCIS_Msk                    0x1000000UL
#define FLEXRAY_MBS_SFIS_Pos                    25UL
#define FLEXRAY_MBS_SFIS_Msk                    0x2000000UL
#define FLEXRAY_MBS_SYNS_Pos                    26UL
#define FLEXRAY_MBS_SYNS_Msk                    0x4000000UL
#define FLEXRAY_MBS_NFIS_Pos                    27UL
#define FLEXRAY_MBS_NFIS_Msk                    0x8000000UL
#define FLEXRAY_MBS_PPIS_Pos                    28UL
#define FLEXRAY_MBS_PPIS_Msk                    0x10000000UL
#define FLEXRAY_MBS_RESS_Pos                    29UL
#define FLEXRAY_MBS_RESS_Msk                    0x20000000UL
/* FLEXRAY.OBCM */
#define FLEXRAY_OBCM_RHSS_Pos                   0UL
#define FLEXRAY_OBCM_RHSS_Msk                   0x1UL
#define FLEXRAY_OBCM_RDSS_Pos                   1UL
#define FLEXRAY_OBCM_RDSS_Msk                   0x2UL
#define FLEXRAY_OBCM_RHSH_Pos                   16UL
#define FLEXRAY_OBCM_RHSH_Msk                   0x10000UL
#define FLEXRAY_OBCM_RDSH_Pos                   17UL
#define FLEXRAY_OBCM_RDSH_Msk                   0x20000UL
/* FLEXRAY.OBCR */
#define FLEXRAY_OBCR_OBRS_Pos                   0UL
#define FLEXRAY_OBCR_OBRS_Msk                   0x7FUL
#define FLEXRAY_OBCR_VIEW_Pos                   8UL
#define FLEXRAY_OBCR_VIEW_Msk                   0x100UL
#define FLEXRAY_OBCR_REQ_Pos                    9UL
#define FLEXRAY_OBCR_REQ_Msk                    0x200UL
#define FLEXRAY_OBCR_OBSYS_Pos                  15UL
#define FLEXRAY_OBCR_OBSYS_Msk                  0x8000UL
#define FLEXRAY_OBCR_OBRH_Pos                   16UL
#define FLEXRAY_OBCR_OBRH_Msk                   0x7F0000UL
/* FLEXRAY.WRHS1_MIR2 */
#define FLEXRAY_WRHS1_MIR2_FID_Pos              0UL
#define FLEXRAY_WRHS1_MIR2_FID_Msk              0x7FFUL
#define FLEXRAY_WRHS1_MIR2_CYC_Pos              16UL
#define FLEXRAY_WRHS1_MIR2_CYC_Msk              0x7F0000UL
#define FLEXRAY_WRHS1_MIR2_CHA_Pos              24UL
#define FLEXRAY_WRHS1_MIR2_CHA_Msk              0x1000000UL
#define FLEXRAY_WRHS1_MIR2_CHB_Pos              25UL
#define FLEXRAY_WRHS1_MIR2_CHB_Msk              0x2000000UL
#define FLEXRAY_WRHS1_MIR2_CFG_Pos              26UL
#define FLEXRAY_WRHS1_MIR2_CFG_Msk              0x4000000UL
#define FLEXRAY_WRHS1_MIR2_PPIT_Pos             27UL
#define FLEXRAY_WRHS1_MIR2_PPIT_Msk             0x8000000UL
#define FLEXRAY_WRHS1_MIR2_TXM_Pos              28UL
#define FLEXRAY_WRHS1_MIR2_TXM_Msk              0x10000000UL
#define FLEXRAY_WRHS1_MIR2_MBI_Pos              29UL
#define FLEXRAY_WRHS1_MIR2_MBI_Msk              0x20000000UL
/* FLEXRAY.WRHS2_MIR2 */
#define FLEXRAY_WRHS2_MIR2_CRC_Pos              0UL
#define FLEXRAY_WRHS2_MIR2_CRC_Msk              0x7FFUL
#define FLEXRAY_WRHS2_MIR2_PLC_Pos              16UL
#define FLEXRAY_WRHS2_MIR2_PLC_Msk              0x7F0000UL
/* FLEXRAY.WRHS3_MIR2 */
#define FLEXRAY_WRHS3_MIR2_DP_Pos               0UL
#define FLEXRAY_WRHS3_MIR2_DP_Msk               0x7FFUL
/* FLEXRAY.WRDS_MIR */
#define FLEXRAY_WRDS_MIR_MD_Pos                 0UL
#define FLEXRAY_WRDS_MIR_MD_Msk                 0xFFFFFFFFUL
/* FLEXRAY.WRHS1_MIR */
#define FLEXRAY_WRHS1_MIR_FID_Pos               0UL
#define FLEXRAY_WRHS1_MIR_FID_Msk               0x7FFUL
#define FLEXRAY_WRHS1_MIR_CYC_Pos               16UL
#define FLEXRAY_WRHS1_MIR_CYC_Msk               0x7F0000UL
#define FLEXRAY_WRHS1_MIR_CHA_Pos               24UL
#define FLEXRAY_WRHS1_MIR_CHA_Msk               0x1000000UL
#define FLEXRAY_WRHS1_MIR_CHB_Pos               25UL
#define FLEXRAY_WRHS1_MIR_CHB_Msk               0x2000000UL
#define FLEXRAY_WRHS1_MIR_CFG_Pos               26UL
#define FLEXRAY_WRHS1_MIR_CFG_Msk               0x4000000UL
#define FLEXRAY_WRHS1_MIR_PPIT_Pos              27UL
#define FLEXRAY_WRHS1_MIR_PPIT_Msk              0x8000000UL
#define FLEXRAY_WRHS1_MIR_TXM_Pos               28UL
#define FLEXRAY_WRHS1_MIR_TXM_Msk               0x10000000UL
#define FLEXRAY_WRHS1_MIR_MBI_Pos               29UL
#define FLEXRAY_WRHS1_MIR_MBI_Msk               0x20000000UL
/* FLEXRAY.WRHS2_MIR */
#define FLEXRAY_WRHS2_MIR_CRC_Pos               0UL
#define FLEXRAY_WRHS2_MIR_CRC_Msk               0x7FFUL
#define FLEXRAY_WRHS2_MIR_PLC_Pos               16UL
#define FLEXRAY_WRHS2_MIR_PLC_Msk               0x7F0000UL
/* FLEXRAY.WRHS3_MIR */
#define FLEXRAY_WRHS3_MIR_DP_Pos                0UL
#define FLEXRAY_WRHS3_MIR_DP_Msk                0x7FFUL
/* FLEXRAY.IBCM_MIR */
#define FLEXRAY_IBCM_MIR_LHSH_Pos               0UL
#define FLEXRAY_IBCM_MIR_LHSH_Msk               0x1UL
#define FLEXRAY_IBCM_MIR_LDSH_Pos               1UL
#define FLEXRAY_IBCM_MIR_LDSH_Msk               0x2UL
#define FLEXRAY_IBCM_MIR_STXRH_Pos              2UL
#define FLEXRAY_IBCM_MIR_STXRH_Msk              0x4UL
#define FLEXRAY_IBCM_MIR_LHSS_Pos               16UL
#define FLEXRAY_IBCM_MIR_LHSS_Msk               0x10000UL
#define FLEXRAY_IBCM_MIR_LDSS_Pos               17UL
#define FLEXRAY_IBCM_MIR_LDSS_Msk               0x20000UL
#define FLEXRAY_IBCM_MIR_STXRS_Pos              18UL
#define FLEXRAY_IBCM_MIR_STXRS_Msk              0x40000UL
/* FLEXRAY.IBCR_MIR */
#define FLEXRAY_IBCR_MIR_IBRH_Pos               0UL
#define FLEXRAY_IBCR_MIR_IBRH_Msk               0x7FUL
#define FLEXRAY_IBCR_MIR_IBSYH_Pos              15UL
#define FLEXRAY_IBCR_MIR_IBSYH_Msk              0x8000UL
#define FLEXRAY_IBCR_MIR_IBRS_Pos               16UL
#define FLEXRAY_IBCR_MIR_IBRS_Msk               0x7F0000UL
#define FLEXRAY_IBCR_MIR_IBSYS_Pos              31UL
#define FLEXRAY_IBCR_MIR_IBSYS_Msk              0x80000000UL
/* FLEXRAY.RDHS1_MIR2 */
#define FLEXRAY_RDHS1_MIR2_FID_Pos              0UL
#define FLEXRAY_RDHS1_MIR2_FID_Msk              0x7FFUL
#define FLEXRAY_RDHS1_MIR2_CYC_Pos              16UL
#define FLEXRAY_RDHS1_MIR2_CYC_Msk              0x7F0000UL
#define FLEXRAY_RDHS1_MIR2_CHA_Pos              24UL
#define FLEXRAY_RDHS1_MIR2_CHA_Msk              0x1000000UL
#define FLEXRAY_RDHS1_MIR2_CHB_Pos              25UL
#define FLEXRAY_RDHS1_MIR2_CHB_Msk              0x2000000UL
#define FLEXRAY_RDHS1_MIR2_CFG_Pos              26UL
#define FLEXRAY_RDHS1_MIR2_CFG_Msk              0x4000000UL
#define FLEXRAY_RDHS1_MIR2_PPIT_Pos             27UL
#define FLEXRAY_RDHS1_MIR2_PPIT_Msk             0x8000000UL
#define FLEXRAY_RDHS1_MIR2_TXM_Pos              28UL
#define FLEXRAY_RDHS1_MIR2_TXM_Msk              0x10000000UL
#define FLEXRAY_RDHS1_MIR2_MBI_Pos              29UL
#define FLEXRAY_RDHS1_MIR2_MBI_Msk              0x20000000UL
/* FLEXRAY.RDHS2_MIR2 */
#define FLEXRAY_RDHS2_MIR2_CRC_Pos              0UL
#define FLEXRAY_RDHS2_MIR2_CRC_Msk              0x7FFUL
#define FLEXRAY_RDHS2_MIR2_PLC_Pos              16UL
#define FLEXRAY_RDHS2_MIR2_PLC_Msk              0x7F0000UL
#define FLEXRAY_RDHS2_MIR2_PLR_Pos              24UL
#define FLEXRAY_RDHS2_MIR2_PLR_Msk              0x7F000000UL
/* FLEXRAY.RDHS3_MIR2 */
#define FLEXRAY_RDHS3_MIR2_DP_Pos               0UL
#define FLEXRAY_RDHS3_MIR2_DP_Msk               0x7FFUL
#define FLEXRAY_RDHS3_MIR2_RCC_Pos              16UL
#define FLEXRAY_RDHS3_MIR2_RCC_Msk              0x3F0000UL
#define FLEXRAY_RDHS3_MIR2_RCI_Pos              24UL
#define FLEXRAY_RDHS3_MIR2_RCI_Msk              0x1000000UL
#define FLEXRAY_RDHS3_MIR2_SFI_Pos              25UL
#define FLEXRAY_RDHS3_MIR2_SFI_Msk              0x2000000UL
#define FLEXRAY_RDHS3_MIR2_SYN_Pos              26UL
#define FLEXRAY_RDHS3_MIR2_SYN_Msk              0x4000000UL
#define FLEXRAY_RDHS3_MIR2_NFI_Pos              27UL
#define FLEXRAY_RDHS3_MIR2_NFI_Msk              0x8000000UL
#define FLEXRAY_RDHS3_MIR2_PPI_Pos              28UL
#define FLEXRAY_RDHS3_MIR2_PPI_Msk              0x10000000UL
#define FLEXRAY_RDHS3_MIR2_RES_Pos              29UL
#define FLEXRAY_RDHS3_MIR2_RES_Msk              0x20000000UL
/* FLEXRAY.MBS_MIR2 */
#define FLEXRAY_MBS_MIR2_VFRA_Pos               0UL
#define FLEXRAY_MBS_MIR2_VFRA_Msk               0x1UL
#define FLEXRAY_MBS_MIR2_VFRB_Pos               1UL
#define FLEXRAY_MBS_MIR2_VFRB_Msk               0x2UL
#define FLEXRAY_MBS_MIR2_SEOA_Pos               2UL
#define FLEXRAY_MBS_MIR2_SEOA_Msk               0x4UL
#define FLEXRAY_MBS_MIR2_SEOB_Pos               3UL
#define FLEXRAY_MBS_MIR2_SEOB_Msk               0x8UL
#define FLEXRAY_MBS_MIR2_CEOA_Pos               4UL
#define FLEXRAY_MBS_MIR2_CEOA_Msk               0x10UL
#define FLEXRAY_MBS_MIR2_CEOB_Pos               5UL
#define FLEXRAY_MBS_MIR2_CEOB_Msk               0x20UL
#define FLEXRAY_MBS_MIR2_SVOA_Pos               6UL
#define FLEXRAY_MBS_MIR2_SVOA_Msk               0x40UL
#define FLEXRAY_MBS_MIR2_SVOB_Pos               7UL
#define FLEXRAY_MBS_MIR2_SVOB_Msk               0x80UL
#define FLEXRAY_MBS_MIR2_TCIA_Pos               8UL
#define FLEXRAY_MBS_MIR2_TCIA_Msk               0x100UL
#define FLEXRAY_MBS_MIR2_TCIB_Pos               9UL
#define FLEXRAY_MBS_MIR2_TCIB_Msk               0x200UL
#define FLEXRAY_MBS_MIR2_ESA_Pos                10UL
#define FLEXRAY_MBS_MIR2_ESA_Msk                0x400UL
#define FLEXRAY_MBS_MIR2_ESB_Pos                11UL
#define FLEXRAY_MBS_MIR2_ESB_Msk                0x800UL
#define FLEXRAY_MBS_MIR2_MLST_Pos               12UL
#define FLEXRAY_MBS_MIR2_MLST_Msk               0x1000UL
#define FLEXRAY_MBS_MIR2_FTA_Pos                14UL
#define FLEXRAY_MBS_MIR2_FTA_Msk                0x4000UL
#define FLEXRAY_MBS_MIR2_FTB_Pos                15UL
#define FLEXRAY_MBS_MIR2_FTB_Msk                0x8000UL
#define FLEXRAY_MBS_MIR2_CCS_Pos                16UL
#define FLEXRAY_MBS_MIR2_CCS_Msk                0x3F0000UL
#define FLEXRAY_MBS_MIR2_RCIS_Pos               24UL
#define FLEXRAY_MBS_MIR2_RCIS_Msk               0x1000000UL
#define FLEXRAY_MBS_MIR2_SFIS_Pos               25UL
#define FLEXRAY_MBS_MIR2_SFIS_Msk               0x2000000UL
#define FLEXRAY_MBS_MIR2_SYNS_Pos               26UL
#define FLEXRAY_MBS_MIR2_SYNS_Msk               0x4000000UL
#define FLEXRAY_MBS_MIR2_NFIS_Pos               27UL
#define FLEXRAY_MBS_MIR2_NFIS_Msk               0x8000000UL
#define FLEXRAY_MBS_MIR2_PPIS_Pos               28UL
#define FLEXRAY_MBS_MIR2_PPIS_Msk               0x10000000UL
#define FLEXRAY_MBS_MIR2_RESS_Pos               29UL
#define FLEXRAY_MBS_MIR2_RESS_Msk               0x20000000UL
/* FLEXRAY.RDDS_MIR */
#define FLEXRAY_RDDS_MIR_MD_Pos                 0UL
#define FLEXRAY_RDDS_MIR_MD_Msk                 0xFFFFFFFFUL
/* FLEXRAY.RDHS1_MIR */
#define FLEXRAY_RDHS1_MIR_FID_Pos               0UL
#define FLEXRAY_RDHS1_MIR_FID_Msk               0x7FFUL
#define FLEXRAY_RDHS1_MIR_CYC_Pos               16UL
#define FLEXRAY_RDHS1_MIR_CYC_Msk               0x7F0000UL
#define FLEXRAY_RDHS1_MIR_CHA_Pos               24UL
#define FLEXRAY_RDHS1_MIR_CHA_Msk               0x1000000UL
#define FLEXRAY_RDHS1_MIR_CHB_Pos               25UL
#define FLEXRAY_RDHS1_MIR_CHB_Msk               0x2000000UL
#define FLEXRAY_RDHS1_MIR_CFG_Pos               26UL
#define FLEXRAY_RDHS1_MIR_CFG_Msk               0x4000000UL
#define FLEXRAY_RDHS1_MIR_PPIT_Pos              27UL
#define FLEXRAY_RDHS1_MIR_PPIT_Msk              0x8000000UL
#define FLEXRAY_RDHS1_MIR_TXM_Pos               28UL
#define FLEXRAY_RDHS1_MIR_TXM_Msk               0x10000000UL
#define FLEXRAY_RDHS1_MIR_MBI_Pos               29UL
#define FLEXRAY_RDHS1_MIR_MBI_Msk               0x20000000UL
/* FLEXRAY.RDHS2_MIR */
#define FLEXRAY_RDHS2_MIR_CRC_Pos               0UL
#define FLEXRAY_RDHS2_MIR_CRC_Msk               0x7FFUL
#define FLEXRAY_RDHS2_MIR_PLC_Pos               16UL
#define FLEXRAY_RDHS2_MIR_PLC_Msk               0x7F0000UL
#define FLEXRAY_RDHS2_MIR_PLR_Pos               24UL
#define FLEXRAY_RDHS2_MIR_PLR_Msk               0x7F000000UL
/* FLEXRAY.RDHS3_MIR */
#define FLEXRAY_RDHS3_MIR_DP_Pos                0UL
#define FLEXRAY_RDHS3_MIR_DP_Msk                0x7FFUL
#define FLEXRAY_RDHS3_MIR_RCC_Pos               16UL
#define FLEXRAY_RDHS3_MIR_RCC_Msk               0x3F0000UL
#define FLEXRAY_RDHS3_MIR_RCI_Pos               24UL
#define FLEXRAY_RDHS3_MIR_RCI_Msk               0x1000000UL
#define FLEXRAY_RDHS3_MIR_SFI_Pos               25UL
#define FLEXRAY_RDHS3_MIR_SFI_Msk               0x2000000UL
#define FLEXRAY_RDHS3_MIR_SYN_Pos               26UL
#define FLEXRAY_RDHS3_MIR_SYN_Msk               0x4000000UL
#define FLEXRAY_RDHS3_MIR_NFI_Pos               27UL
#define FLEXRAY_RDHS3_MIR_NFI_Msk               0x8000000UL
#define FLEXRAY_RDHS3_MIR_PPI_Pos               28UL
#define FLEXRAY_RDHS3_MIR_PPI_Msk               0x10000000UL
#define FLEXRAY_RDHS3_MIR_RES_Pos               29UL
#define FLEXRAY_RDHS3_MIR_RES_Msk               0x20000000UL
/* FLEXRAY.MBS_MIR */
#define FLEXRAY_MBS_MIR_VFRA_Pos                0UL
#define FLEXRAY_MBS_MIR_VFRA_Msk                0x1UL
#define FLEXRAY_MBS_MIR_VFRB_Pos                1UL
#define FLEXRAY_MBS_MIR_VFRB_Msk                0x2UL
#define FLEXRAY_MBS_MIR_SEOA_Pos                2UL
#define FLEXRAY_MBS_MIR_SEOA_Msk                0x4UL
#define FLEXRAY_MBS_MIR_SEOB_Pos                3UL
#define FLEXRAY_MBS_MIR_SEOB_Msk                0x8UL
#define FLEXRAY_MBS_MIR_CEOA_Pos                4UL
#define FLEXRAY_MBS_MIR_CEOA_Msk                0x10UL
#define FLEXRAY_MBS_MIR_CEOB_Pos                5UL
#define FLEXRAY_MBS_MIR_CEOB_Msk                0x20UL
#define FLEXRAY_MBS_MIR_SVOA_Pos                6UL
#define FLEXRAY_MBS_MIR_SVOA_Msk                0x40UL
#define FLEXRAY_MBS_MIR_SVOB_Pos                7UL
#define FLEXRAY_MBS_MIR_SVOB_Msk                0x80UL
#define FLEXRAY_MBS_MIR_TCIA_Pos                8UL
#define FLEXRAY_MBS_MIR_TCIA_Msk                0x100UL
#define FLEXRAY_MBS_MIR_TCIB_Pos                9UL
#define FLEXRAY_MBS_MIR_TCIB_Msk                0x200UL
#define FLEXRAY_MBS_MIR_ESA_Pos                 10UL
#define FLEXRAY_MBS_MIR_ESA_Msk                 0x400UL
#define FLEXRAY_MBS_MIR_ESB_Pos                 11UL
#define FLEXRAY_MBS_MIR_ESB_Msk                 0x800UL
#define FLEXRAY_MBS_MIR_MLST_Pos                12UL
#define FLEXRAY_MBS_MIR_MLST_Msk                0x1000UL
#define FLEXRAY_MBS_MIR_FTA_Pos                 14UL
#define FLEXRAY_MBS_MIR_FTA_Msk                 0x4000UL
#define FLEXRAY_MBS_MIR_FTB_Pos                 15UL
#define FLEXRAY_MBS_MIR_FTB_Msk                 0x8000UL
#define FLEXRAY_MBS_MIR_CCS_Pos                 16UL
#define FLEXRAY_MBS_MIR_CCS_Msk                 0x3F0000UL
#define FLEXRAY_MBS_MIR_RCIS_Pos                24UL
#define FLEXRAY_MBS_MIR_RCIS_Msk                0x1000000UL
#define FLEXRAY_MBS_MIR_SFIS_Pos                25UL
#define FLEXRAY_MBS_MIR_SFIS_Msk                0x2000000UL
#define FLEXRAY_MBS_MIR_SYNS_Pos                26UL
#define FLEXRAY_MBS_MIR_SYNS_Msk                0x4000000UL
#define FLEXRAY_MBS_MIR_NFIS_Pos                27UL
#define FLEXRAY_MBS_MIR_NFIS_Msk                0x8000000UL
#define FLEXRAY_MBS_MIR_PPIS_Pos                28UL
#define FLEXRAY_MBS_MIR_PPIS_Msk                0x10000000UL
#define FLEXRAY_MBS_MIR_RESS_Pos                29UL
#define FLEXRAY_MBS_MIR_RESS_Msk                0x20000000UL
/* FLEXRAY.OBCM_MIR */
#define FLEXRAY_OBCM_MIR_RHSS_Pos               0UL
#define FLEXRAY_OBCM_MIR_RHSS_Msk               0x1UL
#define FLEXRAY_OBCM_MIR_RDSS_Pos               1UL
#define FLEXRAY_OBCM_MIR_RDSS_Msk               0x2UL
#define FLEXRAY_OBCM_MIR_RHSH_Pos               16UL
#define FLEXRAY_OBCM_MIR_RHSH_Msk               0x10000UL
#define FLEXRAY_OBCM_MIR_RDSH_Pos               17UL
#define FLEXRAY_OBCM_MIR_RDSH_Msk               0x20000UL
/* FLEXRAY.OBCR_MIR */
#define FLEXRAY_OBCR_MIR_OBRS_Pos               0UL
#define FLEXRAY_OBCR_MIR_OBRS_Msk               0x7FUL
#define FLEXRAY_OBCR_MIR_VIEW_Pos               8UL
#define FLEXRAY_OBCR_MIR_VIEW_Msk               0x100UL
#define FLEXRAY_OBCR_MIR_REQ_Pos                9UL
#define FLEXRAY_OBCR_MIR_REQ_Msk                0x200UL
#define FLEXRAY_OBCR_MIR_OBSYS_Pos              15UL
#define FLEXRAY_OBCR_MIR_OBSYS_Msk              0x8000UL
#define FLEXRAY_OBCR_MIR_OBRH_Pos               16UL
#define FLEXRAY_OBCR_MIR_OBRH_Msk               0x7F0000UL


#endif /* _CYIP_FLEXRAY_H_ */


/* [] END OF FILE */
