#include <iostream>
#include <Windows.h>

int fibonacci(int num)
{
    if (num <= 1)
        return num;
    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int num;
    std::cout << "Введите номер числа Фибоначчи(n): ";
    std::cin >> num;
    std::cout << "Фибоначчи(" << num << ") = " << fibonacci(num) << std::endl;
    return 0;
}