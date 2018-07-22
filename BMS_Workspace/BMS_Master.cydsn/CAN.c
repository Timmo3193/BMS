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
#include "CAN.h"

uint8_t testByte1 = 0xAC;
uint16_t testData2 = 0x3333;
/*
Get_CAN.Message()
{
    Get_Signal01();
    Get_Signal02();
}

Set_CAN.Message()
{
    Set_Signal01;
}


*/
void Tx_TestMessage(void)
{
	Vehicle_CAN_TX_DATA_BYTE_1(testByte1);

	uint8_t ls_byte = (char)(testData2 && 0xFF);
	uint8_t ms_byte = (char)(testData2 >> 8);

	Vehicle_CAN_SendMsgMailbox0();
}


void Rx_DBG_Msg(void)
{
	//get msgID
	int msgID = Vehicle_CAN_GET_RX_ID(i);
	//Get DLC
	int msgDlc = Vehicle_CAN_GET_DLC(i);

	

}


void checkNewCanData(void)
{
	for (int i = 0, i < NUM_CAN_RX_MAILBOX, i++)
	{
		// If mailbox flag is set

		// Then get message information
		msgID = Vehicle_CAN_GET_RX_ID(i);
		msgDlc = Vehicle_CAN_GET_RX_DLC(i);

		// Then call get data function.

		// ALTERNATIVE: ALWAYS GET MESSAGE INFO? Risk is it will be zero after reading?


	}
}


/* [] END OF FILE */
