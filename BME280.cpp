#include "BME280.h"

void BME280::measureBme280() {
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

