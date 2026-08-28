#include <iostream>
#include <string>

int main()
{
  std::cout << "Введите слово:" << std::endl;
  std::string words{};
  std::cin >> words;
  std::cout << "Вы ввели:\n"
            << words << std::endl;
            
  return 0;
}