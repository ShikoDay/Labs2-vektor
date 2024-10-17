#include <iostream>
#include <vector>
#include <fstream>

// Шаблонный класс для работы с векторами
template <typename T>
class VectorHandler {
private:
    std::vector<T> vec; // Внутреннее хранилище вектора

public:
    // Конструктор по умолчанию
    VectorHandler() {}

    // Конструктор с параметром размера вектора
    VectorHandler(size_t size) : vec(size) {}

    // Перегруженный оператор [] для доступа к элементам
    T& operator[](size_t index) {
        return vec[index];
    }

    // Получение элемента (константный вариант)
    const T& operator[](size_t index) const {
        return vec[index];
    }

    // Метод для получения размера вектора
    size_t Size() const {
        return vec.size();
    }

    // Метод для установки размера вектора
    void Resize(size_t newSize) {
        vec.resize(newSize);
    }

    // Ввод вектора с клавиатуры
    void Input() {
        std::cout << "Введите размер вектора: ";
        size_t size;
        std::cin >> size;
        Resize(size);

        std::cout << "Введите элементы вектора: ";
        for (size_t i = 0; i < size; ++i) {
            std::cin >> vec[i];
        }
    }

    // Вывод вектора на экран
    void Print() const {
        for (const auto& el : vec) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }

    // Перегрузка оператора сложения +
    VectorHandler<T> operator+(const VectorHandler<T>& other) const {
        if (vec.size() != other.Size()) {
            throw std::invalid_argument("Размеры векторов не совпадают для операции сложения.");
        }
        VectorHandler<T> result(vec.size());
        for (size_t i = 0; i < vec.size(); ++i) {
            result[i] = vec[i] + other[i];
        }
        return result;
    }

    // Перегрузка оператора вычитания -
    VectorHandler<T> operator-(const VectorHandler<T>& other) const {
        if (vec.size() != other.Size()) {
            throw std::invalid_argument("Размеры векторов не совпадают для операции вычитания.");
        }
        VectorHandler<T> result(vec.size());
        for (size_t i = 0; i < vec.size(); ++i) {
            result[i] = vec[i] - other[i];
        }
        return result;
    }

    // Перегрузка оператора умножения *
    VectorHandler<T> operator*(const VectorHandler<T>& other) const {
        if (vec.size() != other.Size()) {
            throw std::invalid_argument("Размеры векторов не совпадают для операции умножения.");
        }
        VectorHandler<T> result(vec.size());
        for (size_t i = 0; i < vec.size(); ++i) {
            result[i] = vec[i] * other[i];
        }
        return result;
    }

    // Перегрузка оператора вывода <<
    friend std::ostream& operator<<(std::ostream& out, const VectorHandler<T>& v) {
        for (const auto& el : v.vec) {
            out << el << " ";
        }
        return out;
    }

    // Перегрузка оператора ввода >>
    friend std::istream& operator>>(std::istream& in, VectorHandler<T>& v) {
        for (auto& el : v.vec) {
            in >> el;
        }
        return in;
    }
};
