#include "ReceiveNextion.h"
#include "UpdateLed.h"
#include "Buzzer.h"
#include "UpdateNextion.h"
#include "Detection.h"
#include "Sonar.h"

Sonar so;
bool alarmStatus = false;
bool systemStatus = false;
int key = 4569;
int keyFromNextion;
int panicButton = 6;
int pinActivate = 9;


// The setup() function runs once each time the micro-controller starts
void setup() {
	pinMode(panicButton, INPUT);
	Serial.begin(9600);
	Serial3.begin(9600);
}

// Add the main program code into the continuous loop() function
void loop() {
	updateNextion(alarmStatus, systemStatus);
	if (digitalRead(pinActivate)) {
		delay(5000);
		systemStatus = true;
		led(true,false);
		updateNextion(alarmStatus, systemStatus);
	}
	if ((motionDetection() || digitalRead(panicButton)) && systemStatus) {
		alarmStatus = true;
		led(false, true);

		updateNextion(alarmStatus, systemStatus);

		while (alarmStatus) {
			buzzerOn();
			keyFromNextion = receivedFromNextion();
			if (key == keyFromNextion) {
				keyFromNextion = 0;
				alarmStatus = false;
				systemStatus = false;
				updateNextion(alarmStatus, systemStatus);
				led(false, false);
			}
		}
	}
}