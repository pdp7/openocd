/*******************************************************************************
 * \file cy_loader_smif.c
 * \version 1.0
 *
 * \brief
 *  Implements SMIF Loader APIs.
 *
 ********************************************************************************
 * \copyright
 * Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
 * You may use this file only in accordance with the license, terms, conditions,
 * disclaimers, and limitations in the end user license agreement accompanying
 * the software package with which this file was provided.
 *******************************************************************************/

#include "cy_loader_smif.h"

#if defined(BUILD_ENABLE_LOADER_SMIF)

SMIF_Type *SMIF_Block = (SMIF_Type *)SMIF0_BASE;      /* SMIF Block address                      */
cy_stc_smif_config_t *InitializedSMIFConfig = NULL;   /* Last time initialized SMIF block config */
cy_stc_smif_block_config_t *SMIF_Block_Config = NULL; /* SMIF block config structure */
cy_stc_smif_context_t SMIF_Context = {
	.txBufferAddress = NULL,
	.txBufferSize = 1,
	.txBufferCounter = 0,
	.rxBufferAddress = NULL,
	.rxBufferSize = 1,
	.rxBufferCounter = 0,
	.transferStatus = 0,
	.txCmpltCb = NULL,
	.rxCmpltCb = NULL,
	.timeout = 0,
};                               /* Allocate the SMIF transfer parameters.  */
bool isSMIFStructLoaded = false; /* Is SMIF structures loaded               */

cy_stc_smif_config_t SMIF_Config_NORMAL = /* SMIF configuration parameters */
	{
		.mode = CY_SMIF_NORMAL,               /* Normal (Erase/Program) Mode of operation */
		.deselectDelay = SMIF_DESELECT_DELAY, /* Minimum duration of SPI deselection */
		.rxClockSel = SMIF_RX_CLOCK_SELECT,   /* Clock source for the receiver clock */
		.blockEvent = SMIF_AHB_BUS_ERROR,     /* What happens when there is a read
											   * from an empty RX FIFO or write to a full TX FIFO */
};

cy_stc_smif_config_t SMIF_Config_MEMORY = /* SMIF configuration parameters */
	{
		.mode = CY_SMIF_MEMORY,               /* Memory (XIP) mode of operation */
		.deselectDelay = SMIF_DESELECT_DELAY, /* Minimum duration of SPI deselection */
		.rxClockSel = SMIF_RX_CLOCK_SELECT,   /* Clock source for the receiver clock */
		.blockEvent = SMIF_AHB_BUS_ERROR,     /* What happens when there is a read
											   * from an empty RX FIFO or write to a full TX FIFO */
};

/*******************************************************************************
 * Function Name: ExtMemInterrupt
 ********************************************************************************
 *
 * The ISR for the SMIF interrupt. All Read/Write transfers to/from the external
 * memory are processed inside the SMIF ISR.
 *
 *******************************************************************************/
void ExtMemInterrupt(void) { Cy_SMIF_Interrupt(SMIF_Block, &SMIF_Context); }

/*******************************************************************************
 * Function Name: Loader_SMIF_LoadStructFromFlash
 ********************************************************************************
 *
 * Loads SMIF configuration structures from internal Flash memory
 *
 * \param forceUpdate
 * Force update the structures even if they have been loaded in past
 *
 * \return
 * Status
 * - RESULT_OK: Loaded successfully
 * - RESULT_ERROR: Loading failed
 *
 *******************************************************************************/
