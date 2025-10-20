//
// Created by Shan7 on 2025/10/16.
//
#pragma once

#ifndef ROBOT_BSP_H
#define ROBOT_BSP_H
#include "tim.h"

#ifdef __cplusplus


enum class MotorType
{
    DC,
    Servo,
};

class Motor
{
public:
    Motor(TIM_HandleTypeDef* tim, uint32_t channel, MotorType type);

    void Init();
    void setSpeed(float speed);  //[0.0, 1.0]  控制直流电机
    void setAngle(float angle);  //[0.0, 180.0]  控制舵机

private:
    TIM_HandleTypeDef* m_tim;
    uint32_t m_channel;
    MotorType m_type;
};
#endif

#ifdef __cplusplus
extern "C" {
#endif

    void BSP_Init();
    void Servo_setAngle(float angle);
    void DC_setSpeed(float duty);
#ifdef __cplusplus
}
#endif



#endif //ROBOT_BSP_H