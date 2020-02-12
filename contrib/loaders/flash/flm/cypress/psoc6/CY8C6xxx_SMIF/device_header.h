/*******************************************************************************
* \file device_header.h
* \version 1.0
*
* \brief
*  Selected #defines from the device header file.
*
********************************************************************************
* \copyright
* Copyright 2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#if !defined (DEV_HEADER)
#define DEV_HEADER

#define _VAL2FLD(field, value)    (((uint32_t)(value) << field ## _Pos) & field ## _Msk)
#define _FLD2VAL(field, value)    (((uint32_t)(value) & field ## _Msk) >> field ## _Pos)
#define _CLR_SET_FLD32U(reg, field, value) (((reg) & ((uint32_t)(~(field ## _Msk)))) | (_VAL2FLD(field, value)))
#define CY_SYSCLK_CLR_SET(reg, field, value) (reg) = _CLR_SET_FLD32U((reg), field, value)


#define SRSS_CLK_ROOT_SELECT_ROOT_MUX_Pos (0UL)                 /*!< SRSS CLK_ROOT_SELECT: ROOT_MUX (Bit 0)                    */
#define SRSS_CLK_ROOT_SELECT_ROOT_MUX_Msk (0xfUL)               /*!< SRSS CLK_ROOT_SELECT: ROOT_MUX (Bitfield-Mask: 0x0f)      */
#define SRSS_CLK_ROOT_SELECT_ROOT_DIV_Pos (4UL)                 /*!< SRSS CLK_ROOT_SELECT: ROOT_DIV (Bit 4)                    */
#define SRSS_CLK_ROOT_SELECT_ROOT_DIV_Msk (0x30UL)              /*!< SRSS CLK_ROOT_SELECT: ROOT_DIV (Bitfield-Mask: 0x03)      */
#define SRSS_CLK_ROOT_SELECT_ENABLE_Pos   (31UL)                /*!< SRSS CLK_ROOT_SELECT: ENABLE (Bit 31)                     */
#define SRSS_CLK_ROOT_SELECT_ENABLE_Msk   (0x80000000UL)        /*!< SRSS CLK_ROOT_SELECT: ENABLE (Bitfield-Mask: 0x01)        */
#define CY_SYSCLK_HFCLK_IN_CLKPATH0       (0UL)
#define CY_SYSCLK_HFCLK_DIVIDE_BY_4       (2u)
#define SRSS_BASE                   0x40260000UL

#if defined(PSOC6_1M)
  #define HSIOM_BASE                  0x40310000UL
  #define GPIO_BASE                   0x40320000UL
#elif defined(PSOC6_2M)
  #define HSIOM_BASE                  0x40300000UL
  #define GPIO_BASE                   0x40310000UL
#else
  #error "Target device not defined!"
#endif

#define GPIO_PRT_SECTION_SIZE       0x00000080UL
#define HSIOM_PRT_SECTION_SIZE      0x00000010UL
#define SMIF_DEVICE_SECTION_SIZE    0x00000080UL
#define SMIF_SECTION_SIZE           0x00010000UL

#ifndef   __STATIC_INLINE
  #define __STATIC_INLINE           static __inline
#endif

/* following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */


/**
  * \brief Multi-Counter Watchdog Timer (MCWDT_STRUCT)
  */
typedef struct {
   __IM uint32_t RESERVED;
  __IOM uint32_t MCWDT_CNTLOW;                  /*!< 0x00000004 Multi-Counter Watchdog Sub-counters 0/1                        */
  __IOM uint32_t MCWDT_CNTHIGH;                 /*!< 0x00000008 Multi-Counter Watchdog Sub-counter 2                           */
  __IOM uint32_t MCWDT_MATCH;                   /*!< 0x0000000C Multi-Counter Watchdog Counter Match Register                  */
  __IOM uint32_t MCWDT_CONFIG;                  /*!< 0x00000010 Multi-Counter Watchdog Counter Configuration                   */
  __IOM uint32_t MCWDT_CTL;                     /*!< 0x00000014 Multi-Counter Watchdog Counter Control                         */
  __IOM uint32_t MCWDT_INTR;                    /*!< 0x00000018 Multi-Counter Watchdog Counter Interrupt Register              */
  __IOM uint32_t MCWDT_INTR_SET;                /*!< 0x0000001C Multi-Counter Watchdog Counter Interrupt Set Register          */
  __IOM uint32_t MCWDT_INTR_MASK;               /*!< 0x00000020 Multi-Counter Watchdog Counter Interrupt Mask Register         */
   __IM uint32_t MCWDT_INTR_MASKED;             /*!< 0x00000024 Multi-Counter Watchdog Counter Interrupt Masked Register       */
  __IOM uint32_t MCWDT_LOCK;                    /*!< 0x00000028 Multi-Counter Watchdog Counter Lock Register                   */
   __IM uint32_t RESERVED1[5];
} MCWDT_STRUCT_Type;                            /*!< Size = 44 (0x2C)                                                          */
/**
  * \brief SRSS Clock Supervisor (CSV) registers (CLK_CSV)
  */
typedef struct {
  __IOM uint32_t HF_CTL;                        /*!< 0x00000000 HFCLK Clock Supervision Control Register                       */
  __IOM uint32_t HF_LIMIT;                      /*!< 0x00000004 HFCLK Clock Supervision Limit Register                         */
   __IM uint32_t HF_CNT;                        /*!< 0x00000008 HFCLK Clock Supervision Count Register                         */
   __IM uint32_t RESERVED;
} CLK_CSV_Type;                                 /*!< Size = 12 (0xC)                                                           */
/**
  * \brief SRSS Core Registers (SRSS)
  */
typedef struct {                                /*!< SRSS Structure                                                            */
  __IOM uint32_t PWR_CTL;                       /*!< 0x00000000 Power Mode Control                                             */
  __IOM uint32_t PWR_HIBERNATE;                 /*!< 0x00000004 HIBERNATE Mode Register                                        */
  __IOM uint32_t PWR_LVD_CTL;                   /*!< 0x00000008 Low Voltage Detector (LVD) Configuration Register              */
   __IM uint32_t RESERVED[2];
  __IOM uint32_t PWR_BUCK_CTL;                  /*!< 0x00000014 SIMO Buck Control Register                                     */
  __IOM uint32_t PWR_BUCK_CTL2;                 /*!< 0x00000018 SIMO Buck Control Register 2                                   */
   __IM uint32_t PWR_LVD_STATUS;                /*!< 0x0000001C Low Voltage Detector (LVD) Status Register                     */
   __IM uint32_t RESERVED1[24];
  __IOM uint32_t PWR_HIB_DATA[16];              /*!< 0x00000080 HIBERNATE Data Register                                        */
   __IM uint32_t RESERVED2[48];
  __IOM uint32_t WDT_CTL;                       /*!< 0x00000180 Watchdog Counter Control Register                              */
  __IOM uint32_t WDT_CNT;                       /*!< 0x00000184 Watchdog Counter Count Register                                */
  __IOM uint32_t WDT_MATCH;                     /*!< 0x00000188 Watchdog Counter Match Register                                */
   __IM uint32_t RESERVED3[29];
        MCWDT_STRUCT_Type MCWDT_STRUCT[4];      /*!< 0x00000200 Multi-Counter Watchdog Timer                                   */
  __IOM uint32_t CLK_DSI_SELECT[16];            /*!< 0x00000300 Clock DSI Select Register                                      */
  __IOM uint32_t CLK_PATH_SELECT[16];           /*!< 0x00000340 Clock Path Select Register                                     */
  __IOM uint32_t CLK_ROOT_SELECT[16];           /*!< 0x00000380 Clock Root Select Register                                     */
   __IM uint32_t RESERVED4[16];
        CLK_CSV_Type CLK_CSV[16];               /*!< 0x00000400 SRSS Clock Supervisor (CSV) registers                          */
  __IOM uint32_t CLK_SELECT;                    /*!< 0x00000500 Clock selection register                                       */
  __IOM uint32_t CLK_TIMER_CTL;                 /*!< 0x00000504 Timer Clock Control Register                                   */
  __IOM uint32_t CLK_CSV_WCO_CTL;               /*!< 0x00000508 WCO Clock Supervision Control Register                         */
  __IOM uint32_t CLK_ILO_CONFIG;                /*!< 0x0000050C HVILO Configuration                                            */
  __IOM uint32_t CLK_IMO_CONFIG;                /*!< 0x00000510 IMO Configuration                                              */
  __IOM uint32_t CLK_OUTPUT_FAST;               /*!< 0x00000514 Fast Clock Output Select Register                              */
  __IOM uint32_t CLK_OUTPUT_SLOW;               /*!< 0x00000518 Slow Clock Output Select Register                              */
  __IOM uint32_t CLK_CAL_CNT1;                  /*!< 0x0000051C Clock Calibration Counter 1                                    */
   __IM uint32_t CLK_CAL_CNT2;                  /*!< 0x00000520 Clock Calibration Counter 2                                    */
   __IM uint32_t RESERVED5[2];
  __IOM uint32_t CLK_ECO_CONFIG;                /*!< 0x0000052C ECO Configuration Register                                     */
   __IM uint32_t CLK_ECO_STATUS;                /*!< 0x00000530 ECO Status Register                                            */
   __IM uint32_t RESERVED6;
  __IOM uint32_t CLK_WCO_DPLL;                  /*!< 0x00000538 WCO DPLL Register                                              */
  __IOM uint32_t CLK_PILO_CONFIG;               /*!< 0x0000053C Precision ILO Configuration Register                           */
   __IM uint32_t RESERVED7[16];
  __IOM uint32_t CLK_FLL_CONFIG;                /*!< 0x00000580 FLL Configuration Register                                     */
  __IOM uint32_t CLK_FLL_CONFIG2;               /*!< 0x00000584 FLL Configuration Register 2                                   */
  __IOM uint32_t CLK_FLL_CONFIG3;               /*!< 0x00000588 FLL Configuration Register 3                                   */
  __IOM uint32_t CLK_FLL_CONFIG4;               /*!< 0x0000058C FLL Configuration Register 4                                   */
  __IOM uint32_t CLK_FLL_STATUS;                /*!< 0x00000590 FLL Status Register                                            */
   __IM uint32_t RESERVED8[27];
  __IOM uint32_t CLK_PLL_CONFIG[15];            /*!< 0x00000600 PLL Configuration Register                                     */
   __IM uint32_t RESERVED9;
  __IOM uint32_t CLK_PLL_STATUS[15];            /*!< 0x00000640 PLL Status Register                                            */
   __IM uint32_t RESERVED10[33];
  __IOM uint32_t SRSS_INTR;                     /*!< 0x00000700 SRSS Interrupt Register                                        */
  __IOM uint32_t SRSS_INTR_SET;                 /*!< 0x00000704 SRSS Interrupt Set Register                                    */
  __IOM uint32_t SRSS_INTR_MASK;                /*!< 0x00000708 SRSS Interrupt Mask Register                                   */
   __IM uint32_t SRSS_INTR_MASKED;              /*!< 0x0000070C SRSS Interrupt Masked Register                                 */
  __IOM uint32_t SRSS_INTR_CFG;                 /*!< 0x00000710 SRSS Interrupt Configuration Register                          */
   __IM uint32_t RESERVED11[59];
  __IOM uint32_t RES_CAUSE;                     /*!< 0x00000800 Reset Cause Observation Register                               */
  __IOM uint32_t RES_CAUSE2;                    /*!< 0x00000804 Reset Cause Observation Register 2                             */
   __IM uint32_t RESERVED12[7614];
  __IOM uint32_t PWR_TRIM_REF_CTL;              /*!< 0x00007F00 Reference Trim Register                                        */
  __IOM uint32_t PWR_TRIM_BODOVP_CTL;           /*!< 0x00007F04 BOD/OVP Trim Register                                          */
  __IOM uint32_t CLK_TRIM_CCO_CTL;              /*!< 0x00007F08 CCO Trim Register                                              */
  __IOM uint32_t CLK_TRIM_CCO_CTL2;             /*!< 0x00007F0C CCO Trim Register 2                                            */
   __IM uint32_t RESERVED13[8];
  __IOM uint32_t PWR_TRIM_WAKE_CTL;             /*!< 0x00007F30 Wakeup Trim Register                                           */
   __IM uint32_t RESERVED14[8183];
  __IOM uint32_t PWR_TRIM_LVD_CTL;              /*!< 0x0000FF10 LVD Trim Register                                              */
   __IM uint32_t RESERVED15;
  __IOM uint32_t CLK_TRIM_ILO_CTL;              /*!< 0x0000FF18 ILO Trim Register                                              */
  __IOM uint32_t PWR_TRIM_PWRSYS_CTL;           /*!< 0x0000FF1C Power System Trim Register                                     */
  __IOM uint32_t CLK_TRIM_ECO_CTL;              /*!< 0x0000FF20 ECO Trim Register                                              */
  __IOM uint32_t CLK_TRIM_PILO_CTL;             /*!< 0x0000FF24 PILO Trim Register                                             */
  __IOM uint32_t CLK_TRIM_PILO_CTL2;            /*!< 0x0000FF28 PILO Trim Register 2                                           */
  __IOM uint32_t CLK_TRIM_PILO_CTL3;            /*!< 0x0000FF2C PILO Trim Register 3                                           */
} SRSS_Type;                                    /*!< Size = 65328 (0xFF30)                                                     */
#define SRSS                        ((SRSS_Type*) SRSS_BASE)                                                  /* 0x40260000    */

