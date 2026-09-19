#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

int main()
{
    std::string str = "Hello world!!";
    std::cout << "[IN]: " << str << std::endl;

    std::map<char, int> freq;
    for (char ch : str)
        freq[ch]++;
    std::vector<std::pair<char, int>> vec(freq.begin(), freq.end());
    std::sort(vec.begin(), vec.end(), [](const auto &a, const auto &b)
              { if (a.second != b.second) return a.second > b.second;
                  return a.first < b.first; });

    std::cout << "[OUT]: " << std::endl;
    for (const auto &[ch, count] : vec)
        std::cout << ch << ": " << count << std::endl;

    return 0;
}