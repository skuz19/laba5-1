#pragma once
#include <string>
#include <map>
#include <vector>

using namespace std;

const int ZONES = 2;
const int RACKS = 10;
const int SECTIONS = 6;
const int SHELVES = 7;
const int MAX_ITEMS_PER_CELL = 10;

struct Cell {
    string item;
    int count = 0;
};

extern map<string, Cell> warehouse;
extern int totalItems;

bool isValidAddress(const string& address);
vector<string> getAllAddresses();

void add(const string& item, int count, const string& address);
void remove(const string& item, int count, const string& address);
void info();
