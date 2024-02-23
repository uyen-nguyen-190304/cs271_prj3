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
    cout << "- Heap<float> heapf1: heapf1 = " << heapf1 << endl << endl;


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
    
    for (int i = 10; i >= 1; i--)
        heapf1.insert(i + 0.5);                 // heapf1 = [10.5, 9.5, 8.5, 7.5, 6.5, 5.5, 4.5, 3.5, 2.5, 1.5]
    Heap<float> heapf3(heapf1);                 // heapf3 = heapf1 = [10.5, 9.5, 8.5, 7.5, 6.5, 5.5, 4.5, 3.5, 2.5, 1.5]
    cout << "- Heap<float> heapf3(heapf1): heapf3 " << heapf3 << endl << endl;
    

    //========================================================
    // 3. Testing Int Parameter Constructor
    cout << "**********************************************************" << endl;
    cout << "3. Testing Int Parameter Constructor" << endl;

    // a. Invalid Parameter
    cout << "a. Invalid Parameter Passing" << endl;
    
    // i. Passing 0 as capacity parameter
    try {
        cout << "i. Passing 0 as capacity parameter" << endl;
        Heap<int> heapi4(0);
        cout << "- Heap<int> heapi4(0): " << heapi4 << endl;
    } catch (const std::exception& e) {
        cout << "- Heap<int> heapi4(0): Exception caught (" << e.what() << ")" << endl;
    }

    try {
        Heap<float> heapf4(0);
        cout << "- Heap<float> heapf4(0) " << heapf4 << endl;
    } catch (const std::exception& e) {
        cout << "- Heap<float> heapf4(0): Exception caught (" << e.what() << ")" << endl;
    }

    // ii. Passing negative number as capacity parameter
    try {
        cout << "ii. Passing negative number as capacity parameter" << endl;
        Heap<int> heapi4(-5);
        cout << "- Heap<int> heapi4(-5): " << heapi4 << endl;
    } catch (const std::exception& e) {
        cout << "- Heap<int> heapi4(-5): Exception caught (" << e.what() << ")" << endl;
    }

    try {
        Heap<float> heapf4(-324);
        cout << "- Heap<float> heapf4(-324): " << heapf4 << endl;
    } catch (const std::exception& e) {
        cout << "- Heap<float> heapf4(-324): Exception caught (" << e.what() << ")" << endl;
    }

    // b. Valid Parameter 
    cout << "b. Valid Parameter Passing (a positive integer as capacity parameter" << endl;
    Heap<int> heapi4(10);                       // heapi4 = [ ]
    cout << "- Heap<int> heapi4(10): heapi4 = " << heapi4 << endl;

    Heap<int> heapf4(15);                       // heapf4 = [ ]
    cout << "- Heap<int> heapf4(15): heapf4 = " << heapf4 << endl << endl;


    //========================================================
    // 4. Testing Array/Size Parameters Constructor
    cout << "**********************************************************" << endl;
    cout << "4. Testing Array/Size Parameters Constructor" << endl;

    // a. Invalid Parameter
    cout << "a. Invalid Parameter Passing" << endl;

    // i. Passing Null Pointer
    try {
        cout << "i. Passing Null Pointer" << endl;
        Heap<int> heapi5(nullptr, 0);
        cout << "- Heap<int> heapi5(nullptr, 0): heapi5 = " << heapi5 << endl;
    } catch (const std::exception& e) {
        cout << "- Heap<int> heapi5(nullptr, 0): Exception caught (" << e.what() << ")" << endl;
    }

    try {
        Heap<float> heapf5(nullptr, 0);
        cout << "- Heap<float> heapf5(nullptr, 0): heapf5 = " << heapf5 << endl;
    } catch (const std::exception& e) {
        cout << "- Heap<float> heapf5(nullptr, 0): Exception caught (" << e.what() << ")" << endl;    }

    // ii. Passing Negative arraySize
    try {
        cout << "ii. Passing Negative arraySize " << endl;
        int a[5] = {5, 4, 3, 2, 1};
        Heap<int> heapi5(a, -5);
        cout << "- Heap<int> heapi5(a, -5): heapi5 = " << heapi5 << endl;
    } catch (const std::exception& e) {
        cout << "- Heap<int> heapi5(a, -5): Exception caught (" << e.what() << ")" << endl;
    } 

    try {
        float a[8] = {5.5, 4.5, 3.5, 2.5, 1.5, 0.5, -1.5, -2.5};
        Heap<float> heapf5(a, -8); 
        cout << "- Heap<float> heapf5(a, -8): heapf5 = " << heapf5 << endl;
    } catch (const std::exception& e) {
        cout << "- Heap<float> heapf5(a, -8): Exception caught (" << e.what() << ")" << endl;
    }

    // b. Valid Parameter
    cout << "b. Valid Parameter Passing" << endl;

    // i. Passing an empty array with size 0
    cout << "i. Passing an empty array with size 0" << endl;
    int ai1[0] = {};
    Heap<int> heapi5(ai1, 0);                   // heapi5 = [ ]
    cout << "- Heap<int> heapi5(ai1, 0): heapi5 = " << heapi5 << endl;

    float af1[0] = {};
    Heap<float> heapf5(af1, 0);                 // heapf5 = [ ]
    cout << "- Heap<float> heapf5(af1, 0): heapf5 = " << heapf5 << endl;

    // ii. Passing a nonempty array
    cout << "ii. Passing a nonempty array" << endl;
    int ai2[5] = {10, 9, 8, 7, 6};              // heapi6 = [10, 9, 8, 7, 6]
    Heap<int> heapi6(ai2, 5);
    cout << "- Heap<int> heapi6(ai2, 5): heapi6 = " << heapi6 << endl;
    
    float af2[9] = {10.9, 9.8, 8.7, 7.6, 6.5, 5.4, 4.3, 3.2, 2.1};
    Heap<float> heapf6(af2, 9);                 // heapf6 = [10.9, 9.8, 8.7, 7.6, 6.5, 5.4, 4.3, 3.2, 2.1]
    cout << "- Heap<float> heapf6(af2, 9): heapf6 = " << heapf6 << endl << endl;
    

    //========================================================
    // 5. Testing destructor
    cout << "**********************************************************" << endl;
    cout << "5. Testing Destructor" << endl;
    {
        cout << "a. Testing Destructor for Int Heap" << endl;
        Heap<int> heapi7;
    } // heapi7 should already be destructed here
    cout << "- heapi7 no longer exists outside the block" << endl;

    {
        cout << "b. Testing Destructor for Float Heap" << endl;
        Heap<float> heapf7;
    } // heapf7 should already be destructed here
    cout << "- heapf7 no longer exists outside the block" << endl << endl;


    //========================================================
    // 6. Testing Assignment Operator
    cout << "**********************************************************" << endl;
    cout << "6. Testing Assignment Operator" << endl;

    // a. Self Assignment
    cout << "a. Self Assignment" << endl;
    int bi[5] = {10, 9, 7, 6, 5};
    Heap<int> heapi7(bi, 5);                        // heapi7 = [10, 9, 7, 6, 5]
    heapi7 = heapi7;                                
    cout << "- heapi7 = heapi7: heapi7 = " << heapi7 << endl;
 
    float bf[8] = {3.7, 2.9, 6.4, 9.4, 1.8, 7.5, 4.9, 5.9};
    Heap<float> heapf7(bf, 8);                      // heapf7 = [9.4, 5.9, 7.5, 3.7, 1.8, 6.4, 4.9, 2.9]
    heapf7 = heapf7;
    cout << "- heapf7 = heapf7: heapf7 = " << heapf7 << endl;

    // b. Copy Assignment
    cout << "b. Copy Assignment" << endl;
    Heap<int> heapi8 = heapi7;                      // heapi8 = heapi7 = [10, 9, 7, 6, 5]
    cout << "- Heap<int> heapi8 = heapi7: heapi8 = " << heapi8 << endl;

    Heap<float> heapf8 = heapf7;                    // heapf8 = heapf7 = [9.4, 5.9, 7.5, 3.7, 1.8, 6.4, 4.9, 2.9]
    cout << "- Heap<float> heapf8 = heapf7: heapf8 = " << heapf8 << endl;   

    // c. Assign Empty to Nonempty Heap
    cout << "c. Empty to Non-Empty Assignment" << endl;
    heapi6 = heapi5;                                // heapi6 = heapi5 = [ ]
    cout << "- heapi6 = heapi5: heapi6 =  " << heapi6 << endl;

    heapf6 = heapf5;                                // heapf6 = heapf5 = [ ]
    cout << "- heapf6 = heapf5: heapf6 = " << heapf6 << endl;

    // d. Assign Non-Empty to Empty Heap
    cout << "d. Non-Empty to Empty Assignment" << endl;
    heapi6 = heapi7;                                // heapi6 = heapi7 = [10, 9, 7, 6, 5]           
    cout << "- heapi6 = heapi7: heapi6 = " << heapi6 << endl;

    heapf6 = heapf7;                                // heapf6 = heapf7 = [9.4, 5.9, 7.5, 3.7, 1.8, 6.4, 4.9, 2.9]
    cout << "- heapf6 = heapf7: heapf6 = " << heapf6 << endl;
 
    // e. Chaining Assignments
    cout << "f. Chaining Assignments" << endl;
    heapi5 = heapi6 = heapi7;                       // heapi5 = heapi6 = heapi7 = [10, 9, 7, 6, 5]
    cout << "- heapi5 = heapi6 = heapi7: heapi5 = " << heapi5 << ", heapi6 = " << heapi6 << ", heapi7 = " << heapi7 << endl;

    heapf5 = heapf6 = heapf7;                       // heapf5 =  heapf6 = heapf7 = [9.4, 5.9, 7.5, 3.7, 1.8, 6.4, 4.9, 2.9]
    cout << "- heapf5 = heapf6 = heapf7: heapf5 = " << heapf5 << ", heapf6 = " << heapf6 << ", heapf7 = " << heapf7 << endl << endl;


    //========================================================
    // 7. Testing heapify()
    cout << "**********************************************************" << endl;
    cout << "7. Testing heapify()" << endl;

     // a. Invalid Parameters
    cout << "a. Invalid Parameters Passing" << endl;

    // i. Passing a negative number as index
    try {
        cout << "i. Passing a negative number as index" << endl;
        heapi6.heapify(-1, 5);
        cout << "- heapi6.heapify(-1,5): heapi6 = " << heapi6 << endl; 
    } catch (...) {
        cout << "- heapi6.heapify(-1,5): Exception caught (-1 is not a vaid index)" << endl;
    }

    try {
        heapf6.heapify(-5, 5);
        cout << "- heapf6.heapify(-5, 5): heapf6 = " << heapf6 << endl; 
    } catch (...) {
        cout << "- heapf6.heapify(-5, 5): Exception caught (-5 is not a valid index)" << endl;
    }

    // ii. Passing negative number of size of sub-heap
    try {
        cout << "ii. Passing negative number of size of sub-heap" << endl;
        heapi6.heapify(0, -3);
        cout << "- heapi6.heapify(0, -3): heapi6 = " << heapi6 << endl;
    } catch (...) {
        cout << "- heapi6.heapify(0, -3): Exception caught (-3 is not a valid size for sub-heap)" << endl;
    }

    try {
        heapf6.heapify(0, -5);
        cout << "- heapf6.heapify(0, -5): heapf6 = " << heapf6 << endl;
    } catch (...) { 
        cout << "- heapf6.heapify(0, -5): Exception caught (-5 is not a valid size for sub-heap)" << endl;
    }

    // iii. Passing size of the sub-heap to be heapified > size of the whole heap
    try {
        cout << "iii. Passing size of the sub-heap to be heapified > size of the whole heap" << endl;
        heapi6.heapify(2, 6);
        cout << "- heapi6.heapify(2, 6): heapi6 = " << heapi6 << endl;
    } catch (...) {
        cout << "- heapi6.heapify(2, 6): Exception caught (size sub-heap is larger than size of the whole heap)" << endl;
    }

    try {
        heapf6.heapify(0, 10);
        cout << "- heapf6.heapify(0, 10): heapf6 = " << heapf6 << endl;
    } catch (...) { 
        cout << "- heapf6.heapify(0, 10): Exception caught (size sub-heap is larger than size of the whole heap)" << endl;
    }

    // iv. Passing the index of the node to be heapified >= size of the heap to be heapified
    try {
        cout << "iii. Passing the index of the node to be heapified >= size of the heap to be heapified" << endl;
        heapi6.heapify(6, 5);
        cout << "- heapi6.heapify(6, 5): heapi6 = " << heapi6 << endl;
    } catch (...) {
        cout << "- heapi6.heapify(6, 5): Exception caught (index of node to be heapified is out of valid bound)" << endl;
    }

    try {
        heapf6.heapify(8, 5);
        cout << "- heapf6.heapify(8, 5): heapf6 = " << heapf6 << endl;
    } catch (...) {
        cout << "- heapf6.heapify(8, 5): Exception caught (index of node to be heapified is out of valid bound)" << endl;
    }

    // b. Valid Parameter
    cout << "b. Valid Parameter Passing (valid index and size of the (sub)-heap)" << endl;

    // i. Heapify an empty heap
    cout << "i. i. Heapify an empty heap" << endl;
    heapi4.heapify(0, 0);                           // heapi4 = [ ]
    cout << "- heapi4.heapify(0, 0): heapi4 = " << heapi4 << endl;

    heapf4.heapify(0, 0);                           // heapf4 = [ ]
    cout << "- heapf4.heapify(0, 0): heapf4 = " << heapf4 << endl;

    // ii. Heapify a nonempty heap
    cout << "ii. Heapify a nonempty heap" << endl;
    heapi6.heapSort();                              // heapi6 = [5, 6, 7, 9, 10]
    cout << "- heapi6 after sorted = " << heapi6 << endl;
    heapi6.heapify(1, 5);                           // heapi6 = [5, 10, 7, 9, 6]
    cout << "- heapi6 after calling heapify() at index 1 = " << heapi6 << endl;
    heapi6.heapify(0, 5);                           // heapi6 = [10, 9, 7, 5, 6]
    cout << "- heapi6 after calling heapify() at index 0 = " << heapi6 << endl;

    heapf6.heapSort();                              // heapf6 = [1.8, 2.9, 3.7, 4.9, 5.9, 6.4, 7.5, 9.4]
    cout << "- heapf6 after sorted = " << heapf6 << endl;   
    heapf6.heapify(3, 8);                           // heapf6 = [1.8, 2.9, 3.7, 9.4, 5.9, 6.4, 7.5, 4.9]
    cout << "- heapf6 after calling heapify() at index 3 = " << heapf6 << endl;
    heapf6.heapify(2, 8);                           // heapf6 = [1.8, 2.9, 7.5, 9.4, 5.9, 6.4, 3.7, 4.9]
    cout << "- heapf6 after calling heapify() at index 2 = " << heapf6 << endl;
    heapf6.heapify(1, 8);                           // heapf6 = [1.8, 9.4, 7.5, 4.9, 5.9, 6.4, 3.7, 2.9]
    cout << "- heapf6 after calling heapify() at index 1 = " << heapf6 << endl;
    heapf6.heapify(0, 8);                           // heapf6 = [9.4, 5.9, 7.5, 4.9, 1.8, 6.4, 3.7, 2.9]
    cout << "- heapf6 after calling heapify() at index 0 = " << heapf6 << endl << endl;


    //========================================================
    // 8. Testing buildHeap()
    cout << "**********************************************************" << endl;
    cout << "8. Testing buildHeap()" << endl;

    // a. Build heap with an already sorted heap
    cout << "a. Build heap with a valid heap" << endl;
    heapi6.buildHeap();                             // heapi6 = [10, 9, 7, 6, 5]
    cout << "- heapi7.buildHeap(): heapi6 = " << heapi6 << endl;

    heapf6.buildHeap();                             // heapf6 = [9.4, 5.9, 7.5, 3.7, 1.8, 6.4, 4.9, 2.9]
    cout << "- heapf6.buildHeap(): heapf6 = " << heapf6 << endl;

    // b. Build heap with a reverse sorted heap
    cout << "b. Build heap with a reverse sorted heap" << endl;
    heapi6.heapSort();                              // heapi6 = [5, 6, 7, 9, 10]
    cout << "- Sorted heapi6: heapi6 = " << heapi6 << endl;
    heapi6.buildHeap();                             // heapi6 = [10, 9, 7, 5, 6]
    cout << "- heapi6.buildHeap(): heapi6 = " << heapi6 << endl;          

    heapf6.heapSort();                              // heapf6 = [1.8, 2.9, 3.7, 4.9, 5.9, 6.4, 7.5, 9.4]
    cout << "- Sorted heapf6: heapf6 = " << heapf6 << endl;
    heapf6.buildHeap();                             // heapf6 = [9.4, 5.9, 7.5, 4.9, 1.8, 6.4, 3.7, 2.9]
    cout << "- heapf6.buildHeap() = " << heapf6 << endl; 

    // c. Build heap with an random order 
    cout << "c. Build heap with a random order array" << endl;
    heapi3.heapSort();                              // heapi3 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    heapi3.heapify(0, 10);                          // heapi3 = [3, 2, 7, 4, 5, 6, 1, 8, 9, 10]                          
    cout << "- heapi3 before buildHeap: heapi3 = " << heapi3 << endl;
    heapi3.buildHeap();                             // heapi3 = [10, 9, 7, 8, 5, 6, 1, 3, 4, 2]
    cout << "- heapi3.buildHeap(): heapi3 = " << heapi3 << endl;

    heapf3.heapSort();                              // heapf3 = [1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5]
    heapf3.heapify(1, 5);                           // heapf3 = [1.5, 5.5, 3.5, 4.5, 2.5, 6.5, 7.5, 8.5, 9.5, 10.5]
    heapf3.heapify(2, 10);                          // heapf3 = [1.5, 5.5, 7.5, 4.5, 2.5, 6.5, 3.5, 8.5, 9.5, 10.5]
    cout << "- heapf3 before buildHeap: heapf3 = " << heapf3 << endl;
    heapf3.buildHeap();                             // heapf3 = [10.5, 9.5, 7.5, 8.5, 5.5, 6.5, 3.5, 1.5, 4.5, 2.5]
    cout << "- heapf3.buildHeap(): heapf3 = " << heapf3 << endl;

    // d. Build heap for an empty heap
    cout << "d. Build empty heap" << endl;
    heapi4.buildHeap();                             // heapi4 = [ ]
    cout << "- heapi4.buildHeap(): heapi4 = " << heapi4 << endl;

    heapf4.buildHeap();                             // heapf4 = [ ]
    cout << "- heapf4.buildHeap(): heapf4 = " << heapf4 << endl << endl;


    //========================================================
    // 9. Testing heapSort()
    cout << "**********************************************************" << endl;
    cout << "9. Testing heapSort()" << endl;

    // a. Heap sort with a valid heap
    cout << "a. Sort a valid heap" << endl;             
    cout << "- heapi6 before heapSort: heapi6 = " << heapi6 << endl;
    heapi6.heapSort();                              // heapi6 = [5, 6, 7, 9, 10]
    cout << "- heapi6.heapSort(): heapi6 = " << heapi6 << endl;

    cout << "- heapf6 before heapSort: heapf6 = " << heapf6 << endl;
    heapf6.heapSort();                              // heapf6 = [1.8, 2.9, 3.7, 4.9, 5.9, 6.4, 7.5, 9.4]
    cout << "- heapf6.heapSort(): heapf6 = " << heapf6 << endl;

    // b. Heap sort with an randomly sorted heap
    cout << "b. Sort a randomly ordered array" << endl;
    heapi3.heapSort();                              // heapi3 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    heapi3.heapify(0, 10);                          // heapi3 = [3, 2, 7, 4, 5, 6, 1, 8, 9, 10]                          
    cout << "- heapi3 before heapSort: heapi3 = " << heapi3 << endl;
    heapi3.heapSort();                              // heapi3 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    cout << "- heapi3.heapSort(): heapi3 = " << heapi3 << endl;

    heapf3.heapSort();                              // heapf3 = [1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5]
    heapf3.heapify(1, 5);                           // heapf3 = [1.5, 5.5, 3.5, 4.5, 2.5, 6.5, 7.5, 8.5, 9.5, 10.5]
    heapf3.heapify(2, 10);                          // heapf3 = [1.5, 5.5, 7.5, 4.5, 2.5, 6.5, 3.5, 8.5, 9.5, 10.5]
    cout << "- heapf3 before heapSort: heapf3 = " << heapf3 << endl;
    heapf3.heapSort();                              // heapf3 = [1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5]
    cout << "- heapf3.heapSort(): heapf3 = " << heapf3 << endl;

    // c. Double heapSort a same heap
    cout << "c. Double heapSort a same heap" << endl;
    heapi6.heapSort();                              // heapi6 = [5, 6, 7, 9, 10]
    heapi6.heapSort();                              // heapi6 = [5, 6, 7, 9, 10]
    cout << "- heapi6 after double heapSort: heapi6 = " << heapi6 << endl;

    heapf6.heapSort();                              // heapf6 = [1.8, 2.9, 3.7, 4.9, 5.9, 6.4, 7.5, 9.4]
    heapf6.heapSort();                              // heapf6 = [1.8, 2.9, 3.7, 4.9, 5.9, 6.4, 7.5, 9.4]
    cout << "- heapf6 after double heapSort: heapf6 = " << heapf6 << endl << endl;


    //========================================================
    // 10. Testing increaseKey
    cout << "**********************************************************" << endl;
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



    return 0;


   

}

