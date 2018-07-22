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




struct debug_S {
	//Overwrite Enables
	_bool debugEnable = FALSE;
	_bool airPlusOvr = FALSE;
	_bool airMinusOvr = FALSE;
	_bool prechargeRelayOvr = FALSE;
	_bool enableLineOvr = FALSE;
	//Overwrite Values
	RelayState_E airPlusValue = RELAY_UNKNOWN;
	RelayState_E airMinusValue = RELAY_UNKNOWN;
	RelayState_E prechargeRelayValue = RELAY_UNKNOWN;
	_bool enableLineValue = FALSE;
} dbgEnables;






/* [] END OF FILE */
