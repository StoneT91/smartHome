//#include "Ens160.h"
//#include "AHT2x.h"
#include "BME280.h"
#include "LogicAlarm.h"
#include "Nextion.h"
#include "Sonar.h"
#include "Led.h"
#include "Buzzer.h"
#include <Wire.h>

//#define RXD2 32
//#define TXD2 33

Nextion nx;
Sonar so;
LogicAlarm la;
BME280 bm;
//Aht2x ah;
//Ens160 en;

int masterKey = 4569;
int statusAlarm;
int currentRunTime;

void setup() {
	Serial.begin(9600);
	Serial2.begin(9600);
}
void loop() {
	currentRunTime = millis();
	nx.serialInterface(statusAlarm, currentRunTime, &bm);
	la.logicAlarm(masterKey, &nx, so);
	bm.measureBme280(currentRunTime, 2000);
	statusAlarm = la.statusAlarm;
	for (int i = 0; i < 10; i++){
		updateLed(la.statusAlarm);
		buzzer(la.statusAlarm);
	}
}