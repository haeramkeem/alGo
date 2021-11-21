/**
 * Leetcode 106) https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 *
 * Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTreeImpl(
        vector<int>& inorder,
        vector<int>& postorder,
        int inL, int inR, int postL, int postR) {

        if(inL > inR && postL > postR) { return nullptr; }
        if(inL == inR && postL == postR) { return new TreeNode(inorder[inL]); }

        int rootIdx = find(inorder.begin(), inorder.end(), postorder[postR]) - inorder.begin();

        TreeNode* root = new TreeNode(postorder[postR]);
        root->left = buildTreeImpl(
            inorder,
            postorder,
            inL, rootIdx - 1, postL, rootIdx - inL + postL - 1);

        root->right = buildTreeImpl(
            inorder,
            postorder,
            rootIdx + 1, inR, rootIdx - inL + postL, postR - 1);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeImpl(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
