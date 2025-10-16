//
// Created by Shan7 on 2025/10/16.
//

#ifndef ROBOT_PS2_H
#define ROBOT_PS2_H


#include "ax_ps2.h"

#ifdef __cplusplus
class PS2
{
public:
    JOYSTICK_TypeDef ps2;
    int Joystick[4]; //[LUD,LLR,RUD,RLR] range:[-100, 100]

    static void Init();
    void getData();
    void getJoystick();


    /* 按键检测
     * 1 -> 上
     * 2 -> 左
     * 3 -> 下
     * 4 -> 右
     * 5 -> 三角形
     * 6 -> 圆形
     * 7 -> x
     * 8 -> 矩形
     * 9 -> L2
     * 10 -> R2
     * 11 -> L1
     * 12 -> R1
     * 13 -> 左摇杆按钮
     * 14 -> 右摇杆按钮
     * 15 -> SELECT
     * 16 -> START
     */
    bool isKey(uint8_t key);
};

extern "C"{

    void Init();
    void getData();
    void getJoystick();
    void isKey(uint8_t key);

}
#endif


#endif //ROBOT_PS2_H