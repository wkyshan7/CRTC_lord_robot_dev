//
// Created by Shan7 on 2025/10/16.
//

#ifndef ROBOT_CONTROLTASK_H
#define ROBOT_CONTROLTASK_H

#pragma once
#include "cmsis_os.h"
#include "TaskBase.h"

#ifdef __cplusplus

class ControlTask: public TaskBase
{
public:
    void run() override;
};
#endif


#ifdef __cplusplus
extern "C"{
#endif
    void ControlTask_Init();

#ifdef __cplusplus
}
#endif

#endif //ROBOT_CONTROLTASK_H