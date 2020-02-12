/***************************************************************************//**
* \file cy_smif_device_common.h
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
#if !defined(CY_SMIF_DEVICE_COMMON_H)
#define CY_SMIF_DEVICE_COMMON_H

#if defined(__cplusplus)
extern "C" {
#endif

#if defined (tviibh8m)
  #define CY_SMIF_SUM_DEVICE_NUM (SMIF_DEVICE_NR)
#elif defined (tviic2d6m)
  #define CY_SMIF_SUM_DEVICE_NUM (SMIF0_DEVICE_NR + SMIF1_DEVICE_NR)
#endif

typedef enum
{
	CY_SMIF_S25FL     = 0u,
	CY_SMIF_28HL      = 1u,
	CY_SMIF_DEV_MAX,
} cy_en_smif_ex_device_type;

typedef struct
{
	uint8_t Reserved0 : 1;
	uint8_t IsDualQuad: 1;
	uint8_t width     : 2;
	uint8_t dataSel   : 2;
	uint8_t Reserved1 : 2;
} cy_stc_smif_device_param_field_t;

typedef enum
{
	CY_SMIF_DEV_OSPI            = 0x0C,
	CY_SMIF_DEV_D_QUAD_BIT_0To3 = 0x0A,
	CY_SMIF_DEV_D_QUAD_BIT_4To7 = 0x2A,
	CY_SMIF_DEV_QUAD_BIT_0To3   = 0x08,
	CY_SMIF_DEV_QUAD_BIT_4To7   = 0x28,
	CY_SMIF_DEV_DUAL_BIT_0To1   = 0x04,
	CY_SMIF_DEV_DUAL_BIT_2To3   = 0x14,
	CY_SMIF_DEV_DUAL_BIT_4To5   = 0x24,
	CY_SMIF_DEV_DUAL_BIT_6To7   = 0x34,
	CY_SMIF_DEV_SINGLE_BIT_0To1 = 0x00,
	CY_SMIF_DEV_SINGLE_BIT_2To3 = 0x10,
	CY_SMIF_DEV_SINGLE_BIT_4To5 = 0x20,
	CY_SMIF_DEV_SINGLE_BIT_6To7 = 0x30,
} cy_en_smif_bit_alloc_t;

typedef union
{
	cy_en_smif_bit_alloc_t           en;
	cy_stc_smif_device_param_field_t bits;
} cy_un_smif_bit_alloc_t;

typedef enum
{
	CY_SMIF_BLOCKING     = 0u,
	CY_SMIF_NON_BLOCKING = 1u,
} cy_en_smif_block_mode_t;

typedef struct
{
	uint16_t                       xipReadCmdId;
	uint16_t                       xipReadMode;
	bool                           writeEn;
	uint16_t                       xipWriteCmdId;
	uint16_t                       xipWriteMode;
	bool                           mergeTimeoutEnable;
	cy_en_smif_dev_merge_timeout_t mergeTimeout;
	bool                           totalTimeoutEnable;
	uint16_t                       totalTimeout;
	uint32_t                       addr;
	cy_en_device_size_t            size;
	uint8_t                        rdLatencyCode;
	uint8_t                        wtLatencyCode;
} cy_stc_device_config_t;

typedef struct
{
	uint8_t ids[81];
} cy_stc_JedecId_t;

/************************************************************/
/********** Read/Write Command Sequence Structure ***********/
/************************************************************/
typedef struct
{
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	cy_en_smif_field_presence_t presence;
} cy_stc_cmd_sq_t;

/************************************************************/
/********** Read/Write Address Sequence Structure ***********/
/************************************************************/
typedef struct
{
	cy_en_smif_txfr_width_t    width;
	cy_en_smif_data_rate_t     dataRate;
	cy_en_smif_xip_addr_byte_t addrLen;
} cy_stc_addr_sq_t;

/************************************************************/
/*********** Read/Write Mode Sequence Structure *************/
/************************************************************/
typedef struct
{
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
	cy_en_smif_field_presence_t presence;
} cy_stc_mode_sq_t;

