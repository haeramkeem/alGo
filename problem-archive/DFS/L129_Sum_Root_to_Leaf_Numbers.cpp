/**
 * Leetcode 129) https://leetcode.com/problems/sum-root-to-leaf-numbers/
 *
 * Sum Root to Leaf Numbers
 */

/* ----- Domain ----- */
#include <iostream>
#include <stack>

using namespace std;

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
    int sumNumbers(TreeNode* root) {
		stack<TreeNode*> stk;
		stk.push(root);
		int res = 0;
		while(!stk.empty()) {
			auto t = stk.top();
			stk.pop();
			if(!t->left && !t->right) { res += t->val; }
			if(t->left) { t->left->val += t->val * 10; stk.push(t->left); }
			if(t->right) { t->right->val += t->val * 10; stk.push(t->right); }
		}
		return res;
    }
};
