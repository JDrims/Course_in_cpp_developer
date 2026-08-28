#include "Rectangle.h"

Figures::Rectangle::Rectangle(double side_a, double side_b)
    : Parallelogram("Прямоугольник", side_a, side_b, 90, 90)
{
    name = "Прямоугольник";
}

Figures::Rectangle::Rectangle(const std::string& figureName,
    double side_a, double side_b) : Parallelogram(figureName,
        side_a, side_b, 90, 90)
{
    name = figureName;
}