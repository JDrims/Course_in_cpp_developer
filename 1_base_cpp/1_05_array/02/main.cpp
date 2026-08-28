#include <iostream>

int main()
{
    int arr[10] = {15, -3, 42, 7, 0, 100, -25, 8, 33, 1};

    std::cout << "Массив: ";
    for (int i = 0; i < 10; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < 10; ++i)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    std::cout << "Минимальный элемент: " << min << std::endl;
    std::cout << "Максимальный элемент: " << max << std::endl;

    return 0;
}