//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

void findWays(vector<vector<int> > &grid, vector<pair<int,int> >& dir, int sx, int sy, int emptys, int& paths) {
	for (auto i : dir) {
		sx += i.first, sy += i.second;
		//HACK:grid[sx][sy]
		if (sx<0 || sx>(grid.size() - 1) || sy<0 || sy>(grid[0].size() - 1) || grid[sx][sy] == -1) { 
			sx -= i.first, sy -= i.second;
			continue; 
		}
		if (grid[sx][sy] == 0) {
			grid[sx][sy] = -1, emptys -= 1;
			findWays(grid, dir, sx, sy, emptys, paths);
			grid[sx][sy] = 0, emptys += 1;
		}
		else if (grid[sx][sy] == 2 && !emptys) { paths++; }
		sx -= i.first, sy -= i.second;
	}
}

int uniquePathsIII(vector<vector<int>>& grid){
	vector<pair<int, int> > dir = { {-1,0},{1,0},{0,1},{0,-1} };
	int sx, sy, emptys = 0, paths = 0;
	for(int i=0;i<grid.size();i++)
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == 1) { sx = i, sy = j; }
			if (grid[i][j] == 0) { emptys++; }
		}
	findWays(grid, dir, sx, sy, emptys, paths);
	return paths;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<vector<int> > grid = { {0,1},{2,0} };
	uniquePathsIII(grid);
	return 0;
}