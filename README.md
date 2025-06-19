## Game-AI
- Programming Game AI by Example (2005)
    - Mat Buckland
- Before robotics, there was game development that included Artificial Intelligence. These developed game engines turned into robotic simulators. Code written by Mat Buckland works well with the Arduino Uno particularly his Finite State Machine. The book overall is easy reading and it's fun to apply the AI concepts to the Arduino. Of course, the code does not work as written from the Mat's book into the Arduino without tweaking it but the code can be made to function as described in the book.
- **Game-AI** folder contains Buckland's code. Does NOT function with the Arduino Uno. It has to be tweaked.
- **Tweaked** folder contains the Bucklan's code from chapter 2 *WestWorldWithWoman* that was tweaked for Arduino as exactly described in the book. This functions with the Arduino Uno.
- **Modified** folder contains a practical skeleton of Buckland's FSM for Arduino. This functions with the Arduino Uno but contains barebones code.
- **Linux** folder contains the code that functions on Ubuntu 22.04 or Raspberry Pi OS.
- Code development like a finte state machine would be difficult using a small device like the Uno while using its Serial.print() functions for debugging. The VSCode editor the GNU Compiler Collection on Ubuntu 22.04 or Raspberry Pi OS provides various features and mechanisms to support assertions and error checking in your code. 

##  Finite State Machine (FSM)
- A C-style finite state machine (FSM) is a way to implement a system that can be in one of a limited number of states, transitioning between them based on inputs or events. It's commonly used in embedded systems and event-driven applications due to its simplicity and efficiency.
    - **States**: Represent distinct operational modes of the system.
    - **Events/Inputs**: Triggers that cause the FSM to transition between states.
    - **Transitions**: Rules that define how the FSM moves from one state to another based on events.
    - **Actions**: Tasks performed when entering, exiting, or while in a specific state. See development below for more details...

```
    typedef enum {
      STATE_A,
      STATE_B,
      STATE_C
    } State;

    State currentState = STATE_A;

    void processEvent(int event) {
      switch (currentState) {
        case STATE_A:
          if (event == EVENT_X) {
            // Perform actions for STATE_A
            currentState = STATE_B;
          }
          break;
        case STATE_B:
          if (event == EVENT_Y) {
            // Perform actions for STATE_B
            currentState = STATE_C;
          }
          break;
        case STATE_C:
          if (event == EVENT_Z) {
            // Perform actions for STATE_C
            currentState = STATE_A;
          }
          break;
      }
    }
```
- Instead of a switch statement to handle state transitions based on the current state and received event, create a function pointer for each state, pointing to a function that handles events and transitions for that state.
```
    typedef struct {
      void (*stateFunction)(int);
    } StateMachine;

    void stateA(int event) {
      if (event == EVENT_X) {
        // Perform actions for STATE_A
        currentState.stateFunction = stateB;
      }
    }

    void stateB(int event) {
      if (event == EVENT_Y) {
        // Perform actions for STATE_B
        currentState.stateFunction = stateC;
      }
    }

    void stateC(int event) {
      if (event == EVENT_Z) {
        // Perform actions for STATE_C
        currentState.stateFunction = stateA;
      }
    }

    StateMachine currentState = {stateA};

    void processEvent(int event) {
      currentState.stateFunction(event);
    }
```
Although the pseudocode above is a simplified, human-readable representation of an algorithm. It's not the Arduino C++ programming language and can't be executed by a computer. Instead, it serves as a planning tool for developers, allowing them to outline the logic of a program before writing actual code. 
- Beside the two previous FSM, State Tables represent the FSM's state transitions in a table (e.g., a 2D array). The rows represent states, columns represent events, and table entries contain the next state. This approach can be more efficient for complex state machines with many states and events. 
- Designing a Finite State Machine (FSM) involves defining states, transitions, and inputs to control the behavior of a system. The process typically includes understanding the problem, drawing a state diagram, encoding states, designing next-state logic, and implementing the FSM. 
    - State Diagram: A visual representation of the FSM, showing states and transitions. 
    - State Transition Table: A table that lists the current state, input, and next state. 
    - Mealy vs. Moore Machines: Mealy machines have outputs that depend on both the current state and the input, while Moore machines have outputs that depend only on the current state. 
    - Edge Cases and Error Handling: Ensure the FSM can handle unexpected inputs or conditions gracefully. 
- In chapter two of Mat Buckland's book covers State-Driven Agent Design. The code to the book for chapter two discusses three FSM programs: **WestWorld1**,  **WestWorldWithWoman** and **WestWorldWithMessaging**. The WestWorldWithWoman program is the ideal FSM program for the Arduino Uno.

 
## Testing Platform
- This MCU chip **Atmega328P** is well known and the price is affordable as well as most of the robotic hardware that is described here. The Arduino Uno board comes with a removable MCU.
- **PlatformIO** is a cross-platform, cross-architecture, multiple framework, professional tool for embedded systems engineers and for software developers who write applications for embedded products. 
- **Visual Studio Code** is a streamlined code editor and it runs on macOS, Linux, and Windows. The best thing about VSCode, it is free.

## In Development
- 20250615 Modified folder contains a simple Red, Yellow, Green light system... The modified version is a simpler derivation from Mat Buckland FSM which can be used for the Arduino Uno.
- 20250617 Linux folder contains code for both the Ubuntu 22.04 OS and Raspberry Pi OS.

## Note
- 20250617 - Repository renamed from FSM to Finite-State-Machine

