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
//PUT THESE INTO TEMPSENSE.H
#define NTC_MaxPlausable		100 //degrees <-Convert to data seen on SPI
int tempMax = 0;
int tempMaxLocation[] = {0, 0};
int tempMin = 0;
int tempMinLocation[] = {0, 0};
int tempAverage = 0;


void ReadTempSensors()
{
	//Initializing Variables to 0.
	int temp = 0;
	tempMax = 0;
	tempMaxLocation[] = {0, 0};
	tempMin = 0;
	tempMinLocation[] = {0, 0};
	tempAverage = 0;
	numValidSensors = 0;

    //For Loop
	for(int i = 0, NUM_LTC_CHIPS, i++)
	{
		for(int j = 0; NUM_NTC_PER_LTC, j++)
		{
			//Do a plausability check
			temp = GetNTCFromSPI();
			if (temp > NTC_MaxPlausable)
			{
				SetDTC_a020_invalidTempHigh(i,j);
			}
			else if (temp < NTC_MinPlausable)
			{
				SetDTC_a021_invalidTempLow(i,j);
			}
			else
			{
				ClearDTC_a020_invalidTempHigh(i,j);
				ClearDTC_a021_invalidTempLow(i,j);

				//Update max and min values
				if( temp > tempMax)
				{
					tempMax = temp;
					tempMaxLocation[] = {i,j};
				}
				else if( temp < tempMin)
				{
					tempMin = temp;
					tempMinLocation[] = {i,j};
				}

				//Update the average Temp
				tempAverage += temp;
				numValidSensors++;
			}

		}//end j loop
	}//end i loop

	tempAverage = tempAverage/numValidSensors;  
    
    SetMessage_CellTemps();    
    
}


void SetMessage_CellTemps()
{
	// min temp
	// min location
	// max temp
	// max location
	// average temp
	// Number of Valid Sensors
}


/* [] END OF FILE */
