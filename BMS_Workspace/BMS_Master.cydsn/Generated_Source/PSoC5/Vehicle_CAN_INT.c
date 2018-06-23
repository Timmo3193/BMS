/*******************************************************************************
* File Name: Vehicle_CAN_INT.c
* Version 3.0
*
* Description:
*  This file contains Interrupt Service Routine (ISR) for CAN Component.
*  The Interrupt handlers functions are generated accordingly to the PSoC
*  Creator Customizer inputs.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Vehicle_CAN.h"
#include "cyapicallbacks.h"

/* `#START CAN_INT_C_CODE_DEFINITION` */

/* `#END` */

#if (Vehicle_CAN_ARB_LOST)
    /*******************************************************************************
    * FUNCTION NAME:   Vehicle_CAN_ArbLostIsr
    ********************************************************************************
    *
    * Summary:
    *  This function is entry point to Arbitration Lost Interrupt. Clears
    *  Arbitration Lost interrupt flag. Only generated if Arbitration Lost
    *  Interrupt enable in Customizer.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Reentrant:
    *  Depends on Customer code.
    *
    *******************************************************************************/
    void Vehicle_CAN_ArbLostIsr(void) 
    {
        /* Clear Arbitration Lost flag */
        Vehicle_CAN_INT_SR_REG.byte[0u] = Vehicle_CAN_ARBITRATION_LOST_MASK;

        /* `#START ARBITRATION_LOST_ISR` */

        /* `#END` */

        #ifdef Vehicle_CAN_ARB_LOST_ISR_CALLBACK
            Vehicle_CAN_ArbLostIsr_Callback();
        #endif /* Vehicle_CAN_ARB_LOST_ISR_CALLBACK */
    }
#endif /* Vehicle_CAN_ARB_LOST */


#if (Vehicle_CAN_OVERLOAD)
    /*******************************************************************************
    * FUNCTION NAME:   Vehicle_CAN_OvrLdErrorIsr
    ********************************************************************************
    *
    * Summary:
    *  This function is entry point to Overload Error Interrupt. Clears Overload
    *  Error interrupt flag. Only generated if Overload Error Interrupt enable
    *  in Customizer.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Reentrant:
    *  Depends on Customer code.
    *
    *******************************************************************************/
    void Vehicle_CAN_OvrLdErrorIsr(void) 
    {
        /* Clear Overload Error flag */
        Vehicle_CAN_INT_SR_REG.byte[0u] = Vehicle_CAN_OVERLOAD_ERROR_MASK;

        /* `#START OVER_LOAD_ERROR_ISR` */

        /* `#END` */

        #ifdef Vehicle_CAN_OVR_LD_ERROR_ISR_CALLBACK
            Vehicle_CAN_OvrLdErrorIsr_Callback();
        #endif /* Vehicle_CAN_OVR_LD_ERROR_ISR_CALLBACK */
    }
#endif /* Vehicle_CAN_OVERLOAD */


#if (Vehicle_CAN_BIT_ERR)
    /*******************************************************************************
    * FUNCTION NAME:   Vehicle_CAN_BitErrorIsr
    ********************************************************************************
    *
    * Summary:
    *  This function is entry point to Bit Error Interrupt. Clears Bit Error
    *  interrupt flag. Only generated if Bit Error Interrupt enable in Customizer.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Reentrant:
    *  Depends on Customer code.
    *
    *******************************************************************************/
    void Vehicle_CAN_BitErrorIsr(void) 
    {
        /* Clear Bit Error flag */
        Vehicle_CAN_INT_SR_REG.byte[0u] = Vehicle_CAN_BIT_ERROR_MASK;

        /* `#START BIT_ERROR_ISR` */

        /* `#END` */

        #ifdef Vehicle_CAN_BIT_ERROR_ISR_CALLBACK
            Vehicle_CAN_BitErrorIsr_Callback();
        #endif /* Vehicle_CAN_BIT_ERROR_ISR_CALLBACK */
    }
#endif /* Vehicle_CAN_BIT_ERR */


