//
// Carpenter Software
// File: src: XCPP: BaseManager.cpp
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

#include "BaseManager.h"

int fsm::BaseManager::m_iNextValidID = 0;
void fsm::BaseManager::SetID(int val)
{
    m_ID = val;
    m_iNextValidID = m_ID + 1;
}
