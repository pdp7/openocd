/***************************************************************************//**
* \file cy_srom.c
* \version 1.0
*
* \brief
*  Implements MXS40 SROM APIs
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_srom.h"

#if defined (BUILD_ENABLE_LOADER_FLASH)

/*******************************************************************************
* Function Name: Ipc_PollLockStatus
****************************************************************************//**
*
* Polls lock status of IPC structure
*
* \param ipcId
* Id of IPC structure
* - 0: IPC_STRUCT0 (CM0+)
* - 1: IPC_STRUCT1 (CM4)
* - 2: IPC_STRUCT2 (DAP)
*
* \param timeoutAttempts
* Timeout
*
* \return
* Status
* - RESULT_OK: IPC structure locked successfully
* - RESULT_ERROR: Cannot lock IPC structure
*
*******************************************************************************/
result_t Ipc_PollLockStatus(char ipcId, bool lockExpected, int timeoutAttempts)
{
    result_t result = RESULT_OK;
    int attemptsElapsed = 0x00;
    bool isExpectedStatus = false;
    uint32_t readData;
    uint32_t ipcAddr;
    ipcAddr = MXS40_IPC0_ADDR + MXS40_IPC_SIZE * ipcId;

    do
    {
        /* Check lock status */
        result = ReadIO(ipcAddr + MXS40_IPC_LOCK_STATUS_OFFS,&readData);
        if (result == RESULT_OK)
        {
            bool isLocked = (readData & MXS40_IPC_LOCK_STATUS_ACQUIRED_MSK) != 0;
            isExpectedStatus = (lockExpected && isLocked) || (!lockExpected && !isLocked);
        }

        /* Check for timeout */
        if (!isExpectedStatus)
        {
            if (attemptsElapsed > timeoutAttempts)
            {
                return RESULT_ERROR;
            }
            Cy_SysLib_DelayUs(1000);
            attemptsElapsed++;
        }

    } while (!isExpectedStatus);

  return result;
}

/*******************************************************************************
* Function Name: Ipc_Acquire
****************************************************************************//**
*
* Acquires MXS40 IPC structure
*
* \param ipcId
* Id of IPC structure
* - 0: IPC_STRUCT0 (CM0+)
* - 1: IPC_STRUCT1 (CM4)
* - 2: IPC_STRUCT2 (DAP)
*
* \param timeoutAttempts
* Timeout
*
* \return
* Status
* - RESULT_OK: IPC structure acquired successfully
* - RESULT_ERROR: Cannon acquire IPC structure
*
*******************************************************************************/
result_t Ipc_Acquire(char ipcId, int timeoutAttempts)
{
  unsigned int attemptsElapsed = 0x00;
  bool isAcquired = false;
  unsigned long readData;
	unsigned long ipcAddr;
	ipcAddr = MXS40_IPC0_ADDR + MXS40_IPC_SIZE * ipcId;

	do
  {
		/* To acquire the IPC[2] (IPC structure for DAP),
		   debugger need to write any value to IPC[2].ACQUIRE register.
		   The write operation acquires the lock. The write value is irrelevant. */

		/* To acquire the IPC[0] (CM0) or IPC[1] (CM4) /e.g. in flash loaders/
		   Master needs to read IPC[x].ACQUIRE register
		   If the SUCCESS field returns a '1', the read acquired the lock.
		   If the SUCCESS field returns a '0', the read did not acquire the lock.
		   Note that a single read access performs two functions:
		   The attempt to acquire a lock.
		   Return the result of the acquisition attempt (SUCCESS field). */

    ReadIO(ipcAddr + MXS40_IPC_ACQUIRE_OFFS, &readData);
	  isAcquired = (readData & MXS40_IPC_ACQUIRE_SUCCESS_MSK) != 0;

		/* Check for timeout*/
	  if (!isAcquired)
	  {
		  if (attemptsElapsed > timeoutAttempts)
		  {
				break;
			}
		  Cy_SysLib_DelayUs(1000);
			attemptsElapsed++;
		}

  } while (!isAcquired);

  return isAcquired? RESULT_OK: RESULT_ERROR;
}

