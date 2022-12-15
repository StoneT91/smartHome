#include "Nextion.h"

void Nextion::serialInterface(int Alarm, int cRT) {
	if (Serial2.available()) {
		//receive============================================================================================
		data += char(Serial2.read());
		if (data.substring(0, 1) == "b" && data.length() <= 9) {
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
				data = "";
			}
		}
		else {
			data = "";
		}
	}
	else {
		//send============================================================================================
		if (Alarm == 1 && buttonValue[1] != 0) {
			Serial.println(buttonValue[1]);
			for (int i = 0; i < 100; i++) {
				Serial2.print("j0.val=");
				Serial2.print(i);
				reset();
				delay(buttonValue[1] * 10);
			}
			buttonValue[1] = 0;
			Serial2.print("j0.val=");
			Serial2.print(0);
			reset();
		}
		if (cRT - updateTimeNextion > 500) {
			updateTimeNextion = millis();
			if (Alarm != 0) {
				Serial2.print("j3.val=");
				Serial2.print(100);
				reset();
			}
			else {
				Serial2.print("j3.val=");
				Serial2.print(0);
				reset();
			}
			//BME280======================================================================0
			Serial2.print("tempInside.txt=" + cmd + 0 + cmd); //
			reset();
			Serial2.print("humInside.txt=" + cmd + 1 + cmd);
			reset();
			Serial2.print("presInside.txt=" + cmd + 2 + cmd);
			reset();
		}
	}
}

void Nextion::reset() {
	Serial2.write(0xFF);
	Serial2.write(0xFF);
	Serial2.write(0xFF);
}