/*******************************************************************************
* File Name: doTHM_PumpEn.h  
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

#if !defined(CY_PINS_doTHM_PumpEn_ALIASES_H) /* Pins doTHM_PumpEn_ALIASES_H */
#define CY_PINS_doTHM_PumpEn_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define doTHM_PumpEn_0			(doTHM_PumpEn__0__PC)
#define doTHM_PumpEn_0_INTR	((uint16)((uint16)0x0001u << doTHM_PumpEn__0__SHIFT))

#define doTHM_PumpEn_INTR_ALL	 ((uint16)(doTHM_PumpEn_0_INTR))

#endif /* End Pins doTHM_PumpEn_ALIASES_H */


/* [] END OF FILE */
