//
// Created by Shan7 on 2025/10/21.
//

#include "Control.h"
#include "PS2.h"
#include "Mecanum.h"
#include "Bsp.h"

// 全局变量定义
PS2_Data ps2;
int Joystick[4] = {0};       // [0]:x轴,[1]:Y轴,[2]:Z轴，[3]:旋转
float MotorSpeed[4] = {0};

//控制参数
#define MAX_MOTOR_SPEED 255;
#define DEAD_ZONE 20;

void Control_Init(void)
{
   PS2_Init();
   Motor_Init();
   Servo_Init();
   for (int i = 0; i < 4; i++){
        Joystick[i] = 0;
        MotorSpeed[i] = 0;
   }
}

void Control(void)
{
    // 扫描PS2手柄按键
   if(PS2_ScanKey(&ps2) == PS2_SUCCESS) {
       // 获取摇杆数据
       getJoystick(ps2);

       // 执行移动控制
       Movement();

       // 执行提升机构控制
       LiftUp();
   }
}

void getJoystick(PS2_Data ps2_data)
{
//获取左摇杆数据（X,Y)
Joystick[0] = ps2_data.left_stick_x - 128;
Joystick[1] = ps2_data.left_stick_y - 128;

//获取右摇杆数据（Z,旋转）
Joystick[2] = ps2_data.right_stick_x - 128;
Joystick[3] = ps2_data.right_stick_y - 128;

//应用死区处理
   for(int i = 0; i < 4; i++) {
       if(abs(Joystick[i]) < DEAD_ZONE) {
        Joystick[i] = 0;
       }
   }
}

void Movement(void)
{
    // 使用全向轮运动学计算
    MecanumCalculate(Joystick[0], Joystick[1], Joystick[3]);

    // 设置电机速度
    LF_setSpeed(MotorSpeed[0]);
    LB_setSpeed(MotorSpeed[1]);
    RF_setSpeed(MotorSpeed[2]);
    RB_setSpeed(MotorSpeed[3]);
}

void HecanumCalculate(int joyX, int joyY,int rotation)
{
   //归一化输入（-127 to 127）到（-1.0 to 1.0)
   float x = (float)joyX /m127.0f;
float y = (float)joyY / 127.0f;
float rot = (float)rotation / 127.0f;

MotorSpeed[0] = x + y + rot;
MotorSpeed[1] = -x + y + rot;
MotorSpeed[2] = -x + y - rot;
MotorSpeed[3] = x + y - rot;

   //限制电机速度在合理范围内
   float maxSpeed = 0;
   for(int i = 0; i < 4; i++) {
       if(fabs(MotorSpeed[i]) > maxSpeed) {
          maxSpeed = fabs(MotorSpeed[i]);
       }
   }
   if(maxSpeed > 1.0f){
     for(int i = 0; i < 4; i++) {
         MotorSpeed[i] /= maxSpeed;
     }
   }

   for(int i = 0; i < 4; i++) {
       MotorSpeed[i] *= MAX_MOTOR_SPEED;
   }
}

void LiftUp(void)
{
    if (isKey(5, ps2))
    {
        Servo_setAngle(90);
    }
    else
    {
        Servo_setAngle(0);
    }
}