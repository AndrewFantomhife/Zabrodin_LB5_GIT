#ifndef SURNAME_MATHTASK_H
#define SURNAME_MATHTASK_H

#include <iostream>
#include <limits>
#include <stdexcept>

// Подключение пространства имен std
using namespace std;

// Функция для полной проверки корректности ввода целого числа
void validateInput(istream& input) {
    try {
        if (input.fail()) {
            throw invalid_argument("Ошибка: введено некорректное значение.");
        }
        // Очищаем буфер после успешного ввода
        input.ignore(numeric_limits<streamsize>::max(), '\n');
    } catch (const exception&) {
        // Сброс флага ошибки и очистка буфера при возникновении исключения
        input.clear();
        input.ignore(numeric_limits<streamsize>::max(), '\n');
        throw; // Повторно выбрасываем исключение для обработки выше уровнем
    }
}

int inputNumber(const string& prompt) {
    int number;
    while (true) {
        cout << prompt;
        cin >> number;

        // Вызываем функцию проверки ввода
        try {
            validateInput(cin);

            // Дополнительная проверка: число должно быть положительным
            if (number < 0) {
                cerr << "Ошибка: число должно быть положительным.\n";
                continue; // Перезапрашиваем ввод
            }

            // Если ввод корректен, возвращаем число
            return number;
        } catch (const invalid_argument& e) {
            cerr << e.what() << "\n"; // Выводим сообщение об ошибке
        }
    }
}

// Функция для вычисления результатов деления
void calculateDivisionResults(int Q, int P) {
    if (P <= 0 || P >= Q) {
        throw invalid_argument("Ошибка: P должно быть натуральным числом и меньше Q.");
    }

    int remainder = Q % P;  // Остаток от деления
    int quotient = Q / P;   // Целая часть от деления

    cout << "Остаток от деления Q на P: " << remainder << "\n";
    cout << "Целая часть от деления Q на P: " << quotient << "\n";
}

#endif 
