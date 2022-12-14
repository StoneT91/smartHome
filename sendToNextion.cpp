// 
// 
// 

#include "sendToNextion.h"

void sendToNextion(LogicAlarm la) {
	if (la.statusAlarm == 1) {
		Serial2.print("j3.val=100");
		Serial2.write(0xFF);
		Serial2.write(0xFF);
		Serial2.write(0xFF);
		Serial2.print("page Inside");
		Serial2.write(0xFF);
		Serial2.write(0xFF);
		Serial2.write(0xFF);
	}
	/*
	if (la.statusAlarm > 0) {
		Serial2.print("j3.val=");
		Serial2.print(100);
		Serial2.write(0xff);
		Serial2.write(0xff);
		Serial2.write(0xff);
		delay(5);
	}
	*/
}
