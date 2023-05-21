// HC_SR501.h

#ifndef _HC_SR501_h
#define _HC_SR501_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

bool getMovementDetection(int mP);

#endif

