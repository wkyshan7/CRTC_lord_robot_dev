//
// Created by Shan7 on 2025/10/12.
//

#include <stdbool.h>

#include "main.h"
#include "ax_ps2.h"

extern JOYSTICK_TypeDef ps2;

void ScanKey(void)
{
    AX_PS2_ScanKey(&ps2);
    HAL_Delay(2);
}

bool isButton(uint8_t button_number)
/* 按键检测
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
{
    uint8_t cur_num;
    //btn1赋值
    switch (ps2.btn1)
    {
    case 1:  cur_num = 14;  break;
    case 2:  cur_num = 15;  break;
    case 4:  cur_num = 16;  break;
    case 8:  cur_num = 13;  break;
    case 16: cur_num = 1;   break;
    case 32: cur_num = 2;   break;
    case 64: cur_num = 3;   break;
    case 128:cur_num = 4;   break;
    default:
        cur_num = 0;
    }

    //btn2赋值
    switch (ps2.btn2)
    {
    case 1:  cur_num = 10;  break;
    case 2:  cur_num = 12;  break;
    case 4:  cur_num = 9;   break;
    case 8:  cur_num = 11;  break;
    case 16: cur_num = 5;   break;
    case 32: cur_num = 8;   break;
    case 64: cur_num = 6;   break;
    case 128:cur_num = 7;   break;
    default:
        cur_num = 0;
    }

    //判断是否与指定按键一致
    return (cur_num == button_number);
}
