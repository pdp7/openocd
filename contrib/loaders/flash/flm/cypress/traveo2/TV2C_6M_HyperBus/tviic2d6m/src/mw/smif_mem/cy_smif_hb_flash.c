/* cy_smif_hb_flash.c - Source Code for Cypress's Low Level Driver */

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */


#include "cy_smif_hb_flash.h"

#define CY_SMIF_HB_FLASH_BUFFER_SIZE (256*CY_SMIF_HB_FLASH_BUF_SIZE_MULTIPLIER)
#define CY_SMIF_HB_FLASH_SUSP_RESUME_DELAY  40

/* private functions */

/* Public Functions  */

cy_en_smif_status_t Cy_SMIF_InitDeviceHyperBus(volatile stc_SMIF_DEVICE_t *device, const cy_stc_device_hb_config_t *config)
{
    /********************/
    /* Check parameters */
    /********************/
    uint32_t startAddress  = config->addr;
    uint32_t maxDeviceSize = (~(CY_SMIF_GetXIP_Mask(device))) + 1UL;
    uint32_t size          = Cy_SMIF_MaskValueToSizeInByte(config->size);
    uint32_t endAddress    = config->addr + size - 1;

    if(startAddress < CY_SMIF_GetXIP_Address(device))
    {
        return CY_SMIF_BAD_PARAM;
    }

    if(endAddress > ((uint32_t)CY_SMIF_GetXIP_Address(device) + maxDeviceSize - 1UL))
    {
        return CY_SMIF_BAD_PARAM;
    }

    /*********************/
    /*   Set registers   */
    /*********************/
    Cy_SMIF_DeviceSetDataSelect(device, CY_SMIF_DATA_SEL0);
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


    Cy_SMIF_SetXIPAddrCtl(device, CY_SMIF_XIP_ADDRESS_5_BYTE, false /* not Dual Quad */);

    // Latency code to acctual latency cycle
    uint8_t dummyCycle = Cy_SMIF_HB_LatencyCodeToCycle(config->lc_hb);

    /****************************/
    /*   Set XPI Read Sequence  */
    /****************************/

    /*** Set command ***/
    {
        stc_cy_smif_cmd_mode_ctl_t rdCmdParams;
        rdCmdParams.cmd       = config->xipReadCmd;
        rdCmdParams.width     = CY_SMIF_WIDTH_OCTAL;
        rdCmdParams.dataRate  = CY_SMIF_DDR;
        rdCmdParams.presence  = CY_SMIF_PRESENT_1BYTE;
        Cy_SMIF_SetReadCmdCtl(device, &rdCmdParams);
    }

    /*** Set address ***/
    {
        stc_cy_smif_addr_data_ctl_t rdAddrParams;
        rdAddrParams.width    = CY_SMIF_WIDTH_OCTAL;
        rdAddrParams.dataRate = CY_SMIF_DDR;
        Cy_SMIF_SetReadAddrCtl(device, &rdAddrParams);
    }

    /*** Set mode ***/
    {
        stc_cy_smif_cmd_mode_ctl_t rdModeParams;
        rdModeParams.cmd      = 0ul;
        rdModeParams.width    = CY_SMIF_WIDTH_SINGLE;
        rdModeParams.dataRate = CY_SMIF_SDR;
        rdModeParams.presence = CY_SMIF_NOT_PRESENT;
        Cy_SMIF_SetReadModeCtl(device, &rdModeParams);
    }

    /*** Set dummy ***/
    {
        stc_cy_smif_rd_dummy_ctl_t rdDummyParams;
        rdDummyParams.presence   = CY_SMIF_PRESENT_2BYTE;
        rdDummyParams.numOfDummy = dummyCycle;
        Cy_SMIF_SetReadDummyCtl(device, &rdDummyParams);
    }

    /*** Set data ***/
    {
        stc_cy_smif_addr_data_ctl_t rdDataParams;
        rdDataParams.width    = CY_SMIF_WIDTH_OCTAL;
        rdDataParams.dataRate = CY_SMIF_DDR;
        Cy_SMIF_SetReadDataCtl(device, &rdDataParams);
    }

    /***   Set CRC   ***/
    {
        stc_cy_smif_rd_crc_ctl_t rdCRCParams = { 0u };
        Cy_SMIF_SetReadCrcCtl(device, &rdCRCParams);
    }

    /***  Set bound  ***/
    {
        stc_cy_smif_rd_bound_ctl_t rdBoundParams = { 0u };
        Cy_SMIF_SetReadBoundCtl(device, &rdBoundParams);
    }

    /*****************************/
    /*   Set XPI Write Sequence  */
    /*****************************/
    /*** Set command ***/
    {
        stc_cy_smif_cmd_mode_ctl_t wtCmdParams;
        wtCmdParams.cmd       = config->xipWriteCmd;
        wtCmdParams.width     = CY_SMIF_WIDTH_OCTAL;
        wtCmdParams.dataRate  = CY_SMIF_DDR;
        wtCmdParams.presence  = CY_SMIF_PRESENT_1BYTE;
        Cy_SMIF_SetWriteCmdCtl(device, &wtCmdParams);
    }

    /*** Set address ***/
    {
        stc_cy_smif_addr_data_ctl_t wtAddrParams;
        wtAddrParams.width    = CY_SMIF_WIDTH_OCTAL;
        wtAddrParams.dataRate = CY_SMIF_DDR;
        Cy_SMIF_SetWriteAddrCtl(device, &wtAddrParams);
    }

    /*** Set mode ***/
    {
        stc_cy_smif_cmd_mode_ctl_t wtModeParams;
        wtModeParams.cmd      = 0ul;
        wtModeParams.width    = CY_SMIF_WIDTH_SINGLE;
        wtModeParams.dataRate = CY_SMIF_SDR;
        wtModeParams.presence = CY_SMIF_NOT_PRESENT;
        Cy_SMIF_SetWriteModeCtl(device, &wtModeParams);
    }

    /*** Set dummy ***/
    {
        stc_cy_smif_wr_dummy_ctl_t wtDummyParams;
        if(config->hbDevType == CY_SMIF_HB_FLASH)
        {
            wtDummyParams.presence   = CY_SMIF_NOT_PRESENT;
            wtDummyParams.numOfDummy = 0;;
            wtDummyParams.rwdsEn     = false;
        }
        else
        {
            wtDummyParams.presence   = CY_SMIF_PRESENT_2BYTE;
            wtDummyParams.numOfDummy = dummyCycle;
            wtDummyParams.rwdsEn     = true;
        }
        Cy_SMIF_SetWriteDummyCtl(device, &wtDummyParams);
    }

    /*** Set data ***/
    {
        stc_cy_smif_addr_data_ctl_t wtDataParams;
        wtDataParams.width    = CY_SMIF_WIDTH_OCTAL;
        wtDataParams.dataRate = CY_SMIF_DDR;
        Cy_SMIF_SetWriteDataCtl(device, &wtDataParams);
    }

    Cy_SMIF_DeviceWriteEnable(device);
    Cy_SMIF_DeviceEnable(device);

    return CY_SMIF_SUCCESS;
}

/*******************************************************************************
* Function Cy_SMIF_HB_MMIO_Read
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_HB_MMIO_Read(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        en_hb_bust_type_t burstType,
                                        uint32_t readAddress,
                                        uint32_t sizeInHalfWord,
                                        uint16_t buf[],
                                        cy_en_smif_hb_latency_code_t lcCode,
                                        bool isblockingMode,
                                        cy_stc_smif_context_t *context)
{
    cy_en_smif_status_t status;

    un_Hyper_Com_Addr_t hbComAndAddr  = { .u64 = 0x0ULL };
    hbComAndAddr.fld.ColumnAddress    = readAddress & 0x00000007;
    hbComAndAddr.fld.ByteEnableForRAM = 0x3u;                     // 3 anyway
    hbComAndAddr.fld.PageAddress      = ((readAddress >> 3) & 0x00FFFFFF);
    hbComAndAddr.fld.BurstType        = burstType;
    hbComAndAddr.fld.Target           = CY_SMIF_HB_TARGET_MEMORY;
    hbComAndAddr.fld.ReadWrite        = CY_SMIF_HB_READ;

    uint32_t restOfHbAddr = Cy_SMIF_Reverse4ByteEndian(hbComAndAddr.u32[0]);

    /****** Command and Address ******/
    status = Cy_SMIF_TransmitCommand(base,
                                     hbComAndAddr.u16[2],     /* command value */
                                     true,
                                     CY_SMIF_WIDTH_OCTAL,
                                     CY_SMIF_DDR,
                                     (uint8_t*)&restOfHbAddr, /* Data pointer */
                                     4,                       /* Data size */
                                     CY_SMIF_WIDTH_OCTAL,     /* data width */
                                     CY_SMIF_DDR,             /* data rate */
                                     slave,                   /* slave select */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    /****** No Mode ******/

    /****** Dummy ******/
    uint8_t dummyCycle = Cy_SMIF_HB_LatencyCodeToCycle(lcCode);
    if(dummyCycle > 0u)
    {
        status = Cy_SMIF_SendDummyCycles(base, 
                                         CY_SMIF_WIDTH_OCTAL,  /* command width */
                                         CY_SMIF_DDR,          /* command rate */
                                         false, false, false, true,
                                         dummyCycle);
        if(status != CY_SMIF_SUCCESS)
        {
            return status;
        }
    }

    if(isblockingMode == true)
    {
        status = Cy_SMIF_ReceiveDataBlocking(base, (uint8_t *)buf, (sizeInHalfWord*2), CY_SMIF_WIDTH_OCTAL, CY_SMIF_DDR, slave, context);
    }
    else
    {
        status = Cy_SMIF_ReceiveData(base, (uint8_t *)buf, (sizeInHalfWord*2), CY_SMIF_WIDTH_OCTAL, CY_SMIF_DDR, slave, NULL, context);
    }
    return status;
}

