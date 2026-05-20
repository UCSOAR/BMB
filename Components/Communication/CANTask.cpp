/**
 ******************************************************************************
 * File Name          : BMBTask.cpp
 * Description        : File System Task implementation for USB storage operations
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include <Communication/Inc/CANTask.hpp>
#include "SystemDefines.hpp"
#include <stdint.h>
#include "stm32g4xx_hal.h"

bool CANTask::CANSendToMotherboardDirect(uint16_t logID, const uint8_t *msg) {
	return dau.SendMessageToMotherboardByLogID(logID, msg);
}

/**
 * @brief Constructor, sets up task
 */
CANTask::CANTask() : Task(TASK_BMB_QUEUE_DEPTH_OBJS)
{

}

/**
 * @brief Initialize the BMBTask
 */
void CANTask::InitTask()
{
	// Make sure the task is not already initialized
	SOAR_ASSERT(rtTaskHandle == nullptr, "Cannot initialize BMB task twice");

	// Start the task
	BaseType_t rtValue =
			xTaskCreate((TaskFunction_t)CANTask::RunTask,
					(const char *)"BMBTask",
					(uint16_t)TASK_BMB_STACK_DEPTH_WORDS,
					(void *)this,
					(UBaseType_t)TASK_BMB_TASK_PRIORITY,
					(TaskHandle_t *)&rtTaskHandle);

	// Ensure creation succeded
	SOAR_ASSERT(rtValue == pdPASS, "BMBTask::InitTask() - xTaskCreate() failed");
}

/**
 * @brief Instance Run loop for the BMB Task, runs on scheduler start as long as the task is initialized.
 * @param pvParams RTOS Passed void parameters, contains a pointer to the object instance, should not be used
 */
void CANTask::Run(void *pvParams)
{
	SOAR_PRINT("BMBTask::Run() - Starting task\n");

	osDelay(500);




	while (1)
	{
		/* Process commands in blocking mode */

		if(dau.GetCurrentState() == dau.UNINITIALIZED) {
			osDelay(100);
			SOAR_PRINT("attempting joining...\n");
			if (dau.TryRequestingJoiningNetwork()) {
				SOAR_PRINT("joined\n");
			}
		}
		dau.CheckCANCommands();

		Command cm;
		bool res = qEvtQueue->Receive(cm);
		if (res)
		{
			HandleCommand(cm);
		}

		osDelay(10);

		HandleCANCommands();

		if(dau.GetCurrentState() == CanAutoNodeDaughter::ERROR) {
			while(1) {
				SOAR_PRINT("canautonode errored out!\n");
				osDelay(500);
			}

		}

	}

}

/**
 * @brief Handles a command
 * @param cm Command reference to handle
 */
void CANTask::HandleCommand(Command &cm)
{
	// Handle task-specific commands
	if (cm.GetCommand() == TASK_SPECIFIC_COMMAND)
	{
		switch (cm.GetTaskCommand())
		{

		default:
			SOAR_PRINT("BMBTask - Received Unsupported Task Command {%d}\n", cm.GetTaskCommand());
			break;
		}
	}
	else
	{
		// Handle global commands if any
		SOAR_PRINT("BMBTask - Received Unsupported Global Command {%d}\n", cm.GetCommand());
	}

	// No matter what happens, we must reset allocated data
	cm.Reset();
}

