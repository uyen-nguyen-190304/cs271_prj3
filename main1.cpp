#include <iostream>
#include <stdexcept>
#include "Heap.h"
using namespace std;

int main() {
    //========================================================
    // I. Test method for int heap
    cout << "*********************************************************************" << endl;
    cout << "I. Testing different methods for int heap" << endl;
    

    //========================================================
    // 1. Testing Default Constructor
    cout << "1. Testing Default Constructor" << endl;

    // Create a new empty integer heap
    Heap<int> heapi1;                        // heapi1 = [ ]
    cout << "heapi1 = " << heapi1 << endl;

    //========================================================
    // 2. Testing Copy Constructor
    cout << "2. Testing Copy Constructor" << endl;
    
    // a. Create a copy of an empty heap
    cout << "a. Create a copy of an empty heap" << endl;
    Heap<int> heapi2(heapi1);       // heapi2 = heapi1 = [ ]
    cout << "heapi2 = " << heapi2 << endl;

    // b. Create a copy of a nonempty list
    cout << "b. Create a copy of a nonempty heap" << endl;
    for (int i = 10; i >= 1; i--) 
        heapi1.insert(i);           // heapi1 = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    Heap<int> heapi3(heapi1);       // heapi3 = heapi1 = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    cout << "heapi3 = " << heapi3 << endl;

    //========================================================
    // 3. Testing Int Parameter Constructor
    cout << "3. Testing Int Parameter Constructor" << endl;

    // a. Invalid Parameter
    cout << "a. Invalid Parameter Passing" << endl;
    try {
        cout << "i. Passing 0 as capacity parameter" << endl;
        Heap<int> heapi4(0);
    } catch (...) {
        cout << "0 is not a valid capacity for heap array." << endl;
    }

    try {
        cout << "ii. Passing negative number as capacity parameter" << endl;
        Heap<int> heapi4(-5);
    } catch (...) {
        cout << "-5 is not a valid capacity for heap array." << endl;
    }

    // b. Valid Parameter 
    cout << "b. Valid Parameter Passing (a positive integer as capacity parameter)" << endl;
    Heap<int> heapi4(10);
    cout << "heapi4 = " << heapi4 << endl;

    //========================================================
    // 4. Testing Array/Size Parameters Constructor
    cout << "4. Testing Array/Size Parameters Constructor" << endl;

    // a. Invalid Parameter
    cout << "a. Invalid Parameter Passing" << endl;
    try {
        cout << "i. Passing an empty array" << endl;
        int a[0];
        Heap<int> heapi5(a, 0);
    } catch (...) {
        cout << "An empty array is not a valid input" << endl;
    }

    try {
        cout << "ii. Passing 0 as the arraySize " << endl;
        int a[0];
        Heap<int> heapi5(a, -5);
    } catch (...) {
        cout << "0 is not a valid array size" << endl;
    }

    try {
        cout << "iii. Passing a negative arraySize" << endl;
        int a[0];
        Heap<int> heapi5(a, -5);
    } catch (...) {
        cout << "-5 is not a valid capacity for heap array." << endl;
    }

    /*
    try {
        cout << "iii. Passing an array with its wrong size" << endl;
        int a[5] = {1, 2, 3, 4, 5};
        Heap<int> heapi5(a, 4);
    } catch (...) {
        cout << "Mismatch between length of array and arraySize" << endl;
    }
    */

    // b. Valid Parameter
    cout << "b. Valid Parameter Passing (a nonempty array with its size)" << endl;
    int a[5] = {1, 2, 3, 4, 5};
    Heap<int> heapi5(a, 5);
    cout << "heapi5 = " << heapi5 << endl;

    //========================================================
    // 5. Testing destructor

    //========================================================
    // 6. Testing Assignment Operator
    cout << "6. Testing Assignment Operator" << endl;
    // a. Self Assignment
    cout << "a. Self Assignment" << endl;
    int b[5] = {10, 9, 7, 6, 5};
    Heap<int> heapi6(b, 5);
    cout << "heapi6 = " << heapi6 << endl;
    heapi6 = heapi6; 
    cout << "heapi6 = heapi6 = " << heapi6 << endl;
 
    // b. Copy Assignment
    cout << "b. Copy Assignment" << endl;
    Heap<int> heapi7 = heapi6; 
    cout << "heapi7 = heapi6 = " << heapi7 << endl;

    // c. Empty to Non-Empty Assignment
    cout << "c. Empty to Non-Empty Assignment" << endl;
    Heap<int> heapi8;  // Empty heap
    cout << "heapi6 = " << heapi6 << endl;
    cout << "heapi8 = " << heapi8 << endl;
    heapi6 = heapi8;
    cout << "heapi6 = heapi8 = " << heapi8 << endl;

    // d. Non-Empty to Empty Assignment
    cout << "d. Non-Empty to Empty Assignment" << endl;
    heapi8 = heapi7;
    cout << "heapi8 = heapi7 = " << heapi8 << endl;

    // e. Chaining Assignments
    cout << "f. Chaining Assignments" << endl;
    heapi6 = heapi7 = heapi8;
    cout << "heapi6 = heapi7 = heapi8 " << endl;
    cout << "heapi6 = " << heapi6 << endl;
    cout << "heapi7 = " << heapi7 << endl;
    cout << "heapi8 = " << heapi8 << endl;

    //========================================================
    // 7. Testing heapify()
    cout << "7. Testing heapify()" << endl;

     // a. Invalid Parameters
    cout << "a. Invalid Parameters Passing" << endl;
    try {
        cout << "i. Passing a negative number as the index" << endl;
        heapi6.heapify(-1,5);
    } catch (...) {
        cout << "-1 is not a vaid index" << endl;
    }

    try {
        cout << "ii. Passing size of the sub-heap to be heapified > size of the whole heap" << endl;
        heapi6.heapify(2,6);
    } catch (...) {
        cout << "The size sub-heap to be heapified is larger than size of the whole heap" << endl;
    }

    try {
        cout << "iii. Passing the index of the node to be heapified >= size of the heap to be heapified" << endl;
        heapi6.heapify(6,5);
    } catch (...) {
        cout << "The index of the node to be heapified is at least size of the heap to be heapified" << endl;
    }

    // b. Valid Parameter
    cout << "b. Valid Parameter Passing (valid index and size of the heap)" << endl;
    heapi6.heapSort();
    cout << "heapi6 after sorted = " << heapi6 << endl;
    heapi6.heapify(0, 5);
    cout << "heapi6 after calling heapify() at index 0 = " << heapi6 << endl;
    heapi6.heapify(1, 5);
    cout << "heapi6 after calling heapify() at index 1 = " << heapi6 << endl;

    //========================================================
    // 8. Testing buildHeap()
    cout << "8. Testing buildHeap()" << endl;

    // Build heap with an already sorted heap
    cout << "a. Build heap with a valid heap" << endl;
    cout << "heapi7 = " << heapi7 << endl;
    heapi7.buildHeap();
    cout << "heapi7 = " << heapi7 << endl;
    
    // Build heap with a reverse sorted heap
    cout << "b. Build heap with a reverse sorted heap" << endl;
    heapi7.heapSort();
    cout << "sorted heapi7 = " << heapi7 << endl;
    heapi7.buildHeap();
    cout << "heapi7 = " << heapi7 << endl;

    // Build heap with an randomly sorted heap
    cout << "c. Build heap with a randomly ordered heap" << endl;
    cout << "heapi6 = " << heapi6 << endl;
    heapi6.buildHeap();
    cout << "heapi6 = " << heapi6 << endl;
    
    //========================================================
    // 9. Testing heapSort()
    cout << "9. Testing heapSort()" << endl;

    // Heap sort with a valid heap
    cout << "a. Sort a valid heap" << endl;
    cout << "heapi6 = " << heapi6 << endl;
    heapi6.heapSort();
    cout << "heapi6 = " << heapi6 << endl;

    // Heap sort with an randomly sorted heap
    cout << "b. Sort a randomly ordered heap" << endl;
    heapi6.heapSort();
    heapi6.heapify(0, 5);
    cout << "heapi6 = " << heapi6 << endl;
    heapi6.heapSort();
    cout << "heapi6 = " << heapi6 << endl;
    return 0;

}

