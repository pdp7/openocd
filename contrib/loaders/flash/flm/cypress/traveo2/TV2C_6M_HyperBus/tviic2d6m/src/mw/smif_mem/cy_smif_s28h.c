/***************************************************************************//**
* \file cy_smif_s28h.c
* \version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
*
* \brief
*  This file provides the source code for the S28H HSSPI series driver APIs.
*
* Note:
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

#include "cy_smif_s28h.h"

/************************************************************/
/*************** Specify Read Command Sequence **************/
/************************************************************/
static const cy_stc_cmd_sq_t g_s28hReadCmdTypes[] =
{
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE}, // cmdTypeNum = 0
	{.width = CY_SMIF_WIDTH_OCTAL,  .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_2BYTE}, // cmdTypeNum = 1
	{.width = CY_SMIF_WIDTH_OCTAL,  .dataRate = CY_SMIF_DDR, .presence = CY_SMIF_PRESENT_2BYTE}, // cmdTypeNum = 2
};

/************************************************************/
/*************** Specify Read Address Sequence **************/
/************************************************************/
static const cy_stc_addr_sq_t g_s28hReadAddrTypes[] =
{
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .addrLen = CY_SMIF_XIP_ADDRESS_3_BYTE}, // addrTypeNum = 0
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .addrLen = CY_SMIF_XIP_ADDRESS_4_BYTE}, // addrTypeNum = 1
	{.width = CY_SMIF_WIDTH_OCTAL,  .dataRate = CY_SMIF_SDR, .addrLen = CY_SMIF_XIP_ADDRESS_4_BYTE}, // addrTypeNum = 2
	{.width = CY_SMIF_WIDTH_OCTAL,  .dataRate = CY_SMIF_DDR, .addrLen = CY_SMIF_XIP_ADDRESS_4_BYTE}, // addrTypeNum = 3
};

/************************************************************/
/**************** Specify Read Mode Sequence ****************/
/************************************************************/
static const cy_stc_mode_sq_t g_s28hReadModeTypes[] =
{
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_NOT_PRESENT}, // modeTypeNum = 0
};

/************************************************************/
/**************** Specify Read Dummy Sequence ***************/
/************************************************************/
static const cy_stc_dummy_sq_t g_s28hReadDummyTypes[] =
{
	{.tableId = 0, .width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_NOT_PRESENT,   .doubleDm = false, .rwdsInDm = false, .dlpEn = false, .rwdsEn = false}, // dummyTypeNum = 0
	{.tableId = 0, .width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE, .doubleDm = false, .rwdsInDm = false, .dlpEn = false, .rwdsEn = true}, // dummyTypeNum = 1
	{.tableId = 1, .width = CY_SMIF_WIDTH_OCTAL,  .dataRate = CY_SMIF_SDR,  .presence = CY_SMIF_PRESENT_1BYTE, .doubleDm = false, .rwdsInDm = false, .dlpEn = false, .rwdsEn = true}, // dummyTypeNum = 2
	{.tableId = 1, .width = CY_SMIF_WIDTH_OCTAL,  .dataRate = CY_SMIF_DDR,  .presence = CY_SMIF_PRESENT_1BYTE, .doubleDm = false, .rwdsInDm = false, .dlpEn = false, .rwdsEn = true}, // dummyTypeNum = 3
};

static const uint8_t g_s28hLatancyTableOf1_1_1Read[CY_SMIF_S28H_READ_LATENCY_CODE_MAX] = {0u,  1u,  2u,  3u,  4u,  5u,  6u,  7u,  8u,  9u, 10u, 11u, 12u, 13u, 14u, 15u};
static const uint8_t g_s28hLatancyTableOf8_8_8Read[CY_SMIF_S28H_READ_LATENCY_CODE_MAX] = {5u,  6u,  8u, 10u, 12u, 14u, 16u, 18u, 20u, 22u, 23u, 24u, 25u, 26u, 27u, 28u};

#define g_s28hLatancyTableOf1_1_1Read_m {0u,  1u,  2u,  3u,  4u,  5u,  6u,  7u,  8u,  9u, 10u, 11u, 12u, 13u, 14u, 15u}
#define g_s28hLatancyTableOf8_8_8Read_m {5u,  6u,  8u, 10u, 12u, 14u, 16u, 18u, 20u, 22u, 23u, 24u, 25u, 26u, 27u, 28u}

