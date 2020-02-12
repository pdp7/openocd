/***************************************************************************//**
* \file bb_bsp_tviibh8m.h
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

#ifndef BB_BSP_TVIIBH8M_H
#define BB_BSP_TVIIBH8M_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/******************************************************************************/

// PSVP supports only 320-bga package

#if (CY_USE_PSVP == 1) && ( defined(CYT4BFCCHE) || defined(CYT4BFCCHS) || \
                            defined(CYT4BFCCJE) || defined(CYT4BFCCJS) || \
                            defined(CYT4BFCCDE) || defined(CYT4BFCCDS) || \
                            defined(CYT4BFCCEE) || defined(CYT4BFCCES) )

// Adapter Board Entities

/******************************************************************************/
/*                      USER LED AB Mux (GPIO_133)                            */
/******************************************************************************/

#define CY_AB_LED_PORT                 	GPIO_PRT2
#define CY_AB_LED_PIN                   5
#define CY_AB_LED_PIN_MUX               P2_5_GPIO

/******************************************************************************/
/*                      Button AB Mux (GPIO_134)                              */
/******************************************************************************/

#define CY_AB_BUTTON_PORT              	GPIO_PRT1
#define CY_AB_BUTTON_PIN                5
#define CY_AB_BUTTON_PIN_MUX            P1_5_GPIO
  
/* Setup GPIO for BUTTON AB interrupt sources */
#define CY_AB_BUTTON_IRQN		ioss_interrupts_gpio_dpslp_1_IRQn

/******************************************************************************/
/*                      SDHC AB Mux                                           */
/******************************************************************************/
  
#define CY_SDHC_TYPE                    SDHC0
#define CY_SDHC_CLK_CARD_PORT           GPIO_PRT7
#define CY_SDHC_CLK_CARD_PIN            1
#define CY_SDHC_CLK_CARD_PIN_MUX        P7_1_SDHC0_CLK_CARD
#define CY_SDHC_CARD_CMD_PORT           GPIO_PRT7
#define CY_SDHC_CARD_CMD_PIN            2
#define CY_SDHC_CARD_CMD_PIN_MUX        P7_2_SDHC0_CARD_CMD
#define CY_SDHC_CARD_DETECT_N_PORT      GPIO_PRT6
#define CY_SDHC_CARD_DETECT_N_PIN       5
#define CY_SDHC_CARD_DETECT_N_PIN_MUX   P6_5_SDHC0_CARD_DETECT_N
#define CY_SDHC_CARD_DAT_3TO00_PORT     GPIO_PRT7
#define CY_SDHC_CARD_DAT_3TO00_PIN      4
#define CY_SDHC_CARD_DAT_3TO00_PIN_MUX  P7_4_SDHC0_CARD_DAT_3TO00  
#define CY_SDHC_CARD_DAT_3TO01_PORT     GPIO_PRT7
#define CY_SDHC_CARD_DAT_3TO01_PIN      5
#define CY_SDHC_CARD_DAT_3TO01_PIN_MUX  P7_5_SDHC0_CARD_DAT_3TO01
#define CY_SDHC_CARD_DAT_3TO02_PORT     GPIO_PRT8
#define CY_SDHC_CARD_DAT_3TO02_PIN      0
#define CY_SDHC_CARD_DAT_3TO02_PIN_MUX  P8_0_SDHC0_CARD_DAT_3TO02
#define CY_SDHC_CARD_DAT_3TO03_PORT     GPIO_PRT8
#define CY_SDHC_CARD_DAT_3TO03_PIN      1
#define CY_SDHC_CARD_DAT_3TO03_PIN_MUX  P8_1_SDHC0_CARD_DAT_3TO03
#define CY_SDHC_GENERAL_IRQN            sdhc_0_interrupt_general_IRQn

/******************************************************************************/
/*                      AUDIOSS Port (I2S1) and SCB                           */
/******************************************************************************/

#define CY_AUDIOSS_TYPE                         I2S0

#define CY_AUDIOSS_MCLK_PORT                    GPIO_PRT18
#define CY_AUDIOSS_MCLK_PIN                     4
#define CY_AUDIOSS_MCLK_PIN_MUX                 P18_4_AUDIOSS0_MCLK

#define CY_AUDIOSS_TX_SCK_PORT                  GPIO_PRT18
#define CY_AUDIOSS_TX_SCK_PIN                   5
#define CY_AUDIOSS_TX_SCK_PIN_MUX               P18_5_AUDIOSS0_TX_SCK

#define CY_AUDIOSS_TX_WS_PORT                   GPIO_PRT18
#define CY_AUDIOSS_TX_WS_PIN                    6
#define CY_AUDIOSS_TX_WS_PIN_MUX                P18_6_AUDIOSS0_TX_WS

#define CY_AUDIOSS_TX_SDO_PORT                  GPIO_PRT18
#define CY_AUDIOSS_TX_SDO_PIN                   7
#define CY_AUDIOSS_TX_SDO_PIN_MUX               P18_7_AUDIOSS0_TX_SDO

#define CY_AUDIOSS_CLK_I2S_IF_PORT              GPIO_PRT19
#define CY_AUDIOSS_CLK_I2S_IF_PIN               0
#define CY_AUDIOSS_CLK_I2S_IF_PIN_MUX           P19_0_AUDIOSS0_CLK_I2S_IF

#define CY_AUDIOSS_RX_SCK_PORT                  GPIO_PRT19
#define CY_AUDIOSS_RX_SCK_PIN                   1
#define CY_AUDIOSS_RX_SCK_PIN_MUX               P19_1_AUDIOSS0_RX_SCK

#define CY_AUDIOSS_RX_WS_PORT                   GPIO_PRT19
#define CY_AUDIOSS_RX_WS_PIN                    2
#define CY_AUDIOSS_RX_WS_PIN_MUX                P19_2_AUDIOSS0_RX_WS

#define CY_AUDIOSS_RX_SDI_PORT                  GPIO_PRT19
#define CY_AUDIOSS_RX_SDI_PIN                   3
#define CY_AUDIOSS_RX_SDI_PIN_MUX               P19_3_AUDIOSS0_RX_SDI

#define CY_AUDIOSS_IRQN                         audioss_0_interrupt_i2s_IRQn

/* AUDIOSS-SPI port for Codec Communication */
#define CY_AUDIOSS_SPI_TYPE                     SCB5

#define CY_AUDIOSS_SPI_MISO_PORT                GPIO_PRT4
#define CY_AUDIOSS_SPI_MISO_PIN                 0
#define CY_AUDIOSS_SPI_MISO_PIN_MUX             P4_0_SCB5_SPI_MISO

#define CY_AUDIOSS_SPI_MOSI_PORT                GPIO_PRT4
#define CY_AUDIOSS_SPI_MOSI_PIN                 1
#define CY_AUDIOSS_SPI_MOSI_PIN_MUX             P4_1_SCB5_SPI_MOSI

#define CY_AUDIOSS_SPI_CLK_PORT                 GPIO_PRT4
#define CY_AUDIOSS_SPI_CLK_PIN                  2
#define CY_AUDIOSS_SPI_CLK_PIN_MUX              P4_2_SCB5_SPI_CLK

#define CY_AUDIOSS_SPI_SS0_PORT                 GPIO_PRT4
#define CY_AUDIOSS_SPI_SS0_PIN                  4
#define CY_AUDIOSS_SPI_SS0_PIN_MUX              P4_4_SCB5_SPI_SELECT1

#define CY_AUDIOSS_SPI_PCLK                     PCLK_SCB5_CLOCK
#define CY_AUDIOSS_SPI_IRQN                     scb_5_interrupt_IRQn

// BB Board Entities

/******************************************************************************/
/*                      LEDs Base Board Mux                                   */
/******************************************************************************/

#define CY_LED0_PORT                    GPIO_PRT32
#define CY_LED0_PIN                     3
#define CY_LED0_PIN_MUX                 P32_3_GPIO
  
#define CY_LED1_PORT                    GPIO_PRT32
#define CY_LED1_PIN                     5
#define CY_LED1_PIN_MUX                 P32_5_GPIO
  
#define CY_LED2_PORT                    GPIO_PRT32
#define CY_LED2_PIN                     2
#define CY_LED2_PIN_MUX                 P32_2_GPIO
  
#define CY_LED3_PORT                    GPIO_PRT31
#define CY_LED3_PIN                     2
#define CY_LED3_PIN_MUX                 P31_2_GPIO
  
#define CY_LED4_PORT                    GPIO_PRT31
#define CY_LED4_PIN                     0
#define CY_LED4_PIN_MUX                 P31_0_GPIO
  
#define CY_LED5_PORT                    GPIO_PRT29
#define CY_LED5_PIN                     7
#define CY_LED5_PIN_MUX                 P29_7_GPIO
  
#define CY_LED6_PORT                    GPIO_PRT29
#define CY_LED6_PIN                     4
#define CY_LED6_PIN_MUX                 P29_4_GPIO
  
