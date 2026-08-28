#include <iostream>

class Figure
{
protected:
    std::string name;
    int sides_count;

public:
    Figure() : sides_count(0), name("Фигура") {}

    int get_sides_count() { return sides_count; }
    std::string get_name() { return name; }

    virtual ~Figure() = default;
};

class Triangle : public Figure
{
public:
    Triangle()
    {
        sides_count = 3;
        name = "Треугольник";
    }
};

class Quadrangle : public Figure
{
public:
    Quadrangle()
    {
        sides_count = 4;
        name = "Четырёхугольник";
    }
};

int main()
{
    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;

    std::cout << "Количество сторон: " << std::endl;
    std::cout << figure.get_name() << ": " << figure.get_sides_count() << std::endl;
    std::cout << triangle.get_name() << ": " << triangle.get_sides_count() << std::endl;
    std::cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << std::endl;

    return 0;
}