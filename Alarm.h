#ifndef _MOTIONDETECTION_h
#define _MOTIONDETECTION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

bool motionDetection();

#endif

