/*******************************************************************************
* File Name: SPICAN.c
* Version 2.50
*
* Description:
*  This file provides all API functionality of the SPI Master component.
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

#if(SPICAN_TX_SOFTWARE_BUF_ENABLED)
    volatile uint8 SPICAN_txBuffer[SPICAN_TX_BUFFER_SIZE];
    volatile uint8 SPICAN_txBufferFull;
    volatile uint8 SPICAN_txBufferRead;
    volatile uint8 SPICAN_txBufferWrite;
#endif /* (SPICAN_TX_SOFTWARE_BUF_ENABLED) */

#if(SPICAN_RX_SOFTWARE_BUF_ENABLED)
    volatile uint8 SPICAN_rxBuffer[SPICAN_RX_BUFFER_SIZE];
    volatile uint8 SPICAN_rxBufferFull;
    volatile uint8 SPICAN_rxBufferRead;
    volatile uint8 SPICAN_rxBufferWrite;
#endif /* (SPICAN_RX_SOFTWARE_BUF_ENABLED) */

uint8 SPICAN_initVar = 0u;

volatile uint8 SPICAN_swStatusTx;
volatile uint8 SPICAN_swStatusRx;


/*******************************************************************************
* Function Name: SPICAN_Init
********************************************************************************
*
* Summary:
*  Inits/Restores default SPIM configuration provided with customizer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  When this function is called it initializes all of the necessary parameters
*  for execution. i.e. setting the initial interrupt mask, configuring the
*  interrupt service routine, configuring the bit-counter parameters and
*  clearing the FIFO and Status Register.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPICAN_Init(void) 
{
    /* Initialize the Bit counter */
    SPICAN_COUNTER_PERIOD_REG = SPICAN_BITCTR_INIT;

    /* Init TX ISR  */
    #if(0u != SPICAN_INTERNAL_TX_INT_ENABLED)
        CyIntDisable         (SPICAN_TX_ISR_NUMBER);
        CyIntSetPriority     (SPICAN_TX_ISR_NUMBER,  SPICAN_TX_ISR_PRIORITY);
        (void) CyIntSetVector(SPICAN_TX_ISR_NUMBER, &SPICAN_TX_ISR);
    #endif /* (0u != SPICAN_INTERNAL_TX_INT_ENABLED) */

    /* Init RX ISR  */
    #if(0u != SPICAN_INTERNAL_RX_INT_ENABLED)
        CyIntDisable         (SPICAN_RX_ISR_NUMBER);
        CyIntSetPriority     (SPICAN_RX_ISR_NUMBER,  SPICAN_RX_ISR_PRIORITY);
        (void) CyIntSetVector(SPICAN_RX_ISR_NUMBER, &SPICAN_RX_ISR);
    #endif /* (0u != SPICAN_INTERNAL_RX_INT_ENABLED) */

    /* Clear any stray data from the RX and TX FIFO */
    SPICAN_ClearFIFO();

    #if(SPICAN_RX_SOFTWARE_BUF_ENABLED)
        SPICAN_rxBufferFull  = 0u;
        SPICAN_rxBufferRead  = 0u;
        SPICAN_rxBufferWrite = 0u;
    #endif /* (SPICAN_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPICAN_TX_SOFTWARE_BUF_ENABLED)
        SPICAN_txBufferFull  = 0u;
        SPICAN_txBufferRead  = 0u;
        SPICAN_txBufferWrite = 0u;
    #endif /* (SPICAN_TX_SOFTWARE_BUF_ENABLED) */

    (void) SPICAN_ReadTxStatus(); /* Clear Tx status and swStatusTx */
    (void) SPICAN_ReadRxStatus(); /* Clear Rx status and swStatusRx */

    /* Configure TX and RX interrupt mask */
    SPICAN_TX_STATUS_MASK_REG = SPICAN_TX_INIT_INTERRUPTS_MASK;
    SPICAN_RX_STATUS_MASK_REG = SPICAN_RX_INIT_INTERRUPTS_MASK;
}


/*******************************************************************************
* Function Name: SPICAN_Enable
********************************************************************************
*
* Summary:
*  Enable SPIM component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPICAN_Enable(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    SPICAN_COUNTER_CONTROL_REG |= SPICAN_CNTR_ENABLE;
    SPICAN_TX_STATUS_ACTL_REG  |= SPICAN_INT_ENABLE;
    SPICAN_RX_STATUS_ACTL_REG  |= SPICAN_INT_ENABLE;
    CyExitCriticalSection(enableInterrupts);

    #if(0u != SPICAN_INTERNAL_CLOCK)
        SPICAN_IntClock_Enable();
    #endif /* (0u != SPICAN_INTERNAL_CLOCK) */

    SPICAN_EnableTxInt();
    SPICAN_EnableRxInt();
}


