#include "Alarm.h"
#include "Sonar.h"

Sonar so;
bool alarmOn = false;
int panicButton = 6;
int pinButton = 7;
int buzzer = 8;
int pinActivate = 9;
int pinLedGreen = 10;
bool systemActiv = false;

// The setup() function runs once each time the micro-controller starts
void setup() {
	pinMode(buzzer, OUTPUT);
	pinMode(pinButton, INPUT_PULLUP);
	pinMode(panicButton, INPUT);
	pinMode(pinLedGreen, OUTPUT);
	Serial.begin(9600);
}

// Add the main program code into the continuous loop() function
void loop() {
	if (digitalRead(pinActivate)) {
		delay(5000);
		systemActiv = true;
		digitalWrite(pinLedGreen, HIGH);
	}
	if ((motionDetection() || digitalRead(panicButton)) && systemActiv) {
		alarmOn = true;
		digitalWrite(pinLedGreen, LOW);
		while (alarmOn) {
			digitalWrite(buzzer, HIGH);
			delay(1);
			digitalWrite(buzzer, LOW);
			delay(1);
			if (digitalRead(pinButton)) {
				alarmOn = false;
				systemActiv = false;
			}
		}
	}
	delay(50);

}