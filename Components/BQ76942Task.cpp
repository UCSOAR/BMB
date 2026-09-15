/*
 * BQ76942Task.cpp
 *
 *  Created on: Sep 15, 2026
 *      Author: jaddina
 */


#include "SystemDefines.hpp"
#include "Command.hpp"
#include "Task.hpp"
#include "BQ76942Task.hpp"

/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/

/************************************
 * VARIABLES
 ************************************/

/************************************
 * FUNCTION DECLARATIONS
 ************************************/



/************************************
 * FUNCTION DEFINITIONS
 ************************************/
BQ76942Task::BQ76942Task():Task(TASK_BQ76942_QUEUE_DEPTH_OBJS)
{

}

/**
 * @brief Initialize the BQ76942Task
 *        Do not modify this function aside from adding the task name
 */
void BQ76942Task::InitTask()
{
    // Make sure the task is not already initialized
    SOAR_ASSERT(rtTaskHandle == nullptr, "Cannot initialize BQ76942 task twice");

    // Create the driver instance. InitTask runs before the scheduler starts, so
    // heap allocation here is safe.
    if (bq_ == nullptr)
    {
        bq_ = new BQ76942(&hi2c3);
    }
    SOAR_ASSERT(bq_ != nullptr, "BQ76942Task::InitTask() - driver allocation failed");

    BaseType_t rtValue =
        xTaskCreate((TaskFunction_t)BQ76942Task::RunTask,
            (const char*)"BQ76942Task",
            (uint16_t)TASK_BQ76942_STACK_DEPTH_WORDS,
            (void*)this,
            (UBaseType_t)TASK_BQ76942_PRIORITY,
            (TaskHandle_t*)&rtTaskHandle);

                SOAR_ASSERT(rtValue == pdPASS, "BQ76942Task::InitTask() - xTaskCreate() failed");
}

void BQ76942Task::Run(void * pvParams){


    while (1) {

        Command cm;
        bool res = qEvtQueue->Receive(cm, 333);
        if(res){

        	HandleCommand(cm);
        }
    }
}

void BQ76942Task::HandleCommand(Command& cm){
	switch(cm.GetCommand()){
	case DATA_COMMAND:
		HandleRequestCommand(cm.GetTaskCommand());
		break;

	case TASK_SPECIFIC_COMMAND:
		break;

	default:
		SOAR_PRINT("BQ76942Task - Received Unsupported Global Command {%d}\n", cm.GetCommand());
		break;
	}

	cm.Reset();

}

void BQ76942Task::HandleRequestCommand(uint16_t taskCommand){
	switch(taskCommand){
	case BQ76942_REQUEST_CONNECT:
		HandleConnect();
		break;

	case BQ76942_REQUEST_CELL_VOLTAGES:
		HandleReadCellVoltages();
		break;

	case BQ76942_REQUEST_STACK_VOLTAGE:
		HandleReadStackVoltage();
		break;

	case BQ76942_REQUEST_CURRENT:
		HandleReadCurrent();
		break;

	case BQ76942_REQUEST_ALARM_STATUS:
		HandleReadAlarmStatus();
		break;

	case BQ76942_REQUEST_SAFETY_STATUS:
		HandleReadSafetyStatus();
		break;

	case BQ76942_REQUEST_ALL_MEASUREMENTS:
		HandleReadAllMeasurements();
		break;

	default:
		SOAR_PRINT("BQ76942Task - Received Unsupported Request Command {%d}\n", taskCommand);
		break;
	}


}

/************************************
 * REQUEST HANDLERS
 ************************************/

/**
 * @brief Probe the device on the I2C bus, then verify its device ID (0x7694).
 */
void BQ76942Task::HandleConnect()
{
	BQ76942::Status status = bq_->IsConnected();
	if (status != BQ76942::Status::OK)
	{
		SOAR_PRINT("BQ76942 - Not responding on I2C (%s)\n", StatusToString(status));
		return;
	}

	status = bq_->ReadDeviceID();
	if (status != BQ76942::Status::OK)
	{
		SOAR_PRINT("BQ76942 - ACKed but device ID mismatch (%s)\n", StatusToString(status));
		return;
	}

	SOAR_PRINT("BQ76942 - Connected, device ID OK\n");
}

/**
 * @brief Read and print every enabled cell voltage in mV.
 */
