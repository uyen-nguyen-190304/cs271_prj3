#include <iostream>
#include <stdexcept>
#include "PQueue.h"
using namespace std;

int main() {
     //========================================================
    // I. Test method for int pqueue
    cout << "*********************************************************************" << endl;
    cout << "I. Testing different methods for int pqueue" << endl;
    

    //========================================================
    // 1. Testing Default Constructor
    cout << "*********************************************************************" << endl;
    cout << "1. Testing Default Constructor" << endl;

    // Create a new empty integer pqueue
    {
    PQueue<int> pq1;                            // pq1 = [ ]
    cout << "- PQueue<int> pq1: pq1 = " << pq1 << endl;
    }

    //========================================================
    // 2. Testing Copy Constructor
    cout << "*************************************************" << endl;
    cout << "2. Testing Copy Constructor" << endl;

    // a. Create a copy of an empty pqueue
    {
    cout << "a. Create a copy of an empty pqueue" << endl;
    PQueue<int> pq1;
    PQueue<int> pq2(pq1);                       // pq2 = [ ]
    cout << "- PQueue<int> pq2(pq1): pq2 = " << pq2 << endl;
    }

    // b. Create a copy of a nonempty pqueue
    { 
    cout << "b. Create a copy of a nonempty pqueue" << endl;
    PQueue<int> pq1;                            // pq1 = [ ]
    for (int i = 5; i > 0; i--)
        pq1.enqueue(i);                         // pq1 = [5, 4, 3, 2, 1]
    PQueue<int> pq2(pq1);                       // pq2 = pq1 = [5, 4, 3, 2, 1]
    cout << "- PQueue<int> pq2(pq1): " << pq2 << endl;
    }    

    //========================================================
    // 3. Testing Array/Size Parameters Constructor
    cout << "*************************************************" << endl;
    cout << "3. Testing Array/Size Parameters Constructor" << endl;

    // a. Invalid Parameter
    cout << "a. Invalid Parameter Passing" << endl;
    try {
        cout << "i. Passing empty array as argument" << endl;
        int a[] = {}
        
    }







    return 0;
}