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

#define I2C_COMMUNICATION  //I2C communication. Comment out this line of code if you want to use SPI communication.

#ifdef  I2C_COMMUNICATION
 /**
  *   For Fermion version, the default I2C address is 0x53, connect SDO pin to GND and I2C address will be 0x52
  */
DFRobot_ENS160_I2C ENS160(&Wire, /*I2CAddr*/ 0x53);
#else
 /**
  * Set up digital pin according to the on-board pin connected with SPI chip-select pin
  * csPin Available Pins. For example: ESP32&ESP8266(D3), m0(6)
  */
uint8_t csPin = 7;
DFRobot_ENS160_SPI ENS160(&SPI, csPin);

#endif

void Ens160::measureEns160(int cRT, int dly) {
	//if ((cRT - updateTimeEns160) > dly) {
		//if (ENS160.begin()){
			uint8_t Status = ENS160.getENS160Status();
			uint8_t AQI = ENS160.getAQI();
			uint16_t TVOC = ENS160.getTVOC();
			uint16_t ECO2 = ENS160.getECO2();
			Serial.println(Status);
			Serial.println("Status");
			Serial.println(AQI);
			Serial.println(TVOC);
			Serial.println(ECO2);
		//}
	//}
	updateTimeEns160 = millis();
	
}