#include <iostream>
#include <Windows.h>

int simple_string_hash(std::string str)
{
    int hash = 0;
    for (int i = 0; i < str.length(); i++)
        hash += str.at(i);

    return hash;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string command;
    do
    {
        std::cout << "Введите строку: ";
        std::cin >> command;
        std::cout << "Наивный хэш строки " << command << " = "
                  << simple_string_hash(command) << std::endl;

        if (command == "exit")
            break;
    } while (true);

    return 0;
}