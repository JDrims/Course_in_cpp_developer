cmake_minimum_required (VERSION 3.10)

project ("Program" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable ("Program"  "main.cpp" )

target_link_libraries("Program" PRIVATE DynamicLib)

target_include_directories("Program" PRIVATE ${CMAKE_SOURCE_DIR}/DynamicLib)

add_custom_command(TARGET Program POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:DynamicLib>
        $<TARGET_FILE_DIR:Program>
    COMMENT "Копирование DynamicLib.dll в папку приложения"
)