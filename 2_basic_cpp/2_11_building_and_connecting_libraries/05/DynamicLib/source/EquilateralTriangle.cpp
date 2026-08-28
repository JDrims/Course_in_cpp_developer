#include "EquilateralTriangle.h"

DLL_API EquilateralTriangle::EquilateralTriangle(double side)
	: Triangle(side, side, side, 60, 60, 60)
{
	name = "Равносторонний треугольник";
}