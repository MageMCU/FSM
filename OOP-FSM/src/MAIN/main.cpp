//
// Carpenter Software
// File: src: MAIN: main.cpp
//
// Purpose: Public Github Account - MageMCU
// Repository: FSM
// Date Created: 20230503
// Folder: OOP-FSM
//
// Code was adapted from Programming Game AI by Example (2005)
// by Mat Buckland...
//
// Author: Jesse Carpenter (carpentersoftware.com)
// Email:carpenterhesse@gmail.com
//
// Testing Platform:
//  * MCU:Atmega328P
//  * Editor: VSCode
//  * VSCode Extension: Microsoft C/C++ IntelliSense, debugging, and code browsing.
//  * VSCode Extension:PlatformIO
//
// MIT LICENSE
//

#include <Arduino.h>

#include "ManagerFSM.h"
#include "ManagerNames.h"
#include "Timer.h"

fsm::ManagerFSM sm;
nmr::Timer loopTimer;

void setup()
{
    Serial.begin(9600);
    while (!Serial)
    {
        /* code */
    }

    sm = fsm::ManagerFSM(manager_fsm);
}

void loop()
{
    if (loopTimer.isTimer(250))
    {
        sm.Update();
    }
}