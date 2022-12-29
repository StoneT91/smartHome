// Settings.h

#ifndef _SETTINGS_h
#define _SETTINGS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Nextion.h"
#include <EEPROM.h>

class Settings {
public:
	int masterKey = 1122;
	void setPasswort(Nextion* nx);
	void eepromWriteInt(int address, int number);
	long eepromReadInt(int address);
	int intData = 1024, getInt;
};

#endif

