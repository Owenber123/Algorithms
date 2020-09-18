//
//  heap.cpp
//  Assignment3A
//
//  Created by Owen Beringer on 11/1/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//

#ifndef heap_h
#define heap_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "heap.hpp"

using namespace std;

template <class T>
int heap<T>::parent(int x) {
    return (floor(x / 2));
}

template <class T>
int heap<T>::left(int x) {
    return (2 * x);
}

template <class T>
int heap<T>::right(int x) {
    return ((2 * x) + 1);
}

template <class T>
T heap<T>::getItem(int x) {
    return heapList[x];
}

template <class T>
void heap<T>::initializeMaxHeap(vector <T> list)
{
    heapList.push_back("");
    for (int i = 0; i < list.size(); i++) {
        heapList.push_back(list[i]);
        heapSize++;
    }
}

template <class T>
void heap<T>::maxHeapify(int i) {
    T temp;
    int largest;
    int l = left(i);
    int r = right(i);
    if ((l <= heapSize) && (heapList[l] > heapList[i]))
        largest = l;
    else
        largest = i;
    if ((r <= heapSize) && (heapList[r] > heapList[largest]))
        largest = r;
    if (largest != i) {
        temp = heapList[largest];
        heapList[largest] = heapList[i];
        heapList[i] = temp;
        maxHeapify(largest);
    }
}

template <class T>
void heap<T>::buildMaxHeap() {
    for (int i = floor(heapSize / 2); i >= 1; i--) {
        maxHeapify(i);
    }
}

template <class T>
void heap<T>::heapsort() {
    T temp;
    buildMaxHeap();
    for (int i = heapSize; i >= 2; i--) {
        temp = heapList[1];
        heapList[1] = heapList[i];
        heapList[i] = temp;
        heapSize = heapSize - 1;
        maxHeapify(1);
    }
}

template <class T>
void heap<T>::printHeap() {
    for (int i = 0; i < heapList.size(); i++) {
        cout << heapList[i] << endl;
    }
}

#endif /* heap_h */
