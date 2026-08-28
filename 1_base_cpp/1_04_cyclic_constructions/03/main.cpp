#include <iostream>

int main()
{
    int number;

    std::cout << "Введите целое число:" << std::endl;
    std::cin >> number;

    int count = 10;

    for (int i = 1; i <= count; i++)
    {
        std::cout << number << " x " << i << " = " << number * i << std::endl;
    }

    return 0;
}