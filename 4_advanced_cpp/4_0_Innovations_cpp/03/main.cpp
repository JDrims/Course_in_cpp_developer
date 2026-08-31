#include <iostream>
#include <Windows.h>
#include <vector>
#include <functional>
#include <cmath>

int main()
{
    const double PI = 3.141592653589793;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<double> angles = {
        30.0 * PI / 180.0,
        60.0 * PI / 180.0,
        90.0 * PI / 180.0};

    std::vector<std::function<void(double)>> functions;

    functions.push_back([](double angle)
                        { std::cout << "sin: " << std::sin(angle) << " "; });

    functions.push_back([](double angle)
                        { std::cout << "cos: " << std::cos(angle) << " "; });

    for (const auto &angle : angles)
    {
        std::cout << angle << ": ";
        for (const auto &function : functions)
            function(angle);
        std::cout << std::endl;
    }

    return 0;
}