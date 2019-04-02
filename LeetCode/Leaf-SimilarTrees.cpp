#define LOCAL
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	bool dfs(TreeNode* head, vector<int> &res) {
		if (!head) { return false; }
		if (!dfs(head->left, res) & !dfs(head->right, res)) { res.push_back(head->val); }

		return true;
	}

	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> res1, res2;
		dfs(root1, res1), dfs(root2, res2);

		return res1 == res2;
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

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	string line;
	while (getline(cin, line)) {
		TreeNode* root1 = stringToTreeNode(line);
		getline(cin, line);
		TreeNode* root2 = stringToTreeNode(line);

		bool ret = Solution().leafSimilar(root1, root2);

		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}