#define LOCAL
#include <vector>
#include <queue>
#include <iostream>
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

vector<vector<int>> levelOrder(Node* root) {
	if (!root) { return {}; }

	vector<vector<int> > ret;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		vector<int> val;
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			Node* tmp = q.front();
			q.pop();
			val.push_back(tmp->val);
			for (int j = 0; j < tmp->children.size(); j++) { q.push(tmp->children[j]); }
		}
		ret.push_back(val);
	}

	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif

	return 0;
}