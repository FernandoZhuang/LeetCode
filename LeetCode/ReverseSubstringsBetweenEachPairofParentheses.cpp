#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

string reverseParentheses(string s) {
	string res = "";
	stack<int> sk;
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') { sk.push(i); }
		else if (s[i] == ')') {
			reverse(s.begin() + sk.top(), s.begin() + i);
			sk.pop();
		}
	}
	for (const auto& i : s) {if (i != '('&&i != ')') { res += i; }}
	
	return res;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	string s = "abc";

	reverseParentheses(s);

	return 0;
}