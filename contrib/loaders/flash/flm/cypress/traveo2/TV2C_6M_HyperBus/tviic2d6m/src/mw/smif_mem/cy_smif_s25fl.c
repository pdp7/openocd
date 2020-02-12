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

/************************************************************/
/*************** Specify Read Command Sequence **************/
/************************************************************/
static const  cy_stc_cmd_sq_t g_s25flReadCmdTypes[] =
{
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE}, // cmdTypeNum = 0
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_NOT_PRESENT},   // cmdTypeNum = 1
};

/************************************************************/
/*************** Specify Read Address Sequence **************/
/************************************************************/
static const  cy_stc_addr_sq_t g_s25flReadAddrTypes[] =
{
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .addrLen = CY_SMIF_XIP_ADDRESS_3_BYTE}, // addrTypeNum = 0
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .addrLen = CY_SMIF_XIP_ADDRESS_4_BYTE}, // addrTypeNum = 1
	{.width = CY_SMIF_WIDTH_DUAL,   .dataRate = CY_SMIF_SDR, .addrLen = CY_SMIF_XIP_ADDRESS_3_BYTE}, // addrTypeNum = 2
	{.width = CY_SMIF_WIDTH_DUAL,   .dataRate = CY_SMIF_SDR, .addrLen = CY_SMIF_XIP_ADDRESS_4_BYTE}, // addrTypeNum = 3
	{.width = CY_SMIF_WIDTH_QUAD,   .dataRate = CY_SMIF_SDR, .addrLen = CY_SMIF_XIP_ADDRESS_3_BYTE}, // addrTypeNum = 4
	{.width = CY_SMIF_WIDTH_QUAD,   .dataRate = CY_SMIF_SDR, .addrLen = CY_SMIF_XIP_ADDRESS_4_BYTE}, // addrTypeNum = 5
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_DDR, .addrLen = CY_SMIF_XIP_ADDRESS_3_BYTE}, // addrTypeNum = 6
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_DDR, .addrLen = CY_SMIF_XIP_ADDRESS_4_BYTE}, // addrTypeNum = 7
	{.width = CY_SMIF_WIDTH_DUAL,   .dataRate = CY_SMIF_DDR, .addrLen = CY_SMIF_XIP_ADDRESS_3_BYTE}, // addrTypeNum = 8
	{.width = CY_SMIF_WIDTH_DUAL,   .dataRate = CY_SMIF_DDR, .addrLen = CY_SMIF_XIP_ADDRESS_4_BYTE}, // addrTypeNum = 9
	{.width = CY_SMIF_WIDTH_QUAD,   .dataRate = CY_SMIF_DDR, .addrLen = CY_SMIF_XIP_ADDRESS_3_BYTE}, // addrTypeNum = 10
	{.width = CY_SMIF_WIDTH_QUAD,   .dataRate = CY_SMIF_DDR, .addrLen = CY_SMIF_XIP_ADDRESS_4_BYTE}, // addrTypeNum = 11
};

/************************************************************/
/**************** Specify Read Mode Sequence ****************/
/************************************************************/
static const  cy_stc_mode_sq_t g_s25flReadModeTypes[] =
{
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_NOT_PRESENT  }, // modeTypeNum = 0
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE}, // modeTypeNum = 1
	{.width = CY_SMIF_WIDTH_DUAL,   .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE}, // modeTypeNum = 2
	{.width = CY_SMIF_WIDTH_QUAD,   .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE}, // modeTypeNum = 3
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_DDR, .presence = CY_SMIF_PRESENT_1BYTE}, // modeTypeNum = 4
	{.width = CY_SMIF_WIDTH_DUAL,   .dataRate = CY_SMIF_DDR, .presence = CY_SMIF_PRESENT_1BYTE}, // modeTypeNum = 5
	{.width = CY_SMIF_WIDTH_QUAD,   .dataRate = CY_SMIF_DDR, .presence = CY_SMIF_PRESENT_1BYTE}, // modeTypeNum = 6
};