/** This structure is used to initialize a port of GPIO pins */
typedef struct {
    uint32_t out;           /**< Initial output data for the IO pins in the port */
    uint32_t intrMask;      /**< Interrupt enable mask for the port interrupt */
    uint32_t intrCfg;       /**< Port pin interrupt edge detection configuration */
    uint32_t cfg;           /**< Port pin drive modes and input buffer enable configuration */
    uint32_t cfgIn;         /**< Port pin input buffer configuration */
    uint32_t cfgOut;        /**< Port pin output buffer configuration */
    uint32_t cfgSIO;        /**< Port SIO pins configuration */
    uint32_t sel0Active;    /**< HSIOM selection for port pins 0,1,2,3 */
    uint32_t sel1Active;    /**< HSIOM selection for port pins 4,5,6,7 */
} cy_stc_gpio_prt_config_t;

#if defined(PSOC6_1M)
typedef struct {
  __IOM uint32_t OUT;                           /*!< 0x00000000 Port output data register                                      */
  __IOM uint32_t OUT_CLR;                       /*!< 0x00000004 Port output data set register                                  */
  __IOM uint32_t OUT_SET;                       /*!< 0x00000008 Port output data clear register                                */
  __IOM uint32_t OUT_INV;                       /*!< 0x0000000C Port output data invert register                               */
   __IM uint32_t IN;                            /*!< 0x00000010 Port input state register                                      */
  __IOM uint32_t INTR;                          /*!< 0x00000014 Port interrupt status register                                 */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000018 Port interrupt mask register                                   */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000001C Port interrupt masked status register                          */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000020 Port interrupt set register                                    */
  __IOM uint32_t INTR_CFG;                      /*!< 0x00000024 Port interrupt configuration register                          */
  __IOM uint32_t CFG;                           /*!< 0x00000028 Port configuration register                                    */
  __IOM uint32_t CFG_IN;                        /*!< 0x0000002C Port input buffer configuration register                       */
  __IOM uint32_t CFG_OUT;                       /*!< 0x00000030 Port output buffer configuration register                      */
  __IOM uint32_t CFG_SIO;                       /*!< 0x00000034 Port SIO configuration register                                */
   __IM uint32_t RESERVED;
  __IOM uint32_t CFG_IN_GPIO5V;                 /*!< 0x0000003C Port GPIO5V input buffer configuration register                */
   __IM uint32_t RESERVED1[16];
} GPIO_PRT_Type;                                /*!< Size = 64 (0x40)                                                          */

#elif defined(PSOC6_2M)

typedef struct {
  __IOM uint32_t OUT;                           /*!< 0x00000000 Port output data register */
  __IOM uint32_t OUT_CLR;                       /*!< 0x00000004 Port output data set register */
  __IOM uint32_t OUT_SET;                       /*!< 0x00000008 Port output data clear register */
  __IOM uint32_t OUT_INV;                       /*!< 0x0000000C Port output data invert register */
   __IM uint32_t IN;                            /*!< 0x00000010 Port input state register */
  __IOM uint32_t INTR;                          /*!< 0x00000014 Port interrupt status register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000018 Port interrupt mask register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000001C Port interrupt masked status register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000020 Port interrupt set register */
   __IM uint32_t RESERVED[7];
  __IOM uint32_t INTR_CFG;                      /*!< 0x00000040 Port interrupt configuration register */
  __IOM uint32_t CFG;                           /*!< 0x00000044 Port configuration register */
  __IOM uint32_t CFG_IN;                        /*!< 0x00000048 Port input buffer configuration register */
  __IOM uint32_t CFG_OUT;                       /*!< 0x0000004C Port output buffer configuration register */
  __IOM uint32_t CFG_SIO;                       /*!< 0x00000050 Port SIO configuration register */
   __IM uint32_t RESERVED1;
  __IOM uint32_t CFG_IN_AUTOLVL;                /*!< 0x00000058 Port GPIO5V input buffer configuration register */
   __IM uint32_t RESERVED2[9];
} GPIO_PRT_Type;                                /*!< Size = 128 (0x80) */
#else
  #error "Target device not defined!"
#endif
/**
  * \brief HSIOM port registers (HSIOM_PRT)
  */
typedef struct {
  __IOM uint32_t PORT_SEL0;                     /*!< 0x00000000 Port selection 0                                               */
  __IOM uint32_t PORT_SEL1;                     /*!< 0x00000004 Port selection 1                                               */
   __IM uint32_t RESERVED[2];
} HSIOM_PRT_Type;                               /*!< Size = 8 (0x8)                                                            */


#define GPIO                        ((GPIO_Type*) GPIO_BASE)                                                  /* 0x40320000    */
#define GPIO_PRT0                   ((GPIO_PRT_Type*) &GPIO->PRT[0])                                          /* 0x40320000    */
#define GPIO_PRT1                   ((GPIO_PRT_Type*) &GPIO->PRT[1])                                          /* 0x40320080    */
#define GPIO_PRT2                   ((GPIO_PRT_Type*) &GPIO->PRT[2])                                          /* 0x40320100    */
#define GPIO_PRT3                   ((GPIO_PRT_Type*) &GPIO->PRT[3])                                          /* 0x40320180    */
#define GPIO_PRT4                   ((GPIO_PRT_Type*) &GPIO->PRT[4])                                          /* 0x40320200    */
#define GPIO_PRT5                   ((GPIO_PRT_Type*) &GPIO->PRT[5])                                          /* 0x40320280    */
#define GPIO_PRT6                   ((GPIO_PRT_Type*) &GPIO->PRT[6])                                          /* 0x40320300    */
#define GPIO_PRT7                   ((GPIO_PRT_Type*) &GPIO->PRT[7])                                          /* 0x40320380    */
#define GPIO_PRT8                   ((GPIO_PRT_Type*) &GPIO->PRT[8])                                          /* 0x40320400    */
#define GPIO_PRT9                   ((GPIO_PRT_Type*) &GPIO->PRT[9])                                          /* 0x40320480    */
#define GPIO_PRT10                  ((GPIO_PRT_Type*) &GPIO->PRT[10])                                         /* 0x40320500    */
#define GPIO_PRT11                  ((GPIO_PRT_Type*) &GPIO->PRT[11])                                         /* 0x40320580    */
#define GPIO_PRT12                  ((GPIO_PRT_Type*) &GPIO->PRT[12])                                         /* 0x40320600    */
#define GPIO_PRT13                  ((GPIO_PRT_Type*) &GPIO->PRT[13])                                         /* 0x40320680    */
#define GPIO_PRT14                  ((GPIO_PRT_Type*) &GPIO->PRT[14])                                         /* 0x40320700    */

/**
  * \brief GPIO port control/configuration (GPIO)
  */
typedef struct {                                /*!< GPIO Structure                                                            */
        GPIO_PRT_Type PRT[128];                 /*!< 0x00000000 GPIO port registers                                            */
   __IM uint32_t INTR_CAUSE0;                   /*!< 0x00004000 Interrupt port cause register 0                                */
   __IM uint32_t INTR_CAUSE1;                   /*!< 0x00004004 Interrupt port cause register 1                                */
   __IM uint32_t INTR_CAUSE2;                   /*!< 0x00004008 Interrupt port cause register 2                                */
   __IM uint32_t INTR_CAUSE3;                   /*!< 0x0000400C Interrupt port cause register 3                                */
   __IM uint32_t VDD_ACTIVE;                    /*!< 0x00004010 Extern power supply detection register                         */
  __IOM uint32_t VDD_INTR;                      /*!< 0x00004014 Supply detection interrupt register                            */
  __IOM uint32_t VDD_INTR_MASK;                 /*!< 0x00004018 Supply detection interrupt mask register                       */
   __IM uint32_t VDD_INTR_MASKED;               /*!< 0x0000401C Supply detection interrupt masked register                     */
  __IOM uint32_t VDD_INTR_SET;                  /*!< 0x00004020 Supply detection interrupt set register                        */
} GPIO_Type;


