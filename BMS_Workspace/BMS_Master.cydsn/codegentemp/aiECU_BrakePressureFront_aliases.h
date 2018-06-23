/*******************************************************************************
* File Name: aiECU_BrakePressureFront.h  
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

#if !defined(CY_PINS_aiECU_BrakePressureFront_ALIASES_H) /* Pins aiECU_BrakePressureFront_ALIASES_H */
#define CY_PINS_aiECU_BrakePressureFront_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define aiECU_BrakePressureFront_0			(aiECU_BrakePressureFront__0__PC)
#define aiECU_BrakePressureFront_0_INTR	((uint16)((uint16)0x0001u << aiECU_BrakePressureFront__0__SHIFT))

#define aiECU_BrakePressureFront_INTR_ALL	 ((uint16)(aiECU_BrakePressureFront_0_INTR))

#endif /* End Pins aiECU_BrakePressureFront_ALIASES_H */


/* [] END OF FILE */
