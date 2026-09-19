#include <iostream>
#include <set>
#include <functional>

int main()
{
    std::cout << "[IN]: " << std::endl;
    int count;
    std::cin >> count;

    std::set<int, std::greater<int>> containers;
    for (size_t i = 0; i < count; i++)
    {
        int num;
        std::cin >> num;
        containers.insert(num);
    }

    std::cout << "[OUT]: " << std::endl;
    for (auto &n : containers)
        std::cout << n << std::endl;

    return 0;
}