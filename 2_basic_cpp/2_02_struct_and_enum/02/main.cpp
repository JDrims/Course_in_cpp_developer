#include <iostream>
#include <string>

struct sAccount
{
    int accNumber;
    std::string name;
    double numMoney;
};

void changeMoney(sAccount &account, double newMoney);
void printAccountInfo(const sAccount &account);

int main()
{
    sAccount account;
    double newMoney;

    std::cout << "Введите номер счёта: ";
    std::cin >> account.accNumber;

    std::cout << "Введите имя владельца: ";
    std::cin >> account.name;

    std::cout << "Введите новый баланс: ";
    std::cin >> account.numMoney;

    std::cout << "Введите новый баланс: ";
    std::cin >> newMoney;

    changeMoney(account, newMoney);
    printAccountInfo(account);

    return 0;
}

void changeMoney(sAccount &account, double newMoney)
{
    account.numMoney = newMoney;
}

void printAccountInfo(const sAccount &account)
{
    std::cout << "Ваш счёт: " << account.name
              << ", " << account.accNumber
              << ", " << account.numMoney
              << std::endl;
}