#define CY_LED7_PORT                    GPIO_PRT3
#define CY_LED7_PIN                     7
#define CY_LED7_PIN_MUX                 P3_7_GPIO
  
#define CY_LED8_PORT                    GPIO_PRT3
#define CY_LED8_PIN                     5
#define CY_LED8_PIN_MUX                 P3_5_GPIO
  
#define CY_LED9_PORT                    GPIO_PRT2
#define CY_LED9_PIN                     7
#define CY_LED9_PIN_MUX                 P2_7_GPIO  

/******************************************************************************/
/*                      Buttons Base Board Mux                                */
/******************************************************************************/

#define CY_BUTTON1_PORT                 GPIO_PRT6
#define CY_BUTTON1_PIN                  7
#define CY_BUTTON1_PIN_MUX              P6_7_GPIO

#define CY_BUTTON2_PORT                 GPIO_PRT32
#define CY_BUTTON2_PIN                  0
#define CY_BUTTON2_PIN_MUX              P32_0_GPIO
  
#define CY_BUTTON3_PORT                 GPIO_PRT32
#define CY_BUTTON3_PIN                  1
#define CY_BUTTON3_PIN_MUX              P32_1_GPIO
  
#define CY_BUTTON4_PORT                 GPIO_PRT28
#define CY_BUTTON4_PIN                  2
#define CY_BUTTON4_PIN_MUX              P28_2_GPIO
  
#define CY_BUTTON5_PORT                 GPIO_PRT28
#define CY_BUTTON5_PIN                  1
#define CY_BUTTON5_PIN_MUX              P28_1_GPIO

/* Setup GPIO for BUTTONs 1/2/3/5 interrupt sources */
#define CY_BUTTON1_IRQN		        ioss_interrupts_gpio_dpslp_6_IRQn
#define CY_BUTTON2_IRQN			ioss_interrupts_gpio_dpslp_32_IRQn
#define CY_BUTTON3_IRQN			ioss_interrupts_gpio_dpslp_32_IRQn
#define CY_BUTTON4_IRQN			ioss_interrupts_gpio_dpslp_28_IRQn
#define CY_BUTTON5_IRQN			ioss_interrupts_gpio_dpslp_28_IRQn

/******************************************************************************/
/*                      ADC POT                                		      */
/******************************************************************************/

#define CY_ADC_POT_MACRO                PASS0_SAR0
#define CY_ADC_POT_IN_NO                20
#define CY_ADC_POT_PORT                 GPIO_PRT30
#define CY_ADC_POT_PIN                  1
#define CY_ADC_POT_PIN_MUX              P30_1_GPIO
#define CY_ADC_POT_PCLK                 PCLK_PASS0_CLOCK_SAR0
#define CY_ADC_POT_IRQN                 pass_interrupts_sar_0_IRQn

/******************************************************************************/
/*                      SCB-UART Base Board Mux                               */
/******************************************************************************/

/* USB-UART Mux */
#define CY_USB_SCB_TYPE                 SCB3
#define CY_USB_SCB_UART_RX_PORT         GPIO_PRT13
#define CY_USB_SCB_UART_RX_PIN          0
#define CY_USB_SCB_UART_RX_MUX          P13_0_SCB3_UART_RX
#define CY_USB_SCB_UART_TX_PORT         GPIO_PRT13
#define CY_USB_SCB_UART_TX_PIN          1
#define CY_USB_SCB_UART_TX_MUX          P13_1_SCB3_UART_TX
#define CY_USB_SCB_UART_PCLK            PCLK_SCB3_CLOCK
#define CY_USB_SCB_UART_IRQN            scb_3_interrupt_IRQn  
  
/* CANFD-SPI Mux (BB_CAN_SPI) */
#define CY_CANFD_SCB_TYPE               SCB1
#define CY_CANFD_SCB_MOSI_PORT          GPIO_PRT18
#define CY_CANFD_SCB_MOSI_PIN           1
#define CY_CANFD_SCB_MOSI_PIN_MUX       P18_1_SCB1_SPI_MOSI
#define CY_CANFD_SCB_MISO_PORT          GPIO_PRT18
#define CY_CANFD_SCB_MISO_PIN           0
#define CY_CANFD_SCB_MISO_PIN_MUX       P18_0_SCB1_SPI_MISO
#define CY_CANFD_SCB_SCK_PORT           GPIO_PRT18
#define CY_CANFD_SCB_SCK_PIN            2
#define CY_CANFD_SCB_SCK_PIN_MUX        P18_2_SCB1_SPI_CLK
#define CY_CANFD_SCB_SS0_PORT           GPIO_PRT20
#define CY_CANFD_SCB_SS0_PIN            6
#define CY_CANFD_SCB_SS0_PIN_MUX        P20_6_SCB1_SPI_SELECT0
#define CY_CANFD_SCB_SS1_PORT           GPIO_PRT20
#define CY_CANFD_SCB_SS1_PIN            7
#define CY_CANFD_SCB_SS1_PIN_MUX        P20_7_SCB1_SPI_SELECT1
#define CY_CANFD_SCB_SS2_PORT           GPIO_PRT21
#define CY_CANFD_SCB_SS2_PIN            0
#define CY_CANFD_SCB_SS2_PIN_MUX        P21_0_SCB1_SPI_SELECT2
#define CY_CANFD_SCB_PCLK               PCLK_SCB1_CLOCK
#define CY_CANFD_SCB_IRQN               scb_1_interrupt_IRQn

/* EEPROM SPI Mux (BB_SPI0) */
#define CY_EEPROM_SCB_TYPE              SCB5
#define CY_EEPROM_SCB_MISO_PORT         GPIO_PRT4
#define CY_EEPROM_SCB_MISO_PIN          0
#define CY_EEPROM_SCB_MISO_PIN_MUX      P4_0_SCB5_SPI_MISO
#define CY_EEPROM_SCB_MOSI_PORT         GPIO_PRT4
#define CY_EEPROM_SCB_MOSI_PIN          1
#define CY_EEPROM_SCB_MOSI_PIN_MUX      P4_1_SCB5_SPI_MOSI
#define CY_EEPROM_SCB_SCK_PORT          GPIO_PRT4
#define CY_EEPROM_SCB_SCK_PIN           2
#define CY_EEPROM_SCB_SCK_PIN_MUX       P4_2_SCB5_SPI_CLK
#define CY_EEPROM_SCB_SSEL_PORT         GPIO_PRT4
#define CY_EEPROM_SCB_SSEL_PIN          3
#define CY_EEPROM_SCB_SSEL_PIN_MUX      P4_3_SCB5_SPI_SELECT0
#define CY_EEPROM_HOLD_PORT             GPIO_PRT28
#define CY_EEPROM_HOLD_PIN              4
#define CY_EEPROM_HOLD_PIN_MUX          P28_4_GPIO
#define CY_EEPROM_WP_PORT               GPIO_PRT28
#define CY_EEPROM_WP_PIN                3
#define CY_EEPROM_WP_PIN_MUX            P28_3_GPIO
#define CY_EEPROM_SCB_PCLK              PCLK_SCB5_CLOCK
#define CY_EEPROM_SCB_IRQN              scb_5_interrupt_IRQn


/******************************************************************************/
/*                      CANFD Base Board Mux                                  */
/******************************************************************************/
  
/* CAN0 Pin Mux */
#define CY_CANFD0_TYPE                  CY_CANFD1_4_TYPE
#define CY_CANFD0_RX_PORT               GPIO_PRT32
#define CY_CANFD0_RX_PIN                7
#define CY_CANFD0_RX_MUX                P32_7_CANFD1_TTCAN_RX4
#define CY_CANFD0_TX_PORT               GPIO_PRT32
#define CY_CANFD0_TX_PIN                6
#define CY_CANFD0_TX_MUX                P32_6_CANFD1_TTCAN_TX4
#define CY_CANFD0_PCLK                  PCLK_CANFD1_CLOCK_CAN4
#define CY_CANFD0_IRQN                  canfd_1_interrupts0_4_IRQn
  
/* CAN1 Pin Mux */
#define CY_CANFD1_TYPE                  CY_CANFD1_3_TYPE
#define CY_CANFD1_RX_PORT               GPIO_PRT15
#define CY_CANFD1_RX_PIN                1
#define CY_CANFD1_RX_MUX                P15_1_CANFD1_TTCAN_RX3
#define CY_CANFD1_TX_PORT               GPIO_PRT15
#define CY_CANFD1_TX_PIN                0
#define CY_CANFD1_TX_MUX                P15_0_CANFD1_TTCAN_TX3
#define CY_CANFD1_PCLK                  PCLK_CANFD1_CLOCK_CAN3
#define CY_CANFD1_IRQN                  canfd_1_interrupts0_3_IRQn
  
