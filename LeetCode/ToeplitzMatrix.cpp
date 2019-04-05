#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix) {
	int row = matrix.size(), column = matrix[0].size();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if(i+1<row && j+1<column)
				if (matrix[i][j] != matrix[i + 1][j + 1]) { return false; }
		}
	}
	return true;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	return 0;
}