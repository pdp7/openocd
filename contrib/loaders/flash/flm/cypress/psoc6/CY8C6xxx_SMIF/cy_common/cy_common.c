/*******************************************************************************
* \file cy_common.c
* \version 1.0
*
* \brief
*  Implements Common APIs.
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_common.h"

/*******************************************************************************
* Function Name: WriteIO
****************************************************************************//**
*
* Writes word (32 bits) to memory
*
* \param addr
* absolute address (32 bits)
*
* \param data
* data word (32 bits)
*
* \return
* Status
* - RESULT_OK: Write successful
* - RESULT_ERROR: Write fail
*
*******************************************************************************/
result_t WriteIO (uint32_t addr, uint32_t data)
{
	uint32_t *address = (uint32_t*)addr;
	*address = data;
	return RESULT_OK;
}

/*******************************************************************************
* Function Name: ReadIO
****************************************************************************//**
*
* Reads word (32 bits) from memory
*
* \param addr
* absolute address (32 bits)
*
* \param data
* data word (32 bits)
*
* \return
* Status
* - RESULT_OK: Write successful
* - RESULT_ERROR: Write fail
*
*******************************************************************************/
result_t ReadIO (uint32_t addr, uint32_t *data)
{
	uint32_t *address = (uint32_t*)addr;
	*data = *address;
	return RESULT_OK;
}

/* [] END OF FILE */
