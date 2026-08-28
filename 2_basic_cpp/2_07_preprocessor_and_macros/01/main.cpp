#include <iostream>

#define MODE 1

#ifndef MODE
#error "Необходимо определить MODE"
#endif

#if MODE == 1
int add(int a, int b)
{
    return a + b;
}
#endif

int main()
{
#if MODE == 0
    std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1
    std::cout << "Работаю в боевом режиме" << std::endl;
    int a, b;
    std::cout << "Введите число 1: ";
    std::cin >> a;
    std::cout << "Введите число 2: ";
    std::cin >> b;
    std::cout << "Результат сложения: " << add(a, b) << std::endl;
#else
    std::cout << "Работаю в боевом режиме" << std::endl;
#endif

    return 0;
}