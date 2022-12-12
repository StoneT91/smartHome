#include "UpdateNextion.h"

void updateNextion(bool as, bool ss) {
	String cmd = "\"";
	if (as == true) {
		Serial.print("page Alarm");
		Serial.write(0xFF);
		Serial.write(0xFF);
		Serial.write(0xFF);
	}

	if (ss == true) {
		Serial.print("j3.val=");
		Serial.print(100);
		Serial.write(0xff);
		Serial.write(0xff);
		Serial.write(0xff);
	}
	else {
		Serial.print("j3.val=");
		Serial.print(0);
		Serial.write(0xff);
		Serial.write(0xff);
		Serial.write(0xff);
	}
}
