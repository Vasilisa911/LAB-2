#include "SentenceProcessor.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

void processTextFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл: " << filename << endl;
        return;
    }

    // Считываем весь текст файла в строку через строковый поток
    ostringstream oss;
    oss << file.rdbuf();
    string text = oss.str();

    file.close();

    // Разбор текста на предложения с использованием istringstream
    istringstream iss(text);
    vector<string> questions;
    vector<string> exclamations;

    string current;
    char ch;

    while (iss.get(ch)) {
        current += ch;
        if (ch == '?' || ch == '!' || ch == '.') {
            // Убираем лишние пробелы в начале и конце
            // (простейший вариант)
            while (!current.empty() && (current.front() == ' ' || current.front() == '\n' || current.front() == '\t'))
                current.erase(current.begin());
            while (!current.empty() && (current.back() == ' ' || current.back() == '\n' || current.back() == '\t'))
                current.pop_back();

            if (!current.empty()) {
                if (ch == '?')
                    questions.push_back(current);
                else if (ch == '!')
                    exclamations.push_back(current);
                // предложения, заканчивающиеся '.', можно игнорировать
            }
            current.clear();
        }
    }

    cout << "\nВопросительные предложения:\n";
    if (questions.empty()) {
        cout << "(нет вопросительных предложений)\n";
    } else {
        for (const auto& s : questions)
            cout << s << endl;
    }

    cout << "\nВосклицательные предложения:\n";
    if (exclamations.empty()) {
        cout << "(нет восклицательных предложений)\n";
    } else {
        for (const auto& s : exclamations)
            cout << s << endl;
    }
}
