#include "Buzzer.h"
#include "UpdateNextion.h"
#include "Alarm.h"
#include "Sonar.h"

Sonar so;
bool alarmStatus = false;
bool systemStatus = false;

int panicButton = 6;
int pinButton = 7;
int buzzer = 8;
int pinActivate = 9;
int pinLedGreen = 10;
int keyFromNextion;
String receivedData = "";

union {
	char charByte[4];
	long valLong;
} value;

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
	updateNextion(alarmStatus, systemStatus);
	
	


	if (digitalRead(pinActivate)) {
		delay(5000);
		systemStatus = true;
		digitalWrite(pinLedGreen, HIGH);
		updateNextion(alarmStatus, systemStatus);
	}
	if ((motionDetection() || digitalRead(panicButton)) && systemStatus) {
		alarmStatus = true;
		digitalWrite(pinLedGreen, LOW);

		updateNextion(alarmStatus, systemStatus);

		while (alarmStatus) {
			buzzerOn(buzzer);
			



			if (Serial3.available()) {
				receivedData += char(Serial3.read());
				if (receivedData.length() > 4) {
					receivedData = "";
				}
			}
			if ((receivedData.length() == 4)) {
				value.charByte[0] = char(receivedData[0]);
				value.charByte[1] = char(receivedData[1]);
				value.charByte[2] = char(receivedData[2]);
				value.charByte[3] = char(receivedData[3]);
				keyFromNextion = value.valLong;
				receivedData = "";
				Serial.println(keyFromNextion);
			}




			if (digitalRead(pinButton)) {
				alarmStatus = false;
				systemStatus = false;
				updateNextion(alarmStatus, systemStatus);
			}
		}
	}
}