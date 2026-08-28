#include <iostream>

void swap(int &, int &);

int main()
{
    int a = 5, b = 8;

    std::cout << "a = " << a << ", b = " << b << std::endl;

    swap(a, b);

    std::cout << "a = " << a << ", b = " << b << std::endl;

    return 0;
}

void swap(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}