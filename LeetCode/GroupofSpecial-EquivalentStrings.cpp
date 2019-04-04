#define LOCAL
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int numSpecialEquivGroups(vector<string>& A) {
	unordered_set<string> res;
	for (auto i : A) {
		/*string tmp = "";
		vector<char> even, odd;
		for (int j = 0; j < i.size(); j++) {
			if (j & 1) { odd.push_back(i[j]); }
			else { even.push_back(i[j]); }
		}
		sort(odd.begin(), odd.end()), sort(even.begin(), even.end());
		for (auto j : odd) { tmp += j; }
		for (auto j : even) { tmp += j; }
		res.insert(tmp);
		*/
		string even, odd;
		for (int j = 0; j < i.size(); j++) {
			if (j & 1) { odd.push_back(i[j]); }
			else { even.push_back(i[j]); }
		}
		sort(odd.begin(), odd.end()), sort(even.begin(), even.end());
		res.insert(even + odd);
	}
	return res.size();
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<string> A = { "aa","bb","ab","ba" };
	numSpecialEquivGroups(A);
	return 0;
}