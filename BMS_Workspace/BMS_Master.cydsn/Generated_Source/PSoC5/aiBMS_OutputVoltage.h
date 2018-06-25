/*******************************************************************************
* File Name: aiBMS_OutputVoltage.h  
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

#if !defined(CY_PINS_aiBMS_OutputVoltage_H) /* Pins aiBMS_OutputVoltage_H */
#define CY_PINS_aiBMS_OutputVoltage_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "aiBMS_OutputVoltage_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 aiBMS_OutputVoltage__PORT == 15 && ((aiBMS_OutputVoltage__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    aiBMS_OutputVoltage_Write(uint8 value);
void    aiBMS_OutputVoltage_SetDriveMode(uint8 mode);
uint8   aiBMS_OutputVoltage_ReadDataReg(void);
uint8   aiBMS_OutputVoltage_Read(void);
void    aiBMS_OutputVoltage_SetInterruptMode(uint16 position, uint16 mode);
uint8   aiBMS_OutputVoltage_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the aiBMS_OutputVoltage_SetDriveMode() function.
     *  @{
     */
        #define aiBMS_OutputVoltage_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define aiBMS_OutputVoltage_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define aiBMS_OutputVoltage_DM_RES_UP          PIN_DM_RES_UP
        #define aiBMS_OutputVoltage_DM_RES_DWN         PIN_DM_RES_DWN
        #define aiBMS_OutputVoltage_DM_OD_LO           PIN_DM_OD_LO
        #define aiBMS_OutputVoltage_DM_OD_HI           PIN_DM_OD_HI
        #define aiBMS_OutputVoltage_DM_STRONG          PIN_DM_STRONG
        #define aiBMS_OutputVoltage_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define aiBMS_OutputVoltage_MASK               aiBMS_OutputVoltage__MASK
#define aiBMS_OutputVoltage_SHIFT              aiBMS_OutputVoltage__SHIFT
#define aiBMS_OutputVoltage_WIDTH              1u

/* Interrupt constants */
#if defined(aiBMS_OutputVoltage__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in aiBMS_OutputVoltage_SetInterruptMode() function.
     *  @{
     */
        #define aiBMS_OutputVoltage_INTR_NONE      (uint16)(0x0000u)
        #define aiBMS_OutputVoltage_INTR_RISING    (uint16)(0x0001u)
        #define aiBMS_OutputVoltage_INTR_FALLING   (uint16)(0x0002u)
        #define aiBMS_OutputVoltage_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define aiBMS_OutputVoltage_INTR_MASK      (0x01u) 
#endif /* (aiBMS_OutputVoltage__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define aiBMS_OutputVoltage_PS                     (* (reg8 *) aiBMS_OutputVoltage__PS)
/* Data Register */
#define aiBMS_OutputVoltage_DR                     (* (reg8 *) aiBMS_OutputVoltage__DR)
/* Port Number */
#define aiBMS_OutputVoltage_PRT_NUM                (* (reg8 *) aiBMS_OutputVoltage__PRT) 
/* Connect to Analog Globals */                                                  
#define aiBMS_OutputVoltage_AG                     (* (reg8 *) aiBMS_OutputVoltage__AG)                       
/* Analog MUX bux enable */
#define aiBMS_OutputVoltage_AMUX                   (* (reg8 *) aiBMS_OutputVoltage__AMUX) 
/* Bidirectional Enable */                                                        
#define aiBMS_OutputVoltage_BIE                    (* (reg8 *) aiBMS_OutputVoltage__BIE)
/* Bit-mask for Aliased Register Access */
#define aiBMS_OutputVoltage_BIT_MASK               (* (reg8 *) aiBMS_OutputVoltage__BIT_MASK)
/* Bypass Enable */
#define aiBMS_OutputVoltage_BYP                    (* (reg8 *) aiBMS_OutputVoltage__BYP)
/* Port wide control signals */                                                   
#define aiBMS_OutputVoltage_CTL                    (* (reg8 *) aiBMS_OutputVoltage__CTL)
/* Drive Modes */
#define aiBMS_OutputVoltage_DM0                    (* (reg8 *) aiBMS_OutputVoltage__DM0) 
#define aiBMS_OutputVoltage_DM1                    (* (reg8 *) aiBMS_OutputVoltage__DM1)
#define aiBMS_OutputVoltage_DM2                    (* (reg8 *) aiBMS_OutputVoltage__DM2) 
/* Input Buffer Disable Override */
#define aiBMS_OutputVoltage_INP_DIS                (* (reg8 *) aiBMS_OutputVoltage__INP_DIS)
/* LCD Common or Segment Drive */
#define aiBMS_OutputVoltage_LCD_COM_SEG            (* (reg8 *) aiBMS_OutputVoltage__LCD_COM_SEG)
/* Enable Segment LCD */
#define aiBMS_OutputVoltage_LCD_EN                 (* (reg8 *) aiBMS_OutputVoltage__LCD_EN)
/* Slew Rate Control */
#define aiBMS_OutputVoltage_SLW                    (* (reg8 *) aiBMS_OutputVoltage__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define aiBMS_OutputVoltage_PRTDSI__CAPS_SEL       (* (reg8 *) aiBMS_OutputVoltage__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define aiBMS_OutputVoltage_PRTDSI__DBL_SYNC_IN    (* (reg8 *) aiBMS_OutputVoltage__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define aiBMS_OutputVoltage_PRTDSI__OE_SEL0        (* (reg8 *) aiBMS_OutputVoltage__PRTDSI__OE_SEL0) 
#define aiBMS_OutputVoltage_PRTDSI__OE_SEL1        (* (reg8 *) aiBMS_OutputVoltage__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define aiBMS_OutputVoltage_PRTDSI__OUT_SEL0       (* (reg8 *) aiBMS_OutputVoltage__PRTDSI__OUT_SEL0) 
#define aiBMS_OutputVoltage_PRTDSI__OUT_SEL1       (* (reg8 *) aiBMS_OutputVoltage__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define aiBMS_OutputVoltage_PRTDSI__SYNC_OUT       (* (reg8 *) aiBMS_OutputVoltage__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(aiBMS_OutputVoltage__SIO_CFG)
    #define aiBMS_OutputVoltage_SIO_HYST_EN        (* (reg8 *) aiBMS_OutputVoltage__SIO_HYST_EN)
    #define aiBMS_OutputVoltage_SIO_REG_HIFREQ     (* (reg8 *) aiBMS_OutputVoltage__SIO_REG_HIFREQ)
    #define aiBMS_OutputVoltage_SIO_CFG            (* (reg8 *) aiBMS_OutputVoltage__SIO_CFG)
    #define aiBMS_OutputVoltage_SIO_DIFF           (* (reg8 *) aiBMS_OutputVoltage__SIO_DIFF)
#endif /* (aiBMS_OutputVoltage__SIO_CFG) */

/* Interrupt Registers */
#if defined(aiBMS_OutputVoltage__INTSTAT)
    #define aiBMS_OutputVoltage_INTSTAT            (* (reg8 *) aiBMS_OutputVoltage__INTSTAT)
    #define aiBMS_OutputVoltage_SNAP               (* (reg8 *) aiBMS_OutputVoltage__SNAP)
    
	#define aiBMS_OutputVoltage_0_INTTYPE_REG 		(* (reg8 *) aiBMS_OutputVoltage__0__INTTYPE)
#endif /* (aiBMS_OutputVoltage__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_aiBMS_OutputVoltage_H */


/* [] END OF FILE */
