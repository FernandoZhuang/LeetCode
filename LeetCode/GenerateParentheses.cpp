#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

void recursive(string tmp, int left, int right, stack<char>& sk, vector<string>& res) {
	if (!left && !right) {
		res.push_back(tmp);
		return;
	}

	if (left > 0) { 
		tmp += '(', sk.push('(');
		recursive(tmp, --left, right, sk, res);
		tmp.pop_back(), sk.pop();
		left++;
	}
	if (right > 0 && !sk.empty()) {
		tmp += ')', sk.pop();
		recursive(tmp, left, --right, sk, res);
		sk.push('(');
	}

	return;
}

vector<string> generateParenthesis(int n) {
	if (n <= 0) { return {}; }

	int left = n, right = n;
	stack<char> sk;
	vector<string> res;
	string tmp = "";

	recursive(tmp, left, right, sk, res);

	return res;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int n = 3;

	generateParenthesis(n);

	return 0;
}