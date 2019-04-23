#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<double> averageOfLevels(TreeNode* root) {
	if (!root) { return {}; }

	vector<double> ret;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		int sz = q.size();
		long sum = 0;
		for (int i = 0; i < sz; i++) {
			TreeNode* tmp = q.front();
			q.pop();
			sum += tmp->val;
			if (tmp->left) { q.push(tmp->left); }
			if (tmp->right) { q.push(tmp->right); }
		}
		ret.push_back(sum*1.0 / sz);
	}

	return ret;
}
 