static const uint8_t g_s28hReadLatencyCodeToDummyCycle[CY_SMIF_S28H_READ_LC_DC_TABLE_MAX][CY_SMIF_S28H_READ_LATENCY_CODE_MAX] =
{
	g_s28hLatancyTableOf1_1_1Read_m,
	g_s28hLatancyTableOf8_8_8Read_m,
};

/************************************************************/
/**************** Specify Read Data Sequence ****************/
/************************************************************/
static const cy_stc_data_sq_t g_s28hReadDataTypes[] =
{
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR}, // dataTypeNum = 0
	{.width = CY_SMIF_WIDTH_OCTAL,  .dataRate = CY_SMIF_SDR}, // dataTypeNum = 1
	{.width = CY_SMIF_WIDTH_OCTAL,  .dataRate = CY_SMIF_DDR}, // dataTypeNum = 2
};

/************************************************************/
/************* Read Command Table for S28HXxxxT *************/
/************************************************************/
static const cy_stc_read_info_t g_s28hReadCmdInfo[] =
{
	{ .cmd = CY_28HL_CMD_SPI_RDAY1_C_0,    .cmdTypeNum = 0u, .addrTypeNum = 0u, .modeTypeNum = 0u, .dummyTypeNum = 0u, .dataTypeNum = 0u },  // CY_SMIF_28HL_ID_3ADDR_READ
	{ .cmd = CY_28HL_CMD_SPI_RDAY1_C_0,    .cmdTypeNum = 0u, .addrTypeNum = 1u, .modeTypeNum = 0u, .dummyTypeNum = 0u, .dataTypeNum = 0u },  // CY_SMIF_28HL_ID_4ADDR_READ0
	{ .cmd = CY_28HL_CMD_SPI_RDAY1_4_0,    .cmdTypeNum = 0u, .addrTypeNum = 1u, .modeTypeNum = 0u, .dummyTypeNum = 0u, .dataTypeNum = 0u },  // CY_SMIF_28HL_ID_4ADDR_READ1
	{ .cmd = CY_28HL_CMD_SPI_RDAY2_C_0,    .cmdTypeNum = 0u, .addrTypeNum = 0u, .modeTypeNum = 0u, .dummyTypeNum = 1u, .dataTypeNum = 0u },  // CY_SMIF_28HL_ID_3ADDR_FAST_READ
	{ .cmd = CY_28HL_CMD_SPI_RDAY2_C_0,    .cmdTypeNum = 0u, .addrTypeNum = 1u, .modeTypeNum = 0u, .dummyTypeNum = 1u, .dataTypeNum = 0u },  // CY_SMIF_28HL_ID_4ADDR_FAST_READ
	{ .cmd = CY_28HL_CMD_OCTAL_RDAY1_4_0,  .cmdTypeNum = 1u, .addrTypeNum = 2u, .modeTypeNum = 0u, .dummyTypeNum = 2u, .dataTypeNum = 1u },  // CY_SMIF_28HL_ID_OCTAL_4ADDR_SDR_READ
	{ .cmd = CY_28HL_CMD_OCTAL_RDAY2_4_0,  .cmdTypeNum = 2u, .addrTypeNum = 3u, .modeTypeNum = 0u, .dummyTypeNum = 3u, .dataTypeNum = 2u },  // CY_SMIF_28HL_ID_OCTAL_4ADDR_DDR_READ
};

/************************************************************/
/*************** Specify Write Command Sequence *************/
/************************************************************/
static const cy_stc_cmd_sq_t g_s28hWriteCmdTypes[] =
{
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE}, // cmdTypeNum = 0
	{.width = CY_SMIF_WIDTH_OCTAL,  .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_2BYTE}, // cmdTypeNum = 1
	{.width = CY_SMIF_WIDTH_OCTAL,  .dataRate = CY_SMIF_DDR, .presence = CY_SMIF_PRESENT_2BYTE}, // cmdTypeNum = 2
};

/************************************************************/
/*************** Specify Write Address Sequence *************/
/************************************************************/
static const cy_stc_addr_sq_t g_s28hWriteAddrTypes[] =
{
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .addrLen = CY_SMIF_XIP_ADDRESS_4_BYTE}, // addrTypeNum = 0
	{.width = CY_SMIF_WIDTH_OCTAL,  .dataRate = CY_SMIF_SDR, .addrLen = CY_SMIF_XIP_ADDRESS_4_BYTE}, // addrTypeNum = 0
	{.width = CY_SMIF_WIDTH_OCTAL,  .dataRate = CY_SMIF_DDR, .addrLen = CY_SMIF_XIP_ADDRESS_4_BYTE}, // addrTypeNum = 0
};

