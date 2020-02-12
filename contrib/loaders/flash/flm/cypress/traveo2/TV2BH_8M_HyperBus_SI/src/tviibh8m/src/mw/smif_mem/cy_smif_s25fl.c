/***************************************************************************//**
* \file cy_smif_s25fl.c
* \version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
*
* \brief
*  This file provides the source code for the S25FL HSSPI series driver APIs.
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

#include "cy_smif_s25fl.h"

static const cy_stc_cmd_sq_t g_read_cmd_sq_types[] =
{
    {.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE}, // cmdTypeNum = 0
};

static const cy_stc_addr_sq_t g_read_addr_sq_types[] =
{
    {.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR}, // addrTypeNum = 0
    {.width = CY_SMIF_WIDTH_DUAL,   .dataRate = CY_SMIF_SDR}, // addrTypeNum = 1
    {.width = CY_SMIF_WIDTH_QUAD,   .dataRate = CY_SMIF_SDR}, // addrTypeNum = 2
    {.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_DDR}, // addrTypeNum = 3
    {.width = CY_SMIF_WIDTH_DUAL,   .dataRate = CY_SMIF_DDR}, // addrTypeNum = 4
    {.width = CY_SMIF_WIDTH_QUAD,   .dataRate = CY_SMIF_DDR}, // addrTypeNum = 5
};

static const cy_stc_mode_sq_t g_read_mode_sq_types[] =
{
    {.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_NOT_PRESENT  }, // modeTypeNum = 0
    {.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE}, // modeTypeNum = 1
    {.width = CY_SMIF_WIDTH_DUAL,   .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE}, // modeTypeNum = 2
    {.width = CY_SMIF_WIDTH_QUAD,   .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE}, // modeTypeNum = 3
    {.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_DDR, .presence = CY_SMIF_PRESENT_1BYTE}, // modeTypeNum = 4
    {.width = CY_SMIF_WIDTH_DUAL,   .dataRate = CY_SMIF_DDR, .presence = CY_SMIF_PRESENT_1BYTE}, // modeTypeNum = 5
    {.width = CY_SMIF_WIDTH_QUAD,   .dataRate = CY_SMIF_DDR, .presence = CY_SMIF_PRESENT_1BYTE}, // modeTypeNum = 6
};

static const cy_stc_data_sq_t g_read_data_sq_types[] =
{
    {.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR}, // dataTypeNum = 0
    {.width = CY_SMIF_WIDTH_DUAL,   .dataRate = CY_SMIF_SDR}, // dataTypeNum = 1
    {.width = CY_SMIF_WIDTH_QUAD,   .dataRate = CY_SMIF_SDR}, // dataTypeNum = 2
    {.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_DDR}, // dataTypeNum = 3
    {.width = CY_SMIF_WIDTH_DUAL,   .dataRate = CY_SMIF_DDR}, // dataTypeNum = 4
    {.width = CY_SMIF_WIDTH_QUAD,   .dataRate = CY_SMIF_DDR}, // dataTypeNum = 5
};

static const cy_stc_read_cmd_info_t g_read_cmd_info[] =
{
    { .cmd = CY_SMIF_READ,       .cmdTypeNum = 0u, .addrTypeNum = 0u, .modeTypeNum = 0u, .dataTypeNum = 0u },
    { .cmd = CY_SMIF_4READ,      .cmdTypeNum = 0u, .addrTypeNum = 0u, .modeTypeNum = 0u, .dataTypeNum = 0u },
    { .cmd = CY_SMIF_FAST_READ,  .cmdTypeNum = 0u, .addrTypeNum = 0u, .modeTypeNum = 0u, .dataTypeNum = 0u },
    { .cmd = CY_SMIF_4FAST_READ, .cmdTypeNum = 0u, .addrTypeNum = 0u, .modeTypeNum = 0u, .dataTypeNum = 0u },
    { .cmd = CY_SMIF_DOR,        .cmdTypeNum = 0u, .addrTypeNum = 0u, .modeTypeNum = 0u, .dataTypeNum = 1u },
    { .cmd = CY_SMIF_4DOR,       .cmdTypeNum = 0u, .addrTypeNum = 0u, .modeTypeNum = 0u, .dataTypeNum = 1u },
    { .cmd = CY_SMIF_QOR,        .cmdTypeNum = 0u, .addrTypeNum = 0u, .modeTypeNum = 0u, .dataTypeNum = 2u },
    { .cmd = CY_SMIF_4QOR,       .cmdTypeNum = 0u, .addrTypeNum = 0u, .modeTypeNum = 0u, .dataTypeNum = 2u },

  #ifdef S25FL_USE_LC_ENHANCED
    { .cmd = CY_SMIF_DIOR,       .cmdTypeNum = 0u, .addrTypeNum = 1u, .modeTypeNum = 2u, .dataTypeNum = 1u },
    { .cmd = CY_SMIF_4DIOR,      .cmdTypeNum = 0u, .addrTypeNum = 1u, .modeTypeNum = 2u, .dataTypeNum = 1u },
  #else
    { .cmd = CY_SMIF_DIOR,       .cmdTypeNum = 0u, .addrTypeNum = 1u, .modeTypeNum = 0u, .dataTypeNum = 1u },
    { .cmd = CY_SMIF_4DIOR,      .cmdTypeNum = 0u, .addrTypeNum = 1u, .modeTypeNum = 0u, .dataTypeNum = 1u },
  #endif
    { .cmd = CY_SMIF_QIOR,       .cmdTypeNum = 0u, .addrTypeNum = 2u, .modeTypeNum = 3u, .dataTypeNum = 2u },
    { .cmd = CY_SMIF_4QIOR,      .cmdTypeNum = 0u, .addrTypeNum = 2u, .modeTypeNum = 3u, .dataTypeNum = 2u },
#if (CY_SMIF_QUAD_DEVICE_TYPE == CY_SMIF_S25FXXXS)
  #ifdef S25FL_USE_LC_ENHANCED
    { .cmd = CY_SMIF_DDRFR,      .cmdTypeNum = 0u, .addrTypeNum = 3u, .modeTypeNum = 4u, .dataTypeNum = 3u },
    { .cmd = CY_SMIF_4DDRFR,     .cmdTypeNum = 0u, .addrTypeNum = 3u, .modeTypeNum = 4u, .dataTypeNum = 3u },
  #else
    { .cmd = CY_SMIF_DDRFR,      .cmdTypeNum = 0u, .addrTypeNum = 3u, .modeTypeNum = 0u, .dataTypeNum = 3u },
    { .cmd = CY_SMIF_4DDRFR,     .cmdTypeNum = 0u, .addrTypeNum = 3u, .modeTypeNum = 0u, .dataTypeNum = 3u },
  #endif
  #ifdef S25FL_USE_LC_ENHANCED
    { .cmd = CY_SMIF_DDRDIOR,    .cmdTypeNum = 0u, .addrTypeNum = 4u, .modeTypeNum = 5u, .dataTypeNum = 4u },
    { .cmd = CY_SMIF_4DDRDIOR,   .cmdTypeNum = 0u, .addrTypeNum = 4u, .modeTypeNum = 5u, .dataTypeNum = 4u },
  #else
    { .cmd = CY_SMIF_DDRDIOR,    .cmdTypeNum = 0u, .addrTypeNum = 4u, .modeTypeNum = 0u, .dataTypeNum = 4u },
    { .cmd = CY_SMIF_4DDRDIOR,   .cmdTypeNum = 0u, .addrTypeNum = 4u, .modeTypeNum = 0u, .dataTypeNum = 4u },
  #endif
#endif

    { .cmd = CY_SMIF_DDRQIOR,    .cmdTypeNum = 0u, .addrTypeNum = 5u, .modeTypeNum = 6u, .dataTypeNum = 5u },
    { .cmd = CY_SMIF_4DDRQIOR,   .cmdTypeNum = 0u, .addrTypeNum = 5u, .modeTypeNum = 6u, .dataTypeNum = 5u },
};

static const cy_stc_cmd_sq_t g_write_cmd_sq_types[] =
{
    {.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE}, // cmdTypeNum = 0
};

static const cy_stc_addr_sq_t g_write_addr_sq_types[] =
{
    {.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR}, // addrTypeNum = 0
};

static const cy_stc_mode_sq_t g_write_mode_sq_types[] =
{
    {.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_NOT_PRESENT  }, // modeTypeNum = 0
};

static const cy_stc_data_sq_t g_write_data_sq_types[] =
{
    {.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR}, // dataTypeNum = 0
    {.width = CY_SMIF_WIDTH_QUAD,   .dataRate = CY_SMIF_SDR}, // dataTypeNum = 1
};

static const cy_stc_write_cmd_info_t g_write_cmd_info[] =
{
    { .cmd = CY_SMIF_PP,   .cmdTypeNum   = 0u, .addrTypeNum  = 0u, .modeTypeNum  = 0u, .dataTypeNum  = 0u },
    { .cmd = CY_SMIF_4PP,  .cmdTypeNum   = 0u, .addrTypeNum  = 0u, .modeTypeNum  = 0u, .dataTypeNum  = 0u },
    { .cmd = CY_SMIF_QPP,  .cmdTypeNum   = 0u, .addrTypeNum  = 0u, .modeTypeNum  = 0u, .dataTypeNum  = 1u },
#if (CY_SMIF_QUAD_DEVICE_TYPE == CY_SMIF_S25FXXXS)
    { .cmd = CY_SMIF_QPPA, .cmdTypeNum   = 0u, .addrTypeNum  = 0u, .modeTypeNum  = 0u, .dataTypeNum  = 1u },
#endif
    { .cmd = CY_SMIF_4QPP, .cmdTypeNum   = 0u, .addrTypeNum  = 0u, .modeTypeNum  = 0u, .dataTypeNum  = 1u },
};

#define CY_SMIF_WRITE_CMD_NUM (sizeof(g_write_cmd_info)/sizeof(cy_stc_write_cmd_info_t))
#define CY_SMIF_READ_CMD_NUM  (sizeof(g_read_cmd_info)/sizeof(cy_stc_read_cmd_info_t))



/*******************************************************************************
* Function Name: Cy_SMIF_InitDeviceForS25FL
****************************************************************************//**
*
* \param
*
* \note This function assumes that the external memory is 
*       Cypress HSSPI memory (S25FL128S/S25FL256S series)
*
* \return
*     - \ref CY_SMIF_BAD_PARAM
*     - \ref CY_SMIF_SUCCESS
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_InitDeviceForS25FL(volatile stc_SMIF_DEVICE_t *device, cy_en_smif_device_type_t devType, const cy_stc_device_s25fl_config_t *config)
{
    uint32_t startAddress  = config->addr;
    
    uint32_t maxDeviceSize = (~(CY_SMIF_GetXIP_Mask(device))) + 1UL;
    
    uint32_t size          = Cy_SMIF_MaskValueToSizeInByte(config->size);
    uint32_t endAddress    = config->addr + size - 1;
    cy_un_smif_device_type_t devTypeTmp   = { .en = devType };
    cy_en_smif_xip_addr_byte_t addrSize;

    /********************/
    /* Check parameters */
    /********************/
    if(startAddress < CY_SMIF_GetXIP_Address(device))
    {
        return CY_SMIF_BAD_PARAM;
    }

    if(endAddress > ((uint32_t)CY_SMIF_GetXIP_Address(device) + maxDeviceSize - 1UL))
    {
        return CY_SMIF_BAD_PARAM;
    }

    {
        cy_en_smif_xip_addr_byte_t readCmdAddrByte  = CY_SMIF_GetAddrByteFromCmd((uint8_t)(config->xipReadCmd));
        cy_en_smif_xip_addr_byte_t writeCmdAddrByte = CY_SMIF_GetAddrByteFromCmd((uint8_t)(config->xipWriteCmd));
        cy_en_smif_xip_addr_byte_t requiredAddrByte = CY_SMIF_GetAddrByteSizeFromMemSize(size);
        if(readCmdAddrByte < requiredAddrByte)
        {
            return CY_SMIF_BAD_PARAM;
        }
        else if(writeCmdAddrByte < requiredAddrByte)
        {
            return CY_SMIF_BAD_PARAM;
        }

        addrSize = (readCmdAddrByte >= writeCmdAddrByte) ?  readCmdAddrByte : writeCmdAddrByte;
    }

    /*********************/
    /*   Set registers   */
    /*********************/
    Cy_SMIF_DeviceSetDataSelect(device, (cy_en_smif_data_select_t)devTypeTmp.bits.dataSel);
    Cy_SMIF_DeviceWriteEnable(device);
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

    Cy_SMIF_SetXIPAddrCtl(device, addrSize, (bool)devTypeTmp.bits.IsDualQuad);

    uint8_t readDummySize;
    readDummySize     = CY_SMIF_DummyCycleEachReadCmd(config->xipReadCmd, config->lc_spi);

    CY_SMIF_SetXIPReadSequence(device, config->xipReadCmd, config->xipReadMode, readDummySize, (bool)devTypeTmp.bits.IsDualQuad);

    CY_SMIF_SetXIPWriteSequence(device, config->xipWriteCmd, (bool)devTypeTmp.bits.IsDualQuad);

    Cy_SMIF_DeviceEnable(device);

    return CY_SMIF_SUCCESS;
}


