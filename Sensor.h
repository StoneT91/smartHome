// Sensor.h

#ifndef _SENSOR_h
#define _SENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_BME280.h>

	class SensorClass
	{
	public:
		void init();
		void updateSensors(uint8_t page, uint16_t counter);
		void BME280();
		Adafruit_BME280 bme280;
		float temperature = 0.0F;
		float humidity = 0.0F;
		float pressure = 0.0F;

	private:
		
		
	};

	extern SensorClass Sensor;

#endif

