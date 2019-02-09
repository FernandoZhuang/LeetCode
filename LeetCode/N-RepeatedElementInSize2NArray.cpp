#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

int repeatedNTimes(vector<int>& A) {
	vector<bool> arr(1001, false);
	for (auto i : A) {
		if (arr[i] == false)
			arr[i] = true;
		else
			return i;
	}
	return -1;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	vector<int> A(4);
	for (int i = 0; i < 4; i++)
		cin >> A[i];
	cout << repeatedNTimes(A);
	return 0;
}