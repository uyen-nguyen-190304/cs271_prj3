//==========================================================================================
// * Author       : Yen Nguyen, Uyen Nguyen
// * Purpose      : Implementing Max-Heap Data Structure using Dynamically Allocated Arrays
// * Date Created : 2024-02-13
// * Last Update  : 2024-02-22
//==========================================================================================
#include <iostream>
#include <stdexcept> 
using namespace std;

#ifndef HEAP_H
#define HEAP_H

#define DEFAULT_HEAP_CAPACITY 20

template <class T>
class Heap
{
private:
    T*      heap;           // Dynamically allocated array for heap
    int     capacity;       // Size of the array
    int     size;           // Current number of elements in the heap

    void        resize      ( void );                       // Resize the array when full

public:
                Heap        ( void );                       // Default constructor
                Heap        ( const Heap& other );          // Copy constructor
                Heap        ( int givenCapacity );          // Specified capacity parameter constructor
                Heap        ( T array[], int arraySize );   // Array & size paramters constructor
                ~Heap       ( void );                       // Destructor
    Heap&       operator=   ( const Heap& other );          // Assignment Operator overload
    void        heapify     ( int index, int N );           // Maintain heap-max property   
    void        buildHeap   ( void );                       // Build the heap from an unsorted array
    void        heapSort    ( void );                       // Sort an array using heap structure
    void        increaseKey ( int index, T value );         // Increase the value of an element of the heap
    void        insert      ( T element );                  // Insert an element to current heap
    int         length      ( void ) const;                 // Return the number of elements in heap
    bool        empty       ( void ) const;                 // Check if the heap is empty
    T           max         ( void ) const;                 // Return the max element in the heap
    T           extract     ( void );                       // Remove and return the max element in the heap

    // Friend function - cout << operator overload
    friend ostream & operator<<(ostream &os, const Heap<T> &other) {
        // If the heap is empty, do nothing and return
        if (other.size == 0) {
            return os;
        }
        
        // Else, print every element in the heap, separated by a space
        for (int i = 0; i < other.size - 1; i++) {
            os << other.heap[i] << " ";
        }
        os << other.heap[other.size - 1];
        return os;
    }
};

//==========================================================================================
// * Method name  : resize
// * Purpose      : Resize the array that stores the heap to double its current capacity
// * Parameters   : None
// * Return Value : None
//==========================================================================================
template <class T>
void Heap<T>::resize(void) {
    // Create a new heap array with double the current capacity
    T *newHeap = new T[capacity * 2];

    // Copy existing elements from the old heap to the new heap
    for (int i = 0; i < size; i++) {
        newHeap[i] = heap[i]; 
    }

    // Release the memory allocated to the old heap
    delete [] heap;

    // Point the heap pointer to the newly allocated array
    heap = newHeap;

    // Update the capacity to the new, doubled value
    capacity *= 2;
}


//==========================================================================================
// * Method name  : Heap (default constructor)
// * Purpose      : Initialize a new instance of the Heap class with default capacity
// * Parameters   : None
// * Return Value : None
//==========================================================================================
template <class T>
Heap<T>::Heap(void) {
    // Set the initial capacity to the default capacity
    capacity = DEFAULT_HEAP_CAPACITY;

    // Allocate memory for the heap array based on initial capacity
    heap = new T[capacity];

    // Setting size to 0, indicating an empty array
    size = 0;
}


//==========================================================================================
// * Method name  : Heap (copy constructor)
// * Purpose      : Create a new Heap object that is a deep copy of an existing Heap object
// * Parameters   : const Heap<T>  &other (a reference to the Heap object that is to be copied)
// * Return Value : None
//==========================================================================================
template <class T>
Heap<T>::Heap(const Heap<T> &other) {
    // Copy the capacity and size from the 'other' heap
    capacity = other.capacity;
    size = other.size;

    // Allocating memory for the heap array based on the copied capacity
    heap = new T[capacity];

    // Deep copy the elements from the 'other' heap to this heap
    for (int i = 0; i < size; i++) {
        heap[i] = other.heap[i];
    } 
}


//==========================================================================================
// * Method name  : Heap (int parameter constructor)
// * Purpose      : Create a new Heap object with a specified capacity
// * Parameters   : int givenCapacity (initial capacity for the heap, specified by the user)
// * Return Value : None
//==========================================================================================
template <class T>
Heap<T>::Heap(int givenCapacity) {
    // Check if the given parameter is valid (givenCapacity > 0)
    if (givenCapacity <= 0) {
        throw std::invalid_argument("Invalid capacity for heap array");
    }
    
    // Set the capacity to given value
    capacity = givenCapacity;

    // Allocate memory the heap array based on the specified capacity
    heap = new T[capacity];

    // Initialized the size of the heap to 0, indicating that the heap is current empty
    size = 0;
}


