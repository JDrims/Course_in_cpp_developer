#include <iostream>

class Calculator
{
    double num1;
    double num2;

public:
    double add();
    double multiply();
    double subtract_1_2();
    double subtract_2_1();
    double divide_1_2();
    double divide_2_1();
    bool set_num1(double num1);
    bool set_num2(double num2);
};

int main()
{
    do
    {
        double num1 = 1;
        double num2 = 1;
        Calculator calculator;

        do
        {
            if (!calculator.set_num1(num1))
                std::cout << "Неверный ввод!" << std::endl;
            std::cout << "Введите num1: ";
            std::cin >> num1;
        } while (!calculator.set_num1(num1));

        do
        {
            if (!calculator.set_num2(num2))
                std::cout << "Неверный ввод!" << std::endl;
            std::cout << "Введите num2: ";
            std::cin >> num2;
        } while (!calculator.set_num2(num2));

        std::cout << "num1 + num2 = " << calculator.add() << std::endl;
        std::cout << "num1 - num2 = " << calculator.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calculator.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calculator.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calculator.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calculator.divide_2_1() << std::endl;

    } while (1);

    return 0;
}

double Calculator::add()
{
    return this->num1 + this->num2;
}

double Calculator::multiply()
{
    return this->num1 * this->num2;
}

double Calculator::subtract_1_2()
{
    return this->num1 - this->num2;
}

double Calculator::subtract_2_1()
{
    return this->num2 - this->num1;
}

double Calculator::divide_1_2()
{
    return this->num1 / this->num2;
}

double Calculator::divide_2_1()
{
    return this->num2 / this->num1;
}

bool Calculator::set_num1(double num1)
{
    if (num1 != 0)
        this->num1 = num1;

    return (num1 != 0);
}

bool Calculator::set_num2(double num2)
{
    if (num2 != 0)
        this->num2 = num2;

    return (num2 != 0);
}