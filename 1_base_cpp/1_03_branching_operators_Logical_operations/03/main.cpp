#include <iostream>
#include <string>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char sex;
    std::string zodiac;
    int age;

    std::cout << "Введите пол: ";
    std::cin >> sex;
    std::cout << "Введите знак зодиака: ";
    std::cin >> zodiac;
    std::cout << "Введите возраст: ";
    std::cin >> age;
    std::cout << "Ваше предсказание: " << std::endl;

    if ((sex == 'М' || sex == 'м') && 
        (zodiac == "рак" || zodiac == "скорпион" || zodiac == "рыбы") &&
        (age < 40))
    {
        std::cout << "Сегодня очень плодотворный день. Можно добиться того, ";
        std::cout << "что прежде казалось почти невозможным." << std::endl;
    }
    else if ((sex == 'Ж' || sex == 'ж') &&
             (zodiac == "телец" || zodiac == "дева" || zodiac == "козерог") &&
             (age >= 15 && age <= 30))
    {
        std::cout << "Сегодняшний вечер подходит для общения с друзьями, проведения ";
        std::cout << "домашних праздников и импровизированных вечеринок. ";
        std::cout << "Будет не только весело, но и интересно: найдётся дело, которое ";
        std::cout << "увлечёт всех." << std::endl;
    }
    else
    {
        std::cout << "Гороскоп для вас находится в разработке. ";
        std::cout << "Приходите чуточку позже ;)" << std::endl;
    }

    return 0;
}