// Latency Code to Dummy Cycle table
#if (CY_SMIF_QUAD_DEVICE_TYPE == CY_SMIF_S25FXXXS)

  #ifdef S25FL_USE_LC_ENHANCED
static const uint8_t LC_To_DC[9/*command num*/][4/*latency code*/] =
{
//LC: b'00 b'01 b'10 b'11
       {0u,  0u,  0u,  0u}, // CY_SMIF_READ,      CY_SMIF_4READ
       {8u,  8u,  8u,  0u}, // CY_SMIF_FAST_READ, CY_SMIF_4FAST_READ
       {8u,  8u,  8u,  0u}, // CY_SMIF_DOR,       CY_SMIF_4DOR
       {2u,  4u,  5u,  1u}, // CY_SMIF_DDRFR,     CY_SMIF_4DDRFR
       {8u,  8u,  8u,  0u}, // CY_SMIF_QOR,       CY_SMIF_4QOR
       {0u,  1u,  2u,  0u}, // CY_SMIF_DIOR,      CY_SMIF_4DIOR
       {4u,  5u,  6u,  2u}, // CY_SMIF_DDRDIOR,   CY_SMIF_4DDRDIOR
       {4u,  4u,  5u,  1u}, // CY_SMIF_QIOR,      CY_SMIF_4QIOR
       {6u,  7u,  8u,  3u}, // CY_SMIF_DDRQIOR,   CY_SMIF_4DDRQIOR
};
  #else
