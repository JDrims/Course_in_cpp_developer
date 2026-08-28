#include <iostream>
#include <Windows.h>

int findInArr(int arr[], int sizeArr, int numComp)
{
    int left = 0, right = sizeArr;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] > numComp)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return sizeArr - left;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int arr[] = {14, 16, 19, 32, 32, 32, 56, 69, 72};

    std::cout << "Введите точку отсчёта:";
    int sizeArr = sizeof(arr) / sizeof(arr[0]);
    int numComp;
    std::cin >> numComp;

    int resultFind = findInArr(arr, sizeArr, numComp);

    std::cout << "Количество элементов в массиве больших, чем "
              << numComp << ": " << resultFind << std::endl;

    return 0;
}