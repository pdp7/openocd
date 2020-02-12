/*******************************************************************************
* \file cy_loader_flash.c
* \version 1.0
*
* \brief
*  Implements flash loader APIs.
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_loader_flash.h"

#if defined (BUILD_ENABLE_LOADER_FLASH)

/*******************************************************************************
* Function Name: Loader_Flash_Erase
********************************************************************************
*
* Erases block of internal Flash
*
* \param blockAddr
* Absolute address in target block
*
* \param blockSize
* Size of block to be erased
*
* \return
* Status
* - RESULT_OK: Erased successfully
* - RESULT_ERROR: Erasing failed
*
*******************************************************************************/
result_t Loader_Flash_Erase(uint32_t blockAddr, uint32_t blockSize)
{
    result_t result = RESULT_OK;

    /* Erase block by sectors or by rows or combining */
    if (blockSize <= TARGET_FLASH_ROW_SIZE)
    {
        /* Erase only one row in Flash */
        result = SromApiEraseRow(blockAddr);
    }
    else
    {
        uint32_t currentAddr = blockAddr;
        int remainedSize = blockSize;

        while (remainedSize > 0)
        {
            bool doEraseSector = false;

            /* Check whether block_addr starts at sector start address */
            bool isSectorStart = (currentAddr - TARGET_FLASH_ADDR) % TARGET_FLASH_SECTOR_SIZE == 0;
            if (isSectorStart)
            {
                /* Check whether we can erase whole sector */
                doEraseSector = remainedSize >= (int)TARGET_FLASH_SECTOR_SIZE;
            }

            uint32_t justErasedSize = 0;
            if (doEraseSector)
            {
                /* Erase one memory sector*/
                result = SromApiEraseSector(currentAddr);
                BREAK_IF_FAILED(result);

                justErasedSize = TARGET_FLASH_SECTOR_SIZE;
            }
            else
            {
                /* Erase one row */
                result = SromApiEraseRow(currentAddr);
                BREAK_IF_FAILED(result);

                justErasedSize = TARGET_FLASH_ROW_SIZE;
            }
            currentAddr += justErasedSize;
            remainedSize -= justErasedSize;
        }
    }

    return result;
}

/*******************************************************************************
* Function Name: Loader_Flash_Program
********************************************************************************
*
* Program page in Flash memory
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
* \param prgApi
* SROM API to be used for programming (ProgramRow or WriteRow)
*
* \return
* Status
* - RESULT_OK: Programmed successfully
* - RESULT_ERROR: Programming failed
*
*******************************************************************************/
result_t Loader_Flash_Program(uint32_t blockAddr, uint32_t offsetInBlock, uint8_t *buffer, uint32_t size, prg_api_t prgApi)
{
    result_t result = RESULT_OK;
    uint32_t programGranularity = TARGET_FLASH_ROW_SIZE;
    uint32_t startAddr = blockAddr + offsetInBlock;
    uint32_t endAddr = startAddr + size - 1;

    uint32_t currentAddr, offsetInBuffer = 0;
    for(currentAddr = startAddr;
        currentAddr <= endAddr;
        currentAddr += programGranularity)
    {
        //Delay(50000);
        if (prgApi == PRG_API_PROGRAM_ROW)
        {
            result = SromApiProgramRow(currentAddr, (char const *)(buffer + offsetInBuffer));
            RETURN_IF_FAILED(result);
        }
        else /* prgApi == PRG_API_WRITE_ROW */
        {
            result = SromApiWriteRow(currentAddr, (char const *)(buffer + offsetInBuffer));
            RETURN_IF_FAILED(result);
        }
        offsetInBuffer += programGranularity;
    }

    return result;
}

/*******************************************************************************
* Function Name: Loader_Flash_Verify
********************************************************************************
*
* Compares data in memory with data in buffer
*
* \param blockAddr
* Start of memory block (absolute 32-bit address) to be verified
*
* \param blockSize
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
result_t Loader_Flash_Verify(uint32_t blockAddr, uint32_t blockSize, uint8_t *buffer, uint32_t *lastVerifiedAddr)
{
    /* Note, the "size" for all rows = TARGET_FLASH_ROW_SIZE, but only for last row being verified,
     * this value typically is < TARGET_FLASH_ROW_SIZE.
     * So, it is necessary to use "size" for every call, instead of hardcoded ROW_SIZE. */

    uint32_t i;
    result_t result = RESULT_OK;

    /* Read directly from Flash */
    unsigned char* chipData = (unsigned char*)blockAddr;

    /* Compare bytes */
    /* Always use "size", not TARGET_FLASH_ROW_SIZE, since last block can be not shorter */
    for (i = 0 ; i < blockSize; i++)
    {
        if (buffer[i] != chipData[i])
        {
            result = RESULT_ERROR;
            break;
        }
    }

    /* success = (adr+size), otherwise = fail */
    *lastVerifiedAddr = blockAddr + i;

    return result;
}

/*******************************************************************************
* Function Name: Loader_Flash_IsMemoryFilled
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
result_t Loader_Flash_IsMemoryFilled(uint32_t blockAddr, uint32_t blockSize, uint8_t value)
{
    LOG("\r\n=> FUNC.START: Loader_SMIF_IsMemoryFilled: [blockAddr=0x%08X, blockSize=0x%08X, value=0x%02X]\r\n",
        (unsigned int)blockAddr, (unsigned int)blockSize, (unsigned int)value);

    uint32_t i;
    result_t result = RESULT_OK;

    /* Read directly from memory */
    unsigned char* chipData = (unsigned char*)blockAddr;

    /* Compare bytes vith given value*/
    for (i = 0 ; i < blockSize; i++)
    {
        if (chipData[i] != value)
        {
            result = RESULT_ERROR;
            break;
        }
    }

    LOG("\r\n=> FUNC.RET: [0x%08X]\r\n", (unsigned int)result);
    return result;
}

#endif /* BUILD_ENABLE_LOADER_FLASH */

/* [] END OF FILE */