/************************************************************/
/**************** Specify Read Dummy Sequence ***************/
/************************************************************/
static const  cy_stc_dummy_sq_t g_s25flReadDummyTypes[] =
{
	{.tableId = 0, .width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE, .doubleDm = false, .rwdsInDm = false, .dlpEn = false, .rwdsEn = false}, // dummyTypeNum = 0
	{.tableId = 1, .width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE, .doubleDm = false, .rwdsInDm = false, .dlpEn = false, .rwdsEn = false}, // dummyTypeNum = 1
#if (CY_SMIF_QUAD_DEVICE_TYPE == CY_SMIF_S25FXXXS)
	{.tableId = 2, .width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE, .doubleDm = false, .rwdsInDm = false, .dlpEn = false, .rwdsEn = false}, // dummyTypeNum = 2
	{.tableId = 3, .width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE, .doubleDm = false, .rwdsInDm = false, .dlpEn = false, .rwdsEn = false}, // dummyTypeNum = 3
	{.tableId = 4, .width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE, .doubleDm = false, .rwdsInDm = false, .dlpEn = false, .rwdsEn = false}, // dummyTypeNum = 4
	{.tableId = 5, .width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE, .doubleDm = false, .rwdsInDm = false, .dlpEn = false, .rwdsEn = false}, // dummyTypeNum = 5
	{.tableId = 6, .width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE, .doubleDm = false, .rwdsInDm = false, .dlpEn = false, .rwdsEn = false}, // dummyTypeNum = 6
	{.tableId = 7, .width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE, .doubleDm = false, .rwdsInDm = false, .dlpEn = false, .rwdsEn = false}, // dummyTypeNum = 7
	{.tableId = 8, .width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE, .doubleDm = false, .rwdsInDm = false, .dlpEn = false, .rwdsEn = false}, // dummyTypeNum = 8
#endif
};

#if (CY_SMIF_QUAD_DEVICE_TYPE == CY_SMIF_S25FXXXS)
  #ifdef S25FL_USE_LC_ENHANCED                                                 //LC: b'00 b'01 b'10 b'11
	#define g_s25flLatancyTableOfRead     {0u,  0u,  0u,  0u, }
	#define g_s25flLatancyTableOfFastRead {8u,  8u,  8u,  0u, }
	#define g_s25flLatancyTableOfDOR      {8u,  8u,  8u,  0u, }
	#define g_s25flLatancyTableOfQOR      {8u,  8u,  8u,  0u, }
	#define g_s25flLatancyTableOfDIOR     {0u,  1u,  2u,  0u, }
	#define g_s25flLatancyTableOfQIOR     {4u,  4u,  5u,  1u, }
	#define g_s25flLatancyTableOfDDRFR    {2u,  4u,  5u,  1u, }
	#define g_s25flLatancyTableOfDDRDIOR  {4u,  5u,  6u,  2u, }
	#define g_s25flLatancyTableOfDDRQIOR  {6u,  7u,  8u,  3u, }
  #else                                                                        //LC: b'00 b'01 b'10 b'11
	#define g_s25flLatancyTableOfRead     {0u,  0u,  0u,  0u};
	#define g_s25flLatancyTableOfFastRead {8u,  8u,  8u,  0u};
	#define g_s25flLatancyTableOfDOR      {8u,  8u,  8u,  0u};
	#define g_s25flLatancyTableOfQOR      {8u,  8u,  8u,  0u};
	#define g_s25flLatancyTableOfDIOR     {4u,  5u,  6u,  4u};
	#define g_s25flLatancyTableOfQIOR     {4u,  4u,  5u,  1u};
	#define g_s25flLatancyTableOfDDRFR    {5u,  6u,  7u,  4u};
	#define g_s25flLatancyTableOfDDRDIOR  {6u,  7u,  8u,  4u};
	#define g_s25flLatancyTableOfDDRQIOR  {6u,  7u,  8u,  3u};
  #endif
#elif(CY_SMIF_QUAD_DEVICE_TYPE == CY_SMIF_S25FXXXL)
  #define g_s25flLatancyTableOfRead          {0u,  0u,  0u,  0u, 0u,  0u,  0u,  0u, 0u,  0u,  0u,  0u,  0u,  0u,  0u,  0u}; // CY_SMIF_READ, CY_SMIF_4READ;
  #define g_s25flLatancyTableOfOtherThanRead {0u,  1u,  2u,  3u, 4u,  5u,  6u,  7u, 8u,  9u, 10u, 11u, 12u, 13u, 14u, 15u}; // Other than READ, 4READ;
#endif

#if (CY_SMIF_QUAD_DEVICE_TYPE == CY_SMIF_S25FXXXS)
static const uint8_t g_s25flReadLatencyCodeToDummyCycle[16][16] = {
	g_s25flLatancyTableOfRead,
	g_s25flLatancyTableOfFastRead,
	g_s25flLatancyTableOfDOR,
	g_s25flLatancyTableOfQOR,
	g_s25flLatancyTableOfDIOR,
	g_s25flLatancyTableOfQIOR,
	g_s25flLatancyTableOfDDRFR,
	g_s25flLatancyTableOfDDRDIOR,
	g_s25flLatancyTableOfDDRQIOR,
};
#elif (CY_SMIF_QUAD_DEVICE_TYPE == CY_SMIF_S25FXXXL)
static const uint8_t g_s25flReadLatencyCodeToDummyCycle[16][16] = {
	g_s25flLatancyTableOfRead,
	g_s25flLatancyTableOfOtherThanRead,
}
#endif

