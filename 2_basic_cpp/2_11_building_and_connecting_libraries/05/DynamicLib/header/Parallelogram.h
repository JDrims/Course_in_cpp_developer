#pragma once
#include "Quadrangle.h"

class DLL_API Parallelogram : public Quadrangle
{
public:
    Parallelogram(double side_a, double side_b,
        double angle_A, double angle_B);
};