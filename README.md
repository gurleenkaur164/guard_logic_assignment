Guard Logic Challenge

A C++ program that simulates a decision system for a secured facility. Based on a visitor's credentials and the facility's current state, the system directs them to one of three doors.

How it works

The guard function takes three inputs:

- hasKeycard – does the visitor have a keycard?
- isAuthorized – are they on the approved list?
- alarmActive – is the facility alarm currently on?

Based on these, it picks one of three doors:

- Door 1 – Safe Exit
- Door 2 – Trap
- Door 3 – Back to starting point

The decision follows this logic:

1. If the visitor is authorized, has a keycard, and no alarm is going off → Safe Exit
2. If the alarm is active → Trap (no exceptions)
3. If they have a keycard but aren't authorized → Back to Start
4. Anything else → Trap

Project structure


guard_logic.cpp   – main source file
README.md         – this file


Inside the source file:

- enum class Door – defines the three door outcomes
- doorName() – returns a readable label for each door
- guardDecision() – contains the core logic
- runScenario() – prints the result for a given set of inputs
- main() – runs six test cases

Running the program

g++ -std=c++17 -Wall -o guard_logic guard_logic.cpp
./guard_logic


Test cases

Case 1 – Normal authorized entry
Visitor has a keycard, is authorized, and no alarm is active. Expected result: Safe Exit.

Case 2 – Alarm goes off during authorized entry
Visitor has a keycard and is authorized, but the alarm is active. Expected result: Trap.

Case 3 – Alarm with no credentials
No keycard, not authorized, alarm is active. Expected result: Trap.

Case 4 – Keycard but not on the list
Visitor has a keycard but is not authorized, no alarm. Expected result: Back to Start.

Case 5 – No credentials at all
No keycard, not authorized, no alarm. Expected result: Trap.

Case 6 – Authorized but forgot keycard
Visitor is authorized but has no keycard, no alarm. Expected result: Trap.

Notes

The system defaults to Trap in any unclear or uncovered case. This is intentional — when in doubt, the safest option for a secured facility is to not let someone through.
