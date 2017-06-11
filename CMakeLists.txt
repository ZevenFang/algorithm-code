cmake_minimum_required(VERSION 3.7)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES sort/main.cpp sort/SortHelper.h sort/Student.h sort/MergeSort.h sort/InsertionSort.h sort/SelectionSort.h sort/BubbleSort.h sort/QuickSort.h)
add_executable(algorithm ${SOURCE_FILES})