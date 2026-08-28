#include <iostream>
#include <Windows.h>

int pivot(int *arr, int left, int right)
{
    int pivot = arr[right];

    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quick_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int piv = pivot(arr, left, right);
        quick_sort(arr, left, piv - 1);
        quick_sort(arr, piv + 1, right);
    }
}

void quick_sort(int *arr, int size)
{
    quick_sort(arr, 0, size - 1);
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

    int arr_1[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int arr_2[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    int arr_3[] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};

    int size_arr;

    // 1 Array
    size_arr = sizeof(arr_1) / sizeof(arr_1[0]);
    std::cout << "Исходный массив: ";
    print_arr(arr_1, size_arr);
    quick_sort(arr_1, size_arr);
    std::cout << "Отсортированный массив: ";
    print_arr(arr_1, size_arr);
    std::cout << std::endl;

    // 2 Array
    size_arr = sizeof(arr_2) / sizeof(arr_2[0]);
    std::cout << "Исходный массив: ";
    print_arr(arr_2, size_arr);
    quick_sort(arr_2, size_arr);
    std::cout << "Отсортированный массив: ";
    print_arr(arr_2, size_arr);
    std::cout << std::endl;

    // 3 Array
    size_arr = sizeof(arr_3) / sizeof(arr_3[0]);
    std::cout << "Исходный массив: ";
    print_arr(arr_3, size_arr);
    quick_sort(arr_3, size_arr);
    std::cout << "Отсортированный массив: ";
    print_arr(arr_3, size_arr);
    std::cout << std::endl;

    return 0;
}