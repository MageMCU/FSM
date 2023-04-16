
#include <Arduino.h>

#include "Manager.h"
#include "EntityNames.h"

#include "Timer.h"

// Manager
Manager fsm(ent_Manager);
// Timer
nmr::Timer loopTimer;

void setup()
{
    Serial.begin(9600);
    while (!Serial)
    {
        delay(10);
    }

    // Debug IDs for States...
    Serial.println("----------------------------");
    Serial.println("----------------------------");
    // Manager
    Serial.print("Manager ID: ");
    Serial.println(fsm.ID());
    Serial.println("----------------------------");
    // Manager
    Serial.print("pStateMachine ID: ");
    Serial.println(fsm.GetStateMachineID());
    Serial.println("----------------------------");
    // State Machine
    Serial.print("pOwner ID: ");
    Serial.println(fsm.GetFSM()->GetOwnerID());
    Serial.println("----------------------------");
}

void loop()
{
    if (loopTimer.isTimer(500))
        fsm.Update();
}