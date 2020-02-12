/***************************************************************************//**
* \file bb_bsp_tvic2d6m.h
*
* \brief
* Project specific header
*
* \note
* It contains references to all generated header files and should
* not be modified.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef BB_BSP_TVIIC2D6M_H
#define BB_BSP_TVIIC2D6M_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/******************************************************************************/

// PSVP supports only 500-bga package

#if (CY_USE_PSVP == 1) && ( tviic2d6m )

// Adapter Board Entities

/******************************************************************************/
/*                      USER LED AB Mux (GPIO_133)                            */
/******************************************************************************/
#define CY_AB_LED_PORT                  GPIO_PRT7
#define CY_AB_LED_PIN                   5
#define CY_AB_LED_PIN_MUX               P7_5_GPIO

/******************************************************************************/
/*                      Button AB Mux (GPIO_134)                              */
/******************************************************************************/
#define CY_AB_BUTTON_PORT               GPIO_PRT4
#define CY_AB_BUTTON_PIN                7
#define CY_AB_BUTTON_PIN_MUX            P4_7_GPIO

/* Setup GPIO for BUTTON AB interrupt sources */
#define CY_AB_BUTTON_IRQN               ioss_interrupts_gpio_dpslp_4_IRQn

/******************************************************************************/
/*                      SCB AB Mux                                            */
/******************************************************************************/
/* USB-UART Mux */
#define CY_USB_SCB_TYPE                 SCB1
#define CY_USB_SCB_UART_RX_PORT         GPIO_PRT15
#define CY_USB_SCB_UART_RX_PIN          2
#define CY_USB_SCB_UART_RX_MUX          P15_2_SCB1_UART_RX
#define CY_USB_SCB_UART_TX_PORT         GPIO_PRT15
#define CY_USB_SCB_UART_TX_PIN          3
#define CY_USB_SCB_UART_TX_MUX          P15_3_SCB1_UART_TX
#define CY_USB_SCB_UART_PCLK            PCLK_SCB1_CLOCK
#define CY_USB_SCB_UART_IRQN            scb_1_interrupt_IRQn

/******************************************************************************/
/*                      SMIF0 Definitions                                     */
/******************************************************************************/

#define CY_SMIF0_CLK_PORT                      GPIO_PRT24
#define CY_SMIF0_CLK_PIN                       1
#define CY_SMIF0_CLK_PIN_MUX                   P24_1_SMIF0_SPIHB_CLK

#define CY_SMIF0_RWDS_PORT                     GPIO_PRT23
#define CY_SMIF0_RWDS_PIN                      4
#define CY_SMIF0_RWDS_PIN_MUX                  P23_4_SMIF0_SPIHB_RWDS

#define CY_SMIF0_SELECT0_PORT                  GPIO_PRT25
#define CY_SMIF0_SELECT0_PIN                   2
#define CY_SMIF0_SELECT0_PIN_MUX               P25_2_SMIF0_SPIHB_SELECT0

#define CY_SMIF0_SELECT1_PORT                  GPIO_PRT25
#define CY_SMIF0_SELECT1_PIN                   5
#define CY_SMIF0_SELECT1_PIN_MUX               P25_5_SMIF0_SPIHB_SELECT1

#define CY_SMIF0_DATA0_PORT                    GPIO_PRT25
#define CY_SMIF0_DATA0_PIN                     0
#define CY_SMIF0_DATA0_PIN_MUX                 P25_0_SMIF0_SPIHB_DATA0

#define CY_SMIF0_DATA1_PORT                    GPIO_PRT25
#define CY_SMIF0_DATA1_PIN                     3
#define CY_SMIF0_DATA1_PIN_MUX                 P25_3_SMIF0_SPIHB_DATA1

#define CY_SMIF0_DATA2_PORT                    GPIO_PRT23
#define CY_SMIF0_DATA2_PIN                     1
#define CY_SMIF0_DATA2_PIN_MUX                 P23_1_SMIF0_SPIHB_DATA2

#define CY_SMIF0_DATA3_PORT                    GPIO_PRT23
#define CY_SMIF0_DATA3_PIN                     2
#define CY_SMIF0_DATA3_PIN_MUX                 P23_2_SMIF0_SPIHB_DATA3

#define CY_SMIF0_DATA4_PORT                    GPIO_PRT23
#define CY_SMIF0_DATA4_PIN                     0
#define CY_SMIF0_DATA4_PIN_MUX                 P23_0_SMIF0_SPIHB_DATA4

#define CY_SMIF0_DATA5_PORT                    GPIO_PRT23
#define CY_SMIF0_DATA5_PIN                     3
#define CY_SMIF0_DATA5_PIN_MUX                 P23_3_SMIF0_SPIHB_DATA5

#define CY_SMIF0_DATA6_PORT                    GPIO_PRT25
#define CY_SMIF0_DATA6_PIN                     1
#define CY_SMIF0_DATA6_PIN_MUX                 P25_1_SMIF0_SPIHB_DATA6

#define CY_SMIF0_DATA7_PORT                    GPIO_PRT25
#define CY_SMIF0_DATA7_PIN                     4
#define CY_SMIF0_DATA7_PIN_MUX                 P25_4_SMIF0_SPIHB_DATA7

// BB Board Entities

/******************************************************************************/
/*                      LEDs Base Board Mux                                   */
/******************************************************************************/
#define CY_LED0_PORT                    GPIO_PRT7
#define CY_LED0_PIN                     1
#define CY_LED0_PIN_MUX                 P7_1_GPIO

#define CY_LED1_PORT                    GPIO_PRT4
#define CY_LED1_PIN                     5
#define CY_LED1_PIN_MUX                 P4_5_GPIO

#define CY_LED2_PORT                    GPIO_PRT3
#define CY_LED2_PIN                     4
#define CY_LED2_PIN_MUX                 P3_4_GPIO

