cmake_minimum_required(VERSION 3.7)
project(Analisador_Lexico)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES cmp2.cpp Escrita.cpp Leitura.cpp Separador.cpp)
add_executable(Analisador_Lexico ${SOURCE_FILES})

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/*.txt
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)