/*******************************************************************************
* Function Name: SPICAN_Start
********************************************************************************
*
* Summary:
*  Initialize and Enable the SPI Master component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPICAN_initVar - used to check initial configuration, modified on
*  first function call.
*
* Theory:
*  Enable the clock input to enable operation.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPICAN_Start(void) 
{
    if(0u == SPICAN_initVar)
    {
        SPICAN_Init();
        SPICAN_initVar = 1u;
    }

    SPICAN_Enable();
}


/*******************************************************************************
* Function Name: SPICAN_Stop
********************************************************************************
*
* Summary:
*  Disable the SPI Master component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the clock input to enable operation.
*
*******************************************************************************/
void SPICAN_Stop(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    SPICAN_TX_STATUS_ACTL_REG &= ((uint8) ~SPICAN_INT_ENABLE);
    SPICAN_RX_STATUS_ACTL_REG &= ((uint8) ~SPICAN_INT_ENABLE);
    CyExitCriticalSection(enableInterrupts);

    #if(0u != SPICAN_INTERNAL_CLOCK)
        SPICAN_IntClock_Disable();
    #endif /* (0u != SPICAN_INTERNAL_CLOCK) */

    SPICAN_DisableTxInt();
    SPICAN_DisableRxInt();
}


/*******************************************************************************
* Function Name: SPICAN_EnableTxInt
********************************************************************************
*
* Summary:
*  Enable internal Tx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal Tx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPICAN_EnableTxInt(void) 
{
    #if(0u != SPICAN_INTERNAL_TX_INT_ENABLED)
        CyIntEnable(SPICAN_TX_ISR_NUMBER);
    #endif /* (0u != SPICAN_INTERNAL_TX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPICAN_EnableRxInt
********************************************************************************
*
* Summary:
*  Enable internal Rx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal Rx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPICAN_EnableRxInt(void) 
{
    #if(0u != SPICAN_INTERNAL_RX_INT_ENABLED)
        CyIntEnable(SPICAN_RX_ISR_NUMBER);
    #endif /* (0u != SPICAN_INTERNAL_RX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPICAN_DisableTxInt
********************************************************************************
*
* Summary:
*  Disable internal Tx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal Tx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPICAN_DisableTxInt(void) 
{
    #if(0u != SPICAN_INTERNAL_TX_INT_ENABLED)
        CyIntDisable(SPICAN_TX_ISR_NUMBER);
    #endif /* (0u != SPICAN_INTERNAL_TX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPICAN_DisableRxInt
********************************************************************************
*
* Summary:
*  Disable internal Rx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal Rx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPICAN_DisableRxInt(void) 
{
    #if(0u != SPICAN_INTERNAL_RX_INT_ENABLED)
        CyIntDisable(SPICAN_RX_ISR_NUMBER);
    #endif /* (0u != SPICAN_INTERNAL_RX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPICAN_SetTxInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void SPICAN_SetTxInterruptMode(uint8 intSrc) 
{
    SPICAN_TX_STATUS_MASK_REG = intSrc;
}


/*******************************************************************************
* Function Name: SPICAN_SetRxInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void SPICAN_SetRxInterruptMode(uint8 intSrc) 
{
    SPICAN_RX_STATUS_MASK_REG  = intSrc;
}


/*******************************************************************************
* Function Name: SPICAN_ReadTxStatus
********************************************************************************
*
* Summary:
*  Read the Tx status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the Tx status register.
*
* Global variables:
*  SPICAN_swStatusTx - used to store in software status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the Tx status register for error
*  detection and flow control.
*
* Side Effects:
*  Clear Tx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 SPICAN_ReadTxStatus(void) 
{
    uint8 tmpStatus;

    #if(SPICAN_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        SPICAN_DisableTxInt();

        tmpStatus = SPICAN_GET_STATUS_TX(SPICAN_swStatusTx);
        SPICAN_swStatusTx = 0u;

        SPICAN_EnableTxInt();

    #else

        tmpStatus = SPICAN_TX_STATUS_REG;

    #endif /* (SPICAN_TX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/*******************************************************************************
* Function Name: SPICAN_ReadRxStatus
********************************************************************************
*
* Summary:
*  Read the Rx status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the Rx status register.
*
* Global variables:
*  SPICAN_swStatusRx - used to store in software Rx status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the Rx status register for error
*  detection and flow control.
*
* Side Effects:
*  Clear Rx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 SPICAN_ReadRxStatus(void) 
{
    uint8 tmpStatus;

    #if(SPICAN_RX_SOFTWARE_BUF_ENABLED)
        /* Disable RX interrupt to protect global veriables */
        SPICAN_DisableRxInt();

        tmpStatus = SPICAN_GET_STATUS_RX(SPICAN_swStatusRx);
        SPICAN_swStatusRx = 0u;

        SPICAN_EnableRxInt();

    #else

        tmpStatus = SPICAN_RX_STATUS_REG;

    #endif /* (SPICAN_RX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/*******************************************************************************