#define CY_LED3_PORT                    GPIO_PRT2
#define CY_LED3_PIN                     1
#define CY_LED3_PIN_MUX                 P2_1_GPIO

#define CY_LED4_PORT                    GPIO_PRT7
#define CY_LED4_PIN                     6
#define CY_LED4_PIN_MUX                 P7_6_GPIO

#define CY_LED5_PORT                    GPIO_PRT7
#define CY_LED5_PIN                     4
#define CY_LED5_PIN_MUX                 P7_4_GPIO

#define CY_LED6_PORT                    GPIO_PRT4
#define CY_LED6_PIN                     6
#define CY_LED6_PIN_MUX                 P4_6_GPIO

#define CY_LED7_PORT                    GPIO_PRT3
#define CY_LED7_PIN                     1
#define CY_LED7_PIN_MUX                 P3_1_GPIO

#define CY_LED8_PORT                    GPIO_PRT2
#define CY_LED8_PIN                     2
#define CY_LED8_PIN_MUX                 P2_2_GPIO

#define CY_LED9_PORT                    GPIO_PRT7
#define CY_LED9_PIN                     7
#define CY_LED9_PIN_MUX                 P7_7_GPIO

/******************************************************************************/
/*                      Buttons Base Board Mux                                */
/******************************************************************************/
#define CY_BUTTON1_PORT                 GPIO_PRT7
#define CY_BUTTON1_PIN                  2
#define CY_BUTTON1_PIN_MUX              P7_2_GPIO

#define CY_BUTTON2_PORT                 GPIO_PRT4
#define CY_BUTTON2_PIN                  4
#define CY_BUTTON2_PIN_MUX              P4_4_GPIO

#define CY_BUTTON3_PORT                 GPIO_PRT2
#define CY_BUTTON3_PIN                  0
#define CY_BUTTON3_PIN_MUX              P2_0_GPIO

#define CY_BUTTON4_PORT                 GPIO_PRT12
#define CY_BUTTON4_PIN                  1
#define CY_BUTTON4_PIN_MUX              P12_1_GPIO

#define CY_BUTTON5_PORT                 GPIO_PRT7
#define CY_BUTTON5_PIN                  3
#define CY_BUTTON5_PIN_MUX              P7_3_GPIO

/* Setup GPIO for BUTTONs 1/2/3/4/5 interrupt sources */
#define CY_BUTTON1_IRQN                 ioss_interrupts_gpio_dpslp_7_IRQn
#define CY_BUTTON2_IRQN                 ioss_interrupts_gpio_dpslp_4_IRQn
#define CY_BUTTON3_IRQN                 ioss_interrupts_gpio_dpslp_2_IRQn
#define CY_BUTTON4_IRQN                 ioss_interrupts_gpio_dpslp_12_IRQn
#define CY_BUTTON5_IRQN                 ioss_interrupts_gpio_dpslp_7_IRQn

/******************************************************************************/
/*                      ADC POT                                               */
/******************************************************************************/

#define CY_ADC_POT_MACRO                SAR0
#define CY_ADC_POT_IN_NO                18
#define CY_ADC_POT_PORT                 GPIO_PRT0
#define CY_ADC_POT_PIN                  6
#define CY_ADC_POT_PIN_MUX              P0_6_GPIO
#define CY_ADC_POT_PCLK                 PCLK_PASS0_CLOCK_SAR0
#define CY_ADC_POT_IRQN                 pass_0_interrupts_sar_0_IRQn  // This is logical channel, so it is not board specific

/******************************************************************************/
/*                      SCB Base Board Mux                                    */
/******************************************************************************/

/* USB-UART Mux */


/* CANFD-SPI Mux (BB_CAN_SPI) */


/* EEPROM SPI Mux (BB_SPI0) */


/******************************************************************************/
/*                      CANFD Base Board Mux                                  */
/******************************************************************************/

/* CAN0 Pin Mux */
#define CY_CANFD0_TYPE                  CY_CANFD1_0_TYPE
#define CY_CANFD0_RX_PORT               GPIO_PRT21
#define CY_CANFD0_RX_PIN                3
#define CY_CANFD0_RX_MUX                P21_3_CANFD1_TTCAN_RX0
#define CY_CANFD0_TX_PORT               GPIO_PRT21
#define CY_CANFD0_TX_PIN                2
#define CY_CANFD0_TX_MUX                P21_2_CANFD1_TTCAN_TX0
#define CY_CANFD0_PCLK                  PCLK_CANFD1_CLOCK_CAN0
#define CY_CANFD0_IRQN                  canfd_1_interrupts0_0_IRQn

/* CAN1 Pin Mux */
#define CY_CANFD1_TYPE                  CY_CANFD1_3_TYPE                   // TODO
#define CY_CANFD1_RX_PORT               GPIO_PRT15                         // TODO
#define CY_CANFD1_RX_PIN                1                                  // TODO
#define CY_CANFD1_RX_MUX                P15_1_CANFD1_TTCAN_RX3             // TODO
#define CY_CANFD1_TX_PORT               GPIO_PRT15                         // TODO
#define CY_CANFD1_TX_PIN                0                                  // TODO
#define CY_CANFD1_TX_MUX                P15_0_CANFD1_TTCAN_TX3             // TODO
#define CY_CANFD1_PCLK                  PCLK_CANFD1_CLOCK_CAN3             // TODO
#define CY_CANFD1_IRQN                  canfd_1_interrupts0_3_IRQn         // TODO

