#include "students.h"
#include <iostream>

using namespace std;

int totalStudents = 0;
set<int> expelledCandidates;
set<int> immortalStudents;

// добавление / удаление студентов
void newStudents(int number) {
    if (number > 0) {
        totalStudents += number;
        cout << "Welcome " << number << " clever students!" << endl;
    }
    else {
        number = -number;

        if (expelledCandidates.empty()) {
            cout << "Ошибка: Нет кандидатов на отчисление" << endl;
            return;
        }

        if (number > expelledCandidates.size()) {
            cout << "Ошибка: невозможно отчислить больше студентов, чем есть" << endl;
            return;
        }

        for (int i = 0; i < number; i++) {
            expelledCandidates.erase(expelledCandidates.begin());
        }

        cout << "Удалено " << number << " студентов" << endl;
    }
}

// добавить в список на отчисление
void suspicious(int id) {
    if (id <= 0 || id > totalStudents) {
        cout << "Ошибка: такого студента нет" << endl;
        return;
    }

    if (immortalStudents.count(id)) {
        cout << "Ошибка: студент " << id << " неприкасаемый" << endl;
        return;
    }

    if (expelledCandidates.count(id)) {
        cout << "Ошибка: студент " << id << " уже в списке" << endl;
        return;
    }

    expelledCandidates.insert(id);
    cout << "The suspected student " << id << endl;
}

// сделать неприкасаемым
void immortal(int id) {
    if (!expelledCandidates.count(id)) {
        cout << "Ошибка: студент не в списке на отчисление" << endl;
        return;
    }

    expelledCandidates.erase(id);
    immortalStudents.insert(id);

    cout << "Student " << id << " is immortal!" << endl;
}

// вывод списка
void showTopList() {
    cout << "список студентов на отчисление: ";

    if (expelledCandidates.empty()) {
        cout << "пуст";
    }
    else {
        for (int id : expelledCandidates) {
            cout << id << " ";
        }
    }

    cout << endl;
}

// количество
int getExpelledCount() {
    return expelledCandidates.size();
}
