#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int cnt = 0;
vector<TreeNode*> pdata;

TreeNode* increasingBST(TreeNode* root) {
	if (!root) { return NULL; }
	increasingBST(root->left);
	TreeNode* node = new TreeNode(root->val);
	pdata.push_back(node);
	if (++cnt > 1) { pdata[cnt - 2]->right = pdata[cnt - 1]; }
	increasingBST(root->right);
	return *pdata.begin();
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	return 0;
}