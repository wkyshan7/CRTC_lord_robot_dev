//
// Created by Shan7 on 2025/10/16.
//

#include "../Inc/controlTask.h"
#include "../../Bsp/Inc/bsp.h"


void ControlTask::run()
{
    BSP_Init();
    while (1)
    {
        Servo_setAngle(160);
        osDelay(100);
    }
}

extern "C"{
    static ControlTask control_task;
    void ControlTask_Init()
    {
        control_task.start((char*)"ControlTask", 256, osPriorityNormal);
    }
}

