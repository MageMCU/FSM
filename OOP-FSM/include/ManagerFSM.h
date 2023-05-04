//
// Carpenter Software
// File: include: ManagerFSM.h
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

#ifndef FSM_Manager_h
#define FSM_Manager_h

#include <Arduino.h>
#include "BaseManager.h"
// #include "StateNames.h"
#include "States.h"
#include "StateMachine.h"

namespace fsm
{
    template <class manager_type>
    class StateFSM;

    class ManagerFSM : public fsm::BaseManager
    {
    private:
        StateMachine<ManagerFSM> *m_pStateMachine;

    public:
        ManagerFSM() = default;
        ManagerFSM(int id) : BaseManager(id)
        {
            m_pStateMachine = new StateMachine<ManagerFSM>(this);
            m_pStateMachine->SetCurrentState(IdleState::Instance());
        }

        ~ManagerFSM()
        {
            delete m_pStateMachine;
        }

        void Update();
        StateMachine<ManagerFSM> *GetFSM() const
        {
            return m_pStateMachine;
        }
    };

    inline void ManagerFSM::Update()
    {
        m_pStateMachine->Update();
    }
}

#endif
