#define LOCAL
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string customSortString(string S, string T) {
	string ret = "";
	vector<char> seq;
	vector<int> flag(26, 0);
	unordered_map<char, int> record;
	for (auto i : S) {
		seq.push_back(i); 
		flag[i - 'a'] = 1;
	}
	for (auto i : T) { 
		if (!flag[i - 'a']) { ret += i; }
		else { record[i]++; }
	}
	for (auto i : seq)
		for (int j = 0; j < record[i]; j++) { ret += i; }
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	string res;
	string S = "cba";
	string T = "abcd";
	res = customSortString(S, T);
	return 0;
}