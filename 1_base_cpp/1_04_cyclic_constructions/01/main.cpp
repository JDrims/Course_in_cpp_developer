#include <iostream>

int main()
{
    int num, sum{0};

    do
    {
        std::cout << "Введите целое число или число '0', чтобы закончить:" << std::endl;
        std::cin >> num;
        sum += num;
    } while (num);

    std::cout << "Сумма: " << sum << std::endl;

    return 0;
}