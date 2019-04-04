#define LOCAL
#include <iostream>
using namespace std;

int findComplement(int num) {
	int ret = 0, cnt = 0, tmp = 0;
	if (!num) { return 1; }

	while (num) {
		tmp = num & 1;
		ret += (1 - tmp)*pow(2, cnt++);
		num = num >> 1;
	}

	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int num = 0;
	findComplement(num);
	return 0;
}