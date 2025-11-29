#ifndef SIGNUTILS_H
#define SIGNUTILS_H

#include <vector>
#include <string>
#include "SIGN.h"

// Считывание списка SIGN (число объектов заранее не известно)
void inputSigns(std::vector<SIGN>& people);

// Сортировка по дате рождения
void sortByBirthday(std::vector<SIGN>& people);

// Вывод людей по введённому знаку зодиака
void printByZodiac(const std::vector<SIGN>& people, const std::string& zodiacName);

#endif // SIGNUTILS_H