* Function Name: SPICAN_WriteTxData
********************************************************************************
*
* Summary:
*  Write a byte of data to be sent across the SPI.
*
* Parameters:
*  txDataByte: The data value to send across the SPI.
*
* Return:
*  None.
*
* Global variables:
*  SPICAN_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call if TX Software Buffer is used.
*  SPICAN_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*  SPICAN_txBuffer[SPICAN_TX_BUFFER_SIZE] - used to store
*  data to sending, modified every function call if TX Software Buffer is used.
*
* Theory:
*  Allows the user to transmit any byte of data in a single transfer.
*
* Side Effects:
*  If this function is called again before the previous byte is finished then
*  the next byte will be appended to the transfer with no time between
*  the byte transfers. Clear Tx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPICAN_WriteTxData(uint8 txData) 
{
    #if(SPICAN_TX_SOFTWARE_BUF_ENABLED)

        uint8 tempStatus;
        uint8 tmpTxBufferRead;

        /* Block if TX buffer is FULL: don't overwrite */
        do
        {
            tmpTxBufferRead = SPICAN_txBufferRead;
            if(0u == tmpTxBufferRead)
            {
                tmpTxBufferRead = (SPICAN_TX_BUFFER_SIZE - 1u);
            }
            else
            {
                tmpTxBufferRead--;
            }

        }while(tmpTxBufferRead == SPICAN_txBufferWrite);

        /* Disable TX interrupt to protect global veriables */
        SPICAN_DisableTxInt();

        tempStatus = SPICAN_GET_STATUS_TX(SPICAN_swStatusTx);
        SPICAN_swStatusTx = tempStatus;


        if((SPICAN_txBufferRead == SPICAN_txBufferWrite) &&
           (0u != (SPICAN_swStatusTx & SPICAN_STS_TX_FIFO_NOT_FULL)))
        {
            /* Put data element into the TX FIFO */
            CY_SET_REG8(SPICAN_TXDATA_PTR, txData);
        }
        else
        {
            /* Add to the TX software buffer */
            SPICAN_txBufferWrite++;
            if(SPICAN_txBufferWrite >= SPICAN_TX_BUFFER_SIZE)
            {
                SPICAN_txBufferWrite = 0u;
            }

            if(SPICAN_txBufferWrite == SPICAN_txBufferRead)
            {
                SPICAN_txBufferRead++;
                if(SPICAN_txBufferRead >= SPICAN_TX_BUFFER_SIZE)
                {
                    SPICAN_txBufferRead = 0u;
                }
                SPICAN_txBufferFull = 1u;
            }

            SPICAN_txBuffer[SPICAN_txBufferWrite] = txData;

            SPICAN_TX_STATUS_MASK_REG |= SPICAN_STS_TX_FIFO_NOT_FULL;
        }

        SPICAN_EnableTxInt();

    #else
        /* Wait until TX FIFO has a place */
        while(0u == (SPICAN_TX_STATUS_REG & SPICAN_STS_TX_FIFO_NOT_FULL))
        {
        }

        /* Put data element into the TX FIFO */
        CY_SET_REG8(SPICAN_TXDATA_PTR, txData);

    #endif /* (SPICAN_TX_SOFTWARE_BUF_ENABLED) */
}


