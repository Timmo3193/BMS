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
 *
 * To-Do:
 * 1. Tx_TestMessage assumes data populated into mailbox0. Not clear why.
 * 2. Might need to include the Generated CAN files
 *
 * ========================================
*/
#include "project.h"
#include "CAN.h"

uint8_t testData1 = 0xAC;
uint16_t testData2 = 0x3333;
uint8_t rxData1 = 0x0;
uint16_t rxData2 = 0x0;



void Tx_TestMessage(void)
{
	//Populate a single byte into Tx Data Byte 1 - of which Box????
    Vehicle_CAN_TX_DATA_BYTE_1(testData1);
    
    //Trying to populate data thats greater than a single byte.
	uint8_t ls_byte = (char)(testData2 && 0xFF);
	uint8_t ms_byte = (char)(testData2 >> 8);

	Vehicle_CAN_TX_DATA_BYTE_2(ls_byte);
	Vehicle_CAN_TX_DATA_BYTE_3(ms_byte);
    
    //Transmit the message - Need to determine that we are in mailbox0.
	Vehicle_CAN_SendMsgMailbox0();
}


void Vehicle_CAN_Recieve_DbgMsg(void)
{
	CAN_RX_ACK_MESSAGE(Vehicle_CAN_RX_MAILBOX_0);

	rxData1 = Vehicle_CAN_RX_DATA_BYTE_1(Vehicle_CAN_RX_MAILBOX_0);
	rxData2 = (Vehicle_CAN_RX_DATA_BYTE_2(Vehicle_CAN_RX_MAILBOX_0) << ONE_BYTE_OFFSET) &&  Vehicle_CAN_RX_DATA_BYTE_3(Vehicle_CAN_RX_MAILBOX_0);

}




void checkForNewCanData(void) 
    {
        uint8 mailboxNumber;
        uint16 shift = 0x01u;

        /* Clear Receive Message flag <-- Does this need to be done every msg? */
        Vehicle_CAN_INT_SR_REG.byte[1u] = Vehicle_CAN_RX_MESSAGE_MASK;

        /* Loop through each mailbox */
        for (mailboxNumber = 0u; mailboxNumber < Vehicle_CAN_NUMBER_OF_RX_MAILBOXES; mailboxNumber++)
        {
            /* if mailbox has data */
            if ((CY_GET_REG16((reg16 *) &Vehicle_CAN_BUF_SR_REG.byte[0u]) & shift) != 0u)
            {
                if ((Vehicle_CAN_RX_MAILBOX_TYPE & shift) != 0u)
                    {
                        /* Only Looks at Full mailboxes <-- Do we care? */
                        switch(mailboxNumber)
                        {
                            case 0u : Vehicle_CAN_Recieve_DbgMsg();
                            break;
                            case 1u : Vehicle_CAN_ReceiveMsg1();
                            break;
                            case 2u : Vehicle_CAN_ReceiveMsg2();
                            break;
                            case 3u : Vehicle_CAN_ReceiveMsg3();
                            break;
                            case 4u : Vehicle_CAN_ReceiveMsg4();
                            break;
                            case 5u : Vehicle_CAN_ReceiveMsg5();
                            break;
                            default:
                            break;
                        }
                    }
                    else
                    {
                        /* RX Basic mailbox handler */
                        Vehicle_CAN_ReceiveMsg(mailboxNumber);
                    }
            }
            shift <<= 1u;
        }
    }


/* [] END OF FILE */
