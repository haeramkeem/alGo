/**
 * Leetcode 337) https://leetcode.com/problems/house-robber-iii/
 *
 * House Robber III
 */

#include <iostream>
#include <vector>

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
    vector<int> dp;
    void preOrder(TreeNode* root) {
        dp.push_back(INT_MIN);
        root->val += (dp.size() - 1) * 10000;
        if(root->left) { preOrder(root->left); }
        if(root->right) { preOrder(root->right); }
    }
public:
    int rob(TreeNode* root) {
        preOrder(root);
        return robImpl(root);
    }
    int robImpl(TreeNode* root) {
        int idx = root->val / 10000;
        if(dp[idx] != INT_MIN) { return dp[idx]; }

        int robRoot = root->val % 10000;
        if(root->left) {
            if(root->left->left) {
                robRoot += robImpl(root->left->left);
            }
            if(root->left->right) {
                robRoot += robImpl(root->left->right);
            }
        }
        if(root->right) {
            if(root->right->left) {
                robRoot += robImpl(root->right->left);
            } 
            if(root->right->right) {
                robRoot += robImpl(root->right->right);
            }
        }

        int robChild = 0;
        if(root->left) {
            robChild += robImpl(root->left);
        }
        if(root->right) {
            robChild += robImpl(root->right);
        }

        return dp[idx] = max(robRoot, robChild);
    }
};
