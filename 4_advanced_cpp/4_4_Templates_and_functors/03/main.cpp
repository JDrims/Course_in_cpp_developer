#include <iostream>
#include <vector>
#include <algorithm>

void print_vec(const std::vector<int> &vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (i)
            std::cout << " ";
        std::cout << vec[i];
    }
}

class Counter
{
    int sum = 0;
    int count = 0;

public:
    void operator()(int value)
    {
        if (value % 3 == 0)
        {
            sum += value;
            ++count;
        }
    }

    int get_sum()
    {
        return sum;
    }

    int get_count()
    {
        return count;
    }
};

int main()
{
    std::vector<int> vec = {4, 1, 3, 6, 25, 54};

    std::cout << "[IN]: ";
    print_vec(vec);
    std::cout << std::endl;

    Counter counter = std::for_each(vec.begin(), vec.end(), Counter());

    std::cout << "[OUT]: get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << counter.get_count() << std::endl;

    return 0;
}