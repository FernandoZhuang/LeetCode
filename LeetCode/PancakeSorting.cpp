#define LOCAL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pancakeSort(vector<int>& A) {
	//Plan A
	/*int k, mx = 0, sz = A.size(), cpsz = 0, flag;
	vector<int> cp = A, ret;
	sort(cp.begin(), cp.end());

	for (int i = 0; i < sz; i++) {
		mx = *cp.rbegin(), cpsz = cp.size(), flag = 0;
		cp.pop_back();
		for(int j=0;j<sz;j++)
			if (A[j] == mx) {
				k = j + 1;
				if (k == cpsz) { flag = 1; }
				else if (k != 1) { ret.push_back(k); }
				break;
			}
		if (flag) { continue; }
		if (k != 1) { reverse(A.begin(), A.begin() + k); }
		if (cpsz != 1) {
			ret.push_back(cpsz);
			reverse(A.begin(), A.begin() + cpsz);
		}
	}*/

	//Plan B
	int mx = 0, sz = A.size(), k = 0;
	vector<int> ret;
	for (int i = 0; i < sz; i++) {
		mx = 0;
		for(int j=0;j<sz-i;j++)
			if (A[j] > mx) {
				mx = A[j];
				k = j + 1;
			}
		if (k == sz - i) { continue; }
		if (k != 1) {
			ret.push_back(k);
			reverse(A.begin(), A.begin() + k);
		}
		if (sz - i != 1) {
			ret.push_back(sz - i);
			reverse(A.begin(), A.begin() + sz - i);
		}
	}

	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<int> A = { 3,2,4,1 };
	pancakeSort(A);
	return 0;
}