#define LOCAL
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> shortestToChar(string S, char C) {
	vector<int> ret, cpos;
	for (int i = 0; i < S.size(); i++) { if (S[i] == C) { cpos.push_back(i); } }
	int cstart = *cpos.begin(), cend = *cpos.rbegin(), liflag = 0, biflag = 0;
	for (int i = 0; i < S.size(); i++) {
		if (i > cstart && i < cend) {
			int j = 0;
			for (j; j < cpos.size() && i > cpos[j]; j++) { liflag = cpos[j]; }
			biflag = cpos[j];
			ret.push_back(i - liflag < biflag - i ? (i - liflag) : (biflag - i));
		}
		else if (i <= cstart) { ret.push_back(cstart - i); }
		else if (i >= cend) { ret.push_back(i - cend); }
	}

	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	string S = "loveleetcode";
	char C = 'e';
	shortestToChar(S, C);
	return 0;
}