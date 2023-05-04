//
// Carpenter Software
// File: include: StateMachine.h
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

#ifndef FSM_State_Machine_h
#define FSM_State_Machine_h

#include <Arduino.h>
#include "State.h"

namespace fsm
{
    template <class manager_type>
    class StateMachine
    {
    private:
        manager_type *m_pOwner;
        StateFSM<manager_type> *m_pCurrentState;

    public:
        StateMachine(manager_type *owner) : m_pOwner(owner),
                                            m_pCurrentState(NULL)
        {
        }
        virtual ~StateMachine() {}
        void Update() const
        {
            if (m_pCurrentState)
                m_pCurrentState->Execute(m_pOwner);
        }
        void SetCurrentState(StateFSM<manager_type> *s) { m_pCurrentState = s; }
        void TransitionToState(StateFSM<manager_type> *pNewState)
        {
            m_pCurrentState->Exit(m_pOwner);
            m_pCurrentState = pNewState;
            m_pCurrentState->Enter(m_pOwner);
        }
        StateFSM<manager_type> *CurrentState() const { return m_pCurrentState; }
    };
}
#endif
