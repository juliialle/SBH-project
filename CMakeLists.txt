cmake_minimum_required(VERSION 3.24)
project(SBH)

set(CMAKE_CXX_STANDARD 23)

add_executable(SBH main.cpp generator.h generator.cpp
        reconstruction.h
        reconstruction.cpp levenshtein.h levenshtein.cpp)
