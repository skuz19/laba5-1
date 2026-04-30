#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

// генерация T001, T002 ...
string generateTicket(int id) {
    string result = "T";

    if (id < 10) result += "00";
    else if (id < 100) result += "0";

    result += to_string(id);
    return result;
}

// проверка
bool checkPositive(int value) {
    if (value <= 0) {
        cout << "Ошибка: значение должно быть > 0\n";
        return false;
    }
    return true;
}

// добавление в очередь
void enqueue(vector<Visitor>& visitors, int duration, int& counter) {
    if (!checkPositive(duration)) return;

    Visitor v;
    v.ticket = generateTicket(counter++);
    v.duration = duration;

    visitors.push_back(v);

    cout << v.ticket << endl;
}

// распределение
void distributeQueue(const vector<Visitor>& visitors, int windowsCount) {

    vector<vector<Visitor>> windows(windowsCount);
    vector<int> windowTimes(windowsCount, 0);

    for (const auto& v : visitors) {

        int best = 0;

        for (int i = 1; i < windowsCount; i++) {
            if (windowTimes[i] < windowTimes[best]) {
                best = i;
            }
        }

        windows[best].push_back(v);
        windowTimes[best] += v.duration;
    }

    for (int i = 0; i < windowsCount; i++) {
        if (!windows[i].empty()) {
            cout << "Окно " << i + 1
                 << " (" << windowTimes[i] << " минут): ";

            for (size_t j = 0; j < windows[i].size(); j++) {
                cout << windows[i][j].ticket;
                if (j != windows[i].size() - 1) cout << ", ";
            }

            cout << endl;
        }
    }
}
