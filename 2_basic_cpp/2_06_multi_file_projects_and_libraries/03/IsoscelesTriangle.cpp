#include "IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(double side_a, double side_b,
    double angle_A, double angle_B) : Triangle(side_a, side_b, side_a,
        angle_A, angle_B, angle_A)
{
    name = "Равнобедренный треугольник";
}