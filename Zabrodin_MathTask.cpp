#include "Zabrodin_MathTask.h"

int main() {
    try {
        // Ввод числа Q
        int Q = inputNumber("Введите целое число Q: ");

        // Ввод числа P
        int P = inputNumber("Введите натуральное число P (меньше Q): ");

        // Вычисление и вывод результатов
        calculateDivisionResults(Q, P);
    } catch (const std::exception& e) {
        std::cerr << "Произошла ошибка: " << e.what() << "\n";
    }

    return 0;
}