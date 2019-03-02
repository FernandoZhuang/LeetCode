#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int minAddToMakeValid(string S) {
	stack<char> pl, pr;
	for (auto i : S) {
		if (i == '(') { pl.push('('); }
		else if (!pl.empty() && i == ')') { pl.pop(); }
		else if (pl.empty() && i == ')') { pr.push(')'); }
	}
	return pl.size() + pr.size();
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	string S = "()))((";
	cout<< minAddToMakeValid(S);
	return 0;
}