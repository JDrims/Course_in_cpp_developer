#include <iostream>
#include <string>

int main()
{
    std::string word;
    std::string secret_word = "малина";
    bool win;

    do
    {
        win = false;

        std::cout << "Угадайте слово: ";
        std::cin >> word;

        if (word == secret_word)
        {
            win = true;
        }
        else
        {
            std::cout << "Неправильно" << std::endl;
        }
    } while (!win);

    std::cout << "Правильно! Вы победили! Загаданное слово — малина" << std::endl;

    return 0;
}