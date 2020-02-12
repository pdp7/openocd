/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/*******************************************************************************
* Function Name: _write
*******************************************************************************/

#include "cy_debug.h"

#if defined(DEBUG_LOG)

extern void DBG_PutChar(char txDataByte);

    /* For MDK/RVDS compiler revise fputc() function for printf functionality */
    struct __FILE
    {
        int handle;
    };

    enum
    {
        STDIN_HANDLE,
        STDOUT_HANDLE,
        STDERR_HANDLE
    };

    FILE __stdin = {STDIN_HANDLE};
    FILE __stdout = {STDOUT_HANDLE};
    FILE __stderr = {STDERR_HANDLE};


int fputc(int ch, FILE *file)
{
    int ret = EOF;

    switch( file->handle )
    {
        case STDOUT_HANDLE:
            DBG_PutChar(ch);
            ret = ch ;
            break ;

        case STDERR_HANDLE:
            ret = ch ;
            break ;

        default:
            file = file;
            break ;
    }
    return ret ;
}


/*******************************************************************************
* Function Name: PIN_Write
********************************************************************************
*
* Writes pin vaue
*
* \param value
* Value to be written
*
*******************************************************************************/
void PIN_Write(uint32_t value)
{

    /* Thread-safe: Directly access the pin registers instead of base->OUT */
    if(0 == value)
    {
        GPIO_PRT1->OUT_CLR = 0x01 << 0;
    }
    else
    {
        GPIO_PRT1->OUT_SET = 0x01 << 0;
		}
}


/*******************************************************************************
* Function Name: DBG_PutChar
********************************************************************************
*
* Transmits character via UART.
*
* \param txDataByte
* Character to be transmitted.
*
*******************************************************************************/
__asm void DBG_PutChar(char txDataByte)
{

		PRESERVE8 {TRUE}
			IMPORT Cy_SysLib_DelayCycles
			IMPORT __aeabi_uidiv
			IMPORT PIN_Write

			EXPORT DBG_PutChar
			PUSH {r1, r2, r3, r4, r5, r6, r7, lr}
			MOV r1, r9
			MOV r2, r10
			MOV r3, r11
			PUSH {r1, r2, r3}
																			; cycles  bytes
			MOV r7, r0                      ;   1       2
			;LDR r1, PORT_DR_ADDRESS         ;   2       2
			;LDR r1, [r1, #0]                ;   2       2
			MOV r10, r1                     ;   1       2   Save pin DR base address [r10]

			LDR r2, FREQ                    ;   2       2   Calculate CPU cycles to wait between bits:
			;LDR r2, [r2, #0]                ;   2       2   (CPU Frequency + (UARTBaudRate/2)) / UARTBaudRate
			LDR r0, BAUD_RATE               ;   2       2

			MOVS r1, #2                     ;   1       2
			BL __aeabi_uidiv                ;   4       2
			MOVS r3, r0                     ;   1       2
			LDR r0, FREQ                    ;   2       2
			;LDR r0, [r0, #0]                ;   2       2
			ADDS r0, r0, r3                 ;   1       2
			LDR r1, BAUD_RATE               ;   2       2
			BL __aeabi_uidiv                ;   4       2
			MOVS r6, r0                     ;   1       2
			SUBS r6, r6, #40                ;   1       2   Save delay to [r6] and remove overhead

			MOV r11, r6                     ;   1       2
			;LDR r2, PIN_NUMBER              ;   2       2
			;LDR r2, [r2, #0]                ;   2       2
			MOVS r1, #1                     ;   1       2
			LSLS r1, r1, r2                 ;   1       2
			MVNS r1, r1                     ;   1       2
			MOV r4, r1                      ;   1       2   Save pin state mask to [r4]
			MOVS r5, #1                     ;   1       2   Prepare lower bit mask [r5]
			MOVS r6, #0                     ;   1       2   Prepare counter


																			;               Transmitting start bit
			MOV R9, R0
			MOVS R0, #0
			BL PIN_Write
			MOV R0, R9

			MOV r0, r11                     ;   1       2
			SUBS r0, #44                     ;   1       2   Adjust delay
			BL Cy_SysLib_DelayCycles                ;   4+4     2

bitTxLoop
																			;               Transmit bit loop
			MOVS r0, r7                     ;   1       2   Move byte to r0
			LSRS r0, r0, r6                 ;   1       2   Shift byte by counter
			ANDS r0, r0, r5                 ;   1       2   Extract lower bit
			LSLS r0, r0, r2                 ;   1       2   Shift bit by pin number

			LDR r3, [r1, #0]                ;   2       2   Load current pin data reg
			ANDS r3, r3, r4                 ;   1       2   Apply mask to clear pin bit
			ORRS r3, r3, r0                 ;   1       2   OR result with shifted bit value
			;STR r3, [r1, #0]                ;   2       2   Write register value
		  BL PIN_Write

			MOV r0, r11                     ;   1       2   Move delay time to r0
			BL Cy_SysLib_DelayCycles                ;   4+4     2   Call delay function
			ADDS r6, r6, #1                 ;   1       2   Increment counter
			CMP r6, #7                      ;   1       2   Compare counter

			BLS bitTxLoop                   ;   3(1)    2   Jump to start of the loop
			;                                   24      26

			MOVS r0, #0                     ;   1       2   Wait 2 extra cycles
			ADDS r0, #1                     ;   1       2

																			;               Transmitting STOP bit
			MOVS r0, #1                     ;   1       2
		  BL PIN_Write
			LSLS r0, r0, r2                 ;   1       2
			LDR r3, [r1, #0]                ;   2       2
			ANDS r3, r3, r4                 ;   1       2

			ORRS r3, r3, r0                 ;   1       2
			;STR r3, [r1, #0]                ;   2       2
			MOV r0, r11                     ;   1       2
			ADDS r0, #6                     ;   1       2   Adjust delay

			BL Cy_SysLib_DelayCycles                ;   4       2

			MOV r0, r9                      ;   1       2
			NOP                             ;   1       2
			NOP                             ;   1       2
			NOP                             ;   1       2
			POP {r1, r2, r3}
			MOV r9, r1
			MOV r10, r2
			MOV r11, r3
			POP {r1, r2, r3, r4, r5, r6, r7, pc}

FREQ DCD 50000000
BAUD_RATE DCD 38400
}


#endif /* DEBUG_LOG */


/* [] END OF FILE */
