#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cmath>
#include <functional>

#include "ParserINI.h"

static int g_passed = 0;
static int g_failed = 0;

void run_test(const std::string &name, const std::function<void()> &body)
{
    try
    {
        body();
        std::cout << "[ OK ] " << name << "\n";
        ++g_passed;
    }
    catch (const std::exception &e)
    {
        std::cout << "[FAIL] " << name << ": " << e.what() << "\n";
        ++g_failed;
    }
}

void expect_true(bool cond, const std::string &msg)
{
    if (!cond)
        throw std::runtime_error("Ожидалось true: " + msg);
}

void expect_eq_int(int actual, int expected, const std::string &msg)
{
    if (actual != expected)
    {
        throw std::runtime_error(
            msg + ": ожидалось " + std::to_string(expected) +
            ", получено " + std::to_string(actual));
    }
}

void expect_eq_double(double actual, double expected, const std::string &msg)
{
    if (std::fabs(actual - expected) > 1e-9)
    {
        throw std::runtime_error(
            msg + ": ожидалось " + std::to_string(expected) +
            ", получено " + std::to_string(actual));
    }
}

void expect_eq_str(const std::string &actual,
                   const std::string &expected,
                   const std::string &msg)
{
    if (actual != expected)
    {
        throw std::runtime_error(
            msg + ": ожидалось '" + expected + "', получено '" + actual + "'");
    }
}

template <typename E>
void expect_throw(const std::function<void()> &body, const std::string &msg)
{
    try
    {
        body();
    }
    catch (const E &)
    {
        return;
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error(msg + ": поймано не то исключение: " + e.what());
    }
    throw std::runtime_error(msg + ": исключение не брошено");
}

std::string make_file(const std::string &path, const std::string &content)
{
    std::ofstream f(path, std::ios::binary);
    if (!f.is_open())
        throw std::runtime_error("Не удалось создать " + path);
    f << content;
    f.close();
    return path;
}

void remove_file(const std::string &path)
{
    std::remove(path.c_str());
}

// ========== Тесты ==========

void test_read_int()
{
    const std::string path = "test_int.ini";
    make_file(path, "[S]\nx=42\n");

    ParserINI parser(path);
    int v = parser.get_value<int>("S.x");
    expect_eq_int(v, 42, "S.x");

    remove_file(path);
}

void test_read_double()
{
    const std::string path = "test_double.ini";
    make_file(path, "[S]\nx=3.14\n");

    ParserINI parser(path);
    double v = parser.get_value<double>("S.x");
    expect_eq_double(v, 3.14, "S.x");

    remove_file(path);
}

void test_read_string_with_spaces()
{
    const std::string path = "test_str.ini";
    make_file(path, "[S]\nx=hello world\n");

    ParserINI parser(path);
    std::string v = parser.get_value<std::string>("S.x");
    expect_eq_str(v, "hello world", "S.x");

    remove_file(path);
}

void test_repeated_section_overwrites()
{
    const std::string path = "test_repeat.ini";
    make_file(path, "[S]\nx=1\n[S]\nx=2\n");

    ParserINI parser(path);
    int v = parser.get_value<int>("S.x");
    expect_eq_int(v, 2, "S.x после перезаписи");

    remove_file(path);
}

void test_inline_comment()
{
    const std::string path = "test_inline.ini";
    make_file(path, "[S]\nx=5 ; comment\n");

    ParserINI parser(path);
    int v = parser.get_value<int>("S.x");
    expect_eq_int(v, 5, "S.x с inline-комментарием");

    remove_file(path);
}

void test_empty_value_as_string()
{
    const std::string path = "test_empty.ini";
    make_file(path, "[S]\nMode=\n");

    ParserINI parser(path);
    std::string v = parser.get_value<std::string>("S.Mode");
    expect_eq_str(v, "", "S.Mode пустое");

    remove_file(path);
}

void test_empty_value_as_int_throws()
{
    const std::string path = "test_empty_int.ini";
    make_file(path, "[S]\nMode=\n");

    ParserINI parser(path);
    expect_throw<ini_conversion_error>([&]()
                                       { parser.get_value<int>("S.Mode"); }, "S.Mode как int");

    remove_file(path);
}

void test_section_not_found()
{
    const std::string path = "test_no_section.ini";
    make_file(path, "[S]\nx=1\n");

    ParserINI parser(path);
    expect_throw<ini_section_not_found>([&]()
                                        { parser.get_value<int>("T.x"); }, "T.x — секции нет");

    remove_file(path);
}

void test_key_not_found()
{
    const std::string path = "test_no_key.ini";
    make_file(path, "[S]\na=1\nb=2\n");

    ParserINI parser(path);
    expect_throw<ini_key_not_found>([&]()
                                    { parser.get_value<int>("S.c"); }, "S.c — ключа нет");

    remove_file(path);
}

void test_syntax_error_line_number()
{
    const std::string path = "test_syntax.ini";
    // Ошибка на строке 3
    make_file(path, "[S]\nx=1\n[]\ny=2\n");

    bool caught = false;
    try
    {
        ParserINI parser(path);
    }
    catch (const ini_syntax_error &e)
    {
        caught = true;
        expect_eq_int(e.line(), 3, "номер строки ошибки");
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error(std::string("Не то исключение: ") + e.what());
    }
    if (!caught)
        throw std::runtime_error("ini_syntax_error не брошен");

    remove_file(path);
}

void test_file_not_found()
{
    expect_throw<ini_file_error>([]()
                                 { ParserINI parser("this_file_does_not_exist.ini"); }, "несуществующий файл");
}

// ========== main ==========

int main()
{
    run_test("read int", test_read_int);
    run_test("read double", test_read_double);
    run_test("read string with spaces", test_read_string_with_spaces);
    run_test("repeated section overwrites", test_repeated_section_overwrites);
    run_test("inline comment", test_inline_comment);
    run_test("empty value as string", test_empty_value_as_string);
    run_test("empty value as int throws", test_empty_value_as_int_throws);
    run_test("section not found", test_section_not_found);
    run_test("key not found", test_key_not_found);
    run_test("syntax error line number", test_syntax_error_line_number);
    run_test("file not found", test_file_not_found);

    std::cout << "\nПрошло: " << g_passed
              << ", упало: " << g_failed << "\n";

    return g_failed == 0 ? 0 : 1;
}