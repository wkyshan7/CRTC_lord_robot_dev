//
// Created by Shan7 on 2025/10/20.
//

#include "../Inc/Bsp.h"

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
    auto pulse = static_cast<uint16_t>(angle / 180.0f * 2000.0f);
    __HAL_TIM_SET_COMPARE(m_tim, m_channel, pulse);
}

void Motor::Init()
{
    HAL_TIM_PWM_Start(m_tim, m_channel);
    __HAL_TIM_SET_COMPARE(m_tim, m_channel, 0);
}

extern "C"{
    static Motor DC1(&htim2, TIM_CHANNEL_1, MotorType::DC);
    static Motor DC2(&htim2, TIM_CHANNEL_2, MotorType::DC);
    static Motor DC3(&htim2, TIM_CHANNEL_3, MotorType::DC);
    static Motor DC4(&htim2, TIM_CHANNEL_4, MotorType::DC);
    static Motor DC5(&htim4, TIM_CHANNEL_1, MotorType::DC);
    static Motor DC6(&htim4, TIM_CHANNEL_2, MotorType::DC);
    static Motor DC7(&htim4, TIM_CHANNEL_3, MotorType::DC);
    static Motor DC8(&htim4, TIM_CHANNEL_4, MotorType::DC);
    static Motor Servo(&htim3, TIM_CHANNEL_3, MotorType::Servo);
    static Motor DC9(&htim3, TIM_CHANNEL_1, MotorType::DC);
    static Motor DC10(&htim3, TIM_CHANNEL_2, MotorType::DC);
    static Motor DC11(&htim3, TIM_CHANNEL_3, MotorType::DC);
    static Motor DC12(&htim3, TIM_CHANNEL_4, MotorType::DC);

    void BSP_Init()
    {
        DC1.Init();
        DC2.Init();
        DC3.Init();
        DC4.Init();
        DC5.Init();
        DC6.Init();
        DC7.Init();
        DC8.Init();
        Servo.Init();
        DC9.Init();
        DC10.Init();
        DC11.Init();
        DC12.Init();
    }

    void LF_setSpeed(float duty) //DC1, DC2
    {
        if (duty < -1.0f)
        {
            duty = -1.0f;
        }
        if (duty > 1.0f)
        {
            duty = 1.0f;
        }

        if (duty < 0.0f)
        {
            DC2.setSpeed(0-duty);
            DC1.setSpeed(0);
        }
        else if (duty > 0.0f)
        {
            DC1.setSpeed(duty);
            DC2.setSpeed(0);
        }
        else
        {
            DC1.setSpeed(0);
            DC2.setSpeed(0);
        }
    }

    void LB_setSpeed(float duty)  //DC3, DC4
    {
        if (duty < -1.0f)
        {
            duty = -1.0f;
        }
        if (duty > 1.0f)
        {
            duty = 1.0f;
        }

        if (duty < 0.0f)
        {
            DC4.setSpeed(0-duty);
            DC3.setSpeed(0);
        }
        else if (duty > 0.0f)
        {
            DC3.setSpeed(duty);
            DC4.setSpeed(0);
        }
        else
        {
            DC3.setSpeed(0);
            DC4.setSpeed(0);
        }
    }

    void RF_setSpeed(float duty)  //DC5, DC6
    {
        if (duty < -1.0f)
        {
            duty = -1.0f;
        }
        if (duty > 1.0f)
        {
            duty = 1.0f;
        }

        if (duty < 0.0f)
        {
            DC6.setSpeed(0-duty);
            DC5.setSpeed(0);
        }
        else if (duty > 0.0f)
        {
            DC5.setSpeed(duty);
            DC6.setSpeed(0);
        }
        else
        {
            DC5.setSpeed(0);
            DC6.setSpeed(0);
        }
    }

    void RB_setSpeed(float duty)  //DC7, DC8
    {
        if (duty < -1.0f)
        {
            duty = -1.0f;
        }
        if (duty > 1.0f)
        {
            duty = 1.0f;
        }

        if (duty < 0.0f)
        {
            DC8.setSpeed(0-duty);
            DC7.setSpeed(0);
        }
        else if (duty > 0.0f)
        {
            DC7.setSpeed(duty);
            DC8.setSpeed(0);
        }
        else
        {
            DC7.setSpeed(0);
            DC8.setSpeed(0);
        }
    }
    void Servo_setAngle(float angle)
    {
        Servo.setAngle(angle);
    }
    void Lift_setSpeed(float duty)
    {
        if (duty>0)
        {
            DC9.setSpeed(duty);
            DC10.setSpeed(0);
            DC11.setSpeed(duty);
            DC12.setSpeed(0);
        }
        else if (duty<0)
        {
            DC9.setSpeed(0);
            DC10.setSpeed(-duty);
            DC11.setSpeed(0);
            DC12.setSpeed(-duty);
        }
        else
        {
            DC9.setSpeed(0);
            DC10.setSpeed(0);
            DC11.setSpeed(0);
            DC12.setSpeed(0);
        }
    }
}

