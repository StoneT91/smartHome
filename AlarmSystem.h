// Logic.h

#ifndef _LOGIC_h
#define _LOGIC_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Nextion.h"

class LogicAlarm {
public:
	int statusAlarm = 0;
	void logicAlarm(int mK, Nextion* nx);
};

#endif