result_t Loader_SMIF_LoadStructFromFlash(bool forceUpdate) {
	uint32_t result = RESULT_ERROR;
	uint32_t *smifPointerInTocAddr = NULL;

#ifdef DEBUG_LOG
	const char *logFuncName = "Loader_SMIF_LoadStructFromFlash";
	LOG_FUNC_START(logFuncName);
	LOG(" | Force update           : 0x%02X\r\n", (unsigned int)forceUpdate);
#endif

	/* Do not load structures again if already loaded */
	if (isSMIFStructLoaded && !forceUpdate) {
#ifdef DEBUG_LOG
		LOG("   Skipped: already loaded\r\n");
		LOG_FUNC_END(logFuncName, RESULT_ERROR_OK);
#endif

		result = RESULT_ERROR_OK;
	}

	if (result != RESULT_ERROR_OK) {
		isSMIFStructLoaded = false;

		smifPointerInTocAddr = (uint32_t *)(TARGET_TOC_ADDR + SMIF_CONF_TABLE_OFFS_IN_TOC);
		smifPointerInTocAddr = (uint32_t *)*smifPointerInTocAddr;

#ifdef DEBUG_LOG
		LOG(" | TOC address            : 0x%08X\r\n", (unsigned int)TARGET_TOC_ADDR);
		LOG(" | SMIF offset in TOC     : 0x%08X\r\n", (unsigned int)SMIF_CONF_TABLE_OFFS_IN_TOC);
		LOG(" | SMIF config address    : 0x%08X\r\n", (unsigned int)*smifPointerInTocAddr);
#endif

		result = RESULT_OK;

		/* Check whether SMIF pointer in TOC has valid address*/
		if ((*smifPointerInTocAddr == 0x00000000) || (*smifPointerInTocAddr == 0xFFFFFFFF) ||
			(*smifPointerInTocAddr < TARGET_FLASH_ADDR)) {
#ifdef DEBUG_LOG
			LOG("   E! TOC contains invalid pointer to SMIF configuration structure.\r\n");
			LOG_FUNC_END(logFuncName, RESULT_ERROR);
#endif

			result = RESULT_ERROR;
		}
	}

	if ((result != RESULT_ERROR) && (result != RESULT_ERROR_OK)) {
		SMIF_Block_Config = (cy_stc_smif_block_config_t *)(*smifPointerInTocAddr);
		isSMIFStructLoaded = true;

#ifdef DEBUG_LOG
		LOG(" | SMIF config values       ->\r\n");
		LOG("   | Driver version       : 0x%04X.0x%04X\r\n", SMIF_Block_Config->majorVersion,
			SMIF_Block_Config->minorVersion);
		LOG("   | Mem. configs count   : 0x%08X\r\n", (unsigned int)SMIF_Block_Config->memCount);
		LOG("   | Mem. configs array   : [0x%08X]\r\n", (unsigned int)*SMIF_Block_Config->memConfig);
		for (uint16_t i = 0; i < SMIF_Block_Config->memCount; i++) {
			LOG("   | MemConfig[0x%04X]      ->\r\n", i);
			cy_stc_smif_mem_config_t *memConfig = SMIF_Block_Config->memConfig[i];
			LOG("   | baseAddress          : 0x%08X\r\n", (unsigned int)memConfig->baseAddress);
			LOG("   | memMappedSize        : 0x%08X\r\n", (unsigned int)memConfig->memMappedSize);
			LOG("   | slaveSelect          : 0x%08X\r\n", (unsigned int)memConfig->slaveSelect);
			LOG("   | flags                : 0x%08X\r\n", (unsigned int)memConfig->flags);
			LOG("   | dataSelect           : 0x%08X\r\n", (unsigned int)memConfig->dataSelect);
			LOG("   | dualQuadEnable       : 0x%08X\r\n", (unsigned int)memConfig->dualQuadSlots);
			LOG("   | deviceCfg [0x%08X] ->\r\n", (unsigned int)memConfig->deviceCfg);
			cy_stc_smif_mem_device_cfg_t *deviceCfg = memConfig->deviceCfg;
			LOG("     | memSize            : 0x%08X\r\n", (unsigned int)deviceCfg->memSize);
			LOG("     | eraseSize          : 0x%08X\r\n", (unsigned int)deviceCfg->eraseSize);
			LOG("     | programSize        : 0x%08X\r\n", (unsigned int)deviceCfg->programSize);
			LOG("     | numOfAddrBytes     : 0x%08X\r\n", (unsigned int)deviceCfg->numOfAddrBytes);
		}
		LOG_FUNC_END(logFuncName, RESULT_OK);
		result = RESULT_OK;
#endif
	}

	if (result == RESULT_ERROR_OK) {
		result = RESULT_OK;
	}

	return (result);
}

/*******************************************************************************
 * Function Name: Loader_SMIF_FindMemDeviceByAddr
 ********************************************************************************
 *
 * Search for memory configuration structures by provided XIP mapped address.
 * Pointer smifMemDeviceConfig contains device config if the address was
 * found.
 *
 * \param addr
 * Address inside XIP address space, where memory is mapped
 *
 * \param smifMemConfig
 * SMIF memory device (Slot) configuration structure
 *
 * \param smifMemDeviceConfig
 * Pointer to memory device configuration structure to be set, if address was
 * found.
 *
 * \return
 * Status
 * - RESULT_OK: Found
 * - RESULT_ERROR: Not found
 *
 *******************************************************************************/
result_t Loader_SMIF_FindMemDeviceByAddr(uint32_t addr, cy_stc_smif_mem_config_t **smifMemConfig,
										 cy_stc_smif_mem_device_cfg_t **smifMemDeviceConfig) {
	bool foundMemDevice = false;

#ifdef DEBUG_LOG
	const char *logFuncName = "Loader_SMIF_FindMemDeviceByAddr";
	LOG_FUNC_START(logFuncName);
	LOG(" | addr                   : 0x%02X\r\n", (unsigned int)addr);
#endif

	/* Load SMIF configuration structures if not yet loaded*/
	uint32_t result = Loader_SMIF_LoadStructFromFlash(false);

	if (result != RESULT_OK) {
#ifdef DEBUG_LOG
		LOG_FUNC_END(logFuncName, result);
#endif

		result = RESULT_ERROR;
	}

	if (result != RESULT_ERROR) {
		/* Find SMIF memory configuration structure by XIP address */
		result = RESULT_ERROR;
		uint16_t memCount = SMIF_Block_Config->memCount;
		for (int memIdx = 0; memIdx < memCount; memIdx++) {
			if (SMIF_Block_Config->memConfig[memIdx] != NULL) {
				*smifMemConfig = SMIF_Block_Config->memConfig[memIdx];
				if ((((*smifMemConfig)->flags) & CY_SMIF_FLAG_MEMORY_MAPPED) != 0) {
					if ((addr >= (*smifMemConfig)->baseAddress) &&
						(addr < ((*smifMemConfig)->baseAddress + (*smifMemConfig)->memMappedSize))) {
						*smifMemDeviceConfig = (*smifMemConfig)->deviceCfg;
						foundMemDevice = true;
						break;
					}
				}
			}
		}
	}

	result = foundMemDevice ? RESULT_OK : RESULT_ERROR;

	LOG_FUNC_END(logFuncName, result);

	return (result);
}

