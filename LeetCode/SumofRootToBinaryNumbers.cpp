#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
int mod = 1000000007;

void dfs(TreeNode* root, long long sum, vector<int>& addup) {
	if (!root) { return; }

	sum = (root->val + sum * 2) % mod;
	dfs(root->left, sum, addup);
	dfs(root->right, sum, addup);
	if (!root->left && !root->right) {
		addup.push_back(sum);
	}
}

int sumRootToLeaf(TreeNode* root) {
	int sum = 0, res = 0;
	vector<int> addup;
	dfs(root, sum, addup);
	for (auto i : addup) { res = (res + i) % mod; }

	return res;
}

int main() {
	return 0;
}