/************************************************************/
/*********** Read/Write Dummy Sequence Structure ************/
/************************************************************/
typedef struct
{
	uint8_t                     tableId;
	cy_en_smif_txfr_width_t     width;
	cy_en_smif_data_rate_t      dataRate;
	cy_en_smif_field_presence_t presence;
	bool                        doubleDm;
	bool                        rwdsInDm;
	bool                        dlpEn;
	bool                        rwdsEn;
} cy_stc_dummy_sq_t;

/************************************************************/
/*********** Read/Write Data Sequence Structure *************/
/************************************************************/
typedef struct
{
	cy_en_smif_txfr_width_t width;
	cy_en_smif_data_rate_t  dataRate;
} cy_stc_data_sq_t;

/************************************************************/
/*************** Read Information  Structure ****************/
/************************************************************/
typedef struct
{
	uint16_t                        cmd;
	uint8_t                  cmdTypeNum;
	uint8_t                 addrTypeNum;
	uint8_t                 modeTypeNum;
	uint8_t                dummyTypeNum;
	uint8_t                 dataTypeNum;
} cy_stc_read_info_t;

/************************************************************/
/*************** Write Information  Structure ***************/
/************************************************************/
typedef struct
{
	uint16_t                        cmd;
	uint8_t                  cmdTypeNum;
	uint8_t                 addrTypeNum;
	uint8_t                 modeTypeNum;
	uint8_t                dummyTypeNum;
	uint8_t                 dataTypeNum;
} cy_stc_write_info_t;

/************************************************************/
/****************** User Context Structure ******************/
/************************************************************/
typedef struct
{
	cy_stc_cmd_sq_t*          p_readCmdTypes;
	cy_stc_addr_sq_t*         p_readAddrTypes;
	cy_stc_mode_sq_t*         p_readModeTypes;
	cy_stc_dummy_sq_t*        p_readDummyTypes;
	uint8_t                   pp_readLatencyCodeToDummyCycle[16][16];
	cy_stc_data_sq_t*         p_readDataTypes;
	cy_stc_read_info_t*       p_readCmdInfo;
	cy_stc_cmd_sq_t*          p_writeCmdTypes;
	cy_stc_addr_sq_t*         p_writeAddrTypes;
	cy_stc_mode_sq_t*         p_writeModeTypes;
	cy_stc_dummy_sq_t*        p_writeDummyTypes;
	uint8_t                   pp_writeLatencyCodeToDummyCycle[16][16];
	cy_stc_data_sq_t*         p_writeDataTypes;
	cy_stc_write_info_t*      p_writeCmdInfo;
	uint32_t                  readLatencyCodeMax;
	uint32_t                  writeLatencyCodeMax;
	uint32_t                  readCommandNum;
	uint32_t                  writeCommandNum;
	cy_en_smif_ex_device_type currentExDevice;
} cy_stc_ex_dev_context_t;

/*******************************************************************************
* Function CY_SMIF_GetSlaveNumber
****************************************************************************//**
*
* \param slave (see \cy_en_smif_slave_select_t)
*
* \return
*  Slave number
*
*******************************************************************************/
static uint8_t CY_SMIF_GetSlaveNumber(volatile stc_SMIF_t *base, cy_en_smif_slave_select_t slave)
{
	uint8_t slaveTemp = (uint8_t)slave;
	uint8_t slaveNum = 0;

	for(uint8_t i = 0; i < CY_SMIF_GetDeviceNumber(base); i++)
	{
		if((slaveTemp & 0x01) == 0x01)
		{
			slaveNum++;
		}
		slaveTemp = slaveTemp >> 1u;
	}
	return slaveNum;
}

/*******************************************************************************
* Function CY_SMIF_GetSlaveNo
****************************************************************************//**
*
* \param slave (see \cy_en_smif_slave_select_t)
*
* \return
*  Slave No
*
*******************************************************************************/
static uint8_t CY_SMIF_GetSlaveNo(volatile stc_SMIF_t *base, cy_en_smif_slave_select_t slave)
{
	uint8_t slaveTemp = (uint8_t)slave;
	uint8_t slaveNo = 0;

	for(uint8_t i = 0; i < CY_SMIF_GetDeviceNumber(base); i++)
	{
		if((slaveTemp & 0x01) == 0x01)
		{
			return (slaveNo);
		}
		slaveTemp = slaveTemp >> 1u;
		slaveNo++;
	}

	return (0xFFu);
}

