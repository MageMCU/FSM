#ifndef NAMES_H
#define NAMES_H

#include "string.h"

enum 
{
  ent_Miner_Bob,

  ent_Elsa
};

// inline char* GetNameOfEntity(int n)
inline String GetNameOfEntity(int n)
{
  switch(n)
  {
  case ent_Miner_Bob:

    return "Miner Bob";

  case ent_Elsa:
    
    return "Elsa"; 

  default:

    return "UNKNOWN!";
  }
}

#endif