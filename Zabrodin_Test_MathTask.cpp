#include "CUTE/cute/cute.h"   
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"
#include "Zabrodin_MathTask.h"       // Подключение модуля с тестируемыми методами

using namespace cute;

// Тест для проверки корректного вычисления остатка и целой части
void testCalculateDivision_ValidInput() {
    int Q = 3;
    int P = 2;

    // Перехватываем вывод std::cout
    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Вызываем функцию
    calculateDivisionResults(Q, P);

    // Возвращаем стандартный вывод
    std::cout.rdbuf(oldCout);

    // Проверяем вывод
    std::string expectedOutput = "Остаток от деления Q на P: 1";
    ASSERT_EQUAL(expectedOutput, output.str());
}
// Тест: Проверка отсева пустых значений при вводе
void testInputNumber_EmptyInput() {
    // Создаем строковый поток для эмуляции ввода (пустой ввод, затем корректное значение)
    std::istringstream input("\n42");
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf()); // Перехватываем std::cin

    // Вызываем функцию inputNumber
    int result = inputNumber("Введите число: ");

    // Возвращаем стандартный ввод
    std::cin.rdbuf(oldCin);

    // Проверяем результат
    ASSERT_EQUAL(42, result);
}
// Тест: Проверка отсева нецифровых символов при вводе
void testInputNumber_NonNumericInput() {
    // Создаем строковый поток для эмуляции ввода (нецифровые символы, затем корректное значение)
    std::istringstream input("abc\n42");
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf()); // Перехватываем std::cin

    // Вызываем функцию inputNumber
    int result = inputNumber("Введите число: ");

    // Возвращаем стандартный ввод
    std::cin.rdbuf(oldCin);

    // Проверяем результат
    ASSERT_EQUAL(42, result);
}
void testInputNumber_NegativeInput() {
    // Создаем строковый поток для эмуляции ввода (отрицательное значение, затем корректное значение)
    std::istringstream input("-5\n42");
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf()); // Перехватываем std::cin

    // Вызываем функцию inputNumber
    int result = inputNumber("Введите число: ");

    // Возвращаем стандартный ввод
    std::cin.rdbuf(oldCin);

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