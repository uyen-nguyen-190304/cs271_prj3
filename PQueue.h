//==========================================================================================
// * Author       : Yen Nguyen, Uyen Nguyen
// * Purpose      : Implementing Priority Queue using Heap class as private member
// * Date Created : 2024-02-13
// * Last Update  : 2024-02-21
//==========================================================================================
#include <iostream>
#include <stdexcept>
#include "Heap.h"
using namespace std;

#ifndef PQUEUE_H
#define PQUEUE_H

template <class T>
class PQueue {
private:
    Heap<T> heap;

public:
    PQueue();
    PQueue(const PQueue& other);
    PQueue(T a[], int size);
    ~PQueue();
    PQueue& operator=(const PQueue& other);
    void enqueue(T item);
    int length() const;
    bool empty() const;
    T peek() const;
    T dequeue();

    // Friend function for cout << operator overload
    friend ostream& operator<<(ostream& os, const PQueue<T>& pq) {
        if (pq.empty()) {
            // If the priority queue is empty, do nothing and return
            return os;
        }

        // Else, create a temporary priority queue to avoid changing the given pq
        PQueue<T> temp = pq;
        // Then, extract element one by one to print elements with higher priority first
        while (temp.length() > 1) {
            os << temp.dequeue() << " ";
        }
        os << temp.dequeue();
        return os;
    }
};

template <class T>
PQueue<T>::PQueue() {}

template <class T>
PQueue<T>::PQueue(const PQueue& other) : heap(other.heap) {}

template <class T>
PQueue<T>::PQueue(T a[], int size) : heap(a, size) {}

template <class T>
PQueue<T>::~PQueue() {}

template <class T>
PQueue<T>& PQueue<T>::operator=(const PQueue& other) {
    if (this != &other) {
        this->heap = other.heap;
    }
    return *this;
}

template <class T>
void PQueue<T>::enqueue(T item) {
    heap.insert(item);
}

template <class T>
int PQueue<T>::length() const {
    return heap.length();
}

template <class T>
bool PQueue<T>::empty() const {
    return heap.empty();
}

template <class T>
T PQueue<T>::peek() const {
    if (empty()) {
        throw std::out_of_range("Priority Queue is empty");
    }
    return heap.max();
}

template <class T>
T PQueue<T>::dequeue() {
    if (empty()) {
        throw std::out_of_range("Priority Queue is empty.");
    }
    return heap.extract();
}

#endif // PQUEUE_H
