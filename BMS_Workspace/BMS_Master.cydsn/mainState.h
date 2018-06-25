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

enum State { 
    BMS_STATE_INIT, 
    BMS_STATE_READY,
    BMS_STATE_CLOSING_RELAYS,
    BMS_STATE_ACTIVE,
    BMS_STATE_CHARGING,
    BMS_STATE_SHUTTING_DOWN,
    BMS_STATE_SLEEP,
    BMS_STATE_FAULT,
    BMS_STATE_UPDATING
};

enum State BMS_State = BMS_STATE_INIT;














/* [] END OF FILE */
