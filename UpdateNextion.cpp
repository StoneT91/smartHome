#include "UpdateNextion.h"

void updateNextion(bool as, bool ss) {
	String cmd = "\"";
	if (as == true) {
		Serial3.print("page Alarm");
		Serial3.write(0xFF);
		Serial3.write(0xFF);
		Serial3.write(0xFF);
	}

	if (ss == true) {
		Serial3.print("j3.val=");
		Serial3.print(100);
		Serial3.write(0xff);
		Serial3.write(0xff);
		Serial3.write(0xff);
	}
	else {
		Serial3.print("j3.val=");
		Serial3.print(0);
		Serial3.write(0xff);
		Serial3.write(0xff);
		Serial3.write(0xff);
	}
}
