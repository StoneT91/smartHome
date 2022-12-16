#include "AHT2x.h"
Adafruit_AHTX0 aht;

void Aht2x::measureAHT2x(int cRT, int dly) {
	if ((cRT - updateTimeAht2x) > dly) {
		if (aht.begin()) {
			sensors_event_t humidity, temp;
			aht.getEvent(&humidity, &temp);
			currentValueAht2x[0] = temp.temperature;
			currentValueAht2x[1] = humidity.relative_humidity;
		}
		else {
			currentValueAht2x[0] = -99;
			currentValueAht2x[1] = -99;
		}
		updateTimeAht2x = millis();
	}
}
