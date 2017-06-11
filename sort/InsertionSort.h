//
// Created by fangf on 2017/5/14.
//

#ifndef ALGORITHM_INSERTIONSORT_H
#define ALGORITHM_INSERTIONSORT_H

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

template<typename T>
void insertionSort2(T arr[], int l, int r){
    for (int i = l; i <= r; ++i) {
        for (int j = i+1; j > l; --j) {
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

#endif //ALGORITHM_INSERTIONSORT_H
