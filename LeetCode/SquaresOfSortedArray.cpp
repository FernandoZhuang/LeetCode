#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquares(vector<int>& A) {
	vector<int> res;
	for (int num : A)
		res.push_back(num*num);
	sort(res.begin(), res.end());
	return res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	vector<int> num(6);
	for (int i = 0; i < 6; i++)
		cin >> num[i];
	sortedSquares(num);
	return 0;
}