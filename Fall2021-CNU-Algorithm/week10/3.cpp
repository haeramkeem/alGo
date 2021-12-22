#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    // i번째 인덱스의 첫번째 자식은 2 * i + 1 인덱스 이고, 두번째 자식은 2 * i + 2 인덱스가 되게끔 트리를 구성
    vector<int> bst(N);
    for(int i = 0; i < N; i++) {
        cin >> bst[i];
    }

    double target;
    cin >> target;

    int k;
    cin >> k;

    int rounded = round(target);
    int l = rounded - 1, r = rounded + 1;
    vector<int> res(k);
    res[0] = rounded;
    // 노드가 1부터 시작하기 때문에 target이 1보다 작을 경우에 가까운 노드는 1부터 k개의 노드이다
    if(target < 1) {
        for(int i = 0; i < k; i++) {
            res[i] = i + 1;
        }
    } else if(rounded < target) {
        // target이 n.5보다 작을 경우에는 n부터 n + 1, n - 1, n + 2 ... 의 순서대로 가까운 노드가 된다
        for(int i = 1; i < k; i++) {
            if(i % 2 == 0) {
                res[i] = l--;
            } else {
                res[i] = r++;
            }
        }
    } else {
        // target이 n.5보다 클 경우에는 n + 1부터 n, n + 2, n - 1 ... 의 순서대로 가까운 노드가 된다
        for(int i = 1; i < k; i++) {
            if(i % 2 == 0) {
                res[i] = r++;
            } else {
                res[i] = l--;
            }
        }
    }

    for(int i = 0; i < k - 1; i++) {
        cout << res[i] << ' ';
    }
    cout << res.back() << endl;

    return 0;
}
