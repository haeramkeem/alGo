#include <iostream>
#include <vector>

using namespace std;

#define TOOFAST ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

int N;
vector<int> cache;
int rec(vector<int>& vec, const int& cur) {
    if(cache[cur] != 1) {
        return cache[cur];
    }
    int nmax = 0;
    for(int i = cur + 1; i < N; i++) {
        if(vec[cur] < vec[i] && nmax < rec(vec, i)) {
            nmax = rec(vec, i);
        }
    }
    return cache[cur] = nmax + 1;
}

int main() {
    TOOFAST;
    cin >> N;

    vector<int> vec(N);
    for(int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    cache.resize(N, 1);
    int nmax = 1;
    for(int i = 0; i < N; i++) {
        nmax = max(nmax, rec(vec, i));
    }
    cout << nmax << '\n';

    return 0;
}
