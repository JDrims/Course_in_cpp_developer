#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream inFile("in.txt");

    if (!inFile.is_open())
    {
        std::cerr << "Ошибка: не удалось открыть файл in.txt" << std::endl;
        return 1;
    }

    std::string word;

    while (inFile >> word)
    {
        std::cout << word << std::endl;
    }

    inFile.close();

    return 0;
}