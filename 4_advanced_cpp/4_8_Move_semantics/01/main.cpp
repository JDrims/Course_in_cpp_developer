#include <iostream>
#include <vector>
#include <string>

template <typename T>
void move_vectors(T &vec, T &vec_src)
{
    if (&vec != &vec_src)
        vec = std::move(vec_src);
}

template <typename T>
void print_vector(const T &vec)
{
    for (auto &v : vec)
        std::cout << v << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> one = {"test_string1", "test_string2"};
    std::vector<std::string> two;

    std::cout << "one = ";
    print_vector(one);
    std::cout << "two = ";
    print_vector(two);

    move_vectors(two, one);

    std::cout << "one = ";
    print_vector(one);
    std::cout << "two = ";
    print_vector(two);

    return 0;
}