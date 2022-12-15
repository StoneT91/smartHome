// 
// 
// 

#include "sendToNextion.h"

void sendToNextion(LogicAlarm la, Button bn) {
	if (la.statusAlarm != 0) {
		Serial2.print("j3.val=");
		Serial2.print(100);
		Serial2.write(0xFF);
		Serial2.write(0xFF);
		Serial2.write(0xFF);		
	}
	if (la.statusAlarm == 1) {
		Serial.println(bn.buttonValue[1]);
		for (int i = 0; i < 100; i++) {
			Serial2.print("j0.val=");
			Serial2.print(i);
			Serial2.write(0xFF);
			Serial2.write(0xFF);
			Serial2.write(0xFF);
			delay(bn.buttonValue[1]*10);
		}
		bn.buttonValue[1] = 0;
		Serial2.print("j0.val=");
		Serial2.print(0);
		Serial2.write(0xFF);
		Serial2.write(0xFF);
		Serial2.write(0xFF);
	}
}
