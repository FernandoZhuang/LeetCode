#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int scoreOfParentheses(string S) {
	int res = 0;
	vector<int> leaf, parents(S.size(), -1);

	for (int i = 1; i < S.size(); i++) {
		if (S[i] == ')') { 
			parents[i] = S[i - 1] == '(' ? parents[i - 1] : parents[parents[i - 1]]; 
			if (S[i - 1] == '(') { leaf.push_back(i - 1); }
		}
		else { parents[i] = S[i - 1] == ')' ? parents[i - 1] : i - 1; }
	}
	for (const auto& i : leaf) {
		int level = 0, tmp = i;
		while (parents[tmp] != -1) { level++, tmp = parents[tmp]; }
		res += pow(2, level);
	}

	return res;
}

int main() {
	string S = "(()(()))";

	scoreOfParentheses(S);

	return 0;
}