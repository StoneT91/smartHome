/**
 * \brief	communicates with the display / touch panel 
 * if a signal at the serial interface is available the function will read the signal and store it in an array (buttonValue)
 * if there is no signal at the serial interface available the function will update the values at display (sending values)
 *
 * \author	Timo Steiner
 *
 * \date	16.12.2022
 * 
 * \param	sA = statusAlarm
 * \param	cRT = current runtime of the system
 * \param	bm = current values from BME280 sensor
 *
 * \return	void
 */

#include "Nextion.h"

void Nextion::serialInterface(int sA, int cRT, BME280* bm, Aht2x* ah) {
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
		if (sA == 1 && buttonValue[1] != 0) {
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
			if (sA != 0) {
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
			Serial2.print("tempOutside.txt=" + cmd + bm->currentValueBme280[0] + cmd);
			reset();
			Serial2.print("humOutside.txt=" + cmd + bm->currentValueBme280[1] + cmd);
			reset();
			Serial2.print("presOutside.txt=" + cmd + bm->currentValueBme280[2] + cmd);
			reset();
			Serial2.print("tempSignOuts.val=");
			Serial2.print((int)bm->currentValueBme280[0] * 3);
			reset();
			Serial2.print("humSignOutside.val=");
			Serial2.print((int)bm->currentValueBme280[1]);
			reset();

			Serial2.print("tempInside.txt=" + cmd + ah->currentValueAht2x[0] + cmd);
			reset();
			Serial2.print("humInside.txt=" + cmd + ah->currentValueAht2x[1] + cmd);
			reset();
			Serial2.print("tempSignInside.val=");
			Serial2.print((int)ah->currentValueAht2x[0] * 3);
			reset();
			Serial2.print("humSignInside.val=");
			Serial2.print((int)ah->currentValueAht2x[1]);
			reset();
		}
	}
}

void Nextion::reset() {
	Serial2.write(0xFF);
	Serial2.write(0xFF);
	Serial2.write(0xFF);
}