void BQ76942Task::HandleReadCellVoltages()
{
	const uint8_t cellCount = bq_->GetConfig().cellCount;
	for (uint8_t cell = 0; cell < cellCount; ++cell)
	{
		int16_t millivolts = 0;
		BQ76942::Status status = bq_->ReadCellVoltage(cell, millivolts);
		if (status != BQ76942::Status::OK)
		{
			SOAR_PRINT("BQ76942 - Cell %d read failed (%s)\n", cell + 1, StatusToString(status));
			return;
		}
		SOAR_PRINT("BQ76942 - Cell %2d: %5d mV\n", cell + 1, millivolts);
	}
}

/**
 * @brief Read and print the stack voltage. Units are userV (10 mV per count by default).
 */
void BQ76942Task::HandleReadStackVoltage()
{
	int16_t userVolts = 0;
	BQ76942::Status status = bq_->ReadStackVoltage(userVolts);
	if (status != BQ76942::Status::OK)
	{
		SOAR_PRINT("BQ76942 - Stack voltage read failed (%s)\n", StatusToString(status));
		return;
	}
	SOAR_PRINT("BQ76942 - Stack: %d x10mV (%d.%02d V)\n", userVolts, userVolts / 100, (userVolts < 0 ? -userVolts : userVolts) % 100);
}

/**
 * @brief Read and print the CC2 pack current. Units are userA (mA by default).
 */
void BQ76942Task::HandleReadCurrent()
{
	int16_t userAmps = 0;
	BQ76942::Status status = bq_->ReadCurrent(userAmps);
	if (status != BQ76942::Status::OK)
	{
		SOAR_PRINT("BQ76942 - Current read failed (%s)\n", StatusToString(status));
		return;
	}
	SOAR_PRINT("BQ76942 - Current: %d mA\n", userAmps);
}

/**
 * @brief Read and print the Alarm Status register (0x62).
 */
void BQ76942Task::HandleReadAlarmStatus()
{
	uint16_t alarmStatus = 0;
	BQ76942::Status status = bq_->ReadAlarmStatus(alarmStatus);
	if (status != BQ76942::Status::OK)
	{
		SOAR_PRINT("BQ76942 - Alarm status read failed (%s)\n", StatusToString(status));
		return;
	}
	SOAR_PRINT("BQ76942 - Alarm Status: 0x%04X  (ALERT pin %s)\n", alarmStatus, bq_->IsAlertAsserted() ? "HIGH" : "low");
}

/**
 * @brief Read and print Safety Status A/B/C (0x03/0x05/0x07).
 */
void BQ76942Task::HandleReadSafetyStatus()
{
	BQ76942::SafetyStatus safety;
	BQ76942::Status status = bq_->ReadSafetyStatus(safety);
	if (status != BQ76942::Status::OK)
	{
		SOAR_PRINT("BQ76942 - Safety status read failed (%s)\n", StatusToString(status));
		return;
	}
	SOAR_PRINT("BQ76942 - Safety Status A: 0x%02X  B: 0x%02X  C: 0x%02X\n", safety.a, safety.b, safety.c);
}

/**
 * @brief Read cells, stack voltage and current together and print them.
 */
void BQ76942Task::HandleReadAllMeasurements()
{
	BQ76942::Measurements m;
	BQ76942::Status status = bq_->ReadMeasurements(m);
	if (status != BQ76942::Status::OK)
	{
		SOAR_PRINT("BQ76942 - Measurement read failed (%s)\n", StatusToString(status));
		return;
	}

	const uint8_t cellCount = bq_->GetConfig().cellCount;
	for (uint8_t cell = 0; cell < cellCount; ++cell)
	{
		SOAR_PRINT("BQ76942 - Cell %2d: %5d mV\n", cell + 1, m.cellVoltage_mV[cell]);
	}
	SOAR_PRINT("BQ76942 - Stack: %d x10mV   Current: %d mA\n", m.stackVoltage_userV, m.current_userA);
}

/**
 * @brief Human readable driver status for log output.
 */
const char* BQ76942Task::StatusToString(BQ76942::Status status)
{
	switch (status)
	{
	case BQ76942::Status::OK:              return "OK";
	case BQ76942::Status::ERR_INVALID_ARG: return "INVALID_ARG";
	case BQ76942::Status::ERR_I2C:         return "I2C_ERROR";
	default:                               return "UNKNOWN";
	}
}


