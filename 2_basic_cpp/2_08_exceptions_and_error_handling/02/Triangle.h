#pragma once
#include "Figure.h"

class Triangle : public Figure
{
	double a, b, c;
	double A, B, C;

public:
	Triangle(double side_a, double side_b, double side_c,
		double angle_A, double angle_B, double angle_C);
	Triangle(const std::string& figureName, double side_a, double side_b, double side_c,
		double angle_A, double angle_B, double angle_C);

	double get_a() const;
	double get_b() const;
	double get_c() const;
	double get_A() const;
	double get_B() const;
	double get_C() const;

	void print_info() const override;
};