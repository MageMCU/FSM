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

#include "math.h"

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
        float DeltaTimeSeconds();
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

    float Timer::DeltaTimeSeconds()
    {
        // Period (T) in seconds
        return (float)t_deltaTime * 0.0010;
    }

    // ALWAYS: Use isTimer(milliseconds) inside void loop() function
    bool Timer::isTimer(long incrementedTime_ms)
    {
        // Arduino
        t_currentTime = millis();
        
        if (t_elapsedTime == -1)
        {
            t_elapsedTime = t_currentTime + incrementedTime_ms;
        }
        else if (t_currentTime > t_elapsedTime)
        {
            t_elapsedTime = t_currentTime + incrementedTime_ms;
            // DeltaTime at incremmentedTime
            t_deltaTime = t_elapsedTime - t_currentTime;
            return true;
        }
        return false;
    }
}
#endif
