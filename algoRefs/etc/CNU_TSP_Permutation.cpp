/**
 * Fall2021-CNU-algorithm
 * 
 * Travelling Salesman Problem
 * 
 * Permutation algorithm
 * 
 * ref : algorithm/next_permutation, algorithm/sort
 */

#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <cstdlib>
#include <limits.h>

using namespace std;

int distance(array<int, 2> src, array<int, 2> dst) {
    return abs(src[0] - dst[0]) + abs(src[1] - dst[1]);
}

int main() {
    int n, nAcc, min = INT_MAX;
    cin >> n;

    array<int, 2> src, dst;
    cin >> src[0] >> src[1];
    cin >> dst[0] >> dst[1];

    vector< array<int, 2> > nodes;
    for(int i = 0; i < n - 1; i++) {
        array<int, 2> temp;
        cin >> temp[0] >> temp[1];
        nodes.push_back(temp);
    }

    sort(nodes.begin(), nodes.end());

    do {
        nAcc = distance(src, nodes[0]) + distance(dst, nodes[n - 2]);
        for(int i = 0; i < n - 2; i++) {
            nAcc += distance(nodes[i], nodes[i + 1]);
        }
        min = min > nAcc ? nAcc : min;
    } while(next_permutation(nodes.begin(), nodes.end()));

    cout << min << endl;
}