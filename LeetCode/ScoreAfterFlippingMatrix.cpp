#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int matrixScore(vector<vector<int>>& A) {
	int row = A.size(), col = A[0].size(), res = (1 << (col - 1))*row;
	for (int i = 1; i < col; i++) {
		int cur = 0;
		for (int j = 0; j < row; j++) { cur += A[j][i] == A[j][0] ? 1 : 0; }
		res += max(cur, row - cur)*(1 << (col - 1 - i));
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<vector<int> > A = { {0,0,1,1},{1,0,1,0},{1,1,0,0} };
	matrixScore(A);
	return 0;
}