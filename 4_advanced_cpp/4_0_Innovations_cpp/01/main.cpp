#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

void print_vec(std::vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
        if (i < vec.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<int> vec = {4, 7, 9, 14, 12};

    print_vec(vec);

    std::for_each(vec.begin(), vec.end(),
                  [](int &v)
                  {
                      if (v % 2 != 0)
                          v *= 3;
                  });

    print_vec(vec);

    return 0;
}