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
    capacity = DEFAULT_HEAP_CAPACITY;
    size = 0;
    array = new T[capacity];
    // ? How can i make sense for capacity here...? maybe 0?
}

// Copy constructor
template <class T>
Heap<T>::Heap (const Heap<T> &myarray){

}
// Other constructor that im lazy to implement now



// Destructor
template <class T>
Heap<T>::~Heap(void) {
    delete[] array;     // Release the dynamically allocated array
}


// Overloaded assignment operator
template <typename T>
List <T> List <T> :: operator= (const List<T> &myarray){
    size  = myarray.size;
    capacity = myarray.capacity; 

    array = new T[capacity]; // allocate new memory
    for (int i = 0; i < size; i++) 
        array[i] = myarray.array[i]; // copy elements from myarray

    delete[] array; // deallocate current memory

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
void Heap<T>::heapify(int index){
T l = left(index);
T r = right(index);

if (l <= size && array[l] > array[index]){
    largest = l;
} else{
    largest = index;
}
if (r <= size && array[r] > array[index]){
    largest = r;
}
if (largest != index){
    T temp = array[index];
    array[index] = array[largest];
    array[largest] = temp;
}
}

template <class T>
void Heap<T>::buildHeap(void){
    for(int i = size/2; i > 1; i = i/2){
        heapify(i);
    }
}

template <class T>
void Heap<T>::heapSort(void){
    buildHeap();
    for(int i = size; i > 2; i--){
        T temp = array[1];
        array[1] = array[i];
        array[i] = temp;
        size--;
        heapify(1);
    }
}         

void        increaseKey ( int index, T value );  

#endif