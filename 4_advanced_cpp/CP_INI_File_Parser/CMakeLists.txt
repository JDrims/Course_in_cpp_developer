cmake_minimum_required(VERSION 3.16)
project(INI_Parser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(INI_Parser STATIC
    src/ParserINI.cpp
    include/ParserINI.h
)

target_include_directories(INI_Parser PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(INI_Parser_App
    main.cpp
)

target_link_libraries(INI_Parser_App PRIVATE INI_Parser)

# Тесты
enable_testing()

add_executable(INI_Parser_Tests
    tests/test_ini_parser.cpp
)

target_link_libraries(INI_Parser_Tests PRIVATE INI_Parser)

add_test(NAME INI_Parser_Tests COMMAND INI_Parser_Tests)