/************************************************************/
/**************** Specify Write Mode Sequence ***************/
/************************************************************/
static const cy_stc_mode_sq_t g_s28hWriteModeTypes[] =
{
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_NOT_PRESENT  }, // modeTypeNum = 0
};

/************************************************************/
/**************** Specify Write Dummy Sequence **************/
/************************************************************/
static const cy_stc_dummy_sq_t g_s28hWriteDummyTypes[] =
{
	{.tableId = 0, .width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_NOT_PRESENT,   .doubleDm = false, .rwdsInDm = false, .dlpEn = false, .rwdsEn = false}, // dummyTypeNum = 0
};

#define g_s28latancyTableOfWrite {0u,}
static const uint8_t* g_s28hWriteLatencyCodeToDummyCycle[CY_SMIF_S28H_WRITE_LATENCY_CODE_MAX][CY_SMIF_S28H_WRITE_LC_DC_TABLE_MAX] =
{
   g_s28latancyTableOfWrite,
};

/************************************************************/
/**************** Specify Write Data Sequence ***************/
/************************************************************/
static const cy_stc_data_sq_t g_s28hWriteDataTypes[] =
{
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR}, // dataTypeNum = 0
	{.width = CY_SMIF_WIDTH_OCTAL,  .dataRate = CY_SMIF_SDR}, // dataTypeNum = 1
	{.width = CY_SMIF_WIDTH_OCTAL,  .dataRate = CY_SMIF_DDR}, // dataTypeNum = 2
};

/************************************************************/
/************* Write Command Table for S28HXxxxT ************/
/************************************************************/
static const cy_stc_write_info_t g_s28hWriteCmdInfo[] =
{
	{ .cmd = CY_28HL_CMD_SPI_PRPGE_4_1,    .cmdTypeNum   = 0u, .addrTypeNum  = 0u, .modeTypeNum  = 0u, .dummyTypeNum = 0u, .dataTypeNum  = 0u }, // CY_SMIF_28HL_ID_PP
	{ .cmd = CY_28HL_CMD_OCTAL_PRPGE_4_1,  .cmdTypeNum   = 1u, .addrTypeNum  = 1u, .modeTypeNum  = 0u, .dummyTypeNum = 0u, .dataTypeNum  = 1u }, // CY_SMIF_28HL_ID_OCTAL_SDR_PP
	{ .cmd = CY_28HL_CMD_OCTAL_PRPGE_4_1,  .cmdTypeNum   = 2u, .addrTypeNum  = 2u, .modeTypeNum  = 0u, .dummyTypeNum = 0u, .dataTypeNum  = 2u }, // CY_SMIF_28HL_ID_OCTAL_DDR_PP
};


/***********************************************************************/
/******************* Functions Issuing Each Commands *******************/
/***********************************************************************/
/*******************************************************************************
* Function Cy_SMIF_S28H_ReadId
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_ReadId(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_stc_smif_s28hl_id_t* readID,
										cy_en_smif_s28hl_reg_latency_code_t lc,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;
	uint32_t dummyAddress = 0ul;
	uint8_t dummyCycle;

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	bool                    RWDS_CapEn;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_RDIDN_0_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
		dummyCycle     = g_s28hLatancyTableOfRegType2[lc];
		RWDS_CapEn     = false;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_RDIDN_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = (uint8_t*)&dummyAddress;
		addrLen        = 4u;
		dummyCycle     = g_s28hLatancyTableOfRegType3[lc];
		RWDS_CapEn     = true;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_RDIDN_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = (uint8_t*)&dummyAddress;
		addrLen        = 4u;
		dummyCycle     = g_s28hLatancyTableOfRegType3[lc];
		RWDS_CapEn     = true;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 NOT_LAST_COMMAND,
									 context);
	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}

	/* send dummy */
	if(dummyCycle > 0)
	{
		status = Cy_SMIF_SendDummyCycles(base,
										 width,    /* command width */
										 dataRate, /* command rate */
										 false, false, false, RWDS_CapEn,
										 dummyCycle);
		if(status != CY_SMIF_SUCCESS)
		{
			return status;
		}
	}

	/* read Id */
	status = Cy_SMIF_ReceiveDataBlocking(base, (uint8_t*)readID, sizeof(cy_stc_smif_s28hl_id_t), width, dataRate, slave, context);
	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}

	return status;
}

