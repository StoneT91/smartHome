#include "LogicAlarm.h"
#include "Nextion.h"
#include "Sonar.h"
#include "Led.h"
#include "Buzzer.h"

//#define RXD2 32
//#define TXD2 33

Button bn;
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
	bn.readSerialInterface(Alarm);
	la.logicAlarm(masterKey, &bn, so);
	Alarm = la.statusAlarm;
	updateLed(la.statusAlarm);
	buzzer(la.statusAlarm);
	//Serial.println(la.statusAlarm);
	//Serial.println(bn.buttonValue[1]);
}