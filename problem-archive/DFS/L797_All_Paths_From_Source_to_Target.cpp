/**
 * Leetcode 797) https://leetcode.com/problems/all-paths-from-source-to-target/
 *
 * All Paths From Source to Target
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/* ----- Solution ----- */
class Solution {
    vector<vector<int>> res;

    void dfs(vector<vector<int>>& graph, vector<int> acc) {
        if(acc.back() == graph.size() - 1) {
            res.push_back(acc);
            return;
        }
        for(const auto& conn : graph[acc.back()]) {
            acc.push_back(conn);
            dfs(graph, acc);
            acc.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        res.clear();
        dfs(graph, {0});
        return res;
    }
};

/* ----- Testing ----- */
struct Testing {
    vector<vector<int>> graph, outp;
    Testing(vector<vector<int>> g, vector<vector<int>> o): graph(g), outp(o) {}

    const static int SIZE = 5;
    static void print(vector<vector<int>> arg) {
        cout << "{ ";
        for(const auto& path : arg) {
            cout << "{ ";
            for(const auto& el : path) {
                cout << el << ' ';
            }
            cout << "} ";
       }
        cout  << "}\n";
    }
};

int main() {
    Testing t[Testing::SIZE] = {
        Testing({{1,2},{3},{3},{}}, {{0,1,3},{0,2,3}}),
        Testing({{4,3,1},{3,2,4},{3},{4},{}}, {{0,4},{0,3,4},{0,1,3,4},{0,1,2,3,4},{0,1,4}}),
        Testing({{1},{}},{{0,1}}),
        Testing({{1,2,3},{2},{3},{}},{{0,1,2,3},{0,2,3},{0,3}}),
        Testing({{1,3},{2},{3},{}},{{0,1,2,3},{0,3}}),
    };

    Solution s;

    for(auto& tcase : t) {
        auto res = s.allPathsSourceTarget(tcase.graph);
        if(res != tcase.outp) {
            cout << "FAIL:\nwant: ";
            Testing::print(tcase.outp);
            cout << "got: ";
            Testing::print(res);
            return 1;
        }
    }

    cout << "ok\n";
    return 0;
}