/*******************************************************************************
* Function Cy_SMIF_S28H_ReadJedecId
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_ReadJedecId(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint64_t* readData[],
										uint32_t readAddress,
										uint32_t readSize,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;
	uint32_t                addrInBigEndian;

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	bool                    RWDS_CapEn;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_RSFDP_3_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;


		if(readAddress > 0x00FFFFFFul)
		{
			return CY_SMIF_BAD_PARAM;
		}
		addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(readAddress << 8ul);

		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 3u;
		RWDS_CapEn     = false;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_RSFDP_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(readAddress);
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
		RWDS_CapEn     = true;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_RSFDP_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(readAddress);
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
		RWDS_CapEn     = true;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 NOT_LAST_COMMAND,
									 context);
	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}

	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}

	/* send dummy */
	status = Cy_SMIF_SendDummyCycles(base,
									 width,  /* command width */
									 dataRate,          /* command rate */
									 false, false, false, RWDS_CapEn,
									 8u);
	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}

	status = Cy_SMIF_ReceiveDataBlocking(base, (uint8_t*)readData, readSize, width, dataRate, slave, context);

	return status;
}

/*******************************************************************************
* Function Cy_SMIF_S28H_ReadElectronicSignature
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_ReadUniqueId(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint64_t* uniqueId,
										cy_en_smif_s28hl_reg_latency_code_t lc,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;
	uint32_t dummyAddress = 0ul;
	uint8_t dummyCycle;

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	bool                    RWDS_CapEn;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_RDUID_0_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
		dummyCycle     = g_s28hLatancyTableOfRegType2[lc];
		RWDS_CapEn     = false;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_RDUID_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = (uint8_t*)&dummyAddress;
		addrLen        = 4u;
		dummyCycle     = g_s28hLatancyTableOfRegType3[lc];
		RWDS_CapEn     = true;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_RDUID_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = (uint8_t*)&dummyAddress;
		addrLen        = 4u;
		dummyCycle     = g_s28hLatancyTableOfRegType3[lc];
		RWDS_CapEn     = true;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 NOT_LAST_COMMAND,
									 context);
	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}

	/* send dummy */
	if(dummyCycle > 0)
	{
		status = Cy_SMIF_SendDummyCycles(base,
										 width,    /* command width */
										 dataRate, /* command rate */
										 false, false, false, RWDS_CapEn,
										 dummyCycle);
		if(status != CY_SMIF_SUCCESS)
		{
			return status;
		}
	}

	/* read Id */
	status = Cy_SMIF_ReceiveDataBlocking(base, (uint8_t*)uniqueId, 2u, width, dataRate, slave, context);
	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}

	return status;
}

/*******************************************************************************
* Function Cy_SMIF_S28H_ReadStatusRegister1
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_ReadStatusRegister1(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint8_t* readData,
										cy_en_smif_s28hl_reg_latency_code_t regLc,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;
	uint32_t dummyAddress = 0ul;
	uint8_t dummyCycle;

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*               addrPointer;
	uint8_t                 addrLen;
	bool                    RWDS_CapEn;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_RDSR1_0_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
		dummyCycle     = g_s28hLatancyTableOfRegType2[regLc];
		RWDS_CapEn     = false;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_RDSR1_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = (uint8_t*)&dummyAddress;
		addrLen        = 4u;
		dummyCycle     = g_s28hLatancyTableOfRegType3[regLc];
		RWDS_CapEn     = true;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_RDSR1_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = (uint8_t*)&dummyAddress;
		addrLen        = 4u;
		dummyCycle     = g_s28hLatancyTableOfRegType3[regLc];
		RWDS_CapEn     = true;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 NOT_LAST_COMMAND,
									 context);
	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}

	/* send dummy */
	if(dummyCycle > 0)
	{
		status = Cy_SMIF_SendDummyCycles(base,
										 width,    /* command width */
										 dataRate, /* command rate */
										 false, false, false, RWDS_CapEn,
										 dummyCycle);
		if(status != CY_SMIF_SUCCESS)
		{
			return status;
		}
	}

	if((width == CY_SMIF_WIDTH_OCTAL) && (dataRate == CY_SMIF_DDR))
	{
		uint8_t tempRead[2];
		status = Cy_SMIF_ReceiveDataBlocking(base, tempRead, 2u, width, dataRate, slave, context);
		*readData = tempRead[0];
	}
	else
	{
		status = Cy_SMIF_ReceiveDataBlocking(base, readData, 1u, width, dataRate, slave, context);
	}

	return status;
}

