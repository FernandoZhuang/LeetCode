#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Cmp(int a, int b) {
	return abs(a) < abs(b);
}

int largestSumAfterKNegations(vector<int>& A, int K) {
	int negCnt = 0, sum = 0;
	vector<int> neg;
	for (int i = 0; i < A.size(); i++) {
		sum += A[i];
		if (A[i] < 0) { neg.push_back(A[i]); }
	}
	if (K <= neg.size()) {
		sort(neg.begin(), neg.end());
		for (int i = 0; i < K; i++) { sum = sum + (-neg[i]) * 2; }
		return sum;
	}
	sort(A.begin(), A.end(), Cmp);
	for (int i = 0; i < neg.size(); i++) { sum = sum + (-neg[i]) * 2; }
	return sum - 2 * ((K - neg.size()) % 2)* abs(A[0]);
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int K = 6, ans = 0;
	vector<int> A = { -8, 3, -5, -3, -5, -2 };
	ans = largestSumAfterKNegations(A, K);
	return 0;
}