#include "Square.h"

DLL_API Square::Square(double side) : Rectangle(side, side)
{
    name = "Квадрат";
}