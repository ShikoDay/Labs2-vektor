// Подключаем библиотеку iostream
#include <fstream>
#include <string>
#include <iostream>

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

// string InitData(string filePath)
// {
//     string line;
//     ifstream myfile("C:/Users/Win10Pro/Desktop/kurs5/algoritmisation/Labs2-vektor/" + filePath);
//     if (myfile.is_open())
//     {

//         while (getline(myfile, line))
//         {
//             if (line == "vector" or line == "Vector")
//             {
//                 cout << line << endl;
//                 cout << "vector is search" << "\n";
//                 continue;
//             }
//             else
//                 cout << "vector is not found" << "\n";

//             // cout << line << endl;
//         }
//         myfile.close();
//     }

//     else
//         cout << "Unable to open file" << "\n";

//     int Num_of_values = 1;
//     int Values[Num_of_values];
//     return Num_of_values, Values;
// }

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    CalcProblemParams CalcProblemParamsCreate;
    for (int i = 0; i < argc; i++)
    {
        if (string(argv[i]) == "-fp1")
        {
            if (i + 1 < argc)
            { // Проверка границ
                CalcProblemParamsCreate.filePath1 = argv[i + 1];
                // logAll("File Path 1: " + CalcProblemParamsCreate.filePath1);
            }
        }
        else if (string(argv[i]) == "-fp2")
        {
            if (i + 1 < argc)
            { // Проверка границ
                CalcProblemParamsCreate.filePath2 = argv[i + 1];
                // logAll("File Path 2: " + CalcProblemParamsCreate.filePath2);
            }
        }
        else if (string(argv[i]) == "-op")
        {
            if (i + 1 < argc)
            { // Проверка границ
                string operation = argv[i + 1];
                if (operation == "vv_sum")
                {
                    CalcProblemParamsCreate.op = CalcProblemParams::Operations::vv_sum;
                    cout << "Operation call: vector sum" << "\n";
                }
                else if (operation == "vv_sub")
                {
                    CalcProblemParamsCreate.op = CalcProblemParams::Operations::vv_sub;
                    cout << "Operation call: vector sub" << "\n";
                }
                else if (operation == "vv_scMalt")
                {
                    CalcProblemParamsCreate.op = CalcProblemParams::Operations::vv_scMalt;
                    cout << "Operation call: vector scMath" << "\n";
                }
                else
                {
                    cout << "Error: Unknown operation" << "\n";
                }
            }
            else
            {
                cout << "Error: No value provided for --o" << "\n";
            }
        }
    }

    // string fileParam1 = InitData(CalcProblemParamsCreate.filePath1);
    // string fileParam2 = InitData(CalcProblemParamsCreate.filePath2);

    string line;
    ifstream myfile1("C:/Users/Win10Pro/Desktop/kurs5/algoritmisation/Labs2-vektor/" + CalcProblemParamsCreate.filePath1);
    if (myfile1.is_open())
    {

        while (getline(myfile1, line))
        {
            if (line == "vector" or line == "Vector")
            {
                // cout << line << endl;
                cout << "vector is search" << "\n";
                continue;
            }
            // else
            //     cout << "vector is not found" << "\n";

            cout << line << endl;
        }
        myfile1.close();
    }

    else
    {
        cout << "Unable to open file" << "\n";
    }

    ifstream myfile2("C:/Users/Win10Pro/Desktop/kurs5/algoritmisation/Labs2-vektor/" + CalcProblemParamsCreate.filePath2);
    if (myfile2.is_open())
    {

        while (getline(myfile2, line))
        {
            if (line == "vector" or line == "Vector")
            {
                // cout << line << endl;
                cout << "vector is search" << "\n";
                continue;
            }
            // else
            //     cout << "vector is not found" << "\n";

            cout << line << endl;
        }
        myfile2.close();
    }

    else
    {
        cout << "Unable to open file" << "\n";
    }

    return 0;
};