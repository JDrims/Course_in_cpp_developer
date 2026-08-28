cmake_minimum_required (VERSION 3.10)

project ("Unit-tests_03" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_executable ("Unit-tests_03"
    "test_extarray.h"
    "extended_array.h"
    "main.cpp"
)