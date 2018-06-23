/*******************************************************************************
* File Name: aiECU_BrakePressureRear.h  
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

#if !defined(CY_PINS_aiECU_BrakePressureRear_H) /* Pins aiECU_BrakePressureRear_H */
#define CY_PINS_aiECU_BrakePressureRear_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "aiECU_BrakePressureRear_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 aiECU_BrakePressureRear__PORT == 15 && ((aiECU_BrakePressureRear__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    aiECU_BrakePressureRear_Write(uint8 value);
void    aiECU_BrakePressureRear_SetDriveMode(uint8 mode);
uint8   aiECU_BrakePressureRear_ReadDataReg(void);
uint8   aiECU_BrakePressureRear_Read(void);
void    aiECU_BrakePressureRear_SetInterruptMode(uint16 position, uint16 mode);
uint8   aiECU_BrakePressureRear_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the aiECU_BrakePressureRear_SetDriveMode() function.
     *  @{
     */
        #define aiECU_BrakePressureRear_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define aiECU_BrakePressureRear_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define aiECU_BrakePressureRear_DM_RES_UP          PIN_DM_RES_UP
        #define aiECU_BrakePressureRear_DM_RES_DWN         PIN_DM_RES_DWN
        #define aiECU_BrakePressureRear_DM_OD_LO           PIN_DM_OD_LO
        #define aiECU_BrakePressureRear_DM_OD_HI           PIN_DM_OD_HI
        #define aiECU_BrakePressureRear_DM_STRONG          PIN_DM_STRONG
        #define aiECU_BrakePressureRear_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define aiECU_BrakePressureRear_MASK               aiECU_BrakePressureRear__MASK
#define aiECU_BrakePressureRear_SHIFT              aiECU_BrakePressureRear__SHIFT
#define aiECU_BrakePressureRear_WIDTH              1u

/* Interrupt constants */
#if defined(aiECU_BrakePressureRear__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in aiECU_BrakePressureRear_SetInterruptMode() function.
     *  @{
     */
        #define aiECU_BrakePressureRear_INTR_NONE      (uint16)(0x0000u)
        #define aiECU_BrakePressureRear_INTR_RISING    (uint16)(0x0001u)
        #define aiECU_BrakePressureRear_INTR_FALLING   (uint16)(0x0002u)
        #define aiECU_BrakePressureRear_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define aiECU_BrakePressureRear_INTR_MASK      (0x01u) 
#endif /* (aiECU_BrakePressureRear__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define aiECU_BrakePressureRear_PS                     (* (reg8 *) aiECU_BrakePressureRear__PS)
/* Data Register */
#define aiECU_BrakePressureRear_DR                     (* (reg8 *) aiECU_BrakePressureRear__DR)
/* Port Number */
#define aiECU_BrakePressureRear_PRT_NUM                (* (reg8 *) aiECU_BrakePressureRear__PRT) 
/* Connect to Analog Globals */                                                  
#define aiECU_BrakePressureRear_AG                     (* (reg8 *) aiECU_BrakePressureRear__AG)                       
/* Analog MUX bux enable */
#define aiECU_BrakePressureRear_AMUX                   (* (reg8 *) aiECU_BrakePressureRear__AMUX) 
/* Bidirectional Enable */                                                        
#define aiECU_BrakePressureRear_BIE                    (* (reg8 *) aiECU_BrakePressureRear__BIE)
/* Bit-mask for Aliased Register Access */
#define aiECU_BrakePressureRear_BIT_MASK               (* (reg8 *) aiECU_BrakePressureRear__BIT_MASK)
/* Bypass Enable */
#define aiECU_BrakePressureRear_BYP                    (* (reg8 *) aiECU_BrakePressureRear__BYP)
/* Port wide control signals */                                                   
#define aiECU_BrakePressureRear_CTL                    (* (reg8 *) aiECU_BrakePressureRear__CTL)
/* Drive Modes */
#define aiECU_BrakePressureRear_DM0                    (* (reg8 *) aiECU_BrakePressureRear__DM0) 
#define aiECU_BrakePressureRear_DM1                    (* (reg8 *) aiECU_BrakePressureRear__DM1)
#define aiECU_BrakePressureRear_DM2                    (* (reg8 *) aiECU_BrakePressureRear__DM2) 
/* Input Buffer Disable Override */
#define aiECU_BrakePressureRear_INP_DIS                (* (reg8 *) aiECU_BrakePressureRear__INP_DIS)
/* LCD Common or Segment Drive */
#define aiECU_BrakePressureRear_LCD_COM_SEG            (* (reg8 *) aiECU_BrakePressureRear__LCD_COM_SEG)
/* Enable Segment LCD */
#define aiECU_BrakePressureRear_LCD_EN                 (* (reg8 *) aiECU_BrakePressureRear__LCD_EN)
/* Slew Rate Control */
#define aiECU_BrakePressureRear_SLW                    (* (reg8 *) aiECU_BrakePressureRear__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define aiECU_BrakePressureRear_PRTDSI__CAPS_SEL       (* (reg8 *) aiECU_BrakePressureRear__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define aiECU_BrakePressureRear_PRTDSI__DBL_SYNC_IN    (* (reg8 *) aiECU_BrakePressureRear__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define aiECU_BrakePressureRear_PRTDSI__OE_SEL0        (* (reg8 *) aiECU_BrakePressureRear__PRTDSI__OE_SEL0) 
#define aiECU_BrakePressureRear_PRTDSI__OE_SEL1        (* (reg8 *) aiECU_BrakePressureRear__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define aiECU_BrakePressureRear_PRTDSI__OUT_SEL0       (* (reg8 *) aiECU_BrakePressureRear__PRTDSI__OUT_SEL0) 
#define aiECU_BrakePressureRear_PRTDSI__OUT_SEL1       (* (reg8 *) aiECU_BrakePressureRear__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define aiECU_BrakePressureRear_PRTDSI__SYNC_OUT       (* (reg8 *) aiECU_BrakePressureRear__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(aiECU_BrakePressureRear__SIO_CFG)
    #define aiECU_BrakePressureRear_SIO_HYST_EN        (* (reg8 *) aiECU_BrakePressureRear__SIO_HYST_EN)
    #define aiECU_BrakePressureRear_SIO_REG_HIFREQ     (* (reg8 *) aiECU_BrakePressureRear__SIO_REG_HIFREQ)
    #define aiECU_BrakePressureRear_SIO_CFG            (* (reg8 *) aiECU_BrakePressureRear__SIO_CFG)
    #define aiECU_BrakePressureRear_SIO_DIFF           (* (reg8 *) aiECU_BrakePressureRear__SIO_DIFF)
#endif /* (aiECU_BrakePressureRear__SIO_CFG) */

/* Interrupt Registers */
#if defined(aiECU_BrakePressureRear__INTSTAT)
    #define aiECU_BrakePressureRear_INTSTAT            (* (reg8 *) aiECU_BrakePressureRear__INTSTAT)
    #define aiECU_BrakePressureRear_SNAP               (* (reg8 *) aiECU_BrakePressureRear__SNAP)
    
	#define aiECU_BrakePressureRear_0_INTTYPE_REG 		(* (reg8 *) aiECU_BrakePressureRear__0__INTTYPE)
#endif /* (aiECU_BrakePressureRear__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_aiECU_BrakePressureRear_H */


/* [] END OF FILE */
