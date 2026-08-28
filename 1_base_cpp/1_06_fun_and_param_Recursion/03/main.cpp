#include <iostream>

int fibonacci(int);

int main()
{
    int number;

    std::cout << "Введите число: ";
    std::cin >> number;

    std::cout << "Числа Фибоначчи: ";
    if (number <= 0)
    {
        return 0;
    }

    for (int i = 0; i < number; i++)
    {
        std::cout << fibonacci(i);
        if (i < number - 1)
        {
            std::cout << " ";
        }
    }

    return 0;
}

int fibonacci(int number)
{
    if (number <= 0)
        return 0;
    if (number == 1)
        return 1;
    return fibonacci(number - 1) + fibonacci(number - 2);
}