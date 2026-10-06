cmake_minimum_required(VERSION 3.16)
project(INI_Parser_Project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_subdirectory(lib)
add_subdirectory(bin)
add_subdirectory(tests)