#include "SIGN.h"
#include <limits>

using namespace std;

SIGN::SIGN() {
    surname = "";
    name = "";
    zodiac = "";
    birthday[0] = birthday[1] = birthday[2] = 0;
}

SIGN::SIGN(const string& s, const string& n,
           const string& z, int d, int m, int y) {
    surname = s;
    name = n;
    zodiac = z;
    birthday[0] = d;
    birthday[1] = m;
    birthday[2] = y;
}

void SIGN::setSurname(const string& s) { surname = s; }
void SIGN::setName(const string& n)    { name = n; }
void SIGN::setZodiac(const string& z)  { zodiac = z; }

void SIGN::setBirthday(int d, int m, int y) {
    birthday[0] = d;
    birthday[1] = m;
    birthday[2] = y;
}

string SIGN::getSurname() const { return surname; }
string SIGN::getName() const    { return name; }
string SIGN::getZodiac() const  { return zodiac; }
int SIGN::getDay() const        { return birthday[0]; }
int SIGN::getMonth() const      { return birthday[1]; }
int SIGN::getYear() const       { return birthday[2]; }

// Перегрузка оператора ввода
istream& operator>>(istream& is, SIGN& s) {
    // здесь предполагаем ввод с консоли построчно
    cout << "Фамилия: ";
    is >> s.surname;

    cout << "Имя: ";
    is >> s.name;

    cout << "Знак зодиака: ";
    is >> s.zodiac;

    cout << "День рождения (день месяц год): ";
    is >> s.birthday[0] >> s.birthday[1] >> s.birthday[2];

    return is;
}

// Перегрузка оператора вывода
ostream& operator<<(ostream& os, const SIGN& s) {
    os << s.surname << " " << s.name
       << ", знак: " << s.zodiac
       << ", дата рождения: "
       << s.birthday[0] << "." << s.birthday[1] << "." << s.birthday[2];
    return os;
}
