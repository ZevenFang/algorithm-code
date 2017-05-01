#include <iostream>
#include "SortHelper.h"
#include "Student.h"

template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        // 寻找[i,n)区间的最小值
        int min = i;
        for (int j = i+1; j < n; ++j) {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[i],arr[min]);
    }
}

template<typename T>
void insertionSort(T arr[], int n){
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j > 0; --j) {
            if (arr[j]<arr[j-1]) swap(arr[j],arr[j-1]);
            else break;
        }
    }
}

void testTemplateSort(){
    Student s[4] = {{"D",90},{"C",100},{"B",95},{"A",92}};
    selectionSort(s, 4);
    SortHelper::printArray(s, 4);
}

void testCopySort(int arr[], int n){
    int* arr2 = SortHelper::copyArray(arr,n);
    SortHelper::testSort("Selection", selectionSort, arr, n);
    SortHelper::testSort("Insertion", insertionSort, arr2, n);
    delete[] arr2;
}

int main() {
//    testTemplateSort();
    int n = 10000;
    int *arr = SortHelper::generateRamdomArray(n,0,n);
//    selectionSort(arr, n);
//    SortHelper::printArray(arr, n);
//    SortHelper::testSort("Selection", selectionSort, arr, n);
//    SortHelper::testSort("Insertion", insertionSort, arr, n);
    testCopySort(arr, n);
    delete[] arr;
    return 0;
}
