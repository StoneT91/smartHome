/**
 * \brief	updates status of the alarm
 * if the activation button is pressed, the alarm status will change to "1"
 * if the activation button is pressed, and the alarm status = 1 --> reset activation button
 * if the sonar detects something and the alarmstatus is 1, the alarm status will change to "2"
 * if the deactivation button is pressed, and the passed key = masterkey --> the alarm status will change to "0"
 * 
 * \author	Timo Steiner
 *
 * \date	16.12.2022
 *
 * \param	mk = master key
 * \param	nx = button values from nextion display
 * \param	so = sensor value from sonar
 *
 * \return	void --> prints the status in variable "statusAlarm"
 */

#include "LogicAlarm.h"

void LogicAlarm::logicAlarm(int mK,Nextion *nx, Sonar so) {
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