// AHT2x.h

#ifndef _ENS160AHT2_h
#define _ENS160AHT2_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <Adafruit_AHTX0.h>
class Aht2x {
public:
	sensors_event_t humidity, temp;
	void measureAht2x(int cRT, int dly);
	float currentValueAht2x[2] = {};
	int updateTimeAht2x = 0;
};
#endif