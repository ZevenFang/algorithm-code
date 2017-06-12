using namespace std;

#include <iostream>
#include "MaxHeap.h";
#include "HeapHelper.h"

int main() {
    MaxHeap<int> maxHeap = MaxHeap<int>(100);
    srand(time(NULL));
    for (int i=0;i<15;i++)
        maxHeap.insert(rand()%100);
    printHeap(maxHeap);
    return 0;
}