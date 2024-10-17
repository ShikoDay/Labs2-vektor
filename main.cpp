#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

// Подключаем пространство имен std
using namespace std;

struct CalcProblemParams
{
    std::string filePath1;
    std::string filePath2;
    enum class Operations
    {
        vv_sum,
        vv_sub,
        vv_scMalt
    };
    Operations op;
    /* data */
};

// Структура для хранения значений векторов и их размерностей:
struct VectorData
{
    vector<double> values;
    int size;
};

struct ExportConfig
{
    string path; // Путь к файлу
};

struct CalcResults
{
    VectorData result; // Результат сложения векторов
};

int logAll(string data)
{
    ofstream logFile("log.txt", ios::app); // Открываем файл в режиме добавления
    if (!logFile)
    {
        return -1;
    }
    time_t t = time(0);             // Получаю текущее время
    struct tm *now = localtime(&t); // Преобразую в локальное время

    // Записываем дату и время в файл
    logFile << put_time(now, "%Y-%m-%d %H:%M:%S") << " - "; // Форматирую и записываем дату и время

    logFile << data << endl; // Записываю данные в файл
    logFile.close();         // Закрываю файл
    return 0;
}

// Функция для чтения из файлов и проверки значений
VectorData readDataFromFile(const string &filepath)
{
    string line;
    VectorData vectorData;
    ifstream dataFile(filepath); // Открываем файл в режиме чтения
    if (!dataFile)
    {
        logAll("Ошибка открытия файла");
        return vectorData; // Возвращаем пустой вектор
    }

    while (getline(dataFile, line))
    {
        logAll(line);
        if (line == "vector" or line == "Vector")
        {
            logAll("В файле обнаружено значение vector");
            // Читаем размер вектора
            if (getline(dataFile, line))
            {
                vectorData.size = stoi(line);
                vectorData.values.resize(vectorData.size);
                // Читаем значения вектора
                if (getline(dataFile, line))
                {
                    /*Istringstream - это строковой поток ввода. Конструктор istringstream () со строковым аргументом прикрепляет создаваемый объект потока к указанной строке. То есть теперь информация будет считываться из стандартной строки точно таким же образом, как и из cin, объекта класса потока ввода istream.*/
                    istringstream iss(line);
                    for (int i = 0; i < vectorData.size; ++i)
                    {
                        iss >> vectorData.values[i];
                    }
                }
            }
        }
    }
    dataFile.close(); // Закрываем файл
    return vectorData;
}

// Функция для сложения двух векторов
VectorData Calck_vv_sum(const VectorData &vec1, const VectorData &vec2)
{
    // Проверка на равенство размерностей
    if (vec1.size != vec2.size)
    {
        logAll("Ошибка! Размерность векторов не совпадает");
        return VectorData();
    }

    VectorData result;                 // Создаем объект для хранения результата сложения векторов
    result.size = vec1.size;           // Устанавливаем размер результирующего вектора равным размеру первого вектора
    result.values.resize(result.size); // Изменяем размер массива значений результирующего вектора

    // Сложение векторов
    for (int i = 0; i < result.size; ++i)
    {
        result.values[i] = vec1.values[i] + vec2.values[i];
    }

    return result;
}

// Функция для вычитания векторов
VectorData Calck_vv_sub(const VectorData &vec1, const VectorData &vec2)
{
    // Проверка на равенство размерностей
    if (vec1.size != vec2.size)
    {
        logAll("Ошибка! Размерность векторов не совпадает");
        return VectorData();
    }

    VectorData result;                 // Создаем объект для хранения результата вычитания векторов
    result.size = vec1.size;           // Устанавливаем размер результирующего вектора равным размеру первого вектора
    result.values.resize(result.size); // Изменяем размер массива значений результирующего вектора

    // Вычитание векторов
    for (int i = 0; i < result.size; ++i)
    {
        result.values[i] = vec1.values[i] - vec2.values[i];
    }

    return result;
}

int Export(const CalcResults &calcResults, const ExportConfig &config)
{
    // Создаю файл и открываю его на дозапись
    logAll("Открываю " + config.path);
    ofstream dataFile(config.path, ios::app); // Открываем файл в режиме добавления
    if (!dataFile)
    {
        logAll("Ошибка открытия файла: " + config.path);
        return -1;
    }
    // Записываем дату и время в файл
    dataFile << "Result: "; // Форматирую и записываем дату и время

    // Записываем данные в файл
    for (const auto &value : calcResults.result.values)
    {
        dataFile << value << " "; // Записываем значения вектора
    }
    dataFile << endl; // Переход на новую строку
    dataFile.close(); // Закрываю файл
    return 0;
}