/*******************************************************************************
* Function Cy_SMIF_S28H_ReadStatusRegister2
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_ReadStatusRegister2(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint8_t* readData,
										cy_en_smif_s28hl_reg_latency_code_t regLc,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;
	uint32_t dummyAddress = 0ul;
	uint8_t dummyCycle;

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*               addrPointer;
	uint8_t                 addrLen;
	bool                    RWDS_CapEn;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_RDSR2_0_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
		dummyCycle     = g_s28hLatancyTableOfRegType2[regLc];
		RWDS_CapEn     = false;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_RDSR2_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = (uint8_t*)&dummyAddress;
		addrLen        = 4u;
		dummyCycle     = g_s28hLatancyTableOfRegType3[regLc];
		RWDS_CapEn     = true;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_RDSR2_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = (uint8_t*)&dummyAddress;
		addrLen        = 4u;
		dummyCycle     = g_s28hLatancyTableOfRegType3[regLc];
		RWDS_CapEn     = true;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 NOT_LAST_COMMAND,
									 context);
	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}

	/* send dummy */
	if(dummyCycle > 0)
	{
		status = Cy_SMIF_SendDummyCycles(base,
										 width,    /* command width */
										 dataRate, /* command rate */
										 false, false, false, RWDS_CapEn,
										 dummyCycle);
		if(status != CY_SMIF_SUCCESS)
		{
			return status;
		}
	}

	if((width == CY_SMIF_WIDTH_OCTAL) && (dataRate == CY_SMIF_DDR))
	{
		uint8_t tempRead[2];
		status = Cy_SMIF_ReceiveDataBlocking(base, tempRead, 2u, width, dataRate, slave, context);
		*readData = tempRead[0];
	}
	else
	{
		status = Cy_SMIF_ReceiveDataBlocking(base, readData, 1u, width, dataRate, slave, context);
	}

	return status;
}


/*******************************************************************************
* Function Cy_SMIF_S28H_ReadAnyNonVolatileRegister
****************************************************************************//**
*
* Read data does not support multiple slave access at the same time.
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_ReadAnyNonVolatileRegister(volatile stc_SMIF_t *base,
												cy_en_smif_slave_select_t slave,
												uint8_t* readData,
												cy_en_smif_s28hl_reg_addr_t regAddr,
												cy_en_smif_s28hl_read_latency_code_t latencyCode,
												cy_en_smif_s28hl_addr_len_t addrLen1S1S1S,
												cy_en_smif_s28hl_transaction_t transaction,
												cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;
	uint32_t addrInBigEndian;
	uint8_t dummyCycle;

	if(((uint32_t)regAddr & 0x00800000UL) != 0x0UL)
	{
		// volatile register address
		return CY_SMIF_BAD_PARAM;
	}

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	bool                    RWDS_CapEn;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_RDARG_C_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;

		if(addrLen1S1S1S == CY_S28H_ADDR_3BYTE)
		{
			addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(regAddr << 8ul);
			addrLen        = 3u;
		}
		else
		{
			addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(regAddr);
			addrLen = 4u;
		}

		addrPointer    = (uint8_t*)&addrInBigEndian;
		dummyCycle = g_s28hLatancyTableOf1_1_1Read[latencyCode];
		RWDS_CapEn = false;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_RDARG_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(regAddr);
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
		dummyCycle = g_s28hLatancyTableOf8_8_8Read[latencyCode];
		RWDS_CapEn = true;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_RDARG_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(regAddr);
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
		dummyCycle = g_s28hLatancyTableOf8_8_8Read[latencyCode];
		RWDS_CapEn = true;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 NOT_LAST_COMMAND,
									 context);
	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}

	/* send dummy */
	if(dummyCycle > 0)
	{
		status = Cy_SMIF_SendDummyCycles(base,
										 width,  /* command width */
										 dataRate,          /* command rate */
										 false, false, false, RWDS_CapEn,
										 dummyCycle);
		if(status != CY_SMIF_SUCCESS)
		{
			return status;
		}
	}


	if((width == CY_SMIF_WIDTH_OCTAL) && (dataRate == CY_SMIF_DDR))
	{
		uint8_t tempRead[2];
		status = Cy_SMIF_ReceiveDataBlocking(base, tempRead, 2u, width, dataRate, slave, context);
		*readData = tempRead[0];
	}
	else
	{
		status = Cy_SMIF_ReceiveDataBlocking(base, readData, 1u, width, dataRate, slave, context);
	}

	return status;
}


