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
#include "global.h"
#include "UART.h"

#define DEBUG_MODE   TRUE

/* Function Prototypes */
void initializeComms(void);




int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    initializeComms();


    for(;;)
    {
        UART_DBG_PutString("Printf is working correctly \n");
        doBMS_RelayPreCharge_Write(1);
        CyDelay(500);
        doBMS_RelayPreCharge_Write(0);
        CyDelay(500);    
    }
}


void initializeComms(void)
{
    /* Start UART First, so that we can print any issues */
    if (DEBUG_MODE)
    {
        UART_DBG_Start();                                   /* Start communication component */
        UART_DBG_PutString("Enabled UART \n");
        isr_RxUart_StartEx(isrUartRxHandler);               /* Interrupt Routine to recieve UART messages */
        UART_DBG_PutString("Debug Mode is ACTIVE \n");
    }

    //Start CAN Bus
    //Vehicle_CAN_Start();
    
    //Start SPI
    //SPICAN_Start();    
    
}



/* [] END OF FILE */
