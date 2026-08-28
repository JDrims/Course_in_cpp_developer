#include <iostream>

class Figure
{
protected:
    std::string name;

public:
    Figure() : name("Фигура") {}
    virtual ~Figure() = default;

    std::string get_name() { return name; }

    virtual void print_info() const
    {
        std::cout << name << ": " << std::endl;
    }
};

class Triangle : public Figure
{
    double a, b, c;
    double A, B, C;

public:
    Triangle(double side_a, double side_b, double side_c,
             double angle_A, double angle_B, double angle_C) : a(side_a), b(side_b), c(side_c),
                                                               A(angle_A), B(angle_B), C(angle_C)
    {
        name = "Треугольник";
    }

    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }

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
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(double side) : Triangle(side, side, side, 60, 60, 60)
    {
        name = "Равносторонний треугольник";
    }
};

class Quadrangle : public Figure
{
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
    }

    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_d() const { return d; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }
    double get_D() const { return D; }

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
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(double side_a, double side_b) : Parallelogram(side_a, side_b, 90, 90)
    {
        name = "Прямоугольник";
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
};

class Square : public Rectangle
{
public:
    Square(double side) : Rectangle(side, side)
    {
        name = "Квадрат";
    }
};

void print_info(const Figure *figure)
{
    figure->print_info();
}

int main()
{
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle right_tri(10, 20, 30, 50, 60);
    IsoscelesTriangle isosceles_tri(10, 20, 50, 60);
    EquilateralTriangle equilateral_tri(30);

    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
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