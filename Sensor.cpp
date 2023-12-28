// 
// 
// 

#include "Sensor.h"


	void SensorClass::updateSensors(uint8_t page, uint16_t counter)
	{
		if ((counter%100)==0)
		{
			BME280();
			ENS160();
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

	void SensorClass::init()
	{
		temperatureInside = 0.0F;
		humidityInside = 0.0F;
		pressureInside = 0.0F;
	}


