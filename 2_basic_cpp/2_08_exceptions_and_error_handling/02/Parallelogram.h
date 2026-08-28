#pragma once
#include "Quadrangle.h"

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(double side_a, double side_b, double angle_A, double angle_B);
    Parallelogram(const std::string& figureName,
        double side_a, double side_b, double angle_A, double angle_B);
};