/*******************************************************************************
* Function Cy_SMIF_HB_MMIO_Write
****************************************************************************//**
*
* \param
*
* \return
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_HB_MMIO_Write(volatile stc_SMIF_t *base,
                                        cy_en_smif_slave_select_t slave,
                                        en_hb_bust_type_t burstType,
                                        uint32_t writeAddress,
                                        uint32_t sizeInHalfWord,
                                        uint16_t buf[],
                                        bool isblockingMode,
                                        cy_stc_smif_context_t *context)
{
    cy_en_smif_status_t status;

    un_Hyper_Com_Addr_t hbComAndAddr  = { .u64 = 0x0ULL };
    hbComAndAddr.fld.ColumnAddress    = writeAddress & 0x00000007;
    hbComAndAddr.fld.ByteEnableForRAM = 0x3u;                     // 3 anyway
    hbComAndAddr.fld.PageAddress      = ((writeAddress >> 3) & 0x00FFFFFF);
    hbComAndAddr.fld.BurstType        = burstType;
    hbComAndAddr.fld.Target           = CY_SMIF_HB_TARGET_MEMORY;
    hbComAndAddr.fld.ReadWrite        = CY_SMIF_HB_WRITE;

    uint32_t restOfHbAddr = Cy_SMIF_Reverse4ByteEndian(hbComAndAddr.u32[0]);

    /****** Command and Address ******/
    status = Cy_SMIF_TransmitCommand(base,
                                     hbComAndAddr.u16[2],     /* command value */
                                     true,
                                     CY_SMIF_WIDTH_OCTAL,
                                     CY_SMIF_DDR,
                                     (uint8_t*)&restOfHbAddr, /* Data pointer */
                                     4,                       /* Data size */
                                     CY_SMIF_WIDTH_OCTAL,     /* data width */
                                     CY_SMIF_DDR,             /* data rate */
                                     slave,                   /* slave select */
                                     NOT_LAST_COMMAND,
                                     context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    if(isblockingMode == true)
    {
        Cy_SMIF_TransmitDataBlocking(base, (uint8_t *)buf, (sizeInHalfWord*2), CY_SMIF_WIDTH_OCTAL, CY_SMIF_DDR, slave, context);
    }
    else
    {
        Cy_SMIF_TransmitData(base, (uint8_t *)buf, (sizeInHalfWord*2), CY_SMIF_WIDTH_OCTAL, CY_SMIF_DDR, slave, NULL, context);
    }

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_HB_LatencyCodeToCycle
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - 
*
*******************************************************************************/
static uint32_t Cy_SMIF_HB_LatencyCodeToCycle(cy_en_smif_hb_latency_code_t code)
{
    if((uint8_t)code >= 14u)
    {
        return ((uint32_t)code - 12ul);
    }
    else
    {
        return ((uint32_t)code + 4ul);
    }
}

/*******************************************************************************
* Function CY_SMIF_readHYPERRAM_REG
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - 
*
*******************************************************************************/
cy_en_smif_status_t CY_SMIF_ReadHYPERRAM_REG(volatile stc_SMIF_DEVICE_t *device, uint32_t reg_addr, uint16_t* reg_value)
{
    uint8_t savedCode = device->unRD_CMD_CTL.stcField.u8CODE;
    uint32_t baseAddr = device->unADDR.u32Register;

//    uint32_t savedIntrStatus = Cy_SysLib_EnterCriticalSection();

    device->unRD_CMD_CTL.stcField.u8CODE = 0xC0;
    device->unRD_CMD_CTL.u32Register;

    // Hyper bus devices have two byte for each address.
    // So, SMIF interface dividdes input address by 2 automatically.
    // To neutralize this effect, mulitly the input address by 2 (left shift 1 bit).
    *reg_value = *(uint16_t*)(baseAddr + (reg_addr << 1ul));

    device->unRD_CMD_CTL.stcField.u8CODE = savedCode;
    device->unRD_CMD_CTL.u32Register;

//    Cy_SysLib_ExitCriticalSection(savedIntrStatus);

    return CY_SMIF_SUCCESS;
}

/*******************************************************************************
* Function CY_SMIF_writeHYPERRAM_REG
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - 
*
*******************************************************************************/
cy_en_smif_status_t CY_SMIF_WriteHYPERRAM_REG(volatile stc_SMIF_DEVICE_t *device, uint32_t reg_addr, uint16_t reg_value)
{
    uint8_t savedCode = device->unWR_CMD_CTL.stcField.u8CODE;
    uint32_t savedDummyPresence = device->unWR_DUMMY_CTL.stcField.u2PRESENT2;
    uint32_t baseAddr = device->unADDR.u32Register;

//    uint32_t savedIntrStatus = Cy_SysLib_EnterCriticalSection();

    device->unWR_DUMMY_CTL.stcField.u2PRESENT2 = CY_SMIF_NOT_PRESENT;
    device->unWR_CMD_CTL.stcField.u8CODE = 0x60;
    device->unWR_CMD_CTL.u32Register;

    // Hyper bus devices have two byte for each address.
    // So, SMIF interface dividdes input address by 2 automatically.
    // To neutralize this effect, mulitly the input address by 2 (left shift 1 bit).
    *(uint16_t*)(baseAddr + (reg_addr << 1ul)) = reg_value;

    device->unWR_DUMMY_CTL.stcField.u2PRESENT2 = savedDummyPresence;
    device->unWR_CMD_CTL.stcField.u8CODE = savedCode;
    device->unWR_CMD_CTL.u32Register;

//    Cy_SysLib_ExitCriticalSection(savedIntrStatus);

    return CY_SMIF_SUCCESS;
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_InitCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_InitCmd
(
CY_SMIF_FLASHDATA * base_addr     /* device base address in system */
)
{
  (void) base_addr;
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ResetCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_ResetCmd
(
CY_SMIF_FLASHDATA * base_addr   /* device base address in system */
)
{       
  /* Write Software RESET command */
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_RESET_CMD);
  CY_SMIF_HbFlash_InitCmd(base_addr);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_SectorEraseCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_SectorEraseCmd
(
CY_SMIF_FLASHDATA * base_addr,                   /* device base address in system */
CY_SMIF_ADDRESS offset                           /* address offset from base address */
)
{ 
 
  /* Issue unlock sequence command */
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);

  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_ERASE_SETUP_CMD);
  
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);

  /* Write Sector Erase Command to Offset */
  CY_SMIF_FLASH_WR(base_addr, offset, CY_SMIF_NOR_SECTOR_ERASE_CMD);

}
/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ChipEraseCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_ChipEraseCmd
(
CY_SMIF_FLASHDATA * base_addr    /* device base address in system */
)
{       
  /* Issue inlock sequence command */
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);

  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_ERASE_SETUP_CMD);

  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);

  /* Write Chip Erase Command to Base Address */
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_CHIP_ERASE_CMD);
}
/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ProgramCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_ProgramCmd
(
CY_SMIF_FLASHDATA * base_addr,               /* device base address in system */
CY_SMIF_ADDRESS offset,                  /* address offset from base address */
CY_SMIF_FLASHDATA *pgm_data_ptr          /* variable containing data to program */
)
{       
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);

  /* Write Program Command */
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_PROGRAM_CMD);
  /* Write Data */
  CY_SMIF_FLASH_WR(base_addr, offset, *pgm_data_ptr);
}
/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_WriteToBufferCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_WriteToBufferCmd
(
CY_SMIF_FLASHDATA * base_addr,               /* device base address in system */
CY_SMIF_ADDRESS offset                       /* address offset from base address */
)
{  
  /* Issue unlock command sequence */
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);

  /* Write Write Buffer Load Command */
  CY_SMIF_FLASH_WR(base_addr, offset, CY_SMIF_NOR_WRITE_BUFFER_LOAD_CMD);

}
/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ProgramBufferToFlashCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_ProgramBufferToFlashCmd
(
CY_SMIF_FLASHDATA * base_addr,               /* device base address in system */
CY_SMIF_ADDRESS offset                       /* address offset from base address */
)
{       
  /* Transfer Buffer to Flash Command */
  CY_SMIF_FLASH_WR(base_addr, offset, CY_SMIF_NOR_WRITE_BUFFER_PGM_CONFIRM_CMD);
}
/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_WriteBufferAbortResetCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_WriteBufferAbortResetCmd
(
CY_SMIF_FLASHDATA * base_addr        /* device base address in system */
)
{       
  
  /* Issue Write Buffer Abort Reset Command Sequence */
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);

  /* Write to Buffer Abort Reset Command */
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_WRITE_BUFFER_ABORT_RESET_CMD);   
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_CfiEntryCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_CfiEntryCmd
(
CY_SMIF_FLASHDATA * base_addr,    /* device base address in system */
CY_SMIF_ADDRESS offset            /* sector address offset for ASO(Address Space Overlay) */
)
{        
  CY_SMIF_FLASH_WR(base_addr, (offset & CY_SMIF_SA_OFFSET_MASK) + CY_SMIF_HB_FLASH_CFI_UNLOCK_ADDR1, CY_SMIF_NOR_CFI_QUERY_CMD);
}
/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_CfiExitCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_CfiExitCmd
(
CY_SMIF_FLASHDATA * base_addr   /* device base address in system */
)
{       

  /* Write Software RESET command */
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_RESET_CMD); 

}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ReadCfiWord
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadCfiWord
(
CY_SMIF_FLASHDATA * base_addr,    /* device base address is system */
CY_SMIF_ADDRESS offset        /* address offset from base address */
)
{
  CY_SMIF_FLASHDATA data;

  CY_SMIF_HbFlash_CfiEntryCmd(base_addr, offset);
  data  = CY_SMIF_FLASH_RD(base_addr, offset);
  CY_SMIF_HbFlash_CfiExitCmd(base_addr);

  return(data);
}


