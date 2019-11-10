#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findBottomLeftValue(TreeNode* root) {
	queue<TreeNode* > q;
	q.push(root);
	TreeNode* tmp;

	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		if (tmp->right) { q.push(tmp->right); }
		if (tmp->left) { q.push(tmp->left); }
	}

	return tmp->val;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif

	return 0;
}