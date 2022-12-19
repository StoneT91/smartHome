/**
 * \brief	controls LED (red, green)
 * if the parameter "sA" equals: "0" --> all LEDs off; 1 --> green LED on; 2 --> red LED on
 *
 * \author	Timo Steiner
 *
 * \date	16.12.2022
 *
 * \param	sA = statusAlarm
 *
 * \return	void
 */

#include "Led.h"

void updateLed(int sA) {
	int pinLedGreen = 4;
	int pinLedRed = 5;
	pinMode(pinLedGreen, OUTPUT);
	pinMode(pinLedRed, OUTPUT);

	if (sA == 0){
		digitalWrite(pinLedGreen, LOW);
		digitalWrite(pinLedRed, LOW);
	}
	if (sA == 2) {
		digitalWrite(pinLedGreen, HIGH);
		digitalWrite(pinLedRed, LOW);
	}if (sA == 3) {
		digitalWrite(pinLedGreen, LOW);
		digitalWrite(pinLedRed, HIGH);
	}
}