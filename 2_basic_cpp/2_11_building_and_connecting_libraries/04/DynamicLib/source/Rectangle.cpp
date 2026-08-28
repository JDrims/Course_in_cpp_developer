#include "Rectangle.h"

DLL_API Figures::Rectangle::Rectangle(double side_a, double side_b)
    : Parallelogram(side_a, side_b, 90, 90)
{
    name = "Прямоугольник";
}