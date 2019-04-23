#define LOCAL
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int minFallingPathSum(vector<vector<int>>& A) {
	for (int i = 1; i < A.size(); i++) 
		for (int j = 0; j < A.size(); j++) {
			int a = 101, b = 101, c = 101;
			if (j - 1 >= 0) { a = A[i - 1][j - 1]; }
			b = A[i - 1][j];
			if (j + 1 < A.size()) { c = A[i - 1][j + 1]; }
			A[i][j] += c < min(a, b) ? c : min(a, b);
		}

	return *min_element(A[A.size() - 1].begin(), A[A.size() - 1].end());
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<vector<int> > A = { {1} };
	minFallingPathSum(A);

	return 0;
}