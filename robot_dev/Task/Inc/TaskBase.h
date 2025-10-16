//
// Created by Shan7 on 2025/10/16.
//

#ifndef ROBOT_TASKBASE_H
#define ROBOT_TASKBASE_H

#pragma once
#include "cmsis_os.h"

#ifdef __cplusplus

class TaskBase
{
public:
    virtual ~TaskBase() = default;
    virtual void run() = 0;

    void start(char* name, uint32_t stacksize, osPriority  priority)
    {
        osThreadDef_t taskDef;

        taskDef.name      = name;
        taskDef.pthread   = taskEntry;
        taskDef.stacksize = stacksize;
        taskDef.tpriority = priority;
        taskDef.instances = 1;

        handle_ = osThreadCreate(&taskDef, this);
    }

protected:
    osThreadId handle_ = nullptr;

private:
    static void taskEntry(void *argument)
    {
        auto* task = static_cast<TaskBase*>(const_cast<void*>(argument));
        task->run();
    }
};

#endif



#endif //ROBOT_TASKBASE_H