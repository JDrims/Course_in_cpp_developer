#include <iostream>
#include <Windows.h>

void merge(int* arr, int begin, int mid, int end)
{
    int left_size = mid - begin + 1;
    int right_size = end - mid;

    int* left_arr = new int[left_size];
    int* right_arr = new int[right_size];

    for (int i = 0; i < left_size; i++)
        left_arr[i] = arr[begin + i];
    for (int i = 0; i < right_size; i++)
        right_arr[i] = arr[mid + i + 1];
    
    
    int i = 0, j = 0, k = begin;
    while (i < left_size && j < right_size)
    {
        if (left_arr[i] < right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < right_size)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
    
    delete[] left_arr;
    delete[] right_arr;
}

void merge_sort(int* arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge_sort(int* arr, int size)
{
    merge_sort(arr, 0, size - 1);
}

void print_arr(const int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i < size - 1) std::cout << " ";
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
    merge_sort(arr_1, size_arr);
    std::cout << "Отсортированный массив: ";
    print_arr(arr_1, size_arr);
    std::cout << std::endl;

    // 2 Array
    size_arr = sizeof(arr_2) / sizeof(arr_2[0]);
    std::cout << "Исходный массив: ";
    print_arr(arr_2, size_arr);
    merge_sort(arr_2, size_arr);
    std::cout << "Отсортированный массив: ";
    print_arr(arr_2, size_arr);
    std::cout << std::endl;

    // 3 Array
    size_arr = sizeof(arr_3) / sizeof(arr_3[0]);
    std::cout << "Исходный массив: ";
    print_arr(arr_3, size_arr);
    merge_sort(arr_3, size_arr);
    std::cout << "Отсортированный массив: ";
    print_arr(arr_3, size_arr);
    std::cout << std::endl;

    return 0;
}