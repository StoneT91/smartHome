/**
 * \brief	measure BME280 Sensor (temperature, humitidy, pressure)
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
 * \return	void --> prints sensorresult directly in an Array in the class "BME280"
 */

#include "BME280.h"

void BME280::measureBme280(int cRT, int dly) {
	if ((cRT - updateTimeBME280) > dly) {
		if (bme280.begin(0x76)) {
			currentValueBme280[0] = bme280.readTemperature();
			currentValueBme280[1] = bme280.readHumidity();
			currentValueBme280[2] = bme280.readPressure() / 100;
		}
		else {
			currentValueBme280[0] = -99;
			currentValueBme280[1] = -99;
			currentValueBme280[2] = -99;
		}
		updateTimeBME280 = millis();
	}
}

