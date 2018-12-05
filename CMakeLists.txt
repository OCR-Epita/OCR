cmake_minimum_required(VERSION 3.12)
project(ocr C)

set(CMAKE_C_STANDARD 11)

include_directories(C_Test)
include_directories(Files)

add_executable(ocr
        Files/Binary.c
        Files/Binary.h
        Files/Segmentation.c
        Files/Segmentation.h
        Files/Traitement.c
        Files/Traitement.h
        Files/Utility.c
        Files/Utility.h
        main.c)

target_link_libraries(ocr -lm)