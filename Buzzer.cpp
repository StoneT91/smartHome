// 
// 
// 

#include "Buzzer.h"

void buzzerOn(int pn) {
	digitalWrite(pn, HIGH);
	delay(1);
	digitalWrite(pn, LOW);
	delay(1);
}
