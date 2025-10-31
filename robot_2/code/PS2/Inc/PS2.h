//
// Created by Shan7 on 2025/10/20.
//

#ifndef CODE_PS2_H
#define CODE_PS2_H

#include "ax_ps2.h"


extern uint8_t mode;
extern JOYSTICK_TypeDef ps2;
extern float Joystick[4]; //摇杆数据 [L_UD,L_LR,R_UD,R_LR] range:[-100, 100]

/*初始化PS2*/
void PS2_Init();

/*扫描PS2按键
 传入参数：
  *JoystickStruct = &ps2
 */
void PS2_ScanKey(JOYSTICK_TypeDef *JoystickStruct);

/*判断按键是否按下
 传入参数：
    key：按键编号
     * 1 -> 上        * 9 -> L2
     * 2 -> 左        * 10 -> R2
     * 3 -> 下        * 11 -> L1
     * 4 -> 右        * 12 -> R1
     * 5 -> 三角形     * 13 -> 左摇杆按钮
     * 6 -> 圆形       * 14 -> 右摇杆按钮
     * 7 -> x         * 15 -> SELECT
     * 8 -> 矩形       * 16 -> START

    ps2:ps2

  返回值：
    1:按下   0:未按下
 */
uint8_t isKey(uint8_t key, JOYSTICK_TypeDef ps2);

/*获取摇杆数据
 传入参数：
 ps2:ps2
 */
void getJoystick(JOYSTICK_TypeDef ps2);



#endif //CODE_PS2_H