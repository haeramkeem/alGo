/**
 * Leetcode 226) https://leetcode.com/problems/invert-binary-tree/
 *
 * Invert Binary Tree
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

/* ----- Solution ----- */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
		if(!root) { return root; }
		auto temp = root->left;
		root->left = root->right;
		root->right = temp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
    }
};
