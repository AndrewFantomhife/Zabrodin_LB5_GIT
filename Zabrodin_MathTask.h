#ifndef SURNAME_MATHTASK_H
#define SURNAME_MATHTASK_H

#include <iostream>
#include <limits>
#include <stdexcept>

// Функция для полной проверки корректности ввода целого числа
void validateInput(std::istream& input) {
    try {
        if (input.fail()) {
            // Если ввод некорректен, выбрасываем исключение
            throw std::invalid_argument("Ошибка: введено некорректное значение.");
        }
        // Очищаем буфер после успешного ввода
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } catch (const std::exception&) {
        // Сброс флага ошибки и очистка буфера при возникновении исключения
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw; // Повторно выбрасываем исключение для обработки выше уровнем
    }
}

int inputNumber(const std::string& prompt) {
    int number;
    while (true) {
        std::cout << prompt;
        std::cin >> number;

        // Вызываем функцию проверки ввода
        validateInput(std::cin);

        // Если ввод корректен, возвращаем число
        return number;
    }
}

// Функция для вычисления результатов деления
void calculateDivisionResults(int Q, int P) {
    if (P <= 0 || P >= Q) {
        throw std::invalid_argument("Ошибка: P должно быть натуральным числом и меньше Q.");
    }

    int remainder = Q % P;  // Остаток от деления
    int quotient = Q / P;   // Целая часть от деления

    std::cout << "Остаток от деления Q на P: " << remainder << "\n";
    std::cout << "Целая часть от деления Q на P: " << quotient << "\n";
}

#endif // SURNAME_MATHTASK_H