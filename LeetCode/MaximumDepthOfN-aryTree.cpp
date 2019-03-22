#define LOCAL
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

int maxDepth(Node* root) {
	//Plan A
	/*int max = 1, tmp = 0;
	if (!root) { return 0; }
	if (root->children.empty()) { return 1; }
	for (auto i : root->children) {
		tmp = 1 + maxDepth(i);
		max = tmp > max ? tmp : max;
	}
	return max;*/
	//Plan B
	/*int max = 1;
	map<int, queue<int> > record;
	queue<Node*> q;
	if (!root) { return 0; }
	q.push(root), record[root->val].push(1);
	while (!q.empty()) {
		Node* tmp = q.front();
		int val = record[tmp->val].front();
		q.pop(), record[tmp->val].pop();
		for (auto i : tmp->children) {
			q.push(i), record[i->val].push(val + 1);
			max = (val + 1) > max ? val + 1 : max;
		}
	}
	return max;*/
	//Plan C
	if (!root) { return 0; }
	int ret = 0;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			Node* tmp = q.front();
			q.pop();
			for (auto j : tmp->children) { q.push(j); }
		}
		ret++;
	}
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	return 0;
}