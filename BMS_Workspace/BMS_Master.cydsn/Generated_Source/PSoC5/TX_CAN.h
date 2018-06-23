/*******************************************************************************
* File Name: TX_CAN.h  
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

#if !defined(CY_PINS_TX_CAN_H) /* Pins TX_CAN_H */
#define CY_PINS_TX_CAN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TX_CAN_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TX_CAN__PORT == 15 && ((TX_CAN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    TX_CAN_Write(uint8 value);
void    TX_CAN_SetDriveMode(uint8 mode);
uint8   TX_CAN_ReadDataReg(void);
uint8   TX_CAN_Read(void);
void    TX_CAN_SetInterruptMode(uint16 position, uint16 mode);
uint8   TX_CAN_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the TX_CAN_SetDriveMode() function.
     *  @{
     */
        #define TX_CAN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define TX_CAN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define TX_CAN_DM_RES_UP          PIN_DM_RES_UP
        #define TX_CAN_DM_RES_DWN         PIN_DM_RES_DWN
        #define TX_CAN_DM_OD_LO           PIN_DM_OD_LO
        #define TX_CAN_DM_OD_HI           PIN_DM_OD_HI
        #define TX_CAN_DM_STRONG          PIN_DM_STRONG
        #define TX_CAN_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define TX_CAN_MASK               TX_CAN__MASK
#define TX_CAN_SHIFT              TX_CAN__SHIFT
#define TX_CAN_WIDTH              1u

/* Interrupt constants */
#if defined(TX_CAN__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in TX_CAN_SetInterruptMode() function.
     *  @{
     */
        #define TX_CAN_INTR_NONE      (uint16)(0x0000u)
        #define TX_CAN_INTR_RISING    (uint16)(0x0001u)
        #define TX_CAN_INTR_FALLING   (uint16)(0x0002u)
        #define TX_CAN_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define TX_CAN_INTR_MASK      (0x01u) 
#endif /* (TX_CAN__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TX_CAN_PS                     (* (reg8 *) TX_CAN__PS)
/* Data Register */
#define TX_CAN_DR                     (* (reg8 *) TX_CAN__DR)
/* Port Number */
#define TX_CAN_PRT_NUM                (* (reg8 *) TX_CAN__PRT) 
/* Connect to Analog Globals */                                                  
#define TX_CAN_AG                     (* (reg8 *) TX_CAN__AG)                       
/* Analog MUX bux enable */
#define TX_CAN_AMUX                   (* (reg8 *) TX_CAN__AMUX) 
/* Bidirectional Enable */                                                        
#define TX_CAN_BIE                    (* (reg8 *) TX_CAN__BIE)
/* Bit-mask for Aliased Register Access */
#define TX_CAN_BIT_MASK               (* (reg8 *) TX_CAN__BIT_MASK)
/* Bypass Enable */
#define TX_CAN_BYP                    (* (reg8 *) TX_CAN__BYP)
/* Port wide control signals */                                                   
#define TX_CAN_CTL                    (* (reg8 *) TX_CAN__CTL)
/* Drive Modes */
#define TX_CAN_DM0                    (* (reg8 *) TX_CAN__DM0) 
#define TX_CAN_DM1                    (* (reg8 *) TX_CAN__DM1)
#define TX_CAN_DM2                    (* (reg8 *) TX_CAN__DM2) 
/* Input Buffer Disable Override */
#define TX_CAN_INP_DIS                (* (reg8 *) TX_CAN__INP_DIS)
/* LCD Common or Segment Drive */
#define TX_CAN_LCD_COM_SEG            (* (reg8 *) TX_CAN__LCD_COM_SEG)
/* Enable Segment LCD */
#define TX_CAN_LCD_EN                 (* (reg8 *) TX_CAN__LCD_EN)
/* Slew Rate Control */
#define TX_CAN_SLW                    (* (reg8 *) TX_CAN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TX_CAN_PRTDSI__CAPS_SEL       (* (reg8 *) TX_CAN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TX_CAN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TX_CAN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TX_CAN_PRTDSI__OE_SEL0        (* (reg8 *) TX_CAN__PRTDSI__OE_SEL0) 
#define TX_CAN_PRTDSI__OE_SEL1        (* (reg8 *) TX_CAN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TX_CAN_PRTDSI__OUT_SEL0       (* (reg8 *) TX_CAN__PRTDSI__OUT_SEL0) 
#define TX_CAN_PRTDSI__OUT_SEL1       (* (reg8 *) TX_CAN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TX_CAN_PRTDSI__SYNC_OUT       (* (reg8 *) TX_CAN__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(TX_CAN__SIO_CFG)
    #define TX_CAN_SIO_HYST_EN        (* (reg8 *) TX_CAN__SIO_HYST_EN)
    #define TX_CAN_SIO_REG_HIFREQ     (* (reg8 *) TX_CAN__SIO_REG_HIFREQ)
    #define TX_CAN_SIO_CFG            (* (reg8 *) TX_CAN__SIO_CFG)
    #define TX_CAN_SIO_DIFF           (* (reg8 *) TX_CAN__SIO_DIFF)
#endif /* (TX_CAN__SIO_CFG) */

/* Interrupt Registers */
#if defined(TX_CAN__INTSTAT)
    #define TX_CAN_INTSTAT            (* (reg8 *) TX_CAN__INTSTAT)
    #define TX_CAN_SNAP               (* (reg8 *) TX_CAN__SNAP)
    
	#define TX_CAN_0_INTTYPE_REG 		(* (reg8 *) TX_CAN__0__INTTYPE)
#endif /* (TX_CAN__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TX_CAN_H */


/* [] END OF FILE */
