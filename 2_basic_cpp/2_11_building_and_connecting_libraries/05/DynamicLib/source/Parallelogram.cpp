#include "Parallelogram.h"

DLL_API Parallelogram::Parallelogram(double side_a, double side_b,
    double angle_A, double angle_B) : Quadrangle(side_a, side_b,
        side_a, side_b, angle_A, angle_B, angle_A, angle_B)
{
    name = "Параллелограмм";
}