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

#include "project.h"
#include "UART.h"



CY_ISR(isrUartRxHandler)
{
    isr_RxUart_ClearPending();
    char ch = UART_DBG_GetChar(); 
    UART_DBG_PutChar(ch);
}














/* [] END OF FILE */
