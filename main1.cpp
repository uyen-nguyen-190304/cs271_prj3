#include <iostream>
#include <stdexcept>
#include "Heap.h"
using namespace std;

int main() {
    
    try {
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
    }

    return 0;
}
