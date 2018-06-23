/*******************************************************************************
* File Name: aiECU_Throttle1.h  
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

#if !defined(CY_PINS_aiECU_Throttle1_H) /* Pins aiECU_Throttle1_H */
#define CY_PINS_aiECU_Throttle1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "aiECU_Throttle1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 aiECU_Throttle1__PORT == 15 && ((aiECU_Throttle1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    aiECU_Throttle1_Write(uint8 value);
void    aiECU_Throttle1_SetDriveMode(uint8 mode);
uint8   aiECU_Throttle1_ReadDataReg(void);
uint8   aiECU_Throttle1_Read(void);
void    aiECU_Throttle1_SetInterruptMode(uint16 position, uint16 mode);
uint8   aiECU_Throttle1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the aiECU_Throttle1_SetDriveMode() function.
     *  @{
     */
        #define aiECU_Throttle1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define aiECU_Throttle1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define aiECU_Throttle1_DM_RES_UP          PIN_DM_RES_UP
        #define aiECU_Throttle1_DM_RES_DWN         PIN_DM_RES_DWN
        #define aiECU_Throttle1_DM_OD_LO           PIN_DM_OD_LO
        #define aiECU_Throttle1_DM_OD_HI           PIN_DM_OD_HI
        #define aiECU_Throttle1_DM_STRONG          PIN_DM_STRONG
        #define aiECU_Throttle1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define aiECU_Throttle1_MASK               aiECU_Throttle1__MASK
#define aiECU_Throttle1_SHIFT              aiECU_Throttle1__SHIFT
#define aiECU_Throttle1_WIDTH              1u

/* Interrupt constants */
#if defined(aiECU_Throttle1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in aiECU_Throttle1_SetInterruptMode() function.
     *  @{
     */
        #define aiECU_Throttle1_INTR_NONE      (uint16)(0x0000u)
        #define aiECU_Throttle1_INTR_RISING    (uint16)(0x0001u)
        #define aiECU_Throttle1_INTR_FALLING   (uint16)(0x0002u)
        #define aiECU_Throttle1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define aiECU_Throttle1_INTR_MASK      (0x01u) 
#endif /* (aiECU_Throttle1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define aiECU_Throttle1_PS                     (* (reg8 *) aiECU_Throttle1__PS)
/* Data Register */
#define aiECU_Throttle1_DR                     (* (reg8 *) aiECU_Throttle1__DR)
/* Port Number */
#define aiECU_Throttle1_PRT_NUM                (* (reg8 *) aiECU_Throttle1__PRT) 
/* Connect to Analog Globals */                                                  
#define aiECU_Throttle1_AG                     (* (reg8 *) aiECU_Throttle1__AG)                       
/* Analog MUX bux enable */
#define aiECU_Throttle1_AMUX                   (* (reg8 *) aiECU_Throttle1__AMUX) 
/* Bidirectional Enable */                                                        
#define aiECU_Throttle1_BIE                    (* (reg8 *) aiECU_Throttle1__BIE)
/* Bit-mask for Aliased Register Access */
#define aiECU_Throttle1_BIT_MASK               (* (reg8 *) aiECU_Throttle1__BIT_MASK)
/* Bypass Enable */
#define aiECU_Throttle1_BYP                    (* (reg8 *) aiECU_Throttle1__BYP)
/* Port wide control signals */                                                   
#define aiECU_Throttle1_CTL                    (* (reg8 *) aiECU_Throttle1__CTL)
/* Drive Modes */
#define aiECU_Throttle1_DM0                    (* (reg8 *) aiECU_Throttle1__DM0) 
#define aiECU_Throttle1_DM1                    (* (reg8 *) aiECU_Throttle1__DM1)
#define aiECU_Throttle1_DM2                    (* (reg8 *) aiECU_Throttle1__DM2) 
/* Input Buffer Disable Override */
#define aiECU_Throttle1_INP_DIS                (* (reg8 *) aiECU_Throttle1__INP_DIS)
/* LCD Common or Segment Drive */
#define aiECU_Throttle1_LCD_COM_SEG            (* (reg8 *) aiECU_Throttle1__LCD_COM_SEG)
/* Enable Segment LCD */
#define aiECU_Throttle1_LCD_EN                 (* (reg8 *) aiECU_Throttle1__LCD_EN)
/* Slew Rate Control */
#define aiECU_Throttle1_SLW                    (* (reg8 *) aiECU_Throttle1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define aiECU_Throttle1_PRTDSI__CAPS_SEL       (* (reg8 *) aiECU_Throttle1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define aiECU_Throttle1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) aiECU_Throttle1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define aiECU_Throttle1_PRTDSI__OE_SEL0        (* (reg8 *) aiECU_Throttle1__PRTDSI__OE_SEL0) 
#define aiECU_Throttle1_PRTDSI__OE_SEL1        (* (reg8 *) aiECU_Throttle1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define aiECU_Throttle1_PRTDSI__OUT_SEL0       (* (reg8 *) aiECU_Throttle1__PRTDSI__OUT_SEL0) 
#define aiECU_Throttle1_PRTDSI__OUT_SEL1       (* (reg8 *) aiECU_Throttle1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define aiECU_Throttle1_PRTDSI__SYNC_OUT       (* (reg8 *) aiECU_Throttle1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(aiECU_Throttle1__SIO_CFG)
    #define aiECU_Throttle1_SIO_HYST_EN        (* (reg8 *) aiECU_Throttle1__SIO_HYST_EN)
    #define aiECU_Throttle1_SIO_REG_HIFREQ     (* (reg8 *) aiECU_Throttle1__SIO_REG_HIFREQ)
    #define aiECU_Throttle1_SIO_CFG            (* (reg8 *) aiECU_Throttle1__SIO_CFG)
    #define aiECU_Throttle1_SIO_DIFF           (* (reg8 *) aiECU_Throttle1__SIO_DIFF)
#endif /* (aiECU_Throttle1__SIO_CFG) */

/* Interrupt Registers */
#if defined(aiECU_Throttle1__INTSTAT)
    #define aiECU_Throttle1_INTSTAT            (* (reg8 *) aiECU_Throttle1__INTSTAT)
    #define aiECU_Throttle1_SNAP               (* (reg8 *) aiECU_Throttle1__SNAP)
    
	#define aiECU_Throttle1_0_INTTYPE_REG 		(* (reg8 *) aiECU_Throttle1__0__INTTYPE)
#endif /* (aiECU_Throttle1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_aiECU_Throttle1_H */


/* [] END OF FILE */
