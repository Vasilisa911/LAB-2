#include "SignUtils.h"
#include <algorithm>
#include <iostream>

using namespace std;

// Вводим людей, пока пользователь отвечает 'y' или 'Y'
void inputSigns(vector<SIGN>& people) {
    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        SIGN s;
        cin >> s;                // используем перегруженный оператор >>
        people.push_back(s);

        cout << "Добавить ещё человека? (y/n): ";
        cin >> choice;
    }
}

// Компаратор для сортировки по дате рождения (сначала год, потом месяц, день)
static bool compareByDate(const SIGN& a, const SIGN& b) {
    if (a.getYear() != b.getYear())
        return a.getYear() < b.getYear();
    if (a.getMonth() != b.getMonth())
        return a.getMonth() < b.getMonth();
    return a.getDay() < b.getDay();
}

void sortByBirthday(vector<SIGN>& people) {
    sort(people.begin(), people.end(), compareByDate);
}

void printByZodiac(const vector<SIGN>& people, const string& zodiacName) {
    bool found = false;
    for (const auto& person : people) {
        if (person.getZodiac() == zodiacName) {
            cout << person << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Людей с знаком зодиака \"" << zodiacName
             << "\" не найдено." << endl;
    }
}