/*******************************************************************************
* Function Cy_SMIF_S28H_ReadAnyVolatileRegister
****************************************************************************//**
*
* Read data does not support multiple slave access at the same time.
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_ReadAnyVolatileRegister(volatile stc_SMIF_t *base,
												cy_en_smif_slave_select_t slave,
												uint8_t* readData,
												cy_en_smif_s28hl_reg_addr_t regAddr,
												cy_en_smif_s28hl_reg_latency_code_t latencyCode,
												cy_en_smif_s28hl_addr_len_t addrLen1S1S1S,
												cy_en_smif_s28hl_transaction_t transaction,
												cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;
	uint32_t addrInBigEndian;

	if(((uint32_t)regAddr & 0x00800000UL) == 0x0UL)
	{
		// non-volatile register address.
		return CY_SMIF_BAD_PARAM;
	}

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	uint8_t                 dummyCycle;
	bool                    RWDS_CapEn;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_RDARG_C_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;

		if(addrLen1S1S1S == CY_S28H_ADDR_3BYTE)
		{
			addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(regAddr << 8ul);
			addrLen         = 3u;
		}
		else
		{
			addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(regAddr);
			addrLen         = 4u;
		}

		addrPointer    = (uint8_t*)&addrInBigEndian;
		dummyCycle     = g_s28hLatancyTableOfRegType1[latencyCode];
		RWDS_CapEn     = false;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_RDARG_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(regAddr);
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
		dummyCycle = g_s28hLatancyTableOfRegType3[latencyCode];
		RWDS_CapEn     = true;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_RDARG_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(regAddr);
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
		dummyCycle = g_s28hLatancyTableOfRegType3[latencyCode];
		RWDS_CapEn     = true;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 NOT_LAST_COMMAND,
									 context);
	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}

	/* send dummy */
	if(dummyCycle > 0)
	{
		status = Cy_SMIF_SendDummyCycles(base,
										 width,    /* command width */
										 dataRate, /* command rate */
										 false, false, false, RWDS_CapEn,
										 dummyCycle);
		if(status != CY_SMIF_SUCCESS)
		{
			return status;
		}
	}

	if((width == CY_SMIF_WIDTH_OCTAL) && (dataRate == CY_SMIF_DDR))
	{
		uint8_t tempRead[2];
		status = Cy_SMIF_ReceiveDataBlocking(base, tempRead, 2u, width, dataRate, slave, context);
		*readData = tempRead[0];
	}
	else
	{
		status = Cy_SMIF_ReceiveDataBlocking(base, readData, 1u, width, dataRate, slave, context);
	}

	return status;
}


