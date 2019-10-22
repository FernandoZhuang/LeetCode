#define LOCAL
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int recursive(int x, int y, vector<vector<int> >& flag, vector<vector<int> >& grid) {
	int result = 1, max_row = flag.size(), max_column = flag[0].size(), tmp_x, tmp_y;
	vector<pair<int, int> > dirs = { {-1,0},{1,0},{0,-1},{0,1} };

	for (int i = 0; i < 4; i++) {
		tmp_x = x + dirs[i].first, tmp_y = y + dirs[i].second;
		if (tmp_x >= 0 && tmp_x < max_row && tmp_y >= 0 && tmp_y < max_column && grid[tmp_x][tmp_y] && !flag[tmp_x][tmp_y]) {
			flag[tmp_x][tmp_y] = 1;
			result += recursive(tmp_x, tmp_y, flag, grid);
		}
	}

	return result;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
	int row = grid.size(), column = grid[0].size(), result = 0;
	vector<vector<int> > flag(row, vector<int>(column, 0));

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++) {
			if (!grid[i][j]) { continue; }
			if (!flag[i][j]) {
				flag[i][j] = 1;
				result = max(recursive(i, j, flag, grid), result);
			}
		}

	return result;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<vector<int> > grid = { {0,0,0,0,0}};
	maxAreaOfIsland(grid);

	return 0;
}