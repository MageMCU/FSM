#ifndef Entity_Names_h
#define Entity_Names_h

#include "Arduino.h"
#include "string.h"

enum 
{
  ent_Manager
};

inline String GetNameOfEntity(int n)
{
  switch(n)
  {
    case ent_Manager:

    return "Manager";

  default:

    return "UNKNOWN!";
  }
}

#endif