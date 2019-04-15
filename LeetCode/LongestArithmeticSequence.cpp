#define LOCAL
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int longestArithSeqLength(vector<int>& A) {
	int ret = 2;
	unordered_map<int, unordered_map<int, int> > up;
	for (int i = 0; i < A.size(); i++) {
		for (int j = i + 1; j < A.size(); j++) {
			int dif = A[j] - A[i];
			up[dif][j] = max(up[dif][i] + 1, up[dif][j]);
			ret = max(ret, up[dif][j] + 1);
		}
	}

	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<int> A = { 3,6,9,12 };
	longestArithSeqLength(A);

	return 0;
}