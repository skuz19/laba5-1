#include "TransportSystem.h"
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Система управления троллейбусами\n";
    cout << "Команды:\n";
    cout << "CREATE_TRL\n";
    cout << "TRLS_IN_STOP\n";
    cout << "STOPS_IN_TRL\n";
    cout << "TRLS\n";
    cout << "EXIT\n";

    string command;

    while (true) {
        cout << "\n> ";
        cin >> command;

        // нечувствительность к регистру
        transform(command.begin(), command.end(), command.begin(), ::toupper);

        Command cmd = parseCommand(command);

        if (cmd == Command::CREATE_TRL) {
            string name;
            int count;

            cout << "Введите название троллейбуса: ";
            cin >> name;

            cout << "Введите количество остановок: ";
            cin >> count;

            if (count <= 0) {
                cout << "Ошибка: количество остановок должно быть > 0\n";
                continue;
            }

            vector<string> stops(count);

            cout << "Введите остановки через пробел: ";
            for (int i = 0; i < count; i++) {
                cin >> stops[i];
            }

            createTrolley(name, stops);
        }

        else if (cmd == Command::TRLS_IN_STOP) {
            string stop;
            cout << "Введите название остановки: ";
            cin >> stop;

            showTrolleysForStop(stop);
        }

        else if (cmd == Command::STOPS_IN_TRL) {
            string trl;
            cout << "Введите название троллейбуса: ";
            cin >> trl;

            showStopsForTrolley(trl);
        }

        else if (cmd == Command::TRLS) {
            showAllTrolleys();
        }

        else if (cmd == Command::EXIT) {
            cout << "Выход из программы\n";
            break;
        }

        else {
            cout << "Неизвестная команда\n";
        }
    }

    return 0;
}
