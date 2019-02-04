#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode*  left;
	TreeNode*  right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	int rangeSumBSTBFS(TreeNode*  root, int L, int R) {
		int res = 0;
		queue<TreeNode* > q;
		q.push(root);
		while (q.size() != 0) {
			TreeNode* top = q.front();
			q.pop();
			if (top == NULL)
				continue;
			if (top->val >= L && top->val <= R)
				res += top->val;
			if (top->val > L && top->val < R) {
				q.push(top->left);
				q.push(top->right);
			}
			else if (top->val <= L)
				q.push(top->right);
			else if (top->val >= R)
				q.push(top->left);
		}
		return res;
	}
	int rangeSumBSTDFS(TreeNode* root, int L, int R) {
		if (root == NULL)
			return 0;
		if (root->val < L)
			return rangeSumBSTDFS(root->right, L, R);
		else if (root->val > L)
			return rangeSumBSTDFS(root->left, L, R);
		else
			return rangeSumBSTDFS(root->right, L, R) + rangeSumBSTDFS(root->left, L, R) + root->val;
	}
};