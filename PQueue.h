//==========================================================================================
// * Author       : Yen Nguyen, Uyen Nguyen
// * Purpose      : Implementing Priority Queue using Heap class as private member
// * Date Created : 2024-02-13
// * Last Update  : 2024-02-22
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
                PQueue      ( void );
                PQueue      ( const PQueue& other );
                PQueue      ( T a[], int size );
                ~PQueue     ( void );
    PQueue&     operator=   ( const PQueue& other );
    void        enqueue     ( T item );
    int         length      ( void ) const;
    bool        empty       ( void ) const;
    T           peek        ( void ) const;
    T           dequeue     ( void );


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
//==========================================================================================
// * Method name  : PQueue (default constructor)
// * Purpose      : Initialize a new instance of the PQueue class
// * Parameters   : None
// * Return Value : None
//==========================================================================================
template <class T>
PQueue<T>::PQueue() {}

//==========================================================================================
// * Method name  : PQueue (copy constructor)
// * Purpose      : Create a new PQueue object that is a deep copy of an existing PQueue object
// * Parameters   : const PQueue& other - reference to another Priority Queue
// * Return Value : None
//==========================================================================================
template <class T>
PQueue<T>::PQueue(const PQueue& other) : heap(other.heap) {}  // Copy the heap from the other Priority Queue

//==========================================================================================
// * Method name  : PQueue (array & size parameters constructor)
// * Purpose      : Create a new PQueue object with a specified array and its size
// * Parameters   : T a[] - array with elements of type T
// *                 int size - size of the array, specified by the user
// * Return Value : None
//==========================================================================================
template <class T>
PQueue<T>::PQueue(T a[], int size) : heap(a, size) {}  // Create a heap object with the given array and its size

//==========================================================================================
// * Method name  : ~PQueue (destructor)
// * Purpose      : Destroy the PQueue object and release it allocated memory
// * Parameters   : None
// * Return Value : None
//==========================================================================================
template <class T>
PQueue<T>::~PQueue() {} 

//==========================================================================================
// * Method name  : operator=  (overload assignment operator)
// * Purpose      : Copy a specified priority queue to our PQueue object
// * Parameters   : const PQueue& other - reference to another Priority Queue
// * Return Value : Reference to the current Priority Queue
//==========================================================================================
template <class T>
PQueue<T>& PQueue<T>::operator=(const PQueue& other) {
    // Check for self-assignment. If yes, do nothing and return the object itself
    if (this != &other) {
        // Otherwise, safely assign the heap from the other Priority Queue
        this->heap = other.heap; 
    }
    return *this;
}

//==========================================================================================
// * Method name  : enqueue
// * Purpose      : Insert an element into the Priority Queue
// * Parameters   : T item - the item to be inserted
// * Return Value : None
//==========================================================================================
template <class T>
void PQueue<T>::enqueue(T item) {
    // Insert the element into the underlying Heap
    heap.insert(item); 
}

//==========================================================================================
// * Method name  : length
// * Purpose      : Get the number of elements in the Priority Queue
// * Parameters   : None
// * Return Value : int (the current size of the Priority Queue)
//==========================================================================================
template <class T>
int PQueue<T>::length() const {
    // Return the length of the underlying Heap
    return heap.length();
}

//==========================================================================================
// * Method name  : empty
// * Purpose      : Check if the Priority Queue is empty
// * Parameters   : None
// * Return Value : bool (return true if the Priority Queue is empty, false otherwise)
//==========================================================================================
template <class T>
bool PQueue<T>::empty() const {
    // Check if the underlying Heap is empty
    return heap.empty(); 
}

//==========================================================================================
// * Method name  : peek
// * Purpose      : Get the highest priority element in the Priority Queue without removing it
// * Parameters   : None
// * Return Value : T (the highest priority element)
//==========================================================================================
template <class T>
T PQueue<T>::peek() const {
    // Check if the Priority Queue is empty before retrieving the highest priority element
    if (empty()) {
        throw std::out_of_range("Priority Queue is empty");
    }
    // Return the highest priority element from the underlying Heap
    return heap.max(); 
}

//==========================================================================================
// * Method name  : dequeue
// * Purpose      : Remove and return the highest priority element from the Priority Queue
// * Parameters   : None
// * Return Value : T (the highest priority element)
//==========================================================================================
template <class T>
T PQueue<T>::dequeue() {
    // Check if the Priority Queue is empty before dequeue
    if (empty()) {
        throw std::out_of_range("Priority Queue is empty");
    }
    // Remove and return the highest priority element from the underlying Heap
    return heap.extract();
}

#endif // PQUEUE_H
