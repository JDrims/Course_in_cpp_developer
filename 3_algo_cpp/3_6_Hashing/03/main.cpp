#include <iostream>
#include <Windows.h>

long long simple_string_hash(std::string str)
{
    long long hash = 0;
    for (int i = 0; i < str.length(); i++)
        hash += str.at(i);

    return hash;
}

int find_substring_light_rabin_karp(const std::string &source_str, const std::string &search_str)
{
    int source_size = source_str.size();
    int search_size = search_str.size();

    if (search_size == 0)
        return 0;
    if (search_size > source_size)
        return -1;

    long long hash_search_str = simple_string_hash(search_str);
    long long word_hash = 0;

    for (int i = 0; i < search_size; i++)
        word_hash += source_str.at(i);

    for (int i = 0; i < source_size - search_size + 1; i++)
    {
        if (word_hash == hash_search_str &&
            source_str.compare(i, search_size, search_str) == 0)
        {
            return i;
        }
        else if (i < source_size - search_size)
        {
            word_hash -= source_str.at(i);
            word_hash += source_str.at(i + search_size);
        }
    }

    return -1;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::string source_str;
    std::cin >> source_str;

    do
    {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::string search_str;
        std::cin >> search_str;

        int index = find_substring_light_rabin_karp(source_str, search_str);

        if (index != -1)
        {
            std::cout << "Подстрока " << search_str << " найдена по индексу "
                      << index << std::endl;
        }
        else
        {
            std::cout << "Подстрока " << search_str << " не найдена" << std::endl;
        }

        if (search_str == "exit")
            break;
    } while (true);

    return 0;
}