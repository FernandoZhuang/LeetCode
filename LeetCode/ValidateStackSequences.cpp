#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	//Plan A: Mine
	/*stack<int> sk;
	map<int, bool> in;
	int flag = 0;

	if (pushed.size() == 0) { return true; }

	for (const auto& i : pushed) { in[i] = false; }
	for (const auto& i : popped) {
		if (!in[i]) {
			int j = flag;
			for (j; j < pushed.size() && pushed[j] != i; j++) { sk.push(pushed[j]), in[pushed[j]] = true; }
			flag = j + 1;
		}
		else if (!sk.empty()) {
			if (sk.top() != i) { return false; }
			sk.pop();
		}
	}

	return true;*/

	//Plan B
	stack<int> sk;
	int cnt = 0;

	for (const auto& i : pushed) {
		sk.push(i);
		while (!sk.empty() && sk.top() == popped[cnt]) 
			sk.pop(), cnt++;
	}

	return sk.empty();
}

int main() {
	vector<int> pushed = { 1,2,3,4,5 };
	vector<int> popped = { 4,5,3,2,1 };

	validateStackSequences(pushed, popped);

	return 0;
}