/************************************************************/
/**************** Specify Read Data Sequence ****************/
/************************************************************/
static const  cy_stc_data_sq_t g_s25flReadDataTypes[] =
{
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR}, // dataTypeNum = 0
	{.width = CY_SMIF_WIDTH_DUAL,   .dataRate = CY_SMIF_SDR}, // dataTypeNum = 1
	{.width = CY_SMIF_WIDTH_QUAD,   .dataRate = CY_SMIF_SDR}, // dataTypeNum = 2
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_DDR}, // dataTypeNum = 3
	{.width = CY_SMIF_WIDTH_DUAL,   .dataRate = CY_SMIF_DDR}, // dataTypeNum = 4
	{.width = CY_SMIF_WIDTH_QUAD,   .dataRate = CY_SMIF_DDR}, // dataTypeNum = 5
};

/************************************************************/
/************* Read Command Table for S25FLxxxX *************/
/************************************************************/
static const  cy_stc_read_info_t g_s25flReadCmdInfo[] =
{
#if (CY_SMIF_QUAD_DEVICE_TYPE == CY_SMIF_S25FXXXS)
	{ .cmd = CY_SMIF_S25FL_CMD_READ,       .cmdTypeNum = 0u, .addrTypeNum = 0u,  .modeTypeNum = 0u, .dummyTypeNum = 0, .dataTypeNum = 0u }, // cmd id = 0,
	{ .cmd = CY_SMIF_S25FL_CMD_4READ,      .cmdTypeNum = 0u, .addrTypeNum = 1u,  .modeTypeNum = 0u, .dummyTypeNum = 0, .dataTypeNum = 0u }, // cmd id = 1,
	{ .cmd = CY_SMIF_S25FL_CMD_FAST_READ,  .cmdTypeNum = 0u, .addrTypeNum = 0u,  .modeTypeNum = 0u, .dummyTypeNum = 1, .dataTypeNum = 0u }, // cmd id = 2,
	{ .cmd = CY_SMIF_S25FL_CMD_4FAST_READ, .cmdTypeNum = 0u, .addrTypeNum = 1u,  .modeTypeNum = 0u, .dummyTypeNum = 1, .dataTypeNum = 0u }, // cmd id = 3,
	{ .cmd = CY_SMIF_S25FL_CMD_DOR,        .cmdTypeNum = 0u, .addrTypeNum = 0u,  .modeTypeNum = 0u, .dummyTypeNum = 2, .dataTypeNum = 1u }, // cmd id = 4,
	{ .cmd = CY_SMIF_S25FL_CMD_4DOR,       .cmdTypeNum = 0u, .addrTypeNum = 1u,  .modeTypeNum = 0u, .dummyTypeNum = 2, .dataTypeNum = 1u }, // cmd id = 5,
	{ .cmd = CY_SMIF_S25FL_CMD_QOR,        .cmdTypeNum = 0u, .addrTypeNum = 0u,  .modeTypeNum = 0u, .dummyTypeNum = 3, .dataTypeNum = 2u }, // cmd id = 6,
	{ .cmd = CY_SMIF_S25FL_CMD_4QOR,       .cmdTypeNum = 0u, .addrTypeNum = 1u,  .modeTypeNum = 0u, .dummyTypeNum = 3, .dataTypeNum = 2u }, // cmd id = 7,

  #ifdef S25FL_USE_LC_ENHANCED
	{ .cmd = CY_SMIF_S25FL_CMD_DIOR,       .cmdTypeNum = 0u, .addrTypeNum = 2u,  .modeTypeNum = 2u, .dummyTypeNum = 4, .dataTypeNum = 1u }, // cmd id = 8,
	{ .cmd = CY_SMIF_S25FL_CMD_DIOR,       .cmdTypeNum = 1u, .addrTypeNum = 2u,  .modeTypeNum = 2u, .dummyTypeNum = 4, .dataTypeNum = 1u }, // cmd id = 9,
	{ .cmd = CY_SMIF_S25FL_CMD_4DIOR,      .cmdTypeNum = 0u, .addrTypeNum = 3u,  .modeTypeNum = 2u, .dummyTypeNum = 4, .dataTypeNum = 1u }, // cmd id = 10,
	{ .cmd = CY_SMIF_S25FL_CMD_4DIOR,      .cmdTypeNum = 1u, .addrTypeNum = 3u,  .modeTypeNum = 2u, .dummyTypeNum = 4, .dataTypeNum = 1u }, // cmd id = 11,
  #else
	{ .cmd = CY_SMIF_S25FL_CMD_DIOR,       .cmdTypeNum = 0u, .addrTypeNum = 2u,  .modeTypeNum = 0u, .dummyTypeNum = 4, .dataTypeNum = 1u }, // cmd id = 8,
	{ .cmd = CY_SMIF_S25FL_CMD_DIOR,       .cmdTypeNum = 1u, .addrTypeNum = 2u,  .modeTypeNum = 0u, .dummyTypeNum = 4, .dataTypeNum = 1u }, // cmd id = 9,
	{ .cmd = CY_SMIF_S25FL_CMD_4DIOR,      .cmdTypeNum = 0u, .addrTypeNum = 3u,  .modeTypeNum = 0u, .dummyTypeNum = 4, .dataTypeNum = 1u }, // cmd id = 10,
	{ .cmd = CY_SMIF_S25FL_CMD_4DIOR,      .cmdTypeNum = 1u, .addrTypeNum = 3u,  .modeTypeNum = 0u, .dummyTypeNum = 4, .dataTypeNum = 1u }, // cmd id = 11,
  #endif

	{ .cmd = CY_SMIF_S25FL_CMD_QIOR,       .cmdTypeNum = 0u, .addrTypeNum = 4u,  .modeTypeNum = 3u, .dummyTypeNum = 5, .dataTypeNum = 2u }, // cmd id = 12,
	{ .cmd = CY_SMIF_S25FL_CMD_QIOR,       .cmdTypeNum = 1u, .addrTypeNum = 4u,  .modeTypeNum = 3u, .dummyTypeNum = 5, .dataTypeNum = 2u }, // cmd id = 13,
	{ .cmd = CY_SMIF_S25FL_CMD_4QIOR,      .cmdTypeNum = 0u, .addrTypeNum = 5u,  .modeTypeNum = 3u, .dummyTypeNum = 5, .dataTypeNum = 2u }, // cmd id = 14,
	{ .cmd = CY_SMIF_S25FL_CMD_4QIOR,      .cmdTypeNum = 1u, .addrTypeNum = 5u,  .modeTypeNum = 3u, .dummyTypeNum = 5, .dataTypeNum = 2u }, // cmd id = 15,

	{ .cmd = CY_SMIF_S25FL_CMD_DDRQIOR,    .cmdTypeNum = 0u, .addrTypeNum = 10u, .modeTypeNum = 6u, .dummyTypeNum = 8, .dataTypeNum = 5u }, // cmd id = 16
	{ .cmd = CY_SMIF_S25FL_CMD_DDRQIOR,    .cmdTypeNum = 1u, .addrTypeNum = 10u, .modeTypeNum = 6u, .dummyTypeNum = 8, .dataTypeNum = 5u }, // cmd id = 17
	{ .cmd = CY_SMIF_S25FL_CMD_4DDRQIOR,   .cmdTypeNum = 0u, .addrTypeNum = 11u, .modeTypeNum = 6u, .dummyTypeNum = 8, .dataTypeNum = 5u }, // cmd id = 18
	{ .cmd = CY_SMIF_S25FL_CMD_4DDRQIOR,   .cmdTypeNum = 1u, .addrTypeNum = 11u, .modeTypeNum = 6u, .dummyTypeNum = 8, .dataTypeNum = 5u }, // cmd id = 19

  #ifdef S25FL_USE_LC_ENHANCED
	{ .cmd = CY_SMIF_S25FL_CMD_DDRFR,      .cmdTypeNum = 0u, .addrTypeNum = 6u,  .modeTypeNum = 4u, .dummyTypeNum = 6, .dataTypeNum = 3u }, // cmd id = 20,
	{ .cmd = CY_SMIF_S25FL_CMD_DDRFR,      .cmdTypeNum = 1u, .addrTypeNum = 6u,  .modeTypeNum = 4u, .dummyTypeNum = 6, .dataTypeNum = 3u }, // cmd id = 21,
	{ .cmd = CY_SMIF_S25FL_CMD_4DDRFR,     .cmdTypeNum = 0u, .addrTypeNum = 7u,  .modeTypeNum = 4u, .dummyTypeNum = 6, .dataTypeNum = 3u }, // cmd id = 22,
	{ .cmd = CY_SMIF_S25FL_CMD_4DDRFR,     .cmdTypeNum = 1u, .addrTypeNum = 7u,  .modeTypeNum = 4u, .dummyTypeNum = 6, .dataTypeNum = 3u }, // cmd id = 23,
  #else
	{ .cmd = CY_SMIF_S25FL_CMD_DDRFR,      .cmdTypeNum = 0u, .addrTypeNum = 6u,  .modeTypeNum = 0u, .dummyTypeNum = 6, .dataTypeNum = 3u }, // cmd id = 20,
	{ .cmd = CY_SMIF_S25FL_CMD_DDRFR,      .cmdTypeNum = 1u, .addrTypeNum = 6u,  .modeTypeNum = 0u, .dummyTypeNum = 6, .dataTypeNum = 3u }, // cmd id = 21,
	{ .cmd = CY_SMIF_S25FL_CMD_4DDRFR,     .cmdTypeNum = 0u, .addrTypeNum = 7u,  .modeTypeNum = 0u, .dummyTypeNum = 6, .dataTypeNum = 3u }, // cmd id = 22,
	{ .cmd = CY_SMIF_S25FL_CMD_4DDRFR,     .cmdTypeNum = 1u, .addrTypeNum = 7u,  .modeTypeNum = 0u, .dummyTypeNum = 6, .dataTypeNum = 3u }, // cmd id = 23,
  #endif

  #ifdef S25FL_USE_LC_ENHANCED
	{ .cmd = CY_SMIF_S25FL_CMD_DDRDIOR,    .cmdTypeNum = 0u, .addrTypeNum = 8u,  .modeTypeNum = 5u, .dummyTypeNum = 7, .dataTypeNum = 4u }, // cmd id = 24
	{ .cmd = CY_SMIF_S25FL_CMD_DDRDIOR,    .cmdTypeNum = 1u, .addrTypeNum = 8u,  .modeTypeNum = 5u, .dummyTypeNum = 7, .dataTypeNum = 4u }, // cmd id = 25
	{ .cmd = CY_SMIF_S25FL_CMD_4DDRDIOR,   .cmdTypeNum = 0u, .addrTypeNum = 9u,  .modeTypeNum = 5u, .dummyTypeNum = 7, .dataTypeNum = 4u }, // cmd id = 26
	{ .cmd = CY_SMIF_S25FL_CMD_4DDRDIOR,   .cmdTypeNum = 1u, .addrTypeNum = 9u,  .modeTypeNum = 5u, .dummyTypeNum = 7, .dataTypeNum = 4u }, // cmd id = 27
  #else
	{ .cmd = CY_SMIF_S25FL_CMD_DDRDIOR,    .cmdTypeNum = 0u, .addrTypeNum = 8u,  .modeTypeNum = 0u, .dummyTypeNum = 7, .dataTypeNum = 4u }, // cmd id = 24
	{ .cmd = CY_SMIF_S25FL_CMD_4DDRDIOR,   .cmdTypeNum = 1u, .addrTypeNum = 9u,  .modeTypeNum = 0u, .dummyTypeNum = 7, .dataTypeNum = 4u }, // cmd id = 25
	{ .cmd = CY_SMIF_S25FL_CMD_DDRDIOR,    .cmdTypeNum = 0u, .addrTypeNum = 8u,  .modeTypeNum = 0u, .dummyTypeNum = 7, .dataTypeNum = 4u }, // cmd id = 26
	{ .cmd = CY_SMIF_S25FL_CMD_DDRDIOR,    .cmdTypeNum = 1u, .addrTypeNum = 8u,  .modeTypeNum = 0u, .dummyTypeNum = 7, .dataTypeNum = 4u }, // cmd id = 27
  #endif
#elif (CY_SMIF_QUAD_DEVICE_TYPE == CY_SMIF_S25FXXXL)
	{ .cmd = CY_SMIF_S25FL_CMD_READ,       .cmdTypeNum = 0u, .addrTypeNum = 0u,  .modeTypeNum = 0u, .dummyTypeNum = 0, .dataTypeNum = 0u }, // cmd id = 0,
	{ .cmd = CY_SMIF_S25FL_CMD_4READ,      .cmdTypeNum = 0u, .addrTypeNum = 1u,  .modeTypeNum = 0u, .dummyTypeNum = 0, .dataTypeNum = 0u }, // cmd id = 1,
	{ .cmd = CY_SMIF_S25FL_CMD_FAST_READ,  .cmdTypeNum = 0u, .addrTypeNum = 0u,  .modeTypeNum = 0u, .dummyTypeNum = 1, .dataTypeNum = 0u }, // cmd id = 2,
	{ .cmd = CY_SMIF_S25FL_CMD_4FAST_READ, .cmdTypeNum = 0u, .addrTypeNum = 1u,  .modeTypeNum = 0u, .dummyTypeNum = 1, .dataTypeNum = 0u }, // cmd id = 3,
	{ .cmd = CY_SMIF_S25FL_CMD_DOR,        .cmdTypeNum = 0u, .addrTypeNum = 0u,  .modeTypeNum = 0u, .dummyTypeNum = 1, .dataTypeNum = 1u }, // cmd id = 4,
	{ .cmd = CY_SMIF_S25FL_CMD_4DOR,       .cmdTypeNum = 0u, .addrTypeNum = 1u,  .modeTypeNum = 0u, .dummyTypeNum = 1, .dataTypeNum = 1u }, // cmd id = 5,
	{ .cmd = CY_SMIF_S25FL_CMD_QOR,        .cmdTypeNum = 0u, .addrTypeNum = 0u,  .modeTypeNum = 0u, .dummyTypeNum = 1, .dataTypeNum = 2u }, // cmd id = 6,
	{ .cmd = CY_SMIF_S25FL_CMD_4QOR,       .cmdTypeNum = 0u, .addrTypeNum = 1u,  .modeTypeNum = 0u, .dummyTypeNum = 1, .dataTypeNum = 2u }, // cmd id = 7,
	{ .cmd = CY_SMIF_S25FL_CMD_DIOR,       .cmdTypeNum = 0u, .addrTypeNum = 2u,  .modeTypeNum = 2u, .dummyTypeNum = 1, .dataTypeNum = 1u }, // cmd id = 8,
	{ .cmd = CY_SMIF_S25FL_CMD_DIOR,       .cmdTypeNum = 1u, .addrTypeNum = 2u,  .modeTypeNum = 2u, .dummyTypeNum = 1, .dataTypeNum = 1u }, // cmd id = 9,
	{ .cmd = CY_SMIF_S25FL_CMD_4DIOR,      .cmdTypeNum = 0u, .addrTypeNum = 3u,  .modeTypeNum = 2u, .dummyTypeNum = 1, .dataTypeNum = 1u }, // cmd id = 10,
	{ .cmd = CY_SMIF_S25FL_CMD_4DIOR,      .cmdTypeNum = 1u, .addrTypeNum = 3u,  .modeTypeNum = 2u, .dummyTypeNum = 1, .dataTypeNum = 1u }, // cmd id = 11,
	{ .cmd = CY_SMIF_S25FL_CMD_QIOR,       .cmdTypeNum = 0u, .addrTypeNum = 4u,  .modeTypeNum = 3u, .dummyTypeNum = 1, .dataTypeNum = 2u }, // cmd id = 12,
	{ .cmd = CY_SMIF_S25FL_CMD_QIOR,       .cmdTypeNum = 1u, .addrTypeNum = 4u,  .modeTypeNum = 3u, .dummyTypeNum = 1, .dataTypeNum = 2u }, // cmd id = 13,
	{ .cmd = CY_SMIF_S25FL_CMD_4QIOR,      .cmdTypeNum = 0u, .addrTypeNum = 5u,  .modeTypeNum = 3u, .dummyTypeNum = 1, .dataTypeNum = 2u }, // cmd id = 14,
	{ .cmd = CY_SMIF_S25FL_CMD_4QIOR,      .cmdTypeNum = 1u, .addrTypeNum = 5u,  .modeTypeNum = 3u, .dummyTypeNum = 1, .dataTypeNum = 2u }, // cmd id = 15,
	{ .cmd = CY_SMIF_S25FL_CMD_DDRQIOR,    .cmdTypeNum = 0u, .addrTypeNum = 10u, .modeTypeNum = 6u, .dummyTypeNum = 1, .dataTypeNum = 5u }, // cmd id = 16
	{ .cmd = CY_SMIF_S25FL_CMD_DDRQIOR,    .cmdTypeNum = 1u, .addrTypeNum = 10u, .modeTypeNum = 6u, .dummyTypeNum = 1, .dataTypeNum = 5u }, // cmd id = 17
	{ .cmd = CY_SMIF_S25FL_CMD_4DDRQIOR,   .cmdTypeNum = 0u, .addrTypeNum = 11u, .modeTypeNum = 6u, .dummyTypeNum = 1, .dataTypeNum = 5u }, // cmd id = 18
	{ .cmd = CY_SMIF_S25FL_CMD_4DDRQIOR,   .cmdTypeNum = 1u, .addrTypeNum = 11u, .modeTypeNum = 6u, .dummyTypeNum = 1, .dataTypeNum = 5u }, // cmd id = 19
#endif
};

