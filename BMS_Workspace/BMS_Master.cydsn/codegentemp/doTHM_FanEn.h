/*******************************************************************************
* File Name: doTHM_FanEn.h  
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

#if !defined(CY_PINS_doTHM_FanEn_H) /* Pins doTHM_FanEn_H */
#define CY_PINS_doTHM_FanEn_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "doTHM_FanEn_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 doTHM_FanEn__PORT == 15 && ((doTHM_FanEn__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    doTHM_FanEn_Write(uint8 value);
void    doTHM_FanEn_SetDriveMode(uint8 mode);
uint8   doTHM_FanEn_ReadDataReg(void);
uint8   doTHM_FanEn_Read(void);
void    doTHM_FanEn_SetInterruptMode(uint16 position, uint16 mode);
uint8   doTHM_FanEn_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the doTHM_FanEn_SetDriveMode() function.
     *  @{
     */
        #define doTHM_FanEn_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define doTHM_FanEn_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define doTHM_FanEn_DM_RES_UP          PIN_DM_RES_UP
        #define doTHM_FanEn_DM_RES_DWN         PIN_DM_RES_DWN
        #define doTHM_FanEn_DM_OD_LO           PIN_DM_OD_LO
        #define doTHM_FanEn_DM_OD_HI           PIN_DM_OD_HI
        #define doTHM_FanEn_DM_STRONG          PIN_DM_STRONG
        #define doTHM_FanEn_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define doTHM_FanEn_MASK               doTHM_FanEn__MASK
#define doTHM_FanEn_SHIFT              doTHM_FanEn__SHIFT
#define doTHM_FanEn_WIDTH              1u

/* Interrupt constants */
#if defined(doTHM_FanEn__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in doTHM_FanEn_SetInterruptMode() function.
     *  @{
     */
        #define doTHM_FanEn_INTR_NONE      (uint16)(0x0000u)
        #define doTHM_FanEn_INTR_RISING    (uint16)(0x0001u)
        #define doTHM_FanEn_INTR_FALLING   (uint16)(0x0002u)
        #define doTHM_FanEn_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define doTHM_FanEn_INTR_MASK      (0x01u) 
#endif /* (doTHM_FanEn__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define doTHM_FanEn_PS                     (* (reg8 *) doTHM_FanEn__PS)
/* Data Register */
#define doTHM_FanEn_DR                     (* (reg8 *) doTHM_FanEn__DR)
/* Port Number */
#define doTHM_FanEn_PRT_NUM                (* (reg8 *) doTHM_FanEn__PRT) 
/* Connect to Analog Globals */                                                  
#define doTHM_FanEn_AG                     (* (reg8 *) doTHM_FanEn__AG)                       
/* Analog MUX bux enable */
#define doTHM_FanEn_AMUX                   (* (reg8 *) doTHM_FanEn__AMUX) 
/* Bidirectional Enable */                                                        
#define doTHM_FanEn_BIE                    (* (reg8 *) doTHM_FanEn__BIE)
/* Bit-mask for Aliased Register Access */
#define doTHM_FanEn_BIT_MASK               (* (reg8 *) doTHM_FanEn__BIT_MASK)
/* Bypass Enable */
#define doTHM_FanEn_BYP                    (* (reg8 *) doTHM_FanEn__BYP)
/* Port wide control signals */                                                   
#define doTHM_FanEn_CTL                    (* (reg8 *) doTHM_FanEn__CTL)
/* Drive Modes */
#define doTHM_FanEn_DM0                    (* (reg8 *) doTHM_FanEn__DM0) 
#define doTHM_FanEn_DM1                    (* (reg8 *) doTHM_FanEn__DM1)
#define doTHM_FanEn_DM2                    (* (reg8 *) doTHM_FanEn__DM2) 
/* Input Buffer Disable Override */
#define doTHM_FanEn_INP_DIS                (* (reg8 *) doTHM_FanEn__INP_DIS)
/* LCD Common or Segment Drive */
#define doTHM_FanEn_LCD_COM_SEG            (* (reg8 *) doTHM_FanEn__LCD_COM_SEG)
/* Enable Segment LCD */
#define doTHM_FanEn_LCD_EN                 (* (reg8 *) doTHM_FanEn__LCD_EN)
/* Slew Rate Control */
#define doTHM_FanEn_SLW                    (* (reg8 *) doTHM_FanEn__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define doTHM_FanEn_PRTDSI__CAPS_SEL       (* (reg8 *) doTHM_FanEn__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define doTHM_FanEn_PRTDSI__DBL_SYNC_IN    (* (reg8 *) doTHM_FanEn__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define doTHM_FanEn_PRTDSI__OE_SEL0        (* (reg8 *) doTHM_FanEn__PRTDSI__OE_SEL0) 
#define doTHM_FanEn_PRTDSI__OE_SEL1        (* (reg8 *) doTHM_FanEn__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define doTHM_FanEn_PRTDSI__OUT_SEL0       (* (reg8 *) doTHM_FanEn__PRTDSI__OUT_SEL0) 
#define doTHM_FanEn_PRTDSI__OUT_SEL1       (* (reg8 *) doTHM_FanEn__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define doTHM_FanEn_PRTDSI__SYNC_OUT       (* (reg8 *) doTHM_FanEn__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(doTHM_FanEn__SIO_CFG)
    #define doTHM_FanEn_SIO_HYST_EN        (* (reg8 *) doTHM_FanEn__SIO_HYST_EN)
    #define doTHM_FanEn_SIO_REG_HIFREQ     (* (reg8 *) doTHM_FanEn__SIO_REG_HIFREQ)
    #define doTHM_FanEn_SIO_CFG            (* (reg8 *) doTHM_FanEn__SIO_CFG)
    #define doTHM_FanEn_SIO_DIFF           (* (reg8 *) doTHM_FanEn__SIO_DIFF)
#endif /* (doTHM_FanEn__SIO_CFG) */

/* Interrupt Registers */
#if defined(doTHM_FanEn__INTSTAT)
    #define doTHM_FanEn_INTSTAT            (* (reg8 *) doTHM_FanEn__INTSTAT)
    #define doTHM_FanEn_SNAP               (* (reg8 *) doTHM_FanEn__SNAP)
    
	#define doTHM_FanEn_0_INTTYPE_REG 		(* (reg8 *) doTHM_FanEn__0__INTTYPE)
#endif /* (doTHM_FanEn__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_doTHM_FanEn_H */


/* [] END OF FILE */
