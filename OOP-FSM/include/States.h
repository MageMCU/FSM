//
// Carpenter Software
// File: include: States.h
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

#ifndef FSM_States_h
#define FSM_States_h

#include <Arduino.h>
#include "State.h"

namespace fsm
{
    class ManagerFSM;
    
    class IdleState : public fsm::StateFSM<ManagerFSM>
    {
    private:
        IdleState() {}
        IdleState(const IdleState &);
        IdleState &operator=(const IdleState &);

    public:
        static IdleState *Instance();
        virtual void Enter(ManagerFSM *manager) override;
        virtual void Execute(ManagerFSM *manager) override;
        virtual void Exit(ManagerFSM *manager) override;
    };

    class TestState : public StateFSM<ManagerFSM>
    {
    private:
        TestState() {}
        TestState(const TestState &);
        TestState &operator=(const TestState &);

    public:
        static TestState *Instance();
        virtual void Enter(ManagerFSM *manager) override;
        virtual void Execute(ManagerFSM *manager) override;
        virtual void Exit(ManagerFSM *manager) override;
    };
}

#endif
