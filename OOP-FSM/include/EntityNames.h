#ifndef FSM_Entity_Names_h
#define FSM_Entity_Names_h

#include <Arduino.h>

enum
{
    ent_Manager,
    ent_Utility
};

String GetNameOfEntity(int n)
{
    switch (n)
    {
    case ent_Manager:
        return "Manager";
    case ent_Utility:
        return "Utility";
    default:
        return "UNKNOWN!";
    }
}

#endif