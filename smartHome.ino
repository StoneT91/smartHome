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
String dfd = "";
String endChar = String(char(0xff)) + String(char(0xff)) + String(char(0xff));
union {
	char charByte[4];
	long valLong;
} value;

//NexText t0 = NexText(0, 11, "t0");  // Text box added, so we can read it


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

	if (Serial3.available()) {
		dfd += char(Serial3.read());
	}

	if (dfd.endsWith(endChar)) {
		Serial.println(dfd);
		dfd = "";
	}


	Serial.println(dfd);

	delay(500);
	
	if (dfd.length() > 15) {
		dfd = "";
	}


	if ((dfd.substring(0, 3) == "val") && (dfd.length() == 15)) {
		Serial.println(dfd);
		value.charByte[0] = char(dfd[3]);
		value.charByte[1] = char(dfd[4]);
		value.charByte[2] = char(dfd[5]);
		value.charByte[3] = char(dfd[6]);

		Serial.println(String(value.valLong));

		Serial3.print("t4.txt=" + cmd + String(value.valLong) + cmd);
		Serial3.write(0xff);
		Serial3.write(0xff);
		Serial3.write(0xff);

		dfd = "";
	}

	/*
	if (dfd.endsWith(endChar)) {
		Serial.println(dfd);
		dfd = "";
	}
	*/


	//delay(500);

	

	//delay(500);


	if (alarmOn != true) {
		Serial3.print("t2.txt=" + cmd + "OFF" + cmd);
		Serial3.write(0xff);
		Serial3.write(0xff);
		Serial3.write(0xff);
	}
	/*
	if (systemActiv != true) {
		Serial3.print("t4.txt=" + cmd + "OFF" + cmd);
		Serial3.write(0xff);
		Serial3.write(0xff);
		Serial3.write(0xff);
	}
	*/
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

			
		}
	}
	delay(50);
}