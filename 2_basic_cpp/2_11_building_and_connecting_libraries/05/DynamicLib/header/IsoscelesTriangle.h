#pragma once
#include "Triangle.h"

class DLL_API IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(double side_a, double side_b,
        double angle_A, double angle_B);
};