#if (Vehicle_CAN_STUFF_ERR)
    /*******************************************************************************
    * FUNCTION NAME:   Vehicle_CAN_BitStuffErrorIsr
    ********************************************************************************
    *
    * Summary:
    *  This function is entry point to Bit Stuff Error Interrupt. Clears Bit Stuff
    *  Error interrupt flag. Only generated if Bit Stuff Error Interrupt enable
    *  in Customizer.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Reentrant:
    *  Depends on Customer code.
    *
    *******************************************************************************/
    void Vehicle_CAN_BitStuffErrorIsr(void) 
    {
        /* Clear Stuff Error flag */
        Vehicle_CAN_INT_SR_REG.byte[0u] = Vehicle_CAN_STUFF_ERROR_MASK;

        /* `#START BIT_STUFF_ERROR_ISR` */

        /* `#END` */

        #ifdef Vehicle_CAN_BIT_STUFF_ERROR_ISR_CALLBACK
            Vehicle_CAN_BitStuffErrorIsr_Callback();
        #endif /* Vehicle_CAN_BIT_STUFF_ERROR_ISR_CALLBACK */
    }
#endif /* Vehicle_CAN_STUFF_ERR */


#if (Vehicle_CAN_ACK_ERR)
    /*******************************************************************************
    * FUNCTION NAME:   Vehicle_CAN_AckErrorIsr
    ********************************************************************************
    *
    * Summary:
    *  This function is entry point to Acknowledge Error Interrupt. Clears
    *  Acknowledge Error interrupt flag. Only generated if Acknowledge Error
    *  Interrupt enable in Customizer.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Reentrant:
    *  Depends on Customer code.
    *
    *******************************************************************************/
    void Vehicle_CAN_AckErrorIsr(void) 
    {
        /* Clear Acknoledge Error flag */
        Vehicle_CAN_INT_SR_REG.byte[0u] = Vehicle_CAN_ACK_ERROR_MASK;

        /* `#START ACKNOWLEDGE_ERROR_ISR` */

        /* `#END` */

        #ifdef Vehicle_CAN_ACK_ERROR_ISR_CALLBACK
            Vehicle_CAN_AckErrorIsr_Callback();
        #endif /* Vehicle_CAN_ACK_ERROR_ISR_CALLBACK */
    }
#endif /* Vehicle_CAN_ACK_ERR */


#if (Vehicle_CAN_FORM_ERR)
    /*******************************************************************************
    * FUNCTION NAME:   Vehicle_CAN_MsgErrorIsr
    ********************************************************************************
    *
    * Summary:
    *  This function is entry point to Form Error Interrupt. Clears Form Error
    *  interrupt flag. Only generated if Form Error Interrupt enable in Customizer.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Reentrant:
    *  Depends on Customer code.
    *
    *******************************************************************************/
    void Vehicle_CAN_MsgErrorIsr(void) 
    {
        /* Clear Form Error flag */
        Vehicle_CAN_INT_SR_REG.byte[0u] = Vehicle_CAN_FORM_ERROR_MASK;

        /* `#START MESSAGE_ERROR_ISR` */

        /* `#END` */

        #ifdef Vehicle_CAN_MSG_ERROR_ISR_CALLBACK
            Vehicle_CAN_MsgErrorIsr_Callback();
        #endif /* Vehicle_CAN_MSG_ERROR_ISR_CALLBACK */
    }
#endif /* Vehicle_CAN_FORM_ERR */


#if (Vehicle_CAN_CRC_ERR)
    /*******************************************************************************
    * FUNCTION NAME:   Vehicle_CAN_CrcErrorIsr
    ********************************************************************************
    *
    * Summary:
    *  This function is entry point to CRC Error Interrupt. Clears CRC Error
    *  interrupt flag. Only generated if CRC Error Interrupt enable in Customizer.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Reentrant:
    *  Depends on Customer code.
    *
    *******************************************************************************/
    void Vehicle_CAN_CrcErrorIsr(void) 
    {
        /* Clear CRC Error flag */
        Vehicle_CAN_INT_SR_REG.byte[1u] = Vehicle_CAN_CRC_ERROR_MASK;

        /* `#START CRC_ERROR_ISR` */

        /* `#END` */

        #ifdef Vehicle_CAN_CRC_ERROR_ISR_CALLBACK
            Vehicle_CAN_CrcErrorIsr_Callback();
        #endif /* Vehicle_CAN_CRC_ERROR_ISR_CALLBACK */
    }
#endif /* Vehicle_CAN_CRC_ERR */


