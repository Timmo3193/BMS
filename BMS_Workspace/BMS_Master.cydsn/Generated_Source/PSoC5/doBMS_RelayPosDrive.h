/*******************************************************************************
* File Name: doBMS_RelayPosDrive.h  
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

#if !defined(CY_PINS_doBMS_RelayPosDrive_H) /* Pins doBMS_RelayPosDrive_H */
#define CY_PINS_doBMS_RelayPosDrive_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "doBMS_RelayPosDrive_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 doBMS_RelayPosDrive__PORT == 15 && ((doBMS_RelayPosDrive__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    doBMS_RelayPosDrive_Write(uint8 value);
void    doBMS_RelayPosDrive_SetDriveMode(uint8 mode);
uint8   doBMS_RelayPosDrive_ReadDataReg(void);
uint8   doBMS_RelayPosDrive_Read(void);
void    doBMS_RelayPosDrive_SetInterruptMode(uint16 position, uint16 mode);
uint8   doBMS_RelayPosDrive_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the doBMS_RelayPosDrive_SetDriveMode() function.
     *  @{
     */
        #define doBMS_RelayPosDrive_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define doBMS_RelayPosDrive_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define doBMS_RelayPosDrive_DM_RES_UP          PIN_DM_RES_UP
        #define doBMS_RelayPosDrive_DM_RES_DWN         PIN_DM_RES_DWN
        #define doBMS_RelayPosDrive_DM_OD_LO           PIN_DM_OD_LO
        #define doBMS_RelayPosDrive_DM_OD_HI           PIN_DM_OD_HI
        #define doBMS_RelayPosDrive_DM_STRONG          PIN_DM_STRONG
        #define doBMS_RelayPosDrive_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define doBMS_RelayPosDrive_MASK               doBMS_RelayPosDrive__MASK
#define doBMS_RelayPosDrive_SHIFT              doBMS_RelayPosDrive__SHIFT
#define doBMS_RelayPosDrive_WIDTH              1u

/* Interrupt constants */
#if defined(doBMS_RelayPosDrive__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in doBMS_RelayPosDrive_SetInterruptMode() function.
     *  @{
     */
        #define doBMS_RelayPosDrive_INTR_NONE      (uint16)(0x0000u)
        #define doBMS_RelayPosDrive_INTR_RISING    (uint16)(0x0001u)
        #define doBMS_RelayPosDrive_INTR_FALLING   (uint16)(0x0002u)
        #define doBMS_RelayPosDrive_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define doBMS_RelayPosDrive_INTR_MASK      (0x01u) 
#endif /* (doBMS_RelayPosDrive__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define doBMS_RelayPosDrive_PS                     (* (reg8 *) doBMS_RelayPosDrive__PS)
/* Data Register */
#define doBMS_RelayPosDrive_DR                     (* (reg8 *) doBMS_RelayPosDrive__DR)
/* Port Number */
#define doBMS_RelayPosDrive_PRT_NUM                (* (reg8 *) doBMS_RelayPosDrive__PRT) 
/* Connect to Analog Globals */                                                  
#define doBMS_RelayPosDrive_AG                     (* (reg8 *) doBMS_RelayPosDrive__AG)                       
/* Analog MUX bux enable */
#define doBMS_RelayPosDrive_AMUX                   (* (reg8 *) doBMS_RelayPosDrive__AMUX) 
/* Bidirectional Enable */                                                        
#define doBMS_RelayPosDrive_BIE                    (* (reg8 *) doBMS_RelayPosDrive__BIE)
/* Bit-mask for Aliased Register Access */
#define doBMS_RelayPosDrive_BIT_MASK               (* (reg8 *) doBMS_RelayPosDrive__BIT_MASK)
/* Bypass Enable */
#define doBMS_RelayPosDrive_BYP                    (* (reg8 *) doBMS_RelayPosDrive__BYP)
/* Port wide control signals */                                                   
#define doBMS_RelayPosDrive_CTL                    (* (reg8 *) doBMS_RelayPosDrive__CTL)
/* Drive Modes */
#define doBMS_RelayPosDrive_DM0                    (* (reg8 *) doBMS_RelayPosDrive__DM0) 
#define doBMS_RelayPosDrive_DM1                    (* (reg8 *) doBMS_RelayPosDrive__DM1)
#define doBMS_RelayPosDrive_DM2                    (* (reg8 *) doBMS_RelayPosDrive__DM2) 
/* Input Buffer Disable Override */
#define doBMS_RelayPosDrive_INP_DIS                (* (reg8 *) doBMS_RelayPosDrive__INP_DIS)
/* LCD Common or Segment Drive */
#define doBMS_RelayPosDrive_LCD_COM_SEG            (* (reg8 *) doBMS_RelayPosDrive__LCD_COM_SEG)
/* Enable Segment LCD */
#define doBMS_RelayPosDrive_LCD_EN                 (* (reg8 *) doBMS_RelayPosDrive__LCD_EN)
/* Slew Rate Control */
#define doBMS_RelayPosDrive_SLW                    (* (reg8 *) doBMS_RelayPosDrive__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define doBMS_RelayPosDrive_PRTDSI__CAPS_SEL       (* (reg8 *) doBMS_RelayPosDrive__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define doBMS_RelayPosDrive_PRTDSI__DBL_SYNC_IN    (* (reg8 *) doBMS_RelayPosDrive__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define doBMS_RelayPosDrive_PRTDSI__OE_SEL0        (* (reg8 *) doBMS_RelayPosDrive__PRTDSI__OE_SEL0) 
#define doBMS_RelayPosDrive_PRTDSI__OE_SEL1        (* (reg8 *) doBMS_RelayPosDrive__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define doBMS_RelayPosDrive_PRTDSI__OUT_SEL0       (* (reg8 *) doBMS_RelayPosDrive__PRTDSI__OUT_SEL0) 
#define doBMS_RelayPosDrive_PRTDSI__OUT_SEL1       (* (reg8 *) doBMS_RelayPosDrive__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define doBMS_RelayPosDrive_PRTDSI__SYNC_OUT       (* (reg8 *) doBMS_RelayPosDrive__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(doBMS_RelayPosDrive__SIO_CFG)
    #define doBMS_RelayPosDrive_SIO_HYST_EN        (* (reg8 *) doBMS_RelayPosDrive__SIO_HYST_EN)
    #define doBMS_RelayPosDrive_SIO_REG_HIFREQ     (* (reg8 *) doBMS_RelayPosDrive__SIO_REG_HIFREQ)
    #define doBMS_RelayPosDrive_SIO_CFG            (* (reg8 *) doBMS_RelayPosDrive__SIO_CFG)
    #define doBMS_RelayPosDrive_SIO_DIFF           (* (reg8 *) doBMS_RelayPosDrive__SIO_DIFF)
#endif /* (doBMS_RelayPosDrive__SIO_CFG) */

/* Interrupt Registers */
#if defined(doBMS_RelayPosDrive__INTSTAT)
    #define doBMS_RelayPosDrive_INTSTAT            (* (reg8 *) doBMS_RelayPosDrive__INTSTAT)
    #define doBMS_RelayPosDrive_SNAP               (* (reg8 *) doBMS_RelayPosDrive__SNAP)
    
	#define doBMS_RelayPosDrive_0_INTTYPE_REG 		(* (reg8 *) doBMS_RelayPosDrive__0__INTTYPE)
#endif /* (doBMS_RelayPosDrive__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_doBMS_RelayPosDrive_H */


/* [] END OF FILE */
