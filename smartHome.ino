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
int panicButton = 6;
int pinActivate = 9;

void setup() {
	pinMode(panicButton, INPUT);
	Serial.begin(9600);
	Serial3.begin(9600);
}
void loop() {
	updateNextion(alarmStatus, systemStatus);
	led(systemStatus, alarmStatus);
	if (digitalRead(pinActivate) || receivedFromNextion("b03") != 0) {
		delay(receivedFromNextion("b03")*1000);
		systemStatus = true;
	}
	if ((motionDetection() || digitalRead(panicButton)) && systemStatus) {
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
			}
		}
	}
}