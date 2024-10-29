Векторы в C++ — это динамические массивы, предоставляемые стандартной библиотекой STL (Standard Template Library). Они являются одним из самых популярных контейнеров, позволяя удобно управлять коллекциями объектов. Вот основные аспекты работы с векторами в C++:

▎Основные характеристики векторов

1. Динамическое выделение памяти:

   • Векторы могут изменять свой размер во время выполнения программы, автоматически выделяя и освобождая память по мере добавления или удаления элементов.

2. Хранение элементов:

   • Векторы хранят элементы в непрерывной области памяти, что обеспечивает быструю индексацию (доступ по индексу за O(1)).

3. Гибкость:

   • Векторы могут хранить объекты любого типа, включая пользовательские структуры и классы.

▎Основные операции с векторами

1. Создание вектора:
   
C++

   #include <vector>

   std::vector<int> vec; // Пустой вектор целых чисел
   std::vector<int> vec2(10); // Вектор из 10 элементов, инициализированных нулями
   std::vector<int> vec3(10, 5); // Вектор из 10 элементов, инициализированных значением 5
   

2. Добавление элементов:
   
C++

   vec.push_back(1); // Добавление элемента в конец
   vec.push_back(2);
   

3. Удаление элементов:
   
C++

   vec.pop_back(); // Удаление последнего элемента
   vec.erase(vec.begin() + 1); // Удаление элемента по индексу
   

4. Доступ к элементам:
   
C++

   int first = vec[0]; // Доступ к первому элементу
   int second = vec.at(1); // Доступ с проверкой границ
   

5. Размер и емкость:
   
C++

   size_t size = vec.size(); // Количество элементов
   size_t capacity = vec.capacity(); // Вместимость (количество элементов, которые может хранить без перераспределения)
   

6. Очистка вектора:
   
C++

   vec.clear(); // Удаляет все элементы
   

▎Пример использования

Вот пример простого использования векторов:

C++

#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;

    // Добавление элементов
    for (int i = 1; i <= 5; ++i) {
        numbers.push_back(i);
    }

    // Вывод элементов
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << "Element at index " << i << ": " << numbers[i] << std::endl;
    }

    // Удаление последнего элемента
    numbers.pop_back();

    std::cout << "After popping last element:" << std::endl;
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

▎Заключение

Векторы в C++ — мощный инструмент для работы с динамическими массивами, обеспечивающий гибкость и удобство. Они поддерживают множество операций, что делает их идеальными для хранения и обработки коллекций данных. Использование векторов позволяет разработчикам писать более эффективный и понятный код.