/*******************************************************************************
* Function Name: PollSromApiStatus
****************************************************************************//**
*
* Polls execution status of SROM API
*
* \param address
* Memory address of SROM API status word
*
* \param timeoutAttempts
* Timeout
*
* \param dataOut
* status word
*
* \return
* Status
* - RESULT_OK: SROM API returned successful execution status
* - RESULT_ERROR: SROM API execution failed
*
*******************************************************************************/
result_t PollSromApiStatus(uint32_t address, int timeoutAttempts, uint32_t *dataOut)
{
    result_t result;
    int attemptsElapsed = 0x00;
    bool isAcquired = false;

    do
    {
        /* Poll data */
        result = ReadIO(address, dataOut);
        if (SUCCEEDED(result))
        {
            isAcquired = (*dataOut & SROMAPI_STATUS_MSK) == SROMAPI_STAT_SUCCESS;
        }

        /* Check for timeout */
        if (!isAcquired)
        {
            if (attemptsElapsed > timeoutAttempts)
            {
                return RESULT_ERROR;
            }
            Cy_SysLib_DelayUs(1000);
            attemptsElapsed++;
        }

    } while (!isAcquired);

    return result;
}

/*******************************************************************************
* Function Name: CallSromApi
****************************************************************************//**
*
* Calls SROM API
* SROM APIs are executed by invoking a system call & providing
* the corresponding arguments.
* System calls can be performed by CM0+, CM4 or DAP.
* Each of them have a reserved IPC structure (used as a mailbox) through which
* they can request CM0+ to perform a system call.
* Each one acquires the specific mailbox, writes the opcode and
* argument to the data field of the mailbox and notifies a dedicated
* IPC interrupt structure. This results in an NMI interrupt in M0+.
*
* \param callIdAndParams
* OpCode of SROM API and params (in case all params are in IPC structure)
*
* \param dataOut
* status word
*
* \return
* Status
* - RESULT_OK: SROM API returned successful execution status
* - RESULT_ERROR: SROM API execution failed
*
*******************************************************************************/
result_t CallSromApi(uint32_t callIdAndParams, uint32_t *dataOut)
{
    result_t result;
    // Check where the arguments for this API are located
    // [0]: 1 - arguments are passed in IPC.DATA. 0 - arguments are passed in SRAM
    bool isDataInRam = (callIdAndParams & SROMAPI_DATA_LOCATION_MSK) == 0;

    char ipcId;
    uint32_t ipcStructAddr = 0;

	#if defined(BUILD_TARGET_SMIF) | defined(BUILD_TARGET_CY8C6x6_M0)| defined(BUILD_TARGET_CY8C6x7_M0) | defined(BUILD_TARGET_CY8C622PSVP_M0)
        ipcId = 0;
        ipcStructAddr = MXS40_IPC_CM0_ADDR;
	#elif defined(BUILD_TARGET_CY8C6x6_M4)|defined(BUILD_TARGET_CY8C6x7_M4)| defined(BUILD_TARGET_CY8C622PSVP_M4)
        ipcId = 1;
		    ipcStructAddr = MXS40_IPC_CM4_ADDR;
	#endif

    /* Acquire IPC_STRUCT for target Cortex CPU */
    result = Ipc_Acquire(ipcId, TIMEOUT_IPC_ACQUIRE);

    RETURN_IF_FAILED(result);

    /* Write to IPC_STRUCT.DATA one of:
     * a) Sys call ID and Parameters
     * b) address in SRAM, where they are located */
    if (isDataInRam)
    {
        result = WriteIO(ipcStructAddr + MXS40_IPC_DATA_OFFS , SROMAPI_SRAM_SCRATCH_ADDR);
        RETURN_IF_FAILED(result);
    }
    else
    {
        result = WriteIO(ipcStructAddr + MXS40_IPC_DATA_OFFS , callIdAndParams);
        RETURN_IF_FAILED(result);
    }

    /* Enable notification interrupt of IPC_INTR_STRUCT0(CM0+) for IPC_STRUCT1 or IPC_STRUCT0 */
    result = WriteIO(MXS40_IPC_INTR_ADDR + MXS40_IPC_INTR_IPC_MASK_OFFS , 1 << (16+ipcId));
    RETURN_IF_FAILED(result);

    /* Notify to IPC_INTR_STRUCT.IPC_STRUCT.MASK <- Notify */
    result = WriteIO(ipcStructAddr + MXS40_IPC_NOTIFY_OFFS , 1);
    RETURN_IF_FAILED(result);

    /* Poll IPC lock status */
    result = Ipc_PollLockStatus(ipcId, false, TIMEOUT_IPC_ACQUIRE);
    RETURN_IF_FAILED(result);

    /* Poll for success status in Data word */
    if (isDataInRam)
    {
        result = PollSromApiStatus(SROMAPI_SRAM_SCRATCH_ADDR, TIMEOUT_IPC_DATA, dataOut);
    }
    else
    {
        result = PollSromApiStatus(ipcStructAddr + MXS40_IPC_DATA_OFFS, TIMEOUT_IPC_DATA, dataOut);
    }

  return result;
}

