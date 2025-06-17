#ifndef Manager_h
#define Manager_h

#include "Arduino.h"
#include "BaseEntity.h"
#include "ManagerStates.h"
#include "StateMachine.h"

//the max cnt amount for each LED
const int RED_LED       = 5;
const int YELLOW_LED         = 3;
const int GREEN_LED        = 4;

class Manager : public BaseEntity
{
private:
    // an instance of the state machine class
    StateMachine<Manager> *m_pStateMachine;

    int m_iRedLED;
    int m_iYellowLED;
    int m_iGreenLED;

public:
    Manager(int id) : BaseEntity(id),
                        m_iRedLED(0),
                        m_iYellowLED(0),
                        m_iGreenLED(0)
    {
        m_pStateMachine = new StateMachine<Manager>(this);

        m_pStateMachine->SetCurrentState(RedLED::Instance());
    }
    ~Manager() {}

    // this must be implemented. Also
    // this is used in the Manager.cpp but
    // the StateMachine Update is also placed
    // here. This can be confusing....
    void Update();
    StateMachine<Manager>*  GetFSM()const{return m_pStateMachine;}

    int IncreaseRedCnt(){ m_iRedLED++; return m_iRedLED;}
    void ResetRedCnt(){ m_iRedLED = 0;}
    int IncreaseYellowCnt(){ m_iYellowLED++; return m_iYellowLED;}
    void ResetYellowCnt(){ m_iYellowLED = 0;}
    int IncreaseGreenCnt(){ m_iGreenLED++; return m_iGreenLED;}
    void ResetGreenCnt(){ m_iGreenLED = 0;}
};

#endif
