#include "Parallelogram.h"

Parallelogram::Parallelogram(double side_a, double side_b,
    double angle_A, double angle_B) : Quadrangle("Параллелограмм",
        side_a, side_b, side_a, side_b, angle_A, angle_B, angle_A, angle_B)
{
    name = "Параллелограмм";

    if (angle_A <= 0 || angle_A >= 180 || angle_B <= 0 || angle_B >= 180) {
        throw FigureException(name, "углы должны быть в диапазоне (0, 180)");
    }
}

Parallelogram::Parallelogram(const std::string& figureName, double side_a, double side_b,
    double angle_A, double angle_B) : Quadrangle(figureName,
        side_a, side_b, side_a, side_b, angle_A, angle_B, angle_A, angle_B)
{
    name = figureName;

    if (angle_A <= 0 || angle_A >= 180 || angle_B <= 0 || angle_B >= 180) {
        throw FigureException(figureName, "углы должны быть в диапазоне (0, 180)");
    }
}