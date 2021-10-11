/**
 * Leetcode 543) https://leetcode.com/problems/diameter-of-binary-tree/
 * 
 * Diameter of Binary Tree
 */

#include <iostream>
#include <algorithm>

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
    int depth(TreeNode* cur, int& ans) {
        if(!cur) { return -1; }
        int nLeftDepth = depth(cur->left, ans);
        int nRightDepth = depth(cur->right, ans);
        ans = max(ans, nLeftDepth + nRightDepth + 2);
        return max(nLeftDepth, nRightDepth) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        depth(root, ans);
        return ans;
    }
};

/* ----- Testing ----- */
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    int res;
    if((res = s.diameterOfBinaryTree(root)) != 3) {
        cout << "FAIL: want " << 3 << " got " << res << endl;
    } else {
        cout << "ok" << endl;
    }

    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}