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

#include "IVT-S.h"


int iBat = 0;
int vBat = 0;



//-------------------------------------------------------------

Configure_IVT()
{
	//Insert Configuration Code here
	//

}

//-------------------------------------------------------------

GetCurrent()
{
	//Recieve Current from IVT-S
	iBat = Get_IVT_I();
	//Check that current is in acceptable range
	if ( iBat > CURRENT_MAX )
	{
		SetDTC_f030_PackPosOvercurrent();
	}
	else if ( iBat < CURRENT_MIN )
	{
		SetDTC_f031_PackNegOvercurrent();
	}
	else
	{
		ClearDTC_f030_PackPosOvercurrent();
		ClearDTC_f031_PackNegOvercurrent();
	}

	return iBat;

}

//-------------------------------------------------------------

GetVoltage()
{
	vBat = Get_IVT_Vbat();
	//Check that Voltage is in acceptable range
	if( vBat > VOLTAGE_MAX )
	{
		SetDTC_a040_PackOverV();
	}
	else if ( vBat < VOLTAGE_MIN )
	{
		SetDTC_a041_PackUnderV();
	}

	return vBat;

}

//-------------------------------------------------------------






/* [] END OF FILE */
