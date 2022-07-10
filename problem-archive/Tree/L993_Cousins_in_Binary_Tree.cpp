/**
 * Leetcode 993) https://leetcode.com/problems/cousins-in-binary-tree/
 * 
 * Cousins in Binary Tree
 */

#include <iostream>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    struct Wrapper {
        int parent;
        int depth;
        TreeNode* node;
    };
public:
    bool isCousins(TreeNode* root, int x, int y) {
        auto wroot = Wrapper{-1, 0, root};
        deque<Wrapper> q;
        deque<Wrapper> res;
        q.push_back(wroot);
        while(!q.empty()) {
            auto h = q.front();
            q.pop_front();
            if(h.node->val == x || h.node->val == y) { res.push_back(h); }
            if(res.size() == 2) { break; }
            if(h.node->left) { q.push_back(Wrapper{h.node->val, h.depth + 1, h.node->left}); }
            if(h.node->right) { q.push_back(Wrapper{h.node->val, h.depth + 1, h.node->right}); }
        }
        return (res[0].depth == res[1].depth) && (res[0].parent != res[1].parent);
    }
};