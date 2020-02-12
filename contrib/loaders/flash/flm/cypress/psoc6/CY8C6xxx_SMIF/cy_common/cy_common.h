/***************************************************************************//**
* \file cy_common.h
* \version 1.0
*
* \brief
*  Project common declarations
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_COMMON_H)
#define CY_COMMON_H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

/* extern "C" */
#ifdef __cplusplus
extern "C" {
#endif


/******************************************************************************
 * Functions results processing
 ******************************************************************************/
typedef int result_t;
#define RESULT_OK                0
#define RESULT_ERROR             1
#define RESULT_ERROR_OK          2
#define SUCCEEDED(result)        ((result) == (RESULT_OK))
#define FAILED(result)           ((result) != (RESULT_OK))
#define RETURN_IF_FAILED(result) if (FAILED(result)) return (RESULT_ERROR)
#define BREAK_IF_FAILED(result)  if (FAILED(result)) break


/******************************************************************************
 * Memory managing
 ******************************************************************************/
#define REG32(addr) (*(volatile uint32 *) (addr))

/******************************************************************************
 * Functions definition
 ******************************************************************************/
result_t WriteIO (uint32_t addr, uint32_t data);
result_t ReadIO (uint32_t addr, uint32_t *data);

/******************************************************************************
 * Attributes
 ******************************************************************************/
#define CY_USED __attribute__((used))
#if defined(__ARMCC_VERSION) || defined(__GNUC__) || defined(__ARMCC_VERSION)
    #define CY_SECTION(name)    __attribute__ ((section(name)))
#elif defined (__ICCARM__)
    #define CY_SECTION(name)    CY_PRAGMA(section = name)
#else
    #error Unsupported toolchain
#endif  /* (__ARMCC_VERSION) */

/* extern "C" */
#ifdef __cplusplus
}
#endif

#endif /*CY_COMMON_H*/

/* [] END OF FILE */
