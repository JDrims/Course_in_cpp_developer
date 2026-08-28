#include <windows.h>
#include <iostream>
#include "math_functions.h"

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	double num1, num2;
	int operation;

	std::cout << "Введите первое число: ";
	std::cin >> num1;

	std::cout << "Введите второе число: ";
	std::cin >> num2;

	std::cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	std::cin >> operation;

	double result = 0;
	bool valid = true;

	switch (operation)
	{
	case 1:
		result = add(num1, num2);
		std::cout << num1 << " + " << num2 << " = " << result;
		break;
	case 2:
		result = subtract(num1, num2);
		std::cout << num1 << " - " << num2 << " = " << result;
		break;
	case 3:
		result = multiply(num1, num2);
		std::cout << num1 << " * " << num2 << " = " << result;
		break;
	case 4:
		if (num2 != 0)
		{
			result = divide(num1, num2);
			std::cout << num1 << " / " << num2 << " = " << result;
		}
		else
		{
			std::cout << "Ошибка: деление на ноль!";
			valid = false;
		}
		break;
	case 5:
		result = power(num1, num2);
		std::cout << num1 << " в степени " << num2 << " = " << result;
		break;
	default:
		std::cout << "Неверный выбор операции!";
		valid = false;
	}

	if (valid && operation >= 1 && operation <= 5)
	{
		std::cout << std::endl;
	}

	return 0;
}