#define HSIOM                       ((HSIOM_Type*) HSIOM_BASE)                                                /* 0x40310000    */
#define HSIOM_PRT0                  ((HSIOM_PRT_Type*) &HSIOM->PRT[0])                                        /* 0x40310000    */
#define HSIOM_PRT1                  ((HSIOM_PRT_Type*) &HSIOM->PRT[1])                                        /* 0x40310010    */
#define HSIOM_PRT2                  ((HSIOM_PRT_Type*) &HSIOM->PRT[2])                                        /* 0x40310020    */
#define HSIOM_PRT3                  ((HSIOM_PRT_Type*) &HSIOM->PRT[3])                                        /* 0x40310030    */
#define HSIOM_PRT4                  ((HSIOM_PRT_Type*) &HSIOM->PRT[4])                                        /* 0x40310040    */
#define HSIOM_PRT5                  ((HSIOM_PRT_Type*) &HSIOM->PRT[5])                                        /* 0x40310050    */
#define HSIOM_PRT6                  ((HSIOM_PRT_Type*) &HSIOM->PRT[6])                                        /* 0x40310060    */
#define HSIOM_PRT7                  ((HSIOM_PRT_Type*) &HSIOM->PRT[7])                                        /* 0x40310070    */
#define HSIOM_PRT8                  ((HSIOM_PRT_Type*) &HSIOM->PRT[8])                                        /* 0x40310080    */
#define HSIOM_PRT9                  ((HSIOM_PRT_Type*) &HSIOM->PRT[9])                                        /* 0x40310090    */
#define HSIOM_PRT10                 ((HSIOM_PRT_Type*) &HSIOM->PRT[10])                                       /* 0x403100A0    */
#define HSIOM_PRT11                 ((HSIOM_PRT_Type*) &HSIOM->PRT[11])                                       /* 0x403100B0    */
#define HSIOM_PRT12                 ((HSIOM_PRT_Type*) &HSIOM->PRT[12])                                       /* 0x403100C0    */
#define HSIOM_PRT13                 ((HSIOM_PRT_Type*) &HSIOM->PRT[13])                                       /* 0x403100D0    */
#define HSIOM_PRT14                 ((HSIOM_PRT_Type*) &HSIOM->PRT[14])                                       /* 0x403100E0    */

#define CY_PDL_DRV_ID(id)       ((uint32_t)((uint32_t)((id) & CY_PDL_MODULE_ID_Msk) << CY_PDL_MODULE_ID_Pos))

#define CY_PDL_STATUS_CODE_Pos  (0u)        /**< The module status code position in the status code */
#define CY_PDL_STATUS_TYPE_Pos  (16u)       /**< The status type position in the status code */
#define CY_PDL_MODULE_ID_Pos    (18u)       /**< The software module ID position in the status code */
#define CY_PDL_STATUS_INFO      (0UL << CY_PDL_STATUS_TYPE_Pos)    /**< Information status type */
#define CY_PDL_STATUS_WARNING   (1UL << CY_PDL_STATUS_TYPE_Pos)    /**< Warning status type */
#define CY_PDL_STATUS_ERROR     (2UL << CY_PDL_STATUS_TYPE_Pos)    /**< Error status type */
#define CY_PDL_MODULE_ID_Msk    (0x3FFFu)   /**< The software module ID mask */

/**
  * \brief Device (only used in XIP mode) (SMIF_DEVICE)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Control                                                        */
   __IM uint32_t RESERVED;
  __IOM uint32_t ADDR;                          /*!< 0x00000008 Device region base address                                     */
  __IOM uint32_t MASK;                          /*!< 0x0000000C Device region mask                                             */
   __IM uint32_t RESERVED1[4];
  __IOM uint32_t ADDR_CTL;                      /*!< 0x00000020 Address control                                                */
   __IM uint32_t RESERVED2[7];
  __IOM uint32_t RD_CMD_CTL;                    /*!< 0x00000040 Read command control                                           */
  __IOM uint32_t RD_ADDR_CTL;                   /*!< 0x00000044 Read address control                                           */
  __IOM uint32_t RD_MODE_CTL;                   /*!< 0x00000048 Read mode control                                              */
  __IOM uint32_t RD_DUMMY_CTL;                  /*!< 0x0000004C Read dummy control                                             */
  __IOM uint32_t RD_DATA_CTL;                   /*!< 0x00000050 Read data control                                              */
   __IM uint32_t RESERVED3[3];
  __IOM uint32_t WR_CMD_CTL;                    /*!< 0x00000060 Write command control                                          */
  __IOM uint32_t WR_ADDR_CTL;                   /*!< 0x00000064 Write address control                                          */
  __IOM uint32_t WR_MODE_CTL;                   /*!< 0x00000068 Write mode control                                             */
  __IOM uint32_t WR_DUMMY_CTL;                  /*!< 0x0000006C Write dummy control                                            */
  __IOM uint32_t WR_DATA_CTL;                   /*!< 0x00000070 Write data control                                             */
   __IM uint32_t RESERVED4[3];
} SMIF_DEVICE_Type;                             /*!< Size = 116 (0x74)                                                         */

/**
  * \brief Serial Memory Interface (SMIF)
  */
typedef struct {                                /*!< SMIF Structure                                                            */
  __IOM uint32_t CTL;                           /*!< 0x00000000 Control                                                        */
   __IM uint32_t STATUS;                        /*!< 0x00000004 Status                                                         */
   __IM uint32_t RESERVED[15];
   __IM uint32_t TX_CMD_FIFO_STATUS;            /*!< 0x00000044 Transmitter command FIFO status                                */
   __IM uint32_t RESERVED1[2];
   __OM uint32_t TX_CMD_FIFO_WR;                /*!< 0x00000050 Transmitter command FIFO write                                 */
   __IM uint32_t RESERVED2[11];
  __IOM uint32_t TX_DATA_FIFO_CTL;              /*!< 0x00000080 Transmitter data FIFO control                                  */
   __IM uint32_t TX_DATA_FIFO_STATUS;           /*!< 0x00000084 Transmitter data FIFO status                                   */
   __IM uint32_t RESERVED3[2];
   __OM uint32_t TX_DATA_FIFO_WR1;              /*!< 0x00000090 Transmitter data FIFO write                                    */
   __OM uint32_t TX_DATA_FIFO_WR2;              /*!< 0x00000094 Transmitter data FIFO write                                    */
   __OM uint32_t TX_DATA_FIFO_WR4;              /*!< 0x00000098 Transmitter data FIFO write                                    */
   __IM uint32_t RESERVED4[9];
  __IOM uint32_t RX_DATA_FIFO_CTL;              /*!< 0x000000C0 Receiver data FIFO control                                     */
   __IM uint32_t RX_DATA_FIFO_STATUS;           /*!< 0x000000C4 Receiver data FIFO status                                      */
   __IM uint32_t RESERVED5[2];
   __IM uint32_t RX_DATA_FIFO_RD1;              /*!< 0x000000D0 Receiver data FIFO read                                        */
   __IM uint32_t RX_DATA_FIFO_RD2;              /*!< 0x000000D4 Receiver data FIFO read                                        */
   __IM uint32_t RX_DATA_FIFO_RD4;              /*!< 0x000000D8 Receiver data FIFO read                                        */
   __IM uint32_t RESERVED6;
   __IM uint32_t RX_DATA_FIFO_RD1_SILENT;       /*!< 0x000000E0 Receiver data FIFO silent read                                 */
   __IM uint32_t RESERVED7[7];
  __IOM uint32_t SLOW_CA_CTL;                   /*!< 0x00000100 Slow cache control                                             */
   __IM uint32_t RESERVED8;
  __IOM uint32_t SLOW_CA_CMD;                   /*!< 0x00000108 Slow cache command                                             */
   __IM uint32_t RESERVED9[13];
   __IM uint32_t SLOW_CA_STATUS0;               /*!< 0x00000140 Slow cache status 0                                            */
   __IM uint32_t SLOW_CA_STATUS1;               /*!< 0x00000144 Slow cache status 1                                            */
   __IM uint32_t SLOW_CA_STATUS2;               /*!< 0x00000148 Slow cache status 2                                            */
   __IM uint32_t RESERVED10[13];
  __IOM uint32_t FAST_CA_CTL;                   /*!< 0x00000180 Fast cache control                                             */
   __IM uint32_t RESERVED11;
  __IOM uint32_t FAST_CA_CMD;                   /*!< 0x00000188 Fast cache command                                             */
   __IM uint32_t RESERVED12[13];
   __IM uint32_t FAST_CA_STATUS0;               /*!< 0x000001C0 Fast cache status 0                                            */
   __IM uint32_t FAST_CA_STATUS1;               /*!< 0x000001C4 Fast cache status 1                                            */
   __IM uint32_t FAST_CA_STATUS2;               /*!< 0x000001C8 Fast cache status 2                                            */
   __IM uint32_t RESERVED13[13];
  __IOM uint32_t CRYPTO_CMD;                    /*!< 0x00000200 Cryptography Command                                           */
   __IM uint32_t RESERVED14[7];
  __IOM uint32_t CRYPTO_INPUT0;                 /*!< 0x00000220 Cryptography input 0                                           */
  __IOM uint32_t CRYPTO_INPUT1;                 /*!< 0x00000224 Cryptography input 1                                           */
  __IOM uint32_t CRYPTO_INPUT2;                 /*!< 0x00000228 Cryptography input 2                                           */
  __IOM uint32_t CRYPTO_INPUT3;                 /*!< 0x0000022C Cryptography input 3                                           */
   __IM uint32_t RESERVED15[4];
   __OM uint32_t CRYPTO_KEY0;                   /*!< 0x00000240 Cryptography key 0                                             */
   __OM uint32_t CRYPTO_KEY1;                   /*!< 0x00000244 Cryptography key 1                                             */
   __OM uint32_t CRYPTO_KEY2;                   /*!< 0x00000248 Cryptography key 2                                             */
   __OM uint32_t CRYPTO_KEY3;                   /*!< 0x0000024C Cryptography key 3                                             */
   __IM uint32_t RESERVED16[4];
  __IOM uint32_t CRYPTO_OUTPUT0;                /*!< 0x00000260 Cryptography output 0                                          */
  __IOM uint32_t CRYPTO_OUTPUT1;                /*!< 0x00000264 Cryptography output 1                                          */
  __IOM uint32_t CRYPTO_OUTPUT2;                /*!< 0x00000268 Cryptography output 2                                          */
  __IOM uint32_t CRYPTO_OUTPUT3;                /*!< 0x0000026C Cryptography output 3                                          */
   __IM uint32_t RESERVED17[340];
  __IOM uint32_t INTR;                          /*!< 0x000007C0 Interrupt register                                             */
  __IOM uint32_t INTR_SET;                      /*!< 0x000007C4 Interrupt set register                                         */
  __IOM uint32_t INTR_MASK;                     /*!< 0x000007C8 Interrupt mask register                                        */
   __IM uint32_t INTR_MASKED;                   /*!< 0x000007CC Interrupt masked register                                      */
   __IM uint32_t RESERVED18[12];
        SMIF_DEVICE_Type DEVICE[4];             /*!< 0x00000800 Device (only used in XIP mode)                                 */
} SMIF_Type;                                    /*!< Size = 2560 (0xA00)                                                       */

