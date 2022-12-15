#include "LogicAlarm.h"

void LogicAlarm::logicAlarm(int mK,Button *bn, Sonar so) {
	statusBefore = statusAlarm;
	if (statusAlarm == 0 && bn->buttonValue[1] != 0) {
		alarmDelay = bn->buttonValue[1];
		//bn->buttonValue[1] = 0;
		statusAlarm = 1;
	}
	else if (statusAlarm == 1 && bn->buttonValue[1] != 0){
		bn->buttonValue[1] = 0;
	}
	else if (statusAlarm == 1 && so.measure(2, 3, 500) != 500) {
		statusAlarm = 2;
	}
	else if (statusAlarm == 1 && bn->buttonValue[2] != 0) {
		bn->buttonValue[2] = 0;
		statusAlarm = 0;
	}
	else if (statusAlarm == 2 && bn->buttonValue[2] == mK) {
		bn->buttonValue[2] = 0;
		statusAlarm = 0;
	}
}