/* CAN2 Pin Mux */
#define CY_CANFD2_TYPE                  CY_CANFD0_2_TYPE
#define CY_CANFD2_RX_PORT               GPIO_PRT6
#define CY_CANFD2_RX_PIN                3
#define CY_CANFD2_RX_MUX                P6_3_CANFD0_TTCAN_RX2
#define CY_CANFD2_TX_PORT               GPIO_PRT12
#define CY_CANFD2_TX_PIN                0
#define CY_CANFD2_TX_MUX                P12_0_CANFD0_TTCAN_TX2
#define CY_CANFD2_PCLK                  PCLK_CANFD0_CLOCK_CAN2
#define CY_CANFD2_IRQN                  canfd_0_interrupts0_2_IRQn
  
/* CAN3 Pin Mux */
#define CY_CANFD3_TYPE                  CY_CANFD1_0_TYPE
#define CY_CANFD3_RX_PORT               GPIO_PRT23
#define CY_CANFD3_RX_PIN                1
#define CY_CANFD3_RX_MUX                P23_1_CANFD1_TTCAN_RX0
#define CY_CANFD3_TX_PORT               GPIO_PRT14
#define CY_CANFD3_TX_PIN                0
#define CY_CANFD3_TX_MUX                P14_0_CANFD1_TTCAN_TX0
#define CY_CANFD3_PCLK                  PCLK_CANFD1_CLOCK_CAN0
#define CY_CANFD3_IRQN                  canfd_1_interrupts0_0_IRQn
  
/* CAN4 Pin Mux */
#define CY_CANFD4_TYPE                  CY_CANFD1_2_TYPE
#define CY_CANFD4_RX_PORT               GPIO_PRT20
#define CY_CANFD4_RX_PIN                4
#define CY_CANFD4_RX_MUX                P20_4_CANFD1_TTCAN_RX2
#define CY_CANFD4_TX_PORT               GPIO_PRT20
#define CY_CANFD4_TX_PIN                3
#define CY_CANFD4_TX_MUX                P20_3_CANFD1_TTCAN_TX2
#define CY_CANFD4_PCLK                  PCLK_CANFD1_CLOCK_CAN2
#define CY_CANFD4_IRQN                  canfd_1_interrupts0_2_IRQn
  
/* CAN6 Pin Mux */
#define CY_CANFD6_TYPE                  CY_CANFD1_1_TYPE
#define CY_CANFD6_RX_PORT               GPIO_PRT17
#define CY_CANFD6_RX_PIN                1
#define CY_CANFD6_RX_MUX                P17_1_CANFD1_TTCAN_RX1
#define CY_CANFD6_TX_PORT               GPIO_PRT17
#define CY_CANFD6_TX_PIN                0
#define CY_CANFD6_TX_MUX                P17_0_CANFD1_TTCAN_TX1
#define CY_CANFD6_PCLK                  PCLK_CANFD1_CLOCK_CAN1
#define CY_CANFD6_IRQN                  canfd_1_interrupts0_1_IRQn
  
/******************************************************************************/
/*                      LIN Base Board Mux                                    */
/******************************************************************************/

/* LIN Channel 0 */
#define CY_LINCH0_TYPE                  LIN0_CH0
#define CY_LINCH0_RX_PORT               GPIO_PRT1
#define CY_LINCH0_RX_PIN                2
#define CY_LINCH0_RX_PIN_MUX            P1_2_LIN0_LIN_RX0
#define CY_LINCH0_TX_PORT               GPIO_PRT21
#define CY_LINCH0_TX_PIN                6
#define CY_LINCH0_TX_PIN_MUX            P21_6_LIN0_LIN_TX0
#define CY_LINCH0_PCLK                  PCLK_LIN0_CLOCK_CH_EN0
#define CY_LINCH0_IRQN                  lin_0_interrupts_0_IRQn
  
/* LIN Channel 1 */
#define CY_LINCH1_TYPE                  LIN0_CH6
#define CY_LINCH1_RX_PORT               GPIO_PRT12
#define CY_LINCH1_RX_PIN                2
#define CY_LINCH1_RX_PIN_MUX            P12_2_LIN0_LIN_RX6
#define CY_LINCH1_TX_PORT               GPIO_PRT12
#define CY_LINCH1_TX_PIN                3
#define CY_LINCH1_TX_PIN_MUX            P12_3_LIN0_LIN_TX6
#define CY_LINCH1_PCLK                  PCLK_LIN0_CLOCK_CH_EN6
#define CY_LINCH1_IRQN                  lin_0_interrupts_6_IRQn

/* LIN Channel 2 */
#define CY_LINCH2_TYPE                  LIN0_CH8
#define CY_LINCH2_RX_PORT               GPIO_PRT13
#define CY_LINCH2_RX_PIN                4
#define CY_LINCH2_RX_PIN_MUX            P13_4_LIN0_LIN_RX8
#define CY_LINCH2_TX_PORT               GPIO_PRT13
#define CY_LINCH2_TX_PIN                5
#define CY_LINCH2_TX_PIN_MUX            P13_5_LIN0_LIN_TX8
#define CY_LINCH2_PCLK                  PCLK_LIN0_CLOCK_CH_EN8
#define CY_LINCH2_IRQN                  lin_0_interrupts_8_IRQn

/* LIN Channel 3 */
#define CY_LINCH3_TYPE                  LIN0_CH7
#define CY_LINCH3_RX_PORT               GPIO_PRT22
#define CY_LINCH3_RX_PIN                5
#define CY_LINCH3_RX_PIN_MUX            P22_5_LIN0_LIN_RX7
#define CY_LINCH3_TX_PORT               GPIO_PRT22
#define CY_LINCH3_TX_PIN                6
#define CY_LINCH3_TX_PIN_MUX            P22_6_LIN0_LIN_TX7
#define CY_LINCH3_PCLK                  PCLK_LIN0_CLOCK_CH_EN7
#define CY_LINCH3_IRQN                  lin_0_interrupts_7_IRQn

/* LIN Channel 4 */
#define CY_LINCH4_TYPE                  LIN0_CH10
#define CY_LINCH4_RX_PORT               GPIO_PRT32
#define CY_LINCH4_RX_PIN                4
#define CY_LINCH4_RX_PIN_MUX            P32_4_LIN0_LIN_RX10
#define CY_LINCH4_TX_PORT               GPIO_PRT7
#define CY_LINCH4_TX_PIN                6
#define CY_LINCH4_TX_PIN_MUX            P7_6_LIN0_LIN_TX10
#define CY_LINCH4_PCLK                  PCLK_LIN0_CLOCK_CH_EN10
#define CY_LINCH4_IRQN                  lin_0_interrupts_10_IRQn

/* LIN Channel 5 */
#define CY_LINCH5_TYPE                  LIN0_CH5
#define CY_LINCH5_RX_PORT               GPIO_PRT20
#define CY_LINCH5_RX_PIN                0
#define CY_LINCH5_RX_PIN_MUX            P20_0_LIN0_LIN_RX5
#define CY_LINCH5_TX_PORT               GPIO_PRT20
#define CY_LINCH5_TX_PIN                1
#define CY_LINCH5_TX_PIN_MUX            P20_1_LIN0_LIN_TX5
#define CY_LINCH5_PCLK                  PCLK_LIN0_CLOCK_CH_EN5
#define CY_LINCH5_IRQN                  lin_0_interrupts_5_IRQn   
  
/******************************************************************************/
/*                      SMARTIO Base Board Mux                                */
/******************************************************************************/

#define CY_SMARTIO_MACRO                SMARTIO
#define CY_SMARTIO_PORT                 SMARTIO_PRT15
#define CY_SMARTIO_CLK                  PCLK_SMARTIO15_CLOCK

#define CY_SMARTIO_OUT_PORT             GPIO_PRT15
#define CY_SMARTIO_OUT_PIN              1
#define CY_SMARTIO_OUT_PORT_MUX         P15_1_GPIO

#define CY_SMARTIO_IN_PORT              GPIO_PRT15
#define CY_SMARTIO_IN_PIN               0
#define CY_SMARTIO_IN_PORT_MUX          P15_0_GPIO


/******************************************************************************/
/*                      SMIF0 Definitions                                     */
/******************************************************************************/

#define CY_SMIF0_CLK_PORT                      GPIO_PRT24
#define CY_SMIF0_CLK_PIN                       1
#define CY_SMIF0_CLK_PIN_MUX                   P24_1_SMIF0_SPIHB_CLK

#define CY_SMIF0_RWDS_PORT                     GPIO_PRT24
#define CY_SMIF0_RWDS_PIN                      2
#define CY_SMIF0_RWDS_PIN_MUX                  P24_2_SMIF0_SPIHB_RWDS

#define CY_SMIF0_SELECT0_PORT                  GPIO_PRT24
#define CY_SMIF0_SELECT0_PIN                   3
#define CY_SMIF0_SELECT0_PIN_MUX               P24_3_SMIF0_SPIHB_SELECT0

