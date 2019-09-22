#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//vector<int> res;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
//PlanA Recursive
//vector<int> inorderTraversal(TreeNode* root) {
//	if (!root) { return res; }
//
//	if (root->left) { inorderTraversal(root->left); }
//	res.push_back(root->val);
//	if (root->right) { inorderTraversal(root->right); }
//
//	return res;
//}

//PlanB Iteratively
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	stack<TreeNode*> sk;

	while (!sk.empty() || root) {
		if (root) {
			sk.push(root);
			root = root->left;
		}
		else {
			res.push_back(sk.top()->val);
			root = sk.top()->right;
			sk.pop();
		}
	}

	return res;
}

int main() {

	return 0;
}