add_library(INI_Parser STATIC
    src/ParserINI.cpp
    include/ParserINI.h
    include/Exception.h
    include/Constants.h
)

target_include_directories(INI_Parser PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)