/*******************************************************************************
 * Function Name: Loader_SMIF_Init
 ********************************************************************************
 *
 * Initialize SMIF block
 *
 * \param smifConfig
 * SMIF configuration
 *
 * \param forceInit
 * Force re-initialization even if was initialized before
 *
 * \return
 * Status
 * - RESULT_OK: Initialized successfully
 * - RESULT_ERROR: Not initialized
 *
 *******************************************************************************/
result_t Loader_SMIF_Init(cy_stc_smif_config_t smifConfig, bool forceInit) {
#ifdef DEBUG_LOG
	const char *logFuncName = "Loader_SMIF_Init";
	LOG_FUNC_START(logFuncName);
	LOG(" | forceInit              : 0x%08X\r\n", (unsigned int)forceInit);
	LOG(" | SMIF config              ->\r\n");
	LOG("   | mode                 : 0x%08X\r\n", (unsigned int)smifConfig.mode);
	LOG("   | blockEvent           : 0x%08X\r\n", (unsigned int)smifConfig.blockEvent);
	LOG("   | deselectDelay        : 0x%08X\r\n", (unsigned int)smifConfig.deselectDelay);
	LOG("   | rxClockSel           : 0x%08X\r\n", (unsigned int)smifConfig.rxClockSel);
#endif

	result_t result = RESULT_OK;
	result_smif_t smifResult = CY_SMIF_SUCCESS;
	/* Do not re-initialize SMIF block if it is already initialized with the same config */
	if ((!forceInit) && (NULL != InitializedSMIFConfig) && (InitializedSMIFConfig == &smifConfig)) {
#ifdef DEBUG_LOG
		LOG("   Skipped: already initialized\r\n");
		LOG_FUNC_END(logFuncName, result);
#endif

		result = RESULT_ERROR_OK;
	}

	if ((result != RESULT_ERROR) && (result != RESULT_ERROR_OK)) {
		InitializedSMIFConfig = NULL;

		/* Load SMIF configuration structures if not yet loaded */
		result = Loader_SMIF_LoadStructFromFlash(forceInit);
	}

	if ((result != RESULT_ERROR) && (result != RESULT_ERROR_OK)) {
		/* Initialize SMIF communication block */
		smifResult = Cy_SMIF_Init(SMIF_Block, &smifConfig, SMIF_DRIVER_TIMEOUT, &SMIF_Context);
	}

	if ((smifResult == CY_SMIF_SUCCESS) && ((result != RESULT_ERROR) && (result != RESULT_ERROR_OK))) {
		smifResult = Cy_SMIF_Memslot_Init(SMIF_Block, SMIF_Block_Config, &SMIF_Context);
	} else {
		if (result != RESULT_ERROR_OK) {
			result = RESULT_ERROR;
		}
	}

	if ((smifResult == CY_SMIF_SUCCESS) && ((result != RESULT_ERROR) && (result != RESULT_ERROR_OK))) {
		Cy_SMIF_Enable(SMIF_Block, &SMIF_Context);

		uint16_t memCount = SMIF_Block_Config->memCount;
		for (int memIdx = 0; memIdx < memCount; memIdx++) {
			if (SMIF_Block_Config->memConfig[memIdx] != NULL) {
				if (SMIF_Block_Config->memConfig[memIdx]->deviceCfg->stsRegQuadEnableMask != 0) {
					smifResult =
						Cy_SMIF_Memslot_CmdWriteEnable(SMIF_Block, SMIF_Block_Config->memConfig[memIdx], &SMIF_Context);
					if (smifResult == CY_SMIF_SUCCESS) {
						Cy_SMIF_Memslot_QuadEnable(SMIF_Block, SMIF_Block_Config->memConfig[memIdx], &SMIF_Context);
					}
				}
			}
		}

		InitializedSMIFConfig = &smifConfig;

		LOG_FUNC_END(logFuncName, RESULT_OK);
		result = RESULT_OK;
	}

	if (result == RESULT_ERROR_OK) {
		result = RESULT_OK;
	}

	return (result);
}

/*******************************************************************************
 * Function Name: Loader_SMIF_WaitForDevice
 ********************************************************************************
 *
 * Checks the status of the transfer.
 *
 * \param smifMemConfig
 * SMIF memory device configuration structure
 *
 * \param timeoutAttempts
 * Timeout
 *
 * \return
 * Status
 * - RESULT_OK: Device is not busy
 * - RESULT_ERROR: Device is busy
 *
 *******************************************************************************/
