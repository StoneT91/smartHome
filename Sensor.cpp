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
		//********************Store Old Values********************
		float temperatureInsideOld = Sensor.temperatureInside;
		float humidityInsideOld = Sensor.humidityInside;
		float pressureInsideOld = Sensor.pressureInside;
		//********************Read Sensor if available********************
		if (bme280.begin(0x76))
		{
			Sensor.temperatureInside = bme280.readTemperature();
			Sensor.humidityInside = bme280.readHumidity();
			Sensor.pressureInside = bme280.readPressure() / 100;
		}
		else
		{
			Sensor.temperatureInside = -99;
			Sensor.humidityInside = -99;
			Sensor.pressureInside = -99;
		}
	}

	void SensorClass::init()
	{
		Sensor.temperatureInside = 0.0F;
		Sensor.humidityInside = 0.0F;
		Sensor.pressureInside = 0.0F;
	}


