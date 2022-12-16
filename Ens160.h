// Ens160.h

#ifndef _Ens160_h
#define _Ens160_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <DFRobot_ENS160.h>
#include "AHT2x.h"
class Ens160 {
public:
	void measureEns160(int cRT, int dly, Aht2x *ah);
	float currentValueEns160[3] = {};
	int updateTimeEns160 = 0;
	int counter = 0;
};

#endif