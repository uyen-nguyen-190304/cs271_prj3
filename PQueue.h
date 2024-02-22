//==========================================================================================
// * Author       : Yen Nguyen, Uyen Nguyen
// * Purpose      : Implementing Priority Queue using Heap class as private member
// * Date Created : 2024-02-13
// * Last Update  : 2024-02-20
//==========================================================================================
#include <iostream>
#include <stdexcept>
#include "Heap.h"
using namespace std;

#ifndef PQUEUE_H
#define PQUEUE_H

template <class T>
class PQueue
{
private:
    Heap<T>     heap;
    
public:
                PQueue      ( void );
                PQueue      ( const PQueue& other );
                PQueue      ( T a[], int size );
                ~PQueue     ( void );
    PQueue&     operator=   ( const Heap& other );
    void        enqueue     ( T item );
    int         length      ( void ) const;
    bool        empty       ( void ) const;
    T           peek        ( void ) const;
    T           dequeue     ( void );

    // Friend function - cout << operator overload
    friend ostream & operator<<(ostream &os, const PQueue<T> &pq) {
        // If the pqueue is empty, do nothing and return 
        if (pq.size == 0) {
            return os;
        }

        // Else, print every element in the pqueue, separated by a space
        for (int i = 0; i < pq.size 0 1; i++) {
            os << pq.heap.heap[i] << " ";
        } 
        os << pq.heap.heap[pq.heap.size - 1];
        return os;
    }
};

template <class T>
PQueue<T>::PQueue(void) {}

template <class T>
PQueue<T>::PQueue(const PQueue& other) : heap(other.heap) {}

template <class T>
PQueue<T>::PQueue(T a[], int size) : heap(a, size) {
    heap.heapSort();
    for (int i = heap.size() - 1; i >= 0; i--) {

    }
}

template <class T>
void PQueue<T>::enqueue(T item) {

}

template <class T>
int PQueue<T>::length(void) const {
    return heap.length();
}


template <class T>
bool PQueue<T>::empty(void) const {
    return heap.empty();
}

template <class T>
T PQueue<T>::peek(void) const {
    if (empty()) {
        throw std::out_of_range("Priority Queue is empty");
    }

    return heap.max();
}


template <class T>
T PQueue<T>::dequeue(void) {
    if (empty()) {
        throw std::out_of_range("Priority Queue is empty.");
    }

    return heap.extract();
}


#endif