/*******************************************************************************
* Function Name: SromApiEraseRow
****************************************************************************//**
*
* Erases the specified page. User needs to provide the address of the page which needs to be erased.
* Flash address to be erased should be provided in 32-bit system address format.
* For example if you want to erase second page then you need to provide 32-bit
* system address of any of the byte lying in second page.
*
* \param addr
* 32-bit system address of any of the byte lying in second page
*
* \return
* Status
* - RESULT_OK: Sector erased successfully
* - RESULT_ERROR: Sector erasing failed
*
*******************************************************************************/
result_t SromApiEraseRow(uint32_t addr)
{
    result_t result;
    uint32_t dataOut;

    LOG("\r\n=> Func. entered: \"SromApiEraseRow\"\r\n");

    /* SRAM_SCRATCH: OpCode */
    result = WriteIO(SROMAPI_SRAM_SCRATCH_ADDR, SROMAPI_ERASEROW_CODE);
    RETURN_IF_FAILED(result);
		LOG("\r\n=> => Phase 1 %d\r\n",result);
    /* SRAM_SCRATCH + 0x04: Flash address to be erased (in 32-bit system address format)
     * For example if you want to erase second page then you need to provide
     * 32-bit system address of any of the byte lying in second page */
    result = WriteIO(SROMAPI_SRAM_SCRATCH_ADDR + 0x04 , addr);
    RETURN_IF_FAILED(result);
		LOG("\r\n=> => Phase 2 %d\r\n",result);

    result = CallSromApi(SROMAPI_ERASEROW_CODE, &dataOut);
    return result;
}

/*******************************************************************************
* Function Name: SromApiEraseSector
****************************************************************************//**
*
* Erases FLASH sector, using 'EraseSector' SROM API
* PSOC6 has 4 main FLASH sectors:
* 0x1000_0000, 0x1004_0000, 0x1008_0000, 0x100C_0000
*
* \param addr
* absolute 32-bit flash address in the sector which needs to be erased
*
* \return
* Status
* - RESULT_OK: Sector erased successfully
* - RESULT_ERROR: Sector erasing failed
*
*******************************************************************************/
result_t SromApiEraseSector(uint32_t addr)
{
    result_t result;
    uint32_t dataOut;

    LOG("\r\n=> Func. entered: \"SromApiEraseSector\"\r\n");

    /* SRAM_SCRATCH: OpCode */
    result = WriteIO(SROMAPI_SRAM_SCRATCH_ADDR , SROMAPI_ERASESECTOR_CODE);
    RETURN_IF_FAILED(result);

    /* SRAM_SCRATCH + 0x04:
     * Flash address to be erased (in 32-bit system address format)
     * For example if you want to erase second sector then you need to provide
     * 32-bit system address of any of the byte lying in second sector. */
    result = WriteIO(SROMAPI_SRAM_SCRATCH_ADDR + 0x04 , addr);
    RETURN_IF_FAILED(result);

    result = CallSromApi(SROMAPI_ERASESECTOR_CODE, &dataOut);

    return result;
}

