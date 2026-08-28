#pragma once
#include <iostream>
#include "FigureException.h"

class Figure
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