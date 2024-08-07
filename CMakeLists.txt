cmake_minimum_required(VERSION 3.26)
project(Project_3_Test)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project_3_Test main.cpp
    dictionary.h
    dictionary.cpp
    word.h
    word.cpp
        test.cpp)