result_t Loader_SMIF_WaitForDevice(cy_stc_smif_mem_config_t *smifMemConfig, int timeoutAttempts) {
	bool isBusy;
	int attemptsElapsed = 0;
	cy_stc_smif_mem_config_t *smifMemConfigSecondDev = NULL;
	uint32_t result = RESULT_OK;

	/* Wait while data is transmitted */
	do {
		isBusy = Cy_SMIF_Memslot_IsBusy(SMIF_Block, smifMemConfig, &SMIF_Context);
		if (((*smifMemConfig).dualQuadSlots != 0) && (!isBusy)) {
			Loader_SMIF_FindSecondDevice(&smifMemConfigSecondDev, (*smifMemConfig).dualQuadSlots);
			isBusy = Cy_SMIF_Memslot_IsBusy(SMIF_Block, smifMemConfigSecondDev, &SMIF_Context);
		}
		if (isBusy) {
			/* Check for timeoutAttempts */
			if (attemptsElapsed > timeoutAttempts) {
				result = RESULT_ERROR;

				break;
			}

			Cy_SysLib_DelayUs(SMIF_POLLING_DELAY);
			attemptsElapsed++;
		}
	} while (isBusy);

	return (result);
}

/*******************************************************************************
 * Function Name: Loader_SMIF_Erase
 ********************************************************************************
 *
 * Erases block of SMIF memory
 *
 * \param blockAddr
 * Absolute address in target block
 *
 * \blockSize
 * Size of block to be erased
 *
 * \return
 * Status
 * - RESULT_OK: Erased successfully
 * - RESULT_ERROR: Erasing failed
 *
 *******************************************************************************/
