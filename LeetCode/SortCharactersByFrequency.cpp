#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

//Plan A: Mine
//string frequencySort(string s) {
//	map<char, int> mp;
//
//	for (const auto& i : s) { mp[i]++; }
//	sort(s.begin(), s.end(), [&](char a, char b) {
//		if (mp[a] == mp[b]) { return (a - '0') > (b - '0'); }
//		else return mp[a] > mp[b];
//	});
//
//	return s;
//}

//Plan B: Learn from Others
string frequencySort(string s) {
	string res = "";
	vector<int> cnt(256, 0);
	priority_queue<pair<int, char>> pq;

	for (const auto& i : s) { cnt[i]++; }
	for (int i = 0; i < 256; i++)
		if (cnt[i] > 0)
			pq.push(make_pair(cnt[i], char(i)));
	while (!pq.empty()) {
		auto tmp = pq.top();
		pq.pop();
		string str(tmp.first, tmp.second);
		res += str;
	}

	return res;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	string s = "loveleetcode";

	frequencySort(s);

	return 0;
}