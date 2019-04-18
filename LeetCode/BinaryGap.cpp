#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

int binaryGap(int N) {
	bool flag = false;
	int st = 0, cnt = 0, ret = 0;
	vector<int> base2;

	while (N) {
		base2.push_back(N % 2);
		if ((N % 2) && !flag) { 
			st = cnt; 
			flag = true;
		}
		N /= 2, cnt++;
	}

	if (st == base2.size() - 1) { return 0; }
	for (int i = st + 1; i < base2.size(); i++) {
		if (base2[i]) {
			if (i - st > ret) { ret = i - st; }
			st = i;
		}
	}

	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int N = 8;
	binaryGap(N);

	return 0;
}