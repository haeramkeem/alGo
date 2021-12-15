/**
 * BOJ 11053) https://www.acmicpc.net/problem/11053
 *
 * Longest Increasing Subsequence(LIS)
 *
 * Well known solution
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define TOOFAST ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

int main() {
    TOOFAST;
    int N;
    cin >> N;

    vector<int> vec(N);
    for(int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    vector<int> cache;
    for(const auto& num : vec) {
        if(cache.empty() || cache.back() < num) {
            // When number is bigger than last element of the cache, push it.
            cache.push_back(num);
        } else {
            // Find a lower bound of that number and replace it with current number.
            *lower_bound(cache.begin(), cache.end(), num) = num;
        }
    }

    cout << cache.size() << '\n';

    return 0;
}
