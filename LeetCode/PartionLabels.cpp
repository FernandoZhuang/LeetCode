#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> partitionLabels(string S) {
	vector<int> res, record(26, -1);
	for (int i = 0; i < S.size(); i++) { record[S[i] - 'a'] = i; }
	int start = 0, end = record[S[0] - 'a'];
	for (int i = 0; i < S.size();i++) {
		if (i < end && (record[S[i] - 'a'] > end)) { end = record[S[i] - 'a']; }
		if (i == end) {
			res.push_back(end - start + 1);
			start = (end + 1) < S.size() ? (end + 1) : S.size() - 1, end = record[S[start] - 'a'];
		}
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	string S = "caedbdedda";
	partitionLabels(S);
	return 0;
}