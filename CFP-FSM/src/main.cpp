// Traffic Lights
// Project: FP-FSM-001 (C-code)
// Date: 20221218
// Author: Jesse Carpenter
// Description Setup:
// Setup two sets of traffic lights at an intersection.
// (1) Main Street (3-LEDs each (or print): red, yellow and green).
// (2) Cross Avenue (3-LEDs: red, amber and green).
// (3) Code state functions and a manager function.
// (4) the red lights time overlap 1 second.
// (5) all conditionals are maintained within thes state functions.
// (6) all processes are maintained within the manager function.
// (7) amber 3-seconds, others 10-seconds
//
// Discussion Ponter Function:
// The function pointer finite state machone is written on C...
//     To keep the code simple yet this could be written in C++.
// On the other hand, the dependencies are written in C++.
//
// Although the FSM is sequential, notice how the function pointer
// currentState.
//

#include <Arduino.h>

#include "Timer.h"
#include "Bitwise.h"

// Global Objects
uno::Timer timer;
nmr::Bitwise<int> bitwise;

// Global Function Pointer
void (*currentState)();

// Global bit number step
enum bitNumberStep
{
  mainGR = 0, // main Green Red - 5s
  mainAR,     // main Amber Red - 2.5s
  mainRR,     // main Red Red - 1s
  crossGR,    // cross Green Red - 5s
  crossAR,    // cross Amber Red - 2.5s
  crossRR     // cross Red Red - 1s
};

// processOnce flag
bool processOnce;

// prototypes
void initialize();
void greenRedState();
void amberState();
void overlapState();
void lightManager();

void initialize()
{
  processOnce = false;

  // Assign the current state
  currentState = greenRedState;

  // Set Bit Number
  if (bitwise.GetBits() == 0)
    bitwise.SetBitNumber((uint16_t)mainGR);

  Serial.print("GREEN - RED");
  Serial.print(" - bit number: ");
  Serial.print(bitwise.GetBitNumber());
  Serial.print(" ");
  Serial.println(bitwise.PrintBinaryBits());
}

// state functions
void greenRedState()
{
  // State Conditional - 5s
  if (timer.isTimer(5000))
  {
    timer.resetTimer();
    processOnce = true;
  }
}

void amberState()
{
  // State Conditional - 2.5s
  if (timer.isTimer(2500))
  {
    timer.resetTimer();
    processOnce = true;
  }
}

void overlapState()
{
  // State Conditional - 1s
  if (timer.isTimer(1000))
  {
    timer.resetTimer();
    processOnce = true;
  }
}

// manager function
void lightManager()
{
  if (processOnce)
  {
    if (currentState == greenRedState)
    {
      // Process Main Street Conditionals
      if (bitwise.IsBitNumberSet((uint16_t)mainGR))
      {
        bitwise.ClearBitNumber((uint16_t)mainGR);
        Serial.print("AMBER - RED");
        bitwise.SetBitNumber((uint16_t)mainAR);
      }
      // Process Cross Avenue Conditionals
      if (bitwise.IsBitNumberSet((uint16_t)crossGR))
      {
        bitwise.ClearBitNumber((uint16_t)crossGR);
        Serial.print("RED - AMBER");
        bitwise.SetBitNumber((uint16_t)crossAR);
      }
      // Transition from greenRedState to amberState
      currentState = amberState;
    }
    else if (currentState == amberState)
    {
      // Process Main Street Conditionals
      if (bitwise.IsBitNumberSet((uint16_t)mainAR))
      {
        bitwise.ClearBitNumber((uint16_t)mainAR);
        Serial.print("RED - RED");
        bitwise.SetBitNumber((uint16_t)mainRR);
      }
      // Process Cross Avenue Conditionals
      if (bitwise.IsBitNumberSet((uint16_t)crossAR))
      {
        bitwise.ClearBitNumber((uint16_t)crossAR);
        Serial.print("RED - RED");
        bitwise.SetBitNumber((uint16_t)crossRR);
      }
      // Transition from amberState to overlapState
      currentState = overlapState;
    }
    else if (currentState == overlapState)
    {
      // Process Main Street Conditionals
      if (bitwise.IsBitNumberSet((uint16_t)mainRR))
      {
        bitwise.ClearBitNumber((uint16_t)mainRR);
        Serial.print("RED - GREEN");
        bitwise.SetBitNumber((uint16_t)crossGR);
      }
      // Process Cross Avenue Conditionals
      if (bitwise.IsBitNumberSet((uint16_t)crossRR))
      {
        bitwise.ClearBitNumber((uint16_t)crossRR);
        Serial.print("GREEN - RED");
        bitwise.SetBitNumber((uint16_t)mainGR);
      }
      // Transition from overlapState to greenRedState
      currentState = greenRedState;
    }

    Serial.print(" - bit number: ");
    Serial.print(bitwise.GetBitNumber());
    Serial.print(" ");
    Serial.println(bitwise.PrintBinaryBits());
    processOnce = false;
  }

  //
  currentState();
}

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
    /* code */
  }

  // Timer - global
  timer = uno::Timer();
  timer.resetTimer();
  // Bitwise - global
  bitwise = nmr::Bitwise<int>();

  initialize();
}

void loop()
{
  lightManager();
}