cmake_minimum_required (VERSION 3.10)

project ("DynamicLib" LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library("DynamicLib" SHARED "Leaver.cpp" "Leaver.h")

target_include_directories("DynamicLib" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions("DynamicLib" PRIVATE "LEAVERLIBRARY_EXPORTS")