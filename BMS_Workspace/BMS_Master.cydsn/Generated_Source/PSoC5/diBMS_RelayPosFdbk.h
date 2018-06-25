/*******************************************************************************
* File Name: diBMS_RelayPosFdbk.h  
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

#if !defined(CY_PINS_diBMS_RelayPosFdbk_H) /* Pins diBMS_RelayPosFdbk_H */
#define CY_PINS_diBMS_RelayPosFdbk_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "diBMS_RelayPosFdbk_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 diBMS_RelayPosFdbk__PORT == 15 && ((diBMS_RelayPosFdbk__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    diBMS_RelayPosFdbk_Write(uint8 value);
void    diBMS_RelayPosFdbk_SetDriveMode(uint8 mode);
uint8   diBMS_RelayPosFdbk_ReadDataReg(void);
uint8   diBMS_RelayPosFdbk_Read(void);
void    diBMS_RelayPosFdbk_SetInterruptMode(uint16 position, uint16 mode);
uint8   diBMS_RelayPosFdbk_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the diBMS_RelayPosFdbk_SetDriveMode() function.
     *  @{
     */
        #define diBMS_RelayPosFdbk_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define diBMS_RelayPosFdbk_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define diBMS_RelayPosFdbk_DM_RES_UP          PIN_DM_RES_UP
        #define diBMS_RelayPosFdbk_DM_RES_DWN         PIN_DM_RES_DWN
        #define diBMS_RelayPosFdbk_DM_OD_LO           PIN_DM_OD_LO
        #define diBMS_RelayPosFdbk_DM_OD_HI           PIN_DM_OD_HI
        #define diBMS_RelayPosFdbk_DM_STRONG          PIN_DM_STRONG
        #define diBMS_RelayPosFdbk_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define diBMS_RelayPosFdbk_MASK               diBMS_RelayPosFdbk__MASK
#define diBMS_RelayPosFdbk_SHIFT              diBMS_RelayPosFdbk__SHIFT
#define diBMS_RelayPosFdbk_WIDTH              1u

/* Interrupt constants */
#if defined(diBMS_RelayPosFdbk__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in diBMS_RelayPosFdbk_SetInterruptMode() function.
     *  @{
     */
        #define diBMS_RelayPosFdbk_INTR_NONE      (uint16)(0x0000u)
        #define diBMS_RelayPosFdbk_INTR_RISING    (uint16)(0x0001u)
        #define diBMS_RelayPosFdbk_INTR_FALLING   (uint16)(0x0002u)
        #define diBMS_RelayPosFdbk_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define diBMS_RelayPosFdbk_INTR_MASK      (0x01u) 
#endif /* (diBMS_RelayPosFdbk__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define diBMS_RelayPosFdbk_PS                     (* (reg8 *) diBMS_RelayPosFdbk__PS)
/* Data Register */
#define diBMS_RelayPosFdbk_DR                     (* (reg8 *) diBMS_RelayPosFdbk__DR)
/* Port Number */
#define diBMS_RelayPosFdbk_PRT_NUM                (* (reg8 *) diBMS_RelayPosFdbk__PRT) 
/* Connect to Analog Globals */                                                  
#define diBMS_RelayPosFdbk_AG                     (* (reg8 *) diBMS_RelayPosFdbk__AG)                       
/* Analog MUX bux enable */
#define diBMS_RelayPosFdbk_AMUX                   (* (reg8 *) diBMS_RelayPosFdbk__AMUX) 
/* Bidirectional Enable */                                                        
#define diBMS_RelayPosFdbk_BIE                    (* (reg8 *) diBMS_RelayPosFdbk__BIE)
/* Bit-mask for Aliased Register Access */
#define diBMS_RelayPosFdbk_BIT_MASK               (* (reg8 *) diBMS_RelayPosFdbk__BIT_MASK)
/* Bypass Enable */
#define diBMS_RelayPosFdbk_BYP                    (* (reg8 *) diBMS_RelayPosFdbk__BYP)
/* Port wide control signals */                                                   
#define diBMS_RelayPosFdbk_CTL                    (* (reg8 *) diBMS_RelayPosFdbk__CTL)
/* Drive Modes */
#define diBMS_RelayPosFdbk_DM0                    (* (reg8 *) diBMS_RelayPosFdbk__DM0) 
#define diBMS_RelayPosFdbk_DM1                    (* (reg8 *) diBMS_RelayPosFdbk__DM1)
#define diBMS_RelayPosFdbk_DM2                    (* (reg8 *) diBMS_RelayPosFdbk__DM2) 
/* Input Buffer Disable Override */
#define diBMS_RelayPosFdbk_INP_DIS                (* (reg8 *) diBMS_RelayPosFdbk__INP_DIS)
/* LCD Common or Segment Drive */
#define diBMS_RelayPosFdbk_LCD_COM_SEG            (* (reg8 *) diBMS_RelayPosFdbk__LCD_COM_SEG)
/* Enable Segment LCD */
#define diBMS_RelayPosFdbk_LCD_EN                 (* (reg8 *) diBMS_RelayPosFdbk__LCD_EN)
/* Slew Rate Control */
#define diBMS_RelayPosFdbk_SLW                    (* (reg8 *) diBMS_RelayPosFdbk__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define diBMS_RelayPosFdbk_PRTDSI__CAPS_SEL       (* (reg8 *) diBMS_RelayPosFdbk__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define diBMS_RelayPosFdbk_PRTDSI__DBL_SYNC_IN    (* (reg8 *) diBMS_RelayPosFdbk__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define diBMS_RelayPosFdbk_PRTDSI__OE_SEL0        (* (reg8 *) diBMS_RelayPosFdbk__PRTDSI__OE_SEL0) 
#define diBMS_RelayPosFdbk_PRTDSI__OE_SEL1        (* (reg8 *) diBMS_RelayPosFdbk__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define diBMS_RelayPosFdbk_PRTDSI__OUT_SEL0       (* (reg8 *) diBMS_RelayPosFdbk__PRTDSI__OUT_SEL0) 
#define diBMS_RelayPosFdbk_PRTDSI__OUT_SEL1       (* (reg8 *) diBMS_RelayPosFdbk__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define diBMS_RelayPosFdbk_PRTDSI__SYNC_OUT       (* (reg8 *) diBMS_RelayPosFdbk__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(diBMS_RelayPosFdbk__SIO_CFG)
    #define diBMS_RelayPosFdbk_SIO_HYST_EN        (* (reg8 *) diBMS_RelayPosFdbk__SIO_HYST_EN)
    #define diBMS_RelayPosFdbk_SIO_REG_HIFREQ     (* (reg8 *) diBMS_RelayPosFdbk__SIO_REG_HIFREQ)
    #define diBMS_RelayPosFdbk_SIO_CFG            (* (reg8 *) diBMS_RelayPosFdbk__SIO_CFG)
    #define diBMS_RelayPosFdbk_SIO_DIFF           (* (reg8 *) diBMS_RelayPosFdbk__SIO_DIFF)
#endif /* (diBMS_RelayPosFdbk__SIO_CFG) */

/* Interrupt Registers */
#if defined(diBMS_RelayPosFdbk__INTSTAT)
    #define diBMS_RelayPosFdbk_INTSTAT            (* (reg8 *) diBMS_RelayPosFdbk__INTSTAT)
    #define diBMS_RelayPosFdbk_SNAP               (* (reg8 *) diBMS_RelayPosFdbk__SNAP)
    
	#define diBMS_RelayPosFdbk_0_INTTYPE_REG 		(* (reg8 *) diBMS_RelayPosFdbk__0__INTTYPE)
#endif /* (diBMS_RelayPosFdbk__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_diBMS_RelayPosFdbk_H */


/* [] END OF FILE */