/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_StatusRegReadCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_StatusRegReadCmd
(
CY_SMIF_FLASHDATA * base_addr    /* device base address in system */
)
{         
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_STATUS_REG_READ_CMD); 
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_StatusRegClearCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_StatusRegClearCmd
(
CY_SMIF_FLASHDATA * base_addr   /* device base address in system */
)
{         
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_STATUS_REG_CLEAR_CMD); 
}



/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_AutoselectEntryCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_AutoselectEntryCmd
(
CY_SMIF_FLASHDATA * base_addr,      /* device base address in system */
CY_SMIF_ADDRESS offset          /* address offset from base address */
)
{ 
  /* Issue Autoselect Command Sequence */
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);

  CY_SMIF_FLASH_WR(base_addr, (offset & CY_SMIF_SA_OFFSET_MASK) + CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_AUTOSELECT_CMD); 
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_AutoselectExitCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_AutoselectExitCmd
(
CY_SMIF_FLASHDATA * base_addr     /* device base address in system */
)
{       
  /* Write Software RESET command */
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_RESET_CMD);
}


/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ProgramSuspendCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_ProgramSuspendCmd
(
CY_SMIF_FLASHDATA * base_addr           /* device base address in system */
)
{         
  /* Write Suspend Command */
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_PROGRAM_SUSPEND_CMD);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_EraseSuspendCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_EraseSuspendCmd
(
CY_SMIF_FLASHDATA * base_addr      /* device base address in system */
)
{     
  
  
  /* Write Suspend Command */
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_ERASE_SUSPEND_CMD);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_EraseResumeCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_EraseResumeCmd
(
CY_SMIF_FLASHDATA * base_addr       /* device base address in system */
)
{       

  /* Write Resume Command */
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_ERASE_RESUME_CMD);

}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ProgramResumeCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_ProgramResumeCmd
(
CY_SMIF_FLASHDATA * base_addr       /* device base address in system */
)
{       
  /* Write Resume Command */
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_PROGRAM_RESUME_CMD);
}



/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_EraseSuspendOp
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_EraseSuspendOp
(
CY_SMIF_FLASHDATA * base_addr    /* device base address is system */
)
{       
  CY_SMIF_FLASHDATA    status_reg;
 
  CY_SMIF_HbFlash_EraseSuspendCmd( base_addr );   /* issue erase suspend command */  
  status_reg = CY_SMIF_HbFlash_Poll(base_addr, 0 );    /* wait for device done */
  
  if( (status_reg & CY_SMIF_DEV_ERASE_SUSP_MASK) == CY_SMIF_DEV_ERASE_SUSP_MASK )
    return( CY_SMIF_DEV_ERASE_SUSPEND  );        /* Erase suspend  */
      
  return( CY_SMIF_DEV_ERASE_SUSPEND_ERROR );       /* Erase suspend error */

}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ProgramSuspendOp
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_ProgramSuspendOp
(
CY_SMIF_FLASHDATA * base_addr    /* Device base address is system */
)
{       
  CY_SMIF_FLASHDATA    status_reg;

  CY_SMIF_HbFlash_ProgramSuspendCmd( base_addr );   /* Issue program suspend command */  
  status_reg = CY_SMIF_HbFlash_Poll( base_addr, 0 );
  
  if( (status_reg & CY_SMIF_DEV_PROGRAM_SUSP_MASK) == CY_SMIF_DEV_PROGRAM_SUSP_MASK )
    return( CY_SMIF_DEV_PROGRAM_SUSPEND );      /* Program suspend */
      
  return( CY_SMIF_DEV_PROGRAM_SUSPEND_ERROR  );     /* Program suspend error */ 
}



/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_GetDeviceId
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
uint32_t CY_SMIF_HbFlash_GetDeviceId
(
CY_SMIF_FLASHDATA * base_addr,   /* device base address in system */
CY_SMIF_ADDRESS offset
)
{
  uint32_t id;

  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);

  CY_SMIF_FLASH_WR(base_addr, (offset & CY_SMIF_SA_OFFSET_MASK) + CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_AUTOSELECT_CMD);

  id  = (uint32_t)(CY_SMIF_FLASH_RD(base_addr, (offset & CY_SMIF_SA_OFFSET_MASK) + 0x0001) & 0x000000FF) << 16;
  id |= (uint32_t)(CY_SMIF_FLASH_RD(base_addr, (offset & CY_SMIF_SA_OFFSET_MASK) + 0x000E) & 0x000000FF) <<  8;
  id |= (uint32_t)(CY_SMIF_FLASH_RD(base_addr, (offset & CY_SMIF_SA_OFFSET_MASK) + 0x000F) & 0x000000FF)      ;

  /* Write Software RESET command */
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_RESET_CMD);
  
  return(id);
}






/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_Poll
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
CY_SMIF_FLASHDATA CY_SMIF_HbFlash_Poll
(
CY_SMIF_FLASHDATA * base_addr,          /* device base address in system */
CY_SMIF_ADDRESS offset                 /* address offset from base address */
)
{       
  uint32_t polling_counter = 0xFFFFFFFF;
  volatile CY_SMIF_FLASHDATA status_reg;

  do
  {
    polling_counter--;
    CY_SMIF_HbFlash_StatusRegReadCmd( base_addr );    /* Issue status register read command */
    status_reg = CY_SMIF_FLASH_RD(base_addr, offset);       /* read the status register */
    if( (status_reg & CY_SMIF_DEV_RDY_MASK) == CY_SMIF_DEV_RDY_MASK  )  /* Are all devices done bit 7 is 1 */
      break;

  }while(polling_counter);
  
  return( status_reg );          /* retrun the status reg. */
}


