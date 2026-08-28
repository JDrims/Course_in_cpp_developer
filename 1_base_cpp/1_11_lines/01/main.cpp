#include <iostream>
#include <string>

int main()
{
    std::string name, surname;

    std::cout << "Введите имя: ";
    std::cin >> name;

    std::cout << "Введите фамилию: ";
    std::cin >> surname;

    std::string name_surname = name + " " + surname;

    std::cout << "Здравствуйте, " << name_surname << "!" << std::endl;

    return 0;
}