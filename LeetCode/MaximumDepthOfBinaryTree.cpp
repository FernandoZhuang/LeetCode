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
 

int maxDepth(TreeNode* root) {
	if (!root) { return 0; }

	int res = 0;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		int sz = q.size();
		res++;
		for (int i = 0; i < sz; i++) {
			TreeNode* tmp = q.front();
			q.pop();
			if (tmp->left) { q.push(tmp->left); }
			if (tmp->right) { q.push(tmp->right); }
		}
	}

	return res;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	return 0;
}