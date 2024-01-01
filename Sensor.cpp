// 
// 
// 

#include "Sensor.h"

void SensorClass::updateSensors(uint8_t page)
{
	//********************Update all 2 seconds********************
	//if (((millis()/1000) % 2) == 0) 
	//{
		BME280();
		ENS160();
		SR501(14U);

	//}
	if (page == 2)
	{
		// Niveau
	}
}

void SensorClass::BME280() {
	tempFloatValue = temperatureInside;
	tempIntegarValue = humidityInside;
	//********************Update Sensor Value********************
	if (bme280.begin(0x76))
	{
		temperatureInside = bme280.readTemperature();
		humidityInside = bme280.readHumidity();
		pressureInside = bme280.readPressure() / 100;
	}
	else
	{
		temperatureInside = -99;
		humidityInside = -99;
		pressureInside = -99;
	}
	//********************Update Display Requested********************
	if ((std::abs(tempFloatValue - temperatureInside) >= 0.25) || (std::abs(tempIntegarValue - humidityInside) >= 2U))
	{
		valuesChangedBME280Inside = true;
	}
	else
	{
		valuesChangedBME280Inside = false;
		temperatureInside = tempFloatValue;
		humidityInside = tempIntegarValue;
	}
}

void SensorClass::ENS160()
{
	DFRobot_ENS160_I2C ENS160(&Wire, 0x53);
	ENS160.setTempAndHum(temperatureInside, humidityInside);
	ENS160.setPWRMode(ENS160_STANDARD_MODE);
	uint8_t Status = ENS160.getENS160Status();
	if (NO_ERR == ENS160.begin()) {
		uint8_t AQI = ENS160.getAQI();
		uint16_t TVOC = ENS160.getTVOC();
		uint16_t ECO2 = ENS160.getECO2();
	}
	//ENS160.setPWRMode(ENS160_SLEEP_MODE);
}

void SensorClass::SR501(uint8_t mP)
{
	pinMode(mP, INPUT);
	if (digitalRead(mP)) 
	{
		movementDetected = true;
	}
	else 
	{
		movementDetected = false;
	}
}