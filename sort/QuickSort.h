//
// Created by fangf on 2017/6/11.
//

#ifndef ALGORITHM_QUICKSORT_H
#define ALGORITHM_QUICKSORT_H

template<typename T>
int __partition(T arr[], int l, int r) {
    T v = arr[l];
    int j = l;
    for (int i=l+1; i<=r; i++) {
        if ( arr[i]<v )
            swap(arr[i], arr[++j]);
    }
    swap( arr[l], arr[j] );
    return j;
}

// 优化重复数值的排序
template<typename T>
int __partition2(T arr[], int l, int r){
    swap(arr[l], arr[rand()%(r-l+1)+l]); // 随机选择一个元素
    T v = arr[l];
    int i = l+1, j = r;
    while (true) {
        while (i <= r && arr[i] < v) i++;
        while (j >= l+1 && arr[j] > v) j--;
        if ( i >= j ) break;
        swap( arr[i], arr[j] );
        i++;j--;
    }
    swap( arr[l], arr[j] );
    return j;
}

template<typename T>
void __quickSort(T arr[], int l, int r) {
//    if ( l >= r ) return;
    if ( r-l<16 ) { // 在元素较少的情况下使用插入排序
        insertionSort2(arr, l, r);
        return;
    }
    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}

template<typename T>
void __quickSort2(T arr[], int l, int r) {
//    if ( l >= r ) return;
    if ( r-l<16 ) { // 在元素较少的情况下使用插入排序
        insertionSort2(arr, l, r);
        return;
    }
    int p = __partition2(arr, l, r);
    __quickSort2(arr, l, p-1);
    __quickSort2(arr, p+1, r);
}

// 对相同元素有更好的处理效果
template<typename T>
void __quickSort3(T arr[], int l, int r){
    if ( r-l<16 ) { // 在元素较少的情况下使用插入排序
        insertionSort2(arr, l, r);
        return;
    }
    swap(arr[l], arr[rand()%(r-l+1)+l]); // 随机选择一个元素
    T v = arr[l];
    int lt = l, gt = r+1, i=l+1;
    while ( i<gt ){
        if (arr[i]<v) swap( arr[i++], arr[++lt]) ;
        else if(arr[i]>v) swap( arr[i], arr[--gt] );
        else i++;
    }
    swap( arr[l], arr[lt--] );
    __quickSort3(arr, l, lt);
    __quickSort3(arr, gt, r);
}

template<typename T>
void quickSort(T arr[], int n) {
    __quickSort(arr, 0, n-1);
}

template<typename T>
void quickSort2(T arr[], int n) {
    srand(time(NULL));
    __quickSort2(arr, 0, n-1);
}

// 三路快速排序
template<typename T>
void quickSort3(T arr[], int n) {
    srand(time(NULL));
    __quickSort3(arr, 0, n-1);
}

#endif //ALGORITHM_QUICKSORT_H
