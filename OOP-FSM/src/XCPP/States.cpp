//
// Carpenter Software
// File: src: XCPP: States.cpp
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

#include "States.h"
#include "State.h"
#include "ManagerFSM.h"
#include "ManagerNames.h"

fsm::IdleState *fsm::IdleState::Instance()
{
    static fsm::IdleState instance;
    return &instance;
}

void fsm::IdleState::Enter(fsm::ManagerFSM *pManager)
{
    Serial.println("Idle::Enter");
}

void fsm::IdleState::Execute(fsm::ManagerFSM *pManager)
{
    pManager->GetFSM()->TransitionToState(TestState::Instance());
}

void fsm::IdleState::Exit(fsm::ManagerFSM *pManager)
{
    Serial.println("Idle::Exit");
}

fsm::TestState *fsm::TestState::Instance()
{
    static fsm::TestState instance;
    return &instance;
}

void fsm::TestState::Enter(fsm::ManagerFSM *pManager)
{
    Serial.println("TestState::Enter");
}

void fsm::TestState::Execute(fsm::ManagerFSM *pManager)
{
    pManager->GetFSM()->TransitionToState(IdleState::Instance());
}

void fsm::TestState::Exit(fsm::ManagerFSM *pManager)
{
    Serial.println("TestState::Exit");
}
