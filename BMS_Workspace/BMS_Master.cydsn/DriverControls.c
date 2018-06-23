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
#include "global.h"
#include "DriverControls.h"




//Declare Variables
int BrakeInput1 = 0;


//Function Prototypes


//Function Definitions
    

//Is the brake handle input an acceptable value
int BrakeInputPlausibility()
{
    //Take a snapshot of brake input sensors
    BrakeInput1 = aiECU_BrakeInput1_read();
    
    //Check that Brake input is within tolerance
    if( BrakeInput1 < BrakeSensor1_min)
    {
        SetDTC_f010_Brake1InputOC();
        return BrakeFaultValue;
    }
    else if ( BrakeInput1 > BrakeSensor1_max )
    {
        SetDTC_f011_Brake1InputSC();
        return BrakeFaultValue;
    }
    else
    {
        return BrakeInput1;
    }
}

//------------------------------------------------------------//

//Turn on the brake light if brake input is above the deadzone threshold
_Bool OutputBrakeLight()
{
    doECU_BrakeLight_write(BrakeInputPlausibility() > BrakeLightThreshold);
}

//------------------------------------------------------------//

//Check Throttle Plausibility

//Check BrakeVsThrottle?

//Check BrakePressurePlausibility



















/* [] END OF FILE */
