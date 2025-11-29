#include <iostream>
#include <vector>
#include <string>

#include "SIGN.h"
#include "SignUtils.h"
#include "SentenceProcessor.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // ===== ЧАСТЬ 1. Стандартные потоки, класс SIGN =====
    cout << "=== Задача 1: работа с классом SIGN ===\n";

    vector<SIGN> people;

    // Ввод людей (число заранее не известно)
    inputSigns(people);

    // Сортировка по дате рождения
    sortByBirthday(people);

    cout << "\nОтсортированные записи по дате рождения:\n";
    for (const auto& p : people) {
        cout << p << endl;
    }

    // Поиск по знаку зодиака
    cout << "\nВведите название знака зодиака для поиска: ";
    string z;
    cin >> z;

    cout << "\nЛюди с указанным знаком зодиака:\n";
    printByZodiac(people, z);

    // ===== ЧАСТЬ 2. Файловые и строковые потоки =====
    cout << "\n=== Задача 2: файл + строковые потоки ===\n";
    cout << "Введите имя текстового файла (например, input.txt): ";
    string filename;
    cin >> filename;

    processTextFile(filename);

    return 0;
}
