#pragma once
#include <Export.h>
#include <iostream>

class DLL_API Figure
{
protected:
    std::string name;

public:
    Figure();
    virtual ~Figure() = default;

    std::string get_name();

    virtual void print_info() const
    {
        std::cout << name << ": " << std::endl;
    }
};