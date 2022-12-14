#include "UpdateNextion.h"

void updateNextion(bool as, bool ss) {
	String cmd = "\"";
	if (as == true) {
		Serial2.print("page Alarm");
		Serial2.write(0xFF);
		Serial2.write(0xFF);
		Serial2.write(0xFF);
	}
	if (ss == true) {
		Serial2.print("j3.val=");
		Serial2.print(100);
		Serial2.write(0xff);
		Serial2.write(0xff);
		Serial2.write(0xff);
	}
	else {
		Serial2.print("j3.val=");
		Serial2.print(0);
		Serial2.write(0xff);
		Serial2.write(0xff);
		Serial2.write(0xff);
	}
}
