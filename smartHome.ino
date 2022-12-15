#include "sendToNextion.h"
#include "LogicAlarm.h"
#include "Button.h"
#include "Sonar.h"
#include "Led.h"
#include "Buzzer.h"

//#define RXD2 32
//#define TXD2 33

Button bn;
Sonar so;
LogicAlarm la;

int statusAlarm;
int masterKey = 4569;

void setup() {
	Serial.begin(9600);
	Serial2.begin(9600);
	//Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
}
void loop() {
	bn.readSerialInterface();

	la.logicAlarm(masterKey, &bn, so);
	if (la.statusAlarm!=la.statusBefore) {
		sendToNextion(la, bn);
	}
	updateLed(la.statusAlarm);
	buzzer(la.statusAlarm);
	
	
	//Serial.println(la.statusAlarm);
	//Serial.println(bn.buttonValue[1]);




	/*
	temp = receivedFromNextion("bb3");
	if (temp > 0) {
		alarmOnDelay = temp;
	}
	key = receivedFromNextion("b15");
	if (key > 0) {
		systemStatus = false;
	}
	updateNextion(alarmStatus, systemStatus);
	led(systemStatus, alarmStatus);
	*/
	/*if (alarmActivationDelay > 0) {
		systemStatus = true;
		updateNextion(alarmStatus, systemStatus);
		led(systemStatus, alarmStatus);
	}
	if (motionDetection() && systemStatus) {
		alarmStatus = true;
		updateNextion(alarmStatus, systemStatus);
		led(systemStatus, alarmStatus);
		time0 = millis();
		while (alarmStatus) {
			key = receivedFromNextion("b15");
			if (masterKey == key) {
				valueFromNextion1 = 0;
				alarmStatus = false;
				systemStatus = false;
				updateNextion(alarmStatus, systemStatus);
				led(systemStatus, alarmStatus);
			}
			time1 = millis();
			if ((time1-time0) > (alarmOnDelay*1000)) {
				buzzerOn();
			}
		}
	}

	*/
	//delay(10);
}