#define LOCAL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int projectionArea(vector<vector<int>>& grid) {
	int ret = 0;
	for(auto i:grid)
		for(auto j:i)
			if (j) { ret++; }
	for (auto i : grid)
		ret += *max_element(i.begin(), i.end());
	for (int i = 0, max = 0; i < grid[0].size(); i++, ret += max, max = 0) 
		for(int j=0;j<grid.size();j++)
			if (grid[j][i] > max) { max = grid[j][i]; }
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<vector<int> > grid = { {0} };
	projectionArea(grid);
	return 0;
}