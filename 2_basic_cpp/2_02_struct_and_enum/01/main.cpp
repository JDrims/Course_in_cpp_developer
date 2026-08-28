#include <iostream>
#include <string>

enum class eMouth
{
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

std::string enumMouthToMouthStr(int mouthNum);

int main()
{
    int numMouuth = 0;
    std::string strMouuth = "";
    do
    {
        std::cout << "Введите номер месяца: ";
        std::cin >> numMouuth;
        if (numMouuth != 0)
        {
            strMouuth = enumMouthToMouthStr(numMouuth);
            if (strMouuth != "") std::cout << strMouuth << std::endl;
        }
    } while (numMouuth != 0);
    std::cout << "До свидания";

    return 0;
}

std::string enumMouthToMouthStr(int mouthNum)
{
    switch (static_cast<eMouth>(mouthNum))
    {
    case eMouth::JANUARY:
        return "Январь";
    case eMouth::FEBRUARY:
        return "Февраль";
    case eMouth::MARCH:
        return "Март";
    case eMouth::APRIL:
        return "Апрель";
    case eMouth::MAY:
        return "Май";
    case eMouth::JUNE:
        return "Июнь";
    case eMouth::JULY:
        return "Июль";
    case eMouth::AUGUST:
        return "Август";
    case eMouth::SEPTEMBER:
        return "Сентябрь";
    case eMouth::OCTOBER:
        return "Октябрь";
    case eMouth::NOVEMBER:
        return "Ноябрь";
    case eMouth::DECEMBER:
        return "Декабрь";
    default:
        return "Неправильный номер!";
    }
}