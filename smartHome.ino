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

#define RXD2 32
#define TXD2 33

Nextion nx;
Sonar so;
LogicAlarm la;
BME280 bm;
Aht2x ah;
Ens160 en;
ModuleOutsideBottom mob;

int masterKey = 4569;
int statusAlarm;
int currentRunTime;

void setup() {
	Serial.begin(9600);
	Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
	WiFi.mode(WIFI_STA);
	if (esp_now_init() != ESP_OK) {
		Serial.println("Error init ESP-NOW");
		return;
	}
	esp_now_register_recv_cb((onDataReceive));
}

void loop() {
	currentRunTime = millis();
	nx.serialInterface(statusAlarm, currentRunTime, &bm, &ah, &en, &mob);
	la.logicAlarm(masterKey, &nx, so);
	bm.measureBme280(currentRunTime, 2000);
	ah.measureAht2x(currentRunTime, 2000);
	en.measureEns160(currentRunTime, 2000, &ah);
	statusAlarm = la.statusAlarm;
	for (int i = 0; i < 10; i++){
		updateLed(la.statusAlarm);
		buzzer(la.statusAlarm);
	}	
}

void onDataReceive(const uint8_t* macAddress, const uint8_t* incomingData, int dataLength) {
	//DataStorage ds;
	memcpy(&mob, incomingData, sizeof(mob));
	Serial.println("Data received: " + String(dataLength));
	mob.currentValueBme280[0] = float(mob.currentValueBme280[0]);
	mob.currentValueBme280[1] = float(mob.currentValueBme280[1]);
	mob.currentValueBme280[2] = float(mob.currentValueBme280[2]);
	Serial.println("----------------------------");
}