// 
// 
// 

#include "Buzzer.h"

void buzzerOn() {
	int buzzer = 14;
	pinMode(buzzer, OUTPUT);
	digitalWrite(buzzer, HIGH);
	delay(1);
	digitalWrite(buzzer, LOW);
	delay(1);
}
