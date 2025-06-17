// Could work with iostream
// #include <iostream>
// Reduced memory usage
#include <cstdio>
#include <signal.h>

#include "Locations.h"
#include "Miner.h"
#include "MinersWife.h"
#include "EntityNames.h"

#include "Timer.h"

using namespace std;

csjc::Timer loopTimer;

// create a miner
Miner Bob(ent_Miner_Bob);

// create his wife
MinersWife Elsa(ent_Elsa);

// Main loop exit error
int _err_ = 0;

void setup()
{
    loopTimer = csjc::Timer();
}

int cnt = 0;
void loop()
{
    // wait in milliseconds
    if (loopTimer.isTimer(3000))
    {
        // cout << cnt++ << endl;
        printf("%d\n", cnt++);
        Bob.Update();
        Elsa.Update();
    }
}

void cleanup(int signo)
{
    // cout << "signo: " << signo << endl;
    printf("\nexit: signo: %d\n", signo);
    _err_ = -1;
}

int main()
{
    // BUGFIX - Terminal ctrl-c
    signal(SIGHUP, cleanup);
    signal(SIGINT, cleanup);
    signal(SIGTERM, cleanup);

    // Arduino like setup function
    setup();
    // Arduino like loop function
    while (_err_ == 0)
    {
        loop();
    }

    return _err_;
}
