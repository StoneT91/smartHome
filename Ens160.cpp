/**
 * \brief	measure ENS160 Sensor (AQI, VOC, CO2)
 * if the sensor is available, the function will read the current sensorvalues.
 * if the sensor is not available, the function will print an default value of "-99"
 *
 * \author	Timo Steiner
 *
 * \date	16.12.2022
 *
 * \param	cRT = current runtime of the system
 * \param	dly = break time between measures
 *
 * \return	void --> prints sensorresult directly in an Array in the class "ENS160"
 */

#include "Ens160.h"

#define I2C_COMMUNICATION
#ifdef  I2C_COMMUNICATION
	DFRobot_ENS160_I2C ENS160(&Wire, 0x53);
#else
	uint8_t csPin = 7;
	DFRobot_ENS160_SPI ENS160(&SPI, csPin);
#endif

void Ens160::measureEns160(int cRT, int dly, Aht2x *ah) 
{
	DFRobot_ENS160_I2C ENS160(&Wire, 0x53);
	ENS160.setTempAndHum(25.0,50.0);
	if ((cRT - updateTimeEns160) > dly) {
		if (counter >= 10) {
			ENS160.setPWRMode(ENS160_STANDARD_MODE);
		}
		uint8_t Status = ENS160.getENS160Status();
		//if(Status == 2 && counter >= 14){
			if (NO_ERR == ENS160.begin()) {
				uint8_t AQI = ENS160.getAQI();
				uint16_t TVOC = ENS160.getTVOC();
				uint16_t ECO2 = ENS160.getECO2();
				currentValueEns160[0] = AQI;
				currentValueEns160[1] = TVOC;
				currentValueEns160[2] = ECO2;
				//ENS160.setPWRMode(ENS160_SLEEP_MODE);
				counter = 0;
			}
		//}
		updateTimeEns160 = millis();
		counter++;
	}
}