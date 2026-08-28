#include <iostream>
#include <string>
#include <Leaver.h>
#include <Windows.h>

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	std::cout << "Введите имя: ";
	std::string str;
	std::cin >> str;
	Leaver leaver;
	std::cout << leaver.leave(str) << std::endl;

	return 0;
}