/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_StatusClear
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_StatusClear
(
CY_SMIF_FLASHDATA *  base_addr      /* device base address in system */
)
{
  CY_SMIF_HbFlash_StatusRegClearCmd(base_addr );
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_StatusGetReg
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
CY_SMIF_FLASHDATA CY_SMIF_HbFlash_StatusGetReg
(
CY_SMIF_FLASHDATA *  base_addr,      /* device base address in system */
CY_SMIF_ADDRESS      offset          /* address offset from base address */
)
{
  CY_SMIF_FLASHDATA status_reg = 0xFFFF;
  CY_SMIF_HbFlash_StatusRegReadCmd( base_addr );    /* Issue status register read command */
  status_reg = CY_SMIF_FLASH_RD( base_addr, offset );     /* read the status register */
  return status_reg;
}





/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_SecSiSectorExitCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_SecSiSectorExitCmd
(
CY_SMIF_FLASHDATA * base_addr               /* device base address in system */
)
{       
  /* Issue SecSi Sector Exit Command Sequence */
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);

  /* First Secsi Sector Reset Command */
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_SECSI_SECTOR_EXIT_SETUP_CMD);
  /* Second Secsi Sector Reset Command */
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_SECSI_SECTOR_EXIT_CMD);
}
/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_SecSiSectorEntryCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_SecSiSectorEntryCmd
(
CY_SMIF_FLASHDATA * base_addr,      /* device base address in system */
CY_SMIF_ADDRESS offset        /* sector offset for ASO(Address Space Overlay) */
)
{       
  
  /* Issue SecSi Sector Entry Command Sequence */
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);

  CY_SMIF_FLASH_WR(base_addr, (offset & CY_SMIF_SA_OFFSET_MASK) + CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_SECSI_SECTOR_ENTRY_CMD); 
}


/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_BlankCheckCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_BlankCheckCmd
(
CY_SMIF_FLASHDATA * base_addr,   /* device base address in system */
CY_SMIF_ADDRESS offset           /* sector address offset from base address */
)
{         
  CY_SMIF_FLASH_WR(base_addr, (offset & CY_SMIF_SA_OFFSET_MASK) + CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_BLANK_CHECK_CMD);  
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_BlankCheckOp
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_BlankCheckOp
(
CY_SMIF_FLASHDATA * base_addr,    /* device base address is system */
CY_SMIF_ADDRESS offset        /* address offset from base address */
)
{       
    CY_SMIF_FLASHDATA    status_reg;

  CY_SMIF_HbFlash_BlankCheckCmd( base_addr, offset );  

  status_reg = CY_SMIF_HbFlash_Poll(base_addr, offset );
  
  if( (status_reg & CY_SMIF_DEV_ERASE_MASK) == CY_SMIF_DEV_ERASE_MASK )
    return( CY_SMIF_DEV_ERASE_ERROR );    /* sector not blank */
  else
     return( CY_SMIF_DEV_NOT_BUSY );      /* sector are blank */  

}


/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ReadOp
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadOp
(
CY_SMIF_FLASHDATA * base_addr,    /* device base address is system */
CY_SMIF_ADDRESS offset        /* address offset from base address */
)
{
  CY_SMIF_FLASHDATA data;
  
  data = CY_SMIF_FLASH_RD(base_addr, offset);

  return(data);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_WriteBufferProgramOp
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_WriteBufferProgramOp
(
CY_SMIF_FLASHDATA *   base_addr,  /* device base address in system     */
CY_SMIF_ADDRESS   offset,     /* address offset from base address  */
CY_SMIF_WORDCOUNT word_count, /* number of words to program        */
CY_SMIF_FLASHDATA *data_buf   /* buffer containing data to program */
)
{
  CY_SMIF_ADDRESS   last_loaded_addr;
  CY_SMIF_ADDRESS   current_offset;
  CY_SMIF_ADDRESS   end_offset;
  CY_SMIF_FLASHDATA wcount;
  CY_SMIF_FLASHDATA status_reg;

  /* Initialize variables */
  current_offset   = offset;
  end_offset       = offset + word_count - 1;
  last_loaded_addr = offset;

  /* don't try with a count of zero */
  if (!word_count) 
  {
    return(CY_SMIF_DEV_NOT_BUSY);
  }

  /* Issue Load Write Buffer Command Sequence */
  CY_SMIF_HbFlash_WriteToBufferCmd(base_addr, offset);

  /* Write # of locations to program */
  wcount = (CY_SMIF_FLASHDATA)word_count - 1;
  wcount *= CY_SMIF_HB_FLASH_DEV_MULTIPLIER;     /* For interleaving devices */

  /* In the datasheets of some latest devices, such as GLP, GLS, etc, the 
  command sequence of "write to buffer" command states the address of word count is 
  "Sector Address". Notice that to make LLD backward compatibility, the actual word 
  count address implemented is "Sector Address + CY_SMIF_HB_FLASH_UNLOCK_ADDR2", since the lower 
  address bits (a0-a15) are "don't care" bits and will be ignored anyway.
  */
    CY_SMIF_FLASH_WR(base_addr, offset & CY_SMIF_SA_OFFSET_MASK , wcount);
  
  /* Load Data into Buffer */
  while(current_offset <= end_offset)
  {
    /* Store last loaded address & data value (for polling) */
    last_loaded_addr = current_offset;

    /* Write Data */
    CY_SMIF_FLASH_WR(base_addr, current_offset, *data_buf++);
    current_offset++;
  }

  /* Issue Program Buffer to Flash command */
  CY_SMIF_HbFlash_ProgramBufferToFlashCmd(base_addr, offset);

  status_reg = CY_SMIF_HbFlash_Poll(base_addr, last_loaded_addr);

  if( status_reg & CY_SMIF_DEV_SEC_LOCK_MASK )
    return( CY_SMIF_DEV_SECTOR_LOCK );    /* sector locked */

  if( (status_reg & CY_SMIF_DEV_PROGRAM_MASK) == CY_SMIF_DEV_PROGRAM_MASK )
    return( CY_SMIF_DEV_PROGRAM_ERROR );    /* program error */

  return( CY_SMIF_DEV_NOT_BUSY );         /* program complete */
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ProgramOp
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_ProgramOp
(
CY_SMIF_FLASHDATA * base_addr,      /* device base address is system */
CY_SMIF_ADDRESS offset,         /* address offset from base address */
CY_SMIF_FLASHDATA write_data    /* variable containing data to program */
)
{   
 CY_SMIF_DEVSTATUS status;
 status = CY_SMIF_HbFlash_WriteBufferProgramOp(base_addr, offset, 1, &write_data );
 return(status);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_SectorEraseOp
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_SectorEraseOp
(
CY_SMIF_FLASHDATA * base_addr,    /* device base address is system */
CY_SMIF_ADDRESS offset        /* address offset from base address */
)
{
  CY_SMIF_FLASHDATA         status_reg;

  CY_SMIF_HbFlash_SectorEraseCmd(base_addr, offset);
  status_reg = CY_SMIF_HbFlash_Poll(base_addr, offset );

  if( status_reg & CY_SMIF_DEV_SEC_LOCK_MASK )
    return( CY_SMIF_DEV_SECTOR_LOCK );    /* sector locked */

  if( (status_reg & CY_SMIF_DEV_ERASE_MASK) == CY_SMIF_DEV_ERASE_MASK )
    return( CY_SMIF_DEV_ERASE_ERROR );    /* erase error */
      
  return( CY_SMIF_DEV_NOT_BUSY );         /* erease complete */
}


/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ChipEraseOp
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_ChipEraseOp
(
CY_SMIF_FLASHDATA * base_addr   /* device base address in system */
)
{    
  CY_SMIF_FLASHDATA status_reg;

  CY_SMIF_HbFlash_ChipEraseCmd(base_addr);
  status_reg = CY_SMIF_HbFlash_Poll(base_addr, 0 );

  if( (status_reg & CY_SMIF_DEV_ERASE_MASK) == CY_SMIF_DEV_ERASE_MASK )
    return( CY_SMIF_DEV_ERASE_ERROR );    /* erase error */
      
  return( CY_SMIF_DEV_NOT_BUSY );         /* erease complete */ 
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_memcpy
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_memcpy
(
CY_SMIF_FLASHDATA * base_addr,    /* device base address is system */
CY_SMIF_ADDRESS offset,           /* address offset from base address */
CY_SMIF_WORDCOUNT word_cnt,       /* number of words to program */
CY_SMIF_FLASHDATA *data_buf       /* buffer containing data to program */
)
{
  CY_SMIF_ADDRESS mask = CY_SMIF_HB_FLASH_BUFFER_SIZE - 1;
  CY_SMIF_WORDCOUNT intwc = word_cnt;
  CY_SMIF_DEVSTATUS status = CY_SMIF_DEV_NOT_BUSY;

  if (offset & mask)
  {
    /* program only as much as necessary, so pick the lower of the two numbers */
    if (word_cnt < (CY_SMIF_HB_FLASH_BUFFER_SIZE - (offset & mask)) ) 
      intwc = word_cnt; 
    else
      intwc = CY_SMIF_HB_FLASH_BUFFER_SIZE - (offset & mask);

    /* program the first few to get write buffer aligned */
    status = CY_SMIF_HbFlash_WriteBufferProgramOp(base_addr, offset, intwc, data_buf);
    if (status != CY_SMIF_DEV_NOT_BUSY) 
    {
     return(status);
    }

    offset   += intwc; /* adjust pointers and counter */
    word_cnt -= intwc;
    data_buf += intwc;
    if (word_cnt == 0)
    {
     return(status);
    }
  }

  while(word_cnt >= CY_SMIF_HB_FLASH_BUFFER_SIZE) /* while big chunks to do */
  {
    status = CY_SMIF_HbFlash_WriteBufferProgramOp(base_addr, offset, CY_SMIF_HB_FLASH_BUFFER_SIZE, data_buf);
    if (status != CY_SMIF_DEV_NOT_BUSY)
    {
      return(status);
    }

    offset   += CY_SMIF_HB_FLASH_BUFFER_SIZE; /* adjust pointers and counter */
    word_cnt -= CY_SMIF_HB_FLASH_BUFFER_SIZE;
    data_buf += CY_SMIF_HB_FLASH_BUFFER_SIZE;
  }
  if (word_cnt == 0)
  {
    return(status);
  }

  status = CY_SMIF_HbFlash_WriteBufferProgramOp(base_addr, offset, word_cnt, data_buf);
  return(status);
}

/************************************************************
*************************************************************
* Following are sector protection driver routines     *
*************************************************************
*************************************************************/


/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_LockRegEntryCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_LockRegEntryCmd
(
CY_SMIF_FLASHDATA *   base_addr   /* device base address in system */
)
{

  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);

  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_WSXXX_LOCK_REG_ENTRY);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_LockRegBitsProgramCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_LockRegBitsProgramCmd
(
CY_SMIF_FLASHDATA *   base_addr,  /* device base address in system */
CY_SMIF_FLASHDATA value       /* value to program to lock reg. */
)
{

  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_UNLOCK_BYPASS_PROGRAM_CMD);
  CY_SMIF_FLASH_WR(base_addr, 0x0, value);

}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_LockRegBitsReadCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
CY_SMIF_FLASHDATA CY_SMIF_HbFlash_LockRegBitsReadCmd
(
CY_SMIF_FLASHDATA *   base_addr   /* device base address in system */
)
{

  return(CY_SMIF_FLASH_RD(base_addr, 0x0));

}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_LockRegExitCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_LockRegExitCmd
(
CY_SMIF_FLASHDATA *   base_addr   /* device base address in system */
)
{

  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_SECSI_SECTOR_EXIT_SETUP_CMD);
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_SECSI_SECTOR_EXIT_CMD);

}



/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_PasswordProtectionEntryCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_PasswordProtectionEntryCmd
(
CY_SMIF_FLASHDATA *   base_addr   /* device base address in system */
)
{
  
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);

  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_WSXXX_PSWD_PROT_CMD_ENTRY);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_PasswordProtectionProgramCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_PasswordProtectionProgramCmd
