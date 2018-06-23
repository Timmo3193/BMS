/*******************************************************************************
* File Name: .h
* Version 2.50
*
* Description:
*  This private header file contains internal definitions for the SPIM
*  component. Do not use these definitions directly in your application.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIM_PVT_SPICAN_H)
#define CY_SPIM_PVT_SPICAN_H

#include "SPICAN.h"


/**********************************
*   Functions with external linkage
**********************************/


/**********************************
*   Variables with external linkage
**********************************/

extern volatile uint8 SPICAN_swStatusTx;
extern volatile uint8 SPICAN_swStatusRx;

#if(SPICAN_TX_SOFTWARE_BUF_ENABLED)
    extern volatile uint8 SPICAN_txBuffer[SPICAN_TX_BUFFER_SIZE];
    extern volatile uint8 SPICAN_txBufferRead;
    extern volatile uint8 SPICAN_txBufferWrite;
    extern volatile uint8 SPICAN_txBufferFull;
#endif /* (SPICAN_TX_SOFTWARE_BUF_ENABLED) */

#if(SPICAN_RX_SOFTWARE_BUF_ENABLED)
    extern volatile uint8 SPICAN_rxBuffer[SPICAN_RX_BUFFER_SIZE];
    extern volatile uint8 SPICAN_rxBufferRead;
    extern volatile uint8 SPICAN_rxBufferWrite;
    extern volatile uint8 SPICAN_rxBufferFull;
#endif /* (SPICAN_RX_SOFTWARE_BUF_ENABLED) */

#endif /* CY_SPIM_PVT_SPICAN_H */


/* [] END OF FILE */
