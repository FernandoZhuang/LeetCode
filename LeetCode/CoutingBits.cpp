#define LOCLA
#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int num) {
	//Plan A
	/*vector<int> ret;
	for (int i = 0; i <= num; i++) {
		int res = 0, tmp = i;
		do { if (tmp & 1) { res++; } } while (tmp = tmp >> 1);
		ret.push_back(res);
	}
	return ret;*/
	//Plan B
	vector<int> ret(num + 1, 0);
	for (int i = 1; i <= num; i++) { ret[i] = ret[i >> 1] + (i & 1); }
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int num = 2;
	countBits(num);
	return 0;
}