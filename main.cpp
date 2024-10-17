#include <iostream>
#include <vector>
#include <fstream>
#include "VectorHandler.cpp"
#include "Exporter.cpp"
#include "Calculator.cpp"

// Основная функция
int main() {
    try {
        VectorHandler<int> vec1, vec2, result;

        // Ввод векторов
        std::cout << "Введите первый вектор:\n";
        vec1.Input();
        std::cout << "Введите второй вектор:\n";
        vec2.Input();

        // Создание объектов калькулятора и экспортера
        Calculator<int> calc;
        Exporter<int> exporter;

        // Операция сложения
        std::cout << "Результат сложения векторов:\n";
        result = calc.Add(vec1, vec2);
        result.Print();

        // Экспорт результата в файл
        exporter.ExportToFile(result, "add_result.txt");

        // Операция вычитания
        std::cout << "Результат вычитания векторов:\n";
        result = calc.Subtract(vec1, vec2);
        result.Print();

        // Экспорт результата в файл
        exporter.ExportToFile(result, "sub_result.txt");

        // Операция умножения
        std::cout << "Результат умножения векторов:\n";
        result = calc.Multiply(vec1, vec2);
        result.Print();

        // Экспорт результата в файл
        exporter.ExportToFile(result, "mul_result.txt");

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}