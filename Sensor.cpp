// 
// 
// 

#include "Sensor.h"


	void SensorClass::updateSensors(uint8_t page, uint16_t counter)
	{
		if ((counter%100)==0)
		{
			BME280();
		}

		if (page == 2)
		{
			// Niveau
		}
	}

	void SensorClass::BME280() {
		tmpFloat = temperatureInside;
		tmpIntegar = humidityInside;
		//********************Read Sensor if available********************
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
		temperatureInsideChanged = (std::abs(tmpFloat - temperatureInside) > 0.1) ? true : false;
		humidityInsideChanged = (tmpIntegar != humidityInside) ? true : false;
	}

	void SensorClass::init()
	{
		temperatureInside = 0.0F;
		humidityInside = 0.0F;
		pressureInside = 0.0F;
	}


