#include <iostream>

using namespace std;

int main() {

    /**
     * Reference type is simillar with normal type, but it act like this:
     *     declaring variable by pointer, and using variable by dereferencing pointer.
     *     so refernce type do not use additional memory.
     */

    int nNormal = 1;
    int& nReference = nNormal; // Reference type must be initiated when declare.

    cout << (nNormal == nReference) << endl; // They have same value. result is 1(true).
    cout << (&nNormal == &nReference) << endl; // They have same address. result is 1(true).

    return 0;
}