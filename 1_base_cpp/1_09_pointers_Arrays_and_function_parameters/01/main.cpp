#include <iostream>

void print(int *, int);

int main()
{
    int arr_1[9]{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size_arr = sizeof(arr_1) / sizeof(int);
    print(arr_1, size_arr);

    int arr_2[4]{6, 5, 4, 8};
    size_arr = sizeof(arr_2) / sizeof(int);
    print(arr_2, size_arr);

    int arr_3[5]{1, 4, 3, 7, 5};
    size_arr = sizeof(arr_3) / sizeof(int);
    print(arr_3, size_arr);

    return 0;
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