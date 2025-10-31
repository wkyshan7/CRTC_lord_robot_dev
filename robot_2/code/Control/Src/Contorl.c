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
    MecanumCalculate(-Joystick[0]/100, Joystick[1]/100, -Joystick[3]/50);

    float Gear_0 = 0.6f;
    float Gear_1 = 0.6f;
    float Gear_2 = 0.9f;

    if (isKey(10, ps2))
    {
        if (mode < 2)
        {
            mode += 2;
        }
    }
    else if (isKey(9, ps2))
    {
        if (mode > 0)
        {
            mode -= 1;
        }

    }

    if (mode == 0)
    {
        MotorSpeed[0] = MotorSpeed[0] * Gear_0;
        MotorSpeed[1] = MotorSpeed[1] * Gear_0;
        MotorSpeed[2] = MotorSpeed[2] * Gear_0;
        MotorSpeed[3] = MotorSpeed[3] * Gear_0;

    }
    else if (mode == 1)
    {
        MotorSpeed[0] = MotorSpeed[0] * Gear_1;
        MotorSpeed[1] = MotorSpeed[1] * Gear_1;
        MotorSpeed[2] = MotorSpeed[2] * Gear_1;
        MotorSpeed[3] = MotorSpeed[3] * Gear_1;
    }
    else if (mode == 2)
    {
        MotorSpeed[0] = MotorSpeed[0] * Gear_2;
        MotorSpeed[1] = MotorSpeed[1] * Gear_2;
        MotorSpeed[2] = MotorSpeed[2] * Gear_2;
        MotorSpeed[3] = MotorSpeed[3] * Gear_2;
    }

    LF_setSpeed(MotorSpeed[0]);
    LB_setSpeed(MotorSpeed[1]);
    RF_setSpeed(MotorSpeed[2]);
    RB_setSpeed(MotorSpeed[3]);

}

void LiftUp()
{
    if (isKey(5, ps2))
    {
        Lift_setSpeed(0.1f);
        // Lift_setSpeed(0.0f);
    }
    else if (isKey(7, ps2))
    {
        Lift_setSpeed(-0.1f);
        // Lift_setSpeed(0.0f);
    }
    else
    {
        Lift_setSpeed(0.0f);
    }
}

void Door()
{
    if (isKey(15, ps2))
    {
        Servo_setAngle(90);
    }
    else if (isKey(16, ps2))
    {
        Servo_setAngle(180);
    }
}