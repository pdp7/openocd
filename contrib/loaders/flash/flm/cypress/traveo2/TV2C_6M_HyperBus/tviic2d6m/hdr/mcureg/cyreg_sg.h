/***************************************************************************//**
* \file cyreg_sg.h
*
* \brief
* SG register definition header
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

#ifndef _CYREG_SG_H_
#define _CYREG_SG_H_

#include "cyip_sg.h"

/**
  * \brief Sound generator structure (SG_SG_STRUCT0)
  */
#define CYREG_SG0_SG_STRUCT0_CTL        ((volatile un_SG_SG_STRUCT_CTL_t*) 0x40828000UL)
#define CYREG_SG0_SG_STRUCT0_IF_CTL     ((volatile un_SG_SG_STRUCT_IF_CTL_t*) 0x40828010UL)
#define CYREG_SG0_SG_STRUCT0_TIME_CTL   ((volatile un_SG_SG_STRUCT_TIME_CTL_t*) 0x40828020UL)
#define CYREG_SG0_SG_STRUCT0_TONE_CTL   ((volatile un_SG_SG_STRUCT_TONE_CTL_t*) 0x40828024UL)
#define CYREG_SG0_SG_STRUCT0_AMPL_CTL   ((volatile un_SG_SG_STRUCT_AMPL_CTL_t*) 0x40828028UL)
#define CYREG_SG0_SG_STRUCT0_STEP_CTL   ((volatile un_SG_SG_STRUCT_STEP_CTL_t*) 0x4082802CUL)
#define CYREG_SG0_SG_STRUCT0_TIME_CTL_BUFF ((volatile un_SG_SG_STRUCT_TIME_CTL_BUFF_t*) 0x40828030UL)
#define CYREG_SG0_SG_STRUCT0_TONE_CTL_BUFF ((volatile un_SG_SG_STRUCT_TONE_CTL_BUFF_t*) 0x40828034UL)
#define CYREG_SG0_SG_STRUCT0_AMPL_CTL_BUFF ((volatile un_SG_SG_STRUCT_AMPL_CTL_BUFF_t*) 0x40828038UL)
#define CYREG_SG0_SG_STRUCT0_STEP_CTL_BUFF ((volatile un_SG_SG_STRUCT_STEP_CTL_BUFF_t*) 0x4082803CUL)
#define CYREG_SG0_SG_STRUCT0_INTR_TX    ((volatile un_SG_SG_STRUCT_INTR_TX_t*) 0x408280C0UL)
#define CYREG_SG0_SG_STRUCT0_INTR_TX_SET ((volatile un_SG_SG_STRUCT_INTR_TX_SET_t*) 0x408280C4UL)
#define CYREG_SG0_SG_STRUCT0_INTR_TX_MASK ((volatile un_SG_SG_STRUCT_INTR_TX_MASK_t*) 0x408280C8UL)
#define CYREG_SG0_SG_STRUCT0_INTR_TX_MASKED ((volatile un_SG_SG_STRUCT_INTR_TX_MASKED_t*) 0x408280CCUL)

/**
  * \brief Sound generator structure (SG_SG_STRUCT1)
  */
#define CYREG_SG0_SG_STRUCT1_CTL        ((volatile un_SG_SG_STRUCT_CTL_t*) 0x40828100UL)
#define CYREG_SG0_SG_STRUCT1_IF_CTL     ((volatile un_SG_SG_STRUCT_IF_CTL_t*) 0x40828110UL)
#define CYREG_SG0_SG_STRUCT1_TIME_CTL   ((volatile un_SG_SG_STRUCT_TIME_CTL_t*) 0x40828120UL)
#define CYREG_SG0_SG_STRUCT1_TONE_CTL   ((volatile un_SG_SG_STRUCT_TONE_CTL_t*) 0x40828124UL)
#define CYREG_SG0_SG_STRUCT1_AMPL_CTL   ((volatile un_SG_SG_STRUCT_AMPL_CTL_t*) 0x40828128UL)
#define CYREG_SG0_SG_STRUCT1_STEP_CTL   ((volatile un_SG_SG_STRUCT_STEP_CTL_t*) 0x4082812CUL)
#define CYREG_SG0_SG_STRUCT1_TIME_CTL_BUFF ((volatile un_SG_SG_STRUCT_TIME_CTL_BUFF_t*) 0x40828130UL)
#define CYREG_SG0_SG_STRUCT1_TONE_CTL_BUFF ((volatile un_SG_SG_STRUCT_TONE_CTL_BUFF_t*) 0x40828134UL)
#define CYREG_SG0_SG_STRUCT1_AMPL_CTL_BUFF ((volatile un_SG_SG_STRUCT_AMPL_CTL_BUFF_t*) 0x40828138UL)
#define CYREG_SG0_SG_STRUCT1_STEP_CTL_BUFF ((volatile un_SG_SG_STRUCT_STEP_CTL_BUFF_t*) 0x4082813CUL)
#define CYREG_SG0_SG_STRUCT1_INTR_TX    ((volatile un_SG_SG_STRUCT_INTR_TX_t*) 0x408281C0UL)
#define CYREG_SG0_SG_STRUCT1_INTR_TX_SET ((volatile un_SG_SG_STRUCT_INTR_TX_SET_t*) 0x408281C4UL)
#define CYREG_SG0_SG_STRUCT1_INTR_TX_MASK ((volatile un_SG_SG_STRUCT_INTR_TX_MASK_t*) 0x408281C8UL)
#define CYREG_SG0_SG_STRUCT1_INTR_TX_MASKED ((volatile un_SG_SG_STRUCT_INTR_TX_MASKED_t*) 0x408281CCUL)