#define CY_SMIF0_SELECT1_PORT                  GPIO_PRT7
#define CY_SMIF0_SELECT1_PIN                   3
#define CY_SMIF0_SELECT1_PIN_MUX               P7_3_SMIF0_SPIHB_SELECT1

#define CY_SMIF0_DATA0_PORT                    GPIO_PRT25
#define CY_SMIF0_DATA0_PIN                     0
#define CY_SMIF0_DATA0_PIN_MUX                 P25_0_SMIF0_SPIHB_DATA0

#define CY_SMIF0_DATA1_PORT                    GPIO_PRT25
#define CY_SMIF0_DATA1_PIN                     1
#define CY_SMIF0_DATA1_PIN_MUX                 P25_1_SMIF0_SPIHB_DATA1

#define CY_SMIF0_DATA2_PORT                    GPIO_PRT25
#define CY_SMIF0_DATA2_PIN                     2
#define CY_SMIF0_DATA2_PIN_MUX                 P25_2_SMIF0_SPIHB_DATA2

#define CY_SMIF0_DATA3_PORT                    GPIO_PRT25
#define CY_SMIF0_DATA3_PIN                     3
#define CY_SMIF0_DATA3_PIN_MUX                 P25_3_SMIF0_SPIHB_DATA3

#define CY_SMIF0_DATA4_PORT                    GPIO_PRT8
#define CY_SMIF0_DATA4_PIN                     2
#define CY_SMIF0_DATA4_PIN_MUX                 P8_2_SMIF0_SPIHB_DATA4

#define CY_SMIF0_DATA5_PORT                    GPIO_PRT11
#define CY_SMIF0_DATA5_PIN                     0
#define CY_SMIF0_DATA5_PIN_MUX                 P11_0_SMIF0_SPIHB_DATA5

#define CY_SMIF0_DATA6_PORT                    GPIO_PRT11
#define CY_SMIF0_DATA6_PIN                     1
#define CY_SMIF0_DATA6_PIN_MUX                 P11_1_SMIF0_SPIHB_DATA6

#define CY_SMIF0_DATA7_PORT                    GPIO_PRT11
#define CY_SMIF0_DATA7_PIN                     2
#define CY_SMIF0_DATA7_PIN_MUX                 P11_2_SMIF0_SPIHB_DATA7


/******************************************************************************/
/*                      GIGA ETH Port                                         */
/******************************************************************************/

#define CY_GIG_ETH_TYPE                        ETH0

#define CY_GIG_ETH_TX_CLK_PORT                 GPIO_PRT33
#define CY_GIG_ETH_TX_CLK_PIN                  2
#define CY_GIG_ETH_TX_CLK_PIN_MUX              P33_2_ETH0_TX_CLK

#define CY_GIG_ETH_TX_CTL_PORT                 GPIO_PRT33
#define CY_GIG_ETH_TX_CTL_PIN                  1
#define CY_GIG_ETH_TX_CTL_PIN_MUX              P33_1_ETH0_TX_CTL

#define CY_GIG_ETH_TD0_PORT                    GPIO_PRT0        
#define CY_GIG_ETH_TD0_PIN                     0
#define CY_GIG_ETH_TD0_PIN_MUX                 P0_0_ETH0_TXD0

#define CY_GIG_ETH_TD1_PORT                    GPIO_PRT0        
#define CY_GIG_ETH_TD1_PIN                     1
#define CY_GIG_ETH_TD1_PIN_MUX                 P0_1_ETH0_TXD1

#define CY_GIG_ETH_TD2_PORT                    GPIO_PRT0        
#define CY_GIG_ETH_TD2_PIN                     2
#define CY_GIG_ETH_TD2_PIN_MUX                 P0_2_ETH0_TXD2

#define CY_GIG_ETH_TD3_PORT                    GPIO_PRT0
#define CY_GIG_ETH_TD3_PIN                     3
#define CY_GIG_ETH_TD3_PIN_MUX                 P0_3_ETH0_TXD3

#define CY_GIG_ETH_TXER_PORT                   GPIO_PRT23
#define CY_GIG_ETH_TXER_PIN                    6
#define CY_GIG_ETH_TXER_PIN_MUX                P23_6_ETH0_TX_ER

#define CY_GIG_ETH_RX_CLK_PORT                 GPIO_PRT5
#define CY_GIG_ETH_RX_CLK_PIN                  0
#define CY_GIG_ETH_RX_CLK_PIN_MUX              P5_0_ETH0_RX_CLK

#define CY_GIG_ETH_RX_CTL_PORT                 GPIO_PRT3       
#define CY_GIG_ETH_RX_CTL_PIN                  0
#define CY_GIG_ETH_RX_CTL_PIN_MUX              P3_0_ETH0_RX_CTL

#define CY_GIG_ETH_RD0_PORT                    GPIO_PRT33
#define CY_GIG_ETH_RD0_PIN                     7
#define CY_GIG_ETH_RD0_PIN_MUX                 P33_7_ETH0_RXD0
                                   
#define CY_GIG_ETH_RD1_PORT                    GPIO_PRT2        
#define CY_GIG_ETH_RD1_PIN                     1
#define CY_GIG_ETH_RD1_PIN_MUX                 P2_1_ETH0_RXD1
                                    
#define CY_GIG_ETH_RD2_PORT                    GPIO_PRT2        
#define CY_GIG_ETH_RD2_PIN                     2
#define CY_GIG_ETH_RD2_PIN_MUX                 P2_2_ETH0_RXD2
                                  
#define CY_GIG_ETH_RD3_PORT                    GPIO_PRT2
#define CY_GIG_ETH_RD3_PIN                     3
#define CY_GIG_ETH_RD3_PIN_MUX                 P2_3_ETH0_RXD3

#define CY_GIG_ETH_RX_ER_PORT                  GPIO_PRT3        
#define CY_GIG_ETH_RX_ER_PIN                   1
#define CY_GIG_ETH_RX_ER_PIN_MUX               P3_1_ETH0_RX_ER

#define CY_GIG_ETH_MDC_PORT                    GPIO_PRT5   
#define CY_GIG_ETH_MDC_PIN                     2
#define CY_GIG_ETH_MDC_PIN_MUX                 P5_2_ETH0_MDC
                                    
#define CY_GIG_ETH_MDIO_PORT                   GPIO_PRT5
#define CY_GIG_ETH_MDIO_PIN                    1
#define CY_GIG_ETH_MDIO_PIN_MUX                P5_1_ETH0_MDIO

#define CY_GIG_ETH_REF_CLK_PORT                GPIO_PRT33
#define CY_GIG_ETH_REF_CLK_PIN                 0
#define CY_GIG_ETH_REF_CLK_PIN_MUX             P33_0_ETH0_REF_CLK

/* Setup IRQ source for 0, 1 and 2 Priority Queue */
#define CY_GIG_ETH_IRQN0                       eth_0_interrupt_eth_IRQn
#define CY_GIG_ETH_IRQN1                       eth_0_interrupt_eth_q1_IRQn
#define CY_GIG_ETH_IRQN2                       eth_0_interrupt_eth_q2_IRQn


/******************************************************************************/
/******************************************************************************/

// tviibh8m - 176-TEQFP Package devices
    
// #if (CY_USE_PSVP == 0) (--> Silicon), project setting CY_USE_PSVP should be changed to '0'
// select the supported or required device accordingly

#elif (CY_USE_PSVP == 0) && ( defined(CYT4BF8CES) || defined(CYT4BF8CEE) || \
                              defined(CYT4BF8CDS) || defined(CYT4BF8CDE) )


/******************************************************************************/
/******************************************************************************/

// CPU Board Entities

/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/*                      USER LED                                              */
/******************************************************************************/

#define CY_CB_USER_LED1_PORT                    GPIO_PRT3
#define CY_CB_USER_LED1_PIN                     2
#define CY_CB_USER_LED1_PIN_MUX                 P3_2_GPIO

#define CY_CB_USER_LED2_PORT                    GPIO_PRT3
#define CY_CB_USER_LED2_PIN                     3
#define CY_CB_USER_LED2_PIN_MUX                 P3_3_GPIO


/******************************************************************************/
/*                      USER Button (SW2 and SW4)                             */
/******************************************************************************/

#define CY_CB_USER_BUTTON1_PORT                 GPIO_PRT3
#define CY_CB_USER_BUTTON1_PIN                  4
#define CY_CB_USER_BUTTON1_PIN_MUX              P3_4_GPIO

#define CY_CB_USER_BUTTON2_PORT                 GPIO_PRT3
#define CY_CB_USER_BUTTON2_PIN                  5
#define CY_CB_USER_BUTTON2_PIN_MUX              P3_5_GPIO

/* Setup GPIO for User Button interrupt sources */
#define CY_CB_USER_BUTTON1_IRQN                 ioss_interrupts_gpio_dpslp_3_IRQn
#define CY_CB_USER_BUTTON2_IRQN                 ioss_interrupts_gpio_dpslp_3_IRQn


/******************************************************************************/
/*                      Hibernate Wakeup Button (SW3)                         */
/******************************************************************************/

