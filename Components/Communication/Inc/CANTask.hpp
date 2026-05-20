/**
 ******************************************************************************
 * File Name          : CANTask.hpp
 * Description        : canbus manager
 ******************************************************************************
 */
#ifndef CUBE_SYSTEM_CAN_TASK_HPP_
#define CUBE_SYSTEM_CAN_TASK_HPP_

/* Includes ------------------------------------------------------------------*/
#include "Task.hpp"
#include "SystemDefines.hpp"
#include <stdint.h>
#include "CanAutoNodeDaughter.hpp"
#include "BMBLogs.hpp"
#include "CANBusTargets.hpp"

/* Enums ------------------------------------------------------------------*/
enum BMB_TASK_COMMANDS
{
    BMB_TASK_COMMAND_NONE = 0,
    EVENT_BMB_INIT,
    EVENT_BMB_TEST,
    EVENT_BMB_LOG_DATA,
    EVENT_BMB_CLEANUP
};

/* Macros ------------------------------------------------------------------*/

extern FDCAN_HandleTypeDef hfdcan2;
/* Class ------------------------------------------------------------------*/
class CANTask : public Task
{
public:
    static CANTask &Inst()
    {
        static CANTask inst;
        return inst;
    }

    void InitTask();


    bool CANSendToMotherboardDirect(uint16_t logID, const uint8_t* msg);

protected:
    static void RunTask(void *pvParams)
    {
        CANTask::Inst().Run(pvParams);
    } // Static Task Interface, passes control to the instance Run();

    void Run(void *pvParams); // Main run code
    void HandleCommand(Command &cm);
    bool HandleCANCommands();

private:
    // Private Functions
    CANTask();                                  // Private constructor
    CANTask(const CANTask &);            // Prevent copy-construction
    CANTask &operator=(const CANTask &); // Prevent assignment

    CanAutoNodeDaughter dau = {&hfdcan2,BMB_Init,BMB_LogIndexes::BMB_COUNT,CAN_ROCKET_TARGET_BMB_BOARDTYPE,0,CAN_ROCKET_TARGET_BMB};

};

#endif // CUBE_SYSTEM_BMB_TASK_HPP_
