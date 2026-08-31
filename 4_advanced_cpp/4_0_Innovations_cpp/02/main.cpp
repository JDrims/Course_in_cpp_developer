#include <iostream>
#include <vector>
#include <Windows.h>
#include <variant>

std::variant<int, std::string, std::vector<int>> get_variant()
{
    std::srand(std::time(nullptr));
    int random_variable = std::rand() % 3;

    std::variant<int, std::string, std::vector<int>> result;
    switch (random_variable)
    {
    case 0:
        result = 5;
        break;
    case 1:
        result = "string";
        break;
    case 2:
        result = std::vector<int>{1, 2, 3, 4, 5};
        break;
    default:
        break;
    }
    return result;
}

void print_vec(std::vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
        if (i < vec.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    auto rand_type = get_variant();

    if (std::holds_alternative<int>(rand_type))
        std::cout << (std::get<int>(rand_type) * 2) << std::endl;

    if (std::holds_alternative<std::string>(rand_type))
        std::cout << std::get<std::string>(rand_type) << std::endl;

    if (std::holds_alternative<std::vector<int>>(rand_type))
        print_vec(std::get<std::vector<int>>(rand_type));

    return 0;
}