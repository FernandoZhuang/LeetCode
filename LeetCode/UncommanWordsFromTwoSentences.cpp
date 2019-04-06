#define LOCAL
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

void helper(string str, unordered_map<string, int> & up) {
	size_t pos = str.find(" ");
	while (pos != std::string::npos) {
		up[str.substr(0, pos)]++;
		str = str.substr(pos + 1);
		pos = str.find(" ");
	}
	up[str]++;
}

vector<string> uncommonFromSentences(string A, string B) {
	vector<string> ret;
	unordered_map<string, int> up;
	helper(A, up), helper(B, up);
	for (auto i : up) {
		if (i.second == 1)
			ret.push_back(i.first);
	}
		
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	string A = "apple apple";
	string B = "banana";
	uncommonFromSentences(A, B);
	return 0;
}