#include <iostream>
#include <Windows.h>

void count_sort(int *arr, int size)
{
    int min = 10;
    int max = 24;
    int range = max - min + 1;
    
    int* arr_count = new int[range]();

    for (int i = 0; i < size; i++)
        arr_count[arr[i] - min]++;
    
    int index = 0;
    for (int i = 0; i < range; i++)
    {
        while (arr_count[i] > 0)
        {
            arr[index++] = i + min;
            arr_count[i]--;
        }
    }
    
    delete[] arr_count;
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

    int arr_1[] = {1, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11,
                   20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17};

    int arr_2[] = {16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16,
                   17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11,
                   16, 22, 23, 16};

    int arr_3[] = {21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20,
                   12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15,
                   13, 22, 18, 18, 11, 23, 24, 17, 10};

    int size_arr;

    // 1 Array
    size_arr = sizeof(arr_1) / sizeof(arr_1[0]);
    std::cout << "Исходный массив: ";
    print_arr(arr_1, size_arr);
    count_sort(arr_1, size_arr);
    std::cout << "Отсортированный массив: ";
    print_arr(arr_1, size_arr);
    std::cout << std::endl;

    // 2 Array
    size_arr = sizeof(arr_2) / sizeof(arr_2[0]);
    std::cout << "Исходный массив: ";
    print_arr(arr_2, size_arr);
    count_sort(arr_2, size_arr);
    std::cout << "Отсортированный массив: ";
    print_arr(arr_2, size_arr);
    std::cout << std::endl;

    // 3 Array
    size_arr = sizeof(arr_3) / sizeof(arr_3[0]);
    std::cout << "Исходный массив: ";
    print_arr(arr_3, size_arr);
    count_sort(arr_3, size_arr);
    std::cout << "Отсортированный массив: ";
    print_arr(arr_3, size_arr);
    std::cout << std::endl;

    return 0;
}