/*******************************************************************************
* Function Name: SromApiProgramRow
****************************************************************************//**
*
* Programs the addressed FLASH page (row).
* Requires the data to be loaded & FLASH address to be programmed
* The FLASH page should be in erased state prior to calling this API.
* The API is implemented in 2 phases to make it non-blocking.
*   The first phase sets up the FLASH for program operation and returns to
*   user code by exiting from NMI without releasing the IPC structure which
*   invoked the API.
*   Now user code/interrupts could be handled but no NMI can be invoked.
* Upon the completion of the program operation interrupt_fm is generated by
*   FLASH macro which will invoke the second phase of ProgramRow API
*   to complete the ongoing program operation successfully.
*   SROM API will return the pass or fail status and releases the IPC structure.
* After FLASH program operation is complete API will optionally compare the
* flash row with the contents in page latch for data integrity check.
* Returns STATUS_PL_ROW_COMP_FA if data integrity check fails.
*
* \param addr
* absolute 32-bit flash address in the row which needs to be programmed
*
* \param data
* data to be programmed
*
* \return
* Status
* - RESULT_OK: Row programmed successfully
* - RESULT_ERROR: Row programming failed
*
*******************************************************************************/
result_t SromApiProgramRow(uint32_t addr, char const *data)
{
    result_t result;
    uint32_t dataOut;
    uint32_t params;

    LOG("\r\n=> Func. entered: \"SromApiProgramRow\"\r\n");

    /* SRAM_SCRATCH: OpCode */
    result = WriteIO(SROMAPI_SRAM_SCRATCH_ADDR , SROMAPI_PROGRAMROW_CODE);
    RETURN_IF_FAILED(result);

    /* Set parameters for SROM API */
    params =
        (6 << 0) +   // Data size: 6 - 512b
        (1 << 8) +   // Data location: 1 - SRAM
        (0 << 16) +  // Verify row: 0 - Data integrity check is not performed
        (0 << 24);   // Not used

    /* SRAM_SCRATCH + 0x04: Data location/size and Integrity check
     * ---
     * Bits[31:24]	Bits[23:16]		Bits[15:8]		Bits[7:0]
     * xxxxxxxx		Verify row		Data location	Data size
     * ---
     * Verify row: 0-Data integrity check is not performed 1-Data integrity check is performed
     * Data location : 0 – page latch , 1- SRAM
     * Data size* – 0 – 8b ,1-16b , 2 -32b ,3 – 64b , 4 – 128b , 5 – 256 b , 6 – 512b , 7)
     * *Data size is ignored for S40 SONOS FLASH as the lowest granularity for program operation equals page size. */
    result = WriteIO(SROMAPI_SRAM_SCRATCH_ADDR + 0x04 , params);
    RETURN_IF_FAILED(result);

    /* SRAM_SCRATCH + 0x08:
     * Flash address to be programmed (in 32-bit system address format) */
    result = WriteIO(SROMAPI_SRAM_SCRATCH_ADDR + 0x08 , addr);
    RETURN_IF_FAILED(result);

	/* SRAM_SCRATCH + 0x0C: Pointer to the first data byte location */
    result = WriteIO(SROMAPI_SRAM_SCRATCH_ADDR + 0x0C, (uint32_t)data);
    RETURN_IF_FAILED(result);

    /* Call SROM API */
    result = CallSromApi(SROMAPI_PROGRAMROW_CODE, &dataOut);
    return result;
}