(
CY_SMIF_FLASHDATA *   base_addr,  /* device base address in system */
CY_SMIF_ADDRESS   offset,
CY_SMIF_FLASHDATA pwd
)
{
  CY_SMIF_FLASH_WR(base_addr, offset, CY_SMIF_NOR_UNLOCK_BYPASS_PROGRAM_CMD);
  CY_SMIF_FLASH_WR(base_addr, offset, pwd);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_PasswordProtectionReadCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_PasswordProtectionReadCmd
(
CY_SMIF_FLASHDATA *   base_addr,  /* device base address in system */
CY_SMIF_FLASHDATA *pwd0,      /* Password 0 */
CY_SMIF_FLASHDATA *pwd1,      /* Password 1 */
CY_SMIF_FLASHDATA *pwd2,      /* Password 2 */
CY_SMIF_FLASHDATA *pwd3       /* Password 3 */
)
{
  *pwd0 = CY_SMIF_FLASH_RD(base_addr, 0);
  *pwd1 = CY_SMIF_FLASH_RD(base_addr, 1);
  *pwd2 = CY_SMIF_FLASH_RD(base_addr, 2);
  *pwd3 = CY_SMIF_FLASH_RD(base_addr, 3);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_PasswordProtectionUnlockCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_PasswordProtectionUnlockCmd
(
CY_SMIF_FLASHDATA *   base_addr,  /* device base address in system */
CY_SMIF_FLASHDATA pwd0,       /* Password 0 */
CY_SMIF_FLASHDATA pwd1,       /* Password 1 */
CY_SMIF_FLASHDATA pwd2,       /* Password 2 */
CY_SMIF_FLASHDATA pwd3        /* Password 3 */
)
{
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_WSXXX_PSWD_UNLOCK_1);
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_WSXXX_PSWD_UNLOCK_2);
  CY_SMIF_FLASH_WR(base_addr, 0, pwd0);
  CY_SMIF_FLASH_WR(base_addr, 1, pwd1);
  CY_SMIF_FLASH_WR(base_addr, 2, pwd2);
  CY_SMIF_FLASH_WR(base_addr, 3, pwd3);
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_WSXXX_PSWD_UNLOCK_3);

}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_PasswordProtectionExitCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_PasswordProtectionExitCmd
(
CY_SMIF_FLASHDATA *   base_addr   /* device base address in system */
)
{
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_SECSI_SECTOR_EXIT_SETUP_CMD);
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_SECSI_SECTOR_EXIT_CMD);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_PpbEntryCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_PpbEntryCmd
(
CY_SMIF_FLASHDATA *   base_addr,  /* device base address in system */
CY_SMIF_ADDRESS       offset    /* Sector offset address */
)
{

  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);

  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1+(offset & CY_SMIF_SA_OFFSET_MASK), CY_SMIF_WSXXX_PPB_ENTRY);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_PpbProgramCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_PpbProgramCmd
(
CY_SMIF_FLASHDATA *   base_addr,  /* device base address in system */
CY_SMIF_ADDRESS   offset      /* Sector offset address */
)
{
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_UNLOCK_BYPASS_PROGRAM_CMD);
  CY_SMIF_FLASH_WR(base_addr, offset, 0);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_PpbAllEraseCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_PpbAllEraseCmd
(
CY_SMIF_FLASHDATA *   base_addr   /* device base address in system */
)
{
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_ERASE_SETUP_CMD);
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_WSXXX_PPB_ERASE_CONFIRM);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_PpbStatusReadCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
CY_SMIF_FLASHDATA CY_SMIF_HbFlash_PpbStatusReadCmd
(
CY_SMIF_FLASHDATA *   base_addr,  /* device base address in system */
CY_SMIF_ADDRESS   offset      /* sector offset address */
)
{
  return(CY_SMIF_FLASH_RD(base_addr, offset));
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_PpbExitCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_PpbExitCmd
(
CY_SMIF_FLASHDATA *   base_addr   /* device base address in system */
)
{
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_SECSI_SECTOR_EXIT_SETUP_CMD);
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_SECSI_SECTOR_EXIT_CMD);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_PpbLockBitEntryCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_PpbLockBitEntryCmd
(
CY_SMIF_FLASHDATA *   base_addr   /* device base address in system */
)
{

  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);

  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_WSXXX_PPB_LOCK_ENTRY);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_PpbLockBitSetCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_PpbLockBitSetCmd
(
CY_SMIF_FLASHDATA *   base_addr   /* device base address in system */
)
{
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_UNLOCK_BYPASS_PROGRAM_CMD);
  CY_SMIF_FLASH_WR(base_addr, 0, 0);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_PpbLockBitReadCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
CY_SMIF_FLASHDATA CY_SMIF_HbFlash_PpbLockBitReadCmd
(
CY_SMIF_FLASHDATA *   base_addr   /* device base address in system */
)
{
  return(CY_SMIF_FLASH_RD(base_addr, 0));
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_PpbLockBitExitCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_PpbLockBitExitCmd
(
CY_SMIF_FLASHDATA *   base_addr   /* device base address in system */
)
{
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_SECSI_SECTOR_EXIT_SETUP_CMD);
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_SECSI_SECTOR_EXIT_CMD);
}


/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_DybEntryCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_DybEntryCmd
(
CY_SMIF_FLASHDATA *   base_addr   /* device base address in system */
)
{

  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);

  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_WSXXX_DYB_ENTRY);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_DybSetCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_DybSetCmd
(
CY_SMIF_FLASHDATA *   base_addr,  /* device base address in system */
CY_SMIF_ADDRESS   offset      /* sector offset address */
)
{
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_UNLOCK_BYPASS_PROGRAM_CMD);
  CY_SMIF_FLASH_WR(base_addr, offset, 0x00000000);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_DybClrCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_DybClrCmd
