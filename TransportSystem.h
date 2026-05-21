#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

enum class Command {
    CREATE_TRL,
    TRLS_IN_STOP,
    STOPS_IN_TRL,
    TRLS,
    EXIT,
    UNKNOWN
};

Command parseCommand(const string& input);

// логика
void createTrolley(const string& name, const vector<string>& stops);
void showTrolleysForStop(const string& stop);
void showStopsForTrolley(const string& trolley);
void showAllTrolleys();