/************************************************************/
/*************** Specify Write Command Sequence *************/
/************************************************************/
static const  cy_stc_cmd_sq_t g_s25flWriteCmdTypes[] =
{
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_PRESENT_1BYTE}, // cmdTypeNum = 0
};

/************************************************************/
/*************** Specify Write Address Sequence *************/
/************************************************************/
static const  cy_stc_addr_sq_t g_s25flWriteAddrTypes[] =
{
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .addrLen = CY_SMIF_XIP_ADDRESS_3_BYTE}, // addrTypeNum = 0
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .addrLen = CY_SMIF_XIP_ADDRESS_4_BYTE}, // addrTypeNum = 1
};

/************************************************************/
/**************** Specify Write Mode Sequence ***************/
/************************************************************/
static const  cy_stc_mode_sq_t g_s25flWriteModeTypes[] =
{
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_NOT_PRESENT  }, // modeTypeNum = 0
};

/************************************************************/
/**************** Specify Write Dummy Sequence **************/
/************************************************************/
static const  cy_stc_dummy_sq_t g_s25flWriteDummyTypes[] =
{
	{.tableId = 0, .width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR, .presence = CY_SMIF_NOT_PRESENT,   .doubleDm = false, .rwdsInDm = false, .dlpEn = false, .rwdsEn = false}, // dummyTypeNum = 0
};

