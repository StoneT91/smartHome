#include "ReceiveNextion.h"

String receivedData = "";
union {
	char charByte[7];
	long valLong;
} value;

int receivedFromNextion(String key) {
	if (Serial3.available()) {
		receivedData += char(Serial3.read());
		if ((receivedData.length() > 7) || (receivedData.substring(0, 1) != "b")) {
			receivedData = "";
		}
	}
	if ((receivedData.substring(0,3)==key) && (receivedData.length() == 7)) {
		value.charByte[0] = char(receivedData[3]);
		value.charByte[1] = char(receivedData[4]);
		value.charByte[2] = char(receivedData[5]);
		value.charByte[3] = char(receivedData[6]);

		receivedData = "";
		return value.valLong;
	}
	else {
		return 0;
	}
}