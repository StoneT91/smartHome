#include "Led.h"
//#include "Logic.h"

void updateLed(int sA) {
	int pinLedGreen = 4; //25
	int pinLedRed = 5; //27
	pinMode(pinLedGreen, OUTPUT);
	pinMode(pinLedRed, OUTPUT);

	if (sA == 0){
		digitalWrite(pinLedGreen, LOW);
		digitalWrite(pinLedRed, LOW);
	}
	if (sA == 1) {
		digitalWrite(pinLedGreen, HIGH);
		digitalWrite(pinLedRed, LOW);
	}if (sA == 2) {
		digitalWrite(pinLedGreen, LOW);
		digitalWrite(pinLedRed, HIGH);
	}
}