//
// Created by Shan7 on 2025/10/16.
//

#include "../Inc/bsp.h"

#include <memory>

#include "tim.h"


Motor::Motor(TIM_HandleTypeDef* tim, uint32_t channel, MotorType type)
    : m_tim(tim), m_channel(channel), m_type(type){}

void Motor::setSpeed(float duty)
{
    if (m_type != MotorType::DC)
    {
        return;
    }
    if (duty < 0.0f)
    {
        duty = 0.0f;
    }
    if (duty > 1.0f)
    {
        duty = 1.0f;
    }

    auto compare = static_cast<uint32_t>(m_tim->Init.Period * duty);
    __HAL_TIM_SET_COMPARE(m_tim, m_channel, compare);
}

void Motor::setAngle(float angle)
{
    if (m_type != MotorType::Servo)
    {
        return;
    }
    if (angle < 0.0f)
    {
        angle = 0.0f;
    }
    if (angle > 180.0f)
    {
        angle = 180.0f;
    }
    auto pulse = static_cast<uint16_t>(angle / 180.0f);
    __HAL_TIM_SET_COMPARE(m_tim, m_channel, pulse);
}

void Motor::Init()
{
    HAL_TIM_PWM_Start(m_tim, m_channel);
}

extern "C"{
    static Motor DC(&htim2, TIM_CHANNEL_1, MotorType::DC);
    static Motor DC2(&htim2, TIM_CHANNEL_2, MotorType::DC);
    static Motor Servo(&htim2, TIM_CHANNEL_3, MotorType::DC);
    static Motor DC4(&htim2, TIM_CHANNEL_4, MotorType::DC);
    static Motor DC5(&htim4, TIM_CHANNEL_1, MotorType::DC);
    static Motor DC6(&htim4, TIM_CHANNEL_2, MotorType::DC);
    static Motor DC7(&htim4, TIM_CHANNEL_3, MotorType::DC);
    static Motor DC8(&htim4, TIM_CHANNEL_4, MotorType::DC);


    void BSP_Init()
    {
        Servo.Init();
        DC.Init();
        DC2.Init();

        DC4.Init();
        DC5.Init();
        DC6.Init();
        DC7.Init();
        DC8.Init();
    }

    void DC_setSpeed(float duty)
    {

    }
    void Servo_setAngle(float angle)
    {
        Servo.setAngle(angle);
    }
}

