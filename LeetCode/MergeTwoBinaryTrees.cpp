#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 && t2) { t1->val = (t1 != t2 ? (t1->val + t2->val) : t1->val); }
		else { return (!t1 && t2) ? t2 : t1; }
		//Plan A seems to have some bug
		/*t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);*/
		//Plan B 
		/*if (t1->left || t2->left) {
			if (!t1->left && t2->left) { t1->left = t2->left; }
			else if (t1->left && !t2->left) { t2->left = t1->left; }
			mergeTrees(t1->left, t2->left);
		}
		if (t1->right || t2->right) {
			if (!t1->right && t2->right) { t1->right = t2->right; }
			else if (t1->right && !t2->right) { t2->right = t1->right; }
			mergeTrees(t1->right, t2->right);
		}*/
		return t1;
	}
};