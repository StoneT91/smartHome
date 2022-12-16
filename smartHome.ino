#include "gasSensorEns160.h"
#include "AHT2x.h"
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
Aht2x ah;
gasSensorEns160 gs;


int masterKey = 4569;
int Alarm;
int currentRunTime;




#define I2C_COMMUNICATION
#ifdef  I2C_COMMUNICATION
DFRobot_ENS160_I2C ENS160(&Wire, 0x53);
#else
uint8_t csPin = 7;
DFRobot_ENS160_SPI ENS160(&SPI, csPin);
#endif


void setup() {
	Serial.begin(9600);
	Serial2.begin(9600);
}
void loop() {
	

	ENS160.setPWRMode(ENS160_STANDARD_MODE);
	ENS160.setTempAndHum(/*temperature=*/25.0, /*humidity=*/50.0);


	uint8_t Status = ENS160.getENS160Status();
	uint8_t AQI = ENS160.getAQI();
	uint16_t TVOC = ENS160.getTVOC();
	uint16_t ECO2 = ENS160.getECO2();

	Serial.println(Status); //Sensor operating status : "
	Serial.println(AQI); //Air quality index : "
	Serial.println(TVOC); //Concentration of total volatile organic compounds : ppb
	Serial.println(ECO2);//Carbon dioxide equivalent concentration :   ppm




	currentRunTime = millis();
	nx.serialInterface(Alarm, currentRunTime, &bm);
	la.logicAlarm(masterKey, &nx, so);
	bm.measureBme280(currentRunTime, 2000);
	ah.measureAHT2x(currentRunTime, 2000);
	gs.measureEns160(currentRunTime, 2000);
	//Serial.println(ah.currentValueAht2x[1]);
	Alarm = la.statusAlarm;
	for (int i = 0; i < 10; i++){
		updateLed(la.statusAlarm);
		buzzer(la.statusAlarm);
	}
}