/**
  * \brief Sound generator structure (SG_SG_STRUCT2)
  */
#define CYREG_SG0_SG_STRUCT2_CTL        ((volatile un_SG_SG_STRUCT_CTL_t*) 0x40828200UL)
#define CYREG_SG0_SG_STRUCT2_IF_CTL     ((volatile un_SG_SG_STRUCT_IF_CTL_t*) 0x40828210UL)
#define CYREG_SG0_SG_STRUCT2_TIME_CTL   ((volatile un_SG_SG_STRUCT_TIME_CTL_t*) 0x40828220UL)
#define CYREG_SG0_SG_STRUCT2_TONE_CTL   ((volatile un_SG_SG_STRUCT_TONE_CTL_t*) 0x40828224UL)
#define CYREG_SG0_SG_STRUCT2_AMPL_CTL   ((volatile un_SG_SG_STRUCT_AMPL_CTL_t*) 0x40828228UL)
#define CYREG_SG0_SG_STRUCT2_STEP_CTL   ((volatile un_SG_SG_STRUCT_STEP_CTL_t*) 0x4082822CUL)
#define CYREG_SG0_SG_STRUCT2_TIME_CTL_BUFF ((volatile un_SG_SG_STRUCT_TIME_CTL_BUFF_t*) 0x40828230UL)
#define CYREG_SG0_SG_STRUCT2_TONE_CTL_BUFF ((volatile un_SG_SG_STRUCT_TONE_CTL_BUFF_t*) 0x40828234UL)
#define CYREG_SG0_SG_STRUCT2_AMPL_CTL_BUFF ((volatile un_SG_SG_STRUCT_AMPL_CTL_BUFF_t*) 0x40828238UL)
#define CYREG_SG0_SG_STRUCT2_STEP_CTL_BUFF ((volatile un_SG_SG_STRUCT_STEP_CTL_BUFF_t*) 0x4082823CUL)
#define CYREG_SG0_SG_STRUCT2_INTR_TX    ((volatile un_SG_SG_STRUCT_INTR_TX_t*) 0x408282C0UL)
#define CYREG_SG0_SG_STRUCT2_INTR_TX_SET ((volatile un_SG_SG_STRUCT_INTR_TX_SET_t*) 0x408282C4UL)
#define CYREG_SG0_SG_STRUCT2_INTR_TX_MASK ((volatile un_SG_SG_STRUCT_INTR_TX_MASK_t*) 0x408282C8UL)
#define CYREG_SG0_SG_STRUCT2_INTR_TX_MASKED ((volatile un_SG_SG_STRUCT_INTR_TX_MASKED_t*) 0x408282CCUL)

/**
  * \brief Sound generator structure (SG_SG_STRUCT3)
  */
