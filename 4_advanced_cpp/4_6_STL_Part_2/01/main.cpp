#include <iostream>
#include <vector>
#include <algorithm>

void remove_duplicates(std::vector<int> &containers)
{
    std::sort(containers.begin(), containers.end());
    auto it = std::unique(containers.begin(), containers.end());
    containers.erase(it, containers.end());
}

int main()
{
    std::vector<int> vec = {1, 1, 2, 5, 6, 1, 2, 4};
    std::cout << "[IN]: ";
    std::for_each(vec.begin(), vec.end(), [](const int &elem)
                  { std::cout << elem << " "; });
    std::cout << std::endl;

    remove_duplicates(vec);

    std::cout << "[OUT]: ";
    std::for_each(vec.begin(), vec.end(), [](const int &elem)
                  { std::cout << elem << " "; });
    std::cout << std::endl;

    return 0;
}