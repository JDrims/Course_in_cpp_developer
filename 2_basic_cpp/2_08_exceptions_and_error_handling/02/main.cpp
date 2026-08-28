#include <Windows.h>
#include <iostream>
#include "figures.h"

void print_info(const Figure* figure);
void createTriangle(double, double, double, double, double, double);
void createRightTriangle(double, double, double, double, double);
void createIsoscelesTriangle(double, double, double, double);
void createEquilateralTriangle(double);
void createQuadrangle(double, double, double, double, double, double, double, double);
void createRectangle(double, double);
void createSquare(double);
void createParallelogram(double, double, double, double);
void createRhombus(double, double, double);

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	// ========== ТРЕУГОЛЬНИК ==========
	createTriangle(10, 20, 15, 50, 60, 70); // Правильный
	createTriangle(10, 20, 30, 90, 60, 70); // Ошибка: сумма углов != 180
	createTriangle(-5, 10, 12, 60, 60, 60); // Ошибка: отрицательная сторона
	createTriangle(10, 20, 30, 200, 60, -10); // Ошибка: угол вне диапазона (0,180)

	std::cout << std::endl;

	// ========== ПРЯМОУГОЛЬНЫЙ ТРЕУГОЛЬНИК ==========
	createRightTriangle(3, 4, 5, 30, 60); // Правильный
	createRightTriangle(10, 20, 30, 50, 60); // Ошибка: сумма углов не 180

	std::cout << std::endl;
	
	// ========== РАВНОБЕДРЕННЫЙ ТРЕУГОЛЬНИК ==========
	createIsoscelesTriangle(10, 20, 50, 80); // Правильный
	createIsoscelesTriangle(10, 20, 50, 60); // Ошибка: сумма углов != 180

	std::cout << std::endl;

	// ========== РАВНОСТОРОННИЙ ТРЕУГОЛЬНИК ==========
	createEquilateralTriangle(30); // Правильный
	createEquilateralTriangle(-30); // Ошибка: отрицательная сторона

	std::cout << std::endl;

	// ========== ЧЕТЫРЁХУГОЛЬНИК ==========
	createQuadrangle(10, 20, 30, 40, 80, 100, 90, 90); // Правильный
	createQuadrangle(10, 20, 30, 40, 50, 60, 70, 80); // Ошибка: сумма углов != 360
	createQuadrangle(-10, 20, 30, 40, 90, 90, 90, 90); // Ошибка: отрицательная сторона
	createQuadrangle(10, 20, 30, 40, 370, 0, 0, 0); // Ошибка: угол >= 360

	std::cout << std::endl;

	// ========== ПАРАЛЛЕЛОГРАММ ==========
	createParallelogram(20, 30, 60, 120); // Правильный
	createParallelogram(20, 30, 30, 40); // Ошибка: сумма углов != 360
	createParallelogram(20, 30, 200, 50); // Ошибка: углы вне (0,180)

	std::cout << std::endl;

	// ========== ПРЯМОУГОЛЬНИК ==========
	createRectangle(10, 20); // Правильный
	createRectangle(-10, 20); // Ошибка: отрицательная сторона

	std::cout << std::endl;

	// ========== КВАДРАТ ==========
	createSquare(25); // Правильный
	createSquare(-5); // Ошибка: отрицательная сторона

	std::cout << std::endl;

	// ========== РОМБ ==========
	createRhombus(30, 60, 120); // Правильный
	createRhombus(30, 30, 40); // Ошибка: сумма углов != 360
	createRhombus(30, 200, 50); // Ошибка: угол вне (0,180)

	return 0;
}

void print_info(const Figure* figure)
{
	figure->print_info();
}

void createTriangle(double side_a, double side_b, double side_c,
	double angle_A, double angle_B, double angle_C)
{
	try {
		Triangle t(side_a, side_b, side_c, angle_A, angle_B, angle_C);
		std::cout << "Создана фигура" << std::endl;
		print_info(&t);
	}
	catch (const FigureException& e) {
		std::cout << "Ошибка создания фигуры (" << e.getNameFigure() << ") Причина: " << e.what() << std::endl;
	}
}
void createRightTriangle(double side_a, double side_b, double side_c, double angle_A, double angle_B)
{
	try {
		RightTriangle rt(side_a, side_b, side_c, angle_A, angle_B);
		std::cout << "Создана фигура" << std::endl;
		print_info(&rt);
	}
	catch (const FigureException& e) {
		std::cout << "Ошибка создания фигуры (" << e.getNameFigure() << ") Причина: " << e.what() << std::endl;
	}
}

void createIsoscelesTriangle(double side_a, double side_b, double angle_A, double angle_B)
{
	try {
		IsoscelesTriangle it(side_a, side_b, angle_A, angle_B);
		std::cout << "Создана фигура" << std::endl;
		print_info(&it);
	}
	catch (const FigureException& e) {
		std::cout << "Ошибка создания фигуры (" << e.getNameFigure() << ") Причина: " << e.what() << std::endl;
	}
}

void createEquilateralTriangle(double side)
{
	try {
		EquilateralTriangle et(side);
		std::cout << "Создана фигура" << std::endl;
		print_info(&et);
	}
	catch (const FigureException& e) {
		std::cout << "Ошибка создания фигуры (" << e.getNameFigure() << ") Причина: " << e.what() << std::endl;
	}
}

void createQuadrangle(double side_a, double side_b, double side_c, double side_d,
	double angle_A, double angle_B, double angle_C, double angle_D)
{
	try {
		Quadrangle q(side_a, side_b, side_c, side_d, angle_A, angle_B, angle_C, angle_D);
		std::cout << "Создана фигура" << std::endl;
		print_info(&q);
	}
	catch (const FigureException& e) {
		std::cout << "Ошибка создания фигуры (" << e.getNameFigure() << ") Причина: " << e.what() << std::endl;
	}
}

void createRectangle(double side_a, double side_b)
{
	try {
		Figures::Rectangle r(side_a, side_b);
		std::cout << "Создана фигура" << std::endl;
		print_info(&r);
	}
	catch (const FigureException& e) {
		std::cout << "Ошибка создания фигуры (" << e.getNameFigure() << ") Причина: " << e.what() << std::endl;
	}
}

void createSquare(double side)
{
	try {
		Square s(side);
		std::cout << "Создана фигура" << std::endl;
		print_info(&s);
	}
	catch (const FigureException& e) {
		std::cout << "Ошибка создания фигуры (" << e.getNameFigure() << ") Причина: " << e.what() << std::endl;
	}
}

void createParallelogram(double side_a, double side_b, double angle_A, double angle_B)
{
	try {
		Parallelogram p(side_a, side_b, angle_A, angle_B);
		std::cout << "Создана фигура" << std::endl;
		print_info(&p);
	}
	catch (const FigureException& e) {
		std::cout << "Ошибка создания фигуры (" << e.getNameFigure() << ") Причина: " << e.what() << std::endl;
	}
}

void createRhombus(double side, double angle_A, double angle_B)
{
	try {
		Rhombus rh(side, angle_A, angle_B);
		std::cout << "Создана фигура" << std::endl;
		print_info(&rh);
	}
	catch (const FigureException& e) {
		std::cout << "Ошибка создания фигуры (" << e.getNameFigure() << ") Причина: " << e.what() << std::endl;
	}
}