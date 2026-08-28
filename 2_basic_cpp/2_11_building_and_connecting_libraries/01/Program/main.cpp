#include <iostream>
#include <string>
#include <Greeter.h>
#include <Windows.h>

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	std::cout << "Введите имя: ";
	std::string str;
	std::cin >> str;
	Greeter greeter;
	std::cout << greeter.greet(str) << std::endl;

	return 0;
}