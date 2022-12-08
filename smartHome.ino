#include "Alarm.h"
#include "Sonar.h"
//#include <Nextion.h>

Sonar so;
bool alarmOn = false;
int panicButton = 6;
int pinButton = 7;
int buzzer = 8;
int pinActivate = 9;
int pinLedGreen = 10;
bool systemActiv = false;
String cmd = "\"";
char mySecondCharacter;

// The setup() function runs once each time the micro-controller starts
void setup() {
	pinMode(buzzer, OUTPUT);
	pinMode(pinButton, INPUT_PULLUP);
	pinMode(panicButton, INPUT);
	pinMode(pinLedGreen, OUTPUT);
	Serial.begin(9600);
	Serial3.begin(9600);
}

// Add the main program code into the continuous loop() function
void loop() {
	if (alarmOn != true) {
		Serial3.print("t2.txt=" + cmd + "OFF" + cmd);
		Serial3.write(0xff);
		Serial3.write(0xff);
		Serial3.write(0xff);
	}

	if (systemActiv != true) {
		Serial3.print("t4.txt=" + cmd + "OFF" + cmd);
		Serial3.write(0xff);
		Serial3.write(0xff);
		Serial3.write(0xff);
	}

	if (digitalRead(pinActivate)) {
		delay(5000);
		systemActiv = true;
		digitalWrite(pinLedGreen, HIGH);

		Serial3.print("t4.txt=" + cmd + "ON" + cmd);
		Serial3.write(0xff);
		Serial3.write(0xff);
		Serial3.write(0xff);



	}
	if ((motionDetection() || digitalRead(panicButton)) && systemActiv) {
		alarmOn = true;
		digitalWrite(pinLedGreen, LOW);

		Serial3.print("t2.txt=" + cmd + "ON" + cmd);
		Serial3.write(0xff);
		Serial3.write(0xff);
		Serial3.write(0xff);

		while (alarmOn) {
			digitalWrite(buzzer, HIGH);
			delay(1);
			digitalWrite(buzzer, LOW);
			delay(1);
			if (digitalRead(pinButton)) {
				alarmOn = false;
				systemActiv = false;
				Serial3.print("t2.txt=" + cmd + "OFF" + cmd);
				Serial3.write(0xff);
				Serial3.write(0xff);
				Serial3.write(0xff);
				Serial3.print("t4.txt=" + cmd + "OFF" + cmd);
				Serial3.write(0xff);
				Serial3.write(0xff);
				Serial3.write(0xff);
			}

			while (Serial3.available()) {
				mySecondCharacter = Serial3.read();
			}
			Serial3.print("t4.txt=" + cmd + mySecondCharacter + cmd);
			Serial3.write(0xff);
			Serial3.write(0xff);
			Serial3.write(0xff);
		}
	}
	delay(50);
}