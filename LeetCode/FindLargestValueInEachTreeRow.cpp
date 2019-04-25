#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> largestValues(TreeNode* root) {
	if (!root) { return {}; }

	vector<int> res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		int sz = q.size(), max = q.front()->val;
		for (int i = 0; i < sz; i++) {
			TreeNode* tmp = q.front();
			q.pop();
			if (tmp->left) { q.push(tmp->left); }
			if (tmp->right) { q.push(tmp->right); }
			if (tmp->val > max) { max = tmp->val; }
		}
		res.push_back(max);
	}

	return res;
}

int main() {

	return 0;
}