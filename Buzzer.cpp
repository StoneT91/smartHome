/**
 * \brief	buzzer
 * if the parameter "sA" equal 2 --> buzzer on (pin High, pin LOW)
 *
 * \author	Timo Steiner
 *
 * \date	16.12.2022
 *
 * \param	sA = statusAlarm
 *
 * \return	void
 */

#include "Buzzer.h"

void buzzer(int sA) {
	int buzzer = 26; //30
	if (sA == 3){
		pinMode(buzzer, OUTPUT);
		digitalWrite(buzzer, HIGH);
		delay(1);
		digitalWrite(buzzer, LOW);
		delay(1);
	}
}