/***************************************************************************//**
* \file cyt4bf_config.h
*
* \brief
* CYT4BF device configuration header
*
* \note
* Generator version: 1.4.0.1226
* Database revision: TVIIBH8M_CFR_METALTO
*
********************************************************************************
* \copyright
* Copyright 2016-2018, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef _CYT4BF_CONFIG_H_
#define _CYT4BF_CONFIG_H_

/* Clock Connections */
typedef enum
{
    PCLK_CPUSS_CLOCK_TRACE_IN       = 0x0000u,  /* cpuss.clock_trace_in */
    PCLK_SMARTIO12_CLOCK            = 0x0001u,  /* smartio[12].clock */
    PCLK_SMARTIO13_CLOCK            = 0x0002u,  /* smartio[13].clock */
    PCLK_SMARTIO14_CLOCK            = 0x0003u,  /* smartio[14].clock */
    PCLK_SMARTIO15_CLOCK            = 0x0004u,  /* smartio[15].clock */
    PCLK_SMARTIO17_CLOCK            = 0x0005u,  /* smartio[17].clock */
    PCLK_TCPWM0_CLOCKS0             = 0x0006u,  /* tcpwm[0].clocks[0] */
    PCLK_TCPWM0_CLOCKS1             = 0x0007u,  /* tcpwm[0].clocks[1] */
    PCLK_TCPWM0_CLOCKS2             = 0x0008u,  /* tcpwm[0].clocks[2] */
    PCLK_TCPWM0_CLOCKS256           = 0x0009u,  /* tcpwm[0].clocks[256] */
    PCLK_TCPWM0_CLOCKS257           = 0x000Au,  /* tcpwm[0].clocks[257] */
    PCLK_TCPWM0_CLOCKS258           = 0x000Bu,  /* tcpwm[0].clocks[258] */
    PCLK_TCPWM0_CLOCKS512           = 0x000Cu,  /* tcpwm[0].clocks[512] */
    PCLK_TCPWM0_CLOCKS513           = 0x000Du,  /* tcpwm[0].clocks[513] */
    PCLK_TCPWM0_CLOCKS514           = 0x000Eu,  /* tcpwm[0].clocks[514] */
    PCLK_CANFD0_CLOCK_CAN0          = 0x0100u,  /* canfd[0].clock_can[0] */
    PCLK_CANFD0_CLOCK_CAN1          = 0x0101u,  /* canfd[0].clock_can[1] */
    PCLK_CANFD0_CLOCK_CAN2          = 0x0102u,  /* canfd[0].clock_can[2] */
    PCLK_CANFD0_CLOCK_CAN3          = 0x0103u,  /* canfd[0].clock_can[3] */
    PCLK_CANFD0_CLOCK_CAN4          = 0x0104u,  /* canfd[0].clock_can[4] */
    PCLK_CANFD1_CLOCK_CAN0          = 0x0105u,  /* canfd[1].clock_can[0] */
    PCLK_CANFD1_CLOCK_CAN1          = 0x0106u,  /* canfd[1].clock_can[1] */
    PCLK_CANFD1_CLOCK_CAN2          = 0x0107u,  /* canfd[1].clock_can[2] */
    PCLK_CANFD1_CLOCK_CAN3          = 0x0108u,  /* canfd[1].clock_can[3] */
    PCLK_CANFD1_CLOCK_CAN4          = 0x0109u,  /* canfd[1].clock_can[4] */
    PCLK_LIN0_CLOCK_CH_EN0          = 0x010Au,  /* lin[0].clock_ch_en[0] */
    PCLK_LIN0_CLOCK_CH_EN1          = 0x010Bu,  /* lin[0].clock_ch_en[1] */
    PCLK_LIN0_CLOCK_CH_EN2          = 0x010Cu,  /* lin[0].clock_ch_en[2] */
    PCLK_LIN0_CLOCK_CH_EN3          = 0x010Du,  /* lin[0].clock_ch_en[3] */
    PCLK_LIN0_CLOCK_CH_EN4          = 0x010Eu,  /* lin[0].clock_ch_en[4] */
    PCLK_LIN0_CLOCK_CH_EN5          = 0x010Fu,  /* lin[0].clock_ch_en[5] */
    PCLK_LIN0_CLOCK_CH_EN6          = 0x0110u,  /* lin[0].clock_ch_en[6] */
    PCLK_LIN0_CLOCK_CH_EN7          = 0x0111u,  /* lin[0].clock_ch_en[7] */
    PCLK_LIN0_CLOCK_CH_EN8          = 0x0112u,  /* lin[0].clock_ch_en[8] */
    PCLK_LIN0_CLOCK_CH_EN9          = 0x0113u,  /* lin[0].clock_ch_en[9] */
    PCLK_LIN0_CLOCK_CH_EN10         = 0x0114u,  /* lin[0].clock_ch_en[10] */
    PCLK_LIN0_CLOCK_CH_EN11         = 0x0115u,  /* lin[0].clock_ch_en[11] */
    PCLK_LIN0_CLOCK_CH_EN12         = 0x0116u,  /* lin[0].clock_ch_en[12] */
    PCLK_LIN0_CLOCK_CH_EN13         = 0x0117u,  /* lin[0].clock_ch_en[13] */
    PCLK_LIN0_CLOCK_CH_EN14         = 0x0118u,  /* lin[0].clock_ch_en[14] */
    PCLK_LIN0_CLOCK_CH_EN15         = 0x0119u,  /* lin[0].clock_ch_en[15] */
    PCLK_LIN0_CLOCK_CH_EN16         = 0x011Au,  /* lin[0].clock_ch_en[16] */
    PCLK_LIN0_CLOCK_CH_EN17         = 0x011Bu,  /* lin[0].clock_ch_en[17] */
    PCLK_LIN0_CLOCK_CH_EN18         = 0x011Cu,  /* lin[0].clock_ch_en[18] */
    PCLK_LIN0_CLOCK_CH_EN19         = 0x011Du,  /* lin[0].clock_ch_en[19] */
    PCLK_SCB0_CLOCK                 = 0x011Eu,  /* scb[0].clock */
    PCLK_SCB1_CLOCK                 = 0x011Fu,  /* scb[1].clock */
    PCLK_SCB2_CLOCK                 = 0x0120u,  /* scb[2].clock */
    PCLK_SCB3_CLOCK                 = 0x0121u,  /* scb[3].clock */
    PCLK_SCB4_CLOCK                 = 0x0122u,  /* scb[4].clock */
    PCLK_SCB5_CLOCK                 = 0x0123u,  /* scb[5].clock */
    PCLK_SCB6_CLOCK                 = 0x0124u,  /* scb[6].clock */
    PCLK_SCB7_CLOCK                 = 0x0125u,  /* scb[7].clock */
    PCLK_SCB8_CLOCK                 = 0x0126u,  /* scb[8].clock */
    PCLK_SCB9_CLOCK                 = 0x0127u,  /* scb[9].clock */
    PCLK_SCB10_CLOCK                = 0x0128u,  /* scb[10].clock */
    PCLK_FLEXRAY0_CLK_FLEXRAY       = 0x0129u,  /* flexray[0].clk_flexray */
    PCLK_PASS0_CLOCK_SAR0           = 0x012Au,  /* pass[0].clock_sar[0] */
    PCLK_PASS0_CLOCK_SAR1           = 0x012Bu,  /* pass[0].clock_sar[1] */
    PCLK_PASS0_CLOCK_SAR2           = 0x012Cu,  /* pass[0].clock_sar[2] */
    PCLK_TCPWM1_CLOCKS0             = 0x012Du,  /* tcpwm[1].clocks[0] */
    PCLK_TCPWM1_CLOCKS1             = 0x012Eu,  /* tcpwm[1].clocks[1] */
    PCLK_TCPWM1_CLOCKS2             = 0x012Fu,  /* tcpwm[1].clocks[2] */
    PCLK_TCPWM1_CLOCKS3             = 0x0130u,  /* tcpwm[1].clocks[3] */
    PCLK_TCPWM1_CLOCKS4             = 0x0131u,  /* tcpwm[1].clocks[4] */
    PCLK_TCPWM1_CLOCKS5             = 0x0132u,  /* tcpwm[1].clocks[5] */
    PCLK_TCPWM1_CLOCKS6             = 0x0133u,  /* tcpwm[1].clocks[6] */
    PCLK_TCPWM1_CLOCKS7             = 0x0134u,  /* tcpwm[1].clocks[7] */
    PCLK_TCPWM1_CLOCKS8             = 0x0135u,  /* tcpwm[1].clocks[8] */
    PCLK_TCPWM1_CLOCKS9             = 0x0136u,  /* tcpwm[1].clocks[9] */
    PCLK_TCPWM1_CLOCKS10            = 0x0137u,  /* tcpwm[1].clocks[10] */
    PCLK_TCPWM1_CLOCKS11            = 0x0138u,  /* tcpwm[1].clocks[11] */
    PCLK_TCPWM1_CLOCKS12            = 0x0139u,  /* tcpwm[1].clocks[12] */
    PCLK_TCPWM1_CLOCKS13            = 0x013Au,  /* tcpwm[1].clocks[13] */
    PCLK_TCPWM1_CLOCKS14            = 0x013Bu,  /* tcpwm[1].clocks[14] */
    PCLK_TCPWM1_CLOCKS15            = 0x013Cu,  /* tcpwm[1].clocks[15] */
    PCLK_TCPWM1_CLOCKS16            = 0x013Du,  /* tcpwm[1].clocks[16] */
    PCLK_TCPWM1_CLOCKS17            = 0x013Eu,  /* tcpwm[1].clocks[17] */
    PCLK_TCPWM1_CLOCKS18            = 0x013Fu,  /* tcpwm[1].clocks[18] */
    PCLK_TCPWM1_CLOCKS19            = 0x0140u,  /* tcpwm[1].clocks[19] */
    PCLK_TCPWM1_CLOCKS20            = 0x0141u,  /* tcpwm[1].clocks[20] */
    PCLK_TCPWM1_CLOCKS21            = 0x0142u,  /* tcpwm[1].clocks[21] */
    PCLK_TCPWM1_CLOCKS22            = 0x0143u,  /* tcpwm[1].clocks[22] */
    PCLK_TCPWM1_CLOCKS23            = 0x0144u,  /* tcpwm[1].clocks[23] */
    PCLK_TCPWM1_CLOCKS24            = 0x0145u,  /* tcpwm[1].clocks[24] */
    PCLK_TCPWM1_CLOCKS25            = 0x0146u,  /* tcpwm[1].clocks[25] */
    PCLK_TCPWM1_CLOCKS26            = 0x0147u,  /* tcpwm[1].clocks[26] */
    PCLK_TCPWM1_CLOCKS27            = 0x0148u,  /* tcpwm[1].clocks[27] */
    PCLK_TCPWM1_CLOCKS28            = 0x0149u,  /* tcpwm[1].clocks[28] */
    PCLK_TCPWM1_CLOCKS29            = 0x014Au,  /* tcpwm[1].clocks[29] */
    PCLK_TCPWM1_CLOCKS30            = 0x014Bu,  /* tcpwm[1].clocks[30] */
    PCLK_TCPWM1_CLOCKS31            = 0x014Cu,  /* tcpwm[1].clocks[31] */
    PCLK_TCPWM1_CLOCKS32            = 0x014Du,  /* tcpwm[1].clocks[32] */
    PCLK_TCPWM1_CLOCKS33            = 0x014Eu,  /* tcpwm[1].clocks[33] */
    PCLK_TCPWM1_CLOCKS34            = 0x014Fu,  /* tcpwm[1].clocks[34] */
    PCLK_TCPWM1_CLOCKS35            = 0x0150u,  /* tcpwm[1].clocks[35] */
    PCLK_TCPWM1_CLOCKS36            = 0x0151u,  /* tcpwm[1].clocks[36] */
    PCLK_TCPWM1_CLOCKS37            = 0x0152u,  /* tcpwm[1].clocks[37] */
    PCLK_TCPWM1_CLOCKS38            = 0x0153u,  /* tcpwm[1].clocks[38] */
    PCLK_TCPWM1_CLOCKS39            = 0x0154u,  /* tcpwm[1].clocks[39] */
    PCLK_TCPWM1_CLOCKS40            = 0x0155u,  /* tcpwm[1].clocks[40] */
    PCLK_TCPWM1_CLOCKS41            = 0x0156u,  /* tcpwm[1].clocks[41] */
    PCLK_TCPWM1_CLOCKS42            = 0x0157u,  /* tcpwm[1].clocks[42] */
    PCLK_TCPWM1_CLOCKS43            = 0x0158u,  /* tcpwm[1].clocks[43] */
    PCLK_TCPWM1_CLOCKS44            = 0x0159u,  /* tcpwm[1].clocks[44] */
    PCLK_TCPWM1_CLOCKS45            = 0x015Au,  /* tcpwm[1].clocks[45] */
    PCLK_TCPWM1_CLOCKS46            = 0x015Bu,  /* tcpwm[1].clocks[46] */
    PCLK_TCPWM1_CLOCKS47            = 0x015Cu,  /* tcpwm[1].clocks[47] */
    PCLK_TCPWM1_CLOCKS48            = 0x015Du,  /* tcpwm[1].clocks[48] */
    PCLK_TCPWM1_CLOCKS49            = 0x015Eu,  /* tcpwm[1].clocks[49] */
    PCLK_TCPWM1_CLOCKS50            = 0x015Fu,  /* tcpwm[1].clocks[50] */
    PCLK_TCPWM1_CLOCKS51            = 0x0160u,  /* tcpwm[1].clocks[51] */
    PCLK_TCPWM1_CLOCKS52            = 0x0161u,  /* tcpwm[1].clocks[52] */
    PCLK_TCPWM1_CLOCKS53            = 0x0162u,  /* tcpwm[1].clocks[53] */
    PCLK_TCPWM1_CLOCKS54            = 0x0163u,  /* tcpwm[1].clocks[54] */
    PCLK_TCPWM1_CLOCKS55            = 0x0164u,  /* tcpwm[1].clocks[55] */
    PCLK_TCPWM1_CLOCKS56            = 0x0165u,  /* tcpwm[1].clocks[56] */
    PCLK_TCPWM1_CLOCKS57            = 0x0166u,  /* tcpwm[1].clocks[57] */
    PCLK_TCPWM1_CLOCKS58            = 0x0167u,  /* tcpwm[1].clocks[58] */
    PCLK_TCPWM1_CLOCKS59            = 0x0168u,  /* tcpwm[1].clocks[59] */
    PCLK_TCPWM1_CLOCKS60            = 0x0169u,  /* tcpwm[1].clocks[60] */
    PCLK_TCPWM1_CLOCKS61            = 0x016Au,  /* tcpwm[1].clocks[61] */
    PCLK_TCPWM1_CLOCKS62            = 0x016Bu,  /* tcpwm[1].clocks[62] */
    PCLK_TCPWM1_CLOCKS63            = 0x016Cu,  /* tcpwm[1].clocks[63] */
    PCLK_TCPWM1_CLOCKS64            = 0x016Du,  /* tcpwm[1].clocks[64] */
    PCLK_TCPWM1_CLOCKS65            = 0x016Eu,  /* tcpwm[1].clocks[65] */
    PCLK_TCPWM1_CLOCKS66            = 0x016Fu,  /* tcpwm[1].clocks[66] */
    PCLK_TCPWM1_CLOCKS67            = 0x0170u,  /* tcpwm[1].clocks[67] */
    PCLK_TCPWM1_CLOCKS68            = 0x0171u,  /* tcpwm[1].clocks[68] */
    PCLK_TCPWM1_CLOCKS69            = 0x0172u,  /* tcpwm[1].clocks[69] */
    PCLK_TCPWM1_CLOCKS70            = 0x0173u,  /* tcpwm[1].clocks[70] */
    PCLK_TCPWM1_CLOCKS71            = 0x0174u,  /* tcpwm[1].clocks[71] */
    PCLK_TCPWM1_CLOCKS72            = 0x0175u,  /* tcpwm[1].clocks[72] */
    PCLK_TCPWM1_CLOCKS73            = 0x0176u,  /* tcpwm[1].clocks[73] */
    PCLK_TCPWM1_CLOCKS74            = 0x0177u,  /* tcpwm[1].clocks[74] */
    PCLK_TCPWM1_CLOCKS75            = 0x0178u,  /* tcpwm[1].clocks[75] */
    PCLK_TCPWM1_CLOCKS76            = 0x0179u,  /* tcpwm[1].clocks[76] */
    PCLK_TCPWM1_CLOCKS77            = 0x017Au,  /* tcpwm[1].clocks[77] */
    PCLK_TCPWM1_CLOCKS78            = 0x017Bu,  /* tcpwm[1].clocks[78] */
    PCLK_TCPWM1_CLOCKS79            = 0x017Cu,  /* tcpwm[1].clocks[79] */
    PCLK_TCPWM1_CLOCKS80            = 0x017Du,  /* tcpwm[1].clocks[80] */
    PCLK_TCPWM1_CLOCKS81            = 0x017Eu,  /* tcpwm[1].clocks[81] */
    PCLK_TCPWM1_CLOCKS82            = 0x017Fu,  /* tcpwm[1].clocks[82] */
    PCLK_TCPWM1_CLOCKS83            = 0x0180u,  /* tcpwm[1].clocks[83] */
    PCLK_TCPWM1_CLOCKS256           = 0x0181u,  /* tcpwm[1].clocks[256] */
    PCLK_TCPWM1_CLOCKS257           = 0x0182u,  /* tcpwm[1].clocks[257] */
    PCLK_TCPWM1_CLOCKS258           = 0x0183u,  /* tcpwm[1].clocks[258] */
    PCLK_TCPWM1_CLOCKS259           = 0x0184u,  /* tcpwm[1].clocks[259] */
    PCLK_TCPWM1_CLOCKS260           = 0x0185u,  /* tcpwm[1].clocks[260] */
    PCLK_TCPWM1_CLOCKS261           = 0x0186u,  /* tcpwm[1].clocks[261] */
    PCLK_TCPWM1_CLOCKS262           = 0x0187u,  /* tcpwm[1].clocks[262] */
    PCLK_TCPWM1_CLOCKS263           = 0x0188u,  /* tcpwm[1].clocks[263] */
    PCLK_TCPWM1_CLOCKS264           = 0x0189u,  /* tcpwm[1].clocks[264] */
    PCLK_TCPWM1_CLOCKS265           = 0x018Au,  /* tcpwm[1].clocks[265] */
    PCLK_TCPWM1_CLOCKS266           = 0x018Bu,  /* tcpwm[1].clocks[266] */
    PCLK_TCPWM1_CLOCKS267           = 0x018Cu,  /* tcpwm[1].clocks[267] */
    PCLK_TCPWM1_CLOCKS512           = 0x018Du,  /* tcpwm[1].clocks[512] */
    PCLK_TCPWM1_CLOCKS513           = 0x018Eu,  /* tcpwm[1].clocks[513] */
    PCLK_TCPWM1_CLOCKS514           = 0x018Fu,  /* tcpwm[1].clocks[514] */
    PCLK_TCPWM1_CLOCKS515           = 0x0190u,  /* tcpwm[1].clocks[515] */
    PCLK_TCPWM1_CLOCKS516           = 0x0191u,  /* tcpwm[1].clocks[516] */
    PCLK_TCPWM1_CLOCKS517           = 0x0192u,  /* tcpwm[1].clocks[517] */
    PCLK_TCPWM1_CLOCKS518           = 0x0193u,  /* tcpwm[1].clocks[518] */
    PCLK_TCPWM1_CLOCKS519           = 0x0194u,  /* tcpwm[1].clocks[519] */
    PCLK_TCPWM1_CLOCKS520           = 0x0195u,  /* tcpwm[1].clocks[520] */
    PCLK_TCPWM1_CLOCKS521           = 0x0196u,  /* tcpwm[1].clocks[521] */
    PCLK_TCPWM1_CLOCKS522           = 0x0197u,  /* tcpwm[1].clocks[522] */
    PCLK_TCPWM1_CLOCKS523           = 0x0198u,  /* tcpwm[1].clocks[523] */
    PCLK_TCPWM1_CLOCKS524           = 0x0199u   /* tcpwm[1].clocks[524] */
} en_clk_dst_t;

/* Trigger Group */
/* This section contains the enums related to the Trigger multiplexer (TrigMux) driver. 
* The constants are divided into four types because each signal of the TrigMux driver has a path
* through two multiplexers: the reduction multiplexer and the distribution multiplexer. This 
* requires two calls for Cy_TrigMux_Connect() function. The first call - for the reduction 
* multiplexer, the second call - for the distribution multiplexer.
*
* The four types of inputs/output parameters:
* 1) Parameters for reduction multiplexer's inputs (input signals of TrigMux)
* 2) Parameters for reduction multiplexer's outputs (intermediate signals);
* 3) Parameters for distribution multiplexer's inputs (intermediate signals);
* 4) Parameters for distribution multiplexer's outputs (output signals of TrigMux).
*
* The Cy_TrigMux_Connect() inTrig parameter can have 1) and 3) types parameters. The outTrig 
* parameter can have 2) and 4) types parameters.
* The names of the constants for these parameters have the following format:
*
* 1) For reduction multiplexer's inputs:
* TRIG<REDMULT>_IN_<IPSOURCE><IPNUM>
* <REDMULT> the reduction multiplexer number;
* <IPSOURCE> - the name of the IP block which is the source of the signal;
* <IPNUM> - the source signal number in the IP block.
*
* Example:
* TRIG11_IN_TCPWM0_TR_OVERFLOW3 - the TCPWM0 tr_overflow[3] input of reduction multiplexer#11.
* 
* 2) For reduction multiplexer's outputs:
* TRIG<REDMULT>_OUT_TR_GROUP<DISTMULT >_INPUT<DISTMULTINPUT>
* <REDMULT> - the reduction multiplexer number;
* <DISTMULT> - the distribution multiplexer number;
* <DISTMULTINPUT> - the input number of the distribution multiplexer.
*
* Example:
* TRIG11_OUT_TR_GROUP0_INPUT23 - Input#23 of the distribution multiplexer#0 is the destination 
* of the reduction multiplexer#11.
*
* 3) For distribution multiplexer's inputs:
* TRIG<DISTMULT>_IN_TR_GROUP<REDMULT >_OUTPUT<REDMULTOUTPUT>
* <REDMULT> - the reduction multiplexer number;
* <DISTMULT> - the distribution multiplexer number;
* <REDMULTOUTPUT> - the output number of the reduction multiplexer;
*
* Example:
* TRIG0_IN_TR_GROUP11_OUTPUT15 - Output#15 of the reduction multiplexer#11 is the source of the 
* distribution multiplexer#0.
* 
* 4) For distribution multiplexer's outputs:
* TRIG<DISTMULT>_OUT_<IPDEST><IPNUM>
* <REDMULT> - the distribution multiplexer number;
* <IPDEST> - the name of the IP block which is the destination of the signal;
* <IPNUM> - the input signal number in the IP block.
*
* Example:
* TRIG0_OUT_CPUSS_DW0_TR_IN3 - the DW0 tr_out[3] ouput of the distribution multiplexer 0.*/
/* Trigger Group Inputs */
/* Trigger Input Group 0 - P-DMA0[0:15] Request Assignments */
typedef enum
{
    TRIG_IN_MUX_0_PDMA0_TR_OUT0     = 0x00000001u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT1     = 0x00000002u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT2     = 0x00000003u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT3     = 0x00000004u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT4     = 0x00000005u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT5     = 0x00000006u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT6     = 0x00000007u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT7     = 0x00000008u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT8     = 0x00000009u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT9     = 0x0000000Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT10    = 0x0000000Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT11    = 0x0000000Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT12    = 0x0000000Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT13    = 0x0000000Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT14    = 0x0000000Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_0_PDMA0_TR_OUT15    = 0x00000010u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT0     = 0x00000011u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT1     = 0x00000012u, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT2     = 0x00000013u, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT3     = 0x00000014u, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT4     = 0x00000015u, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT5     = 0x00000016u, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT6     = 0x00000017u, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT7     = 0x00000018u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT8     = 0x00000019u, /* cpuss.dw1_tr_out[8] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT9     = 0x0000001Au, /* cpuss.dw1_tr_out[9] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT10    = 0x0000001Bu, /* cpuss.dw1_tr_out[10] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT11    = 0x0000001Cu, /* cpuss.dw1_tr_out[11] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT12    = 0x0000001Du, /* cpuss.dw1_tr_out[12] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT13    = 0x0000001Eu, /* cpuss.dw1_tr_out[13] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT14    = 0x0000001Fu, /* cpuss.dw1_tr_out[14] */
    TRIG_IN_MUX_0_PDMA1_TR_OUT15    = 0x00000020u, /* cpuss.dw1_tr_out[15] */
    TRIG_IN_MUX_0_MDMA_TR_OUT0      = 0x00000021u, /* cpuss.dmac_tr_out[0] */
    TRIG_IN_MUX_0_MDMA_TR_OUT1      = 0x00000022u, /* cpuss.dmac_tr_out[1] */
    TRIG_IN_MUX_0_MDMA_TR_OUT2      = 0x00000023u, /* cpuss.dmac_tr_out[2] */
    TRIG_IN_MUX_0_MDMA_TR_OUT3      = 0x00000024u, /* cpuss.dmac_tr_out[3] */
    TRIG_IN_MUX_0_MDMA_TR_OUT4      = 0x00000025u, /* cpuss.dmac_tr_out[4] */
    TRIG_IN_MUX_0_MDMA_TR_OUT5      = 0x00000026u, /* cpuss.dmac_tr_out[5] */
    TRIG_IN_MUX_0_MDMA_TR_OUT6      = 0x00000027u, /* cpuss.dmac_tr_out[6] */
    TRIG_IN_MUX_0_MDMA_TR_OUT7      = 0x00000028u, /* cpuss.dmac_tr_out[7] */
    TRIG_IN_MUX_0_CAN0_TT_TR_OUT0   = 0x00000029u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_0_CAN0_TT_TR_OUT1   = 0x0000002Au, /* canfd[0].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_0_CAN0_TT_TR_OUT2   = 0x0000002Bu, /* canfd[0].tr_tmp_rtp_out[2] */
    TRIG_IN_MUX_0_CAN0_TT_TR_OUT3   = 0x0000002Cu, /* canfd[0].tr_tmp_rtp_out[3] */
    TRIG_IN_MUX_0_CAN0_TT_TR_OUT4   = 0x0000002Du, /* canfd[0].tr_tmp_rtp_out[4] */
    TRIG_IN_MUX_0_CAN1_TT_TR_OUT0   = 0x0000002Eu, /* canfd[1].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_0_CAN1_TT_TR_OUT1   = 0x0000002Fu, /* canfd[1].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_0_CAN1_TT_TR_OUT2   = 0x00000030u, /* canfd[1].tr_tmp_rtp_out[2] */
    TRIG_IN_MUX_0_CAN1_TT_TR_OUT3   = 0x00000031u, /* canfd[1].tr_tmp_rtp_out[3] */
    TRIG_IN_MUX_0_CAN1_TT_TR_OUT4   = 0x00000032u, /* canfd[1].tr_tmp_rtp_out[4] */
    TRIG_IN_MUX_0_FLEXRAY_TT_TR_OUT = 0x00000033u, /* flexray[0].tr_tint0_out */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT0   = 0x00000034u, /* peri.tr_io_input[0] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT1   = 0x00000035u, /* peri.tr_io_input[1] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT2   = 0x00000036u, /* peri.tr_io_input[2] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT3   = 0x00000037u, /* peri.tr_io_input[3] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT4   = 0x00000038u, /* peri.tr_io_input[4] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT5   = 0x00000039u, /* peri.tr_io_input[5] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT6   = 0x0000003Au, /* peri.tr_io_input[6] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT7   = 0x0000003Bu, /* peri.tr_io_input[7] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT8   = 0x0000003Cu, /* peri.tr_io_input[8] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT9   = 0x0000003Du, /* peri.tr_io_input[9] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT10  = 0x0000003Eu, /* peri.tr_io_input[10] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT11  = 0x0000003Fu, /* peri.tr_io_input[11] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT12  = 0x00000040u, /* peri.tr_io_input[12] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT13  = 0x00000041u, /* peri.tr_io_input[13] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT14  = 0x00000042u, /* peri.tr_io_input[14] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT15  = 0x00000043u, /* peri.tr_io_input[15] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT16  = 0x00000044u, /* peri.tr_io_input[16] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT17  = 0x00000045u, /* peri.tr_io_input[17] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT18  = 0x00000046u, /* peri.tr_io_input[18] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT19  = 0x00000047u, /* peri.tr_io_input[19] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT20  = 0x00000048u, /* peri.tr_io_input[20] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT21  = 0x00000049u, /* peri.tr_io_input[21] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT22  = 0x0000004Au, /* peri.tr_io_input[22] */
    TRIG_IN_MUX_0_HSIOM_IO_INPUT23  = 0x0000004Bu, /* peri.tr_io_input[23] */
    TRIG_IN_MUX_0_FAULT_TR_OUT0     = 0x0000004Cu, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_0_FAULT_TR_OUT1     = 0x0000004Du, /* cpuss.tr_fault[1] */
    TRIG_IN_MUX_0_FAULT_TR_OUT2     = 0x0000004Eu, /* cpuss.tr_fault[2] */
    TRIG_IN_MUX_0_FAULT_TR_OUT3     = 0x0000004Fu /* cpuss.tr_fault[3] */
} en_trig_input_pdma0_0_15_tr_t;

/* Trigger Input Group 1 - P-DMA0[16:31] Request Assignments */
typedef enum
{
    TRIG_IN_MUX_1_TCPWM0_16_TR_OUT00 = 0x00000101u, /* tcpwm[0].tr_out0[0] */
    TRIG_IN_MUX_1_TCPWM0_16_TR_OUT01 = 0x00000102u, /* tcpwm[0].tr_out0[1] */
    TRIG_IN_MUX_1_TCPWM0_16_TR_OUT02 = 0x00000103u, /* tcpwm[0].tr_out0[2] */
    TRIG_IN_MUX_1_TCPWM0_16M_TR_OUT00 = 0x00000104u, /* tcpwm[0].tr_out0[256] */
    TRIG_IN_MUX_1_TCPWM0_16M_TR_OUT01 = 0x00000105u, /* tcpwm[0].tr_out0[257] */
    TRIG_IN_MUX_1_TCPWM0_16M_TR_OUT02 = 0x00000106u, /* tcpwm[0].tr_out0[258] */
    TRIG_IN_MUX_1_TCPWM0_32_TR_OUT00 = 0x00000107u, /* tcpwm[0].tr_out0[512] */
    TRIG_IN_MUX_1_TCPWM0_32_TR_OUT01 = 0x00000108u, /* tcpwm[0].tr_out0[513] */
    TRIG_IN_MUX_1_TCPWM0_32_TR_OUT02 = 0x00000109u, /* tcpwm[0].tr_out0[514] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT00 = 0x0000010Au, /* tcpwm[1].tr_out0[0] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT01 = 0x0000010Bu, /* tcpwm[1].tr_out0[1] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT02 = 0x0000010Cu, /* tcpwm[1].tr_out0[2] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT03 = 0x0000010Du, /* tcpwm[1].tr_out0[3] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT04 = 0x0000010Eu, /* tcpwm[1].tr_out0[4] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT05 = 0x0000010Fu, /* tcpwm[1].tr_out0[5] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT06 = 0x00000110u, /* tcpwm[1].tr_out0[6] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT07 = 0x00000111u, /* tcpwm[1].tr_out0[7] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT08 = 0x00000112u, /* tcpwm[1].tr_out0[8] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT09 = 0x00000113u, /* tcpwm[1].tr_out0[9] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT010 = 0x00000114u, /* tcpwm[1].tr_out0[10] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT011 = 0x00000115u, /* tcpwm[1].tr_out0[11] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT012 = 0x00000116u, /* tcpwm[1].tr_out0[12] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT013 = 0x00000117u, /* tcpwm[1].tr_out0[13] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT014 = 0x00000118u, /* tcpwm[1].tr_out0[14] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT015 = 0x00000119u, /* tcpwm[1].tr_out0[15] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT016 = 0x0000011Au, /* tcpwm[1].tr_out0[16] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT017 = 0x0000011Bu, /* tcpwm[1].tr_out0[17] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT018 = 0x0000011Cu, /* tcpwm[1].tr_out0[18] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT019 = 0x0000011Du, /* tcpwm[1].tr_out0[19] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT020 = 0x0000011Eu, /* tcpwm[1].tr_out0[20] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT021 = 0x0000011Fu, /* tcpwm[1].tr_out0[21] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT022 = 0x00000120u, /* tcpwm[1].tr_out0[22] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT023 = 0x00000121u, /* tcpwm[1].tr_out0[23] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT024 = 0x00000122u, /* tcpwm[1].tr_out0[24] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT025 = 0x00000123u, /* tcpwm[1].tr_out0[25] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT026 = 0x00000124u, /* tcpwm[1].tr_out0[26] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT027 = 0x00000125u, /* tcpwm[1].tr_out0[27] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT028 = 0x00000126u, /* tcpwm[1].tr_out0[28] */
    TRIG_IN_MUX_1_TCPWM1_16_TR_OUT029 = 0x00000127u, /* tcpwm[1].tr_out0[29] */
    TRIG_IN_MUX_1_TCPWM1_16M_TR_OUT00 = 0x00000128u, /* tcpwm[1].tr_out0[256] */
    TRIG_IN_MUX_1_TCPWM1_16M_TR_OUT01 = 0x00000129u, /* tcpwm[1].tr_out0[257] */
    TRIG_IN_MUX_1_TCPWM1_16M_TR_OUT02 = 0x0000012Au, /* tcpwm[1].tr_out0[258] */
    TRIG_IN_MUX_1_TCPWM1_16M_TR_OUT03 = 0x0000012Bu, /* tcpwm[1].tr_out0[259] */
    TRIG_IN_MUX_1_TCPWM1_16M_TR_OUT04 = 0x0000012Cu, /* tcpwm[1].tr_out0[260] */
    TRIG_IN_MUX_1_TCPWM1_16M_TR_OUT05 = 0x0000012Du, /* tcpwm[1].tr_out0[261] */
    TRIG_IN_MUX_1_TCPWM1_16M_TR_OUT06 = 0x0000012Eu, /* tcpwm[1].tr_out0[262] */
    TRIG_IN_MUX_1_TCPWM1_16M_TR_OUT07 = 0x0000012Fu, /* tcpwm[1].tr_out0[263] */
    TRIG_IN_MUX_1_TCPWM1_16M_TR_OUT08 = 0x00000130u, /* tcpwm[1].tr_out0[264] */
    TRIG_IN_MUX_1_TCPWM1_16M_TR_OUT09 = 0x00000131u, /* tcpwm[1].tr_out0[265] */
    TRIG_IN_MUX_1_TCPWM1_16M_TR_OUT010 = 0x00000132u, /* tcpwm[1].tr_out0[266] */
    TRIG_IN_MUX_1_TCPWM1_16M_TR_OUT011 = 0x00000133u, /* tcpwm[1].tr_out0[267] */
    TRIG_IN_MUX_1_TCPWM1_32_TR_OUT00 = 0x00000134u, /* tcpwm[1].tr_out0[512] */
    TRIG_IN_MUX_1_TCPWM1_32_TR_OUT01 = 0x00000135u, /* tcpwm[1].tr_out0[513] */
    TRIG_IN_MUX_1_TCPWM1_32_TR_OUT02 = 0x00000136u, /* tcpwm[1].tr_out0[514] */
    TRIG_IN_MUX_1_TCPWM1_32_TR_OUT03 = 0x00000137u, /* tcpwm[1].tr_out0[515] */
    TRIG_IN_MUX_1_TCPWM1_32_TR_OUT04 = 0x00000138u, /* tcpwm[1].tr_out0[516] */
    TRIG_IN_MUX_1_TCPWM1_32_TR_OUT05 = 0x00000139u, /* tcpwm[1].tr_out0[517] */
    TRIG_IN_MUX_1_TCPWM1_32_TR_OUT06 = 0x0000013Au, /* tcpwm[1].tr_out0[518] */
    TRIG_IN_MUX_1_TCPWM1_32_TR_OUT07 = 0x0000013Bu, /* tcpwm[1].tr_out0[519] */
    TRIG_IN_MUX_1_TCPWM1_32_TR_OUT08 = 0x0000013Cu, /* tcpwm[1].tr_out0[520] */
    TRIG_IN_MUX_1_TCPWM1_32_TR_OUT09 = 0x0000013Du, /* tcpwm[1].tr_out0[521] */
    TRIG_IN_MUX_1_TCPWM1_32_TR_OUT010 = 0x0000013Eu, /* tcpwm[1].tr_out0[522] */
    TRIG_IN_MUX_1_TCPWM1_32_TR_OUT011 = 0x0000013Fu, /* tcpwm[1].tr_out0[523] */
    TRIG_IN_MUX_1_TCPWM1_32_TR_OUT012 = 0x00000140u, /* tcpwm[1].tr_out0[524] */
    TRIG_IN_MUX_1_PASS_GEN_TR_OUT0  = 0x00000141u, /* pass[0].tr_sar_gen_out[0] */
    TRIG_IN_MUX_1_PASS_GEN_TR_OUT1  = 0x00000142u, /* pass[0].tr_sar_gen_out[1] */
    TRIG_IN_MUX_1_PASS_GEN_TR_OUT2  = 0x00000143u, /* pass[0].tr_sar_gen_out[2] */
    TRIG_IN_MUX_1_PASS_GEN_TR_OUT3  = 0x00000144u, /* pass[0].tr_sar_gen_out[3] */
    TRIG_IN_MUX_1_PASS_GEN_TR_OUT4  = 0x00000145u, /* pass[0].tr_sar_gen_out[4] */
    TRIG_IN_MUX_1_PASS_GEN_TR_OUT5  = 0x00000146u, /* pass[0].tr_sar_gen_out[5] */
    TRIG_IN_MUX_1_CTI_TR_OUT0       = 0x00000147u, /* cpuss.cti_tr_out[0] */
    TRIG_IN_MUX_1_CTI_TR_OUT1       = 0x00000148u, /* cpuss.cti_tr_out[1] */
    TRIG_IN_MUX_1_EVTGEN_TR_OUT0    = 0x00000149u, /* evtgen[0].tr_out[0] */
    TRIG_IN_MUX_1_EVTGEN_TR_OUT1    = 0x0000014Au, /* evtgen[0].tr_out[1] */
    TRIG_IN_MUX_1_EVTGEN_TR_OUT2    = 0x0000014Bu, /* evtgen[0].tr_out[2] */
    TRIG_IN_MUX_1_EVTGEN_TR_OUT3    = 0x0000014Cu /* evtgen[0].tr_out[3] */
} en_trig_input_pdma0_16_31_tr_t;

/* Trigger Input Group 2 - P-DMA1[0:15] Request Assignments */
typedef enum
{
    TRIG_IN_MUX_2_PDMA1_TR_OUT0     = 0x00000201u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT1     = 0x00000202u, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT2     = 0x00000203u, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT3     = 0x00000204u, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT4     = 0x00000205u, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT5     = 0x00000206u, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT6     = 0x00000207u, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT7     = 0x00000208u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT8     = 0x00000209u, /* cpuss.dw1_tr_out[8] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT9     = 0x0000020Au, /* cpuss.dw1_tr_out[9] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT10    = 0x0000020Bu, /* cpuss.dw1_tr_out[10] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT11    = 0x0000020Cu, /* cpuss.dw1_tr_out[11] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT12    = 0x0000020Du, /* cpuss.dw1_tr_out[12] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT13    = 0x0000020Eu, /* cpuss.dw1_tr_out[13] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT14    = 0x0000020Fu, /* cpuss.dw1_tr_out[14] */
    TRIG_IN_MUX_2_PDMA1_TR_OUT15    = 0x00000210u, /* cpuss.dw1_tr_out[15] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT0     = 0x00000211u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT1     = 0x00000212u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT2     = 0x00000213u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT3     = 0x00000214u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT4     = 0x00000215u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT5     = 0x00000216u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT6     = 0x00000217u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT7     = 0x00000218u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT8     = 0x00000219u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT9     = 0x0000021Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT10    = 0x0000021Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT11    = 0x0000021Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT12    = 0x0000021Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT13    = 0x0000021Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT14    = 0x0000021Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_2_PDMA0_TR_OUT15    = 0x00000220u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT030 = 0x00000221u, /* tcpwm[1].tr_out0[30] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT031 = 0x00000222u, /* tcpwm[1].tr_out0[31] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT032 = 0x00000223u, /* tcpwm[1].tr_out0[32] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT033 = 0x00000224u, /* tcpwm[1].tr_out0[33] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT034 = 0x00000225u, /* tcpwm[1].tr_out0[34] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT035 = 0x00000226u, /* tcpwm[1].tr_out0[35] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT036 = 0x00000227u, /* tcpwm[1].tr_out0[36] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT037 = 0x00000228u, /* tcpwm[1].tr_out0[37] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT038 = 0x00000229u, /* tcpwm[1].tr_out0[38] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT039 = 0x0000022Au, /* tcpwm[1].tr_out0[39] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT040 = 0x0000022Bu, /* tcpwm[1].tr_out0[40] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT041 = 0x0000022Cu, /* tcpwm[1].tr_out0[41] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT042 = 0x0000022Du, /* tcpwm[1].tr_out0[42] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT043 = 0x0000022Eu, /* tcpwm[1].tr_out0[43] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT044 = 0x0000022Fu, /* tcpwm[1].tr_out0[44] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT045 = 0x00000230u, /* tcpwm[1].tr_out0[45] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT046 = 0x00000231u, /* tcpwm[1].tr_out0[46] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT047 = 0x00000232u, /* tcpwm[1].tr_out0[47] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT048 = 0x00000233u, /* tcpwm[1].tr_out0[48] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT049 = 0x00000234u, /* tcpwm[1].tr_out0[49] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT050 = 0x00000235u, /* tcpwm[1].tr_out0[50] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT051 = 0x00000236u, /* tcpwm[1].tr_out0[51] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT052 = 0x00000237u, /* tcpwm[1].tr_out0[52] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT053 = 0x00000238u, /* tcpwm[1].tr_out0[53] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT054 = 0x00000239u, /* tcpwm[1].tr_out0[54] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT055 = 0x0000023Au, /* tcpwm[1].tr_out0[55] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT056 = 0x0000023Bu, /* tcpwm[1].tr_out0[56] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT057 = 0x0000023Cu, /* tcpwm[1].tr_out0[57] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT058 = 0x0000023Du, /* tcpwm[1].tr_out0[58] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT059 = 0x0000023Eu, /* tcpwm[1].tr_out0[59] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT060 = 0x0000023Fu, /* tcpwm[1].tr_out0[60] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT061 = 0x00000240u, /* tcpwm[1].tr_out0[61] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT062 = 0x00000241u, /* tcpwm[1].tr_out0[62] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT063 = 0x00000242u, /* tcpwm[1].tr_out0[63] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT064 = 0x00000243u, /* tcpwm[1].tr_out0[64] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT065 = 0x00000244u, /* tcpwm[1].tr_out0[65] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT066 = 0x00000245u, /* tcpwm[1].tr_out0[66] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT067 = 0x00000246u, /* tcpwm[1].tr_out0[67] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT068 = 0x00000247u, /* tcpwm[1].tr_out0[68] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT069 = 0x00000248u, /* tcpwm[1].tr_out0[69] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT070 = 0x00000249u, /* tcpwm[1].tr_out0[70] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT071 = 0x0000024Au, /* tcpwm[1].tr_out0[71] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT072 = 0x0000024Bu, /* tcpwm[1].tr_out0[72] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT073 = 0x0000024Cu, /* tcpwm[1].tr_out0[73] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT074 = 0x0000024Du, /* tcpwm[1].tr_out0[74] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT075 = 0x0000024Eu, /* tcpwm[1].tr_out0[75] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT076 = 0x0000024Fu, /* tcpwm[1].tr_out0[76] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT077 = 0x00000250u, /* tcpwm[1].tr_out0[77] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT078 = 0x00000251u, /* tcpwm[1].tr_out0[78] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT079 = 0x00000252u, /* tcpwm[1].tr_out0[79] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT080 = 0x00000253u, /* tcpwm[1].tr_out0[80] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT081 = 0x00000254u, /* tcpwm[1].tr_out0[81] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT082 = 0x00000255u, /* tcpwm[1].tr_out0[82] */
    TRIG_IN_MUX_2_TCPWM1_16_TR_OUT083 = 0x00000256u, /* tcpwm[1].tr_out0[83] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT0   = 0x00000257u, /* peri.tr_io_input[0] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT1   = 0x00000258u, /* peri.tr_io_input[1] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT2   = 0x00000259u, /* peri.tr_io_input[2] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT3   = 0x0000025Au, /* peri.tr_io_input[3] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT4   = 0x0000025Bu, /* peri.tr_io_input[4] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT5   = 0x0000025Cu, /* peri.tr_io_input[5] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT6   = 0x0000025Du, /* peri.tr_io_input[6] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT7   = 0x0000025Eu, /* peri.tr_io_input[7] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT8   = 0x0000025Fu, /* peri.tr_io_input[8] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT9   = 0x00000260u, /* peri.tr_io_input[9] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT10  = 0x00000261u, /* peri.tr_io_input[10] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT11  = 0x00000262u, /* peri.tr_io_input[11] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT12  = 0x00000263u, /* peri.tr_io_input[12] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT13  = 0x00000264u, /* peri.tr_io_input[13] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT14  = 0x00000265u, /* peri.tr_io_input[14] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT15  = 0x00000266u, /* peri.tr_io_input[15] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT16  = 0x00000267u, /* peri.tr_io_input[16] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT17  = 0x00000268u, /* peri.tr_io_input[17] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT18  = 0x00000269u, /* peri.tr_io_input[18] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT19  = 0x0000026Au, /* peri.tr_io_input[19] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT20  = 0x0000026Bu, /* peri.tr_io_input[20] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT21  = 0x0000026Cu, /* peri.tr_io_input[21] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT22  = 0x0000026Du, /* peri.tr_io_input[22] */
    TRIG_IN_MUX_2_HSIOM_IO_INPUT23  = 0x0000026Eu /* peri.tr_io_input[23] */
} en_trig_input_pdma1_0_15_tr_t;

/* Trigger Input Group 3 - M-DMA Request Assignments */
typedef enum
{
    TRIG_IN_MUX_3_TCPWM0_16_TR_OUT00 = 0x00000301u, /* tcpwm[0].tr_out0[0] */
    TRIG_IN_MUX_3_TCPWM0_16_TR_OUT01 = 0x00000302u, /* tcpwm[0].tr_out0[1] */
    TRIG_IN_MUX_3_TCPWM0_16_TR_OUT02 = 0x00000303u, /* tcpwm[0].tr_out0[2] */
    TRIG_IN_MUX_3_TCPWM0_16M_TR_OUT00 = 0x00000304u, /* tcpwm[0].tr_out0[256] */
    TRIG_IN_MUX_3_TCPWM0_16M_TR_OUT01 = 0x00000305u, /* tcpwm[0].tr_out0[257] */
    TRIG_IN_MUX_3_TCPWM0_16M_TR_OUT02 = 0x00000306u /* tcpwm[0].tr_out0[258] */
} en_trig_input_mdma_tr_t;

/* Trigger Input Group 4 -  */
typedef enum
{
    TRIG_IN_MUX_4_PDMA0_TR_OUT0     = 0x00000401u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT1     = 0x00000402u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT2     = 0x00000403u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT3     = 0x00000404u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT4     = 0x00000405u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT5     = 0x00000406u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT6     = 0x00000407u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT7     = 0x00000408u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT8     = 0x00000409u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT9     = 0x0000040Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT10    = 0x0000040Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT11    = 0x0000040Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT12    = 0x0000040Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT13    = 0x0000040Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT14    = 0x0000040Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_4_PDMA0_TR_OUT15    = 0x00000410u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT0     = 0x00000411u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT1     = 0x00000412u, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT2     = 0x00000413u, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT3     = 0x00000414u, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT4     = 0x00000415u, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT5     = 0x00000416u, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT6     = 0x00000417u, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT7     = 0x00000418u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT8     = 0x00000419u, /* cpuss.dw1_tr_out[8] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT9     = 0x0000041Au, /* cpuss.dw1_tr_out[9] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT10    = 0x0000041Bu, /* cpuss.dw1_tr_out[10] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT11    = 0x0000041Cu, /* cpuss.dw1_tr_out[11] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT12    = 0x0000041Du, /* cpuss.dw1_tr_out[12] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT13    = 0x0000041Eu, /* cpuss.dw1_tr_out[13] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT14    = 0x0000041Fu, /* cpuss.dw1_tr_out[14] */
    TRIG_IN_MUX_4_PDMA1_TR_OUT15    = 0x00000420u, /* cpuss.dw1_tr_out[15] */
    TRIG_IN_MUX_4_MDMA_TR_OUT0      = 0x00000421u, /* cpuss.dmac_tr_out[0] */
    TRIG_IN_MUX_4_MDMA_TR_OUT1      = 0x00000422u, /* cpuss.dmac_tr_out[1] */
    TRIG_IN_MUX_4_MDMA_TR_OUT2      = 0x00000423u, /* cpuss.dmac_tr_out[2] */
    TRIG_IN_MUX_4_MDMA_TR_OUT3      = 0x00000424u, /* cpuss.dmac_tr_out[3] */
    TRIG_IN_MUX_4_MDMA_TR_OUT4      = 0x00000425u, /* cpuss.dmac_tr_out[4] */
    TRIG_IN_MUX_4_MDMA_TR_OUT5      = 0x00000426u, /* cpuss.dmac_tr_out[5] */
    TRIG_IN_MUX_4_MDMA_TR_OUT6      = 0x00000427u, /* cpuss.dmac_tr_out[6] */
    TRIG_IN_MUX_4_MDMA_TR_OUT7      = 0x00000428u, /* cpuss.dmac_tr_out[7] */
    TRIG_IN_MUX_4_TCPWM0_16_TR_OUT00 = 0x00000429u, /* tcpwm[0].tr_out0[0] */
    TRIG_IN_MUX_4_TCPWM0_16_TR_OUT01 = 0x0000042Au, /* tcpwm[0].tr_out0[1] */
    TRIG_IN_MUX_4_TCPWM0_16_TR_OUT02 = 0x0000042Bu, /* tcpwm[0].tr_out0[2] */
    TRIG_IN_MUX_4_TCPWM0_16M_TR_OUT00 = 0x0000042Cu, /* tcpwm[0].tr_out0[256] */
    TRIG_IN_MUX_4_TCPWM0_16M_TR_OUT01 = 0x0000042Du, /* tcpwm[0].tr_out0[257] */
    TRIG_IN_MUX_4_TCPWM0_16M_TR_OUT02 = 0x0000042Eu, /* tcpwm[0].tr_out0[258] */
    TRIG_IN_MUX_4_TCPWM0_32_TR_OUT00 = 0x0000042Fu, /* tcpwm[0].tr_out0[512] */
    TRIG_IN_MUX_4_TCPWM0_32_TR_OUT01 = 0x00000430u, /* tcpwm[0].tr_out0[513] */
    TRIG_IN_MUX_4_TCPWM0_32_TR_OUT02 = 0x00000431u, /* tcpwm[0].tr_out0[514] */
    TRIG_IN_MUX_4_TCPWM1_16_TR_OUT00 = 0x00000432u, /* tcpwm[1].tr_out0[0] */
    TRIG_IN_MUX_4_TCPWM1_16_TR_OUT01 = 0x00000433u, /* tcpwm[1].tr_out0[1] */
    TRIG_IN_MUX_4_TCPWM1_16_TR_OUT02 = 0x00000434u, /* tcpwm[1].tr_out0[2] */
    TRIG_IN_MUX_4_TCPWM1_16_TR_OUT03 = 0x00000435u, /* tcpwm[1].tr_out0[3] */
    TRIG_IN_MUX_4_TCPWM1_16_TR_OUT04 = 0x00000436u, /* tcpwm[1].tr_out0[4] */
    TRIG_IN_MUX_4_TCPWM1_16_TR_OUT05 = 0x00000437u, /* tcpwm[1].tr_out0[5] */
    TRIG_IN_MUX_4_TCPWM1_16_TR_OUT06 = 0x00000438u, /* tcpwm[1].tr_out0[6] */
    TRIG_IN_MUX_4_TCPWM1_16_TR_OUT07 = 0x00000439u, /* tcpwm[1].tr_out0[7] */
    TRIG_IN_MUX_4_TCPWM1_16_TR_OUT08 = 0x0000043Au, /* tcpwm[1].tr_out0[8] */
    TRIG_IN_MUX_4_TCPWM1_16_TR_OUT09 = 0x0000043Bu, /* tcpwm[1].tr_out0[9] */
    TRIG_IN_MUX_4_TCPWM1_16_TR_OUT010 = 0x0000043Cu, /* tcpwm[1].tr_out0[10] */
    TRIG_IN_MUX_4_TCPWM1_16_TR_OUT011 = 0x0000043Du, /* tcpwm[1].tr_out0[11] */
    TRIG_IN_MUX_4_TCPWM1_16_TR_OUT012 = 0x0000043Eu, /* tcpwm[1].tr_out0[12] */
    TRIG_IN_MUX_4_TCPWM1_16_TR_OUT013 = 0x0000043Fu, /* tcpwm[1].tr_out0[13] */
    TRIG_IN_MUX_4_TCPWM1_16_TR_OUT014 = 0x00000440u, /* tcpwm[1].tr_out0[14] */
    TRIG_IN_MUX_4_TCPWM1_16_TR_OUT015 = 0x00000441u, /* tcpwm[1].tr_out0[15] */
    TRIG_IN_MUX_4_TCPWM1_16M_TR_OUT00 = 0x00000442u, /* tcpwm[1].tr_out0[256] */
    TRIG_IN_MUX_4_TCPWM1_16M_TR_OUT01 = 0x00000443u, /* tcpwm[1].tr_out0[257] */
    TRIG_IN_MUX_4_TCPWM1_16M_TR_OUT02 = 0x00000444u, /* tcpwm[1].tr_out0[258] */
    TRIG_IN_MUX_4_TCPWM1_16M_TR_OUT03 = 0x00000445u, /* tcpwm[1].tr_out0[259] */
    TRIG_IN_MUX_4_TCPWM1_16M_TR_OUT04 = 0x00000446u, /* tcpwm[1].tr_out0[260] */
    TRIG_IN_MUX_4_TCPWM1_16M_TR_OUT05 = 0x00000447u, /* tcpwm[1].tr_out0[261] */
    TRIG_IN_MUX_4_TCPWM1_32_TR_OUT00 = 0x00000448u, /* tcpwm[1].tr_out0[512] */
    TRIG_IN_MUX_4_TCPWM1_32_TR_OUT01 = 0x00000449u, /* tcpwm[1].tr_out0[513] */
    TRIG_IN_MUX_4_TCPWM1_32_TR_OUT02 = 0x0000044Au, /* tcpwm[1].tr_out0[514] */
    TRIG_IN_MUX_4_TCPWM1_32_TR_OUT03 = 0x0000044Bu, /* tcpwm[1].tr_out0[515] */
    TRIG_IN_MUX_4_TCPWM1_32_TR_OUT04 = 0x0000044Cu, /* tcpwm[1].tr_out0[516] */
    TRIG_IN_MUX_4_TCPWM1_32_TR_OUT05 = 0x0000044Du, /* tcpwm[1].tr_out0[517] */
    TRIG_IN_MUX_4_TCPWM1_32_TR_OUT06 = 0x0000044Eu, /* tcpwm[1].tr_out0[518] */
    TRIG_IN_MUX_4_SMIF_TX_TR_OUT    = 0x0000044Fu, /* smif[0].tr_tx_req */
    TRIG_IN_MUX_4_SMIF_RX_TR_OUT    = 0x00000450u, /* smif[0].tr_rx_req */
    TRIG_IN_MUX_4_I2S0_TX_TR_OUT    = 0x00000451u, /* audioss[0].tr_i2s_tx_req */
    TRIG_IN_MUX_4_I2S0_RX_TR_OUT    = 0x00000452u, /* audioss[0].tr_i2s_rx_req */
    TRIG_IN_MUX_4_I2S1_TX_TR_OUT    = 0x00000453u, /* audioss[1].tr_i2s_tx_req */
    TRIG_IN_MUX_4_I2S1_RX_TR_OUT    = 0x00000454u, /* audioss[1].tr_i2s_rx_req */
    TRIG_IN_MUX_4_I2S2_TX_TR_OUT    = 0x00000455u, /* audioss[2].tr_i2s_tx_req */
    TRIG_IN_MUX_4_I2S2_RX_TR_OUT    = 0x00000456u /* audioss[2].tr_i2s_rx_req */
} en_trig_input_tcpwm0_tr_t;

/* Trigger Input Group 5 -  */
typedef enum
{
    TRIG_IN_MUX_5_TCPWM0_16_TR_OUT00 = 0x00000501u, /* tcpwm[0].tr_out0[0] */
    TRIG_IN_MUX_5_TCPWM0_16_TR_OUT01 = 0x00000502u, /* tcpwm[0].tr_out0[1] */
    TRIG_IN_MUX_5_TCPWM0_16_TR_OUT02 = 0x00000503u, /* tcpwm[0].tr_out0[2] */
    TRIG_IN_MUX_5_TCPWM0_16M_TR_OUT00 = 0x00000504u, /* tcpwm[0].tr_out0[256] */
    TRIG_IN_MUX_5_TCPWM0_16M_TR_OUT01 = 0x00000505u, /* tcpwm[0].tr_out0[257] */
    TRIG_IN_MUX_5_TCPWM0_16M_TR_OUT02 = 0x00000506u, /* tcpwm[0].tr_out0[258] */
    TRIG_IN_MUX_5_TCPWM0_32_TR_OUT00 = 0x00000507u, /* tcpwm[0].tr_out0[512] */
    TRIG_IN_MUX_5_TCPWM0_32_TR_OUT01 = 0x00000508u, /* tcpwm[0].tr_out0[513] */
    TRIG_IN_MUX_5_TCPWM0_32_TR_OUT02 = 0x00000509u, /* tcpwm[0].tr_out0[514] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT00 = 0x0000050Au, /* tcpwm[1].tr_out0[0] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT01 = 0x0000050Bu, /* tcpwm[1].tr_out0[1] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT02 = 0x0000050Cu, /* tcpwm[1].tr_out0[2] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT03 = 0x0000050Du, /* tcpwm[1].tr_out0[3] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT04 = 0x0000050Eu, /* tcpwm[1].tr_out0[4] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT05 = 0x0000050Fu, /* tcpwm[1].tr_out0[5] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT06 = 0x00000510u, /* tcpwm[1].tr_out0[6] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT07 = 0x00000511u, /* tcpwm[1].tr_out0[7] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT08 = 0x00000512u, /* tcpwm[1].tr_out0[8] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT09 = 0x00000513u, /* tcpwm[1].tr_out0[9] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT010 = 0x00000514u, /* tcpwm[1].tr_out0[10] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT011 = 0x00000515u, /* tcpwm[1].tr_out0[11] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT012 = 0x00000516u, /* tcpwm[1].tr_out0[12] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT013 = 0x00000517u, /* tcpwm[1].tr_out0[13] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT014 = 0x00000518u, /* tcpwm[1].tr_out0[14] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT015 = 0x00000519u, /* tcpwm[1].tr_out0[15] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT016 = 0x0000051Au, /* tcpwm[1].tr_out0[16] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT017 = 0x0000051Bu, /* tcpwm[1].tr_out0[17] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT018 = 0x0000051Cu, /* tcpwm[1].tr_out0[18] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT019 = 0x0000051Du, /* tcpwm[1].tr_out0[19] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT020 = 0x0000051Eu, /* tcpwm[1].tr_out0[20] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT021 = 0x0000051Fu, /* tcpwm[1].tr_out0[21] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT022 = 0x00000520u, /* tcpwm[1].tr_out0[22] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT023 = 0x00000521u, /* tcpwm[1].tr_out0[23] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT024 = 0x00000522u, /* tcpwm[1].tr_out0[24] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT025 = 0x00000523u, /* tcpwm[1].tr_out0[25] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT026 = 0x00000524u, /* tcpwm[1].tr_out0[26] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT027 = 0x00000525u, /* tcpwm[1].tr_out0[27] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT028 = 0x00000526u, /* tcpwm[1].tr_out0[28] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT029 = 0x00000527u, /* tcpwm[1].tr_out0[29] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT030 = 0x00000528u, /* tcpwm[1].tr_out0[30] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT031 = 0x00000529u, /* tcpwm[1].tr_out0[31] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT032 = 0x0000052Au, /* tcpwm[1].tr_out0[32] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT033 = 0x0000052Bu, /* tcpwm[1].tr_out0[33] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT034 = 0x0000052Cu, /* tcpwm[1].tr_out0[34] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT035 = 0x0000052Du, /* tcpwm[1].tr_out0[35] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT036 = 0x0000052Eu, /* tcpwm[1].tr_out0[36] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT037 = 0x0000052Fu, /* tcpwm[1].tr_out0[37] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT038 = 0x00000530u, /* tcpwm[1].tr_out0[38] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT039 = 0x00000531u, /* tcpwm[1].tr_out0[39] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT040 = 0x00000532u, /* tcpwm[1].tr_out0[40] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT041 = 0x00000533u, /* tcpwm[1].tr_out0[41] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT042 = 0x00000534u, /* tcpwm[1].tr_out0[42] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT043 = 0x00000535u, /* tcpwm[1].tr_out0[43] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT044 = 0x00000536u, /* tcpwm[1].tr_out0[44] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT045 = 0x00000537u, /* tcpwm[1].tr_out0[45] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT046 = 0x00000538u, /* tcpwm[1].tr_out0[46] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT047 = 0x00000539u, /* tcpwm[1].tr_out0[47] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT048 = 0x0000053Au, /* tcpwm[1].tr_out0[48] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT049 = 0x0000053Bu, /* tcpwm[1].tr_out0[49] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT050 = 0x0000053Cu, /* tcpwm[1].tr_out0[50] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT051 = 0x0000053Du, /* tcpwm[1].tr_out0[51] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT052 = 0x0000053Eu, /* tcpwm[1].tr_out0[52] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT053 = 0x0000053Fu, /* tcpwm[1].tr_out0[53] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT054 = 0x00000540u, /* tcpwm[1].tr_out0[54] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT055 = 0x00000541u, /* tcpwm[1].tr_out0[55] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT056 = 0x00000542u, /* tcpwm[1].tr_out0[56] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT057 = 0x00000543u, /* tcpwm[1].tr_out0[57] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT058 = 0x00000544u, /* tcpwm[1].tr_out0[58] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT059 = 0x00000545u, /* tcpwm[1].tr_out0[59] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT060 = 0x00000546u, /* tcpwm[1].tr_out0[60] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT061 = 0x00000547u, /* tcpwm[1].tr_out0[61] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT062 = 0x00000548u, /* tcpwm[1].tr_out0[62] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT063 = 0x00000549u, /* tcpwm[1].tr_out0[63] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT064 = 0x0000054Au, /* tcpwm[1].tr_out0[64] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT065 = 0x0000054Bu, /* tcpwm[1].tr_out0[65] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT066 = 0x0000054Cu, /* tcpwm[1].tr_out0[66] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT067 = 0x0000054Du, /* tcpwm[1].tr_out0[67] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT068 = 0x0000054Eu, /* tcpwm[1].tr_out0[68] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT069 = 0x0000054Fu, /* tcpwm[1].tr_out0[69] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT070 = 0x00000550u, /* tcpwm[1].tr_out0[70] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT071 = 0x00000551u, /* tcpwm[1].tr_out0[71] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT072 = 0x00000552u, /* tcpwm[1].tr_out0[72] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT073 = 0x00000553u, /* tcpwm[1].tr_out0[73] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT074 = 0x00000554u, /* tcpwm[1].tr_out0[74] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT075 = 0x00000555u, /* tcpwm[1].tr_out0[75] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT076 = 0x00000556u, /* tcpwm[1].tr_out0[76] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT077 = 0x00000557u, /* tcpwm[1].tr_out0[77] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT078 = 0x00000558u, /* tcpwm[1].tr_out0[78] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT079 = 0x00000559u, /* tcpwm[1].tr_out0[79] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT080 = 0x0000055Au, /* tcpwm[1].tr_out0[80] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT081 = 0x0000055Bu, /* tcpwm[1].tr_out0[81] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT082 = 0x0000055Cu, /* tcpwm[1].tr_out0[82] */
    TRIG_IN_MUX_5_TCPWM1_16_TR_OUT083 = 0x0000055Du, /* tcpwm[1].tr_out0[83] */
    TRIG_IN_MUX_5_TCPWM1_16M_TR_OUT00 = 0x0000055Eu, /* tcpwm[1].tr_out0[256] */
    TRIG_IN_MUX_5_TCPWM1_16M_TR_OUT01 = 0x0000055Fu, /* tcpwm[1].tr_out0[257] */
    TRIG_IN_MUX_5_TCPWM1_16M_TR_OUT02 = 0x00000560u, /* tcpwm[1].tr_out0[258] */
    TRIG_IN_MUX_5_TCPWM1_16M_TR_OUT03 = 0x00000561u, /* tcpwm[1].tr_out0[259] */
    TRIG_IN_MUX_5_TCPWM1_16M_TR_OUT04 = 0x00000562u, /* tcpwm[1].tr_out0[260] */
    TRIG_IN_MUX_5_TCPWM1_16M_TR_OUT05 = 0x00000563u, /* tcpwm[1].tr_out0[261] */
    TRIG_IN_MUX_5_TCPWM1_16M_TR_OUT06 = 0x00000564u, /* tcpwm[1].tr_out0[262] */
    TRIG_IN_MUX_5_TCPWM1_16M_TR_OUT07 = 0x00000565u, /* tcpwm[1].tr_out0[263] */
    TRIG_IN_MUX_5_TCPWM1_16M_TR_OUT08 = 0x00000566u, /* tcpwm[1].tr_out0[264] */
    TRIG_IN_MUX_5_TCPWM1_16M_TR_OUT09 = 0x00000567u, /* tcpwm[1].tr_out0[265] */
    TRIG_IN_MUX_5_TCPWM1_16M_TR_OUT010 = 0x00000568u, /* tcpwm[1].tr_out0[266] */
    TRIG_IN_MUX_5_TCPWM1_16M_TR_OUT011 = 0x00000569u, /* tcpwm[1].tr_out0[267] */
    TRIG_IN_MUX_5_TCPWM1_32_TR_OUT00 = 0x0000056Au, /* tcpwm[1].tr_out0[512] */
    TRIG_IN_MUX_5_TCPWM1_32_TR_OUT01 = 0x0000056Bu, /* tcpwm[1].tr_out0[513] */
    TRIG_IN_MUX_5_TCPWM1_32_TR_OUT02 = 0x0000056Cu, /* tcpwm[1].tr_out0[514] */
    TRIG_IN_MUX_5_TCPWM1_32_TR_OUT03 = 0x0000056Du, /* tcpwm[1].tr_out0[515] */
    TRIG_IN_MUX_5_TCPWM1_32_TR_OUT04 = 0x0000056Eu, /* tcpwm[1].tr_out0[516] */
    TRIG_IN_MUX_5_TCPWM1_32_TR_OUT05 = 0x0000056Fu, /* tcpwm[1].tr_out0[517] */
    TRIG_IN_MUX_5_TCPWM1_32_TR_OUT06 = 0x00000570u, /* tcpwm[1].tr_out0[518] */
    TRIG_IN_MUX_5_TCPWM1_32_TR_OUT07 = 0x00000571u, /* tcpwm[1].tr_out0[519] */
    TRIG_IN_MUX_5_TCPWM1_32_TR_OUT08 = 0x00000572u, /* tcpwm[1].tr_out0[520] */
    TRIG_IN_MUX_5_TCPWM1_32_TR_OUT09 = 0x00000573u, /* tcpwm[1].tr_out0[521] */
    TRIG_IN_MUX_5_TCPWM1_32_TR_OUT010 = 0x00000574u, /* tcpwm[1].tr_out0[522] */
    TRIG_IN_MUX_5_TCPWM1_32_TR_OUT011 = 0x00000575u, /* tcpwm[1].tr_out0[523] */
    TRIG_IN_MUX_5_TCPWM1_32_TR_OUT012 = 0x00000576u, /* tcpwm[1].tr_out0[524] */
    TRIG_IN_MUX_5_CAN0_DBG_TR_OUT0  = 0x00000577u, /* canfd[0].tr_dbg_dma_req[0] */
    TRIG_IN_MUX_5_CAN0_DBG_TR_OUT1  = 0x00000578u, /* canfd[0].tr_dbg_dma_req[1] */
    TRIG_IN_MUX_5_CAN0_DBG_TR_OUT2  = 0x00000579u, /* canfd[0].tr_dbg_dma_req[2] */
    TRIG_IN_MUX_5_CAN0_DBG_TR_OUT3  = 0x0000057Au, /* canfd[0].tr_dbg_dma_req[3] */
    TRIG_IN_MUX_5_CAN0_DBG_TR_OUT4  = 0x0000057Bu, /* canfd[0].tr_dbg_dma_req[4] */
    TRIG_IN_MUX_5_CAN0_FIFO0_TR_OUT0 = 0x0000057Cu, /* canfd[0].tr_fifo0[0] */
    TRIG_IN_MUX_5_CAN0_FIFO0_TR_OUT1 = 0x0000057Du, /* canfd[0].tr_fifo0[1] */
    TRIG_IN_MUX_5_CAN0_FIFO0_TR_OUT2 = 0x0000057Eu, /* canfd[0].tr_fifo0[2] */
    TRIG_IN_MUX_5_CAN0_FIFO0_TR_OUT3 = 0x0000057Fu, /* canfd[0].tr_fifo0[3] */
    TRIG_IN_MUX_5_CAN0_FIFO0_TR_OUT4 = 0x00000580u, /* canfd[0].tr_fifo0[4] */
    TRIG_IN_MUX_5_CAN0_FIFO1_TR_OUT0 = 0x00000581u, /* canfd[0].tr_fifo1[0] */
    TRIG_IN_MUX_5_CAN0_FIFO1_TR_OUT1 = 0x00000582u, /* canfd[0].tr_fifo1[1] */
    TRIG_IN_MUX_5_CAN0_FIFO1_TR_OUT2 = 0x00000583u, /* canfd[0].tr_fifo1[2] */
    TRIG_IN_MUX_5_CAN0_FIFO1_TR_OUT3 = 0x00000584u, /* canfd[0].tr_fifo1[3] */
    TRIG_IN_MUX_5_CAN0_FIFO1_TR_OUT4 = 0x00000585u, /* canfd[0].tr_fifo1[4] */
    TRIG_IN_MUX_5_CAN1_DBG_TR_OUT0  = 0x00000586u, /* canfd[1].tr_dbg_dma_req[0] */
    TRIG_IN_MUX_5_CAN1_DBG_TR_OUT1  = 0x00000587u, /* canfd[1].tr_dbg_dma_req[1] */
    TRIG_IN_MUX_5_CAN1_DBG_TR_OUT2  = 0x00000588u, /* canfd[1].tr_dbg_dma_req[2] */
    TRIG_IN_MUX_5_CAN1_DBG_TR_OUT3  = 0x00000589u, /* canfd[1].tr_dbg_dma_req[3] */
    TRIG_IN_MUX_5_CAN1_DBG_TR_OUT4  = 0x0000058Au, /* canfd[1].tr_dbg_dma_req[4] */
    TRIG_IN_MUX_5_CAN1_FIFO0_TR_OUT0 = 0x0000058Bu, /* canfd[1].tr_fifo0[0] */
    TRIG_IN_MUX_5_CAN1_FIFO0_TR_OUT1 = 0x0000058Cu, /* canfd[1].tr_fifo0[1] */
    TRIG_IN_MUX_5_CAN1_FIFO0_TR_OUT2 = 0x0000058Du, /* canfd[1].tr_fifo0[2] */
    TRIG_IN_MUX_5_CAN1_FIFO0_TR_OUT3 = 0x0000058Eu, /* canfd[1].tr_fifo0[3] */
    TRIG_IN_MUX_5_CAN1_FIFO0_TR_OUT4 = 0x0000058Fu, /* canfd[1].tr_fifo0[4] */
    TRIG_IN_MUX_5_CAN1_FIFO1_TR_OUT0 = 0x00000590u, /* canfd[1].tr_fifo1[0] */
    TRIG_IN_MUX_5_CAN1_FIFO1_TR_OUT1 = 0x00000591u, /* canfd[1].tr_fifo1[1] */
    TRIG_IN_MUX_5_CAN1_FIFO1_TR_OUT2 = 0x00000592u, /* canfd[1].tr_fifo1[2] */
    TRIG_IN_MUX_5_CAN1_FIFO1_TR_OUT3 = 0x00000593u, /* canfd[1].tr_fifo1[3] */
    TRIG_IN_MUX_5_CAN1_FIFO1_TR_OUT4 = 0x00000594u, /* canfd[1].tr_fifo1[4] */
    TRIG_IN_MUX_5_CAN0_TT_TR_OUT0   = 0x00000595u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_5_CAN0_TT_TR_OUT1   = 0x00000596u, /* canfd[0].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_5_CAN0_TT_TR_OUT2   = 0x00000597u, /* canfd[0].tr_tmp_rtp_out[2] */
    TRIG_IN_MUX_5_CAN0_TT_TR_OUT3   = 0x00000598u, /* canfd[0].tr_tmp_rtp_out[3] */
    TRIG_IN_MUX_5_CAN0_TT_TR_OUT4   = 0x00000599u, /* canfd[0].tr_tmp_rtp_out[4] */
    TRIG_IN_MUX_5_CAN1_TT_TR_OUT0   = 0x0000059Au, /* canfd[1].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_5_CAN1_TT_TR_OUT1   = 0x0000059Bu, /* canfd[1].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_5_CAN1_TT_TR_OUT2   = 0x0000059Cu, /* canfd[1].tr_tmp_rtp_out[2] */
    TRIG_IN_MUX_5_CAN1_TT_TR_OUT3   = 0x0000059Du, /* canfd[1].tr_tmp_rtp_out[3] */
    TRIG_IN_MUX_5_CAN1_TT_TR_OUT4   = 0x0000059Eu, /* canfd[1].tr_tmp_rtp_out[4] */
    TRIG_IN_MUX_5_FLEXRAY_TT_TR_OUT = 0x0000059Fu, /* flexray[0].tr_tint0_out */
    TRIG_IN_MUX_5_EVTGEN_TR_OUT4    = 0x000005A0u, /* evtgen[0].tr_out[4] */
    TRIG_IN_MUX_5_EVTGEN_TR_OUT5    = 0x000005A1u, /* evtgen[0].tr_out[5] */
    TRIG_IN_MUX_5_EVTGEN_TR_OUT6    = 0x000005A2u, /* evtgen[0].tr_out[6] */
    TRIG_IN_MUX_5_EVTGEN_TR_OUT7    = 0x000005A3u, /* evtgen[0].tr_out[7] */
    TRIG_IN_MUX_5_EVTGEN_TR_OUT8    = 0x000005A4u, /* evtgen[0].tr_out[8] */
    TRIG_IN_MUX_5_EVTGEN_TR_OUT9    = 0x000005A5u, /* evtgen[0].tr_out[9] */
    TRIG_IN_MUX_5_EVTGEN_TR_OUT10   = 0x000005A6u, /* evtgen[0].tr_out[10] */
    TRIG_IN_MUX_5_EVTGEN_TR_OUT11   = 0x000005A7u /* evtgen[0].tr_out[11] */
} en_trig_input_tcpwm1_0_11_tr_t;

/* Trigger Input Group 6 - TCPWM trigger inputs */
typedef enum
{
    TRIG_IN_MUX_6_TCPWM1_16_TR_OUT10 = 0x00000601u, /* tcpwm[1].tr_out1[0] */
    TRIG_IN_MUX_6_TCPWM1_16_TR_OUT11 = 0x00000602u, /* tcpwm[1].tr_out1[1] */
    TRIG_IN_MUX_6_TCPWM1_16_TR_OUT12 = 0x00000603u, /* tcpwm[1].tr_out1[2] */
    TRIG_IN_MUX_6_TCPWM1_16_TR_OUT13 = 0x00000604u, /* tcpwm[1].tr_out1[3] */
    TRIG_IN_MUX_6_TCPWM1_16_TR_OUT14 = 0x00000605u, /* tcpwm[1].tr_out1[4] */
    TRIG_IN_MUX_6_TCPWM1_16_TR_OUT15 = 0x00000606u, /* tcpwm[1].tr_out1[5] */
    TRIG_IN_MUX_6_TCPWM1_16_TR_OUT16 = 0x00000607u, /* tcpwm[1].tr_out1[6] */
    TRIG_IN_MUX_6_TCPWM1_16_TR_OUT17 = 0x00000608u, /* tcpwm[1].tr_out1[7] */
    TRIG_IN_MUX_6_TCPWM1_16_TR_OUT18 = 0x00000609u, /* tcpwm[1].tr_out1[8] */
    TRIG_IN_MUX_6_TCPWM1_16_TR_OUT19 = 0x0000060Au, /* tcpwm[1].tr_out1[9] */
    TRIG_IN_MUX_6_TCPWM1_16_TR_OUT110 = 0x0000060Bu, /* tcpwm[1].tr_out1[10] */
    TRIG_IN_MUX_6_TCPWM1_16_TR_OUT111 = 0x0000060Cu, /* tcpwm[1].tr_out1[11] */
    TRIG_IN_MUX_6_TCPWM1_16_TR_OUT112 = 0x0000060Du, /* tcpwm[1].tr_out1[12] */
    TRIG_IN_MUX_6_TCPWM1_16_TR_OUT113 = 0x0000060Eu, /* tcpwm[1].tr_out1[13] */
    TRIG_IN_MUX_6_TCPWM1_16_TR_OUT114 = 0x0000060Fu, /* tcpwm[1].tr_out1[14] */
    TRIG_IN_MUX_6_TCPWM1_16_TR_OUT115 = 0x00000610u, /* tcpwm[1].tr_out1[15] */
    TRIG_IN_MUX_6_SCB_TX_TR_OUT0    = 0x00000611u, /* scb[0].tr_tx_req */
    TRIG_IN_MUX_6_SCB_RX_TR_OUT0    = 0x00000612u, /* scb[0].tr_rx_req */
    TRIG_IN_MUX_6_SCB_I2C_SCL_TR_OUT0 = 0x00000613u, /* scb[0].tr_i2c_scl_filtered */
    TRIG_IN_MUX_6_SCB_TX_TR_OUT1    = 0x00000614u, /* scb[1].tr_tx_req */
    TRIG_IN_MUX_6_SCB_RX_TR_OUT1    = 0x00000615u, /* scb[1].tr_rx_req */
    TRIG_IN_MUX_6_SCB_I2C_SCL_TR_OUT1 = 0x00000616u, /* scb[1].tr_i2c_scl_filtered */
    TRIG_IN_MUX_6_SCB_TX_TR_OUT2    = 0x00000617u, /* scb[2].tr_tx_req */
    TRIG_IN_MUX_6_SCB_RX_TR_OUT2    = 0x00000618u, /* scb[2].tr_rx_req */
    TRIG_IN_MUX_6_SCB_I2C_SCL_TR_OUT2 = 0x00000619u, /* scb[2].tr_i2c_scl_filtered */
    TRIG_IN_MUX_6_SCB_TX_TR_OUT3    = 0x0000061Au, /* scb[3].tr_tx_req */
    TRIG_IN_MUX_6_SCB_RX_TR_OUT3    = 0x0000061Bu, /* scb[3].tr_rx_req */
    TRIG_IN_MUX_6_SCB_I2C_SCL_TR_OUT3 = 0x0000061Cu, /* scb[3].tr_i2c_scl_filtered */
    TRIG_IN_MUX_6_SCB_TX_TR_OUT4    = 0x0000061Du, /* scb[4].tr_tx_req */
    TRIG_IN_MUX_6_SCB_RX_TR_OUT4    = 0x0000061Eu, /* scb[4].tr_rx_req */
    TRIG_IN_MUX_6_SCB_I2C_SCL_TR_OUT4 = 0x0000061Fu, /* scb[4].tr_i2c_scl_filtered */
    TRIG_IN_MUX_6_SCB_TX_TR_OUT5    = 0x00000620u, /* scb[5].tr_tx_req */
    TRIG_IN_MUX_6_SCB_RX_TR_OUT5    = 0x00000621u, /* scb[5].tr_rx_req */
    TRIG_IN_MUX_6_SCB_I2C_SCL_TR_OUT5 = 0x00000622u, /* scb[5].tr_i2c_scl_filtered */
    TRIG_IN_MUX_6_SCB_TX_TR_OUT6    = 0x00000623u, /* scb[6].tr_tx_req */
    TRIG_IN_MUX_6_SCB_RX_TR_OUT6    = 0x00000624u, /* scb[6].tr_rx_req */
    TRIG_IN_MUX_6_SCB_I2C_SCL_TR_OUT6 = 0x00000625u, /* scb[6].tr_i2c_scl_filtered */
    TRIG_IN_MUX_6_SCB_TX_TR_OUT7    = 0x00000626u, /* scb[7].tr_tx_req */
    TRIG_IN_MUX_6_SCB_RX_TR_OUT7    = 0x00000627u, /* scb[7].tr_rx_req */
    TRIG_IN_MUX_6_SCB_I2C_SCL_TR_OUT7 = 0x00000628u, /* scb[7].tr_i2c_scl_filtered */
    TRIG_IN_MUX_6_SCB_TX_TR_OUT8    = 0x00000629u, /* scb[8].tr_tx_req */
    TRIG_IN_MUX_6_SCB_RX_TR_OUT8    = 0x0000062Au, /* scb[8].tr_rx_req */
    TRIG_IN_MUX_6_SCB_I2C_SCL_TR_OUT8 = 0x0000062Bu, /* scb[8].tr_i2c_scl_filtered */
    TRIG_IN_MUX_6_SCB_TX_TR_OUT9    = 0x0000062Cu, /* scb[9].tr_tx_req */
    TRIG_IN_MUX_6_CB_RX_TR_OUT9     = 0x0000062Du, /* scb[9].tr_rx_req */
    TRIG_IN_MUX_6_SCB_I2C_SCL_TR_OUT9 = 0x0000062Eu, /* scb[9].tr_i2c_scl_filtered */
    TRIG_IN_MUX_6_SCB_TX_TR_OUT10   = 0x0000062Fu, /* scb[10].tr_tx_req */
    TRIG_IN_MUX_6_SCB_RX_TR_OUT10   = 0x00000630u, /* scb[10].tr_rx_req */
    TRIG_IN_MUX_6_SCB_I2C_SCL_TR_OUT10 = 0x00000631u, /* scb[10].tr_i2c_scl_filtered */
    TRIG_IN_MUX_6_FLEXRAY_IBUF_TR_OUT = 0x00000632u, /* flexray[0].tr_ibf_out */
    TRIG_IN_MUX_6_FLEXRAY_OBUF_TR_OUT = 0x00000633u, /* flexray[0].tr_obf_out */
    TRIG_IN_MUX_6_PASS_GEN_TR_OUT0  = 0x00000634u, /* pass[0].tr_sar_gen_out[0] */
    TRIG_IN_MUX_6_PASS_GEN_TR_OUT1  = 0x00000635u, /* pass[0].tr_sar_gen_out[1] */
    TRIG_IN_MUX_6_PASS_GEN_TR_OUT2  = 0x00000636u, /* pass[0].tr_sar_gen_out[2] */
    TRIG_IN_MUX_6_PASS_GEN_TR_OUT3  = 0x00000637u, /* pass[0].tr_sar_gen_out[3] */
    TRIG_IN_MUX_6_PASS_GEN_TR_OUT4  = 0x00000638u, /* pass[0].tr_sar_gen_out[4] */
    TRIG_IN_MUX_6_PASS_GEN_TR_OUT5  = 0x00000639u, /* pass[0].tr_sar_gen_out[5] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT0   = 0x0000063Au, /* peri.tr_io_input[0] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT1   = 0x0000063Bu, /* peri.tr_io_input[1] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT2   = 0x0000063Cu, /* peri.tr_io_input[2] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT3   = 0x0000063Du, /* peri.tr_io_input[3] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT4   = 0x0000063Eu, /* peri.tr_io_input[4] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT5   = 0x0000063Fu, /* peri.tr_io_input[5] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT6   = 0x00000640u, /* peri.tr_io_input[6] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT7   = 0x00000641u, /* peri.tr_io_input[7] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT8   = 0x00000642u, /* peri.tr_io_input[8] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT9   = 0x00000643u, /* peri.tr_io_input[9] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT10  = 0x00000644u, /* peri.tr_io_input[10] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT11  = 0x00000645u, /* peri.tr_io_input[11] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT12  = 0x00000646u, /* peri.tr_io_input[12] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT13  = 0x00000647u, /* peri.tr_io_input[13] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT14  = 0x00000648u, /* peri.tr_io_input[14] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT15  = 0x00000649u, /* peri.tr_io_input[15] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT16  = 0x0000064Au, /* peri.tr_io_input[16] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT17  = 0x0000064Bu, /* peri.tr_io_input[17] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT18  = 0x0000064Cu, /* peri.tr_io_input[18] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT19  = 0x0000064Du, /* peri.tr_io_input[19] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT20  = 0x0000064Eu, /* peri.tr_io_input[20] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT21  = 0x0000064Fu, /* peri.tr_io_input[21] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT22  = 0x00000650u, /* peri.tr_io_input[22] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT23  = 0x00000651u, /* peri.tr_io_input[23] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT24  = 0x00000652u, /* peri.tr_io_input[24] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT25  = 0x00000653u, /* peri.tr_io_input[25] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT26  = 0x00000654u, /* peri.tr_io_input[26] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT27  = 0x00000655u, /* peri.tr_io_input[27] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT28  = 0x00000656u, /* peri.tr_io_input[28] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT29  = 0x00000657u, /* peri.tr_io_input[29] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT30  = 0x00000658u, /* peri.tr_io_input[30] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT31  = 0x00000659u, /* peri.tr_io_input[31] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT32  = 0x0000065Au, /* peri.tr_io_input[32] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT33  = 0x0000065Bu, /* peri.tr_io_input[33] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT34  = 0x0000065Cu, /* peri.tr_io_input[34] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT35  = 0x0000065Du, /* peri.tr_io_input[35] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT36  = 0x0000065Eu, /* peri.tr_io_input[36] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT37  = 0x0000065Fu, /* peri.tr_io_input[37] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT38  = 0x00000660u, /* peri.tr_io_input[38] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT39  = 0x00000661u, /* peri.tr_io_input[39] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT40  = 0x00000662u, /* peri.tr_io_input[40] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT41  = 0x00000663u, /* peri.tr_io_input[41] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT42  = 0x00000664u, /* peri.tr_io_input[42] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT43  = 0x00000665u, /* peri.tr_io_input[43] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT44  = 0x00000666u, /* peri.tr_io_input[44] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT45  = 0x00000667u, /* peri.tr_io_input[45] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT46  = 0x00000668u, /* peri.tr_io_input[46] */
    TRIG_IN_MUX_6_HSIOM_IO_INPUT47  = 0x00000669u, /* peri.tr_io_input[47] */
    TRIG_IN_MUX_6_CTI_TR_IN0        = 0x0000066Au, /* cpuss.cti_tr_out[0] */
    TRIG_IN_MUX_6_CTI_TR_IN1        = 0x0000066Bu, /* cpuss.cti_tr_out[1] */
    TRIG_IN_MUX_6_FAULT_TR_OUT0     = 0x0000066Cu, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_6_FAULT_TR_OUT1     = 0x0000066Du, /* cpuss.tr_fault[1] */
    TRIG_IN_MUX_6_FAULT_TR_OUT2     = 0x0000066Eu, /* cpuss.tr_fault[2] */
    TRIG_IN_MUX_6_FAULT_TR_OUT3     = 0x0000066Fu /* cpuss.tr_fault[3] */
} en_trig_input_tcpwm1_12_40_tr_t;

/* Trigger Input Group 7 - PASS trigger multiplexer */
typedef enum
{
    TRIG_IN_MUX_7_PDMA0_TR_OUT0     = 0x00000701u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT1     = 0x00000702u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT2     = 0x00000703u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT3     = 0x00000704u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT4     = 0x00000705u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT5     = 0x00000706u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT6     = 0x00000707u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT7     = 0x00000708u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT8     = 0x00000709u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT9     = 0x0000070Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT10    = 0x0000070Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT11    = 0x0000070Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT12    = 0x0000070Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT13    = 0x0000070Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT14    = 0x0000070Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_7_PDMA0_TR_OUT15    = 0x00000710u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_7_TCPWM1_16M_TR_OUT00 = 0x00000711u, /* tcpwm[1].tr_out0[256] */
    TRIG_IN_MUX_7_TCPWM1_16M_TR_OUT01 = 0x00000712u, /* tcpwm[1].tr_out0[257] */
    TRIG_IN_MUX_7_TCPWM1_16M_TR_OUT02 = 0x00000713u, /* tcpwm[1].tr_out0[258] */
    TRIG_IN_MUX_7_TCPWM1_16M_TR_OUT03 = 0x00000714u, /* tcpwm[1].tr_out0[259] */
    TRIG_IN_MUX_7_TCPWM1_16M_TR_OUT04 = 0x00000715u, /* tcpwm[1].tr_out0[260] */
    TRIG_IN_MUX_7_TCPWM1_16M_TR_OUT05 = 0x00000716u, /* tcpwm[1].tr_out0[261] */
    TRIG_IN_MUX_7_TCPWM1_16M_TR_OUT06 = 0x00000717u, /* tcpwm[1].tr_out0[262] */
    TRIG_IN_MUX_7_TCPWM1_16M_TR_OUT07 = 0x00000718u, /* tcpwm[1].tr_out0[263] */
    TRIG_IN_MUX_7_TCPWM1_16M_TR_OUT08 = 0x00000719u, /* tcpwm[1].tr_out0[264] */
    TRIG_IN_MUX_7_TCPWM1_16M_TR_OUT09 = 0x0000071Au, /* tcpwm[1].tr_out0[265] */
    TRIG_IN_MUX_7_TCPWM1_16M_TR_OUT010 = 0x0000071Bu, /* tcpwm[1].tr_out0[266] */
    TRIG_IN_MUX_7_TCPWM1_16M_TR_OUT011 = 0x0000071Cu, /* tcpwm[1].tr_out0[267] */
    TRIG_IN_MUX_7_TCPWM1_32_TR_OUT00 = 0x0000071Du, /* tcpwm[1].tr_out0[512] */
    TRIG_IN_MUX_7_TCPWM1_32_TR_OUT01 = 0x0000071Eu, /* tcpwm[1].tr_out0[513] */
    TRIG_IN_MUX_7_TCPWM1_32_TR_OUT02 = 0x0000071Fu, /* tcpwm[1].tr_out0[514] */
    TRIG_IN_MUX_7_TCPWM1_32_TR_OUT03 = 0x00000720u, /* tcpwm[1].tr_out0[515] */
    TRIG_IN_MUX_7_TCPWM1_32_TR_OUT04 = 0x00000721u, /* tcpwm[1].tr_out0[516] */
    TRIG_IN_MUX_7_TCPWM1_32_TR_OUT05 = 0x00000722u, /* tcpwm[1].tr_out0[517] */
    TRIG_IN_MUX_7_TCPWM1_32_TR_OUT06 = 0x00000723u, /* tcpwm[1].tr_out0[518] */
    TRIG_IN_MUX_7_TCPWM1_32_TR_OUT07 = 0x00000724u, /* tcpwm[1].tr_out0[519] */
    TRIG_IN_MUX_7_TCPWM1_32_TR_OUT08 = 0x00000725u, /* tcpwm[1].tr_out0[520] */
    TRIG_IN_MUX_7_TCPWM1_32_TR_OUT09 = 0x00000726u, /* tcpwm[1].tr_out0[521] */
    TRIG_IN_MUX_7_TCPWM1_32_TR_OUT010 = 0x00000727u, /* tcpwm[1].tr_out0[522] */
    TRIG_IN_MUX_7_TCPWM1_32_TR_OUT011 = 0x00000728u, /* tcpwm[1].tr_out0[523] */
    TRIG_IN_MUX_7_TCPWM1_32_TR_OUT012 = 0x00000729u, /* tcpwm[1].tr_out0[524] */
    TRIG_IN_MUX_7_HSIOM_IO_INPUT0   = 0x0000072Au, /* peri.tr_io_input[0] */
    TRIG_IN_MUX_7_HSIOM_IO_INPUT1   = 0x0000072Bu, /* peri.tr_io_input[1] */
    TRIG_IN_MUX_7_HSIOM_IO_INPUT2   = 0x0000072Cu, /* peri.tr_io_input[2] */
    TRIG_IN_MUX_7_HSIOM_IO_INPUT3   = 0x0000072Du, /* peri.tr_io_input[3] */
    TRIG_IN_MUX_7_HSIOM_IO_INPUT4   = 0x0000072Eu, /* peri.tr_io_input[4] */
    TRIG_IN_MUX_7_HSIOM_IO_INPUT5   = 0x0000072Fu, /* peri.tr_io_input[5] */
    TRIG_IN_MUX_7_HSIOM_IO_INPUT6   = 0x00000730u, /* peri.tr_io_input[6] */
    TRIG_IN_MUX_7_HSIOM_IO_INPUT7   = 0x00000731u, /* peri.tr_io_input[7] */
    TRIG_IN_MUX_7_EVTGEN_TR_OUT12   = 0x00000732u, /* evtgen[0].tr_out[12] */
    TRIG_IN_MUX_7_EVTGEN_TR_OUT13   = 0x00000733u, /* evtgen[0].tr_out[13] */
    TRIG_IN_MUX_7_EVTGEN_TR_OUT14   = 0x00000734u /* evtgen[0].tr_out[14] */
} en_trig_input_pass_tr_t;

/* Trigger Input Group 8 - CAN TT Synchronization triggers */
typedef enum
{
    TRIG_IN_MUX_8_CAN0_TT_TR_OUT0   = 0x00000801u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_8_CAN0_TT_TR_OUT1   = 0x00000802u, /* canfd[0].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_8_CAN0_TT_TR_OUT2   = 0x00000803u, /* canfd[0].tr_tmp_rtp_out[2] */
    TRIG_IN_MUX_8_CAN0_TT_TR_OUT3   = 0x00000804u, /* canfd[0].tr_tmp_rtp_out[3] */
    TRIG_IN_MUX_8_CAN0_TT_TR_OUT4   = 0x00000805u, /* canfd[0].tr_tmp_rtp_out[4] */
    TRIG_IN_MUX_8_CAN1_TT_TR_OUT0   = 0x00000806u, /* canfd[1].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_8_CAN1_TT_TR_OUT1   = 0x00000807u, /* canfd[1].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_8_CAN1_TT_TR_OUT2   = 0x00000808u, /* canfd[1].tr_tmp_rtp_out[2] */
    TRIG_IN_MUX_8_CAN1_TT_TR_OUT3   = 0x00000809u, /* canfd[1].tr_tmp_rtp_out[3] */
    TRIG_IN_MUX_8_CAN1_TT_TR_OUT4   = 0x0000080Au, /* canfd[1].tr_tmp_rtp_out[4] */
    TRIG_IN_MUX_8_FLEXRAY_TT_TR_OUT = 0x0000080Bu /* flexray[0].tr_tint0_out */
} en_trig_input_can_flexray_tr_t;

/* Trigger Input Group 9 - 2nd level MUX using input from MUX_11/12/13 */
typedef enum
{
    TRIG_IN_MUX_9_TR_GROUP10_OUTPUT0 = 0x00000901u, /* tr_group[10].output[0] */
    TRIG_IN_MUX_9_TR_GROUP10_OUTPUT1 = 0x00000902u, /* tr_group[10].output[1] */
    TRIG_IN_MUX_9_TR_GROUP10_OUTPUT2 = 0x00000903u, /* tr_group[10].output[2] */
    TRIG_IN_MUX_9_TR_GROUP10_OUTPUT3 = 0x00000904u, /* tr_group[10].output[3] */
    TRIG_IN_MUX_9_TR_GROUP10_OUTPUT4 = 0x00000905u, /* tr_group[10].output[4] */
    TRIG_IN_MUX_9_TR_GROUP11_OUTPUT0 = 0x00000906u, /* tr_group[11].output[0] */
    TRIG_IN_MUX_9_TR_GROUP11_OUTPUT1 = 0x00000907u, /* tr_group[11].output[1] */
    TRIG_IN_MUX_9_TR_GROUP11_OUTPUT2 = 0x00000908u, /* tr_group[11].output[2] */
    TRIG_IN_MUX_9_TR_GROUP11_OUTPUT3 = 0x00000909u, /* tr_group[11].output[3] */
    TRIG_IN_MUX_9_TR_GROUP11_OUTPUT4 = 0x0000090Au, /* tr_group[11].output[4] */
    TRIG_IN_MUX_9_TR_GROUP12_OUTPUT0 = 0x0000090Bu, /* tr_group[12].output[0] */
    TRIG_IN_MUX_9_TR_GROUP12_OUTPUT1 = 0x0000090Cu, /* tr_group[12].output[1] */
    TRIG_IN_MUX_9_TR_GROUP12_OUTPUT2 = 0x0000090Du, /* tr_group[12].output[2] */
    TRIG_IN_MUX_9_TR_GROUP12_OUTPUT3 = 0x0000090Eu, /* tr_group[12].output[3] */
    TRIG_IN_MUX_9_TR_GROUP12_OUTPUT4 = 0x0000090Fu /* tr_group[12].output[4] */
} en_trig_input_debug_tr_t;

/* Trigger Input Group 10 - Makes all possible triggers visible as I/O signals for debug purposes, or to build external circuitry */
typedef enum
{
    TRIG_IN_MUX_10_PDMA0_TR_OUT0    = 0x00000A01u, /* cpuss.dw0_tr_out[0] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT1    = 0x00000A02u, /* cpuss.dw0_tr_out[1] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT2    = 0x00000A03u, /* cpuss.dw0_tr_out[2] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT3    = 0x00000A04u, /* cpuss.dw0_tr_out[3] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT4    = 0x00000A05u, /* cpuss.dw0_tr_out[4] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT5    = 0x00000A06u, /* cpuss.dw0_tr_out[5] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT6    = 0x00000A07u, /* cpuss.dw0_tr_out[6] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT7    = 0x00000A08u, /* cpuss.dw0_tr_out[7] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT8    = 0x00000A09u, /* cpuss.dw0_tr_out[8] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT9    = 0x00000A0Au, /* cpuss.dw0_tr_out[9] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT10   = 0x00000A0Bu, /* cpuss.dw0_tr_out[10] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT11   = 0x00000A0Cu, /* cpuss.dw0_tr_out[11] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT12   = 0x00000A0Du, /* cpuss.dw0_tr_out[12] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT13   = 0x00000A0Eu, /* cpuss.dw0_tr_out[13] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT14   = 0x00000A0Fu, /* cpuss.dw0_tr_out[14] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT15   = 0x00000A10u, /* cpuss.dw0_tr_out[15] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT16   = 0x00000A11u, /* cpuss.dw0_tr_out[16] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT17   = 0x00000A12u, /* cpuss.dw0_tr_out[17] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT18   = 0x00000A13u, /* cpuss.dw0_tr_out[18] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT19   = 0x00000A14u, /* cpuss.dw0_tr_out[19] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT20   = 0x00000A15u, /* cpuss.dw0_tr_out[20] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT21   = 0x00000A16u, /* cpuss.dw0_tr_out[21] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT22   = 0x00000A17u, /* cpuss.dw0_tr_out[22] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT23   = 0x00000A18u, /* cpuss.dw0_tr_out[23] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT24   = 0x00000A19u, /* cpuss.dw0_tr_out[24] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT25   = 0x00000A1Au, /* cpuss.dw0_tr_out[25] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT26   = 0x00000A1Bu, /* cpuss.dw0_tr_out[26] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT27   = 0x00000A1Cu, /* cpuss.dw0_tr_out[27] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT28   = 0x00000A1Du, /* cpuss.dw0_tr_out[28] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT29   = 0x00000A1Eu, /* cpuss.dw0_tr_out[29] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT30   = 0x00000A1Fu, /* cpuss.dw0_tr_out[30] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT31   = 0x00000A20u, /* cpuss.dw0_tr_out[31] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT32   = 0x00000A21u, /* cpuss.dw0_tr_out[32] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT33   = 0x00000A22u, /* cpuss.dw0_tr_out[33] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT34   = 0x00000A23u, /* cpuss.dw0_tr_out[34] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT35   = 0x00000A24u, /* cpuss.dw0_tr_out[35] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT36   = 0x00000A25u, /* cpuss.dw0_tr_out[36] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT37   = 0x00000A26u, /* cpuss.dw0_tr_out[37] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT38   = 0x00000A27u, /* cpuss.dw0_tr_out[38] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT39   = 0x00000A28u, /* cpuss.dw0_tr_out[39] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT40   = 0x00000A29u, /* cpuss.dw0_tr_out[40] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT41   = 0x00000A2Au, /* cpuss.dw0_tr_out[41] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT42   = 0x00000A2Bu, /* cpuss.dw0_tr_out[42] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT43   = 0x00000A2Cu, /* cpuss.dw0_tr_out[43] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT44   = 0x00000A2Du, /* cpuss.dw0_tr_out[44] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT45   = 0x00000A2Eu, /* cpuss.dw0_tr_out[45] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT46   = 0x00000A2Fu, /* cpuss.dw0_tr_out[46] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT47   = 0x00000A30u, /* cpuss.dw0_tr_out[47] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT48   = 0x00000A31u, /* cpuss.dw0_tr_out[48] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT49   = 0x00000A32u, /* cpuss.dw0_tr_out[49] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT50   = 0x00000A33u, /* cpuss.dw0_tr_out[50] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT51   = 0x00000A34u, /* cpuss.dw0_tr_out[51] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT52   = 0x00000A35u, /* cpuss.dw0_tr_out[52] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT53   = 0x00000A36u, /* cpuss.dw0_tr_out[53] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT54   = 0x00000A37u, /* cpuss.dw0_tr_out[54] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT55   = 0x00000A38u, /* cpuss.dw0_tr_out[55] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT56   = 0x00000A39u, /* cpuss.dw0_tr_out[56] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT57   = 0x00000A3Au, /* cpuss.dw0_tr_out[57] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT58   = 0x00000A3Bu, /* cpuss.dw0_tr_out[58] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT59   = 0x00000A3Cu, /* cpuss.dw0_tr_out[59] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT60   = 0x00000A3Du, /* cpuss.dw0_tr_out[60] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT61   = 0x00000A3Eu, /* cpuss.dw0_tr_out[61] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT62   = 0x00000A3Fu, /* cpuss.dw0_tr_out[62] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT63   = 0x00000A40u, /* cpuss.dw0_tr_out[63] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT64   = 0x00000A41u, /* cpuss.dw0_tr_out[64] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT65   = 0x00000A42u, /* cpuss.dw0_tr_out[65] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT66   = 0x00000A43u, /* cpuss.dw0_tr_out[66] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT67   = 0x00000A44u, /* cpuss.dw0_tr_out[67] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT68   = 0x00000A45u, /* cpuss.dw0_tr_out[68] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT69   = 0x00000A46u, /* cpuss.dw0_tr_out[69] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT70   = 0x00000A47u, /* cpuss.dw0_tr_out[70] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT71   = 0x00000A48u, /* cpuss.dw0_tr_out[71] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT72   = 0x00000A49u, /* cpuss.dw0_tr_out[72] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT73   = 0x00000A4Au, /* cpuss.dw0_tr_out[73] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT74   = 0x00000A4Bu, /* cpuss.dw0_tr_out[74] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT75   = 0x00000A4Cu, /* cpuss.dw0_tr_out[75] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT76   = 0x00000A4Du, /* cpuss.dw0_tr_out[76] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT77   = 0x00000A4Eu, /* cpuss.dw0_tr_out[77] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT78   = 0x00000A4Fu, /* cpuss.dw0_tr_out[78] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT79   = 0x00000A50u, /* cpuss.dw0_tr_out[79] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT80   = 0x00000A51u, /* cpuss.dw0_tr_out[80] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT81   = 0x00000A52u, /* cpuss.dw0_tr_out[81] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT82   = 0x00000A53u, /* cpuss.dw0_tr_out[82] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT83   = 0x00000A54u, /* cpuss.dw0_tr_out[83] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT84   = 0x00000A55u, /* cpuss.dw0_tr_out[84] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT85   = 0x00000A56u, /* cpuss.dw0_tr_out[85] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT86   = 0x00000A57u, /* cpuss.dw0_tr_out[86] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT87   = 0x00000A58u, /* cpuss.dw0_tr_out[87] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT88   = 0x00000A59u, /* cpuss.dw0_tr_out[88] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT89   = 0x00000A5Au, /* cpuss.dw0_tr_out[89] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT90   = 0x00000A5Bu, /* cpuss.dw0_tr_out[90] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT91   = 0x00000A5Cu, /* cpuss.dw0_tr_out[91] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT92   = 0x00000A5Du, /* cpuss.dw0_tr_out[92] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT93   = 0x00000A5Eu, /* cpuss.dw0_tr_out[93] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT94   = 0x00000A5Fu, /* cpuss.dw0_tr_out[94] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT95   = 0x00000A60u, /* cpuss.dw0_tr_out[95] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT96   = 0x00000A61u, /* cpuss.dw0_tr_out[96] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT97   = 0x00000A62u, /* cpuss.dw0_tr_out[97] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT98   = 0x00000A63u, /* cpuss.dw0_tr_out[98] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT99   = 0x00000A64u, /* cpuss.dw0_tr_out[99] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT100  = 0x00000A65u, /* cpuss.dw0_tr_out[100] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT101  = 0x00000A66u, /* cpuss.dw0_tr_out[101] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT102  = 0x00000A67u, /* cpuss.dw0_tr_out[102] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT103  = 0x00000A68u, /* cpuss.dw0_tr_out[103] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT104  = 0x00000A69u, /* cpuss.dw0_tr_out[104] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT105  = 0x00000A6Au, /* cpuss.dw0_tr_out[105] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT106  = 0x00000A6Bu, /* cpuss.dw0_tr_out[106] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT107  = 0x00000A6Cu, /* cpuss.dw0_tr_out[107] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT108  = 0x00000A6Du, /* cpuss.dw0_tr_out[108] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT109  = 0x00000A6Eu, /* cpuss.dw0_tr_out[109] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT110  = 0x00000A6Fu, /* cpuss.dw0_tr_out[110] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT111  = 0x00000A70u, /* cpuss.dw0_tr_out[111] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT112  = 0x00000A71u, /* cpuss.dw0_tr_out[112] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT113  = 0x00000A72u, /* cpuss.dw0_tr_out[113] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT114  = 0x00000A73u, /* cpuss.dw0_tr_out[114] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT115  = 0x00000A74u, /* cpuss.dw0_tr_out[115] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT116  = 0x00000A75u, /* cpuss.dw0_tr_out[116] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT117  = 0x00000A76u, /* cpuss.dw0_tr_out[117] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT118  = 0x00000A77u, /* cpuss.dw0_tr_out[118] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT119  = 0x00000A78u, /* cpuss.dw0_tr_out[119] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT120  = 0x00000A79u, /* cpuss.dw0_tr_out[120] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT121  = 0x00000A7Au, /* cpuss.dw0_tr_out[121] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT122  = 0x00000A7Bu, /* cpuss.dw0_tr_out[122] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT123  = 0x00000A7Cu, /* cpuss.dw0_tr_out[123] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT124  = 0x00000A7Du, /* cpuss.dw0_tr_out[124] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT125  = 0x00000A7Eu, /* cpuss.dw0_tr_out[125] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT126  = 0x00000A7Fu, /* cpuss.dw0_tr_out[126] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT127  = 0x00000A80u, /* cpuss.dw0_tr_out[127] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT128  = 0x00000A81u, /* cpuss.dw0_tr_out[128] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT129  = 0x00000A82u, /* cpuss.dw0_tr_out[129] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT130  = 0x00000A83u, /* cpuss.dw0_tr_out[130] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT131  = 0x00000A84u, /* cpuss.dw0_tr_out[131] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT132  = 0x00000A85u, /* cpuss.dw0_tr_out[132] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT133  = 0x00000A86u, /* cpuss.dw0_tr_out[133] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT134  = 0x00000A87u, /* cpuss.dw0_tr_out[134] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT135  = 0x00000A88u, /* cpuss.dw0_tr_out[135] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT136  = 0x00000A89u, /* cpuss.dw0_tr_out[136] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT137  = 0x00000A8Au, /* cpuss.dw0_tr_out[137] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT138  = 0x00000A8Bu, /* cpuss.dw0_tr_out[138] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT139  = 0x00000A8Cu, /* cpuss.dw0_tr_out[139] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT140  = 0x00000A8Du, /* cpuss.dw0_tr_out[140] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT141  = 0x00000A8Eu, /* cpuss.dw0_tr_out[141] */
    TRIG_IN_MUX_10_PDMA0_TR_OUT142  = 0x00000A8Fu, /* cpuss.dw0_tr_out[142] */
    TRIG_IN_MUX_10_SCB_TX_TR_OUT0   = 0x00000A90u, /* scb[0].tr_tx_req */
    TRIG_IN_MUX_10_SCB_TX_TR_OUT1   = 0x00000A91u, /* scb[1].tr_tx_req */
    TRIG_IN_MUX_10_SCB_TX_TR_OUT2   = 0x00000A92u, /* scb[2].tr_tx_req */
    TRIG_IN_MUX_10_SCB_TX_TR_OUT3   = 0x00000A93u, /* scb[3].tr_tx_req */
    TRIG_IN_MUX_10_SCB_TX_TR_OUT4   = 0x00000A94u, /* scb[4].tr_tx_req */
    TRIG_IN_MUX_10_SCB_TX_TR_OUT5   = 0x00000A95u, /* scb[5].tr_tx_req */
    TRIG_IN_MUX_10_SCB_TX_TR_OUT6   = 0x00000A96u, /* scb[6].tr_tx_req */
    TRIG_IN_MUX_10_SCB_TX_TR_OUT7   = 0x00000A97u, /* scb[7].tr_tx_req */
    TRIG_IN_MUX_10_SCB_TX_TR_OUT8   = 0x00000A98u, /* scb[8].tr_tx_req */
    TRIG_IN_MUX_10_SCB_TX_TR_OUT9   = 0x00000A99u, /* scb[9].tr_tx_req */
    TRIG_IN_MUX_10_SCB_TX_TR_OUT10  = 0x00000A9Au, /* scb[10].tr_tx_req */
    TRIG_IN_MUX_10_SCB_RX_TR_OUT0   = 0x00000A9Bu, /* scb[0].tr_rx_req */
    TRIG_IN_MUX_10_SCB_RX_TR_OUT1   = 0x00000A9Cu, /* scb[1].tr_rx_req */
    TRIG_IN_MUX_10_SCB_RX_TR_OUT2   = 0x00000A9Du, /* scb[2].tr_rx_req */
    TRIG_IN_MUX_10_SCB_RX_TR_OUT3   = 0x00000A9Eu, /* scb[3].tr_rx_req */
    TRIG_IN_MUX_10_SCB_RX_TR_OUT4   = 0x00000A9Fu, /* scb[4].tr_rx_req */
    TRIG_IN_MUX_10_SCB_RX_TR_OUT5   = 0x00000AA0u, /* scb[5].tr_rx_req */
    TRIG_IN_MUX_10_SCB_RX_TR_OUT6   = 0x00000AA1u, /* scb[6].tr_rx_req */
    TRIG_IN_MUX_10_SCB_RX_TR_OUT7   = 0x00000AA2u, /* scb[7].tr_rx_req */
    TRIG_IN_MUX_10_SCB_RX_TR_OUT8   = 0x00000AA3u, /* scb[8].tr_rx_req */
    TRIG_IN_MUX_10_SCB_RX_TR_OUT9   = 0x00000AA4u, /* scb[9].tr_rx_req */
    TRIG_IN_MUX_10_SCB_RX_TR_OUT10  = 0x00000AA5u, /* scb[10].tr_rx_req */
    TRIG_IN_MUX_10_SCB_I2C_SCL_TR_OUT0 = 0x00000AA6u, /* scb[0].tr_i2c_scl_filtered */
    TRIG_IN_MUX_10_SCB_I2C_SCL_TR_OUT1 = 0x00000AA7u, /* scb[1].tr_i2c_scl_filtered */
    TRIG_IN_MUX_10_SCB_I2C_SCL_TR_OUT2 = 0x00000AA8u, /* scb[2].tr_i2c_scl_filtered */
    TRIG_IN_MUX_10_SCB_I2C_SCL_TR_OUT3 = 0x00000AA9u, /* scb[3].tr_i2c_scl_filtered */
    TRIG_IN_MUX_10_SCB_I2C_SCL_TR_OUT4 = 0x00000AAAu, /* scb[4].tr_i2c_scl_filtered */
    TRIG_IN_MUX_10_SCB_I2C_SCL_TR_OUT5 = 0x00000AABu, /* scb[5].tr_i2c_scl_filtered */
    TRIG_IN_MUX_10_SCB_I2C_SCL_TR_OUT6 = 0x00000AACu, /* scb[6].tr_i2c_scl_filtered */
    TRIG_IN_MUX_10_SCB_I2C_SCL_TR_OUT7 = 0x00000AADu, /* scb[7].tr_i2c_scl_filtered */
    TRIG_IN_MUX_10_SCB_I2C_SCL_TR_OUT8 = 0x00000AAEu, /* scb[8].tr_i2c_scl_filtered */
    TRIG_IN_MUX_10_SCB_I2C_SCL_TR_OUT9 = 0x00000AAFu, /* scb[9].tr_i2c_scl_filtered */
    TRIG_IN_MUX_10_SCB_I2C_SCL_TR_OUT10 = 0x00000AB0u, /* scb[10].tr_i2c_scl_filtered */
    TRIG_IN_MUX_10_CAN0_DBG_TR_OUT0 = 0x00000AB1u, /* canfd[0].tr_dbg_dma_req[0] */
    TRIG_IN_MUX_10_CAN0_DBG_TR_OUT1 = 0x00000AB2u, /* canfd[0].tr_dbg_dma_req[1] */
    TRIG_IN_MUX_10_CAN0_DBG_TR_OUT2 = 0x00000AB3u, /* canfd[0].tr_dbg_dma_req[2] */
    TRIG_IN_MUX_10_CAN0_DBG_TR_OUT3 = 0x00000AB4u, /* canfd[0].tr_dbg_dma_req[3] */
    TRIG_IN_MUX_10_CAN0_DBG_TR_OUT4 = 0x00000AB5u, /* canfd[0].tr_dbg_dma_req[4] */
    TRIG_IN_MUX_10_CAN0_FIFO0_TR_OUT0 = 0x00000AB6u, /* canfd[0].tr_fifo0[0] */
    TRIG_IN_MUX_10_CAN0_FIFO0_TR_OUT1 = 0x00000AB7u, /* canfd[0].tr_fifo0[1] */
    TRIG_IN_MUX_10_CAN0_FIFO0_TR_OUT2 = 0x00000AB8u, /* canfd[0].tr_fifo0[2] */
    TRIG_IN_MUX_10_CAN0_FIFO0_TR_OUT3 = 0x00000AB9u, /* canfd[0].tr_fifo0[3] */
    TRIG_IN_MUX_10_CAN0_FIFO0_TR_OUT4 = 0x00000ABAu, /* canfd[0].tr_fifo0[4] */
    TRIG_IN_MUX_10_CAN0_FIFO1_TR_OUT0 = 0x00000ABBu, /* canfd[0].tr_fifo1[0] */
    TRIG_IN_MUX_10_CAN0_FIFO1_TR_OUT1 = 0x00000ABCu, /* canfd[0].tr_fifo1[1] */
    TRIG_IN_MUX_10_CAN0_FIFO1_TR_OUT2 = 0x00000ABDu, /* canfd[0].tr_fifo1[2] */
    TRIG_IN_MUX_10_CAN0_FIFO1_TR_OUT3 = 0x00000ABEu, /* canfd[0].tr_fifo1[3] */
    TRIG_IN_MUX_10_CAN0_FIFO1_TR_OUT4 = 0x00000ABFu, /* canfd[0].tr_fifo1[4] */
    TRIG_IN_MUX_10_CAN0_TT_TR_OUT0  = 0x00000AC0u, /* canfd[0].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_10_CAN0_TT_TR_OUT1  = 0x00000AC1u, /* canfd[0].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_10_CAN0_TT_TR_OUT2  = 0x00000AC2u, /* canfd[0].tr_tmp_rtp_out[2] */
    TRIG_IN_MUX_10_CAN0_TT_TR_OUT3  = 0x00000AC3u, /* canfd[0].tr_tmp_rtp_out[3] */
    TRIG_IN_MUX_10_CAN0_TT_TR_OUT4  = 0x00000AC4u, /* canfd[0].tr_tmp_rtp_out[4] */
    TRIG_IN_MUX_10_CAN1_DBG_TR_OUT0 = 0x00000AC5u, /* canfd[1].tr_dbg_dma_req[0] */
    TRIG_IN_MUX_10_CAN1_DBG_TR_OUT1 = 0x00000AC6u, /* canfd[1].tr_dbg_dma_req[1] */
    TRIG_IN_MUX_10_CAN1_DBG_TR_OUT2 = 0x00000AC7u, /* canfd[1].tr_dbg_dma_req[2] */
    TRIG_IN_MUX_10_CAN1_DBG_TR_OUT3 = 0x00000AC8u, /* canfd[1].tr_dbg_dma_req[3] */
    TRIG_IN_MUX_10_CAN1_DBG_TR_OUT4 = 0x00000AC9u, /* canfd[1].tr_dbg_dma_req[4] */
    TRIG_IN_MUX_10_CAN1_FIFO0_TR_OUT0 = 0x00000ACAu, /* canfd[1].tr_fifo0[0] */
    TRIG_IN_MUX_10_CAN1_FIFO0_TR_OUT1 = 0x00000ACBu, /* canfd[1].tr_fifo0[1] */
    TRIG_IN_MUX_10_CAN1_FIFO0_TR_OUT2 = 0x00000ACCu, /* canfd[1].tr_fifo0[2] */
    TRIG_IN_MUX_10_CAN1_FIFO0_TR_OUT3 = 0x00000ACDu, /* canfd[1].tr_fifo0[3] */
    TRIG_IN_MUX_10_CAN1_FIFO0_TR_OUT4 = 0x00000ACEu, /* canfd[1].tr_fifo0[4] */
    TRIG_IN_MUX_10_CAN1_FIFO1_TR_OUT0 = 0x00000ACFu, /* canfd[1].tr_fifo1[0] */
    TRIG_IN_MUX_10_CAN1_FIFO1_TR_OUT1 = 0x00000AD0u, /* canfd[1].tr_fifo1[1] */
    TRIG_IN_MUX_10_CAN1_FIFO1_TR_OUT2 = 0x00000AD1u, /* canfd[1].tr_fifo1[2] */
    TRIG_IN_MUX_10_CAN1_FIFO1_TR_OUT3 = 0x00000AD2u, /* canfd[1].tr_fifo1[3] */
    TRIG_IN_MUX_10_CAN1_FIFO1_TR_OUT4 = 0x00000AD3u, /* canfd[1].tr_fifo1[4] */
    TRIG_IN_MUX_10_CAN1_TT_TR_OUT0  = 0x00000AD4u, /* canfd[1].tr_tmp_rtp_out[0] */
    TRIG_IN_MUX_10_CAN1_TT_TR_OUT1  = 0x00000AD5u, /* canfd[1].tr_tmp_rtp_out[1] */
    TRIG_IN_MUX_10_CAN1_TT_TR_OUT2  = 0x00000AD6u, /* canfd[1].tr_tmp_rtp_out[2] */
    TRIG_IN_MUX_10_CAN1_TT_TR_OUT3  = 0x00000AD7u, /* canfd[1].tr_tmp_rtp_out[3] */
    TRIG_IN_MUX_10_CAN1_TT_TR_OUT4  = 0x00000AD8u, /* canfd[1].tr_tmp_rtp_out[4] */
    TRIG_IN_MUX_10_CTI_TR_OUT0      = 0x00000AD9u, /* cpuss.cti_tr_out[0] */
    TRIG_IN_MUX_10_CTI_TR_OUT1      = 0x00000ADAu, /* cpuss.cti_tr_out[1] */
    TRIG_IN_MUX_10_FAULT_TR_OU0     = 0x00000ADBu, /* cpuss.tr_fault[0] */
    TRIG_IN_MUX_10_FAULT_TR_OU1     = 0x00000ADCu, /* cpuss.tr_fault[1] */
    TRIG_IN_MUX_10_FAULT_TR_OU2     = 0x00000ADDu, /* cpuss.tr_fault[2] */
    TRIG_IN_MUX_10_FAULT_TR_OU3     = 0x00000ADEu, /* cpuss.tr_fault[3] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT0   = 0x00000ADFu, /* evtgen[0].tr_out[0] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT1   = 0x00000AE0u, /* evtgen[0].tr_out[1] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT2   = 0x00000AE1u, /* evtgen[0].tr_out[2] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT3   = 0x00000AE2u, /* evtgen[0].tr_out[3] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT4   = 0x00000AE3u, /* evtgen[0].tr_out[4] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT5   = 0x00000AE4u, /* evtgen[0].tr_out[5] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT6   = 0x00000AE5u, /* evtgen[0].tr_out[6] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT7   = 0x00000AE6u, /* evtgen[0].tr_out[7] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT8   = 0x00000AE7u, /* evtgen[0].tr_out[8] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT9   = 0x00000AE8u, /* evtgen[0].tr_out[9] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT10  = 0x00000AE9u, /* evtgen[0].tr_out[10] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT11  = 0x00000AEAu, /* evtgen[0].tr_out[11] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT12  = 0x00000AEBu, /* evtgen[0].tr_out[12] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT13  = 0x00000AECu, /* evtgen[0].tr_out[13] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT14  = 0x00000AEDu, /* evtgen[0].tr_out[14] */
    TRIG_IN_MUX_10_EVTGEN_TR_OUT15  = 0x00000AEEu /* evtgen[0].tr_out[15] */
} en_trig_input_debug_reduction_1_t;

/* Trigger Input Group 11 - Makes all possible triggers visible as I/O signals for debug purposes, or to build external circuitry */
typedef enum
{
    TRIG_IN_MUX_11_TCPWM1_32_TR_OUT00 = 0x00000B01u, /* tcpwm[1].tr_out0[512] */
    TRIG_IN_MUX_11_TCPWM1_32_TR_OUT01 = 0x00000B02u, /* tcpwm[1].tr_out0[513] */
    TRIG_IN_MUX_11_TCPWM1_32_TR_OUT02 = 0x00000B03u, /* tcpwm[1].tr_out0[514] */
    TRIG_IN_MUX_11_TCPWM1_32_TR_OUT03 = 0x00000B04u, /* tcpwm[1].tr_out0[515] */
    TRIG_IN_MUX_11_TCPWM1_32_TR_OUT04 = 0x00000B05u, /* tcpwm[1].tr_out0[516] */
    TRIG_IN_MUX_11_TCPWM1_32_TR_OUT05 = 0x00000B06u, /* tcpwm[1].tr_out0[517] */
    TRIG_IN_MUX_11_TCPWM1_32_TR_OUT06 = 0x00000B07u, /* tcpwm[1].tr_out0[518] */
    TRIG_IN_MUX_11_TCPWM1_32_TR_OUT07 = 0x00000B08u, /* tcpwm[1].tr_out0[519] */
    TRIG_IN_MUX_11_TCPWM1_32_TR_OUT08 = 0x00000B09u, /* tcpwm[1].tr_out0[520] */
    TRIG_IN_MUX_11_TCPWM1_32_TR_OUT09 = 0x00000B0Au, /* tcpwm[1].tr_out0[521] */
    TRIG_IN_MUX_11_TCPWM1_32_TR_OUT010 = 0x00000B0Bu, /* tcpwm[1].tr_out0[522] */
    TRIG_IN_MUX_11_TCPWM1_32_TR_OUT011 = 0x00000B0Cu, /* tcpwm[1].tr_out0[523] */
    TRIG_IN_MUX_11_TCPWM1_32_TR_OUT012 = 0x00000B0Du, /* tcpwm[1].tr_out0[524] */
    TRIG_IN_MUX_11_TCPWM0_32_TR_OUT00 = 0x00000B0Eu, /* tcpwm[0].tr_out0[512] */
    TRIG_IN_MUX_11_TCPWM0_32_TR_OUT01 = 0x00000B0Fu, /* tcpwm[0].tr_out0[513] */
    TRIG_IN_MUX_11_TCPWM0_32_TR_OUT02 = 0x00000B10u, /* tcpwm[0].tr_out0[514] */
    TRIG_IN_MUX_11_TCPWM1_16M_TR_OUT00 = 0x00000B11u, /* tcpwm[1].tr_out0[256] */
    TRIG_IN_MUX_11_TCPWM1_16M_TR_OUT01 = 0x00000B12u, /* tcpwm[1].tr_out0[257] */
    TRIG_IN_MUX_11_TCPWM1_16M_TR_OUT02 = 0x00000B13u, /* tcpwm[1].tr_out0[258] */
    TRIG_IN_MUX_11_TCPWM1_16M_TR_OUT03 = 0x00000B14u, /* tcpwm[1].tr_out0[259] */
    TRIG_IN_MUX_11_TCPWM1_16M_TR_OUT04 = 0x00000B15u, /* tcpwm[1].tr_out0[260] */
    TRIG_IN_MUX_11_TCPWM1_16M_TR_OUT05 = 0x00000B16u, /* tcpwm[1].tr_out0[261] */
    TRIG_IN_MUX_11_TCPWM1_16M_TR_OUT06 = 0x00000B17u, /* tcpwm[1].tr_out0[262] */
    TRIG_IN_MUX_11_TCPWM1_16M_TR_OUT07 = 0x00000B18u, /* tcpwm[1].tr_out0[263] */
    TRIG_IN_MUX_11_TCPWM1_16M_TR_OUT08 = 0x00000B19u, /* tcpwm[1].tr_out0[264] */
    TRIG_IN_MUX_11_TCPWM1_16M_TR_OUT09 = 0x00000B1Au, /* tcpwm[1].tr_out0[265] */
    TRIG_IN_MUX_11_TCPWM1_16M_TR_OUT010 = 0x00000B1Bu, /* tcpwm[1].tr_out0[266] */
    TRIG_IN_MUX_11_TCPWM1_16M_TR_OUT011 = 0x00000B1Cu, /* tcpwm[1].tr_out0[267] */
    TRIG_IN_MUX_11_TCPWM0_16M_TR_OUT00 = 0x00000B1Du, /* tcpwm[0].tr_out0[256] */
    TRIG_IN_MUX_11_TCPWM0_16M_TR_OUT01 = 0x00000B1Eu, /* tcpwm[0].tr_out0[257] */
    TRIG_IN_MUX_11_TCPWM0_16M_TR_OUT02 = 0x00000B1Fu, /* tcpwm[0].tr_out0[258] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT00 = 0x00000B20u, /* tcpwm[1].tr_out0[0] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT01 = 0x00000B21u, /* tcpwm[1].tr_out0[1] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT02 = 0x00000B22u, /* tcpwm[1].tr_out0[2] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT03 = 0x00000B23u, /* tcpwm[1].tr_out0[3] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT04 = 0x00000B24u, /* tcpwm[1].tr_out0[4] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT05 = 0x00000B25u, /* tcpwm[1].tr_out0[5] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT06 = 0x00000B26u, /* tcpwm[1].tr_out0[6] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT07 = 0x00000B27u, /* tcpwm[1].tr_out0[7] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT08 = 0x00000B28u, /* tcpwm[1].tr_out0[8] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT09 = 0x00000B29u, /* tcpwm[1].tr_out0[9] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT010 = 0x00000B2Au, /* tcpwm[1].tr_out0[10] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT011 = 0x00000B2Bu, /* tcpwm[1].tr_out0[11] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT012 = 0x00000B2Cu, /* tcpwm[1].tr_out0[12] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT013 = 0x00000B2Du, /* tcpwm[1].tr_out0[13] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT014 = 0x00000B2Eu, /* tcpwm[1].tr_out0[14] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT015 = 0x00000B2Fu, /* tcpwm[1].tr_out0[15] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT016 = 0x00000B30u, /* tcpwm[1].tr_out0[16] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT017 = 0x00000B31u, /* tcpwm[1].tr_out0[17] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT018 = 0x00000B32u, /* tcpwm[1].tr_out0[18] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT019 = 0x00000B33u, /* tcpwm[1].tr_out0[19] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT020 = 0x00000B34u, /* tcpwm[1].tr_out0[20] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT021 = 0x00000B35u, /* tcpwm[1].tr_out0[21] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT022 = 0x00000B36u, /* tcpwm[1].tr_out0[22] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT023 = 0x00000B37u, /* tcpwm[1].tr_out0[23] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT024 = 0x00000B38u, /* tcpwm[1].tr_out0[24] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT025 = 0x00000B39u, /* tcpwm[1].tr_out0[25] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT026 = 0x00000B3Au, /* tcpwm[1].tr_out0[26] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT027 = 0x00000B3Bu, /* tcpwm[1].tr_out0[27] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT028 = 0x00000B3Cu, /* tcpwm[1].tr_out0[28] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT029 = 0x00000B3Du, /* tcpwm[1].tr_out0[29] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT030 = 0x00000B3Eu, /* tcpwm[1].tr_out0[30] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT031 = 0x00000B3Fu, /* tcpwm[1].tr_out0[31] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT032 = 0x00000B40u, /* tcpwm[1].tr_out0[32] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT033 = 0x00000B41u, /* tcpwm[1].tr_out0[33] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT034 = 0x00000B42u, /* tcpwm[1].tr_out0[34] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT035 = 0x00000B43u, /* tcpwm[1].tr_out0[35] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT036 = 0x00000B44u, /* tcpwm[1].tr_out0[36] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT037 = 0x00000B45u, /* tcpwm[1].tr_out0[37] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT038 = 0x00000B46u, /* tcpwm[1].tr_out0[38] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT039 = 0x00000B47u, /* tcpwm[1].tr_out0[39] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT040 = 0x00000B48u, /* tcpwm[1].tr_out0[40] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT041 = 0x00000B49u, /* tcpwm[1].tr_out0[41] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT042 = 0x00000B4Au, /* tcpwm[1].tr_out0[42] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT043 = 0x00000B4Bu, /* tcpwm[1].tr_out0[43] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT044 = 0x00000B4Cu, /* tcpwm[1].tr_out0[44] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT045 = 0x00000B4Du, /* tcpwm[1].tr_out0[45] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT046 = 0x00000B4Eu, /* tcpwm[1].tr_out0[46] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT047 = 0x00000B4Fu, /* tcpwm[1].tr_out0[47] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT048 = 0x00000B50u, /* tcpwm[1].tr_out0[48] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT049 = 0x00000B51u, /* tcpwm[1].tr_out0[49] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT050 = 0x00000B52u, /* tcpwm[1].tr_out0[50] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT051 = 0x00000B53u, /* tcpwm[1].tr_out0[51] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT052 = 0x00000B54u, /* tcpwm[1].tr_out0[52] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT053 = 0x00000B55u, /* tcpwm[1].tr_out0[53] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT054 = 0x00000B56u, /* tcpwm[1].tr_out0[54] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT055 = 0x00000B57u, /* tcpwm[1].tr_out0[55] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT056 = 0x00000B58u, /* tcpwm[1].tr_out0[56] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT057 = 0x00000B59u, /* tcpwm[1].tr_out0[57] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT058 = 0x00000B5Au, /* tcpwm[1].tr_out0[58] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT059 = 0x00000B5Bu, /* tcpwm[1].tr_out0[59] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT060 = 0x00000B5Cu, /* tcpwm[1].tr_out0[60] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT061 = 0x00000B5Du, /* tcpwm[1].tr_out0[61] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT062 = 0x00000B5Eu, /* tcpwm[1].tr_out0[62] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT063 = 0x00000B5Fu, /* tcpwm[1].tr_out0[63] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT064 = 0x00000B60u, /* tcpwm[1].tr_out0[64] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT065 = 0x00000B61u, /* tcpwm[1].tr_out0[65] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT066 = 0x00000B62u, /* tcpwm[1].tr_out0[66] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT067 = 0x00000B63u, /* tcpwm[1].tr_out0[67] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT068 = 0x00000B64u, /* tcpwm[1].tr_out0[68] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT069 = 0x00000B65u, /* tcpwm[1].tr_out0[69] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT070 = 0x00000B66u, /* tcpwm[1].tr_out0[70] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT071 = 0x00000B67u, /* tcpwm[1].tr_out0[71] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT072 = 0x00000B68u, /* tcpwm[1].tr_out0[72] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT073 = 0x00000B69u, /* tcpwm[1].tr_out0[73] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT074 = 0x00000B6Au, /* tcpwm[1].tr_out0[74] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT075 = 0x00000B6Bu, /* tcpwm[1].tr_out0[75] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT076 = 0x00000B6Cu, /* tcpwm[1].tr_out0[76] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT077 = 0x00000B6Du, /* tcpwm[1].tr_out0[77] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT078 = 0x00000B6Eu, /* tcpwm[1].tr_out0[78] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT079 = 0x00000B6Fu, /* tcpwm[1].tr_out0[79] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT080 = 0x00000B70u, /* tcpwm[1].tr_out0[80] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT081 = 0x00000B71u, /* tcpwm[1].tr_out0[81] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT082 = 0x00000B72u, /* tcpwm[1].tr_out0[82] */
    TRIG_IN_MUX_11_TCPWM1_16_TR_OUT083 = 0x00000B73u, /* tcpwm[1].tr_out0[83] */
    TRIG_IN_MUX_11_TCPWM0_16_TR_OUT00 = 0x00000B74u, /* tcpwm[0].tr_out0[0] */
    TRIG_IN_MUX_11_TCPWM0_16_TR_OUT01 = 0x00000B75u, /* tcpwm[0].tr_out0[1] */
    TRIG_IN_MUX_11_TCPWM0_16_TR_OUT02 = 0x00000B76u, /* tcpwm[0].tr_out0[2] */
    TRIG_IN_MUX_11_SMIF_TX_TR_OUT   = 0x00000B77u, /* smif[0].tr_tx_req */
    TRIG_IN_MUX_11_SMIF_RX_TR_OUT   = 0x00000B78u, /* smif[0].tr_rx_req */
    TRIG_IN_MUX_11_FLEXRAY_TT_TR_OUT = 0x00000B79u, /* flexray[0].tr_tint0_out */
    TRIG_IN_MUX_11_FLEXRAY_IBUF_TR_OUT = 0x00000B7Au, /* flexray[0].tr_ibf_out */
    TRIG_IN_MUX_11_FLEXRAY_OBUF_TR_OUT = 0x00000B7Bu, /* flexray[0].tr_obf_out */
    TRIG_IN_MUX_11_I2S0_TX_TR_OUT   = 0x00000B7Cu, /* audioss[0].tr_i2s_tx_req */
    TRIG_IN_MUX_11_I2S0_RX_TR_OUT   = 0x00000B7Du, /* audioss[0].tr_i2s_rx_req */
    TRIG_IN_MUX_11_I2S1_TX_TR_OUT   = 0x00000B7Eu, /* audioss[1].tr_i2s_tx_req */
    TRIG_IN_MUX_11_I2S1_RX_TR_OUT   = 0x00000B7Fu, /* audioss[1].tr_i2s_rx_req */
    TRIG_IN_MUX_11_I2S2_TX_TR_OUT   = 0x00000B80u, /* audioss[2].tr_i2s_tx_req */
    TRIG_IN_MUX_11_I2S2_RX_TR_OUT   = 0x00000B81u, /* audioss[2].tr_i2s_rx_req */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT0  = 0x00000B82u, /* peri.tr_io_input[0] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT1  = 0x00000B83u, /* peri.tr_io_input[1] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT2  = 0x00000B84u, /* peri.tr_io_input[2] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT3  = 0x00000B85u, /* peri.tr_io_input[3] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT4  = 0x00000B86u, /* peri.tr_io_input[4] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT5  = 0x00000B87u, /* peri.tr_io_input[5] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT6  = 0x00000B88u, /* peri.tr_io_input[6] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT7  = 0x00000B89u, /* peri.tr_io_input[7] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT8  = 0x00000B8Au, /* peri.tr_io_input[8] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT9  = 0x00000B8Bu, /* peri.tr_io_input[9] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT10 = 0x00000B8Cu, /* peri.tr_io_input[10] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT11 = 0x00000B8Du, /* peri.tr_io_input[11] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT12 = 0x00000B8Eu, /* peri.tr_io_input[12] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT13 = 0x00000B8Fu, /* peri.tr_io_input[13] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT14 = 0x00000B90u, /* peri.tr_io_input[14] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT15 = 0x00000B91u, /* peri.tr_io_input[15] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT16 = 0x00000B92u, /* peri.tr_io_input[16] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT17 = 0x00000B93u, /* peri.tr_io_input[17] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT18 = 0x00000B94u, /* peri.tr_io_input[18] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT19 = 0x00000B95u, /* peri.tr_io_input[19] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT20 = 0x00000B96u, /* peri.tr_io_input[20] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT21 = 0x00000B97u, /* peri.tr_io_input[21] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT22 = 0x00000B98u, /* peri.tr_io_input[22] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT23 = 0x00000B99u, /* peri.tr_io_input[23] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT24 = 0x00000B9Au, /* peri.tr_io_input[24] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT25 = 0x00000B9Bu, /* peri.tr_io_input[25] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT26 = 0x00000B9Cu, /* peri.tr_io_input[26] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT27 = 0x00000B9Du, /* peri.tr_io_input[27] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT28 = 0x00000B9Eu, /* peri.tr_io_input[28] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT29 = 0x00000B9Fu, /* peri.tr_io_input[29] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT30 = 0x00000BA0u, /* peri.tr_io_input[30] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT31 = 0x00000BA1u, /* peri.tr_io_input[31] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT32 = 0x00000BA2u, /* peri.tr_io_input[32] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT33 = 0x00000BA3u, /* peri.tr_io_input[33] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT34 = 0x00000BA4u, /* peri.tr_io_input[34] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT35 = 0x00000BA5u, /* peri.tr_io_input[35] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT36 = 0x00000BA6u, /* peri.tr_io_input[36] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT37 = 0x00000BA7u, /* peri.tr_io_input[37] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT38 = 0x00000BA8u, /* peri.tr_io_input[38] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT39 = 0x00000BA9u, /* peri.tr_io_input[39] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT40 = 0x00000BAAu, /* peri.tr_io_input[40] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT41 = 0x00000BABu, /* peri.tr_io_input[41] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT42 = 0x00000BACu, /* peri.tr_io_input[42] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT43 = 0x00000BADu, /* peri.tr_io_input[43] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT44 = 0x00000BAEu, /* peri.tr_io_input[44] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT45 = 0x00000BAFu, /* peri.tr_io_input[45] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT46 = 0x00000BB0u, /* peri.tr_io_input[46] */
    TRIG_IN_MUX_11_HSIOM_IO_INPUT47 = 0x00000BB1u /* peri.tr_io_input[47] */
} en_trig_input_debug_reduction_2_t;

/* Trigger Input Group 12 - Makes all possible triggers visible as I/O signals for debug purposes, or to build external circuitry */
typedef enum
{
    TRIG_IN_MUX_12_PDMA1_TR_OUT0    = 0x00000C01u, /* cpuss.dw1_tr_out[0] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT1    = 0x00000C02u, /* cpuss.dw1_tr_out[1] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT2    = 0x00000C03u, /* cpuss.dw1_tr_out[2] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT3    = 0x00000C04u, /* cpuss.dw1_tr_out[3] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT4    = 0x00000C05u, /* cpuss.dw1_tr_out[4] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT5    = 0x00000C06u, /* cpuss.dw1_tr_out[5] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT6    = 0x00000C07u, /* cpuss.dw1_tr_out[6] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT7    = 0x00000C08u, /* cpuss.dw1_tr_out[7] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT8    = 0x00000C09u, /* cpuss.dw1_tr_out[8] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT9    = 0x00000C0Au, /* cpuss.dw1_tr_out[9] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT10   = 0x00000C0Bu, /* cpuss.dw1_tr_out[10] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT11   = 0x00000C0Cu, /* cpuss.dw1_tr_out[11] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT12   = 0x00000C0Du, /* cpuss.dw1_tr_out[12] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT13   = 0x00000C0Eu, /* cpuss.dw1_tr_out[13] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT14   = 0x00000C0Fu, /* cpuss.dw1_tr_out[14] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT15   = 0x00000C10u, /* cpuss.dw1_tr_out[15] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT16   = 0x00000C11u, /* cpuss.dw1_tr_out[16] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT17   = 0x00000C12u, /* cpuss.dw1_tr_out[17] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT18   = 0x00000C13u, /* cpuss.dw1_tr_out[18] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT19   = 0x00000C14u, /* cpuss.dw1_tr_out[19] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT20   = 0x00000C15u, /* cpuss.dw1_tr_out[20] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT21   = 0x00000C16u, /* cpuss.dw1_tr_out[21] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT22   = 0x00000C17u, /* cpuss.dw1_tr_out[22] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT23   = 0x00000C18u, /* cpuss.dw1_tr_out[23] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT24   = 0x00000C19u, /* cpuss.dw1_tr_out[24] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT25   = 0x00000C1Au, /* cpuss.dw1_tr_out[25] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT26   = 0x00000C1Bu, /* cpuss.dw1_tr_out[26] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT27   = 0x00000C1Cu, /* cpuss.dw1_tr_out[27] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT28   = 0x00000C1Du, /* cpuss.dw1_tr_out[28] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT29   = 0x00000C1Eu, /* cpuss.dw1_tr_out[29] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT30   = 0x00000C1Fu, /* cpuss.dw1_tr_out[30] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT31   = 0x00000C20u, /* cpuss.dw1_tr_out[31] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT32   = 0x00000C21u, /* cpuss.dw1_tr_out[32] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT33   = 0x00000C22u, /* cpuss.dw1_tr_out[33] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT34   = 0x00000C23u, /* cpuss.dw1_tr_out[34] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT35   = 0x00000C24u, /* cpuss.dw1_tr_out[35] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT36   = 0x00000C25u, /* cpuss.dw1_tr_out[36] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT37   = 0x00000C26u, /* cpuss.dw1_tr_out[37] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT38   = 0x00000C27u, /* cpuss.dw1_tr_out[38] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT39   = 0x00000C28u, /* cpuss.dw1_tr_out[39] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT40   = 0x00000C29u, /* cpuss.dw1_tr_out[40] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT41   = 0x00000C2Au, /* cpuss.dw1_tr_out[41] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT42   = 0x00000C2Bu, /* cpuss.dw1_tr_out[42] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT43   = 0x00000C2Cu, /* cpuss.dw1_tr_out[43] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT44   = 0x00000C2Du, /* cpuss.dw1_tr_out[44] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT45   = 0x00000C2Eu, /* cpuss.dw1_tr_out[45] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT46   = 0x00000C2Fu, /* cpuss.dw1_tr_out[46] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT47   = 0x00000C30u, /* cpuss.dw1_tr_out[47] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT48   = 0x00000C31u, /* cpuss.dw1_tr_out[48] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT49   = 0x00000C32u, /* cpuss.dw1_tr_out[49] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT50   = 0x00000C33u, /* cpuss.dw1_tr_out[50] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT51   = 0x00000C34u, /* cpuss.dw1_tr_out[51] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT52   = 0x00000C35u, /* cpuss.dw1_tr_out[52] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT53   = 0x00000C36u, /* cpuss.dw1_tr_out[53] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT54   = 0x00000C37u, /* cpuss.dw1_tr_out[54] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT55   = 0x00000C38u, /* cpuss.dw1_tr_out[55] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT56   = 0x00000C39u, /* cpuss.dw1_tr_out[56] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT57   = 0x00000C3Au, /* cpuss.dw1_tr_out[57] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT58   = 0x00000C3Bu, /* cpuss.dw1_tr_out[58] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT59   = 0x00000C3Cu, /* cpuss.dw1_tr_out[59] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT60   = 0x00000C3Du, /* cpuss.dw1_tr_out[60] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT61   = 0x00000C3Eu, /* cpuss.dw1_tr_out[61] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT62   = 0x00000C3Fu, /* cpuss.dw1_tr_out[62] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT63   = 0x00000C40u, /* cpuss.dw1_tr_out[63] */
    TRIG_IN_MUX_12_PDMA1_TR_OUT64   = 0x00000C41u, /* cpuss.dw1_tr_out[64] */
    TRIG_IN_MUX_12_MDMA_TR_OUT0     = 0x00000C42u, /* cpuss.dmac_tr_out[0] */
    TRIG_IN_MUX_12_MDMA_TR_OUT1     = 0x00000C43u, /* cpuss.dmac_tr_out[1] */
    TRIG_IN_MUX_12_MDMA_TR_OUT2     = 0x00000C44u, /* cpuss.dmac_tr_out[2] */
    TRIG_IN_MUX_12_MDMA_TR_OUT3     = 0x00000C45u, /* cpuss.dmac_tr_out[3] */
    TRIG_IN_MUX_12_MDMA_TR_OUT4     = 0x00000C46u, /* cpuss.dmac_tr_out[4] */
    TRIG_IN_MUX_12_MDMA_TR_OUT5     = 0x00000C47u, /* cpuss.dmac_tr_out[5] */
    TRIG_IN_MUX_12_MDMA_TR_OUT6     = 0x00000C48u, /* cpuss.dmac_tr_out[6] */
    TRIG_IN_MUX_12_MDMA_TR_OUT7     = 0x00000C49u, /* cpuss.dmac_tr_out[7] */
    TRIG_IN_MUX_12_TCPWM0_16_TR_OUT10 = 0x00000C4Au, /* tcpwm[0].tr_out1[0] */
    TRIG_IN_MUX_12_TCPWM0_16_TR_OUT11 = 0x00000C4Bu, /* tcpwm[0].tr_out1[1] */
    TRIG_IN_MUX_12_TCPWM0_16_TR_OUT12 = 0x00000C4Cu, /* tcpwm[0].tr_out1[2] */
    TRIG_IN_MUX_12_TCPWM0_16M_TR_OUT10 = 0x00000C4Du, /* tcpwm[0].tr_out1[256] */
    TRIG_IN_MUX_12_TCPWM0_16M_TR_OUT11 = 0x00000C4Eu, /* tcpwm[0].tr_out1[257] */
    TRIG_IN_MUX_12_TCPWM0_16M_TR_OUT12 = 0x00000C4Fu, /* tcpwm[0].tr_out1[258] */
    TRIG_IN_MUX_12_TCPWM0_32_TR_OUT10 = 0x00000C50u, /* tcpwm[0].tr_out1[512] */
    TRIG_IN_MUX_12_TCPWM0_32_TR_OUT11 = 0x00000C51u, /* tcpwm[0].tr_out1[513] */
    TRIG_IN_MUX_12_TCPWM0_32_TR_OUT12 = 0x00000C52u, /* tcpwm[0].tr_out1[514] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT10 = 0x00000C53u, /* tcpwm[1].tr_out1[0] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT11 = 0x00000C54u, /* tcpwm[1].tr_out1[1] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT12 = 0x00000C55u, /* tcpwm[1].tr_out1[2] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT13 = 0x00000C56u, /* tcpwm[1].tr_out1[3] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT14 = 0x00000C57u, /* tcpwm[1].tr_out1[4] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT15 = 0x00000C58u, /* tcpwm[1].tr_out1[5] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT16 = 0x00000C59u, /* tcpwm[1].tr_out1[6] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT17 = 0x00000C5Au, /* tcpwm[1].tr_out1[7] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT18 = 0x00000C5Bu, /* tcpwm[1].tr_out1[8] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT19 = 0x00000C5Cu, /* tcpwm[1].tr_out1[9] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT110 = 0x00000C5Du, /* tcpwm[1].tr_out1[10] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT111 = 0x00000C5Eu, /* tcpwm[1].tr_out1[11] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT112 = 0x00000C5Fu, /* tcpwm[1].tr_out1[12] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT113 = 0x00000C60u, /* tcpwm[1].tr_out1[13] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT114 = 0x00000C61u, /* tcpwm[1].tr_out1[14] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT115 = 0x00000C62u, /* tcpwm[1].tr_out1[15] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT116 = 0x00000C63u, /* tcpwm[1].tr_out1[16] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT117 = 0x00000C64u, /* tcpwm[1].tr_out1[17] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT118 = 0x00000C65u, /* tcpwm[1].tr_out1[18] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT119 = 0x00000C66u, /* tcpwm[1].tr_out1[19] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT120 = 0x00000C67u, /* tcpwm[1].tr_out1[20] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT121 = 0x00000C68u, /* tcpwm[1].tr_out1[21] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT122 = 0x00000C69u, /* tcpwm[1].tr_out1[22] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT123 = 0x00000C6Au, /* tcpwm[1].tr_out1[23] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT124 = 0x00000C6Bu, /* tcpwm[1].tr_out1[24] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT125 = 0x00000C6Cu, /* tcpwm[1].tr_out1[25] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT126 = 0x00000C6Du, /* tcpwm[1].tr_out1[26] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT127 = 0x00000C6Eu, /* tcpwm[1].tr_out1[27] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT128 = 0x00000C6Fu, /* tcpwm[1].tr_out1[28] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT129 = 0x00000C70u, /* tcpwm[1].tr_out1[29] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT130 = 0x00000C71u, /* tcpwm[1].tr_out1[30] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT131 = 0x00000C72u, /* tcpwm[1].tr_out1[31] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT132 = 0x00000C73u, /* tcpwm[1].tr_out1[32] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT133 = 0x00000C74u, /* tcpwm[1].tr_out1[33] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT134 = 0x00000C75u, /* tcpwm[1].tr_out1[34] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT135 = 0x00000C76u, /* tcpwm[1].tr_out1[35] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT136 = 0x00000C77u, /* tcpwm[1].tr_out1[36] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT137 = 0x00000C78u, /* tcpwm[1].tr_out1[37] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT138 = 0x00000C79u, /* tcpwm[1].tr_out1[38] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT139 = 0x00000C7Au, /* tcpwm[1].tr_out1[39] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT140 = 0x00000C7Bu, /* tcpwm[1].tr_out1[40] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT141 = 0x00000C7Cu, /* tcpwm[1].tr_out1[41] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT142 = 0x00000C7Du, /* tcpwm[1].tr_out1[42] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT143 = 0x00000C7Eu, /* tcpwm[1].tr_out1[43] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT144 = 0x00000C7Fu, /* tcpwm[1].tr_out1[44] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT145 = 0x00000C80u, /* tcpwm[1].tr_out1[45] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT146 = 0x00000C81u, /* tcpwm[1].tr_out1[46] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT147 = 0x00000C82u, /* tcpwm[1].tr_out1[47] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT148 = 0x00000C83u, /* tcpwm[1].tr_out1[48] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT149 = 0x00000C84u, /* tcpwm[1].tr_out1[49] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT150 = 0x00000C85u, /* tcpwm[1].tr_out1[50] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT151 = 0x00000C86u, /* tcpwm[1].tr_out1[51] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT152 = 0x00000C87u, /* tcpwm[1].tr_out1[52] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT153 = 0x00000C88u, /* tcpwm[1].tr_out1[53] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT154 = 0x00000C89u, /* tcpwm[1].tr_out1[54] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT155 = 0x00000C8Au, /* tcpwm[1].tr_out1[55] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT156 = 0x00000C8Bu, /* tcpwm[1].tr_out1[56] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT157 = 0x00000C8Cu, /* tcpwm[1].tr_out1[57] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT158 = 0x00000C8Du, /* tcpwm[1].tr_out1[58] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT159 = 0x00000C8Eu, /* tcpwm[1].tr_out1[59] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT160 = 0x00000C8Fu, /* tcpwm[1].tr_out1[60] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT161 = 0x00000C90u, /* tcpwm[1].tr_out1[61] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT162 = 0x00000C91u, /* tcpwm[1].tr_out1[62] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT163 = 0x00000C92u, /* tcpwm[1].tr_out1[63] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT164 = 0x00000C93u, /* tcpwm[1].tr_out1[64] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT165 = 0x00000C94u, /* tcpwm[1].tr_out1[65] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT166 = 0x00000C95u, /* tcpwm[1].tr_out1[66] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT167 = 0x00000C96u, /* tcpwm[1].tr_out1[67] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT168 = 0x00000C97u, /* tcpwm[1].tr_out1[68] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT169 = 0x00000C98u, /* tcpwm[1].tr_out1[69] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT170 = 0x00000C99u, /* tcpwm[1].tr_out1[70] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT171 = 0x00000C9Au, /* tcpwm[1].tr_out1[71] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT172 = 0x00000C9Bu, /* tcpwm[1].tr_out1[72] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT173 = 0x00000C9Cu, /* tcpwm[1].tr_out1[73] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT174 = 0x00000C9Du, /* tcpwm[1].tr_out1[74] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT175 = 0x00000C9Eu, /* tcpwm[1].tr_out1[75] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT176 = 0x00000C9Fu, /* tcpwm[1].tr_out1[76] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT177 = 0x00000CA0u, /* tcpwm[1].tr_out1[77] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT178 = 0x00000CA1u, /* tcpwm[1].tr_out1[78] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT179 = 0x00000CA2u, /* tcpwm[1].tr_out1[79] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT180 = 0x00000CA3u, /* tcpwm[1].tr_out1[80] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT181 = 0x00000CA4u, /* tcpwm[1].tr_out1[81] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT182 = 0x00000CA5u, /* tcpwm[1].tr_out1[82] */
    TRIG_IN_MUX_12_TCPWM1_16_TR_OUT183 = 0x00000CA6u, /* tcpwm[1].tr_out1[83] */
    TRIG_IN_MUX_12_TCPWM1_16M_TR_OUT10 = 0x00000CA7u, /* tcpwm[1].tr_out1[256] */
    TRIG_IN_MUX_12_TCPWM1_16M_TR_OUT11 = 0x00000CA8u, /* tcpwm[1].tr_out1[257] */
    TRIG_IN_MUX_12_TCPWM1_16M_TR_OUT12 = 0x00000CA9u, /* tcpwm[1].tr_out1[258] */
    TRIG_IN_MUX_12_TCPWM1_16M_TR_OUT13 = 0x00000CAAu, /* tcpwm[1].tr_out1[259] */
    TRIG_IN_MUX_12_TCPWM1_16M_TR_OUT14 = 0x00000CABu, /* tcpwm[1].tr_out1[260] */
    TRIG_IN_MUX_12_TCPWM1_16M_TR_OUT15 = 0x00000CACu, /* tcpwm[1].tr_out1[261] */
    TRIG_IN_MUX_12_TCPWM1_16M_TR_OUT16 = 0x00000CADu, /* tcpwm[1].tr_out1[262] */
    TRIG_IN_MUX_12_TCPWM1_16M_TR_OUT17 = 0x00000CAEu, /* tcpwm[1].tr_out1[263] */
    TRIG_IN_MUX_12_TCPWM1_16M_TR_OUT18 = 0x00000CAFu, /* tcpwm[1].tr_out1[264] */
    TRIG_IN_MUX_12_TCPWM1_16M_TR_OUT19 = 0x00000CB0u, /* tcpwm[1].tr_out1[265] */
    TRIG_IN_MUX_12_TCPWM1_16M_TR_OUT110 = 0x00000CB1u, /* tcpwm[1].tr_out1[266] */
    TRIG_IN_MUX_12_TCPWM1_16M_TR_OUT111 = 0x00000CB2u, /* tcpwm[1].tr_out1[267] */
    TRIG_IN_MUX_12_TCPWM1_32_TR_OUT10 = 0x00000CB3u, /* tcpwm[1].tr_out1[512] */
    TRIG_IN_MUX_12_TCPWM1_32_TR_OUT11 = 0x00000CB4u, /* tcpwm[1].tr_out1[513] */
    TRIG_IN_MUX_12_TCPWM1_32_TR_OUT12 = 0x00000CB5u, /* tcpwm[1].tr_out1[514] */
    TRIG_IN_MUX_12_TCPWM1_32_TR_OUT13 = 0x00000CB6u, /* tcpwm[1].tr_out1[515] */
    TRIG_IN_MUX_12_TCPWM1_32_TR_OUT14 = 0x00000CB7u, /* tcpwm[1].tr_out1[516] */
    TRIG_IN_MUX_12_TCPWM1_32_TR_OUT15 = 0x00000CB8u, /* tcpwm[1].tr_out1[517] */
    TRIG_IN_MUX_12_TCPWM1_32_TR_OUT16 = 0x00000CB9u, /* tcpwm[1].tr_out1[518] */
    TRIG_IN_MUX_12_TCPWM1_32_TR_OUT17 = 0x00000CBAu, /* tcpwm[1].tr_out1[519] */
    TRIG_IN_MUX_12_TCPWM1_32_TR_OUT18 = 0x00000CBBu, /* tcpwm[1].tr_out1[520] */
    TRIG_IN_MUX_12_TCPWM1_32_TR_OUT19 = 0x00000CBCu, /* tcpwm[1].tr_out1[521] */
    TRIG_IN_MUX_12_TCPWM1_32_TR_OUT110 = 0x00000CBDu, /* tcpwm[1].tr_out1[522] */
    TRIG_IN_MUX_12_TCPWM1_32_TR_OUT111 = 0x00000CBEu, /* tcpwm[1].tr_out1[523] */
    TRIG_IN_MUX_12_TCPWM1_32_TR_OUT112 = 0x00000CBFu, /* tcpwm[1].tr_out1[524] */
    TRIG_IN_MUX_12_PASS_GEN_TR_OUT0 = 0x00000CC0u, /* pass[0].tr_sar_gen_out[0] */
    TRIG_IN_MUX_12_PASS_GEN_TR_OUT1 = 0x00000CC1u, /* pass[0].tr_sar_gen_out[1] */
    TRIG_IN_MUX_12_PASS_GEN_TR_OUT2 = 0x00000CC2u, /* pass[0].tr_sar_gen_out[2] */
    TRIG_IN_MUX_12_PASS_GEN_TR_OUT3 = 0x00000CC3u, /* pass[0].tr_sar_gen_out[3] */
    TRIG_IN_MUX_12_PASS_GEN_TR_OUT4 = 0x00000CC4u, /* pass[0].tr_sar_gen_out[4] */
    TRIG_IN_MUX_12_PASS_GEN_TR_OUT5 = 0x00000CC5u /* pass[0].tr_sar_gen_out[5] */
} en_trig_input_debug_reduction_3_t;

/* Trigger Input Group 0 - CAN DW Triggers (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_0_CAN0_DBG_TO_PDMA0_0 = 0x00001000u, /* canfd[0].tr_dbg_dma_req[0] */
    TRIG_IN_1TO1_0_CAN0_FIFO0_TO_PDMA0_0 = 0x00001001u, /* canfd[0].tr_fifo0[0] */
    TRIG_IN_1TO1_0_CAN0_FIFO1_TO_PDMA0_0 = 0x00001002u, /* canfd[0].tr_fifo1[0] */
    TRIG_IN_1TO1_0_CAN0_DBG_TO_PDMA0_1 = 0x00001003u, /* canfd[0].tr_dbg_dma_req[1] */
    TRIG_IN_1TO1_0_CAN0_FIFO0_TO_PDMA0_1 = 0x00001004u, /* canfd[0].tr_fifo0[1] */
    TRIG_IN_1TO1_0_CAN0_FIFO1_TO_PDMA0_1 = 0x00001005u, /* canfd[0].tr_fifo1[1] */
    TRIG_IN_1TO1_0_CAN0_DBG_TO_PDMA0_2 = 0x00001006u, /* canfd[0].tr_dbg_dma_req[2] */
    TRIG_IN_1TO1_0_CAN0_FIFO0_TO_PDMA0_2 = 0x00001007u, /* canfd[0].tr_fifo0[2] */
    TRIG_IN_1TO1_0_CAN0_FIFO1_TO_PDMA0_2 = 0x00001008u, /* canfd[0].tr_fifo1[2] */
    TRIG_IN_1TO1_0_CAN0_DBG_TO_PDMA0_3 = 0x00001009u, /* canfd[0].tr_dbg_dma_req[3] */
    TRIG_IN_1TO1_0_CAN0_FIFO0_TO_PDMA0_3 = 0x0000100Au, /* canfd[0].tr_fifo0[3] */
    TRIG_IN_1TO1_0_CAN0_FIFO1_TO_PDMA0_3 = 0x0000100Bu, /* canfd[0].tr_fifo1[3] */
    TRIG_IN_1TO1_0_CAN0_DBG_TO_PDMA0_4 = 0x0000100Cu, /* canfd[0].tr_dbg_dma_req[4] */
    TRIG_IN_1TO1_0_CAN0_FIFO0_TO_PDMA0_4 = 0x0000100Du, /* canfd[0].tr_fifo0[4] */
    TRIG_IN_1TO1_0_CAN0_FIFO1_TO_PDMA0_4 = 0x0000100Eu /* canfd[0].tr_fifo1[4] */
} en_trig_input_1to1_can_to_dw0_t;

/* Trigger Input Group 1 - PASS to DW0 direct connect (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA00 = 0x00001100u, /* pass[0].tr_sar_ch_done[0] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA01 = 0x00001101u, /* pass[0].tr_sar_ch_done[1] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA02 = 0x00001102u, /* pass[0].tr_sar_ch_done[2] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA03 = 0x00001103u, /* pass[0].tr_sar_ch_done[3] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA04 = 0x00001104u, /* pass[0].tr_sar_ch_done[4] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA05 = 0x00001105u, /* pass[0].tr_sar_ch_done[5] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA06 = 0x00001106u, /* pass[0].tr_sar_ch_done[6] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA07 = 0x00001107u, /* pass[0].tr_sar_ch_done[7] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA08 = 0x00001108u, /* pass[0].tr_sar_ch_done[8] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA09 = 0x00001109u, /* pass[0].tr_sar_ch_done[9] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA010 = 0x0000110Au, /* pass[0].tr_sar_ch_done[10] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA011 = 0x0000110Bu, /* pass[0].tr_sar_ch_done[11] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA012 = 0x0000110Cu, /* pass[0].tr_sar_ch_done[12] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA013 = 0x0000110Du, /* pass[0].tr_sar_ch_done[13] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA014 = 0x0000110Eu, /* pass[0].tr_sar_ch_done[14] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA015 = 0x0000110Fu, /* pass[0].tr_sar_ch_done[15] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA016 = 0x00001110u, /* pass[0].tr_sar_ch_done[16] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA017 = 0x00001111u, /* pass[0].tr_sar_ch_done[17] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA018 = 0x00001112u, /* pass[0].tr_sar_ch_done[18] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA019 = 0x00001113u, /* pass[0].tr_sar_ch_done[19] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA020 = 0x00001114u, /* pass[0].tr_sar_ch_done[20] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA021 = 0x00001115u, /* pass[0].tr_sar_ch_done[21] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA022 = 0x00001116u, /* pass[0].tr_sar_ch_done[22] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA023 = 0x00001117u, /* pass[0].tr_sar_ch_done[23] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA024 = 0x00001118u, /* pass[0].tr_sar_ch_done[24] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA025 = 0x00001119u, /* pass[0].tr_sar_ch_done[25] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA026 = 0x0000111Au, /* pass[0].tr_sar_ch_done[26] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA027 = 0x0000111Bu, /* pass[0].tr_sar_ch_done[27] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA028 = 0x0000111Cu, /* pass[0].tr_sar_ch_done[28] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA029 = 0x0000111Du, /* pass[0].tr_sar_ch_done[29] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA030 = 0x0000111Eu, /* pass[0].tr_sar_ch_done[30] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA031 = 0x0000111Fu, /* pass[0].tr_sar_ch_done[31] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA032 = 0x00001120u, /* pass[0].tr_sar_ch_done[32] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA033 = 0x00001121u, /* pass[0].tr_sar_ch_done[33] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA034 = 0x00001122u, /* pass[0].tr_sar_ch_done[34] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA035 = 0x00001123u, /* pass[0].tr_sar_ch_done[35] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA036 = 0x00001124u, /* pass[0].tr_sar_ch_done[36] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA037 = 0x00001125u, /* pass[0].tr_sar_ch_done[37] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA038 = 0x00001126u, /* pass[0].tr_sar_ch_done[38] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA039 = 0x00001127u, /* pass[0].tr_sar_ch_done[39] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA040 = 0x00001128u, /* pass[0].tr_sar_ch_done[40] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA041 = 0x00001129u, /* pass[0].tr_sar_ch_done[41] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA042 = 0x0000112Au, /* pass[0].tr_sar_ch_done[42] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA043 = 0x0000112Bu, /* pass[0].tr_sar_ch_done[43] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA044 = 0x0000112Cu, /* pass[0].tr_sar_ch_done[44] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA045 = 0x0000112Du, /* pass[0].tr_sar_ch_done[45] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA046 = 0x0000112Eu, /* pass[0].tr_sar_ch_done[46] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA047 = 0x0000112Fu, /* pass[0].tr_sar_ch_done[47] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA048 = 0x00001130u, /* pass[0].tr_sar_ch_done[48] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA049 = 0x00001131u, /* pass[0].tr_sar_ch_done[49] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA050 = 0x00001132u, /* pass[0].tr_sar_ch_done[50] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA051 = 0x00001133u, /* pass[0].tr_sar_ch_done[51] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA052 = 0x00001134u, /* pass[0].tr_sar_ch_done[52] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA053 = 0x00001135u, /* pass[0].tr_sar_ch_done[53] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA054 = 0x00001136u, /* pass[0].tr_sar_ch_done[54] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA055 = 0x00001137u, /* pass[0].tr_sar_ch_done[55] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA056 = 0x00001138u, /* pass[0].tr_sar_ch_done[56] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA057 = 0x00001139u, /* pass[0].tr_sar_ch_done[57] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA058 = 0x0000113Au, /* pass[0].tr_sar_ch_done[58] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA059 = 0x0000113Bu, /* pass[0].tr_sar_ch_done[59] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA060 = 0x0000113Cu, /* pass[0].tr_sar_ch_done[60] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA061 = 0x0000113Du, /* pass[0].tr_sar_ch_done[61] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA062 = 0x0000113Eu, /* pass[0].tr_sar_ch_done[62] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA063 = 0x0000113Fu, /* pass[0].tr_sar_ch_done[63] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA064 = 0x00001140u, /* pass[0].tr_sar_ch_done[64] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA065 = 0x00001141u, /* pass[0].tr_sar_ch_done[65] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA066 = 0x00001142u, /* pass[0].tr_sar_ch_done[66] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA067 = 0x00001143u, /* pass[0].tr_sar_ch_done[67] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA068 = 0x00001144u, /* pass[0].tr_sar_ch_done[68] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA069 = 0x00001145u, /* pass[0].tr_sar_ch_done[69] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA070 = 0x00001146u, /* pass[0].tr_sar_ch_done[70] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA071 = 0x00001147u, /* pass[0].tr_sar_ch_done[71] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA072 = 0x00001148u, /* pass[0].tr_sar_ch_done[72] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA073 = 0x00001149u, /* pass[0].tr_sar_ch_done[73] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA074 = 0x0000114Au, /* pass[0].tr_sar_ch_done[74] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA075 = 0x0000114Bu, /* pass[0].tr_sar_ch_done[75] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA076 = 0x0000114Cu, /* pass[0].tr_sar_ch_done[76] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA077 = 0x0000114Du, /* pass[0].tr_sar_ch_done[77] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA078 = 0x0000114Eu, /* pass[0].tr_sar_ch_done[78] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA079 = 0x0000114Fu, /* pass[0].tr_sar_ch_done[79] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA080 = 0x00001150u, /* pass[0].tr_sar_ch_done[80] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA081 = 0x00001151u, /* pass[0].tr_sar_ch_done[81] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA082 = 0x00001152u, /* pass[0].tr_sar_ch_done[82] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA083 = 0x00001153u, /* pass[0].tr_sar_ch_done[83] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA084 = 0x00001154u, /* pass[0].tr_sar_ch_done[84] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA085 = 0x00001155u, /* pass[0].tr_sar_ch_done[85] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA086 = 0x00001156u, /* pass[0].tr_sar_ch_done[86] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA087 = 0x00001157u, /* pass[0].tr_sar_ch_done[87] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA088 = 0x00001158u, /* pass[0].tr_sar_ch_done[88] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA089 = 0x00001159u, /* pass[0].tr_sar_ch_done[89] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA090 = 0x0000115Au, /* pass[0].tr_sar_ch_done[90] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA091 = 0x0000115Bu, /* pass[0].tr_sar_ch_done[91] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA092 = 0x0000115Cu, /* pass[0].tr_sar_ch_done[92] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA093 = 0x0000115Du, /* pass[0].tr_sar_ch_done[93] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA094 = 0x0000115Eu, /* pass[0].tr_sar_ch_done[94] */
    TRIG_IN_1TO1_1_PASS_CH_DONE_TO_PDMA095 = 0x0000115Fu /* pass[0].tr_sar_ch_done[95] */
} en_trig_input_1to1_sar_to_dw0_t;

/* Trigger Input Group 2 - SCB DW Triggers (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_2_SCB_TX_TO_PDMA10 = 0x00001200u, /* scb[0].tr_tx_req */
    TRIG_IN_1TO1_2_SCB_RX_TO_PDMA10 = 0x00001201u, /* scb[0].tr_rx_req */
    TRIG_IN_1TO1_2_SCB_TX_TO_PDMA11 = 0x00001202u, /* scb[1].tr_tx_req */
    TRIG_IN_1TO1_2_SCB_RX_TO_PDMA11 = 0x00001203u, /* scb[1].tr_rx_req */
    TRIG_IN_1TO1_2_SCB_TX_TO_PDMA12 = 0x00001204u, /* scb[2].tr_tx_req */
    TRIG_IN_1TO1_2_SCB_RX_TO_PDMA12 = 0x00001205u, /* scb[2].tr_rx_req */
    TRIG_IN_1TO1_2_SCB_TX_TO_PDMA13 = 0x00001206u, /* scb[3].tr_tx_req */
    TRIG_IN_1TO1_2_SCB_RX_TO_PDMA13 = 0x00001207u, /* scb[3].tr_rx_req */
    TRIG_IN_1TO1_2_SCB_TX_TO_PDMA14 = 0x00001208u, /* scb[4].tr_tx_req */
    TRIG_IN_1TO1_2_SCB_RX_TO_PDMA14 = 0x00001209u, /* scb[4].tr_rx_req */
    TRIG_IN_1TO1_2_SCB_TX_TO_PDMA15 = 0x0000120Au, /* scb[5].tr_tx_req */
    TRIG_IN_1TO1_2_SCB_RX_TO_PDMA15 = 0x0000120Bu, /* scb[5].tr_rx_req */
    TRIG_IN_1TO1_2_SCB_TX_TO_PDMA16 = 0x0000120Cu, /* scb[6].tr_tx_req */
    TRIG_IN_1TO1_2_SCB_RX_TO_PDMA16 = 0x0000120Du, /* scb[6].tr_rx_req */
    TRIG_IN_1TO1_2_SCB_TX_TO_PDMA17 = 0x0000120Eu, /* scb[7].tr_tx_req */
    TRIG_IN_1TO1_2_SCB_RX_TO_PDMA17 = 0x0000120Fu, /* scb[7].tr_rx_req */
    TRIG_IN_1TO1_2_SCB_TX_TO_PDMA18 = 0x00001210u, /* scb[8].tr_tx_req */
    TRIG_IN_1TO1_2_SCB_RX_TO_PDMA18 = 0x00001211u, /* scb[8].tr_rx_req */
    TRIG_IN_1TO1_2_SCB_TX_TO_PDMA19 = 0x00001212u, /* scb[9].tr_tx_req */
    TRIG_IN_1TO1_2_SCB_RX_TO_PDMA19 = 0x00001213u, /* scb[9].tr_rx_req */
    TRIG_IN_1TO1_2_SCB_TX_TO_PDMA110 = 0x00001214u, /* scb[10].tr_tx_req */
    TRIG_IN_1TO1_2_SCB_RX_TO_PDMA110 = 0x00001215u /* scb[10].tr_rx_req */
} en_trig_input_1to1_scb_to_dw1_t;

/* Trigger Input Group 3 - SMIF DW Triggers (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_3_SMIF_TX_TO_PDMA1 = 0x00001300u, /* smif[0].tr_tx_req */
    TRIG_IN_1TO1_3_SMIF_RX_TO_PDMA1 = 0x00001301u /* smif[0].tr_rx_req */
} en_trig_input_1to1_smif_to_dw1_t;

/* Trigger Input Group 4 - More CAN DW triggers (on DW1 for max BW) (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_4_CAN1_DBG_TO_PDMA1_0 = 0x00001400u, /* canfd[1].tr_dbg_dma_req[0] */
    TRIG_IN_1TO1_4_CAN1_FIFO0_TO_PDMA1_0 = 0x00001401u, /* canfd[1].tr_fifo0[0] */
    TRIG_IN_1TO1_4_CAN1_FIFO1_TO_PDMA1_0 = 0x00001402u, /* canfd[1].tr_fifo1[0] */
    TRIG_IN_1TO1_4_CAN1_DBG_TO_PDMA1_1 = 0x00001403u, /* canfd[1].tr_dbg_dma_req[1] */
    TRIG_IN_1TO1_4_CAN1_FIFO0_TO_PDMA1_1 = 0x00001404u, /* canfd[1].tr_fifo0[1] */
    TRIG_IN_1TO1_4_CAN1_FIFO1_TO_PDMA1_1 = 0x00001405u, /* canfd[1].tr_fifo1[1] */
    TRIG_IN_1TO1_4_CAN1_DBG_TO_PDMA1_2 = 0x00001406u, /* canfd[1].tr_dbg_dma_req[2] */
    TRIG_IN_1TO1_4_CAN1_FIFO0_TO_PDMA1_2 = 0x00001407u, /* canfd[1].tr_fifo0[2] */
    TRIG_IN_1TO1_4_CAN1_FIFO1_TO_PDMA1_2 = 0x00001408u, /* canfd[1].tr_fifo1[2] */
    TRIG_IN_1TO1_4_CAN1_DBG_TO_PDMA1_3 = 0x00001409u, /* canfd[1].tr_dbg_dma_req[3] */
    TRIG_IN_1TO1_4_CAN1_FIFO0_TO_PDMA1_3 = 0x0000140Au, /* canfd[1].tr_fifo0[3] */
    TRIG_IN_1TO1_4_CAN1_FIFO1_TO_PDMA1_3 = 0x0000140Bu, /* canfd[1].tr_fifo1[3] */
    TRIG_IN_1TO1_4_CAN1_DBG_TO_PDMA1_4 = 0x0000140Cu, /* canfd[1].tr_dbg_dma_req[4] */
    TRIG_IN_1TO1_4_CAN1_FIFO0_TO_PDMA1_4 = 0x0000140Du, /* canfd[1].tr_fifo0[4] */
    TRIG_IN_1TO1_4_CAN1_FIFO1_TO_PDMA1_4 = 0x0000140Eu /* canfd[1].tr_fifo1[4] */
} en_trig_input_1to1_can_to_dw1_t;

/* Trigger Input Group 5 - I2S DW Triggers (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_5_I2S_TX_TO_PDMA10 = 0x00001500u, /* audioss[0].tr_i2s_tx_req */
    TRIG_IN_1TO1_5_I2S_RX_TO_PDMA10 = 0x00001501u, /* audioss[0].tr_i2s_rx_req */
    TRIG_IN_1TO1_5_I2S_TX_TO_PDMA11 = 0x00001502u, /* audioss[1].tr_i2s_tx_req */
    TRIG_IN_1TO1_5_I2S_RX_TO_PDMA11 = 0x00001503u, /* audioss[1].tr_i2s_rx_req */
    TRIG_IN_1TO1_5_I2S_TX_TO_PDMA12 = 0x00001504u, /* audioss[2].tr_i2s_tx_req */
    TRIG_IN_1TO1_5_I2S_RX_TO_PDMA12 = 0x00001505u /* audioss[2].tr_i2s_rx_req */
} en_trig_input_1to1_i2s_to_dw1_t;

/* Trigger Input Group 6 - PASS to PWM direct connect (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL0 = 0x00001600u, /* pass[0].tr_sar_ch_rangevio[0] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL1 = 0x00001601u, /* pass[0].tr_sar_ch_rangevio[1] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL2 = 0x00001602u, /* pass[0].tr_sar_ch_rangevio[2] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL3 = 0x00001603u, /* pass[0].tr_sar_ch_rangevio[3] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL4 = 0x00001604u, /* pass[0].tr_sar_ch_rangevio[4] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL5 = 0x00001605u, /* pass[0].tr_sar_ch_rangevio[5] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL6 = 0x00001606u, /* pass[0].tr_sar_ch_rangevio[6] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL7 = 0x00001607u, /* pass[0].tr_sar_ch_rangevio[7] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL8 = 0x00001608u, /* pass[0].tr_sar_ch_rangevio[8] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL9 = 0x00001609u, /* pass[0].tr_sar_ch_rangevio[9] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL10 = 0x0000160Au, /* pass[0].tr_sar_ch_rangevio[10] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL11 = 0x0000160Bu, /* pass[0].tr_sar_ch_rangevio[11] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL12 = 0x0000160Cu, /* pass[0].tr_sar_ch_rangevio[12] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL13 = 0x0000160Du, /* pass[0].tr_sar_ch_rangevio[13] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL14 = 0x0000160Eu, /* pass[0].tr_sar_ch_rangevio[14] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL15 = 0x0000160Fu, /* pass[0].tr_sar_ch_rangevio[15] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL16 = 0x00001610u, /* pass[0].tr_sar_ch_rangevio[16] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL17 = 0x00001611u, /* pass[0].tr_sar_ch_rangevio[17] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL18 = 0x00001612u, /* pass[0].tr_sar_ch_rangevio[18] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL19 = 0x00001613u, /* pass[0].tr_sar_ch_rangevio[19] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL20 = 0x00001614u, /* pass[0].tr_sar_ch_rangevio[20] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL21 = 0x00001615u, /* pass[0].tr_sar_ch_rangevio[21] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL22 = 0x00001616u, /* pass[0].tr_sar_ch_rangevio[22] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL23 = 0x00001617u, /* pass[0].tr_sar_ch_rangevio[23] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL24 = 0x00001618u, /* pass[0].tr_sar_ch_rangevio[24] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL25 = 0x00001619u, /* pass[0].tr_sar_ch_rangevio[25] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL26 = 0x0000161Au, /* pass[0].tr_sar_ch_rangevio[26] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL27 = 0x0000161Bu, /* pass[0].tr_sar_ch_rangevio[27] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL28 = 0x0000161Cu, /* pass[0].tr_sar_ch_rangevio[28] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL29 = 0x0000161Du, /* pass[0].tr_sar_ch_rangevio[29] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL30 = 0x0000161Eu, /* pass[0].tr_sar_ch_rangevio[30] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL31 = 0x0000161Fu, /* pass[0].tr_sar_ch_rangevio[31] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL32 = 0x00001620u, /* pass[0].tr_sar_ch_rangevio[32] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL33 = 0x00001621u, /* pass[0].tr_sar_ch_rangevio[33] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL34 = 0x00001622u, /* pass[0].tr_sar_ch_rangevio[34] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL35 = 0x00001623u, /* pass[0].tr_sar_ch_rangevio[35] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL36 = 0x00001624u, /* pass[0].tr_sar_ch_rangevio[36] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL37 = 0x00001625u, /* pass[0].tr_sar_ch_rangevio[37] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL38 = 0x00001626u, /* pass[0].tr_sar_ch_rangevio[38] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL39 = 0x00001627u, /* pass[0].tr_sar_ch_rangevio[39] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL40 = 0x00001628u, /* pass[0].tr_sar_ch_rangevio[40] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL41 = 0x00001629u, /* pass[0].tr_sar_ch_rangevio[41] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL42 = 0x0000162Au, /* pass[0].tr_sar_ch_rangevio[42] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL43 = 0x0000162Bu, /* pass[0].tr_sar_ch_rangevio[43] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL44 = 0x0000162Cu, /* pass[0].tr_sar_ch_rangevio[44] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL45 = 0x0000162Du, /* pass[0].tr_sar_ch_rangevio[45] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL46 = 0x0000162Eu, /* pass[0].tr_sar_ch_rangevio[46] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL47 = 0x0000162Fu, /* pass[0].tr_sar_ch_rangevio[47] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL48 = 0x00001630u, /* pass[0].tr_sar_ch_rangevio[48] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL49 = 0x00001631u, /* pass[0].tr_sar_ch_rangevio[49] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL50 = 0x00001632u, /* pass[0].tr_sar_ch_rangevio[50] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL51 = 0x00001633u, /* pass[0].tr_sar_ch_rangevio[51] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL52 = 0x00001634u, /* pass[0].tr_sar_ch_rangevio[52] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL53 = 0x00001635u, /* pass[0].tr_sar_ch_rangevio[53] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL54 = 0x00001636u, /* pass[0].tr_sar_ch_rangevio[54] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL55 = 0x00001637u, /* pass[0].tr_sar_ch_rangevio[55] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL56 = 0x00001638u, /* pass[0].tr_sar_ch_rangevio[56] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL57 = 0x00001639u, /* pass[0].tr_sar_ch_rangevio[57] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL58 = 0x0000163Au, /* pass[0].tr_sar_ch_rangevio[58] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL59 = 0x0000163Bu, /* pass[0].tr_sar_ch_rangevio[59] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL60 = 0x0000163Cu, /* pass[0].tr_sar_ch_rangevio[60] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL61 = 0x0000163Du, /* pass[0].tr_sar_ch_rangevio[61] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL62 = 0x0000163Eu, /* pass[0].tr_sar_ch_rangevio[62] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL63 = 0x0000163Fu, /* pass[0].tr_sar_ch_rangevio[63] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL64 = 0x00001640u, /* pass[0].tr_sar_ch_rangevio[64] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL65 = 0x00001641u, /* pass[0].tr_sar_ch_rangevio[65] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL66 = 0x00001642u, /* pass[0].tr_sar_ch_rangevio[66] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL67 = 0x00001643u, /* pass[0].tr_sar_ch_rangevio[67] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL68 = 0x00001644u, /* pass[0].tr_sar_ch_rangevio[68] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL69 = 0x00001645u, /* pass[0].tr_sar_ch_rangevio[69] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL70 = 0x00001646u, /* pass[0].tr_sar_ch_rangevio[70] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL71 = 0x00001647u, /* pass[0].tr_sar_ch_rangevio[71] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL72 = 0x00001648u, /* pass[0].tr_sar_ch_rangevio[72] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL73 = 0x00001649u, /* pass[0].tr_sar_ch_rangevio[73] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL74 = 0x0000164Au, /* pass[0].tr_sar_ch_rangevio[74] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL75 = 0x0000164Bu, /* pass[0].tr_sar_ch_rangevio[75] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL76 = 0x0000164Cu, /* pass[0].tr_sar_ch_rangevio[76] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL77 = 0x0000164Du, /* pass[0].tr_sar_ch_rangevio[77] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL78 = 0x0000164Eu, /* pass[0].tr_sar_ch_rangevio[78] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL79 = 0x0000164Fu, /* pass[0].tr_sar_ch_rangevio[79] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL80 = 0x00001650u, /* pass[0].tr_sar_ch_rangevio[80] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL81 = 0x00001651u, /* pass[0].tr_sar_ch_rangevio[81] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL82 = 0x00001652u, /* pass[0].tr_sar_ch_rangevio[82] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL83 = 0x00001653u, /* pass[0].tr_sar_ch_rangevio[83] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL84 = 0x00001654u, /* pass[0].tr_sar_ch_rangevio[84] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL85 = 0x00001655u, /* pass[0].tr_sar_ch_rangevio[85] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL86 = 0x00001656u, /* pass[0].tr_sar_ch_rangevio[86] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL87 = 0x00001657u, /* pass[0].tr_sar_ch_rangevio[87] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL88 = 0x00001658u, /* pass[0].tr_sar_ch_rangevio[88] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL89 = 0x00001659u, /* pass[0].tr_sar_ch_rangevio[89] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL90 = 0x0000165Au, /* pass[0].tr_sar_ch_rangevio[90] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL91 = 0x0000165Bu, /* pass[0].tr_sar_ch_rangevio[91] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL92 = 0x0000165Cu, /* pass[0].tr_sar_ch_rangevio[92] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL93 = 0x0000165Du, /* pass[0].tr_sar_ch_rangevio[93] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL94 = 0x0000165Eu, /* pass[0].tr_sar_ch_rangevio[94] */
    TRIG_IN_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL95 = 0x0000165Fu /* pass[0].tr_sar_ch_rangevio[95] */
} en_trig_input_1to1_sar_to_tcpwm1_t;

/* Trigger Input Group 7 -  (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR0 = 0x00001700u, /* tcpwm[1].tr_out1[0] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR1 = 0x00001701u, /* tcpwm[1].tr_out1[1] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR2 = 0x00001702u, /* tcpwm[1].tr_out1[2] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR3 = 0x00001703u, /* tcpwm[1].tr_out1[3] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR4 = 0x00001704u, /* tcpwm[1].tr_out1[4] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR5 = 0x00001705u, /* tcpwm[1].tr_out1[5] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR6 = 0x00001706u, /* tcpwm[1].tr_out1[6] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR7 = 0x00001707u, /* tcpwm[1].tr_out1[7] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR8 = 0x00001708u, /* tcpwm[1].tr_out1[8] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR9 = 0x00001709u, /* tcpwm[1].tr_out1[9] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR10 = 0x0000170Au, /* tcpwm[1].tr_out1[10] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR11 = 0x0000170Bu, /* tcpwm[1].tr_out1[11] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR12 = 0x0000170Cu, /* tcpwm[1].tr_out1[12] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR13 = 0x0000170Du, /* tcpwm[1].tr_out1[13] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR14 = 0x0000170Eu, /* tcpwm[1].tr_out1[14] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR15 = 0x0000170Fu, /* tcpwm[1].tr_out1[15] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR16 = 0x00001710u, /* tcpwm[1].tr_out1[16] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR17 = 0x00001711u, /* tcpwm[1].tr_out1[17] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR18 = 0x00001712u, /* tcpwm[1].tr_out1[18] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR19 = 0x00001713u, /* tcpwm[1].tr_out1[19] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR20 = 0x00001714u, /* tcpwm[1].tr_out1[20] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR21 = 0x00001715u, /* tcpwm[1].tr_out1[21] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR22 = 0x00001716u, /* tcpwm[1].tr_out1[22] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR23 = 0x00001717u, /* tcpwm[1].tr_out1[23] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR24 = 0x00001718u, /* tcpwm[1].tr_out1[24] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR25 = 0x00001719u, /* tcpwm[1].tr_out1[25] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR26 = 0x0000171Au, /* tcpwm[1].tr_out1[26] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR27 = 0x0000171Bu, /* tcpwm[1].tr_out1[27] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR28 = 0x0000171Cu, /* tcpwm[1].tr_out1[28] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR29 = 0x0000171Du, /* tcpwm[1].tr_out1[29] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR30 = 0x0000171Eu, /* tcpwm[1].tr_out1[30] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR31 = 0x0000171Fu, /* tcpwm[1].tr_out1[31] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR32 = 0x00001720u, /* tcpwm[1].tr_out1[32] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR33 = 0x00001721u, /* tcpwm[1].tr_out1[33] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR34 = 0x00001722u, /* tcpwm[1].tr_out1[34] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR35 = 0x00001723u, /* tcpwm[1].tr_out1[35] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR36 = 0x00001724u, /* tcpwm[1].tr_out1[36] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR37 = 0x00001725u, /* tcpwm[1].tr_out1[37] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR38 = 0x00001726u, /* tcpwm[1].tr_out1[38] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR39 = 0x00001727u, /* tcpwm[1].tr_out1[39] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR40 = 0x00001728u, /* tcpwm[1].tr_out1[40] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR41 = 0x00001729u, /* tcpwm[1].tr_out1[41] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR42 = 0x0000172Au, /* tcpwm[1].tr_out1[42] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR43 = 0x0000172Bu, /* tcpwm[1].tr_out1[43] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR44 = 0x0000172Cu, /* tcpwm[1].tr_out1[44] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR45 = 0x0000172Du, /* tcpwm[1].tr_out1[45] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR46 = 0x0000172Eu, /* tcpwm[1].tr_out1[46] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR47 = 0x0000172Fu, /* tcpwm[1].tr_out1[47] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR48 = 0x00001730u, /* tcpwm[1].tr_out1[48] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR49 = 0x00001731u, /* tcpwm[1].tr_out1[49] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR50 = 0x00001732u, /* tcpwm[1].tr_out1[50] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR51 = 0x00001733u, /* tcpwm[1].tr_out1[51] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR52 = 0x00001734u, /* tcpwm[1].tr_out1[52] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR53 = 0x00001735u, /* tcpwm[1].tr_out1[53] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR54 = 0x00001736u, /* tcpwm[1].tr_out1[54] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR55 = 0x00001737u, /* tcpwm[1].tr_out1[55] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR56 = 0x00001738u, /* tcpwm[1].tr_out1[56] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR57 = 0x00001739u, /* tcpwm[1].tr_out1[57] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR58 = 0x0000173Au, /* tcpwm[1].tr_out1[58] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR59 = 0x0000173Bu, /* tcpwm[1].tr_out1[59] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR60 = 0x0000173Cu, /* tcpwm[1].tr_out1[60] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR61 = 0x0000173Du, /* tcpwm[1].tr_out1[61] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR62 = 0x0000173Eu, /* tcpwm[1].tr_out1[62] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR63 = 0x0000173Fu, /* tcpwm[1].tr_out1[63] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR64 = 0x00001740u, /* tcpwm[1].tr_out1[64] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR65 = 0x00001741u, /* tcpwm[1].tr_out1[65] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR66 = 0x00001742u, /* tcpwm[1].tr_out1[66] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR67 = 0x00001743u, /* tcpwm[1].tr_out1[67] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR68 = 0x00001744u, /* tcpwm[1].tr_out1[68] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR69 = 0x00001745u, /* tcpwm[1].tr_out1[69] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR70 = 0x00001746u, /* tcpwm[1].tr_out1[70] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR71 = 0x00001747u, /* tcpwm[1].tr_out1[71] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR72 = 0x00001748u, /* tcpwm[1].tr_out1[72] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR73 = 0x00001749u, /* tcpwm[1].tr_out1[73] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR74 = 0x0000174Au, /* tcpwm[1].tr_out1[74] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR75 = 0x0000174Bu, /* tcpwm[1].tr_out1[75] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR76 = 0x0000174Cu, /* tcpwm[1].tr_out1[76] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR77 = 0x0000174Du, /* tcpwm[1].tr_out1[77] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR78 = 0x0000174Eu, /* tcpwm[1].tr_out1[78] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR79 = 0x0000174Fu, /* tcpwm[1].tr_out1[79] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR80 = 0x00001750u, /* tcpwm[1].tr_out1[80] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR81 = 0x00001751u, /* tcpwm[1].tr_out1[81] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR82 = 0x00001752u, /* tcpwm[1].tr_out1[82] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR83 = 0x00001753u, /* tcpwm[1].tr_out1[83] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR256 = 0x00001754u, /* tcpwm[1].tr_out1[256] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR257 = 0x00001755u, /* tcpwm[1].tr_out1[257] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR258 = 0x00001756u, /* tcpwm[1].tr_out1[258] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR259 = 0x00001757u, /* tcpwm[1].tr_out1[259] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR260 = 0x00001758u, /* tcpwm[1].tr_out1[260] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR261 = 0x00001759u, /* tcpwm[1].tr_out1[261] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR262 = 0x0000175Au, /* tcpwm[1].tr_out1[262] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR263 = 0x0000175Bu, /* tcpwm[1].tr_out1[263] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR264 = 0x0000175Cu, /* tcpwm[1].tr_out1[264] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR265 = 0x0000175Du, /* tcpwm[1].tr_out1[265] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR266 = 0x0000175Eu, /* tcpwm[1].tr_out1[266] */
    TRIG_IN_1TO1_7_TCPWM1_TO_PASS_CH_TR267 = 0x0000175Fu /* tcpwm[1].tr_out1[267] */
} en_trig_input_1to1_tcpwm1_to_sar_t;

/* Trigger Input Group 8 - Acknowledge triggers from DW1 to CAN (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_8_PDMA1_ACK_TO_CAN1_0 = 0x00001800u, /* cpuss.dw1_tr_out[38] */
    TRIG_IN_1TO1_8_PDMA1_ACK_TO_CAN1_1 = 0x00001801u, /* cpuss.dw1_tr_out[41] */
    TRIG_IN_1TO1_8_PDMA1_ACK_TO_CAN1_2 = 0x00001802u, /* cpuss.dw1_tr_out[44] */
    TRIG_IN_1TO1_8_PDMA1_ACK_TO_CAN1_3 = 0x00001803u, /* cpuss.dw1_tr_out[47] */
    TRIG_IN_1TO1_8_PDMA1_ACK_TO_CAN1_4 = 0x00001804u /* cpuss.dw1_tr_out[50] */
} en_trig_input_1to1_dw1_to_can1_t;

/* Trigger Input Group 9 - Acknowledge triggers from DW0 to CAN (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_9_PDMA0_ACK_TO_CAN0_0 = 0x00001900u, /* cpuss.dw0_tr_out[32] */
    TRIG_IN_1TO1_9_PDMA0_ACK_TO_CAN0_1 = 0x00001901u, /* cpuss.dw0_tr_out[35] */
    TRIG_IN_1TO1_9_PDMA0_ACK_TO_CAN0_2 = 0x00001902u, /* cpuss.dw0_tr_out[38] */
    TRIG_IN_1TO1_9_PDMA0_ACK_TO_CAN0_3 = 0x00001903u, /* cpuss.dw0_tr_out[41] */
    TRIG_IN_1TO1_9_PDMA0_ACK_TO_CAN0_4 = 0x00001904u /* cpuss.dw0_tr_out[44] */
} en_trig_input_1to1_dw0_to_can0_t;

/* Trigger Input Group 10 -  (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR0 = 0x00001A00u, /* tcpwm[1].tr_out0[0] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR1 = 0x00001A01u, /* tcpwm[1].tr_out0[1] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR2 = 0x00001A02u, /* tcpwm[1].tr_out0[2] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR3 = 0x00001A03u, /* tcpwm[1].tr_out0[3] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR4 = 0x00001A04u, /* tcpwm[1].tr_out0[4] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR5 = 0x00001A05u, /* tcpwm[1].tr_out0[5] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR6 = 0x00001A06u, /* tcpwm[1].tr_out0[6] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR7 = 0x00001A07u, /* tcpwm[1].tr_out0[7] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR8 = 0x00001A08u, /* tcpwm[1].tr_out0[8] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR9 = 0x00001A09u, /* tcpwm[1].tr_out0[9] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR10 = 0x00001A0Au, /* tcpwm[1].tr_out0[10] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR11 = 0x00001A0Bu, /* tcpwm[1].tr_out0[11] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR12 = 0x00001A0Cu, /* tcpwm[1].tr_out0[12] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR13 = 0x00001A0Du, /* tcpwm[1].tr_out0[13] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR14 = 0x00001A0Eu, /* tcpwm[1].tr_out0[14] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR15 = 0x00001A0Fu, /* tcpwm[1].tr_out0[15] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR16 = 0x00001A10u, /* tcpwm[1].tr_out0[16] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR17 = 0x00001A11u, /* tcpwm[1].tr_out0[17] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR18 = 0x00001A12u, /* tcpwm[1].tr_out0[18] */
    TRIG_IN_1TO1_10_TCPWM1_TO_LIN_TR19 = 0x00001A13u /* tcpwm[1].tr_out0[19] */
} en_trig_input_1to1_tcpwm_to_lin_t;

/* Trigger Input Group 11 -  (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_11_FLEXRAY_IBF_TR_TO_PDMA1 = 0x00001B00u, /* flexray[0].tr_ibf_out */
    TRIG_IN_1TO1_11_FLEXRAY_OBF_TR_TO_PDMA1 = 0x00001B01u /* flexray[0].tr_obf_out */
} en_trig_input_1to1_flexyray_to_dw1_t;

/* Trigger Input Group 12 -  (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_12_PDMA1_61_TO_PDMA1_63 = 0x00001C00u, /* cpuss.dw1_tr_out[61] */
    TRIG_IN_1TO1_12_PDMA1_62_TO_PDMA1_64 = 0x00001C01u /* cpuss.dw1_tr_out[62] */
} en_trig_input_1to1_dw1_to_dw1_t;

/* Trigger Input Group 13 -  (OneToOne) */
typedef enum
{
    TRIG_IN_1TO1_13_PDMA1_TO_FLEXRAY_IBF_TR = 0x00001D00u, /* cpuss.dw1_tr_out[63] */
    TRIG_IN_1TO1_13_PDMA1_TO_FLEXRAY_OBF_TR = 0x00001D01u /* cpuss.dw1_tr_out[64] */
} en_trig_input_1to1_dw1_to_flexray_t;

/* Trigger Group Outputs */
/* Trigger Output Group 0 - P-DMA0[0:15] Request Assignments */
typedef enum
{
    TRIG_OUT_MUX_0_PDMA0_TR_IN0     = 0x40000000u, /* cpuss.dw0_tr_in[0] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN1     = 0x40000001u, /* cpuss.dw0_tr_in[1] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN2     = 0x40000002u, /* cpuss.dw0_tr_in[2] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN3     = 0x40000003u, /* cpuss.dw0_tr_in[3] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN4     = 0x40000004u, /* cpuss.dw0_tr_in[4] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN5     = 0x40000005u, /* cpuss.dw0_tr_in[5] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN6     = 0x40000006u, /* cpuss.dw0_tr_in[6] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN7     = 0x40000007u, /* cpuss.dw0_tr_in[7] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN8     = 0x40000008u, /* cpuss.dw0_tr_in[8] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN9     = 0x40000009u, /* cpuss.dw0_tr_in[9] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN10    = 0x4000000Au, /* cpuss.dw0_tr_in[10] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN11    = 0x4000000Bu, /* cpuss.dw0_tr_in[11] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN12    = 0x4000000Cu, /* cpuss.dw0_tr_in[12] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN13    = 0x4000000Du, /* cpuss.dw0_tr_in[13] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN14    = 0x4000000Eu, /* cpuss.dw0_tr_in[14] */
    TRIG_OUT_MUX_0_PDMA0_TR_IN15    = 0x4000000Fu /* cpuss.dw0_tr_in[15] */
} en_trig_output_pdma0_0_15_tr_t;

/* Trigger Output Group 1 - P-DMA0[16:31] Request Assignments */
typedef enum
{
    TRIG_OUT_MUX_1_PDMA0_TR_IN16    = 0x40000100u, /* cpuss.dw0_tr_in[16] */
    TRIG_OUT_MUX_1_PDMA0_TR_IN17    = 0x40000101u, /* cpuss.dw0_tr_in[17] */
    TRIG_OUT_MUX_1_PDMA0_TR_IN18    = 0x40000102u, /* cpuss.dw0_tr_in[18] */
    TRIG_OUT_MUX_1_PDMA0_TR_IN19    = 0x40000103u, /* cpuss.dw0_tr_in[19] */
    TRIG_OUT_MUX_1_PDMA0_TR_IN20    = 0x40000104u, /* cpuss.dw0_tr_in[20] */
    TRIG_OUT_MUX_1_PDMA0_TR_IN21    = 0x40000105u, /* cpuss.dw0_tr_in[21] */
    TRIG_OUT_MUX_1_PDMA0_TR_IN22    = 0x40000106u, /* cpuss.dw0_tr_in[22] */
    TRIG_OUT_MUX_1_PDMA0_TR_IN23    = 0x40000107u, /* cpuss.dw0_tr_in[23] */
    TRIG_OUT_MUX_1_PDMA0_TR_IN24    = 0x40000108u, /* cpuss.dw0_tr_in[24] */
    TRIG_OUT_MUX_1_PDMA0_TR_IN25    = 0x40000109u, /* cpuss.dw0_tr_in[25] */
    TRIG_OUT_MUX_1_PDMA0_TR_IN26    = 0x4000010Au, /* cpuss.dw0_tr_in[26] */
    TRIG_OUT_MUX_1_PDMA0_TR_IN27    = 0x4000010Bu, /* cpuss.dw0_tr_in[27] */
    TRIG_OUT_MUX_1_PDMA0_TR_IN28    = 0x4000010Cu, /* cpuss.dw0_tr_in[28] */
    TRIG_OUT_MUX_1_PDMA0_TR_IN29    = 0x4000010Du, /* cpuss.dw0_tr_in[29] */
    TRIG_OUT_MUX_1_PDMA0_TR_IN30    = 0x4000010Eu, /* cpuss.dw0_tr_in[30] */
    TRIG_OUT_MUX_1_PDMA0_TR_IN31    = 0x4000010Fu /* cpuss.dw0_tr_in[31] */
} en_trig_output_pdma0_16_31_tr_t;

/* Trigger Output Group 2 - P-DMA1[0:15] Request Assignments */
typedef enum
{
    TRIG_OUT_MUX_2_PDMA1_TR_IN0     = 0x40000200u, /* cpuss.dw1_tr_in[0] */
    TRIG_OUT_MUX_2_PDMA1_TR_IN1     = 0x40000201u, /* cpuss.dw1_tr_in[1] */
    TRIG_OUT_MUX_2_PDMA1_TR_IN2     = 0x40000202u, /* cpuss.dw1_tr_in[2] */
    TRIG_OUT_MUX_2_PDMA1_TR_IN3     = 0x40000203u, /* cpuss.dw1_tr_in[3] */
    TRIG_OUT_MUX_2_PDMA1_TR_IN4     = 0x40000204u, /* cpuss.dw1_tr_in[4] */
    TRIG_OUT_MUX_2_PDMA1_TR_IN5     = 0x40000205u, /* cpuss.dw1_tr_in[5] */
    TRIG_OUT_MUX_2_PDMA1_TR_IN6     = 0x40000206u, /* cpuss.dw1_tr_in[6] */
    TRIG_OUT_MUX_2_PDMA1_TR_IN7     = 0x40000207u, /* cpuss.dw1_tr_in[7] */
    TRIG_OUT_MUX_2_PDMA1_TR_IN8     = 0x40000208u, /* cpuss.dw1_tr_in[8] */
    TRIG_OUT_MUX_2_PDMA1_TR_IN9     = 0x40000209u, /* cpuss.dw1_tr_in[9] */
    TRIG_OUT_MUX_2_PDMA1_TR_IN10    = 0x4000020Au, /* cpuss.dw1_tr_in[10] */
    TRIG_OUT_MUX_2_PDMA1_TR_IN11    = 0x4000020Bu, /* cpuss.dw1_tr_in[11] */
    TRIG_OUT_MUX_2_PDMA1_TR_IN12    = 0x4000020Cu, /* cpuss.dw1_tr_in[12] */
    TRIG_OUT_MUX_2_PDMA1_TR_IN13    = 0x4000020Du, /* cpuss.dw1_tr_in[13] */
    TRIG_OUT_MUX_2_PDMA1_TR_IN14    = 0x4000020Eu, /* cpuss.dw1_tr_in[14] */
    TRIG_OUT_MUX_2_PDMA1_TR_IN15    = 0x4000020Fu /* cpuss.dw1_tr_in[15] */
} en_trig_output_pdma1_0_15_tr_t;

/* Trigger Output Group 3 - M-DMA Request Assignments */
typedef enum
{
    TRIG_OUT_MUX_3_MDMA_TR_IN0      = 0x40000300u, /* cpuss.dmac_tr_in[0] */
    TRIG_OUT_MUX_3_MDMA_TR_IN1      = 0x40000301u, /* cpuss.dmac_tr_in[1] */
    TRIG_OUT_MUX_3_MDMA_TR_IN2      = 0x40000302u, /* cpuss.dmac_tr_in[2] */
    TRIG_OUT_MUX_3_MDMA_TR_IN3      = 0x40000303u, /* cpuss.dmac_tr_in[3] */
    TRIG_OUT_MUX_3_MDMA_TR_IN4      = 0x40000304u, /* cpuss.dmac_tr_in[4] */
    TRIG_OUT_MUX_3_MDMA_TR_IN5      = 0x40000305u, /* cpuss.dmac_tr_in[5] */
    TRIG_OUT_MUX_3_MDMA_TR_IN6      = 0x40000306u, /* cpuss.dmac_tr_in[6] */
    TRIG_OUT_MUX_3_MDMA_TR_IN7      = 0x40000307u /* cpuss.dmac_tr_in[7] */
} en_trig_output_mdma_tr_t;

/* Trigger Output Group 4 -  */
typedef enum
{
    TRIG_OUT_MUX_4_TCPWM0_ALL_CNT_TR_IN0 = 0x40000400u, /* tcpwm[0].tr_all_cnt_in[0] */
    TRIG_OUT_MUX_4_TCPWM0_ALL_CNT_TR_IN1 = 0x40000401u, /* tcpwm[0].tr_all_cnt_in[1] */
    TRIG_OUT_MUX_4_TCPWM0_ALL_CNT_TR_IN2 = 0x40000402u, /* tcpwm[0].tr_all_cnt_in[2] */
    TRIG_OUT_MUX_4_TCPWM0_ALL_CNT_TR_IN3 = 0x40000403u, /* tcpwm[0].tr_all_cnt_in[3] */
    TRIG_OUT_MUX_4_TCPWM0_ALL_CNT_TR_IN4 = 0x40000404u, /* tcpwm[0].tr_all_cnt_in[4] */
    TRIG_OUT_MUX_4_TCPWM0_ALL_CNT_TR_IN5 = 0x40000405u, /* tcpwm[0].tr_all_cnt_in[5] */
    TRIG_OUT_MUX_4_TCPWM0_ALL_CNT_TR_IN6 = 0x40000406u, /* tcpwm[0].tr_all_cnt_in[6] */
    TRIG_OUT_MUX_4_TCPWM0_ALL_CNT_TR_IN7 = 0x40000407u, /* tcpwm[0].tr_all_cnt_in[7] */
    TRIG_OUT_MUX_4_TCPWM0_ALL_CNT_TR_IN8 = 0x40000408u, /* tcpwm[0].tr_all_cnt_in[8] */
    TRIG_OUT_MUX_4_TCPWM0_ALL_CNT_TR_IN9 = 0x40000409u, /* tcpwm[0].tr_all_cnt_in[9] */
    TRIG_OUT_MUX_4_TCPWM0_ALL_CNT_TR_IN10 = 0x4000040Au, /* tcpwm[0].tr_all_cnt_in[10] */
    TRIG_OUT_MUX_4_TCPWM0_ALL_CNT_TR_IN11 = 0x4000040Bu /* tcpwm[0].tr_all_cnt_in[11] */
} en_trig_output_tcpwm0_tr_t;

/* Trigger Output Group 5 -  */
typedef enum
{
    TRIG_OUT_MUX_5_TCPWM1_ALL_CNT_TR_IN0 = 0x40000500u, /* tcpwm[1].tr_all_cnt_in[0] */
    TRIG_OUT_MUX_5_TCPWM1_ALL_CNT_TR_IN1 = 0x40000501u, /* tcpwm[1].tr_all_cnt_in[1] */
    TRIG_OUT_MUX_5_TCPWM1_ALL_CNT_TR_IN2 = 0x40000502u, /* tcpwm[1].tr_all_cnt_in[2] */
    TRIG_OUT_MUX_5_TCPWM1_ALL_CNT_TR_IN3 = 0x40000503u, /* tcpwm[1].tr_all_cnt_in[3] */
    TRIG_OUT_MUX_5_TCPWM1_ALL_CNT_TR_IN4 = 0x40000504u, /* tcpwm[1].tr_all_cnt_in[4] */
    TRIG_OUT_MUX_5_TCPWM1_ALL_CNT_TR_IN5 = 0x40000505u, /* tcpwm[1].tr_all_cnt_in[5] */
    TRIG_OUT_MUX_5_TCPWM1_ALL_CNT_TR_IN6 = 0x40000506u, /* tcpwm[1].tr_all_cnt_in[6] */
    TRIG_OUT_MUX_5_TCPWM1_ALL_CNT_TR_IN7 = 0x40000507u, /* tcpwm[1].tr_all_cnt_in[7] */
    TRIG_OUT_MUX_5_TCPWM1_ALL_CNT_TR_IN8 = 0x40000508u, /* tcpwm[1].tr_all_cnt_in[8] */
    TRIG_OUT_MUX_5_TCPWM1_ALL_CNT_TR_IN9 = 0x40000509u, /* tcpwm[1].tr_all_cnt_in[9] */
    TRIG_OUT_MUX_5_TCPWM1_ALL_CNT_TR_IN10 = 0x4000050Au, /* tcpwm[1].tr_all_cnt_in[10] */
    TRIG_OUT_MUX_5_TCPWM1_ALL_CNT_TR_IN11 = 0x4000050Bu /* tcpwm[1].tr_all_cnt_in[11] */
} en_trig_output_tcpwm1_0_11_tr_t;

/* Trigger Output Group 6 - TCPWM trigger inputs */
typedef enum
{
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN12 = 0x40000600u, /* tcpwm[1].tr_all_cnt_in[12] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN13 = 0x40000601u, /* tcpwm[1].tr_all_cnt_in[13] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN14 = 0x40000602u, /* tcpwm[1].tr_all_cnt_in[14] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN15 = 0x40000603u, /* tcpwm[1].tr_all_cnt_in[15] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN16 = 0x40000604u, /* tcpwm[1].tr_all_cnt_in[16] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN17 = 0x40000605u, /* tcpwm[1].tr_all_cnt_in[17] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN18 = 0x40000606u, /* tcpwm[1].tr_all_cnt_in[18] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN19 = 0x40000607u, /* tcpwm[1].tr_all_cnt_in[19] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN20 = 0x40000608u, /* tcpwm[1].tr_all_cnt_in[20] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN21 = 0x40000609u, /* tcpwm[1].tr_all_cnt_in[21] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN22 = 0x4000060Au, /* tcpwm[1].tr_all_cnt_in[22] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN23 = 0x4000060Bu, /* tcpwm[1].tr_all_cnt_in[23] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN24 = 0x4000060Cu, /* tcpwm[1].tr_all_cnt_in[24] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN25 = 0x4000060Du, /* tcpwm[1].tr_all_cnt_in[25] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN26 = 0x4000060Eu, /* tcpwm[1].tr_all_cnt_in[26] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN27 = 0x4000060Fu, /* tcpwm[1].tr_all_cnt_in[27] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN28 = 0x40000610u, /* tcpwm[1].tr_all_cnt_in[28] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN29 = 0x40000611u, /* tcpwm[1].tr_all_cnt_in[29] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN30 = 0x40000612u, /* tcpwm[1].tr_all_cnt_in[30] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN31 = 0x40000613u, /* tcpwm[1].tr_all_cnt_in[31] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN32 = 0x40000614u, /* tcpwm[1].tr_all_cnt_in[32] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN33 = 0x40000615u, /* tcpwm[1].tr_all_cnt_in[33] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN34 = 0x40000616u, /* tcpwm[1].tr_all_cnt_in[34] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN35 = 0x40000617u, /* tcpwm[1].tr_all_cnt_in[35] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN36 = 0x40000618u, /* tcpwm[1].tr_all_cnt_in[36] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN37 = 0x40000619u, /* tcpwm[1].tr_all_cnt_in[37] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN38 = 0x4000061Au, /* tcpwm[1].tr_all_cnt_in[38] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN39 = 0x4000061Bu, /* tcpwm[1].tr_all_cnt_in[39] */
    TRIG_OUT_MUX_6_TCPWM1_ALL_CNT_TR_IN40 = 0x4000061Cu /* tcpwm[1].tr_all_cnt_in[40] */
} en_trig_output_tcpwm1_12_40_tr_t;

/* Trigger Output Group 7 - PASS trigger multiplexer */
typedef enum
{
    TRIG_OUT_MUX_7_PASS_GEN_TR_IN0  = 0x40000700u, /* pass[0].tr_sar_gen_in[0] */
    TRIG_OUT_MUX_7_PASS_GEN_TR_IN1  = 0x40000701u, /* pass[0].tr_sar_gen_in[1] */
    TRIG_OUT_MUX_7_PASS_GEN_TR_IN2  = 0x40000702u, /* pass[0].tr_sar_gen_in[2] */
    TRIG_OUT_MUX_7_PASS_GEN_TR_IN3  = 0x40000703u, /* pass[0].tr_sar_gen_in[3] */
    TRIG_OUT_MUX_7_PASS_GEN_TR_IN4  = 0x40000704u, /* pass[0].tr_sar_gen_in[4] */
    TRIG_OUT_MUX_7_PASS_GEN_TR_IN5  = 0x40000705u, /* pass[0].tr_sar_gen_in[5] */
    TRIG_OUT_MUX_7_PASS_GEN_TR_IN6  = 0x40000706u, /* pass[0].tr_sar_gen_in[6] */
    TRIG_OUT_MUX_7_PASS_GEN_TR_IN7  = 0x40000707u, /* pass[0].tr_sar_gen_in[7] */
    TRIG_OUT_MUX_7_PASS_GEN_TR_IN8  = 0x40000708u, /* pass[0].tr_sar_gen_in[8] */
    TRIG_OUT_MUX_7_PASS_GEN_TR_IN9  = 0x40000709u, /* pass[0].tr_sar_gen_in[9] */
    TRIG_OUT_MUX_7_PASS_GEN_TR_IN10 = 0x4000070Au, /* pass[0].tr_sar_gen_in[10] */
    TRIG_OUT_MUX_7_PASS_GEN_TR_IN11 = 0x4000070Bu /* pass[0].tr_sar_gen_in[11] */
} en_trig_output_pass_tr_t;

/* Trigger Output Group 8 - CAN TT Synchronization triggers */
typedef enum
{
    TRIG_OUT_MUX_8_CAN0_TT_TR_IN0   = 0x40000800u, /* canfd[0].tr_evt_swt_in[0] */
    TRIG_OUT_MUX_8_CAN0_TT_TR_IN1   = 0x40000801u, /* canfd[0].tr_evt_swt_in[1] */
    TRIG_OUT_MUX_8_CAN0_TT_TR_IN2   = 0x40000802u, /* canfd[0].tr_evt_swt_in[2] */
    TRIG_OUT_MUX_8_CAN0_TT_TR_IN3   = 0x40000803u, /* canfd[0].tr_evt_swt_in[3] */
    TRIG_OUT_MUX_8_CAN0_TT_TR_IN4   = 0x40000804u, /* canfd[0].tr_evt_swt_in[4] */
    TRIG_OUT_MUX_8_CAN1_TT_TR_IN0   = 0x40000805u, /* canfd[1].tr_evt_swt_in[0] */
    TRIG_OUT_MUX_8_CAN1_TT_TR_IN1   = 0x40000806u, /* canfd[1].tr_evt_swt_in[1] */
    TRIG_OUT_MUX_8_CAN1_TT_TR_IN2   = 0x40000807u, /* canfd[1].tr_evt_swt_in[2] */
    TRIG_OUT_MUX_8_CAN1_TT_TR_IN3   = 0x40000808u, /* canfd[1].tr_evt_swt_in[3] */
    TRIG_OUT_MUX_8_CAN1_TT_TR_IN4   = 0x40000809u, /* canfd[1].tr_evt_swt_in[4] */
    TRIG_OUT_MUX_8_FLEXRAY_TT_TR_IN = 0x4000080Au /* flexray[0].tr_stpwt_in */
} en_trig_output_can_flexray_tr_t;

/* Trigger Output Group 9 - 2nd level MUX using input from MUX_11/12/13 */
typedef enum
{
    TRIG_OUT_MUX_9_HSIOM_IO_OUTPUT0 = 0x40000900u, /* peri.tr_io_output[0] */
    TRIG_OUT_MUX_9_HSIOM_IO_OUTPUT1 = 0x40000901u, /* peri.tr_io_output[1] */
    TRIG_OUT_MUX_9_CTI_TR_IN0       = 0x40000902u, /* cpuss.cti_tr_in[0] */
    TRIG_OUT_MUX_9_CTI_TR_IN1       = 0x40000903u, /* cpuss.cti_tr_in[1] */
    TRIG_OUT_MUX_9_PERI_DEBUG_FREEZE_TR_IN = 0x40000904u, /* peri.tr_dbg_freeze */
    TRIG_OUT_MUX_9_PASS_DEBUG_FREEZE_TR_IN = 0x40000905u, /* pass[0].tr_debug_freeze */
    TRIG_OUT_MUX_9_SRSS_WDT_DEBUG_FREEZE_TR_IN = 0x40000906u, /* srss.tr_debug_freeze_wdt */
    TRIG_OUT_MUX_9_SRSS_MCWDT_DEBUG_FREEZE_TR_IN2 = 0x40000907u, /* srss.tr_debug_freeze_mcwdt[2] */
    TRIG_OUT_MUX_9_SRSS_MCWDT_DEBUG_FREEZE_TR_IN1 = 0x40000908u, /* srss.tr_debug_freeze_mcwdt[1] */
    TRIG_OUT_MUX_9_SRSS_MCWDT_DEBUG_FREEZE_TR_IN0 = 0x40000909u, /* srss.tr_debug_freeze_mcwdt[0] */
    TRIG_OUT_MUX_9_TCPWM0_DEBUG_FREEZE_TR_IN = 0x4000090Au, /* tcpwm[0].tr_debug_freeze */
    TRIG_OUT_MUX_9_TCPWM1_DEBUG_FREEZE_TR_IN = 0x4000090Bu /* tcpwm[1].tr_debug_freeze */
} en_trig_output_debug_tr_t;

/* Trigger Output Group 10 - Makes all possible triggers visible as I/O signals for debug purposes, or to build external circuitry */
typedef enum
{
    TRIG_OUT_MUX_10_TR_GROUP9_INPUT1 = 0x40000A00u, /* tr_group[9].input[1] */
    TRIG_OUT_MUX_10_TR_GROUP9_INPUT2 = 0x40000A01u, /* tr_group[9].input[2] */
    TRIG_OUT_MUX_10_TR_GROUP9_INPUT3 = 0x40000A02u, /* tr_group[9].input[3] */
    TRIG_OUT_MUX_10_TR_GROUP9_INPUT4 = 0x40000A03u, /* tr_group[9].input[4] */
    TRIG_OUT_MUX_10_TR_GROUP9_INPUT5 = 0x40000A04u /* tr_group[9].input[5] */
} en_trig_output_debug_reduction_1_t;

/* Trigger Output Group 11 - Makes all possible triggers visible as I/O signals for debug purposes, or to build external circuitry */
typedef enum
{
    TRIG_OUT_MUX_11_TR_GROUP9_INPUT6 = 0x40000B00u, /* tr_group[9].input[6] */
    TRIG_OUT_MUX_11_TR_GROUP9_INPUT7 = 0x40000B01u, /* tr_group[9].input[7] */
    TRIG_OUT_MUX_11_TR_GROUP9_INPUT8 = 0x40000B02u, /* tr_group[9].input[8] */
    TRIG_OUT_MUX_11_TR_GROUP9_INPUT9 = 0x40000B03u, /* tr_group[9].input[9] */
    TRIG_OUT_MUX_11_TR_GROUP9_INPUT10 = 0x40000B04u /* tr_group[9].input[10] */
} en_trig_output_debug_reduction_2_t;

/* Trigger Output Group 12 - Makes all possible triggers visible as I/O signals for debug purposes, or to build external circuitry */
typedef enum
{
    TRIG_OUT_MUX_12_TR_GROUP9_INPUT11 = 0x40000C00u, /* tr_group[9].input[11] */
    TRIG_OUT_MUX_12_TR_GROUP9_INPUT12 = 0x40000C01u, /* tr_group[9].input[12] */
    TRIG_OUT_MUX_12_TR_GROUP9_INPUT13 = 0x40000C02u, /* tr_group[9].input[13] */
    TRIG_OUT_MUX_12_TR_GROUP9_INPUT14 = 0x40000C03u, /* tr_group[9].input[14] */
    TRIG_OUT_MUX_12_TR_GROUP9_INPUT15 = 0x40000C04u /* tr_group[9].input[15] */
} en_trig_output_debug_reduction_3_t;

/* Trigger Output Group 0 - CAN DW Triggers (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_0_CAN0_DBG_TO_PDMA0_0 = 0x40001000u, /* cpuss.dw0_tr_in[32] */
    TRIG_OUT_1TO1_0_CAN0_FIFO0_TO_PDMA0_0 = 0x40001001u, /* cpuss.dw0_tr_in[33] */
    TRIG_OUT_1TO1_0_CAN0_FIFO1_TO_PDMA0_0 = 0x40001002u, /* cpuss.dw0_tr_in[34] */
    TRIG_OUT_1TO1_0_CAN0_DBG_TO_PDMA0_1 = 0x40001003u, /* cpuss.dw0_tr_in[35] */
    TRIG_OUT_1TO1_0_CAN0_FIFO0_TO_PDMA0_1 = 0x40001004u, /* cpuss.dw0_tr_in[36] */
    TRIG_OUT_1TO1_0_CAN0_FIFO1_TO_PDMA0_1 = 0x40001005u, /* cpuss.dw0_tr_in[37] */
    TRIG_OUT_1TO1_0_CAN0_DBG_TO_PDMA0_2 = 0x40001006u, /* cpuss.dw0_tr_in[38] */
    TRIG_OUT_1TO1_0_CAN0_FIFO0_TO_PDMA0_2 = 0x40001007u, /* cpuss.dw0_tr_in[39] */
    TRIG_OUT_1TO1_0_CAN0_FIFO1_TO_PDMA0_2 = 0x40001008u, /* cpuss.dw0_tr_in[40] */
    TRIG_OUT_1TO1_0_CAN0_DBG_TO_PDMA0_3 = 0x40001009u, /* cpuss.dw0_tr_in[41] */
    TRIG_OUT_1TO1_0_CAN0_FIFO0_TO_PDMA0_3 = 0x4000100Au, /* cpuss.dw0_tr_in[42] */
    TRIG_OUT_1TO1_0_CAN0_FIFO1_TO_PDMA0_3 = 0x4000100Bu, /* cpuss.dw0_tr_in[43] */
    TRIG_OUT_1TO1_0_CAN0_DBG_TO_PDMA0_4 = 0x4000100Cu, /* cpuss.dw0_tr_in[44] */
    TRIG_OUT_1TO1_0_CAN0_FIFO0_TO_PDMA0_4 = 0x4000100Du, /* cpuss.dw0_tr_in[45] */
    TRIG_OUT_1TO1_0_CAN0_FIFO1_TO_PDMA0_4 = 0x4000100Eu /* cpuss.dw0_tr_in[46] */
} en_trig_output_1to1_can_to_dw0_t;

/* Trigger Output Group 1 - PASS to DW0 direct connect (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA00 = 0x40001100u, /* cpuss.dw0_tr_in[47] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA01 = 0x40001101u, /* cpuss.dw0_tr_in[48] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA02 = 0x40001102u, /* cpuss.dw0_tr_in[49] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA03 = 0x40001103u, /* cpuss.dw0_tr_in[50] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA04 = 0x40001104u, /* cpuss.dw0_tr_in[51] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA05 = 0x40001105u, /* cpuss.dw0_tr_in[52] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA06 = 0x40001106u, /* cpuss.dw0_tr_in[53] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA07 = 0x40001107u, /* cpuss.dw0_tr_in[54] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA08 = 0x40001108u, /* cpuss.dw0_tr_in[55] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA09 = 0x40001109u, /* cpuss.dw0_tr_in[56] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA010 = 0x4000110Au, /* cpuss.dw0_tr_in[57] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA011 = 0x4000110Bu, /* cpuss.dw0_tr_in[58] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA012 = 0x4000110Cu, /* cpuss.dw0_tr_in[59] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA013 = 0x4000110Du, /* cpuss.dw0_tr_in[60] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA014 = 0x4000110Eu, /* cpuss.dw0_tr_in[61] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA015 = 0x4000110Fu, /* cpuss.dw0_tr_in[62] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA016 = 0x40001110u, /* cpuss.dw0_tr_in[63] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA017 = 0x40001111u, /* cpuss.dw0_tr_in[64] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA018 = 0x40001112u, /* cpuss.dw0_tr_in[65] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA019 = 0x40001113u, /* cpuss.dw0_tr_in[66] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA020 = 0x40001114u, /* cpuss.dw0_tr_in[67] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA021 = 0x40001115u, /* cpuss.dw0_tr_in[68] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA022 = 0x40001116u, /* cpuss.dw0_tr_in[69] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA023 = 0x40001117u, /* cpuss.dw0_tr_in[70] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA024 = 0x40001118u, /* cpuss.dw0_tr_in[71] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA025 = 0x40001119u, /* cpuss.dw0_tr_in[72] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA026 = 0x4000111Au, /* cpuss.dw0_tr_in[73] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA027 = 0x4000111Bu, /* cpuss.dw0_tr_in[74] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA028 = 0x4000111Cu, /* cpuss.dw0_tr_in[75] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA029 = 0x4000111Du, /* cpuss.dw0_tr_in[76] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA030 = 0x4000111Eu, /* cpuss.dw0_tr_in[77] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA031 = 0x4000111Fu, /* cpuss.dw0_tr_in[78] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA032 = 0x40001120u, /* cpuss.dw0_tr_in[79] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA033 = 0x40001121u, /* cpuss.dw0_tr_in[80] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA034 = 0x40001122u, /* cpuss.dw0_tr_in[81] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA035 = 0x40001123u, /* cpuss.dw0_tr_in[82] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA036 = 0x40001124u, /* cpuss.dw0_tr_in[83] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA037 = 0x40001125u, /* cpuss.dw0_tr_in[84] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA038 = 0x40001126u, /* cpuss.dw0_tr_in[85] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA039 = 0x40001127u, /* cpuss.dw0_tr_in[86] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA040 = 0x40001128u, /* cpuss.dw0_tr_in[87] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA041 = 0x40001129u, /* cpuss.dw0_tr_in[88] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA042 = 0x4000112Au, /* cpuss.dw0_tr_in[89] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA043 = 0x4000112Bu, /* cpuss.dw0_tr_in[90] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA044 = 0x4000112Cu, /* cpuss.dw0_tr_in[91] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA045 = 0x4000112Du, /* cpuss.dw0_tr_in[92] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA046 = 0x4000112Eu, /* cpuss.dw0_tr_in[93] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA047 = 0x4000112Fu, /* cpuss.dw0_tr_in[94] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA048 = 0x40001130u, /* cpuss.dw0_tr_in[95] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA049 = 0x40001131u, /* cpuss.dw0_tr_in[96] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA050 = 0x40001132u, /* cpuss.dw0_tr_in[97] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA051 = 0x40001133u, /* cpuss.dw0_tr_in[98] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA052 = 0x40001134u, /* cpuss.dw0_tr_in[99] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA053 = 0x40001135u, /* cpuss.dw0_tr_in[100] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA054 = 0x40001136u, /* cpuss.dw0_tr_in[101] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA055 = 0x40001137u, /* cpuss.dw0_tr_in[102] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA056 = 0x40001138u, /* cpuss.dw0_tr_in[103] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA057 = 0x40001139u, /* cpuss.dw0_tr_in[104] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA058 = 0x4000113Au, /* cpuss.dw0_tr_in[105] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA059 = 0x4000113Bu, /* cpuss.dw0_tr_in[106] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA060 = 0x4000113Cu, /* cpuss.dw0_tr_in[107] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA061 = 0x4000113Du, /* cpuss.dw0_tr_in[108] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA062 = 0x4000113Eu, /* cpuss.dw0_tr_in[109] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA063 = 0x4000113Fu, /* cpuss.dw0_tr_in[110] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA064 = 0x40001140u, /* cpuss.dw0_tr_in[111] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA065 = 0x40001141u, /* cpuss.dw0_tr_in[112] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA066 = 0x40001142u, /* cpuss.dw0_tr_in[113] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA067 = 0x40001143u, /* cpuss.dw0_tr_in[114] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA068 = 0x40001144u, /* cpuss.dw0_tr_in[115] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA069 = 0x40001145u, /* cpuss.dw0_tr_in[116] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA070 = 0x40001146u, /* cpuss.dw0_tr_in[117] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA071 = 0x40001147u, /* cpuss.dw0_tr_in[118] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA072 = 0x40001148u, /* cpuss.dw0_tr_in[119] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA073 = 0x40001149u, /* cpuss.dw0_tr_in[120] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA074 = 0x4000114Au, /* cpuss.dw0_tr_in[121] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA075 = 0x4000114Bu, /* cpuss.dw0_tr_in[122] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA076 = 0x4000114Cu, /* cpuss.dw0_tr_in[123] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA077 = 0x4000114Du, /* cpuss.dw0_tr_in[124] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA078 = 0x4000114Eu, /* cpuss.dw0_tr_in[125] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA079 = 0x4000114Fu, /* cpuss.dw0_tr_in[126] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA080 = 0x40001150u, /* cpuss.dw0_tr_in[127] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA081 = 0x40001151u, /* cpuss.dw0_tr_in[128] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA082 = 0x40001152u, /* cpuss.dw0_tr_in[129] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA083 = 0x40001153u, /* cpuss.dw0_tr_in[130] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA084 = 0x40001154u, /* cpuss.dw0_tr_in[131] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA085 = 0x40001155u, /* cpuss.dw0_tr_in[132] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA086 = 0x40001156u, /* cpuss.dw0_tr_in[133] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA087 = 0x40001157u, /* cpuss.dw0_tr_in[134] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA088 = 0x40001158u, /* cpuss.dw0_tr_in[135] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA089 = 0x40001159u, /* cpuss.dw0_tr_in[136] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA090 = 0x4000115Au, /* cpuss.dw0_tr_in[137] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA091 = 0x4000115Bu, /* cpuss.dw0_tr_in[138] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA092 = 0x4000115Cu, /* cpuss.dw0_tr_in[139] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA093 = 0x4000115Du, /* cpuss.dw0_tr_in[140] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA094 = 0x4000115Eu, /* cpuss.dw0_tr_in[141] */
    TRIG_OUT_1TO1_1_PASS_CH_DONE_TO_PDMA095 = 0x4000115Fu /* cpuss.dw0_tr_in[142] */
} en_trig_output_1to1_sar_to_dw0_t;

/* Trigger Output Group 2 - SCB DW Triggers (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_2_SCB_TX_TO_PDMA10 = 0x40001200u, /* cpuss.dw1_tr_in[16] */
    TRIG_OUT_1TO1_2_SCB_RX_TO_PDMA10 = 0x40001201u, /* cpuss.dw1_tr_in[17] */
    TRIG_OUT_1TO1_2_SCB_TX_TO_PDMA11 = 0x40001202u, /* cpuss.dw1_tr_in[18] */
    TRIG_OUT_1TO1_2_SCB_RX_TO_PDMA11 = 0x40001203u, /* cpuss.dw1_tr_in[19] */
    TRIG_OUT_1TO1_2_SCB_TX_TO_PDMA12 = 0x40001204u, /* cpuss.dw1_tr_in[20] */
    TRIG_OUT_1TO1_2_SCB_RX_TO_PDMA12 = 0x40001205u, /* cpuss.dw1_tr_in[21] */
    TRIG_OUT_1TO1_2_SCB_TX_TO_PDMA13 = 0x40001206u, /* cpuss.dw1_tr_in[22] */
    TRIG_OUT_1TO1_2_SCB_RX_TO_PDMA13 = 0x40001207u, /* cpuss.dw1_tr_in[23] */
    TRIG_OUT_1TO1_2_SCB_TX_TO_PDMA14 = 0x40001208u, /* cpuss.dw1_tr_in[24] */
    TRIG_OUT_1TO1_2_SCB_RX_TO_PDMA14 = 0x40001209u, /* cpuss.dw1_tr_in[25] */
    TRIG_OUT_1TO1_2_SCB_TX_TO_PDMA15 = 0x4000120Au, /* cpuss.dw1_tr_in[26] */
    TRIG_OUT_1TO1_2_SCB_RX_TO_PDMA15 = 0x4000120Bu, /* cpuss.dw1_tr_in[27] */
    TRIG_OUT_1TO1_2_SCB_TX_TO_PDMA16 = 0x4000120Cu, /* cpuss.dw1_tr_in[28] */
    TRIG_OUT_1TO1_2_SCB_RX_TO_PDMA16 = 0x4000120Du, /* cpuss.dw1_tr_in[29] */
    TRIG_OUT_1TO1_2_SCB_TX_TO_PDMA17 = 0x4000120Eu, /* cpuss.dw1_tr_in[30] */
    TRIG_OUT_1TO1_2_SCB_RX_TO_PDMA17 = 0x4000120Fu, /* cpuss.dw1_tr_in[31] */
    TRIG_OUT_1TO1_2_SCB_TX_TO_PDMA18 = 0x40001210u, /* cpuss.dw1_tr_in[32] */
    TRIG_OUT_1TO1_2_SCB_RX_TO_PDMA18 = 0x40001211u, /* cpuss.dw1_tr_in[33] */
    TRIG_OUT_1TO1_2_SCB_TX_TO_PDMA19 = 0x40001212u, /* cpuss.dw1_tr_in[34] */
    TRIG_OUT_1TO1_2_SCB_RX_TO_PDMA19 = 0x40001213u, /* cpuss.dw1_tr_in[35] */
    TRIG_OUT_1TO1_2_SCB_TX_TO_PDMA110 = 0x40001214u, /* cpuss.dw1_tr_in[36] */
    TRIG_OUT_1TO1_2_SCB_RX_TO_PDMA110 = 0x40001215u /* cpuss.dw1_tr_in[37] */
} en_trig_output_1to1_scb_to_dw1_t;

/* Trigger Output Group 3 - SMIF DW Triggers (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_3_SMIF_TX_TO_PDMA1 = 0x40001300u, /* cpuss.dw1_tr_in[53] */
    TRIG_OUT_1TO1_3_SMIF_RX_TO_PDMA1 = 0x40001301u /* cpuss.dw1_tr_in[54] */
} en_trig_output_1to1_smif_to_dw1_t;

/* Trigger Output Group 4 - More CAN DW triggers (on DW1 for max BW) (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_4_CAN1_DBG_TO_PDMA1_0 = 0x40001400u, /* cpuss.dw1_tr_in[38] */
    TRIG_OUT_1TO1_4_CAN1_FIFO0_TO_PDMA1_0 = 0x40001401u, /* cpuss.dw1_tr_in[39] */
    TRIG_OUT_1TO1_4_CAN1_FIFO1_TO_PDMA1_0 = 0x40001402u, /* cpuss.dw1_tr_in[40] */
    TRIG_OUT_1TO1_4_CAN1_DBG_TO_PDMA1_1 = 0x40001403u, /* cpuss.dw1_tr_in[41] */
    TRIG_OUT_1TO1_4_CAN1_FIFO0_TO_PDMA1_1 = 0x40001404u, /* cpuss.dw1_tr_in[42] */
    TRIG_OUT_1TO1_4_CAN1_FIFO1_TO_PDMA1_1 = 0x40001405u, /* cpuss.dw1_tr_in[43] */
    TRIG_OUT_1TO1_4_CAN1_DBG_TO_PDMA1_2 = 0x40001406u, /* cpuss.dw1_tr_in[44] */
    TRIG_OUT_1TO1_4_CAN1_FIFO0_TO_PDMA1_2 = 0x40001407u, /* cpuss.dw1_tr_in[45] */
    TRIG_OUT_1TO1_4_CAN1_FIFO1_TO_PDMA1_2 = 0x40001408u, /* cpuss.dw1_tr_in[46] */
    TRIG_OUT_1TO1_4_CAN1_DBG_TO_PDMA1_3 = 0x40001409u, /* cpuss.dw1_tr_in[47] */
    TRIG_OUT_1TO1_4_CAN1_FIFO0_TO_PDMA1_3 = 0x4000140Au, /* cpuss.dw1_tr_in[48] */
    TRIG_OUT_1TO1_4_CAN1_FIFO1_TO_PDMA1_3 = 0x4000140Bu, /* cpuss.dw1_tr_in[49] */
    TRIG_OUT_1TO1_4_CAN1_DBG_TO_PDMA1_4 = 0x4000140Cu, /* cpuss.dw1_tr_in[50] */
    TRIG_OUT_1TO1_4_CAN1_FIFO0_TO_PDMA1_4 = 0x4000140Du, /* cpuss.dw1_tr_in[51] */
    TRIG_OUT_1TO1_4_CAN1_FIFO1_TO_PDMA1_4 = 0x4000140Eu /* cpuss.dw1_tr_in[52] */
} en_trig_output_1to1_can_to_dw1_t;

/* Trigger Output Group 5 - I2S DW Triggers (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_5_I2S_TX_TO_PDMA10 = 0x40001500u, /* cpuss.dw1_tr_in[55] */
    TRIG_OUT_1TO1_5_I2S_RX_TO_PDMA10 = 0x40001501u, /* cpuss.dw1_tr_in[56] */
    TRIG_OUT_1TO1_5_I2S_TX_TO_PDMA11 = 0x40001502u, /* cpuss.dw1_tr_in[57] */
    TRIG_OUT_1TO1_5_I2S_RX_TO_PDMA11 = 0x40001503u, /* cpuss.dw1_tr_in[58] */
    TRIG_OUT_1TO1_5_I2S_TX_TO_PDMA12 = 0x40001504u, /* cpuss.dw1_tr_in[59] */
    TRIG_OUT_1TO1_5_I2S_RX_TO_PDMA12 = 0x40001505u /* cpuss.dw1_tr_in[60] */
} en_trig_output_1to1_i2s_to_dw1_t;

/* Trigger Output Group 6 - PASS to PWM direct connect (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL0 = 0x40001600u, /* tcpwm[1].tr_one_cnt_in[2] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL1 = 0x40001601u, /* tcpwm[1].tr_one_cnt_in[5] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL2 = 0x40001602u, /* tcpwm[1].tr_one_cnt_in[8] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL3 = 0x40001603u, /* tcpwm[1].tr_one_cnt_in[11] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL4 = 0x40001604u, /* tcpwm[1].tr_one_cnt_in[14] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL5 = 0x40001605u, /* tcpwm[1].tr_one_cnt_in[17] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL6 = 0x40001606u, /* tcpwm[1].tr_one_cnt_in[20] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL7 = 0x40001607u, /* tcpwm[1].tr_one_cnt_in[23] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL8 = 0x40001608u, /* tcpwm[1].tr_one_cnt_in[26] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL9 = 0x40001609u, /* tcpwm[1].tr_one_cnt_in[29] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL10 = 0x4000160Au, /* tcpwm[1].tr_one_cnt_in[32] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL11 = 0x4000160Bu, /* tcpwm[1].tr_one_cnt_in[35] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL12 = 0x4000160Cu, /* tcpwm[1].tr_one_cnt_in[38] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL13 = 0x4000160Du, /* tcpwm[1].tr_one_cnt_in[41] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL14 = 0x4000160Eu, /* tcpwm[1].tr_one_cnt_in[44] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL15 = 0x4000160Fu, /* tcpwm[1].tr_one_cnt_in[47] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL16 = 0x40001610u, /* tcpwm[1].tr_one_cnt_in[50] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL17 = 0x40001611u, /* tcpwm[1].tr_one_cnt_in[53] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL18 = 0x40001612u, /* tcpwm[1].tr_one_cnt_in[56] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL19 = 0x40001613u, /* tcpwm[1].tr_one_cnt_in[59] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL20 = 0x40001614u, /* tcpwm[1].tr_one_cnt_in[62] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL21 = 0x40001615u, /* tcpwm[1].tr_one_cnt_in[65] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL22 = 0x40001616u, /* tcpwm[1].tr_one_cnt_in[68] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL23 = 0x40001617u, /* tcpwm[1].tr_one_cnt_in[71] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL24 = 0x40001618u, /* tcpwm[1].tr_one_cnt_in[74] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL25 = 0x40001619u, /* tcpwm[1].tr_one_cnt_in[77] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL26 = 0x4000161Au, /* tcpwm[1].tr_one_cnt_in[80] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL27 = 0x4000161Bu, /* tcpwm[1].tr_one_cnt_in[83] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL28 = 0x4000161Cu, /* tcpwm[1].tr_one_cnt_in[86] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL29 = 0x4000161Du, /* tcpwm[1].tr_one_cnt_in[89] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL30 = 0x4000161Eu, /* tcpwm[1].tr_one_cnt_in[92] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL31 = 0x4000161Fu, /* tcpwm[1].tr_one_cnt_in[95] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL32 = 0x40001620u, /* tcpwm[1].tr_one_cnt_in[98] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL33 = 0x40001621u, /* tcpwm[1].tr_one_cnt_in[101] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL34 = 0x40001622u, /* tcpwm[1].tr_one_cnt_in[104] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL35 = 0x40001623u, /* tcpwm[1].tr_one_cnt_in[107] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL36 = 0x40001624u, /* tcpwm[1].tr_one_cnt_in[110] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL37 = 0x40001625u, /* tcpwm[1].tr_one_cnt_in[113] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL38 = 0x40001626u, /* tcpwm[1].tr_one_cnt_in[116] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL39 = 0x40001627u, /* tcpwm[1].tr_one_cnt_in[119] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL40 = 0x40001628u, /* tcpwm[1].tr_one_cnt_in[122] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL41 = 0x40001629u, /* tcpwm[1].tr_one_cnt_in[125] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL42 = 0x4000162Au, /* tcpwm[1].tr_one_cnt_in[128] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL43 = 0x4000162Bu, /* tcpwm[1].tr_one_cnt_in[131] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL44 = 0x4000162Cu, /* tcpwm[1].tr_one_cnt_in[134] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL45 = 0x4000162Du, /* tcpwm[1].tr_one_cnt_in[137] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL46 = 0x4000162Eu, /* tcpwm[1].tr_one_cnt_in[140] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL47 = 0x4000162Fu, /* tcpwm[1].tr_one_cnt_in[143] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL48 = 0x40001630u, /* tcpwm[1].tr_one_cnt_in[146] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL49 = 0x40001631u, /* tcpwm[1].tr_one_cnt_in[149] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL50 = 0x40001632u, /* tcpwm[1].tr_one_cnt_in[152] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL51 = 0x40001633u, /* tcpwm[1].tr_one_cnt_in[155] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL52 = 0x40001634u, /* tcpwm[1].tr_one_cnt_in[158] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL53 = 0x40001635u, /* tcpwm[1].tr_one_cnt_in[161] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL54 = 0x40001636u, /* tcpwm[1].tr_one_cnt_in[164] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL55 = 0x40001637u, /* tcpwm[1].tr_one_cnt_in[167] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL56 = 0x40001638u, /* tcpwm[1].tr_one_cnt_in[170] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL57 = 0x40001639u, /* tcpwm[1].tr_one_cnt_in[173] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL58 = 0x4000163Au, /* tcpwm[1].tr_one_cnt_in[176] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL59 = 0x4000163Bu, /* tcpwm[1].tr_one_cnt_in[179] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL60 = 0x4000163Cu, /* tcpwm[1].tr_one_cnt_in[182] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL61 = 0x4000163Du, /* tcpwm[1].tr_one_cnt_in[185] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL62 = 0x4000163Eu, /* tcpwm[1].tr_one_cnt_in[188] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL63 = 0x4000163Fu, /* tcpwm[1].tr_one_cnt_in[191] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL64 = 0x40001640u, /* tcpwm[1].tr_one_cnt_in[194] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL65 = 0x40001641u, /* tcpwm[1].tr_one_cnt_in[197] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL66 = 0x40001642u, /* tcpwm[1].tr_one_cnt_in[200] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL67 = 0x40001643u, /* tcpwm[1].tr_one_cnt_in[203] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL68 = 0x40001644u, /* tcpwm[1].tr_one_cnt_in[206] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL69 = 0x40001645u, /* tcpwm[1].tr_one_cnt_in[209] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL70 = 0x40001646u, /* tcpwm[1].tr_one_cnt_in[212] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL71 = 0x40001647u, /* tcpwm[1].tr_one_cnt_in[215] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL72 = 0x40001648u, /* tcpwm[1].tr_one_cnt_in[218] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL73 = 0x40001649u, /* tcpwm[1].tr_one_cnt_in[221] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL74 = 0x4000164Au, /* tcpwm[1].tr_one_cnt_in[224] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL75 = 0x4000164Bu, /* tcpwm[1].tr_one_cnt_in[227] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL76 = 0x4000164Cu, /* tcpwm[1].tr_one_cnt_in[230] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL77 = 0x4000164Du, /* tcpwm[1].tr_one_cnt_in[233] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL78 = 0x4000164Eu, /* tcpwm[1].tr_one_cnt_in[236] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL79 = 0x4000164Fu, /* tcpwm[1].tr_one_cnt_in[239] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL80 = 0x40001650u, /* tcpwm[1].tr_one_cnt_in[242] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL81 = 0x40001651u, /* tcpwm[1].tr_one_cnt_in[245] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL82 = 0x40001652u, /* tcpwm[1].tr_one_cnt_in[248] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL83 = 0x40001653u, /* tcpwm[1].tr_one_cnt_in[251] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL84 = 0x40001654u, /* tcpwm[1].tr_one_cnt_in[770] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL85 = 0x40001655u, /* tcpwm[1].tr_one_cnt_in[773] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL86 = 0x40001656u, /* tcpwm[1].tr_one_cnt_in[776] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL87 = 0x40001657u, /* tcpwm[1].tr_one_cnt_in[779] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL88 = 0x40001658u, /* tcpwm[1].tr_one_cnt_in[782] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL89 = 0x40001659u, /* tcpwm[1].tr_one_cnt_in[785] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL90 = 0x4000165Au, /* tcpwm[1].tr_one_cnt_in[788] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL91 = 0x4000165Bu, /* tcpwm[1].tr_one_cnt_in[791] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL92 = 0x4000165Cu, /* tcpwm[1].tr_one_cnt_in[794] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL93 = 0x4000165Du, /* tcpwm[1].tr_one_cnt_in[797] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL94 = 0x4000165Eu, /* tcpwm[1].tr_one_cnt_in[800] */
    TRIG_OUT_1TO1_6_PASS_CH_RANGEVIO_TO_PWM1_KILL95 = 0x4000165Fu /* tcpwm[1].tr_one_cnt_in[803] */
} en_trig_output_1to1_sar_to_tcpwm1_t;

/* Trigger Output Group 7 -  (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR0 = 0x40001700u, /* pass[0].tr_sar_ch_in[0] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR1 = 0x40001701u, /* pass[0].tr_sar_ch_in[1] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR2 = 0x40001702u, /* pass[0].tr_sar_ch_in[2] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR3 = 0x40001703u, /* pass[0].tr_sar_ch_in[3] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR4 = 0x40001704u, /* pass[0].tr_sar_ch_in[4] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR5 = 0x40001705u, /* pass[0].tr_sar_ch_in[5] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR6 = 0x40001706u, /* pass[0].tr_sar_ch_in[6] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR7 = 0x40001707u, /* pass[0].tr_sar_ch_in[7] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR8 = 0x40001708u, /* pass[0].tr_sar_ch_in[8] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR9 = 0x40001709u, /* pass[0].tr_sar_ch_in[9] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR10 = 0x4000170Au, /* pass[0].tr_sar_ch_in[10] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR11 = 0x4000170Bu, /* pass[0].tr_sar_ch_in[11] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR12 = 0x4000170Cu, /* pass[0].tr_sar_ch_in[12] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR13 = 0x4000170Du, /* pass[0].tr_sar_ch_in[13] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR14 = 0x4000170Eu, /* pass[0].tr_sar_ch_in[14] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR15 = 0x4000170Fu, /* pass[0].tr_sar_ch_in[15] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR16 = 0x40001710u, /* pass[0].tr_sar_ch_in[16] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR17 = 0x40001711u, /* pass[0].tr_sar_ch_in[17] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR18 = 0x40001712u, /* pass[0].tr_sar_ch_in[18] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR19 = 0x40001713u, /* pass[0].tr_sar_ch_in[19] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR20 = 0x40001714u, /* pass[0].tr_sar_ch_in[20] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR21 = 0x40001715u, /* pass[0].tr_sar_ch_in[21] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR22 = 0x40001716u, /* pass[0].tr_sar_ch_in[22] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR23 = 0x40001717u, /* pass[0].tr_sar_ch_in[23] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR24 = 0x40001718u, /* pass[0].tr_sar_ch_in[24] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR25 = 0x40001719u, /* pass[0].tr_sar_ch_in[25] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR26 = 0x4000171Au, /* pass[0].tr_sar_ch_in[26] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR27 = 0x4000171Bu, /* pass[0].tr_sar_ch_in[27] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR28 = 0x4000171Cu, /* pass[0].tr_sar_ch_in[28] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR29 = 0x4000171Du, /* pass[0].tr_sar_ch_in[29] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR30 = 0x4000171Eu, /* pass[0].tr_sar_ch_in[30] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR31 = 0x4000171Fu, /* pass[0].tr_sar_ch_in[31] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR32 = 0x40001720u, /* pass[0].tr_sar_ch_in[32] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR33 = 0x40001721u, /* pass[0].tr_sar_ch_in[33] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR34 = 0x40001722u, /* pass[0].tr_sar_ch_in[34] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR35 = 0x40001723u, /* pass[0].tr_sar_ch_in[35] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR36 = 0x40001724u, /* pass[0].tr_sar_ch_in[36] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR37 = 0x40001725u, /* pass[0].tr_sar_ch_in[37] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR38 = 0x40001726u, /* pass[0].tr_sar_ch_in[38] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR39 = 0x40001727u, /* pass[0].tr_sar_ch_in[39] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR40 = 0x40001728u, /* pass[0].tr_sar_ch_in[40] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR41 = 0x40001729u, /* pass[0].tr_sar_ch_in[41] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR42 = 0x4000172Au, /* pass[0].tr_sar_ch_in[42] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR43 = 0x4000172Bu, /* pass[0].tr_sar_ch_in[43] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR44 = 0x4000172Cu, /* pass[0].tr_sar_ch_in[44] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR45 = 0x4000172Du, /* pass[0].tr_sar_ch_in[45] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR46 = 0x4000172Eu, /* pass[0].tr_sar_ch_in[46] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR47 = 0x4000172Fu, /* pass[0].tr_sar_ch_in[47] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR48 = 0x40001730u, /* pass[0].tr_sar_ch_in[48] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR49 = 0x40001731u, /* pass[0].tr_sar_ch_in[49] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR50 = 0x40001732u, /* pass[0].tr_sar_ch_in[50] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR51 = 0x40001733u, /* pass[0].tr_sar_ch_in[51] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR52 = 0x40001734u, /* pass[0].tr_sar_ch_in[52] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR53 = 0x40001735u, /* pass[0].tr_sar_ch_in[53] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR54 = 0x40001736u, /* pass[0].tr_sar_ch_in[54] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR55 = 0x40001737u, /* pass[0].tr_sar_ch_in[55] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR56 = 0x40001738u, /* pass[0].tr_sar_ch_in[56] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR57 = 0x40001739u, /* pass[0].tr_sar_ch_in[57] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR58 = 0x4000173Au, /* pass[0].tr_sar_ch_in[58] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR59 = 0x4000173Bu, /* pass[0].tr_sar_ch_in[59] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR60 = 0x4000173Cu, /* pass[0].tr_sar_ch_in[60] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR61 = 0x4000173Du, /* pass[0].tr_sar_ch_in[61] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR62 = 0x4000173Eu, /* pass[0].tr_sar_ch_in[62] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR63 = 0x4000173Fu, /* pass[0].tr_sar_ch_in[63] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR64 = 0x40001740u, /* pass[0].tr_sar_ch_in[64] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR65 = 0x40001741u, /* pass[0].tr_sar_ch_in[65] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR66 = 0x40001742u, /* pass[0].tr_sar_ch_in[66] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR67 = 0x40001743u, /* pass[0].tr_sar_ch_in[67] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR68 = 0x40001744u, /* pass[0].tr_sar_ch_in[68] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR69 = 0x40001745u, /* pass[0].tr_sar_ch_in[69] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR70 = 0x40001746u, /* pass[0].tr_sar_ch_in[70] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR71 = 0x40001747u, /* pass[0].tr_sar_ch_in[71] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR72 = 0x40001748u, /* pass[0].tr_sar_ch_in[72] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR73 = 0x40001749u, /* pass[0].tr_sar_ch_in[73] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR74 = 0x4000174Au, /* pass[0].tr_sar_ch_in[74] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR75 = 0x4000174Bu, /* pass[0].tr_sar_ch_in[75] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR76 = 0x4000174Cu, /* pass[0].tr_sar_ch_in[76] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR77 = 0x4000174Du, /* pass[0].tr_sar_ch_in[77] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR78 = 0x4000174Eu, /* pass[0].tr_sar_ch_in[78] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR79 = 0x4000174Fu, /* pass[0].tr_sar_ch_in[79] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR80 = 0x40001750u, /* pass[0].tr_sar_ch_in[80] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR81 = 0x40001751u, /* pass[0].tr_sar_ch_in[81] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR82 = 0x40001752u, /* pass[0].tr_sar_ch_in[82] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR83 = 0x40001753u, /* pass[0].tr_sar_ch_in[83] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR256 = 0x40001754u, /* pass[0].tr_sar_ch_in[84] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR257 = 0x40001755u, /* pass[0].tr_sar_ch_in[85] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR258 = 0x40001756u, /* pass[0].tr_sar_ch_in[86] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR259 = 0x40001757u, /* pass[0].tr_sar_ch_in[87] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR260 = 0x40001758u, /* pass[0].tr_sar_ch_in[88] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR261 = 0x40001759u, /* pass[0].tr_sar_ch_in[89] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR262 = 0x4000175Au, /* pass[0].tr_sar_ch_in[90] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR263 = 0x4000175Bu, /* pass[0].tr_sar_ch_in[91] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR264 = 0x4000175Cu, /* pass[0].tr_sar_ch_in[92] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR265 = 0x4000175Du, /* pass[0].tr_sar_ch_in[93] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR266 = 0x4000175Eu, /* pass[0].tr_sar_ch_in[94] */
    TRIG_OUT_1TO1_7_TCPWM1_TO_PASS_CH_TR267 = 0x4000175Fu /* pass[0].tr_sar_ch_in[95] */
} en_trig_output_1to1_tcpwm1_to_sar_t;

/* Trigger Output Group 8 - Acknowledge triggers from DW1 to CAN (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_8_PDMA1_ACK_TO_CAN1_0 = 0x40001800u, /* canfd[1].tr_dbg_dma_ack[0] */
    TRIG_OUT_1TO1_8_PDMA1_ACK_TO_CAN1_1 = 0x40001801u, /* canfd[1].tr_dbg_dma_ack[1] */
    TRIG_OUT_1TO1_8_PDMA1_ACK_TO_CAN1_2 = 0x40001802u, /* canfd[1].tr_dbg_dma_ack[2] */
    TRIG_OUT_1TO1_8_PDMA1_ACK_TO_CAN1_3 = 0x40001803u, /* canfd[1].tr_dbg_dma_ack[3] */
    TRIG_OUT_1TO1_8_PDMA1_ACK_TO_CAN1_4 = 0x40001804u /* canfd[1].tr_dbg_dma_ack[4] */
} en_trig_output_1to1_dw1_to_can1_t;

/* Trigger Output Group 9 - Acknowledge triggers from DW0 to CAN (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_9_PDMA0_ACK_TO_CAN0_0 = 0x40001900u, /* canfd[0].tr_dbg_dma_ack[0] */
    TRIG_OUT_1TO1_9_PDMA0_ACK_TO_CAN0_1 = 0x40001901u, /* canfd[0].tr_dbg_dma_ack[1] */
    TRIG_OUT_1TO1_9_PDMA0_ACK_TO_CAN0_2 = 0x40001902u, /* canfd[0].tr_dbg_dma_ack[2] */
    TRIG_OUT_1TO1_9_PDMA0_ACK_TO_CAN0_3 = 0x40001903u, /* canfd[0].tr_dbg_dma_ack[3] */
    TRIG_OUT_1TO1_9_PDMA0_ACK_TO_CAN0_4 = 0x40001904u /* canfd[0].tr_dbg_dma_ack[4] */
} en_trig_output_1to1_dw0_to_can0_t;

/* Trigger Output Group 10 -  (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR0 = 0x40001A00u, /* lin[0].tr_cmd_tx_header[0] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR1 = 0x40001A01u, /* lin[0].tr_cmd_tx_header[1] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR2 = 0x40001A02u, /* lin[0].tr_cmd_tx_header[2] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR3 = 0x40001A03u, /* lin[0].tr_cmd_tx_header[3] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR4 = 0x40001A04u, /* lin[0].tr_cmd_tx_header[4] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR5 = 0x40001A05u, /* lin[0].tr_cmd_tx_header[5] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR6 = 0x40001A06u, /* lin[0].tr_cmd_tx_header[6] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR7 = 0x40001A07u, /* lin[0].tr_cmd_tx_header[7] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR8 = 0x40001A08u, /* lin[0].tr_cmd_tx_header[8] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR9 = 0x40001A09u, /* lin[0].tr_cmd_tx_header[9] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR10 = 0x40001A0Au, /* lin[0].tr_cmd_tx_header[10] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR11 = 0x40001A0Bu, /* lin[0].tr_cmd_tx_header[11] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR12 = 0x40001A0Cu, /* lin[0].tr_cmd_tx_header[12] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR13 = 0x40001A0Du, /* lin[0].tr_cmd_tx_header[13] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR14 = 0x40001A0Eu, /* lin[0].tr_cmd_tx_header[14] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR15 = 0x40001A0Fu, /* lin[0].tr_cmd_tx_header[15] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR16 = 0x40001A10u, /* lin[0].tr_cmd_tx_header[16] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR17 = 0x40001A11u, /* lin[0].tr_cmd_tx_header[17] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR18 = 0x40001A12u, /* lin[0].tr_cmd_tx_header[18] */
    TRIG_OUT_1TO1_10_TCPWM1_TO_LIN_TR19 = 0x40001A13u /* lin[0].tr_cmd_tx_header[19] */
} en_trig_output_1to1_tcpwm_to_lin_t;

/* Trigger Output Group 11 -  (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_11_FLEXRAY_IBF_TR_TO_PDMA1 = 0x40001B00u, /* cpuss.dw1_tr_in[61] */
    TRIG_OUT_1TO1_11_FLEXRAY_OBF_TR_TO_PDMA1 = 0x40001B01u /* cpuss.dw1_tr_in[62] */
} en_trig_output_1to1_flexyray_to_dw1_t;

/* Trigger Output Group 12 -  (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_12_PDMA1_61_TO_PDMA1_63 = 0x40001C00u, /* cpuss.dw1_tr_in[63] */
    TRIG_OUT_1TO1_12_PDMA1_62_TO_PDMA1_64 = 0x40001C01u /* cpuss.dw1_tr_in[64] */
} en_trig_output_1to1_dw1_to_dw1_t;

/* Trigger Output Group 13 -  (OneToOne) */
typedef enum
{
    TRIG_OUT_1TO1_13_PDMA1_TO_FLEXRAY_IBF_TR = 0x40001D00u, /* flexray[0].tr_ibf_in */
    TRIG_OUT_1TO1_13_PDMA1_TO_FLEXRAY_OBF_TR = 0x40001D01u /* flexray[0].tr_obf_in */
} en_trig_output_1to1_dw1_to_flexray_t;

/* Level or edge detection setting for a trigger mux */
typedef enum
{
    /* The trigger is a simple level output */
    TRIGGER_TYPE_LEVEL = 0u,
    /* The trigger is synchronized to the consumer blocks clock
       and a two cycle pulse is generated on this clock */
    TRIGGER_TYPE_EDGE = 1u
} en_trig_type_t;

/* Trigger Type Defines */
/* TCPWM Trigger Types */
#define TRIGGER_TYPE_TCPWM_TR_DEBUG_FREEZE      TRIGGER_TYPE_LEVEL
/* SCB Trigger Types */
#define TRIGGER_TYPE_SCB_TR_TX_REQ              TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SCB_TR_RX_REQ              TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SCB_TR_I2C_SCL_FILTERED    TRIGGER_TYPE_LEVEL
/* LIN Trigger Types */
#define TRIGGER_TYPE_LIN_TR_CMD_TX_HEADER       TRIGGER_TYPE_EDGE
/* CANFD Trigger Types */
#define TRIGGER_TYPE_CANFD_TR_TMP_RTP_OUT       TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CANFD_TR_DBG_DMA_REQ       TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CANFD_TR_FIFO0             TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CANFD_TR_FIFO1             TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CANFD_TR_EVT_SWT_IN        TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CANFD_TR_DBG_DMA_ACK       TRIGGER_TYPE_EDGE
/* PERI Trigger Types */
#define TRIGGER_TYPE_PERI_TR_IO_INPUT__LEVEL    TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PERI_TR_IO_INPUT__EDGE     TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PERI_TR_IO_OUTPUT__LEVEL   TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PERI_TR_IO_OUTPUT__EDGE    TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PERI_TR_DBG_FREEZE         TRIGGER_TYPE_LEVEL
/* CPUSS Trigger Types */
#define TRIGGER_TYPE_CPUSS_DW0_TR_IN__LEVEL     TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CPUSS_DW0_TR_IN__EDGE      TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DW1_TR_IN__LEVEL     TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CPUSS_DW1_TR_IN__EDGE      TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DMAC_TR_IN__LEVEL    TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_CPUSS_DMAC_TR_IN__EDGE     TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DW0_TR_OUT           TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DW1_TR_OUT           TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_DMAC_TR_OUT          TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_TR_FAULT             TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_CTI_TR_OUT           TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_CPUSS_CTI_TR_IN            TRIGGER_TYPE_EDGE
/* PASS Trigger Types */
#define TRIGGER_TYPE_PASS_TR_SAR_GEN_OUT__LEVEL TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PASS_TR_SAR_GEN_OUT__EDGE  TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PASS_TR_SAR_GEN_IN__LEVEL  TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PASS_TR_SAR_GEN_IN__EDGE   TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PASS_TR_DEBUG_FREEZE       TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PASS_TR_SAR_CH_DONE__LEVEL TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PASS_TR_SAR_CH_DONE__EDGE  TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PASS_TR_SAR_CH_RANGEVIO    TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_PASS_TR_SAR_CH_IN__LEVEL   TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_PASS_TR_SAR_CH_IN__EDGE    TRIGGER_TYPE_EDGE
/* SRSS Trigger Types */
#define TRIGGER_TYPE_SRSS_TR_DEBUG_FREEZE_WDT   TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SRSS_TR_DEBUG_FREEZE_MCWDT TRIGGER_TYPE_LEVEL
/* SMIF Trigger Types */
#define TRIGGER_TYPE_SMIF_TR_TX_REQ             TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_SMIF_TR_RX_REQ             TRIGGER_TYPE_LEVEL
/* FLEXRAY Trigger Types */
#define TRIGGER_TYPE_FLEXRAY_TR_TINT0_OUT       TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_FLEXRAY_TR_IBF_OUT         TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_FLEXRAY_TR_OBF_OUT         TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_FLEXRAY_TR_STPWT_IN        TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_FLEXRAY_TR_IBF_IN          TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_FLEXRAY_TR_OBF_IN          TRIGGER_TYPE_EDGE
/* AUDIOSS Trigger Types */
#define TRIGGER_TYPE_AUDIOSS_TR_I2S_TX_REQ      TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_AUDIOSS_TR_I2S_RX_REQ      TRIGGER_TYPE_LEVEL
/* TR_GROUP Trigger Types */
#define TRIGGER_TYPE_TR_GROUP_OUTPUT__LEVEL     TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_TR_GROUP_OUTPUT__EDGE      TRIGGER_TYPE_EDGE
#define TRIGGER_TYPE_TR_GROUP_INPUT__LEVEL      TRIGGER_TYPE_LEVEL
#define TRIGGER_TYPE_TR_GROUP_INPUT__EDGE       TRIGGER_TYPE_EDGE

/* Fault connections */
typedef enum
{
    CPUSS_MPU_VIO_0                 = 0x0000u,
    CPUSS_MPU_VIO_1                 = 0x0001u,
    CPUSS_MPU_VIO_2                 = 0x0002u,
    CPUSS_MPU_VIO_3                 = 0x0003u,
    CPUSS_MPU_VIO_4                 = 0x0004u,
    CPUSS_MPU_VIO_5                 = 0x0005u,
    CPUSS_MPU_VIO_9                 = 0x0009u,
    CPUSS_MPU_VIO_10                = 0x000Au,
    CPUSS_MPU_VIO_13                = 0x000Du,
    CPUSS_MPU_VIO_14                = 0x000Eu,
    CPUSS_MPU_VIO_15                = 0x000Fu,
    CPUSS_CM7_1_TCM_C_ECC           = 0x0010u,
    CPUSS_CM7_1_TCM_NC_ECC          = 0x0011u,
    CPUSS_CM7_0_CACHE_C_ECC         = 0x0012u,
    CPUSS_CM7_0_CACHE_NC_ECC        = 0x0013u,
    CPUSS_CM7_1_CACHE_C_ECC         = 0x0014u,
    CPUSS_CM7_1_CACHE_NC_ECC        = 0x0015u,
    PERI_MS_VIO_4                   = 0x0019u,
    PERI_PERI_C_ECC                 = 0x001Au,
    PERI_PERI_NC_ECC                = 0x001Bu,
    PERI_MS_VIO_0                   = 0x001Cu,
    PERI_MS_VIO_1                   = 0x001Du,
    PERI_MS_VIO_2                   = 0x001Eu,
    PERI_MS_VIO_3                   = 0x001Fu,
    PERI_GROUP_VIO_0                = 0x0020u,
    PERI_GROUP_VIO_1                = 0x0021u,
    PERI_GROUP_VIO_2                = 0x0022u,
    PERI_GROUP_VIO_3                = 0x0023u,
    PERI_GROUP_VIO_4                = 0x0024u,
    PERI_GROUP_VIO_5                = 0x0025u,
    PERI_GROUP_VIO_6                = 0x0026u,
    PERI_GROUP_VIO_8                = 0x0028u,
    PERI_GROUP_VIO_9                = 0x0029u,
    CPUSS_FLASHC_MAIN_BUS_ERR       = 0x0030u,
    CPUSS_FLASHC_MAIN_C_ECC         = 0x0031u,
    CPUSS_FLASHC_MAIN_NC_ECC        = 0x0032u,
    CPUSS_FLASHC_WORK_BUS_ERR       = 0x0033u,
    CPUSS_FLASHC_WORK_C_ECC         = 0x0034u,
    CPUSS_FLASHC_WORK_NC_ECC        = 0x0035u,
    CPUSS_FLASHC_CM0_CA_C_ECC       = 0x0036u,
    CPUSS_FLASHC_CM0_CA_NC_ECC      = 0x0037u,
    CPUSS_CM7_0_TCM_C_ECC           = 0x0038u,
    CPUSS_CM7_0_TCM_NC_ECC          = 0x0039u,
    CPUSS_RAMC0_C_ECC               = 0x003Au,
    CPUSS_RAMC0_NC_ECC              = 0x003Bu,
    CPUSS_RAMC1_C_ECC               = 0x003Cu,
    CPUSS_RAMC1_NC_ECC              = 0x003Du,
    CPUSS_RAMC2_C_ECC               = 0x003Eu,
    CPUSS_RAMC2_NC_ECC              = 0x003Fu,
    CPUSS_CRYPTO_C_ECC              = 0x0040u,
    CPUSS_CRYPTO_NC_ECC             = 0x0041u,
    CPUSS_DW0_C_ECC                 = 0x0046u,
    CPUSS_DW0_NC_ECC                = 0x0047u,
    CPUSS_DW1_C_ECC                 = 0x0048u,
    CPUSS_DW1_NC_ECC                = 0x0049u,
    CPUSS_FM_SRAM_C_ECC             = 0x004Au,
    CPUSS_FM_SRAM_NC_ECC            = 0x004Bu,
    CANFD_0_CAN_C_ECC               = 0x0050u,
    CANFD_0_CAN_NC_ECC              = 0x0051u,
    CANFD_1_CAN_C_ECC               = 0x0052u,
    CANFD_1_CAN_NC_ECC              = 0x0053u,
    SRSS_FAULT_CSV                  = 0x005Au,
    SRSS_FAULT_SSV                  = 0x005Bu,
    SRSS_FAULT_MCWDT0               = 0x005Cu,
    SRSS_FAULT_MCWDT1               = 0x005Du,
    SRSS_FAULT_MCWDT2               = 0x005Eu
} en_sysflt_source_t;

/* Bus masters */
typedef enum
{
    CPUSS_MS_ID_CM0                 =  0,
    CPUSS_MS_ID_CRYPTO              =  1,
    CPUSS_MS_ID_DW0                 =  2,
    CPUSS_MS_ID_DW1                 =  3,
    CPUSS_MS_ID_DMAC                =  4,
    CPUSS_MS_ID_SLOW0               =  5,
    CPUSS_MS_ID_SLOW1               =  6,
    CPUSS_MS_ID_FAST0               =  9,
    CPUSS_MS_ID_FAST1               = 10,
    CPUSS_MS_ID_FAST2               = 11,
    CPUSS_MS_ID_FAST3               = 12,
    CPUSS_MS_ID_CM7_1               = 13,
    CPUSS_MS_ID_CM7_0               = 14,
    CPUSS_MS_ID_TC                  = 15
} en_prot_master_t;

/* Parameter Defines */
/* ULP variant. Must be 1 when targeting S40S and 0 otherwise. */
#define SRSS_ULP_VARIANT                0u
/* HT variant. Must be 1 when targeting S40E and 0 otherwise. */
#define SRSS_HT_VARIANT                 1u
/* Number of regulator modules instantiated within SRSS. Must be > 0. */
#define SRSS_NUM_ACTREG_PWRMOD          6u
/* Number of shorting switches between vccd and vccact. Must be > 0. */
#define SRSS_NUM_ACTIVE_SWITCH          6u
/* ULP linear regulator system is present */
#define SRSS_ULPLINREG_PRESENT          0u
/* HT linear regulator system is present */
#define SRSS_HTLINREG_PRESENT           1u
/* SIMO buck core regulator is present. Only compatible with ULP linear regulator
   system (ULPLINREG_PRESENT==1). */
#define SRSS_SIMOBUCK_PRESENT           0u
/* Precision ILO (PILO) is present */
#define SRSS_PILO_PRESENT               0u
/* External Crystal Oscillator is present (high frequency) */
#define SRSS_ECO_PRESENT                1u
/* System Buck-Boost is present */
#define SRSS_SYSBB_PRESENT              0u
/* Number of PWR_HIB_DATA registers. Min is zero. */
#define SRSS_NUM_HIBDATA                1u
/* Number of clock paths. Must be > 0. Recommend
   NUM_CLKPATH>=NUM_TOTAL_PLL+CSV_PRESENT+2. CSV and FLL requires special paths,
   and one extra is recommended for programming flexibility. */
#define SRSS_NUM_CLKPATH                7u
/* Number of 200MHz PLLs present. */
#define SRSS_NUM_PLL                    2u
/* Number of HFCLK roots present. Must be > 0. Recommend NUM_HFROOT=<# chipwide
   roots>+CSV_PRESENT. */
#define SRSS_NUM_HFROOT                 8u
/* Number of DSI inputs into clock muxes. This is used for logic optimization.
   Must be > 0 */
#define SRSS_NUM_DSI                    0u
/* Alternate high-frequency clock is present. This is used for logic optimization. */
#define SRSS_ALTHF_PRESENT              0u
/* Alternate low-frequency clock is present. This is used for logic optimization. */
#define SRSS_ALTLF_PRESENT              0u
/* Backup domain is present. See VBCK_PRESENT for whether it is supplied by vddd
   or by an independent vbackup supply. */
#define SRSS_BACKUP_PRESENT             1u
/* CSV present. User must add one NUM_CLKPATH and one NUM_HFROOT to monitor ILO0
   with CSV_HF_REF clock. */
#define SRSS_CSV_PRESENT                1u
/* Number of multi-counter watchdog timers. Min is zero. */
#define SRSS_NUM_MCWDT                  3u
/* Use the hardened clkactfllmux block */
#define SRSS_USE_HARD_CLKACTFLLMUX      1u
/* Number of clock paths, including direct paths in hardened clkactfllmux block */
#define SRSS_HARD_CLKPATH               8u
/* Number of clock paths with muxes in hardened clkactfllmux block */
#define SRSS_HARD_CLKPATHMUX            8u
/* Number of HFCLKS present in hardened clkactfllmux block */
#define SRSS_HARD_HFROOT                8u
/* ECO mux is present in hardened clkactfllmux block */
#define SRSS_HARD_ECOMUX_PRESENT        1u
/* ALTHF mux is present in hardened clkactfllmux block */
#define SRSS_HARD_ALTHFMUX_PRESENT      1u
/* POR present. */
#define SRSS_POR_PRESENT                1u
/* Low-current buck regulator present. Can be derived from S40S_SISOBUCKLC_PRESENT
   or SIMOBUCK_PRESENT. */
#define SRSS_BUCKCTL_PRESENT            0u
/* Low-current SISO buck core regulator is present. Only compatible with ULP
   linear regulator system (ULPLINREG_PRESENT==1). */
#define SRSS_S40S_SISOBUCKLC_PRESENT    0u
/* HT linear regulator system is present */
#define SRSS_S40E_HTREGHC_PRESENT       1u
/* LPECO mux is present in hardened clkactfllmux block */
#define SRSS_HARD_LPECOMUX_PRESENT      1u
/* Number of 400MHz PLLs present. */
#define SRSS_NUM_PLL400M                2u
/* Mask of DIRECT_MUX defaults. For each clock root i, if bit[i] is low the
   DIRECT_MUX defaults to IMO. If bit[0] is high, the DIRECT_MUX selects the
   output of ROOT_MUX. For backward compatibility, M4 systems can have all mask
   bits high. BootROM needs either Bit0 high or a code change to pick predivider
   output before using the FLL. */
#define SRSS_MASK_DIRECTMUX_DEF         1u
/* Mask of which HFCLK roots are enabled when the debugger requests power up
   (CDBGPWRUPREQ). For each clock root i, SRSS enables the clock in response to
   CDBGPWRUPREQ, if bit[i] of mask is high. SRSS automatically enables clk_hf0,
   regardless of setting of mask bit0. */
#define SRSS_MASK_DEBUG_CLK             65535u
/* Total number of PLLs present. Must be calculated (NUM_PLL+NUM_PLL400M). Cannot
   exceed max or NUM_CLKPATH. */
#define SRSS_NUM_TOTAL_PLL              4u
/* ULP variant. Must be 1 when targeting S40S and 0 otherwise. */
#define SRSS_CLK_TRIM_PLL400M_ULP_VARIANT 0u
/* Mask of HFCLK root clock supervisors (CSV). For each clock root i, bit[i] of
   mask indicates presence of a CSV. */
#define SRSS_CSV_HF_MASK_HFCSV          255u
/* Separate power supply Vbackup is present (only used when BACKUP_PRESENT==1) */
#define SRSS_BACKUP_VBCK_PRESENT        0u
/* Alarm1 present in RTC */
#define SRSS_BACKUP_ALM1_PRESENT        1u
/* Alarm2 present in RTC */
#define SRSS_BACKUP_ALM2_PRESENT        1u
/* Backup memory is present (only used when BACKUP_PRESENT==1) */
#define SRSS_BACKUP_BMEM_PRESENT        0u
/* Number of Backup registers to include (each is 32b). Only used when
   BACKUP_PRESENT==1. Approximate size is 850squm per register. */
#define SRSS_BACKUP_NUM_BREG            4u
/* Low power external crystal oscillator (LPECO) is present. */
#define SRSS_BACKUP_S40E_LPECO_PRESENT  0u
/* Number of AMUX splitter cells */
#define IOSS_HSIOM_AMUX_SPLIT_NR        4u
/* Number of HSIOM ports in device */
#define IOSS_HSIOM_HSIOM_PORT_NR        35u
/* Number of PWR/GND MONITOR CELLs in the device */
#define IOSS_HSIOM_MONITOR_NR           26u
/* Number of PWR/GND MONITOR CELLs in range 0..31 */
#define IOSS_HSIOM_MONITOR_NR_0_31      26u
/* Number of PWR/GND MONITOR CELLs in range 32..63 */
#define IOSS_HSIOM_MONITOR_NR_32_63     0u
/* Number of PWR/GND MONITOR CELLs in range 64..95 */
#define IOSS_HSIOM_MONITOR_NR_64_95     0u
/* Number of PWR/GND MONITOR CELLs in range 96..127 */
#define IOSS_HSIOM_MONITOR_NR_96_127    0u
/* Indicates the presence of alternate JTAG interface */
#define IOSS_HSIOM_ALTJTAG_PRESENT      1u
/* Number of GPIO ports in range 0..31 */
#define IOSS_GPIO_GPIO_PORT_NR_0_31     32u
/* Number of GPIO ports in range 32..63 */
#define IOSS_GPIO_GPIO_PORT_NR_32_63    3u
/* Number of GPIO ports in range 64..95 */
#define IOSS_GPIO_GPIO_PORT_NR_64_95    0u
/* Number of GPIO ports in range 96..127 */
#define IOSS_GPIO_GPIO_PORT_NR_96_127   0u
/* Number of GPIO ports in device */
#define IOSS_GPIO_GPIO_PORT_NR          35u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO0 1u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO1 1u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO2 1u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO3 1u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR0_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR1_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR2_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR3_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR4_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR5_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR6_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR7_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR8_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR9_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR10_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR11_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR12_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR13_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR14_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR15_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR16_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR17_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR18_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR19_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR20_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR21_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR22_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR23_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR24_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR24_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR24_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR24_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR24_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR24_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR24_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR24_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR24_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR24_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR24_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR25_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR25_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR25_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR25_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR25_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR25_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR25_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR25_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR25_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR25_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR25_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR26_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR26_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR26_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR26_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR26_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR26_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR26_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR26_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR26_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR26_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR26_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR27_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR27_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR27_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR27_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR27_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR27_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR27_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR27_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR27_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR27_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR27_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR28_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR28_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR28_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR28_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR28_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR28_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR28_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR28_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR28_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR28_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR28_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR29_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR29_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR29_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR29_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR29_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR29_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR29_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR29_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR29_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR29_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR29_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR30_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR30_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR30_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR30_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR30_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR30_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR30_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR30_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR30_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR30_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR30_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR31_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR31_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR31_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR31_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR31_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR31_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR31_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR31_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR31_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR31_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR31_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR32_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR32_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR32_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR32_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR32_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR32_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR32_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR32_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR32_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR32_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR32_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR33_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR33_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR33_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR33_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR33_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR33_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR33_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR33_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR33_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR33_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR33_GPIO_PRT_SLOW_IO7 0u
/* Indicates port is either GPIO or SIO (i.e. all GPIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR34_GPIO_PRT_GPIO 1u
/* Indicates port is an SIO port (i.e. both GPIO and SIO registers present) */
#define IOSS_GPIO_GPIO_PORT_NR34_GPIO_PRT_SIO 0u
/* Indicates port is a GPIO port including the "AUTO" input threshold */
#define IOSS_GPIO_GPIO_PORT_NR34_GPIO_PRT_AUTOLVL 1u
/* Indicates that pin #0 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR34_GPIO_PRT_SLOW_IO0 0u
/* Indicates that pin #1 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR34_GPIO_PRT_SLOW_IO1 0u
/* Indicates that pin #2 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR34_GPIO_PRT_SLOW_IO2 0u
/* Indicates that pin #3 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR34_GPIO_PRT_SLOW_IO3 0u
/* Indicates that pin #4 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR34_GPIO_PRT_SLOW_IO4 0u
/* Indicates that pin #5 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR34_GPIO_PRT_SLOW_IO5 0u
/* Indicates that pin #6 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR34_GPIO_PRT_SLOW_IO6 0u
/* Indicates that pin #7 exists for this port with slew control feature */
#define IOSS_GPIO_GPIO_PORT_NR34_GPIO_PRT_SLOW_IO7 0u
/* Mask of SMARTIO instances presence */
#define IOSS_SMARTIO_SMARTIO_MASK       192512u
/* The number of protection contexts ([2, 16]). */
#define PERI_PC_NR                      8u
/* Master interface presence mask (5 bits) */
#define PERI_MS_PRESENT                 31u
/* Protection structures SRAM ECC present or not ('0': no, '1': yes) */
#define PERI_ECC_PRESENT                1u
/* Protection structures SRAM address ECC present or not ('0': no, '1': yes) */
#define PERI_ECC_ADDR_PRESENT           1u
/* Peripheral group PCLK root select */
#define PERI_GROUP_PRESENT0_PERI_GROUP_PCLK_ROOT_SEL 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL1_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL2_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT0_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Peripheral group PCLK root select */
#define PERI_GROUP_PRESENT1_PERI_GROUP_PCLK_ROOT_SEL 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT1_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Peripheral group PCLK root select */
#define PERI_GROUP_PRESENT2_PERI_GROUP_PCLK_ROOT_SEL 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL1_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL2_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL3_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL4_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL5_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL6_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL7_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL8_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL9_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL10_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL11_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT2_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Peripheral group PCLK root select */
#define PERI_GROUP_PRESENT3_PERI_GROUP_PCLK_ROOT_SEL 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL1_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL2_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL3_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL4_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT3_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Peripheral group PCLK root select */
#define PERI_GROUP_PRESENT4_PERI_GROUP_PCLK_ROOT_SEL 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL1_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL2_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL3_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT4_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Peripheral group PCLK root select */
#define PERI_GROUP_PRESENT5_PERI_GROUP_PCLK_ROOT_SEL 1u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL1_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL2_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL3_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL4_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT5_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Peripheral group PCLK root select */
#define PERI_GROUP_PRESENT6_PERI_GROUP_PCLK_ROOT_SEL 1u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL1_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL2_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL3_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL4_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL5_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL6_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL7_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL8_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL9_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL10_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT6_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Peripheral group PCLK root select */
#define PERI_GROUP_PRESENT7_PERI_GROUP_PCLK_ROOT_SEL 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT7_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Peripheral group PCLK root select */
#define PERI_GROUP_PRESENT8_PERI_GROUP_PCLK_ROOT_SEL 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL1_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL2_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT8_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Peripheral group PCLK root select */
#define PERI_GROUP_PRESENT9_PERI_GROUP_PCLK_ROOT_SEL 1u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_CLOCK_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL0_PRESENT 1u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT9_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Peripheral group PCLK root select */
#define PERI_GROUP_PRESENT10_PERI_GROUP_PCLK_ROOT_SEL 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT10_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Peripheral group PCLK root select */
#define PERI_GROUP_PRESENT11_PERI_GROUP_PCLK_ROOT_SEL 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT11_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Peripheral group PCLK root select */
#define PERI_GROUP_PRESENT12_PERI_GROUP_PCLK_ROOT_SEL 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT12_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Peripheral group PCLK root select */
#define PERI_GROUP_PRESENT13_PERI_GROUP_PCLK_ROOT_SEL 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT13_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Peripheral group PCLK root select */
#define PERI_GROUP_PRESENT14_PERI_GROUP_PCLK_ROOT_SEL 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT14_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Peripheral group PCLK root select */
#define PERI_GROUP_PRESENT15_PERI_GROUP_PCLK_ROOT_SEL 0u
/* Clock control functionality present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_CLOCK_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL0_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL1_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL2_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL3_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL4_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL5_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL6_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL7_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL8_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL9_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL10_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL11_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL12_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL13_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL14_PRESENT 0u
/* Slave present ('0': no, '1': yes) */
#define PERI_GROUP_PRESENT15_PERI_GROUP_STRUCT_SL15_PRESENT 0u
/* Number of asynchronous PCLK groups */
#define PERI_PCLK_GROUP_NR              2u
/* Timeout functionality present ('0': no, '1': yes) */
#define PERI_TIMEOUT_PRESENT            1u
/* Trigger module present ('0': no, '1': yes) */
#define PERI_TR                         1u
/* Number of trigger groups */
#define PERI_TR_GROUP_NR                13u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR0_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR1_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR2_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR3_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR4_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR5_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR6_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR7_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR8_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR9_TR_GROUP_TR_MANIPULATION_PRESENT 1u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR10_TR_GROUP_TR_MANIPULATION_PRESENT 0u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR11_TR_GROUP_TR_MANIPULATION_PRESENT 0u
/* Trigger group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_GROUP_NR12_TR_GROUP_TR_MANIPULATION_PRESENT 0u
/* 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR0_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR1_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR2_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR3_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR4_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR5_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR6_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR7_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR8_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR9_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR10_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR11_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR12_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* 1-to-1 group trigger manipulation logic present ('0': no, '1': yes) */
#define PERI_TR_1TO1_GROUP_NR13_TR_1TO1_GROUP_TR_1TO1_MANIPULATION_PRESENT 1u
/* Number of asynchronous PCLK groups */
#define PERI_PERI_PCLK_PCLK_GROUP_NR    2u
/* Number of 8.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_8_VECT 4u
/* Number of 16.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_16_VECT 3u
/* Number of 16.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR0_GR_DIV_24_5_VECT 1u
/* Number of programmable clocks [1, 256] */
#define PERI_PERI_PCLK_PCLK_GROUP_NR0_GR_CLOCK_VECT 15u
/* Number of 8.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_8_VECT 19u
/* Number of 16.0 dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_16_VECT 20u
/* Number of 16.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_16_5_VECT 0u
/* Number of 24.5 (fractional) dividers */
#define PERI_PERI_PCLK_PCLK_GROUP_NR1_GR_DIV_24_5_VECT 21u
/* Number of programmable clocks [1, 256] */
#define PERI_PERI_PCLK_PCLK_GROUP_NR1_GR_CLOCK_VECT 154u
/* Divider number width: max(1,roundup(log2(max(DIV_*_NR))) */
#define PERI_GR_DIV_ADDR_WIDTH          5u
/* UDB present or not ('0': no, '1': yes) */
#define CPUSS_UDB_PRESENT               0u
/* MBIST MMIO for Synopsys MBIST ('0': no, '1': yes). Set this to '1' only for the
   chips which doesn't use mxdft. */
#define CPUSS_MBIST_MMIO_PRESENT        0u
/* System RAM 0 size in KB */
#define CPUSS_SRAM0_SIZE                512u
/* Number of macros used to implement system RAM 0. Example: 8 if 256 KB system
   SRAM 0 is implemented with 8 32KB macros. */
#define CPUSS_RAMC0_MACRO_NR            16u
/* System RAM 1 present or not ('0': no, '1': yes) */
#define CPUSS_RAMC1_PRESENT             1u
/* System RAM 1 size in KB */
#define CPUSS_SRAM1_SIZE                256u
/* Number of macros used to implement system RAM 1. */
#define CPUSS_RAMC1_MACRO_NR            8u
/* System RAM 2 present or not ('0': no, '1': yes) */
#define CPUSS_RAMC2_PRESENT             1u
/* System RAM 2 size in KB */
#define CPUSS_SRAM2_SIZE                256u
/* Number of macros used to implement System RAM 2. */
#define CPUSS_RAMC2_MACRO_NR            8u
/* System SRAM(s) ECC present or not ('0': no, '1': yes) */
#define CPUSS_RAMC_ECC_PRESENT          1u
/* System SRAM(s) address ECC present or not ('0': no, '1': yes) */
#define CPUSS_RAMC_ECC_ADDR_PRESENT     1u
/* ECC present in either system RAM or interrupt handler (RAMC_ECC_PRESENT) */
#define CPUSS_ECC_PRESENT               1u
/* DataWire SRAMs ECC present or not ('0': no, '1': yes) */
#define CPUSS_DW_ECC_PRESENT            1u
/* DataWire SRAMs address ECC present or not ('0': no, '1': yes) */
#define CPUSS_DW_ECC_ADDR_PRESENT       1u
/* System ROM size in KB */
#define CPUSS_ROM_SIZE                  64u
/* Number of macros used to implement system ROM. Example: 4 if 512 KB system ROM
   is implemented with 4 128KB macros. */
#define CPUSS_ROMC_MACRO_NR             1u
/* Flash memory present or not ('0': no, '1': yes) */
#define CPUSS_FLASHC_PRESENT            1u
/* Flash memory type ('0' : SONOS, '1': ECT) */
#define CPUSS_FLASHC_ECT                1u
/* Flash main region size in KB */
#define CPUSS_FLASH_SIZE                8192u
/* Flash work region size in KB (EEPROM emulation, data) */
#define CPUSS_WFLASH_SIZE               256u
/* Flash supervisory region size in KB */
#define CPUSS_SFLASH_SIZE               32u
/* Flash data output word size (in Bits) Example: 256 for 256-bit Flash data
   output */
#define CPUSS_FLASHC_MAIN_DATA_WIDTH    256u
/* SONOS Flash RWW present or not ('0': no, '1': yes) When RWW is '0', No special
   sectors present in Flash. Part of main sector 0 is allowcated for Supervisory
   Flash, and no Work Flash present. */
#define CPUSS_FLASHC_SONOS_RWW          0u
/* SONOS Flash, number of main sectors. */
#define CPUSS_FLASHC_SONOS_MAIN_SECTORS 0u
/* SONOS Flash, number of rows per main sector. */
#define CPUSS_FLASHC_SONOS_MAIN_ROWS    0u
/* SONOS Flash, number of words per row of main sector. */
#define CPUSS_FLASHC_SONOS_MAIN_WORDS   0u
/* SONOS Flash, number of special sectors. */
#define CPUSS_FLASHC_SONOS_SPL_SECTORS  0u
/* SONOS Flash, number of rows per special sector. */
#define CPUSS_FLASHC_SONOS_SPL_ROWS     0u
/* Flash memory ECC present or not ('0': no, '1': yes) */
#define CPUSS_FLASHC_FLASH_ECC_PRESENT  1u
/* Flash cache SRAM(s) ECC present or not ('0': no, '1': yes) */
#define CPUSS_FLASHC_RAM_ECC_PRESENT    1u
/* Number of external AHB-Lite slaves directly connected to slow AHB-Lite
   infrastructure. Maximum nubmer of slave supported is 6. Width of this
   parameter is 6-bits. 1-bit mask for each slave indicating present or not.
   Example: 6'b00_0011 - slave 0 and slave 1 are present. Note: The
   SLOW_SLx_ADDR and SLOW_SLx_MASK parameters (for the slaves present) should be
   derived from the Memory Map. */
#define CPUSS_SLOW_SL_PRESENT           1u
/* Number of external AXI slaves directly connected to fast AXI infrastructure.
   Maximum nubmer of slave supported is 8. Width of this parameter is 8-bits.
   1-bit mask for each slave indicating present or not. Example: 8'b0000_0011 -
   slave 0 and slave 1 are present. Note: The FAST_SLx_ADDR and FAST_SLx_MASK
   parameters (for the slaves present) should be derived from the Memory Map. */
#define CPUSS_FAST_SL_PRESENT           1u
/* Number of external AHB-Lite masters driving the slow AHB-Lite infrastructure.
   Maximum number of masters supported is 2. Width of this parameter is 2-bits.
   1-bit mask for each master indicating present or not. Example: 2'b01 - master
   0 is present. */
#define CPUSS_SLOW_MS_PRESENT           1u
/* Number of external AXI masters driving the fast AXI infrastructure. Maximum
   number of masters supported is 4. Width of this parameter is 4-bits. 1-bit
   mask for each master indicating present or not. Example: 4'b0001 - master 0
   is present. */
#define CPUSS_FAST_MS_PRESENT           3u
/* Retain 'protection context' (PC), 'privileged' (P), 'Non Secure' (NS)
   attributes coming from external AXI master or use it from CPUSS protection
   MMIO (PROT_MPU.MS_CTL.PC, PROT_SMPU.MSx_CTL.P, PROT_SMPU.MSx_CTL.NS). Width
   of this parameter is 4-bits. 1-bit mask for each master indicating retain PC
   or not. */
#define CPUSS_AXIM_RETAIN_PROT          0u
/* Width of external AXI master ID signals. Legal range [3,8] */
#define CPUSS_AXIM_ID_WIDTH             3u
/* Width of external AXI slave ID signals (AXIM_ID_WIDTH + MASTER_WIDTH + 1).
   Legal range [12,17] */
#define CPUSS_AXIS_ID_WIDTH             12u
/* IRQ expander present ('0': no, '1': yes) */
#define CPUSS_SYSTEM_IRQ_PRESENT        1u
/* Number of system interrupt inputs to CPUSS */
#define CPUSS_SYSTEM_INT_NR             567u
/* Number of DeepSleep system interrupt inputs to CPUSS */
#define CPUSS_SYSTEM_DPSLP_INT_NR       51u
/* Width of the CM4 interrupt priority bits. Legal range [3,8] Example: 3 = 8
   levels of priority 8 = 256 levels of priority */
#define CPUSS_CM7_LVL_WIDTH             3u
/* Number of CM7 CPU Interrupts. Legal values 8 or 16. */
#define CPUSS_CM7_INT_NR                8u
/* CM7 Cache SRAMs ECC present or not ('0': no, '1': yes) */
#define CPUSS_CM7_CACHE_ECC_PRESENT     1u
/* CM7 TCM SRAMs ECC present or not ('0': no, '1': yes) */
#define CPUSS_CM7_TCM_ECC_PRESENT       1u
/* CM7 TCM SRAMs address ECC present or not ('0': no, '1': yes) */
#define CPUSS_CM7_TCM_ECC_ADDR_PRESENT  0u
/* CM7_0 Floating point unit configuration. Legal range [0,2] 0 - No FPU 1 -
   Single precision FPU 2 - Single and Double precision FPU */
#define CPUSS_CM7_0_FPU_LVL             2u
/* Number of MPU regions in CM7_0. Legal values [0, 8, 16] */
#define CPUSS_CM7_0_MPU_NR              16u
/* CM7_0 Instruction cache (ICACHE) size in KB */
#define CPUSS_CM7_0_ICACHE_SIZE         16u
/* CM7_0 Data cache size (DCACHE) in KB */
#define CPUSS_CM7_0_DCACHE_SIZE         16u
/* CM7_0 Instruction TCM (ITCM) size in KB */
#define CPUSS_CM7_0_ITCM_SIZE           16u
/* CM7_0 Data TCM (DTCM) size in KB */
#define CPUSS_CM7_0_DTCM_SIZE           16u
/* CM7_1 CPU present or not ('0': no, '1': yes) */
#define CPUSS_CM7_1_PRESENT             1u
/* System interrupt functionality present or not ('0': no; '1': yes) for CM7_1.
   Not used for CM0+ CPU, which always uses system interrupt functionality. */
#define CPUSS_CM7_1_SYSTEM_IRQ_PRESENT  1u
/* CM7_1 Floating point unit configuration. Legal range [0,2] 0 - No FPU 1 -
   Single precision FPU 2 - Single and Double precision FPU */
#define CPUSS_CM7_1_FPU_LVL             2u
/* Number of MPU regions in CM7_1. Legal values [0, 8, 16] */
#define CPUSS_CM7_1_MPU_NR              16u
/* CM7_1 Instruction cache (ICACHE) size in KB */
#define CPUSS_CM7_1_ICACHE_SIZE         16u
/* CM7_1 Data cache size (DCACHE) in KB */
#define CPUSS_CM7_1_DCACHE_SIZE         16u
/* CM7_1 Instruction TCM (ITCM) size in KB */
#define CPUSS_CM7_1_ITCM_SIZE           16u
/* CM7_1 Data TCM (DTCM) size in KB */
#define CPUSS_CM7_1_DTCM_SIZE           16u
/* Debug level. Legal range [0,3] */
#define CPUSS_DEBUG_LVL                 3u
/* Trace level. Legal range [0,2] Note: CM4 HTM is not supported. Hence vaule 3
   for trace level is not supported in CPUSS. // CPUSS_TRACE_LVL: // 0 = no
   tracing // 1 = only ITM source and TPIU sink (no ETM, Funnel, Replicator or
   ETB) // 2 = ITM and ETM sources, Funnel and TPIU (no Replicator or ETB) // 3
   = ITM and ETM sources, Funnel, Replicator, TPIU and ET */
#define CPUSS_TRACE_LVL                 2u
/* Embedded Trace Buffer present or not ('0': no, '1': yes) */
#define CPUSS_ETB_PRESENT               1u
/* CM0+ MTB SRAM buffer size in kilobytes. Legal vaules 4, 8 or 16 */
#define CPUSS_MTB_SRAM_SIZE             4u
/* CM7 ETB SRAM buffer size in kilobytes. Legal vaules 4, 8 or 16 */
#define CPUSS_ETB_SRAM_SIZE             8u
/* PTM interface present (0=No, 1=Yes) */
#define CPUSS_PTM_PRESENT               0u
/* Width of the PTM interface in bits ([2,32]) */
#define CPUSS_PTM_WIDTH                 1u
/* Width of the TPIU interface in bits ([1,4]) */
#define CPUSS_TPIU_WIDTH                4u
/* CoreSight Part Identification Number */
#define CPUSS_JEPID                     52u
/* CoreSight Part Identification Number */
#define CPUSS_JEPCONTINUATION           0u
/* CoreSight Part Identification Number */
#define CPUSS_FAMILYID                  259u
/* ROM trim register width (for ARM 3, for Synopsys 5) */
#define CPUSS_ROM_TRIM_WIDTH            3u
/* ROM trim register default (for both ARM and Synopsys 0x0000_0002) */
#define CPUSS_ROM_TRIM_DEFAULT          2u
/* RAM trim register width (for ARM 8, for Synopsys 15) */
#define CPUSS_RAM_TRIM_WIDTH            8u
/* RAM trim register default (for ARM 0x0000_0062 and for Synopsys 0x0000_6012) */
#define CPUSS_RAM_TRIM_DEFAULT          98u
/* Cryptography IP present or not ('0': no, '1': yes) */
#define CPUSS_CRYPTO_PRESENT            1u
/* DataWire and DMAC SW trigger per channel present or not ('0': no, '1': yes) */
#define CPUSS_SW_TR_PRESENT             1u
/* DataWire 0 present or not ('0': no, '1': yes) */
#define CPUSS_DW0_PRESENT               1u
/* Number of DataWire 0 channels ([1, 1024]) */
#define CPUSS_DW0_CH_NR                 143u
/* DataWire 1 present or not ('0': no, '1': yes) */
#define CPUSS_DW1_PRESENT               1u
/* Number of DataWire 1 channels ([1, 1024]) */
#define CPUSS_DW1_CH_NR                 65u
/* DMA controller present or not ('0': no, '1': yes) */
#define CPUSS_DMAC_PRESENT              1u
/* Number of DMA controller channels ([1, 8]) */
#define CPUSS_DMAC_CH_NR                8u
/* Number of Flash BIST_DATA registers */
#define CPUSS_FLASHC_FLASHC_BIST_DATA_NR 8u
/* Page size in # of 32-bit words (1: 4 bytes, 2: 8 bytes, ... */
#define CPUSS_FLASHC_PA_SIZE            128u
/* SONOS Flash is used or not ('0': no, '1': yes) */
#define CPUSS_FLASHC_FLASHC_IS_SONOS    0u
/* eCT Flash is used or not ('0': no, '1': yes) */
#define CPUSS_FLASHC_FLASHC_IS_ECT      1u
/* Sequential Work Flash read feature for the FLASHC AXI port present or not ('0':
   no, '1': yes) */
#define CPUSS_FLASHC_FLASHC_WORK_SEQ_PRESENT 1u
/* CM7_1 CPU present or not ('0': no, '1': yes) */
#define CPUSS_FLASHC_CM7_1_PRESENT      1u
/* External AHB-Lite master0 Present */
#define CPUSS_FLASHC_SLOW0_MS_PRESENT   1u
/* External AHB-Lite master1 Present */
#define CPUSS_FLASHC_SLOW1_MS_PRESENT   0u
/* Cryptography SRAMs ECC present or not ('0': no, '1': yes) */
#define CPUSS_CRYPTO_ECC_PRESENT        1u
/* Cryptography SRAMs address ECC present or not ('0': no, '1': yes) */
#define CPUSS_CRYPTO_ECC_ADDR_PRESENT   1u
/* AES cipher support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_AES                1u
/* (Tripple) DES cipher support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_DES                1u
/* Chacha support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_CHACHA             1u
/* Pseudo random number generation support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_PR                 1u
/* SHA1 hash support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_SHA1               1u
/* SHA2 hash support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_SHA2               1u
/* SHA3 hash support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_SHA3               1u
/* Cyclic Redundancy Check support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_CRC                1u
/* True random number generation support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_TR                 1u
/* Vector unit support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_VU                 1u
/* Galios/Counter Mode (GCM) support ('0': no, '1': yes) */
#define CPUSS_CRYPTO_GCM                1u
/* Number of 32-bit words in the IP internal memory buffer (from the set [64, 128,
   256, 512, 1024, 2048, 4096], to allow for a 256 B, 512 B, 1 kB, 2 kB, 4 kB, 8
   kB and 16 kB memory buffer) */
#define CPUSS_CRYPTO_BUFF_SIZE          2048u
/* Number of fault structures. Legal range [1, 4] */
#define CPUSS_FAULT_FAULT_NR            4u
/* Number of IPC structures. Legal range [1, 16] */
#define CPUSS_IPC_IPC_NR                8u
/* Number of IPC interrupt structures. Legal range [1, 16] */
#define CPUSS_IPC_IPC_IRQ_NR            8u
/* Master 0 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS0_PC_NR_MINUS1 7u
/* Master 1 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS1_PC_NR_MINUS1 0u
/* Master 2 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS2_PC_NR_MINUS1 0u
/* Master 3 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS3_PC_NR_MINUS1 0u
/* Master 4 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS4_PC_NR_MINUS1 0u
/* Master 5 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS5_PC_NR_MINUS1 7u
/* Master 6 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS6_PC_NR_MINUS1 0u
/* Master 7 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS7_PC_NR_MINUS1 0u
/* Master 8 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS8_PC_NR_MINUS1 0u
/* Master 9 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS9_PC_NR_MINUS1 7u
/* Master 10 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS10_PC_NR_MINUS1 7u
/* Master 11 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS11_PC_NR_MINUS1 0u
/* Master 12 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS12_PC_NR_MINUS1 0u
/* Master 13 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS13_PC_NR_MINUS1 7u
/* Master 14 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS14_PC_NR_MINUS1 7u
/* Master 15 protect contexts minus one */
#define CPUSS_PROT_SMPU_MS15_PC_NR_MINUS1 7u
/* Number of SMPU protection structures */
#define CPUSS_PROT_SMPU_STRUCT_NR       16u
/* Number of protection contexts supported minus 1. Legal range [1,16] */
#define CPUSS_SMPU_STRUCT_PC_NR_MINUS1  7u
/* Number of DataWire controllers present (max 2) */
#define CPUSS_DW_NR                     2u
/* DataWire SRAMs ECC present or not ('0': no, '1': yes) */
#define CPUSS_DW_ECC_PRESENT            1u
/* DataWire SW trigger per channel present or not ('0': no, '1': yes) */
#define CPUSS_CH_STRUCT_SW_TR_PRESENT   1u
/* Number of DataWire controllers present (max 2) (same as DW.NR above) */
#define CPUSS_CPUSS_DW_DW_NR            2u
/* Number of channels in each DataWire controller */
#define CPUSS_CPUSS_DW_DW_NR0_DW_CH_NR  143u
/* Width of a channel number in bits */
#define CPUSS_CPUSS_DW_DW_NR0_DW_CH_NR_WIDTH 8u
/* Number of channels in each DataWire controller */
#define CPUSS_CPUSS_DW_DW_NR1_DW_CH_NR  65u
/* Width of a channel number in bits */
#define CPUSS_CPUSS_DW_DW_NR1_DW_CH_NR_WIDTH 7u
/* Number of DMA controller channels ([1, 8]) */
#define CPUSS_DMAC_CH_NR                8u
/* DMAC SW trigger per channel present or not ('0': no, '1': yes) */
#define CPUSS_CH_SW_TR_PRESENT          1u
/* See MMIO2 instantiation or not */
#define CPUSS_CHIP_TOP_PROFILER_PRESENT 0u
/* ETAS Calibration support pin out present (automotive only) */
#define CPUSS_CHIP_TOP_CAL_SUP_NZ_PRESENT 1u
/* TRACE_LVL>0 */
#define CPUSS_CHIP_TOP_TRACE_PRESENT    1u
/* PTM_PRESENT ? PTM_WIDTH : 0 */
#define CPUSS_CHIP_TOP_PTM_PRESENT_WIDTH 0u
/* Number of instantiated eFUSE macros (256 bit macros). Legal range [1, 16] */
#define EFUSE_EFUSE_NR                  4u
/* SONOS Flash is used or not ('0': no, '1': yes) */
#define SFLASH_FLASHC_IS_SONOS          0u
/* WOUND_PRESENT or not ('0': no, '1': yes) */
#define SFLASH_WOUND_PRESENT            1u
/* Number of HFCLK roots present. Must be > 0. Must be same as set for SRSS */
#define DFT_NUM_HFROOT                  8u
/* Width of clk_occ_fast output bus (number of external OCCs) */
#define DFT_EXT_OCC                     2u
/* Number of MBIST controllers with corresponding mbist(pg)_done and mbist(pg)_go
   signals. Value defined by CIC during Pass 1 */
#define DFT_MBIST_C_NUM                 11u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB0_DEEPSLEEP                  1u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB0_EC                         1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB0_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB0_I2C_S                      1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB0_I2C_GLITCH                 1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB0_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB0_I2C_EC                     1u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB0_I2C_M_S                    1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB0_I2C_S_EC                   1u
/* SPI master support? ('0': no, '1': yes) */
#define SCB0_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB0_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB0_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB0_SPI_EC                     1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB0_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB0_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB0_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB0_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB0_CMD_RESP                   1u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB0_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB0_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB0_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB0_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB0_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB0_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB0_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB1_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB1_EC                         1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB1_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB1_I2C_S                      1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB1_I2C_GLITCH                 1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB1_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB1_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB1_I2C_M_S                    1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB1_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB1_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB1_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB1_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB1_SPI_EC                     1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB1_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB1_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB1_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB1_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB1_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB1_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB1_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB1_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB1_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB1_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB1_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB1_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB2_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB2_EC                         1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB2_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB2_I2C_S                      1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB2_I2C_GLITCH                 1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB2_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB2_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB2_I2C_M_S                    1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB2_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB2_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB2_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB2_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB2_SPI_EC                     1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB2_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB2_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB2_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB2_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB2_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB2_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB2_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB2_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB2_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB2_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB2_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB2_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB3_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB3_EC                         1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB3_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB3_I2C_S                      1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB3_I2C_GLITCH                 1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB3_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB3_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB3_I2C_M_S                    1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB3_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB3_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB3_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB3_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB3_SPI_EC                     1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB3_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB3_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB3_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB3_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB3_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB3_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB3_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB3_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB3_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB3_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB3_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB3_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB4_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB4_EC                         1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB4_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB4_I2C_S                      1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB4_I2C_GLITCH                 1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB4_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB4_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB4_I2C_M_S                    1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB4_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB4_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB4_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB4_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB4_SPI_EC                     1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB4_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB4_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB4_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB4_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB4_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB4_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB4_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB4_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB4_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB4_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB4_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB4_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB5_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB5_EC                         1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB5_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB5_I2C_S                      1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB5_I2C_GLITCH                 1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB5_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB5_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB5_I2C_M_S                    1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB5_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB5_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB5_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB5_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB5_SPI_EC                     1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB5_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB5_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB5_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB5_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB5_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB5_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB5_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB5_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB5_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB5_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB5_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB5_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB6_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB6_EC                         1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB6_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB6_I2C_S                      1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB6_I2C_GLITCH                 1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB6_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB6_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB6_I2C_M_S                    1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB6_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB6_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB6_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB6_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB6_SPI_EC                     1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB6_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB6_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB6_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB6_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB6_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB6_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB6_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB6_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB6_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB6_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB6_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB6_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB7_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB7_EC                         1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB7_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB7_I2C_S                      1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB7_I2C_GLITCH                 1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB7_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB7_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB7_I2C_M_S                    1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB7_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB7_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB7_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB7_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB7_SPI_EC                     1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB7_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB7_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB7_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB7_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB7_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB7_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB7_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB7_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB7_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB7_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB7_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB7_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB8_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB8_EC                         1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB8_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB8_I2C_S                      1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB8_I2C_GLITCH                 1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB8_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB8_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB8_I2C_M_S                    1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB8_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB8_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB8_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB8_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB8_SPI_EC                     1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB8_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB8_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB8_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB8_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB8_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB8_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB8_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB8_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB8_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB8_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB8_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB8_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB9_DEEPSLEEP                  0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB9_EC                         1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB9_I2C_M                      1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB9_I2C_S                      1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB9_I2C_GLITCH                 1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB9_I2C                        1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB9_I2C_EC                     0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB9_I2C_M_S                    1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB9_I2C_S_EC                   0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB9_SPI_M                      1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB9_SPI_S                      1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB9_SPI                        1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB9_SPI_EC                     1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB9_SPI_S_EC                   1u
/* UART support? ('0': no, '1': yes) */
#define SCB9_UART                       1u
/* SPI or UART (SPI | UART) */
#define SCB9_SPI_UART                   1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB9_EZ_DATA_NR                 256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB9_CMD_RESP                   0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB9_EZ                         1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB9_EZ_CMD_RESP                1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB9_I2C_S_EZ                   1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB9_SPI_S_EZ                   1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB9_MASTER_WIDTH               8u
/* Number of used spi_select signals (max 4) */
#define SCB9_CHIP_TOP_SPI_SEL_NR        4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB9_CHIP_TOP_I2C_FAST_PLUS     1u
/* DeepSleep support ('0':no, '1': yes) */
#define SCB10_DEEPSLEEP                 0u
/* Externally clocked support? ('0': no, '1': yes) */
#define SCB10_EC                        1u
/* I2C master support? ('0': no, '1': yes) */
#define SCB10_I2C_M                     1u
/* I2C slave support? ('0': no, '1': yes) */
#define SCB10_I2C_S                     1u
/* I2C glitch filters present? ('0': no, '1': yes) */
#define SCB10_I2C_GLITCH                1u
/* I2C support? (I2C_M | I2C_S) */
#define SCB10_I2C                       1u
/* I2C externally clocked support? ('0': no, '1': yes) */
#define SCB10_I2C_EC                    0u
/* I2C master and slave support? (I2C_M & I2C_S) */
#define SCB10_I2C_M_S                   1u
/* I2C slave with EC? (I2C_S & I2C_EC) */
#define SCB10_I2C_S_EC                  0u
/* SPI master support? ('0': no, '1': yes) */
#define SCB10_SPI_M                     1u
/* SPI slave support? ('0': no, '1': yes) */
#define SCB10_SPI_S                     1u
/* SPI support? (SPI_M | SPI_S) */
#define SCB10_SPI                       1u
/* SPI externally clocked support? ('0': no, '1': yes) */
#define SCB10_SPI_EC                    1u
/* SPI slave with EC? (SPI_S & SPI_EC) */
#define SCB10_SPI_S_EC                  1u
/* UART support? ('0': no, '1': yes) */
#define SCB10_UART                      1u
/* SPI or UART (SPI | UART) */
#define SCB10_SPI_UART                  1u
/* Number of EZ memory Bytes ([32, 256, 512]). This memory is used in EZ mode,
   CMD_RESP mode and FIFO mode. Note that in EZ mode, if EZ_DATA_NR is 512, only
   256 B are used. This is because the EZ mode uses 8-bit addresses. */
#define SCB10_EZ_DATA_NR                256u
/* Command/response mode support? ('0': no, '1': yes) */
#define SCB10_CMD_RESP                  0u
/* EZ mode support? ('0': no, '1': yes) */
#define SCB10_EZ                        1u
/* Command/response mode or EZ mode support? (CMD_RESP | EZ) */
#define SCB10_EZ_CMD_RESP               1u
/* I2C slave with EZ mode (I2C_S & EZ) */
#define SCB10_I2C_S_EZ                  1u
/* SPI slave with EZ mode (SPI_S & EZ) */
#define SCB10_SPI_S_EZ                  1u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SCB10_MASTER_WIDTH              8u
/* Number of used spi_select signals (max 4) */
#define SCB10_CHIP_TOP_SPI_SEL_NR       4u
/* Support I2C FM+/1Mbps speed ('0': no, '1': yes) */
#define SCB10_CHIP_TOP_I2C_FAST_PLUS    1u
/* Number of input triggers per counter only routed to one counter (0..8) */
#define TCPWM0_TR_ONE_CNT_NR            3u
/* Number of input triggers routed to all counters (0..254),
   NR_TR_ONE_CNT+NR_TR_ALL CNT <= 254 */
#define TCPWM0_TR_ALL_CNT_NR            12u
/* Number of TCPWM counter groups (1..4) */
#define TCPWM0_GRP_NR                   3u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM0_GRP_NR0_GRP_GRP_CNT_NR   3u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM0_GRP_NR0_CNT_GRP_CNT_WIDTH 16u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM0_GRP_NR0_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define TCPWM0_GRP_NR0_CNT_GRP_AMC_PRESENT 0u
/* Stepper Motor Control features are present (0, 1). */
#define TCPWM0_GRP_NR0_CNT_GRP_SMC_PRESENT 0u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM0_GRP_NR1_GRP_GRP_CNT_NR   3u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM0_GRP_NR1_CNT_GRP_CNT_WIDTH 16u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM0_GRP_NR1_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define TCPWM0_GRP_NR1_CNT_GRP_AMC_PRESENT 1u
/* Stepper Motor Control features are present (0, 1). */
#define TCPWM0_GRP_NR1_CNT_GRP_SMC_PRESENT 1u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM0_GRP_NR2_GRP_GRP_CNT_NR   3u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM0_GRP_NR2_CNT_GRP_CNT_WIDTH 32u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM0_GRP_NR2_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define TCPWM0_GRP_NR2_CNT_GRP_AMC_PRESENT 0u
/* Stepper Motor Control features are present (0, 1). */
#define TCPWM0_GRP_NR2_CNT_GRP_SMC_PRESENT 0u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define TCPWM0_MASTER_WIDTH             8u
/* Number of input triggers per counter only routed to one counter (0..8) */
#define TCPWM1_TR_ONE_CNT_NR            3u
/* Number of input triggers routed to all counters (0..254),
   NR_TR_ONE_CNT+NR_TR_ALL CNT <= 254 */
#define TCPWM1_TR_ALL_CNT_NR            41u
/* Number of TCPWM counter groups (1..4) */
#define TCPWM1_GRP_NR                   3u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM1_GRP_NR0_GRP_GRP_CNT_NR   84u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM1_GRP_NR0_CNT_GRP_CNT_WIDTH 16u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM1_GRP_NR0_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define TCPWM1_GRP_NR0_CNT_GRP_AMC_PRESENT 0u
/* Stepper Motor Control features are present (0, 1). */
#define TCPWM1_GRP_NR0_CNT_GRP_SMC_PRESENT 0u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM1_GRP_NR1_GRP_GRP_CNT_NR   12u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM1_GRP_NR1_CNT_GRP_CNT_WIDTH 16u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM1_GRP_NR1_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define TCPWM1_GRP_NR1_CNT_GRP_AMC_PRESENT 1u
/* Stepper Motor Control features are present (0, 1). */
#define TCPWM1_GRP_NR1_CNT_GRP_SMC_PRESENT 1u
/* Number of counters per TCPWM group (1..256) */
#define TCPWM1_GRP_NR2_GRP_GRP_CNT_NR   13u
/* Counter width in number of bits per TCPWM group (16: 16-bits, 32: 32-bits) */
#define TCPWM1_GRP_NR2_CNT_GRP_CNT_WIDTH 32u
/* Second Capture / Compare Unit is present (0, 1) */
#define TCPWM1_GRP_NR2_CNT_GRP_CC1_PRESENT 1u
/* Advanced Motor Control features are present (0, 1). Should only be 1 when
   GRP_CC1_PRESENT = 1 */
#define TCPWM1_GRP_NR2_CNT_GRP_AMC_PRESENT 0u
/* Stepper Motor Control features are present (0, 1). */
#define TCPWM1_GRP_NR2_CNT_GRP_SMC_PRESENT 0u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define TCPWM1_MASTER_WIDTH             8u
/* Number of TTCAN instances */
#define CANFD0_CAN_NR                   5u
/* ECC logic present or not */
#define CANFD0_ECC_PRESENT              1u
/* address included in ECC logic or not */
#define CANFD0_ECC_ADDR_PRESENT         1u
/* Time Stamp counter present or not (required for instance 0, otherwise not
   allowed) */
#define CANFD0_TS_PRESENT               1u
/* Message RAM size in KB */
#define CANFD0_MRAM_SIZE                40u
/* Message RAM address width */
#define CANFD0_MRAM_ADDR_WIDTH          14u
/* Number of TTCAN instances */
#define CANFD1_CAN_NR                   5u
/* ECC logic present or not */
#define CANFD1_ECC_PRESENT              1u
/* address included in ECC logic or not */
#define CANFD1_ECC_ADDR_PRESENT         1u
/* Time Stamp counter present or not (required for instance 0, otherwise not
   allowed) */
#define CANFD1_TS_PRESENT               0u
/* Message RAM size in KB */
#define CANFD1_MRAM_SIZE                40u
/* Message RAM address width */
#define CANFD1_MRAM_ADDR_WIDTH          14u
/* Number of LIN channels ([2, 32]). For test functionality (two channels are
   connected), the minimal number of LIN channels is 2. */
#define LIN_CH_NR                       20u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define LIN_MASTER_WIDTH                8u
/* Number of SAR blocks */
#define PASS_SAR_ADC_NR                 3u
/* Number of SAR sequencer channels (per SAR) */
#define PASS_SAR_ADC_NR0_SAR_SAR_CHAN_NR 32u
/* Number of MUX inputs (per SAR), must be 8, 16, 24, or 32 */
#define PASS_SAR_ADC_NR0_SAR_SAR_MUX_IN 32u
/* Number of SAR sequencer channels (per SAR) */
#define PASS_SAR_ADC_NR1_SAR_SAR_CHAN_NR 32u
/* Number of MUX inputs (per SAR), must be 8, 16, 24, or 32 */
#define PASS_SAR_ADC_NR1_SAR_SAR_MUX_IN 32u
/* Number of SAR sequencer channels (per SAR) */
#define PASS_SAR_ADC_NR2_SAR_SAR_CHAN_NR 32u
/* Number of MUX inputs (per SAR), must be 8, 16, 24, or 32 */
#define PASS_SAR_ADC_NR2_SAR_SAR_MUX_IN 32u
/* Parameter that is 1 for ADC0 only if ADC1 exists */
#define PASS_SAR_SAR_ADC0               1u
/* Averaging logic present in SAR */
#define PASS_SAR_SAR_AVERAGE            1u
/* Range detect logic present in SAR */
#define PASS_SAR_SAR_RANGEDET           1u
/* Pulse detect logic present in SAR */
#define PASS_SAR_SAR_PULSEDET           1u
/* Number of comparator structures ([1, 32]) */
#define EVTGEN_COMP_STRUCT_NR           16u
/* Spare Enable (0=no spare, 1=max, 2=min) */
#define FLEXRAY_SPARE_EN                1u
/* TX Packet Buffer Size (jumbo frame size is 1.5KB): 00: 16KB to support four
   queues with capacity for two jumbo frames; 01: 8KB to support two queues with
   capacity for two jumbo frames or four queues with capacity for one jumbo
   frame; 10: 4KB to support one queue with capacity for two jumbo frames or two
   queues with capacity for one jumbo frame; 11: 2KB to support one queue with
   capacity for one jumbo frame; */
#define ETH0_TX_PACKET_BUFFER_SIZE      1u
/* RX Packet Buffer Size (jumbo frame size is 1.5KB): 00: 4KB to support capacity
   for two jumbo frames; 01: 2KB to support capacity for one jumbo frames; */
#define ETH0_RX_PACKET_BUFFER_SIZE      0u
/* Selects the clock source to use for the tsu_clk. A value of 0=Internal PCLK, ,
   1=clk_hf */
#define ETH0_TSU_CLK_SOURCE             1u
/* This parameter is used to specify if mxeth should contain a clock divider. The
   clock divider is useful for chips where multiple mxeth are instantiated as it
   allows a single source PLL to be used 0=No Divider, ref_clk_int_in is used as
   is 1=Divider instantiated, ref_clk_int_in should be 125MHz */
#define ETH0_SRC_CLOCK_DIVIDER          1u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define ETH0_SPARE_EN                   1u
/* Number of Priority Queues. */
#define ETH0_ETH_NPQ                    3u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define ETH0_MASTER_WIDTH               8u
/* Platform variant (0=ULL65, 1=MXS40S-ULP, 2=MXS40E, 3=M0S8, 4=MXS40S-HD) */
#define ETH0_PLATFORM_VARIANT           2u
/* RAM vendor (0=CYP, 1=SNPS, 2=ARM) */
#define ETH0_RAM_VEND                   2u
/* TX Packet Buffer Size (jumbo frame size is 1.5KB): 00: 16KB to support four
   queues with capacity for two jumbo frames; 01: 8KB to support two queues with
   capacity for two jumbo frames or four queues with capacity for one jumbo
   frame; 10: 4KB to support one queue with capacity for two jumbo frames or two
   queues with capacity for one jumbo frame; 11: 2KB to support one queue with
   capacity for one jumbo frame; */
#define ETH1_TX_PACKET_BUFFER_SIZE      1u
/* RX Packet Buffer Size (jumbo frame size is 1.5KB): 00: 4KB to support capacity
   for two jumbo frames; 01: 2KB to support capacity for one jumbo frames; */
#define ETH1_RX_PACKET_BUFFER_SIZE      0u
/* Selects the clock source to use for the tsu_clk. A value of 0=Internal PCLK, ,
   1=clk_hf */
#define ETH1_TSU_CLK_SOURCE             1u
/* This parameter is used to specify if mxeth should contain a clock divider. The
   clock divider is useful for chips where multiple mxeth are instantiated as it
   allows a single source PLL to be used 0=No Divider, ref_clk_int_in is used as
   is 1=Divider instantiated, ref_clk_int_in should be 125MHz */
#define ETH1_SRC_CLOCK_DIVIDER          1u
/* Set to 1 if IP will instantiate spares (0=None, 1=Max, 2=Min) */
#define ETH1_SPARE_EN                   1u
/* Number of Priority Queues. */
#define ETH1_ETH_NPQ                    3u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define ETH1_MASTER_WIDTH               8u
/* Platform variant (0=ULL65, 1=MXS40S-ULP, 2=MXS40E, 3=M0S8, 4=MXS40S-HD) */
#define ETH1_PLATFORM_VARIANT           2u
/* RAM vendor (0=CYP, 1=SNPS, 2=ARM) */
#define ETH1_RAM_VEND                   2u
/* Base address of the SMIF XIP memory region. This address must be a multiple of
   the SMIF XIP memory capacity. This address must be a multiple of the SMIF XIP
   memory region capacity (see SMIP_XIP_MASK below). The SMIF XIP memory region
   should NOT overlap with other memory regions. This adress must be in the
   [0x0000:0000, 0xffff:0000] memory region. However, for MXS40 CM4 based
   platform variant, this address must be in the [0x0000:0000, 0x1fff:0000]
   memory region (to ensure a connection to the ARM CM4 CPU ICode/DCode memory
   region [0x0000:0000, 0x1fff:ffff]). The external memory devices are located
   within the SMIF XIP memory region. */
#define SMIF_SMIF_XIP_ADDR              1610612736u
/* Capacity of the SMIF XIP memory region. The capacity must be a power of 2 and
   greater or equal than 64 KB). The more significant bits of this parameter are
   '1' and the lesser significant bits of this parameter are '0'. E.g.,
   0xfff0:0000 specifies a 1 MB memory region. Legal values are {0xffff:0000,
   0xfffe:0000, 0xfffc:0000, 0xfff8:0000, 0xfff0:0000, 0xffe0:0000, ...,
   0x8000:0000, 0x0000:0000}. */
#define SMIF_SMIF_XIP_MASK              4160749568u
/* Cryptography (AES) support. This is a 1-bit parameter: '0' = no support, '1' =
   support. */
#define SMIF_CRYPTO                     1u
/* Bus CRC support is present ([0,1]) Note: In MXS40 SMIF version 2 this option is
   currently not available (BUS_CRC_PRESENT=0). Based on project schedules this
   feature may be added already to MXS40 SMIF version 2 or to a later SMIF
   version. */
#define SMIF_BUS_CRC_PRESENT            0u
/* Number of external memory devices supported. This parameter is in the range
   [1,4]. */
#define SMIF_DEVICE_NR                  2u
/* External memory devices write support. This is a 4-bit field. Each external
   memory device has a dedicated bit. E.g., if bit 2 is '1', external device 2
   has write support. */
#define SMIF_DEVICE_WR_EN               3u
/* Number of delay lines ([1..8]). */
#define SMIF_DELAY_LINES_NR             4u
/* Number of delay taps in clock delay line. */
#define SMIF_DELAY_TAPS_NR              32u
/* AXI ID width. Legal range [11,16] */
#define SMIF_AXIS_ID_WIDTH              12u
/* Number of AHB-Lite "hmaster[]" bits ([1, 8]). */
#define SMIF_MASTER_WIDTH               8u
/* Chip top connect all 8 data pins (0= connect 4 data pins, 1= connect 8 data
   pins) */
#define SMIF_CHIP_TOP_DATA8_PRESENT     1u
/* Number of used spi_select signals (max 4) */
#define SMIF_CHIP_TOP_SPI_SEL_NR        2u
/* Basically the max packet size, which gets double buffered in RAM 0: 512B
   (implies 1KB of RAM space for data) 1: 1KB (implies 2KB of RAM space for
   data) */
#define SDHC_MAX_BLK_SIZE               0u
/* 0: No Command Queuing Engine present 1: Command Queuing Engine present; this
   adds 288 bytes of space to the RAM for this purpose. */
#define SDHC_CQE_PRESENT                0u
/* 0: no retention of any SDHC_CORE regs 1: retention of SDHC_CORE regs that have
   the Retention flag (Note, CTL.ENABLE is always retained irrespective of this
   parameter) */
#define SDHC_RETENTION_PRESENT          0u
/* Basically the max packet size, which gets double buffered in RAM 0: 512B
   (implies 1KB of RAM space for data) 1: 1KB (implies 2KB of RAM space for
   data) */
#define SDHC_CORE_MAX_BLK_SIZE          0u
/* 0: No Command Queuing Engine present 1: Command Queuing Engine present; this
   adds 288 bytes of space to the RAM for this purpose. */
#define SDHC_CORE_CQE_PRESENT           0u
/* 0: no retention of any SDHC_CORE regs 1: retention of SDHC_CORE regs that have
   the Retention flag (Note, CTL.ENABLE is always retained irrespective of this
   parameter) */
#define SDHC_CORE_RETENTION_PRESENT     0u
/* Chip top connect all 8 data pins (0= connect 4 data pins, 1= connect 8 data
   pins) */
#define SDHC_CHIP_TOP_DATA8_PRESENT     1u
/* Chip top connect card_detect */
#define SDHC_CHIP_TOP_CARD_DETECT_PRESENT 1u
/* Chip top connect card_mech_write_prot_in */
#define SDHC_CHIP_TOP_CARD_WRITE_PROT_PRESENT 1u
/* Chip top connect led_ctrl_out and led_ctrl_out_en */
#define SDHC_CHIP_TOP_LED_CTRL_PRESENT  0u
/* Chip top connect io_volt_sel_out and io_volt_sel_out_en */
#define SDHC_CHIP_TOP_IO_VOLT_SEL_PRESENT 0u
/* Chip top connect io_drive_strength_out and io_drive_strength_out_en */
#define SDHC_CHIP_TOP_IO_DRIVE_STRENGTH_PRESENT 0u
/* Chip top connect card_if_pwr_en_out and card_if_pwr_en_out_en */
#define SDHC_CHIP_TOP_CARD_IF_PWR_EN_PRESENT 1u
/* Chip top connect card_emmc_reset_n_out and card_emmc_reset_n_out_en */
#define SDHC_CHIP_TOP_CARD_EMMC_RESET_PRESENT 0u
/* Chip top connect interrupt_wakeup (not used for eMMC) */
#define SDHC_CHIP_TOP_INTERRUPT_WAKEUP_PRESENT 1u
/* I2S capable? (0=No,1=Yes) */
#define AUDIOSS0_I2S_I2S                1u
/* I2S instantiates both RX and TX. 0=TX Only 1=RX Plus TX present */
#define AUDIOSS0_I2S_I2S_RX_TX          1u
/* PDM capable? (0=No,1=Yes) */
#define AUDIOSS0_PDM_PDM                0u
/* I2S capable? (0=No,1=Yes) */
#define AUDIOSS1_I2S_I2S                1u
/* I2S instantiates both RX and TX. 0=TX Only 1=RX Plus TX present */
#define AUDIOSS1_I2S_I2S_RX_TX          1u
/* PDM capable? (0=No,1=Yes) */
#define AUDIOSS1_PDM_PDM                0u
/* I2S capable? (0=No,1=Yes) */
#define AUDIOSS2_I2S_I2S                1u
/* I2S instantiates both RX and TX. 0=TX Only 1=RX Plus TX present */
#define AUDIOSS2_I2S_I2S_RX_TX          1u
/* PDM capable? (0=No,1=Yes) */
#define AUDIOSS2_PDM_PDM                0u

/* MMIO Targets Defines */
#define CY_MMIO_CRYPTO_GROUP_NR         1u
#define CY_MMIO_CRYPTO_SLAVE_NR         0u
#define CY_MMIO_CPUSS_GROUP_NR          2u
#define CY_MMIO_CPUSS_SLAVE_NR          0u
#define CY_MMIO_FAULT_GROUP_NR          2u
#define CY_MMIO_FAULT_SLAVE_NR          1u
#define CY_MMIO_IPC_GROUP_NR            2u
#define CY_MMIO_IPC_SLAVE_NR            2u
#define CY_MMIO_PROT_GROUP_NR           2u
#define CY_MMIO_PROT_SLAVE_NR           3u
#define CY_MMIO_FLASHC_GROUP_NR         2u
#define CY_MMIO_FLASHC_SLAVE_NR         4u
#define CY_MMIO_SRSS_GROUP_NR           2u
#define CY_MMIO_SRSS_SLAVE_NR           5u
#define CY_MMIO_BACKUP_GROUP_NR         2u
#define CY_MMIO_BACKUP_SLAVE_NR         6u
#define CY_MMIO_DW_GROUP_NR             2u
#define CY_MMIO_DW_SLAVE_NR             7u
#define CY_MMIO_DMAC_GROUP_NR           2u
#define CY_MMIO_DMAC_SLAVE_NR           9u
#define CY_MMIO_EFUSE_GROUP_NR          2u
#define CY_MMIO_EFUSE_SLAVE_NR          10u
#define CY_MMIO_DFT_GROUP_NR            2u
#define CY_MMIO_DFT_SLAVE_NR            11u
#define CY_MMIO_HSIOM_GROUP_NR          3u
#define CY_MMIO_HSIOM_SLAVE_NR          0u
#define CY_MMIO_GPIO_GROUP_NR           3u
#define CY_MMIO_GPIO_SLAVE_NR           1u
#define CY_MMIO_SMARTIO_GROUP_NR        3u
#define CY_MMIO_SMARTIO_SLAVE_NR        2u
#define CY_MMIO_TCPWM0_GROUP_NR         3u
#define CY_MMIO_TCPWM0_SLAVE_NR         3u
#define CY_MMIO_EVTGEN0_GROUP_NR        3u
#define CY_MMIO_EVTGEN0_SLAVE_NR        4u
#define CY_MMIO_SMIF0_GROUP_NR          4u
#define CY_MMIO_SMIF0_SLAVE_NR          0u
#define CY_MMIO_SDHC0_GROUP_NR          4u
#define CY_MMIO_SDHC0_SLAVE_NR          1u
#define CY_MMIO_ETH0_GROUP_NR           4u
#define CY_MMIO_ETH0_SLAVE_NR           2u
#define CY_MMIO_ETH1_GROUP_NR           4u
#define CY_MMIO_ETH1_SLAVE_NR           3u
#define CY_MMIO_LIN0_GROUP_NR           5u
#define CY_MMIO_LIN0_SLAVE_NR           0u
#define CY_MMIO_CANFD0_GROUP_NR         5u
#define CY_MMIO_CANFD0_SLAVE_NR         1u
#define CY_MMIO_CANFD1_GROUP_NR         5u
#define CY_MMIO_CANFD1_SLAVE_NR         2u
#define CY_MMIO_FLEXRAY0_GROUP_NR       5u
#define CY_MMIO_FLEXRAY0_SLAVE_NR       3u
#define CY_MMIO_TCPWM1_GROUP_NR         5u
#define CY_MMIO_TCPWM1_SLAVE_NR         4u
#define CY_MMIO_SCB0_GROUP_NR           6u
#define CY_MMIO_SCB0_SLAVE_NR           0u
#define CY_MMIO_SCB1_GROUP_NR           6u
#define CY_MMIO_SCB1_SLAVE_NR           1u
#define CY_MMIO_SCB2_GROUP_NR           6u
#define CY_MMIO_SCB2_SLAVE_NR           2u
#define CY_MMIO_SCB3_GROUP_NR           6u
#define CY_MMIO_SCB3_SLAVE_NR           3u
#define CY_MMIO_SCB4_GROUP_NR           6u
#define CY_MMIO_SCB4_SLAVE_NR           4u
#define CY_MMIO_SCB5_GROUP_NR           6u
#define CY_MMIO_SCB5_SLAVE_NR           5u
#define CY_MMIO_SCB6_GROUP_NR           6u
#define CY_MMIO_SCB6_SLAVE_NR           6u
#define CY_MMIO_SCB7_GROUP_NR           6u
#define CY_MMIO_SCB7_SLAVE_NR           7u
#define CY_MMIO_SCB8_GROUP_NR           6u
#define CY_MMIO_SCB8_SLAVE_NR           8u
#define CY_MMIO_SCB9_GROUP_NR           6u
#define CY_MMIO_SCB9_SLAVE_NR           9u
#define CY_MMIO_SCB10_GROUP_NR          6u
#define CY_MMIO_SCB10_SLAVE_NR          10u
#define CY_MMIO_I2S0_GROUP_NR           8u
#define CY_MMIO_I2S0_SLAVE_NR           0u
#define CY_MMIO_I2S1_GROUP_NR           8u
#define CY_MMIO_I2S1_SLAVE_NR           1u
#define CY_MMIO_I2S2_GROUP_NR           8u
#define CY_MMIO_I2S2_SLAVE_NR           2u
#define CY_MMIO_PASS0_GROUP_NR          9u
#define CY_MMIO_PASS0_SLAVE_NR          0u

#endif /* _CYT4BF_CONFIG_H_ */


/* [] END OF FILE */
