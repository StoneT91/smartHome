#ifndef _SONAR_h
#define _SONAR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Sonar {
public:
    int trigPin;
    int echoPin;
    int maxDistance;
    int currentDistance;
    int measure(int trigpin, int echopin, int maxdistance);
};
#endif