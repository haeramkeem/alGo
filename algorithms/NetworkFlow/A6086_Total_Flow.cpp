/**
 * BOJ 6086) https://www.acmicpc.net/problem/6086
 *
 * Total Flow
 */

/* ----- Solution ----- */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

#define umap unordered_map
#define MAXINT 2147483647

struct Edge {
    string src, dst;
    int capp, flow;
    Edge* rev;
    Edge(): Edge("", "", 0) {}
    Edge(string s, string d, int c): src(s), dst(d), capp(c), flow(0), rev(nullptr) {}
    int rem() { return capp - flow; }
    void addFlow(const int& addi) { this->flow += addi; }
};

int main() {
    int N;
    cin >> N;

    umap<string, vector<Edge*>> edges;
    for(int i = 0; i < N; i++) {
        string s, d;
        int c;
        cin >> s >> d >> c;
        Edge* u = new Edge(s, d, c);
        Edge* v = new Edge(d, s, c);
        u->rev = v;
        v->rev = u;
        if(edges.count(s) == 0) { edges[s] = {}; }
        if(edges.count(d) == 0) { edges[d] = {}; }
        edges[s].push_back(u);
        edges[d].push_back(v);
    }

    int tot = 0;
    const string beg = "A", end = "Z";
    while(true) {
        umap<string, Edge*> prev;
        queue<string> q;
        q.push(beg);
        while(!q.empty() && prev.count(end) == 0) {
            auto curr = q.front();
            q.pop();
            for(auto& edge : edges[curr]) {
                // Not Visited
                if(prev.count(edge->dst) == 0) {
                    // Capacity > Current flow
                    if(edge->rem() > 0) {
                        prev[edge->dst] = edge;
                        if(edge->dst == end) { break; }
                        q.push(edge->dst);
                    }
                }
            }
        }

        if(prev.count(end) == 0) { break; }

        int nextFlow = MAXINT;

        for(string it = end; it != beg; it = prev[it]->src) {
            nextFlow = min(nextFlow, prev[it]->rem());
        }

        for(string it = end; it != beg; it = prev[it]->src) {
            prev[it]->addFlow(nextFlow);
            prev[it]->rev->addFlow(-nextFlow);
        }

        tot += nextFlow;
    }

    cout << tot << endl;
    return 0;
}
