#include <iostream>

int main()
{
    std::cout << "Оператор: ||" << std::endl;
    std::cout << "true\t"  << "true\t"  << ((true  || true ) ? "true" :  "false") << std::endl;
    std::cout << "false\t" << "true\t"  << ((false || true ) ? "true" :  "false") << std::endl;
    std::cout << "true\t"  << "false\t" << ((true  || false) ? "true" :  "false") << std::endl;
    std::cout << "false\t" << "false\t" << ((false || false) ? "true" :  "false") << std::endl;

    std::cout << std::endl;

    std::cout << "Оператор: &&" << std::endl;
    std::cout << "true\t"  << "true\t"  << ((true  && true ) ? "true" :  "false") << std::endl;
    std::cout << "false\t" << "true\t"  << ((false && true ) ? "true" :  "false") << std::endl;
    std::cout << "true\t"  << "false\t" << ((true  && false) ? "true" :  "false") << std::endl;
    std::cout << "false\t" << "false\t" << ((false && false) ? "true" :  "false") << std::endl;

    return 0;
}