static const uint8_t LC_To_DC[9][4] =
{
//LC: b'00 b'01 b'10 b'11
       {0u,  0u,  0u,  0u}, // CY_SMIF_READ,      CY_SMIF_4READ
       {8u,  8u,  8u,  0u}, // CY_SMIF_FAST_READ, CY_SMIF_4FAST_READ
       {8u,  8u,  8u,  0u}, // CY_SMIF_DOR,       CY_SMIF_4DOR
       {5u,  6u,  7u,  4u}, // CY_SMIF_DDRFR,     CY_SMIF_4DDRFR
       {8u,  8u,  8u,  0u}, // CY_SMIF_QOR,       CY_SMIF_4QOR
       {4u,  5u,  6u,  4u}, // CY_SMIF_DIOR,      CY_SMIF_4DIOR
       {6u,  7u,  8u,  4u}, // CY_SMIF_DDRDIOR,   CY_SMIF_4DDRDIOR
       {4u,  4u,  5u,  1u}, // CY_SMIF_QIOR,      CY_SMIF_4QIOR
       {6u,  7u,  8u,  3u}, // CY_SMIF_DDRQIOR,   CY_SMIF_4DDRQIOR
};
  #endif
#elif (CY_SMIF_QUAD_DEVICE_TYPE == CY_SMIF_S25FXXXL)
static const uint8_t LC_To_DC[9/*command num*/][16/*latency code*/] =
{
//LC: b'00 b'01 b'10 b'11
       {0u,  0u,  0u,  0u, 0u,  0u,  0u,  0u, 0u,  0u,  0u,  0u,  0u,  0u,  0u,  0u}, // CY_SMIF_READ,      CY_SMIF_4READ
       {0u,  1u,  2u,  3u, 4u,  5u,  6u,  7u, 8u,  9u, 10u, 11u, 12u, 13u, 14u, 15u}, // CY_SMIF_FAST_READ, CY_SMIF_4FAST_READ
       {0u,  1u,  2u,  3u, 4u,  5u,  6u,  7u, 8u,  9u, 10u, 11u, 12u, 13u, 14u, 15u}, // CY_SMIF_DOR,       CY_SMIF_4DOR
       {0u,  0u,  0u,  0u, 0u,  0u,  0u,  0u, 0u,  0u,  0u,  0u,  0u,  0u,  0u,  0u}, // Dummy
       {0u,  1u,  2u,  3u, 4u,  5u,  6u,  7u, 8u,  9u, 10u, 11u, 12u, 13u, 14u, 15u}, // CY_SMIF_QOR,       CY_SMIF_4QOR
       {0u,  1u,  2u,  3u, 4u,  5u,  6u,  7u, 8u,  9u, 10u, 11u, 12u, 13u, 14u, 15u}, // CY_SMIF_DIOR,      CY_SMIF_4DIOR
       {0u,  0u,  0u,  0u, 0u,  0u,  0u,  0u, 0u,  0u,  0u,  0u,  0u,  0u,  0u,  0u}, // Dummy
       {0u,  1u,  2u,  3u, 4u,  5u,  6u,  7u, 8u,  9u, 10u, 11u, 12u, 13u, 14u, 15u}, // CY_SMIF_QIOR,      CY_SMIF_4QIOR
       {0u,  1u,  2u,  3u, 4u,  5u,  6u,  7u, 8u,  9u, 10u, 11u, 12u, 13u, 14u, 15u}, // CY_SMIF_DDRQIOR,   CY_SMIF_4DDRQIOR
};
#endif
#define CY_SMIF_MAX_DUMMY_CYCLE_S25F (8u)
/*******************************************************************************
* Function Name CY_SMIF_DummyCycleEachReadCmd
****************************************************************************//**
*
* \param cmd (see \cy_en_smif_rd_cmd_t)
*
* \param lc_spi (see \cy_en_smif_spi_latency_code_t)
*
* \return proper dummy cycle for input cmmand and latency code.
*
*******************************************************************************/
static uint8_t CY_SMIF_DummyCycleEachReadCmd(cy_en_smif_rd_cmd_t cmd, cy_en_smif_spi_latency_code_t lc_spi)
{
    if((cmd == CY_SMIF_READ) || (cmd ==CY_SMIF_4READ))
    {
        return LC_To_DC[0][lc_spi];
    }
    else if((cmd == CY_SMIF_FAST_READ) || (cmd == CY_SMIF_4FAST_READ))
    {
        return LC_To_DC[1][lc_spi];
    }
    else if((cmd == CY_SMIF_DOR) || (cmd == CY_SMIF_4DOR))
    {
        return LC_To_DC[2][lc_spi];
    }
#if (CY_SMIF_QUAD_DEVICE_TYPE == CY_SMIF_S25FXXXS)
    else if((cmd == CY_SMIF_DDRFR) || (cmd == CY_SMIF_4DDRFR))
    {
        return LC_To_DC[3][lc_spi];
    }
#endif
    else if((cmd == CY_SMIF_QOR) || (cmd == CY_SMIF_4QOR))
    {
        return LC_To_DC[4][lc_spi];
    }
    else if((cmd == CY_SMIF_DIOR) || (cmd == CY_SMIF_4DIOR))
    {
        return LC_To_DC[5][lc_spi];
    }
#if (CY_SMIF_QUAD_DEVICE_TYPE == CY_SMIF_S25FXXXS)
    else if((cmd == CY_SMIF_DDRDIOR) || (cmd == CY_SMIF_4DDRDIOR))
    {
        return LC_To_DC[6][lc_spi];
    }
#endif
    else if((cmd == CY_SMIF_QIOR) || (cmd == CY_SMIF_4QIOR))
    {
        return LC_To_DC[7][lc_spi];
    }
    else if((cmd == CY_SMIF_DDRQIOR) || (cmd == CY_SMIF_4DDRQIOR))
    {
        return LC_To_DC[8][lc_spi];
    }
    else
    {
        return 0ul;
    }
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
* Function CY_SMIF_GetReadCmdInfoNum
****************************************************************************//**
*
* \param cmd (see \cy_en_smif_rd_cmd_t)
*
* \return
*  Commad number which is defined and used internally
*
*******************************************************************************/
static uint8_t CY_SMIF_GetReadCmdInfoNum(cy_en_smif_rd_cmd_t cmd)
{
    for(uint8_t i_cmd = 0u; i_cmd < CY_SMIF_READ_CMD_NUM; i_cmd++)
    {
        if(g_read_cmd_info[i_cmd].cmd == cmd)
        {
            return i_cmd;
        }
    }

    CY_ASSERT_L3(false);
}

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
* Function CY_SMIF_SetXIPReadSequence
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
static void CY_SMIF_SetXIPReadSequence(volatile stc_SMIF_DEVICE_t *device, cy_en_smif_rd_cmd_t cmd, cy_en_smif_rw_mode_t mode, uint8_t dummySize, bool dualQuad)
{
    uint8_t readCmdNum = CY_SMIF_GetReadCmdInfoNum(cmd);

    /************************/
    /*** Set read command ***/
    /************************/
    /* Prepare the parameters */
    stc_cy_smif_cmd_mode_ctl_t rdCmdParams;
    if(mode == CY_SMIF_XIP_RW_NON_CONTINUOUS)
    {
        uint8_t cmdTypeNum = g_read_cmd_info[readCmdNum].cmdTypeNum;
        rdCmdParams.cmd       = (uint16_t)cmd;
        rdCmdParams.width     = g_read_cmd_sq_types[cmdTypeNum].width;
        rdCmdParams.dataRate  = g_read_cmd_sq_types[cmdTypeNum].dataRate;
        rdCmdParams.presence  = g_read_cmd_sq_types[cmdTypeNum].presence;
    }
    else
    {
        rdCmdParams.cmd       = (uint16_t)0x0000;
        rdCmdParams.width     = CY_SMIF_WIDTH_SINGLE;
        rdCmdParams.dataRate  = CY_SMIF_SDR;
        rdCmdParams.presence  = CY_SMIF_NOT_PRESENT;
    }
    /* Set the parameters */
    Cy_SMIF_SetReadCmdCtl(device, &rdCmdParams);

    /************************/
    /*** Set read address ***/
    /************************/
    /* Prepare the parameters */
    stc_cy_smif_addr_data_ctl_t rdAddrParams;
    uint8_t addrTypeNum = g_read_cmd_info[readCmdNum].addrTypeNum;
    rdAddrParams.width    = g_read_addr_sq_types[addrTypeNum].width;
    rdAddrParams.dataRate = g_read_addr_sq_types[addrTypeNum].dataRate;
    /* Set the parameters */
    Cy_SMIF_SetReadAddrCtl(device, &rdAddrParams);

    /************************/
    /***  Set read mode  ***/
    /************************/
    /* Prepare the parameters */
    uint8_t modeTypeNum = g_read_cmd_info[readCmdNum].modeTypeNum;
    stc_cy_smif_cmd_mode_ctl_t rdModeParams;
    rdModeParams.cmd      = mode;
    rdModeParams.width    = g_read_mode_sq_types[modeTypeNum].width;
    rdModeParams.dataRate = g_read_mode_sq_types[modeTypeNum].dataRate;
    rdModeParams.presence = g_read_mode_sq_types[modeTypeNum].presence;
    /* Set the parameters */
    Cy_SMIF_SetReadModeCtl(device, &rdModeParams);

    /************************/
    /***  Set read dummy  ***/
    /************************/
    /* Prepare the parameters */
    stc_cy_smif_rd_dummy_ctl_t rdDummyParams;
    rdDummyParams.numOfDummy = dummySize;
    rdDummyParams.presence   = CY_SMIF_PRESENT_1BYTE;
    /* Set the parameters */
    Cy_SMIF_SetReadDummyCtl(device, &rdDummyParams);

    /************************/
    /***  Set read data   ***/
    /************************/
    /* Prepare the parameters */
    uint8_t dataTypeNum = g_read_cmd_info[readCmdNum].dataTypeNum;
    stc_cy_smif_addr_data_ctl_t rdDataParams;
    rdDataParams.width    = (dualQuad == true) ? CY_SMIF_WIDTH_OCTAL : g_read_data_sq_types[dataTypeNum].width;
    rdDataParams.dataRate = g_read_data_sq_types[dataTypeNum].dataRate;
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
static uint8_t CY_SMIF_GetWriteCmdInfoNum(cy_en_smif_wt_cmd_t cmd)
{
    for(uint8_t i_cmd = 0u; i_cmd < CY_SMIF_WRITE_CMD_NUM; i_cmd++)
    {
        if(g_write_cmd_info[i_cmd].cmd == cmd)
        {
            return i_cmd;
        }
    }

    CY_ASSERT_L3(false);
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
static void CY_SMIF_SetXIPWriteSequence(volatile stc_SMIF_DEVICE_t *device, cy_en_smif_wt_cmd_t cmd, bool dualQuad)
{
    uint8_t writeCmdNum = CY_SMIF_GetWriteCmdInfoNum(cmd);

    /*************************/
    /*** Set write command ***/
    /*************************/
    /* Prepare the parameters */
    stc_cy_smif_cmd_mode_ctl_t wtCmdParams;
    uint8_t cmdTypeNum = g_write_cmd_info[writeCmdNum].cmdTypeNum;
    wtCmdParams.cmd       = (uint16_t)cmd;
    wtCmdParams.width     = g_write_cmd_sq_types[cmdTypeNum].width;
    wtCmdParams.dataRate  = g_write_cmd_sq_types[cmdTypeNum].dataRate;
    wtCmdParams.presence  = g_write_cmd_sq_types[cmdTypeNum].presence;
    /* Set the parameters */
    Cy_SMIF_SetWriteCmdCtl(device, &wtCmdParams);

    /*************************/
    /*** Set write address ***/
    /*************************/
    /* Prepare the parameters */
    stc_cy_smif_addr_data_ctl_t wtAddrParams;
    uint8_t addrTypeNum = g_write_cmd_info[writeCmdNum].addrTypeNum;
    wtAddrParams.width    = g_write_addr_sq_types[addrTypeNum].width;
    wtAddrParams.dataRate = g_write_addr_sq_types[addrTypeNum].dataRate;
    /* Set the parameters */
    Cy_SMIF_SetWriteAddrCtl(device, &wtAddrParams);

    /************************/
    /***  Set write mode  ***/
    /************************/
    /* Prepare the parameters */
    uint8_t modeTypeNum = g_write_cmd_info[writeCmdNum].modeTypeNum;
    stc_cy_smif_cmd_mode_ctl_t wtModeParams;
    wtModeParams.cmd      = (uint16_t)0x0000;
    wtModeParams.width    = g_write_mode_sq_types[modeTypeNum].width;
    wtModeParams.dataRate = g_write_mode_sq_types[modeTypeNum].dataRate;
    wtModeParams.presence = g_write_mode_sq_types[modeTypeNum].presence;
    /* Set the parameters */
    Cy_SMIF_SetWriteModeCtl(device, &wtModeParams);

    /*************************/
    /***  Set write dummy  ***/
    /*************************/
    /* Prepare the parameters */
    stc_cy_smif_wr_dummy_ctl_t wtDummyParams;
    wtDummyParams.numOfDummy = 0u;
    wtDummyParams.presence   = CY_SMIF_NOT_PRESENT;
    wtDummyParams.rwdsEn     = false;
    /* Set the parameters */
    Cy_SMIF_SetWriteDummyCtl(device, &wtDummyParams);

    /************************/
    /***  Set read data   ***/
    /************************/
    /* Prepare the parameters */
    uint8_t dataTypeNum = g_write_cmd_info[writeCmdNum].dataTypeNum;
    stc_cy_smif_addr_data_ctl_t wtDataParams;
    wtDataParams.width    = (dualQuad == true) ? CY_SMIF_WIDTH_OCTAL : g_write_data_sq_types[dataTypeNum].width;
    wtDataParams.dataRate = g_write_data_sq_types[dataTypeNum].dataRate;
    /* Set the parameters */
    Cy_SMIF_SetWriteDataCtl(device, &wtDataParams);

    /************************/
    /***   Set read CRC   ***/
    /************************/
    /* Prepare the parameters */
    stc_cy_smif_wr_crc_ctl_t wtCRCParams = { 0u };
    /* Set the parameters */
    Cy_SMIF_SetWriteCrcCtl(device, &wtCRCParams);

    return;

}

/***********************************************************************/
/******************* Functions Issuing Each Commands *******************/
/***********************************************************************/


/*******************************************************************************
* Function Cy_SMIF_S25FL_Read
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_Read(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_en_smif_rd_cmd_t readCmd,
                                        uint32_t readAddress,
                                        uint32_t size,
                                        uint8_t buf[],
                                        cy_en_smif_spi_latency_code_t lcCode,
                                        cy_en_smif_rw_mode_t mode,
                                        cy_en_smif_block_mode_t blockingMode,
                                        cy_stc_smif_context_t *context)
{
    cy_en_smif_status_t status;
    cy_en_smif_xip_addr_byte_t addrSize = CY_SMIF_GetAddrByteFromCmd(readCmd);
    uint8_t addrSizeInByte;
    uint32_t addrInBigEndian;

    if(addrSize == CY_SMIF_XIP_ADDRESS_4_BYTE)
    {
        // No need to check
        addrSizeInByte = 4u;
        addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(readAddress);
    }
    else if(addrSize == CY_SMIF_XIP_ADDRESS_3_BYTE)
    {
        if(readAddress > 0x00FFFFFFul)
        {
            CY_ASSERT_L1(false);
        }
        addrSizeInByte = 3u;
        addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(readAddress << 8ul);
    }
    else
    {
        CY_ASSERT_L1(false);
    }

    uint8_t readCmdNum = CY_SMIF_GetReadCmdInfoNum(readCmd);
    uint8_t cmdTypeNum = g_read_cmd_info[readCmdNum].cmdTypeNum;
    uint8_t addrTypeNum = g_read_cmd_info[readCmdNum].addrTypeNum;

    /****** Command and Address ******/
    status = Cy_SMIF_TransmitCommand(base,
                                     (uint8_t)readCmd,                          /* command value */
                                     false,
                                     g_read_cmd_sq_types[cmdTypeNum].width,     /* command width */
                                     g_read_cmd_sq_types[cmdTypeNum].dataRate,  /* command rate */
                                     (uint8_t*)&addrInBigEndian,                /* Data pointer */
                                     addrSizeInByte,                            /* Data size */
                                     g_read_addr_sq_types[addrTypeNum].width,   /* data width */
                                     g_read_addr_sq_types[addrTypeNum].dataRate,/* data rate */
                                     slave,                /* slave select */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    /****** Mode ******/
    uint8_t modeTypeNum = g_read_cmd_info[readCmdNum].modeTypeNum;
    if(g_read_mode_sq_types[modeTypeNum].presence != CY_SMIF_NOT_PRESENT)
    {
        status = Cy_SMIF_TransmitCommand(base,
                                         mode,
                                         false,
                                         g_read_mode_sq_types[modeTypeNum].width,   /* command width */
                                         g_read_mode_sq_types[modeTypeNum].dataRate,/* command rate */
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
    uint8_t dummyCycle = CY_SMIF_DummyCycleEachReadCmd(readCmd, lcCode);
    if(dummyCycle > 0u)
    {
        status = Cy_SMIF_SendDummyCycles(base, 
                                         CY_SMIF_WIDTH_SINGLE,  /* command width */
                                         CY_SMIF_SDR,          /* command rate */
                                         false, false, false, false,
                                         dummyCycle);
        if(status != CY_SMIF_SUCCESS)
        {
            return status;
        }
    }

    uint8_t dataTypeNum = g_read_cmd_info[readCmdNum].dataTypeNum;
    cy_en_smif_txfr_width_t width;
    if((CY_SMIF_GetSlaveNumber(base, slave) == 2u) && (g_read_data_sq_types[dataTypeNum].width == CY_SMIF_WIDTH_QUAD))
    {
        width = CY_SMIF_WIDTH_OCTAL;
    }
    else
    {
        width = g_read_data_sq_types[dataTypeNum].width;
    }

    if(blockingMode == CY_SMIF_BLOCKING)
    {
        status = Cy_SMIF_ReceiveDataBlocking(base, buf, size, width, g_read_data_sq_types[dataTypeNum].dataRate, slave, context);
    }
    else
    {
        status = Cy_SMIF_ReceiveData(base, buf, size, width, g_read_data_sq_types[dataTypeNum].dataRate, slave, NULL, context);
    }
    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_Program
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_Program(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_en_smif_wt_cmd_t writeCmd,
                                        uint32_t programedAddress,
                                        uint32_t size,
                                        const uint8_t buf[],
                                        cy_en_smif_block_mode_t blockingMode,
                                        cy_stc_smif_context_t *context)
{
    cy_en_smif_status_t status;
    cy_en_smif_xip_addr_byte_t writeCmdAddrByte = CY_SMIF_GetAddrByteFromCmd((uint8_t)writeCmd);
    uint8_t addrSizeInByte;
    uint32_t addrInBigEndian;

    if(writeCmdAddrByte == CY_SMIF_XIP_ADDRESS_4_BYTE)
    {
        // No need to check
        addrSizeInByte = 4u;
        addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(programedAddress);
    }
    else if(writeCmdAddrByte == CY_SMIF_XIP_ADDRESS_3_BYTE)
    {
        if(programedAddress > 0x00FFFFFFul)
        {
            CY_ASSERT_L1(false);
        }
        addrSizeInByte = 3u;
        addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(programedAddress << 8ul);
    }
    else
    {
        CY_ASSERT_L1(false);
    }

    uint8_t writeCmdNum = CY_SMIF_GetWriteCmdInfoNum(writeCmd);

    /****** Command and Address ******/
    uint8_t cmdTypeNum  = g_write_cmd_info[writeCmdNum].cmdTypeNum;
    uint8_t addrTypeNum = g_write_cmd_info[writeCmdNum].addrTypeNum;
    status = Cy_SMIF_TransmitCommand(base,
                                     (uint8_t)writeCmd,                          /* command value */
                                     false,
                                     g_write_cmd_sq_types[cmdTypeNum].width,     /* command width */
                                     g_write_cmd_sq_types[cmdTypeNum].dataRate,  /* command rate */
                                     (uint8_t*)&addrInBigEndian,                          /* Data pointer */
                                     addrSizeInByte,                            /* Data size */
                                     g_write_addr_sq_types[addrTypeNum].width,   /* data width */
                                     g_write_addr_sq_types[addrTypeNum].dataRate,/* data rate */
                                     slave,                /* slave select */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    uint8_t dataTypeNum = g_write_cmd_info[writeCmdNum].dataTypeNum;
    cy_en_smif_txfr_width_t width;

    // Check if it indicate dual quad mode.
    if((CY_SMIF_GetSlaveNumber(base, slave) == 2u) && (g_write_data_sq_types[dataTypeNum].width == CY_SMIF_WIDTH_QUAD))
    {
        // Dual quad
        width = CY_SMIF_WIDTH_OCTAL;
    }
    else
    {
        // Not dual quad
        width = g_write_data_sq_types[dataTypeNum].width;
    }

    if(blockingMode == CY_SMIF_BLOCKING)
    {
        Cy_SMIF_TransmitDataBlocking(base, buf, size, width, g_write_data_sq_types[dataTypeNum].dataRate, slave, context);
    }
    else
    {
        Cy_SMIF_TransmitData(base, buf, size, width, g_write_data_sq_types[dataTypeNum].dataRate, slave, NULL, context);
    }

    return status;
}


/*******************************************************************************
* Function Cy_SMIF_S25FL_ReadJedecId
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ReadJedecId(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_stc_JedecId_t* readData,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_RDID   ,  /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     NULL,                 /* Data pointer */
                                     0,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    status = Cy_SMIF_ReceiveDataBlocking(base, (uint8_t*)readData, 0x51u, CY_SMIF_WIDTH_SINGLE, CY_SMIF_SDR, slave, context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_ReadStatusRegister1
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ReadStatusRegister1(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint8_t* readData,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_RDSR1,    /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     NULL,                 /* Data pointer */
                                     0,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    status = Cy_SMIF_ReceiveDataBlocking(base, readData, 1u, CY_SMIF_WIDTH_SINGLE, CY_SMIF_SDR, slave, context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_ReadStatusRegister2
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ReadStatusRegister2(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint8_t* readData,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_RDSR2,    /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     NULL,                 /* Data pointer */
                                     0,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    status = Cy_SMIF_ReceiveDataBlocking(base, readData, 1u, CY_SMIF_WIDTH_SINGLE, CY_SMIF_SDR, slave, context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_ReadConfigurationRegister
****************************************************************************//**
*
* Read data does not support multiple slave access at the same time.
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ReadConfigurationRegister(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint8_t* readData,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_RDCR1,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     NULL,                 /* Data pointer */
                                     0,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    status = Cy_SMIF_ReceiveDataBlocking(base, readData, 1u, CY_SMIF_WIDTH_SINGLE, CY_SMIF_SDR, slave, context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_WriteStatusAndConfigRegister
****************************************************************************//**
*
* \param
*
* \return
*
* \note if writeRegNum is less than "4", all register won't be written.
*       e.g. if writeRegNum = 2, status register 1 and configuration register 2
             will be written.
*******************************************************************************/
// YOTS: Need to modify
cy_en_smif_status_t Cy_SMIF_S25FL_WriteStatusAndConfigRegister(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        stc_cy_smif_s25f_write_reg_t* writeRegs,
                                        uint8_t writeRegNum,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_WRR,      /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     (uint8_t*)writeRegs,  /* Data pointer */
                                     writeRegNum,          /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_WriteDisable
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_WriteDisable(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_WRDI,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     NULL,                 /* Data pointer */
                                     0,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_WriteEnable
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_WriteEnable(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_WREN,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     NULL,                 /* Data pointer */
                                     0,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_ClearStatusRegister
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ClearStatusRegister(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_CLSR,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     NULL,                 /* Data pointer */
                                     0,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);

    return status;
}


/*******************************************************************************
* Function Cy_SMIF_S25FL_DataLeaningPatternRead
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_DataLeaningPatternRead(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint8_t *readDLP,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_DLPRD,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     NULL,                 /* Data pointer */
                                     0,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);

    status = Cy_SMIF_ReceiveDataBlocking(base, readDLP, 1u, CY_SMIF_WIDTH_SINGLE, CY_SMIF_SDR, slave, context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_ProgramNVDLR
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ProgramNVDLR(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint8_t writeData,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;

    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_PDLRNV,   /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     &writeData,           /* Data pointer */
                                     1,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_WriteVDLR
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_WriteVDLR(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint8_t writeData,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;

    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_WDLRV,    /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     &writeData,           /* Data pointer */
                                     1,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_SectorErase
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_SectorErase(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint32_t erasedAddress,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    en_cy_smif_s25f_cmd_t eraseCmd;
    uint8_t  addrSizeInByte;
    uint32_t addrInBigEndian;
    if(erasedAddress > 0x00FFFFFFul)
    {
        eraseCmd = CY_SMIF_CMD_4SE;
        addrSizeInByte = 4ul;
        addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(erasedAddress);
    }
    else
    {
        // assuming that ExtAdd == 0;
        eraseCmd = CY_SMIF_CMD_SE;
        addrSizeInByte = 3ul;
        addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(erasedAddress << 8ul);
    }

    status = Cy_SMIF_TransmitCommand(base,
                                     (uint8_t)eraseCmd,    /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     (uint8_t*)&addrInBigEndian,     /* Data pointer */
                                     addrSizeInByte,       /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);
    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_ChipErase
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ChipErase(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_CE,       /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     NULL,                 /* Data pointer */
                                     0,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_PasswordRead
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_PasswordRead(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint64_t* readPW,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_PASSRD,   /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate  */
                                     NULL,                 /* Data pointer  */
                                     0,                    /* Data size     */
                                     CY_SMIF_WIDTH_SINGLE, /* data width    */
                                     CY_SMIF_SDR,          /* data rate     */
                                     slave,                /* slave select  */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    Cy_SMIF_ReceiveDataBlocking(base, (uint8_t*)readPW, 8u, CY_SMIF_WIDTH_SINGLE, CY_SMIF_SDR, slave, context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_PasswordProgram
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_PasswordProgram(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint64_t  programPW,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_PASSP,    /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate  */
                                     (uint8_t*)&programPW,           /* Data pointer  */
                                     8u,                   /* Data size     */
                                     CY_SMIF_WIDTH_SINGLE, /* data width    */
                                     CY_SMIF_SDR,          /* data rate     */
                                     slave,                /* slave select  */
                                     LAST_COMMAND_BYTE,
                                     context);
    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_PasswordUnlock
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_PasswordUnlock(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint64_t  inputPW,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_PASSU,    /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate  */
                                     (uint8_t*)&inputPW,   /* Data pointer  */
                                     8u,                   /* Data size     */
                                     CY_SMIF_WIDTH_SINGLE, /* data width    */
                                     CY_SMIF_SDR,          /* data rate     */
                                     slave,                /* slave select  */
                                     LAST_COMMAND_BYTE,
                                     context);
    return status;
}


/*******************************************************************************
* Function Cy_SMIF_S25FL_SoftwareReset
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_SoftwareReset(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_RST,    /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate  */
                                     NULL,                 /* Data pointer  */
                                     0u,                   /* Data size     */
                                     CY_SMIF_WIDTH_SINGLE, /* data width    */
                                     CY_SMIF_SDR,          /* data rate     */
                                     slave,                /* slave select  */
                                     LAST_COMMAND_BYTE,
                                     context);
    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_ModeBitReset
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ModeBitReset(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_MBR,      /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate  */
                                     NULL,                 /* Data pointer  */
                                     0u,                   /* Data size     */
                                     CY_SMIF_WIDTH_SINGLE, /* data width    */
                                     CY_SMIF_SDR,          /* data rate     */
                                     slave,                /* slave select  */
                                     LAST_COMMAND_BYTE,
                                     context);
    return status;
}


#if (CY_SMIF_QUAD_DEVICE_TYPE == CY_SMIF_S25FXXXS)


/*******************************************************************************
* Function Cy_SMIF_S25FL_ReadId
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ReadId(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint8_t* readManufactureID,
                                        uint8_t* readDeviceID,
                                        cy_stc_smif_context_t const *context)
{
    uint8_t dummyAddress[3] = {0x00u};
    uint8_t recievedData[2] = {0x00u};

    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_READ_ID,  /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     dummyAddress,         /* Data pointer */
                                     3,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    status = Cy_SMIF_ReceiveDataBlocking(base, recievedData, 2u, CY_SMIF_WIDTH_SINGLE, CY_SMIF_SDR, slave, context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    *readManufactureID = recievedData[0];
    *readDeviceID      = recievedData[1];

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_ReadElectronicSignature
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ReadElectronicSignature(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint8_t* readData,
                                        cy_stc_smif_context_t const *context)
{
    uint8_t dummyAddress[3] = {0x00u};
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_RES,      /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     dummyAddress,         /* Data pointer */
                                     3,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    status = Cy_SMIF_ReceiveDataBlocking(base, readData, 1u, CY_SMIF_WIDTH_SINGLE, CY_SMIF_SDR, slave, context);

    return status;
}


/*******************************************************************************
* Function Cy_SMIF_S25FL_ReadBankRegister
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ReadBankRegister(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint8_t* readData,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_BRRD,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     NULL,                 /* Data pointer */
                                     0,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    status = Cy_SMIF_ReceiveDataBlocking(base, readData, 1u, CY_SMIF_WIDTH_SINGLE, CY_SMIF_SDR, slave, context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_WriteBankRegister
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_WriteBankRegister(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint8_t writeData,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_BRWR,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     &writeData,           /* Data pointer */
                                     1,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_AccessBankRegister
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_AccessBankRegister(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint8_t BarBit0,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    uint8_t writeData[2];
    writeData[0] = CY_SMIF_CMD_WRR; // YOTS: what is this?
    writeData[1] = BarBit0;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_BRAC,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     writeData,           /* Data pointer */
                                     2,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_WriteStatusRegister
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_WriteStatusRegister(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint8_t writeData,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_WRR,      /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     &writeData,           /* Data pointer */
                                     1,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);

    return status;
}


/*******************************************************************************
* Function Cy_SMIF_S25FL_ReadAutoBootRegister
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ReadAutoBootRegister(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint32_t* readData,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;

    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_ABRD,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     NULL,                 /* Data pointer */
                                     0,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    status = Cy_SMIF_ReceiveDataBlocking(base, (uint8_t*)readData, 4u, CY_SMIF_WIDTH_SINGLE, CY_SMIF_SDR, slave, context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_WriteAutoBootRegister
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_WriteAutoBootRegister(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint32_t writeData,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;

    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_ABWR,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     (uint8_t*)&writeData, /* Data pointer */
                                     4,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_ProgramSuspend
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ProgramSuspend(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_PGSP,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     NULL,                 /* Data pointer */
                                     0,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_ProgramResume
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ProgramResume(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_PGRS,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     NULL,                 /* Data pointer */
                                     0,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);

    return status;
}


/*******************************************************************************
* Function Cy_SMIF_S25FL_4KB_SectorErase
****************************************************************************//**
*
* Make sure the device is configured as 4-kB sectors
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_4KB_SectorErase(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint32_t erasedAddress,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    en_cy_smif_s25f_cmd_t eraseCmd;
    uint8_t  addrSizeInByte;
    uint32_t addrInBigEndian;
    if(erasedAddress > 0x00FFFFFFul)
    {
        eraseCmd = CY_SMIF_CMD_4P4E;
        addrSizeInByte = 4ul;
        addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(erasedAddress);
    }
    else
    {
        // assuming that ExtAdd == 0;
        eraseCmd = CY_SMIF_CMD_P4E;
        addrSizeInByte = 3ul;
        addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(erasedAddress << 8ul);
    }

    status = Cy_SMIF_TransmitCommand(base,
                                     (uint8_t)eraseCmd,    /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     (uint8_t*)&addrInBigEndian,     /* Data pointer */
                                     addrSizeInByte,       /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);
    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_EraseSuspend
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_EraseSuspend(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_ERSP,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     NULL,                 /* Data pointer */
                                     0,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_EraseResume
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_EraseResume(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_ERRS,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     NULL,                 /* Data pointer */
                                     0,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_OPT_Program
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_OPT_Program(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint32_t programedAddress,
                                        uint32_t size,
                                        uint8_t buf[],
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    uint32_t addrInBigEndian;

    if(programedAddress > 0x000003FFul)
    {
        CY_ASSERT_L1(false);
    }
    addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(programedAddress << 8ul);

    /****** Command and Address ******/
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_OTPP,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     (uint8_t*)&addrInBigEndian,     /* Data pointer */
                                     3,       /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    Cy_SMIF_TransmitDataBlocking(base, buf, size, CY_SMIF_WIDTH_SINGLE, CY_SMIF_SDR, slave, context);
    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_OPT_Read
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_OPT_Read(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint32_t readAddress,
                                        uint32_t size,
                                        uint8_t buf[],
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    uint32_t addrInBigEndian;

    if(readAddress > 0x000003FFul)
    {
        CY_ASSERT_L1(false);
    }
    addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(readAddress << 8ul);

    /****** Command and Address ******/
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_OTPR,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate  */
                                     (uint8_t*)&addrInBigEndian,     /* Data pointer  */
                                     3,       /* Data size     */
                                     CY_SMIF_WIDTH_SINGLE, /* data width    */
                                     CY_SMIF_SDR,          /* data rate     */
                                     slave,                /* slave select  */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    Cy_SMIF_ReceiveDataBlocking(base, buf, size, CY_SMIF_WIDTH_SINGLE, CY_SMIF_SDR, slave, context);
    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_ASP_Read
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ASP_Read(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint16_t* readValue,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_ASPRD,    /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate  */
                                     NULL,                 /* Data pointer  */
                                     0,                    /* Data size     */
                                     CY_SMIF_WIDTH_SINGLE, /* data width    */
                                     CY_SMIF_SDR,          /* data rate     */
                                     slave,                /* slave select  */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    Cy_SMIF_ReceiveDataBlocking(base, (uint8_t*)readValue, 2u, CY_SMIF_WIDTH_SINGLE, CY_SMIF_SDR, slave, context);
    return status;
}


/*******************************************************************************
* Function Cy_SMIF_S25FL_ASP_Program
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ASP_Program(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint16_t* programedValue,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_ASPP,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate  */
                                     (uint8_t*)programedValue,       /* Data pointer  */
                                     2,                    /* Data size     */
                                     CY_SMIF_WIDTH_SINGLE, /* data width    */
                                     CY_SMIF_SDR,          /* data rate     */
                                     slave,                /* slave select  */
                                     LAST_COMMAND_BYTE,
                                     context);
    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_DYB_Read
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_DYB_Read(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint32_t readAddress,
                                        uint8_t* readValue,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    uint32_t addrInBigEndian;

    addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(readAddress);
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_DYBRD,    /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate  */
                                     (uint8_t*)&addrInBigEndian,     /* Data pointer  */
                                     4,                    /* Data size     */
                                     CY_SMIF_WIDTH_SINGLE, /* data width    */
                                     CY_SMIF_SDR,          /* data rate     */
                                     slave,                /* slave select  */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    Cy_SMIF_ReceiveDataBlocking(base, readValue, 1u, CY_SMIF_WIDTH_SINGLE, CY_SMIF_SDR, slave, context);
    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_DYB_Write
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_DYB_Write(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint32_t writeAddress,
                                        uint8_t  writeValue,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    uint8_t writtenData[5];
    uint32_t addrInBigEndian;

    addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(writeAddress);
    *(uint32_t*)writtenData = addrInBigEndian;
    writtenData[4] = writeValue;

    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_DYBWR,    /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate  */
                                     writtenData,          /* Data pointer  */
                                     5,                    /* Data size     */
                                     CY_SMIF_WIDTH_SINGLE, /* data width    */
                                     CY_SMIF_SDR,          /* data rate     */
                                     slave,                /* slave select  */
                                     LAST_COMMAND_BYTE,
                                     context);
    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_PPB_Read
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_PPB_Read(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint32_t readAddress,
                                        uint8_t* readValue,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    uint32_t addrInBigEndian;

    addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(readAddress);
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_PPBRD,    /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate  */
                                     (uint8_t*)&addrInBigEndian,     /* Data pointer  */
                                     4,                    /* Data size     */
                                     CY_SMIF_WIDTH_SINGLE, /* data width    */
                                     CY_SMIF_SDR,          /* data rate     */
                                     slave,                /* slave select  */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    Cy_SMIF_ReceiveDataBlocking(base, readValue, 1u, CY_SMIF_WIDTH_SINGLE, CY_SMIF_SDR, slave, context);
    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_PPB_Program
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_PPB_Program(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint32_t programedAddress,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    uint32_t addrInBigEndian;
    addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(programedAddress);

    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_PPBP,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate  */
                                     (uint8_t*)&addrInBigEndian,      /* Data pointer  */
                                     4,                    /* Data size     */
                                     CY_SMIF_WIDTH_SINGLE, /* data width    */
                                     CY_SMIF_SDR,          /* data rate     */
                                     slave,                /* slave select  */
                                     LAST_COMMAND_BYTE,
                                     context);
    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_PPB_Erase
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_PPB_Erase(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;

    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_PPBE,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate  */
                                     NULL,      /* Data pointer  */
                                     0,                    /* Data size     */
                                     CY_SMIF_WIDTH_SINGLE, /* data width    */
                                     CY_SMIF_SDR,          /* data rate     */
                                     slave,                /* slave select  */
                                     LAST_COMMAND_BYTE,
                                     context);
    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_PPB_LockBitRead
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_PPB_LockBitRead(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint8_t* readValue,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_PLBRD,    /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate  */
                                     NULL,                 /* Data pointer  */
                                     0,                    /* Data size     */
                                     CY_SMIF_WIDTH_SINGLE, /* data width    */
                                     CY_SMIF_SDR,          /* data rate     */
                                     slave,                /* slave select  */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    Cy_SMIF_ReceiveDataBlocking(base, readValue, 1u, CY_SMIF_WIDTH_SINGLE, CY_SMIF_SDR, slave, context);
    return status;
}


/*******************************************************************************
* Function Cy_SMIF_S25FL_PPB_LockBitWrite
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_PPB_LockBitWrite(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_PLBWR,    /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate  */
                                     NULL,                 /* Data pointer  */
                                     0,                    /* Data size     */
                                     CY_SMIF_WIDTH_SINGLE, /* data width    */
                                     CY_SMIF_SDR,          /* data rate     */
                                     slave,                /* slave select  */
                                     LAST_COMMAND_BYTE,
                                     context);
    return status;
}

#elif (CY_SMIF_QUAD_DEVICE_TYPE == CY_SMIF_S25FXXXL)

/*******************************************************************************
* Function Cy_SMIF_S25FL_ReadConfigurationRegister2
****************************************************************************//**
*
* Read data does not support multiple slave access at the same time.
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ReadConfigurationRegister2(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint8_t* readData,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_RDCR2,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     NULL,                 /* Data pointer */
                                     0,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    status = Cy_SMIF_ReceiveDataBlocking(base, readData, 1u, CY_SMIF_WIDTH_SINGLE, CY_SMIF_SDR, slave, context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_ReadConfigurationRegister3
****************************************************************************//**
*
* Read data does not support multiple slave access at the same time.
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ReadConfigurationRegister3(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        uint8_t* readData,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_RDCR3,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     NULL,                 /* Data pointer */
                                     0,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    status = Cy_SMIF_ReceiveDataBlocking(base, readData, 1u, CY_SMIF_WIDTH_SINGLE, CY_SMIF_SDR, slave, context);

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_S25FL_ProgramOrEraseSuspend
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_S25FL_ProgramOrEraseSuspend(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_stc_smif_context_t const *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_TransmitCommand(base,
                                     CY_SMIF_CMD_EPS,     /* command value */
                                     false,
                                     CY_SMIF_WIDTH_SINGLE, /* command width */
                                     CY_SMIF_SDR,          /* command rate */
                                     NULL,                 /* Data pointer */
                                     0,                    /* Data size */
                                     CY_SMIF_WIDTH_SINGLE, /* data width */
                                     CY_SMIF_SDR,          /* data rate */
                                     slave,                /* slave select */
                                     LAST_COMMAND_BYTE,
                                     context);

    return status;
}


#endif

#if defined(__cplusplus)
}
#endif
