// 
// 
// 

#include "SR04T.h"

int SR04T::measure(int tP, int eP) {
	pinMode(tP, OUTPUT);
	pinMode(eP, INPUT);

	digitalWrite(tP,HIGH);
	delayMicroseconds(1);
	digitalWrite(tP, LOW);

	duration = pulseIn(eP, HIGH);

	return (duration/2)/29.1;
}