#if (Vehicle_CAN_BUS_OFF)
    /*******************************************************************************
    * FUNCTION NAME:   Vehicle_CAN_BusOffIsr
    ********************************************************************************
    *
    * Summary:
    *  This function is entry point to Bus Off Interrupt. Places CAN Component
    *  to Stop mode. Only generated if Bus Off Interrupt enable in Customizer.
    *  Recommended setting to enable this interrupt.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Side Effects:
    *  Stops CAN component operation.
    *
    *******************************************************************************/
    void Vehicle_CAN_BusOffIsr(void) 
    {
        /* Clear Bus Off flag */
        Vehicle_CAN_INT_SR_REG.byte[1u] = Vehicle_CAN_BUS_OFF_MASK;
        (void) Vehicle_CAN_GlobalIntDisable();

        /* `#START BUS_OFF_ISR` */

        /* `#END` */

        #ifdef Vehicle_CAN_BUS_OFF_ISR_CALLBACK
            Vehicle_CAN_BusOffIsr_Callback();
        #endif /* Vehicle_CAN_BUS_OFF_ISR_CALLBACK */

        (void) Vehicle_CAN_Stop();
    }
#endif /* Vehicle_CAN_BUS_OFF */


#if (Vehicle_CAN_RX_MSG_LOST)
    /*******************************************************************************
    * FUNCTION NAME:   Vehicle_CAN_MsgLostIsr
    ********************************************************************************
    *
    * Summary:
    *  This function is entry point to Message Lost Interrupt. Clears Message Lost
    *  interrupt flag. Only generated if Message Lost Interrupt enable in Customizer
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Reentrant:
    *  Depends on Customer code.
    *
    *******************************************************************************/
    void Vehicle_CAN_MsgLostIsr(void) 
    {
        /* Clear Receive Message Lost flag */
        Vehicle_CAN_INT_SR_REG.byte[1u] = Vehicle_CAN_RX_MSG_LOST_MASK;

        /* `#START MESSAGE_LOST_ISR` */

        /* `#END` */

        #ifdef Vehicle_CAN_MSG_LOST_ISR_CALLBACK
            Vehicle_CAN_MsgLostIsr_Callback();
        #endif /* Vehicle_CAN_MSG_LOST_ISR_CALLBACK */
    }
#endif /* Vehicle_CAN_RX_MSG_LOST */


#if (Vehicle_CAN_TX_MESSAGE)
    /*******************************************************************************
    * FUNCTION NAME:   Vehicle_CAN_MsgTXIsr
    ********************************************************************************
    *
    * Summary:
    *  This function is entry point to Transmit Message Interrupt. Clears Transmit
    *  Message interrupt flag. Only generated if Transmit Message Interrupt enable
    *  in Customizer.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Reentrant:
    *  Depends on Customer code.
    *
    *******************************************************************************/
    void Vehicle_CAN_MsgTXIsr(void) 
    {
        /* Clear Transmit Message flag */
        Vehicle_CAN_INT_SR_REG.byte[1u] = Vehicle_CAN_TX_MESSAGE_MASK;

        /* `#START MESSAGE_TRANSMITTED_ISR` */

        /* `#END` */

        #ifdef Vehicle_CAN_MSG_TX_ISR_CALLBACK
            Vehicle_CAN_MsgTXIsr_Callback();
        #endif /* Vehicle_CAN_MSG_TX_ISR_CALLBACK */
    }
#endif /* Vehicle_CAN_TX_MESSAGE */


