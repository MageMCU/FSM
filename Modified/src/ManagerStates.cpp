#include "Arduino.h"

#include "ManagerStates.h"
#include "State.h"
#include "Manager.h"
#include "EntityNames.h"

RedLED *RedLED::Instance()
{
    static RedLED instance;

    return &instance;
}

void RedLED::Enter(Manager *pManager)
{
    Serial.println("RedLED Enter");
    pManager->ResetRedCnt();
}

void RedLED::Execute(Manager *pManager)
{
    Serial.println("RedLED Execute");
    int cnt = pManager->IncreaseRedCnt();
    if (cnt > RED_LED) 
    {
        pManager->GetFSM()->ChangeState(GreenLED::Instance());
    }
}

void RedLED::Exit(Manager *pManager)
{
    Serial.println("RedLED Exit");
}


YellowLED *YellowLED::Instance()
{
    static YellowLED instance;

    return &instance;
}

void YellowLED::Enter(Manager *pManager)
{
    Serial.println("YellowLED Enter");
    pManager->ResetYellowCnt();
}

void YellowLED::Execute(Manager *pManager)
{
    Serial.println("YellowLED Execute");
    int cnt = pManager->IncreaseYellowCnt();
    if (cnt > YELLOW_LED) 
    {
        pManager->GetFSM()->ChangeState(RedLED::Instance());
    }
}

void YellowLED::Exit(Manager *pManager)
{
    Serial.println("YellowLED Exit");
}


GreenLED *GreenLED::Instance()
{
    static GreenLED instance;

    return &instance;
}

void GreenLED::Enter(Manager *pManager)
{
    Serial.println("GreenLED Enter");
    pManager->ResetYellowCnt();
}

void GreenLED::Execute(Manager *pManager)
{
    Serial.println("GreenLED Execute");
    int cnt = pManager->IncreaseGreenCnt();
    if (cnt > GREEN_LED) 
    {
        pManager->GetFSM()->ChangeState(YellowLED::Instance());
    }
}

void GreenLED::Exit(Manager *pManager)
{
    Serial.println("GreenLED Exit");
}
