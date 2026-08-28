#include <iostream>

double *create_array(int);

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

    double *arr = create_array(size_arr);

    std::cout << "Массив: ";
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

double *create_array(int size)
{
    return new double[size]();
}