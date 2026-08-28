cmake_minimum_required (VERSION 3.10)

project ("02" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable (02  "Source/main.cpp" 
					"Source/Figure.cpp" 
					"Source/IsoscelesTriangle.cpp"
					"Source/EquilateralTriangle.cpp"
					"Source/Parallelogram.cpp"
					"Source/Quadrangle.cpp"
					"Source/Rectangle.cpp"
					"Source/Rhombus.cpp"
					"Source/RightTriangle.cpp"
					"Source/Square.cpp"
					"Source/Triangle.cpp"
					"Header/EquilateralTriangle.h" 
					"Header/Figure.h"
					"Header/figures.h"
					"Header/IsoscelesTriangle.h"
					"Header/Parallelogram.h"
					"Header/Quadrangle.h"
					"Header/Rectangle.h"
					"Header/Rhombus.h"
					"Header/RightTriangle.h"
					"Header/Square.h"
					"Header/Triangle.h"
				)