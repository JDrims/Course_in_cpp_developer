#include "Exception.h"

#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <cctype>
#include <algorithm>

std::string trim(const std::string &line);

class ParserINI
{
    std::map<std::string, std::map<std::string, std::string>> data_struct;
    std::string fileName;
    std::fstream file;

    void readFile();

    template <typename T>
    T convert(const std::string &value, const std::string &section, const std::string &key)
    {
        if constexpr (std::is_same_v<T, std::string>)
        {
            return value;
        }
        else
        {
            std::istringstream iss(value);
            T result;
            iss >> result;
            if (iss.fail() || !iss.eof())
                throw ini_conversion_error(section, key, value);
            return result;
        }
    }

public:
    explicit ParserINI(const std::string &fileName);
    ~ParserINI();

    template <typename T>
    T get_value(const std::string &path)
    {
        if (path == "")
            throw ini_error("Путь не может быть пустым");

        auto dot = path.find('.');
        if (dot == 0 || dot == path.size() - 1)
            throw ini_error("Пустая секция или ключ в пути");

        std::string section = path.substr(0, dot);
        std::string key = path.substr(dot + 1);

        auto section_it = data_struct.find(section);
        if (section_it == data_struct.end())
            throw ini_section_not_found(section);

        auto key_it = section_it->second.find(key);
        if (key_it == section_it->second.end())
            throw ini_key_not_found(section, key);

        std::string value = key_it->second;

        return convert<T>(value, section, key);
    }
};