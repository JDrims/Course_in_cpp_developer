cmake_minimum_required (VERSION 3.10)

project ("DynamicLib" LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library("DynamicLib" SHARED "source/EquilateralTriangle.cpp"
								"header/EquilateralTriangle.h"
								"source/Figure.cpp"
								"header/Figure.h"
								"source/IsoscelesTriangle.cpp"
								"header/IsoscelesTriangle.h"
								"source/Parallelogram.cpp"
								"header/Parallelogram.h"
								"source/Quadrangle.cpp"
								"header/Quadrangle.h"
								"source/Rectangle.cpp"
								"header/Rectangle.h"
								"source/Rhombus.cpp"
								"header/Rhombus.h"
								"source/RightTriangle.cpp"
								"header/RightTriangle.h"
								"source/Square.cpp"
								"header/Square.h"
								"source/Triangle.cpp"
								"header/Triangle.h"
								"header/Export.h"
)

target_include_directories("DynamicLib" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header)

target_compile_definitions("DynamicLib" PRIVATE "DYNAMICLIB_EXPORTS")