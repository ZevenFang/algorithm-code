cmake_minimum_required(VERSION 3.7)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

set(SORT_CODE sort/main.cpp sort/SortHelper.h sort/Student.h sort/MergeSort.h sort/InsertionSort.h sort/SelectionSort.h sort/BubbleSort.h sort/QuickSort.h)
set(HEAP_CODE heap/main.cpp heap/MaxHeap.h heap/HeapHelper.h)
add_executable(sort ${SORT_CODE})
add_executable(heap ${HEAP_CODE})