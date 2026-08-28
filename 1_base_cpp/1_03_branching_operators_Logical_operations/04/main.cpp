#include <iostream>
#include <string>

int main()
{
    int tens{0}, units{0};
    int num1, num2;
    int m_num1, m_num2;
    std::string result{};

    std::cout << "Введите целое число: ";
    std::cin >> num1;
    std::cout << "Введите целое число: ";
    std::cin >> num2;

    if (!((num1 > -100) && (num1 < 100) && (num2 > -100) && (num2 < 100)))
    {
        std::cout << "Ошибка! Одно из чисел вне диапазона!" << std::endl;
    }
    else
    {
        m_num1 = num1;
        m_num2 = num2;

        if (num1 == 0)
            result += "ноль";

        if (num1 < 0)
        {
            result += "минус ";
            num1 = -num1;
        }

        tens = num1 / 10;
        units = num1 % 10;

        switch (tens)
        {
        case 2:
            result += "двадцать";
            break;
        case 3:
            result += "тридцать";
            break;
        case 4:
            result += "сорок";
            break;
        case 5:
            result += "пятьдесят";
            break;
        case 6:
            result += "шестьдесят";
            break;
        case 7:
            result += "семьдесят";
            break;
        case 8:
            result += "восемьдесят";
            break;
        case 9:
            result += "девяносто";
            break;
        }

        if (tens == 1)
        {
            switch (units)
            {
            case 0:
                result += "десять";
                break;
            case 1:
                result += "одиннадцать";
                break;
            case 2:
                result += "двенадцать";
                break;
            case 3:
                result += "тринадцать";
                break;
            case 4:
                result += "четырнадцать";
                break;
            case 5:
                result += "пятнадцать";
                break;
            case 6:
                result += "шестнадцать";
                break;
            case 7:
                result += "семнадцать";
                break;
            case 8:
                result += "восемнадцать";
                break;
            case 9:
                result += "девятнадцать";
                break;
            }
        }
        else
        {
            if (tens > 0 && units > 0)
                result += " ";
            switch (units)
            {
            case 1:
                result += "один";
                break;
            case 2:
                result += "два";
                break;
            case 3:
                result += "три";
                break;
            case 4:
                result += "четыре";
                break;
            case 5:
                result += "пять";
                break;
            case 6:
                result += "шесть";
                break;
            case 7:
                result += "семь";
                break;
            case 8:
                result += "восемь";
                break;
            case 9:
                result += "девять";
                break;
            }
        }

        if (m_num1 > m_num2)
        {
            result += " больше чем ";
        }
        else if (m_num1 < m_num2)
        {
            result += " меньше чем ";
        }
        else
        {
            result += " равно ";
        }

        if (num2 == 0)
            result += "ноль";
        if (num2 < 0)
        {
            result += "минус ";
            num2 = -num2;
        }

        tens = num2 / 10;
        units = num2 % 10;

        switch (tens)
        {
        case 2:
            result += "двадцать";
            break;
        case 3:
            result += "тридцать";
            break;
        case 4:
            result += "сорок";
            break;
        case 5:
            result += "пятьдесят";
            break;
        case 6:
            result += "шестьдесят";
            break;
        case 7:
            result += "семьдесят";
            break;
        case 8:
            result += "восемьдесят";
            break;
        case 9:
            result += "девяносто";
            break;
        }

        if (tens == 1)
        {
            switch (units)
            {
            case 0:
                result += "десять";
                break;
            case 1:
                result += "одиннадцать";
                break;
            case 2:
                result += "двенадцать";
                break;
            case 3:
                result += "тринадцать";
                break;
            case 4:
                result += "четырнадцать";
                break;
            case 5:
                result += "пятнадцать";
                break;
            case 6:
                result += "шестнадцать";
                break;
            case 7:
                result += "семнадцать";
                break;
            case 8:
                result += "восемнадцать";
                break;
            case 9:
                result += "девятнадцать";
                break;
            }
        }
        else
        {
            if (tens > 0 && units > 0)
                result += " ";
            switch (units)
            {
            case 1:
                result += "один";
                break;
            case 2:
                result += "два";
                break;
            case 3:
                result += "три";
                break;
            case 4:
                result += "четыре";
                break;
            case 5:
                result += "пять";
                break;
            case 6:
                result += "шесть";
                break;
            case 7:
                result += "семь";
                break;
            case 8:
                result += "восемь";
                break;
            case 9:
                result += "девять";
                break;
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}