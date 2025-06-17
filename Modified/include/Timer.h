
#ifndef Numerics_Timer_h
#define Numerics_Timer_h

#include "Arduino.h"

namespace csjc
{
    class Timer
    {
    private:
        // Private Properties
        long t_currentTime;
        long t_elapsedTime;
        long t_deltaTime;

    public:
        // Constructors
        Timer();
        ~Timer() = default;

        // Methods
        void resetTimer();
        bool isTimer(long incrementedTime_ms);
    };

    Timer::Timer()
    {
        t_elapsedTime = 0;
    }

    void Timer::resetTimer()
    {
        t_elapsedTime = -1;
    }

    // ALWAYS: Use isTimer(milliseconds) inside void loop() function
    bool Timer::isTimer(long incrementedTime_ms)
    {
        // Arduino
        t_currentTime = millis();
        
        // Linux System
        // t_currentTime = t_time.millis();

        if (t_elapsedTime == -1)
        {
            t_elapsedTime = t_currentTime + incrementedTime_ms;
        }
        else if (t_currentTime > t_elapsedTime)
        {
            t_elapsedTime = t_currentTime + incrementedTime_ms;
            return true;
        }

        return false;
    }
}

#endif
