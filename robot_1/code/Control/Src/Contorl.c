//
// Created by Shan7 on 2025/10/21.
//

#include "Control.h"
#include "PS2.h"
#include "Mecanum.h"
#include "Bsp.h"

void Control()
{
    PS2_ScanKey(&ps2);
    getJoystick(ps2);
    Movement();
    LiftUp();
}

void Movement()
{
    MecanumCalculate(Joystick[0]/100, Joystick[1]/100, Joystick[3]/100);

    LF_setSpeed(MotorSpeed[0]);
    LB_setSpeed(MotorSpeed[1]);
    RF_setSpeed(MotorSpeed[2]);
    RB_setSpeed(MotorSpeed[3]);
}

void LiftUp()
{
    if (isKey(5, ps2))
    {
        // Servo_setAngle(90);
    }
    else
    {
        // Servo_setAngle(0);
    }
}