result_t Loader_SMIF_Erase(uint32_t blockAddr, uint32_t blockSize) {
	result_t result = RESULT_OK;
	result_smif_t smifResult;
	uint8_t status = 0;

#ifdef DEBUG_LOG
	const char *logFuncName = "Loader_SMIF_Erase";
	LOG_FUNC_START(logFuncName);
	LOG(" | blockAddr              : 0x%08X\r\n", (unsigned int)blockAddr);
	LOG(" | blockSize              : 0x%08X\r\n", (unsigned int)blockSize);
#endif

	/* Find SMIF memory configuration structures by address */
	uint32_t xipAddr = blockAddr;
	uint32_t isDualMember = 0;
	cy_stc_smif_mem_config_t *smifMemConfig = NULL;
	cy_stc_smif_mem_config_t *smifMemConfigSecondDev = NULL;
	cy_stc_smif_mem_device_cfg_t *smifMemDeviceConfig = NULL;
	result = Loader_SMIF_FindMemDeviceByAddr(xipAddr, &smifMemConfig, &smifMemDeviceConfig);

	if (result == RESULT_OK) {
		/* Save Dual quad second member */
		if (smifMemConfig->dualQuadSlots != 0) {
			isDualMember = smifMemConfig->dualQuadSlots;
			result = Loader_SMIF_FindSecondDevice(&smifMemConfigSecondDev, smifMemConfig->dualQuadSlots);
		}
	}

	if (result == RESULT_OK) {
		/* Initialize SMIF block if not initialized yet */
		result = Loader_SMIF_Init(SMIF_Config_NORMAL, false);
	}

	/* Determine size for portions of data*/
	uint32_t remainedSize = blockSize;
	uint32_t segmentSize = smifMemDeviceConfig->eraseSize;

	/* Determine addresses for input buffer and for target memory */
	uint32_t startAddr = blockAddr - smifMemConfig->baseAddress;
	uint32_t currentAddr = startAddr;

	if (result == RESULT_OK) {
		/* Wait while memory device is busy */
		result = Loader_SMIF_WaitForDevice(smifMemConfig, SMIF_ERASE_TIMEOUT);
	}

	if (result == RESULT_OK) {
		/* Erase data by segments */
		while (remainedSize > 0u) {
			uint8_t addressInFlash[4] = {0, 0, 0, 0};
			if (smifMemConfig->deviceCfg->numOfAddrBytes == 1) {
				addressInFlash[0] = (currentAddr)&0xFF;
			} else if (smifMemConfig->deviceCfg->numOfAddrBytes == 2) {
				addressInFlash[1] = (currentAddr)&0xFF;
				addressInFlash[0] = (currentAddr >> 8) & 0xFF;
			} else if (smifMemConfig->deviceCfg->numOfAddrBytes == 3) {
				addressInFlash[2] = (currentAddr)&0xFF;
				addressInFlash[1] = (currentAddr >> 8) & 0xFF;
				addressInFlash[0] = (currentAddr >> 16) & 0xFF;
			} else if (smifMemConfig->deviceCfg->numOfAddrBytes == 4) {
				addressInFlash[3] = (currentAddr)&0xFF;
				addressInFlash[2] = (currentAddr >> 8) & 0xFF;
				addressInFlash[1] = (currentAddr >> 16) & 0xFF;
				addressInFlash[0] = (currentAddr >> 24) & 0xFF;
			}

#if defined(BUILD_ENABLE_LEDS)
			/* Blink LED to catch the period of each loop*/
			Cy_GPIO_Inv(LED_Status0_0);
#endif

#ifdef DEBUG_LOG
			LOG("   | erasing sector: [currentAddr=0x%08X, segmentSize=0x%08X]\r\n", (unsigned int)currentAddr,
				(unsigned int)segmentSize);
#endif

			/* Enable memory write */
			smifResult = Cy_SMIF_Memslot_CmdWriteEnable(SMIF_Block, smifMemConfig, &SMIF_Context);
			if (smifResult != CY_SMIF_SUCCESS) {
				result = RESULT_ERROR;
				break;
			}

			if (isDualMember != 0) {
				/* Enable memory write */
				smifResult = Cy_SMIF_Memslot_CmdWriteEnable(SMIF_Block, smifMemConfigSecondDev, &SMIF_Context);
				if (smifResult != CY_SMIF_SUCCESS) {
					result = RESULT_ERROR;
					break;
				}
			}

			/* Erase current segment */
			if (remainedSize < segmentSize) {
				segmentSize = remainedSize;
			}

			smifResult = Cy_SMIF_Memslot_CmdSectorErase(SMIF_Block, smifMemConfig, addressInFlash, &SMIF_Context);
			if (smifResult != CY_SMIF_SUCCESS) {
				result = RESULT_ERROR;
				break;
			}

			if (isDualMember != 0) {
				smifResult =
					Cy_SMIF_Memslot_CmdSectorErase(SMIF_Block, smifMemConfigSecondDev, addressInFlash, &SMIF_Context);

				if (smifResult != CY_SMIF_SUCCESS) {
					result = RESULT_ERROR;
					break;
				}
			}

			/* Wait while memory device is busy */
			do {
				while (Cy_SMIF_BusyCheck(SMIF_Block)) {
				}
				smifResult =
					Cy_SMIF_TransmitCommand(SMIF_Block, smifMemConfig->deviceCfg->readStsRegWipCmd->command,
											CY_SMIF_WIDTH_SINGLE, CY_SMIF_CMD_WITHOUT_PARAM, CY_SMIF_CMD_WITHOUT_PARAM,
											(cy_en_smif_txfr_width_t)CY_SMIF_CMD_WITHOUT_PARAM,
											smifMemConfig->slaveSelect, CY_SMIF_TX_NOT_LAST_BYTE, &SMIF_Context);

				/* Enter the receiving mode */
				SMIF_Block->TX_CMD_FIFO_WR =
					_VAL2FLD(CY_SMIF_CMD_FIFO_WR_MODE, CY_SMIF_CMD_FIFO_RX_COUNT_MODE) |
					_VAL2FLD(CY_SMIF_CMD_FIFO_WR_WIDTH, (uint32_t)CY_SMIF_WIDTH_SINGLE) |
					_VAL2FLD(CY_SMIF_CMD_FIFO_WR_RX_COUNT, ((uint32_t)(CY_SMIF_READ_ONE_BYTE - 1U)));

				while (SMIF_Block->RX_DATA_FIFO_STATUS == 0) {
				}
				status = SMIF_Block->RX_DATA_FIFO_RD1;
				Cy_SysLib_DelayUs(SMIF_POLLING_DELAY);
			} while ((status & smifMemConfig->deviceCfg->stsRegBusyMask) != 0);

			if (isDualMember != 0) {
				/* Wait while memory device is busy */
				do {
					while (Cy_SMIF_BusyCheck(SMIF_Block)) {
					}
					smifResult = Cy_SMIF_TransmitCommand(
						SMIF_Block, smifMemConfigSecondDev->deviceCfg->readStsRegWipCmd->command, CY_SMIF_WIDTH_SINGLE,
						CY_SMIF_CMD_WITHOUT_PARAM, CY_SMIF_CMD_WITHOUT_PARAM,
						(cy_en_smif_txfr_width_t)CY_SMIF_CMD_WITHOUT_PARAM, smifMemConfigSecondDev->slaveSelect,
						CY_SMIF_TX_NOT_LAST_BYTE, &SMIF_Context);

					/* Enter the receiving mode */
					SMIF_Block->TX_CMD_FIFO_WR =
						_VAL2FLD(CY_SMIF_CMD_FIFO_WR_MODE, CY_SMIF_CMD_FIFO_RX_COUNT_MODE) |
						_VAL2FLD(CY_SMIF_CMD_FIFO_WR_WIDTH, (uint32_t)CY_SMIF_WIDTH_SINGLE) |
						_VAL2FLD(CY_SMIF_CMD_FIFO_WR_RX_COUNT, ((uint32_t)(CY_SMIF_READ_ONE_BYTE - 1U)));

					while (SMIF_Block->RX_DATA_FIFO_STATUS == 0) {
					}
					status = SMIF_Block->RX_DATA_FIFO_RD1;
					Cy_SysLib_DelayUs(SMIF_POLLING_DELAY);
				} while ((status & smifMemConfigSecondDev->deviceCfg->stsRegBusyMask) != 0);
			}

			result = Loader_SMIF_WaitForDevice(smifMemConfig, SMIF_ERASE_TIMEOUT);
			if (result != RESULT_OK) {
				break;
			}

			remainedSize -= segmentSize;
			currentAddr += segmentSize;
		}
	}

#ifdef DEBUG_LOG
	LOG_FUNC_END(logFuncName, result);
#endif

	return (result);
}

