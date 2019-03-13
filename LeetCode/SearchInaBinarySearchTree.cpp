#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

 class Solution {
 public:
	 TreeNode* searchBST(TreeNode* root, int val) {
		/* if (!root) { return NULL; }
		 queue<TreeNode*> q;
		 q.push(root);
		 while (q.size()) {
			 TreeNode* tmp = q.front();
			 q.pop();
			 if (tmp->val == val) { return tmp; }
			 if (tmp->left) { q.push(tmp->left); }
			 if (tmp->right) { q.push(tmp->right); }
		 }
		 return NULL;*/
		 if (!root) { return NULL; }
		 TreeNode* cur = root;
		 while (cur) {
			 if (cur->val == val) { return cur; }
			 if (val < cur->val) { cur = cur->left; }
			 else { cur = cur->right; }
		 }
		 return NULL;
	 }
 };

 void trimLeftTrailingSpaces(string &input) {
	 input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		 return !isspace(ch);
	 }));
 }

 void trimRightTrailingSpaces(string &input) {
	 input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		 return !isspace(ch);
	 }).base(), input.end());
 }

 TreeNode* stringToTreeNode(string input) {
	 trimLeftTrailingSpaces(input);
	 trimRightTrailingSpaces(input);
	 input = input.substr(1, input.length() - 2);
	 if (!input.size()) {
		 return nullptr;
	 }

	 string item;
	 stringstream ss;
	 ss.str(input);

	 getline(ss, item, ',');
	 TreeNode* root = new TreeNode(stoi(item));
	 queue<TreeNode*> nodeQueue;
	 nodeQueue.push(root);

	 while (true) {
		 TreeNode* node = nodeQueue.front();
		 nodeQueue.pop();

		 if (!getline(ss, item, ',')) {
			 break;
		 }

		 trimLeftTrailingSpaces(item);
		 if (item != "null") {
			 int leftNumber = stoi(item);
			 node->left = new TreeNode(leftNumber);
			 nodeQueue.push(node->left);
		 }

		 if (!getline(ss, item, ',')) {
			 break;
		 }

		 trimLeftTrailingSpaces(item);
		 if (item != "null") {
			 int rightNumber = stoi(item);
			 node->right = new TreeNode(rightNumber);
			 nodeQueue.push(node->right);
		 }
	 }
	 return root;
 }

 int stringToInteger(string input) {
	 return stoi(input);
 }

 string treeNodeToString(TreeNode* root) {
	 if (root == nullptr) {
		 return "[]";
	 }

	 string output = "";
	 queue<TreeNode*> q;
	 q.push(root);
	 while (!q.empty()) {
		 TreeNode* node = q.front();
		 q.pop();

		 if (node == nullptr) {
			 output += "null, ";
			 continue;
		 }

		 output += to_string(node->val) + ", ";
		 q.push(node->left);
		 q.push(node->right);
	 }
	 return "[" + output.substr(0, output.length() - 2) + "]";
 }

 int main() {
#ifdef LOCAL
	 freopen("data.txt", "r", stdin);
#endif
	 string line;
	 while (getline(cin, line)) {
		 TreeNode* root = stringToTreeNode(line);
		 getline(cin, line);
		 int val = stringToInteger(line);

		 TreeNode* ret = Solution().searchBST(root, val);

		 string out = treeNodeToString(ret);
		 cout << out << endl;
	 }
	 return 0;
 }