/*******************************************************************************
* File Name: doBMS_RelayPreCharge.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_doBMS_RelayPreCharge_ALIASES_H) /* Pins doBMS_RelayPreCharge_ALIASES_H */
#define CY_PINS_doBMS_RelayPreCharge_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define doBMS_RelayPreCharge_0			(doBMS_RelayPreCharge__0__PC)
#define doBMS_RelayPreCharge_0_INTR	((uint16)((uint16)0x0001u << doBMS_RelayPreCharge__0__SHIFT))

#define doBMS_RelayPreCharge_INTR_ALL	 ((uint16)(doBMS_RelayPreCharge_0_INTR))

#endif /* End Pins doBMS_RelayPreCharge_ALIASES_H */


/* [] END OF FILE */
