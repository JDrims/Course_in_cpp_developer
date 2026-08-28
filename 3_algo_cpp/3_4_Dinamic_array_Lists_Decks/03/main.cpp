#include <iostream>
#include "Windows.h"

int *remove_dynamic_array_head(int *arr, int &logical_size, int &actual_size)
{
    if (logical_size == 0)
        return arr;

    if ((logical_size - 1) > (actual_size / 3))
    {
        for (int i = 0; i < logical_size - 1; i++)
            arr[i] = arr[i + 1];
        logical_size--;

        return arr;
    }
    else
    {
        actual_size = actual_size / 3;
        if (actual_size < 1)
            actual_size = 1;

        int *new_arr = new int[actual_size];
        for (int i = 0; i < logical_size - 1; i++)
            new_arr[i] = arr[i + 1];

        logical_size--;

        delete[] arr;

        return new_arr;
    }
}

void print_dynamic_array(int *arr, int logical_size, int actual_size)
{
    for (int i = 0; i < actual_size; ++i)
    {
        if (i < logical_size)
        {
            std::cout << arr[i];
        }
        else
        {
            std::cout << '_';
        }
        if (i != actual_size - 1)
        {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int actual_size, logical_size;

    std::cout << "Введите фактичеcкий размер массива: ";
    std::cin >> actual_size;
    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;

    if (logical_size > actual_size)
    {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
        return 1;
    }

    int *arr = new int[actual_size];

    for (int i = 0; i < logical_size; ++i)
    {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    std::cout << "Динамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);

    while (true)
    {
        std::string is_delete;
        std::cout << "Удалить первый элемент? ";
        std::cin >> is_delete;
        if (is_delete == "да")
        {
            if (logical_size > 0)
            {
                arr = remove_dynamic_array_head(arr, logical_size, actual_size);
                std::cout << "Динамический массив: ";
                print_dynamic_array(arr, logical_size, actual_size);
            }
            else
            {
                std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!";
                break;
            }
        }
        else
        {
            std::cout << "Спасибо! Ваш динамический массив: ";
            print_dynamic_array(arr, logical_size, actual_size);
            break;
        }
    }

    delete[] arr;

    return 0;
}