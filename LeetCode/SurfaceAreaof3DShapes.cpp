#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int surfaceArea(vector<vector<int>>& grid) {
	int res = 0, rows = grid.size(), columns = grid[0].size();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (!grid[i][j]) { continue; }
			
			res += 4 * grid[i][j] + 2;
			//res += grid[i][j] == 1 ? 6 : (4 * grid[i][j] + 2);
			if (j + 1 < columns) { res -= min(grid[i][j], grid[i][j + 1]) * 2; }
			if (i != 0) { res -= min(grid[i - 1][j], grid[i][j]) * 2; }
		}
	}

	return res;
}

int main() {
	vector<vector<int> > grid = { {2,2,2},{2,1,2},{2,2,2} };
	
	surfaceArea(grid);

	return 0;
}