// 
// 
// 

#include "Buzzer.h"

void buzzerOn() {
	int buzzer = 8;
	pinMode(buzzer, OUTPUT);
	digitalWrite(buzzer, HIGH);
	delay(1);
	digitalWrite(buzzer, LOW);
	delay(1);
}
