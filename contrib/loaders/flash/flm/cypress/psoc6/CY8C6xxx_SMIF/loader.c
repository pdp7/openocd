//#include "loader.h"

//result_t Loader_Program(uint32_t blockAddr, uint32_t offsetInBlock, uint8_t *buffer, uint32_t size)
//{
//    result_t result = RESULT_OK;

//    /* Check whether it is internal or external (SMIF\XIP) memory */
//    mem_type_t mem_type = Loader_GetMemType(blockAddr);
//    bool isSupportedMem = false;
//    if (mem_type == MEM_TYPE_FLASH)
//    {
//        //#if defined(BUILD_ENABLE_LOADER_FLASH)
//        /* Program internal Flash */
//        isSupportedMem = true;
//        //result = Loader_Flash_Program(blockAddr, offsetInBlock, buffer, size, PRG_API_PROGRAM_ROW);
//        //#endif
//    }
//    else if (mem_type == MEM_TYPE_SMIF)
//    {
//        //#if defined(BUILD_ENABLE_LOADER_SMIF)
//        /* Program external memory via the SMIF block*/
//        isSupportedMem = true;
//        //result = Loader_SMIF_Program(blockAddr, offsetInBlock, buffer, size);
//        //#endif
//    }

//    if (!isSupportedMem)
//    {
//        LOG("\r\nERROR: unsupported memory address!\r\n");
//        result = RESULT_ERROR;
//    }
//
//    return result;
//}


///*******************************************************************************
//* Function Name: Loader_GetMemType
//********************************************************************************
//*
//* Detects the memory type from provided address
//*
//* \param addr
//* Memory address
//*
//* \return
//* Memory type (MEM_TYPE_FLASH or MEM_TYPE_SMIF
//*
//*******************************************************************************/
//mem_type_t Loader_GetMemType(uint32_t addr)
//{
//    if (addr < TARGET_XIP_ADDR)
//    {
//        return MEM_TYPE_FLASH;
//    }
//    else
//    if ((addr >= TARGET_XIP_ADDR) &&
//        (addr < (TARGET_XIP_ADDR + TARGET_XIP_SIZE)))
//    {
//        return MEM_TYPE_SMIF;
//    }
//    else
//    {
//        return MEM_TYPE_UNKNOWN;
//    }
//}


///*******************************************************************************
//* Function Name: Loader_ApiEraseRow
//********************************************************************************
//*
//* Erases the memory type from provided address
//*
//* \param addr
//* Memory address
//*
//* \return
//* Result of the operation
//*
//*******************************************************************************/
//int Loader_ApiEraseRow(uint32_t adr)
//{
//	int retVal;
//
//	retVal = Loader_GetMemType(adr);
//
//	if (retVal == MEM_TYPE_FLASH)
//	{
//		retVal = SromApiEraseRow(adr);
//	}
//	else if (MEM_TYPE_SMIF)
//	{
//		//SMIF memory not supported
//		//retVal = Loader_SMIF_Erase(adr);
//		retVal = 1u;
//	}
//	else
//	{
//		retVal = 1u;
//	}

//
//	return (retVal);
//}


///*******************************************************************************
//* Function Name: Loader_ProgRow
//********************************************************************************
//*
//* Erases the memory type from provided address
//*
//* \param addr
//* Memory address
//*
//* \return
//* Result of the operation
//*
//*******************************************************************************/
//int Loader_ProgRow(unsigned long adr, unsigned long sz, unsigned char *buf)
//{
//	int retVal;
//
//	retVal = Loader_GetMemType(adr);
//
//	if (retVal == MEM_TYPE_FLASH)
//	{
//		SromApiProgramRow(adr, buf, sz);
//	}
//	else if (MEM_TYPE_SMIF)
//	{
//		//SMIF memory not supported
//		//retVal = Loader_SMIF_Erase(adr);
//		retVal = 1u;
//	}
//	else
//	{
//		retVal = 1u;
//	}
//
//
//	return (retVal);
//}


//void Loader_InitSmif(void)
//{

//}
