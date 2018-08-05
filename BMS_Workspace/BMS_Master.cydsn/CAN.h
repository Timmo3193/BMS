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
#include "RelayControl.h"

#define ONE_BYTE_OFFSET		8u


typedef struct debug_S {
	//Overwrite Enables
	_Bool debugEnable;
	_Bool airPlusOvr;
	_Bool airMinusOvr;
	_Bool prechargeRelayOvr;
	_Bool enableLineOvr;
	//Overwrite Values
	enum RelayState_E airPlusValue;
	enum RelayState_E airMinusValue;
	enum RelayState_E prechargeRelayValue;
	_Bool enableLineValue;
};


void Vehicle_CAN_Recieve_DbgMsg(void);





/* [] END OF FILE */
