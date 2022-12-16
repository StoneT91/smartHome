// Ens160.h

#ifndef _Ens160_h
#define _Ens160_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "SparkFun_ENS160.h"


class Ens160 {
public:
	//SparkFun_ENS160 myENS;
	//int ensStatus;
	void measureEns160(int cRT, int dly);
	float currentValueEns160[3] = {};
	int updateTimeEns160 = 0;
};

#endif

