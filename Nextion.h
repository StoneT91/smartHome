#ifndef _SERIALINTERFACE_h
#define _SERIALINTERFACE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Sensor.h"
#include "BME280.h"
#include "AHT2x.h"
#include "Ens160.h"
#include "ModuleOutsideBottom.h"

class Nextion {
public:
	String data;
	union {
		char charByte[8];
		long valLong;
	} value;
	int num;
	int val;
	int stringLength = 9;
	int buttonValue[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 }; //1:Activate Alarm; 2:Deactivate Alarm; 3:Activation Delay; 4:Old Passwort; 5:New Passwort; 6: Confirm new Passwort
	int updateTimeNextion = 0;
	void serialInterface(int sA, uint16_t counter, SensorClass* Sensor, Aht2x* ah, Ens160* en, ModuleOutsideBottom* mob);
	void reset();
	int delayStatus = 0;
	String cmd = "\"";
};

#endif