#include <iostream>
#include <stdexcept>
#include "PQueue.h"
using namespace std;

int main() {


    int array[] = {2, 4, 5, 6, 7, 8, 9, 10};
    PQueue<int> pq1(array, 8);
    cout << "pq1 = " << pq1 << endl;







    return 0;
}