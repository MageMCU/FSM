#include "Arduino.h"

#include "MinersWifeOwnedStates.h"
#include "MinersWife.h"
#include "Locations.h"
#include "EntityNames.h"

//-----------------------------------------------------------------------Global state
WifesGlobalState *WifesGlobalState::Instance()
{
  static WifesGlobalState instance;

  return &instance;
}

void WifesGlobalState::Execute(MinersWife *wife)
{
  // BUGFIX
  int rand = random(1, 100 + 1);

  // 1 in 10 chance of needing the bathroom
  if (rand < 10)
  {
    wife->GetFSM()->ChangeState(VisitBathroom::Instance());
  }
}

//---------------------------------------DoHouseWork

DoHouseWork *DoHouseWork::Instance()
{
  static DoHouseWork instance;

  return &instance;
}

void DoHouseWork::Enter(MinersWife *wife)
{
}

void DoHouseWork::Execute(MinersWife *wife)
{
  // BUGFIX
  int rand = random(0, 2 + 1);

  switch (rand)
  {
  case 0:

    // cout << GetNameOfEntity(wife->ID()) << ": Moppin' the floor" << "\n";
    // printf("%s: Moppin' the floor\n", GetNameOfEntity(wife->ID()).c_str());

    Serial.print(GetNameOfEntity(wife->ID()));
    Serial.println(": Moppin' the floor");

    break;

  case 1:

    // cout << GetNameOfEntity(wife->ID()) << ": Washin' the dishes" << "\n";
    // printf("%s: Washin' the dishes\n", GetNameOfEntity(wife->ID()).c_str());

    Serial.print(GetNameOfEntity(wife->ID()));
    Serial.println(": Washin' the dishes");

    break;

  case 2:

    // cout << GetNameOfEntity(wife->ID()) << ": Makin' the bed" << "\n";
    // printf("%s: Makin' the bed\n", GetNameOfEntity(wife->ID()).c_str());

    Serial.print(GetNameOfEntity(wife->ID()));
    Serial.println(": Makin' the bed");

    break;
  }
}

void DoHouseWork::Exit(MinersWife *wife)
{
}

//------------------------------------------------------------------------VisitBathroom
VisitBathroom *VisitBathroom::Instance()
{
  static VisitBathroom instance;

  return &instance;
}

void VisitBathroom::Enter(MinersWife *wife)
{
  // cout << GetNameOfEntity(wife->ID()) << ": Walkin' to the can. Need to powda mah pretty li'lle nose" << "\n";
  printf("%s: Walkin' to the can. Need to powda mah pretty li'lle nose\n", GetNameOfEntity(wife->ID()).c_str());
}

void VisitBathroom::Execute(MinersWife *wife)
{
  // cout << GetNameOfEntity(wife->ID()) << ": Ahhhhhh! Sweet relief!" << "\n";
  printf("%s: Ahhhhhh! Sweet relief!\n", GetNameOfEntity(wife->ID()).c_str());

  wife->GetFSM()->RevertToPreviousState();
}

void VisitBathroom::Exit(MinersWife *wife)
{
  // cout << GetNameOfEntity(wife->ID()) << ": Leavin' the Jon" << "\n";
  printf("%s: Leavin' the Jon\n", GetNameOfEntity(wife->ID()).c_str());
}