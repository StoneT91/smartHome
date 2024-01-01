#include "Sensor.h"
#include "hardwareUpdate.h"
#include "Settings.h"
#include "ModuleOutsideBottom.h"
#include "AlarmSystem.h"
#include "Nextion.h"
#include "Led.h"
#include "Buzzer.h"
#include <esp_now.h>
#include <WiFi.h>
#include <Adafruit_GFX.h>

#define RXD2 32
#define TXD2 33
#define EEPROM_SIZE 1

Nextion nx;
LogicAlarm la;
ModuleOutsideBottom mob;
Settings set;
SensorClass Sensor;

bool TEST=false;
int statusAlarm;
int currentRunTime;

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
	set.setPasswort(&nx);
	la.logicAlarm(set.masterKey, &nx);
	hardwareUpdate(la.statusAlarm);

	//********************Update Sensors********************
	Sensor.updateSensors(1);
	//********************Update Display********************
	nx.serialInterface(la.statusAlarm, &Sensor, &mob);
}

void onDataReceive(const uint8_t* macAddress, const uint8_t* incomingData, int dataLength) {
	//DataStorage ds;
	memcpy(&mob, incomingData, sizeof(mob));
	Serial.println("Data received: " + String(dataLength));
	Sensor.temperatureOutside = float(mob.currentValueBme280[0]);
	Sensor.humidityOutside = float(mob.currentValueBme280[1]);
	Serial.println("----------------------------");
}