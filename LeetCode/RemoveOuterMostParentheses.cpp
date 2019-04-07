#define LOCAL
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeOuterParentheses(string S) {
	//Plan A Mine
	/*if (S.empty()) { return ""; }
	string res = "";
	stack<char> sk;

	int cnt = 0, flag = 0;

	for (;cnt<S.size();) {
		sk.push(S[cnt++]);
		flag = 1;
		while (!sk.empty()) {
			if (S[cnt] == ')') {
				if (sk.size() > 1) { res += "()"; }
				sk.pop();
				flag--;
			}
			else { 
				sk.push('('); 
				flag++;
				if (flag == 3) {
					sk.pop(), sk.pop();
					res += "((";
					flag -= 2;
					int l = 2, r = 0;
					while (r < l) {
						cnt++;
						res += S[cnt];
						if (S[cnt] == '(') { l++; }
						else { r++; }
					}

				}
			}
			cnt++;
		}
	}*/
	//Plan B Copy Lee
	string res;
	int opened = 0;
	for (char c : S) {
		if (c == '(' && opened++ > 0) res += c;
		if (c == ')' && opened-- > 1) res += c;
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	string S = "(()((())))(()())(())";
	removeOuterParentheses(S);
	return 0;
}