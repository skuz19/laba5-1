#include <iostream>
#include "queue.h"
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Моделирование электронной очереди\n";

    int windowsCount;
    cout << ">>> Введите количество окон:\n>>> ";
    cin >> windowsCount;

    if (!checkPositive(windowsCount)) return 0;

    vector<Visitor> visitors;

    string command;
    int counter = 1;

    while (true) {
        cout << ">>> ";
        cin >> command;

        // делаем команды нечувствительными к регистру
        transform(command.begin(), command.end(), command.begin(), ::toupper);

        if (command == "ENQUEUE") {
            int duration;
            cin >> duration;
            enqueue(visitors, duration, counter);
        }
        else if (command == "DISTRIBUTE") {
            distributeQueue(visitors, windowsCount);
            break;
        }
        else {
            cout << "Ошибка: неизвестная команда\n";
        }
    }

    return 0;
}