(
CY_SMIF_FLASHDATA *   base_addr,  /* device base address in system */
CY_SMIF_ADDRESS   offset      /* sector offset address */
)
{
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_UNLOCK_BYPASS_PROGRAM_CMD);
  CY_SMIF_FLASH_WR(base_addr, offset, CY_SMIF_WSXXX_DYB_CLEAR);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_DybReadCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
CY_SMIF_FLASHDATA CY_SMIF_HbFlash_DybReadCmd
(
CY_SMIF_FLASHDATA *   base_addr,  /* device base address in system */
CY_SMIF_ADDRESS   offset      /* sector offset address */
)
{
  return(CY_SMIF_FLASH_RD(base_addr, offset));
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_DybExitCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
void CY_SMIF_HbFlash_DybExitCmd
(
CY_SMIF_FLASHDATA *   base_addr   /* device base address in system */
)
{
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_SECSI_SECTOR_EXIT_SETUP_CMD);
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_SECSI_SECTOR_EXIT_CMD);
}

/******************************************************************************
* 
* CY_SMIF_HbFlash_PpbLockBitReadOp - Operation to read global lock bit.
*
* RETURNS: CY_SMIF_FLASHDATA
*
*/
CY_SMIF_FLASHDATA  CY_SMIF_HbFlash_PpbLockBitReadOp ( CY_SMIF_FLASHDATA *base_addr)
{
  CY_SMIF_FLASHDATA retval;

  (CY_SMIF_HbFlash_PpbLockBitEntryCmd)(base_addr);
  retval = (CY_SMIF_HbFlash_PpbLockBitReadCmd)(base_addr);
  CY_SMIF_HbFlash_PpbLockBitExitCmd(base_addr);

  return retval;
}

/******************************************************************************
* 
* CY_SMIF_HbFlash_PpbLockBitSetOp - Operation to set the global lock bit.
*
* RETURNS: 0 Successful
*         -1 Failed
*
*/
int CY_SMIF_HbFlash_PpbLockBitSetOp ( CY_SMIF_FLASHDATA *   base_addr)
{ 
  CY_SMIF_DEVSTATUS dev_status = CY_SMIF_DEV_STATUS_UNKNOWN;
  CY_SMIF_FLASHDATA    status_reg;


  CY_SMIF_HbFlash_PpbLockBitEntryCmd(base_addr);
  CY_SMIF_HbFlash_PpbLockBitSetCmd(base_addr);
  /* poll for completion */
  status_reg = CY_SMIF_HbFlash_Poll(base_addr, 0);
  if( (status_reg & CY_SMIF_DEV_PROGRAM_MASK) == CY_SMIF_DEV_PROGRAM_MASK )
    dev_status =  CY_SMIF_DEV_PROGRAM_ERROR;    /* program error */
  else
    dev_status = CY_SMIF_DEV_NOT_BUSY;

  /* if not done, then we have an error */
  if (dev_status != CY_SMIF_DEV_NOT_BUSY)
  {
    /* Write Software RESET command */
    CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_RESET_CMD);
    CY_SMIF_HbFlash_PpbLockBitExitCmd(base_addr);
    return (-1);  /* return error */ 
  }

  CY_SMIF_HbFlash_PpbLockBitExitCmd(base_addr);
  return 0; /* successfull */
}

/******************************************************************************
* 
* CY_SMIF_HbFlash_PpbAllEraseOp - Operation to clear protection for all sections.
*
* RETURNS: 0 Successful
*         -1 Failed
*
*/
int CY_SMIF_HbFlash_PpbAllEraseOp ( CY_SMIF_FLASHDATA *   base_addr)
{
  CY_SMIF_DEVSTATUS    dev_status = CY_SMIF_DEV_STATUS_UNKNOWN;
  CY_SMIF_FLASHDATA    status_reg;

  if (CY_SMIF_HbFlash_PpbLockBitReadOp(base_addr) == CY_SMIF_PPB_PROTECTED)    /* if it is already locked */
  {
    return(-1);                            /* return an error cuz Lock Bit is locked */
  }

  CY_SMIF_HbFlash_PpbEntryCmd(base_addr, 0);
  CY_SMIF_HbFlash_PpbAllEraseCmd(base_addr);
  /* poll for completion */
  status_reg = CY_SMIF_HbFlash_Poll(base_addr, 0);
  if( (status_reg & CY_SMIF_DEV_PROGRAM_MASK) == CY_SMIF_DEV_PROGRAM_MASK )
    dev_status =  CY_SMIF_DEV_PROGRAM_ERROR;    /* program error */
  else
    dev_status = CY_SMIF_DEV_NOT_BUSY;

  /* if not done, then we have an error */
  if (dev_status != CY_SMIF_DEV_NOT_BUSY)
  {
    /* Write Software RESET command */
    CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_RESET_CMD);
    CY_SMIF_HbFlash_PpbExitCmd(base_addr);
    return (-1); /* return error */
  }

  CY_SMIF_HbFlash_PpbExitCmd(base_addr);    /* exit Ppb protection mode command */
  return 0; /* successful */
}

/******************************************************************************
* 
* CY_SMIF_HbFlash_PpbProgramOp - Operation set the Persistent Protection for a sector. 
*
* RETURNS: 0 Successful
*         -1 Failed
*
*/
int CY_SMIF_HbFlash_PpbProgramOp ( CY_SMIF_FLASHDATA *base_addr, CY_SMIF_ADDRESS offset)
{
  CY_SMIF_DEVSTATUS    dev_status = CY_SMIF_DEV_STATUS_UNKNOWN;
  CY_SMIF_FLASHDATA    status_reg;
  
  if (CY_SMIF_HbFlash_PpbLockBitReadOp(base_addr) == CY_SMIF_PPB_PROTECTED)      /* if it is already locked */
  {
    return(-1);                              /* return an error cuz Lock Bit is locked */
  }


  CY_SMIF_HbFlash_PpbEntryCmd(base_addr,offset);
  CY_SMIF_HbFlash_PpbProgramCmd(base_addr, offset);

  /* poll for completion */
  status_reg = CY_SMIF_HbFlash_Poll(base_addr, 0);
  if( (status_reg & CY_SMIF_DEV_PROGRAM_MASK) == CY_SMIF_DEV_PROGRAM_MASK )
    dev_status =  CY_SMIF_DEV_PROGRAM_ERROR;    /* program error */
  else
    dev_status = CY_SMIF_DEV_NOT_BUSY;

  /* if not done, then we have an error */
  if (dev_status != CY_SMIF_DEV_NOT_BUSY)
  {
    /* Write Software RESET command */
    CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_RESET_CMD);
    CY_SMIF_HbFlash_PpbExitCmd(base_addr);
    return (-1); /* return error */
  }

  CY_SMIF_HbFlash_PpbExitCmd(base_addr);
  return 0; /* successful */
}

/******************************************************************************
* 
* CY_SMIF_HbFlash_PpbStatusReadOp - Operation to read the Persistent Protection status register.
*
* RETURNS: CY_SMIF_FLASHDATA
*CY_SMIF_HbFlash_read
*/

CY_SMIF_FLASHDATA CY_SMIF_HbFlash_PpbStatusReadOp ( CY_SMIF_FLASHDATA *base_addr, CY_SMIF_ADDRESS offset)
{
  CY_SMIF_FLASHDATA  status;
  
  CY_SMIF_HbFlash_PpbEntryCmd(base_addr,offset);
  status = (CY_SMIF_FLASH_RD(base_addr, offset));
  CY_SMIF_HbFlash_PpbExitCmd(base_addr);
  
  return status;

}

/******************************************************************************
* 
* CY_SMIF_HbFlash_LockRegBitsReadOp - Operation to read the lock status register.
*
* RETURNS: CY_SMIF_FLASHDATA
*
*/
CY_SMIF_FLASHDATA CY_SMIF_HbFlash_LockRegBitsReadOp ( CY_SMIF_FLASHDATA *base_addr)
{ 
  CY_SMIF_FLASHDATA value;

  CY_SMIF_HbFlash_LockRegEntryCmd(base_addr);
  value = CY_SMIF_HbFlash_LockRegBitsReadCmd(base_addr);
  CY_SMIF_HbFlash_LockRegExitCmd(base_addr);

  return(value);
}


