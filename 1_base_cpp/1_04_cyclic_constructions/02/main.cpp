#include <iostream>

int main()
{
    int number;

    std::cout << "Введите целое число:" << std::endl;
    std::cin >> number;

    if (number < 0)
    {
        number = -number;
    }

    int sum = 0;

    while (number > 0)
    {
        int lastDigit = number % 10;
        sum += lastDigit;
        number /= 10;
    }

    std::cout << "Сумма цифр: " << sum << std::endl;

    return 0;
}