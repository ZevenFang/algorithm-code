//
// Created by fangf on 2017/6/12.
//

#ifndef ALGORITHM_MAXHEAP_H
#define ALGORITHM_MAXHEAP_H

#include <cassert>
#include <cmath>

template<typename Item>
class MaxHeap {
private:
    Item* data;
    int count;
    int capacity;
    void shiftUp (int i) {
        while (i > 1 && data[i] > data[i/2]) {
            swap(data[i],data[i/2]);
            i /= 2;
        }
    }
public:
    MaxHeap(int capacity){
        data = new Item[capacity+1];
        count = 0;
        this->capacity = capacity;
    }
    ~MaxHeap(){
        delete[] data;
    }
    int size(){
        return count;
    }
    int isEmpty(){
        return count==0;
    }
    Item* getData(){
        return data;
    }
    void insert(Item item){
        assert(count < capacity);
        data[++count] = item;
        shiftUp(count);
    }
};

#endif //ALGORITHM_MAXHEAP_H
