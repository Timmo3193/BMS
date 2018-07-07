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

#include "Timer.h"
#include "global.h"

//Global Variables
unsigned long CAN_MIA_StartTime =0;



//-------------------------------------------

//
GlobalTimer_Init()
{
    //Start Clock
    Global_Timer_start();
    
}

//-------------------------------------------

//setup timer functions
GetGlobalTime()
{
    return Global_Timer_ReadCounter();
}

//-------------------------------------------


_Bool CAN_MIA_Expired()
{
    _Bool result = FALSE;
    unsigned int deltaTime = (GetGlobalTime() - CAN_MIA_GetStartTime())*BUSCLOCK_BASE;
    if ( deltaTime > CAN_MIA_TIMEOUT)
    {
        result = TRUE;
    }
    return result;
}

CAN_MIA_SetStartTime()
{
    unsigned long StartTime = GetGlobalTime();
}

/* [] END OF FILE */
