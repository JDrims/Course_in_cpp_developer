#include <iostream>

int main()
{
    int arr[10] = {5, 15, 3, 9, 1, 64, 33, 11, 45, 86};

    for (int i = 0; i < 10; i++)
    {
        if (i > 0)
        {
            std::cout << ", ";
        }
        std::cout << arr[i];
    }

    return 0;
}