cmake_minimum_required(VERSION 3.19)
project(ProgramMare)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ProgramMare
        graf.cpp
        graf.h
        main.cpp)
