// hardwareUpdate.h

#ifndef _HARDWAREUPDATE_h
#define _HARDWAREUPDATE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "LogicAlarm.h"
#include "Led.h"
#include "Buzzer.h"


void hardwareUpdate(int sA);

#endif

