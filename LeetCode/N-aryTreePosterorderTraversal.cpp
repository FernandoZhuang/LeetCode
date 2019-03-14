#define LOCAL
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

vector<int> postorder(Node* root) {
	vector<int> ret;
	stack<Node*> stk;
	stk.push(root);
	if (!root) { return ret; }
	while (stk.size()) {
		Node* tmp = stk.top();
		stk.pop();
		for (auto i : tmp->children) { stk.push(i); }
		ret.push_back(tmp->val);
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	return 0;
}