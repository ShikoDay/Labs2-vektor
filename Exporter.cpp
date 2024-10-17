#include <iostream>
#include <vector>
#include <fstream>

// Класс для экспорта данных в файл
template <typename T>
class Exporter {
public:
    // Метод для записи вектора в файл
    void ExportToFile(const VectorHandler<T>& vec, const std::string& filename) {
        std::ofstream outfile(filename);
        if (!outfile) {
            std::cerr << "Не удалось открыть файл для записи!\n";
            return;
        }
        outfile << "Результат вектора:\n";
        outfile << vec << "\n";
        outfile.close();
        std::cout << "Результаты сохранены в файл " << filename << "\n";
    }
};