#define CY_CB_HIB_WAKE_BUTTON_PORT              GPIO_PRT21
#define CY_CB_HIB_WAKE_BUTTON_PIN               4
#define CY_CB_HIB_WAKE_BUTTON_PIN_MUX           P21_4_GPIO

/* Setup GPIO for Hibernate Wakeup Button interrupt source */
#define CY_CB_HIB_WAKE_BUTTON_IRQN              ioss_interrupts_gpio_dpslp_21_IRQn


/******************************************************************************/
/*                      Power Control Option (VCC11, REGHC)                   */
/******************************************************************************/
// EXT_PS_CTL0 -> i_sense_in_plus
#define CY_CB_EXT_PS_CTL0_PORT                  GPIO_PRT22
#define CY_CB_EXT_PS_CTL0_PIN                   1
#define CY_CB_EXT_PS_CTL0_PIN_MUX               P22_1_GPIO
// EXT_PS_CTL1 -> i_sense_in_minus
#define CY_CB_EXT_PS_CTL1_PORT                  GPIO_PRT22
#define CY_CB_EXT_PS_CTL1_PIN                   2
#define CY_CB_EXT_PS_CTL1_PIN_MUX               P22_2_GPIO


/******************************************************************************/
/*                      SCB-USB Uart                                          */
/******************************************************************************/

#define CY_USB_SCB_TYPE                         SCB3
#define CY_USB_SCB_UART_RX_PORT                 GPIO_PRT13
#define CY_USB_SCB_UART_RX_PIN                  0
#define CY_USB_SCB_UART_RX_MUX                  P13_0_SCB3_UART_RX
#define CY_USB_SCB_UART_TX_PORT                 GPIO_PRT13
#define CY_USB_SCB_UART_TX_PIN                  1
#define CY_USB_SCB_UART_TX_MUX                  P13_1_SCB3_UART_TX
#define CY_USB_SCB_UART_PCLK                    PCLK_SCB3_CLOCK
#define CY_USB_SCB_UART_IRQN                    scb_3_interrupt_IRQn 


/******************************************************************************/
/*                      AUTO ETH Port                                         */
/******************************************************************************/

#define CY_AUTO_ETH_TYPE                        ETH0

#define CY_AUTO_ETH_TX_CLK_PORT                 GPIO_PRT0
#define CY_AUTO_ETH_TX_CLK_PIN                  3
#define CY_AUTO_ETH_TX_CLK_PIN_MUX              P0_3_ETH0_TX_CLK

#define CY_AUTO_ETH_TX_CTL_PORT                 GPIO_PRT0
#define CY_AUTO_ETH_TX_CTL_PIN                  1
#define CY_AUTO_ETH_TX_CTL_PIN_MUX              P0_1_ETH0_TX_CTL

#define CY_AUTO_ETH_TD0_PORT                    GPIO_PRT2        
#define CY_AUTO_ETH_TD0_PIN                     0
#define CY_AUTO_ETH_TD0_PIN_MUX                 P2_0_ETH0_TXD0

#define CY_AUTO_ETH_TD1_PORT                    GPIO_PRT2        
#define CY_AUTO_ETH_TD1_PIN                     1
#define CY_AUTO_ETH_TD1_PIN_MUX                 P2_1_ETH0_TXD1

#define CY_AUTO_ETH_TD2_PORT                    GPIO_PRT2        
#define CY_AUTO_ETH_TD2_PIN                     2
#define CY_AUTO_ETH_TD2_PIN_MUX                 P2_2_ETH0_TXD2

#define CY_AUTO_ETH_TD3_PORT                    GPIO_PRT2
#define CY_AUTO_ETH_TD3_PIN                     3
#define CY_AUTO_ETH_TD3_PIN_MUX                 P2_3_ETH0_TXD3

#define CY_AUTO_ETH_TXER_PORT                   GPIO_PRT0
#define CY_AUTO_ETH_TXER_PIN                    2
#define CY_AUTO_ETH_TXER_PIN_MUX                P0_2_ETH0_TX_ER

#define CY_AUTO_ETH_RX_CLK_PORT                 GPIO_PRT6
#define CY_AUTO_ETH_RX_CLK_PIN                  0
#define CY_AUTO_ETH_RX_CLK_PIN_MUX              P6_0_ETH0_RX_CLK

#define CY_AUTO_ETH_RX_CTL_PORT                 GPIO_PRT5       
#define CY_AUTO_ETH_RX_CTL_PIN                  2
#define CY_AUTO_ETH_RX_CTL_PIN_MUX              P5_2_ETH0_RX_CTL

#define CY_AUTO_ETH_RD0_PORT                    GPIO_PRT3
#define CY_AUTO_ETH_RD0_PIN                     0
#define CY_AUTO_ETH_RD0_PIN_MUX                 P3_0_ETH0_RXD0
                                   
#define CY_AUTO_ETH_RD1_PORT                    GPIO_PRT3        
#define CY_AUTO_ETH_RD1_PIN                     1
#define CY_AUTO_ETH_RD1_PIN_MUX                 P3_1_ETH0_RXD1
                                    
#define CY_AUTO_ETH_RD2_PORT                    GPIO_PRT5        
#define CY_AUTO_ETH_RD2_PIN                     0
#define CY_AUTO_ETH_RD2_PIN_MUX                 P5_0_ETH0_RXD2
                                  
#define CY_AUTO_ETH_RD3_PORT                    GPIO_PRT5
#define CY_AUTO_ETH_RD3_PIN                     1
#define CY_AUTO_ETH_RD3_PIN_MUX                 P5_1_ETH0_RXD3

#define CY_AUTO_ETH_RX_ER_PORT                  GPIO_PRT5        
#define CY_AUTO_ETH_RX_ER_PIN                   3
#define CY_AUTO_ETH_RX_ER_PIN_MUX               P5_3_ETH0_RX_ER

#define CY_AUTO_ETH_MDC_PORT                    GPIO_PRT6   
#define CY_AUTO_ETH_MDC_PIN                     2
#define CY_AUTO_ETH_MDC_PIN_MUX                 P6_2_ETH0_MDC
                                    
#define CY_AUTO_ETH_MDIO_PORT                   GPIO_PRT6
#define CY_AUTO_ETH_MDIO_PIN                    1
#define CY_AUTO_ETH_MDIO_PIN_MUX                P6_1_ETH0_MDIO

#define CY_AUTO_ETH_REF_CLK_PORT                GPIO_PRT0
#define CY_AUTO_ETH_REF_CLK_PIN                 0
#define CY_AUTO_ETH_REF_CLK_PIN_MUX             P0_0_ETH0_REF_CLK

/* Setup IRQ source for 0, 1 and 2 Priority Queue */
#define CY_AUTO_ETH_IRQN0                       eth_0_interrupt_eth_0_IRQn
#define CY_AUTO_ETH_IRQN1                       eth_0_interrupt_eth_1_IRQn
#define CY_AUTO_ETH_IRQN2                       eth_0_interrupt_eth_2_IRQn


/******************************************************************************/
/*                      AUDIOSS Port (I2S1) and SCB                           */
/******************************************************************************/

#define CY_AUDIOSS_TYPE                         I2S1

#define CY_AUDIOSS_MCLK_PORT                    GPIO_PRT14
#define CY_AUDIOSS_MCLK_PIN                     0
#define CY_AUDIOSS_MCLK_PIN_MUX                 P14_0_AUDIOSS1_MCLK

#define CY_AUDIOSS_TX_SCK_PORT                  GPIO_PRT14
#define CY_AUDIOSS_TX_SCK_PIN                   1
#define CY_AUDIOSS_TX_SCK_PIN_MUX               P14_1_AUDIOSS1_TX_SCK

#define CY_AUDIOSS_TX_WS_PORT                   GPIO_PRT14
#define CY_AUDIOSS_TX_WS_PIN                    2
#define CY_AUDIOSS_TX_WS_PIN_MUX                P14_2_AUDIOSS1_TX_WS

#define CY_AUDIOSS_TX_SDO_PORT                  GPIO_PRT14
#define CY_AUDIOSS_TX_SDO_PIN                   3
#define CY_AUDIOSS_TX_SDO_PIN_MUX               P14_3_AUDIOSS1_TX_SDO

#define CY_AUDIOSS_CLK_I2S_IF_PORT              GPIO_PRT18
#define CY_AUDIOSS_CLK_I2S_IF_PIN               0
#define CY_AUDIOSS_CLK_I2S_IF_PIN_MUX           P18_0_AUDIOSS1_CLK_I2S_IF

#define CY_AUDIOSS_RX_SCK_PORT                  GPIO_PRT18
#define CY_AUDIOSS_RX_SCK_PIN                   1
#define CY_AUDIOSS_RX_SCK_PIN_MUX               P18_1_AUDIOSS1_RX_SCK

