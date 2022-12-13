#include <dummy.h>
#include "ReceiveNextion.h"
#include "UpdateLed.h"
#include "Buzzer.h"
#include "UpdateNextion.h"
#include "Detection.h"
#include "Sonar.h"

Sonar so;
bool alarmStatus = false;
bool systemStatus = false;
int masterKey = 4569;
int keyFromNextion;
unsigned long time0 = 0;
unsigned long time1 = 0;
#define RXD2 32
#define TXD2 33

void setup() {
	Serial.begin(9600);
	Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
}
void loop() {
	keyFromNextion = receivedFromNextion("b03");
	if (keyFromNextion > 0) {
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
			keyFromNextion = receivedFromNextion("b15");
			if (masterKey == keyFromNextion) {
				Serial.println(keyFromNextion);
				keyFromNextion = 0;
				alarmStatus = false;
				systemStatus = false;
				updateNextion(alarmStatus, systemStatus);
				led(systemStatus, alarmStatus);
			}
			time1 = millis();
			if ((time1-time0) > 5000) {
				buzzerOn();
			}
		}
	}
	delay(10);
}