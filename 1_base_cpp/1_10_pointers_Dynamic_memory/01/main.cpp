#include <iostream>

int main()
{
    int size_arr;

    std::cout << "Введите размер массива: ";
    std::cin >> size_arr;
    if (size_arr <= 0)
    {
        std::cout << "Размер массива должен быть положительным!" << std::endl;
        return 1;
    }

    int *arr = new int[size_arr];
    for (int i = 0; i < size_arr; i++)
    {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }

    std::cout << "Введённый массив: ";
    for (int i = 0; i < size_arr; i++)
    {
        std::cout << arr[i];
        if (i < size_arr - 1)
        {
            std::cout << " ";
        }
    }

    delete[] arr;

    return 0;
}