/* CAN2 Pin Mux */                                                         // TODO
#define CY_CANFD2_TYPE                  CY_CANFD0_2_TYPE                   // TODO
#define CY_CANFD2_RX_PORT               GPIO_PRT6                          // TODO
#define CY_CANFD2_RX_PIN                3                                  // TODO
#define CY_CANFD2_RX_MUX                P6_3_CANFD0_TTCAN_RX2              // TODO
#define CY_CANFD2_TX_PORT               GPIO_PRT12                         // TODO
#define CY_CANFD2_TX_PIN                0                                  // TODO
#define CY_CANFD2_TX_MUX                P12_0_CANFD0_TTCAN_TX2             // TODO
#define CY_CANFD2_PCLK                  PCLK_CANFD0_CLOCK_CAN2             // TODO
#define CY_CANFD2_IRQN                  canfd_0_interrupts0_2_IRQn         // TODO

/* CAN3 Pin Mux */                                                         // TODO
#define CY_CANFD3_TYPE                  CY_CANFD1_0_TYPE                   // TODO
#define CY_CANFD3_RX_PORT               GPIO_PRT23                         // TODO
#define CY_CANFD3_RX_PIN                1                                  // TODO
#define CY_CANFD3_RX_MUX                P23_1_CANFD1_TTCAN_RX0             // TODO
#define CY_CANFD3_TX_PORT               GPIO_PRT14                         // TODO
#define CY_CANFD3_TX_PIN                0                                  // TODO
#define CY_CANFD3_TX_MUX                P14_0_CANFD1_TTCAN_TX0             // TODO
#define CY_CANFD3_PCLK                  PCLK_CANFD1_CLOCK_CAN0             // TODO
#define CY_CANFD3_IRQN                  canfd_1_interrupts0_0_IRQn         // TODO

/******************************************************************************/
/*                      LIN Base Board Mux                                    */
/******************************************************************************/

/* LIN Channel 0 */
#define CY_LINCH0_TYPE                  LIN0_CH0                            // TODO
#define CY_LINCH0_RX_PORT               GPIO_PRT1                           // TODO
#define CY_LINCH0_RX_PIN                2                                   // TODO
#define CY_LINCH0_RX_PIN_MUX            P1_2_LIN0_LIN_RX0                   // TODO
#define CY_LINCH0_TX_PORT               GPIO_PRT21                          // TODO
#define CY_LINCH0_TX_PIN                6                                   // TODO
#define CY_LINCH0_TX_PIN_MUX            P21_6_LIN0_LIN_TX0                  // TODO
#define CY_LINCH0_PCLK                  PCLK_LIN0_CLOCK_CH_EN0              // TODO
#define CY_LINCH0_IRQN                  lin_0_interrupts_0_IRQn             // TODO

/* LIN Channel 1 */
#define CY_LINCH1_TYPE                  LIN0_CH6                            // TODO
#define CY_LINCH1_RX_PORT               GPIO_PRT12                          // TODO
#define CY_LINCH1_RX_PIN                2                                   // TODO
#define CY_LINCH1_RX_PIN_MUX            P12_2_LIN0_LIN_RX6                  // TODO
#define CY_LINCH1_TX_PORT               GPIO_PRT12                          // TODO
#define CY_LINCH1_TX_PIN                3                                   // TODO
#define CY_LINCH1_TX_PIN_MUX            P12_3_LIN0_LIN_TX6                  // TODO
#define CY_LINCH1_PCLK                  PCLK_LIN0_CLOCK_CH_EN6              // TODO
#define CY_LINCH1_IRQN                  lin_0_interrupts_6_IRQn

/******************************************************************************/
/*                      SMARTIO Base Board Mux                                */
/******************************************************************************/

#define CY_SMARTIO_MACRO                SMARTIO                             // TODO
#define CY_SMARTIO_PORT                 SMARTIO_PRT15                       // TODO
#define CY_SMARTIO_CLK                  PCLK_SMARTIO15_CLOCK                // TODO

#define CY_SMARTIO_OUT_PORT             GPIO_PRT15                          // TODO
#define CY_SMARTIO_OUT_PIN              1                                   // TODO
#define CY_SMARTIO_OUT_PORT_MUX         P15_1_GPIO                          // TODO

#define CY_SMARTIO_IN_PORT              GPIO_PRT15                          // TODO
#define CY_SMARTIO_IN_PIN               0                                   // TODO
#define CY_SMARTIO_IN_PORT_MUX          P15_0_GPIO                          // TODO

// Cluster Extension Board entities

/******************************************************************************/
/*                      USER LED CEB Mux (GPIO_202)                           */
/******************************************************************************/

#define CY_CEB_LED_PORT                         GPIO_PRT13                          // TODO for CFR, configuring unused GPIO_002 net on AB for now
#define CY_CEB_LED_PIN                          4                                   // TODO for CFR, configuring unused GPIO_002 net on AB for now
#define CY_CEB_LED_PIN_MUX                      P13_4_GPIO                          // TODO for CFR, configuring unused GPIO_002 net on AB for now

/******************************************************************************/
/*                      Button CEB Mux (GPIO_201)                             */
/******************************************************************************/

#define CY_CEB_BUTTON_PORT                      GPIO_PRT13                          // TODO for CFR, configuring unused GPIO_003 net on AB for now
#define CY_CEB_BUTTON_PIN                       1                                   // TODO for CFR, configuring unused GPIO_003 net on AB for now
#define CY_CEB_BUTTON_PIN_MUX                   P13_1_GPIO                          // TODO for CFR, configuring unused GPIO_003 net on AB for now

#define CY_CEB_BUTTON_IRQN                      ioss_interrupts_gpio_dpslp_13_IRQn  // TODO for CFR, configuring unused GPIO_003 net on AB for now

/******************************************************************************/
/*                      SMIF1 Definitions                                     */
/******************************************************************************/

#define CY_SMIF1_CLK_PORT                      GPIO_PRT27
#define CY_SMIF1_CLK_PIN                       1
#define CY_SMIF1_CLK_PIN_MUX                   P27_1_SMIF1_SPIHB_CLK

