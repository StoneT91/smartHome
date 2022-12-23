//#include "wifiCommunication.h"
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

int masterKey = 4569;
int statusAlarm;
int currentRunTime;



struct messageStruct {
	//char myString[32];
	float tempOutside;
	int humOutside;
	int presOutside;
};

messageStruct messageData;

void onDataReceive(const uint8_t* macAddress, const uint8_t* incomingData, int dataLength)
{
	memcpy(&messageData, incomingData, sizeof(messageData));
	Serial.println("Data received: " + String(dataLength));
	Serial.println("tempOutside " + String(messageData.tempOutside));
	Serial.println("humOutside: " + String(messageData.humOutside));
	Serial.println("presOutside: " + String(messageData.presOutside));
	Serial.println("----------------------------");
}

void setup() {
	Serial.begin(9600);
	Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
	//Serial2.begin(9600);

	WiFi.mode(WIFI_STA);
	if (esp_now_init() != ESP_OK) {
		Serial.println("Error init ESP-NOW");
		return;
	}
	esp_now_register_recv_cb(onDataReceive);

}

void loop() {
	currentRunTime = millis();
	nx.serialInterface(statusAlarm, currentRunTime, &bm, &ah, &en);
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