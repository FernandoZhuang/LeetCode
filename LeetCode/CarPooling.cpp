#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
	set<int> st;
	vector<int> cnt(1001, 0);

	for (const auto& i : trips) {
			for (int k = i[1]; k < i[2]; k++) { cnt[k] += i[0]; }
			st.insert(i[1]), st.insert(i[2]);
	}
	for (set<int>::iterator it = st.begin(); it != st.end(); it++) { if (cnt[*it - 1] > capacity) { return false; } }

	return true;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif

	return 0;
}