/*******************************************************************************
* Function Name: SromApiWriteRow
****************************************************************************//**
*
* Programs the addressed FLASH page (row).
*	WriteRow performs pre-program, erase & then programs the FLASH page with contents provided in SRAM.
*	The s40flash IP (SONOS) supports Read While Write (RWW) feature which allows FLASH to be read from a RWW sector
*	which is not getting programmed/erased during a program/erase of other RWW sector.
*	The API is implemented in 3 phases to make it non-blocking.
*	- The first phase sets up the FLASH for pre-program & erase operation and returns to user code by exiting from NMI
*	  without releasing the IPC structure which invoked the API. Now user code/interrupts could be handled but no NMI can be invoked.
*	- Upon the completion of the erase HV pulse interrupt_fm is generated by FLASH macro which will invoke the second phase
*	  of WriteRow API to complete the ongoing erase operation successfully and start the program operation.
*	  API returns from NMI to user code after it sets up for program operation.
*	- Upon the completion of the program HV pulse interrupt_fm is generated by FLASH macro which will invoke the third phase
*	  of WriteRow API to complete the ongoing program operation successfully which completes WriteRow API.
*	  SROM API will now return the pass or fail status and releases the IPC structure.
*	API returns invalid address error status if called on wounded FLASH.
*	API returns fail status if user does not have write access to FLASH as per SMPU settings.
*	After FLASH program operation is complete API will optionally compare the flash row with the contents in page latch for
*	data integrity check. Returns STATUS_PL_ROW_COMP_FA if data integrity check fails.
*
* \param addr
* absolute 32-bit flash address in the row which needs to be programmed
*
* \param data
* data to be programmed
*
* \return
* Status
* - RESULT_OK: Row programmed successfully
* - RESULT_ERROR: Row programming failed
*
*******************************************************************************/
result_t SromApiWriteRow(uint32_t addr, char const *data)
{
    result_t result;
    uint32_t dataOut;
    uint32_t params;

    /* SRAM_SCRATCH: OpCode */
    result = WriteIO(SROMAPI_SRAM_SCRATCH_ADDR , SROMAPI_WRITEROW_CODE);
    RETURN_IF_FAILED(result);

    /* Set parameters for SROM API */
    params =
        (6 << 0) +   // Data size: 6 - 512b
        (1 << 8) +   // Data location: 1 - SRAM
        (0 << 16) +  // Verify row: 0 - Data integrity check is not performed
        (0 << 24);   // Not used

    /* SRAM_SCRATCH + 0x04: Data location/size and Integrity check
     * ---
     * Bits[31:24]	Bits[23:16]		Bits[15:8]		Bits[7:0]
     * xxxxxxxx		Verify row		Data location	Data size
     * ---
     * Verify row: 0-Data integrity check is not performed 1-Data integrity check is performed
     * Data location : 0 – page latch , 1- SRAM
     * Data size* – 0 – 8b ,1-16b , 2 -32b ,3 – 64b , 4 – 128b , 5 – 256 b , 6 – 512b , 7)
     * *Data size is ignored for S40 SONOS FLASH as the lowest granularity for program operation equals page size */
    result = WriteIO(SROMAPI_SRAM_SCRATCH_ADDR + 0x04 , params);
    RETURN_IF_FAILED(result);

    /* SRAM_SCRATCH + 0x08:
     * Flash address to be programmed (in 32-bit system address format) */
    result = WriteIO(SROMAPI_SRAM_SCRATCH_ADDR + 0x08 , addr);
    RETURN_IF_FAILED(result);

	/* SRAM_SCRATCH + 0x0C: Pointer to the first data byte location */
    result = WriteIO(SROMAPI_SRAM_SCRATCH_ADDR + 0x0C, (uint32_t)data);
    RETURN_IF_FAILED(result);

    /* Call SROM API */
    result = CallSromApi(SROMAPI_WRITEROW_CODE, &dataOut);
    return result;
}

#endif /* BUILD_ENABLE_LOADER_FLASH */
