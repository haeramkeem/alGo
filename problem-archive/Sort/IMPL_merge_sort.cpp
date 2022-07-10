#include <iostream>
#include <vector>

using namespace std;

// Merge left-vector and right-vector to target.
void fnMerge(vector<int>& vecTarget, vector<int>& vecLeft, vector<int>& vecRight) {
    auto lit = vecLeft.begin(), rit = vecRight.begin();
    int i = 0;
    while(lit < vecLeft.end() && rit < vecRight.end() && i < vecTarget.size()) {
        // if value of left-iterator is smaller than right-iterator.
        if(*lit <= *rit) {
            // Put value of left-iterator to target vector.
            //     then move left-iterator.
            vecTarget[i] = *lit; lit++;

            // If iteration of left-vector finished, put all remaining elements of right-vector to target.
            //     then set right-iterator to end. it will break a loop.
            if(lit >= vecLeft.end()) {
                copy(rit, vecRight.end(), vecTarget.begin() + i + 1);
                rit = vecRight.end();
            }

        // if value of right-iterator is smaller than left-iterator
        } else {
            // Put value of right-iterator to target vector.
            //     then move right-iterator.
            vecTarget[i] = *rit; rit++;

            // If iteration of right-vector finished, put all remaining elements of left-vector to target.
            //     then set left-iterator to end. it will break a loop.
            if(rit >= vecRight.end()) {
                copy(lit, vecLeft.end(), vecTarget.begin() + i + 1);
                lit = vecLeft.end();
            }
        }
        i++;
    }
}

// Sort target vector.
void fnSortAsc(vector<int>& vecToSort) {
    // If size of target is smaller than 2, consider it sorted.
    if(vecToSort.size() < 2) { return; }

    // Splits the given vector into two equal pieces.
    int nSep = vecToSort.size() / 2;
    vector<int> vecLeft,vecRight;
    vecLeft.assign(vecToSort.begin(), vecToSort.begin() + nSep);
    vecRight.assign(vecToSort.begin() + nSep, vecToSort.end());

    // Sort left, right vector recursively.
    fnSortAsc(vecLeft);
    fnSortAsc(vecRight);

    // Merge left, right vector into target.
    fnMerge(vecToSort, vecLeft, vecRight);
}

int main() {

    vector<int> vecInts = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    fnSortAsc(vecInts); // result is {1 2 3 4 5 6 7 8 9}

    return 0;
}