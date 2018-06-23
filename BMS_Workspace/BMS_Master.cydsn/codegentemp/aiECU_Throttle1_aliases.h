/*******************************************************************************
* File Name: aiECU_Throttle1.h  
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

#if !defined(CY_PINS_aiECU_Throttle1_ALIASES_H) /* Pins aiECU_Throttle1_ALIASES_H */
#define CY_PINS_aiECU_Throttle1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define aiECU_Throttle1_0			(aiECU_Throttle1__0__PC)
#define aiECU_Throttle1_0_INTR	((uint16)((uint16)0x0001u << aiECU_Throttle1__0__SHIFT))

#define aiECU_Throttle1_INTR_ALL	 ((uint16)(aiECU_Throttle1_0_INTR))

#endif /* End Pins aiECU_Throttle1_ALIASES_H */


/* [] END OF FILE */