//==========================================================================================
// * Method name  : Heap (array & size parameters constructor)
// * Purpose      : Create a new Heap object with a specified array and its size
// * Parameters   : T a[] (an array with elements of type T)
// *                int arraySize (size of the given array, specified by the user)
// * Return Value : None
//==========================================================================================
template <class T>
Heap<T>::Heap(T a[], int arraySize) {
    // Validate the input array and size
    if (a == nullptr || arraySize < 0) {
        throw std::invalid_argument("Invalid array or size");
    }

    // Initialized the heap's size with the size of the provided array
    size = arraySize;

    // Decide the capacity for the heap
    if (arraySize < DEFAULT_HEAP_CAPACITY) {
        capacity = DEFAULT_HEAP_CAPACITY;
    } else {
        capacity = static_cast<int>(arraySize * 1.5);
    } 

    // Allocate memory for the heap with the specified capacity
    heap = new T[capacity];

    // Copy elements from the input array to the heap array
    for (int i = 0; i < size; i++) {
        heap[i] = a[i];
    }
    
    // Organize the copied elements into a valid heap structure
    buildHeap();
}


//==========================================================================================
// * Method name  : ~Heap (destructor)
// * Purpose      : Destroy the Heap object and release it allocated memory
// * Parameters   : None
// * Return Value : None
//==========================================================================================
template <class T>
Heap<T>::~Heap(void) {
    // Release the dynamically allocated array
    delete[] heap;    

    // Reset the size of the heap
    size = 0;           
}


//==========================================================================================
// * Method name  : operator= (overload assignment operator)
// * Purpose      : Copy a specified heap to our heap object
// * Parameters   : const Heap& other (the heap object from which to copy)
// * Return Value : Heap& (a reference to this heap object)
//==========================================================================================
template <class T>
Heap<T>& Heap<T>::operator=(const Heap& other) {
    // Check for self-assignment. If yes, do nothing and return the object itself
    if (this == &other) {
        return *this;
    }

    // Release the existing memory to prevent memory leaks before reallocating
    delete[] heap;

    // Copy the size and capacity from the source object
    size  = other.size;
    capacity = other.capacity; 

    // Allocate new memory for the heap array with the copied capacity
    heap = new T[capacity];
    
    // Deep copy elements from the source heap to the current heap
    for (int i = 0; i < size; i++) {
        heap[i] = other.heap[i]; 
    }

    // Return a reference to the current object
    return *this;  
}


//==========================================================================================
// * Method name  : heapify 
// * Purpose      : Ensures the subtree rooted at the given index holds the max-heap property
// * Parameters   : int index (the index of the current node in the heap array)
// *                int N (the size of the heap or the subset of the heap to be heapified)
// * Return Value : None
//==========================================================================================
template <class T>
void Heap<T>::heapify(int index, int N ) {
    // If the (sub)-heap is empty, heapify does nothing, so it will return and terminate the function
    if (N == 0) {
        return;
    }
    // Validate input parameters to ensure they are within valid range 
    if (index < 0 || N < 0 || N > size || index >= N) {
        throw std::invalid_argument("Invalid index or N out of bounds.");
    }

    // First, assume that the node at index index is the largest
    int largest = index;

    // Calculate the index of the left and right children of the node at index index
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    // If the left child exists and is greater than the current node, update largest
    if (left <= N - 1 && heap[left] > heap[index]) {
        largest = left;
    }

    // If the right child exists and is greater than the largest so far, update largest
    if (right <= N - 1 && heap[right] > heap[largest]) {
        largest = right;
    }

    // If the largest is not the current node, swap it with the largest and recursively heapify to ensure max-heap property
    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapify(largest, N);        
    }
}


//==========================================================================================
// * Method name  : buildHeap 
// * Purpose      : Transform the current unordered array into a valid max heap
// * Parameters   : None
// * Return Value : None
//==========================================================================================
template <class T>
void Heap<T>::buildHeap(void) {
    // Heapify from the last non-leaf node all the way up to the root node
    for (int i = (size / 2) - 1; i >= 0; i--) {
        // Apply heapify to each non-leaf node to ensure the subtree rooted at 'i' satisfied max-heap property
        heapify(i, size);
    }
}


