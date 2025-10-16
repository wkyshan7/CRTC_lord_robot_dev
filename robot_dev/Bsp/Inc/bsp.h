//
// Created by Shan7 on 2025/10/16.
//
#pragma once

#ifndef ROBOT_BSP_H
#define ROBOT_BSP_H
#include "stm32f1xx_hal_tim.h"

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


extern "C" {

    void Init();
    void setSpeed();
    void setAngle();

}
#endif



#endif //ROBOT_BSP_H