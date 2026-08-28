#include <iostream>

void reverse(int *, int);
void print(int *, int);

int main()
{
    int arr1[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size_arr = sizeof(arr1) / sizeof(int);

    std::cout << "До функции reverse: ";
    print(arr1, size_arr);
    reverse(arr1, size_arr);
    std::cout << "После функции reverse: ";
    print(arr1, size_arr);

    std::cout << std::endl;

    int arr2[9]{1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_arr = sizeof(arr2) / sizeof(int);

    std::cout << "До функции reverse: ";
    print(arr2, size_arr);
    reverse(arr2, size_arr);
    std::cout << "После функции reverse: ";
    print(arr2, size_arr);

    return 0;
}

void reverse(int *arr, int size)
{
    int half_size = static_cast<int>(size / 2);

    for (int i = 0; i < half_size; i++)
    {
        int temp = arr[size - 1 - i];
        arr[size - i - 1] = arr[i];
        arr[i] = temp;
    }
}

void print(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i < size - 1)
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}