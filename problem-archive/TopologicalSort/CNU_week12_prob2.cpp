#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

#define umap unordered_map
#define uset unordered_set

int main() {
    int N, E;
    cin >> N >> E;

    // 한 노드에서 갈 수 있는 다음 노드들을 저장
    umap<string, vector<string>> nextIs;
    // 해당 노드를 방문하기 위해 먼저 방문해야 되는 노드들을 저장
    umap<string, vector<string>> beforeIs;
    // 선행노드가 없는 노드가 시작지점이기 때문에 그러한 노드를 저장하기 위한 set
    uset<string> noDepend;
    // 각 자료구조들을 초기화함
    for(int i = 0; i < N; i++) {
        string node;
        cin >> node;
        nextIs[node] = {};
        beforeIs[node] = {};
        noDepend.insert(node);
    }

    // 후행노드, 선행노드 연결관계를 입력받고
    // 선행노드가 있는 노드를 시작지점 집합에서 삭제함
    for(int i = 0; i < E; i++) {
        string s, d;
        cin >> s >> d;
        nextIs[s].push_back(d);
        beforeIs[d].push_back(s);
        noDepend.erase(d);
    }

    // 방문한 노드를 체크하기 위함
    uset<string> completed;
    // 정렬된 결과를 담음
    vector<string> seq;
    seq.reserve(N);
    // 큐를 생성하고 시작지점 집합에 들어있는 노드들을 넣어줌
    queue<string> q;
    for(auto it = noDepend.begin(); it != noDepend.end(); it++) {
        q.push(*it);
    }
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        // 큐의 head를 방문처리해주고 정렬결과에 담음
        completed.insert(cur);
        seq.push_back(cur);

        // 현재 노드의 모든 후행노드에 대해서
        for(const auto& next : nextIs[cur]) {
            // 해당 후행 노드의 선행 노드가 모두 완료되었는지 체크
            bool dependCompl = true;
            for(const auto& depend : beforeIs[next]) {
                if(completed.count(depend) == 0) {
                    dependCompl = false;
                }
            }
            // 선행노드가 모두 완료되었다면 큐에 넣어줌
            if(dependCompl) {
                q.push(next);
            }
        }
    }

    // 결과 출력
    for(int i = 0; i < N - 1; i++) {
        cout << seq[i] << ' ';
    }
    cout << seq.back() << endl;
}
