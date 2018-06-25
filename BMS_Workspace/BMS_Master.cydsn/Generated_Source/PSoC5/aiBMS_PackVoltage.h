/*******************************************************************************
* File Name: aiBMS_PackVoltage.h  
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

#if !defined(CY_PINS_aiBMS_PackVoltage_H) /* Pins aiBMS_PackVoltage_H */
#define CY_PINS_aiBMS_PackVoltage_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "aiBMS_PackVoltage_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 aiBMS_PackVoltage__PORT == 15 && ((aiBMS_PackVoltage__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    aiBMS_PackVoltage_Write(uint8 value);
void    aiBMS_PackVoltage_SetDriveMode(uint8 mode);
uint8   aiBMS_PackVoltage_ReadDataReg(void);
uint8   aiBMS_PackVoltage_Read(void);
void    aiBMS_PackVoltage_SetInterruptMode(uint16 position, uint16 mode);
uint8   aiBMS_PackVoltage_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the aiBMS_PackVoltage_SetDriveMode() function.
     *  @{
     */
        #define aiBMS_PackVoltage_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define aiBMS_PackVoltage_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define aiBMS_PackVoltage_DM_RES_UP          PIN_DM_RES_UP
        #define aiBMS_PackVoltage_DM_RES_DWN         PIN_DM_RES_DWN
        #define aiBMS_PackVoltage_DM_OD_LO           PIN_DM_OD_LO
        #define aiBMS_PackVoltage_DM_OD_HI           PIN_DM_OD_HI
        #define aiBMS_PackVoltage_DM_STRONG          PIN_DM_STRONG
        #define aiBMS_PackVoltage_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define aiBMS_PackVoltage_MASK               aiBMS_PackVoltage__MASK
#define aiBMS_PackVoltage_SHIFT              aiBMS_PackVoltage__SHIFT
#define aiBMS_PackVoltage_WIDTH              1u

/* Interrupt constants */
#if defined(aiBMS_PackVoltage__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in aiBMS_PackVoltage_SetInterruptMode() function.
     *  @{
     */
        #define aiBMS_PackVoltage_INTR_NONE      (uint16)(0x0000u)
        #define aiBMS_PackVoltage_INTR_RISING    (uint16)(0x0001u)
        #define aiBMS_PackVoltage_INTR_FALLING   (uint16)(0x0002u)
        #define aiBMS_PackVoltage_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define aiBMS_PackVoltage_INTR_MASK      (0x01u) 
#endif /* (aiBMS_PackVoltage__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define aiBMS_PackVoltage_PS                     (* (reg8 *) aiBMS_PackVoltage__PS)
/* Data Register */
#define aiBMS_PackVoltage_DR                     (* (reg8 *) aiBMS_PackVoltage__DR)
/* Port Number */
#define aiBMS_PackVoltage_PRT_NUM                (* (reg8 *) aiBMS_PackVoltage__PRT) 
/* Connect to Analog Globals */                                                  
#define aiBMS_PackVoltage_AG                     (* (reg8 *) aiBMS_PackVoltage__AG)                       
/* Analog MUX bux enable */
#define aiBMS_PackVoltage_AMUX                   (* (reg8 *) aiBMS_PackVoltage__AMUX) 
/* Bidirectional Enable */                                                        
#define aiBMS_PackVoltage_BIE                    (* (reg8 *) aiBMS_PackVoltage__BIE)
/* Bit-mask for Aliased Register Access */
#define aiBMS_PackVoltage_BIT_MASK               (* (reg8 *) aiBMS_PackVoltage__BIT_MASK)
/* Bypass Enable */
#define aiBMS_PackVoltage_BYP                    (* (reg8 *) aiBMS_PackVoltage__BYP)
/* Port wide control signals */                                                   
#define aiBMS_PackVoltage_CTL                    (* (reg8 *) aiBMS_PackVoltage__CTL)
/* Drive Modes */
#define aiBMS_PackVoltage_DM0                    (* (reg8 *) aiBMS_PackVoltage__DM0) 
#define aiBMS_PackVoltage_DM1                    (* (reg8 *) aiBMS_PackVoltage__DM1)
#define aiBMS_PackVoltage_DM2                    (* (reg8 *) aiBMS_PackVoltage__DM2) 
/* Input Buffer Disable Override */
#define aiBMS_PackVoltage_INP_DIS                (* (reg8 *) aiBMS_PackVoltage__INP_DIS)
/* LCD Common or Segment Drive */
#define aiBMS_PackVoltage_LCD_COM_SEG            (* (reg8 *) aiBMS_PackVoltage__LCD_COM_SEG)
/* Enable Segment LCD */
#define aiBMS_PackVoltage_LCD_EN                 (* (reg8 *) aiBMS_PackVoltage__LCD_EN)
/* Slew Rate Control */
#define aiBMS_PackVoltage_SLW                    (* (reg8 *) aiBMS_PackVoltage__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define aiBMS_PackVoltage_PRTDSI__CAPS_SEL       (* (reg8 *) aiBMS_PackVoltage__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define aiBMS_PackVoltage_PRTDSI__DBL_SYNC_IN    (* (reg8 *) aiBMS_PackVoltage__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define aiBMS_PackVoltage_PRTDSI__OE_SEL0        (* (reg8 *) aiBMS_PackVoltage__PRTDSI__OE_SEL0) 
#define aiBMS_PackVoltage_PRTDSI__OE_SEL1        (* (reg8 *) aiBMS_PackVoltage__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define aiBMS_PackVoltage_PRTDSI__OUT_SEL0       (* (reg8 *) aiBMS_PackVoltage__PRTDSI__OUT_SEL0) 
#define aiBMS_PackVoltage_PRTDSI__OUT_SEL1       (* (reg8 *) aiBMS_PackVoltage__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define aiBMS_PackVoltage_PRTDSI__SYNC_OUT       (* (reg8 *) aiBMS_PackVoltage__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(aiBMS_PackVoltage__SIO_CFG)
    #define aiBMS_PackVoltage_SIO_HYST_EN        (* (reg8 *) aiBMS_PackVoltage__SIO_HYST_EN)
    #define aiBMS_PackVoltage_SIO_REG_HIFREQ     (* (reg8 *) aiBMS_PackVoltage__SIO_REG_HIFREQ)
    #define aiBMS_PackVoltage_SIO_CFG            (* (reg8 *) aiBMS_PackVoltage__SIO_CFG)
    #define aiBMS_PackVoltage_SIO_DIFF           (* (reg8 *) aiBMS_PackVoltage__SIO_DIFF)
#endif /* (aiBMS_PackVoltage__SIO_CFG) */

/* Interrupt Registers */
#if defined(aiBMS_PackVoltage__INTSTAT)
    #define aiBMS_PackVoltage_INTSTAT            (* (reg8 *) aiBMS_PackVoltage__INTSTAT)
    #define aiBMS_PackVoltage_SNAP               (* (reg8 *) aiBMS_PackVoltage__SNAP)
    
	#define aiBMS_PackVoltage_0_INTTYPE_REG 		(* (reg8 *) aiBMS_PackVoltage__0__INTTYPE)
#endif /* (aiBMS_PackVoltage__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_aiBMS_PackVoltage_H */


/* [] END OF FILE */
