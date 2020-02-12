/***************************************************************************//**
* \file cy_smif_device_common.c
* \version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
*
* Provide common definition for specific external flash drivers.
*
********************************************************************************
* \copyright
* Copyright 2016-2018, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

#include "smif/cy_smif.h"
#include "cy_smif_device_common.h"
#include "string.h"

cy_en_smif_status_t Cy_SMIF_InitExMemContext(cy_en_smif_ex_device_type exDevice, cy_stc_ex_dev_context_t* context)
{

	switch(exDevice)
	{
	case CY_SMIF_S25FL:
		memcpy(&context->pp_readLatencyCodeToDummyCycle, g_s25flReadLatencyCodeToDummyCycle, sizeof(g_s25flReadLatencyCodeToDummyCycle));
		memcpy(&context->pp_writeLatencyCodeToDummyCycle, g_s25flWriteLatencyCodeToDummyCycle, sizeof(g_s25flWriteLatencyCodeToDummyCycle));

		context->p_readCmdTypes                  = (cy_stc_cmd_sq_t*)g_s25flReadCmdTypes;
		context->p_readAddrTypes                 = (cy_stc_addr_sq_t*)g_s25flReadAddrTypes;
		context->p_readModeTypes                 = (cy_stc_mode_sq_t*)g_s25flReadModeTypes;
		context->p_readDummyTypes                = (cy_stc_dummy_sq_t*)g_s25flReadDummyTypes;

		context->p_readDataTypes                 = (cy_stc_data_sq_t*)g_s25flReadDataTypes;
		context->p_readCmdInfo                   = (cy_stc_read_info_t*)g_s25flReadCmdInfo;
		context->readLatencyCodeMax              = CY_SMIF_S25FL_READ_LATENCY_CODE_MAX;
		context->readCommandNum                  = CY_SMIF_S25FL_READ_ID_NUM;

		context->p_writeCmdTypes                 = (cy_stc_cmd_sq_t*)g_s25flWriteCmdTypes;
		context->p_writeAddrTypes                = (cy_stc_addr_sq_t*)g_s25flWriteAddrTypes;
		context->p_writeModeTypes                = (cy_stc_mode_sq_t*)g_s25flWriteModeTypes;
		context->p_writeDummyTypes               = (cy_stc_dummy_sq_t*)g_s25flWriteDummyTypes;

		context->p_writeDataTypes                = (cy_stc_data_sq_t*)g_s25flWriteDataTypes;
		context->p_writeCmdInfo                  = (cy_stc_write_info_t*)g_s25flWriteCmdInfo;
		context->writeLatencyCodeMax             = CY_SMIF_S25FL_WRITE_LATENCY_CODE_MAX;
		context->writeCommandNum                 = CY_SMIF_S25FL_WRITE_ID_NUM;

		context->currentExDevice                 = exDevice;
		break;
	case CY_SMIF_28HL:
		memcpy(&context->pp_readLatencyCodeToDummyCycle, g_s28hReadLatencyCodeToDummyCycle, sizeof(g_s28hReadLatencyCodeToDummyCycle));
		memcpy(&context->pp_writeLatencyCodeToDummyCycle, g_s28hWriteLatencyCodeToDummyCycle, sizeof(g_s28hWriteLatencyCodeToDummyCycle));

		context->p_readCmdTypes                  = (cy_stc_cmd_sq_t*)g_s28hReadCmdTypes;
		context->p_readAddrTypes                 = (cy_stc_addr_sq_t*)g_s28hReadAddrTypes;
		context->p_readModeTypes                 = (cy_stc_mode_sq_t*)g_s28hReadModeTypes;
		context->p_readDummyTypes                = (cy_stc_dummy_sq_t*)g_s28hReadDummyTypes;
		context->p_readDataTypes                 = (cy_stc_data_sq_t*)g_s28hReadDataTypes;
		context->p_readCmdInfo                   = (cy_stc_read_info_t*)g_s28hReadCmdInfo;
		context->readLatencyCodeMax              = CY_SMIF_S28H_READ_LATENCY_CODE_MAX;
		context->readCommandNum                  = CY_SMIF_S28H_READ_ID_NUM;

		context->p_writeCmdTypes                 = (cy_stc_cmd_sq_t*)g_s28hWriteCmdTypes;
		context->p_writeAddrTypes                = (cy_stc_addr_sq_t*)g_s28hWriteAddrTypes;
		context->p_writeModeTypes                = (cy_stc_mode_sq_t*)g_s28hWriteModeTypes;
		context->p_writeDummyTypes               = (cy_stc_dummy_sq_t*)g_s28hWriteDummyTypes;
		context->p_writeDataTypes                = (cy_stc_data_sq_t*)g_s28hWriteDataTypes;
		context->p_writeCmdInfo                  = (cy_stc_write_info_t*)g_s28hWriteCmdInfo;
		context->writeLatencyCodeMax             = CY_SMIF_S28H_WRITE_LATENCY_CODE_MAX;
		context->writeCommandNum                 = CY_SMIF_S28H_WRITE_ID_NUM;

		context->currentExDevice                 = exDevice;
		break;
	default:
		return CY_SMIF_BAD_PARAM;
	}

	return CY_SMIF_SUCCESS;
}

/*******************************************************************************
* Function CY_SMIF_GetAddrByteSizeFromMemSize
****************************************************************************//**
*
* \param size to be checked
*
* \return (see \cy_en_smif_xip_addr_byte_t)
*
*******************************************************************************/
static cy_en_smif_xip_addr_byte_t CY_SMIF_GetAddrByteSizeFromMemSize(uint32_t size)
{
	cy_en_smif_xip_addr_byte_t addressByte;

	if(size >= Cy_SMIF_MaskValueToSizeInByte(CY_SMIF_DEVICE_16M_BYTE))
	{
		addressByte = CY_SMIF_XIP_ADDRESS_4_BYTE;
	}
	else
	{
		addressByte = CY_SMIF_XIP_ADDRESS_3_BYTE;
	}

	return addressByte;
}


