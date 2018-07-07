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

#define NTC_MAXPLAUSABLE		100 //degrees <-Convert to data seen on SPI
#define NTC_MINPLAUSABLE		100 //degrees <-Convert to data seen on SPI
#define NUM_LTC_CHIPS           5   //5 Segments, 1 LTC chip each
#define NUM_NTC_PER_LTC         3   //NTC's per chip


int tempMax = 0;
int tempMaxLocation = 0;
int tempMin = 0;
int tempMinLocation = 0;
int tempAverage = 0;
int numValidSensors = 0;


void ReadTempSensors(void);
void SetMessage_CellTemps(void);



/* [] END OF FILE */
