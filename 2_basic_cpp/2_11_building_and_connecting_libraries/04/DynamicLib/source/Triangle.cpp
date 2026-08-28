#include "Triangle.h"

DLL_API Triangle::Triangle(double side_a, double side_b, double side_c,
	double angle_A, double angle_B, double angle_C)
	: a(side_a), b(side_b), c(side_c),
	A(angle_A), B(angle_B), C(angle_C)
{
	name = "Треугольник";
}

double DLL_API Triangle::get_a() const { return a; }
double DLL_API Triangle::get_b() const { return b; }
double DLL_API Triangle::get_c() const { return c; }
double DLL_API Triangle::get_A() const { return A; }
double DLL_API Triangle::get_B() const { return B; }
double DLL_API Triangle::get_C() const { return C; }

void DLL_API Triangle::print_info() const
{
	Figure::print_info();
	std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
	std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
	std::cout << std::endl;
}