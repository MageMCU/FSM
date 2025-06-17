#include "MinerOwnedStates.h"
#include "State.h"
#include "Miner.h"
#include "Locations.h"
#include "EntityNames.h"

// #include <iostream>
#include <cstdio>

//--------------------------------------methods for EnterMineAndDigForNugget

EnterMineAndDigForNugget* EnterMineAndDigForNugget::Instance()
{
  static EnterMineAndDigForNugget instance;

  return &instance;
}

void EnterMineAndDigForNugget::Enter(Miner* pMiner)
{
  //if the miner is not already located at the goldmine, he must
  //change location to the gold mine
  if (pMiner->Location() != goldmine)
  {
    // cout << GetNameOfEntity(pMiner->ID()) << ": " << "Walkin' to the goldmine" << "\n";
    printf("%s: Walkin' to the goldmine\n", GetNameOfEntity(pMiner->ID()).c_str());
    pMiner->ChangeLocation(goldmine);
  }
}


void EnterMineAndDigForNugget::Execute(Miner* pMiner)
{  
  //if the miner is at the goldmine he digs for gold until he
  //is carrying in excess of MaxNuggets. If he gets thirsty during
  //his digging he packs up work for a while and changes state to
  //gp to the saloon for a whiskey.
  pMiner->AddToGoldCarried(1);

  pMiner->IncreaseFatigue();

  // cout << GetNameOfEntity(pMiner->ID()) << ": " << "Pickin' up a nugget" << "\n";
    printf("%s: Pickin' up a nugget\n", GetNameOfEntity(pMiner->ID()).c_str());

  //if enough gold mined, go and put it in the bank
  if (pMiner->PocketsFull())
  {
    pMiner->GetFSM()->ChangeState(VisitBankAndDepositGold::Instance());
  }

  if (pMiner->Thirsty())
  {
    pMiner->GetFSM()->ChangeState(QuenchThirst::Instance());
  }
}


void EnterMineAndDigForNugget::Exit(Miner* pMiner)
{
  // cout << GetNameOfEntity(pMiner->ID()) << ": " 
  //     << "Ah'm leavin' the goldmine with mah pockets full o' sweet gold" << "\n";
    printf("%s: Ah'm leavin' the goldmine with mah pockets full o' sweet gold\n", GetNameOfEntity(pMiner->ID()).c_str());
}



//----------------------------------------methods for VisitBankAndDepositGold

VisitBankAndDepositGold* VisitBankAndDepositGold::Instance()
{
  static VisitBankAndDepositGold instance;

  return &instance;
}

void VisitBankAndDepositGold::Enter(Miner* pMiner)
{  
  //on entry the miner makes sure he is located at the bank
  if (pMiner->Location() != bank)
  {
    // cout << GetNameOfEntity(pMiner->ID()) << ": " << "Goin' to the bank. Yes siree" << "\n";
    printf("%s: Goin' to the bank. Yes siree\n", GetNameOfEntity(pMiner->ID()).c_str());

    pMiner->ChangeLocation(bank);
  }
}


void VisitBankAndDepositGold::Execute(Miner* pMiner)
{
  //deposit the gold
  pMiner->AddToWealth(pMiner->GoldCarried());
    
  pMiner->SetGoldCarried(0);

  // cout << GetNameOfEntity(pMiner->ID()) << ": " 
  //     << "Depositing gold. Total savings now: "<< pMiner->Wealth() << "\n";
    printf("%s: Depositing gold. Total savings now: %d\n", GetNameOfEntity(pMiner->ID()).c_str(), pMiner->Wealth());

  //wealthy enough to have a well earned rest?
  if (pMiner->Wealth() >= ComfortLevel)
  {
    // cout << GetNameOfEntity(pMiner->ID()) << ": " 
    //     << "WooHoo! Rich enough for now. Back home to mah li'lle lady" << "\n";
    printf("%s: WooHoo! Rich enough for now. Back home to mah li'lle lady\n", GetNameOfEntity(pMiner->ID()).c_str());
      
    pMiner->GetFSM()->ChangeState(GoHomeAndSleepTilRested::Instance());      
  }

  //otherwise get more gold
  else 
  {
    pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
  }

}


void VisitBankAndDepositGold::Exit(Miner* pMiner)
{
  // cout << GetNameOfEntity(pMiner->ID()) << ": " << "Leavin' the bank" << "\n";
  printf("%s: Leavin' the bank\n", GetNameOfEntity(pMiner->ID()).c_str());
}


//----------------------------------------methods for GoHomeAndSleepTilRested

GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::Instance()
{
  static GoHomeAndSleepTilRested instance;

  return &instance;
}

void GoHomeAndSleepTilRested::Enter(Miner* pMiner)
{
  if (pMiner->Location() != shack)
  {
    // cout << GetNameOfEntity(pMiner->ID()) << ": " << "Walkin' home" << "\n";
    printf("%s: Walkin' home\n", GetNameOfEntity(pMiner->ID()).c_str());

    pMiner->ChangeLocation(shack); 
  }
}

void GoHomeAndSleepTilRested::Execute(Miner* pMiner)
{ 
  //if miner is not fatigued start to dig for nuggets again.
  if (!pMiner->Fatigued())
  {
    // cout << GetNameOfEntity(pMiner->ID()) << ": " 
    //      << "What a God darn fantastic nap! Time to find more gold" << "\n";
    printf("%s: What a God darn fantastic nap! Time to find more gold\n", GetNameOfEntity(pMiner->ID()).c_str());

     pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
  }

  else 
  {
    //sleep
    pMiner->DecreaseFatigue();

    // cout << GetNameOfEntity(pMiner->ID()) << ": " << "ZZZZ... " << "\n";
    printf("%s: ZZZZ... \n", GetNameOfEntity(pMiner->ID()).c_str());
  } 
}

void GoHomeAndSleepTilRested::Exit(Miner* pMiner)
{ 
  // cout << GetNameOfEntity(pMiner->ID()) << ": " << "Leaving the house" << "\n";
    printf("%s: Leaving the house\n", GetNameOfEntity(pMiner->ID()).c_str());
}




//------------------------------------------------methods for QuenchThirst

QuenchThirst* QuenchThirst::Instance()
{
  static QuenchThirst instance;

  return &instance;
}

void QuenchThirst::Enter(Miner* pMiner)
{
  if (pMiner->Location() != saloon)
  {    
    pMiner->ChangeLocation(saloon);

    // cout << GetNameOfEntity(pMiner->ID()) << ": " << "Boy, ah sure is thusty! Walking to the saloon" << "\n";
    printf("%s: Boy, ah sure is thusty! Walking to the saloon\n", GetNameOfEntity(pMiner->ID()).c_str());
  }
}

void QuenchThirst::Execute(Miner* pMiner)
{
   if (pMiner->Thirsty())
   {
     pMiner->BuyAndDrinkAWhiskey();

     // cout << GetNameOfEntity(pMiner->ID()) << ": " << "That's mighty fine sippin' liquer" << "\n";
    printf("%s: That's mighty fine sippin' liquer\n", GetNameOfEntity(pMiner->ID()).c_str());

     pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
   }

  else 
  {
    // cout << "\nERROR!\nERROR!\nERROR!";
    printf("ERROR!\nERROR!\nERROR!\n");
  }  
}

void QuenchThirst::Exit(Miner* pMiner)
{ 
  // cout << GetNameOfEntity(pMiner->ID()) << ": " << "Leaving the saloon, feelin' good" << "\n";
    printf("%s: Leaving the saloon, feelin' good\n", GetNameOfEntity(pMiner->ID()).c_str());
}

