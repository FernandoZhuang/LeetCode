#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

vector<bool> prefixesDivBy5(vector<int>& A) {
	vector<bool> ret;
	int step = 0;
	for (int i = 0; i < A.size(); i++) {
		step = (step * 2 + A[i]) % 5;
		ret.push_back(step % 5 == 0 ? true : false);
	}
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<int> A = { 0,1,1 };
	prefixesDivBy5(A);
	return 0;
}