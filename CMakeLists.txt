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
    src/structures/string.c
    src/app.c
    include/app.h
    include/core/parser.h
    include/core/validator.h
    include/core/translator.h
    include/core/execution_time.h
    include/core/instruction/instruction.h
    src/core/instruction/Instruction.c
    include/core/label/label_manager.h
    include/core/label/label.h
    src/core/label/label_manager.c
    src/core/label/label.c
    include/core/instruction/InstructionManager.h
    src/core/instruction/InstructionManager.c
)

target_include_directories(Traductor PRIVATE ${CMAKE_SOURCE_DIR}/include)