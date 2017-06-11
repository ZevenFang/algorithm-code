//
// Created by fangf on 2017/5/14.
//

#ifndef ALGORITHM_MERGESORT_H
#define ALGORITHM_MERGESORT_H

#include "InsertionSort.h"

// 将arr[l...r]分成两部分进行归并
template<typename T>
void __merge(T arr[], int l, int mid, int r){
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
//    if (l >= r) return;
    if (r-l < 16) { // 在元素较少的情况下使用插入排序
        insertionSort2(arr, l, r);
        return;
    }
    int mid = (l+r)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    if (arr[mid] > arr[mid+1]) // 在近乎有序的数组效果更加明显
        __merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n){
    __mergeSort(arr, 0, n-1);
}

// 自底向上的归并排序
template<typename T>
void mergeSort2(T arr[], int n){
    for (int sz = 2; sz <= n; sz += sz ) {
        for (int i = 0; i + sz < n; i += sz+sz) {
            // 防止数组越界
            int r = min(i+sz+sz-1, n-1);
            if (r-i < 16) {
                // 在元素较少的情况下使用插入排序
                insertionSort2(arr, i, r);
            } else {
                int mid = i + sz - 1;
                // 对 arr[i...i+sz-1] 和 arr[i+sz...i+2*sz-1] 进行归并
                if (arr[mid] > arr[mid+1])
                    __merge(arr, i, mid, r);
            }
        }
    }
}

#endif //ALGORITHM_MERGESORT_H
