cmake_minimum_required(VERSION 3.31)
project(Traductor C)

set(CMAKE_C_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(Traductor
    src/main.c
    src/utils/FileManager.c
    include/structures/Vector.h
    src/structures/Vector.c
    include/structures/string.h
    src/structures/string.c)

target_include_directories(Traductor PRIVATE ${CMAKE_SOURCE_DIR}/include)