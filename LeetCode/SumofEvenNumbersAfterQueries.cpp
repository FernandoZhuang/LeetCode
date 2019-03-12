#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
	vector<int> ret;
	int res = 0;
	for (auto i : A) { if (!(i % 2)) { res += i; } }
	for (auto i : queries) {
		if (A[i[1]] % 2) { if (i[0] % 2) { res += i[0] + A[i[1]]; } }
		else {
			if (i[0] % 2) { res -= A[i[1]]; }
			else { res += i[0]; }
		}
		ret.push_back(res);
		A[i[1]] += i[0];
	}
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<int> A = { 1,2,3,4 };
	vector<vector<int> > queries = { {1,0},{-3,1},{-4,0},{2,3} };
	sumEvenAfterQueries(A, queries);
	return 0;
}