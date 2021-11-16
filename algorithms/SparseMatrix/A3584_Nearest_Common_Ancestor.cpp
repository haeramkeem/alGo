/**
 * BOJ 3584) https://www.acmicpc.net/problem/3584
 *
 * Nearest Common Anscestor
 *
 * Brute Force Version
 */

#include <iostream>
#include <map>
#include <set>

using namespace std;
#define toofast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

/* ----- Solution ----- */
int main() {
    toofast;
    int tcaseSize;
    cin >> tcaseSize;
    for(int i = 0; i < tcaseSize;i++) {
        int nodeSize;
        cin >> nodeSize;
        map<int, int> conn;
        for(int j = 0; j < nodeSize - 1; j++) {
            int child, par;
            cin >> par >> child;
            conn[child] = par;
        }
        int tar1, tar2;
        cin >> tar1 >> tar2;
        set<int> parent;
        while(conn.count(tar1) != 0) {
            parent.insert(tar1);
            tar1 = conn[tar1];
        }
        while(conn.count(tar2) != 0) {
            if(parent.count(tar2) != 0) {
                cout << tar2 << '\n';
                break;
            }
            tar2 = conn[tar2];
        }
        if(tar1 == tar2) {
            cout << tar1 << '\n';
         }
    }

    return 0;
}
