#define LOCAL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int smallestRangeI(vector<int>& A, int K) {
	//Plan A: Bruteforce
	/*sort(A.begin(), A.end());
	int st = *A.begin(), ed = *A.rbegin(), min = 10001, tmp = 0;
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j >= -K; j--) {
			tmp = ed + j - (st + i);
			if (tmp >= 0 && tmp < min) { min = tmp; }
			if (min == 0) { return 0; }
		}
	}
	return min;*/
	//Plan B
	int max = 0, min = 10001;
	for (auto i : A) {
		if (i > max) { max = i; }
		if (i < min) { min = i; }
	}
	if (min + K < max - K) { return max - K - (min + K); }
	else { return 0; }
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<int> A = { 1,3,6 };
	int K = 3;
	smallestRangeI(A, K);
	return 0;
}