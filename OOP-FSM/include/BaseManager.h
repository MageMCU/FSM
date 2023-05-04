//
// Carpenter Software
// File: include: BaseManager.h
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

#ifndef FSM_Base_Manager_h
#define FSM_Base_Manager_h

namespace fsm
{
    class BaseManager
    {
    private:
        int m_ID;
        static int m_iNextValidID;
        void SetID(int val);

    public:
        BaseManager() {}
        BaseManager(int id)
        {
            SetID(id);
        }
        virtual ~BaseManager() {}
        virtual void Update() = 0;
        int ID() const
        {
            return m_ID;
        }
    };
}

#endif