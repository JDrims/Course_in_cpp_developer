#include <iostream>

int main()
{
    int num1, num2, num3;

    std::cout << "Введите первое число: " << std::endl;
    std::cin >> num1;
    std::cout << "Введите второе  число: " << std::endl;
    std::cin >> num2;
    std::cout << "Введите третье  число: " << std::endl;
    std::cin >> num3;
    std::cout << std::endl;

    int max = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);
    int min = (num1 < num2) ? ((num1 < num3) ? num1 : num3) : ((num2 < num3) ? num2 : num3);
    int mid = num1 + num2 + num3 - max - min;

    std::cout << "Результат: " << max << " " << mid << " " << min << std::endl;

    return 0;
}