/*******************************************************************************
* Function Name: Cy_SMIF_InitSpecificDevice
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_BAD_PARAM
*     - \ref CY_SMIF_SUCCESS
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_InitXIPModeForExMem(volatile stc_SMIF_DEVICE_t *device,
												cy_en_smif_bit_alloc_t bitAllocation,
												const cy_stc_device_config_t *config,
												const cy_stc_ex_dev_context_t* context)
{
	uint32_t startAddress  = config->addr;
	uint32_t maxDeviceSize = (~(CY_SMIF_GetXIP_Mask(device))) + 1UL;
	uint32_t size          = Cy_SMIF_MaskValueToSizeInByte(config->size);
	uint32_t endAddress    = config->addr + size - 1;
	cy_un_smif_bit_alloc_t unBitAllocation   = { .en = bitAllocation };
	cy_en_smif_xip_addr_byte_t addrSize;

	/********************/
	/* Check parameters */
	/********************/
	if(context == NULL)
	{
		return CY_SMIF_BAD_PARAM;
	}

	if((context->p_readCmdInfo == NULL)                  ||
	   (context->p_readCmdTypes == NULL)                 ||
	   (context->p_readAddrTypes == NULL)                ||
	   (context->p_readModeTypes == NULL)                ||
	   (context->p_readDummyTypes == NULL)               ||
	   (context->pp_readLatencyCodeToDummyCycle == NULL)  ||
	   (context->p_readDataTypes == NULL)                ||
	   (context->p_readCmdInfo == NULL)                  ||
	   (context->p_writeCmdInfo == NULL)                 ||
	   (context->p_writeCmdTypes == NULL)                ||
	   (context->p_writeAddrTypes == NULL)               ||
	   (context->p_writeModeTypes == NULL)               ||
	   (context->p_writeDummyTypes == NULL)              ||
	   (context->pp_writeLatencyCodeToDummyCycle == NULL) ||
	   (context->p_writeDataTypes == NULL)               ||
	   (context->p_writeCmdInfo == NULL))
	{
		return CY_SMIF_BAD_PARAM;
	}

	if(startAddress < CY_SMIF_GetXIP_Address(device))
	{
		return CY_SMIF_BAD_PARAM;
	}

	if(endAddress > ((uint32_t)CY_SMIF_GetXIP_Address(device) + maxDeviceSize - 1UL))
	{
		return CY_SMIF_BAD_PARAM;
	}

	{
		cy_en_smif_xip_addr_byte_t readCmdAddrByte  = CY_SMIF_GetAddrLenFromReadCmd(device, config->xipReadCmdId, context);
		cy_en_smif_xip_addr_byte_t writeCmdAddrByte = CY_SMIF_GetAddrLenFromWriteCmd(device, config->xipWriteCmdId, context);
		cy_en_smif_xip_addr_byte_t requiredAddrByte = CY_SMIF_GetAddrByteSizeFromMemSize(size);
		if(readCmdAddrByte < requiredAddrByte)
		{
			return CY_SMIF_BAD_PARAM;
		}

		if(config->writeEn == true)
		{
			if(writeCmdAddrByte < requiredAddrByte)
			{
				return CY_SMIF_BAD_PARAM;
			}

			if(readCmdAddrByte != writeCmdAddrByte)
			{
				return CY_SMIF_BAD_PARAM;
			}
		}

		addrSize = readCmdAddrByte;
	}

	/*********************/
	/*   Set registers   */
	/*********************/
	Cy_SMIF_DeviceSetDataSelect(device, (cy_en_smif_data_select_t)unBitAllocation.bits.dataSel);
	Cy_SMIF_DeviceCryptoDisable(device);

	if(config->mergeTimeoutEnable)
	{
		Cy_SMIF_DeviceTransferMergingEnable(device, config->mergeTimeout);
	}
	else
	{
		Cy_SMIF_DeviceTransferMergingDisable(device);
	}

	if(config->totalTimeoutEnable)
	{
		Cy_SMIF_DeviceTotalTimeoutEnable(device, config->totalTimeout);
	}
	else
	{
		Cy_SMIF_DeviceTotalTimeoutDisable(device);
	}

	Cy_SMIF_SetXIPBaseAddress(device, config->addr);
	Cy_SMIF_SetXIPAddressSize(device, config->size);

	Cy_SMIF_SetXIPAddrCtl(device, addrSize, (bool)unBitAllocation.bits.IsDualQuad);

	CY_SMIF_SetXIPReadSequence(device, config->xipReadCmdId, config->xipReadMode, config->rdLatencyCode, (bool)unBitAllocation.bits.IsDualQuad, context);

	if(config->writeEn == true)
	{
		Cy_SMIF_DeviceWriteEnable(device);
		CY_SMIF_SetXIPWriteSequence(device, config->xipWriteCmdId, config->xipWriteMode, config->wtLatencyCode, (bool)unBitAllocation.bits.IsDualQuad, context);
	}

	Cy_SMIF_DeviceEnable(device);

	return CY_SMIF_SUCCESS;
}

