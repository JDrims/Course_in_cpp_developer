#include <iostream>
#include <Windows.h>

const int MAX_MEM = 100;
int mem[MAX_MEM];

int fibonacci(int num) // Memory O(n)
{
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;
    if (mem[num] != -1)
        return mem[num];
    mem[num] = fibonacci(num - 1) + fibonacci(num - 2);
    return mem[num];
}

// int fibonacci(int num) //Memory O(1)
// {
//     int sum = 0;
//     int cur = 1;
//     for (int i = 0; i < num; i++)
//     {
//         int temp = cur;
//         cur = sum + cur;
//         sum = temp;
//     }
//     return sum;
// }

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    for (int i = 0; i < MAX_MEM; ++i)
        mem[i] = -1;

    int num;
    std::cout << "Введите номер числа Фибоначчи(n): ";
    std::cin >> num;
    std::cout << "Фибоначчи(" << num << ") = " << fibonacci(num) << std::endl;
    return 0;
}