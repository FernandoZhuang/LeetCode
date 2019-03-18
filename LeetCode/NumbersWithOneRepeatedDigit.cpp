#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

int numDupDigitsAtMostN(int N) {
	int digitCnt = 1, cp = N;
	while (cp = cp / 10) { digitCnt++; }
	if (digitCnt == 1) { return 0; }
	for (int i = 2; i <= digitCnt; i++) {

	}
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif

	return 0;
}