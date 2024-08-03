cmake_minimum_required(VERSION 3.0)
project(CompilacionFinal)

set(SFML_DIR "/ruta/a/SFML/lib/cmake/SFML")


find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(menu main.cpp)
target_link_libraries(menu sfml-system sfml-window sfml-graphics)

