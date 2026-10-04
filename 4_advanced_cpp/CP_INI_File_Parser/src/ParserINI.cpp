#include "ParserINI.h"

#include <algorithm>
#include <iostream>

ParserINI::ParserINI(const std::string &fileName) : fileName(fileName)
{
    if (fileName == "")
        throw ini_error("Имя файла не может быть пустым");

    file.open(fileName);

    if (!file.is_open())
        throw ini_file_error(fileName);

    readFile();
}

ParserINI::~ParserINI()
{
    file.close();
}

void ParserINI::readFile()
{
    std::string line;
    int numLines = 0;
    bool in_section = false;
    std::string nameSection;

    while (!file.eof())
    {
        numLines++;
        std::getline(file, line);

        line.erase(std::find_if(line.begin(), line.end(), [](char c)
                                { return c == ';'; }),
                   line.end());

        line = trim(line);

        if (line.empty() || line[0] == ';')
            continue;

        if (line[0] == '[')
        {
            if (line.find(']') == std::string::npos)
                throw ini_syntax_error(numLines, "не закрыта скобка секции");

            if (line.find(']') != line.length() - 1)
                throw ini_syntax_error(numLines, "лишние символы после скобки");

            nameSection = line;
            nameSection.erase(std::remove_if(nameSection.begin(), nameSection.end(), [](char c)
                                             { return c == '[' || c == ']'; }),
                              nameSection.end());
            nameSection = trim(nameSection);
            if (nameSection.empty())
                throw ini_syntax_error(numLines, "пустое имя секции");

            in_section = true;

            data_struct[nameSection];
        }
        else if (line.find('=') != std::string::npos)
        {
            std::string key = line.substr(0, line.find('='));
            std::string value = line.substr(line.find('=') + 1);

            key = trim(key);
            value = trim(value);

            if (key.empty())
                throw ini_syntax_error(numLines, "пустое имя переменной");

            if (!in_section)
                throw ini_syntax_error(numLines, "переменная вне секции");

            data_struct[nameSection][key] = value;
        }
        else
        {
            throw ini_syntax_error(numLines, "ошибка синтаксиса");
        }
    }
}

std::string trim(const std::string &line)
{
    auto start = line.begin();
    while (start != line.end() && std::isspace(static_cast<unsigned char>(*start)))
        start++;

    auto end = line.end();
    while (end != start && std::isspace(static_cast<unsigned char>(*(end - 1))))
        end--;

    return std::string(start, end);
}