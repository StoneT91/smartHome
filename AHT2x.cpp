/**
 * \brief	measure AHT2x Sensor (temperature, humitidy)
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
 * \return	void --> prints sensorresult directly in an Array in the class "AHT2x"
 */


#include "AHT2x.h"
Adafruit_AHTX0 aht;

void Aht2x::measureAht2x(int cRT, int dly) {
	if ((cRT - updateTimeAht2x) > dly) {
		if (aht.begin()) {
			sensors_event_t humidity, temp;
			aht.getEvent(&humidity, &temp);
			currentValueAht2x[0] = temp.temperature;
			currentValueAht2x[1] = humidity.relative_humidity;
		}
		else {
			currentValueAht2x[0] = -99;
			currentValueAht2x[1] = -99;
		}
		updateTimeAht2x = millis();
	}
}