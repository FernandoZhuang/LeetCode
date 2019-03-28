#define LOCAL
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
	int cnt = 1, rc = R * C, step = 0, tmpr = 0, tmpc = 0, flag = 1, valr = 0, valc = 0;
	vector<pair<int, int> > dir = { {1,0},{0,1},{-1,0},{0,-1} };
	vector<vector<int> > ret = { {r0,c0} };
	while (cnt < rc) {
		step++, flag = 1;
		for (int i = 0; i < 4; i++) {
			valr = dir[i].second, valc = dir[i].first;
			tmpr = r0, tmpc = c0;
			if (flag && i >= 2) { step++, flag = 0; }
			for (int j = 1; j <= step; j++) {
				tmpr += valr, tmpc += valc;
				if (tmpr >= 0 && tmpr < R && tmpc >= 0 && tmpc < C) {
					ret.push_back({ tmpr, tmpc });
					if ((++cnt) >= rc) { return ret; }
				}
			}
			r0 += dir[i].second*step, c0 += dir[i].first*step;
		}
	}
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	vector<vector<int> > res;
	int R = 5, C = 6, r0 = 1, c0 = 4;
	res = spiralMatrixIII(R, C, r0, c0);
	return 0;
}