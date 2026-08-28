#include <iostream>

class Figure
{
protected:
    std::string name;
    int sides_count;

public:
    Figure() : sides_count(0), name("Фигура") {}
    virtual ~Figure() = default;

    std::string get_name() { return name; }
    int get_sides_count() { return sides_count; }

    virtual bool check() const
    {
        return sides_count == 0;
    }

    virtual void print_info() const
    {
        std::cout << name << ": " << std::endl;
        std::cout << (check() ? "Правильный" : "Неправильный") << std::endl;
        std::cout << "Количество сторон: " << sides_count << std::endl;
    }
};

class Triangle : public Figure
{
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double side_a, double side_b, double side_c,
             double angle_A, double angle_B, double angle_C) : a(side_a), b(side_b), c(side_c),
                                                               A(angle_A), B(angle_B), C(angle_C)
    {
        name = "Треугольник";
        sides_count = 3;
    }

    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }

    bool check() const override
    {
        const double eps = 1e-9;
        return std::abs(A + B + C - 180.0) < eps;
    }

    void print_info() const override
    {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
        std::cout << std::endl;
    }
};

class RightTriangle : public Triangle
{
public:
    RightTriangle(double side_a, double side_b, double side_c,
                  double angle_A, double angle_B) : Triangle(side_a, side_b, side_c,
                                                             angle_A, angle_B, 90)
    {
        name = "Прямоугольный треугольник";
    }

    bool check() const override
    {
        const double eps = 1e-9;
        return Triangle::check() &&
               std::abs(C - 90.0) < 180.0;
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(double side_a, double side_b,
                      double angle_A, double angle_B) : Triangle(side_a, side_b, side_a,
                                                                 angle_A, angle_B, angle_A)
    {
        name = "Равнобедренный треугольник";
    }

    bool check() const override
    {
        const double eps = 1e-9;
        return Triangle::check() &&
               std::abs(a - c) < eps &&
               std::abs(A - C) < eps;
    }
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(double side) : Triangle(side, side, side, 60, 60, 60)
    {
        name = "Равносторонний треугольник";
    }

    bool check() const override
    {
        const double eps = 1e-9;
        return Triangle::check() &&
               std::abs(a - b) < eps &&
               std::abs(b - c) < eps &&
               std::abs(A - 60.0) < eps &&
               std::abs(B - 60.0) < eps &&
               std::abs(C - 60.0) < eps;
    }
};

class Quadrangle : public Figure
{
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrangle(double side_a, double side_b,
               double side_c, double side_d,
               double angle_A, double angle_B,
               double angle_C, double angle_D) : a(side_a), b(side_b),
                                                 c(side_c), d(side_d),
                                                 A(angle_A), B(angle_B),
                                                 C(angle_C), D(angle_D)
    {
        name = "Четырёхугольник";
        sides_count = 4;
    }

    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_d() const { return d; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }
    double get_D() const { return D; }

    bool check() const override
    {
        const double eps = 1e-9;
        return std::abs(A + B + C + D - 360.0) < eps;
    }

    void print_info() const override
    {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
        std::cout << std::endl;
    }
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(double side_a, double side_b,
                  double angle_A, double angle_B) : Quadrangle(side_a, side_b,
                                                               side_a, side_b,
                                                               angle_A, angle_B,
                                                               angle_A, angle_B)
    {
        name = "Параллелограмм";
    }

    bool check() const override
    {
        const double eps = 1e-9;
        return Quadrangle::check() &&
               std::abs(a - c) < eps && std::abs(b - d) < eps &&
               std::abs(A - C) < eps && std::abs(B - D) < eps;
    }
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(double side_a, double side_b) : Parallelogram(side_a, side_b, 90, 90)
    {
        name = "Прямоугольник";
    }

    bool check() const override
    {
        const double eps = 1e-9;
        return Parallelogram::check() &&
               std::abs(A - 90.0) < eps && std::abs(B - 90.0) < eps &&
               std::abs(C - 90.0) < eps && std::abs(D - 90.0) < eps;
    }
};

class Rhombus : public Parallelogram
{
public:
    Rhombus(double side,
            double angle_A, double angle_B) : Parallelogram(side, side,
                                                            angle_A, angle_B)
    {
        name = "Ромб";
    }

    bool check() const override
    {
        const double eps = 1e-9;
        return Parallelogram::check() &&
               std::abs(a - b) < eps && std::abs(b - c) < eps && std::abs(c - d) < eps;
    }
};

class Square : public Rectangle
{
public:
    Square(double side) : Rectangle(side, side)
    {
        name = "Квадрат";
    }

    bool check() const override
    {
        const double eps = 1e-9;
        return Rectangle::check() &&
               std::abs(a - b) < eps && std::abs(b - c) < eps && std::abs(c - d) < eps;
    }
};

void print_info(const Figure *figure)
{
    figure->print_info();
}

int main()
{
    Figure figure;

    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle right_tri_wrong(10, 20, 30, 50, 60);
    RightTriangle right_tri_correct(10, 20, 30, 50, 40);
    IsoscelesTriangle isosceles_tri(10, 20, 50, 60);
    EquilateralTriangle equilateral_tri(30);

    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    print_info(&figure);
    std::cout << std::endl;
    print_info(&triangle);
    print_info(&right_tri_wrong);
    print_info(&right_tri_correct);
    print_info(&isosceles_tri);
    print_info(&equilateral_tri);
    print_info(&quadrangle);
    print_info(&rectangle);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhombus);

    return 0;
}