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
    cout << "b. Valid Parameter Passing" << endl;
    Heap<int> heapi4(10);
    cout << "heapi4 = " << heapi4 << endl;

    //========================================================
    // 4. Testing Int Parameter Constructor   





    return 0;
}

/*
        // Test default constructor
        Heap<int> h1;
        std::cout << "h1 = " << h1 << std::endl;

        // Test constructor with array and size parameters
        int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
        int arrSize = sizeof(arr) / sizeof(arr[0]);
        Heap<int> h2(arr, arrSize);
        std::cout << "h2 = " << h2 << std::endl;

        // Test copy constructor
        Heap<int> h3 = h2;
        std::cout << "h3 = " << h3 << std::endl;

        // Test heapify and buildHeap
        h2.heapify(0, 9);
        std::cout << "h2 after heapify = " << h2 << std::endl;
        h3.buildHeap();
        std::cout << "h3 after buildHeap = " << h3 << std::endl;

        // Test increaseKey and insert
        h3.increaseKey(4, 10);
        std::cout << "h3 after increaseKey = " << h3 << std::endl;
        h3.insert(7);
        std::cout << "h3 after insert = " << h3 << std::endl;

        // Test length, empty, max, and extract
        std::cout << "Length of h3: " << h3.length() << std::endl;
        std::cout << "Is h3 empty? " << (h3.empty() ? "Yes" : "No") << std::endl;
        std::cout << "Max item in h3: " << h3.max() << std::endl;
        std::cout << "Extracted max item from h3: " << h3.extract() << std::endl;
        std::cout << "h3 after extraction = " << h3 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
*/