//==========================================================================================
// * Method name  : heapSort 
// * Purpose      : Sort the elements in ascending order using heap sort algorithm
// * Parameters   : None
// * Return Value : None
//==========================================================================================
template <class T>
void Heap<T>::heapSort(void) {
    // Transform the unsorted array into a max heap
    buildHeap();

    // Iteractively recude the heap size by one and sort the array from the end backwards
    for (int i = size - 1; i >= 1; i--) {
        // Swap the maximum element (the root) with the last element in the unsorted part of the array
        swap(heap[0], heap[i]);

        // Apply heapify to the root element to ensure the remaining unsorted part of the array maintains the max-heap property
        heapify(0, i);  
    }
}


//==========================================================================================
// * Method name  : increaseKey 
// * Purpose      : Set the node at the specified index to a given higher value and maintains the max-heap property
// * Parameters   : int index (the index of the node to be updated)
// *                T value (the value that will be assigned to the specified node)
// * Return Value : None
//==========================================================================================
template <class T>
void Heap<T>::increaseKey(int index, T value) {
    // Check if the given index is of valid value
    if (index < 0 || index >= size) {
        throw std::invalid_argument("Invalid index to increase key.");
    }

    // Check if the new value is smaller than the current value at the index. If so, throw an exception
    if  (value < heap[index]) {
        throw std::logic_error("New key is smaller than current key");
    }

    // Update the element's value at the given index to the new, higher value
    heap[index] = value; 

    // Adjust the heap upwards if needed to maintain max-heap property
    while (index > 0 && heap[(index - 1)/2] < heap[index]) {
        // If the parent of the current node is smaller than the node itself, swap the two nodes
        swap(heap[(index - 1)/2], heap[index]);

        // Move up to the parent index for the next iteration
        index = (index - 1)/2;
    }
}


//==========================================================================================
// * Method name  : insert 
// * Purpose      : Add a new element to the heap while ensuring the max-heap property
// * Parameters   : T element (the new element to be added to the heap)
// * Return Value : None
//==========================================================================================
template <class T>
void Heap<T>::insert(T element) {
    // Check if the heap has reached its current capacity to resize if needed
    if(size == capacity) {
        resize();
    }

    // Place the new element at the next available position in the heap
    // Set the element's value to one less than its actual value to ensure it can be increased and properly positioned through increaseKey()
    heap[size] = element - 1; 

    // Correctly position and set the new node to its intended value using increaseKey(), then increase size to account for new element just added
    increaseKey(size++, element);
}


//==========================================================================================
// * Method name  : length 
// * Purpose      : Return the current number of elements in the heap
// * Parameters   : None
// * Return Value : int (the current size of the heap)
//==========================================================================================
template <class T>
int Heap<T>::length(void) const {
    // Return the current size of the heap
    return size;
}


//==========================================================================================
// * Method name  : empty 
// * Purpose      : Check if the heap is empty
// * Parameters   : None
// * Return Value : bool (return true if the heap is empty, false otherwise)
//==========================================================================================
template <class T>
bool Heap<T>::empty(void) const {
    // Check if the size of the heap is 0
    return size == 0;
}


//==========================================================================================
// * Method name  : max 
// * Purpose      : Return the maximum element from the heap
// * Parameters   : None
// * Return Value : T (the maximum element in the heap of type T)
//==========================================================================================
template <class T>
T Heap<T>::max(void) const {
    // Check if the heap is empty before retrieving the maximum element
    if (size == 0) {
        throw std::out_of_range("Heap is empty");
    }

    // Return the element at the root of the heap, which is the maximum element in a max-heap
    return heap[0];
}


//==========================================================================================
// * Method name  : extract
// * Purpose      : Extract and return the maximum element from the heap
// * Parameters   : None
// * Return Value : T (the maximum element in the heap of type T)
//==========================================================================================
template <class T>
T Heap<T>::extract(void) {
    // Check if the heap is empty before extraction
    if (size == 0)
        throw std::out_of_range("Heap is empty.");

    // Store the maximum element (the root) of the heap to return later
    T maxElement = heap[0];

    // Move the last element of the heap to root and decrease size
    heap[0] = heap[size- 1];
    size--;

    // Call Heapify at root to restore the max-heap property if the heap now is not empty 
    if (size != 0)
        heapify(0, size);

    // Return the previously stored maximum element
    return maxElement;
}

#endif
