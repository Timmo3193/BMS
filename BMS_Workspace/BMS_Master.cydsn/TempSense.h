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

#define NTC_MaxPlausable		100 //degrees <-Convert to data seen on SPI
#define NTC_MinPlausable		100 //degrees <-Convert to data seen on SPI



int tempMax = 0;
int tempMaxLocation[] = {0, 0};
int tempMin = 0;
int tempMinLocation[] = {0, 0};
int tempAverage = 0;


void ReadTempSensors();
void SetMessage_CellTemps();



/* [] END OF FILE */
