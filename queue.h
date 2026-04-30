#pragma once
#include <vector>
#include <string>

using namespace std;

struct Visitor {
    string ticket;
    int duration;
};

string generateTicket(int id);

void enqueue(vector<Visitor>& visitors, int duration, int& counter);
void distributeQueue(const vector<Visitor>& visitors, int windowsCount);
bool checkPositive(int value);