#define CYREG_SG0_SG_STRUCT3_CTL        ((volatile un_SG_SG_STRUCT_CTL_t*) 0x40828300UL)
#define CYREG_SG0_SG_STRUCT3_IF_CTL     ((volatile un_SG_SG_STRUCT_IF_CTL_t*) 0x40828310UL)
#define CYREG_SG0_SG_STRUCT3_TIME_CTL   ((volatile un_SG_SG_STRUCT_TIME_CTL_t*) 0x40828320UL)
#define CYREG_SG0_SG_STRUCT3_TONE_CTL   ((volatile un_SG_SG_STRUCT_TONE_CTL_t*) 0x40828324UL)
#define CYREG_SG0_SG_STRUCT3_AMPL_CTL   ((volatile un_SG_SG_STRUCT_AMPL_CTL_t*) 0x40828328UL)
#define CYREG_SG0_SG_STRUCT3_STEP_CTL   ((volatile un_SG_SG_STRUCT_STEP_CTL_t*) 0x4082832CUL)
#define CYREG_SG0_SG_STRUCT3_TIME_CTL_BUFF ((volatile un_SG_SG_STRUCT_TIME_CTL_BUFF_t*) 0x40828330UL)
#define CYREG_SG0_SG_STRUCT3_TONE_CTL_BUFF ((volatile un_SG_SG_STRUCT_TONE_CTL_BUFF_t*) 0x40828334UL)
#define CYREG_SG0_SG_STRUCT3_AMPL_CTL_BUFF ((volatile un_SG_SG_STRUCT_AMPL_CTL_BUFF_t*) 0x40828338UL)
#define CYREG_SG0_SG_STRUCT3_STEP_CTL_BUFF ((volatile un_SG_SG_STRUCT_STEP_CTL_BUFF_t*) 0x4082833CUL)
#define CYREG_SG0_SG_STRUCT3_INTR_TX    ((volatile un_SG_SG_STRUCT_INTR_TX_t*) 0x408283C0UL)
#define CYREG_SG0_SG_STRUCT3_INTR_TX_SET ((volatile un_SG_SG_STRUCT_INTR_TX_SET_t*) 0x408283C4UL)
#define CYREG_SG0_SG_STRUCT3_INTR_TX_MASK ((volatile un_SG_SG_STRUCT_INTR_TX_MASK_t*) 0x408283C8UL)
#define CYREG_SG0_SG_STRUCT3_INTR_TX_MASKED ((volatile un_SG_SG_STRUCT_INTR_TX_MASKED_t*) 0x408283CCUL)

/**
  * \brief Sound generator structure (SG_SG_STRUCT4)
  */
#define CYREG_SG0_SG_STRUCT4_CTL        ((volatile un_SG_SG_STRUCT_CTL_t*) 0x40828400UL)
#define CYREG_SG0_SG_STRUCT4_IF_CTL     ((volatile un_SG_SG_STRUCT_IF_CTL_t*) 0x40828410UL)
#define CYREG_SG0_SG_STRUCT4_TIME_CTL   ((volatile un_SG_SG_STRUCT_TIME_CTL_t*) 0x40828420UL)
#define CYREG_SG0_SG_STRUCT4_TONE_CTL   ((volatile un_SG_SG_STRUCT_TONE_CTL_t*) 0x40828424UL)
#define CYREG_SG0_SG_STRUCT4_AMPL_CTL   ((volatile un_SG_SG_STRUCT_AMPL_CTL_t*) 0x40828428UL)
#define CYREG_SG0_SG_STRUCT4_STEP_CTL   ((volatile un_SG_SG_STRUCT_STEP_CTL_t*) 0x4082842CUL)
#define CYREG_SG0_SG_STRUCT4_TIME_CTL_BUFF ((volatile un_SG_SG_STRUCT_TIME_CTL_BUFF_t*) 0x40828430UL)
#define CYREG_SG0_SG_STRUCT4_TONE_CTL_BUFF ((volatile un_SG_SG_STRUCT_TONE_CTL_BUFF_t*) 0x40828434UL)
#define CYREG_SG0_SG_STRUCT4_AMPL_CTL_BUFF ((volatile un_SG_SG_STRUCT_AMPL_CTL_BUFF_t*) 0x40828438UL)
#define CYREG_SG0_SG_STRUCT4_STEP_CTL_BUFF ((volatile un_SG_SG_STRUCT_STEP_CTL_BUFF_t*) 0x4082843CUL)
#define CYREG_SG0_SG_STRUCT4_INTR_TX    ((volatile un_SG_SG_STRUCT_INTR_TX_t*) 0x408284C0UL)
#define CYREG_SG0_SG_STRUCT4_INTR_TX_SET ((volatile un_SG_SG_STRUCT_INTR_TX_SET_t*) 0x408284C4UL)
#define CYREG_SG0_SG_STRUCT4_INTR_TX_MASK ((volatile un_SG_SG_STRUCT_INTR_TX_MASK_t*) 0x408284C8UL)
#define CYREG_SG0_SG_STRUCT4_INTR_TX_MASKED ((volatile un_SG_SG_STRUCT_INTR_TX_MASKED_t*) 0x408284CCUL)

#endif /* _CYREG_SG_H_ */


/* [] END OF FILE */
