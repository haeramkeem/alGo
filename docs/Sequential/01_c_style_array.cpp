#include <iostream>
using namespace std;

int main() {

    // Declare static array. It vanishes when block ends.
    int staticArray[5];

    // Declare and allocate dynamic array.
    int* dynamicArray = new int[5];

    // Deallocate dynamic array
    delete[] dynamicArray;

    return 0;
}