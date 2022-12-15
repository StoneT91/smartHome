#include "LogicAlarm.h"
#include "Nextion.h"
#include "Sonar.h"
#include "Led.h"
#include "Buzzer.h"

//#define RXD2 32
//#define TXD2 33

Nextion nx;
Sonar so;
LogicAlarm la;

int masterKey = 4569;
int Alarm;

void setup() {
	Serial.begin(9600);
	Serial2.begin(9600);
	//Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
}
void loop() {
	nx.readSerialInterface(Alarm);
	la.logicAlarm(masterKey, &nx, so);
	Alarm = la.statusAlarm;
	for (int i = 0; i < 10; i++){
		updateLed(la.statusAlarm);
		buzzer(la.statusAlarm);
	}
	
}