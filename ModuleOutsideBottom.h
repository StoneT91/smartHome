// ModuleOutsideBottom.h

#ifndef _MODULEOUTSIDEBOTTOM_h
#define _MODULEOUTSIDEBOTTOM_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <esp_now.h>
class ModuleOutsideBottom {
public:
	float currentValueBme280[3];
	//void onDataReceive(const uint8_t* macAddress, const uint8_t* incomingData, int dataLength);
};



#endif