/*******************************************************************************
* Function Name: SPICAN_ReadRxData
********************************************************************************
*
* Summary:
*  Read the next byte of data received across the SPI.
*
* Parameters:
*  None.
*
* Return:
*  The next byte of data read from the FIFO.
*
* Global variables:
*  SPICAN_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  SPICAN_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified every function
*  call if RX Software Buffer is used.
*  SPICAN_rxBuffer[SPICAN_RX_BUFFER_SIZE] - used to store
*  received data.
*
* Theory:
*  Allows the user to read a byte of data received.
*
* Side Effects:
*  Will return invalid data if the FIFO is empty. The user should Call
*  GetRxBufferSize() and if it returns a non-zero value then it is safe to call
*  ReadByte() function.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 SPICAN_ReadRxData(void) 
{
    uint8 rxData;

    #if(SPICAN_RX_SOFTWARE_BUF_ENABLED)

        /* Disable RX interrupt to protect global veriables */
        SPICAN_DisableRxInt();

        if(SPICAN_rxBufferRead != SPICAN_rxBufferWrite)
        {
            if(0u == SPICAN_rxBufferFull)
            {
                SPICAN_rxBufferRead++;
                if(SPICAN_rxBufferRead >= SPICAN_RX_BUFFER_SIZE)
                {
                    SPICAN_rxBufferRead = 0u;
                }
            }
            else
            {
                SPICAN_rxBufferFull = 0u;
            }
        }

        rxData = SPICAN_rxBuffer[SPICAN_rxBufferRead];

        SPICAN_EnableRxInt();

    #else

        rxData = CY_GET_REG8(SPICAN_RXDATA_PTR);

    #endif /* (SPICAN_RX_SOFTWARE_BUF_ENABLED) */

    return(rxData);
}


/*******************************************************************************
* Function Name: SPICAN_GetRxBufferSize
********************************************************************************
*
* Summary:
*  Returns the number of bytes/words of data currently held in the RX buffer.
*  If RX Software Buffer not used then function return 0 if FIFO empty or 1 if
*  FIFO not empty. In another case function return size of RX Software Buffer.
*
* Parameters:
*  None.
*
* Return:
*  Integer count of the number of bytes/words in the RX buffer.
*
* Global variables:
*  SPICAN_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  SPICAN_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
uint8 SPICAN_GetRxBufferSize(void) 
{
    uint8 size;

    #if(SPICAN_RX_SOFTWARE_BUF_ENABLED)

        /* Disable RX interrupt to protect global veriables */
        SPICAN_DisableRxInt();

        if(SPICAN_rxBufferRead == SPICAN_rxBufferWrite)
        {
            size = 0u;
        }
        else if(SPICAN_rxBufferRead < SPICAN_rxBufferWrite)
        {
            size = (SPICAN_rxBufferWrite - SPICAN_rxBufferRead);
        }
        else
        {
            size = (SPICAN_RX_BUFFER_SIZE - SPICAN_rxBufferRead) + SPICAN_rxBufferWrite;
        }

        SPICAN_EnableRxInt();

    #else

        /* We can only know if there is data in the RX FIFO */
        size = (0u != (SPICAN_RX_STATUS_REG & SPICAN_STS_RX_FIFO_NOT_EMPTY)) ? 1u : 0u;

    #endif /* (SPICAN_TX_SOFTWARE_BUF_ENABLED) */

    return(size);
}


/*******************************************************************************
* Function Name: SPICAN_GetTxBufferSize
********************************************************************************
*
* Summary:
*  Returns the number of bytes/words of data currently held in the TX buffer.
*  If TX Software Buffer not used then function return 0 - if FIFO empty, 1 - if
*  FIFO not full, 4 - if FIFO full. In another case function return size of TX
*  Software Buffer.
*
* Parameters:
*  None.
*
* Return:
*  Integer count of the number of bytes/words in the TX buffer.
*
* Global variables:
*  SPICAN_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  SPICAN_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
uint8  SPICAN_GetTxBufferSize(void) 
{
    uint8 size;

    #if(SPICAN_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        SPICAN_DisableTxInt();

        if(SPICAN_txBufferRead == SPICAN_txBufferWrite)
        {
            size = 0u;
        }
        else if(SPICAN_txBufferRead < SPICAN_txBufferWrite)
        {
            size = (SPICAN_txBufferWrite - SPICAN_txBufferRead);
        }
        else
        {
            size = (SPICAN_TX_BUFFER_SIZE - SPICAN_txBufferRead) + SPICAN_txBufferWrite;
        }

        SPICAN_EnableTxInt();

    #else

        size = SPICAN_TX_STATUS_REG;

        if(0u != (size & SPICAN_STS_TX_FIFO_EMPTY))
        {
            size = 0u;
        }
        else if(0u != (size & SPICAN_STS_TX_FIFO_NOT_FULL))
        {
            size = 1u;
        }
        else
        {
            size = SPICAN_FIFO_SIZE;
        }

    #endif /* (SPICAN_TX_SOFTWARE_BUF_ENABLED) */

    return(size);
}


