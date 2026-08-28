#include <iostream>
#include <Windows.h>

int real_string_hash(std::string str, int p, int n)
{
    unsigned long long hash = 0;
    unsigned long long power = 1;

    for (int i = 0; i < str.length(); i++)
    {
        hash = (hash + (str.at(i) * power) % n) % n;
        power = (power * p) % n;
    }

    return hash;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Введите p: ";
    int p;
    std::cin >> p;

    std::cout << "Введите n: ";
    int n;
    std::cin >> n;

    std::string command;
    do
    {
        std::cout << "Введите строку: ";
        std::cin >> command;
        std::cout << "Наивный хэш строки " << command << " = "
                  << real_string_hash(command, p, n) << std::endl;

        if (command == "exit")
            break;
    } while (true);

    return 0;
}