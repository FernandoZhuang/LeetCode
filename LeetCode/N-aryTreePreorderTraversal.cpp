#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	vector<int> preorder(Node* root) {
		vector<int> ret;
		if (!root) { return ret; }
		stack<Node* > stk;
		stk.push(root);
		while (!stk.empty()) {
			Node* tmp = stk.top();
			ret.push_back(tmp->val);
			stk.pop();
			for (int i = tmp->children.size() - 1; i >= 0; i--) { stk.push(tmp->children[i]); }
		}
		return ret;
	}
};