/*******************************************************************************
* Function Name: SPICAN_ClearRxBuffer
********************************************************************************
*
* Summary:
*  Clear the RX RAM buffer by setting the read and write pointers both to zero.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPICAN_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer, modified every function
*  call - resets to zero.
*  SPICAN_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified every function call -
*  resets to zero.
*
* Theory:
*  Setting the pointers to zero makes the system believe there is no data to
*  read and writing will resume at address 0 overwriting any data that may have
*  remained in the RAM.
*
* Side Effects:
*  Any received data not read from the RAM buffer will be lost when overwritten.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPICAN_ClearRxBuffer(void) 
{
    /* Clear Hardware RX FIFO */
    while(0u !=(SPICAN_RX_STATUS_REG & SPICAN_STS_RX_FIFO_NOT_EMPTY))
    {
        (void) CY_GET_REG8(SPICAN_RXDATA_PTR);
    }

    #if(SPICAN_RX_SOFTWARE_BUF_ENABLED)
        /* Disable RX interrupt to protect global veriables */
        SPICAN_DisableRxInt();

        SPICAN_rxBufferFull  = 0u;
        SPICAN_rxBufferRead  = 0u;
        SPICAN_rxBufferWrite = 0u;

        SPICAN_EnableRxInt();
    #endif /* (SPICAN_RX_SOFTWARE_BUF_ENABLED) */
}


/*******************************************************************************
* Function Name: SPICAN_ClearTxBuffer
********************************************************************************
*
* Summary:
*  Clear the TX RAM buffer by setting the read and write pointers both to zero.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPICAN_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call - resets to zero.
*  SPICAN_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified every function call -
*  resets to zero.
*
* Theory:
*  Setting the pointers to zero makes the system believe there is no data to
*  read and writing will resume at address 0 overwriting any data that may have
*  remained in the RAM.
*
* Side Effects:
*  Any data not yet transmitted from the RAM buffer will be lost when
*  overwritten.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPICAN_ClearTxBuffer(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    /* Clear TX FIFO */
    SPICAN_AUX_CONTROL_DP0_REG |= ((uint8)  SPICAN_TX_FIFO_CLR);
    SPICAN_AUX_CONTROL_DP0_REG &= ((uint8) ~SPICAN_TX_FIFO_CLR);

    #if(SPICAN_USE_SECOND_DATAPATH)
        /* Clear TX FIFO for 2nd Datapath */
        SPICAN_AUX_CONTROL_DP1_REG |= ((uint8)  SPICAN_TX_FIFO_CLR);
        SPICAN_AUX_CONTROL_DP1_REG &= ((uint8) ~SPICAN_TX_FIFO_CLR);
    #endif /* (SPICAN_USE_SECOND_DATAPATH) */
    CyExitCriticalSection(enableInterrupts);

    #if(SPICAN_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        SPICAN_DisableTxInt();

        SPICAN_txBufferFull  = 0u;
        SPICAN_txBufferRead  = 0u;
        SPICAN_txBufferWrite = 0u;

        /* Buffer is EMPTY: disable TX FIFO NOT FULL interrupt */
        SPICAN_TX_STATUS_MASK_REG &= ((uint8) ~SPICAN_STS_TX_FIFO_NOT_FULL);

        SPICAN_EnableTxInt();
    #endif /* (SPICAN_TX_SOFTWARE_BUF_ENABLED) */
}


#if(0u != SPICAN_BIDIRECTIONAL_MODE)
    /*******************************************************************************
    * Function Name: SPICAN_TxEnable
    ********************************************************************************
    *
    * Summary:
    *  If the SPI master is configured to use a single bi-directional pin then this
    *  will set the bi-directional pin to transmit.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void SPICAN_TxEnable(void) 
    {
        SPICAN_CONTROL_REG |= SPICAN_CTRL_TX_SIGNAL_EN;
    }


    /*******************************************************************************
    * Function Name: SPICAN_TxDisable
    ********************************************************************************
    *
    * Summary:
    *  If the SPI master is configured to use a single bi-directional pin then this
    *  will set the bi-directional pin to receive.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void SPICAN_TxDisable(void) 
    {
        SPICAN_CONTROL_REG &= ((uint8) ~SPICAN_CTRL_TX_SIGNAL_EN);
    }

#endif /* (0u != SPICAN_BIDIRECTIONAL_MODE) */