/*******************************************************************************
* Function CY_SMIF_GetReadCmdInfoNum
****************************************************************************//**
*
* \param cmd (see \cy_en_smif_rd_cmd_t)
*
* \return
*  Commad number which is defined and used internally
*
*******************************************************************************/
static uint16_t CY_SMIF_GetReadCmdInfoNum(uint16_t rdCmdId)
{
	return (uint16_t)rdCmdId;
}

static cy_en_smif_xip_addr_byte_t CY_SMIF_GetAddrLenFromReadCmd(volatile stc_SMIF_DEVICE_t *device, uint16_t cmd, const cy_stc_ex_dev_context_t* context)
{
	uint8_t devNum = Cy_SMIF_GetNoOfDevice(device);

	CY_ASSERT_L3(context->p_readAddrTypes != NULL);
	CY_ASSERT_L3(context->p_readCmdInfo != NULL);

	uint8_t readInfoNum = CY_SMIF_GetReadCmdInfoNum(cmd);
	uint8_t addrTypeNum = context->p_readCmdInfo[readInfoNum].addrTypeNum;

	return (context->p_readAddrTypes[addrTypeNum].addrLen);
}

/*******************************************************************************
* Function Name CY_SMIF_DummyCycleEachReadCmd
****************************************************************************//**
*
* \param cmd (see \cy_en_smif_rd_cmd_t)
*
* \param
*
* \return proper dummy cycle for input cmmand and latency code.
*
*******************************************************************************/
static cy_en_smif_field_presence_t CY_SMIF_DummyCycleEachReadCmd(volatile stc_SMIF_DEVICE_t *device, uint16_t cmd, uint8_t latencyCode, uint8_t* dummyCycle, const cy_stc_ex_dev_context_t* context)
{
	uint8_t devNum = Cy_SMIF_GetNoOfDevice(device);

	CY_ASSERT_L3(context->p_readCmdInfo != NULL);
	CY_ASSERT_L3(context->p_readDummyTypes != NULL);
	CY_ASSERT_L3(context->pp_readLatencyCodeToDummyCycle != NULL);
	CY_ASSERT_L3(latencyCode < context->readLatencyCodeMax);

	uint8_t readCmdNum   = CY_SMIF_GetReadCmdInfoNum(cmd);
	uint8_t dummyTypeNum = context->p_readCmdInfo[readCmdNum].dummyTypeNum;
	uint8_t tableId      = context->p_readDummyTypes[dummyTypeNum].tableId;

	//CY_ASSERT_L3(context->pp_readLatencyCodeToDummyCycle[tableId] != NULL);
	*dummyCycle = context->pp_readLatencyCodeToDummyCycle[tableId][latencyCode];

	return (context->p_readDummyTypes[dummyTypeNum].presence);
}

