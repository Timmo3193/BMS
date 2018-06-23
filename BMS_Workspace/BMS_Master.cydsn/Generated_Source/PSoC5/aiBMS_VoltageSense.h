/*******************************************************************************
* File Name: aiBMS_VoltageSense.h  
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

#if !defined(CY_PINS_aiBMS_VoltageSense_H) /* Pins aiBMS_VoltageSense_H */
#define CY_PINS_aiBMS_VoltageSense_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "aiBMS_VoltageSense_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 aiBMS_VoltageSense__PORT == 15 && ((aiBMS_VoltageSense__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    aiBMS_VoltageSense_Write(uint8 value);
void    aiBMS_VoltageSense_SetDriveMode(uint8 mode);
uint8   aiBMS_VoltageSense_ReadDataReg(void);
uint8   aiBMS_VoltageSense_Read(void);
void    aiBMS_VoltageSense_SetInterruptMode(uint16 position, uint16 mode);
uint8   aiBMS_VoltageSense_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the aiBMS_VoltageSense_SetDriveMode() function.
     *  @{
     */
        #define aiBMS_VoltageSense_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define aiBMS_VoltageSense_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define aiBMS_VoltageSense_DM_RES_UP          PIN_DM_RES_UP
        #define aiBMS_VoltageSense_DM_RES_DWN         PIN_DM_RES_DWN
        #define aiBMS_VoltageSense_DM_OD_LO           PIN_DM_OD_LO
        #define aiBMS_VoltageSense_DM_OD_HI           PIN_DM_OD_HI
        #define aiBMS_VoltageSense_DM_STRONG          PIN_DM_STRONG
        #define aiBMS_VoltageSense_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define aiBMS_VoltageSense_MASK               aiBMS_VoltageSense__MASK
#define aiBMS_VoltageSense_SHIFT              aiBMS_VoltageSense__SHIFT
#define aiBMS_VoltageSense_WIDTH              1u

/* Interrupt constants */
#if defined(aiBMS_VoltageSense__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in aiBMS_VoltageSense_SetInterruptMode() function.
     *  @{
     */
        #define aiBMS_VoltageSense_INTR_NONE      (uint16)(0x0000u)
        #define aiBMS_VoltageSense_INTR_RISING    (uint16)(0x0001u)
        #define aiBMS_VoltageSense_INTR_FALLING   (uint16)(0x0002u)
        #define aiBMS_VoltageSense_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define aiBMS_VoltageSense_INTR_MASK      (0x01u) 
#endif /* (aiBMS_VoltageSense__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define aiBMS_VoltageSense_PS                     (* (reg8 *) aiBMS_VoltageSense__PS)
/* Data Register */
#define aiBMS_VoltageSense_DR                     (* (reg8 *) aiBMS_VoltageSense__DR)
/* Port Number */
#define aiBMS_VoltageSense_PRT_NUM                (* (reg8 *) aiBMS_VoltageSense__PRT) 
/* Connect to Analog Globals */                                                  
#define aiBMS_VoltageSense_AG                     (* (reg8 *) aiBMS_VoltageSense__AG)                       
/* Analog MUX bux enable */
#define aiBMS_VoltageSense_AMUX                   (* (reg8 *) aiBMS_VoltageSense__AMUX) 
/* Bidirectional Enable */                                                        
#define aiBMS_VoltageSense_BIE                    (* (reg8 *) aiBMS_VoltageSense__BIE)
/* Bit-mask for Aliased Register Access */
#define aiBMS_VoltageSense_BIT_MASK               (* (reg8 *) aiBMS_VoltageSense__BIT_MASK)
/* Bypass Enable */
#define aiBMS_VoltageSense_BYP                    (* (reg8 *) aiBMS_VoltageSense__BYP)
/* Port wide control signals */                                                   
#define aiBMS_VoltageSense_CTL                    (* (reg8 *) aiBMS_VoltageSense__CTL)
/* Drive Modes */
#define aiBMS_VoltageSense_DM0                    (* (reg8 *) aiBMS_VoltageSense__DM0) 
#define aiBMS_VoltageSense_DM1                    (* (reg8 *) aiBMS_VoltageSense__DM1)
#define aiBMS_VoltageSense_DM2                    (* (reg8 *) aiBMS_VoltageSense__DM2) 
/* Input Buffer Disable Override */
#define aiBMS_VoltageSense_INP_DIS                (* (reg8 *) aiBMS_VoltageSense__INP_DIS)
/* LCD Common or Segment Drive */
#define aiBMS_VoltageSense_LCD_COM_SEG            (* (reg8 *) aiBMS_VoltageSense__LCD_COM_SEG)
/* Enable Segment LCD */
#define aiBMS_VoltageSense_LCD_EN                 (* (reg8 *) aiBMS_VoltageSense__LCD_EN)
/* Slew Rate Control */
#define aiBMS_VoltageSense_SLW                    (* (reg8 *) aiBMS_VoltageSense__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define aiBMS_VoltageSense_PRTDSI__CAPS_SEL       (* (reg8 *) aiBMS_VoltageSense__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define aiBMS_VoltageSense_PRTDSI__DBL_SYNC_IN    (* (reg8 *) aiBMS_VoltageSense__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define aiBMS_VoltageSense_PRTDSI__OE_SEL0        (* (reg8 *) aiBMS_VoltageSense__PRTDSI__OE_SEL0) 
#define aiBMS_VoltageSense_PRTDSI__OE_SEL1        (* (reg8 *) aiBMS_VoltageSense__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define aiBMS_VoltageSense_PRTDSI__OUT_SEL0       (* (reg8 *) aiBMS_VoltageSense__PRTDSI__OUT_SEL0) 
#define aiBMS_VoltageSense_PRTDSI__OUT_SEL1       (* (reg8 *) aiBMS_VoltageSense__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define aiBMS_VoltageSense_PRTDSI__SYNC_OUT       (* (reg8 *) aiBMS_VoltageSense__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(aiBMS_VoltageSense__SIO_CFG)
    #define aiBMS_VoltageSense_SIO_HYST_EN        (* (reg8 *) aiBMS_VoltageSense__SIO_HYST_EN)
    #define aiBMS_VoltageSense_SIO_REG_HIFREQ     (* (reg8 *) aiBMS_VoltageSense__SIO_REG_HIFREQ)
    #define aiBMS_VoltageSense_SIO_CFG            (* (reg8 *) aiBMS_VoltageSense__SIO_CFG)
    #define aiBMS_VoltageSense_SIO_DIFF           (* (reg8 *) aiBMS_VoltageSense__SIO_DIFF)
#endif /* (aiBMS_VoltageSense__SIO_CFG) */

/* Interrupt Registers */
#if defined(aiBMS_VoltageSense__INTSTAT)
    #define aiBMS_VoltageSense_INTSTAT            (* (reg8 *) aiBMS_VoltageSense__INTSTAT)
    #define aiBMS_VoltageSense_SNAP               (* (reg8 *) aiBMS_VoltageSense__SNAP)
    
	#define aiBMS_VoltageSense_0_INTTYPE_REG 		(* (reg8 *) aiBMS_VoltageSense__0__INTTYPE)
#endif /* (aiBMS_VoltageSense__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_aiBMS_VoltageSense_H */


/* [] END OF FILE */