#define g_latancyTableOfWrite { 0u, }
static const uint8_t g_s25flWriteLatencyCodeToDummyCycle[16][16] = { g_latancyTableOfWrite, };

/************************************************************/
/**************** Specify Write Data Sequence ***************/
/************************************************************/
static const  cy_stc_data_sq_t g_s25flWriteDataTypes[] =
{
	{.width = CY_SMIF_WIDTH_SINGLE, .dataRate = CY_SMIF_SDR}, // dataTypeNum = 0
	{.width = CY_SMIF_WIDTH_QUAD,   .dataRate = CY_SMIF_SDR}, // dataTypeNum = 1
};

/************************************************************/
/************* Write Command Table for S25FLxxxX ************/
/************************************************************/
static const  cy_stc_write_info_t g_s25flWriteCmdInfo[] =
{
	{ .cmd = CY_SMIF_S25FL_CMD_PP,   .cmdTypeNum   = 0u, .addrTypeNum  = 0u, .modeTypeNum  = 0u, .dataTypeNum  = 0u },
	{ .cmd = CY_SMIF_S25FL_CMD_4PP,  .cmdTypeNum   = 0u, .addrTypeNum  = 1u, .modeTypeNum  = 0u, .dataTypeNum  = 0u },
	{ .cmd = CY_SMIF_S25FL_CMD_QPP,  .cmdTypeNum   = 0u, .addrTypeNum  = 0u, .modeTypeNum  = 0u, .dataTypeNum  = 1u },
	{ .cmd = CY_SMIF_S25FL_CMD_4QPP, .cmdTypeNum   = 0u, .addrTypeNum  = 1u, .modeTypeNum  = 0u, .dataTypeNum  = 1u },
#if (CY_SMIF_QUAD_DEVICE_TYPE == CY_SMIF_S25FXXXS)
	{ .cmd = CY_SMIF_S25FL_CMD_QPPA, .cmdTypeNum   = 0u, .addrTypeNum  = 0u, .modeTypeNum  = 0u, .dataTypeNum  = 1u },
#endif
};