int main(int argc, char *argv[])
{
    VectorData vector1, vector2;
    CalcProblemParams calcParams;
    CalcResults calcResult; // Создаем объект для хранения результата

    // cout << "vxod";

    for (int i = 1; i < argc; i++)
    {
        // cout << argv[i];
        if (string(argv[i]) == "-fp1")
        {
            if (i + 1 < argc)
            { // Проверка границ
                calcParams.filePath1 = argv[i + 1];
                logAll("Путь к файлу 1: " + calcParams.filePath1);
                vector1 = readDataFromFile(calcParams.filePath1);
            }
        }
        else if (string(argv[i]) == "-fp2")
        {
            if (i + 1 < argc)
            { // Проверка границ
                calcParams.filePath2 = argv[i + 1];
                logAll("Путь к файлу 2: " + calcParams.filePath2);
                vector2 = readDataFromFile(calcParams.filePath2);
            }
        }
        else if (string(argv[i]) == "-op")
        {
            if (i + 1 < argc)
            { // Проверка границ
                string operation = argv[i + 1];
                logAll("Операция: " + operation);
                if (operation == "vv_sum")
                {
                    calcParams.op = CalcProblemParams::Operations::vv_sum;
                    logAll("Вызвана операция: суммирование векторов");
                    // Сложение векторов
                    calcResult.result = Calck_vv_sum(vector1, vector2);
                    // if (calcResult.result.size > 0)
                    // {
                    //     cout << "Resulting vector: ";
                    //     for (const auto &value : calcResult.result.values)
                    //     {
                    //         cout << value << " ";
                    //     }
                    //     cout << endl;
                    // }
                }
                else if (operation == "vv_sub")
                {
                    calcParams.op = CalcProblemParams::Operations::vv_sub;
                    logAll("Вызвана операция: вычитание векторов");
                    calcResult.result = Calck_vv_sub(vector1, vector2);
                }
                else if (operation == "vv_scMalt")
                {
                    calcParams.op = CalcProblemParams::Operations::vv_scMalt;
                    logAll("Вызвана операция: переумножение векторов");
                }
                else
                {
                    logAll("Ошибка: неизвестная операция");
                }
            }
            else
            {
                logAll("Ошибка: нет аргументов после --op");
            }
        }
        else if (string(argv[i]) == "--exp")
        {
            if (i + 1 < argc)
            { // Проверка границ
                ExportConfig conf;
                conf.path = argv[i + 1]; // Сохраняем путь к файлу
                logAll("Путь и имя выходного файла: " + conf.path);
                // Вызов функции Export с нужными аргументами
                int exportResult = Export(calcResult, conf);
                if (exportResult != 0)
                {
                    logAll("Ошибка при экспорте данных");
                }
            }
            else
            {
                logAll("Ошибка: нет аргументов после --exp");
            }
        }
    }
    return 0;
}
// g++ 1.cpp -o app

// int main(int argc, char *argv[])
// {
//     setlocale(LC_ALL, "Russian");
//     CalcProblemParams CalcProblemParamsCreate;
//     for (int i = 0; i < argc; i++)
//     {
//         if (string(argv[i]) == "-fp1")
//         {
//             if (i + 1 < argc)
//             {
//                 CalcProblemParamsCreate.filePath1 = argv[i + 1];
//                 // logAll("File Path 1: " + CalcProblemParamsCreate.filePath1);
//             }
//         }
//         else if (string(argv[i]) == "-fp2")
//         {
//             if (i + 1 < argc)
//             {
//                 CalcProblemParamsCreate.filePath2 = argv[i + 1];
//                 // logAll("File Path 2: " + CalcProblemParamsCreate.filePath2);
//             }
//         }
//         else if (string(argv[i]) == "-op")
//         {
//             if (i + 1 < argc)
//             {
//                 string operation = argv[i + 1];
//                 if (operation == "vv_sum")
//                 {
//                     CalcProblemParamsCreate.op = CalcProblemParams::Operations::vv_sum;
//                     cout << "Operation call: vector sum" << "\n";
//                 }
//                 else if (operation == "vv_sub")
//                 {
//                     CalcProblemParamsCreate.op = CalcProblemParams::Operations::vv_sub;
//                     cout << "Operation call: vector sub" << "\n";
//                 }
//                 else if (operation == "vv_scMalt")
//                 {
//                     CalcProblemParamsCreate.op = CalcProblemParams::Operations::vv_scMalt;
//                     cout << "Operation call: vector scMath" << "\n";
//                 }
//                 else
//                 {
//                     cout << "Error: Unknown operation" << "\n";
//                 }
//             }
//             else
//             {
//                 cout << "Error: No value provided for --o" << "\n";
//             }
//         }
//     }

//     // string fileParam1 = InitData(CalcProblemParamsCreate.filePath1);
//     // string fileParam2 = InitData(CalcProblemParamsCreate.filePath2);

//     string line;
//     ifstream myfile1("C:/Users/Win10Pro/Desktop/kurs5/algoritmisation/Labs2-vektor/" + CalcProblemParamsCreate.filePath1);
//     if (myfile1.is_open())
//     {

//         while (getline(myfile1, line))
//         {
//             if (line == "vector" or line == "Vector")
//             {
//                 // cout << line << endl;
//                 cout << "vector is search" << "\n";
//                 continue;
//             }
//             // else
//             //     cout << "vector is not found" << "\n";

//             cout << line << endl;
//         }
//         myfile1.close();
//     }

//     else
//     {
//         cout << "Unable to open file" << "\n";
//     }

//     ifstream myfile2("C:/Users/Win10Pro/Desktop/kurs5/algoritmisation/Labs2-vektor/" + CalcProblemParamsCreate.filePath2);
//     if (myfile2.is_open())
//     {

//         while (getline(myfile2, line))
//         {
//             if (line == "vector" or line == "Vector")
//             {
//                 // cout << line << endl;
//                 cout << "vector is search" << "\n";
//                 continue;
//             }
//             // else
//             //     cout << "vector is not found" << "\n";

//             cout << line << endl;
//         }
//         myfile2.close();
//     }

//     else
//     {
//         cout << "Unable to open file" << "\n";
//     }

//     return 0;
// };