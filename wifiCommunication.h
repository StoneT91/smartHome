// wifiCommunication.h

#ifndef _WIFICOMMUNICATION_h
#define _WIFICOMMUNICATION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

/*
struct messageStruct {
	char myString[32];
	int myInt;
	float myFloat;
	bool myBool;
};

messageStruct messageData;

void onDataReceive(const uint8_t* macAddress, const uint8_t* incomingData, int dataLength);
*/

#endif

