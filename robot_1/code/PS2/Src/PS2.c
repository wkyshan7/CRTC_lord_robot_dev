//
// Created by Shan7 on 2025/10/20.
//

#include "ax_ps2.h"
#include "PS2.h"

JOYSTICK_TypeDef ps2;
float Joystick[4];
uint8_t mode = 0;

void PS2_Init()
{
    AX_PS2_Init();
}

void PS2_ScanKey(JOYSTICK_TypeDef *JoystickStruct)
{
    AX_PS2_ScanKey(JoystickStruct);
    HAL_Delay(10);
}

uint8_t isKey(uint8_t key, JOYSTICK_TypeDef ps2)
{
    uint8_t pressedBtn;
    switch (ps2.btn1)
    {
    case 1:  pressedBtn = 15;  break;
    case 2:  pressedBtn = 13;  break;
    case 4:  pressedBtn = 14;  break;
    case 8:  pressedBtn = 16;  break;
    case 16: pressedBtn = 1;   break;
    case 32: pressedBtn = 2;   break;
    case 64: pressedBtn = 3;   break;
    case 128:pressedBtn = 4;   break;
    default: pressedBtn = 0;   break;
    }
    switch (ps2.btn2)
    {
    case 1:  pressedBtn = 9;  break;
    case 2:  pressedBtn = 10;  break;
    case 4:  pressedBtn = 11;  break;
    case 8:  pressedBtn = 12;  break;
    case 16: pressedBtn = 5;   break;
    case 32: pressedBtn = 6;   break;
    case 64: pressedBtn = 7;   break;
    case 128:pressedBtn = 8;   break;
    default: pressedBtn = 0;   break;
    }
    if (pressedBtn == key)
    {
        return 1;
    }
    return 0;
}

void getJoystick(JOYSTICK_TypeDef ps2)
{
    if (ps2.mode == 65)  // 判断PS2是否为红灯模式，如果是，所有摇杆数据皆为0
    {

        for (int i=0; i < 4; i++)
            {
            Joystick[i] = 0;
            }
        // if (isKey(1, ps2))
        // {
        //     Joystick[0] = 100;
        //     Joystick[1] = 0;
        //     Joystick[2] = 0;
        //     Joystick[3] = 0;
        // }
        // if (isKey(3, ps2))
        // {
        //     Joystick[0] = -100;
        //     Joystick[1] = 0;
        //     Joystick[2] = 0;
        //     Joystick[3] = 0;
        // }
        // if (isKey(2, ps2))
        // {
        //     Joystick[0] = 0;
        //     Joystick[1] = 100;
        //     Joystick[2] = 0;
        //     Joystick[3] = 0;
        // }
        // if (isKey(1, ps2))
        // {
        //     Joystick[0] = 0;
        //     Joystick[1] = -100;
        //     Joystick[2] = 0;
        //     Joystick[3] = 0;
        // }
        return;
    }

    uint8_t dataJoystick[4] = {ps2.LJoy_UD, ps2.LJoy_LR, ps2.RJoy_UD, ps2.RJoy_LR};
    for (int i=0; i < 4; i++)  //处理摇杆数据
    {
        if (dataJoystick[i] < 124)
        {
            Joystick[i] = ((128-dataJoystick[i])*100)/128;
        }
        else if (dataJoystick[i] > 134)
        {
            Joystick[i] = ((dataJoystick[i]-127)*100*-1)/128;
        }
        else
        {
            Joystick[i] = 0;
        }
    }
}