/*******************************************************************************
* Function CY_SMIF_SetXIPReadSequence
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
static void CY_SMIF_SetXIPReadSequence(volatile stc_SMIF_DEVICE_t *device, uint16_t cmd, uint8_t mode, uint8_t latencyCode, bool dualQuad, const cy_stc_ex_dev_context_t* context)
{
	uint8_t devNum = Cy_SMIF_GetNoOfDevice(device);

	CY_ASSERT_L3(context->p_readCmdInfo != NULL);
	CY_ASSERT_L3(context->p_readCmdTypes != NULL);
	CY_ASSERT_L3(context->p_readAddrTypes != NULL);
	CY_ASSERT_L3(context->p_readModeTypes != NULL);
	CY_ASSERT_L3(context->p_readDataTypes != NULL);

	CY_ASSERT_L3(cmd < context->readCommandNum);

	uint8_t readCmdNum = CY_SMIF_GetReadCmdInfoNum(cmd);

	/************************/
	/*** Set read command ***/
	/************************/
	/* Prepare the parameters */
	stc_cy_smif_cmd_mode_ctl_t rdCmdParams;
	uint8_t cmdTypeNum    = context->p_readCmdInfo[readCmdNum].cmdTypeNum;
	rdCmdParams.cmd       = (uint16_t)context->p_readCmdInfo[readCmdNum].cmd;
	rdCmdParams.width     = context->p_readCmdTypes[cmdTypeNum].width;
	rdCmdParams.dataRate  = context->p_readCmdTypes[cmdTypeNum].dataRate;
	rdCmdParams.presence  = context->p_readCmdTypes[cmdTypeNum].presence;
	/* Set the parameters */
	Cy_SMIF_SetReadCmdCtl(device, &rdCmdParams);

	/************************/
	/*** Set read address ***/
	/************************/
	/* Prepare the parameters */
	stc_cy_smif_addr_data_ctl_t rdAddrParams;
	uint8_t addrTypeNum = context->p_readCmdInfo[readCmdNum].addrTypeNum;
	rdAddrParams.width    = context->p_readAddrTypes[addrTypeNum].width;
	rdAddrParams.dataRate = context->p_readAddrTypes[addrTypeNum].dataRate;
	/* Set the parameters */
	Cy_SMIF_SetReadAddrCtl(device, &rdAddrParams);

	/************************/
	/***  Set read mode  ***/
	/************************/
	/* Prepare the parameters */
	stc_cy_smif_cmd_mode_ctl_t rdModeParams;
	uint8_t modeTypeNum = context->p_readCmdInfo[readCmdNum].modeTypeNum;
	rdModeParams.cmd      = mode;
	rdModeParams.width    = context->p_readModeTypes[modeTypeNum].width;
	rdModeParams.dataRate = context->p_readModeTypes[modeTypeNum].dataRate;
	rdModeParams.presence = context->p_readModeTypes[modeTypeNum].presence;
	/* Set the parameters */
	Cy_SMIF_SetReadModeCtl(device, &rdModeParams);

	/************************/
	/***  Set read dummy  ***/
	/************************/
	/* Prepare the parameters */
	stc_cy_smif_rd_dummy_ctl_t rdDummyParams;
	uint8_t dummyCycle;
	rdDummyParams.presence   = CY_SMIF_DummyCycleEachReadCmd(device, cmd, latencyCode, &dummyCycle, context);
	rdDummyParams.numOfDummy = dummyCycle;
	/* Set the parameters */
	Cy_SMIF_SetReadDummyCtl(device, &rdDummyParams);

	/************************/
	/***  Set read data   ***/
	/************************/
	stc_cy_smif_addr_data_ctl_t rdDataParams;
	/* Prepare the parameters */
	uint8_t dataTypeNum = context->p_readCmdInfo[readCmdNum].dataTypeNum;
	rdDataParams.width    = (dualQuad == true) ? CY_SMIF_WIDTH_OCTAL : context->p_readDataTypes[dataTypeNum].width;
	rdDataParams.dataRate = context->p_readDataTypes[dataTypeNum].dataRate;
	/* Set the parameters */
	Cy_SMIF_SetReadDataCtl(device, &rdDataParams);

	/************************/
	/***   Set read CRC   ***/
	/************************/
	/* Prepare the parameters */
	stc_cy_smif_rd_crc_ctl_t rdCRCParams = { 0u };
	/* Set the parameters */
	Cy_SMIF_SetReadCrcCtl(device, &rdCRCParams);

	/************************/
	/***  Set read bound  ***/
	/************************/
	/* Prepare the parameters */
	stc_cy_smif_rd_bound_ctl_t rdBoundParams = { 0u };
	/* Set the parameters */
	Cy_SMIF_SetReadBoundCtl(device, &rdBoundParams);

	return;

}