#define CY_AUDIOSS_RX_WS_PORT                   GPIO_PRT18
#define CY_AUDIOSS_RX_WS_PIN                    2
#define CY_AUDIOSS_RX_WS_PIN_MUX                P18_2_AUDIOSS1_RX_WS

#define CY_AUDIOSS_RX_SDI_PORT                  GPIO_PRT18
#define CY_AUDIOSS_RX_SDI_PIN                   3
#define CY_AUDIOSS_RX_SDI_PIN_MUX               P18_3_AUDIOSS1_RX_SDI

#define CY_AUDIOSS_IRQN                         audioss_1_interrupt_i2s_IRQn

/* AUDIOSS-SPI port for Codec Communication */
#define CY_AUDIOSS_SPI_TYPE                     SCB0

#define CY_AUDIOSS_SPI_MISO_PORT                GPIO_PRT1
#define CY_AUDIOSS_SPI_MISO_PIN                 0
#define CY_AUDIOSS_SPI_MISO_PIN_MUX             P1_0_SCB0_SPI_MISO

#define CY_AUDIOSS_SPI_MOSI_PORT                GPIO_PRT1
#define CY_AUDIOSS_SPI_MOSI_PIN                 1
#define CY_AUDIOSS_SPI_MOSI_PIN_MUX             P1_1_SCB0_SPI_MOSI

#define CY_AUDIOSS_SPI_CLK_PORT                 GPIO_PRT1
#define CY_AUDIOSS_SPI_CLK_PIN                  2
#define CY_AUDIOSS_SPI_CLK_PIN_MUX              P1_2_SCB0_SPI_CLK

#define CY_AUDIOSS_SPI_SS0_PORT                 GPIO_PRT1
#define CY_AUDIOSS_SPI_SS0_PIN                  3
#define CY_AUDIOSS_SPI_SS0_PIN_MUX              P1_3_SCB0_SPI_SELECT0

#define CY_AUDIOSS_SPI_PCLK                     PCLK_SCB0_CLOCK
#define CY_AUDIOSS_SPI_IRQN                     scb_0_interrupt_IRQn


/******************************************************************************/
/*                      SDHC-eMMC Mux                                         */
/******************************************************************************/

#define CY_SDHC_TYPE                            SDHC0

#define CY_SDHC_WP_PORT                         GPIO_PRT7
#define CY_SDHC_WP_PIN                          0
#define CY_SDHC_WP_PIN_MUX                      P7_0_SDHC0_CARD_MECH_WRITE_PROT

#define CY_SDHC_CLK_CARD_PORT                   GPIO_PRT7
#define CY_SDHC_CLK_CARD_PIN                    1
#define CY_SDHC_CLK_CARD_PIN_MUX                P7_1_SDHC0_CLK_CARD

#define CY_SDHC_CARD_CMD_PORT                   GPIO_PRT7
#define CY_SDHC_CARD_CMD_PIN                    2
#define CY_SDHC_CARD_CMD_PIN_MUX                P7_2_SDHC0_CARD_CMD

#define CY_SDHC_CARD_DETECT_N_PORT              GPIO_PRT6
#define CY_SDHC_CARD_DETECT_N_PIN               5
#define CY_SDHC_CARD_DETECT_N_PIN_MUX           P6_5_SDHC0_CARD_DETECT_N

#define CY_SDHC_CARD_DAT_3TO00_PORT             GPIO_PRT7
#define CY_SDHC_CARD_DAT_3TO00_PIN              4
#define CY_SDHC_CARD_DAT_3TO00_PIN_MUX          P7_4_SDHC0_CARD_DAT_3TO00  

#define CY_SDHC_CARD_DAT_3TO01_PORT             GPIO_PRT7
#define CY_SDHC_CARD_DAT_3TO01_PIN              5
#define CY_SDHC_CARD_DAT_3TO01_PIN_MUX          P7_5_SDHC0_CARD_DAT_3TO01

#define CY_SDHC_CARD_DAT_3TO02_PORT             GPIO_PRT8
#define CY_SDHC_CARD_DAT_3TO02_PIN              0
#define CY_SDHC_CARD_DAT_3TO02_PIN_MUX          P8_0_SDHC0_CARD_DAT_3TO02

#define CY_SDHC_CARD_DAT_3TO03_PORT             GPIO_PRT8
#define CY_SDHC_CARD_DAT_3TO03_PIN              1
#define CY_SDHC_CARD_DAT_3TO03_PIN_MUX          P8_1_SDHC0_CARD_DAT_3TO03

#define CY_SDHC_GENERAL_IRQN                    sdhc_0_interrupt_general_IRQn


/******************************************************************************/
/*                      SMIF0- Hyper Flash/RAM and Dual Quad                  */
/******************************************************************************/

#define CY_SMIF0_TYPE                           SMIF0_DEVICE0

#define CY_SMIF0_CLK_PORT                       GPIO_PRT7
#define CY_SMIF0_CLK_PIN                        0
#define CY_SMIF0_CLK_PIN_MUX                    P7_0_SMIF0_SPIHB_CLK

#define CY_SMIF0_RWDS_PORT                      GPIO_PRT7
#define CY_SMIF0_RWDS_PIN                       1
#define CY_SMIF0_RWDS_PIN_MUX                   P7_1_SMIF0_SPIHB_RWDS

#define CY_SMIF0_SELECT0_PORT                   GPIO_PRT7
#define CY_SMIF0_SELECT0_PIN                    2
#define CY_SMIF0_SELECT0_PIN_MUX                P7_2_SMIF0_SPIHB_SELECT0

#define CY_SMIF0_SELECT1_PORT                   GPIO_PRT7
#define CY_SMIF0_SELECT1_PIN                    3
#define CY_SMIF0_SELECT1_PIN_MUX                P7_3_SMIF0_SPIHB_SELECT1

#define CY_SMIF0_DATA0_PORT                     GPIO_PRT7
#define CY_SMIF0_DATA0_PIN                      4
#define CY_SMIF0_DATA0_PIN_MUX                  P7_4_SMIF0_SPIHB_DATA0

#define CY_SMIF0_DATA1_PORT                     GPIO_PRT7
#define CY_SMIF0_DATA1_PIN                      5
#define CY_SMIF0_DATA1_PIN_MUX                  P7_5_SMIF0_SPIHB_DATA1

#define CY_SMIF0_DATA2_PORT                     GPIO_PRT8
#define CY_SMIF0_DATA2_PIN                      0
#define CY_SMIF0_DATA2_PIN_MUX                  P8_0_SMIF0_SPIHB_DATA2

#define CY_SMIF0_DATA3_PORT                     GPIO_PRT8
#define CY_SMIF0_DATA3_PIN                      1
#define CY_SMIF0_DATA3_PIN_MUX                  P8_1_SMIF0_SPIHB_DATA3

#define CY_SMIF0_DATA4_PORT                     GPIO_PRT8
#define CY_SMIF0_DATA4_PIN                      2
#define CY_SMIF0_DATA4_PIN_MUX                  P8_2_SMIF0_SPIHB_DATA4

#define CY_SMIF0_DATA5_PORT                     GPIO_PRT11
#define CY_SMIF0_DATA5_PIN                      0
#define CY_SMIF0_DATA5_PIN_MUX                  P11_0_SMIF0_SPIHB_DATA5

#define CY_SMIF0_DATA6_PORT                     GPIO_PRT11
#define CY_SMIF0_DATA6_PIN                      1
#define CY_SMIF0_DATA6_PIN_MUX                  P11_1_SMIF0_SPIHB_DATA6

#define CY_SMIF0_DATA7_PORT                     GPIO_PRT11
#define CY_SMIF0_DATA7_PIN                      2
#define CY_SMIF0_DATA7_PIN_MUX                  P11_2_SMIF0_SPIHB_DATA7

#define CY_SMIF0_IRQN                           smif_0_interrupt_IRQn


/******************************************************************************/
/******************************************************************************/

// BB Board Entities

/******************************************************************************/
/*                      LEDs Base Board Mux                                   */
/******************************************************************************/

#define CY_LED0_PORT                            GPIO_PRT7
#define CY_LED0_PIN                             6
#define CY_LED0_PIN_MUX                         P7_6_GPIO
  
#define CY_LED1_PORT                            GPIO_PRT7
#define CY_LED1_PIN                             7
#define CY_LED1_PIN_MUX                         P7_7_GPIO
    
#define CY_LED2_PORT                            GPIO_PRT8
#define CY_LED2_PIN                             3
#define CY_LED2_PIN_MUX                         P8_3_GPIO
  
#define CY_LED3_PORT                            GPIO_PRT8
#define CY_LED3_PIN                             4
#define CY_LED3_PIN_MUX                         P8_4_GPIO
  
#define CY_LED4_PORT                            GPIO_PRT9
#define CY_LED4_PIN                             0
#define CY_LED4_PIN_MUX                         P9_0_GPIO
  
#define CY_LED5_PORT                            GPIO_PRT9
#define CY_LED5_PIN                             1
#define CY_LED5_PIN_MUX                         P9_1_GPIO
  
