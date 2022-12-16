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

void Ens160::measureEns160(int cRT, int dly) {
	/*if ((cRT - updateTimeEns160) > dly) {
		
		if (myENS.setOperatingMode(SFE_ENS160_RESET)) {
			Serial.println("Ready.");
			delay(100);
		}

		ensStatus = myENS.getFlags();
		if(ensStatus !=0){
			myENS.setOperatingMode(SFE_ENS160_STANDARD);
		}

		if (myENS.begin()){
			if (myENS.checkDataStatus()) {
				Serial.println(myENS.getAQI());
				Serial.println(myENS.getTVOC());
				Serial.println(myENS.getECO2());
			}
		}
		updateTimeEns160 = millis();
	}
	*/
}
