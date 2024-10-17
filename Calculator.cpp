#include <iostream>
#include <vector>
#include <fstream>

// Класс для выполнения операций с векторами
template <typename T>
class Calculator {
public:
    // Сложение векторов
    VectorHandler<T> Add(const VectorHandler<T>& v1, const VectorHandler<T>& v2) {
        return v1 + v2;
    }

    // Вычитание векторов
    VectorHandler<T> Subtract(const VectorHandler<T>& v1, const VectorHandler<T>& v2) {
        return v1 - v2;
    }

    // Умножение векторов
    VectorHandler<T> Multiply(const VectorHandler<T>& v1, const VectorHandler<T>& v2) {
        return v1 * v2;
    }
};