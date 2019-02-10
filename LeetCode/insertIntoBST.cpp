#include <iostream>
using namespace std;


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
	  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

 TreeNode* insertIntoBST(TreeNode* root, int val) {
	 if (!root) 
		 return new TreeNode(val);
	 if (val < root->val)
		 root->left = insertIntoBST(root->left, val);
	 else if (val > root->val)
		 root->right = insertIntoBST(root->right, val);
	 return root;
 }

int main() {
	TreeNode* root = new TreeNode(3);
	insertIntoBST(root, 5);
	return 0;
}