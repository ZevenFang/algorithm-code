//
// Created by fangf on 2017/5/14.
//

#ifndef ALGORITHM_BUBBLESORT_H
#define ALGORITHM_BUBBLESORT_H

#include "SortHelper.h"

template<typename T>
void bubbleSort(T arr[], int n){
    for (int i = 0; i < n; ++i) {
        for (int j = n-1; j > i; --j) {
            if (arr[j] < arr[j-1]) swap(arr[j], arr[j-1]);
        }
    }
}

#endif //ALGORITHM_BUBBLESORT_H
