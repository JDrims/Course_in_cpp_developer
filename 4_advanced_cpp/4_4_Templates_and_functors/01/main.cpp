#include <iostream>
#include <vector>

void print_vec(const std::vector<int> &vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (i)
            std::cout << ", ";
        std::cout << vec[i];
    }
}

template <typename T>
T square(const T &a)
{
    return a * a;
}

template <typename T>
std::vector<T> square(const std::vector<T> &vec)
{
    std::vector<T> new_vec;
    for (auto &&v : vec)
        new_vec.push_back(v * v);
    return new_vec;
}

int main()
{
    int a = 4;
    std::cout << "[IN] " << a << std::endl;
    int a_sq = square(a);
    std::cout << "[OUT] " << a_sq << std::endl;

    std::vector<int> vec = {-1, 4, 8};
    std::cout << "[IN] ";
    print_vec(vec);
    std::cout << std::endl;
    std::vector<int> vec_sq = square(vec);
    std::cout << "[OUT] ";
    print_vec(vec_sq);
    std::cout << std::endl;

    return 0;
}