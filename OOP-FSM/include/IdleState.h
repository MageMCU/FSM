#ifndef FSM_IdleState_h
#define FSM_IdleState_h

#include <Arduino.h>

#include "State.h"
#include "Manager.h"
#include "EntityNames.h"

class Manager;
class IdleState : public State<Manager>
{
private:
    IdleState() {}
    IdleState(const IdleState &);
    IdleState &operator=(const IdleState &);

    int counter;
    void Progress(Manager *pManager);

public:
    static IdleState *Instance();

    virtual void Enter(Manager *manager);
    virtual void Execute(Manager *manager);
    virtual void Exit(Manager *manager);
};

IdleState *IdleState::Instance()
{
    static IdleState instance;
    return &instance;
}

void IdleState::Enter(Manager *pManager)
{
    Serial.println("Enter Idle State");
}

void IdleState::Execute(Manager *pManager)
{
    Progress(pManager);

    // ISSUE: pMinor: Incomplete type ----------------------------- FIXME
    // pManager->GetFSM()->ChangeState(TestState::Instance());
}

void IdleState::Exit(Manager *pManager)
{
    Serial.println("Exit Idle State");
}

void IdleState::Progress(Manager *pManager)
{
    if (counter % 5 == 0)
    {
        Serial.print("Idle State - pManager ID: ");
        Serial.println((int)pManager);
        Serial.println("Issue: invalid use of incomplete type 'class Manager' line 45");
        Serial.println("----------------------------");
    }
    counter++;
}
#endif