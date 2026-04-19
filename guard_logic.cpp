#include <iostream>
#include <string>

using namespace std;


enum class Door {
    SAFE_EXIT,
    TRAP,
    START_POINT
};


string doorName(Door d) {
    switch (d) {
        case Door::SAFE_EXIT:   return "Door 1 – Safe Exit";
        case Door::TRAP:        return "Door 2 – Trap";
        case Door::START_POINT: return "Door 3 – Back to Start";
    }
    return "Unknown";
}



Door guardDecision(bool hasKeycard, bool alarmActive, bool isAuthorized) {

    
    if (isAuthorized && hasKeycard && !alarmActive) {
        return Door::SAFE_EXIT;
    }

    
    if (alarmActive) {
        return Door::TRAP;
    }

    
    if (hasKeycard && !isAuthorized) {
        return Door::START_POINT;
    }

    
    return Door::TRAP;
}


void runScenario(const string& label,
                 bool hasKeycard,
                 bool alarmActive,
                 bool isAuthorized)
{
    Door result = guardDecision(hasKeycard, alarmActive, isAuthorized);

    cout << "Scenario : " << label                          << "\n";
    cout << "  Keycard   : " << (hasKeycard   ? "Yes" : "No") << "\n";
    cout << "  Alarm     : " << (alarmActive  ? "Yes" : "No") << "\n";
    cout << "  Authorized: " << (isAuthorized ? "Yes" : "No") << "\n";
    cout << "  >> Decision: " << doorName(result)             << "\n";
    cout << "─────────────────────────────────\n";
}


int main() {
    cout << "===== GUARD LOGIC SYSTEM =====\n\n";

    // (label, hasKeycard, alarmActive, isAuthorized)
    runScenario("All clear – authorised visitor",   true,  false, true);
    runScenario("Alarm triggered – authorised",     true,  true,  true);
    runScenario("Alarm triggered – no keycard",     false, true,  false);
    runScenario("Keycard present, not authorised",  true,  false, false);
    runScenario("No keycard, not authorised",        false, false, false);
    runScenario("Authorised but no keycard",         false, false, true);

    return 0;
}