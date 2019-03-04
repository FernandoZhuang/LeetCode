#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

// Plan A
//void judge(int num, int tmp, bool& flag) {
//	if (!tmp) { return; }
//	if (!(tmp % 10) || num % (tmp % 10)) { flag = false; }
//	if (flag) { judge(num, tmp / 10, flag); }
//}
//
//vector<int> selfDividingNumbers(int left, int right) {
//	bool flag = true;
//	vector<int> ret;
//	for (int i = left; i <= right; i++) {
//		judge(i, i, flag);
//		if (flag) { ret.push_back(i); }
//		flag = true;
//	}
//	return ret;
//}

//Plan B
vector<int> selfDividingNumbers(int left, int right) {
	vector<int> ret;
	for (int i = left; i <= right; i++) {
		int tmp = i;
		while (tmp) {
			if (!(tmp % 10) || i % (tmp % 10)) { break; }
			if (!(tmp /= 10)) { ret.push_back(i); }
		}
	}
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int left = 1, right = 22;
	selfDividingNumbers(left, right);
	return 0;
}