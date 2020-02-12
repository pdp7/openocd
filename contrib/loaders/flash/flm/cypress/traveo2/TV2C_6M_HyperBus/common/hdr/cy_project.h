/***************************************************************************//**
* \file cy_project.h
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

#ifndef CY_PROJECT_H
#define CY_PROJECT_H

#ifdef __cplusplus
extern "C" {
#endif


#include "syslib/cy_syslib.h"

// Accomodate for different system frequencies of PSVP and silicon for the simple LED toggle delay
#if (CY_USE_PSVP == 1)
  #define CY_LED_TOGGLE_DELAY     (150000UL)
#else
  #if CY_CPU_CORTEX_M0P
	#define CY_LED_TOGGLE_DELAY     (400000UL * 6)
  #else
	#define CY_LED_TOGGLE_DELAY     (400000UL * 12)
  #endif
#endif


#include "gpio/cy_gpio.h"
//MYKT#include "ipc/cy_ipc_drv.h"
//MYKT#include "ipc/cy_ipc_pipe.h"
//MYKT#include "ipc/cy_ipc_config.h"
//MYKT#include "mcwdt/cy_mcwdt.h"
//MYKT#include "prot/cy_prot.h"
//MYKT#include "scb/cy_scb_common.h"
//MYKT#include "scb/cy_scb_ezi2c.h"
//MYKT#include "scb/cy_scb_i2c.h"
//MYKT#include "scb/cy_scb_spi.h"
//MYKT#include "scb/cy_scb_uart.h"
//MYKT#include "sysint/cy_sysint.h"
#include "sysclk/cy_sysclk.h"
#include "syswdt/cy_syswdt.h"
//MYKT#include "sysrtc/cy_sysrtc.h"
//MYKT#include "tcpwm/cy_tcpwm.h"
//MYKT#include "tcpwm/cy_tcpwm_counter.h"
//MYKT#include "tcpwm/cy_tcpwm_pwm.h"
//MYKT#include "tcpwm/cy_tcpwm_quaddec.h"
//MYKT#include "tcpwm/cy_tcpwm_sr.h"
//MYKT#include "syspm/cy_syspm.h"
//MYKT#include "syslib/cy_syslib.h"
//MYKT#include "trigmux/cy_trigmux.h"
//MYKT#include "systick/cy_systick.h"
//MYKT#include "dma/cy_pdma.h"
//MYKT#include "dma/cy_mdma.h"
//MYKT#include "adc/cy_adc.h"
//MYKT#include "crypto/cy_crypto.h"
//MYKT#include "crypto/cy_crypto_server.h"
//MYKT#include "lin/cy_lin.h"
//MYKT#include "canfd/cy_canfd.h"
//MYKT#include "evtgen/cy_evtgen.h"
//MYKT#include "flash/cy_flash.h"
//MYKT#include "sysflt/cy_sysflt.h"
//MYKT#include "lvd/cy_lvd.h"
//MYKT#include "smartio/cy_smartio.h"
//MYKT#include "sysreset/cy_sysreset.h"

#if defined (tviibe2m) || defined (tviic2d6m)
//MYKT    #include "cxpi/cy_cxpi.h"
#endif

#if defined (tviibh8m)
	#include "cpu/cy_cpu.h"
	#include "flexray/cy_fr.h"
	#include "sd_host/cy_sd_host.h"
	#include "audioss/cy_i2s.h"
	#include "smif/cy_smif.h"
	#include "smif/cy_smif_memslot.h"
	#include "ethernet/cy_ethif.h"
	#include "sysreg/cy_sysreg.h"
#endif

#if defined (tviic2d6m)
//MYKT#include "audioss/mixer/cy_mixer.h"
//MYKT#include "audioss/i2s/cy_i2s.h"
//MYKT#include "audioss/pwm/cy_pwm.h"
	#include "smif/cy_smif.h"
	#include "smif/cy_smif_memslot.h"
#endif

//=============================================

#if defined (tviibe1m)
	#include "bb_bsp_tviibe1m.h"
#elif defined (tviibe2m)
	#include "bb_bsp_tviibe2m.h"
#elif defined (tviibh8m)
	#include "bb_bsp_tviibh8m.h"
#elif defined (tviic2d6m)
	#include "bb_bsp_tviic2d6m.h"
#endif

//============ Middleware =====================

//MYKT #include "button/cy_button.h"
//MYKT #include "semihosting/cy_semihosting.h"
//MYKT #include "sw_timer/cy_sw_tmr.h" 
#if defined (tviibh8m)
	#include "mw/reghc/cy_reghc.h"
	#include "mw/smif_mem/cy_smif_device_common.h"
	#include "mw/smif_mem/cy_smif_hb_flash.h"
	#include "mw/smif_mem/cy_smif_s25fl.h"
	#include "mw/smif_mem/cy_smif_s28h.h"
#endif
#if defined (tviic2d6m)
//MYKT     #include "mw/gfx_env/cy_gfx_env.h"
	#include "mw/smif_mem/cy_smif_device_common.h"
	#include "mw/smif_mem/cy_smif_hb_flash.h"
	#include "mw/smif_mem/cy_smif_s25fl.h"
	#include "mw/smif_mem/cy_smif_s28h.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /* CY_PROJECT_H */

/* [] END OF FILE */
