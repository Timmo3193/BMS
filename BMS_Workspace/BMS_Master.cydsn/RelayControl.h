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

#define PRECHARGE_DELTA_V       10 //Volts


//Defining the Relay Enumeration Values
enum RelayState_E { 
    RELAY_CLOSED,
    RELAY_CLOSING,
    RELAY_OPEN,
    RELAY_OPENING,
    RELAY_FAULT,
    RELAY_UNKNOWN 
};




void ClosePosRelay();
enum RelayState_E  PosRelayFeedback();
void CloseNegRelay();
enum RelayState_E  NegRelayFeedback();
void PerformPrecharge();







/* [] END OF FILE */
