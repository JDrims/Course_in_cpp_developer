#include <iostream>

#include "ParserINI.h"
#include <Windows.h>

int main()
{

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    try
    {
        ParserINI parser("example.ini");

        auto d = parser.get_value<double>("Section1.var1");
        auto s = parser.get_value<std::string>("Section2.var2");
        auto m = parser.get_value<std::string>("Section4.Mode");

        std::cout << "Section1.var1 = " << d << "\n";
        std::cout << "Section2.var2 = " << s << "\n";
        std::cout << "Section4.Mode = '" << m << "'\n";
    }
    catch (const ini_syntax_error &e)
    {
        std::cerr << "Ошибка в файле: " << e.what() << "\n";
        std::cerr << "Номер строки: " << e.line() << "\n";
    }
    catch (const ini_key_not_found &e)
    {
        std::cerr << e.what() << "\n";
    }
    catch (const ini_error &e)
    {
        std::cerr << "Ошибка парсера: " << e.what() << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Стандартное исключение: " << e.what() << "\n";
    }
    catch (...)
    {
        std::cerr << "Неизвестная ошибка (не исключение)\n";
    }

    return 0;
}