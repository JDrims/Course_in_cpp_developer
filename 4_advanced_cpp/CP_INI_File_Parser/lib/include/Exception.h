#pragma once

#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>

class ini_error : public std::runtime_error
{
public:
    explicit ini_error(const std::string &message)
        : std::runtime_error(message) {}

    virtual const char *what() const noexcept override
    {
        return std::runtime_error::what();
    }
};

class ini_file_error : public ini_error
{
    std::string path_;

public:
    explicit ini_file_error(const std::string &path)
        : ini_error("Не удалось открыть файл: " + path),
          path_(path) {}

    const std::string &path() const { return path_; }
};

class ini_syntax_error : public ini_error
{
    int line_;

public:
    ini_syntax_error(int line, const std::string &message)
        : ini_error("Строка " + std::to_string(line) + ": " + message),
          line_(line) {}

    int line() const { return line_; }
};

class ini_section_not_found : public ini_error
{
    std::string section_;

public:
    explicit ini_section_not_found(const std::string &section)
        : ini_error("Секция '" + section + "' не найдена"),
          section_(section) {}

    const std::string &section() const { return section_; }
};

class ini_key_not_found : public ini_error
{
    static std::string make_message(const std::string &section,
                                    const std::string &key)
    {
        std::string msg = "Ключ '" + key + "' не найден в секции '" + section + "'";
        return msg;
    }

    std::string section_;
    std::string key_;

public:
    ini_key_not_found(const std::string &section,
                      const std::string &key)
        : ini_error(make_message(section, key)),
          section_(section),
          key_(key) {}

    const std::string &section() const { return section_; }
    const std::string &key() const { return key_; }
};

class ini_conversion_error : public ini_error
{
    std::string section_;
    std::string key_;
    std::string value_;

public:
    ini_conversion_error(const std::string &section,
                         const std::string &key,
                         const std::string &value)
        : ini_error("Не удалось преобразовать значение '" + value +
                    " для ключа '" + section + "." + key + "'"),
          section_(section),
          key_(key),
          value_(value) {}

    const std::string &section() const { return section_; }
    const std::string &key() const { return key_; }
    const std::string &value() const { return value_; }
};