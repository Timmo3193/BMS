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
#include "global.h"
#include "DTC.h"
#include "mainState.h"


//init Relays as type RelayState
enum RelayState_E PosRelay = RELAY_UNKNOWN;
enum RelayState_E NegRelay = RELAY_UNKNOWN;
enum RelayState_E PrechargeRelay = RELAY_UNKNOWN;


ClosePosRelay()
{
    //Dont close if BMS has faulted
    if( BMS_STATE_FAULT != BMS_State)
    {
        doBMS_RelayPosDrive_write(CLOSE);
        PosRelay = RELAY_CLOSING;
        //implement delay to wait for closing
        
        if( RELAY_CLOSED == PosRelayFeedback() )
        {
            PosRelay = RELAY_CLOSED;
            ClearDTC_f010_PosRelayWeldedClosed();
        }
        else
        {
            PosRelay = RELAY_FAULT;
            SetDTC_f010_PosRelayWeldedClosed();
        }        
    }
    else
    {
        //send message to display?
        SetDTC_a010_RelayWontCloseInFault();
    }
}

// -------------------------------------------------------//

enum RelayState_E PosRelayFeedback()
{
    //Confirm Timer has elapsed?
    return diBMS_RelayPosFdbk_read();
}

// -------------------------------------------------------//

CloseNegRelay()
{
    //Dont close if BMS has faulted
    if( BMS_STATE_FAULT != BMS_State)
    {
        doBMS_RelayNegDrive_write(CLOSE);
        NegRelay = RELAY_CLOSING;
        //implement delay to wait for closing
        
        if( RELAY_CLOSED == NegRelayFeedback() )
        {
            NegRelay = RELAY_CLOSED;
            ClearDTC_f010_NegRelayWeldedClosed();
        }
        else
        {
            NegRelay = RELAY_FAULT;
            SetDTC_f010_NegRelayWeldedClosed();
        }        
    }
    else
    {
        //send message to display?
        SetDTC_a010_NegRelayWontCloseInFault();
    }
}

// -------------------------------------------------------//

enum RelayState_E NegRelayFeedback()
{
    //Confirm Timer has elapsed?
    return diBMS_RelayNegFdbk_read();
}

    
    
    
void PerformPrecharge()
{
    //Check Negative Relay is already Closed
    if( RELAY_CLOSED == NegRelay )
    {
        //Confirm that the negative relay is already closed        
        doBMS_RelayPreCharge_write(CLOSE);
        //Wait Precharge RC time
        //
        //Check Voltage delta is below threshold <--! ToDo: Ensure that this is made ABS delta
        if ( (aiBMS_outputVoltage_read() - aiBMS_packVoltage_read()) < PRECHARGE_DELTA_V )
        {
            ClearDTC_f014_PrechareFailure();
            //What are we returning to flag success?
            return;
        }
        else
        {
            SetDTC_f014_PrechareFailure();
            //What are we returning to flag failure?
            return;
        }
    }
    
}



/* [] END OF FILE */
