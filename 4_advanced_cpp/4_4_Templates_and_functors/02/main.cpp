#include <iostream>
#include <vector>

template <class T>
class Table
{
    std::size_t rows;
    std::size_t cols;
    std::vector<std::vector<T>> double_arr;

public:
    Table(std::size_t rows, std::size_t cols) : double_arr(rows, std::vector<T>(cols)) {};

    std::vector<T> &operator[](std::size_t row)
    {
        return double_arr[row];
    }

    const std::vector<T> &operator[](std::size_t row) const
    {
        return double_arr[row];
    }

    std::pair<std::size_t, std::size_t> Size() const
    {
        if (double_arr.empty())
            return {0, 0};
        return {double_arr.size(), double_arr[0].size()};
    }
};

int main()
{
    auto test = Table<int>(2, 3);

    test[0][0] = 4;
    std::cout << test[0][0] << std::endl;

    const auto &ctest = test;
    std::cout << ctest[0][0] << std::endl;

    auto [rows, cols] = ctest.Size();
    std::cout << "(" << rows << ", " << cols << ")" << std::endl;

    return 0;
}