/**
 * Leetcode 563) https://leetcode.com/problems/binary-tree-tilt/
 *
 * Binary Tree Tilt
 */

#include <iostream>
#include <cmath>

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
    int acc;
    int postOrder(TreeNode* root) {
        int lSum = 0, rSum = 0;
        if(root->left) { lSum = postOrder(root->left); }
        if(root->right) { rSum = postOrder(root->right); }
        acc += abs(lSum - rSum);
        return root->val + lSum + rSum;
    }
public:
    int findTilt(TreeNode* root) {
        if(!root) { return 0; }
        acc = 0;
        postOrder(root);
        return acc;
    }
};
