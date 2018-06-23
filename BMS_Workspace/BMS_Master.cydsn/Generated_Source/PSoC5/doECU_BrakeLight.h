/*******************************************************************************
* File Name: doECU_BrakeLight.h  
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

#if !defined(CY_PINS_doECU_BrakeLight_H) /* Pins doECU_BrakeLight_H */
#define CY_PINS_doECU_BrakeLight_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "doECU_BrakeLight_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 doECU_BrakeLight__PORT == 15 && ((doECU_BrakeLight__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    doECU_BrakeLight_Write(uint8 value);
void    doECU_BrakeLight_SetDriveMode(uint8 mode);
uint8   doECU_BrakeLight_ReadDataReg(void);
uint8   doECU_BrakeLight_Read(void);
void    doECU_BrakeLight_SetInterruptMode(uint16 position, uint16 mode);
uint8   doECU_BrakeLight_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the doECU_BrakeLight_SetDriveMode() function.
     *  @{
     */
        #define doECU_BrakeLight_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define doECU_BrakeLight_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define doECU_BrakeLight_DM_RES_UP          PIN_DM_RES_UP
        #define doECU_BrakeLight_DM_RES_DWN         PIN_DM_RES_DWN
        #define doECU_BrakeLight_DM_OD_LO           PIN_DM_OD_LO
        #define doECU_BrakeLight_DM_OD_HI           PIN_DM_OD_HI
        #define doECU_BrakeLight_DM_STRONG          PIN_DM_STRONG
        #define doECU_BrakeLight_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define doECU_BrakeLight_MASK               doECU_BrakeLight__MASK
#define doECU_BrakeLight_SHIFT              doECU_BrakeLight__SHIFT
#define doECU_BrakeLight_WIDTH              1u

/* Interrupt constants */
#if defined(doECU_BrakeLight__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in doECU_BrakeLight_SetInterruptMode() function.
     *  @{
     */
        #define doECU_BrakeLight_INTR_NONE      (uint16)(0x0000u)
        #define doECU_BrakeLight_INTR_RISING    (uint16)(0x0001u)
        #define doECU_BrakeLight_INTR_FALLING   (uint16)(0x0002u)
        #define doECU_BrakeLight_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define doECU_BrakeLight_INTR_MASK      (0x01u) 
#endif /* (doECU_BrakeLight__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define doECU_BrakeLight_PS                     (* (reg8 *) doECU_BrakeLight__PS)
/* Data Register */
#define doECU_BrakeLight_DR                     (* (reg8 *) doECU_BrakeLight__DR)
/* Port Number */
#define doECU_BrakeLight_PRT_NUM                (* (reg8 *) doECU_BrakeLight__PRT) 
/* Connect to Analog Globals */                                                  
#define doECU_BrakeLight_AG                     (* (reg8 *) doECU_BrakeLight__AG)                       
/* Analog MUX bux enable */
#define doECU_BrakeLight_AMUX                   (* (reg8 *) doECU_BrakeLight__AMUX) 
/* Bidirectional Enable */                                                        
#define doECU_BrakeLight_BIE                    (* (reg8 *) doECU_BrakeLight__BIE)
/* Bit-mask for Aliased Register Access */
#define doECU_BrakeLight_BIT_MASK               (* (reg8 *) doECU_BrakeLight__BIT_MASK)
/* Bypass Enable */
#define doECU_BrakeLight_BYP                    (* (reg8 *) doECU_BrakeLight__BYP)
/* Port wide control signals */                                                   
#define doECU_BrakeLight_CTL                    (* (reg8 *) doECU_BrakeLight__CTL)
/* Drive Modes */
#define doECU_BrakeLight_DM0                    (* (reg8 *) doECU_BrakeLight__DM0) 
#define doECU_BrakeLight_DM1                    (* (reg8 *) doECU_BrakeLight__DM1)
#define doECU_BrakeLight_DM2                    (* (reg8 *) doECU_BrakeLight__DM2) 
/* Input Buffer Disable Override */
#define doECU_BrakeLight_INP_DIS                (* (reg8 *) doECU_BrakeLight__INP_DIS)
/* LCD Common or Segment Drive */
#define doECU_BrakeLight_LCD_COM_SEG            (* (reg8 *) doECU_BrakeLight__LCD_COM_SEG)
/* Enable Segment LCD */
#define doECU_BrakeLight_LCD_EN                 (* (reg8 *) doECU_BrakeLight__LCD_EN)
/* Slew Rate Control */
#define doECU_BrakeLight_SLW                    (* (reg8 *) doECU_BrakeLight__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define doECU_BrakeLight_PRTDSI__CAPS_SEL       (* (reg8 *) doECU_BrakeLight__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define doECU_BrakeLight_PRTDSI__DBL_SYNC_IN    (* (reg8 *) doECU_BrakeLight__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define doECU_BrakeLight_PRTDSI__OE_SEL0        (* (reg8 *) doECU_BrakeLight__PRTDSI__OE_SEL0) 
#define doECU_BrakeLight_PRTDSI__OE_SEL1        (* (reg8 *) doECU_BrakeLight__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define doECU_BrakeLight_PRTDSI__OUT_SEL0       (* (reg8 *) doECU_BrakeLight__PRTDSI__OUT_SEL0) 
#define doECU_BrakeLight_PRTDSI__OUT_SEL1       (* (reg8 *) doECU_BrakeLight__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define doECU_BrakeLight_PRTDSI__SYNC_OUT       (* (reg8 *) doECU_BrakeLight__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(doECU_BrakeLight__SIO_CFG)
    #define doECU_BrakeLight_SIO_HYST_EN        (* (reg8 *) doECU_BrakeLight__SIO_HYST_EN)
    #define doECU_BrakeLight_SIO_REG_HIFREQ     (* (reg8 *) doECU_BrakeLight__SIO_REG_HIFREQ)
    #define doECU_BrakeLight_SIO_CFG            (* (reg8 *) doECU_BrakeLight__SIO_CFG)
    #define doECU_BrakeLight_SIO_DIFF           (* (reg8 *) doECU_BrakeLight__SIO_DIFF)
#endif /* (doECU_BrakeLight__SIO_CFG) */

/* Interrupt Registers */
#if defined(doECU_BrakeLight__INTSTAT)
    #define doECU_BrakeLight_INTSTAT            (* (reg8 *) doECU_BrakeLight__INTSTAT)
    #define doECU_BrakeLight_SNAP               (* (reg8 *) doECU_BrakeLight__SNAP)
    
	#define doECU_BrakeLight_0_INTTYPE_REG 		(* (reg8 *) doECU_BrakeLight__0__INTTYPE)
#endif /* (doECU_BrakeLight__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_doECU_BrakeLight_H */


/* [] END OF FILE */
