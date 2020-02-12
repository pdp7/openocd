/***************************************************************************//**
* \file cy_debug.h
* \version 1.0
*
* \brief
*  Includes all the necessary outputs for the UART console
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(__DBG_IO_H)
#define __DBG_IO_H

#include "../device_header.h"

/******************************************************************************
 * Logging
 ******************************************************************************/
 #include <stdio.h>
 int _write(int file, char *ptr, int len);
#if !defined(DEBUG_LOG)
    #define LOG(...)
    #define LOG_RESULT(...)
    #define LOG_FUNC_START(...)
    #define LOG_FUNC_END(...)
#else


#include "cy_debug.h"


#define LOG(...) printf(__VA_ARGS__)
#define LOG_RESULT(result) \
        if (SUCCEEDED(result)) LOG("SUCCESS"); \
        else LOG("FAIL!");
#define LOG_FUNC_START(funcName) printf("=> FUNC.STARTED:\t  \"%s\"\r\n", funcName);
#define LOG_FUNC_END(funcName, result) \
        const char *resultStr; \
        if (SUCCEEDED(result)) resultStr = "SUCCEEDED"; \
        else resultStr = "FAILED!"; \
        printf("<= FUNC.%s:\t  \"%s\"\r\n", resultStr, funcName);


#endif /* DEBUG_LOG */

#endif /*CY_DEBUG_H*/

void DBG_PutChar(char txDataByte);
void DBG_PutString(const char string[]);
extern void Cy_SysLib_DelayCycles(uint32_t cycles);
void PIN_Write(uint32_t value);


/* [] END OF FILE */