/******************************************************************************
* 
* CY_SMIF_HbFlash_LockRegBitsProgramOp - Operation to program the lock register.
*
* RETURNS: 0 Successful
*         -1 Failed
*
*/
int CY_SMIF_HbFlash_LockRegBitsProgramOp ( CY_SMIF_FLASHDATA *base_addr, CY_SMIF_FLASHDATA value)
{
  CY_SMIF_DEVSTATUS    dev_status = CY_SMIF_DEV_STATUS_UNKNOWN;
  CY_SMIF_FLASHDATA    status_reg;

  CY_SMIF_HbFlash_LockRegEntryCmd(base_addr);
  CY_SMIF_HbFlash_LockRegBitsProgramCmd(base_addr,value);

  /* poll for completion */
    status_reg = CY_SMIF_HbFlash_Poll(base_addr, 0);
    if( (status_reg & CY_SMIF_DEV_PROGRAM_MASK) == CY_SMIF_DEV_PROGRAM_MASK )
      dev_status =  CY_SMIF_DEV_PROGRAM_ERROR;    /* program error */
  else
    dev_status = CY_SMIF_DEV_NOT_BUSY;

  /* if not done, then we have an error */
  if (dev_status != CY_SMIF_DEV_NOT_BUSY)
  {
     /* Write Software RESET command */
     CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_RESET_CMD);
     CY_SMIF_HbFlash_LockRegExitCmd(base_addr);
     return (-1); /* return error */
  }

  CY_SMIF_HbFlash_LockRegExitCmd(base_addr);
  return 0; /* successful */
}





/**************************************************************************
* Special API for RPC2 device (KS-S/KL-S)
**************************************************************************/

/******************************************************************************
* 
* CY_SMIF_HbFlash_EnterDeepPowerDown - Enter Deep Power Down Command.
* Note: n/a
* RETURNS: n/a
*
*/
extern void CY_SMIF_HbFlash_EnterDeepPowerDown
(
  CY_SMIF_FLASHDATA *base_addr  /* device base address in system */
)
{
  /* Issue Enter Deep Power Down command */
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_ENTER_DEEP_POWER_DOWN_CMD);
}

/******************************************************************************
* 
* CY_SMIF_HbFlash_MeasureTemperature - Measure Temperature Command.
* Note: n/a
* RETURNS: n/a
*
*/
extern void CY_SMIF_HbFlash_MeasureTemperature
(
 CY_SMIF_FLASHDATA *base_addr
)
{
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_MEASURE_TEMPERATURE_CMD);
}

/******************************************************************************
* 
* CY_SMIF_HbFlash_ReadTemperatureReg - Read Temperature Register
* Note: n/a
* RETURNS: CY_SMIF_FLASHDATA
*
*/
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadTemperatureReg 
(
 CY_SMIF_FLASHDATA *base_addr 
)
{
  CY_SMIF_FLASHDATA value;

  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_READ_TEMPERATURE_REG_CMD);  
  value = (CY_SMIF_FLASH_RD(base_addr, 0));

  return(value);
}

/******************************************************************************
* 
* CY_SMIF_HbFlash_ProgramPORTimerReg - Program Power On Reset Timer Register
* Note: n/a
* RETURNS: n/a
*
*/
extern void CY_SMIF_HbFlash_ProgramPORTimerReg
(
 CY_SMIF_FLASHDATA *base_addr,
 CY_SMIF_FLASHDATA portime 			/* Power On Reset Time */
)
{
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_PROGRAM_POR_TIMER_CMD);
  CY_SMIF_FLASH_WR(base_addr, 0, portime);
}

/******************************************************************************
* 
* CY_SMIF_HbFlash_ReadPORTimerReg - Read Power On Reset Timer Register
* Note: n/a
* RETURNS: CY_SMIF_FLASHDATA
*
*/
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadPORTimerReg
(
 CY_SMIF_FLASHDATA *base_addr
)
{
  CY_SMIF_FLASHDATA value;
  
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_READ_POR_TIMER_CMD);
  value = (CY_SMIF_FLASH_RD(base_addr, 0));

  return(value);
}

/******************************************************************************
* 
* CY_SMIF_HbFlash_LoadInterruptConfigReg - Load Interrupt Configuration Register
* Note: n/a
* RETURNS: n/a
*
*/
extern void CY_SMIF_HbFlash_LoadInterruptConfigReg 
(
 CY_SMIF_FLASHDATA *base_addr,
 CY_SMIF_FLASHDATA icr				/* Interrupt Configuration Register */
)
{
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_LOAD_INTERRUPT_CFG_REG_CMD);
  CY_SMIF_FLASH_WR(base_addr, 0, icr);
}

/******************************************************************************
* 
* CY_SMIF_HbFlash_ReadInterruptConfigReg - Read Interrupt Configuration Register
* Note: n/a
* RETURNS: CY_SMIF_FLASHDATA
*
*/
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadInterruptConfigReg
(
 CY_SMIF_FLASHDATA *base_addr
)
{
  CY_SMIF_FLASHDATA value;
  
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_READ_INTERRUPT_CFG_REG_CMD);
  value = (CY_SMIF_FLASH_RD(base_addr, 0));

  return(value);
}

/******************************************************************************
* 
* CY_SMIF_HbFlash_LoadInterruptStatusReg - Load Interrupt Status Register
* Note: n/a
* RETURNS: n/a
*
*/
extern void CY_SMIF_HbFlash_LoadInterruptStatusReg
(
 CY_SMIF_FLASHDATA *base_addr, 
 CY_SMIF_FLASHDATA isr      /* Interrupt Status Register */
)
{
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_LOAD_INTERRUPT_STATUS_REG_CMD);
  CY_SMIF_FLASH_WR(base_addr, 0, isr);
}

/******************************************************************************
* 
* CY_SMIF_HbFlash_ReadInterruptStatusReg - Read Interrupt Status Register
* Note: n/a
* RETURNS: CY_SMIF_FLASHDATA
*
*/
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadInterruptStatusReg
(
 CY_SMIF_FLASHDATA *base_addr
)
{
  CY_SMIF_FLASHDATA value;
  
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_READ_INTERRUPT_STATUS_REG_CMD);
  value = (CY_SMIF_FLASH_RD(base_addr, 0));

  return(value);
}

/******************************************************************************
* 
* CY_SMIF_HbFlash_LoadVolatileConfigReg - Load Volatile Configuration Register
* Note: n/a
* RETURNS: n/a
*
*/
extern void CY_SMIF_HbFlash_LoadVolatileConfigReg
(
 CY_SMIF_FLASHDATA *base_addr,
 CY_SMIF_FLASHDATA vcr
)
{
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_LOAD_VOLATILE_CFG_REG_CMD);
  CY_SMIF_FLASH_WR(base_addr, 0, vcr);
}

/******************************************************************************
* 
* CY_SMIF_HbFlash_ReadInterruptStatusReg - Read Volatile Configuration Register
* Note: n/a
* RETURNS: CY_SMIF_FLASHDATA
*         
*/
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadVolatileConfigReg
(
 CY_SMIF_FLASHDATA *base_addr
)
{
  CY_SMIF_FLASHDATA value;
  
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_READ_VOLATILE_CFG_REG_CMD);
  value = (CY_SMIF_FLASH_RD(base_addr, 0));

  return(value);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ProgramVolatileConfigRegOp
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_ProgramVolatileConfigRegOp
(
 CY_SMIF_FLASHDATA *base_addr,
 CY_SMIF_FLASHDATA vcr
)
{
  CY_SMIF_FLASHDATA status_reg;
  
  /* Load VCR */
  CY_SMIF_HbFlash_LoadVolatileConfigReg(base_addr, vcr);

  /* Poll for Program completion */
  status_reg = CY_SMIF_HbFlash_Poll(base_addr, 0);

  if( (status_reg & CY_SMIF_DEV_PROGRAM_MASK) == CY_SMIF_DEV_PROGRAM_MASK )
	  return( CY_SMIF_DEV_PROGRAM_ERROR );		/* program error */

  return( CY_SMIF_DEV_NOT_BUSY );			    /* program complete */
}

/******************************************************************************
* 
* CY_SMIF_HbFlash_ProgramNonVolatileConfigReg - Program Non-Volatile Configuration Register
* Note: n/a
* RETURNS: n/a
*
*/
extern void CY_SMIF_HbFlash_ProgramNonVolatileConfigReg
(
 CY_SMIF_FLASHDATA *base_addr, 
 CY_SMIF_FLASHDATA nvcr
)
{
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_PROGRAM_NON_VOLATILE_CFG_REG_CMD);
  CY_SMIF_FLASH_WR(base_addr, 0, nvcr);
}

/******************************************************************************
* 
* CY_SMIF_HbFlash_EraseNonVolatileConfigReg - Erase Non-Volatile Configuration Register
* Note: n/a
* RETURNS: n/a
*
*/
extern void CY_SMIF_HbFlash_EraseNonVolatileConfigReg
(
 CY_SMIF_FLASHDATA *base_addr
)
{
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_ERASE_NON_VOLATILE_CFG_REG_CMD);
}

