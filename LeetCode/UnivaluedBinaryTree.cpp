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
 
//Plan A: queue BFS
//bool isUnivalTree(TreeNode* root) {
//	bool flag = true;
//	int val = root->val;
//	queue<TreeNode* > q;
//	q.push(root);
//	while (q.size()) {
//		TreeNode* tmp = q.front();
//		q.pop();
//		if (tmp->val != val) { 
//			flag = false;
//			break; 
//		}
//		if (tmp->left) { q.push(tmp->left); }
//		if (tmp->right) { q.push(tmp->right); }
//	}
//	return flag;
//}

 //DFS
 static void DPF(TreeNode* root, bool* flag, int value) {
	 if (!root) { return; }
	 if (root->val != value) {
		 *flag = false;
		 return;
	 }
	 if (flag) { DPF(root->left, flag, value); }
	 if (flag) { DPF(root->right, flag, value); }
 }

 bool isUnivalTree(TreeNode* root) {
	 bool flag = true;
	 DPF(root, &flag, root->val);
	 return flag;
 }