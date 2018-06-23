/*******************************************************************************
* File Name: aiTHM_CoolantInlet.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_aiTHM_CoolantInlet_H) /* Pins aiTHM_CoolantInlet_H */
#define CY_PINS_aiTHM_CoolantInlet_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "aiTHM_CoolantInlet_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 aiTHM_CoolantInlet__PORT == 15 && ((aiTHM_CoolantInlet__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    aiTHM_CoolantInlet_Write(uint8 value);
void    aiTHM_CoolantInlet_SetDriveMode(uint8 mode);
uint8   aiTHM_CoolantInlet_ReadDataReg(void);
uint8   aiTHM_CoolantInlet_Read(void);
void    aiTHM_CoolantInlet_SetInterruptMode(uint16 position, uint16 mode);
uint8   aiTHM_CoolantInlet_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the aiTHM_CoolantInlet_SetDriveMode() function.
     *  @{
     */
        #define aiTHM_CoolantInlet_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define aiTHM_CoolantInlet_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define aiTHM_CoolantInlet_DM_RES_UP          PIN_DM_RES_UP
        #define aiTHM_CoolantInlet_DM_RES_DWN         PIN_DM_RES_DWN
        #define aiTHM_CoolantInlet_DM_OD_LO           PIN_DM_OD_LO
        #define aiTHM_CoolantInlet_DM_OD_HI           PIN_DM_OD_HI
        #define aiTHM_CoolantInlet_DM_STRONG          PIN_DM_STRONG
        #define aiTHM_CoolantInlet_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define aiTHM_CoolantInlet_MASK               aiTHM_CoolantInlet__MASK
#define aiTHM_CoolantInlet_SHIFT              aiTHM_CoolantInlet__SHIFT
#define aiTHM_CoolantInlet_WIDTH              1u

/* Interrupt constants */
#if defined(aiTHM_CoolantInlet__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in aiTHM_CoolantInlet_SetInterruptMode() function.
     *  @{
     */
        #define aiTHM_CoolantInlet_INTR_NONE      (uint16)(0x0000u)
        #define aiTHM_CoolantInlet_INTR_RISING    (uint16)(0x0001u)
        #define aiTHM_CoolantInlet_INTR_FALLING   (uint16)(0x0002u)
        #define aiTHM_CoolantInlet_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define aiTHM_CoolantInlet_INTR_MASK      (0x01u) 
#endif /* (aiTHM_CoolantInlet__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define aiTHM_CoolantInlet_PS                     (* (reg8 *) aiTHM_CoolantInlet__PS)
/* Data Register */
#define aiTHM_CoolantInlet_DR                     (* (reg8 *) aiTHM_CoolantInlet__DR)
/* Port Number */
#define aiTHM_CoolantInlet_PRT_NUM                (* (reg8 *) aiTHM_CoolantInlet__PRT) 
/* Connect to Analog Globals */                                                  
#define aiTHM_CoolantInlet_AG                     (* (reg8 *) aiTHM_CoolantInlet__AG)                       
/* Analog MUX bux enable */
#define aiTHM_CoolantInlet_AMUX                   (* (reg8 *) aiTHM_CoolantInlet__AMUX) 
/* Bidirectional Enable */                                                        
#define aiTHM_CoolantInlet_BIE                    (* (reg8 *) aiTHM_CoolantInlet__BIE)
/* Bit-mask for Aliased Register Access */
#define aiTHM_CoolantInlet_BIT_MASK               (* (reg8 *) aiTHM_CoolantInlet__BIT_MASK)
/* Bypass Enable */
#define aiTHM_CoolantInlet_BYP                    (* (reg8 *) aiTHM_CoolantInlet__BYP)
/* Port wide control signals */                                                   
#define aiTHM_CoolantInlet_CTL                    (* (reg8 *) aiTHM_CoolantInlet__CTL)
/* Drive Modes */
#define aiTHM_CoolantInlet_DM0                    (* (reg8 *) aiTHM_CoolantInlet__DM0) 
#define aiTHM_CoolantInlet_DM1                    (* (reg8 *) aiTHM_CoolantInlet__DM1)
#define aiTHM_CoolantInlet_DM2                    (* (reg8 *) aiTHM_CoolantInlet__DM2) 
/* Input Buffer Disable Override */
#define aiTHM_CoolantInlet_INP_DIS                (* (reg8 *) aiTHM_CoolantInlet__INP_DIS)
/* LCD Common or Segment Drive */
#define aiTHM_CoolantInlet_LCD_COM_SEG            (* (reg8 *) aiTHM_CoolantInlet__LCD_COM_SEG)
/* Enable Segment LCD */
#define aiTHM_CoolantInlet_LCD_EN                 (* (reg8 *) aiTHM_CoolantInlet__LCD_EN)
/* Slew Rate Control */
#define aiTHM_CoolantInlet_SLW                    (* (reg8 *) aiTHM_CoolantInlet__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define aiTHM_CoolantInlet_PRTDSI__CAPS_SEL       (* (reg8 *) aiTHM_CoolantInlet__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define aiTHM_CoolantInlet_PRTDSI__DBL_SYNC_IN    (* (reg8 *) aiTHM_CoolantInlet__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define aiTHM_CoolantInlet_PRTDSI__OE_SEL0        (* (reg8 *) aiTHM_CoolantInlet__PRTDSI__OE_SEL0) 
#define aiTHM_CoolantInlet_PRTDSI__OE_SEL1        (* (reg8 *) aiTHM_CoolantInlet__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define aiTHM_CoolantInlet_PRTDSI__OUT_SEL0       (* (reg8 *) aiTHM_CoolantInlet__PRTDSI__OUT_SEL0) 
#define aiTHM_CoolantInlet_PRTDSI__OUT_SEL1       (* (reg8 *) aiTHM_CoolantInlet__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define aiTHM_CoolantInlet_PRTDSI__SYNC_OUT       (* (reg8 *) aiTHM_CoolantInlet__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(aiTHM_CoolantInlet__SIO_CFG)
    #define aiTHM_CoolantInlet_SIO_HYST_EN        (* (reg8 *) aiTHM_CoolantInlet__SIO_HYST_EN)
    #define aiTHM_CoolantInlet_SIO_REG_HIFREQ     (* (reg8 *) aiTHM_CoolantInlet__SIO_REG_HIFREQ)
    #define aiTHM_CoolantInlet_SIO_CFG            (* (reg8 *) aiTHM_CoolantInlet__SIO_CFG)
    #define aiTHM_CoolantInlet_SIO_DIFF           (* (reg8 *) aiTHM_CoolantInlet__SIO_DIFF)
#endif /* (aiTHM_CoolantInlet__SIO_CFG) */

/* Interrupt Registers */
#if defined(aiTHM_CoolantInlet__INTSTAT)
    #define aiTHM_CoolantInlet_INTSTAT            (* (reg8 *) aiTHM_CoolantInlet__INTSTAT)
    #define aiTHM_CoolantInlet_SNAP               (* (reg8 *) aiTHM_CoolantInlet__SNAP)
    
	#define aiTHM_CoolantInlet_0_INTTYPE_REG 		(* (reg8 *) aiTHM_CoolantInlet__0__INTTYPE)
#endif /* (aiTHM_CoolantInlet__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_aiTHM_CoolantInlet_H */


/* [] END OF FILE */
