/***************************************************************************//**
* \file cy_ipc_config.h
* \version 1.10
*
* \brief
* This header file is not intended to be part of the IPC driver since it defines
* a device specific configuration for the IPC channels and pipes.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef CY_IPC_CONFIG_H
#define CY_IPC_CONFIG_H

/* IPC Resources */
#define CY_IPC_CHANNELS                 (uint32_t)(CPUSS_IPC_IPC_NR)
#define CY_IPC_INTERRUPTS               (uint32_t)(CPUSS_IPC_IPC_IRQ_NR)

/* IPC channel definitions  */
#define CY_IPC_CHAN_SYSCALL_CM0         (0u)  /**< System calls for the CM0 processor */
#define CY_IPC_CHAN_SYSCALL_CM4_CM7_0   (1u)  /**< System calls for the 1st non-CM0 processor */
#define CY_IPC_CHAN_SYSCALL_CM7_1       (2u)  /**< System calls for the 2nd non-CM0 processor */

#if (CY_CPU_CORTEX_M0P)
    #define CY_IPC_CHAN_SYSCALL                  CY_IPC_CHAN_SYSCALL_CM0
#else
    #if defined (tviibe1m) || defined (tviibe2m)
        #define CY_IPC_CHAN_SYSCALL              CY_IPC_CHAN_SYSCALL_CM4_CM7_0    
    #elif defined (tviibh8m) || defined (tviic2d6m)
        #if defined (CY_CORE_CM7_0)
            #define CY_IPC_CHAN_SYSCALL          CY_IPC_CHAN_SYSCALL_CM4_CM7_0    
        #else
            #define CY_IPC_CHAN_SYSCALL          CY_IPC_CHAN_SYSCALL_CM7_1
        #endif
    #endif    
#endif  /* (CY_CPU_CORTEX_M0P) */

#if defined (tviibe1m) || defined (tviibe2m)
    #define CY_IPC_CHAN_SYSCALL_DAP     (uint32_t)(2u)    /**< System calls for the DAP */
#elif defined (tviibh8m) || defined (tviic2d6m)
    #define CY_IPC_CHAN_SYSCALL_DAP     (uint32_t)(3u)    /**< System calls for the DAP */
#endif 

#define CY_IPC_CHAN_CRYPTO              (uint32_t)(4u)    /**< IPC data channel for the Crypto */

#define CY_IPC_CHAN_SEMA                (uint32_t)(5u)    /**< IPC data channel for the Semaphores */

#define CY_IPC_CHAN_CYPIPE_EP0          (uint32_t)(6u)    /**< IPC data channel for CYPIPE EP0 */
#define CY_IPC_CHAN_CYPIPE_EP1          (uint32_t)(7u)    /**< IPC data channel for CYPIPE EP1 */

/* IPC Notify interrupts definitions */
#define CY_IPC_INTR_CRYPTO_SRV          (uint32_t)(4u)    /**< IPC interrupt structure for the Crypto server */
#define CY_IPC_INTR_CRYPTO_CLI          (uint32_t)(5u)    /**< IPC interrupt structure for the Crypto client */

/* IPC Semaphores allocation
   This will allow 128 (4*32) semaphores */
#define CY_IPC_SEMA_COUNT               (uint32_t)(128u)

/* IPC Pipe definitions */
#define CY_IPC_MAX_ENDPOINTS            (uint32_t)(8u)

/*******************************************************************************
** CY_PIPE default configuration
*******************************************************************************/
#define CY_IPC_CYPIPE_CLIENT_CNT        (uint32_t)(8u)

#define CY_IPC_INTR_CYPIPE_INTIDX_EP0   (CPUIntIdx2_IRQn)/* IPC CYPRESS PIPE */
#define CY_IPC_INTR_CYPIPE_EP0          (uint32_t)(6u)   /* Notifier EP0 */
#define CY_IPC_INTR_CYPIPE_INTIDX_EP1   (CPUIntIdx2_IRQn)/* IPC CYPRESS PIPE */
#define CY_IPC_INTR_CYPIPE_EP1          (uint32_t)(7u)   /* Notifier EP1 */

#define CY_IPC_CYPIPE_CHAN_MASK_EP0     (uint32_t)(0x0001ul << CY_IPC_CHAN_CYPIPE_EP0)
#define CY_IPC_CYPIPE_CHAN_MASK_EP1     (uint32_t)(0x0001ul << CY_IPC_CHAN_CYPIPE_EP1)

/* Endpoint indexes in the pipe array */
#define CY_IPC_EP_CYPIPE_CM0_ADDR       (uint32_t)(0u)
#define CY_IPC_EP_CYPIPE_CM4_CM7_X_ADDR (uint32_t)(1u)

#if (CY_CPU_CORTEX_M0P)
    #define CY_IPC_EP_CYPIPE_ADDR       CY_IPC_EP_CYPIPE_CM0_ADDR
#else
    #define CY_IPC_EP_CYPIPE_ADDR       CY_IPC_EP_CYPIPE_CM4_CM7_X_ADDR
#endif  /* (CY_CPU_CORTEX_M0P) */



/******************************************************************************/

/*
 * The System pipe configuration defines the IPC channel number, interrupt
 * number, and the pipe interrupt mask for the endpoint.
 *
 * The format of the endPoint configuration
 *    Bits[31:16] Interrupt Mask
 *    Bits[15:8 ] IPC interrupt
 *    Bits[ 7:0 ] IPC channel
 */

/* System Pipe addresses */
/* CyPipe defines */

#define CY_IPC_CYPIPE_CONFIG_EP0  (uint32_t)( (CY_IPC_CYPIPE_INTR_MASK << CY_IPC_PIPE_CFG_IMASK_Pos) \
                                            | (CY_IPC_INTR_CYPIPE_EP0 << CY_IPC_PIPE_CFG_INTR_Pos) \
                                            | CY_IPC_CHAN_CYPIPE_EP0)
#define CY_IPC_CYPIPE_CONFIG_EP1  (uint32_t)( (CY_IPC_CYPIPE_INTR_MASK << CY_IPC_PIPE_CFG_IMASK_Pos) \
                                            | (CY_IPC_INTR_CYPIPE_EP1 << CY_IPC_PIPE_CFG_INTR_Pos) \
                                            | CY_IPC_CHAN_CYPIPE_EP1)
#define CY_IPC_CYPIPE_INTR_MASK   (uint32_t)( CY_IPC_CYPIPE_CHAN_MASK_EP0 | CY_IPC_CYPIPE_CHAN_MASK_EP1 )

/******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif


void Cy_IPC_SystemSemaInit(void);
void Cy_IPC_SystemPipeInit(void);
void Cy_IPC_SystemPipeIsr(void);


#ifdef __cplusplus
}
#endif


#endif /* CY_IPC_CONFIG_H  */

/* [] END OF FILE */
