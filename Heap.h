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

template <class T>
class Heap
{
private:
    T*      array;          // Dynamically allocated array for heap
    int     capacity;       // Size of the array
    int     size;           // Current number of elements in the heap

    void resize();          // Resize the array when full

public:
                Heap        ( void );                   // Default constructor
                Heap        ( const Heap& other );      // Copy constructor
                // int parameter - idk what im reading
                // array/size parameter constructor


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
    // ? How can i make sense for capacity here...? maybe 0?

}


// Other constructor that im lazy to implement now


// Destructor
template <class T>
Heap<T>::~Heap(void) {
    delete[] array;     // Release the dynamically allocated array
}


// 







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


#endif