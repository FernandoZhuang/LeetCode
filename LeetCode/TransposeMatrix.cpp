#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& A) {
	vector<vector<int> > ret(A[0].size(), vector<int>(A.size()));
	for(int i=0;i<A.size();i++)
		for (int j = 0; j < A[0].size(); j++) { ret[j][i] = A[i][j]; }
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<vector<int> > A = { {1,2,3},{4,5,6},{7,8,9} };
	transpose(A);
	return 0;
}