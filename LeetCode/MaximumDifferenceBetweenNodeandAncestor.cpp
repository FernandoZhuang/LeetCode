#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

void dfs(TreeNode* root, int mx, int mn, int &ret) {
	if (!root) { return; }

	if (root->val > mx) { mx = root->val; }
	if (root->val < mn) { mn = root->val; }

	int tmp1 = abs(root->val - mx), tmp2 = abs(root->val - mn);
	if (tmp1 > ret) { ret = tmp1; }
	if (tmp2 > ret) { ret = tmp2; }

	dfs(root->left, mx, mn, ret);
	dfs(root->right, mx, mn, ret);
}

int maxAncestorDiff(TreeNode* root) {
	int mx = 0, mn = 100001, ret = 0;
	dfs(root, mx, mn, ret);

	return ret;
}