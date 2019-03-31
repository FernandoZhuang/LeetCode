#define LOCAL
#include <iostream>
#include <string>
using namespace std;

string baseNeg2(int N) {
	string ret = "";
	int r = 0;
	if (!N) { return "0"; }
	while (N != 0) {
		r = N % (-2), N /= (-2);
		if (r < 0) {
			r += abs(-2);
			N += 1;
		}
		ret = to_string(r) + ret;
	}
	
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int n = 0;
	baseNeg2(n);
	return 0;
}