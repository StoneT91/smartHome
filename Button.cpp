#include "Button.h"

void Button::readSerialInterface() {
	if (Serial2.available()) {
		data += char(Serial2.read());
		if (data.substring(0,1) =="b" && data.length() <= 9) {
			if (data.length() == stringLength) {
				value.charByte[0] = char(data[1]);
				value.charByte[1] = char(data[2]);
				value.charByte[2] = char(data[3]);
				value.charByte[3] = char(data[4]);
				num = value.valLong;

				value.charByte[0] = char(data[5]);
				value.charByte[1] = char(data[6]);
				value.charByte[2] = char(data[7]);
				value.charByte[3] = char(data[8]);
				val = value.valLong;

				buttonValue[num] = val;
				Serial.println(buttonValue[num]);
				data = "";
			}
		}
		else {
			data = "";
		}
		
	}
}