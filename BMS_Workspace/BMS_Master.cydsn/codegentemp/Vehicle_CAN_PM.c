/*******************************************************************************
* File Name: Vehicle_CAN_PM.c
* Version 3.0
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in the low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Vehicle_CAN.h"

static Vehicle_CAN_BACKUP_STRUCT Vehicle_CAN_backup =
{
    0u,
    #if (CY_PSOC3 || CY_PSOC5)
        0u,
        Vehicle_CAN_INIT_INTERRUPT_MASK,
        Vehicle_CAN_MODE_MASK,
        (((uint32) ((uint32) Vehicle_CAN_SYNC_EDGE    << Vehicle_CAN_EDGE_MODE_SHIFT))     |
        ((uint32) ((uint32) Vehicle_CAN_SAMPLING_MODE << Vehicle_CAN_SAMPLE_MODE_SHIFT))   |
        ((uint32) ((uint32) Vehicle_CAN_CFG_REG_SJW   << Vehicle_CAN_CFG_REG_SJW_SHIFT))   |
        ((uint32) ((uint32) Vehicle_CAN_RESET_TYPE    << Vehicle_CAN_RESET_SHIFT))         |
        ((uint32) ((uint32) Vehicle_CAN_CFG_REG_TSEG2 << Vehicle_CAN_CFG_REG_TSEG2_SHIFT)) |
        ((uint32) ((uint32) Vehicle_CAN_CFG_REG_TSEG1 << Vehicle_CAN_CFG_REG_TSEG1_SHIFT)) |
        ((uint32) ((uint32) Vehicle_CAN_ARBITER       << Vehicle_CAN_ARBITER_SHIFT))       |
        ((uint32) ((uint32) Vehicle_CAN_BITRATE       << Vehicle_CAN_BITRATE_SHIFT)))
    #endif /* CY_PSOC3 || CY_PSOC5 */
};


/*******************************************************************************
* Function Name: Vehicle_CAN_SaveConfig
********************************************************************************
*
* Summary:
*  Save the CAN configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Vehicle_CAN_backup - Modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Vehicle_CAN_SaveConfig(void) 
{
    #if (CY_PSOC3 || CY_PSOC5)
        Vehicle_CAN_backup.intSr = (CY_GET_REG32(Vehicle_CAN_INT_SR_PTR));
        Vehicle_CAN_backup.intEn = (CY_GET_REG32(Vehicle_CAN_INT_EN_PTR));
        Vehicle_CAN_backup.cmd = (CY_GET_REG32(Vehicle_CAN_CMD_PTR));
        Vehicle_CAN_backup.cfg = (CY_GET_REG32(Vehicle_CAN_CFG_PTR));
    #endif /* CY_PSOC3 || CY_PSOC5 */
}


/*******************************************************************************
* Function Name: Vehicle_CAN_RestoreConfig
********************************************************************************
*
* Summary:
*  Restore the CAN configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Vehicle_CAN_backup - Used when non-retention registers are restored.
*
* Side Effects:
*  If this API is called without first calling SaveConfig then default values
*  from Customizer will be in the following registers: Vehicle_CAN_INT_SR,
*  Vehicle_CAN_INT_EN, Vehicle_CAN_CMD, Vehicle_CAN_CFG.
*
*******************************************************************************/
void Vehicle_CAN_RestoreConfig(void) 
{
    #if (CY_PSOC3 || CY_PSOC5)
        CY_SET_REG32(Vehicle_CAN_INT_SR_PTR, Vehicle_CAN_backup.intSr);
        CY_SET_REG32(Vehicle_CAN_INT_EN_PTR, Vehicle_CAN_backup.intEn);
        CY_SET_REG32(Vehicle_CAN_CMD_PTR, Vehicle_CAN_backup.cmd);
        CY_SET_REG32(Vehicle_CAN_CFG_PTR, Vehicle_CAN_backup.cfg);
    #endif /* CY_PSOC3 || CY_PSOC5 */
}


/*******************************************************************************
* Function Name: Vehicle_CAN_Sleep
********************************************************************************
*
* Summary:
*  Prepares CAN Component to go to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Vehicle_CAN_backup - Modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Vehicle_CAN_Sleep(void) 
{
    #if (!(CY_PSOC3 || CY_PSOC5))
        uint8 i;
    #endif /* (!(CY_PSOC3 || CY_PSOC5)) */

    if (0u != (CY_GET_REG32(Vehicle_CAN_CMD_PTR) & Vehicle_CAN_MODE_MASK))
    {
        Vehicle_CAN_backup.enableState = 1u;
    }
    else /* CAN block is disabled */
    {
        Vehicle_CAN_backup.enableState = 0u;
    }

    #if (CY_PSOC3 || CY_PSOC5)
        Vehicle_CAN_SaveConfig();
        (void) Vehicle_CAN_Stop();
    #else /* CY_PSOC4 */
        /* Abort respective pending TX message requests */
        for (i = 0u; i < Vehicle_CAN_NUMBER_OF_TX_MAILBOXES; i++)
        {
            Vehicle_CAN_TX_ABORT_MESSAGE(i);
        }

        /* Sets CAN controller to Stop mode */
        (void) Vehicle_CAN_Stop();

        /* Clear Global Interrupt enable Flag */
        (void) Vehicle_CAN_GlobalIntDisable();
    #endif /* CY_PSOC3 || CY_PSOC5 */
}


/*******************************************************************************
* Function Name: Vehicle_CAN_Wakeup
********************************************************************************
*
* Summary:
*  Prepares CAN Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Vehicle_CAN_backup - Used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Vehicle_CAN_Wakeup(void) 
{
    #if (CY_PSOC3 || CY_PSOC5)
        /* Enable CAN block in Active mode */
        Vehicle_CAN_PM_ACT_CFG_REG |= Vehicle_CAN_ACT_PWR_EN;
        /* Enable CAN block in Alternate Active (Standby) mode */
        Vehicle_CAN_PM_STBY_CFG_REG |= Vehicle_CAN_STBY_PWR_EN;

        Vehicle_CAN_RestoreConfig();

        /* Reconfigure Rx and Tx Buffers control registers */
        (void) Vehicle_CAN_RxTxBuffersConfig();

        if (Vehicle_CAN_backup.enableState != 0u)
        {
            /* Enable component's operation */
            (void) Vehicle_CAN_Enable();
        } /* Do nothing if component's block was disabled before */
    #else /* CY_PSOC4 */
        /* Clear all INT_STATUS bits */
        Vehicle_CAN_INT_SR_REG = Vehicle_CAN_INT_STATUS_MASK;

        /* Set Global Interrupt enable Flag */
        (void) Vehicle_CAN_GlobalIntEnable();

        if (Vehicle_CAN_backup.enableState != 0u)
        {
            (void) Vehicle_CAN_Enable();
        } /* Do nothing if component's block was disabled before */
    #endif /* CY_PSOC3 || CY_PSOC5 */
}


/* [] END OF FILE */
