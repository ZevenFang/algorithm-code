//
// Created by Zeven Fang on 2017/4/30.
//

#ifndef ALGORITHM_SORTHELPER_H
#define ALGORITHM_SORTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortHelper{

    int* generateRamdomArray(int n, int rangeL, int rangeR){
        assert(rangeL<rangeR);
        auto *arr = new int[n];
        srand((unsigned int) time(nullptr));
        for(int i=0;i<n;i++)
            arr[i] = (int) (random() % (rangeR - rangeL + 1) + rangeL);
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n) {
        for(int i=0; i < n; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

    template<typename T>
    bool isSorted(T arr[], int n){
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i+1])
                return false;
        }
        return true;
    }

    template<typename T>
    void testSort(string name, void(*sort)(T[],int), T arr[], int n){
        clock_t start = clock();
        sort(arr,n);
        clock_t end = clock();
        assert(isSorted(arr, n));
        cout << name << ": " << double(end-start) / CLOCKS_PER_SEC << " s" << endl;
    }

    template<typename T>
    T* copyArray(T a[], int n){
        auto* arr = new T[n-1];
        for (int i = 0; i < n; ++i) {
            arr[i] = a[i];
        }
        return arr;
    }

    template<typename T>
    void compareSort(string name1, void(*sort1)(T[],int), string name2, void(*sort2)(T[],int), T arr[], int n){
        T *arr2 = SortHelper::copyArray(arr, n);
        SortHelper::testSort(name1, sort1, arr, n);
        SortHelper::testSort(name2, sort2, arr2, n);
        delete[] arr2;
    }

}

#endif //ALGORITHM_SORTHELPER_H
