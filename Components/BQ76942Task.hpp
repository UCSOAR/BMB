/*
 * BQ76942Task.hpp
 *
 *  Created on: Sep 15, 2026
 *      Author: jaddina
 */

#ifndef BQ76942TASK_HPP_
#define BQ76942TASK_HPP_


#include "Task.hpp"
#include "main.h"
#include "BQ76942.hpp"


/************************************
 * MACROS AND DEFINES
 ************************************/

extern I2C_HandleTypeDef hi2c3;

/************************************
 * TYPEDEFS
 ************************************/

/* Request commands understood by BQ76942Task.
 * Send as: Command cm(DATA_COMMAND, BQ76942_REQUEST_xxx); BQ76942Task::Inst().GetEventQueue()->Send(cm);
 */
enum BQ76942_TASK_COMMANDS : uint16_t
{
    BQ76942_COMMAND_NONE = 0,
    BQ76942_REQUEST_CONNECT,          // Probe the I2C address and verify the device ID
    BQ76942_REQUEST_CELL_VOLTAGES,    // Read every enabled cell voltage (mV)
    BQ76942_REQUEST_STACK_VOLTAGE,    // Read the stack voltage (userV, 10 mV units by default)
    BQ76942_REQUEST_CURRENT,          // Read the CC2 pack current (userA, mA by default)
    BQ76942_REQUEST_ALARM_STATUS,     // Read the Alarm Status register
    BQ76942_REQUEST_SAFETY_STATUS,    // Read Safety Status A/B/C
    BQ76942_REQUEST_ALL_MEASUREMENTS  // Cells + stack + current in one shot
};

/************************************
 * CLASS DEFINITIONS
 ************************************/

/************************************
 * FUNCTION DECLARATIONS
 ************************************/
class BQ76942Task: public Task
{
	public:
		static BQ76942Task& Inst() {
			static BQ76942Task inst;
			return inst;
		}

		void InitTask();



	protected:
		static void RunTask(void* pvParams) { BQ76942Task::Inst().Run(pvParams); } // Static Task Interface, passes control to the instance Run();
		void Run(void * pvParams); // Main run code
		void HandleCommand(Command& cm);
		void HandleRequestCommand(uint16_t taskCommand);



	private:
		// Private Functions
		BQ76942Task();       									// Private constructor
		BQ76942Task(const BQ76942Task&);                        // Prevent copy-construction
		BQ76942Task& operator=(const BQ76942Task&);				// Prevent assignment
		void LogData();

		// Request handlers
		void HandleConnect();
		void HandleReadCellVoltages();
		void HandleReadStackVoltage();
		void HandleReadCurrent();
		void HandleReadAlarmStatus();
		void HandleReadSafetyStatus();
		void HandleReadAllMeasurements();

		static const char* StatusToString(BQ76942::Status status);

		// Driver instance, created in InitTask (before the scheduler starts)
		BQ76942* bq_ = nullptr;
};


#endif /* BQ76942TASK_HPP_ */
