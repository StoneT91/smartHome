#include "LogicAlarm.h"

void LogicAlarm::logicAlarm(int mK,Nextion *nx, Sonar so) {
	//statusBefore = statusAlarm;
	if (statusAlarm == 0 && nx->buttonValue[1] != 0) {
		statusAlarm = 1;
	}
	else if (statusAlarm == 1 && nx->buttonValue[1] != 0){
		nx->buttonValue[1] = 0;
	}
	else if (statusAlarm == 1 && so.measure(2, 3, 500) != 500) {
		statusAlarm = 2;
	}
	else if (statusAlarm == 1 && nx->buttonValue[2] != 0) {
		nx->buttonValue[2] = 0;
		statusAlarm = 0;
	}
	else if (statusAlarm == 2 && nx->buttonValue[2] == mK) {
		nx->buttonValue[2] = 0;
		statusAlarm = 0;
	}
}
