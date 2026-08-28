#pragma once
#include "Parallelogram.h"

namespace Figures {
    class Rectangle : public Parallelogram
    {
    public:
        Rectangle(double side_a, double side_b);
        Rectangle(const std::string& figureName, double side_a, double side_b);
    };
}