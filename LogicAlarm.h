// Logic.h

#ifndef _LOGIC_h
#define _LOGIC_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Sonar.h"
#include "Button.h"

class LogicAlarm {
public:
	int statusAlarm = 0;
	int statusBefore = 0;	
	void logicAlarm(int mK, Button* bn, Sonar so);
};

#endif