#define CY_SMIF1_RWDS_PORT                     GPIO_PRT26
#define CY_SMIF1_RWDS_PIN                      4
#define CY_SMIF1_RWDS_PIN_MUX                  P26_4_SMIF1_SPIHB_RWDS

#define CY_SMIF1_SELECT0_PORT                  GPIO_PRT28
#define CY_SMIF1_SELECT0_PIN                   2
#define CY_SMIF1_SELECT0_PIN_MUX               P28_2_SMIF1_SPIHB_SELECT0

#define CY_SMIF1_SELECT1_PORT                  GPIO_PRT28
#define CY_SMIF1_SELECT1_PIN                   5
#define CY_SMIF1_SELECT1_PIN_MUX               P28_5_SMIF1_SPIHB_SELECT1

#define CY_SMIF1_DATA0_PORT                    GPIO_PRT28
#define CY_SMIF1_DATA0_PIN                     0
#define CY_SMIF1_DATA0_PIN_MUX                 P28_0_SMIF1_SPIHB_DATA0

#define CY_SMIF1_DATA1_PORT                    GPIO_PRT28
#define CY_SMIF1_DATA1_PIN                     3
#define CY_SMIF1_DATA1_PIN_MUX                 P28_3_SMIF1_SPIHB_DATA1

#define CY_SMIF1_DATA2_PORT                    GPIO_PRT26
#define CY_SMIF1_DATA2_PIN                     1
#define CY_SMIF1_DATA2_PIN_MUX                 P26_1_SMIF1_SPIHB_DATA2

#define CY_SMIF1_DATA3_PORT                    GPIO_PRT26
#define CY_SMIF1_DATA3_PIN                     2
#define CY_SMIF1_DATA3_PIN_MUX                 P26_2_SMIF1_SPIHB_DATA3

#define CY_SMIF1_DATA4_PORT                    GPIO_PRT26
#define CY_SMIF1_DATA4_PIN                     0
#define CY_SMIF1_DATA4_PIN_MUX                 P26_0_SMIF1_SPIHB_DATA4

#define CY_SMIF1_DATA5_PORT                    GPIO_PRT26
#define CY_SMIF1_DATA5_PIN                     3
#define CY_SMIF1_DATA5_PIN_MUX                 P26_3_SMIF1_SPIHB_DATA5

#define CY_SMIF1_DATA6_PORT                    GPIO_PRT28
#define CY_SMIF1_DATA6_PIN                     1
#define CY_SMIF1_DATA6_PIN_MUX                 P28_1_SMIF1_SPIHB_DATA6

#define CY_SMIF1_DATA7_PORT                    GPIO_PRT28
#define CY_SMIF1_DATA7_PIN                     4
#define CY_SMIF1_DATA7_PIN_MUX                 P28_4_SMIF1_SPIHB_DATA7

#define CY_SMIF_S25FXXXS                       (0u)
#define CY_SMIF_S25FXXXL                       (1u)
#define CY_SMIF0_QUAD_MEMORY                   CY_SMIF_S25FXXXS


/******************************************************************************/
/*                 Backlight Display #0 Definitions                           */
/******************************************************************************/

// #define CY_BL_DISP0_EN_PORT                    GPIO_PRT?      // only jumper, not SW controllable
// #define CY_BL_DISP0_EN_PIN                     ?              // only jumper, not SW controllable
// #define CY_BL_DISP0_EN_PIN_MUX                 P?_?_GPIO      // only jumper, not SW controllable

#define CY_BL_DISP0_PWM_PORT                   GPIO_PRT13                                             // TODO for CFR, configuring unused GPIO_006 net on AB for now
#define CY_BL_DISP0_PWM_PIN                    6                                                      // TODO for CFR, configuring unused GPIO_006 net on AB for now
#define CY_BL_DISP0_PWM_PIN_MUX                P13_6_GPIO  // use as GPIO for now (0% or 100% PWM)    // TODO for CFR, configuring unused GPIO_006 net on AB for now

/******************************************************************************/
/*                 Backlight Display #1 Definitions                           */
/******************************************************************************/

// #define CY_BL_DISP1_EN_PORT                    GPIO_PRT?      // only jumper, not SW controllable
// #define CY_BL_DISP1_EN_PIN                     ?              // only jumper, not SW controllable
// #define CY_BL_DISP1_EN_PIN_MUX                 P?_?_GPIO      // only jumper, not SW controllable

#define CY_BL_DISP1_PWM_PORT                   GPIO_PRT13                                             // TODO for CFR, configuring unused GPIO_007 net on AB for now
#define CY_BL_DISP1_PWM_PIN                    7                                                      // TODO for CFR, configuring unused GPIO_007 net on AB for now
#define CY_BL_DISP1_PWM_PIN_MUX                P13_7_GPIO  // use as GPIO for now (0% or 100% PWM)    // TODO for CFR, configuring unused GPIO_007 net on AB for now

/******************************************************************************/
/*                      Display #0 Definitions                                */
/******************************************************************************/

#define CY_DISP0_CLK_PORT                      GPIO_PRT8
#define CY_DISP0_CLK_PIN                       3
#define CY_DISP0_CLK_PIN_MUX                   P8_3_VIDEOSS0_TTL_DSP0_CLOCK

#define CY_DISP0_CTRL0_PORT                    GPIO_PRT8
#define CY_DISP0_CTRL0_PIN                     0
#define CY_DISP0_CTRL0_PIN_MUX                 P8_0_VIDEOSS0_TTL_DSP0_CONTROL0

#define CY_DISP0_CTRL1_PORT                    GPIO_PRT8
#define CY_DISP0_CTRL1_PIN                     1
#define CY_DISP0_CTRL1_PIN_MUX                 P8_1_VIDEOSS0_TTL_DSP0_CONTROL1

