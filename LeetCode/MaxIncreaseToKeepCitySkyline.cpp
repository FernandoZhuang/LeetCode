#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
	int res = 0;
	vector<int> row, column;
	for (int i = 0; i < grid.size(); i++) {
		int max = 0;
		for (int j = 0; j < grid[i].size(); j++)
			if (grid[i][j] > max)
				max = grid[i][j];
		row.push_back(max);
	}
	for (int i = 0; i < grid[0].size(); i++) {
		int max = 0;
		for (int j = 0; j < grid.size(); j++)
			if (grid[j][i] > max)
				max = grid[j][i];
		column.push_back(max);
	}
	for (int i = 0; i < grid.size(); i++) 
		for (int j = 0; j < grid[i].size(); j++)
			res += (row[i] >= column[j] ? column[j] : row[i]) - grid[i][j];
	return res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int tmp;
	vector<vector <int> > grid(4, vector<int> (4));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> grid[i][j];
	cout << maxIncreaseKeepingSkyline(grid);
	return 0;
}