#include "ReceiveNextion.h"

String receivedData = "";
union {
	char charByte[4];
	long valLong;
} value;

int receivedFromNextion() {
	if (Serial3.available()) {
		receivedData += char(Serial3.read());
		if (receivedData.length() > 4) {
			receivedData = "";
		}
	}
	if ((receivedData.length() == 4)) {
		value.charByte[0] = char(receivedData[0]);
		value.charByte[1] = char(receivedData[1]);
		value.charByte[2] = char(receivedData[2]);
		value.charByte[3] = char(receivedData[3]);
		receivedData = "";
		return value.valLong;
	}
}