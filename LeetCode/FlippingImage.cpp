#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
	for (int i = 0; i < A.size(); i++) {
		int j, k;
		for (j = 0, k = A[i].size() - 1; j < k; j++, k--) {
			int tmp = A[i][j];
			A[i][j] = A[i][k], A[i][k] = tmp;

			A[i][j] = 1 - A[i][j], A[i][k] = 1 - A[i][k];
		}
		if (j == k)
			A[i][j] = 1 - A[i][j];
	}
	return A;
}

vector<vector<int>> flipAndInvertImageAuto(vector<vector<int>>& A) {
	for (auto& i : A) {
		reverse(i.begin(), i.end());
		for (auto& j : i)
			j = 1 - j;
	}
	return A;
}

int main() {
	vector<vector <int> > A = { {1,1,0},{1,0,1},{0,0,0} };
	//flipAndInvertImage(A);
	flipAndInvertImageAuto(A);
	return 0;
}