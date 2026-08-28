#include "Triangle.h"

Triangle::Triangle(double side_a, double side_b, double side_c,
	double angle_A, double angle_B, double angle_C)
	: a(side_a), b(side_b), c(side_c),
	A(angle_A), B(angle_B), C(angle_C)
{
	name = "Треугольник";

	const double eps = 1e-9;
	if (std::abs(A + B + C - 180.0) > eps) {
		throw FigureException(name, "сумма углов не равна 180");
	}
	if (a <= 0 || b <= 0 || c <= 0) {
		throw FigureException(name, "стороны должны быть положительными");
	}
	if (A <= 0 || B <= 0 || C <= 0 || A >= 180 || B >= 180 || C >= 180) {
		throw FigureException(name, "углы должны быть в диапазоне (0, 180)");
	}
}

Triangle::Triangle(const std::string& figureName, double side_a, double side_b, double side_c,
	double angle_A, double angle_B, double angle_C)
	: a(side_a), b(side_b), c(side_c),
	A(angle_A), B(angle_B), C(angle_C)
{
	name = figureName;

	const double eps = 1e-9;
	if (std::abs(A + B + C - 180.0) > eps) {
		throw FigureException(figureName, "сумма углов не равна 180");
	}
	if (a <= 0 || b <= 0 || c <= 0) {
		throw FigureException(figureName, "стороны должны быть положительными");
	}
	if (A <= 0 || B <= 0 || C <= 0 || A >= 180 || B >= 180 || C >= 180) {
		throw FigureException(figureName, "углы должны быть в диапазоне (0, 180)");
	}
}

double Triangle::get_a() const { return a; }
double Triangle::get_b() const { return b; }
double Triangle::get_c() const { return c; }
double Triangle::get_A() const { return A; }
double Triangle::get_B() const { return B; }
double Triangle::get_C() const { return C; }

void Triangle::print_info() const
{
	Figure::print_info();
	std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
	std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
	std::cout << std::endl;
}