/*******************************************************************************
* Function CY_SMIF_GetWriteCmdInfoNum
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
static uint16_t CY_SMIF_GetWriteCmdInfoNum(uint16_t wtCmdId)
{
	return (uint16_t)wtCmdId;
}

static cy_en_smif_xip_addr_byte_t CY_SMIF_GetAddrLenFromWriteCmd(volatile stc_SMIF_DEVICE_t *device, uint16_t cmd, const cy_stc_ex_dev_context_t* context)
{
	uint8_t devNum = Cy_SMIF_GetNoOfDevice(device);

	CY_ASSERT_L3(context->p_writeAddrTypes != NULL);
	CY_ASSERT_L3(context->p_writeCmdInfo != NULL);

	uint8_t writeInfoNum = CY_SMIF_GetWriteCmdInfoNum(cmd);
	uint8_t addrTypeNum = context->p_writeCmdInfo[writeInfoNum].addrTypeNum;

	return (context->p_writeAddrTypes[addrTypeNum].addrLen);
}


/*******************************************************************************
* Function Name CY_SMIF_DummyCycleEachWriteCmd
****************************************************************************//**
*
* \param cmd (see \cy_en_smif_rd_cmd_t)
*
* \param
*
* \return proper dummy cycle for input cmmand and latency code.
*
*******************************************************************************/
static cy_en_smif_field_presence_t CY_SMIF_DummyCycleEachWriteCmd(volatile stc_SMIF_DEVICE_t *device, uint16_t cmd, uint8_t latencyCode, uint8_t* dummyCycle, bool* rwdsEn, const cy_stc_ex_dev_context_t* context)
{
	uint8_t devNum = Cy_SMIF_GetNoOfDevice(device);

	CY_ASSERT_L3(context->p_writeCmdInfo != NULL);
	CY_ASSERT_L3(context->p_writeDummyTypes != NULL);
	CY_ASSERT_L3(context->pp_writeLatencyCodeToDummyCycle != NULL);
	CY_ASSERT_L3(latencyCode < context->writeLatencyCodeMax);

	uint8_t writeCmdNum  = CY_SMIF_GetWriteCmdInfoNum(cmd);
	uint8_t dummyTypeNum = context->p_writeCmdInfo[writeCmdNum].dummyTypeNum;
	uint8_t tableId      = context->p_writeDummyTypes[dummyTypeNum].tableId;
	*rwdsEn     = context->p_writeDummyTypes[dummyTypeNum].rwdsEn;

	//CY_ASSERT_L3(context->pp_writeLatencyCodeToDummyCycle[tableId] != NULL);
	*dummyCycle = context->pp_writeLatencyCodeToDummyCycle[tableId][latencyCode];
	return (context->p_writeDummyTypes[dummyTypeNum].presence);
}


/*******************************************************************************
* Function CY_SMIF_SetXIPWriteSequence
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
static void CY_SMIF_SetXIPWriteSequence(volatile stc_SMIF_DEVICE_t *device, uint16_t cmd, uint8_t mode, uint8_t latencyCode, bool dualQuad, const cy_stc_ex_dev_context_t* context)
{
	uint8_t devNum = Cy_SMIF_GetNoOfDevice(device);

	CY_ASSERT_L3(context->p_writeCmdInfo != NULL);
	CY_ASSERT_L3(context->p_writeCmdTypes != NULL);
	CY_ASSERT_L3(context->p_writeAddrTypes != NULL);
	CY_ASSERT_L3(context->p_writeModeTypes != NULL);
	CY_ASSERT_L3(context->p_writeDataTypes != NULL);

	CY_ASSERT_L3(cmd < context->writeCommandNum);

	uint8_t writeCmdNum = CY_SMIF_GetWriteCmdInfoNum(cmd);

	/*************************/
	/*** Set write command ***/
	/*************************/
	/* Prepare the parameters */
	stc_cy_smif_cmd_mode_ctl_t wtCmdParams;
	wtCmdParams.cmd       = (uint16_t)context->p_writeCmdInfo[writeCmdNum].cmd;

	uint8_t cmdTypeNum = context->p_writeCmdInfo[writeCmdNum].cmdTypeNum;
	wtCmdParams.width     = context->p_writeCmdTypes[cmdTypeNum].width;
	wtCmdParams.dataRate  = context->p_writeCmdTypes[cmdTypeNum].dataRate;
	wtCmdParams.presence  = context->p_writeCmdTypes[cmdTypeNum].presence;
	/* Set the parameters */
	Cy_SMIF_SetWriteCmdCtl(device, &wtCmdParams);

	/*************************/
	/*** Set write address ***/
	/*************************/
	/* Prepare the parameters */
	stc_cy_smif_addr_data_ctl_t wtAddrParams;
	uint8_t addrTypeNum = context->p_writeCmdInfo[writeCmdNum].addrTypeNum;
	wtAddrParams.width    = context->p_writeAddrTypes[addrTypeNum].width;
	wtAddrParams.dataRate = context->p_writeAddrTypes[addrTypeNum].dataRate;
	/* Set the parameters */
	Cy_SMIF_SetWriteAddrCtl(device, &wtAddrParams);

	/************************/
	/***  Set write mode  ***/
	/************************/
	/* Prepare the parameters */
	stc_cy_smif_cmd_mode_ctl_t wtModeParams;
	uint8_t modeTypeNum = context->p_writeCmdInfo[writeCmdNum].modeTypeNum;
	wtModeParams.cmd      = mode;
	wtModeParams.width    = context->p_writeModeTypes[modeTypeNum].width;
	wtModeParams.dataRate = context->p_writeModeTypes[modeTypeNum].dataRate;
	wtModeParams.presence = context->p_writeModeTypes[modeTypeNum].presence;
	/* Set the parameters */
	Cy_SMIF_SetWriteModeCtl(device, &wtModeParams);

	/*************************/
	/***  Set write dummy  ***/
	/*************************/
	/* Prepare the parameters */
	stc_cy_smif_wr_dummy_ctl_t wtDummyParams;
	uint8_t dummyCycle;
	bool    rwdsEn;
	wtDummyParams.presence   = CY_SMIF_DummyCycleEachWriteCmd(device, cmd, latencyCode, &dummyCycle, &rwdsEn, context);
	wtDummyParams.numOfDummy = dummyCycle;
	wtDummyParams.rwdsEn     = rwdsEn;
	/* Set the parameters */
	Cy_SMIF_SetWriteDummyCtl(device, &wtDummyParams);

	/************************/
	/***  Set write data   ***/
	/************************/
	/* Prepare the parameters */
	uint8_t dataTypeNum = context->p_writeCmdInfo[writeCmdNum].dataTypeNum;
	stc_cy_smif_addr_data_ctl_t wtDataParams;
	wtDataParams.width    = (dualQuad == true) ? CY_SMIF_WIDTH_OCTAL : context->p_writeDataTypes[dataTypeNum].width;
	wtDataParams.dataRate = context->p_writeDataTypes[dataTypeNum].dataRate;
	/* Set the parameters */
	Cy_SMIF_SetWriteDataCtl(device, &wtDataParams);

	/************************/
	/***   Set write CRC   ***/
	/************************/
	/* Prepare the parameters */
	stc_cy_smif_wr_crc_ctl_t wtCRCParams = { 0u };
	/* Set the parameters */
	Cy_SMIF_SetWriteCrcCtl(device, &wtCRCParams);

	return;

}

