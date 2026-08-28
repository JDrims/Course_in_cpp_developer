#include <iostream>

int main()
{
    int arr[3][6] = {
        {73, 22, 4, 7, -15, 43},
        {-3, 15, -25, 86, 154, -51},
        {-84, -14, 51, 145, 5, 9}
    };

    std::cout << "Массив: " << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    int imin{0}, jmin{0};
    int imax{0}, jmax{0};
    int min{arr[0][0]};
    int max{arr[0][0]};

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
                imin = i;
                jmin = j;
            }
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                imax = i;
                jmax = j;
            }
        }
    }

    std::cout << "Индекс минимального элемента: " << imin << " " << jmin << std::endl;
    std::cout << "Индекс максимального элемента: " << imax << " " << jmax << std::endl;

    return 0;
}