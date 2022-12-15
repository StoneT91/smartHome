// 
// 
// 

#include "Buzzer.h"

void buzzer(int sA) {
	if (sA == 2){
		int buzzer = 6;//26;
		pinMode(buzzer, OUTPUT);
		digitalWrite(buzzer, HIGH);
		delay(1);
		digitalWrite(buzzer, LOW);
		delay(1);
	}
}
