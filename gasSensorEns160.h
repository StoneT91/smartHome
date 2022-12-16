// gasSensorEns160.h

#ifndef _GASSENSORENS160_h
#define _GASSENSORENS160_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif



#include <DFRobot_ENS160.h>




class gasSensorEns160 {
public:
	void measureEns160(int cRT, int dly);
	float currentValueEns160[3] = {};
	int updateTimeEns160 = 0;
};

#endif

