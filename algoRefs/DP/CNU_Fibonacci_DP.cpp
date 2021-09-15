/**
 * Fall2021-CNU-algorithm
 * 
 * Fibonacci numbers
 * 
 * Dynamic Programming
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int nNum) {
    if(nNum <=  1) {
        return 1;
    } else {
        vector<int> vecFibonacci(nNum, 1);
        for(int i = 2; i < nNum; i++) {
            vecFibonacci[i] = vecFibonacci[i - 1] + vecFibonacci[i - 2];
            cout << vecFibonacci[i] << endl;
        }
        return vecFibonacci[nNum - 1];
    }
}

int main() {
    int nNum;
    cin >> nNum;
    cout << fibonacci(nNum) << endl;
}
