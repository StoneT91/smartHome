#include "UpdateNextion.h"

void updateNextion(bool as, bool ss) {
	String cmd = "\"";
	if (as == true) {
		Serial3.print("t2.txt=" + cmd + "ON" + cmd);
		Serial3.write(0xff);
		Serial3.write(0xff);
		Serial3.write(0xff);
	}
	else {
		Serial3.print("t2.txt=" + cmd + "OFF" + cmd);
		Serial3.write(0xff);
		Serial3.write(0xff);
		Serial3.write(0xff);
	}

	if (ss == true) {
		Serial3.print("t4.txt=" + cmd + "ON" + cmd);
		Serial3.write(0xff);
		Serial3.write(0xff);
		Serial3.write(0xff);
	}
	else {
		Serial3.print("t4.txt=" + cmd + "OFF" + cmd);
		Serial3.write(0xff);
		Serial3.write(0xff);
		Serial3.write(0xff);
	}
}
