#include "students.h"
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "NEW_STUDENTS - добавить студентов\n";
    cout << "SUSPICIOUS - добавить в список на отчисление\n";
    cout << "IMMORTAL - сделать неприкасаемым\n";
    cout << "TOP-LIST - показать список\n";
    cout << "SCOUNT - количество студентов в списке\n";
    cout << "EXIT - выход\n";

    string command;

    while (true) {
        cout << "\n>>> ";
        cin >> command;

        transform(command.begin(), command.end(), command.begin(), ::toupper);

        if (command == "NEW_STUDENTS") {
            int number;
            cout << "Введите количество новых студентов:\n";
            cin >> number;
            newStudents(number);
        }

        else if (command == "SUSPICIOUS") {
            int id;
            cout << "Введите номер подозрительного студента:\n";
            cin >> id;
            suspicious(id);
        }

        else if (command == "IMMORTAL") {
            int id;
            cout << "Введите номер неприкасаемого студента:\n";
            cin >> id;
            immortal(id);
        }

        else if (command == "TOP-LIST") {
            showTopList();
        }

        else if (command == "SCOUNT") {
            cout << "Количество студентов в списке на отчисление: "
                 << getExpelledCount() << endl;
        }

        else if (command == "EXIT") {
            cout << "Выход из программы\n";
            break;
        }

        else {
            cout << "Ошибка: неизвестная команда\n";
        }
    }

    return 0;
}
