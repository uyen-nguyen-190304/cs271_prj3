//==========================================================================================
// * Author       : Yen Nguyen, Uyen Nguyen
// * Purpose      : Test Driver for Priority Queue Implementation
// * Date Created : 2024-02-13
// * Last Update  : 2024-02-22
//==========================================================================================
#include <iostream>
#include <stdexcept>
#include <string>
#include "PQueue.h"
using namespace std;

int main() {
    //========================================================
    // 1. Testing Default Constructor
    cout << "*********************************************************************" << endl;
    cout << "1. Testing Default Constructor" << endl;

    // Create a new empty integer pqueue
    PQueue<int> pqi1;                            // pqi1 = [ ]
    cout << "- PQueue<int> pqi1: pqi1 = " << pqi1 << endl;

    PQueue<float> pqf1;                          // pqf1 = [ ]
    cout << "- PQueue<float> pqf1: pqf1 = " << pqf1 << endl;


    //========================================================
    // 2. Testing Copy Constructor
    cout << "********************************************************" << endl;
    cout << "2. Testing Copy Constructor" << endl;

    // a. Create a copy of an empty pqueue
    cout << "a. Create a copy of an empty pqueue" << endl;
    PQueue<int> pqi2(pqi1);                       // pqi2 = pqi1 = [ ]
    cout << "- PQueue<int> pqi2(pqi1): pqi2 = " << pqi2 << endl;

    PQueue<float> pqf2(pqf1);                     // pqf2 = pqf1 = [ ]
    cout << "- PQueue<float> pqf2(pqf1): pqf2 = " << pqf2 << endl;

    // b. Create a copy of a nonempty pqueue
    cout << "b. Create a copy of a nonempty pqueue" << endl;
    for (int i = 5; i > 0; i--)
        pqi1.enqueue(i);                          // pqi1 = [5, 4, 3, 2, 1]
    PQueue<int> pqi3(pqi1);                       // pqi3 = pqi1 = [5, 4, 3, 2, 1]
    cout << "- PQueue<int> pqi3(pqi1): " << pqi3 << endl;

    for (int i = 5; i > 0; i--)
        pqf1.enqueue(i + 0.1*i);                  // pqf1 = [5.5, 4.4, 3.3, 2.2, 1.1]
    PQueue<float> pqf3(pqf1);                     // pqf3 = pqf1 = [5.5, 4.4, 3.3, 2.2, 1.1]
    cout << "- PQueue<float> pqf3(pqf1): " << pqf3 << endl;


    //========================================================
    // 3. Testing Array/Size Parameters Constructor
    cout << "********************************************************" << endl;
    cout << "3. Testing Array/Size Parameters Constructor" << endl;

    // a. Invalid Parameter
    cout << "a. Invalid Parameter Passing" << endl;
    try {
        cout << "i. Passing empty int array for int pqueue" << endl;
        int a[1];                                  // empty array: a = [ ]
        PQueue<int> pqi4(a, 0);
    } catch (const std::exception& e) {
        cerr << "- PQueue<int> pqi4(a, 0): Exception caught (" << e.what() << ")" << endl;
    }

    try {
        cout << "ii. Passing empty float array for float pqueue" << endl;
        float a[1];                                // empty array: a = [ ]
        PQueue<float> pqf4(a, 0);
    } catch (const std::exception& e) {
        cerr << "- PQueue<float> pqf4(a, 0): Exception caught (" << e.what() << ")" << endl;
    }

    try {
        cout << "iii. Passing invalid size parameter for int pqueue" << endl;
        int a[5] = {1, 2, 3, 4, 5};
        PQueue<int> pqi4(a, 0);
    } catch (const std::exception& e) {
        cerr << "- PQueue<int> pqi4(a, 0): Exception caught (" << e.what() << ")" << endl;
    }

    try {
        cout << "iv. Passing invalid size parameter for float pqueue" << endl;
        float a[5] = {1.5, 2.5, 3.5, 4.5, 5.5};
        PQueue<float> pqf4(a, -5);
    } catch (const std::exception& e) {
        cerr << "- PQueue<float> pqf4(a, -5): Exception caught (" << e.what() << ")" << endl;
    }

    // b. Valid Parameters
    cout << "b. Valid Parameter Passing" << endl;
    int ai[5] = {6, 7, 8, 9, 10};
    PQueue<int> pqi4(ai, 5);                         // pqi4 = [10, 9, 8, 7, 6]
    cout << "- PQueue<int> pqi4(ai, 5): pqi4 = " << pqi4 << endl;

    float af[7] = {3.1, 9.5, -2.3, 1.5, -3.4, 0.2, 1.9};
    PQueue<float> pqf4(af, 7);                       // pqf4 = [9.5, 3.1, 1.9, 1.5, 0.2, -2.3, -3.4]
    cout << "- PQueue<float> pqf4(af, 7): pqf4 = " << pqf4 << endl;


    //========================================================
    // 4. Tesing Destructor
    cout << "********************************************************" << endl;
    cout << "4. Testing Destructor" << endl;
    {
        cout << "i. Testing destructor for int pqueue" << endl;
        PQueue<int> pqi5;
    } // pqi5 should already be destructed here
    cout << "- pqi5 no longer exists outside the block" << endl;
    
    {
        cout << "ii. Testing destructor for float pqueue" << endl;
        PQueue<float> pqf5;
    } // pqj5 should alreay be destructed here
    cout << "- pqj5 no longer exists outside the block" << endl;


    //========================================================
    // 5. Testing Assignment Operator Overload
    cout << "********************************************************" << endl;
    cout << "5. Testing Assignment Operator Overload" << endl;

    // a. Self-assignment
    cout << "a. Self-assignment" << endl;
    pqi4 = pqi4;                                     // pqi4 = [10, 9, 8, 7, 6]
    cout << "- pqi4 = pqi4: pqi4 = " << pqi4 << endl;

    pqf4 = pqf4;
    cout << "- pqf4 = pqf4: pqf4 = " << pqf4 << endl;

    // b. Copy Assignment 
    cout << "b. Copy Assignment" << endl;
    PQueue<int> pqi5 = pqi4;                        // pqi5 = pqi4 = [10, 9, 8, 7, 6]
    cout << "- pqi5 = pqi4: pqi5 = " << pqi5 << endl;

    PQueue<float> pqf5 = pqf4;                      // pqf5 = pqf4 = [9.5, 3.1, 1.9, 1.5, 0.2, -2.3, -3.4]
    cout << "- pqf5 = pqf4: pqf5 = " << pqf5 << endl;

    // c. Assignment from empty pqueue to nonempty pqueue
    cout << "c. Assignment from empty to nonempty pqueue" << endl;
    pqi3 = pqi2;                                    // pqi3 = pqi2 = [ ]
    cout << "- pqi3 = pqi2: pqi3 = " << pqi3 << endl;

    pqf3 = pqf2;                                    // pqf3 = pqf2 = [ ]
    cout << "- pqf3 = pqf2: pqf3 = " << pqf3 << endl;

    // d. Assignment from nonempty pqueue to empty pqueue
    cout << "d. Assignment from nonempty to empty pqueue" << endl; 
    pqi2 = pqi1;                                    // pqi2 = pqi1 = [5, 4, 3, 2, 1]
    cout << "- pqi2 = pqi1: pqi2 = " << pqi2 << endl;

    pqf2 = pqf1;                                    // pqf2 = pqf1 = [5.5, 4.4, 3.3, 2.2, 1.1]
    cout << "- pqf2 = pqf1: pqf2 = " << pqf2 << endl; 

    // e. Chain Assignment
    cout << "e. Chain Assignment" << endl;  
    pqi2 = pqi3 = pqi4;                             // pqi2 = pqi3 = pqi4 = [10, 9, 8, 7, 6]
    cout << "- pqi2 = pqi3 = pqi4: pqi2 = " << pqi2 << ", pqi3 = " << pqi3 << ", pqi4 = " << pqi4 << endl;

    pqf2 = pqf3 = pqf4;
    cout << "- pqf2 = pqf3 = pqf4: pqf2 = " << pqf2 << ", pqf3 = " << pqf3 << ", pqf4 = " << pqf4 << endl;


    //========================================================
    // 6. Testing Enqueue
    cout << "********************************************************" << endl;
    cout << "6. Testing Enqueue" << endl;

    // a. Enqueue an element that is larger than any of the current element
    cout << "a. Enqueue an element that is larger than any of the current element" << endl;
    pqi5.enqueue(100);                              // pqi5 = [100, 10, 9, 8, 7, 6]
    cout << "- pqi5.enqueue(100): pqi5 = " << pqi5 << endl;

    pqf5.enqueue(54.3);                             // pqf5 = [54.3, 9.5, 3.1, 1.9, 1.5, 0.2, -2.3, -3.4]
    cout << "- pqf5.enqueue(54.3): pqf5 = " << pqf5 << endl;

    // b. Enqueue an element that is smaller than any of the current element
    cout << "b. Enqueue an element that is smaller than any of the current element" << endl;
    pqi5.enqueue(-23);                              // pqi5 = [100, 10, 9, 8, 7, 6, -23]
    cout << "- pqi5.enqueue(-23): pqi5 = " << pqi5 << endl;

    pqf5.enqueue(-49.6);                            // pqf5 = [54.3, 9.5, 3.1, 1.9, 1.5, 0.2, -2.3, -3.4, -49.6]
    cout << "- pqf5.enqueue(-49.6): pqf5 = " << pqf5 << endl;

    // c. Enqueue an element with average priority
    cout << "c. Enqueue an element with average priority" << endl;
    pqi5.enqueue(5);                                // pqi5 = [100, 10, 9, 8, 7, 6, 5, -23]
    cout << "- pqi5.enqueue(5): pqi5 = " << pqi5 << endl;

    pqf5.enqueue(2.8);                              // pqf5 = [54.3, 9.5, 3.1, 2.8, 1.9, 1.5, 0.2, -2.3, -3.4, -49.6]
    cout << "- pqj5.enqueue(28): pqj5 = " << pqf5 << endl;


    //========================================================
    // 7. Testing Length
    cout << "********************************************************" << endl;
    cout << "7. Testing Enqueue" << endl;

    // a. Length of an empty pqueue
    PQueue<int> pqi6;                               // pqi6 = [ ]
    cout << "- pqi6.length() = " << pqi6.length() << endl;

    PQueue<float> pqf6;                             // pqf6 = [ ]
    cout << "- pqf6.length() = " << pqf6.length() << endl;

    // b. Length of a nonempty pqueue
    cout << "- pqi5.length() = " << pqi5.length() << endl;
    cout << "- pqf5.length() = " << pqf5.length() << endl;


    //========================================================
    // 8. Testing Empty
    cout << "********************************************************" << endl;
    cout << "8. Testing Empty" << endl;

    // a. Testing emptiness of an empty pqueue
    cout << "a. Testing emptiness of an empty pqueue" << endl;
    cout << "- Is pqi6 empty? " << (pqi6.empty() ? "Yes" : "No") << endl;
    cout << "- Is pqf6 empty? " << (pqf6.empty() ? "Yes" : "No") << endl;

    // b. Testing emptiness of a nonempty pqueue
    cout << "b. Testing emptiness of a nonempty pqueue" << endl;
    cout << "- Is pqi5 empty? " << (pqi5.empty() ? "Yes" : "No") << endl;
    cout << "- Is pqf5 empty? " << (pqf5.empty() ? "Yes" : "No") << endl;


    //========================================================
    // 9. Testing Peek
    cout << "********************************************************" << endl;
    cout << "9. Testing Peek" << endl;

    // a. Peek of an empty pqueue
    cout << "a. Peek of an empty pqueue" << endl;
    try {
        cout << "- Peek of pqi6: " << pqi6.peek();
    } catch (const std::exception& e) {
        cerr << "Exception caught (" << e.what() << ")" << endl;
    }

    try {
        cout << "- Peek of pqf6: " << pqf6.peek();
    } catch (const std::exception& e) {
        cerr << "Exception caught (" << e.what() << ")" << endl;
    }

    // b. Peek of a nonempty pqueue
    cout << "b. Peek of a nonempty pqueue" << endl;
    cout << "- Peek of pqi4: " << pqi4.peek() << endl;
    cout << "- Peek of pqi5: " << pqi5.peek() << endl;

    cout << "- Peek of pqf4: " << pqf4.peek() << endl;
    cout << "- Peek of pqf5: " << pqf5.peek() << endl;


    //========================================================
    // 10. Testing Dequeue
    cout << "********************************************************" << endl;
    cout << "10. Testing Dequeue" << endl;

    // a. Dequeue an empty pqueue
    cout << "a. Dequeue an empty pqueue" << endl;
    try {
        cout << "- Dequeue pqi6: " << pqi6.dequeue();
    } catch (const std::exception& e) {
        cerr << "Exception caught (" << e.what() << ")" << endl;
    }

    try {
        cout << "- Dequeue pqf6: " << pqf6.dequeue();
    } catch (const std::exception& e) {
        cerr << "Exception caught (" << e.what() << ")" << endl;
    }

    // b. Dequeue nonempty pqueue
    cout << "b. Dequeue nonempty pqueue" << endl;
    PQueue<int> pqi7;
    pqi7.enqueue(10);                               // pqi7 = [10]
    cout << "- Dequeue pqi7: " << pqi7.dequeue() << ", pqi7 after dequeue: " << pqi7 << endl;
    // pqi5 = [100, 10, 9, 8, 7, 6, 5, -23]
    cout << "- Dequeue pqi5: " << pqi5.dequeue() << ", pqi5 after dequeue: " << pqi5 << endl;

    PQueue<float> pqf7;
    pqf7.enqueue(34.5);                               // pqf7 = [34.5]
    cout << "- Dequeue pqf7: " << pqf7.dequeue() << ", pqf7 after dequeue: " << pqf7 << endl;
    // pqf5 = [54.3, 9.5, 3.1, 2.8, 1.9, 1.5, 0.2, -2.3, -3.4, -49.6]
    cout << "- Dequeue pqf5: " << pqf5.dequeue() << ", pqf5 after dequeue: " << pqf5 << endl;

    cout << "*********************************************************************" << endl;
    return 0;
}