/*******************************************************************************
* Function Cy_SMIF_MMIO_Read_ExMem
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_MMIO_Read_ExMem(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint16_t readCmdId,
										uint32_t readAddress,
										uint32_t size,
										uint8_t buf[],
										uint8_t lcCode,
										uint8_t mode,
										cy_en_smif_block_mode_t blockingMode,
										const cy_stc_ex_dev_context_t* devContext,
										cy_stc_smif_context_t *context)
{
	cy_en_smif_status_t status;

	// If slave is Dual Quad then use younger No.
	uint8_t devNum = Cy_SMIF_GetNoOfDeviceFromSlave(base, slave);

	if(0) // Check if this is Hyper device or not.
	{
		// This function is not supporting Hyper device
		return CY_SMIF_BAD_PARAM;
	}

	if((devContext->p_readCmdInfo == NULL)                  ||
	   (devContext->p_readCmdTypes == NULL)                 ||
	   (devContext->p_readAddrTypes == NULL)                ||
	   (devContext->p_readModeTypes == NULL)                ||
	   (devContext->p_readDummyTypes == NULL)               ||
	   (devContext->pp_readLatencyCodeToDummyCycle == NULL) ||
	   (devContext->p_readDataTypes == NULL)                ||
	   (devContext->p_readCmdInfo == NULL))
	{
		return CY_SMIF_BAD_PARAM;
	}

	if(readCmdId >= devContext->readCommandNum)
	{
		return CY_SMIF_BAD_PARAM;
	}

	uint8_t cmdTypeNum  = devContext->p_readCmdInfo[readCmdId].cmdTypeNum;
	uint8_t addrTypeNum = devContext->p_readCmdInfo[readCmdId].addrTypeNum;

	if(devContext->p_readCmdTypes[cmdTypeNum].presence == CY_SMIF_NOT_PRESENT)
	{
		return CY_SMIF_BAD_PARAM;
	}

	cy_en_smif_xip_addr_byte_t addrLen = devContext->p_readAddrTypes[addrTypeNum].addrLen;
	uint8_t                    addrLenInByte;
	uint32_t                   addrInBigEndian;

	if(addrLen == CY_SMIF_XIP_ADDRESS_4_BYTE)
	{
		// No need to check
		addrLenInByte   = 4u;
		addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(readAddress);
	}
	else if(addrLen == CY_SMIF_XIP_ADDRESS_3_BYTE)
	{
		if(readAddress > 0x00FFFFFFul)
		{
			return CY_SMIF_BAD_PARAM;
		}
		addrLenInByte   = 3u;
		addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(readAddress << 8ul);
	}
	else
	{
		CY_ASSERT_L1(false);
	}

	/****** Command and Address ******/
	bool is2ByteCmd;
	if((devContext->p_readCmdInfo[readCmdId].cmd & 0xFF00) == 0)
	{
		is2ByteCmd = false;
	}
	else
	{
		is2ByteCmd = true;
	}
	status = Cy_SMIF_TransmitCommand(base,
									 devContext->p_readCmdInfo[readCmdId].cmd,         /* command value */
									 is2ByteCmd,
									 devContext->p_readCmdTypes[cmdTypeNum].width,     /* command width */
									 devContext->p_readCmdTypes[cmdTypeNum].dataRate,  /* command rate */
									 (uint8_t*)&addrInBigEndian,                /* Data pointer */
									 addrLenInByte,                             /* Data size */
									 devContext->p_readAddrTypes[addrTypeNum].width,   /* data width */
									 devContext->p_readAddrTypes[addrTypeNum].dataRate,/* data rate */
									 slave,                /* slave select */
									 NOT_LAST_COMMAND,
									 context);
	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}

	/****** Mode ******/
	uint8_t modeTypeNum = devContext->p_readCmdInfo[readCmdId].modeTypeNum;
	if(devContext->p_readModeTypes[modeTypeNum].presence != CY_SMIF_NOT_PRESENT)
	{
		status = Cy_SMIF_TransmitCommand(base,
										 mode,
										 false,
										 devContext->p_readModeTypes[modeTypeNum].width,   /* command width */
										 devContext->p_readModeTypes[modeTypeNum].dataRate,/* command rate */
										 NULL,                 /* Data pointer */
										 0,                    /* Data size */
										 CY_SMIF_WIDTH_SINGLE, /* data width */
										 CY_SMIF_SDR,          /* data rate */
										 slave,                /* slave select */
										 NOT_LAST_COMMAND,
										 context);
	}
	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}

	/****** Dummy ******/
	uint8_t dummyTypeNum = devContext->p_readCmdInfo[readCmdId].dummyTypeNum;
	if(devContext->p_readDummyTypes[dummyTypeNum].presence != CY_SMIF_NOT_PRESENT)
	{
		uint8_t tableId      = devContext->p_readDummyTypes[dummyTypeNum].tableId;
		uint8_t dummyCycle   = devContext->pp_readLatencyCodeToDummyCycle[tableId][(uint32_t)lcCode];
		if(dummyCycle > 0u)
		{
			status = Cy_SMIF_SendDummyCycles(base,
											 devContext->p_readDummyTypes[dummyTypeNum].width,  /* command width */
											 devContext->p_readDummyTypes[dummyTypeNum].dataRate,          /* command rate */
											 devContext->p_readDummyTypes[dummyTypeNum].doubleDm,
											 devContext->p_readDummyTypes[dummyTypeNum].rwdsInDm,
											 devContext->p_readDummyTypes[dummyTypeNum].dlpEn,
											 devContext->p_readDummyTypes[dummyTypeNum].rwdsEn,
											 dummyCycle);
			if(status != CY_SMIF_SUCCESS)
			{
				return status;
			}
		}
	}

	/****** Data ******/
	uint8_t dataTypeNum = devContext->p_readCmdInfo[readCmdId].dataTypeNum;
	cy_en_smif_txfr_width_t width;
	if((CY_SMIF_GetSlaveNumber(base, slave) == 2u) && (devContext->p_readDataTypes[dataTypeNum].width == CY_SMIF_WIDTH_QUAD))
	{
		// Dual Quad mode
		width = CY_SMIF_WIDTH_OCTAL;
	}
	else
	{
		width = devContext->p_readDataTypes[dataTypeNum].width;
	}

	if(blockingMode == CY_SMIF_BLOCKING)
	{
		status = Cy_SMIF_ReceiveDataBlocking(base, buf, size, width, devContext->p_readDataTypes[dataTypeNum].dataRate, slave, context);
	}
	else
	{
		status = Cy_SMIF_ReceiveData(base, buf, size, width, devContext->p_readDataTypes[dataTypeNum].dataRate, slave, NULL, context);
	}
	return status;
}

