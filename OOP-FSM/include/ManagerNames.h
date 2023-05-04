//
// Carpenter Software
// File: include: ManagerNames.h
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

#ifndef FSM_Manager_Names_h
#define FSM_Manager_Names_h

enum
{
    manager_fsm = 1,
    manager_util
};

inline int GetManagerID(int n)
{
    switch (n)
    {
    // Used
    case manager_fsm:
        return manager_fsm;

    case manager_util:
        return manager_util;

    default:
        return -1;
    }
}
#endif
