// 
// 
// 

#include "Alarm.h"
#include "Sonar.h"

bool motionDetection() {
	Sonar so;
	int currentDistanceSonar1 = so.measure(32, 33, 500);
	int currentDistanceSonar2 = so.measure(18, 19, 500);
	if (currentDistanceSonar1!=500 || currentDistanceSonar2 != 500) {
		return true;
	}
	else {
		return false;
	}
}
/*
bool deactivateAlarm(int idx, int pButton) {
	int longPressTime = 1000;
	

	int buttonPressTime;
	bool insertionCorrect;
	if (digitalRead(pinButton) == HIGH) {

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
*/