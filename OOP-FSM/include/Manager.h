#ifndef FSM_Manager_h
#define FSM_Manager_h

#include <Arduino.h>

#include "BaseEntity.h"
#include "StateMachine.h"
#include "IdleState.h"

class Manager : public BaseEntity
{
private:
    StateMachine<Manager> *m_pStateMachine;

public:
    Manager(int id) : BaseEntity(id)
    {
        m_pStateMachine = new StateMachine<Manager>(this);
        m_pStateMachine->SetCurrentState(IdleState::Instance());
    }
    ~Manager() { delete m_pStateMachine; }

    void Update();
    int GetStateMachineID();
    StateMachine<Manager> *GetFSM() const { return m_pStateMachine; }
};

void Manager::Update()
{
    m_pStateMachine->Update();
}

int Manager::GetStateMachineID()
{
    return (int)m_pStateMachine;
}
#endif
