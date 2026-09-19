#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <string>

template <typename T>
void print_container(const T &containers)
{
    for (auto &elem : containers)
        std::cout << elem << " ";
    std::cout << std::endl;
}

int main()
{
    std::set<std::string> test_set = {"one", "two", "three", "four"};
    print_container(test_set);

    std::list<std::string> test_list = {"one", "two", "three", "four"};
    print_container(test_list);

    std::vector<std::string> test_vector = {"one", "two", "three", "four"};
    print_container(test_vector);

    return 0;
}