#define CY_DISP0_CTRL2_PORT                    GPIO_PRT8
#define CY_DISP0_CTRL2_PIN                     2
#define CY_DISP0_CTRL2_PIN_MUX                 P8_2_VIDEOSS0_TTL_DSP0_CONTROL2

#define CY_DISP0_DATA_A0_0_PORT                GPIO_PRT12
#define CY_DISP0_DATA_A0_0_PIN                 2
#define CY_DISP0_DATA_A0_0_PIN_MUX             P12_2_VIDEOSS0_TTL_DSP0_DATA_A00

#define CY_DISP0_DATA_A0_1_PORT                GPIO_PRT12
#define CY_DISP0_DATA_A0_1_PIN                 4
#define CY_DISP0_DATA_A0_1_PIN_MUX             P12_4_VIDEOSS0_TTL_DSP0_DATA_A01

#define CY_DISP0_DATA_A0_2_PORT                GPIO_PRT12
#define CY_DISP0_DATA_A0_2_PIN                 6
#define CY_DISP0_DATA_A0_2_PIN_MUX             P12_6_VIDEOSS0_TTL_DSP0_DATA_A02

#define CY_DISP0_DATA_A0_3_PORT                GPIO_PRT5
#define CY_DISP0_DATA_A0_3_PIN                 0
#define CY_DISP0_DATA_A0_3_PIN_MUX             P5_0_VIDEOSS0_TTL_DSP0_DATA_A03

#define CY_DISP0_DATA_A0_4_PORT                GPIO_PRT5
#define CY_DISP0_DATA_A0_4_PIN                 2
#define CY_DISP0_DATA_A0_4_PIN_MUX             P5_2_VIDEOSS0_TTL_DSP0_DATA_A04

#define CY_DISP0_DATA_A0_5_PORT                GPIO_PRT5
#define CY_DISP0_DATA_A0_5_PIN                 4
#define CY_DISP0_DATA_A0_5_PIN_MUX             P5_4_VIDEOSS0_TTL_DSP0_DATA_A05

#define CY_DISP0_DATA_A0_6_PORT                GPIO_PRT5
#define CY_DISP0_DATA_A0_6_PIN                 6
#define CY_DISP0_DATA_A0_6_PIN_MUX             P5_6_VIDEOSS0_TTL_DSP0_DATA_A06

#define CY_DISP0_DATA_A0_7_PORT                GPIO_PRT6
#define CY_DISP0_DATA_A0_7_PIN                 0
#define CY_DISP0_DATA_A0_7_PIN_MUX             P6_0_VIDEOSS0_TTL_DSP0_DATA_A07

#define CY_DISP0_DATA_A0_8_PORT                GPIO_PRT6
#define CY_DISP0_DATA_A0_8_PIN                 2
#define CY_DISP0_DATA_A0_8_PIN_MUX             P6_2_VIDEOSS0_TTL_DSP0_DATA_A08

#define CY_DISP0_DATA_A0_9_PORT                GPIO_PRT6
#define CY_DISP0_DATA_A0_9_PIN                 4
#define CY_DISP0_DATA_A0_9_PIN_MUX             P6_4_VIDEOSS0_TTL_DSP0_DATA_A09

#define CY_DISP0_DATA_A0_10_PORT               GPIO_PRT6
#define CY_DISP0_DATA_A0_10_PIN                6
#define CY_DISP0_DATA_A0_10_PIN_MUX            P6_6_VIDEOSS0_TTL_DSP0_DATA_A010

#define CY_DISP0_DATA_A0_11_PORT               GPIO_PRT7
#define CY_DISP0_DATA_A0_11_PIN                0
#define CY_DISP0_DATA_A0_11_PIN_MUX            P7_0_VIDEOSS0_TTL_DSP0_DATA_A011

#define CY_DISP0_DATA_A1_0_PORT                GPIO_PRT12
#define CY_DISP0_DATA_A1_0_PIN                 3
#define CY_DISP0_DATA_A1_0_PIN_MUX             P12_3_VIDEOSS0_TTL_DSP0_DATA_A10

#define CY_DISP0_DATA_A1_1_PORT                GPIO_PRT12
#define CY_DISP0_DATA_A1_1_PIN                 5
#define CY_DISP0_DATA_A1_1_PIN_MUX             P12_5_VIDEOSS0_TTL_DSP0_DATA_A11

#define CY_DISP0_DATA_A1_2_PORT                GPIO_PRT12
#define CY_DISP0_DATA_A1_2_PIN                 7
#define CY_DISP0_DATA_A1_2_PIN_MUX             P12_7_VIDEOSS0_TTL_DSP0_DATA_A12

#define CY_DISP0_DATA_A1_3_PORT                GPIO_PRT5
#define CY_DISP0_DATA_A1_3_PIN                 1
#define CY_DISP0_DATA_A1_3_PIN_MUX             P5_1_VIDEOSS0_TTL_DSP0_DATA_A13

#define CY_DISP0_DATA_A1_4_PORT                GPIO_PRT5
#define CY_DISP0_DATA_A1_4_PIN                 3
#define CY_DISP0_DATA_A1_4_PIN_MUX             P5_3_VIDEOSS0_TTL_DSP0_DATA_A14

#define CY_DISP0_DATA_A1_5_PORT                GPIO_PRT5
#define CY_DISP0_DATA_A1_5_PIN                 5
#define CY_DISP0_DATA_A1_5_PIN_MUX             P5_5_VIDEOSS0_TTL_DSP0_DATA_A15

#define CY_DISP0_DATA_A1_6_PORT                GPIO_PRT5
#define CY_DISP0_DATA_A1_6_PIN                 7
#define CY_DISP0_DATA_A1_6_PIN_MUX             P5_7_VIDEOSS0_TTL_DSP0_DATA_A16

