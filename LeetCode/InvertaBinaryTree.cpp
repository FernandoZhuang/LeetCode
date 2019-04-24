#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
	if (!root) { return NULL; }

	queue<TreeNode* > q;
	q.push(root);
	while (!q.empty()) {
		TreeNode* head = q.front(), *tmp;
		q.pop();
		if (head->right) { q.push(head->right); }
		if (head->left) { q.push(head->left); }
		tmp = head->left;
		head->left = head->right, head->right = tmp;
	}

	return root;
}

int main() {

	return 0;
}