/*******************************************************************************
 * Function Name: Loader_SMIF_Program
 ********************************************************************************
 *
 * Program page in XIP mapped memory
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
result_t Loader_SMIF_Program(uint32_t blockAddr, uint32_t offsetInBlock, uint8_t *buffer, uint32_t size) {
	result_t result = RESULT_OK;
	result_smif_t smifResult;
	uint8_t status = 0;

#ifdef DEBUG_LOG
	const char *logFuncName = "Loader_SMIF_Program";
	LOG_FUNC_START(logFuncName);
	LOG(" | blockAddr              : 0x%08X\r\n", (unsigned int)blockAddr);
	LOG(" | offsetInBlock          : 0x%08X\r\n", (unsigned int)offsetInBlock);
	LOG(" | buffer                 : 0x%08X\r\n", (unsigned int)buffer);
	LOG(" | size                   : 0x%08X\r\n", (unsigned int)size);
#endif

	/* Find SMIF memory configuration structures by address */
	uint32_t xipAddr = blockAddr + offsetInBlock;
	cy_stc_smif_mem_config_t *smifMemConfig = NULL;
	uint32_t isDualMember = 0;
	cy_stc_smif_mem_config_t *smifMemConfigSecondDev = NULL;
	cy_stc_smif_mem_device_cfg_t *smifMemDeviceConfig = NULL;
	result = Loader_SMIF_FindMemDeviceByAddr(xipAddr, &smifMemConfig, &smifMemDeviceConfig);
	if (result == RESULT_OK) {
		/* Save Dual quad second member */
		if (smifMemConfig->dualQuadSlots != 0) {
			isDualMember = smifMemConfig->dualQuadSlots;
			result = Loader_SMIF_FindSecondDevice(&smifMemConfigSecondDev, smifMemConfig->dualQuadSlots);
		}
	}
	if (result != RESULT_ERROR) {
		/* Initialize SMIF block if not initialized yet */
		result = Loader_SMIF_Init(SMIF_Config_NORMAL, true);
	}

	/* Determine size for portions of data*/
	uint32_t remainedSize = size;
	uint32_t segmentSize = smifMemDeviceConfig->programSize;

	/* Determine addresses for input buffer and for target memory */
	uint32_t startAddr = blockAddr - smifMemConfig->baseAddress + offsetInBlock;
	uint32_t currentAddr = startAddr;
	uint32_t offsetInBuffer = 0;

	if (result != RESULT_ERROR) {
		/* Wait while memory device is busy */
		result = Loader_SMIF_WaitForDevice(smifMemConfig, SMIF_PROGRAM_TIMEOUT);
	}

	if (result != RESULT_ERROR) {
		/* Write data by segments */
		while (remainedSize > 0) {
			uint8_t addressInFlash[4] = {0, 0, 0, 0};
			if (smifMemConfig->deviceCfg->numOfAddrBytes == 1) {
				addressInFlash[0] = (currentAddr)&0xFF;
			} else if (smifMemConfig->deviceCfg->numOfAddrBytes == 2) {
				addressInFlash[1] = (currentAddr)&0xFF;
				addressInFlash[0] = (currentAddr >> 8) & 0xFF;
			} else if (smifMemConfig->deviceCfg->numOfAddrBytes == 3) {
				addressInFlash[2] = (currentAddr)&0xFF;
				addressInFlash[1] = (currentAddr >> 8) & 0xFF;
				addressInFlash[0] = (currentAddr >> 16) & 0xFF;
			} else if (smifMemConfig->deviceCfg->numOfAddrBytes == 4) {
				addressInFlash[3] = (currentAddr)&0xFF;
				addressInFlash[2] = (currentAddr >> 8) & 0xFF;
				addressInFlash[1] = (currentAddr >> 16) & 0xFF;
				addressInFlash[0] = (currentAddr >> 24) & 0xFF;
			}

#if defined(BUILD_ENABLE_LEDS)
			/* Blink LED to catch the period of each loop*/
			Cy_GPIO_Inv(LED_Status0_0);
#endif

#ifdef DEBUG_LOG
			LOG("   | programming sector: [offsetInBlock=0x%08X, segmentSize=0x%08X, offsetInBuffer=0x%08X]\r\n",
				(unsigned int)offsetInBlock, (unsigned int)segmentSize, (unsigned int)offsetInBuffer);
#endif

			/* Enable memory write */
			smifResult = Cy_SMIF_Memslot_CmdWriteEnable(SMIF_Block, smifMemConfig, &SMIF_Context);
			if (smifResult != CY_SMIF_SUCCESS) {
				result = RESULT_ERROR;
				break;
			}

			if (isDualMember != 0) {
				/* Enable memory write */
				smifResult = Cy_SMIF_Memslot_CmdWriteEnable(SMIF_Block, smifMemConfigSecondDev, &SMIF_Context);
				if (smifResult != CY_SMIF_SUCCESS) {
					result = RESULT_ERROR;
					break;
				}
			}

			if (smifResult != CY_SMIF_SUCCESS) {
				result = RESULT_ERROR;
				break;
			}

			while (Cy_SMIF_BusyCheck(SMIF_Block)) {
			}

			/* Write current portion of data */
			if (remainedSize < segmentSize) {
				segmentSize = remainedSize;
			}

			smifResult = Cy_SMIF_TransmitCommand(
				SMIF_Block, smifMemDeviceConfig->programCmd->command, smifMemDeviceConfig->programCmd->cmdWidth,
				addressInFlash, smifMemDeviceConfig->numOfAddrBytes, smifMemDeviceConfig->programCmd->addrWidth,
				smifMemConfig->slaveSelect, CY_SMIF_TX_NOT_LAST_BYTE, &SMIF_Context);

			if (smifResult != CY_SMIF_SUCCESS) {
				result = RESULT_ERROR;
				break;
			}

			while (Cy_SMIF_GetTxFifoStatus(SMIF_Block) > 0) {
			}

			/* The page program command */
			smifResult = Cy_SMIF_TransmitData(SMIF_Block, NULL, smifMemDeviceConfig->programSize,
											  smifMemDeviceConfig->programCmd->dataWidth, NULL, &SMIF_Context);
			if (smifResult != CY_SMIF_SUCCESS) {
				result = RESULT_ERROR;
				break;
			}

			/* Transfet the data */
			for (uint32_t i = 0; i < smifMemDeviceConfig->programSize; i++) {
				SMIF_Block->TX_DATA_FIFO_WR1 = buffer[offsetInBuffer + i];
				while (Cy_SMIF_GetTxFifoStatus(SMIF_Block) > SMIF_FIFO_THRESHOLD) {
				}
			}

			do {
				while (Cy_SMIF_BusyCheck(SMIF_Block)) {
				}
				smifResult =
					Cy_SMIF_TransmitCommand(SMIF_Block, smifMemConfig->deviceCfg->readStsRegWipCmd->command,
											CY_SMIF_WIDTH_SINGLE, CY_SMIF_CMD_WITHOUT_PARAM, CY_SMIF_CMD_WITHOUT_PARAM,
											(cy_en_smif_txfr_width_t)CY_SMIF_CMD_WITHOUT_PARAM,
											smifMemConfig->slaveSelect, CY_SMIF_TX_NOT_LAST_BYTE, &SMIF_Context);

				/* Enter the receiving mode */
				SMIF_Block->TX_CMD_FIFO_WR =
					_VAL2FLD(CY_SMIF_CMD_FIFO_WR_MODE, CY_SMIF_CMD_FIFO_RX_COUNT_MODE) |
					_VAL2FLD(CY_SMIF_CMD_FIFO_WR_WIDTH, (uint32_t)CY_SMIF_WIDTH_SINGLE) |
					_VAL2FLD(CY_SMIF_CMD_FIFO_WR_RX_COUNT, ((uint32_t)(CY_SMIF_READ_ONE_BYTE - 1U)));

				while (SMIF_Block->RX_DATA_FIFO_STATUS == 0) {
				}
				status = SMIF_Block->RX_DATA_FIFO_RD1;
				Cy_SysLib_DelayUs(SMIF_POLLING_DELAY);
			} while ((status & smifMemConfig->deviceCfg->stsRegBusyMask) != 0);

#ifdef DEBUG_LOG
			LOG("   | programm API call: [blockAddr=0x%08X, &SMIF_Context=0x%08X, smifResult=0x%08X/0x%08X]\r\n",
				(unsigned int)blockAddr, (unsigned int)&SMIF_Context, (unsigned int)smifResult,
				(unsigned int)CY_SMIF_BAD_PARAM);
#endif

			remainedSize -= segmentSize;
			offsetInBuffer += segmentSize;
			currentAddr += segmentSize;
		}
	}
