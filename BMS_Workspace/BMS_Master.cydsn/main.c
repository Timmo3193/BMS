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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    void initializeComms();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}


void initializeComms(void)
{
    //Start CAN Bus
    Vehicle_CAN_Start();
    //Enable Interupts?
    
    //Start SPI
    SPICAN_Start();
  
    #ifdef DEBUG_MODE
        UART_DBG_Start();
    #endif
    
    
    
}











/* [] END OF FILE */
