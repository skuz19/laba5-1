#include "TransportSystem.h"
#include <iostream>

using namespace std;

// данные
map<string, vector<string>> trolleyRoutes;
map<string, set<string>> stopToTrolleys;

// парсинг команд
Command parseCommand(const string& input) {
    if (input == "CREATE_TRL") return Command::CREATE_TRL;
    if (input == "TRLS_IN_STOP") return Command::TRLS_IN_STOP;
    if (input == "STOPS_IN_TRL") return Command::STOPS_IN_TRL;
    if (input == "TRLS") return Command::TRLS;
    if (input == "EXIT") return Command::EXIT;
    return Command::UNKNOWN;
}

// создание троллейбуса
void createTrolley(const string& name, const vector<string>& stops) {
    trolleyRoutes[name] = stops;

    for (const auto& stop : stops) {
        stopToTrolleys[stop].insert(name);
    }

    cout << "Троллейбус " << name
         << " создан с " << stops.size()
         << " остановками\n";
}

// троллейбусы на остановке
void showTrolleysForStop(const string& stop) {
    if (stopToTrolleys.count(stop) == 0) {
        cout << "Остановка " << stop << " не найдена\n";
        return;
    }

    cout << "Через остановку " << stop << " проходят: ";
    for (const auto& trl : stopToTrolleys[stop]) {
        cout << trl << " ";
    }
    cout << endl;
}

// остановки троллейбуса
void showStopsForTrolley(const string& trolley) {
    if (trolleyRoutes.count(trolley) == 0) {
        cout << "Троллейбус " << trolley << " не найден\n";
        return;
    }

    cout << "Троллейбус " << trolley << " проходит через:\n";

    for (const auto& stop : trolleyRoutes[trolley]) {
        cout << stop << " (другие троллейбусы: ";

        bool found = false;

        for (const auto& trl : stopToTrolleys[stop]) {
            if (trl != trolley) {
                cout << trl << " ";
                found = true;
            }
        }

        if (!found) {
            cout << "";
        }

        cout << ")\n";
    }
}

// вывод всех троллейбусов
void showAllTrolleys() {
    if (trolleyRoutes.empty()) {
        cout << "Нет троллейбусов\n";
        return;
    }

    cout << "Все троллейбусы:\n";

    for (const auto& [trl, stops] : trolleyRoutes) {
        cout << trl << ": ";
        for (const auto& stop : stops) {
            cout << stop << " ";
        }
        cout << endl;
    }
}
