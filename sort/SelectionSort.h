//
// Created by fangf on 2017/5/14.
//

#ifndef ALGORITHM_SELECTIONSORT_H
#define ALGORITHM_SELECTIONSORT_H

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

void testTemplateSort(){
    Student s[4] = {{"D",90},{"C",100},{"B",95},{"A",92}};
    selectionSort(s, 4);
    SortHelper::printArray(s, 4);
}

#endif //ALGORITHM_SELECTIONSORT_H
