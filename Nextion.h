#ifndef _SERIALINTERFACE_h
#define _SERIALINTERFACE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "BME280.h"
#include "AHT2x.h"
class Nextion {
public:
	String data;
	union {
		char charByte[8];
		long valLong;
	} value;
	int num;
	int val;
	int stringLength = 9;
	int buttonValue[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
	int updateTimeNextion = 0;
	void serialInterface(int sA, int cRT, BME280* bm, Aht2x* ah);
	void reset();
	String cmd = "\"";
};

#endif