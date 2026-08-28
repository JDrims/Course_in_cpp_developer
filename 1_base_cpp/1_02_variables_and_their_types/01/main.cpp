#include <iostream>

int main()
{
  std::cout << "Введите число:" << std::endl;
  int num;
  std::cin >> num;
  std::cout << "Вы ввели:\n"
            << num << std::endl;

  return 0;
}