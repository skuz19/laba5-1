#pragma once
#include <set>

using namespace std;

// глобальные данные
extern int totalStudents;
extern set<int> expelledCandidates;
extern set<int> immortalStudents;

// функции
void newStudents(int number);
void suspicious(int id);
void immortal(int id);
void showTopList();
int getExpelledCount();
