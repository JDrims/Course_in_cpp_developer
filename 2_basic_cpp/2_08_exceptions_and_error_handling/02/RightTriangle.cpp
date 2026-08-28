#include "RightTriangle.h"

RightTriangle::RightTriangle(double side_a, double side_b, double side_c,
    double angle_A, double angle_B)
    : Triangle("Прямоугольный треугольник", side_a, side_b, side_c,
        angle_A, angle_B, 90)
{
    name = "Прямоугольный треугольник";
}