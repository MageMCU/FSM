//
// Carpenter Software
// File: Class Timer.h
// Github: MageMCU
// Repository:
// Folder:
//
// By Jesse Carpenter (carpentersoftware.com)
//
// Testing Platform:
//  * COMPUTER:Raspberry Pi 3 Model B v1.2 2015 (See note.)
//  * Raspberry Pi OS (Bookworm 64-bits)
//  * Editor: Code::Blocks (or VSCode)
//  * MCU:Arduino Uno Rev.3 (Atmega328P)
//  * IDE:PlatformIO
//  * Editor: VSCode
//  * NOTE Computer may not run VSCode.
//
// MIT LICENSE
//

#ifndef Numerics_Timer_h
#define Numerics_Timer_h

// #include <iostream>
#include <cstdio>

#include <string>
#include <cmath>
#include "LinuxTime.h"

namespace csjc
{
    class Timer
    {
    private:
        // Private Properties
        long t_currentTime;
        long t_elapsedTime;
        LinuxTime t_time;

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
        t_time = LinuxTime();
    }

    void Timer::resetTimer()
    {
        t_elapsedTime = -1;
    }

    // ALWAYS: Use isTimer(milliseconds) inside void loop() function
    bool Timer::isTimer(long incrementedTime_ms)
    {
        // Arduino
        // t_currentTime = millis();
        // Linux System
        t_currentTime = t_time.millis();
        
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
