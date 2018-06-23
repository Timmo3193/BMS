/*******************************************************************************
* File Name: aiECU_BrakePressureFront.h  
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

#if !defined(CY_PINS_aiECU_BrakePressureFront_H) /* Pins aiECU_BrakePressureFront_H */
#define CY_PINS_aiECU_BrakePressureFront_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "aiECU_BrakePressureFront_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 aiECU_BrakePressureFront__PORT == 15 && ((aiECU_BrakePressureFront__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    aiECU_BrakePressureFront_Write(uint8 value);
void    aiECU_BrakePressureFront_SetDriveMode(uint8 mode);
uint8   aiECU_BrakePressureFront_ReadDataReg(void);
uint8   aiECU_BrakePressureFront_Read(void);
void    aiECU_BrakePressureFront_SetInterruptMode(uint16 position, uint16 mode);
uint8   aiECU_BrakePressureFront_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the aiECU_BrakePressureFront_SetDriveMode() function.
     *  @{
     */
        #define aiECU_BrakePressureFront_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define aiECU_BrakePressureFront_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define aiECU_BrakePressureFront_DM_RES_UP          PIN_DM_RES_UP
        #define aiECU_BrakePressureFront_DM_RES_DWN         PIN_DM_RES_DWN
        #define aiECU_BrakePressureFront_DM_OD_LO           PIN_DM_OD_LO
        #define aiECU_BrakePressureFront_DM_OD_HI           PIN_DM_OD_HI
        #define aiECU_BrakePressureFront_DM_STRONG          PIN_DM_STRONG
        #define aiECU_BrakePressureFront_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define aiECU_BrakePressureFront_MASK               aiECU_BrakePressureFront__MASK
#define aiECU_BrakePressureFront_SHIFT              aiECU_BrakePressureFront__SHIFT
#define aiECU_BrakePressureFront_WIDTH              1u

/* Interrupt constants */
#if defined(aiECU_BrakePressureFront__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in aiECU_BrakePressureFront_SetInterruptMode() function.
     *  @{
     */
        #define aiECU_BrakePressureFront_INTR_NONE      (uint16)(0x0000u)
        #define aiECU_BrakePressureFront_INTR_RISING    (uint16)(0x0001u)
        #define aiECU_BrakePressureFront_INTR_FALLING   (uint16)(0x0002u)
        #define aiECU_BrakePressureFront_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define aiECU_BrakePressureFront_INTR_MASK      (0x01u) 
#endif /* (aiECU_BrakePressureFront__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define aiECU_BrakePressureFront_PS                     (* (reg8 *) aiECU_BrakePressureFront__PS)
/* Data Register */
#define aiECU_BrakePressureFront_DR                     (* (reg8 *) aiECU_BrakePressureFront__DR)
/* Port Number */
#define aiECU_BrakePressureFront_PRT_NUM                (* (reg8 *) aiECU_BrakePressureFront__PRT) 
/* Connect to Analog Globals */                                                  
#define aiECU_BrakePressureFront_AG                     (* (reg8 *) aiECU_BrakePressureFront__AG)                       
/* Analog MUX bux enable */
#define aiECU_BrakePressureFront_AMUX                   (* (reg8 *) aiECU_BrakePressureFront__AMUX) 
/* Bidirectional Enable */                                                        
#define aiECU_BrakePressureFront_BIE                    (* (reg8 *) aiECU_BrakePressureFront__BIE)
/* Bit-mask for Aliased Register Access */
#define aiECU_BrakePressureFront_BIT_MASK               (* (reg8 *) aiECU_BrakePressureFront__BIT_MASK)
/* Bypass Enable */
#define aiECU_BrakePressureFront_BYP                    (* (reg8 *) aiECU_BrakePressureFront__BYP)
/* Port wide control signals */                                                   
#define aiECU_BrakePressureFront_CTL                    (* (reg8 *) aiECU_BrakePressureFront__CTL)
/* Drive Modes */
#define aiECU_BrakePressureFront_DM0                    (* (reg8 *) aiECU_BrakePressureFront__DM0) 
#define aiECU_BrakePressureFront_DM1                    (* (reg8 *) aiECU_BrakePressureFront__DM1)
#define aiECU_BrakePressureFront_DM2                    (* (reg8 *) aiECU_BrakePressureFront__DM2) 
/* Input Buffer Disable Override */
#define aiECU_BrakePressureFront_INP_DIS                (* (reg8 *) aiECU_BrakePressureFront__INP_DIS)
/* LCD Common or Segment Drive */
#define aiECU_BrakePressureFront_LCD_COM_SEG            (* (reg8 *) aiECU_BrakePressureFront__LCD_COM_SEG)
/* Enable Segment LCD */
#define aiECU_BrakePressureFront_LCD_EN                 (* (reg8 *) aiECU_BrakePressureFront__LCD_EN)
/* Slew Rate Control */
#define aiECU_BrakePressureFront_SLW                    (* (reg8 *) aiECU_BrakePressureFront__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define aiECU_BrakePressureFront_PRTDSI__CAPS_SEL       (* (reg8 *) aiECU_BrakePressureFront__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define aiECU_BrakePressureFront_PRTDSI__DBL_SYNC_IN    (* (reg8 *) aiECU_BrakePressureFront__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define aiECU_BrakePressureFront_PRTDSI__OE_SEL0        (* (reg8 *) aiECU_BrakePressureFront__PRTDSI__OE_SEL0) 
#define aiECU_BrakePressureFront_PRTDSI__OE_SEL1        (* (reg8 *) aiECU_BrakePressureFront__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define aiECU_BrakePressureFront_PRTDSI__OUT_SEL0       (* (reg8 *) aiECU_BrakePressureFront__PRTDSI__OUT_SEL0) 
#define aiECU_BrakePressureFront_PRTDSI__OUT_SEL1       (* (reg8 *) aiECU_BrakePressureFront__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define aiECU_BrakePressureFront_PRTDSI__SYNC_OUT       (* (reg8 *) aiECU_BrakePressureFront__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(aiECU_BrakePressureFront__SIO_CFG)
    #define aiECU_BrakePressureFront_SIO_HYST_EN        (* (reg8 *) aiECU_BrakePressureFront__SIO_HYST_EN)
    #define aiECU_BrakePressureFront_SIO_REG_HIFREQ     (* (reg8 *) aiECU_BrakePressureFront__SIO_REG_HIFREQ)
    #define aiECU_BrakePressureFront_SIO_CFG            (* (reg8 *) aiECU_BrakePressureFront__SIO_CFG)
    #define aiECU_BrakePressureFront_SIO_DIFF           (* (reg8 *) aiECU_BrakePressureFront__SIO_DIFF)
#endif /* (aiECU_BrakePressureFront__SIO_CFG) */

/* Interrupt Registers */
#if defined(aiECU_BrakePressureFront__INTSTAT)
    #define aiECU_BrakePressureFront_INTSTAT            (* (reg8 *) aiECU_BrakePressureFront__INTSTAT)
    #define aiECU_BrakePressureFront_SNAP               (* (reg8 *) aiECU_BrakePressureFront__SNAP)
    
	#define aiECU_BrakePressureFront_0_INTTYPE_REG 		(* (reg8 *) aiECU_BrakePressureFront__0__INTTYPE)
#endif /* (aiECU_BrakePressureFront__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_aiECU_BrakePressureFront_H */


/* [] END OF FILE */