#define CY_LED6_PORT                            GPIO_PRT9
#define CY_LED6_PIN                             2
#define CY_LED6_PIN_MUX                         P9_2_GPIO
  
#define CY_LED7_PORT                            GPIO_PRT9
#define CY_LED7_PIN                             3
#define CY_LED7_PIN_MUX                         P9_3_GPIO
  
#define CY_LED8_PORT                            GPIO_PRT10
#define CY_LED8_PIN                             0
#define CY_LED8_PIN_MUX                         P10_0_GPIO
  
#define CY_LED9_PORT                            GPIO_PRT10
#define CY_LED9_PIN                             1
#define CY_LED9_PIN_MUX                         P10_1_GPIO  


/******************************************************************************/
/*                      ADC POT                                		      */
/******************************************************************************/

#define CY_ADC_POT_MACRO                        PASS0_SAR1
#define CY_ADC_POT_IN_NO                        10
#define CY_ADC_POT_PORT                         GPIO_PRT12
#define CY_ADC_POT_PIN                          6
#define CY_ADC_POT_PIN_MUX                      P12_6_GPIO
#define CY_ADC_POT_PCLK                         PCLK_PASS0_CLOCK_SAR1
#define CY_ADC_POT_IRQN                         pass_0_interrupts_sar_42_IRQn


/******************************************************************************/
/*                      CAN FD Port                          		      */
/******************************************************************************/

/* CAN1 Pin Mux */
#define CY_CANFD1_TYPE                          CY_CANFD0_1_TYPE
#define CY_CANFD1_RX_PORT                       GPIO_PRT4
#define CY_CANFD1_RX_PIN                        4
#define CY_CANFD1_RX_MUX                        P4_4_CANFD0_TTCAN_RX1
#define CY_CANFD1_TX_PORT                       GPIO_PRT4
#define CY_CANFD1_TX_PIN                        3
#define CY_CANFD1_TX_MUX                        P4_3_CANFD0_TTCAN_TX1
#define CY_CANFD1_PCLK                          PCLK_CANFD0_CLOCK_CAN1
#define CY_CANFD1_IRQN                          canfd_0_interrupts0_1_IRQn
  
/* CAN2 Pin Mux */
#define CY_CANFD2_TYPE                          CY_CANFD0_2_TYPE
#define CY_CANFD2_RX_PORT                       GPIO_PRT12
#define CY_CANFD2_RX_PIN                        1
#define CY_CANFD2_RX_MUX                        P12_1_CANFD0_TTCAN_RX2
#define CY_CANFD2_TX_PORT                       GPIO_PRT12
#define CY_CANFD2_TX_PIN                        0
#define CY_CANFD2_TX_MUX                        P12_0_CANFD0_TTCAN_TX2
#define CY_CANFD2_PCLK                          PCLK_CANFD0_CLOCK_CAN2
#define CY_CANFD2_IRQN                          canfd_0_interrupts0_2_IRQn
  
/* CAN3 Pin Mux */
#define CY_CANFD3_TYPE                          CY_CANFD1_0_TYPE
#define CY_CANFD3_RX_PORT                       GPIO_PRT23
#define CY_CANFD3_RX_PIN                        1
#define CY_CANFD3_RX_MUX                        P23_1_CANFD1_TTCAN_RX0
#define CY_CANFD3_TX_PORT                       GPIO_PRT23
#define CY_CANFD3_TX_PIN                        0
#define CY_CANFD3_TX_MUX                        P23_0_CANFD1_TTCAN_TX0
#define CY_CANFD3_PCLK                          PCLK_CANFD1_CLOCK_CAN0
#define CY_CANFD3_IRQN                          canfd_1_interrupts0_0_IRQn
  
/* CAN4 Pin Mux */
#define CY_CANFD4_TYPE                          CY_CANFD1_1_TYPE
#define CY_CANFD4_RX_PORT                       GPIO_PRT12
#define CY_CANFD4_RX_PIN                        5
#define CY_CANFD4_RX_MUX                        P12_5_CANFD1_TTCAN_RX1
#define CY_CANFD4_TX_PORT                       GPIO_PRT12
#define CY_CANFD4_TX_PIN                        4
#define CY_CANFD4_TX_MUX                        P12_4_CANFD1_TTCAN_TX1
#define CY_CANFD4_PCLK                          PCLK_CANFD1_CLOCK_CAN1
#define CY_CANFD4_IRQN                          canfd_1_interrupts0_1_IRQn

/* CAN5 Pin Mux */
#define CY_CANFD5_TYPE                          CY_CANFD1_2_TYPE
#define CY_CANFD5_RX_PORT                       GPIO_PRT20
#define CY_CANFD5_RX_PIN                        4
#define CY_CANFD5_RX_MUX                        P20_4_CANFD1_TTCAN_RX2
#define CY_CANFD5_TX_PORT                       GPIO_PRT20
#define CY_CANFD5_TX_PIN                        3
#define CY_CANFD5_TX_MUX                        P20_3_CANFD1_TTCAN_TX2
#define CY_CANFD5_PCLK                          PCLK_CANFD1_CLOCK_CAN2
#define CY_CANFD5_IRQN                          canfd_1_interrupts0_2_IRQn
  
/* CAN6 Pin Mux */
#define CY_CANFD6_TYPE                          CY_CANFD1_3_TYPE
#define CY_CANFD6_RX_PORT                       GPIO_PRT15
#define CY_CANFD6_RX_PIN                        1
#define CY_CANFD6_RX_MUX                        P15_1_CANFD1_TTCAN_RX3
#define CY_CANFD6_TX_PORT                       GPIO_PRT15
#define CY_CANFD6_TX_PIN                        0
#define CY_CANFD6_TX_MUX                        P15_0_CANFD1_TTCAN_TX3
#define CY_CANFD6_PCLK                          PCLK_CANFD1_CLOCK_CAN3
#define CY_CANFD6_IRQN                          canfd_1_interrupts0_3_IRQn

/* CAN7 Pin Mux */
#define CY_CANFD7_TYPE                          CY_CANFD1_4_TYPE
#define CY_CANFD7_RX_PORT                       GPIO_PRT20
#define CY_CANFD7_RX_PIN                        7
#define CY_CANFD7_RX_MUX                        P20_7_CANFD1_TTCAN_RX4
#define CY_CANFD7_TX_PORT                       GPIO_PRT20
#define CY_CANFD7_TX_PIN                        6
#define CY_CANFD7_TX_MUX                        P20_6_CANFD1_TTCAN_TX4
#define CY_CANFD7_PCLK                          PCLK_CANFD1_CLOCK_CAN4
#define CY_CANFD7_IRQN                          canfd_1_interrupts0_4_IRQn

/******************************************************************************/
/*                      SCB_CADFD Base Board Mux                               */
/******************************************************************************/
/* CANFD-SPI Mux (BB_CAN_SPI) */
#define CY_CANFD_SCB_TYPE               SCB1
#define CY_CANFD_SCB_MOSI_PORT          GPIO_PRT18
#define CY_CANFD_SCB_MOSI_PIN           1
#define CY_CANFD_SCB_MOSI_PIN_MUX       P18_1_SCB1_SPI_MOSI
#define CY_CANFD_SCB_MISO_PORT          GPIO_PRT18
#define CY_CANFD_SCB_MISO_PIN           0
#define CY_CANFD_SCB_MISO_PIN_MUX       P18_0_SCB1_SPI_MISO
#define CY_CANFD_SCB_SCK_PORT           GPIO_PRT18
#define CY_CANFD_SCB_SCK_PIN            2
#define CY_CANFD_SCB_SCK_PIN_MUX        P18_2_SCB1_SPI_CLK
#define CY_CANFD_SCB_SS0_PORT           GPIO_PRT20
#define CY_CANFD_SCB_SS0_PIN            6
#define CY_CANFD_SCB_SS0_PIN_MUX        P20_6_SCB1_SPI_SELECT0
#define CY_CANFD_SCB_SS1_PORT           GPIO_PRT20
#define CY_CANFD_SCB_SS1_PIN            7
#define CY_CANFD_SCB_SS1_PIN_MUX        P20_7_SCB1_SPI_SELECT1
#define CY_CANFD_SCB_SS2_PORT           GPIO_PRT21
#define CY_CANFD_SCB_SS2_PIN            0
#define CY_CANFD_SCB_SS2_PIN_MUX        P21_0_SCB1_SPI_SELECT2
#define CY_CANFD_SCB_PCLK               PCLK_SCB1_CLOCK
#define CY_CANFD_SCB_IRQN               scb_1_interrupt_IRQn
/******************************************************************************/
/*                      LIN Base Board Mux                                    */
/******************************************************************************/

