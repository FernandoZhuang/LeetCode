#define LOCAL
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
TreeNode* trimBST(TreeNode* root, int L, int R) {
	if (!root) { return NULL; }

	if (root->val <= L) { root->left = NULL; }
	else { root->left = trimBST(root->left, L, R); }

	if (root->val >= R) { root->right = NULL; }
	else { root->right = trimBST(root->right, L, R); }

	if (root->val < L) { root = root->right; }
	else if (root->val > R) { root = root->left; }

	return root;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif

	return 0;
}