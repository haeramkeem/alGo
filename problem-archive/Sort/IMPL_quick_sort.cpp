#include <iostream>
#include <vector>

using namespace std;

// Swaps the two values ​​pointed to by the iterators.
void fnSwap(vector<int>::iterator it1, vector<int>::iterator it2) {
    int nTemp = *it1;
    *it1 = *it2;
    *it2 = nTemp;
}

// Sort vector placed between two iterators
void fnQuick(vector<int>::iterator hit, vector<int>::iterator tit) {
    // If size of vector is under 1, return immediately.
    if(tit - hit < 1) { return; }

    // Set pivot to the head, left iterator to head + 1, and right iterator to tail - 1.
    auto pit = hit, lit = hit + 1, rit = tit - 1;

    // Repeat while left iterator is smaller than right iterator.
    while(lit < rit) {

        // Find first value that bigger than pivot.
        while(*pit >= *lit && lit < tit) { lit++; }

        // Find last value that smaller than pivot.
        while(*pit <= *rit && rit > hit) { rit--; }

        // If left iterator is smaller than right iterator, swap two values of iterators.
        if(lit < rit) { fnSwap(lit, rit); }
    }

    // Swap values of right iterator and pivot. And set pivot to the right iterator.
    //     reason for swapping pivot with right iterator is that if right iterator is smaller than left iterator,
    //     that means there are no more elements to be swapped between left and right iterators.
    //     so, all the elements between pivot and right iterator(including element of right iterator) are smaller than value of pivot.
    //     and all the elements after left iterator(including element of left iterator) are bigger than value of pivot.
    //     thus, result of swapping pivot and right iterator is like this:
    //          { <-- Elements smaller than pivot --> PIVOT <-- Elements bigger than pivot --> }
    //
    // And it doesn't matter whether the right iterator moves to the head.
    //     because after swapping, size of sub vector between head and pivot is 0, so recursive sorting process gonna be ignored.
    fnSwap(rit, pit);
    pit = rit;

    // Sort left subvector and right subvector recursively.
    fnQuick(hit, pit);
    fnQuick(pit + 1, tit);
}

int main() {

    vector<int> vecInts = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    fnQuick(vecInts.begin(), vecInts.end()); // result is {1, 2, 3, 4, 5, 6, 7, 8, 9}

    return 0;
}