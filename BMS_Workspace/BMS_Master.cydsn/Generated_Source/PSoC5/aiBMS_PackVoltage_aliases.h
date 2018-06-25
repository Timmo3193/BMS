/*******************************************************************************
* File Name: aiBMS_PackVoltage.h  
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

#if !defined(CY_PINS_aiBMS_PackVoltage_ALIASES_H) /* Pins aiBMS_PackVoltage_ALIASES_H */
#define CY_PINS_aiBMS_PackVoltage_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define aiBMS_PackVoltage_0			(aiBMS_PackVoltage__0__PC)
#define aiBMS_PackVoltage_0_INTR	((uint16)((uint16)0x0001u << aiBMS_PackVoltage__0__SHIFT))

#define aiBMS_PackVoltage_INTR_ALL	 ((uint16)(aiBMS_PackVoltage_0_INTR))

#endif /* End Pins aiBMS_PackVoltage_ALIASES_H */


/* [] END OF FILE */
