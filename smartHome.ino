#include "Ens160.h"
#include "AHT2x.h"
#include "BME280.h"
#include "LogicAlarm.h"
#include "Nextion.h"
#include "Sonar.h"
#include "Led.h"
#include "Buzzer.h"
#include <WiFi.h>
#include <HTTPClient.h>


#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";

//Your IP address or domain name with URL path
const char* serverNameTemp = "http://192.168.4.1/temperature";
const char* serverNameHumi = "http://192.168.4.1/humidity";
const char* serverNamePres = "http://192.168.4.1/pressure";

String temperature;
String humidity;
String pressure;
unsigned long previousMillis = 0;
const long interval = 5000;



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

void setup() {
	Serial.begin(9600);
	Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
	//Serial2.begin(9600);

	WiFi.begin(ssid, password);
	


	/*
	//Serial.println("Connecting");
	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}
	*/
	
	//Serial.println("");
	//Serial.print("Connected to WiFi network with IP Address: ");
	//Serial.println(WiFi.localIP());
	

}

void loop() {
	
	
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
        // Check WiFi connection status
        if (WiFi.status() == WL_CONNECTED) {
            temperature = httpGETRequest(serverNameTemp);
            humidity = httpGETRequest(serverNameHumi);
            pressure = httpGETRequest(serverNamePres);
            Serial.println("Temperature: " + temperature + " *C - Humidity: " + humidity + " % - Pressure: " + pressure + " hPa");
            // save the last HTTP GET Request
            previousMillis = currentMillis;
        }
        else {
            Serial.println("WiFi Disconnected");
        }
    }
	


	





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



String httpGETRequest(const char* serverName) {
	WiFiClient client;
	HTTPClient http;

	// Your Domain name with URL path or IP address with path
	http.begin(client, serverName);

	// Send HTTP POST request
	int httpResponseCode = http.GET();

	String payload = "--";

	if (httpResponseCode > 0) {
		Serial.print("HTTP Response code: ");
		Serial.println(httpResponseCode);
		payload = http.getString();
	}
	else {
		Serial.print("Error code: ");
		Serial.println(httpResponseCode);
	}
	// Free resources
	http.end();

	return payload;
}