#define CY_DISP0_DATA_A1_7_PORT                GPIO_PRT6
#define CY_DISP0_DATA_A1_7_PIN                 1
#define CY_DISP0_DATA_A1_7_PIN_MUX             P6_1_VIDEOSS0_TTL_DSP0_DATA_A17

#define CY_DISP0_DATA_A1_8_PORT                GPIO_PRT6
#define CY_DISP0_DATA_A1_8_PIN                 3
#define CY_DISP0_DATA_A1_8_PIN_MUX             P6_3_VIDEOSS0_TTL_DSP0_DATA_A18

#define CY_DISP0_DATA_A1_9_PORT                GPIO_PRT6
#define CY_DISP0_DATA_A1_9_PIN                 5
#define CY_DISP0_DATA_A1_9_PIN_MUX             P6_5_VIDEOSS0_TTL_DSP0_DATA_A19

#define CY_DISP0_DATA_A1_10_PORT               GPIO_PRT6
#define CY_DISP0_DATA_A1_10_PIN                7
#define CY_DISP0_DATA_A1_10_PIN_MUX            P6_7_VIDEOSS0_TTL_DSP0_DATA_A110

#define CY_DISP0_DATA_A1_11_PORT               GPIO_PRT0
#define CY_DISP0_DATA_A1_11_PIN                7
#define CY_DISP0_DATA_A1_11_PIN_MUX            P0_7_VIDEOSS0_TTL_DSP0_DATA_A111

/******************************************************************************/
/*                      Display #1 Definitions                                */
/******************************************************************************/

#define CY_DISP1_CLK_PORT                      GPIO_PRT21
#define CY_DISP1_CLK_PIN                       1
#define CY_DISP1_CLK_PIN_MUX                   P21_1_VIDEOSS0_TTL_DSP1_CLOCK

#define CY_DISP1_CTRL0_PORT                    GPIO_PRT20
#define CY_DISP1_CTRL0_PIN                     6
#define CY_DISP1_CTRL0_PIN_MUX                 P20_6_VIDEOSS0_TTL_DSP1_CONTROL0

#define CY_DISP1_CTRL1_PORT                    GPIO_PRT20
#define CY_DISP1_CTRL1_PIN                     7
#define CY_DISP1_CTRL1_PIN_MUX                 P20_7_VIDEOSS0_TTL_DSP1_CONTROL1

#define CY_DISP1_CTRL2_PORT                    GPIO_PRT21
#define CY_DISP1_CTRL2_PIN                     0
#define CY_DISP1_CTRL2_PIN_MUX                 P21_0_VIDEOSS0_TTL_DSP1_CONTROL2

#define CY_DISP1_DATA_A0_0_PORT                GPIO_PRT16
#define CY_DISP1_DATA_A0_0_PIN                 7
#define CY_DISP1_DATA_A0_0_PIN_MUX             P16_7_VIDEOSS0_TTL_DSP1_DATA_A00

#define CY_DISP1_DATA_A0_1_PORT                GPIO_PRT18
#define CY_DISP1_DATA_A0_1_PIN                 0
#define CY_DISP1_DATA_A0_1_PIN_MUX             P18_0_VIDEOSS0_TTL_DSP1_DATA_A01

#define CY_DISP1_DATA_A0_2_PORT                GPIO_PRT18
#define CY_DISP1_DATA_A0_2_PIN                 2
#define CY_DISP1_DATA_A0_2_PIN_MUX             P18_2_VIDEOSS0_TTL_DSP1_DATA_A02

#define CY_DISP1_DATA_A0_3_PORT                GPIO_PRT18
#define CY_DISP1_DATA_A0_3_PIN                 4
#define CY_DISP1_DATA_A0_3_PIN_MUX             P18_4_VIDEOSS0_TTL_DSP1_DATA_A03

#define CY_DISP1_DATA_A0_4_PORT                GPIO_PRT18
#define CY_DISP1_DATA_A0_4_PIN                 6
#define CY_DISP1_DATA_A0_4_PIN_MUX             P18_6_VIDEOSS0_TTL_DSP1_DATA_A04

#define CY_DISP1_DATA_A0_5_PORT                GPIO_PRT19
#define CY_DISP1_DATA_A0_5_PIN                 0
#define CY_DISP1_DATA_A0_5_PIN_MUX             P19_0_VIDEOSS0_TTL_DSP1_DATA_A05

#define CY_DISP1_DATA_A0_6_PORT                GPIO_PRT19
#define CY_DISP1_DATA_A0_6_PIN                 2
#define CY_DISP1_DATA_A0_6_PIN_MUX             P19_2_VIDEOSS0_TTL_DSP1_DATA_A06

#define CY_DISP1_DATA_A0_7_PORT                GPIO_PRT19
#define CY_DISP1_DATA_A0_7_PIN                 4
#define CY_DISP1_DATA_A0_7_PIN_MUX             P19_4_VIDEOSS0_TTL_DSP1_DATA_A07

#define CY_DISP1_DATA_A0_8_PORT                GPIO_PRT19
#define CY_DISP1_DATA_A0_8_PIN                 6
#define CY_DISP1_DATA_A0_8_PIN_MUX             P19_6_VIDEOSS0_TTL_DSP1_DATA_A08

#define CY_DISP1_DATA_A0_9_PORT                GPIO_PRT20
#define CY_DISP1_DATA_A0_9_PIN                 0
#define CY_DISP1_DATA_A0_9_PIN_MUX             P20_0_VIDEOSS0_TTL_DSP1_DATA_A09

#define CY_DISP1_DATA_A0_10_PORT               GPIO_PRT20
#define CY_DISP1_DATA_A0_10_PIN                2
#define CY_DISP1_DATA_A0_10_PIN_MUX            P20_2_VIDEOSS0_TTL_DSP1_DATA_A010

