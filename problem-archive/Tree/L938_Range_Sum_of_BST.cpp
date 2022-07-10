/**
 * Leetcode 938) https://leetcode.com/problems/range-sum-of-bst/
 *
 * Range Sum of BST
 *
 */

#include <iostream>

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

/* -----Solution ----- */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root->val < low) {
            return root->right ? rangeSumBST(root->right, low, high) : 0;
        } else if(high < root->val) {
            return root->left ? rangeSumBST(root->left, low, high) : 0;
        }
        int acc = root->val;
        if(root->left) { acc += rangeSumBST(root->left, low, high); }
        if(root->right) { acc += rangeSumBST(root->right, low, high); }
        return acc;
    }
};
