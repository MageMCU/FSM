//
// Carpenter Software
// File: include: State.h
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

#ifndef FSM_State_h
#define FSM_State_h

namespace fsm
{
    template <class manager_type>
    class StateFSM
    {
    public:
        virtual ~StateFSM() {}
        virtual void Enter(manager_type *) = 0;
        virtual void Execute(manager_type *) = 0;
        virtual void Exit(manager_type *) = 0;
    };
}
#endif
