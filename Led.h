// UpdateLed.h

#ifndef _UPDATELED_h
#define _UPDATELED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
void updateLed(int sA);

#endif

