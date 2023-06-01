// SR04T.h

#ifndef _SR04T_h
#define _SR04T_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_GFX.h>

class SR04T {
	public:
		int trigPin;
		int echoPin;
		int maxDistance;
		int duration;
		int currentDistance;
		int measure(int trigpin, int echopin);
	private:

};




#endif

