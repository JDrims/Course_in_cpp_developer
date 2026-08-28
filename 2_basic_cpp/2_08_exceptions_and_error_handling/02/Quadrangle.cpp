#include "Quadrangle.h"

Quadrangle::Quadrangle(double side_a, double side_b, double side_c, double side_d,
    double angle_A, double angle_B, double angle_C, double angle_D) : a(side_a), b(side_b),
    c(side_c), d(side_d), A(angle_A), B(angle_B), C(angle_C), D(angle_D)
{
    name = "Четырёхугольник";
    
    const double eps = 1e-9;
    if (std::abs(A + B + C + D - 360.0) > eps) {
        throw FigureException(name, "сумма углов не равна 360");
    }
    if (a <= 0 || b <= 0 || c <= 0 || d <= 0) {
        throw FigureException(name, "стороны должны быть положительными");
    }
    if (A <= 0 || B <= 0 || C <= 0 || D <= 0 ||
        A >= 360 || B >= 360 || C >= 360 || D >= 360) {
        throw FigureException(name, "углы должны быть в диапазоне (0, 360)");
    }
}

Quadrangle::Quadrangle(const std::string& figureName,
    double side_a, double side_b, double side_c, double side_d,
    double angle_A, double angle_B, double angle_C, double angle_D) : a(side_a), b(side_b),
    c(side_c), d(side_d), A(angle_A), B(angle_B), C(angle_C), D(angle_D)
{
    name = figureName;

    const double eps = 1e-9;
    if (std::abs(A + B + C + D - 360.0) > eps) {
        throw FigureException(figureName, "сумма углов не равна 360");
    }
    if (a <= 0 || b <= 0 || c <= 0 || d <= 0) {
        throw FigureException(figureName, "стороны должны быть положительными");
    }
    if (A <= 0 || B <= 0 || C <= 0 || D <= 0 ||
        A >= 360 || B >= 360 || C >= 360 || D >= 360) {
        throw FigureException(figureName, "углы должны быть в диапазоне (0, 360)");
    }
}

double Quadrangle::get_a() const { return a; }
double Quadrangle::get_b() const { return b; }
double Quadrangle::get_c() const { return c; }
double Quadrangle::get_d() const { return d; }
double Quadrangle::get_A() const { return A; }
double Quadrangle::get_B() const { return B; }
double Quadrangle::get_C() const { return C; }
double Quadrangle::get_D() const { return D; }

void Quadrangle::print_info() const
{
    Figure::print_info();
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    std::cout << std::endl;
}