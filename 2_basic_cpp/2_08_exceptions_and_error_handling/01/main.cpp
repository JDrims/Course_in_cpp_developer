#include <iostream>
#include <string>
#include <exception>
#include <windows.h>

class bad_length : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Вы ввели слово запретной длины! До свидания";
    }
};

int function(std::string str, int forbidden_length)
{
    int len = str.length();
    if (len == forbidden_length)
    {
        throw bad_length();
    }
    return len;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int forbidden;
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden;

    std::string word;
    while (true)
    {
        std::cout << "Введите слово: ";
        std::cin >> word;
        try
        {
            int length = function(word, forbidden);
            std::cout << "Длина слова \"" << word << "\" равна " << length << std::endl;
        }
        catch (const bad_length &e)
        {
            std::cout << e.what() << std::endl;
            break;
        }
    }

    return 0;
}