#define CY_DISP1_DATA_A0_11_PORT               GPIO_PRT20
#define CY_DISP1_DATA_A0_11_PIN                4
#define CY_DISP1_DATA_A0_11_PIN_MUX            P20_4_VIDEOSS0_TTL_DSP1_DATA_A011

#define CY_DISP1_DATA_A1_0_PORT                GPIO_PRT17
#define CY_DISP1_DATA_A1_0_PIN                 0
#define CY_DISP1_DATA_A1_0_PIN_MUX             P17_0_VIDEOSS0_TTL_DSP1_DATA_A10

#define CY_DISP1_DATA_A1_1_PORT                GPIO_PRT18
#define CY_DISP1_DATA_A1_1_PIN                 1
#define CY_DISP1_DATA_A1_1_PIN_MUX             P18_1_VIDEOSS0_TTL_DSP1_DATA_A11

#define CY_DISP1_DATA_A1_2_PORT                GPIO_PRT18
#define CY_DISP1_DATA_A1_2_PIN                 3
#define CY_DISP1_DATA_A1_2_PIN_MUX             P18_3_VIDEOSS0_TTL_DSP1_DATA_A12

#define CY_DISP1_DATA_A1_3_PORT                GPIO_PRT18
#define CY_DISP1_DATA_A1_3_PIN                 5
#define CY_DISP1_DATA_A1_3_PIN_MUX             P18_5_VIDEOSS0_TTL_DSP1_DATA_A13

#define CY_DISP1_DATA_A1_4_PORT                GPIO_PRT18
#define CY_DISP1_DATA_A1_4_PIN                 7
#define CY_DISP1_DATA_A1_4_PIN_MUX             P18_7_VIDEOSS0_TTL_DSP1_DATA_A14

#define CY_DISP1_DATA_A1_5_PORT                GPIO_PRT19
#define CY_DISP1_DATA_A1_5_PIN                 1
#define CY_DISP1_DATA_A1_5_PIN_MUX             P19_1_VIDEOSS0_TTL_DSP1_DATA_A15

#define CY_DISP1_DATA_A1_6_PORT                GPIO_PRT19
#define CY_DISP1_DATA_A1_6_PIN                 3
#define CY_DISP1_DATA_A1_6_PIN_MUX             P19_3_VIDEOSS0_TTL_DSP1_DATA_A16

#define CY_DISP1_DATA_A1_7_PORT                GPIO_PRT19
#define CY_DISP1_DATA_A1_7_PIN                 5
#define CY_DISP1_DATA_A1_7_PIN_MUX             P19_5_VIDEOSS0_TTL_DSP1_DATA_A17

#define CY_DISP1_DATA_A1_8_PORT                GPIO_PRT19
#define CY_DISP1_DATA_A1_8_PIN                 7
#define CY_DISP1_DATA_A1_8_PIN_MUX             P19_7_VIDEOSS0_TTL_DSP1_DATA_A18

#define CY_DISP1_DATA_A1_9_PORT                GPIO_PRT20
#define CY_DISP1_DATA_A1_9_PIN                 1
#define CY_DISP1_DATA_A1_9_PIN_MUX             P20_1_VIDEOSS0_TTL_DSP1_DATA_A19

#define CY_DISP1_DATA_A1_10_PORT               GPIO_PRT20
#define CY_DISP1_DATA_A1_10_PIN                3
#define CY_DISP1_DATA_A1_10_PIN_MUX            P20_3_VIDEOSS0_TTL_DSP1_DATA_A110

#define CY_DISP1_DATA_A1_11_PORT               GPIO_PRT20
#define CY_DISP1_DATA_A1_11_PIN                5
#define CY_DISP1_DATA_A1_11_PIN_MUX            P20_5_VIDEOSS0_TTL_DSP1_DATA_A111

/******************************************************************************/
/*                      Capture #0 Definitions                                */
/******************************************************************************/

#define CY_CAP0_CLK_PORT                       GPIO_PRT15
#define CY_CAP0_CLK_PIN                        6
#define CY_CAP0_CLK_PIN_MUX                    P15_6_VIDEOSS0_TTL_CAP0_CLK

#define CY_CAP0_DATA0_PORT                     GPIO_PRT15
#define CY_CAP0_DATA0_PIN                      7
#define CY_CAP0_DATA0_PIN_MUX                  P15_7_VIDEOSS0_TTL_CAP0_DATA0

#define CY_CAP0_DATA1_PORT                     GPIO_PRT16
#define CY_CAP0_DATA1_PIN                      0
#define CY_CAP0_DATA1_PIN_MUX                  P16_0_VIDEOSS0_TTL_CAP0_DATA1

#define CY_CAP0_DATA2_PORT                     GPIO_PRT16
#define CY_CAP0_DATA2_PIN                      1
#define CY_CAP0_DATA2_PIN_MUX                  P16_1_VIDEOSS0_TTL_CAP0_DATA2

#define CY_CAP0_DATA3_PORT                     GPIO_PRT16
#define CY_CAP0_DATA3_PIN                      2
#define CY_CAP0_DATA3_PIN_MUX                  P16_2_VIDEOSS0_TTL_CAP0_DATA3

#define CY_CAP0_DATA4_PORT                     GPIO_PRT16
#define CY_CAP0_DATA4_PIN                      3
#define CY_CAP0_DATA4_PIN_MUX                  P16_3_VIDEOSS0_TTL_CAP0_DATA4

#define CY_CAP0_DATA5_PORT                     GPIO_PRT16
#define CY_CAP0_DATA5_PIN                      4
#define CY_CAP0_DATA5_PIN_MUX                  P16_4_VIDEOSS0_TTL_CAP0_DATA5

