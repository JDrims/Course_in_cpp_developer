#include <iostream>

int fun_pow(int, int);

int main(int argc, char **argv)
{
    int value = 5, power = 2, result;

    result = fun_pow(value, power);
    std::cout << value << " в степени " << power << " = " << result << std::endl;

    value = 3;
    power = 3;

    result = fun_pow(value, power);
    std::cout << value << " в степени " << power << " = " << result << std::endl;

    value = 4;
    power = 4;

    result = fun_pow(value, power);
    std::cout << value << " в степени " << power << " = " << result << std::endl;

    return 0;
}

int fun_pow(int value, int power)
{
    int result{1};
    for (int i = 0; i < power; i++)
    {
        result *= value;
    }
    return result;
}