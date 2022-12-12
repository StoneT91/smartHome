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

void setup() {
	Serial.begin(9600);
	//Serial3.begin(9600);
}
void loop() {
	keyFromNextion = receivedFromNextion("b03");
	if (keyFromNextion > 0) {
		Serial.println(keyFromNextion);
		systemStatus = true;
		updateNextion(alarmStatus, systemStatus);
		led(systemStatus, alarmStatus);
	}

	if (motionDetection() && systemStatus) {
		alarmStatus = true;
		updateNextion(alarmStatus, systemStatus);
		led(systemStatus, alarmStatus);
		while (alarmStatus) {
			buzzerOn();
			keyFromNextion = receivedFromNextion("b15");
			if (masterKey == keyFromNextion) {
				Serial.println(keyFromNextion);
				keyFromNextion = 0;
				alarmStatus = false;
				systemStatus = false;
				updateNextion(alarmStatus, systemStatus);
				led(systemStatus, alarmStatus);
			}
		}
	}
	delay(10);
}