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

#include "RelayControl.h"



ClosePosRelay()
{
    if( BMS_FAULT != BMS_State)
    {
        doBMS_RelayPosDrive_write(1);
        
    }
    else
    {
        //send message to display?
        SetDTC_f010_RelayWontCloseInFault();
    }
}








/* [] END OF FILE */
