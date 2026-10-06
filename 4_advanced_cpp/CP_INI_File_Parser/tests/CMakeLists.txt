add_executable(INI_Parser_Tests test_ini_parser.cpp)

target_link_libraries(INI_Parser_Tests PRIVATE INI_Parser)

add_test(NAME INI_Parser_Tests COMMAND INI_Parser_Tests)