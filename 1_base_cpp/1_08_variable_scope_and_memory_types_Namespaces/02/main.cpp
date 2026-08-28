#include <iostream>

namespace sum
{
    int calc(int x, int y)
    {
        return x + y;
    }
}

namespace diff
{
    int calc(int x, int y)
    {
        return x - y;
    }
}

namespace mult
{
    int calc(int x, int y)
    {
        return x * y;
    }
}

namespace divv
{
    int calc(int x, int y)
    {
        return x / y;
    }
}

int main()
{
    int x = 6, y = 9;
    std::cout << "Сложение: " << sum::calc(x, y) << std::endl;
    std::cout << "Вычитание: " << diff::calc(x, y) << std::endl;
    std::cout << "Умножение: " << divv::calc(x, y) << std::endl;
    std::cout << "Деление: " << divv::calc(x, y) << std::endl;

    return 0;
}