/*******************************************************************************
* Function Cy_SMIF_MMIO_Program_ExMem
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_MMIO_Program_ExMem(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint16_t writeCmdId,
										uint32_t programedAddress,
										uint32_t size,
										const uint8_t buf[],
										cy_en_smif_block_mode_t blockingMode,
										uint8_t lcCode,
										uint8_t mode,
										const cy_stc_ex_dev_context_t* devContext,
										cy_stc_smif_context_t *context)
{
	cy_en_smif_status_t status;

	// If slave is Dual Quad then use younger No.
	uint8_t devNum = Cy_SMIF_GetNoOfDeviceFromSlave(base, slave);

	if(0) // Check if this is Hyper device or not.
	{
		// This function is not supporting Hyper device
		return CY_SMIF_BAD_PARAM;
	}

	if((devContext->p_writeCmdInfo == NULL)                  ||
	   (devContext->p_writeCmdTypes == NULL)                 ||
	   (devContext->p_writeAddrTypes == NULL)                ||
	   (devContext->p_writeModeTypes == NULL)                ||
	   (devContext->p_writeDummyTypes == NULL)               ||
	   (devContext->pp_writeLatencyCodeToDummyCycle == NULL) ||
	   (devContext->p_writeDataTypes == NULL)                ||
	   (devContext->p_writeCmdInfo == NULL))
	{
		return CY_SMIF_BAD_PARAM;
	}

	uint8_t cmdTypeNum  = devContext->p_writeCmdInfo[writeCmdId].cmdTypeNum;
	uint8_t addrTypeNum = devContext->p_writeCmdInfo[writeCmdId].addrTypeNum;

	if(devContext->p_writeCmdTypes[cmdTypeNum].presence == CY_SMIF_NOT_PRESENT)
	{
		return CY_SMIF_BAD_PARAM;
	}

	cy_en_smif_xip_addr_byte_t addrLen = devContext->p_writeAddrTypes[addrTypeNum].addrLen;
	uint8_t                    addrLenInByte;
	uint32_t                   addrInBigEndian;

	if(addrLen == CY_SMIF_XIP_ADDRESS_4_BYTE)
	{
		// No need to check
		addrLenInByte = 4u;
		addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(programedAddress);
	}
	else if(addrLen == CY_SMIF_XIP_ADDRESS_3_BYTE)
	{
		if(programedAddress > 0x00FFFFFFul)
		{
			return CY_SMIF_BAD_PARAM;
		}
		addrLenInByte = 3u;
		addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(programedAddress << 8ul);
	}
	else
	{
		CY_ASSERT_L1(false);
	}

	/****** Command and Address ******/
	bool is2ByteCmd;
	if((devContext->p_writeCmdInfo[writeCmdId].cmd & 0xFF00) == 0)
	{
		is2ByteCmd = false;
	}
	else
	{
		is2ByteCmd = true;
	}
	status = Cy_SMIF_TransmitCommand(base,
									 devContext->p_writeCmdInfo[writeCmdId].cmd,         /* command value */
									 is2ByteCmd,
									 devContext->p_writeCmdTypes[cmdTypeNum].width,     /* command width */
									 devContext->p_writeCmdTypes[cmdTypeNum].dataRate,  /* command rate */
									 (uint8_t*)&addrInBigEndian,                          /* Data pointer */
									 addrLenInByte,                            /* Data size */
									 devContext->p_writeAddrTypes[addrTypeNum].width,   /* data width */
									 devContext->p_writeAddrTypes[addrTypeNum].dataRate,/* data rate */
									 slave,                /* slave select */
									 NOT_LAST_COMMAND,
									 context);
	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}

	/****** Mode ******/
	uint8_t modeTypeNum = devContext->p_writeCmdInfo[writeCmdId].modeTypeNum;
	if(devContext->p_writeModeTypes[modeTypeNum].presence != CY_SMIF_NOT_PRESENT)
	{
		status = Cy_SMIF_TransmitCommand(base,
										 mode,
										 false,
										 devContext->p_writeModeTypes[modeTypeNum].width,   /* command width */
										 devContext->p_writeModeTypes[modeTypeNum].dataRate,/* command rate */
										 NULL,                 /* Data pointer */
										 0,                    /* Data size */
										 CY_SMIF_WIDTH_SINGLE, /* data width */
										 CY_SMIF_SDR,          /* data rate */
										 slave,                /* slave select */
										 NOT_LAST_COMMAND,
										 context);
	}
	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}

	/****** Dummy ******/
	uint8_t dummyTypeNum = devContext->p_writeCmdInfo[writeCmdId].dummyTypeNum;
	if(devContext->p_readDummyTypes[dummyTypeNum].presence != CY_SMIF_NOT_PRESENT)
	{
		uint8_t tableId      = devContext->p_writeDummyTypes[dummyTypeNum].tableId;
		uint8_t dummyCycle   = devContext->pp_writeLatencyCodeToDummyCycle[tableId][(uint32_t)lcCode];
		if(dummyCycle > 0u)
		{
			status = Cy_SMIF_SendDummyCycles(base,
											 devContext->p_writeDummyTypes[dummyTypeNum].width,  /* command width */
											 devContext->p_writeDummyTypes[dummyTypeNum].dataRate,          /* command rate */
											 devContext->p_writeDummyTypes[dummyTypeNum].doubleDm,
											 devContext->p_writeDummyTypes[dummyTypeNum].rwdsInDm,
											 devContext->p_writeDummyTypes[dummyTypeNum].dlpEn,
											 devContext->p_writeDummyTypes[dummyTypeNum].rwdsEn,
											 dummyCycle);
			if(status != CY_SMIF_SUCCESS)
			{
				return status;
			}
		}
	}

	/****** Data ******/
	uint8_t dataTypeNum = devContext->p_writeCmdInfo[writeCmdId].dataTypeNum;
	cy_en_smif_txfr_width_t width;
	// Check if it indicate dual quad mode.
	if((CY_SMIF_GetSlaveNumber(base, slave) == 2u) && (devContext->p_writeDataTypes[dataTypeNum].width == CY_SMIF_WIDTH_QUAD))
	{
		// Dual quad
		width = CY_SMIF_WIDTH_OCTAL;
	}
	else
	{
		// Not dual quad
		width = devContext->p_writeDataTypes[dataTypeNum].width;
	}

	if(blockingMode == CY_SMIF_BLOCKING)
	{
		Cy_SMIF_TransmitDataBlocking(base, buf, size, width, devContext->p_writeDataTypes[dataTypeNum].dataRate, slave, context);
	}
	else
	{
		Cy_SMIF_TransmitData(base, buf, size, width, devContext->p_writeDataTypes[dataTypeNum].dataRate, slave, NULL, context);
	}

	return status;
}


#if defined(__cplusplus)
}
#endif

