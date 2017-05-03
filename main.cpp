#include <iostream>
#include "SortHelper.h"
#include "Student.h"

template<typename T>
void bubbleSort(T arr[], int n){
    for (int i = 0; i < n; ++i) {
        for (int j = n-1; j > i; --j) {
            if (arr[j] < arr[j-1]) swap(arr[j], arr[j-1]);
        }
    }
}

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

template<typename T>
void insertionSort2(T arr[], int n){
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j > 0; --j) {
            if (arr[j]<arr[j-1]) arr[j] = arr[j-1];
            else {
                arr[j] = arr[i];
                break;
            }
        }
    }
}

/*
 * 希尔排序时效分析很难，关键码的比较次数与记录移动次数依赖于步长因子序列的选取，
 * 特定情况下可以准确估算出关键码的比较次数和记录的移动次数。目前还没有人给出选取
 * 最好的步长因子序列的方法。步长因子序列可以有各种取法，有取奇数的，也有取质数的，
 * 但需要注意：步长因子中除1 外没有公因子，且最后一个步长因子必须为1。
 * 希尔排序方法是一个不稳定的排序方法。
 */
template<typename T>
void shellSort(T arr[], int n){
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            for (int j = i - gap; j > 0; j -= gap) {
                if (arr[j + gap] < arr[j]) arr[j + gap] =arr[j] ;
                else {
                    arr[j] = arr[i];
                    break;
                }
            }
        }
}

void testTemplateSort(){
    Student s[4] = {{"D",90},{"C",100},{"B",95},{"A",92}};
    selectionSort(s, 4);
    SortHelper::printArray(s, 4);
}

// 将arr[l...r]分成两部分进行归并
template<typename T>
void __merge(T arr[], int l, int r){
    int mid = (l+r)/2;
    T *temp = new T[r-l+1];
    for (int i = l; i <= r; ++i)
        temp[i-l] = arr[i];
    for (int i = l, j = mid+1, k = l; k <= r; ++k) {
        if (i > mid) {
            arr[k] = temp[j-l];
            j++;
        } else if (j > r) {
            arr[k] = temp[i-l];
            i++;
        } else if (temp[i-l] < temp[j-l]) {
            arr[k] = temp[i-l];
            i++;
        } else {
            arr[k] = temp[j-l];
            j++;
        }
    }
}

// 递归使用归并排序，对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r){
    if (l >= r) return;
    int mid = (l+r)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    __merge(arr, l, r);
}

template<typename T>
void mergeSort(T arr[], int n){
    __mergeSort(arr, 0, n-1);
}

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
//    SortHelper::compareSort("Insertion", insertionSort2, "Merge", mergeSort, arr, n);
    delete[] arr;
    return 0;
}
