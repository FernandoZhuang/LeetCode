#define LOCAL
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	int distributeCoins(TreeNode* root) {
		int res = 0;
		if (root->left) {
			res += distributeCoins(root->left);
			root->val += root->left->val - 1;
			res += abs(root->left->val - 1);
		}
		if (root->right) {
			res += distributeCoins(root->right);
			root->val += root->right->val - 1;
			res += abs(root->right->val - 1);
		}
		return res;
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

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	string line;
	while (getline(cin, line)) {
		TreeNode* root = stringToTreeNode(line);

		int ret = Solution().distributeCoins(root);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}