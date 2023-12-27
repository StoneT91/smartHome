#include "Sensor.h"
#include "SR04T.h"
#include "hardwareUpdate.h"
#include "HC_SR501.h"
#include "Settings.h"
#include "ModuleOutsideBottom.h"
#include "Ens160.h"
#include "AHT2x.h"
#include "BME280.h"
#include "LogicAlarm.h"
#include "Nextion.h"
#include "Sonar.h"
#include "Led.h"
#include "Buzzer.h"
#include <esp_now.h>
#include <WiFi.h>
#include <Adafruit_GFX.h>

#define RXD2 32
#define TXD2 33
#define EEPROM_SIZE 1


Nextion nx;
Sonar so;
LogicAlarm la;
BME280 bm;
Aht2x ah;
Ens160 en;
ModuleOutsideBottom mob;
Settings set;
SR04T sr;

SensorClass Sensor;

bool TEST=false;
int statusAlarm;
int currentRunTime;
uint16_t counter = 0U;

void setup() {
	EEPROM.begin(2);
	Serial.begin(9600);
	Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
	WiFi.mode(WIFI_STA);
	if (esp_now_init() != ESP_OK) {
		Serial.println("Error init ESP-NOW");
		return;
	}
	//set.eepromWriteInt(0, 1234); //Reset Passwort
	esp_now_register_recv_cb((onDataReceive));
	set.masterKey = set.eepromReadInt(0);
}

void loop() {
	//currentRunTime = millis();
	//bm.measureBme280(currentRunTime, 2000);
	//ah.measureAht2x(currentRunTime, 2000);
	//en.measureEns160(currentRunTime, 2000, &ah);

	//set.setPasswort(&nx);
	//la.logicAlarm(set.masterKey, &nx);

	//hardwareUpdate(la.statusAlarm);
	nx.serialInterface(la.statusAlarm, counter, &Sensor, &ah, &en, &mob);

	//Serial.println(sr.measure(13,12));
	Sensor.updateSensors(1, counter);
	(counter == 65535) ? counter = 0U : counter++;
}

void onDataReceive(const uint8_t* macAddress, const uint8_t* incomingData, int dataLength) {
	//DataStorage ds;
	memcpy(&mob, incomingData, sizeof(mob));
	Serial.println("Data received: " + String(dataLength));
	mob.currentValueBme280[0] = float(mob.currentValueBme280[0]);
	mob.currentValueBme280[1] = float(mob.currentValueBme280[1]);
	mob.currentValueBme280[2] = float(mob.currentValueBme280[2]);
	mob.currentValueBme280[3] = float(mob.currentValueBme280[3]);
	mob.currentValueBme280[4] = float(mob.currentValueBme280[4]);
	Serial.println("----------------------------");
}