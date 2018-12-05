cmake_minimum_required(VERSION 3.12)
project(ocr)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Files)
include_directories(Images)
include_directories(res)

add_executable(ocr
        Files/Binary.c
        Files/Traitement.c
        Files/Utility.c
        main.c)

target_link_libraries(ocr -lm)