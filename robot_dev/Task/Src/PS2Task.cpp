//
// Created by Shan7 on 2025/10/16.
//
#include "main.h"
#include "../Inc/PS2Task.h"
#include "PS2.h"
#include "cmsis_os.h"
#include "../../Bsp/Inc/bsp.h"

void PS2Task::run()
{
    // Init();
    // while(1)
    // {
    //     getData();
    //     getJoystick();
    //     if (isKey(5))
    //     {
    //         HAL_GPIO_WritePin(GPIOC, LED_Pin, GPIO_PIN_RESET);
    //     }
    //     else
    //     {
    //         HAL_GPIO_WritePin(GPIOC, LED_Pin, GPIO_PIN_SET);
    //     }
    // }
}


extern "C"{
    static PS2Task PS2_task;
    void PS2_Init()
    {

        PS2_task.start((char*)"PS2Task", 512, osPriorityAboveNormal);
    }
}