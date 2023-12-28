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
		void init();
		void updateSensors(uint8_t page, uint16_t counter);
		float tmpFloat = 0.0F;
		uint8_t tmpIntegar = 0U;
		//********************BME280 Inside********************
		void BME280();
		Adafruit_BME280 bme280;
		float temperatureInside = 0.0F;
		uint8_t humidityInside = 0.0F;
		uint16_t pressureInside = 0.0F;
		bool temperatureInsideChanged = true;
		bool humidityInsideChanged = true;
		//********************ENS160 Inside********************
		void ENS160();
		uint8_t AQI = 0U;
		uint16_t TVOC = 0U;
		uint16_t ECO2 = 0U;
		//********************BME280 Outside********************
		float temperatureOutside = 0.0F;
		uint8_t humidityOutside = 0.0F;
		bool temperatureOutsideChanged = true;
		bool humidityOutsideChanged = true;
	
	private:
		
		
	};

	extern SensorClass Sensor;

#endif

