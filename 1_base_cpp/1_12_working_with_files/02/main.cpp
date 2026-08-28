#include <iostream>
#include <fstream>

int main()
{
    std::ifstream inFile("in.txt");

    if (!inFile.is_open())
    {
        std::cerr << "Ошибка: не удалось открыть файл in.txt" << std::endl;
        return 1;
    }

    int size;
    if (!(inFile >> size) || size <= 0)
    {
        std::cerr << "Ошибка: неверный размер массива" << std::endl;
        return 1;
    }

    int *arr = new int[size];

    for (int i = 0; i < size; ++i)
    {
        if (!(inFile >> arr[i]))
        {
            std::cerr << "Ошибка: недостаточно данных в файле" << std::endl;
            delete[] arr;
            return 1;
        }
    }

    for (int i = size - 1; i >= 0; --i)
    {
        std::cout << arr[i];
        if (i > 0)
        {
            std::cout << " ";
        }
    }

    std::cout << std::endl;

    delete[] arr;
    inFile.close();

    return 0;
}