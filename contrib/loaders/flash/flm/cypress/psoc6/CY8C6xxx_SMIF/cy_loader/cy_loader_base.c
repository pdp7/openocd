/*******************************************************************************
* \file cy_loader_flash.c
* \version 1.0
*
* \brief
*  Implements base flash loaders API declaration.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_loader_base.h"


/*******************************************************************************
* Function Name: Loader_GetMemType
********************************************************************************
*
* Detects the memory type from provided address
*
* \param addr
* Memory address
*
* \return
* Memory type (MEM_TYPE_FLASH or MEM_TYPE_SMIF)
*
*******************************************************************************/
mem_type_t Loader_GetMemType(uint32_t addr)
{
	if (addr < TARGET_XIP_ADDR)
	{
		return MEM_TYPE_FLASH;
	}
	else if ((addr >= TARGET_XIP_ADDR) &&
		(addr < (TARGET_XIP_ADDR + TARGET_XIP_SIZE)))
	{
		return MEM_TYPE_SMIF;
	}
	else
	{
		return MEM_TYPE_UNKNOWN;
	}
}

/*******************************************************************************
* Function Name: Loader_Erase
********************************************************************************
*
* Erases block of memory
*
* \param blockAddr
* Absolute address in target block
*
* \blockSize addr
* Size of block to be erased
*
* \return
* Status
* - RESULT_OK: Erased successfully
* - RESULT_ERROR: Erasing failed
*
*******************************************************************************/
result_t Loader_Erase(uint32_t blockAddr, uint32_t blockSize)
{
	result_t result = RESULT_OK;

	/* Check whether it is internal or external (SMIF\XIP) memory */
	mem_type_t mem_type = Loader_GetMemType(blockAddr);
	bool isSupportedMem = false;
	if (mem_type == MEM_TYPE_FLASH)
	{
		#if defined(BUILD_ENABLE_LOADER_FLASH)
			/* Erase block of internal Flash */
			isSupportedMem = true;
			result = Loader_Flash_Erase(blockAddr, blockSize);
		#endif
	}
	else if (mem_type == MEM_TYPE_SMIF)
	{
		#if defined(BUILD_ENABLE_LOADER_SMIF)
			/* Erase external memory via the SMIF block*/
			isSupportedMem = true;
			result = Loader_SMIF_Erase(blockAddr, blockSize);
		#endif
	}

	if (!isSupportedMem)
	{
		LOG("\r\nERROR: unsupported memory address!\r\n");
		result = RESULT_ERROR;
	}

	return result;
}

/*******************************************************************************
* Function Name: Loader_Program
********************************************************************************
*
* Programs block of memory
*
* \param blockAddr
* Block start address
*
* \param offsetInBlock
* Offset in given block
*
* \param buffer
* Data to be programmed
*
* \param size
* Size of data to be programmed
*
* \return
* Status
* - RESULT_OK: Programmed successfully
* - RESULT_ERROR: Programming failed
*
*******************************************************************************/
result_t Loader_Program(uint32_t blockAddr, uint32_t offsetInBlock, uint8_t *buffer, uint32_t size)
{
	result_t result = RESULT_OK;

	/* Check whether it is internal or external (SMIF\XIP) memory */
	mem_type_t mem_type = Loader_GetMemType(blockAddr);
	bool isSupportedMem = false;
	if (mem_type == MEM_TYPE_FLASH)
	{
		#if defined(BUILD_ENABLE_LOADER_FLASH)
		/* Program internal Flash */
		isSupportedMem = true;
		result = Loader_Flash_Program(blockAddr, offsetInBlock, buffer, size, PRG_API_PROGRAM_ROW);
		#endif
	}
	else if (mem_type == MEM_TYPE_SMIF)
	{
		#if defined(BUILD_ENABLE_LOADER_SMIF)
		/* Program external memory via the SMIF block*/
		isSupportedMem = true;
		result = Loader_SMIF_Program(blockAddr, offsetInBlock, buffer, size);
		#endif
	}

	if (!isSupportedMem)
	{
		LOG("\r\nERROR: unsupported memory address!\r\n");
		result = RESULT_ERROR;
	}

	return result;
}

/*******************************************************************************
* Function Name: Loader_Verify
********************************************************************************
*
* Compares data data in memory with data in buffer
*
* \param addr
* Start of memory block (absolute 32-bit address) to be verified
*
* \param size
* Size of data to be verified
*
* \param buffer
* Data to be compared for verification
*
* \param lastVerifiedAddr
* Address of last successfully verified data
* The sum of (addr+size): Data verified successfully
*
* \return
* Status
* - RESULT_OK: Verified successfully
* - RESULT_ERROR: Verification failed
*
*******************************************************************************/
result_t Loader_Verify(uint32_t addr, uint32_t size, uint8_t *buffer, uint32_t *lastVerifiedAddr)
{
	result_t result = RESULT_OK;

	/* Check whether it is internal or external (SMIF\XIP) memory */
	mem_type_t memType = Loader_GetMemType(addr);
	bool isSupportedMem = false;
	if (memType == MEM_TYPE_FLASH)
	{
		#if defined(BUILD_ENABLE_LOADER_FLASH)
		/* Verify internal Flash */
		isSupportedMem = true;
		result = Loader_Flash_Verify(addr, size, buffer, lastVerifiedAddr);
		#endif
	}
	else if (memType == MEM_TYPE_SMIF)
	{
		#if defined(BUILD_ENABLE_LOADER_SMIF)
		/* Verify external memory via the SMIF block*/
		isSupportedMem = true;
		result = Loader_SMIF_Verify(addr, size, buffer, lastVerifiedAddr);
		#endif
	}

	if (!isSupportedMem)
	{
		LOG("\r\nERROR: unsupported memory address!\r\n");
		result = RESULT_ERROR;
	}

	return result;
}

