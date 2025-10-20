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
     * 1 -> 上        * 9 -> L2
     * 2 -> 左        * 10 -> R2
     * 3 -> 下        * 11 -> L1
     * 4 -> 右        * 12 -> R1
     * 5 -> 三角形     * 13 -> 左摇杆按钮
     * 6 -> 圆形       * 14 -> 右摇杆按钮
     * 7 -> x         * 15 -> SELECT
     * 8 -> 矩形       * 16 -> START








     */
    bool isKey(uint8_t key);
};

extern "C"{

    void Init();
    void getData();
    void getJoystick();
    bool isKey(uint8_t key);

}
#endif


#endif //ROBOT_PS2_H