/*******************************************************************************
* Function Name: SPICAN_PutArray
********************************************************************************
*
* Summary:
*  Write available data from ROM/RAM to the TX buffer while space is available
*  in the TX buffer. Keep trying until all data is passed to the TX buffer.
*
* Parameters:
*  *buffer: Pointer to the location in RAM containing the data to send
*  byteCount: The number of bytes to move to the transmit buffer.
*
* Return:
*  None.
*
* Side Effects:
*  Will stay in this routine until all data has been sent.  May get locked in
*  this loop if data is not being initiated by the master if there is not
*  enough room in the TX FIFO.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPICAN_PutArray(const uint8 buffer[], uint8 byteCount)
                                                                          
{
    uint8 bufIndex;

    bufIndex = 0u;

    while(byteCount > 0u)
    {
        SPICAN_WriteTxData(buffer[bufIndex]);
        bufIndex++;
        byteCount--;
    }
}


/*******************************************************************************
* Function Name: SPICAN_ClearFIFO
********************************************************************************
*
* Summary:
*  Clear the RX and TX FIFO's of all data for a fresh start.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
void SPICAN_ClearFIFO(void) 
{
    uint8 enableInterrupts;

    /* Clear Hardware RX FIFO */
    while(0u !=(SPICAN_RX_STATUS_REG & SPICAN_STS_RX_FIFO_NOT_EMPTY))
    {
        (void) CY_GET_REG8(SPICAN_RXDATA_PTR);
    }

    enableInterrupts = CyEnterCriticalSection();
    /* Clear TX FIFO */
    SPICAN_AUX_CONTROL_DP0_REG |= ((uint8)  SPICAN_TX_FIFO_CLR);
    SPICAN_AUX_CONTROL_DP0_REG &= ((uint8) ~SPICAN_TX_FIFO_CLR);

    #if(SPICAN_USE_SECOND_DATAPATH)
        /* Clear TX FIFO for 2nd Datapath */
        SPICAN_AUX_CONTROL_DP1_REG |= ((uint8)  SPICAN_TX_FIFO_CLR);
        SPICAN_AUX_CONTROL_DP1_REG &= ((uint8) ~SPICAN_TX_FIFO_CLR);
    #endif /* (SPICAN_USE_SECOND_DATAPATH) */
    CyExitCriticalSection(enableInterrupts);
}


/* Following functions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects.
*/


/*******************************************************************************
* Function Name: SPICAN_EnableInt
********************************************************************************
*
* Summary:
*  Enable internal interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPICAN_EnableInt(void) 
{
    SPICAN_EnableRxInt();
    SPICAN_EnableTxInt();
}


/*******************************************************************************
* Function Name: SPICAN_DisableInt
********************************************************************************
*
* Summary:
*  Disable internal interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPICAN_DisableInt(void) 
{
    SPICAN_DisableTxInt();
    SPICAN_DisableRxInt();
}


/*******************************************************************************
* Function Name: SPICAN_SetInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void SPICAN_SetInterruptMode(uint8 intSrc) 
{
    SPICAN_TX_STATUS_MASK_REG  = (intSrc & ((uint8) ~SPICAN_STS_SPI_IDLE));
    SPICAN_RX_STATUS_MASK_REG  =  intSrc;
}


/*******************************************************************************
* Function Name: SPICAN_ReadStatus
********************************************************************************
*
* Summary:
*  Read the status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the status register.
*
* Global variables:
*  SPICAN_swStatus - used to store in software status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the status register for error detection
*  and flow control.
*
* Side Effects:
*  Clear status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 SPICAN_ReadStatus(void) 
{
    uint8 tmpStatus;

    #if(SPICAN_TX_SOFTWARE_BUF_ENABLED || SPICAN_RX_SOFTWARE_BUF_ENABLED)

        SPICAN_DisableInt();

        tmpStatus  = SPICAN_GET_STATUS_RX(SPICAN_swStatusRx);
        tmpStatus |= SPICAN_GET_STATUS_TX(SPICAN_swStatusTx);
        tmpStatus &= ((uint8) ~SPICAN_STS_SPI_IDLE);

        SPICAN_swStatusTx = 0u;
        SPICAN_swStatusRx = 0u;

        SPICAN_EnableInt();

    #else

        tmpStatus  = SPICAN_RX_STATUS_REG;
        tmpStatus |= SPICAN_TX_STATUS_REG;
        tmpStatus &= ((uint8) ~SPICAN_STS_SPI_IDLE);

    #endif /* (SPICAN_TX_SOFTWARE_BUF_ENABLED || SPICAN_RX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/* [] END OF FILE */
