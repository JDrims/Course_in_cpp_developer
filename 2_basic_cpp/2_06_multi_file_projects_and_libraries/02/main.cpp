#include <Windows.h>
#include <string>
#include "Counter.h"

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	Counter counter;
	std::string yesNo;
	int initValue;
	char cmd;

	std::cout << "Вы хотите указать начальное значение счётчика? "
		<< "Введите да или нет: ";
	std::cin >> yesNo;

	if (yesNo == "да")
	{
		std::cout << "Введите начальное значение счётчика: ";
		std::cin >> initValue;
		counter = Counter(initValue);
	}
	else
	{
		counter = Counter();
	}

	do
	{
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> cmd;

		switch (cmd)
		{
		case '+':
			counter.increaseNum();
			break;
		case '-':
			counter.reduceNum();
			break;
		case '=':
			counter.printCurrentNumber();
			break;
		}

	} while (cmd != 'x');

	std::cout << "До свидания!" << std::endl;

	return 0;
}