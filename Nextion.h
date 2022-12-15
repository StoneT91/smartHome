#ifndef _SERIALINTERFACE_h
#define _SERIALINTERFACE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Button{
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
	void readSerialInterface(int Alarm);
};

#endif