#if (Vehicle_CAN_RX_MESSAGE)
    /*******************************************************************************
    * FUNCTION NAME:   Vehicle_CAN_MsgRXIsr
    ********************************************************************************
    *
    * Summary:
    *  This function is entry point to Receive Message Interrupt. Clears Receive
    *  Message interrupt flag and call appropriate handlers for Basic and Full
    *  interrupt based mailboxes. Only generated if Receive Message Interrupt
    *  enable in Customizer. Recommended setting to enable this interrupt.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void Vehicle_CAN_MsgRXIsr(void) 
    {
        uint8 mailboxNumber;
        uint16 shift = 0x01u;

        /* Clear Receive Message flag */
        Vehicle_CAN_INT_SR_REG.byte[1u] = Vehicle_CAN_RX_MESSAGE_MASK;

        /* `#START MESSAGE_RECEIVE_ISR` */

        /* `#END` */

        #ifdef Vehicle_CAN_MSG_RX_ISR_CALLBACK
            Vehicle_CAN_MsgRXIsr_Callback();
        #endif /* Vehicle_CAN_MSG_RX_ISR_CALLBACK */

        for (mailboxNumber = 0u; mailboxNumber < Vehicle_CAN_NUMBER_OF_RX_MAILBOXES; mailboxNumber++)
        {
            if ((CY_GET_REG16((reg16 *) &Vehicle_CAN_BUF_SR_REG.byte[0u]) & shift) != 0u)
            {
                if ((Vehicle_CAN_RX[mailboxNumber].rxcmd.byte[0u] & Vehicle_CAN_RX_INT_ENABLE_MASK) != 0u)
                {
                    if ((Vehicle_CAN_RX_MAILBOX_TYPE & shift) != 0u)
                    {
                        /* RX Full mailboxes handler */
                    }
                    else
                    {
                        /* RX Basic mailbox handler */
                        Vehicle_CAN_ReceiveMsg(mailboxNumber);
                    }
                }
            }
            shift <<= 1u;
        }
    }
#endif /* Vehicle_CAN_RX_MESSAGE */


