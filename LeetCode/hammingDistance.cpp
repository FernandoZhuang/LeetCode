#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
using namespace std;

int hammingDistance(int x, int y) {
	int small = x >= y ? y : x, big = x >= y ? x : y;
	int res = 0;
	while (big) {
		if (small % 2 != big % 2) { res++; }
		small /= 2, big /= 2;
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int x, y;
	cin >> x >> y;
	hammingDistance(x, y);
	return 0;
}