/***********************************************************************/
/******************* Functions Issuing Each Commands *******************/
/***********************************************************************/
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
									 CY_SMIF_S25FL_CMD_RDID   ,  /* command value */
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
									 CY_SMIF_S25FL_CMD_RDSR1,    /* command value */
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
									 CY_SMIF_S25FL_CMD_RDSR2,    /* command value */
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
									 CY_SMIF_S25FL_CMD_RDCR1,     /* command value */
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
cy_en_smif_status_t Cy_SMIF_S25FL_WriteStatusAndConfigRegister(volatile stc_SMIF_t *base,
										cy_en_smif_slave_select_t slave,
										stc_cy_smif_s25f_write_reg_t* writeRegs,
										uint8_t writeRegNum,
										cy_stc_smif_context_t const *context)
{
	cy_en_smif_status_t status;
	status = Cy_SMIF_TransmitCommand(base,
									 CY_SMIF_S25FL_CMD_WRR,      /* command value */
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
									 CY_SMIF_S25FL_CMD_WRDI,     /* command value */
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
									 CY_SMIF_S25FL_CMD_WREN,     /* command value */
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
									 CY_SMIF_S25FL_CMD_CLSR,     /* command value */
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
									 CY_SMIF_S25FL_CMD_DLPRD,     /* command value */
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
									 CY_SMIF_S25FL_CMD_PDLRNV,   /* command value */
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
									 CY_SMIF_S25FL_CMD_WDLRV,    /* command value */
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
	en_cy_smif_s25fl_cmd_t eraseCmd;
	uint8_t  addrSizeInByte;
	uint32_t addrInBigEndian;
	if(erasedAddress > 0x00FFFFFFul)
	{
		eraseCmd = CY_SMIF_S25FL_CMD_4SE;
		addrSizeInByte = 4ul;
		addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(erasedAddress);
	}
	else
	{
		// assuming that ExtAdd == 0;
		eraseCmd = CY_SMIF_S25FL_CMD_SE;
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
									 CY_SMIF_S25FL_CMD_CE,       /* command value */
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
									 CY_SMIF_S25FL_CMD_PASSRD,   /* command value */
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
									 CY_SMIF_S25FL_CMD_PASSP,    /* command value */
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
									 CY_SMIF_S25FL_CMD_PASSU,    /* command value */
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
									 CY_SMIF_S25FL_CMD_RST,    /* command value */
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
									 CY_SMIF_S25FL_CMD_MBR,      /* command value */
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
									 CY_SMIF_S25FL_CMD_READ_ID,  /* command value */
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
									 CY_SMIF_S25FL_CMD_RES,      /* command value */
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
									 CY_SMIF_S25FL_CMD_BRRD,     /* command value */
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
									 CY_SMIF_S25FL_CMD_BRWR,     /* command value */
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
	writeData[0] = CY_SMIF_S25FL_CMD_WRR; // When the BRAC command is sent, the FL-S
									// family device will then interpret an
									// immediately following Write Register (WRR)
									// command as a write to the lower address
									// bits of the BAR.
	writeData[1] = BarBit0;
	status = Cy_SMIF_TransmitCommand(base,
									 CY_SMIF_S25FL_CMD_BRAC,     /* command value */
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
									 CY_SMIF_S25FL_CMD_WRR,      /* command value */
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
									 CY_SMIF_S25FL_CMD_ABRD,     /* command value */
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
									 CY_SMIF_S25FL_CMD_ABWR,     /* command value */
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
									 CY_SMIF_S25FL_CMD_PGSP,     /* command value */
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
									 CY_SMIF_S25FL_CMD_PGRS,     /* command value */
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
	en_cy_smif_s25fl_cmd_t eraseCmd;
	uint8_t  addrSizeInByte;
	uint32_t addrInBigEndian;
	if(erasedAddress > 0x00FFFFFFul)
	{
		eraseCmd = CY_SMIF_S25FL_CMD_4P4E;
		addrSizeInByte = 4ul;
		addrInBigEndian = Cy_SMIF_Reverse4ByteEndian(erasedAddress);
	}
	else
	{
		// assuming that ExtAdd == 0;
		eraseCmd = CY_SMIF_S25FL_CMD_P4E;
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
									 CY_SMIF_S25FL_CMD_ERSP,     /* command value */
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
									 CY_SMIF_S25FL_CMD_ERRS,     /* command value */
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
									 CY_SMIF_S25FL_CMD_OTPP,     /* command value */
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
									 CY_SMIF_S25FL_CMD_OTPR,     /* command value */
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
									 CY_SMIF_S25FL_CMD_ASPRD,    /* command value */
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
									 CY_SMIF_S25FL_CMD_ASPP,     /* command value */
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
									 CY_SMIF_S25FL_CMD_DYBRD,    /* command value */
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
									 CY_SMIF_S25FL_CMD_DYBWR,    /* command value */
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
									 CY_SMIF_S25FL_CMD_PPBRD,    /* command value */
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
									 CY_SMIF_S25FL_CMD_PPBP,     /* command value */
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
									 CY_SMIF_S25FL_CMD_PPBE,     /* command value */
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
									 CY_SMIF_S25FL_CMD_PLBRD,    /* command value */
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
									 CY_SMIF_S25FL_CMD_PLBWR,    /* command value */
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
									 CY_SMIF_S25FL_CMD_RDCR2,     /* command value */
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
									 CY_SMIF_S25FL_CMD_RDCR3,     /* command value */
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
									 CY_SMIF_S25FL_CMD_EPS,     /* command value */
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
