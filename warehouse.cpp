#include "warehouse.h"
#include <iostream>
#include <iomanip>

map<string, Cell> warehouse;
int totalItems = 0;

// 🔹 Проверка адреса с подсказками
bool isValidAddress(const string& addr) {
    if (addr.length() < 4 || addr.length() > 5) {
        cout << "Ошибка: адрес должен быть вида A173\n";
        return false;
    }

    char zone = addr[0];
    if (zone != 'A' && zone != 'B') {
        cout << "Ошибка: зона должна быть A или B\n";
        return false;
    }

    try {
        int rack = stoi(addr.substr(1, addr.length() - 3));
        int section = addr[addr.length() - 2] - '0';
        int shelf = addr[addr.length() - 1] - '0';

        if (rack < 1 || rack > RACKS) {
            cout << "Ошибка: номер стеллажа должен быть от 1 до " << RACKS << endl;
            return false;
        }

        if (section < 1 || section > SECTIONS) {
            cout << "Ошибка: номер секции должен быть от 1 до " << SECTIONS << endl;
            return false;
        }

        if (shelf < 1 || shelf > SHELVES) {
            cout << "Ошибка: номер полки должен быть от 1 до " << SHELVES << endl;
            return false;
        }
    }
    catch (...) {
        cout << "Ошибка: неверный формат адреса\n";
        return false;
    }

    return true;
}

// 🔹 генерация всех адресов
vector<string> getAllAddresses() {
    vector<string> result;
    char zones[] = {'A', 'B'};

    for (char z : zones) {
        for (int r = 1; r <= RACKS; r++) {
            for (int s = 1; s <= SECTIONS; s++) {
                for (int h = 1; h <= SHELVES; h++) {
                    result.push_back(
                        string(1, z) +
                        to_string(r) +
                        to_string(s) +
                        to_string(h)
                    );
                }
            }
        }
    }
    return result;
}

void add(const string& item, int count, const string& address) {
    if (count <= 0) {
        cout << "Ошибка: количество должно быть положительным\n";
        return;
    }

    if (!isValidAddress(address)) return;

    Cell& cell = warehouse[address];

    if (cell.count > 0 && cell.item != item) {
        cout << "Ошибка: ячейка " << address
             << " занята товаром " << cell.item << endl;
        return;
    }

    if (cell.count + count > MAX_ITEMS_PER_CELL) {
        cout << "Ошибка: превышена вместимость ячейки (максимум 10)\n";
        return;
    }

    cell.item = item;
    cell.count += count;
    totalItems += count;

    cout << "Добавлено " << count << " " << item
         << " в " << address << endl;
}

void remove(const string& item, int count, const string& address) {
    if (!isValidAddress(address)) return;

    auto it = warehouse.find(address);

    if (it == warehouse.end() || it->second.item != item) {
        cout << "Ошибка: товар " << item
             << " не найден в ячейке " << address << endl;
        return;
    }

    if (it->second.count < count) {
        cout << "Ошибка: недостаточно товаров для удаления\n";
        return;
    }

    it->second.count -= count;
    totalItems -= count;

    cout << "Удалено " << count << " " << item
         << " (остаток: " << it->second.count << ")" << endl;

    if (it->second.count == 0) {
        warehouse.erase(it);
    }
}

void info() {
    int totalCells = ZONES * RACKS * SECTIONS * SHELVES;
    int capacity = totalCells * MAX_ITEMS_PER_CELL;

    cout << fixed << setprecision(2);

    cout << "\n=== Состояние склада ===\n";
    cout << "Загруженность склада: "
         << (double)totalItems / capacity * 100 << " %\n";

    int zoneA = 0, zoneB = 0;

    for (const auto& [addr, cell] : warehouse) {
        if (addr[0] == 'A') zoneA += cell.count;
        else zoneB += cell.count;
    }

    int zoneCapacity = capacity / 2;

    cout << "Зона A: " << (double)zoneA / zoneCapacity * 100 << " %\n";
    cout << "Зона B: " << (double)zoneB / zoneCapacity * 100 << " %\n";

    cout << "\nЗаполненные ячейки:\n";
    for (const auto& [addr, cell] : warehouse) {
        cout << addr << ": "
             << cell.item << " (" << cell.count << ")\n";
    }

    cout << "\nПустые ячейки:\n";
    vector<string> all = getAllAddresses();

    for (const auto& addr : all) {
        if (warehouse.find(addr) == warehouse.end()) {
            cout << addr << " ";
        }
    }

    cout << endl;
}
