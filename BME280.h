// BME280.h

#ifndef _BME280_h
#define _BME280_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#define SEALEVELPRESSURE_HPA (1013.25)
#include <Adafruit_BME280.h>
class BME280 {
public:
	Adafruit_BME280 bme280;
	void measureBme280(int cRT, int dly);
	float currentValueBme280[4] = {};
	int updateTimeBME280 = 0;
};
#endif