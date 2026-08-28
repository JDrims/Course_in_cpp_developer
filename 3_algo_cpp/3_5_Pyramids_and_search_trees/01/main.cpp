#include <iostream>
#include <Windows.h>

void print_pyramid(const int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int level = 0;
        int index = i + 1;
        while (index > 1)
        {
            index /= 2;
            level++;
        }

        if (i == 0)
        {
            std::cout << level << " root " << arr[i];
        }
        else
        {
            int parent_index = (i - 1) / 2;
            int parent_value = arr[parent_index];
            if (i % 2 == 1)
            {
                std::cout << level << " left(" << parent_value << ") " << arr[i];
            }
            else
            {
                std::cout << level << " right(" << parent_value << ") " << arr[i];
            }
        }
        std::cout << std::endl;
    }
}

void print_arr(const int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i < size - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr_1[] = {1, 3, 6, 5, 9, 8};
    int size_arr_1 = sizeof(arr_1) / sizeof(arr_1[0]);

    int arr_2[] = {94, 67, 18, 44, 55, 12, 6, 42};
    int size_arr_2 = sizeof(arr_2) / sizeof(arr_2[0]);

    int arr_3[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    int size_arr_3 = sizeof(arr_3) / sizeof(arr_3[0]);

    std::cout << "Исходный массив: ";
    print_arr(arr_1, size_arr_1);
    std::cout << "Пирамида:" << std::endl;
    print_pyramid(arr_1, size_arr_1);
    std::cout << std::endl;

    std::cout << "Исходный массив: ";
    print_arr(arr_2, size_arr_2);
    std::cout << "Пирамида:" << std::endl;
    print_pyramid(arr_2, size_arr_2);
    std::cout << std::endl;

    std::cout << "Исходный массив: ";
    print_arr(arr_3, size_arr_3);
    std::cout << "Пирамида:" << std::endl;
    print_pyramid(arr_3, size_arr_3);
    std::cout << std::endl;

    return 0;
}