#define SMIF_CTL_ENABLED_Pos              (31UL)                /*!< SMIF CTL: ENABLED (Bit 31)                                */
#define SMIF_CTL_ENABLED_Msk              (0x80000000UL)        /*!< SMIF CTL: ENABLED (Bitfield-Mask: 0x01)                   */
/* ====================================================  SMIF_DEVICE.CTL  ==================================================== */
#define SMIF_DEVICE_CTL_WR_EN_Pos         (0UL)                 /*!< SMIF_DEVICE CTL: WR_EN (Bit 0)                            */
#define SMIF_DEVICE_CTL_WR_EN_Msk         (0x1UL)               /*!< SMIF_DEVICE CTL: WR_EN (Bitfield-Mask: 0x01)              */
#define SMIF_DEVICE_CTL_CRYPTO_EN_Pos     (8UL)                 /*!< SMIF_DEVICE CTL: CRYPTO_EN (Bit 8)                        */
#define SMIF_DEVICE_CTL_CRYPTO_EN_Msk     (0x100UL)             /*!< SMIF_DEVICE CTL: CRYPTO_EN (Bitfield-Mask: 0x01)          */
#define SMIF_DEVICE_CTL_DATA_SEL_Pos      (16UL)                /*!< SMIF_DEVICE CTL: DATA_SEL (Bit 16)                        */
#define SMIF_DEVICE_CTL_DATA_SEL_Msk      (0x30000UL)           /*!< SMIF_DEVICE CTL: DATA_SEL (Bitfield-Mask: 0x03)           */
#define SMIF_DEVICE_CTL_ENABLED_Pos       (31UL)                /*!< SMIF_DEVICE CTL: ENABLED (Bit 31)                         */
#define SMIF_DEVICE_CTL_ENABLED_Msk       (0x80000000UL)        /*!< SMIF_DEVICE CTL: ENABLED (Bitfield-Mask: 0x01)            */
/* ===================================================  SMIF_DEVICE.ADDR  ==================================================== */
#define SMIF_DEVICE_ADDR_ADDR_Pos         (8UL)                 /*!< SMIF_DEVICE ADDR: ADDR (Bit 8)                            */
#define SMIF_DEVICE_ADDR_ADDR_Msk         (0xffffff00UL)        /*!< SMIF_DEVICE ADDR: ADDR (Bitfield-Mask: 0xffffff)          */
/* ===================================================  SMIF_DEVICE.MASK  ==================================================== */
#define SMIF_DEVICE_MASK_MASK_Pos         (8UL)                 /*!< SMIF_DEVICE MASK: MASK (Bit 8)                            */
#define SMIF_DEVICE_MASK_MASK_Msk         (0xffffff00UL)        /*!< SMIF_DEVICE MASK: MASK (Bitfield-Mask: 0xffffff)          */
/* =================================================  SMIF_DEVICE.ADDR_CTL  ================================================== */
#define SMIF_DEVICE_ADDR_CTL_SIZE2_Pos    (0UL)                 /*!< SMIF_DEVICE ADDR_CTL: SIZE2 (Bit 0)                       */
#define SMIF_DEVICE_ADDR_CTL_SIZE2_Msk    (0x3UL)               /*!< SMIF_DEVICE ADDR_CTL: SIZE2 (Bitfield-Mask: 0x03)         */
#define SMIF_DEVICE_ADDR_CTL_DIV2_Pos     (8UL)                 /*!< SMIF_DEVICE ADDR_CTL: DIV2 (Bit 8)                        */
#define SMIF_DEVICE_ADDR_CTL_DIV2_Msk     (0x100UL)             /*!< SMIF_DEVICE ADDR_CTL: DIV2 (Bitfield-Mask: 0x01)          */
/* ================================================  SMIF_DEVICE.RD_CMD_CTL  ================================================= */
#define SMIF_DEVICE_RD_CMD_CTL_CODE_Pos   (0UL)                 /*!< SMIF_DEVICE RD_CMD_CTL: CODE (Bit 0)                      */
#define SMIF_DEVICE_RD_CMD_CTL_CODE_Msk   (0xffUL)              /*!< SMIF_DEVICE RD_CMD_CTL: CODE (Bitfield-Mask: 0xff)        */
#define SMIF_DEVICE_RD_CMD_CTL_WIDTH_Pos  (16UL)                /*!< SMIF_DEVICE RD_CMD_CTL: WIDTH (Bit 16)                    */
#define SMIF_DEVICE_RD_CMD_CTL_WIDTH_Msk  (0x30000UL)           /*!< SMIF_DEVICE RD_CMD_CTL: WIDTH (Bitfield-Mask: 0x03)       */
#define SMIF_DEVICE_RD_CMD_CTL_PRESENT_Pos (31UL)               /*!< SMIF_DEVICE RD_CMD_CTL: PRESENT (Bit 31)                  */
#define SMIF_DEVICE_RD_CMD_CTL_PRESENT_Msk (0x80000000UL)       /*!< SMIF_DEVICE RD_CMD_CTL: PRESENT (Bitfield-Mask: 0x01)     */
/* ================================================  SMIF_DEVICE.RD_ADDR_CTL  ================================================ */
#define SMIF_DEVICE_RD_ADDR_CTL_WIDTH_Pos (16UL)                /*!< SMIF_DEVICE RD_ADDR_CTL: WIDTH (Bit 16)                   */
#define SMIF_DEVICE_RD_ADDR_CTL_WIDTH_Msk (0x30000UL)           /*!< SMIF_DEVICE RD_ADDR_CTL: WIDTH (Bitfield-Mask: 0x03)      */
/* ================================================  SMIF_DEVICE.RD_MODE_CTL  ================================================ */
#define SMIF_DEVICE_RD_MODE_CTL_CODE_Pos  (0UL)                 /*!< SMIF_DEVICE RD_MODE_CTL: CODE (Bit 0)                     */
#define SMIF_DEVICE_RD_MODE_CTL_CODE_Msk  (0xffUL)              /*!< SMIF_DEVICE RD_MODE_CTL: CODE (Bitfield-Mask: 0xff)       */
#define SMIF_DEVICE_RD_MODE_CTL_WIDTH_Pos (16UL)                /*!< SMIF_DEVICE RD_MODE_CTL: WIDTH (Bit 16)                   */
#define SMIF_DEVICE_RD_MODE_CTL_WIDTH_Msk (0x30000UL)           /*!< SMIF_DEVICE RD_MODE_CTL: WIDTH (Bitfield-Mask: 0x03)      */
#define SMIF_DEVICE_RD_MODE_CTL_PRESENT_Pos (31UL)              /*!< SMIF_DEVICE RD_MODE_CTL: PRESENT (Bit 31)                 */
#define SMIF_DEVICE_RD_MODE_CTL_PRESENT_Msk (0x80000000UL)      /*!< SMIF_DEVICE RD_MODE_CTL: PRESENT (Bitfield-Mask: 0x01)    */
/* ===============================================  SMIF_DEVICE.RD_DUMMY_CTL  ================================================ */
#define SMIF_DEVICE_RD_DUMMY_CTL_SIZE5_Pos (0UL)                /*!< SMIF_DEVICE RD_DUMMY_CTL: SIZE5 (Bit 0)                   */
#define SMIF_DEVICE_RD_DUMMY_CTL_SIZE5_Msk (0x1fUL)             /*!< SMIF_DEVICE RD_DUMMY_CTL: SIZE5 (Bitfield-Mask: 0x1f)     */
#define SMIF_DEVICE_RD_DUMMY_CTL_PRESENT_Pos (31UL)             /*!< SMIF_DEVICE RD_DUMMY_CTL: PRESENT (Bit 31)                */
#define SMIF_DEVICE_RD_DUMMY_CTL_PRESENT_Msk (0x80000000UL)     /*!< SMIF_DEVICE RD_DUMMY_CTL: PRESENT (Bitfield-Mask: 0x01)   */
/* ================================================  SMIF_DEVICE.RD_DATA_CTL  ================================================ */
#define SMIF_DEVICE_RD_DATA_CTL_WIDTH_Pos (16UL)                /*!< SMIF_DEVICE RD_DATA_CTL: WIDTH (Bit 16)                   */
#define SMIF_DEVICE_RD_DATA_CTL_WIDTH_Msk (0x30000UL)           /*!< SMIF_DEVICE RD_DATA_CTL: WIDTH (Bitfield-Mask: 0x03)      */
/* ================================================  SMIF_DEVICE.WR_CMD_CTL  ================================================= */
#define SMIF_DEVICE_WR_CMD_CTL_CODE_Pos   (0UL)                 /*!< SMIF_DEVICE WR_CMD_CTL: CODE (Bit 0)                      */
#define SMIF_DEVICE_WR_CMD_CTL_CODE_Msk   (0xffUL)              /*!< SMIF_DEVICE WR_CMD_CTL: CODE (Bitfield-Mask: 0xff)        */
#define SMIF_DEVICE_WR_CMD_CTL_WIDTH_Pos  (16UL)                /*!< SMIF_DEVICE WR_CMD_CTL: WIDTH (Bit 16)                    */
#define SMIF_DEVICE_WR_CMD_CTL_WIDTH_Msk  (0x30000UL)           /*!< SMIF_DEVICE WR_CMD_CTL: WIDTH (Bitfield-Mask: 0x03)       */
#define SMIF_DEVICE_WR_CMD_CTL_PRESENT_Pos (31UL)               /*!< SMIF_DEVICE WR_CMD_CTL: PRESENT (Bit 31)                  */
#define SMIF_DEVICE_WR_CMD_CTL_PRESENT_Msk (0x80000000UL)       /*!< SMIF_DEVICE WR_CMD_CTL: PRESENT (Bitfield-Mask: 0x01)     */
/* ================================================  SMIF_DEVICE.WR_ADDR_CTL  ================================================ */
#define SMIF_DEVICE_WR_ADDR_CTL_WIDTH_Pos (16UL)                /*!< SMIF_DEVICE WR_ADDR_CTL: WIDTH (Bit 16)                   */
#define SMIF_DEVICE_WR_ADDR_CTL_WIDTH_Msk (0x30000UL)           /*!< SMIF_DEVICE WR_ADDR_CTL: WIDTH (Bitfield-Mask: 0x03)      */
/* ================================================  SMIF_DEVICE.WR_MODE_CTL  ================================================ */
#define SMIF_DEVICE_WR_MODE_CTL_CODE_Pos  (0UL)                 /*!< SMIF_DEVICE WR_MODE_CTL: CODE (Bit 0)                     */
#define SMIF_DEVICE_WR_MODE_CTL_CODE_Msk  (0xffUL)              /*!< SMIF_DEVICE WR_MODE_CTL: CODE (Bitfield-Mask: 0xff)       */
#define SMIF_DEVICE_WR_MODE_CTL_WIDTH_Pos (16UL)                /*!< SMIF_DEVICE WR_MODE_CTL: WIDTH (Bit 16)                   */
#define SMIF_DEVICE_WR_MODE_CTL_WIDTH_Msk (0x30000UL)           /*!< SMIF_DEVICE WR_MODE_CTL: WIDTH (Bitfield-Mask: 0x03)      */
#define SMIF_DEVICE_WR_MODE_CTL_PRESENT_Pos (31UL)              /*!< SMIF_DEVICE WR_MODE_CTL: PRESENT (Bit 31)                 */
#define SMIF_DEVICE_WR_MODE_CTL_PRESENT_Msk (0x80000000UL)      /*!< SMIF_DEVICE WR_MODE_CTL: PRESENT (Bitfield-Mask: 0x01)    */
/* ===============================================  SMIF_DEVICE.WR_DUMMY_CTL  ================================================ */
#define SMIF_DEVICE_WR_DUMMY_CTL_SIZE5_Pos (0UL)                /*!< SMIF_DEVICE WR_DUMMY_CTL: SIZE5 (Bit 0)                   */
#define SMIF_DEVICE_WR_DUMMY_CTL_SIZE5_Msk (0x1fUL)             /*!< SMIF_DEVICE WR_DUMMY_CTL: SIZE5 (Bitfield-Mask: 0x1f)     */
#define SMIF_DEVICE_WR_DUMMY_CTL_PRESENT_Pos (31UL)             /*!< SMIF_DEVICE WR_DUMMY_CTL: PRESENT (Bit 31)                */
#define SMIF_DEVICE_WR_DUMMY_CTL_PRESENT_Msk (0x80000000UL)     /*!< SMIF_DEVICE WR_DUMMY_CTL: PRESENT (Bitfield-Mask: 0x01)   */
/* ================================================  SMIF_DEVICE.WR_DATA_CTL  ================================================ */
#define SMIF_DEVICE_WR_DATA_CTL_WIDTH_Pos (16UL)                /*!< SMIF_DEVICE WR_DATA_CTL: WIDTH (Bit 16)                   */
#define SMIF_DEVICE_WR_DATA_CTL_WIDTH_Msk (0x30000UL)           /*!< SMIF_DEVICE WR_DATA_CTL: WIDTH (Bitfield-Mask: 0x03)      */