/******************************************************************************
* 
* CY_SMIF_HbFlash_ReadNonVolatileConfigReg - Read Non-Volatile Configuration Register
* Note: n/a
* RETURNS: CY_SMIF_FLASHDATA
*
*/
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadNonVolatileConfigReg
(
 CY_SMIF_FLASHDATA *base_addr
)
{
  CY_SMIF_FLASHDATA value;
  
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_READ_NON_VOLATILE_CFG_REG_CMD);
  value = (CY_SMIF_FLASH_RD(base_addr, 0));

  return(value);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ProgramNonVolatileConfigRegOp
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
CY_SMIF_DEVSTATUS CY_SMIF_HbFlash_ProgramNonVolatileConfigRegOp
(
 CY_SMIF_FLASHDATA *base_addr,
 CY_SMIF_FLASHDATA nvcr
)
{
  CY_SMIF_FLASHDATA status_reg;

  /* Erase NVCR */
  CY_SMIF_HbFlash_EraseNonVolatileConfigReg(base_addr);

  /* Poll for erase completion */
  status_reg = CY_SMIF_HbFlash_Poll(base_addr, 0);
  if( (status_reg & CY_SMIF_DEV_ERASE_MASK) == CY_SMIF_DEV_ERASE_MASK )
    return( CY_SMIF_DEV_ERASE_ERROR );		/* erase  error */

  /* Program NVCR */
  CY_SMIF_HbFlash_ProgramNonVolatileConfigReg(base_addr, nvcr);

  /* Poll for program completion */
  status_reg = CY_SMIF_HbFlash_Poll(base_addr, 0);
  if( (status_reg & CY_SMIF_DEV_PROGRAM_MASK) == CY_SMIF_DEV_PROGRAM_MASK )
    return( CY_SMIF_DEV_PROGRAM_ERROR );		/* program error */

  return( CY_SMIF_DEV_NOT_BUSY );			    /* program complete */
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_EvaluateEraseStatus
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
extern void CY_SMIF_HbFlash_EvaluateEraseStatus
(
 CY_SMIF_FLASHDATA *base_addr, 
 CY_SMIF_ADDRESS   offset
)
{
  /* Write Evaluate Erase Status Command to Offset */
  CY_SMIF_FLASH_WR(base_addr, (offset & CY_SMIF_SA_OFFSET_MASK) + CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_EVALUATE_ERASE_STATUS_CMD);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ECCStatusEnterCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
extern void CY_SMIF_HbFlash_ECCStatusEnterCmd
(
 CY_SMIF_FLASHDATA *base_addr
)
{
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_ECC_STATUS_ENTER_CMD);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ECCStatusReadCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ECCStatusReadCmd
(
 CY_SMIF_FLASHDATA *base_addr, 
 CY_SMIF_ADDRESS   offset
)
{
  CY_SMIF_FLASHDATA value;
  value = (CY_SMIF_FLASH_RD(base_addr, offset));
  return(value);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ECCErrorLowerAddrRegReadCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ECCErrorLowerAddrRegReadCmd
(
  CY_SMIF_FLASHDATA *base_addr
)
{
  CY_SMIF_FLASHDATA value;
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_ECC_READ_ERROR_CMD);
  value = (CY_SMIF_FLASH_RD(base_addr, 0x01));
  return(value);  
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ECCErrorUpperAddrRegReadCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ECCErrorUpperAddrRegReadCmd
(
  CY_SMIF_FLASHDATA *base_addr
)
{
  CY_SMIF_FLASHDATA value;
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_ECC_READ_ERROR_CMD);
  value = (CY_SMIF_FLASH_RD(base_addr, 0x02));
  return(value);  
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ECCReadErrorDetectionCounterCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ECCReadErrorDetectionCounterCmd
(
 CY_SMIF_FLASHDATA *base_addr
)
{
  CY_SMIF_FLASHDATA value;
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_ECC_READ_ERROR_CMD);
  value = (CY_SMIF_FLASH_RD(base_addr, 0x03));
  return(value);  
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ECCClearErrorDetectionCounterCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
extern void CY_SMIF_HbFlash_ECCClearErrorDetectionCounterCmd
(
 CY_SMIF_FLASHDATA *base_addr
)
{
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_ECC_CLEAR_ERROR_DETECTION_COUNTER_CMD);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ECCExitCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
extern void CY_SMIF_HbFlash_ECCExitCmd
(
 CY_SMIF_FLASHDATA *base_addr
)
{
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_ECC_EXIT_CMD);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ECCStatusReadOp
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ECCStatusReadOp
(
 CY_SMIF_FLASHDATA *base_addr, 
 CY_SMIF_ADDRESS   offset
)
{
  CY_SMIF_FLASHDATA value;
  CY_SMIF_HbFlash_ECCStatusEnterCmd(base_addr);
  value = (CY_SMIF_FLASH_RD(base_addr, offset));
  CY_SMIF_HbFlash_ECCExitCmd(base_addr);
  return (value);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_CRCEnterCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
extern void CY_SMIF_HbFlash_CRCEnterCmd
(
 CY_SMIF_FLASHDATA *base_addr
)
{
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_UNLOCK_DATA1);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR2, CY_SMIF_NOR_UNLOCK_DATA2);
  CY_SMIF_FLASH_WR(base_addr, CY_SMIF_HB_FLASH_UNLOCK_ADDR1, CY_SMIF_NOR_CRC_ENTRY_CMD);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_LoadCRCStartAddrCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
extern void CY_SMIF_HbFlash_LoadCRCStartAddrCmd
(
 CY_SMIF_FLASHDATA *base_addr, 
 CY_SMIF_ADDRESS   offset             /* Beginning location of checkvalue calculation */
)
{
  CY_SMIF_FLASH_WR(base_addr, offset, CY_SMIF_NOR_LOAD_CRC_START_ADDR_CMD);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_LoadCRCEndAddrCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
extern void CY_SMIF_HbFlash_LoadCRCEndAddrCmd
(
 CY_SMIF_FLASHDATA *base_addr, 
 CY_SMIF_ADDRESS   offset             /* Ending location of checkvalue calculation */
)
{
  CY_SMIF_FLASH_WR(base_addr, offset, CY_SMIF_NOR_LOAD_CRC_END_ADDR_CMD);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_CRCSuspendCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
extern void CY_SMIF_HbFlash_CRCSuspendCmd
(
 CY_SMIF_FLASHDATA *base_addr
)
{
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_CRC_SUSPEND_CMD);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_CRCArrayReadCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_CRCArrayReadCmd
(
 CY_SMIF_FLASHDATA *base_addr,
 CY_SMIF_ADDRESS   offset           /* Array Read Address */
)
{
  CY_SMIF_FLASHDATA value;
  value = (CY_SMIF_FLASH_RD(base_addr, offset));
  return(value);  
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_CRCResumeCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
extern void CY_SMIF_HbFlash_CRCResumeCmd
(
 CY_SMIF_FLASHDATA *base_addr
)
{
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_CRC_RESUME_CMD);
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ReadCheckvalueLowResultRegCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadCheckvalueLowResultRegCmd
(
 CY_SMIF_FLASHDATA *base_addr 
)
{
  CY_SMIF_FLASHDATA value;
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_CRC_READ_CHECKVALUE_RESLUT_REG_CMD);
  value = (CY_SMIF_FLASH_RD(base_addr, 0x00));
  return(value);  
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_ReadCheckvalueHighResultRegCmd
****************************************************************************//**
*
* \param
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
extern CY_SMIF_FLASHDATA CY_SMIF_HbFlash_ReadCheckvalueHighResultRegCmd
(
 CY_SMIF_FLASHDATA *base_addr
)
{
  CY_SMIF_FLASHDATA value;
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_CRC_READ_CHECKVALUE_RESLUT_REG_CMD);
  value = (CY_SMIF_FLASH_RD(base_addr, 0x01));
  return(value);  
}

/*******************************************************************************
* Function Name: CY_SMIF_HbFlash_CRCExitCmd
****************************************************************************//**
*
* \paramCY_SMIF_FLASHDATA
*
* \note
*
* \return
*     - \ref CY_SMIF_HYPERBUSI_STATUS
*
*******************************************************************************/
extern void CY_SMIF_HbFlash_CRCExitCmd
(
 CY_SMIF_FLASHDATA *base_addr
)
{
  CY_SMIF_FLASH_WR(base_addr, 0, CY_SMIF_NOR_CRC_EXIT_CMD);
}

#if defined(__cplusplus)
}
#endif
