//
// Created by Shan7 on 2025/10/21.
//

#ifndef CODE_CONTROL_H
#define CODE_CONTROL_H

void Control(); // 主控制函数，将其他函数放入其中调用

void Movement(); // 移动

void LiftUp();  // 抬起外货舱

#endif //CODE_CONTROL_H
#include "Control.h"
#include <iostream>
#include <thread>
#include <chrono>

// 电机控制状态枚举
enum MotorState {
    STOPPED,
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// 货舱状态枚举
enum CargoState {
    LOWERED,
    RAISING,
    RAISED,
    LOWERING
};

// 全局状态变量
MotorState currentMotorState = STOPPED;
CargoState currentCargoState = LOWERED;
bool systemRunning = true;

void Movement() {
    std::cout << "=== 移动控制系统 ===" << std::endl;
    std::cout << "1. 前进" << std::endl;
    std::cout << "2. 后退" << std::endl;
    std::cout << "3. 左转" << std::endl;
    std::cout << "4. 右转" << std::endl;
    std::cout << "5. 停止" << std::endl;
    std::cout << "请选择移动指令: ";
    
    int choice;
    std::cin >> choice;
    
    switch(choice) {
        case 1:
            currentMotorState = FORWARD;
            std::cout << "执行: 前进移动" << std::endl;
            // 模拟前进过程
            for(int i = 0; i < 3; i++) {
                std::cout << "前进中..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
            break;
        case 2:
            currentMotorState = BACKWARD;
            std::cout << "执行: 后退移动" << std::endl;
            for(int i = 0; i < 3; i++) {
                std::cout << "后退中..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
            break;
        case 3:
            currentMotorState = LEFT;
            std::cout << "执行: 左转" << std::endl;
            for(int i = 0; i < 2; i++) {
                std::cout << "左转中..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
            break;
        case 4:
            currentMotorState = RIGHT;
            std::cout << "执行: 右转" << std::endl;
            for(int i = 0; i < 2; i++) {
                std::cout << "右转中..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
            break;
        case 5:
            currentMotorState = STOPPED;
            std::cout << "执行: 停止移动" << std::endl;
            break;
        default:
            std::cout << "无效指令，保持当前状态" << std::endl;
    }
    
    std::cout << "移动操作完成" << std::endl << std::endl;
}

void LiftUp() {
    std::cout << "=== 货舱控制系统 ===" << std::endl;
    
    if(currentCargoState == RAISED) {
        std::cout << "货舱已处于抬起状态" << std::endl;
        std::cout << "是否要降下货舱? (y/n): ";
        char choice;
        std::cin >> choice;
        
        if(choice == 'y' || choice == 'Y') {
            std::cout << "开始降下货舱..." << std::endl;
            currentCargoState = LOWERING;
            for(int i = 3; i > 0; i--) {
                std::cout << "降下中... " << i << "秒" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            currentCargoState = LOWERED;
            std::cout << "货舱已降下" << std::endl;
        }
    } else {
        std::cout << "当前货舱状态: " << (currentCargoState == LOWERED ? "降下" : "抬起中") << std::endl;
        std::cout << "开始抬起外货舱..." << std::endl;
        
        currentCargoState = RAISING;
        for(int i = 1; i <= 3; i++) {
            std::cout << "抬起中... " << i << "秒" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        currentCargoState = RAISED;
        std::cout << "外货舱已完全抬起" << std::endl;
    }
    std::cout << std::endl;
}

void DisplayStatus() {
    std::cout << "\n=== 系统状态 ===" << std::endl;
    
    // 显示移动状态
    std::string motorStatus;
    switch(currentMotorState) {
        case STOPPED: motorStatus = "停止"; break;
        case FORWARD: motorStatus = "前进"; break;
        case BACKWARD: motorStatus = "后退"; break;
        case LEFT: motorStatus = "左转"; break;
        case RIGHT: motorStatus = "右转"; break;
    }
    std::cout << "移动状态: " << motorStatus << std::endl;
    
    // 显示货舱状态
    std::string cargoStatus;
    switch(currentCargoState) {
        case LOWERED: cargoStatus = "降下"; break;
        case RAISING: cargoStatus = "抬起中"; break;
        case RAISED: cargoStatus = "已抬起"; break;
        case LOWERING: cargoStatus = "降下中"; break;
    }
    std::cout << "货舱状态: " << cargoStatus << std::endl;
    std::cout << "==================" << std::endl << std::endl;
}

void Control() {
    std::cout << "=== 主控制系统启动 ===" << std::endl;
    std::cout << "欢迎使用机器人控制系统" << std::endl;
    
    while(systemRunning) {
        std::cout << "\n=== 主控制菜单 ===" << std::endl;
        std::cout << "1. 移动控制" << std::endl;
        std::cout << "2. 货舱控制" << std::endl;
        std::cout << "3. 显示状态" << std::endl;
        std::cout << "4. 退出系统" << std::endl;
        std::cout << "请选择操作: ";
        
        int choice;
        std::cin >> choice;
        
        switch(choice) {
            case 1:
                Movement();
                break;
            case 2:
                LiftUp();
                break;
            case 3:
                DisplayStatus();
                break;
            case 4:
                systemRunning = false;
                std::cout << "系统关闭中..." << std::endl;
                break;
            default:
                std::cout << "无效选择，请重新输入" << std::endl;
        }
    }
    
    std::cout << "控制系统已安全关闭" << std::endl;
}
