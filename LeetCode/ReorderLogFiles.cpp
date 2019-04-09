#define LOCAL
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

vector<string> reorderLogFiles(vector<string>& logs) {
	vector<string> digit, letter, ret;

	if (!logs.size()) { return {}; }

	for (const auto i : logs) {
		if (isdigit(i[i.find(" ") + 1])) { digit.push_back(i); }
		else { letter.push_back(i); }
	}

	sort(letter.begin(), letter.end(), [](string a, string b) {
		a = a.substr(a.find(" ") + 1), b = b.substr(b.find(" ") + 1);
		return a < b;
	});
	ret.assign(letter.begin(), letter.end());
	for (const auto i : digit) { ret.push_back(i); }

	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<string> logs = { "a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo" };
	reorderLogFiles(logs);
	return 0;
}