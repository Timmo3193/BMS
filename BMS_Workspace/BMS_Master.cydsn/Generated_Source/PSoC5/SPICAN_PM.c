/*******************************************************************************
* File Name: SPICAN_PM.c
* Version 2.50
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPICAN_PVT.h"

static SPICAN_BACKUP_STRUCT SPICAN_backup =
{
    SPICAN_DISABLED,
    SPICAN_BITCTR_INIT,
};


/*******************************************************************************
* Function Name: SPICAN_SaveConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPICAN_SaveConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPICAN_RestoreConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPICAN_RestoreConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPICAN_Sleep
********************************************************************************
*
* Summary:
*  Prepare SPIM Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPICAN_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPICAN_Sleep(void) 
{
    /* Save components enable state */
    SPICAN_backup.enableState = ((uint8) SPICAN_IS_ENABLED);

    SPICAN_Stop();
}


/*******************************************************************************
* Function Name: SPICAN_Wakeup
********************************************************************************
*
* Summary:
*  Prepare SPIM Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPICAN_backup - used when non-retention registers are restored.
*  SPICAN_txBufferWrite - modified every function call - resets to
*  zero.
*  SPICAN_txBufferRead - modified every function call - resets to
*  zero.
*  SPICAN_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPICAN_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPICAN_Wakeup(void) 
{
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

    /* Clear any data from the RX and TX FIFO */
    SPICAN_ClearFIFO();

    /* Restore components block enable state */
    if(0u != SPICAN_backup.enableState)
    {
        SPICAN_Enable();
    }
}


/* [] END OF FILE */
