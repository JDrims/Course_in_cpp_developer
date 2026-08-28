#include <Windows.h>
#include <iostream>
#include "figures.h"

void print_info(const Figure* figure);

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	Triangle triangle(10, 20, 30, 50, 60, 70);
	RightTriangle right_tri(10, 20, 30, 50, 60);
	IsoscelesTriangle isosceles_tri(10, 20, 50, 60);
	EquilateralTriangle equilateral_tri(30);

	Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	Figures::Rectangle rectangle(10, 20);
	Square square(20);
	Parallelogram parallelogram(20, 30, 30, 40);
	Rhombus rhombus(30, 30, 40);

	print_info(&triangle);
	print_info(&right_tri);
	print_info(&isosceles_tri);
	print_info(&equilateral_tri);
	print_info(&quadrangle);
	print_info(&rectangle);
	print_info(&square);
	print_info(&parallelogram);
	print_info(&rhombus);

	return 0;
}

void print_info(const Figure* figure)
{
	figure->print_info();
}