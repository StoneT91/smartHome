#include "UpdateLed.h"

void led(bool green, bool red) {
	int pinLedGreen = 25;
	int pinLedRed = 26;
	pinMode(pinLedGreen, OUTPUT);
	if (green == true && red != true) {
		digitalWrite(pinLedGreen, HIGH);
	}
	else {
		digitalWrite(pinLedGreen, LOW);
	}

	if (red == true) {
		digitalWrite(pinLedRed, HIGH);
	}
	else {
		digitalWrite(pinLedRed, LOW);
	}

}