/* =======================================================  SMIF.CTL  ======================================================== */
#define SMIF_CTL_XIP_MODE_Pos             (0UL)                 /*!< SMIF CTL: XIP_MODE (Bit 0)                                */
#define SMIF_CTL_XIP_MODE_Msk             (0x1UL)               /*!< SMIF CTL: XIP_MODE (Bitfield-Mask: 0x01)                  */
#define SMIF_CTL_CLOCK_IF_RX_SEL_Pos      (12UL)                /*!< SMIF CTL: CLOCK_IF_RX_SEL (Bit 12)                        */
#define SMIF_CTL_CLOCK_IF_RX_SEL_Msk      (0x3000UL)            /*!< SMIF CTL: CLOCK_IF_RX_SEL (Bitfield-Mask: 0x03)           */
#define SMIF_CTL_DESELECT_DELAY_Pos       (16UL)                /*!< SMIF CTL: DESELECT_DELAY (Bit 16)                         */
#define SMIF_CTL_DESELECT_DELAY_Msk       (0x70000UL)           /*!< SMIF CTL: DESELECT_DELAY (Bitfield-Mask: 0x07)            */
#define SMIF_CTL_BLOCK_Pos                (24UL)                /*!< SMIF CTL: BLOCK (Bit 24)                                  */
#define SMIF_CTL_BLOCK_Msk                (0x1000000UL)         /*!< SMIF CTL: BLOCK (Bitfield-Mask: 0x01)                     */
#define SMIF_CTL_ENABLED_Pos              (31UL)                /*!< SMIF CTL: ENABLED (Bit 31)                                */
#define SMIF_CTL_ENABLED_Msk              (0x80000000UL)        /*!< SMIF CTL: ENABLED (Bitfield-Mask: 0x01)                   */
/* ======================================================  SMIF.STATUS  ====================================================== */
#define SMIF_STATUS_BUSY_Pos              (31UL)                /*!< SMIF STATUS: BUSY (Bit 31)                                */
#define SMIF_STATUS_BUSY_Msk              (0x80000000UL)        /*!< SMIF STATUS: BUSY (Bitfield-Mask: 0x01)                   */
/* ================================================  SMIF.TX_CMD_FIFO_STATUS  ================================================ */
#define SMIF_TX_CMD_FIFO_STATUS_USED3_Pos (0UL)                 /*!< SMIF TX_CMD_FIFO_STATUS: USED3 (Bit 0)                    */
#define SMIF_TX_CMD_FIFO_STATUS_USED3_Msk (0x7UL)               /*!< SMIF TX_CMD_FIFO_STATUS: USED3 (Bitfield-Mask: 0x07)      */
/* ==================================================  SMIF.TX_CMD_FIFO_WR  ================================================== */
#define SMIF_TX_CMD_FIFO_WR_DATA20_Pos    (0UL)                 /*!< SMIF TX_CMD_FIFO_WR: DATA20 (Bit 0)                       */
#define SMIF_TX_CMD_FIFO_WR_DATA20_Msk    (0xfffffUL)           /*!< SMIF TX_CMD_FIFO_WR: DATA20 (Bitfield-Mask: 0xfffff)      */
/* =================================================  SMIF.TX_DATA_FIFO_CTL  ================================================= */
#define SMIF_TX_DATA_FIFO_CTL_TRIGGER_LEVEL_Pos (0UL)           /*!< SMIF TX_DATA_FIFO_CTL: TRIGGER_LEVEL (Bit 0)              */
#define SMIF_TX_DATA_FIFO_CTL_TRIGGER_LEVEL_Msk (0x7UL)         /*!< SMIF TX_DATA_FIFO_CTL: TRIGGER_LEVEL (Bitfield-Mask: 0x07)*/
/* ===============================================  SMIF.TX_DATA_FIFO_STATUS  ================================================ */
#define SMIF_TX_DATA_FIFO_STATUS_USED4_Pos (0UL)                /*!< SMIF TX_DATA_FIFO_STATUS: USED4 (Bit 0)                   */
#define SMIF_TX_DATA_FIFO_STATUS_USED4_Msk (0xfUL)              /*!< SMIF TX_DATA_FIFO_STATUS: USED4 (Bitfield-Mask: 0x0f)     */
/* =================================================  SMIF.TX_DATA_FIFO_WR1  ================================================= */
#define SMIF_TX_DATA_FIFO_WR1_DATA0_Pos   (0UL)                 /*!< SMIF TX_DATA_FIFO_WR1: DATA0 (Bit 0)                      */
#define SMIF_TX_DATA_FIFO_WR1_DATA0_Msk   (0xffUL)              /*!< SMIF TX_DATA_FIFO_WR1: DATA0 (Bitfield-Mask: 0xff)        */
/* =================================================  SMIF.TX_DATA_FIFO_WR2  ================================================= */
#define SMIF_TX_DATA_FIFO_WR2_DATA0_Pos   (0UL)                 /*!< SMIF TX_DATA_FIFO_WR2: DATA0 (Bit 0)                      */
#define SMIF_TX_DATA_FIFO_WR2_DATA0_Msk   (0xffUL)              /*!< SMIF TX_DATA_FIFO_WR2: DATA0 (Bitfield-Mask: 0xff)        */
#define SMIF_TX_DATA_FIFO_WR2_DATA1_Pos   (8UL)                 /*!< SMIF TX_DATA_FIFO_WR2: DATA1 (Bit 8)                      */
#define SMIF_TX_DATA_FIFO_WR2_DATA1_Msk   (0xff00UL)            /*!< SMIF TX_DATA_FIFO_WR2: DATA1 (Bitfield-Mask: 0xff)        */
/* =================================================  SMIF.TX_DATA_FIFO_WR4  ================================================= */
#define SMIF_TX_DATA_FIFO_WR4_DATA0_Pos   (0UL)                 /*!< SMIF TX_DATA_FIFO_WR4: DATA0 (Bit 0)                      */
#define SMIF_TX_DATA_FIFO_WR4_DATA0_Msk   (0xffUL)              /*!< SMIF TX_DATA_FIFO_WR4: DATA0 (Bitfield-Mask: 0xff)        */
#define SMIF_TX_DATA_FIFO_WR4_DATA1_Pos   (8UL)                 /*!< SMIF TX_DATA_FIFO_WR4: DATA1 (Bit 8)                      */
#define SMIF_TX_DATA_FIFO_WR4_DATA1_Msk   (0xff00UL)            /*!< SMIF TX_DATA_FIFO_WR4: DATA1 (Bitfield-Mask: 0xff)        */
#define SMIF_TX_DATA_FIFO_WR4_DATA2_Pos   (16UL)                /*!< SMIF TX_DATA_FIFO_WR4: DATA2 (Bit 16)                     */
#define SMIF_TX_DATA_FIFO_WR4_DATA2_Msk   (0xff0000UL)          /*!< SMIF TX_DATA_FIFO_WR4: DATA2 (Bitfield-Mask: 0xff)        */
#define SMIF_TX_DATA_FIFO_WR4_DATA3_Pos   (24UL)                /*!< SMIF TX_DATA_FIFO_WR4: DATA3 (Bit 24)                     */
#define SMIF_TX_DATA_FIFO_WR4_DATA3_Msk   (0xff000000UL)        /*!< SMIF TX_DATA_FIFO_WR4: DATA3 (Bitfield-Mask: 0xff)        */
/* =================================================  SMIF.RX_DATA_FIFO_CTL  ================================================= */
#define SMIF_RX_DATA_FIFO_CTL_TRIGGER_LEVEL_Pos (0UL)           /*!< SMIF RX_DATA_FIFO_CTL: TRIGGER_LEVEL (Bit 0)              */
#define SMIF_RX_DATA_FIFO_CTL_TRIGGER_LEVEL_Msk (0x7UL)         /*!< SMIF RX_DATA_FIFO_CTL: TRIGGER_LEVEL (Bitfield-Mask: 0x07)*/
/* ===============================================  SMIF.RX_DATA_FIFO_STATUS  ================================================ */
#define SMIF_RX_DATA_FIFO_STATUS_USED4_Pos (0UL)                /*!< SMIF RX_DATA_FIFO_STATUS: USED4 (Bit 0)                   */
#define SMIF_RX_DATA_FIFO_STATUS_USED4_Msk (0xfUL)              /*!< SMIF RX_DATA_FIFO_STATUS: USED4 (Bitfield-Mask: 0x0f)     */
/* =================================================  SMIF.RX_DATA_FIFO_RD1  ================================================= */
#define SMIF_RX_DATA_FIFO_RD1_DATA0_Pos   (0UL)                 /*!< SMIF RX_DATA_FIFO_RD1: DATA0 (Bit 0)                      */
#define SMIF_RX_DATA_FIFO_RD1_DATA0_Msk   (0xffUL)              /*!< SMIF RX_DATA_FIFO_RD1: DATA0 (Bitfield-Mask: 0xff)        */
/* =================================================  SMIF.RX_DATA_FIFO_RD2  ================================================= */
#define SMIF_RX_DATA_FIFO_RD2_DATA0_Pos   (0UL)                 /*!< SMIF RX_DATA_FIFO_RD2: DATA0 (Bit 0)                      */
#define SMIF_RX_DATA_FIFO_RD2_DATA0_Msk   (0xffUL)              /*!< SMIF RX_DATA_FIFO_RD2: DATA0 (Bitfield-Mask: 0xff)        */
#define SMIF_RX_DATA_FIFO_RD2_DATA1_Pos   (8UL)                 /*!< SMIF RX_DATA_FIFO_RD2: DATA1 (Bit 8)                      */
#define SMIF_RX_DATA_FIFO_RD2_DATA1_Msk   (0xff00UL)            /*!< SMIF RX_DATA_FIFO_RD2: DATA1 (Bitfield-Mask: 0xff)        */
/* =================================================  SMIF.RX_DATA_FIFO_RD4  ================================================= */
#define SMIF_RX_DATA_FIFO_RD4_DATA0_Pos   (0UL)                 /*!< SMIF RX_DATA_FIFO_RD4: DATA0 (Bit 0)                      */
#define SMIF_RX_DATA_FIFO_RD4_DATA0_Msk   (0xffUL)              /*!< SMIF RX_DATA_FIFO_RD4: DATA0 (Bitfield-Mask: 0xff)        */
#define SMIF_RX_DATA_FIFO_RD4_DATA1_Pos   (8UL)                 /*!< SMIF RX_DATA_FIFO_RD4: DATA1 (Bit 8)                      */
#define SMIF_RX_DATA_FIFO_RD4_DATA1_Msk   (0xff00UL)            /*!< SMIF RX_DATA_FIFO_RD4: DATA1 (Bitfield-Mask: 0xff)        */
#define SMIF_RX_DATA_FIFO_RD4_DATA2_Pos   (16UL)                /*!< SMIF RX_DATA_FIFO_RD4: DATA2 (Bit 16)                     */
#define SMIF_RX_DATA_FIFO_RD4_DATA2_Msk   (0xff0000UL)          /*!< SMIF RX_DATA_FIFO_RD4: DATA2 (Bitfield-Mask: 0xff)        */
#define SMIF_RX_DATA_FIFO_RD4_DATA3_Pos   (24UL)                /*!< SMIF RX_DATA_FIFO_RD4: DATA3 (Bit 24)                     */
#define SMIF_RX_DATA_FIFO_RD4_DATA3_Msk   (0xff000000UL)        /*!< SMIF RX_DATA_FIFO_RD4: DATA3 (Bitfield-Mask: 0xff)        */
/* =============================================  SMIF.RX_DATA_FIFO_RD1_SILENT  ============================================== */
#define SMIF_RX_DATA_FIFO_RD1_SILENT_DATA0_Pos (0UL)            /*!< SMIF RX_DATA_FIFO_RD1_SILENT: DATA0 (Bit 0)               */
#define SMIF_RX_DATA_FIFO_RD1_SILENT_DATA0_Msk (0xffUL)         /*!< SMIF RX_DATA_FIFO_RD1_SILENT: DATA0 (Bitfield-Mask: 0xff) */
/* ===================================================  SMIF.SLOW_CA_CTL  ==================================================== */
#define SMIF_SLOW_CA_CTL_WAY_Pos          (16UL)                /*!< SMIF SLOW_CA_CTL: WAY (Bit 16)                            */
#define SMIF_SLOW_CA_CTL_WAY_Msk          (0x30000UL)           /*!< SMIF SLOW_CA_CTL: WAY (Bitfield-Mask: 0x03)               */
#define SMIF_SLOW_CA_CTL_SET_ADDR_Pos     (24UL)                /*!< SMIF SLOW_CA_CTL: SET_ADDR (Bit 24)                       */
#define SMIF_SLOW_CA_CTL_SET_ADDR_Msk     (0x3000000UL)         /*!< SMIF SLOW_CA_CTL: SET_ADDR (Bitfield-Mask: 0x03)          */
#define SMIF_SLOW_CA_CTL_PREF_EN_Pos      (30UL)                /*!< SMIF SLOW_CA_CTL: PREF_EN (Bit 30)                        */
#define SMIF_SLOW_CA_CTL_PREF_EN_Msk      (0x40000000UL)        /*!< SMIF SLOW_CA_CTL: PREF_EN (Bitfield-Mask: 0x01)           */
#define SMIF_SLOW_CA_CTL_ENABLED_Pos      (31UL)                /*!< SMIF SLOW_CA_CTL: ENABLED (Bit 31)                        */
#define SMIF_SLOW_CA_CTL_ENABLED_Msk      (0x80000000UL)        /*!< SMIF SLOW_CA_CTL: ENABLED (Bitfield-Mask: 0x01)           */
/* ===================================================  SMIF.SLOW_CA_CMD  ==================================================== */
#define SMIF_SLOW_CA_CMD_INV_Pos          (0UL)                 /*!< SMIF SLOW_CA_CMD: INV (Bit 0)                             */
#define SMIF_SLOW_CA_CMD_INV_Msk          (0x1UL)               /*!< SMIF SLOW_CA_CMD: INV (Bitfield-Mask: 0x01)               */
/* =================================================  SMIF.SLOW_CA_STATUS0  ================================================== */
#define SMIF_SLOW_CA_STATUS0_VALID16_Pos  (0UL)                 /*!< SMIF SLOW_CA_STATUS0: VALID16 (Bit 0)                     */
#define SMIF_SLOW_CA_STATUS0_VALID16_Msk  (0xffffUL)            /*!< SMIF SLOW_CA_STATUS0: VALID16 (Bitfield-Mask: 0xffff)     */
/* =================================================  SMIF.SLOW_CA_STATUS1  ================================================== */
#define SMIF_SLOW_CA_STATUS1_TAG_Pos      (0UL)                 /*!< SMIF SLOW_CA_STATUS1: TAG (Bit 0)                         */
#define SMIF_SLOW_CA_STATUS1_TAG_Msk      (0xffffffffUL)        /*!< SMIF SLOW_CA_STATUS1: TAG (Bitfield-Mask: 0xffffffff)     */
/* =================================================  SMIF.SLOW_CA_STATUS2  ================================================== */
#define SMIF_SLOW_CA_STATUS2_LRU_Pos      (0UL)                 /*!< SMIF SLOW_CA_STATUS2: LRU (Bit 0)                         */
#define SMIF_SLOW_CA_STATUS2_LRU_Msk      (0x3fUL)              /*!< SMIF SLOW_CA_STATUS2: LRU (Bitfield-Mask: 0x3f)           */
/* ===================================================  SMIF.FAST_CA_CTL  ==================================================== */
#define SMIF_FAST_CA_CTL_WAY_Pos          (16UL)                /*!< SMIF FAST_CA_CTL: WAY (Bit 16)                            */
#define SMIF_FAST_CA_CTL_WAY_Msk          (0x30000UL)           /*!< SMIF FAST_CA_CTL: WAY (Bitfield-Mask: 0x03)               */
#define SMIF_FAST_CA_CTL_SET_ADDR_Pos     (24UL)                /*!< SMIF FAST_CA_CTL: SET_ADDR (Bit 24)                       */
#define SMIF_FAST_CA_CTL_SET_ADDR_Msk     (0x3000000UL)         /*!< SMIF FAST_CA_CTL: SET_ADDR (Bitfield-Mask: 0x03)          */
#define SMIF_FAST_CA_CTL_PREF_EN_Pos      (30UL)                /*!< SMIF FAST_CA_CTL: PREF_EN (Bit 30)                        */
#define SMIF_FAST_CA_CTL_PREF_EN_Msk      (0x40000000UL)        /*!< SMIF FAST_CA_CTL: PREF_EN (Bitfield-Mask: 0x01)           */
#define SMIF_FAST_CA_CTL_ENABLED_Pos      (31UL)                /*!< SMIF FAST_CA_CTL: ENABLED (Bit 31)                        */
#define SMIF_FAST_CA_CTL_ENABLED_Msk      (0x80000000UL)        /*!< SMIF FAST_CA_CTL: ENABLED (Bitfield-Mask: 0x01)           */
/* ===================================================  SMIF.FAST_CA_CMD  ==================================================== */
#define SMIF_FAST_CA_CMD_INV_Pos          (0UL)                 /*!< SMIF FAST_CA_CMD: INV (Bit 0)                             */
#define SMIF_FAST_CA_CMD_INV_Msk          (0x1UL)               /*!< SMIF FAST_CA_CMD: INV (Bitfield-Mask: 0x01)               */
/* =================================================  SMIF.FAST_CA_STATUS0  ================================================== */
#define SMIF_FAST_CA_STATUS0_VALID16_Pos  (0UL)                 /*!< SMIF FAST_CA_STATUS0: VALID16 (Bit 0)                     */
#define SMIF_FAST_CA_STATUS0_VALID16_Msk  (0xffffUL)            /*!< SMIF FAST_CA_STATUS0: VALID16 (Bitfield-Mask: 0xffff)     */
/* =================================================  SMIF.FAST_CA_STATUS1  ================================================== */
#define SMIF_FAST_CA_STATUS1_TAG_Pos      (0UL)                 /*!< SMIF FAST_CA_STATUS1: TAG (Bit 0)                         */
#define SMIF_FAST_CA_STATUS1_TAG_Msk      (0xffffffffUL)        /*!< SMIF FAST_CA_STATUS1: TAG (Bitfield-Mask: 0xffffffff)     */
/* =================================================  SMIF.FAST_CA_STATUS2  ================================================== */
#define SMIF_FAST_CA_STATUS2_LRU_Pos      (0UL)                 /*!< SMIF FAST_CA_STATUS2: LRU (Bit 0)                         */
#define SMIF_FAST_CA_STATUS2_LRU_Msk      (0x3fUL)              /*!< SMIF FAST_CA_STATUS2: LRU (Bitfield-Mask: 0x3f)           */
/* ====================================================  SMIF.CRYPTO_CMD  ==================================================== */
#define SMIF_CRYPTO_CMD_START_Pos         (0UL)                 /*!< SMIF CRYPTO_CMD: START (Bit 0)                            */
#define SMIF_CRYPTO_CMD_START_Msk         (0x1UL)               /*!< SMIF CRYPTO_CMD: START (Bitfield-Mask: 0x01)              */
/* ==================================================  SMIF.CRYPTO_INPUT0  =================================================== */
#define SMIF_CRYPTO_INPUT0_INPUT_Pos      (0UL)                 /*!< SMIF CRYPTO_INPUT0: INPUT (Bit 0)                         */
#define SMIF_CRYPTO_INPUT0_INPUT_Msk      (0xffffffffUL)        /*!< SMIF CRYPTO_INPUT0: INPUT (Bitfield-Mask: 0xffffffff)     */
/* ==================================================  SMIF.CRYPTO_INPUT1  =================================================== */
#define SMIF_CRYPTO_INPUT1_INPUT_Pos      (0UL)                 /*!< SMIF CRYPTO_INPUT1: INPUT (Bit 0)                         */
#define SMIF_CRYPTO_INPUT1_INPUT_Msk      (0xffffffffUL)        /*!< SMIF CRYPTO_INPUT1: INPUT (Bitfield-Mask: 0xffffffff)     */
/* ==================================================  SMIF.CRYPTO_INPUT2  =================================================== */
#define SMIF_CRYPTO_INPUT2_INPUT_Pos      (0UL)                 /*!< SMIF CRYPTO_INPUT2: INPUT (Bit 0)                         */
#define SMIF_CRYPTO_INPUT2_INPUT_Msk      (0xffffffffUL)        /*!< SMIF CRYPTO_INPUT2: INPUT (Bitfield-Mask: 0xffffffff)     */
/* ==================================================  SMIF.CRYPTO_INPUT3  =================================================== */
#define SMIF_CRYPTO_INPUT3_INPUT_Pos      (0UL)                 /*!< SMIF CRYPTO_INPUT3: INPUT (Bit 0)                         */
#define SMIF_CRYPTO_INPUT3_INPUT_Msk      (0xffffffffUL)        /*!< SMIF CRYPTO_INPUT3: INPUT (Bitfield-Mask: 0xffffffff)     */
/* ===================================================  SMIF.CRYPTO_KEY0  ==================================================== */
#define SMIF_CRYPTO_KEY0_KEY_Pos          (0UL)                 /*!< SMIF CRYPTO_KEY0: KEY (Bit 0)                             */
#define SMIF_CRYPTO_KEY0_KEY_Msk          (0xffffffffUL)        /*!< SMIF CRYPTO_KEY0: KEY (Bitfield-Mask: 0xffffffff)         */
/* ===================================================  SMIF.CRYPTO_KEY1  ==================================================== */
#define SMIF_CRYPTO_KEY1_KEY_Pos          (0UL)                 /*!< SMIF CRYPTO_KEY1: KEY (Bit 0)                             */
#define SMIF_CRYPTO_KEY1_KEY_Msk          (0xffffffffUL)        /*!< SMIF CRYPTO_KEY1: KEY (Bitfield-Mask: 0xffffffff)         */
/* ===================================================  SMIF.CRYPTO_KEY2  ==================================================== */
#define SMIF_CRYPTO_KEY2_KEY_Pos          (0UL)                 /*!< SMIF CRYPTO_KEY2: KEY (Bit 0)                             */
#define SMIF_CRYPTO_KEY2_KEY_Msk          (0xffffffffUL)        /*!< SMIF CRYPTO_KEY2: KEY (Bitfield-Mask: 0xffffffff)         */
/* ===================================================  SMIF.CRYPTO_KEY3  ==================================================== */
#define SMIF_CRYPTO_KEY3_KEY_Pos          (0UL)                 /*!< SMIF CRYPTO_KEY3: KEY (Bit 0)                             */
#define SMIF_CRYPTO_KEY3_KEY_Msk          (0xffffffffUL)        /*!< SMIF CRYPTO_KEY3: KEY (Bitfield-Mask: 0xffffffff)         */
/* ==================================================  SMIF.CRYPTO_OUTPUT0  ================================================== */
#define SMIF_CRYPTO_OUTPUT0_OUTPUT_Pos    (0UL)                 /*!< SMIF CRYPTO_OUTPUT0: OUTPUT (Bit 0)                       */
#define SMIF_CRYPTO_OUTPUT0_OUTPUT_Msk    (0xffffffffUL)        /*!< SMIF CRYPTO_OUTPUT0: OUTPUT (Bitfield-Mask: 0xffffffff)   */
/* ==================================================  SMIF.CRYPTO_OUTPUT1  ================================================== */
#define SMIF_CRYPTO_OUTPUT1_OUTPUT_Pos    (0UL)                 /*!< SMIF CRYPTO_OUTPUT1: OUTPUT (Bit 0)                       */
#define SMIF_CRYPTO_OUTPUT1_OUTPUT_Msk    (0xffffffffUL)        /*!< SMIF CRYPTO_OUTPUT1: OUTPUT (Bitfield-Mask: 0xffffffff)   */
/* ==================================================  SMIF.CRYPTO_OUTPUT2  ================================================== */
#define SMIF_CRYPTO_OUTPUT2_OUTPUT_Pos    (0UL)                 /*!< SMIF CRYPTO_OUTPUT2: OUTPUT (Bit 0)                       */
#define SMIF_CRYPTO_OUTPUT2_OUTPUT_Msk    (0xffffffffUL)        /*!< SMIF CRYPTO_OUTPUT2: OUTPUT (Bitfield-Mask: 0xffffffff)   */
/* ==================================================  SMIF.CRYPTO_OUTPUT3  ================================================== */
#define SMIF_CRYPTO_OUTPUT3_OUTPUT_Pos    (0UL)                 /*!< SMIF CRYPTO_OUTPUT3: OUTPUT (Bit 0)                       */
#define SMIF_CRYPTO_OUTPUT3_OUTPUT_Msk    (0xffffffffUL)        /*!< SMIF CRYPTO_OUTPUT3: OUTPUT (Bitfield-Mask: 0xffffffff)   */
/* =======================================================  SMIF.INTR  ======================================================= */
#define SMIF_INTR_TR_TX_REQ_Pos           (0UL)                 /*!< SMIF INTR: TR_TX_REQ (Bit 0)                              */
#define SMIF_INTR_TR_TX_REQ_Msk           (0x1UL)               /*!< SMIF INTR: TR_TX_REQ (Bitfield-Mask: 0x01)                */
#define SMIF_INTR_TR_RX_REQ_Pos           (1UL)                 /*!< SMIF INTR: TR_RX_REQ (Bit 1)                              */
#define SMIF_INTR_TR_RX_REQ_Msk           (0x2UL)               /*!< SMIF INTR: TR_RX_REQ (Bitfield-Mask: 0x01)                */
#define SMIF_INTR_XIP_ALIGNMENT_ERROR_Pos (2UL)                 /*!< SMIF INTR: XIP_ALIGNMENT_ERROR (Bit 2)                    */
#define SMIF_INTR_XIP_ALIGNMENT_ERROR_Msk (0x4UL)               /*!< SMIF INTR: XIP_ALIGNMENT_ERROR (Bitfield-Mask: 0x01)      */
#define SMIF_INTR_TX_CMD_FIFO_OVERFLOW_Pos (3UL)                /*!< SMIF INTR: TX_CMD_FIFO_OVERFLOW (Bit 3)                   */
#define SMIF_INTR_TX_CMD_FIFO_OVERFLOW_Msk (0x8UL)              /*!< SMIF INTR: TX_CMD_FIFO_OVERFLOW (Bitfield-Mask: 0x01)     */
#define SMIF_INTR_TX_DATA_FIFO_OVERFLOW_Pos (4UL)               /*!< SMIF INTR: TX_DATA_FIFO_OVERFLOW (Bit 4)                  */
#define SMIF_INTR_TX_DATA_FIFO_OVERFLOW_Msk (0x10UL)            /*!< SMIF INTR: TX_DATA_FIFO_OVERFLOW (Bitfield-Mask: 0x01)    */
#define SMIF_INTR_RX_DATA_FIFO_UNDERFLOW_Pos (5UL)              /*!< SMIF INTR: RX_DATA_FIFO_UNDERFLOW (Bit 5)                 */
#define SMIF_INTR_RX_DATA_FIFO_UNDERFLOW_Msk (0x20UL)           /*!< SMIF INTR: RX_DATA_FIFO_UNDERFLOW (Bitfield-Mask: 0x01)   */
/* =====================================================  SMIF.INTR_SET  ===================================================== */
#define SMIF_INTR_SET_TR_TX_REQ_Pos       (0UL)                 /*!< SMIF INTR_SET: TR_TX_REQ (Bit 0)                          */
#define SMIF_INTR_SET_TR_TX_REQ_Msk       (0x1UL)               /*!< SMIF INTR_SET: TR_TX_REQ (Bitfield-Mask: 0x01)            */
#define SMIF_INTR_SET_TR_RX_REQ_Pos       (1UL)                 /*!< SMIF INTR_SET: TR_RX_REQ (Bit 1)                          */
#define SMIF_INTR_SET_TR_RX_REQ_Msk       (0x2UL)               /*!< SMIF INTR_SET: TR_RX_REQ (Bitfield-Mask: 0x01)            */
#define SMIF_INTR_SET_XIP_ALIGNMENT_ERROR_Pos (2UL)             /*!< SMIF INTR_SET: XIP_ALIGNMENT_ERROR (Bit 2)                */
#define SMIF_INTR_SET_XIP_ALIGNMENT_ERROR_Msk (0x4UL)           /*!< SMIF INTR_SET: XIP_ALIGNMENT_ERROR (Bitfield-Mask: 0x01)  */
#define SMIF_INTR_SET_TX_CMD_FIFO_OVERFLOW_Pos (3UL)            /*!< SMIF INTR_SET: TX_CMD_FIFO_OVERFLOW (Bit 3)               */
#define SMIF_INTR_SET_TX_CMD_FIFO_OVERFLOW_Msk (0x8UL)          /*!< SMIF INTR_SET: TX_CMD_FIFO_OVERFLOW (Bitfield-Mask: 0x01) */
#define SMIF_INTR_SET_TX_DATA_FIFO_OVERFLOW_Pos (4UL)           /*!< SMIF INTR_SET: TX_DATA_FIFO_OVERFLOW (Bit 4)              */
#define SMIF_INTR_SET_TX_DATA_FIFO_OVERFLOW_Msk (0x10UL)        /*!< SMIF INTR_SET: TX_DATA_FIFO_OVERFLOW (Bitfield-Mask: 0x01)*/
#define SMIF_INTR_SET_RX_DATA_FIFO_UNDERFLOW_Pos (5UL)          /*!< SMIF INTR_SET: RX_DATA_FIFO_UNDERFLOW (Bit 5)             */
#define SMIF_INTR_SET_RX_DATA_FIFO_UNDERFLOW_Msk (0x20UL)       /*!< SMIF INTR_SET: RX_DATA_FIFO_UNDERFLOW (Bitfield-Mask: 0x01)*/
/* ====================================================  SMIF.INTR_MASK  ===================================================== */
#define SMIF_INTR_MASK_TR_TX_REQ_Pos      (0UL)                 /*!< SMIF INTR_MASK: TR_TX_REQ (Bit 0)                         */
#define SMIF_INTR_MASK_TR_TX_REQ_Msk      (0x1UL)               /*!< SMIF INTR_MASK: TR_TX_REQ (Bitfield-Mask: 0x01)           */
#define SMIF_INTR_MASK_TR_RX_REQ_Pos      (1UL)                 /*!< SMIF INTR_MASK: TR_RX_REQ (Bit 1)                         */
#define SMIF_INTR_MASK_TR_RX_REQ_Msk      (0x2UL)               /*!< SMIF INTR_MASK: TR_RX_REQ (Bitfield-Mask: 0x01)           */
#define SMIF_INTR_MASK_XIP_ALIGNMENT_ERROR_Pos (2UL)            /*!< SMIF INTR_MASK: XIP_ALIGNMENT_ERROR (Bit 2)               */
#define SMIF_INTR_MASK_XIP_ALIGNMENT_ERROR_Msk (0x4UL)          /*!< SMIF INTR_MASK: XIP_ALIGNMENT_ERROR (Bitfield-Mask: 0x01) */
#define SMIF_INTR_MASK_TX_CMD_FIFO_OVERFLOW_Pos (3UL)           /*!< SMIF INTR_MASK: TX_CMD_FIFO_OVERFLOW (Bit 3)              */
#define SMIF_INTR_MASK_TX_CMD_FIFO_OVERFLOW_Msk (0x8UL)         /*!< SMIF INTR_MASK: TX_CMD_FIFO_OVERFLOW (Bitfield-Mask: 0x01)*/
#define SMIF_INTR_MASK_TX_DATA_FIFO_OVERFLOW_Pos (4UL)          /*!< SMIF INTR_MASK: TX_DATA_FIFO_OVERFLOW (Bit 4)             */
#define SMIF_INTR_MASK_TX_DATA_FIFO_OVERFLOW_Msk (0x10UL)       /*!< SMIF INTR_MASK: TX_DATA_FIFO_OVERFLOW (Bitfield-Mask: 0x01)*/
#define SMIF_INTR_MASK_RX_DATA_FIFO_UNDERFLOW_Pos (5UL)         /*!< SMIF INTR_MASK: RX_DATA_FIFO_UNDERFLOW (Bit 5)            */
#define SMIF_INTR_MASK_RX_DATA_FIFO_UNDERFLOW_Msk (0x20UL)      /*!< SMIF INTR_MASK: RX_DATA_FIFO_UNDERFLOW (Bitfield-Mask: 0x01)*/
/* ===================================================  SMIF.INTR_MASKED  ==================================================== */
#define SMIF_INTR_MASKED_TR_TX_REQ_Pos    (0UL)                 /*!< SMIF INTR_MASKED: TR_TX_REQ (Bit 0)                       */
#define SMIF_INTR_MASKED_TR_TX_REQ_Msk    (0x1UL)               /*!< SMIF INTR_MASKED: TR_TX_REQ (Bitfield-Mask: 0x01)         */
#define SMIF_INTR_MASKED_TR_RX_REQ_Pos    (1UL)                 /*!< SMIF INTR_MASKED: TR_RX_REQ (Bit 1)                       */
#define SMIF_INTR_MASKED_TR_RX_REQ_Msk    (0x2UL)               /*!< SMIF INTR_MASKED: TR_RX_REQ (Bitfield-Mask: 0x01)         */
#define SMIF_INTR_MASKED_XIP_ALIGNMENT_ERROR_Pos (2UL)          /*!< SMIF INTR_MASKED: XIP_ALIGNMENT_ERROR (Bit 2)             */
#define SMIF_INTR_MASKED_XIP_ALIGNMENT_ERROR_Msk (0x4UL)        /*!< SMIF INTR_MASKED: XIP_ALIGNMENT_ERROR (Bitfield-Mask: 0x01)*/
#define SMIF_INTR_MASKED_TX_CMD_FIFO_OVERFLOW_Pos (3UL)         /*!< SMIF INTR_MASKED: TX_CMD_FIFO_OVERFLOW (Bit 3)            */
#define SMIF_INTR_MASKED_TX_CMD_FIFO_OVERFLOW_Msk (0x8UL)       /*!< SMIF INTR_MASKED: TX_CMD_FIFO_OVERFLOW (Bitfield-Mask: 0x01)*/
#define SMIF_INTR_MASKED_TX_DATA_FIFO_OVERFLOW_Pos (4UL)        /*!< SMIF INTR_MASKED: TX_DATA_FIFO_OVERFLOW (Bit 4)           */
#define SMIF_INTR_MASKED_TX_DATA_FIFO_OVERFLOW_Msk (0x10UL)     /*!< SMIF INTR_MASKED: TX_DATA_FIFO_OVERFLOW (Bitfield-Mask: 0x01)*/
#define SMIF_INTR_MASKED_RX_DATA_FIFO_UNDERFLOW_Pos (5UL)       /*!< SMIF INTR_MASKED: RX_DATA_FIFO_UNDERFLOW (Bit 5)          */
#define SMIF_INTR_MASKED_RX_DATA_FIFO_UNDERFLOW_Msk (0x20UL)    /*!< SMIF INTR_MASKED: RX_DATA_FIFO_UNDERFLOW (Bitfield-Mask: 0x01)*/

