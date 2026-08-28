#include <iostream>

int main()
{
    const int SIZE_ARR = 10;
    int arr[SIZE_ARR] = {15, -3, 42, 7, 0, 100, -25, 8, 33, 1};

    std::cout << "Массив до сортировки: ";
    for (int i = 0; i < SIZE_ARR; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    bool swapped;
    int sort_border{0};

    do
    {
        swapped = false;
        for (int i = SIZE_ARR - 1; i > sort_border; --i)
        {
            if (arr[i - 1] > arr[i])
            {
                int temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                swapped = true;
            }
        }
        sort_border++;
    } while (swapped);

    std::cout << "Массив после сортировки: ";
    for (int i = 0; i < SIZE_ARR; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}