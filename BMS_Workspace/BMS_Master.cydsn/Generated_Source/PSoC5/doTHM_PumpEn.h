/*******************************************************************************
* File Name: doTHM_PumpEn.h  
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

#if !defined(CY_PINS_doTHM_PumpEn_H) /* Pins doTHM_PumpEn_H */
#define CY_PINS_doTHM_PumpEn_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "doTHM_PumpEn_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 doTHM_PumpEn__PORT == 15 && ((doTHM_PumpEn__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    doTHM_PumpEn_Write(uint8 value);
void    doTHM_PumpEn_SetDriveMode(uint8 mode);
uint8   doTHM_PumpEn_ReadDataReg(void);
uint8   doTHM_PumpEn_Read(void);
void    doTHM_PumpEn_SetInterruptMode(uint16 position, uint16 mode);
uint8   doTHM_PumpEn_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the doTHM_PumpEn_SetDriveMode() function.
     *  @{
     */
        #define doTHM_PumpEn_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define doTHM_PumpEn_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define doTHM_PumpEn_DM_RES_UP          PIN_DM_RES_UP
        #define doTHM_PumpEn_DM_RES_DWN         PIN_DM_RES_DWN
        #define doTHM_PumpEn_DM_OD_LO           PIN_DM_OD_LO
        #define doTHM_PumpEn_DM_OD_HI           PIN_DM_OD_HI
        #define doTHM_PumpEn_DM_STRONG          PIN_DM_STRONG
        #define doTHM_PumpEn_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define doTHM_PumpEn_MASK               doTHM_PumpEn__MASK
#define doTHM_PumpEn_SHIFT              doTHM_PumpEn__SHIFT
#define doTHM_PumpEn_WIDTH              1u

/* Interrupt constants */
#if defined(doTHM_PumpEn__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in doTHM_PumpEn_SetInterruptMode() function.
     *  @{
     */
        #define doTHM_PumpEn_INTR_NONE      (uint16)(0x0000u)
        #define doTHM_PumpEn_INTR_RISING    (uint16)(0x0001u)
        #define doTHM_PumpEn_INTR_FALLING   (uint16)(0x0002u)
        #define doTHM_PumpEn_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define doTHM_PumpEn_INTR_MASK      (0x01u) 
#endif /* (doTHM_PumpEn__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define doTHM_PumpEn_PS                     (* (reg8 *) doTHM_PumpEn__PS)
/* Data Register */
#define doTHM_PumpEn_DR                     (* (reg8 *) doTHM_PumpEn__DR)
/* Port Number */
#define doTHM_PumpEn_PRT_NUM                (* (reg8 *) doTHM_PumpEn__PRT) 
/* Connect to Analog Globals */                                                  
#define doTHM_PumpEn_AG                     (* (reg8 *) doTHM_PumpEn__AG)                       
/* Analog MUX bux enable */
#define doTHM_PumpEn_AMUX                   (* (reg8 *) doTHM_PumpEn__AMUX) 
/* Bidirectional Enable */                                                        
#define doTHM_PumpEn_BIE                    (* (reg8 *) doTHM_PumpEn__BIE)
/* Bit-mask for Aliased Register Access */
#define doTHM_PumpEn_BIT_MASK               (* (reg8 *) doTHM_PumpEn__BIT_MASK)
/* Bypass Enable */
#define doTHM_PumpEn_BYP                    (* (reg8 *) doTHM_PumpEn__BYP)
/* Port wide control signals */                                                   
#define doTHM_PumpEn_CTL                    (* (reg8 *) doTHM_PumpEn__CTL)
/* Drive Modes */
#define doTHM_PumpEn_DM0                    (* (reg8 *) doTHM_PumpEn__DM0) 
#define doTHM_PumpEn_DM1                    (* (reg8 *) doTHM_PumpEn__DM1)
#define doTHM_PumpEn_DM2                    (* (reg8 *) doTHM_PumpEn__DM2) 
/* Input Buffer Disable Override */
#define doTHM_PumpEn_INP_DIS                (* (reg8 *) doTHM_PumpEn__INP_DIS)
/* LCD Common or Segment Drive */
#define doTHM_PumpEn_LCD_COM_SEG            (* (reg8 *) doTHM_PumpEn__LCD_COM_SEG)
/* Enable Segment LCD */
#define doTHM_PumpEn_LCD_EN                 (* (reg8 *) doTHM_PumpEn__LCD_EN)
/* Slew Rate Control */
#define doTHM_PumpEn_SLW                    (* (reg8 *) doTHM_PumpEn__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define doTHM_PumpEn_PRTDSI__CAPS_SEL       (* (reg8 *) doTHM_PumpEn__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define doTHM_PumpEn_PRTDSI__DBL_SYNC_IN    (* (reg8 *) doTHM_PumpEn__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define doTHM_PumpEn_PRTDSI__OE_SEL0        (* (reg8 *) doTHM_PumpEn__PRTDSI__OE_SEL0) 
#define doTHM_PumpEn_PRTDSI__OE_SEL1        (* (reg8 *) doTHM_PumpEn__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define doTHM_PumpEn_PRTDSI__OUT_SEL0       (* (reg8 *) doTHM_PumpEn__PRTDSI__OUT_SEL0) 
#define doTHM_PumpEn_PRTDSI__OUT_SEL1       (* (reg8 *) doTHM_PumpEn__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define doTHM_PumpEn_PRTDSI__SYNC_OUT       (* (reg8 *) doTHM_PumpEn__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(doTHM_PumpEn__SIO_CFG)
    #define doTHM_PumpEn_SIO_HYST_EN        (* (reg8 *) doTHM_PumpEn__SIO_HYST_EN)
    #define doTHM_PumpEn_SIO_REG_HIFREQ     (* (reg8 *) doTHM_PumpEn__SIO_REG_HIFREQ)
    #define doTHM_PumpEn_SIO_CFG            (* (reg8 *) doTHM_PumpEn__SIO_CFG)
    #define doTHM_PumpEn_SIO_DIFF           (* (reg8 *) doTHM_PumpEn__SIO_DIFF)
#endif /* (doTHM_PumpEn__SIO_CFG) */

/* Interrupt Registers */
#if defined(doTHM_PumpEn__INTSTAT)
    #define doTHM_PumpEn_INTSTAT            (* (reg8 *) doTHM_PumpEn__INTSTAT)
    #define doTHM_PumpEn_SNAP               (* (reg8 *) doTHM_PumpEn__SNAP)
    
	#define doTHM_PumpEn_0_INTTYPE_REG 		(* (reg8 *) doTHM_PumpEn__0__INTTYPE)
#endif /* (doTHM_PumpEn__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_doTHM_PumpEn_H */


/* [] END OF FILE */