/*******************************************************************************
* Function Name: Loader_IsMemoryFilled
********************************************************************************
*
* Compares data in memory with given value
*
* \param blockAddr
* Start of memory block (absolute 32-bit address) to be verified
*
* \param blockSize
* Size of data to be compared
*
* \param value
* Value to be compared with memory
*
* \return
* Status
* - RESULT_OK: Memory is filled with given value
* - RESULT_ERROR: Memory is not filed with given value
*
*******************************************************************************/
result_t Loader_IsMemoryFilled(uint32_t blockAddr, uint32_t blockSize, uint8_t value)
{
	result_t result = RESULT_OK;

	/* Check whether it is internal or external (SMIF\XIP) memory */
	mem_type_t memType = Loader_GetMemType(blockAddr);
	bool isSupportedMem = false;
	if (memType == MEM_TYPE_FLASH)
	{
		#if defined(BUILD_ENABLE_LOADER_FLASH)
		/* Verify internal Flash */
		isSupportedMem = true;
		result = Loader_Flash_IsMemoryFilled(blockAddr, blockSize, value);
		#endif
	}
	else if (memType == MEM_TYPE_SMIF)
	{
		#if defined(BUILD_ENABLE_LOADER_SMIF)
		/* Verify external memory via the SMIF block*/
		isSupportedMem = true;
		result = Loader_SMIF_IsMemoryFilled(blockAddr, blockSize, value);
		#endif
	}

	if (!isSupportedMem)
	{
		LOG("\r\nERROR: unsupported memory address!\r\n");
		result = RESULT_ERROR;
	}

	return result;
}

/*******************************************************************************
* Function Name: Loader_Init
********************************************************************************
*
* Initialises the loader for specific mode (SMIF/FLASH)
*
* \param blockAddr
* Start of memory block (absolute 32-bit address)
*
* \return
* Status
* - RESULT_OK: Memory is initialised successfully
* - RESULT_ERROR: Memory initialisation error
*
*******************************************************************************/
result_t Loader_Init(uint32_t blockAddr)
{
	result_t result = RESULT_OK;

	/* Check whether it is internal or external (SMIF\XIP) memory */
	mem_type_t memType = Loader_GetMemType(blockAddr);
	bool isSupportedMem = false;
	if (memType == MEM_TYPE_FLASH)
	{
		#if defined(BUILD_ENABLE_LOADER_FLASH)
		/* Internal Flash, already enabled */
		isSupportedMem = true;
		#endif
	}
	else if (memType == MEM_TYPE_SMIF)
	{
		#if defined(BUILD_ENABLE_LOADER_SMIF)
		/* Enable SMIF in XIP mode */
		isSupportedMem = true;
		result = Loader_SMIF_Init_XIP(blockAddr);
		#endif
	}

	if (!isSupportedMem)
	{
		LOG("\r\nERROR: unsupported memory address!\r\n");
		result = RESULT_ERROR;
	}

	return result;
}

/*******************************************************************************
* Function Name: Loader_UnInit
********************************************************************************
*
* Disable the SMIF block.
*
* \param func
*   Function Code (1 - Erase, 2 - Program, 3 - Verify)
*   Most cases - it is unused.
*
* \return
* Status
* - RESULT_OK: SMIF block is disabled
*
*******************************************************************************/
result_t Loader_UnInit(uint32_t func)
{
  result_t retVal = 0;

	retVal = Loader_SMIF_Deinit();
	backRestoreCnfg(true);

	return retVal;
}


/*******************************************************************************
* Function Name: Loader_Checksum
********************************************************************************
*
* Calculates the checksum of specified area.
*
* \param address
*   Address of the area
*
* \param size
*   Size of the data
*
* \param checksum
*   Pointer where checksum to be stored
*
* \return
* Status
* - RESULT_OK: Checksum was calculated
* - RESULT_ERROR: Error has occured
*
*******************************************************************************/
uint32_t Loader_Checksum(uint32_t address, uint32_t size, uint32_t *checksum)
{
	result_t result = RESULT_OK;

	/* Check whether it is internal or external (SMIF\XIP) memory */
	mem_type_t memType = Loader_GetMemType(address);

	if (memType == MEM_TYPE_FLASH)
	{
		/* Nothing special needs to be done in case of FLASH */
	}
	else if (memType == MEM_TYPE_SMIF)
	{
		result = Loader_SMIF_Init_XIP(address);
	}
	else
	{
		result = RESULT_ERROR;
	}

	if (result != RESULT_ERROR)
	{
		*checksum = 0;
		unsigned char* memPtr = (unsigned char*)address;
		uint32_t i;
		for (i=0;i<size;i++)
		{
			*checksum += memPtr[i];
		}
	}
	return (result);
}


/* [] END OF FILE */