#ifdef DEBUG_LOG
	LOG_FUNC_END(logFuncName, result);
#endif

	return result;
}

/*******************************************************************************
 * Function Name: Loader_SMIF_Verify
 ********************************************************************************
 *
 * Compares data in memory with data in buffer
 * Please note that XIP mode is used for verification.
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
result_t Loader_SMIF_Verify(uint32_t blockAddr, uint32_t blockSize, uint8_t *buffer, uint32_t *lastVerifiedAddr) {
#ifdef DEBUG_LOG
	const char *logFuncName = "Loader_SMIF_Verify";
	LOG_FUNC_START(logFuncName);
	LOG(" | blockAddr              : 0x%08X\r\n", (unsigned int)blockAddr);
	LOG(" | blockSize              : 0x%08X\r\n", (unsigned int)blockSize);
	LOG(" | buffer                 : 0x%08X\r\n", (unsigned int)buffer);
#endif

	uint32_t i;
	result_t result = RESULT_OK;

	/* Initialize SMIF block if not initialized yet */
	result = Loader_SMIF_Init(SMIF_Config_MEMORY, false);

	if (result == RESULT_OK) { /* Read directly from XIP address space */
		unsigned char *chipData = (unsigned char *)blockAddr;

		/* Compare bytes */
		for (i = 0; i < blockSize; i++) {
			if (buffer[i] != chipData[i]) {
				result = RESULT_ERROR;
				break;
			}
		}

		/* success = (adr+size), otherwise = fail */
		*lastVerifiedAddr = blockAddr + i;
	}

#ifdef DEBUG_LOG
	LOG(" | lastVerifiedAddr       : 0x%08X\r\n", (unsigned int)*lastVerifiedAddr);
	LOG_FUNC_END(logFuncName, result);
#endif

	return result;
}