/*******************************************************************************
* Function Name: Vehicle_CAN_ISR
********************************************************************************
*
* Summary:
*  This ISR is executed when CAN Core generates and interrupt on one of events:
*  Arb_lost, Overload, Bit_err, Stuff_err, Ack_err, Form_err, Crc_err,
*  Buss_off, Rx_msg_lost, Tx_msg or Rx_msg. The interrupt sources depends
*  on the Customizer inputs.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
CY_ISR(Vehicle_CAN_ISR)
{
    #ifdef Vehicle_CAN_ISR_INTERRUPT_CALLBACK
        Vehicle_CAN_ISR_InterruptCallback();
    #endif /* Vehicle_CAN_ISR_INTERRUPT_CALLBACK */
    
    /* Place your Interrupt code here. */
    /* `#START CAN_ISR` */

    /* `#END` */
    
    /* Arbitration */
    #if (Vehicle_CAN_ARB_LOST && (Vehicle_CAN_ARB_LOST_USE_HELPER || \
        (!Vehicle_CAN_ADVANCED_INTERRUPT_CFG)))
        if ((Vehicle_CAN_INT_SR_REG.byte[0u] & Vehicle_CAN_ARBITRATION_LOST_MASK) != 0u)
        {
            Vehicle_CAN_ArbLostIsr();
        }
    #endif /* Vehicle_CAN_ARB_LOST && Vehicle_CAN_ARB_LOST_USE_HELPER */

    /* Overload Error */
    #if (Vehicle_CAN_OVERLOAD && (Vehicle_CAN_OVERLOAD_USE_HELPER || \
        (!Vehicle_CAN_ADVANCED_INTERRUPT_CFG)))
        if ((Vehicle_CAN_INT_SR_REG.byte[0u] & Vehicle_CAN_OVERLOAD_ERROR_MASK) != 0u)
        {
            Vehicle_CAN_OvrLdErrorIsr();
        }
    #endif /* Vehicle_CAN_OVERLOAD && Vehicle_CAN_OVERLOAD_USE_HELPER */

    /* Bit Error */
    #if (Vehicle_CAN_BIT_ERR && (Vehicle_CAN_BIT_ERR_USE_HELPER || \
        (!Vehicle_CAN_ADVANCED_INTERRUPT_CFG)))
        if ((Vehicle_CAN_INT_SR_REG.byte[0u] & Vehicle_CAN_BIT_ERROR_MASK) != 0u)
        {
            Vehicle_CAN_BitErrorIsr();
        }
    #endif /* Vehicle_CAN_BIT_ERR && Vehicle_CAN_BIT_ERR_USE_HELPER */

    /* Bit Staff Error */
    #if (Vehicle_CAN_STUFF_ERR && (Vehicle_CAN_STUFF_ERR_USE_HELPER || \
        (!Vehicle_CAN_ADVANCED_INTERRUPT_CFG)))
        if ((Vehicle_CAN_INT_SR_REG.byte[0u] & Vehicle_CAN_STUFF_ERROR_MASK) != 0u)
        {
            Vehicle_CAN_BitStuffErrorIsr();
        }
    #endif /* Vehicle_CAN_STUFF_ERR && Vehicle_CAN_STUFF_ERR_USE_HELPER */

    /* ACK Error */
    #if (Vehicle_CAN_ACK_ERR && (Vehicle_CAN_ACK_ERR_USE_HELPER || \
        (!Vehicle_CAN_ADVANCED_INTERRUPT_CFG)))
        if ((Vehicle_CAN_INT_SR_REG.byte[0u] & Vehicle_CAN_ACK_ERROR_MASK) != 0u)
        {
            Vehicle_CAN_AckErrorIsr();
        }
    #endif /* Vehicle_CAN_ACK_ERR && Vehicle_CAN_ACK_ERR_USE_HELPER */

    /* Form(msg) Error */
    #if (Vehicle_CAN_FORM_ERR && (Vehicle_CAN_FORM_ERR_USE_HELPER || \
        (!Vehicle_CAN_ADVANCED_INTERRUPT_CFG)))
        if ((Vehicle_CAN_INT_SR_REG.byte[0u] & Vehicle_CAN_FORM_ERROR_MASK) != 0u)
        {
            Vehicle_CAN_MsgErrorIsr();
        }
    #endif /* Vehicle_CAN_FORM_ERR && Vehicle_CAN_FORM_ERR_USE_HELPER */

    /* CRC Error */
    #if (Vehicle_CAN_CRC_ERR && (Vehicle_CAN_CRC_ERR_USE_HELPER || \
        (!Vehicle_CAN_ADVANCED_INTERRUPT_CFG)))
        if ((Vehicle_CAN_INT_SR_REG.byte[1u] & Vehicle_CAN_CRC_ERROR_MASK) != 0u)
        {
            Vehicle_CAN_CrcErrorIsr();
        }
    #endif /* Vehicle_CAN_CRC_ERR && Vehicle_CAN_CRC_ERR_USE_HELPER */

    /* Bus Off state */
    #if (Vehicle_CAN_BUS_OFF && (Vehicle_CAN_BUS_OFF_USE_HELPER || \
        (!Vehicle_CAN_ADVANCED_INTERRUPT_CFG)))
        if ((Vehicle_CAN_INT_SR_REG.byte[1u] & Vehicle_CAN_BUS_OFF_MASK) != 0u)
        {
            Vehicle_CAN_BusOffIsr();
        }
    #endif /* Vehicle_CAN_BUS_OFF && Vehicle_CAN_BUS_OFF_USE_HELPER */

    /* Message Lost */
    #if (Vehicle_CAN_RX_MSG_LOST && (Vehicle_CAN_RX_MSG_LOST_USE_HELPER || \
        (!Vehicle_CAN_ADVANCED_INTERRUPT_CFG)))
        if ((Vehicle_CAN_INT_SR_REG.byte[1u] & Vehicle_CAN_RX_MSG_LOST_MASK) != 0u)
        {
            Vehicle_CAN_MsgLostIsr();
        }
    #endif /* Vehicle_CAN_RX_MSG_LOST && Vehicle_CAN_RX_MSG_LOST_USE_HELPER */

    /* TX Message Send */
    #if (Vehicle_CAN_TX_MESSAGE && (Vehicle_CAN_TX_MESSAGE_USE_HELPER || \
        (!Vehicle_CAN_ADVANCED_INTERRUPT_CFG)))
        if ((Vehicle_CAN_INT_SR_REG.byte[1u] & Vehicle_CAN_TX_MESSAGE_MASK) != 0u)
        {
            Vehicle_CAN_MsgTXIsr();
        }
    #endif /* Vehicle_CAN_TX_MESSAGE && Vehicle_CAN_TX_MESSAGE_USE_HELPER */

    /* RX Message Available */
    #if (Vehicle_CAN_RX_MESSAGE && (Vehicle_CAN_RX_MESSAGE_USE_HELPER || \
        (!Vehicle_CAN_ADVANCED_INTERRUPT_CFG)))
        if ((Vehicle_CAN_INT_SR_REG.byte[1u] & Vehicle_CAN_RX_MESSAGE_MASK) != 0u)
        {
            Vehicle_CAN_MsgRXIsr();
        }
    #endif /* Vehicle_CAN_RX_MESSAGE && Vehicle_CAN_RX_MESSAGE_USE_HELPER */
}


/* [] END OF FILE */
