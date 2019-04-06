#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

int islandPerimeter(vector<vector<int> >& grid) {
	int ret = 0, ro = grid.size(), co = grid[0].size(), cnt = 4;
	for (int i = 0; i < ro; i++) {
		for (int j = 0; j < co; j++) {
			cnt = 4;
			if (!grid[i][j]) { continue; }
			if (j - 1 >= 0)
				if (grid[i][j - 1] == 1) { cnt--; }
			if(i - 1 >= 0)
				if (grid[i - 1][j] == 1) { cnt--; }
			if(j + 1 < co)
				if (grid[i][j + 1] == 1) { cnt--; }
			if(i + 1 < ro)
				if (grid[i + 1][j] == 1) { cnt--; }
			ret += cnt;
		}
	}

	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<vector<int> > grid = { {1,1} };
	islandPerimeter(grid);
	return 0;
}