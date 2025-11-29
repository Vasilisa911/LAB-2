#ifndef SIGN_H
#define SIGN_H

#include <string>
#include <iostream>

class SIGN {
private:
    std::string surname;    // фамилия
    std::string name;       // имя
    std::string zodiac;     // знак зодиака
    int birthday[3];        // день рождения: [0] - день, [1] - месяц, [2] - год

public:
    SIGN();
    SIGN(const std::string& s, const std::string& n,
         const std::string& z, int d, int m, int y);

    // Методы доступа (get/set)
    void setSurname(const std::string& s);
    void setName(const std::string& n);
    void setZodiac(const std::string& z);
    void setBirthday(int d, int m, int y);

    std::string getSurname() const;
    std::string getName() const;
    std::string getZodiac() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Дружественные операторы ввода/вывода
    friend std::istream& operator>>(std::istream& is, SIGN& s);
    friend std::ostream& operator<<(std::ostream& os, const SIGN& s);
};

#endif // SIGN_H
