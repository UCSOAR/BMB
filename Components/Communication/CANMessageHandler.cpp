/*
 * CANMessageHandler.cpp
 *
 *  Created on: May 3, 2026
 *      Author: Local user
 */


#include "CANTask.hpp"

/* @brief Handle user-defined CANBus messages.
 * @return true if any message found.
 */
bool CANTask::HandleCANCommands() {
	bool foundone = false;
	{
		BMB_POWER_COMMAND cmd;
		if(dau.ReadMessageByLogIndex(_BMB_POWER_COMMAND_LOGINDEX, (uint8_t*)&cmd, sizeof(cmd))) {
			SOAR_PRINT("got airbrakes cmd %d\n",cmd.enable);
		}
		foundone= true;
	}



	return foundone;
};
