#include "Arduino.h"

#include "Locations.h"
#include "Miner.h"
#include "MinersWife.h"
#include "EntityNames.h"

#include "Timer.h"

using namespace std;

// fsm::ManagerFSM sm;
csjc::Timer loopTimer;

// create a miner
Miner Bob(ent_Miner_Bob);

// create his wife
MinersWife Elsa(ent_Elsa);

// Main loop exit error
int _err_ = 0;

void setup()
{
    Serial.begin(9600);
    while(!Serial) {}
    
    // sm = fsm::ManagerFSM(manager_fsm);
    loopTimer = csjc::Timer();
}

int cnt = 0;
void loop()
{
    // wait in milliseconds
    if (loopTimer.isTimer(3000))
    {
        // cout << cnt++ << endl;
        // printf("%d\n", cnt++);
        Serial.println(cnt++);
        Bob.Update();
        Elsa.Update();
        // sm.Update();
    }
}