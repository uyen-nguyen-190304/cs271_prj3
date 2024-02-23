//==========================================================================================
// * Author       : Yen Nguyen, Uyen Nguyen
// * Purpose      : Test Driver for Heap Implementation
// * Date Created : 2024-02-13
// * Last Update  : 2024-02-22
//==========================================================================================
#include <iostream>
#include <stdexcept>
#include "Heap.h"
using namespace std;

int main() {
    //========================================================
    // 1. Testing Default Constructor
    cout << "*********************************************************************" << endl;
    cout << "1. Testing Default Constructor" << endl;

    // Create a new empty integer heap
    Heap<int> heapi1;                           // heapi1 = [ ]
    cout << "- Heap<int> heapi1: heapi1 = " << heapi1 << endl;

    Heap<float> heapf1;                         // heapf1 = [ ]
    cout << "- Heap<float> heapf1: heapf1 = " << heapf1 << endl;


    //========================================================
    // 2. Testing Copy Constructor
    cout << "**********************************************************" << endl;
    cout << "2. Testing Copy Constructor" << endl;
    
    // a. Create a copy of an empty heap
    cout << "a. Create a copy of an empty heap" << endl;
    Heap<int> heapi2(heapi1);                   // heapi2 = heapi1 = [ ]
    cout << "- Heap<int> heapi2(heapi1): heapi2 = " << heapi2 << endl;

    Heap<float> heapf2(heapf1);                 // heapf2 = heapf1 = [ ]
    cout << "- Heap<float> heapf2(heapf1): heapf2 = " << heapf2 << endl;

    // b. Create a copy of a nonempty list
    cout << "b. Create a copy of a nonempty heap" << endl;
    for (int i = 10; i >= 1; i--) 
        heapi1.insert(i);                       // heapi1 = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    Heap<int> heapi3(heapi1);                   // heapi3 = heapi1 = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    cout << "- Heap<int> heapi3(heapi1): heapi3 = " << heapi3 << endl;
    
    for (int i = 10; i >= 5; i--)
        heapf1.insert(i + 0.5);                 // heapf1 = [10.9, 9.8, 8.7, 7.6, 6.5, 5.4]
    Heap<float> heapf3(heapf1);       // heapf3 = heapf1 = [10.9, 9.8, 8.7, 7.6, 6.5, 5.4]
    cout << "Float Heap: heapf3 = " << heapf3 << endl;
    

    //========================================================
    // 3. Testing Int Parameter Constructor
    cout << "**********************************************************" << endl;
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

    //========================================================
    // 10. Testing increaseKey
    /*
    cout << "10. Testing increaseKey" << endl;

    int a[5] = {5, 4, 3, 2, 1};
    Heap<int> heapi1(a, 5);
    // a. Invalid Parameter
    cout << "a. Invalid Parameter Passing" << endl;
    
    try {
        cout << "i. Passing negative index" << endl;
        heapi1.increaseKey(-5, 23);
    } catch (...) {
        cout << "heapi1.increaseKey(-5, 23): -5 is not a valid index value." << endl;
    }

    try {
        cout << "ii. Passing index larger than actual heap size" << endl;
        heapi1.increaseKey(8, 17);
    } catch (...) {
        cout << "heapi1.increaseKey(8, 17): index 8 is out of heap bound." << endl;
    }

    // b. Set the node at a given index by smaller value
    cout << "b. Set node by smaller value" << endl;
    try {
        heapi1.increaseKey(2, -10);
    } catch (...) {
        cout << "heapi1.increaseKey(2, -10): New key (10) is smaller than current key (3) at index 2." << endl; 
    }
    */
}