/*******************************************************************************
* Function Cy_SMIF_S28H_WriteEnable
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_WriteEnable(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_WRENB_0_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_WRENB_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_WRENB_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 LAST_COMMAND_BYTE,
									 context);

	return status;
}

/*******************************************************************************
* Function Cy_SMIF_S28H_WriteDisable
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_WriteDisable(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_WRDIS_0_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_WRDIS_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_WRDIS_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 LAST_COMMAND_BYTE,
									 context);

	return status;
}

/*******************************************************************************
* Function Cy_SMIF_S28H_WriteAnyRegister
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_WriteAnyRegister(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint8_t writeData,
										cy_en_smif_s28hl_reg_addr_t regAddr,
										cy_en_smif_s28hl_addr_len_t addrLen1S1S1S,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;
	uint8_t addrAndData[5] = { 0u };

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_WRARG_C_1;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;

		if(addrLen1S1S1S == CY_S28H_ADDR_3BYTE)
		{
			*(uint32_t*)(&addrAndData[0]) = Cy_SMIF_Reverse4ByteEndian(((regAddr << 8ul) | writeData));
			addrLen        = 4u;
		}
		else
		{
			*(uint32_t*)(&addrAndData[0]) = Cy_SMIF_Reverse4ByteEndian(regAddr);
			addrAndData[4] = writeData;
			addrLen        = 5u;
		}
		addrPointer    = &addrAndData[0];
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_WRARG_4_1;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		*(uint32_t*)(&addrAndData[0]) = Cy_SMIF_Reverse4ByteEndian(regAddr);
		addrAndData[4] = writeData;
		addrLen        = 5u;
		addrPointer    = &addrAndData[0];
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_WRARG_4_1;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		*(uint32_t*)(&addrAndData[0]) = Cy_SMIF_Reverse4ByteEndian(regAddr);
		addrAndData[4] = writeData;
		addrLen        = 5u;
		addrPointer    = &addrAndData[0];
	}


	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 LAST_COMMAND_BYTE,
									 context);

	return status;
}


/*******************************************************************************
* Function Cy_SMIF_S28H_ClearProgramAndEraseFailureFlags
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_ClearProgramAndEraseFailureFlags(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_CLPEF_0_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_CLPEF_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_CLPEF_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 LAST_COMMAND_BYTE,
									 context);

	return status;
}

/*******************************************************************************
* Function Cy_SMIF_S28H_ReadECC_DataUnitStatus
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_ReadECC_DataUnitStatus(volatile stc_SMIF_t *base,
												cy_en_smif_slave_select_t slave,
												uint8_t* readStatus,
												uint32_t unitAdder,
												uint8_t latencyCode,
												cy_en_smif_s28hl_transaction_t transaction,
												cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;
	uint8_t dummyCycle;

	if((unitAdder & 0x0000000Ful) != 0ul)
	{
		return CY_SMIF_BAD_PARAM;
	}

	uint32_t addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(unitAdder);

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	bool                    RWDS_CapEn;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_RDECC_4_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
		dummyCycle = g_s28hLatancyTableOf1_1_1Read[latencyCode];
		RWDS_CapEn     = false;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_RDECC_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
		dummyCycle = g_s28hLatancyTableOf8_8_8Read[latencyCode];
		RWDS_CapEn     = true;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_RDECC_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
		dummyCycle = g_s28hLatancyTableOf8_8_8Read[latencyCode];
		RWDS_CapEn     = true;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 NOT_LAST_COMMAND,
									 context);
	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}

	/* send dummy */
	if(dummyCycle > 0)
	{
		status = Cy_SMIF_SendDummyCycles(base,
										 width,  /* command width */
										 dataRate,          /* command rate */
										 false, false, false, RWDS_CapEn,
										 dummyCycle);
		if(status != CY_SMIF_SUCCESS)
		{
			return status;
		}
	}

	if((width == CY_SMIF_WIDTH_OCTAL) && (dataRate == CY_SMIF_DDR))
	{
		uint8_t tempRead[2];
		status = Cy_SMIF_ReceiveDataBlocking(base, tempRead, 2u, width, dataRate, slave, context);
		*readStatus = tempRead[0];
	}
	else
	{
		status = Cy_SMIF_ReceiveDataBlocking(base, readStatus, 1u, width, dataRate, slave, context);
	}

	return status;
}



/*******************************************************************************
* Function Cy_SMIF_S28H_ClearECC_StatusRegister
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_ClearECC_StatusRegister(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_CLECC_0_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_CLECC_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_CLECC_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 LAST_COMMAND_BYTE,
									 context);

	return status;
}

/*******************************************************************************
* Function Cy_SMIF_S28H_ReadInterfaceCRCRegister
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_ReadInterfaceCRCRegister(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint32_t* readICRV,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;
	uint32_t dummyAddress = 0ul;

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		return CY_SMIF_BAD_PARAM;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		return CY_SMIF_BAD_PARAM;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_RDCRC_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = (uint8_t*)&dummyAddress;
		addrLen        = 4u;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 NOT_LAST_COMMAND,
									 context);
	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}

	/* send dummy */
	status = Cy_SMIF_SendDummyCycles(base,
									 width,    /* command width */
									 dataRate, /* command rate */
									 false, false, false, true,
									 8u);
	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}

	status = Cy_SMIF_ReceiveDataBlocking(base, (uint8_t*)readICRV, 4u, width, dataRate, slave, context);
	if(status != CY_SMIF_SUCCESS)
	{
		return status;
	}
	*readICRV = Cy_SMIF_Reverse4ByteEndian(*readICRV);
	return status;
}


