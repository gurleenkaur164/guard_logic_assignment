Guard Logic Challenge – C++
A simple decision system for a secured facility with three doors, implemented in C++.

Problem Statement
You are designing a decision system for a secured facility with three doors:
DoorOutcomeDoor 1Safe ExitDoor 2TrapDoor 3Back to Starting Point
A guard logic function decides which door to open based on given conditions.


 Decision Rules
Rules are evaluated in priority order:
PriorityConditionResult1Authorized + Keycard + No Alarm Door 1 – Safe Exit2Alarm is Active (any other flags) Door 2 – Trap3Has Keycard but NOT Authorized Door 3 – Back to Start4Everything else (fail-safe)
Door 2 – Trap

Code Structure
guard_logic.cpp
│
├── enum class Door          → Type-safe door outcomes (SAFE_EXIT, TRAP, START_POINT)
├── doorName()               → Converts Door enum to a readable string
├── guardDecision()          → Core logic function — takes 3 bools, returns a Door
├── runScenario()            → Helper to print a labeled test case and its result
└── main()                   → Runs 6 scenarios covering all key cases

 Test Scenarios & Output
ScenarioKeycardAlarmAuthorizedResultAll clear – authorised visitor  Door 1 – Safe ExitAlarm triggered – authorised
Door 2 – TrapAlarm triggered – no keycard 
Door 2 – TrapKeycard present, not authorised 
Door 3 – Back to StartNo keycard, not authorised
Door 2 – TrapAuthorised but no keycard
Door 2 – Trap

 How to Compile & Run
Make sure you have g++ installed, then run:
bashg++ -std=c++17 -Wall -o guard_logic guard_logic.cpp
./guard_logic
Expected Output


Scenario : All clear – authorised visitor
  Keycard   : Yes
  Alarm     : No
  Authorized: Yes
  Decision: Door 1 – Safe Exit

Requirements

C++17 or later
g++ compiler (GCC) or any standard C++ compile