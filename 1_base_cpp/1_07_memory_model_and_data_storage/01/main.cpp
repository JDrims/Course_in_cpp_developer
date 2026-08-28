#include <iostream>

int main()
{
    int i_val;
    short sh_val;
    long l_val;
    long long ll_va;
    float f_val;
    double d_val;
    long double ld_val;
    bool b_val;

    std::cout << "int: " << &i_val << " " << sizeof(i_val) << std::endl;
    std::cout << "short: " << &sh_val << " " << sizeof(sh_val) << std::endl;
    std::cout << "long: " << &l_val << " " << sizeof(l_val) << std::endl;
    std::cout << "long long: " << &ll_va << " " << sizeof(ll_va) << std::endl;
    std::cout << "float: " << &f_val << " " << sizeof(f_val) << std::endl;
    std::cout << "double: " << &d_val << " " << sizeof(d_val) << std::endl;
    std::cout << "long double: " << &ld_val << " " << sizeof(ld_val) << std::endl;
    std::cout << "bool: " << &b_val << " " << sizeof(b_val) << std::endl;

    return 0;
}