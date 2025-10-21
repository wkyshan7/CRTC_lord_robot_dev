//
// Created by Shan7 on 2025/10/21.
//

#ifndef CODE_MECANUM_H
#define CODE_MECANUM_H

extern float MotorSpeed[4]; //各轮子数据 {LF, LB, RF, RB}

void MecanumCalculate(float Vx, float Vy, float omega);

#endif //CODE_MECANUM_H