#define CY_CAP0_DATA6_PORT                     GPIO_PRT16
#define CY_CAP0_DATA6_PIN                      5
#define CY_CAP0_DATA6_PIN_MUX                  P16_5_VIDEOSS0_TTL_CAP0_DATA6

#define CY_CAP0_DATA7_PORT                     GPIO_PRT16
#define CY_CAP0_DATA7_PIN                      6
#define CY_CAP0_DATA7_PIN_MUX                  P16_6_VIDEOSS0_TTL_CAP0_DATA7

#define CY_CAP0_DATA8_PORT                     GPIO_PRT9
#define CY_CAP0_DATA8_PIN                      0
#define CY_CAP0_DATA8_PIN_MUX                  P9_0_VIDEOSS0_TTL_CAP0_DATA8

#define CY_CAP0_DATA9_PORT                     GPIO_PRT9
#define CY_CAP0_DATA9_PIN                      1
#define CY_CAP0_DATA9_PIN_MUX                  P9_1_VIDEOSS0_TTL_CAP0_DATA9

#define CY_CAP0_DATA10_PORT                    GPIO_PRT9
#define CY_CAP0_DATA10_PIN                     2
#define CY_CAP0_DATA10_PIN_MUX                 P9_2_VIDEOSS0_TTL_CAP0_DATA10

#define CY_CAP0_DATA11_PORT                    GPIO_PRT9
#define CY_CAP0_DATA11_PIN                     3
#define CY_CAP0_DATA11_PIN_MUX                 P9_3_VIDEOSS0_TTL_CAP0_DATA11

#define CY_CAP0_DATA12_PORT                    GPIO_PRT9
#define CY_CAP0_DATA12_PIN                     4
#define CY_CAP0_DATA12_PIN_MUX                 P9_4_VIDEOSS0_TTL_CAP0_DATA12

#define CY_CAP0_DATA13_PORT                    GPIO_PRT9
#define CY_CAP0_DATA13_PIN                     5
#define CY_CAP0_DATA13_PIN_MUX                 P9_5_VIDEOSS0_TTL_CAP0_DATA13

#define CY_CAP0_DATA14_PORT                    GPIO_PRT9
#define CY_CAP0_DATA14_PIN                     6
#define CY_CAP0_DATA14_PIN_MUX                 P9_6_VIDEOSS0_TTL_CAP0_DATA14

#define CY_CAP0_DATA15_PORT                    GPIO_PRT9
#define CY_CAP0_DATA15_PIN                     7
#define CY_CAP0_DATA15_PIN_MUX                 P9_7_VIDEOSS0_TTL_CAP0_DATA15

#define CY_CAP0_DATA16_PORT                    GPIO_PRT10
#define CY_CAP0_DATA16_PIN                     0
#define CY_CAP0_DATA16_PIN_MUX                 P10_0_VIDEOSS0_TTL_CAP0_DATA16

#define CY_CAP0_DATA17_PORT                    GPIO_PRT10
#define CY_CAP0_DATA17_PIN                     1
#define CY_CAP0_DATA17_PIN_MUX                 P10_1_VIDEOSS0_TTL_CAP0_DATA17

#define CY_CAP0_DATA18_PORT                    GPIO_PRT11
#define CY_CAP0_DATA18_PIN                     0
#define CY_CAP0_DATA18_PIN_MUX                 P11_0_VIDEOSS0_TTL_CAP0_DATA18

#define CY_CAP0_DATA19_PORT                    GPIO_PRT11
#define CY_CAP0_DATA19_PIN                     1
#define CY_CAP0_DATA19_PIN_MUX                 P11_1_VIDEOSS0_TTL_CAP0_DATA19

#define CY_CAP0_DATA20_PORT                    GPIO_PRT11
#define CY_CAP0_DATA20_PIN                     2
#define CY_CAP0_DATA20_PIN_MUX                 P11_2_VIDEOSS0_TTL_CAP0_DATA20

#define CY_CAP0_DATA21_PORT                    GPIO_PRT11
#define CY_CAP0_DATA21_PIN                     3
#define CY_CAP0_DATA21_PIN_MUX                 P11_3_VIDEOSS0_TTL_CAP0_DATA21

#define CY_CAP0_DATA22_PORT                    GPIO_PRT11
#define CY_CAP0_DATA22_PIN                     4
#define CY_CAP0_DATA22_PIN_MUX                 P11_4_VIDEOSS0_TTL_CAP0_DATA22

#define CY_CAP0_DATA23_PORT                    GPIO_PRT11
#define CY_CAP0_DATA23_PIN                     5
#define CY_CAP0_DATA23_PIN_MUX                 P11_5_VIDEOSS0_TTL_CAP0_DATA23

#define CY_CAP0_DATA24_PORT                    GPIO_PRT11
#define CY_CAP0_DATA24_PIN                     6
#define CY_CAP0_DATA24_PIN_MUX                 P11_6_VIDEOSS0_TTL_CAP0_DATA24

#define CY_CAP0_DATA25_PORT                    GPIO_PRT11
#define CY_CAP0_DATA25_PIN                     7
#define CY_CAP0_DATA25_PIN_MUX                 P11_7_VIDEOSS0_TTL_CAP0_DATA25

#define CY_CAP0_DATA26_PORT                    GPIO_PRT12
#define CY_CAP0_DATA26_PIN                     0
#define CY_CAP0_DATA26_PIN_MUX                 P12_0_VIDEOSS0_TTL_CAP0_DATA26


/******************************************************************************/
/******************************************************************************/

#else // No Device or PSVP Selected

    #error "Choose either a Device based on TVII-C-2D-6M Datasheet or CY_USE_PSVP"

#endif // #if (CY_USE_PSVP == 1)


#ifdef __cplusplus
}
#endif

#endif /* BB_BSP_TVIIC2D6M_H */

/* [] END OF FILE */
