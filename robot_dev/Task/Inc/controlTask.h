//
// Created by Shan7 on 2025/10/16.
//

#ifndef ROBOT_CONTROLTASK_H
#define ROBOT_CONTROLTASK_H

#pragma once
#include "cmsis_os.h"
#include "TaskBase.h"
#include "../../Bsp/Inc/bsp.h"

class controlTask: public TaskBase
{
public:
    void run() override;

};


#endif //ROBOT_CONTROLTASK_H