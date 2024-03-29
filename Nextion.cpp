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
void Nextion::serialInterface(int sA, SensorClass* Sensor, ModuleOutsideBottom* mob) {
	//receive============================================================================================
	if (Serial2.available()) {
		data += char(Serial2.read());
		if (data.substring(0, 1) == "b" && data.length() <= 9) 
		{
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
		else 
		{
			data = "";
		}
	}
	//send============================================================================================
	else {
		if (sA==2) {
			delayStatus = 0;
		}
		if (sA == 1) {
			for (int i = 0; i < 100; i++) {
				Serial2.print("j0.val=");
				Serial2.print(i);
				reset();
				delay(buttonValue[1] * 10);
			}
			delayStatus = 2;
			buttonValue[1] = 0;
			Serial2.print("j0.val=");
			Serial2.print(0);
			reset();
		}
		//if ((millis() % 25) == 0) {
			//updateTimeNextion = millis();
			if (sA == 0) {
				Serial2.print("AlarmStatus.pic=");
				Serial2.print(0);
				reset();
			}
			else if (sA == 1 || sA == 2) {
				Serial2.print("AlarmStatus.pic=");
				Serial2.print(1);
				reset();
			}
			else {
				Serial2.print("AlarmStatus.pic=");
				Serial2.print(2);
				reset();
			}
			//********************BME280 Outside********************
			if (Sensor->valuesChangedBME280Outside)
			{
				Serial2.print("tempOutside.txt=" + cmd + Sensor->temperatureOutside + cmd);
				reset();
				Serial2.print("tempSignOuts.val=");
				Serial2.print((int8_t)Sensor->temperatureOutside * 3);
				reset();

				Serial2.print("humOutside.val=");
				Serial2.print((uint8_t)Sensor->humidityOutside);
				reset();
			}
			
			//********************BME280 Inside********************
			if (Sensor->valuesChangedBME280Inside)
			{
				//********************Temperature********************
				Serial2.print("tempInside.txt=" + cmd + Sensor->temperatureInside + cmd);
				reset();
				Serial2.print("tempSignInside.val=");
				Serial2.print((int8_t)Sensor->temperatureInside * 3);
				reset();
				//********************Humidity********************
				Serial2.print("humInside.val=");
				Serial2.print((uint8_t)Sensor->humidityInside);
				reset();
				Serial2.print("humSignInside.val=");
				Serial2.print((uint8_t)Sensor->humidityInside);
				reset();
				//********************Pressure********************
				Serial2.print("presOutside.txt=" + cmd + (uint16_t)Sensor->pressureInside + cmd);
				reset();
			}
			
			//ENS160======================================================================
			Serial2.print("Voc.txt=" + cmd + (uint8_t)Sensor->TVOC + cmd);
			reset();
			Serial2.print("Co2.txt=" + cmd + (uint8_t)Sensor->ECO2 + cmd);
			reset();
			if (Sensor->AQI == 1) {
				Serial2.print("AirQualitySign.pic=");
				Serial2.print(13);
				reset();
			}
			else if (Sensor->AQI == 2) {
				Serial2.print("AirQualitySign.pic=");
				Serial2.print(12);
				reset();
			}
			else if (Sensor->AQI == 3) {
				Serial2.print("AirQualitySign.pic=");
				Serial2.print(11);
				reset();
			}
			else if (Sensor->AQI == 4) {
				Serial2.print("AirQualitySign.pic=");
				Serial2.print(10);
				reset();
			}
			else if (Sensor->AQI == 5) {
				Serial2.print("AirQualitySign.pic=");
				Serial2.print(9);
				reset();
			}
			else {
				Serial2.print("AirQualitySign.pic=");
				Serial2.print(13);
				reset();
			}
		//}
	}
}



void Nextion::reset() {
	Serial2.write(0xFF);
	Serial2.write(0xFF);
	Serial2.write(0xFF);
}