/**
 * Leetcode 404) https://leetcode.com/problems/sum-of-left-leaves/
 *
 * Sum of Left Leaves
 */

#include <iostream>
#include <stack>

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
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> stk;
		stk.push(root);
		int res = 0;
		while(!stk.empty()) {
			auto h = stk.top();
			stk.pop();
			if(!h->left && !h->right && h->val > 1000) { res += h->val - 10000; }
			if(h->left) { h->left->val += 10000; stk.push(h->left); }
			if(h->right) { stk.push(h->right); }
		}
		return res;
    }
};
