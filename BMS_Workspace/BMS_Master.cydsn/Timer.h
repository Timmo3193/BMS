/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#define BUSCLOCK_BASE               1/(24*10^6) //24Mhz
#define CAN_MIA_TIMEOUT             20          //20ms





void GlobalTimer_Init(void);
_Bool CAN_MIA_Expired(void);





/* [] END OF FILE */