static uint8_t Cy_SMIF_GetNoOfDevice(volatile stc_SMIF_DEVICE_t *device)
{
	if(device == SMIF0_DEVICE0)
	{
		return (0u);
	}
	else if(device == SMIF0_DEVICE1)
	{
		return (1u);
	}
#if defined (tviic2d6m)
	else if(device == SMIF1_DEVICE0)
	{
		return (2u);
	}
	else if(device == SMIF1_DEVICE1)
	{
		return (3u);
	}
#endif
	// should not reach here
	CY_ASSERT_L1(false);
}

static uint8_t Cy_SMIF_GetNoOfDeviceFromSlave(volatile stc_SMIF_t *base, cy_en_smif_slave_select_t slave)
{

	uint8_t devNum = CY_SMIF_GetSlaveNo(base, slave);

	CY_ASSERT_L1(devNum != 0xFF);

#if defined (tviic2d6m)
	if(base == SMIF1)
	{
		devNum += SMIF0_DEVICE_NR;
	}
#endif

	return (devNum);
}

cy_en_smif_status_t Cy_SMIF_InitExMemContext(cy_en_smif_ex_device_type exDevice, cy_stc_ex_dev_context_t* context);
static cy_en_smif_xip_addr_byte_t CY_SMIF_GetAddrByteSizeFromMemSize(uint32_t size);
cy_en_smif_status_t Cy_SMIF_InitXIPModeForExMem(volatile stc_SMIF_DEVICE_t *device,
												cy_en_smif_bit_alloc_t bitAllocation,
												const cy_stc_device_config_t *config,
												const cy_stc_ex_dev_context_t* context);
static uint16_t CY_SMIF_GetReadCmdInfoNum(uint16_t rdCmdId);
static cy_en_smif_xip_addr_byte_t CY_SMIF_GetAddrLenFromReadCmd(volatile stc_SMIF_DEVICE_t *device, uint16_t cmd, const cy_stc_ex_dev_context_t* context);
static cy_en_smif_field_presence_t CY_SMIF_DummyCycleEachReadCmd(volatile stc_SMIF_DEVICE_t *device, uint16_t cmd, uint8_t latencyCode, uint8_t* dummyCycle, const cy_stc_ex_dev_context_t* context);
static void CY_SMIF_SetXIPReadSequence(volatile stc_SMIF_DEVICE_t *device, uint16_t cmd, uint8_t mode, uint8_t latencyCode, bool dualQuad, const cy_stc_ex_dev_context_t* context);
static uint16_t CY_SMIF_GetWriteCmdInfoNum(uint16_t wtCmdId);
static cy_en_smif_xip_addr_byte_t CY_SMIF_GetAddrLenFromWriteCmd(volatile stc_SMIF_DEVICE_t *device, uint16_t cmd, const cy_stc_ex_dev_context_t* context);
static cy_en_smif_field_presence_t CY_SMIF_DummyCycleEachWriteCmd(volatile stc_SMIF_DEVICE_t *device, uint16_t cmd, uint8_t latencyCode, uint8_t* dummyCycle, bool* rwdsEn, const cy_stc_ex_dev_context_t* context);
static void CY_SMIF_SetXIPWriteSequence(volatile stc_SMIF_DEVICE_t *device, uint16_t cmd, uint8_t mode, uint8_t latencyCode, bool dualQuad, const cy_stc_ex_dev_context_t* context);
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
										cy_stc_smif_context_t *context);
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
										cy_stc_smif_context_t *context);


#include "cy_smif_s25fl.h"
#include "cy_smif_s28h.h"

#if defined(__cplusplus)
}
#endif


#endif // CY_SMIF_DEVICE_COMMON_H
