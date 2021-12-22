#include <iostream>
#include <map>
#include <array>

using namespace std;

map<char, array<char, 2>> conn;

// 전위순회
void post(const char& cur) {
    if(conn[cur][0] != '.') { post(conn[cur][0]); } // 첫번째 자식 방문
    if(conn[cur][1] != '.') { post(conn[cur][1]); } // 두번째 자식 방문
    cout << cur; // 자기자신 방문
}

// 후위순회
void pre(const char& cur) {
    cout << cur; // 자기자신 방문
    if(conn[cur][0] != '.') { pre(conn[cur][0]); } // 첫번째 자식 방문
    if(conn[cur][1] != '.') { pre(conn[cur][1]); } // 두번째 자식 방문
}

// 중위순회
void in(const char& cur) {
    if(conn[cur][0] != '.') { in(conn[cur][0]); } // 첫번째 자식 방문
    cout << cur; // 자기자신 방문
    if(conn[cur][1] != '.') { in(conn[cur][1]); } // 두번째 자식 방문
}

int main() {
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        char f, s, t;
        cin >> f >> s >> t;
        conn[f] = { s, t };
    }

    pre('A');
    cout << endl;
    in('A');
    cout << endl;
    post('A');
    cout << endl;

    return 0;
}
