//
// Created by Shan7 on 2025/10/21.
//
#include "Mecanum.h"
#include "PS2.h"

float MotorSpeed[4];

void MecanumCalculate(float Vx, float Vy, float omega)
{
    float LENGTH = 0.6f;
    float WIDTH = 0.4f;
    float RADIUS = 1.0f;

    float R = LENGTH + WIDTH;

    MotorSpeed[0] = (Vx + Vy - omega * R) / RADIUS;
    MotorSpeed[1] = (Vx - Vy - omega * R) / RADIUS;
    MotorSpeed[2] = -(Vx + Vy + omega * R) / RADIUS;
    MotorSpeed[3] = -(Vx - Vy + omega * R) / RADIUS;
}