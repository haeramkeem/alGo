/**
 * Leetcode 437) https://leetcode.com/problems/path-sum-iii/
 * 
 * Path Sum III
 */

#include <iostream>
#include <queue>

using namespace std;

/* ----- Domain ----- */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* ----- Solution ----- */
class Solution {
    int res = 0;
    void pathSumImpl(TreeNode* root, const int& targetNum, int acc) {
        if(acc == targetNum) { res++; }
        if(root->left) { pathSumImpl(root->left, targetNum, acc + root->left->val); }
        if(root->right) { pathSumImpl(root->right, targetNum, acc + root->right->val); }
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) { return 0; }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto h = q.front();
            q.pop();
            pathSumImpl(h, targetSum, h->val);
            if(h->left) { q.push(h->left); }
            if(h->right) { q.push(h->right); }
        }
        return res;
    }
};