/*******************************************************************************
 * Function Name: Loader_Flash_IsMemoryFilled
 ********************************************************************************
 *
 * Compares data in memory with given value
 * Please note that XIP mode is used for verification.
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
result_t Loader_SMIF_IsMemoryFilled(uint32_t blockAddr, uint32_t blockSize, uint8_t value) {
	uint32_t i;

#ifdef DEBUG_LOG
	const char *logFuncName = "Loader_SMIF_IsMemoryFilled";
	LOG_FUNC_START(logFuncName);
	LOG(" | blockAddr              : 0x%08X\r\n", (unsigned int)blockAddr);
	LOG(" | blockSize              : 0x%08X\r\n", (unsigned int)blockSize);
	LOG(" | value                  : 0x%08X\r\n", (unsigned int)value);
#endif

	/* Initialize SMIF block if not initialized yet */
	result_t result = Loader_SMIF_Init(SMIF_Config_MEMORY, false);

	if (result == RESULT_OK) { /* Read directly from memory */
		unsigned char *chipData = (unsigned char *)blockAddr;

		/* Compare bytes vith given value*/
		for (i = 0; i < blockSize; i++) {
			if (chipData[i] != value) {
				result = RESULT_ERROR;
				break;
			}
		}
	}

#ifdef DEBUG_LOG
	LOG_FUNC_END(logFuncName, result);
#endif

	return (result);
}

/*******************************************************************************
 * Function Name: Loader_SMIF_Init_XIP
 ********************************************************************************
 *
 * Initializes SMIF in XIP mode.
 *
 * \param blockAddr
 * Start of memory block (absolute 32-bit address) to be verified
 *
 * \return
 * Status
 * - RESULT_OK: SMIF is ready for read requests
 * - RESULT_ERROR: Error during initialization
 *
 *******************************************************************************/
result_t Loader_SMIF_Init_XIP(uint32_t blockAddr) {
	result_t result = RESULT_OK;
	uint32_t xipAddr = blockAddr;

#ifdef DEBUG_LOG
	const char *logFuncName = "Loader_SMIF_Init_XIP";
	LOG_FUNC_START(logFuncName);
#endif

	cy_stc_smif_mem_config_t *smifMemConfig = NULL;
	cy_stc_smif_mem_device_cfg_t *smifMemDeviceConfig = NULL;
	result = Loader_SMIF_FindMemDeviceByAddr(xipAddr, &smifMemConfig, &smifMemDeviceConfig);

	if (result == RESULT_OK) {
		result = Loader_SMIF_Init(SMIF_Config_MEMORY, true);
	}

	return (result);
}

/*******************************************************************************
 * Function Name: Loader_SMIF_Deinit
 ********************************************************************************
 *
 * Deinitialises SMIF
 *
 * \return
 * Status
 * - RESULT_OK: SMIF deinitialised
 * - RESULT_ERROR: SMIF is not initialised
 *
 *******************************************************************************/
result_t Loader_SMIF_Deinit(void) {
	result_t result = RESULT_ERROR;

#ifdef DEBUG_LOG
	const char *logFuncName = "Loader_SMIF_Deinit";
	LOG_FUNC_START(logFuncName);
#endif

	if (InitializedSMIFConfig != NULL) {
		Cy_SMIF_DeInit(SMIF_Block);
	}

#ifdef DEBUG_LOG
	LOG_FUNC_END(logFuncName, result);
#endif

	return (result);
}

/*******************************************************************************
 * Function Name: Loader_SMIF_FindSecondDevice
 ********************************************************************************
 *
 * Searches for a second device for dual quad.
 *
 * \param smifMemConfig
 * Pointer to be set
 *
 * \param dualChMask
 * Mask to compare
 *
 * \return
 * Status
 * - RESULT_OK: SMIF deinitialised
 * - RESULT_ERROR: SMIF is not initialised
 *
 *******************************************************************************/
result_t Loader_SMIF_FindSecondDevice(cy_stc_smif_mem_config_t **smifMemConfig, uint32_t dualChMask) {
	cy_stc_smif_mem_config_t *smifMemConfigTest;
	uint32_t result;
	bool foundMemDevice = false;
	bool foundSecondDevice = false;

#ifdef DEBUG_LOG
	const char *logFuncName = "Loader_SMIF_FindSecondDevice";
	LOG_FUNC_START(logFuncName);
	LOG(" | addr                   : 0x%02X\r\n", (unsigned int)addr);
#endif

	/* Load SMIF configuration structures if not yet loaded*/
	result = Loader_SMIF_LoadStructFromFlash(false);

	if (result != RESULT_OK) {
#ifdef DEBUG_LOG
		LOG_FUNC_END(logFuncName, result);
#endif

		result = RESULT_ERROR;
	}

	if (result != RESULT_ERROR) {
		/* Find SMIF memory configuration structure by XIP address */
		uint16_t memCount = SMIF_MAX_SLOT_NUMBER;
		for (int memIdx = 0; memIdx < memCount; memIdx++) {
			if (SMIF_Block_Config->memConfig[memIdx] != NULL) {
				smifMemConfigTest = SMIF_Block_Config->memConfig[memIdx];

				if ((((*smifMemConfig)->flags) & CY_SMIF_FLAG_MEMORY_MAPPED) != 0) {
					if ((dualChMask == (*smifMemConfig)->dualQuadSlots) && (foundMemDevice == true)) {
						*smifMemConfig = smifMemConfigTest;
						foundSecondDevice = true;
						break;
					}

					if (dualChMask == (*smifMemConfig)->dualQuadSlots) {
						foundMemDevice = true;
					}
				}
			}
		}
	}

	result = foundSecondDevice ? RESULT_OK : RESULT_ERROR;

	LOG_FUNC_END(logFuncName, result);

	return (result);
}

#endif /* BUILD_ENABLE_LOADER_SMIF */

/* [] END OF FILE */