/*******************************************************************************
* Function Cy_SMIF_S28H_DataIntegrityCheck
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_DataIntegrityCheck(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint32_t startAddress,
										uint32_t endAddress,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;
	uint32_t startEndAddress[2];
	startEndAddress[0] = Cy_SMIF_Reverse4ByteEndian(startAddress);
	startEndAddress[1] = Cy_SMIF_Reverse4ByteEndian(endAddress);

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_DICHK_4_1;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = (uint8_t*)&startEndAddress;
		addrLen        = 8u;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_DICHK_4_1;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = (uint8_t*)&startEndAddress;
		addrLen        = 8u;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_DICHK_4_1;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = (uint8_t*)&startEndAddress;
		addrLen        = 8u;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 LAST_COMMAND_BYTE,
									 context);

	return status;
}


/*******************************************************************************
* Function Cy_SMIF_S28H_Erase_4KB_Sector
****************************************************************************//**
*
* Make sure the device is configured as 4-kB sectors
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_Erase_4KB_Sector(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint32_t erasedAddress,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;
	uint32_t addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(erasedAddress);

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_ER004_4_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_ER004_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_ER004_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 LAST_COMMAND_BYTE,
									 context);
	return status;
}

/*******************************************************************************
* Function Cy_SMIF_S28H_Erase_256KB_Sector
****************************************************************************//**
*
* Make sure the device is configured as 4-kB sectors
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_Erase_256KB_Sector(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint32_t erasedAddress,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;
	uint32_t addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(erasedAddress);

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_ER256_4_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_ER256_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_ER256_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 LAST_COMMAND_BYTE,
									 context);
	return status;
}

/*******************************************************************************
* Function Cy_SMIF_S28H_EraseChip
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_EraseChip(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*               addrPointer;
	uint8_t                 addrLen;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_ERCHP_0_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_ERCHP_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_ERCHP_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 LAST_COMMAND_BYTE,
									 context);

	return status;
}

/*******************************************************************************
* Function Cy_SMIF_S28H_EvaluateEraseStatus
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_EvaluateEraseStatus(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint32_t erasedAddress,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;
	uint32_t addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(erasedAddress);

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_EVERS_4_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_EVERS_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_EVERS_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 LAST_COMMAND_BYTE,
									 context);

	return status;
}

/*******************************************************************************
* Function Cy_SMIF_S28H_SectorEraseCount
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_SectorEraseCount(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										uint32_t erasedAddress,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;
	uint32_t addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(erasedAddress);

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_SEERC_4_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_SEERC_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_SEERC_4_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = (uint8_t*)&addrInBigEndian;
		addrLen        = 4u;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 LAST_COMMAND_BYTE,
									 context);

	return status;
}

/*******************************************************************************
* Function Cy_SMIF_S28H_SuspendEraseProgram
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_SuspendEraseProgram(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_SPEPD_0_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_SPEPD_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_SPEPD_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 LAST_COMMAND_BYTE,
									 context);

	return status;
}

/*******************************************************************************
* Function Cy_SMIF_S28H_ResumeEraseProgram
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_ResumeEraseProgram(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_RSEPD_0_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_RSEPD_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_RSEPD_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 LAST_COMMAND_BYTE,
									 context);

	return status;
}

/* Secure Silicon Region Command and Advanced Sector Protection Command are not impremented yet! */

/*******************************************************************************
* Function Cy_SMIF_S28H_SoftwareResetEnable
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_SoftwareResetEnable(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_SRSTE_0_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_SRSTE_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_SRSTE_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 LAST_COMMAND_BYTE,
									 context);

	return status;
}

/*******************************************************************************
* Function Cy_SMIF_S28H_SoftwareReset
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_SoftwareReset(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_SFRST_0_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_SFRST_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_SFRST_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 LAST_COMMAND_BYTE,
									 context);

	return status;
}

/*******************************************************************************
* Function Cy_SMIF_S28H_EnterDeepPowerDownMode
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S28H_EnterDeepPowerDownMode(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										cy_en_smif_s28hl_transaction_t transaction,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;

	uint16_t                commandValue;
	bool                    isCommand2Byte;
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	uint8_t*                addrPointer;
	uint8_t                 addrLen;
	if(transaction == CY_S28H_TRANSACTION_1S1S1S)
	{
		commandValue   = CY_28HL_CMD_SPI_ENDPD_0_0;
		isCommand2Byte = false;
		width          = CY_SMIF_WIDTH_SINGLE;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else if(transaction == CY_S28H_TRANSACTION_8S8S8S)
	{
		commandValue   = CY_28HL_CMD_OCTAL_ENDPD_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_SDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}
	else // 8D8D8D
	{
		commandValue   = CY_28HL_CMD_OCTAL_ENDPD_0_0;
		isCommand2Byte = true;
		width          = CY_SMIF_WIDTH_OCTAL;
		dataRate       = CY_SMIF_DDR;
		addrPointer    = NULL;
		addrLen        = 0u;
	}

	status = Cy_SMIF_TransmitCommand(base,
									 commandValue,  /* command value */
									 isCommand2Byte,
									 width,         /* command width */
									 dataRate,      /* command rate */
									 addrPointer,   /* Data pointer */
									 addrLen,       /* Data size */
									 width,         /* data width */
									 dataRate,      /* data rate */
									 slave,         /* slave select */
									 LAST_COMMAND_BYTE,
									 context);

	return status;
}

#if defined(__cplusplus)
}
#endif
