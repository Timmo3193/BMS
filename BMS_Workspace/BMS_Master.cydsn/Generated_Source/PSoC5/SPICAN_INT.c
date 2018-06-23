/*******************************************************************************
* File Name: SPICAN_INT.c
* Version 2.50
*
* Description:
*  This file provides all Interrupt Service Routine (ISR) for the SPI Master
*  component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPICAN_PVT.h"
#include "cyapicallbacks.h"

/* User code required at start of ISR */
/* `#START SPICAN_ISR_START_DEF` */

/* `#END` */


/*******************************************************************************
* Function Name: SPICAN_TX_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for TX portion of the SPI Master.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPICAN_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  SPICAN_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified when exist data to
*  sending and FIFO Not Full.
*  SPICAN_txBuffer[SPICAN_TX_BUFFER_SIZE] - used to store
*  data to sending.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPICAN_TX_ISR)
{
    #if(SPICAN_TX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
    #endif /* (SPICAN_TX_SOFTWARE_BUF_ENABLED) */

    #ifdef SPICAN_TX_ISR_ENTRY_CALLBACK
        SPICAN_TX_ISR_EntryCallback();
    #endif /* SPICAN_TX_ISR_ENTRY_CALLBACK */

    /* User code required at start of ISR */
    /* `#START SPICAN_TX_ISR_START` */

    /* `#END` */
    
    #if(SPICAN_TX_SOFTWARE_BUF_ENABLED)
        /* Check if TX data buffer is not empty and there is space in TX FIFO */
        while(SPICAN_txBufferRead != SPICAN_txBufferWrite)
        {
            tmpStatus = SPICAN_GET_STATUS_TX(SPICAN_swStatusTx);
            SPICAN_swStatusTx = tmpStatus;

            if(0u != (SPICAN_swStatusTx & SPICAN_STS_TX_FIFO_NOT_FULL))
            {
                if(0u == SPICAN_txBufferFull)
                {
                   SPICAN_txBufferRead++;

                    if(SPICAN_txBufferRead >= SPICAN_TX_BUFFER_SIZE)
                    {
                        SPICAN_txBufferRead = 0u;
                    }
                }
                else
                {
                    SPICAN_txBufferFull = 0u;
                }

                /* Put data element into the TX FIFO */
                CY_SET_REG8(SPICAN_TXDATA_PTR, 
                                             SPICAN_txBuffer[SPICAN_txBufferRead]);
            }
            else
            {
                break;
            }
        }

        if(SPICAN_txBufferRead == SPICAN_txBufferWrite)
        {
            /* TX Buffer is EMPTY: disable interrupt on TX NOT FULL */
            SPICAN_TX_STATUS_MASK_REG &= ((uint8) ~SPICAN_STS_TX_FIFO_NOT_FULL);
        }

    #endif /* (SPICAN_TX_SOFTWARE_BUF_ENABLED) */

    /* User code required at end of ISR (Optional) */
    /* `#START SPICAN_TX_ISR_END` */

    /* `#END` */
    
    #ifdef SPICAN_TX_ISR_EXIT_CALLBACK
        SPICAN_TX_ISR_ExitCallback();
    #endif /* SPICAN_TX_ISR_EXIT_CALLBACK */
}


/*******************************************************************************
* Function Name: SPICAN_RX_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for RX portion of the SPI Master.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPICAN_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer modified when FIFO contains
*  new data.
*  SPICAN_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified when overflow occurred.
*  SPICAN_rxBuffer[SPICAN_RX_BUFFER_SIZE] - used to store
*  received data, modified when FIFO contains new data.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPICAN_RX_ISR)
{
    #if(SPICAN_RX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
        uint8 rxData;
    #endif /* (SPICAN_RX_SOFTWARE_BUF_ENABLED) */

    #ifdef SPICAN_RX_ISR_ENTRY_CALLBACK
        SPICAN_RX_ISR_EntryCallback();
    #endif /* SPICAN_RX_ISR_ENTRY_CALLBACK */

    /* User code required at start of ISR */
    /* `#START SPICAN_RX_ISR_START` */

    /* `#END` */
    
    #if(SPICAN_RX_SOFTWARE_BUF_ENABLED)

        tmpStatus = SPICAN_GET_STATUS_RX(SPICAN_swStatusRx);
        SPICAN_swStatusRx = tmpStatus;

        /* Check if RX data FIFO has some data to be moved into the RX Buffer */
        while(0u != (SPICAN_swStatusRx & SPICAN_STS_RX_FIFO_NOT_EMPTY))
        {
            rxData = CY_GET_REG8(SPICAN_RXDATA_PTR);

            /* Set next pointer. */
            SPICAN_rxBufferWrite++;
            if(SPICAN_rxBufferWrite >= SPICAN_RX_BUFFER_SIZE)
            {
                SPICAN_rxBufferWrite = 0u;
            }

            if(SPICAN_rxBufferWrite == SPICAN_rxBufferRead)
            {
                SPICAN_rxBufferRead++;
                if(SPICAN_rxBufferRead >= SPICAN_RX_BUFFER_SIZE)
                {
                    SPICAN_rxBufferRead = 0u;
                }

                SPICAN_rxBufferFull = 1u;
            }

            /* Move data from the FIFO to the Buffer */
            SPICAN_rxBuffer[SPICAN_rxBufferWrite] = rxData;

            tmpStatus = SPICAN_GET_STATUS_RX(SPICAN_swStatusRx);
            SPICAN_swStatusRx = tmpStatus;
        }

    #endif /* (SPICAN_RX_SOFTWARE_BUF_ENABLED) */

    /* User code required at end of ISR (Optional) */
    /* `#START SPICAN_RX_ISR_END` */

    /* `#END` */
    
    #ifdef SPICAN_RX_ISR_EXIT_CALLBACK
        SPICAN_RX_ISR_ExitCallback();
    #endif /* SPICAN_RX_ISR_EXIT_CALLBACK */
}

/* [] END OF FILE */
