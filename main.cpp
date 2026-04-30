#include "warehouse.h"
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string command, item, address;
    int count;

    setlocale(LC_ALL, "Russian");

    cout << "Система учета товаров на складе\n";
    cout << "Вариант 5 (2 зоны, 10 стеллажей, 6 секций, 7 полок)\n\n";

    cout << "Формат адреса: A173\n";
    cout << "[Зона][Стеллаж][Секция][Полка]\n";
    cout << "Пример: A153\n";
    cout << "A - зона (A или B)\n";
    cout << "1 - стеллаж (1-10)\n";
    cout << "5 - секция (1-6)\n";
    cout << "3 - полка (1-7)\n\n";

    cout << "Команды:\n";
    cout << "ADD <товар> <кол-во> <адрес>\n";
    cout << "REMOVE <товар> <кол-во> <адрес>\n";
    cout << "INFO\nEXIT\n";

    while (true) {
        cout << "\n>>> ";
        cin >> command;

        transform(command.begin(), command.end(), command.begin(), ::toupper);

        if (command == "ADD") {
            cin >> item >> count >> address;
            add(item, count, address);
        }
        else if (command == "REMOVE") {
            cin >> item >> count >> address;
            remove(item, count, address);
        }
        else if (command == "INFO") {
            info();
        }
        else if (command == "EXIT") {
            cout << "Выход\n";
            break;
        }
        else {
            cout << "Ошибка: неизвестная команда\n";
        }
    }

    return 0;
}
