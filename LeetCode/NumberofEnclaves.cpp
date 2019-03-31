#define LOCAL
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<vector<int> > cp;
vector<vector<bool> > judge;
vector<pair<int, int> > dir = { {-1,0},{1,0},{0,-1},{0,1} };

void dfs(int x, int y) {
	judge[x][y] = true;
	int r, c;
	for (int i = 0; i < 4; i++) {
		r = x + dir[i].second, c = y + dir[i].first;
		if(r >= 0 && r < cp.size() && c >= 0 && c < cp[0].size())
			if (cp[r][c] == 1 && !judge[r][c])
				dfs(r, c);
	}
}

int numEnclaves(vector<vector<int>>& A) {
	int ret = 0, ro = A.size() - 1, co = A[0].size() - 1, x = 0, y = 0;
	cp = A;
	judge.resize(A.size(), vector<bool>(A[0].size(), false));
	
	for(int i = 0;i<= ro;i++)
		for (int j = 0; j <= co; j++) 
			if (i == 0 || i == ro || j == 0 || j == co) {
				if (A[i][j] == 1 && !judge[i][j])
					dfs(i, j);
			}
		
	for(int i=0;i<=ro;i++)
		for(int j=0;j<=co;j++)
			if (A[i][j] == 1 && !judge[i][j]) { ret++; }
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int ans = 0;
	vector<vector<int> > A = { {0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0} };
	ans = numEnclaves(A);
	return 0;
}