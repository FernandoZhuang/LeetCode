#define LOCAL
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestPerimeter(vector<int>& A) {
	int p = 0;
	if (A.size() < 3) { return 0; }

	/*sort(A.begin(), A.end());
	for (int i = 0; i <= A.size() - 3; i++) 
		if (A[i] + A[i + 1] > A[i + 2]) { p = A[i] + A[i + 1] + A[i + 2]; }*/
	sort(A.begin(), A.end(), [](int a, int b) {return a > b; });
	for (int i = 0; i <= A.size() - 3; i++) {
		if (A[i + 2] + A[i + 1] > A[i]) { return A[i + 2] + A[i + 1] + A[i]; } 
	}
	return p;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<int> A = { 3,4,2,3 };
	largestPerimeter(A);

	return 0;
}