/* LIN Channel 0 */
#define CY_LINCH0_TYPE                          LIN0_CH0
#define CY_LINCH0_RX_PORT                       GPIO_PRT21
#define CY_LINCH0_RX_PIN                        5
#define CY_LINCH0_RX_PIN_MUX                    P21_5_LIN0_LIN_RX0
#define CY_LINCH0_TX_PORT                       GPIO_PRT21
#define CY_LINCH0_TX_PIN                        6
#define CY_LINCH0_TX_PIN_MUX                    P21_6_LIN0_LIN_TX0
#define CY_LINCH0_PCLK                          PCLK_LIN0_CLOCK_CH_EN0
#define CY_LINCH0_IRQN                          lin_0_interrupts_0_IRQn
  
/* LIN Channel 1 */
#define CY_LINCH1_TYPE                          LIN0_CH1
#define CY_LINCH1_RX_PORT                       GPIO_PRT4
#define CY_LINCH1_RX_PIN                        0
#define CY_LINCH1_RX_PIN_MUX                    P4_0_LIN0_LIN_RX1
#define CY_LINCH1_TX_PORT                       GPIO_PRT4
#define CY_LINCH1_TX_PIN                        1
#define CY_LINCH1_TX_PIN_MUX                    P4_1_LIN0_LIN_TX1
#define CY_LINCH1_PCLK                          PCLK_LIN0_CLOCK_CH_EN1
#define CY_LINCH1_IRQN                          lin_0_interrupts_1_IRQn

/* LIN Channel 2 */
#define CY_LINCH2_TYPE                          LIN0_CH5
#define CY_LINCH2_RX_PORT                       GPIO_PRT20
#define CY_LINCH2_RX_PIN                        0
#define CY_LINCH2_RX_PIN_MUX                    P20_0_LIN0_LIN_RX5
#define CY_LINCH2_TX_PORT                       GPIO_PRT20
#define CY_LINCH2_TX_PIN                        1
#define CY_LINCH2_TX_PIN_MUX                    P20_1_LIN0_LIN_TX5
#define CY_LINCH2_PCLK                          PCLK_LIN0_CLOCK_CH_EN5
#define CY_LINCH2_IRQN                          lin_0_interrupts_5_IRQn

/* LIN Channel 3 */
#define CY_LINCH3_TYPE                          LIN0_CH7
#define CY_LINCH3_RX_PORT                       GPIO_PRT22
#define CY_LINCH3_RX_PIN                        5
#define CY_LINCH3_RX_PIN_MUX                    P22_5_LIN0_LIN_RX7
#define CY_LINCH3_TX_PORT                       GPIO_PRT22
#define CY_LINCH3_TX_PIN                        6
#define CY_LINCH3_TX_PIN_MUX                    P22_6_LIN0_LIN_TX7
#define CY_LINCH3_PCLK                          PCLK_LIN0_CLOCK_CH_EN7
#define CY_LINCH3_IRQN                          lin_0_interrupts_7_IRQn

/* LIN Channel 4 */
#define CY_LINCH4_TYPE                          LIN0_CH11
#define CY_LINCH4_RX_PORT                       GPIO_PRT17
#define CY_LINCH4_RX_PIN                        0
#define CY_LINCH4_RX_PIN_MUX                    P17_0_LIN0_LIN_RX11
#define CY_LINCH4_TX_PORT                       GPIO_PRT17
#define CY_LINCH4_TX_PIN                        1
#define CY_LINCH4_TX_PIN_MUX                    P17_1_LIN0_LIN_TX11
#define CY_LINCH4_PCLK                          PCLK_LIN0_CLOCK_CH_EN11
#define CY_LINCH4_IRQN                          lin_0_interrupts_11_IRQn

/* LIN Channel 5 */
#define CY_LINCH5_TYPE                          LIN0_CH15
#define CY_LINCH5_RX_PORT                       GPIO_PRT17
#define CY_LINCH5_RX_PIN                        5
#define CY_LINCH5_RX_PIN_MUX                    P17_5_LIN0_LIN_RX15
#define CY_LINCH5_TX_PORT                       GPIO_PRT17
#define CY_LINCH5_TX_PIN                        6
#define CY_LINCH5_TX_PIN_MUX                    P17_6_LIN0_LIN_TX15
#define CY_LINCH5_PCLK                          PCLK_LIN0_CLOCK_CH_EN15
#define CY_LINCH5_IRQN                          lin_0_interrupts_15_IRQn   


/******************************************************************************/
/*                      FLEX-RAY Base Board Mux                               */
/******************************************************************************/

#define CY_FLEXRAY_TYPE                         FLEXRAY0

#define CY_FRA_RXD_PORT                         GPIO_PRT10
#define CY_FRA_RXD_PIN                          2
#define CY_FRA_RXD_PIN_MUX                      P10_2_FLEXRAY0_RXDA

#define CY_FRA_TXD_PORT                         GPIO_PRT10
#define CY_FRA_TXD_PIN                          3
#define CY_FRA_TXD_PIN_MUX                      P10_3_FLEXRAY0_TXDA

#define CY_FRA_TXEN_PORT                        GPIO_PRT10
#define CY_FRA_TXEN_PIN                         4
#define CY_FRA_TXEN_PIN_MUX                     P10_4_FLEXRAY0_TXENA_N

#define CY_FRA_STBN_PORT                        GPIO_PRT13
#define CY_FRA_STBN_PIN                         4
#define CY_FRA_STBN_PIN_MUX                     P13_4_GPIO

#define CY_FRA_EN_PORT                          GPIO_PRT13
#define CY_FRA_EN_PIN                           5
#define CY_FRA_EN_PIN_MUX                       P13_5_GPIO

#define CY_FRA_ERRN_PORT                        GPIO_PRT13
#define CY_FRA_ERRN_PIN                         6
#define CY_FRA_ERRN_PIN_MUX                     P13_6_GPIO

#define CY_FRA_WAKE_PORT                        GPIO_PRT13
#define CY_FRA_WAKE_PIN                         7
#define CY_FRA_WAKE_PIN_MUX                     P13_7_GPIO

#define CY_FRB_RXD_PORT                         GPIO_PRT10
#define CY_FRB_RXD_PIN                          5
#define CY_FRB_RXD_PIN_MUX                      P10_5_FLEXRAY0_RXDB

#define CY_FRB_TXD_PORT                         GPIO_PRT10
#define CY_FRB_TXD_PIN                          6
#define CY_FRB_TXD_PIN_MUX                      P10_6_FLEXRAY0_TXDB

#define CY_FRB_TXEN_PORT                        GPIO_PRT10
#define CY_FRB_TXEN_PIN                         7
#define CY_FRB_TXEN_PIN_MUX                     P10_7_FLEXRAY0_TXENB_N

#define CY_FRB_STBN_PORT                        GPIO_PRT14
#define CY_FRB_STBN_PIN                         4
#define CY_FRB_STBN_PIN_MUX                     P14_4_GPIO

#define CY_FRB_EN_PORT                          GPIO_PRT14
#define CY_FRB_EN_PIN                           5
#define CY_FRB_EN_PIN_MUX                       P14_5_GPIO

#define CY_FRB_ERRN_PORT                        GPIO_PRT14
#define CY_FRB_ERRN_PIN                         6
#define CY_FRB_ERRN_PIN_MUX                     P14_6_GPIO

#define CY_FRB_WAKE_PORT                        GPIO_PRT14
#define CY_FRB_WAKE_PIN                         7
#define CY_FRB_WAKE_PIN_MUX                     P14_7_GPIO


/******************************************************************************/
/*                      SMARTIO Base Board Mux                                */
/******************************************************************************/

#define CY_SMARTIO_MACRO                        SMARTIO
#define CY_SMARTIO_PORT                         SMARTIO_PRT15
#define CY_SMARTIO_CLK                          PCLK_SMARTIO15_CLOCK

#define CY_SMARTIO_OUT_PORT                     GPIO_PRT15
#define CY_SMARTIO_OUT_PIN                      1
#define CY_SMARTIO_OUT_PORT_MUX                 P15_1_GPIO

#define CY_SMARTIO_IN_PORT                      GPIO_PRT15
#define CY_SMARTIO_IN_PIN                       0
#define CY_SMARTIO_IN_PORT_MUX                  P15_0_GPIO


/******************************************************************************/
/******************************************************************************/

// tviibh8m - 320-BGA Package devices
    
// #if (CY_USE_PSVP == 0) (--> Silicon), project setting CY_USE_PSVP should be changed to '0'
// select the supported or required device accordingly

#elif (CY_USE_PSVP == 0) && ( defined(CYT4BFCCHE) || defined(CYT4BFCCHS) || \
                              defined(CYT4BFCCJE) || defined(CYT4BFCCJS) )



/******************************************************************************/
/******************************************************************************/

#else // No Device or PSVP Selected
    
    #error "Choose either a Device based on TVII-B-H-8M Datasheet or CY_USE_PSVP"
    
#endif // #if (CY_USE_PSVP == 1)
  
  
#ifdef __cplusplus
}
#endif

#endif /* BB_BSP_TVIIBH8M_H */

/* [] END OF FILE */
