/*******************************************************************************
* File Name: diBMS_RelayNegFdbk.h  
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

#if !defined(CY_PINS_diBMS_RelayNegFdbk_H) /* Pins diBMS_RelayNegFdbk_H */
#define CY_PINS_diBMS_RelayNegFdbk_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "diBMS_RelayNegFdbk_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 diBMS_RelayNegFdbk__PORT == 15 && ((diBMS_RelayNegFdbk__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    diBMS_RelayNegFdbk_Write(uint8 value);
void    diBMS_RelayNegFdbk_SetDriveMode(uint8 mode);
uint8   diBMS_RelayNegFdbk_ReadDataReg(void);
uint8   diBMS_RelayNegFdbk_Read(void);
void    diBMS_RelayNegFdbk_SetInterruptMode(uint16 position, uint16 mode);
uint8   diBMS_RelayNegFdbk_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the diBMS_RelayNegFdbk_SetDriveMode() function.
     *  @{
     */
        #define diBMS_RelayNegFdbk_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define diBMS_RelayNegFdbk_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define diBMS_RelayNegFdbk_DM_RES_UP          PIN_DM_RES_UP
        #define diBMS_RelayNegFdbk_DM_RES_DWN         PIN_DM_RES_DWN
        #define diBMS_RelayNegFdbk_DM_OD_LO           PIN_DM_OD_LO
        #define diBMS_RelayNegFdbk_DM_OD_HI           PIN_DM_OD_HI
        #define diBMS_RelayNegFdbk_DM_STRONG          PIN_DM_STRONG
        #define diBMS_RelayNegFdbk_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define diBMS_RelayNegFdbk_MASK               diBMS_RelayNegFdbk__MASK
#define diBMS_RelayNegFdbk_SHIFT              diBMS_RelayNegFdbk__SHIFT
#define diBMS_RelayNegFdbk_WIDTH              1u

/* Interrupt constants */
#if defined(diBMS_RelayNegFdbk__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in diBMS_RelayNegFdbk_SetInterruptMode() function.
     *  @{
     */
        #define diBMS_RelayNegFdbk_INTR_NONE      (uint16)(0x0000u)
        #define diBMS_RelayNegFdbk_INTR_RISING    (uint16)(0x0001u)
        #define diBMS_RelayNegFdbk_INTR_FALLING   (uint16)(0x0002u)
        #define diBMS_RelayNegFdbk_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define diBMS_RelayNegFdbk_INTR_MASK      (0x01u) 
#endif /* (diBMS_RelayNegFdbk__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define diBMS_RelayNegFdbk_PS                     (* (reg8 *) diBMS_RelayNegFdbk__PS)
/* Data Register */
#define diBMS_RelayNegFdbk_DR                     (* (reg8 *) diBMS_RelayNegFdbk__DR)
/* Port Number */
#define diBMS_RelayNegFdbk_PRT_NUM                (* (reg8 *) diBMS_RelayNegFdbk__PRT) 
/* Connect to Analog Globals */                                                  
#define diBMS_RelayNegFdbk_AG                     (* (reg8 *) diBMS_RelayNegFdbk__AG)                       
/* Analog MUX bux enable */
#define diBMS_RelayNegFdbk_AMUX                   (* (reg8 *) diBMS_RelayNegFdbk__AMUX) 
/* Bidirectional Enable */                                                        
#define diBMS_RelayNegFdbk_BIE                    (* (reg8 *) diBMS_RelayNegFdbk__BIE)
/* Bit-mask for Aliased Register Access */
#define diBMS_RelayNegFdbk_BIT_MASK               (* (reg8 *) diBMS_RelayNegFdbk__BIT_MASK)
/* Bypass Enable */
#define diBMS_RelayNegFdbk_BYP                    (* (reg8 *) diBMS_RelayNegFdbk__BYP)
/* Port wide control signals */                                                   
#define diBMS_RelayNegFdbk_CTL                    (* (reg8 *) diBMS_RelayNegFdbk__CTL)
/* Drive Modes */
#define diBMS_RelayNegFdbk_DM0                    (* (reg8 *) diBMS_RelayNegFdbk__DM0) 
#define diBMS_RelayNegFdbk_DM1                    (* (reg8 *) diBMS_RelayNegFdbk__DM1)
#define diBMS_RelayNegFdbk_DM2                    (* (reg8 *) diBMS_RelayNegFdbk__DM2) 
/* Input Buffer Disable Override */
#define diBMS_RelayNegFdbk_INP_DIS                (* (reg8 *) diBMS_RelayNegFdbk__INP_DIS)
/* LCD Common or Segment Drive */
#define diBMS_RelayNegFdbk_LCD_COM_SEG            (* (reg8 *) diBMS_RelayNegFdbk__LCD_COM_SEG)
/* Enable Segment LCD */
#define diBMS_RelayNegFdbk_LCD_EN                 (* (reg8 *) diBMS_RelayNegFdbk__LCD_EN)
/* Slew Rate Control */
#define diBMS_RelayNegFdbk_SLW                    (* (reg8 *) diBMS_RelayNegFdbk__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define diBMS_RelayNegFdbk_PRTDSI__CAPS_SEL       (* (reg8 *) diBMS_RelayNegFdbk__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define diBMS_RelayNegFdbk_PRTDSI__DBL_SYNC_IN    (* (reg8 *) diBMS_RelayNegFdbk__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define diBMS_RelayNegFdbk_PRTDSI__OE_SEL0        (* (reg8 *) diBMS_RelayNegFdbk__PRTDSI__OE_SEL0) 
#define diBMS_RelayNegFdbk_PRTDSI__OE_SEL1        (* (reg8 *) diBMS_RelayNegFdbk__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define diBMS_RelayNegFdbk_PRTDSI__OUT_SEL0       (* (reg8 *) diBMS_RelayNegFdbk__PRTDSI__OUT_SEL0) 
#define diBMS_RelayNegFdbk_PRTDSI__OUT_SEL1       (* (reg8 *) diBMS_RelayNegFdbk__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define diBMS_RelayNegFdbk_PRTDSI__SYNC_OUT       (* (reg8 *) diBMS_RelayNegFdbk__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(diBMS_RelayNegFdbk__SIO_CFG)
    #define diBMS_RelayNegFdbk_SIO_HYST_EN        (* (reg8 *) diBMS_RelayNegFdbk__SIO_HYST_EN)
    #define diBMS_RelayNegFdbk_SIO_REG_HIFREQ     (* (reg8 *) diBMS_RelayNegFdbk__SIO_REG_HIFREQ)
    #define diBMS_RelayNegFdbk_SIO_CFG            (* (reg8 *) diBMS_RelayNegFdbk__SIO_CFG)
    #define diBMS_RelayNegFdbk_SIO_DIFF           (* (reg8 *) diBMS_RelayNegFdbk__SIO_DIFF)
#endif /* (diBMS_RelayNegFdbk__SIO_CFG) */

/* Interrupt Registers */
#if defined(diBMS_RelayNegFdbk__INTSTAT)
    #define diBMS_RelayNegFdbk_INTSTAT            (* (reg8 *) diBMS_RelayNegFdbk__INTSTAT)
    #define diBMS_RelayNegFdbk_SNAP               (* (reg8 *) diBMS_RelayNegFdbk__SNAP)
    
	#define diBMS_RelayNegFdbk_0_INTTYPE_REG 		(* (reg8 *) diBMS_RelayNegFdbk__0__INTTYPE)
#endif /* (diBMS_RelayNegFdbk__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_diBMS_RelayNegFdbk_H */


/* [] END OF FILE */
