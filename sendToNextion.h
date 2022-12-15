// sendToNextion.h

#ifndef _SENDTONEXTION_h
#define _SENDTONEXTION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "LogicAlarm.h"
void sendToNextion(LogicAlarm la, Button bn);

#endif

