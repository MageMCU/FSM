#include "Arduino.h"

#include "BaseEntity.h"
#include "EntityNames.h"
#include "Manager.h"
#include "Timer.h"

// Global Variables
csjc::Timer loopTimer;

// create a manager
Manager fsm(ent_Manager);

void setup()
{
    Serial.begin(9600);
    while (!Serial) {}{}
    
    loopTimer = csjc::Timer();
}

void loop()
{
    // wait in milliseconds
    if (loopTimer.isTimer(1000))
    {
        fsm.Update();
    }
}
