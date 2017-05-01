cmake_minimum_required(VERSION 3.7)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SortHelper.h Student.h)
add_executable(algorithm ${SOURCE_FILES})