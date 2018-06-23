/*******************************************************************************
* File Name: aiTHM_CoolantInlet.h  
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

#if !defined(CY_PINS_aiTHM_CoolantInlet_ALIASES_H) /* Pins aiTHM_CoolantInlet_ALIASES_H */
#define CY_PINS_aiTHM_CoolantInlet_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define aiTHM_CoolantInlet_0			(aiTHM_CoolantInlet__0__PC)
#define aiTHM_CoolantInlet_0_INTR	((uint16)((uint16)0x0001u << aiTHM_CoolantInlet__0__SHIFT))

#define aiTHM_CoolantInlet_INTR_ALL	 ((uint16)(aiTHM_CoolantInlet_0_INTR))

#endif /* End Pins aiTHM_CoolantInlet_ALIASES_H */


/* [] END OF FILE */
