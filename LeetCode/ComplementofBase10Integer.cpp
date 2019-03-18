#define LOCAL
#include <iostream>
using namespace std;

int bitwiseComplement(int N) {
	int cnt = 0, sum = 0;
	if (!N) { return 1; }
	while (N) {
		int tmp = N & 1;
		tmp = 1 - tmp;
		sum = sum + pow(2, cnt++)*tmp;
		N = N >> 1;
	}
	return sum;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int N = 10;
	bitwiseComplement(N);
	return 0;
}