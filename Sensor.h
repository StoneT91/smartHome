// Sensor.h

#ifndef _SENSOR_h
#define _SENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_BME280.h>
#include <DFRobot_ENS160.h>

class SensorClass
{
public:
	//********************Temporary Vaiables********************
	float tempFloatValue = 0.0F;
	uint8_t tempIntegarValue = 0U;
	//********************Update Logic********************
	void updateSensors(uint8_t page);
	//********************BME280 Inside********************
	void BME280();
	Adafruit_BME280 bme280;
	float temperatureInside = 0.0F;
	uint8_t humidityInside = 0.0F;
	uint16_t pressureInside = 0.0F;
	bool valuesChangedBME280Inside = true;
	//********************ENS160 Inside********************
	void ENS160();
	uint8_t AQI = 0U;
	uint16_t TVOC = 0U;
	uint16_t ECO2 = 0U;
	//********************SR501 Inside********************
	void SR501(uint8_t mP);
	bool movementDetected = false;
	//********************BME280 Outside********************
	float temperatureOutside = 0.0F;
	uint8_t humidityOutside = 0.0F;
	bool valuesChangedBME280Outside = true;
private:
};

extern SensorClass Sensor;

#endif

