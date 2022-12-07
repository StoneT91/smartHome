// 
// 
// 

#include "Alarm.h"
#include "Sonar.h"

bool motionDetection() {
	Sonar so;
	int currentDistanceSonar1 = so.measure(2, 3, 500);
	int currentDistanceSonar2 = so.measure(8, 9, 500);
	if (currentDistanceSonar1!=500 || currentDistanceSonar2 != 500) {
		return true;
	}
	else {
		return false;
	}
}



bool deactivateAlarm() {
	int longPressTime = 1000;
	int demandPin[4] = { 0,0,1,1 };
	int insertedPin[4] = {};
	int pinButton = 13;
	int buttonPressTime;
	int time = millis();
	int index;
	bool insertionCorrect;
	if (digitalRead(pinButton) == HIGH) {
		buttonPressTime = time;
		if (index == 4) {
			for (int i = 0; i < 4; i++)
			{
				if (demandPin[i] != insertedPin[i]) {
					return false;
				}
				if (i == 3) {
					return true;
				}
			}
		}
		if (buttonPressTime < longPressTime) {
			insertedPin[index] = 0;
		}
		else {
			insertedPin[index] = 1;
		}
		index++;
	}

}