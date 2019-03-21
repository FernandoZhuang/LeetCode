#define LOCAL
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <stdlib.h>
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
	bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		set<int> s1, s2;
		queue<TreeNode*> q1, q2;
		q1.push(root1), q2.push(root2);
		if (!root1 && !root2) { return true; }
		if ((!root1 && root2) || (root1 && !root2)) { return false; }
		if (root1->val != root2->val) { return false; }
		while (!q1.empty() && !q2.empty()) {
			s1.clear(), s2.clear();
			TreeNode* tmp1 = q1.front(), *tmp2 = q2.front();
			q1.pop(), q2.pop();
			if (!tmp1 && !tmp2) { continue; }
			s1.insert(tmp1->left ? tmp1->left->val : -1), s1.insert(tmp1->right ? tmp1->right->val : -1);
			s2.insert(tmp2->left ? tmp2->left->val : -1), s2.insert(tmp2->right ? tmp2->right->val : -1);
			if (s1 != s2) { return false; }
			else {
				if (!tmp1->left && !tmp2->left && !tmp1->right && !tmp2->right) { continue; }
				else {
					if (((tmp1->left && tmp2->left) && tmp1->left->val == tmp2->left->val) || (!tmp1->left && !tmp2->left)) { q2.push(tmp2->left), q2.push(tmp2->right); }
					else { q2.push(tmp2->right), q2.push(tmp2->left); }
					q1.push(tmp1->left), q1.push(tmp1->right);
				}
			}
		}
		return q1.size() == q2.size();
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

		bool ret = Solution().flipEquiv(root1, root2);

		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}