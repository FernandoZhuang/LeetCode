#define LOCAL
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
	int sum_a = 0, sum_b = 0, val = 0, flag = 0;
	vector<int> ans(2, 0);
	sort(A.begin(), A.end()), sort(B.begin(), B.end());

	for (const auto& i : A) { sum_a += i; }
	for (const auto& i : B) { sum_b += i; }
	if (sum_a > sum_b) {
		flag = 1;
		A.swap(B);
	}
	val = abs(sum_a - sum_b) / 2;
	for (const auto& i : A) 
		for (const auto& j : B) 
			if (j - i == val) {
				if (!flag) { ans[0] = i, ans[1] = j; }
				else { ans[0] = j, ans[1] = i; }
				return ans;
			}

	return ans;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<int> A, B;
	A = {1,2,5}, B = { 2,4 };
	fairCandySwap(A, B);
	return 0;
}