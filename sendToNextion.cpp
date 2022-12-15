// 
// 
// 

#include "sendToNextion.h"

void sendToNextion(LogicAlarm la) {
	if (la.statusAlarm != 0) {
		Serial2.print("j3.val=");
		Serial2.print(100);
		Serial2.write(0xFF);
		Serial2.write(0xFF);
		Serial2.write(0xFF);		
	}
}
