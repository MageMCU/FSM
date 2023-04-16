#ifndef FSM_TestState_h
#define FSM_TestState_h

#include <Arduino.h>

#include "State.h"
#include "Manager.h"
#include "EntityNames.h"

class Manager;
class TestState : public State<Manager>
{
private:
    TestState() {}
    TestState(const TestState &);
    TestState &operator=(const TestState &);

public:
    static TestState *Instance();

    virtual void Enter(Manager *manager);
    virtual void Execute(Manager *manager);
    virtual void Exit(Manager *manager);
};

TestState *TestState::Instance()
{
    static TestState instance;
    return &instance;
}

void TestState::Enter(Manager *pManager)
{
    Serial.println("Enter Test State");
}

void TestState::Execute(Manager *pManager)
{
    // pManager->GetFSM()->ChangeState(IdleState::Instance());
}

void TestState::Exit(Manager *pManager)
{
    Serial.println("Exit Test State");
}

#endif