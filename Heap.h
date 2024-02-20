//========================================================
// * Author       : 
// * Purpose      : 
// * Date Created : 2024-02-13
// * Last Update  : 2024-02-14
//========================================================
#include <iostream>
#include <string>
#include <stdexcept> 
using namespace std;

#ifndef HEAP_H
#define HEAP_H

// ? Can I do this?
#define DEFAULT_HEAP_CAPACITY 10

template <class T>
class Heap
{
private:
    T*      heap;          // Dynamically allocated array for heap
    int     capacity;       // Size of the array
    int     size;           // Current number of elements in the heap

    void resize();          // Resize the array when full

public:
                Heap        ( void );                   // Default constructor
                Heap        ( const Heap& other );      // Copy constructor
                Heap        ( int specified_capacity ); // Specified parameter constructor
                Heap        ( int array[], int size);   // Array/size paramters constructor
                ~Heap       ( void );                   // Destructor
    Heap&       operator=   ( const Heap& other );      // Assignment Operator overload
    void        heapify     ( int index );              
    void        buildHeap   ( void );                   // Build the heap from an unsorted array
    void        heapSort    ( void );                   // Sort an array using heap structure
    void        increaseKey ( int index, T value );     // Increase the value of an element of the heap
    void        insert      ( T element );              // Insert an element to current heap
    int         length      ( void ) const;             // Return the number of elements in heap
    bool        empty       ( void ) const;             // Check if the heap is empty
    
    // throw an exception and terminate the program if max/extract from empty heap
    T           max         ( void ) const;             // Return the max element in the heap
    T           extract     ( void );                   // Remove and return the max element in the heap


    // friend func - the correct version



    


};

// Default constructor
template <class T>
Heap<T>::Heap(void) {
    capacity = DEFAULT_HEAP_CAPACITY;
    heap = new T[capacity];
    size = 0;
}

// Copy constructor
template <class T>
Heap<T>::Heap(const Heap<T> &other) {
    capacity = other.capacity;
    size = other.size;
    heap = new T[capacity];
    for (int i = 0; i < size; i++) {
        heap[i] = other.heap[i];
    }  
}

// Int parameter constructor
template <class T>
Heap<T>::Heap(int specified_capacity) {
    capacity = specified_capacity;
    size = 0;
    heap = new T[capacity];
}

// Array/Size Parameters
template <class T>
Heap<T>::Heap(int a[], int size) {
    pass;
}


// Destructor
template <class T>
Heap<T>::~Heap(void) {
    delete[] heap;     // Release the dynamically allocated array
    size = 0;           // Reset the size of the heap
}


// Overloaded assignment operator
template <class T>
Heap& Heap<T>::operator=(const Heap& other) {
    size  = other.size;
    capacity = other.capacity; 

    heap = new T[capacity]; // allocate new memory
    for (int i = 0; i < size; i++) 
        heap[i] = other.heap[i]; // copy elements from myarray

    delete[] heap; // deallocate current memory

    return *this;  // return a reference to this object
}


// ! Document
template <class T>
int Heap<T>::length(void) const {
    return size;
}

// ! Document
template <class T>
bool Heap<T>::empty(void) const {
    return size == 0;
}


// ! Document
template <class T>
T Heap<T>::max(void) const {
    if (size == 0) 
        throw std::out_of_range("Heap is empty.")
    return data[0];
}


// ! Document
template <class T>
T Heap<T>::extract(void) {
    // Check if the heap is valid for extract
    if (size == 0)
        throw std::out_of_range("Heap is empty.")

    // Create a new element to store the max value in heap
    T maxElement = data[0];

    // Move the last element of the heap to root and decrease size
    data[0] = data[size - 1];
    size--;

    // Call Heapify at root to restore the max-heap property
    heapify(0);

    // Return the max element
    return maxElement;
}

template <class T>
void Heap<T>::heapify(int index, int size){
T l = left(index);
T r = right(index);

if (l <= size && heap[l] > heap[index]){
    largest = l;
} else{
    largest = index;
}
if (r <= size && heap[r] > heap[largest]){
    largest = r;
}
if (largest != index){
    T temp = heap[index];
    heap[index] = heap[largest];
    heap[largest] = temp;

    heapify(largest);
}
}

template <class T>
void Heap<T>::buildHeap(void){
    for(int i = size/2; i >= 0; i--){
        heapify(i);
    }
}

template <class T>
void Heap<T>::heapSort(void) {
    buildHeap();
    for (int i = size - 1; i >= 1; i--) {
        T temp = heap[0];  // Corrected index from 1 to 0
        heap[0] = heap[i];
        heap[i] = temp;
        heapify(0, i);  // Corrected index from 1 to 0
    }
}

//void        increaseKey ( int index, T value );  

#endif