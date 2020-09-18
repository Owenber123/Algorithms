//
//  heap.hpp
//  Assignment3A
//
//  Created by Owen Beringer on 11/1/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//

#ifndef heap_hpp
#define heap_hpp

#include <stdio.h>
#include <vector>

using namespace std;

template <class T>
class heap
{
public:
    heap(){
        heapSize = 0;
    }
    int parent(int x);
    int left(int x);
    int right(int x);
    T getItem(int x);
    void initializeMaxHeap(vector<T> list);
    void maxHeapify(int i);
    void buildMaxHeap();
    void heapsort();
    void printHeap();
    
private:
    vector<T> heapList;
    int heapSize;
};

#endif /* heap_hpp */
