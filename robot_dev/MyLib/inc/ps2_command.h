//
// Created by Shan7 on 2025/10/12.
//

#ifndef MOTOR_PS2_COMMAND_H
#define MOTOR_PS2_COMMAND_H


#include "main.h"
#include "stdbool.h"
void ScanKey();


/* 按键检测
 * button =
 *  1  -> 上
 *  2  -> 左
 *  3  -> 下
 *  4  -> 右
 *  5  -> 三角形
 *  6  -> ×
 *  7  -> 正方形
 *  8  -> 圆形
 *  9  -> L1
 *  10 -> L2
 *  11 -> R1
 *  12 -> R2
 *  13 -> start
 *  14 -> select
 *  15 -> L摇杆按键
 *  16 -> R摇杆按键
 */
bool isButton(int button);


#endif //MOTOR_PS2_COMMAND_H