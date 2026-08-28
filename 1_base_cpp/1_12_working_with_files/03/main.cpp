#include <iostream>
#include <fstream>

int main()
{
    int *arr;
    std::ofstream outFile("out.txt");

    if (!outFile.is_open())
    {
        std::cerr << "Ошибка: не удалось открыть файл out.txt" << std::endl;
        return 1;
    }

    int size;

    std::cout << "Введите размер массива: ";
    std::cin >> size;

    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }

    outFile << size << std::endl;
    for (int i = size - 1; i >= 0; i--)
    {
        outFile << arr[i] << " ";
    }

    delete[] arr;
    outFile.close();

    return 0;
}