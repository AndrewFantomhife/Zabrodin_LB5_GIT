#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"
#include "Zabrodin_MathTask.h"       

using namespace cute;
using namespace std;

// Тест для проверки корректного вычисления остатка и целой части
void testCalculateDivision_ValidInput() {
    int Q = 3;
    int P = 2;

    // Перехватываем вывод cout
    ostringstream output;
    streambuf* oldCout = cout.rdbuf(output.rdbuf());

    // Вызываем функцию
    calculateDivisionResults(Q, P);

    // Возвращаем стандартный вывод
    cout.rdbuf(oldCout);

    // Проверяем вывод
    string expectedOutput = "Остаток от деления Q на P: 1\nЦелая часть от деления Q на P: 1\n";
    ASSERT_EQUAL(expectedOutput, output.str());
}

// Тест: Проверка отсева пустых значений при вводе
void testInputNumber_EmptyInput() {
    // Создаем строковый поток для эмуляции ввода 
    istringstream input("\n42");
    streambuf* oldCin = cin.rdbuf(input.rdbuf()); // Перехватываем cin

    // Вызываем функцию inputNumber
    int result = inputNumber("Введите число: ");

    // Возвращаем стандартный ввод
    cin.rdbuf(oldCin);

    // Проверяем результат
    ASSERT_EQUAL(42, result);
}

// Тест: Проверка отсева нецифровых символов при вводе
void testInputNumber_NonNumericInput() {
    // Создаем строковый поток для эмуляции ввода (нецифровые символы, затем корректное значение)
    istringstream input("abc\n42");
    streambuf* oldCin = cin.rdbuf(input.rdbuf()); // Перехватываем cin

    // Вызываем функцию inputNumber
    int result = inputNumber("Введите число: ");

    // Возвращаем стандартный ввод
    cin.rdbuf(oldCin);

    // Проверяем результат
    ASSERT_EQUAL(42, result);
}

// Тест: Проверка отсева отрицательных чисел при вводе
void testInputNumber_NegativeInput() {
    // Создаем строковый поток для эмуляции ввода (отрицательное значение, затем корректное значение)
    istringstream input("-5\n42");
    streambuf* oldCin = cin.rdbuf(input.rdbuf()); // Перехватываем cin

    // Вызываем функцию inputNumber
    int result = inputNumber("Введите число: ");

    // Возвращаем стандартный ввод
    cin.rdbuf(oldCin);

    // Проверяем результат
    ASSERT_EQUAL(42, result);
}

// Главная функция для запуска тестов
int main() {
    // Создаем тестовый набор
    suite s;

    // Добавляем тестовые функции в набор
    s.push_back(CUTE(testCalculateDivision_ValidInput));
    s.push_back(CUTE(testInputNumber_EmptyInput));
    s.push_back(CUTE(testInputNumber_NonNumericInput));
    s.push_back(CUTE(testInputNumber_NegativeInput));

    // Создаем listener и runner
    ide_listener<> listener;

    // Запускаем тесты
    makeRunner(listener)(s, "Тесты для calculateDivisionResults");

    return 0;
}
