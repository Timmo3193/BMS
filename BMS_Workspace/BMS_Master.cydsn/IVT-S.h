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


#define CURRENT_MAX				1000 // Amps
#define CURRENT_MIN				-1000 // Amps
#define VOLTAGE_MAX				800 // Volts
#define VOLTAGE_MIN				400 // Volts

#define IVT_INVERTED_SIGNAL		0 // Signed-ness. 0 = NO, 1 = YES
#define ENDIANESS				0 // BIG ENDIANESS


enum IVT_Mode_E {
	DISABLED,
	TRIGGERED,
	CYCLIC
} IVT_ModeSelect_E;

typedef struct {
	int IVT_MuxID;
	int IVT_ResultState;
	int IVT_MsgCount;
	int IVT_ResultData;
} IVT_Recieve_S;

//This struct needs reviewing
typedef struct {
	int IVT_ChannelSelect;
	enum IVT_Mode_E channelMode;
} ivtMode_S;



//Function Declerations
void Configure_IVT();
void GetIVTCurrent();
void GetIVTVoltage1();







/* [] END OF FILE */