#define SMIF_DEVICE_NR              4u



#define SMIF0_BASE                  0x40420000UL
#define SMIF0                       ((SMIF_Type*) SMIF0_BASE)                                                 /* 0x40420000    */
#define SMIF0_DEVICE0               ((SMIF_DEVICE_Type*) &SMIF0->DEVICE[0])                                   /* 0x40420800    */
#define SMIF0_DEVICE1               ((SMIF_DEVICE_Type*) &SMIF0->DEVICE[1])                                   /* 0x40420880    */
#define SMIF0_DEVICE2               ((SMIF_DEVICE_Type*) &SMIF0->DEVICE[2])                                   /* 0x40420900    */
#define SMIF0_DEVICE3               ((SMIF_DEVICE_Type*) &SMIF0->DEVICE[3])                                   /* 0x40420980    */

#define CY_PDL_MODULE_ID_Pos    (18u)       /**< The software module ID position in the status code */
#define CY_PDL_MODULE_ID_Msk    (0x3FFFu)   /**< The software module ID mask */
#define CY_PDL_DRV_ID(id)       ((uint32_t)((uint32_t)((id) & CY_PDL_MODULE_ID_Msk) << CY_PDL_MODULE_ID_Pos))
#define CY_SYSPM_ID                             (CY_PDL_DRV_ID(0x10u))
#define CY_PDL_STATUS_CODE_Pos  (0u)        /**< The module status code position in the status code */
#define CY_PDL_STATUS_TYPE_Pos  (16u)       /**< The status type position in the status code */
#define CY_PDL_MODULE_ID_Pos    (18u)       /**< The software module ID position in the status code */
#define CY_PDL_STATUS_INFO      (0UL << CY_PDL_STATUS_TYPE_Pos)    /**< Information status type */
#define CY_PDL_STATUS_WARNING   (1UL << CY_PDL_STATUS_TYPE_Pos)    /**< Warning status type */
#define CY_PDL_STATUS_ERROR     (2UL << CY_PDL_STATUS_TYPE_Pos)    /**< Error status type */
/** The callback mode enumeration. This enum defines the callback mode */
typedef enum
{
    CY_SYSPM_CHECK_READY        = 0x01u,    /**< Callbacks with this mode are executed before entering into the
                                                 low-power mode. Callback function check if the device is ready
                                                 to enter the low-power mode */
    CY_SYSPM_CHECK_FAIL         = 0x02u,    /**< Callbacks with this mode are executed after the previous callbacks
                                                 execution with CY_SYSPM_CHECK_READY return CY_SYSPM_FAIL. The callback
                                                 with the CY_SYSPM_CHECK_FAIL mode should roll back the actions done in
                                                 the callbacks executed previously with CY_SYSPM_CHECK_READY */
    CY_SYSPM_BEFORE_TRANSITION  = 0x04u,    /**< The actions to be done before entering into the low-power mode */
    CY_SYSPM_AFTER_TRANSITION   = 0x08u,    /**< The actions to be done after exiting the low-power mode */
} cy_en_syspm_callback_mode_t;
/** The SysPm status definitions */
typedef enum
{
    CY_SYSPM_SUCCESS       = 0x00u,                                        /**< Successful */
    CY_SYSPM_BAD_PARAM     = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0x01u,    /**< One or more invalid parameters */
    CY_SYSPM_TIMEOUT       = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0x02u,    /**< A time-out occurs */
    CY_SYSPM_INVALID_STATE = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0x03u,    /**< The operation is not setup or is in an
                                                                                improper state */
    CY_SYSPM_FAIL          = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0xFFu     /**< An unknown failure */
} cy_en_syspm_status_t;
/** The structure with the syspm callback parameters */
typedef struct
{
    cy_en_syspm_callback_mode_t mode;   /**< The callback mode, element for internal usage, see
                                             \ref cy_en_syspm_callback_mode_t. This element should not be defined
                                             as it is updated every time before the callback function is executed */
    void *base;                         /**< The base address of a HW instance, matches name of the driver in
                                             the API for the base address. Can be not defined if not required */
    void *context;                      /**< The context for the handler function. This item can be
                                             skipped if not required. Can be not defined if not required */

} cy_stc_syspm_callback_params_t;


uint32_t Cy_GPIO_Port_Init(GPIO_PRT_Type* base, const cy_stc_gpio_prt_config_t *config);
void initHWSMIF(void);
void Cy_SysLib_DelayUs(uint16_t microseconds);
void initUART(void);
void backRestoreCnfg( bool restore );


#endif
