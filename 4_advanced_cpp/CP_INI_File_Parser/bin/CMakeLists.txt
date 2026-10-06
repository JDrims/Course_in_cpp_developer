add_executable(INI_Parser_App main.cpp)

target_link_libraries(INI_Parser_App PRIVATE INI_Parser)

add_custom_command(TARGET INI_Parser_App POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/example.ini
        $<TARGET_FILE_DIR:INI_Parser_App>
    COMMENT "Копирование example.ini рядом с исполняемым файлом"
)