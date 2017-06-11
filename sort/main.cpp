#include <iostream>
#include "SortHelper.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"

int main() {
//    testTemplateSort();
    int n = 1000000;
    int *arr = SortHelper::generateRamdomArray(n,0,n);
//    selectionSort(arr, n);
//    SortHelper::printArray(arr, n);
//    SortHelper::testSort("Bubble", bubbleSort, arr, n);
//    SortHelper::testSort("Selection", selectionSort, arr, n);
//    SortHelper::testSort("Insertion", insertionSort, arr, n);
//    SortHelper::testSort("Insertion", insertionSort2, arr, n);
//    SortHelper::testSort("Merge", mergeSort, arr, n);
    SortHelper::testSort("Merge2", mergeSort2, arr, n);
//    SortHelper::compareSort("Insertion", insertionSort2, "Merge", mergeSort, arr, n);
    delete[] arr;
    return 0;
}
