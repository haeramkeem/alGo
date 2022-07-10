#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

// 방문한 노드를 저장할 배열
int visitedDFS[13] = {};
int visitedBFS[13] = {};
// 방문 결과를 저장할 배열
vector<string> vecDFS;
vector<string> vecBFS;

void dfs(map<string, vector<string>> mMap, string cur) {
    // 방분한 노드를 저장
    vecDFS.push_back(cur);
    // 인접노드 배열을 저장
    auto els = mMap[cur];
    // 인접노드를 뒤에서부터 탐색
    for(auto it = els.rbegin(); it != els.rend(); it++) {
        // 만약 방문하지 않은 노드일때
        if(visitedDFS[(*it)[0] - 'A'] != 1) {
            // 방문함으로 바꿔주고
            visitedDFS[(*it)[0] - 'A'] = 1;
            // 다음노드를 방문
            dfs(mMap, *it);
        }
    }
}

void bfs(map<string, vector<string>> mMap, string start) {
    // 큐를 생성하고 첫번째 노드를 큐에 넣어줌
    queue<string> q;
    q.push(start);
    visitedBFS[start[0] - 'A'] = 1;
    while(!q.empty()) {
        // 큐의 헤드를 pop하여 현재 노드를 얻어옴
        string h = q.front();
        q.pop();
        // 현재 노드를 방문 목록에 추가함
        vecBFS.push_back(h);
        // 현재 노드와 인접 노드를 순회함
        for(const auto& el : mMap[h]) {
            // 만약 방문하지 않은 노드일때
            if(visitedBFS[el[0] - 'A'] != 1) {
                // 방문함으로 바꿔주고
                visitedBFS[el[0] - 'A'] = 1;
                // 해당 노드를 큐에 넣어줌
                q.push(el);
            }
        }
    }
}

int main() {
    string chStart;
    cin >> chStart;
    map<string, vector<string>> mMap;
    
    // input을 받음
    for(int i = 0; i < 13; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string key, val;
        getline(ss, key, ' ');
        mMap[key] = {};
        while(getline(ss, val, ' ')) {
            mMap[key].push_back(val);
        }
    }
    
    // BFS로 노드들을 순회하여 그의 결과를 저장함
    bfs(mMap, chStart);

    // 첫번째 노드를 방문했음으로 바꿔주고 DFS로 노드들을 순회하여 그의 결과를 저장함
	visitedDFS[chStart[0] - 'A'] = 1;
    dfs(mMap, chStart);
    
    // BFS에 대해 방문한 노드들을 출력함
    for(int i = 0; i < 12; i++) {
        cout << vecBFS[i] << ' ';
    }
    cout << vecBFS[12] << endl;
    
    // DFS에 대해 방문한 노드들을 출력함
    for(int i = 0; i < 12; i++) {
        cout << vecDFS[i] << ' ';
    }
    cout << vecDFS[12] << endl;

    
    return 0;
}