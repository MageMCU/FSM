#ifndef Manager_States_h
#define Manager_States_h

#include "State.h"
class Manager;

class RedLED : public State<Manager>
{
private:
    RedLED() {}

    // copy ctor and assignment should be private
    RedLED(const RedLED &);
    RedLED &operator=(const RedLED &);

public:
    static RedLED *Instance();

    virtual void Enter(Manager *manager);

    virtual void Execute(Manager *manager);

    virtual void Exit(Manager *manager);
};

class YellowLED : public State<Manager>
{
private:
    YellowLED() {}

    // copy ctor and assignment should be private
    YellowLED(const YellowLED &);
    YellowLED &operator=(const YellowLED &);

public:
    static YellowLED *Instance();

    virtual void Enter(Manager *manager);

    virtual void Execute(Manager *manager);

    virtual void Exit(Manager *manager);
};

class GreenLED : public State<Manager>
{
private:
    GreenLED() {}

    // copy ctor and assignment should be private
    GreenLED(const GreenLED &);
    GreenLED &operator=(const GreenLED &);

public:
    static GreenLED *Instance();

    virtual void Enter(Manager *manager);

    virtual void Execute(Manager *manager);

    virtual void Exit(Manager *manager);
};

#endif